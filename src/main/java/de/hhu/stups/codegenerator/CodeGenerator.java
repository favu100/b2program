package de.hhu.stups.codegenerator;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.stream.JsonWriter;
import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.MachineReferenceGenerator;
import de.hhu.stups.codegenerator.json.modelchecker.ModelCheckingInfo;
import de.hhu.stups.codegenerator.json.visb.VisBEvent;
import de.hhu.stups.codegenerator.json.visb.VisBFileHandler;
import de.hhu.stups.codegenerator.json.visb.VisBItem;
import de.hhu.stups.codegenerator.json.visb.VisBVisualisation;
import de.prob.parser.antlr.Antlr4BParser;
import de.prob.parser.antlr.BProject;
import de.prob.parser.antlr.ScopeException;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.visitors.TypeErrorException;

import java.io.File;
import java.io.IOException;
import java.io.Writer;
import java.math.BigInteger;
import java.net.URISyntaxException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import static java.nio.file.StandardOpenOption.CREATE_NEW;
import static java.nio.file.StandardOpenOption.TRUNCATE_EXISTING;

import com.fatboyindustrial.gsonjavatime.Converters;

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
	* Example: gradle run -Planguage = "java" -Pbig_integer="false" -Pminint=-2047 -Pmaxint=2048 -Pdeferred_set_size="10" -Pfile = "Lift.mch"
	*/
	public static void main(String[] args) throws URISyntaxException, IOException, CodeGenerationException {
		if(args.length < 8 || args.length > 9) {
			System.err.println("Wrong number of arguments");
			return;
		}
		GeneratorMode mode = getMode(args[0]);
		boolean useBigInteger = useBigInteger(args[1]);
		String minint = args[2];
		String maxint = args[3];
		String deferredSetSize = args[4];
		boolean useConstraintSolving = useConstraintSolving(args[5]);
		boolean forModelChecking = forModelChecking(args[6]);
		CodeGenerator codeGenerator = new CodeGenerator();
		Path path = Paths.get(args[7]).toAbsolutePath();
		checkPath(path);
		checkIntegerRange(useBigInteger, minint, maxint);
		String addition = null;
		if(args.length == 9) {
			addition = args[8];
		}
		codeGenerator.generate(path, mode, useBigInteger, minint, maxint, deferredSetSize, forModelChecking, useConstraintSolving, true, addition, false);
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
		} else if("ts".equals(languageOption)) {
			mode = GeneratorMode.TS;
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

	/*
	 * This functon extracts boolean for using constraint solving from the given string
	 */
	private static boolean useConstraintSolving(String constraintOption) {
		boolean useConstraintSolving;
		if("true".equals(constraintOption)) {
			useConstraintSolving = true;
		} else if("false".equals(constraintOption)) {
			useConstraintSolving = false;
		} else {
			throw new RuntimeException("Wrong argument for choice of constraints");
		}
		return useConstraintSolving;
	}

	private static boolean forModelChecking(String modelCheckingOption) {
		boolean forModelChecking;
		if("true".equals(modelCheckingOption)) {
			forModelChecking = true;
		} else if("false".equals(modelCheckingOption)) {
			forModelChecking = false;
		} else {
			throw new RuntimeException("Wrong argument for choice of model checking");
		}
		return forModelChecking;
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
	public List<Path> generate(Path path, GeneratorMode mode, boolean useBigInteger, String minint, String maxint, String deferredSetSize, boolean forModelChecking, boolean useConstraintSolving, boolean isMain, String addition, boolean isIncludedMachine) throws CodeGenerationException, IOException {
		if(isMain) {
			paths.clear();
		}
		// Hard coded
		//VisBVisualisation visualisation = VisBFileHandler.constructVisualisationFromJSON(new File("./traffic_light.json"));
		//List<String> formulas = visualisation.getVisBItems().stream().map(VisBItem::getExpression).collect(Collectors.toList());
		//List<String> events = visualisation.getVisBEvents().stream().map(VisBEvent::getEvent).collect(Collectors.toList());

		BProject project = parseProject(path, new ArrayList<>(), new ArrayList<>());
		Path additionPath = Paths.get(path.getParent().toString(), addition != null ? addition: "");
		machineReferenceGenerator.generateIncludedMachines(project, path, mode, useBigInteger, minint, maxint, deferredSetSize, forModelChecking, useConstraintSolving);
		paths.add(writeToFile(path, mode, useBigInteger, minint, maxint, deferredSetSize, forModelChecking, useConstraintSolving, project.getMainMachine(), addition != null ? additionPath : null, isIncludedMachine));
		return paths;
	}

	/*
	* This function generates code for a targeted programming language with creating the belonging file
	*/
	private Path writeToFile(Path path, GeneratorMode mode, boolean useBigInteger, String minint, String maxint, String deferredSetSize, boolean forModelChecking, boolean useConstraintSolving, MachineNode node, Path addition, boolean isIncludedMachine) {
		MachineGenerator generator = new MachineGenerator(mode, useBigInteger, minint, maxint, deferredSetSize, forModelChecking, useConstraintSolving, addition, isIncludedMachine);
		machineReferenceGenerator.updateNameHandler(generator);
		machineReferenceGenerator.updateDeclarationGenerator(generator);
		machineReferenceGenerator.updateRecordStructGenerator(generator);

		String code = generator.generateMachine(node);

		String fileName = path.getFileName().toString().replace(".mch", "");
		Path newPath;
		if(mode == GeneratorMode.CPP && isIncludedMachine) {
			newPath = Paths.get(path.getParent().toString(), generator.getNameHandler().handle(fileName) + ".hpp");
		} else {
			newPath = Paths.get(path.getParent().toString(), generator.getNameHandler().handle(fileName) + "." + mode.name().toLowerCase());
		}
		Path jsonPath = Paths.get(path.getParent().toString(), generator.getNameHandler().handle(fileName) + ".json");
		try {
			if(forModelChecking) {
				ModelCheckingInfo mcInfo = generator.generateModelCheckingInfo(node);
				try (final Writer writer = Files.newBufferedWriter(jsonPath)) {
					final JsonWriter jsonWriter = new JsonWriter(writer);
					jsonWriter.setHtmlSafe(false);
					jsonWriter.setIndent("  ");
					Gson gson = Converters.registerAll(new GsonBuilder())
							.disableHtmlEscaping()
							.serializeNulls()
							.setPrettyPrinting()
							.create();

					gson.toJson(mcInfo.toJsonObject(), jsonWriter);
				}
			}
			return Files.write(newPath, code.getBytes(), Files.exists(newPath) ? TRUNCATE_EXISTING : CREATE_NEW);
		} catch (IOException e) {
			e.printStackTrace();
			throw new RuntimeException(e);
		}
	}

	/*
	* This function executes parsing and semantic checkings on a project
	*/
	private BProject parseProject(Path path, List<String> formulas, List<String> events) throws CodeGenerationException {
		BProject project;
		try {
			project = Antlr4BParser.createBProjectFromMainMachineFile(path.toFile(), formulas, events);
		} catch (TypeErrorException | ScopeException | IOException e) {
			e.printStackTrace();
			throw new CodeGenerationException(e.getMessage());
		}
		return project;
	}

	private BProject parseProject(Path path) throws CodeGenerationException {
		return parseProject(path, new ArrayList<>() , new ArrayList<>());
	}

	public List<Path> getPaths() {
		return paths;
	}

}
