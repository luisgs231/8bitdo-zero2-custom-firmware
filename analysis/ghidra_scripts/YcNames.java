import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

// Puts the names from analysis/names.txt on the functions, so the decompile reads with the project's
// own vocabulary instead of 832 addresses. A line is an address, a name, and anything after a # is a
// note. An address with no function, or a name that will not take, is reported rather than ignored.
public class YcNames extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String path = getScriptArgs()[0];
        int named = 0;
        int missing = 0;
        int failed = 0;
        for (String line : java.nio.file.Files.readAllLines(new java.io.File(path).toPath())) {
            String text = line;
            int hash = text.indexOf('#');
            if (hash != -1) {
                text = text.substring(0, hash);
            }
            String[] parts = text.trim().split("\\s+");
            if (parts.length < 2 || parts[0].isEmpty()) {
                continue;
            }
            Address at = toAddr(Long.parseLong(parts[0], 16));
            Function function = getFunctionAt(at);
            if (function == null) {
                println("YcNames: no function at " + parts[0] + " for " + parts[1]);
                missing++;
                continue;
            }
            try {
                function.setName(parts[1], SourceType.USER_DEFINED);
                named++;
            } catch (Exception e) {
                println("YcNames: " + parts[1] + " would not take at " + parts[0] + ": "
                        + e.getMessage());
                failed++;
            }
        }
        println(String.format("YcNames: %d named, %d with no function, %d refused", named, missing,
                failed));
    }
}
