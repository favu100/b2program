package de.hhu.stups.codegenerator.rust;

import de.hhu.stups.codegenerator.CodeGenerator;
import de.hhu.stups.codegenerator.GeneratorMode;
import org.junit.Ignore;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

@Ignore
public class TestRS {
    public static void writeInputToOutput(InputStream inputStream, OutputStream outputStream) throws IOException {
        int size;
        byte[] buffer = new byte[1024];
        while ((size = inputStream.read(buffer)) != -1)
            outputStream.write(buffer, 0, size);
    }

    public static void writeInputToSystem(InputStream inputStream) throws IOException {
        writeInputToOutput(inputStream, System.err);
    }

    private static String streamToString(InputStream inputStream) throws IOException {
        ByteArrayOutputStream result = new ByteArrayOutputStream();
        byte[] buffer = new byte[1024];
        int length;
        while ((length = inputStream.read(buffer)) != -1) {
            result.write(buffer, 0, length);
        }
        return result.toString();
    }

    public void testRS(String machine) throws Exception {
        testRS(machine, null, "DefaultAddition.strs", false);
    }

    public void testRS(String machine, String machineName, String addition, boolean execute) throws Exception {
        testRS(machine, machineName, addition, execute, false, false, false);
    }

    public void testRSMC(String machine) throws Exception {
        testRSMC(machine, true);
    }

    public void testRSMC(String machine, boolean execute) throws Exception {
        testRSMC(machine, null, execute);
    }

    public void testRSMC(String machine, String machinePath, boolean execute) throws Exception {
        testRSMC(machine, machinePath, execute, false);
    }

    public void testRSMC(String machine, String machinePath, boolean execute, boolean noDead) throws Exception {
        testRSMC(machine, machinePath, execute, noDead, false);
    }

    public void testRSMC(String machine, String machinePath, boolean execute, boolean noDead, boolean noInv) throws Exception {
        testRS(machine, machinePath, null, execute, true, noDead, noInv);
    }

    public void testRS(String machine, String machinePath, String addition, boolean execute, boolean modelChecking, boolean noDead, boolean noInv) throws Exception {
        if (machinePath == null) { machinePath = "../../../resources/test/de/hhu/stups/codegenerator/"; }
        if (!machinePath.endsWith("/")) { machinePath += "/"; }
        Path mchPath = Paths.get(CodeGenerator.class.getClassLoader().getResource("").toURI()).resolve(machinePath + machine + ".mch").normalize();
        CodeGenerator codeGenerator = new CodeGenerator();
        List<Path> rsFilePaths = codeGenerator.generate(mchPath,
                                                        GeneratorMode.RS,
                                             false,
                                                        String.valueOf(Integer.MIN_VALUE),
                                                        String.valueOf(Integer.MAX_VALUE),
                                            "10",
                                                        modelChecking,
                                        false,
                                                  true,
                                                        addition,
                                          false,
                                            false,
                                            null,
                                                null);

        Path typesPath = Paths.get(this.getClass().getClassLoader().getResource("./").toURI()).getParent().getParent().getParent().getParent().resolve(Paths.get("btypes_primitives/src/main/rust/bmachine/src"));
        Files.createDirectories(typesPath);
        File[] oldFiles = typesPath.toFile().listFiles();
        if (oldFiles != null && oldFiles.length > 0) Arrays.stream(oldFiles).forEach(this::cleanUp);
        rsFilePaths = rsFilePaths.stream().map(file -> {
            Path dest = typesPath.resolve(Paths.get(file.toFile().getName()));
            file.toFile().renameTo(dest.toFile());
            return dest;
        }).collect(Collectors.toList());

        Runtime runtime = Runtime.getRuntime();
        Path mainPath = rsFilePaths.get(rsFilePaths.size() - 1);
        File newMainFile = typesPath.resolve(Paths.get("main.rs")).toFile();
        mainPath.toFile().renameTo(newMainFile);
        Process process = runtime.exec("cargo build --release --manifest-path " + mainPath.getParent().getParent().toFile().getAbsolutePath() + "/Cargo.toml");
        writeInputToSystem(process.getErrorStream());
        writeInputToOutput(process.getErrorStream(), process.getOutputStream());
        process.waitFor();
        if (process.exitValue() != 0) {
            throw new Exception("cargo build failed, exitcode: " + process.exitValue());
        }

        if(!execute) {
            rsFilePaths.forEach(p -> cleanUp(p.toFile()));
            return;
        }

        String progArgs = "";
        if (modelChecking) { progArgs = " -- mixed 2 true"; }
        if (noDead) { progArgs += " -nodead"; }
        if (noInv) { progArgs += " -noinv"; }

        Process executeProcess = runtime.exec("cargo run --release --manifest-path " + mainPath.getParent().getParent().toFile().getAbsolutePath() + "/Cargo.toml" + progArgs);
        executeProcess.waitFor();

        String error = streamToString(executeProcess.getErrorStream());
        if(executeProcess.exitValue() != 0) {
            throw new RuntimeException(error);
        }

        String result = streamToString(executeProcess.getInputStream());
        if (modelChecking && !machine.contains("MC")) machine += "_MC";
        File outFile = Paths.get(CodeGenerator.class.getClassLoader().getResource("de/hhu/stups/codegenerator/" + machine + ".out").toURI()).toFile();
        String expectedOutput = streamToString(new FileInputStream(outFile)).replaceAll("[\n\r]", "");
        result = result.replaceAll("\n", "");

        if (!modelChecking) {
            System.out.println("Assert: " + result + " = " + expectedOutput);
            assertEquals(expectedOutput, result);
        } else {
            System.out.println("Asserting Success: ");
            System.out.println("Expected: " + expectedOutput);
            System.out.println("Gotten  : " + result);
            assertTrue(result.contains(expectedOutput));
        }
        cleanUp(newMainFile);
        rsFilePaths.forEach(p -> cleanUp(p.toFile()));
    }

    private void cleanUp(File file) {
        if (file.exists()) {
            file.delete();
        }
    }

    private void cleanUp(String path) {
        File file = new File(path);
        cleanUp(file);
    }
}
