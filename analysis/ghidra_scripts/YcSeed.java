import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.data.ArrayDataType;
import ghidra.program.model.data.ByteDataType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;
import java.util.ArrayList;
import java.util.List;

// Auto analysis only reaches code something calls. The pattern engine at 0x01024584, the pairing
// write-back at 0x0101FFAC and their like are reached through a function pointer or not at all, so
// they stay undefined and never decompile. Keil's switch helper hides even more: it jumps through a
// byte table laid down after its own call site, so a function's body ends at that call and every
// case stays undisassembled. This resolves those tables, then seeds what is left: every odd word
// that points into the code (a Thumb function pointer) and every `push {.., lr}` in space still
// undefined, then lets analysis follow the calls out of each new function.
public class YcSeed extends GhidraScript {
    private static final long CODE_START = 0x01018000L;
    private static final long CODE_END = 0x01025A6EL;   // the core blob, strings and SDP records follow

    // Code already disassembled but belonging to no function counts as missing too: the pattern
    // engine is reached through a pointer, so analysis decodes it and then leaves it orphaned, out
    // of every decompile.
    private boolean seed(Address a) throws Exception {
        if (getFunctionAt(a) != null || getFunctionContaining(a) != null) {
            return false;
        }
        if (getInstructionAt(a) == null) {
            disassemble(a);
            if (getInstructionAt(a) == null) {
                return false;
            }
        }
        return createFunction(a, null) != null;
    }

    // The address a 32 bit Thumb `bl` at this address reaches, or null if these halfwords are not
    // one.
    private Long blTarget(Memory mem, long a) throws Exception {
        int h1 = mem.getShort(toAddr(a)) & 0xFFFF;
        int h2 = mem.getShort(toAddr(a + 2)) & 0xFFFF;
        if ((h1 & 0xF800) != 0xF000 || (h2 & 0xD000) != 0xD000) {
            return null;
        }
        int s = (h1 >> 10) & 1;
        int i1 = 1 - (((h2 >> 13) & 1) ^ s);
        int i2 = 1 - (((h2 >> 11) & 1) ^ s);
        long off = ((long) s << 24) | ((long) i1 << 23) | ((long) i2 << 22)
                | ((long) (h1 & 0x3FF) << 12) | ((h2 & 0x7FF) << 1);
        if (s == 1) {
            off -= 1L << 25;
        }
        return a + 4 + off;
    }

    // `bl __ARM_common_switch8` is followed by a count byte and count + 1 offset bytes, and the
    // helper jumps to table + 2 * offset with the Thumb bit set. Mark the table as data and
    // disassemble every case, which the orphan pass below then turns into functions of their own.
    // Pointing a computed jump from the call site at each case instead, so that the switch reads as
    // one function, makes the decompiler run away: every one of these five functions then dies with
    // "Bad instruction count exceeded" and loses its C altogether, the core event handler and its
    // dispatcher included.
    private int[] switches() throws Exception {
        Function helper = null;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (f.getName().equals("yc_switch8")) {
                helper = f;
                break;
            }
        }
        if (helper == null) {
            println("YcSeed: yc_switch8 is not defined, no switch tables resolved");
            return new int[] {0, 0};
        }
        // Found by decoding the bytes, not by following references: four of the twelve calls sit in
        // the very stretches that stay undisassembled until their own table is resolved.
        Memory mem = currentProgram.getMemory();
        long helperAddress = helper.getEntryPoint().getOffset();
        List<Address> sites = new ArrayList<>();
        for (long a = CODE_START; a + 4 <= CODE_END; a += 2) {
            Long target = blTarget(mem, a);
            if (target != null && target == helperAddress) {
                sites.add(toAddr(a));
            }
        }
        int cases = 0;
        for (Address site : sites) {
            Address table = site.add(4);
            int n = mem.getByte(table) & 0xFF;
            int len = n + 2;
            clearListing(table, table.add(len - 1));
            createData(table, new ArrayDataType(ByteDataType.dataType, len, 1));
            for (int i = 0; i <= n; i++) {
                Address target = table.add(2 * (mem.getByte(table.add(1 + i)) & 0xFF));
                if (getInstructionAt(target) == null) {
                    disassemble(target);
                }
                cases++;
            }
        }
        return new int[] {sites.size(), cases};
    }

    // Whatever the scans above leave undefined, named for what it is. A run of zeros is the padding
    // between a function and the next one's literal pool; a run of text is a log string the string
    // finder stopped short of; anything else is tried as code and kept only if it decodes to the
    // end of its own run, so a literal pool tail is left alone rather than turned into a wrong
    // instruction. This is what reaches the dead veneer table at 0x01018004 and the run loop's
    // `execute` at 0x01023E76, which nothing calls directly.
    private int[] leftovers() throws Exception {
        Memory mem = currentProgram.getMemory();
        ghidra.program.model.listing.Listing listing = currentProgram.getListing();
        List<long[]> runs = new ArrayList<>();
        long start = -1;
        for (long a = CODE_START; a <= CODE_END; a++) {
            boolean unknown = false;
            if (a < CODE_END) {
                Address ad = toAddr(a);
                ghidra.program.model.listing.Data data = listing.getDataContaining(ad);
                unknown = listing.getInstructionContaining(ad) == null
                        && (data == null || !data.isDefined());
            }
            if (unknown && start == -1) {
                start = a;
            } else if (!unknown && start != -1) {
                runs.add(new long[] {start, a - 1});
                start = -1;
            }
        }
        int padding = 0;
        int text = 0;
        int code = 0;
        int left = 0;
        for (long[] run : runs) {
            int len = (int) (run[1] - run[0] + 1);
            Address from = toAddr(run[0]);
            Address to = toAddr(run[1]);
            byte[] bytes = new byte[len];
            mem.getBytes(from, bytes);
            int zeros = 0;
            int printable = 0;
            for (byte b : bytes) {
                int v = b & 0xFF;
                if (v == 0) {
                    zeros++;
                }
                if (v >= 0x20 && v < 0x7F) {
                    printable++;
                }
            }
            if (zeros == len) {
                createData(from, new ArrayDataType(ByteDataType.dataType, len, 1));
                padding++;
                continue;
            }
            if (len >= 4 && printable * 5 >= len * 4) {
                try {
                    createAsciiString(from, len);
                    text++;
                    continue;
                } catch (Exception e) {
                    // not a string after all, fall through and try it as code
                }
            }
            // Every position in the run, not just the first: a run of these is several entries that
            // reach each other through nothing, such as the `b .` default handlers at 0x010180E2 or
            // the veneer table, where following the flow from the first one covers two bytes and
            // stops.
            long covered = run[0];
            while (covered <= run[1]) {
                Address at = toAddr(covered);
                if (getInstructionAt(at) == null) {
                    disassemble(at);
                }
                Instruction instruction = getInstructionAt(at);
                if (instruction == null) {
                    break;
                }
                covered += instruction.getLength();
            }
            if (covered > run[1]) {
                code++;
            } else {
                // Not code: an odd address cannot start a Thumb instruction, and what is left here
                // sits between two log strings, so it is the tail of a literal or of a string.
                clearListing(from, to);
                createData(from, new ArrayDataType(ByteDataType.dataType, len, 1));
                left++;
            }
        }
        return new int[] {padding, text, code, left};
    }

    // Above CODE_END there is the core blob, its records, the strings and the modes' SDP records,
    // all of it data. Anything decoded as an instruction up there is a stray reference leading into
    // data, so it goes.
    private int clearData() throws Exception {
        AddressSet area = new AddressSet(toAddr(CODE_END),
                currentProgram.getMemory().getBlock(toAddr(CODE_START)).getEnd());
        List<Instruction> stray = new ArrayList<>();
        for (Instruction i : currentProgram.getListing().getInstructions(area, true)) {
            stray.add(i);
        }
        int cleared = 0;
        for (Instruction i : stray) {
            Address at = i.getAddress();
            int len = i.getLength();
            ghidra.program.model.listing.Function owner = getFunctionContaining(at);
            if (owner != null) {
                removeFunction(owner);
            }
            clearListing(at, at.add(len - 1));
            cleared += len;
        }
        return cleared;
    }

    @Override
    protected void run() throws Exception {
        int[] sw = switches();
        analyzeChanges(currentProgram);
        Memory mem = currentProgram.getMemory();
        int pointers = 0;
        for (long a = CODE_START; a + 4 <= CODE_END; a += 4) {
            int w = mem.getInt(toAddr(a));
            long t = (w & 0xFFFFFFFEL);
            if ((w & 1) == 0 || t < CODE_START || t >= CODE_END) {
                continue;
            }
            if (seed(toAddr(t))) {
                pointers++;
            }
        }
        int prologues = 0;
        for (long a = CODE_START; a + 2 <= CODE_END; a += 2) {
            if ((mem.getByte(toAddr(a + 1)) & 0xFF) != 0xB5) {
                continue;
            }
            if (seed(toAddr(a))) {
                prologues++;
            }
        }
        analyzeChanges(currentProgram);
        int[] rest = leftovers();
        analyzeChanges(currentProgram);
        // Whatever is still decoded and unclaimed gets a function of its own, which also sweeps up
        // the stretches the scans above reached only part of. Each round decodes more code, so this
        // repeats until a round claims nothing.
        AddressSet code = new AddressSet(toAddr(CODE_START), toAddr(CODE_END - 1));
        int claimed = 0;
        int seen = 0;
        for (int round = 0; round < 8; round++) {
            List<Address> orphans = new ArrayList<>();
            for (Instruction i : currentProgram.getListing().getInstructions(code, true)) {
                if (getFunctionContaining(i.getAddress()) == null) {
                    orphans.add(i.getAddress());
                }
            }
            seen += orphans.size();
            int round_claimed = 0;
            for (Address a : orphans) {
                if (seed(a)) {
                    round_claimed++;
                }
            }
            analyzeChanges(currentProgram);
            claimed += round_claimed;
            if (round_claimed == 0) {
                break;
            }
        }
        println(String.format("YcSeed: %d switch tables with %d cases, %d from pointers, %d from"
                + " prologues, %d orphans claimed of %d, %d functions now", sw[0], sw[1], pointers,
                prologues, claimed, seen,
                currentProgram.getFunctionManager().getFunctionCount()));
        println(String.format("YcSeed: leftovers: %d runs of padding, %d of text, %d decoded as"
                + " code, %d not code and left as data", rest[0], rest[1], rest[2], rest[3]));
        println(String.format("YcSeed: %d bytes of stray instructions cleared above 0x%X",
                clearData(), CODE_END));
    }
}
