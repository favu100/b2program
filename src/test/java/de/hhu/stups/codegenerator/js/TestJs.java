package de.hhu.stups.codegenerator.js;

import de.hhu.stups.codegenerator.CodeGenerator;
import de.hhu.stups.codegenerator.GeneratorMode;

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

import static org.junit.Assert.assertEquals;


public class TestJs {

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

	public void testJs(String machine) throws Exception {
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> tsFilePaths = codeGenerator.generate(mchPath, GeneratorMode.TS, false, String.valueOf(Integer.MIN_VALUE), String.valueOf(Integer.MAX_VALUE), "10", false,false, true, null, false);
		Process process = Runtime.getRuntime()
				.exec("tsc --target es2015 --moduleResolution node "  +
						String.join(" ", tsFilePaths.stream()
						.map(path -> path.toFile().getAbsoluteFile().toString())
						.collect(Collectors.toSet())));

		writeInputToSystem(process.getErrorStream());
		writeInputToOutput(process.getErrorStream(), process.getOutputStream());
		process.waitFor();

		Set<File> jsFiles = tsFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machine + ".class"))
				.collect(Collectors.toSet());

		jsFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));
	}

	public void testJs(String machinePath, String machineName, String addition, boolean execute) throws Exception {
		testJs(machinePath);
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machinePath + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> javaFilePaths = codeGenerator.generate(mchPath, GeneratorMode.TS, false, String.valueOf(Integer.MIN_VALUE), String.valueOf(Integer.MAX_VALUE), "10", false, false, true, addition, false);
		Runtime runtime = Runtime.getRuntime();
		Process compileProcess = runtime.exec("tsc --target es2020 --moduleResolution node " +
				String.join(" ", javaFilePaths.stream()
						.map(path -> path.toFile().getAbsoluteFile().toString())
						.collect(Collectors.toSet())));
		compileProcess.waitFor();

		String error = streamToString(compileProcess.getInputStream());
		if(!error.isEmpty()) {
			throw new RuntimeException(error);
		}
		Path mainPath = javaFilePaths.get(javaFilePaths.size() - 1);

		if(!execute) {
			return;
		}

		ProcessBuilder processBuilder = new ProcessBuilder();
		processBuilder.environment().put("NODE_PATH", "btypes_primitives/src/main/js/");
		processBuilder.command("node", "build/resources/test/de/hhu/stups/codegenerator/" + machinePath.substring(0, machinePath.length() - machineName.length()) + machineName + ".js");
		Process executeProcess = processBuilder.start();
		executeProcess.waitFor();

		error = streamToString(executeProcess.getErrorStream());
		if(!error.isEmpty()) {
			throw new RuntimeException(error);
		}

		String result = streamToString(executeProcess.getInputStream()).replaceAll("\n", "");
		String expectedOutput = streamToString(new FileInputStream(mainPath.toFile().getAbsoluteFile().toString().replaceAll(".ts", ".out"))).replaceAll("\n", "");

		System.out.println("Assert: " + result + " = " + expectedOutput);

		assertEquals(expectedOutput, result);

		Set<File> jsFiles = javaFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machinePath + ".js"))
				.collect(Collectors.toSet());

		jsFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));
	}

	private void cleanUp(String path) {
		File file = new File(path);
		if (file.exists()) {
			//file.delete();
		}
	}

}
