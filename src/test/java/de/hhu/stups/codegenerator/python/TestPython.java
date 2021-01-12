package de.hhu.stups.codegenerator.python;

import static org.junit.Assert.assertEquals;
import de.hhu.stups.codegenerator.CodeGenerator;
import de.hhu.stups.codegenerator.GeneratorMode;
import org.junit.Ignore;
import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * Created by fabian on 31.05.18.
 */

public class TestPython {

	public static void writeInputToOutput(InputStream inputStream, OutputStream outputStream) throws IOException {
		int size;
		byte[] buffer = new byte[1024];
		while ((size = inputStream.read(buffer)) != -1)
			outputStream.write(buffer, 0, size);
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

	public void testPython(String machine) throws Exception {
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> pythonFilePaths = codeGenerator.generate(mchPath, GeneratorMode.PY, false, String.valueOf(Integer.MIN_VALUE), String.valueOf(Integer.MAX_VALUE), "10", true, null, false);

		//pythonFilePaths.forEach(path -> cleanUp(path.toString()));
	}

	public void testPython(String machinePath, String machineName, String addition, boolean execute) throws Exception {
		testPython(machinePath);
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machinePath + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> pythonFilePaths = codeGenerator.generate(mchPath, GeneratorMode.PY, false, String.valueOf(Integer.MIN_VALUE), String.valueOf(Integer.MAX_VALUE), "10", true, addition, false);

    Path mainPath = pythonFilePaths.get(pythonFilePaths.size() - 1);

    if(!execute) {
      return;
    }

    ProcessBuilder processBuilder = new ProcessBuilder();
    processBuilder.environment().put("PYTHONPATH", "btypes_persistent.jar");
    processBuilder.command("python",  "build/resources/test/de/hhu/stups/codegenerator/" + machinePath.substring(0, machinePath.length() - machineName.length()) + machineName + ".py");
    Process executeProcess = processBuilder.start();
    executeProcess.waitFor();

    String error = streamToString(executeProcess.getErrorStream());
    if(!error.isEmpty()) {
      throw new RuntimeException(error);
    }

    String result = streamToString(executeProcess.getInputStream()).replaceAll("\n", "");
    String expectedOutput = streamToString(new FileInputStream(mainPath.toFile().getAbsoluteFile().toString().replaceAll(".py", ".out"))).replaceAll("\n", "");

    System.out.println("Assert: " + result + " = " + expectedOutput);

    assertEquals(result, expectedOutput);

    /*Set<File> classFiles = pythonFilePaths.stream()
        .map(path -> new File(path.getParent().toFile(), machinePath + ".class"))
        .collect(Collectors.toSet());*/

		//pythonFilePaths.forEach(path -> cleanUp(path.toString()));
	}

	private void cleanUp(String path) {
		File file = new File(path);
		if (file.exists()) {
			file.delete();
		}
	}

}
