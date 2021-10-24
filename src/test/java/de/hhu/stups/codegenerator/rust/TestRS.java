package de.hhu.stups.codegenerator.rust;

import de.hhu.stups.codegenerator.CodeGenerator;
import de.hhu.stups.codegenerator.GeneratorMode;
import sun.reflect.generics.reflectiveObjects.NotImplementedException;

import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.stream.Collectors;

import static org.junit.Assert.assertEquals;

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
        testRS(machine, machine, "DefaultAddition.strs", false);
    }

    public void testRS(String machine, String machineName, String addition, boolean execute) throws Exception {
        Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
                .getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
        CodeGenerator codeGenerator = new CodeGenerator();
        List<Path> rsFilePaths = codeGenerator.generate(mchPath, GeneratorMode.RS,
                false, String.valueOf(Integer.MIN_VALUE),
                String.valueOf(Integer.MAX_VALUE), "10",
                false, false,true,
                addition, false, false, null);

        Path typesPath = Paths.get(this.getClass().getClassLoader().getResource("./").toURI()).getParent().getParent().getParent().getParent().resolve(Paths.get("btypes_primitives/src/main/rust/bmachine/src"));
        rsFilePaths = rsFilePaths.stream().map(file -> {
            Path dest = typesPath.resolve(Paths.get(file.toFile().getName()));
            file.toFile().renameTo(dest.toFile());
            return dest;
        }).collect(Collectors.toList());

        Runtime runtime = Runtime.getRuntime();
        Path mainPath = rsFilePaths.get(rsFilePaths.size() - 1);
        File newMainFile = typesPath.resolve(Paths.get("main.rs")).toFile();
        cleanUp(newMainFile);
        mainPath.toFile().renameTo(newMainFile);
        Process process = runtime.exec("cargo build --manifest-path " + mainPath.getParent().getParent().toFile().getAbsolutePath() + "/Cargo.toml");
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

        Process executeProcess = runtime.exec("cargo run --manifest-path " + mainPath.getParent().getParent().toFile().getAbsolutePath() + "/Cargo.toml");
        executeProcess.waitFor();

        String error = streamToString(executeProcess.getErrorStream());
        if(executeProcess.exitValue() != 0) {
            throw new RuntimeException(error);
        }

        String result = streamToString(executeProcess.getInputStream()).replaceAll("\n", "");
        File outFile = Paths.get(CodeGenerator.class.getClassLoader().getResource("de/hhu/stups/codegenerator/" + machine + ".out").toURI()).toFile();
        String expectedOutput = streamToString(new FileInputStream(outFile)).replaceAll("\n", "");

        System.out.println("Assert: " + result + " = " + expectedOutput);

        assertEquals(expectedOutput, result);
        cleanUp(newMainFile);
        rsFilePaths.forEach(p -> cleanUp(p.toFile()));
    }

    public void testRSMC(String machine) { //model checking
        throw new NotImplementedException();
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
