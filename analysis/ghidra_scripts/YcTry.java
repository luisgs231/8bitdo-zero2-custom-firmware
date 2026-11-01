import ghidra.app.script.GhidraScript;
import ghidra.app.util.PseudoDisassembler;
import ghidra.app.util.PseudoInstruction;
import ghidra.program.database.ProgramDB;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.Language;
import ghidra.program.model.lang.LanguageDescription;
import ghidra.program.model.lang.LanguageService;
import ghidra.program.util.DefaultLanguageService;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

// Which instruction set is a headerless blob written in? Decode it linearly with every processor
// Ghidra has and see which one swallows it. Usage: a file path, then the base address in hex.
// Prints the best candidates by the share of bytes a linear sweep decodes, with the number of
// positions that decoded to nothing. A permissive set (x86, ARM) decodes almost anything, so read
// the result together with the shape of the bytes, never on its own.
public class YcTry extends GhidraScript {
    private static class Score {
        String id;
        int good;
        int bad;
        int covered;
        double share;
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        byte[] bytes = Files.readAllBytes(new File(args[0]).toPath());
        long base = Long.parseLong(args[1], 16);
        LanguageService service = DefaultLanguageService.getLanguageService();
        List<Score> scores = new ArrayList<>();
        for (LanguageDescription description : service.getLanguageDescriptions(false)) {
            ProgramDB program = null;
            int tx = -1;
            try {
                Language language = service.getLanguage(description.getLanguageID());
                program = new ProgramDB("try", language, language.getDefaultCompilerSpec(), this);
                tx = program.startTransaction("try");
                Address start = language.getDefaultSpace().getAddress(base);
                program.getMemory().createInitializedBlock("blob", start,
                        new ByteArrayInputStream(bytes), bytes.length, monitor, false);
                int step = Math.max(1, language.getInstructionAlignment());
                PseudoDisassembler disassembler = new PseudoDisassembler(program);
                Score score = new Score();
                score.id = description.getLanguageID().getIdAsString();
                for (int off = 0; off < bytes.length; ) {
                    PseudoInstruction instruction = null;
                    try {
                        instruction = disassembler.disassemble(start.add(off));
                    } catch (Exception | Error e) {
                        instruction = null;
                    }
                    if (instruction == null || instruction.getLength() <= 0) {
                        score.bad++;
                        off += step;
                    } else {
                        score.good++;
                        score.covered += instruction.getLength();
                        off += instruction.getLength();
                    }
                }
                score.share = (double) score.covered / bytes.length;
                scores.add(score);
            } catch (Exception | Error e) {
                // a language that will not load or map at this address tells us nothing
            } finally {
                if (program != null) {
                    if (tx != -1) {
                        program.endTransaction(tx, false);
                    }
                    program.release(this);
                }
            }
        }
        scores.sort(Comparator.comparingDouble((Score s) -> -s.share).thenComparingInt(s -> s.bad));
        println(String.format("YcTry: %s, %d bytes, %d languages decoded", args[0], bytes.length,
                scores.size()));
        for (Score s : scores) {
            if (s.bad == 0 || s.share > 0.9) {
                println(String.format("YcTry: %-34s covered %5.1f%%  instructions %5d  dead ends %5d",
                        s.id, 100 * s.share, s.good, s.bad));
            }
        }
    }
}
