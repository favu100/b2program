package de.hhu.stups.codegenerator.rust_embedded;

import de.hhu.stups.codegenerator.CodeGenerator;
import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.TestHelper;
import org.junit.Before;
import org.junit.Test;

import java.io.File;
import java.io.IOException;
import java.net.URISyntaxException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

import static org.junit.Assert.assertNotNull;

public class TestSets {
    final ClassLoader classLoader = this.getClass().getClassLoader();
    final Path rustSrcPath = Paths.get(classLoader.getResource("./").toURI()).getParent().getParent().getParent().getParent().resolve(Paths.get("btypes_primitives/src/main/rust_embedded/bmachine/src"));
    final Runtime runtime = Runtime.getRuntime();

    public TestSets() throws URISyntaxException, IOException {
        Files.createDirectories(rustSrcPath);
    }

    @Before
    public void beforeEach() {
        File[] oldFiles = rustSrcPath.toFile().listFiles();
        if (oldFiles != null) Arrays.stream(oldFiles).forEach(File::delete);
    }

    @Test
    public void test_SimpleEnumeratedSet() throws IOException, InterruptedException {
        boolean execute = true;
        boolean modelChecking = false;
        boolean noInv = false;
        boolean noDead = false;

        String machineFile = "";
        URL machineURL = classLoader.getResource("de/hhu/stups/codegenerator/embedded/" + machineFile);
        assertNotNull(machineURL);
        Path machinePath = Paths.get(machineURL.getPath());
        List<Path> rsFilePaths = TestHelper.generateCode(machinePath, GeneratorMode.RS, false, "DefaultAddition.strs", true);
        rsFilePaths = rsFilePaths.stream().map(path -> {
            Path dest = rustSrcPath.resolve(Paths.get(path.toFile().getName()));
            path.toFile().renameTo(dest.toFile());
            return dest;
        }).collect(Collectors.toList());

        Path mainPath = rsFilePaths.get(rsFilePaths.size() - 1);
        File newMainFile = rustSrcPath.resolve(Paths.get("main.rs")).toFile();
        mainPath.toFile().renameTo(newMainFile);

        Process process = runtime.exec("cargo build --release --manifest-path " + mainPath.getParent().getParent().toFile().getAbsolutePath() + "/Cargo.toml");
        TestHelper.writeInputToSystem(process.getErrorStream());
        TestHelper.writeInputToOutput(process.getErrorStream(), process.getOutputStream());
        process.waitFor();
        if (process.exitValue() != 0) {
            throw new RuntimeException("cargo build failed, exitcode: " + process.exitValue());
        }

        if(!execute) {
            rsFilePaths.forEach(p -> p.toFile().delete());
            return;
        }

        String progArgs = "";
        if (modelChecking) { progArgs = " -- mixed 2 true"; }
        if (noDead) { progArgs += " -nodead"; }
        if (noInv) { progArgs += " -noinv"; }

        Process executeProcess = runtime.exec("cargo run --release --manifest-path " + mainPath.getParent().getParent().toFile().getAbsolutePath() + "/Cargo.toml" + progArgs);
        executeProcess.waitFor();

        String error = TestHelper.streamToString(executeProcess.getErrorStream());
        if(executeProcess.exitValue() != 0) {
            throw new RuntimeException(error);
        }
        String result = TestHelper.streamToString(executeProcess.getInputStream());
    }
}
