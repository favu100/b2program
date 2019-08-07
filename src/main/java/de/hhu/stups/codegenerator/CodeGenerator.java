package de.hhu.stups.codegenerator;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.MachineReferenceGenerator;
import de.prob.parser.antlr.Antlr4BParser;
import de.prob.parser.antlr.BProject;
import de.prob.parser.antlr.ScopeException;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.visitors.TypeErrorException;

import java.io.IOException;
import java.math.BigInteger;
import java.net.MalformedURLException;
import java.net.URISyntaxException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static java.nio.file.StandardOpenOption.CREATE_NEW;
import static java.nio.file.StandardOpenOption.TRUNCATE_EXISTING;

public class CodeGenerator {

	private List<Path> paths = new ArrayList<>();

	private final MachineReferenceGenerator machineReferenceGenerator;

	public CodeGenerator() {
		this.machineReferenceGenerator = new MachineReferenceGenerator(this);
	}

	/*
	* Main function
	* First argument : Option for programming language
	* Second argument : Path for the main machine code should be generated for
	* Example: gradle run -Planguage = "java" -Pbig_integer="false" -Pminint=-2047 -Pmaxint=2048 -Pfile = "Lift.mch"
	*/
	public static void main(String[] args) throws URISyntaxException, MalformedURLException, CodeGenerationException {
		if(args.length < 6 || args.length > 7) {
			System.err.println("Wrong number of arguments");
			return;
		}
		GeneratorMode mode = getMode(args[0]);
		boolean useBigInteger = useBigInteger(args[1]);
		String minint = args[2];
		String maxint = args[3];
		String deferredSetSize = args[4];
		CodeGenerator codeGenerator = new CodeGenerator();
		Path path = Paths.get(args[5]);
		checkPath(path);
		checkIntegerRange(useBigInteger, minint, maxint);
		String addition = null;
		if(args.length == 7) {
			addition = args[6];
		}
		codeGenerator.generate(path, mode, useBigInteger, minint, maxint, deferredSetSize, true, addition);
	}

	/*
	* This function extracts the generator mode representing the language code should be generated from from the given string
	*/
	private static GeneratorMode getMode(String languageOption) {
		GeneratorMode mode = null;
		if("java".equals(languageOption)) {
			mode = GeneratorMode.JAVA;
		} else if("python".equals(languageOption)) {
			mode = GeneratorMode.PY;
		} else if("c".equals(languageOption)) {
			mode = GeneratorMode.C;
		} else if("cpp".equals(languageOption)) {
			mode = GeneratorMode.CPP;
		} else if("clojure".equals(languageOption)) {
			mode = GeneratorMode.CLJ;
		} else {
			throw new RuntimeException("Wrong argument for language");
		}
		return mode;
	}


	/*
	* This functon extracts boolean for using big integer from the given string
	*/
	private static boolean useBigInteger(String integerOption) {
		boolean useBigInteger;
		if("true".equals(integerOption)) {
			useBigInteger = true;
		} else if("false".equals(integerOption)) {
			useBigInteger = false;
		} else {
			throw new RuntimeException("Wrong argument for choice of integers");
		}
		return useBigInteger;
	}

	private static void checkPath(Path path) {
		if(path == null) {
			throw new RuntimeException("File not found");
		}
	}

	/*
	*  This function checks the integer range from the given options for MININT, MAXINT and using big integer
	*/
	private static void checkIntegerRange(boolean useBigInteger, String minint, String maxint) {
		if(new BigInteger(minint).compareTo(new BigInteger(String.valueOf(Integer.MIN_VALUE))) == -1 ||
				new BigInteger(maxint).compareTo(new BigInteger(String.valueOf(Integer.MAX_VALUE))) == 1) {
			if(!useBigInteger) {
				throw new CodeGenerationException("The given range of MININT..MAXINT must use big integers");
			}
		}
	}

	/*
	* This function generates code from a given path for a machine, the target language and the information whether it is a main machine of a project
	*/
	public List<Path> generate(Path path, GeneratorMode mode, boolean useBigInteger, String minint, String maxint, String deferredSetSize, boolean isMain, String addition) throws CodeGenerationException {
		if(isMain) {
			paths.clear();
		}
		BProject project = parseProject(path);
		String[] pathAsList = path.toString().split("/");
		String[] additionAsList = Arrays.copyOf(pathAsList, pathAsList.length);
		if(addition != null) {
			additionAsList[additionAsList.length - 1] = addition;
		}
		machineReferenceGenerator.generateIncludedMachines(project, pathAsList, mode, useBigInteger, minint, maxint, deferredSetSize);
		paths.add(writeToFile(path, mode, useBigInteger, minint, maxint, deferredSetSize, project.getMainMachine(), addition != null ? Paths.get(String.join("/",additionAsList)) : null));
		return paths;
	}

	/*
	* This function generates code for a targeted programming language with creating the belonging file
	*/
	private Path writeToFile(Path path, GeneratorMode mode, boolean useBigInteger, String minint, String maxint, String deferredSetSize, MachineNode node, Path addition) {
		MachineGenerator generator = new MachineGenerator(mode, useBigInteger, minint, maxint, deferredSetSize, addition);
		machineReferenceGenerator.updateNameHandler(generator);
		machineReferenceGenerator.updateDeclarationGenerator(generator);
		machineReferenceGenerator.updateRecordStructGenerator(generator);

		String code = generator.generateMachine(node);

		int lastIndexDot = path.toString().lastIndexOf(".");
		int lastIndexSlash = path.toString().lastIndexOf("/");

		String fileName = path.toString().substring(lastIndexSlash + 1, lastIndexDot);
		Path newPath = Paths.get(path.toString().substring(0, lastIndexSlash + 1) + generator.getNameHandler().handle(fileName) + "." + mode.name().toLowerCase());
		try {
			return Files.write(newPath, code.getBytes(), Files.exists(newPath) ? TRUNCATE_EXISTING : CREATE_NEW);
		} catch (IOException e) {
			e.printStackTrace();
			throw new RuntimeException(e);
		}
	}

	/*
	* This function executes parsing and semantic checkings on a project
	*/
	private BProject parseProject(Path path) throws CodeGenerationException {
		BProject project;
		try {
			project = Antlr4BParser.createBProjectFromMainMachineFile(path.toFile());
		} catch (TypeErrorException | ScopeException | IOException e) {
			e.printStackTrace();
			throw new CodeGenerationException(e.getMessage());
		}
		return project;
	}

	public List<Path> getPaths() {
		return paths;
	}

}
