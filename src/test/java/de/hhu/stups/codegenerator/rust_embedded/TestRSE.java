package de.hhu.stups.codegenerator.rust_embedded;

import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.TestHelper;
import org.junit.Before;
import org.junit.Test;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

import static org.junit.Assert.*;

public class TestRSE {
    final ClassLoader classLoader = this.getClass().getClassLoader();
    final Path tomlPath = Paths.get(classLoader.getResource("./").toURI()).getParent().getParent().getParent().getParent().resolve(Paths.get("btypes_primitives/src/main/rust_embedded/bmachine/Cargo.toml"));
    final Path rustSrcPath = tomlPath.getParent().resolve(Paths.get("src/"));
    final Runtime runtime = Runtime.getRuntime();
    final Path testFileBasePath = Paths.get(classLoader.getResource("./").toURI()).getParent().getParent().getParent().resolve("resources/test/de/hhu/stups/codegenerator/");

    public TestRSE() throws URISyntaxException, IOException {
        Files.createDirectories(rustSrcPath);
    }

    public void cleanup() {
        File[] oldFiles = rustSrcPath.toFile().listFiles();
        if (oldFiles != null) Arrays.stream(oldFiles).forEach(File::delete);
    }

    public void generateTestFiles(String machineName, boolean modelChecking, String addition) throws IOException {
        if (addition == null) addition = "DefaultAddition.strs";
        cleanup();

        Path machinePath = testFileBasePath.resolve(machineName + ".mch");
        List<Path> rsFilePaths = TestHelper.generateCode(machinePath, GeneratorMode.RS, modelChecking, addition, true);
        rsFilePaths.forEach(path -> {
            Path dest = rustSrcPath.resolve(Paths.get(path.toFile().getName()));
            path.toFile().renameTo(dest.toFile());
        });

        File mainPath = rustSrcPath.resolve(machineName + ".rs").toFile();
        File newMainFile = rustSrcPath.resolve("main.rs").toFile();
        mainPath.renameTo(newMainFile);
    }

    public void compileTestFiles() throws IOException, InterruptedException {
        Process process = runtime.exec("cargo build --release --manifest-path " + tomlPath);
        TestHelper.writeInputToSystem(process.getErrorStream());
        TestHelper.writeInputToOutput(process.getErrorStream(), process.getOutputStream());
        process.waitFor();
        if (process.exitValue() != 0) {
            throw new RuntimeException("cargo build failed, exitcode: " + process.exitValue());
        }
    }

    public String runTestFiles(boolean modelChecking, boolean noDead, boolean noInv) throws IOException, InterruptedException {
        String progArgs = "";
        if (modelChecking) { progArgs = " -- mixed 2 true"; }
        if (noDead) { progArgs += " -nodead"; }
        if (noInv) { progArgs += " -noinv"; }

        Process executeProcess = runtime.exec("cargo run --release --manifest-path " + tomlPath + progArgs);
        executeProcess.waitFor();

        String error = TestHelper.streamToString(executeProcess.getErrorStream());
        if(executeProcess.exitValue() != 0) {
            System.err.println("cargo run failed!");
            throw new RuntimeException(error);
        }
        return TestHelper.streamToString(executeProcess.getInputStream());
    }

    public void verifyOutput(String machineName, boolean modelChecking, String actualOutput) throws IOException {
        if (modelChecking && !machineName.contains("MC")) machineName += "_MC";
        File outFile = testFileBasePath.resolve(machineName + ".out").toFile();
        String expectedOutput = TestHelper.readFile(outFile).replaceAll("[\n\r]", "");
        actualOutput = actualOutput.replaceAll("[\n\r]", "");

        if (!modelChecking) {
            System.out.println("Assert: " + actualOutput + " = " + expectedOutput);
            assertEquals(expectedOutput, actualOutput);
        } else {
            System.out.println("Asserting Success: ");
            System.out.println("Expected: " + expectedOutput);
            System.out.println("Gotten  : " + actualOutput);
            assertTrue(actualOutput.contains(expectedOutput));
        }
    }

    public void testRSE(String machineName, String addition) throws IOException, InterruptedException {
        boolean execute = true;
        boolean modelChecking = false;
        boolean noInv = false;
        boolean noDead = false;

        generateTestFiles(machineName, modelChecking, addition);
        compileTestFiles();

        if(!execute) {
            cleanup();
            return;
        }

        String result = runTestFiles(modelChecking, noDead, noInv);
        verifyOutput(machineName, modelChecking, result);

        cleanup();
    }
}
