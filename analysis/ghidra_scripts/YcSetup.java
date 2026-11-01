import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;

public class YcSetup extends GhidraScript {
    private void block(String name, long start, long size, boolean volatil) throws Exception {
        Memory mem = currentProgram.getMemory();
        Address a = toAddr(start);
        if (mem.getBlock(a) != null) {
            return;
        }
        MemoryBlock b = mem.createUninitializedBlock(name, a, size, false);
        b.setRead(true);
        b.setWrite(true);
        b.setExecute(!volatil);
        b.setVolatile(volatil);
    }

    @Override
    protected void run() throws Exception {
        block("ROM", 0x0, 0x20000, false);
        block("RAM", 0x20000, 0x10000, false);
        block("PERIPH", 0xf0000, 0x10000, true);
        block("SCS", 0xe000e000L, 0x1000, true);
        Address start = toAddr(0x01018000L);
        currentProgram.getProgramContext().setValue(
            currentProgram.getProgramContext().getRegister("TMode"), start,
            currentProgram.getMemory().getBlock(start).getEnd(), java.math.BigInteger.ONE);
        disassemble(start);
        createFunction(start, "entry");
        // Keil's switch helper: it returns to a byte table that follows its own call site, so a
        // function's body ends there and the rest of it stays undisassembled. YcSeed reads those
        // tables itself. Ghidra has a call fixup keyed on the name `__ARM_common_switch8`
        // (ARM.cspec, switch8_r3, and all 12 call sites do put the index in r3), which recovers the
        // switch into the one function, but the decompiler then runs away in each of the five
        // functions that have a table and all five lose their C to "Bad instruction count
        // exceeded", the core event handler and its dispatcher among them. So the helper gets a
        // name of its own, deliberately not the one the fixup looks for, and the cases become
        // functions of their own.
        Address switch8 = toAddr(0x010230ECL);
        disassemble(switch8);
        createFunction(switch8, "yc_switch8");
    }
}
