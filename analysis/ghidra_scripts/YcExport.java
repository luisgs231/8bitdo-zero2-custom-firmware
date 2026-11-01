import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.data.StringDataInstance;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import java.io.File;
import java.io.PrintWriter;

public class YcExport extends GhidraScript {
    // What every byte of the image turned out to be, as runs: code inside a function, code no
    // function claims, defined data, or still unknown. This is how a run's coverage is judged.
    private void layout(String out) throws Exception {
        ghidra.program.model.listing.Listing l = currentProgram.getListing();
        try (PrintWriter w = new PrintWriter(out + "/layout.txt")) {
            String run = null;
            ghidra.program.model.address.Address runStart = null;
            ghidra.program.model.address.Address prev = null;
            for (long a = 0x01018000L; a < 0x01029E00L; a++) {
                ghidra.program.model.address.Address ad = toAddr(a);
                String kind;
                if (l.getInstructionContaining(ad) != null) {
                    kind = getFunctionContaining(ad) != null ? "func" : "orphan-code";
                } else {
                    Data da = l.getDataContaining(ad);
                    kind = (da != null && da.isDefined()) ? "data" : "unknown";
                }
                if (!kind.equals(run)) {
                    if (run != null) {
                        w.printf("%s %s %d %s%n", runStart, prev, prev.subtract(runStart) + 1, run);
                    }
                    run = kind;
                    runStart = ad;
                }
                prev = ad;
            }
            w.printf("%s %s %d %s%n", runStart, prev, prev.subtract(runStart) + 1, run);
        }
    }

    @Override
    protected void run() throws Exception {
        String out = getScriptArgs()[0];
        new File(out).mkdirs();
        try (PrintWriter fl = new PrintWriter(out + "/functions.txt");
             PrintWriter c = new PrintWriter(out + "/decompiled.c");
             PrintWriter rg = new PrintWriter(out + "/ranges.txt");
             PrintWriter st = new PrintWriter(out + "/strings.txt")) {
            DecompInterface d = new DecompInterface();
            d.openProgram(currentProgram);
            for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
                fl.printf("%s %6d %s%n", f.getEntryPoint(), f.getBody().getNumAddresses(), f.getName());
                for (ghidra.program.model.address.AddressRange r : f.getBody()) {
                    rg.printf("%s %s %s%n", f.getEntryPoint(), r.getMinAddress(), r.getMaxAddress());
                }
                DecompileResults r = d.decompileFunction(f, 60, monitor);
                c.printf("// %s %s%n", f.getEntryPoint(), f.getName());
                c.println(r.decompileCompleted() ? r.getDecompiledFunction().getC() : "// failed: " + r.getErrorMessage());
            }
            layout(out);
            for (Data s : currentProgram.getListing().getDefinedData(true)) {
                if (!s.hasStringValue()) {
                    continue;
                }
                StringBuilder refs = new StringBuilder();
                for (Reference ref : getReferencesTo(s.getAddress())) {
                    Function f = getFunctionContaining(ref.getFromAddress());
                    refs.append(' ').append(f != null ? f.getName() : ref.getFromAddress().toString());
                }
                st.printf("%s %s |%s%n", s.getAddress(), StringDataInstance.getStringDataInstance(s).getStringValue().replace("\n", "\\n"), refs);
            }
        }
    }
}
