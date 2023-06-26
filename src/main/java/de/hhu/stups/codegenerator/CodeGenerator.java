package de.hhu.stups.codegenerator;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.stream.JsonWriter;
import de.hhu.stups.codegenerator.blackbox.traces.TraceGenerator;
import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.MachineReferenceGenerator;
import de.hhu.stups.codegenerator.generators.VisualisationGenerator;
import de.hhu.stups.codegenerator.json.modelchecker.ModelCheckingInfo;
import de.hhu.stups.codegenerator.json.simb.SimulationRewriter;
import de.hhu.stups.codegenerator.json.visb.VisBFileHandler;
import de.hhu.stups.codegenerator.json.visb.VisBProject;
import de.hhu.stups.codegenerator.json.visb.VisBProjectParser;
import de.hhu.stups.codegenerator.json.visb.VisBVisualisation;
import de.hhu.stups.codegenerator.server.ServerLinkCompatibility;
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

import static de.hhu.stups.codegenerator.GeneratorMode.RL;
import static java.nio.file.StandardOpenOption.CREATE_NEW;
import static java.nio.file.StandardOpenOption.TRUNCATE_EXISTING;

import com.fatboyindustrial.gsonjavatime.Converters;
import org.apache.commons.cli.CommandLine;
import org.apache.commons.cli.DefaultParser;
import org.apache.commons.cli.HelpFormatter;
import org.apache.commons.cli.Options;
import org.apache.commons.cli.ParseException;

public class CodeGenerator {

	private static Options options;

	private final List<Path> paths = new ArrayList<>();

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

		CommandLine cmd = processArgs(args);

		assert cmd != null;

		GeneratorMode mode = getMode(cmd.getOptionValue("l"));
		boolean useBigInteger = useBigInteger(cmd.getOptionValue("bi"));
		String minint = cmd.getOptionValue("min") == null ? "-2147483648" : cmd.getOptionValue("min");
		String maxint = cmd.getOptionValue("max") == null ? "2147483647" : cmd.getOptionValue("max");
		String deferredSetSize = cmd.getOptionValue("dss") == null ? "10" : cmd.getOptionValue("dss");
		boolean useConstraintSolving = useConstraintSolving(cmd.getOptionValue("cs"));
		boolean forModelChecking = forModelChecking(cmd.getOptionValue("mc"));
		Path path = Paths.get(cmd.getOptionValue("f")).toAbsolutePath();
		String visualisationFile = cmd.getOptionValue("v") == null ? "" : cmd.getOptionValue("v");
		String serverLink = cmd.getOptionValue("sl") == null ? "." : cmd.getOptionValue("sl");
		String simulationFile = cmd.getOptionValue("sim") == null ? "" : cmd.getOptionValue("sim");
		String addition = cmd.getOptionValue("a");

		checkPath(path);
		checkIntegerRange(useBigInteger, minint, maxint);

		CodeGenerator codeGenerator = new CodeGenerator();

		boolean forVisualisation = !visualisationFile.isEmpty();
		if(forVisualisation && mode != GeneratorMode.TS) {
			throw new CodeGenerationException("Generating a visualisation is only supported for TypeScript");
		}
		codeGenerator.generate(path, mode, useBigInteger, minint, maxint, deferredSetSize, forModelChecking, useConstraintSolving, true, addition, false, forVisualisation, visualisationFile, serverLink);

		if(!simulationFile.isEmpty()) {
			SimulationRewriter.rewriteConfigurationFromJSON(new File(simulationFile), new File(simulationFile.replaceAll(".json", "_new.json")));
		}
	}

	private static CommandLine processArgs(String[] args) {
		options = new Options();
		options.addOption("l", "language", true, "Target Language");
		options.addOption("bi", "big_integer", true, "Use Big Integer");
		options.addOption("min", "minint", true, "MININT");
		options.addOption("max", "maxint", true, "MAXINT");
		options.addOption("dss", "deferred_set_size", true, "Deferred Set Size");
		options.addOption("cs", "useConstraintSolving", true, "Use Constraint Solving");
		options.addOption("mc", "forModelChecking", true, "For Model Checking");
		options.addOption("f", "file", true, "File");
		options.addOption("v", "visualisation", true, "VisB File");
		options.addOption("sl", "serverLink", true, "Server Link");
		options.addOption("a", "addition", true, "Additional Main Function");
		options.addOption("sim", "simulation", true, "SimB Simulation File");

		try {
			DefaultParser parser = new DefaultParser();
			return parser.parse(options, args);
		} catch (ParseException e) {
			System.out.println(e.getMessage());
			new HelpFormatter().printHelp("{-l <language> -bi <use_big_integer> -min <minint> -max <maxint> -dss <deferred_set_size> -cs <use_constraint_solving> -mc <forModelChecking> -f <filename> -v <visualisation> -a <additionalMain>} | -sim <simb_file>", options);
		}
		return null;
	}


	/*
	* This function extracts the generator mode representing the language code should be generated from the given string
	*/
	private static GeneratorMode getMode(String languageOption) {
		GeneratorMode mode;
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
		} else if("prolog".equals(languageOption)) {
			mode = GeneratorMode.PL;
		} else if("rs".equals(languageOption)) {
			mode = GeneratorMode.RS;
		} else {
			throw new RuntimeException(String.format("Wrong argument '%s' for language (must be java, python, c, cpp, clojure, ts, rs)", languageOption));
		}
		return mode;
	}


	/*
	* This function extracts boolean for using big integer from the given string
	*/
	private static boolean useBigInteger(String integerOption) {
		boolean useBigInteger;
		if("true".equals(integerOption)) {
			useBigInteger = true;
		} else if("false".equals(integerOption)) {
			useBigInteger = false;
		} else {
			useBigInteger = false; // default value
		}
		return useBigInteger;
	}

	/*
	 * This function extracts boolean for using constraint solving from the given string
	 */
	private static boolean useConstraintSolving(String constraintOption) {
		boolean useConstraintSolving;
		if("true".equals(constraintOption)) {
			useConstraintSolving = true;
		} else if("false".equals(constraintOption)) {
			useConstraintSolving = false;
		} else {
			useConstraintSolving = false; // default value
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
			forModelChecking = false; // default value
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
	public List<Path> generate(Path path, GeneratorMode mode, boolean useBigInteger,
														 String minint, String maxint, String deferredSetSize,
														 boolean forModelChecking, boolean useConstraintSolving,
														 boolean isMain, String addition, boolean isIncludedMachine,
														 boolean forVisualisation,
														 String visualisationFile,
							   							 String serverLink) throws CodeGenerationException, IOException {
		if(isMain) {
			paths.clear();
		}

		BProject project = parseProject(path);
		Path additionPath = Paths.get(path.getParent().toString(), addition != null ? addition: "");
		machineReferenceGenerator.generateIncludedMachines(project, path, mode, useBigInteger, minint, maxint, deferredSetSize, forModelChecking, useConstraintSolving, forVisualisation, serverLink);
		paths.add(generateCode(path, mode, useBigInteger, minint, maxint, deferredSetSize, forModelChecking, useConstraintSolving, project.getMainMachine(), addition != null ? additionPath : null, isIncludedMachine, forVisualisation, visualisationFile, project, serverLink));
		return paths;
	}

	public void generateBlackBoxTraceGenerator(Path path, String name, String modelPath, String learningTechnique, int episodes, String minint, String maxint, String deferredSetSize) {
		paths.clear();

		BProject project = parseProject(path);
		TraceGenerator traceGenerator = new TraceGenerator(name, modelPath, learningTechnique, episodes, minint, maxint, deferredSetSize);
		String traceGeneratorCode = traceGenerator.generate(project.getMainMachine());
		Path codePath = Paths.get(path.toString().replace(".mch", "")).toAbsolutePath();
		writeToFile(codePath, RL, false, null, false, null, traceGeneratorCode);
	}

	/*
	 * This function generates code for a targeted programming language with creating the belonging file
	 */
	private Path generateCode(Path path, GeneratorMode mode, boolean useBigInteger,
							  String minint, String maxint, String deferredSetSize,
							  boolean forModelChecking, boolean useConstraintSolving, MachineNode node,
							  Path addition, boolean isIncludedMachine, boolean forVisualisation, String visualisationFile,
							  BProject project, String serverLink) throws IOException {
		MachineGenerator generator =
				new MachineGenerator(mode, useBigInteger, minint, maxint, deferredSetSize, forModelChecking,
									useConstraintSolving, addition, isIncludedMachine, forVisualisation, serverLink);
		machineReferenceGenerator.updateNameHandler(generator);
		machineReferenceGenerator.updateDeclarationGenerator(generator);
		machineReferenceGenerator.updateRecordStructGenerator(generator);

		String code = generator.generateMachine(node, mode);
		Path codePath = writeToFile(path, mode, forModelChecking, node, isIncludedMachine, generator, code);

		if(forVisualisation && !isIncludedMachine) {

			VisBProject visBProject;
			if(visualisationFile != null) {
				VisBVisualisation visualisation = VisBFileHandler.constructVisualisationFromJSON(Paths.get(path.getParent().toString(), visualisationFile).toFile());
				visBProject = parseVisBProject(path, visualisation);
			} else {
				visBProject = parseVisBProject(path, new VisBVisualisation(new ArrayList<>(), new ArrayList<>(), null, null));
			}

			generateVisualisation(project, visBProject, generator, path);
		}

		return codePath;
	}

	private void generateVisualisation(BProject project, VisBProject visBProject, MachineGenerator generator, Path mainMachinePath) {
		VisualisationGenerator visualisationGenerator = new VisualisationGenerator(project, generator, generator.getImportGenerator(), generator.getExpressionGenerator(), generator.getInvariantGenerator(), generator.getIterationConstructHandler());
		String htmlCode = visualisationGenerator.generateHTML(visBProject);
		writeToFile(mainMachinePath, GeneratorMode.HTML, false, null, false, generator, htmlCode);
		//Has to be saved as <machineName>-visualisation.js
		String jsVisualisationCode = visualisationGenerator.generateVisualisation(visBProject);
		Path visualisationPath = Paths.get(mainMachinePath.toString().replace(".mch", "-visualisation.mch")).toAbsolutePath();
		writeToFile(visualisationPath, GeneratorMode.JS, false, null, false, generator, jsVisualisationCode);
		if(generator.getServerLink() != null && !generator.getServerLink().isEmpty()) {
			String serverCompatibilityCode = visualisationGenerator.generateServerLink();
			Path serverCompatibilityPath = Paths.get(mainMachinePath.toString().replace(".mch", "-compatibility.mch")).toAbsolutePath();
			writeToFile(serverCompatibilityPath, GeneratorMode.JS, false, null, false, generator, serverCompatibilityCode);
		}
	}

	/*
	 * This function writes code for a targeted programming language with creating the belonging file
	 */
	private Path writeToFile(Path path, GeneratorMode mode, boolean forModelChecking, MachineNode node, boolean isIncludedMachine, MachineGenerator generator, String code) {
		String fileName = path.getFileName().toString().replace(".mch", "");
		Path newPath = null;
		Path jsonPath = null;

		if (mode == GeneratorMode.CPP && isIncludedMachine) {
			newPath = Paths.get(path.getParent().toString(), generator.getNameHandler().handle(fileName) + ".hpp");
		} else if(mode == GeneratorMode.RL) {
			newPath = Paths.get(path.getParent().toString(), fileName + ".py");
		} else {
			newPath = Paths.get(path.getParent().toString(), generator.getNameHandler().handle(fileName) + "." + mode.name().toLowerCase());
		}

		if(mode != GeneratorMode.RL) {
			jsonPath = Paths.get(path.getParent().toString(), generator.getNameHandler().handle(fileName) + ".json");
		}

		try {
			if(forModelChecking) {
				ModelCheckingInfo mcInfo = generator.generateModelCheckingInfo(node);
				assert jsonPath != null;
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
	* This function executes parsing and semantic checking on a project
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

	private VisBProject parseVisBProject(Path path, VisBVisualisation visualisation) throws CodeGenerationException {
		VisBProject project;
		try {
			project = VisBProjectParser.createVisBProjectFromMainFile(path.toFile(), visualisation);
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
