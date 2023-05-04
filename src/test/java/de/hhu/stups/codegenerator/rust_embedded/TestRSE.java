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
    //array
    //final Path tomlPath = Paths.get(classLoader.getResource("./").toURI()).getParent().getParent().getParent().getParent().resolve(Paths.get("btypes_primitives/src/main/rust_embedded/bmachine/Cargo.toml"));
    //bitvec
    final Path tomlPath = Paths.get(classLoader.getResource("./").toURI()).getParent().getParent().getParent().getParent().resolve(Paths.get("btypes_primitives/src/main/rust_embedded/bmachine_bitvec/Cargo.toml"));
    //final Path tomlPath_MC = Paths.get(classLoader.getResource("./").toURI()).getParent().getParent().getParent().getParent().resolve(Paths.get("btypes_primitives/src/main/rust_embedded/bmachine_mc/Cargo.toml"));
    final Path tomlPath_MC = Paths.get(classLoader.getResource("./").toURI()).getParent().getParent().getParent().getParent().resolve(Paths.get("btypes_primitives/src/main/rust_embedded/bmachine_bitvec_mc/Cargo.toml"));
    //final Path rustSrcPath = tomlPath.getParent().resolve(Paths.get("src/")); // arrays
    final Path rustSrcPath = tomlPath.getParent().resolve(Paths.get("src/")); // bitvec
    //final Path rustSrcPath_MC = tomlPath_MC.getParent().resolve(Paths.get("src/"));
    final Path rustSrcPath_MC = tomlPath_MC.getParent().resolve(Paths.get("src/"));
    final Runtime runtime = Runtime.getRuntime();
    final Path testFileBasePath = Paths.get(classLoader.getResource("./").toURI()).getParent().getParent().getParent().resolve("resources/test/de/hhu/stups/codegenerator/");
    //final String cargoChannel = "";
    final String cargoChannel = "+nightly";

    public TestRSE() throws URISyntaxException, IOException {
        Files.createDirectories(rustSrcPath);
    }

    public void cleanup(boolean modelChecking) {
        File[] oldFiles = (!modelChecking ? rustSrcPath : rustSrcPath_MC).toFile().listFiles();
        if (oldFiles != null) Arrays.stream(oldFiles).forEach(File::delete);
    }

    public void generateTestFiles(String machineRelPath, boolean modelChecking, String addition) throws IOException {
        if (addition == null && !modelChecking) addition = "DefaultAddition.strs";
        cleanup(modelChecking);
        final Path usedPath = !modelChecking ? rustSrcPath : rustSrcPath_MC;

        Path machinePath = testFileBasePath.resolve(machineRelPath + ".mch");
        List<Path> rsFilePaths = TestHelper.generateCode(machinePath, GeneratorMode.RS, modelChecking, addition, true);
        rsFilePaths.forEach(path -> {
            Path dest = usedPath.resolve(Paths.get(path.toFile().getName()));
            path.toFile().renameTo(dest.toFile());
        });

        int i = machineRelPath.lastIndexOf('/');
        File mainPath = usedPath.resolve(machineRelPath.substring(i+1) + ".rs").toFile();
        File newMainFile = usedPath.resolve("main.rs").toFile();
        mainPath.renameTo(newMainFile);
    }

    public void compileTestFiles(boolean forModelChecking) throws IOException, InterruptedException {
        Path usedTomlPath = !forModelChecking ? tomlPath : tomlPath_MC;
        Process process = runtime.exec(String.format("cargo %s build --release --manifest-path %s", cargoChannel, usedTomlPath));
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

        Path usedTomlPath = !modelChecking ? tomlPath : tomlPath_MC;

        Process executeProcess = runtime.exec(String.format("cargo %s run --release --manifest-path %s %s", cargoChannel, usedTomlPath, progArgs));
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
        testRSE(machineName, addition, false);
    }

    public void testRSEMC(String machineName) throws IOException, InterruptedException {
        testRSE(machineName, null, true);
    }

    public void testRSE(String machineName, String addition, boolean modelChecking) throws IOException, InterruptedException {
        boolean execute = modelChecking || addition != null;
        boolean noInv = false;
        boolean noDead = false;

        generateTestFiles(machineName, modelChecking, addition);
        compileTestFiles(modelChecking);

        if(!execute) {
            cleanup(modelChecking);
            return;
        }

        String result = runTestFiles(modelChecking, noDead, noInv);
        verifyOutput(machineName, modelChecking, result);

        cleanup(modelChecking);
    }
}
