package de.hhu.stups.codegenerator;

import de.hhu.stups.codegenerator.analyzers.RecordStructAnalyzer;
import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import de.hhu.stups.codegenerator.generators.DeclarationGenerator;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.prob.parser.antlr.Antlr4BParser;
import de.prob.parser.antlr.BProject;
import de.prob.parser.antlr.ScopeException;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.MachineReferenceNode;
import de.prob.parser.ast.types.RecordType;
import de.prob.parser.ast.visitors.TypeErrorException;

import java.io.IOException;
import java.math.BigInteger;
import java.net.URISyntaxException;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;

import static java.nio.file.StandardOpenOption.CREATE_NEW;
import static java.nio.file.StandardOpenOption.TRUNCATE_EXISTING;

public class CodeGenerator {

	private List<Path> paths = new ArrayList<>();

	private NameHandler nameHandler = null;

	private DeclarationGenerator declarationGenerator = null;

	private RecordStructAnalyzer recordStructAnalyzer = null;

	/*
	* Main function
	* First argument : Option for programming language
	* Second argument : Path for the main machine code should be generated for
	* Example: gradle run -Planguage = "java" -Pbig_integer="false" -Pminint=... -Pmaxint=... -Pfile = "de/hhu/stups/codegenerator/testfiles/Lift.mch"
	*/
	public static void main(String[] args) throws URISyntaxException, CodeGenerationException {
		if(args.length < 5 || args.length > 6) {
			System.err.println("Wrong number of arguments");
			return;
		}
		GeneratorMode mode = null;
		String languageOption = args[0];
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
			System.err.println("Wrong argument for language");
			return;
		}
		String integerOption = args[1];
		boolean useBigInteger;
		if("true".equals(integerOption)) {
			useBigInteger = true;
		} else if("false".equals(integerOption)) {
			useBigInteger = false;
		} else {
			System.err.println("Wrong argument for choice of integers");
			return;
		}
		String minint = args[2];
		String maxint = args[3];
		CodeGenerator codeGenerator = new CodeGenerator();
		URL url = CodeGenerator.class.getClassLoader().getResource(args[4]);
		if(url == null) {
			System.err.println("File not found");
			return;
		}
		String addition = null;
		if(new BigInteger(minint).compareTo(new BigInteger(String.valueOf(Integer.MIN_VALUE))) == -1 ||
				new BigInteger(maxint).compareTo(new BigInteger(String.valueOf(Integer.MAX_VALUE))) == 1) {
			if(!useBigInteger) {
				System.err.println("The given range of MININT..MAXINT must use big integers");
				return;
			}
		}
		if(args.length == 6) {
			addition = args[5];
		}
		codeGenerator.generate(Paths.get(url.toURI()), mode, useBigInteger, minint, maxint, true, addition);
	}

	/*
	* This function generates code from a given path for a machine, the target language and the information whether it is a main machine of a project
	*/
	public List<Path> generate(Path path, GeneratorMode mode, boolean useBigInteger, String minint, String maxint, boolean isMain, String addition) throws CodeGenerationException {
		if(isMain) {
			paths.clear();
		}
		BProject project = parseProject(path);
		String[] pathAsList = path.toString().split("/");
		String[] additionAsList = Arrays.copyOf(pathAsList, pathAsList.length);
		if(addition != null) {
			additionAsList[additionAsList.length - 1] = addition;
		}
		for(MachineReferenceNode referenceNode : project.getMainMachine().getMachineReferences()) {
			pathAsList[pathAsList.length - 1] = pathAsList[pathAsList.length - 1].replaceAll(project.getMainMachine().getName(), referenceNode.getMachineName());
			Path currentPath = Paths.get(String.join("/", pathAsList));
			if(!paths.contains(currentPath)) {
				generate(currentPath, mode, useBigInteger, minint, maxint, false, null);
			}
		}
		paths.add(writeToFile(path, mode, useBigInteger, minint, maxint, project.getMainMachine(), addition != null ? Paths.get(String.join("/",additionAsList)) : null));
		return paths;
	}

	/*
	* This function generates code for a targeted programming language with creating the belonging file
	*/
	private Path writeToFile(Path path, GeneratorMode mode, boolean useBigInteger, String minint, String maxint, MachineNode node, Path addition) {
		MachineGenerator generator = new MachineGenerator(mode, useBigInteger, minint, maxint, addition);
		if(nameHandler != null) {
			Map<String, List<String>> enumTypes = nameHandler.getEnumTypes();
			for(String key : enumTypes.keySet()) {
				generator.getNameHandler().getEnumTypes().put(key, enumTypes.get(key));
			}
			generator.getNameHandler().getReservedMachines().addAll(nameHandler.getReservedMachines());
			generator.getNameHandler().getReservedMachinesAndFunctions().addAll(nameHandler.getReservedMachinesAndFunctions());
			generator.getNameHandler().getReservedMachinesAndFunctionsAndVariables().addAll(nameHandler.getReservedMachinesAndFunctionsAndVariables());
			generator.getNameHandler().getReservedMachinesWithIncludedMachines().addAll(nameHandler.getReservedMachinesWithIncludedMachines());

		}

		if(declarationGenerator != null) {
			Map<String, List<String>> setToEnum = declarationGenerator.getSetToEnum();
			for(String key : setToEnum.keySet()) {
				generator.getDeclarationGenerator().getSetToEnum().put(key, setToEnum.get(key));
			}
			Map<String, String> enumToMachine = declarationGenerator.getEnumToMachine();
			for(String key : enumToMachine.keySet()) {
				generator.getDeclarationGenerator().getEnumToMachine().put(key, enumToMachine.get(key));
			}
		}

		if(recordStructAnalyzer != null) {
			List<RecordType> structs = recordStructAnalyzer.getStructs();
			generator.getRecordStructAnalyzer().getStructs().addAll(structs);
			Map<String, String> nodeToClassName = recordStructAnalyzer.getNodeToClassName();
			for(String key : nodeToClassName.keySet()) {
				generator.getRecordStructAnalyzer().getNodeToClassName().put(key, nodeToClassName.get(key));
			}
		}

		String code = generator.generateMachine(node);

		nameHandler = generator.getNameHandler();
		declarationGenerator = generator.getDeclarationGenerator();
		recordStructAnalyzer = generator.getRecordStructAnalyzer();


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

}
