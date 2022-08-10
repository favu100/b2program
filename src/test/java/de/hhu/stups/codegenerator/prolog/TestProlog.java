package de.hhu.stups.codegenerator.prolog;

import de.hhu.stups.codegenerator.CodeGenerator;
import de.hhu.stups.codegenerator.GeneratorMode;

import java.io.*;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

import static org.junit.Assert.assertEquals;

public class TestProlog {

    public static void writeInputToSystem(InputStream inputStream) throws IOException {
        writeInputToOutput(inputStream, System.out);
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

    public static void writeInputToOutput(InputStream inputStream, OutputStream outputStream) throws IOException {
        int size;
        byte[] buffer = new byte[1024];
        while ((size = inputStream.read(buffer)) != -1)
            outputStream.write(buffer, 0, size);
    }

    public void testProlog(String machine) throws Exception {
        Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
                .getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
        CodeGenerator codeGenerator = new CodeGenerator();
        List<Path> javaFilePaths = codeGenerator.generate(mchPath,
                GeneratorMode.PL,
                false,
                String.valueOf(Integer.MIN_VALUE),
                String.valueOf(Integer.MAX_VALUE),
                "10",
                true,
                false,
                true,
                null,
                false,
                false,
                null,
                null);
        Process process = Runtime.getRuntime()
                .exec("javac -classpath btypes_persistent.jar " + String.join(" ", javaFilePaths.stream()
                        .map(path -> path.toFile().getAbsoluteFile().toString())
                        .collect(Collectors.toSet())));

        writeInputToSystem(process.getErrorStream());
        writeInputToOutput(process.getErrorStream(), process.getOutputStream());
        process.waitFor();

        String error = streamToString(process.getErrorStream());
        if (!error.isEmpty()) {
            throw new RuntimeException(error);
        }
    }

    public void testProlog(String machinePath, String machineName, String addition, boolean execute) throws Exception {
        Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
                .getResource("de/hhu/stups/codegenerator/" + machinePath + ".mch").toURI());
        CodeGenerator codeGenerator = new CodeGenerator();
        List<Path> javaFilePaths = codeGenerator.generate(mchPath,
                GeneratorMode.PL,
                false,
                String.valueOf(Integer.MIN_VALUE),
                String.valueOf(Integer.MAX_VALUE),
                "10",
                false,
                false,
                true,
                addition,
                false,
                false,
                null,
                null);
//        Runtime runtime = Runtime.getRuntime();
//        Process compileProcess = runtime.exec("javac -cp btypes_persistent.jar " +
//                String.join(" ", javaFilePaths.stream()
//                        .map(path -> path.toFile().getAbsoluteFile().toString())
//                        .collect(Collectors.toSet())));
//        compileProcess.waitFor();
//
//        String error = streamToString(compileProcess.getErrorStream());
//        if(!error.isEmpty()) {
//            throw new RuntimeException(error);
//        }
//        Path mainPath = javaFilePaths.get(javaFilePaths.size() - 1);
//
//        if(!execute) {
//            return;
//        }
//
//        String generatedMachinePath = Paths.get("out", "test", "resources", "de", "hhu", "stups", "codegenerator", machinePath.substring(0, machinePath.length() - machineName.length()) + " " + machineName).toString();
//
//        Process executeProcess = runtime.exec("java -cp btypes_persistent.jar:" + generatedMachinePath);
//        executeProcess.waitFor();
//
//        error = streamToString(executeProcess.getErrorStream());
//        if(!error.isEmpty()) {
//            throw new RuntimeException(error);
//        }
//
//        String result = streamToString(executeProcess.getInputStream()).replaceAll("\n", "");
//        String expectedOutput = streamToString(new FileInputStream(mainPath.toFile().getAbsoluteFile().toString().replaceAll(".java", ".out"))).replaceAll("\n", "");
//
//        System.out.println("Assert: " + result + " = " + expectedOutput);
//
//        assertEquals(expectedOutput, result);
//
//        Set<File> classFiles = javaFilePaths.stream()
//                .map(path -> new File(path.getParent().toFile(), machinePath + ".class"))
//                .collect(Collectors.toSet());

        //javaFilePaths.forEach(path -> cleanUp(path.toString()));
        //classFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));
    }

    public void testPrologMC(String machine) throws Exception {
        Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
                .getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
        CodeGenerator codeGenerator = new CodeGenerator();
        List<Path> javaFilePaths = codeGenerator.generate(mchPath,
                GeneratorMode.PL,
                false,
                String.valueOf(Integer.MIN_VALUE),
                String.valueOf(Integer.MAX_VALUE),
                "10",
                true,
                false,
                true,
                null,
                false,
                false,
                null,
                null);
        Process process = Runtime.getRuntime()
                .exec("javac -classpath btypes.jar " + String.join(" ", javaFilePaths.stream()
                        .map(path -> path.toFile().getAbsoluteFile().toString())
                        .collect(Collectors.toSet())));

        writeInputToSystem(process.getErrorStream());
        writeInputToOutput(process.getErrorStream(), process.getOutputStream());
        process.waitFor();

        Set<File> classFiles = javaFilePaths.stream()
                .map(path -> new File(path.getParent().toFile(), machine + ".class"))
                .collect(Collectors.toSet());

        //javaFilePaths.forEach(path -> cleanUp(path.toString()));
        //classFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));
    }

}
