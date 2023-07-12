package de.hhu.stups.codegenerator.js;

import de.hhu.stups.codegenerator.CodeGenerator;
import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.generators.CodeGenerationException;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

import static java.nio.file.StandardCopyOption.REPLACE_EXISTING;
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

	private void provideBTypesAndImmutables(Path machinePath) throws Exception{
		Path machineDirectory = machinePath.getParent();
		Path btypeDirectory = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("btypes").toURI());
		if (Files.exists(btypeDirectory)) {
			if (Files.notExists(machineDirectory.resolve("btypes"))) {
				Files.copy(btypeDirectory, machineDirectory.resolve("btypes"), REPLACE_EXISTING);
			}
			File[] btypesJS = btypeDirectory.toFile().listFiles((directory, name) -> name.toLowerCase().endsWith(".js"));
			if (btypesJS == null) {
				throw new CodeGenerationException("BTypes must be provided in resources/test/btypes.");
			}
			for (File file : btypesJS) {
				Files.copy(file.toPath(), machineDirectory.resolve("btypes/" + file.getName()), REPLACE_EXISTING);
			}
		}

		Path immutableDirectory = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("immutable").toURI());
		if (Files.exists(immutableDirectory)) {
			if (Files.notExists(machineDirectory.resolve("immutable"))) {
				Files.copy(btypeDirectory, machineDirectory.resolve("immutable"), REPLACE_EXISTING);
			}
			Files.copy(immutableDirectory.resolve("LICENSE"), machineDirectory.resolve("immutable/LICENSE"), REPLACE_EXISTING);
			if(Files.notExists(machineDirectory.resolve("immutable/dist"))) {
				Files.copy(immutableDirectory.resolve("dist"), machineDirectory.resolve("immutable/dist"), REPLACE_EXISTING);
			}
			Files.copy(immutableDirectory.resolve("dist/immutable.es.js"), machineDirectory.resolve("immutable/dist/immutable.es.js"), REPLACE_EXISTING);
		}

		Path modelcheckingDirectory = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("modelchecking").toURI());
		if (Files.exists(modelcheckingDirectory)) {
			if (Files.notExists(machineDirectory.resolve("modelchecking"))) {
				Files.copy(modelcheckingDirectory, machineDirectory.resolve("modelchecking"), REPLACE_EXISTING);
			}
			File[] modelcheckingJS = modelcheckingDirectory.toFile().listFiles((directory, name) -> name.toLowerCase().endsWith(".js"));
			if (modelcheckingJS == null) {
				throw new CodeGenerationException("Model Checking Sources must be provided in resources/test/modelchecking.");
			}
			for (File file : modelcheckingJS) {
				Files.copy(file.toPath(), machineDirectory.resolve("modelchecking/" + file.getName()), REPLACE_EXISTING);
			}
		}
	}

	/**
	 * Tests if the machine can successfully be transpiled to JS.
	 */
	public void testJs(String machine) throws Exception {
		List<Path> tsFilePaths = compileMachine(machine, null, null, false, false, null);

		Set<File> jsFiles = tsFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machine + ".js"))
				.collect(Collectors.toSet());

		jsFiles.forEach(path -> cleanUp(path.getAbsolutePath()));
	}

	public void testJSMC(String machine) throws Exception {
		List<Path> tsFilePaths = compileMachine(machine, null, null, false, true, null);

		Set<File> jsFiles = tsFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machine + ".js"))
				.collect(Collectors.toSet());

		jsFiles.forEach(path -> cleanUp(path.getAbsolutePath()));
	}

	public void testJs(String machinePath, String machineName, String addition, boolean execute) throws Exception {
		testJs(machinePath, machineName, addition, null, execute, false, null);
	}


	private List<Path> compileMachine(String machinePath, String addition, String visualisation, boolean forVisualisation, boolean forModelChecking, String serverLink) throws Exception {
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machinePath + ".mch").toURI());
		provideBTypesAndImmutables(mchPath);
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> tsFilePaths =
				codeGenerator.generate(mchPath,
						GeneratorMode.TS,
						false,
						String.valueOf(Integer.MIN_VALUE),
						String.valueOf(Integer.MAX_VALUE),
						"10",
						forModelChecking,
						false,
						true,
						addition,
						false,
						forVisualisation,
						visualisation,
						null);

		Process compileProcess = Runtime.getRuntime().exec("tsc --target ES6 --moduleResolution node " +
				String.join(" ", tsFilePaths.stream()
						.map(path -> path.toFile().getAbsoluteFile().toString())
						.collect(Collectors.toSet())));
		compileProcess.waitFor();

		writeInputToSystem(compileProcess.getErrorStream());
		writeInputToOutput(compileProcess.getErrorStream(), compileProcess.getOutputStream());
		compileProcess.waitFor();

		String error = streamToString(compileProcess.getInputStream());
		if(!error.isEmpty()) {
			throw new RuntimeException(error);
		}
		return tsFilePaths;
	}

	public void testJs(String machinePath, String machineName, String addition, String visualisation, boolean execute, boolean forVisualisation) throws Exception {
		testJs(machinePath, machineName, addition, visualisation, execute, forVisualisation, null);
	}

	/**
	 * Tests if the machine can be successfully transpiled to JS and be executed with node.
	 */
	public void testJs(String machinePath, String machineName, String addition, String visualisation, boolean execute, boolean forVisualisation, String serverLink) throws Exception {
		List<Path> tsFilePaths = compileMachine(machinePath, addition, visualisation, forVisualisation, false, serverLink);
		Path mainPath = tsFilePaths.get(tsFilePaths.size() - 1);

		if(!execute) {
			return;
		}

		ProcessBuilder processBuilder = new ProcessBuilder();
		processBuilder.environment().put("NODE_PATH", "btypes_primitives/src/main/js/");
		processBuilder.command("node", "--experimental-specifier-resolution=node", "build/resources/test/de/hhu/stups/codegenerator/" + machinePath.substring(0, machinePath.length() - machineName.length()) + machineName + ".js");
		Process executeProcess = processBuilder.start();
		executeProcess.waitFor();

		String error = streamToString(executeProcess.getErrorStream());
		if(!error.isEmpty()) {
			throw new RuntimeException(error);
		}

		String result = streamToString(executeProcess.getInputStream()).replaceAll("\n", "");
		String expectedOutput = streamToString(new FileInputStream(mainPath.toFile().getAbsoluteFile().toString().replace(".ts", ".out"))).replaceAll("\n", "");

		System.out.println("Assert: " + result + " = " + expectedOutput);

		assertEquals(expectedOutput, result);

		Set<File> jsFiles = tsFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machinePath + ".js"))
				.collect(Collectors.toSet());

		jsFiles.forEach(path -> cleanUp(path.getAbsolutePath()));
	}

	private void cleanUp(String path) {
		File file = new File(path);
		if (file.exists()) {
			//file.delete();
		}
	}

}
