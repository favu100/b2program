package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.CodeGeneratorUtils;
import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.MachineConstantsOptimizer;
import de.hhu.stups.codegenerator.analyzers.CheckReachabilityAnalyzer;
import de.hhu.stups.codegenerator.analyzers.DeferredSetAnalyzer;
import de.hhu.stups.codegenerator.analyzers.RecordStructAnalyzer;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.ParallelConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.hhu.stups.codegenerator.json.modelchecker.ModelCheckingInfo;
import de.prob.parser.ast.nodes.*;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.expression.IfExpressionNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.expression.LetExpressionNode;
import de.prob.parser.ast.nodes.expression.NumberNode;
import de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode;
import de.prob.parser.ast.nodes.expression.RealNumberNode;
import de.prob.parser.ast.nodes.expression.RecordFieldAccessNode;
import de.prob.parser.ast.nodes.expression.RecordNode;
import de.prob.parser.ast.nodes.expression.SetComprehensionNode;
import de.prob.parser.ast.nodes.expression.StringNode;
import de.prob.parser.ast.nodes.expression.StructNode;
import de.prob.parser.ast.nodes.ltl.LTLBPredicateNode;
import de.prob.parser.ast.nodes.ltl.LTLInfixOperatorNode;
import de.prob.parser.ast.nodes.ltl.LTLKeywordNode;
import de.prob.parser.ast.nodes.ltl.LTLPrefixOperatorNode;
import de.prob.parser.ast.nodes.predicate.CastPredicateExpressionNode;
import de.prob.parser.ast.nodes.predicate.IdentifierPredicateNode;
import de.prob.parser.ast.nodes.predicate.IfPredicateNode;
import de.prob.parser.ast.nodes.predicate.LetPredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import de.prob.parser.ast.nodes.predicate.QuantifiedPredicateNode;
import de.prob.parser.ast.nodes.substitution.AnySubstitutionNode;
import de.prob.parser.ast.nodes.substitution.AssignSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.BecomesElementOfSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.BecomesSuchThatSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ChoiceSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ConditionSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.IfOrSelectSubstitutionsNode;
import de.prob.parser.ast.nodes.substitution.LetSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ListSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.OperationCallSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.SkipSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.VarSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.WhileSubstitutionNode;
import de.prob.parser.ast.types.CoupleType;
import de.prob.parser.ast.types.UntypedType;
import de.prob.parser.ast.visitors.AbstractVisitor;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;
import java.util.stream.Collectors;

/*
* The code generator is implemented by using the visitor pattern
*/

public class MachineGenerator implements AbstractVisitor<String, Void> {

	private final MachinePreprocessor machinePreprocessor;

	private final TypeGenerator typeGenerator;

	private final ImportGenerator importGenerator;

	private final IterationConstructHandler iterationConstructHandler;

	private final OperatorGenerator operatorGenerator;

	private final OperationGenerator operationGenerator;

	private DeclarationGenerator declarationGenerator;

	private final ExpressionGenerator expressionGenerator;

	private final PredicateGenerator predicateGenerator;

	private final LambdaFunctionGenerator lambdaFunctionGenerator;

	private final SubstitutionGenerator substitutionGenerator;

	private final IdentifierGenerator identifierGenerator;

	private final NameHandler nameHandler;

	private final ParallelConstructHandler parallelConstructHandler;

	private final RecordStructAnalyzer recordStructAnalyzer;

	private final RecordStructGenerator recordStructGenerator;

	private final DeferredSetAnalyzer deferredSetAnalyzer;

	private final SetWithPredicateGenerator infiniteSetGenerator;

	private final ModelCheckingGenerator modelCheckingGenerator;

	private final ModelCheckingInfoGenerator modelCheckingInfoGenerator;

	private final InvariantGenerator invariantGenerator;

	private final TransitionGenerator transitionGenerator;

	private final BacktrackingGenerator backtrackingGenerator;

	private final CheckReachabilityAnalyzer checkReachabilityAnalyzer;

	private final boolean forModelChecking;

	private final boolean forVisualisation;

	private final boolean useBigInteger;

	private final String serverLink;

	private final Map<String, Integer> boundedVariablesDepth;

	private final STGroup currentGroup;

	private MachineNode machineNode;

	private String addition;

	private int iterationConstructDepth;

	private final boolean isIncludedMachine;

	private final Set<String> lambdaFunctions;

	private final Set<String> infiniteSets;

	private int currentExpressionCount;

	private int currentStateCount;

	private GeneratorMode mode;

	private List<String> constants;

	private Set<String> enumIdentifier;

	public MachineGenerator(GeneratorMode mode, boolean useBigInteger, String minint, String maxint, String deferredSetSize,
							boolean forModelChecking, boolean useConstraintSolving, Path addition, boolean isIncludedMachine,
							boolean forVisualisation, String serverLink) {
		this.mode = mode;
		this.currentGroup = CodeGeneratorUtils.getGroup(mode);
		this.forModelChecking = forModelChecking;
		this.forVisualisation = forVisualisation;
		this.useBigInteger = useBigInteger;
		this.serverLink = serverLink;
		this.boundedVariablesDepth = new HashMap<>();
		if(addition != null && !addition.toFile().isDirectory()) {
			try {
				this.addition = new String(Files.readAllBytes(addition));
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		this.machinePreprocessor = new MachinePreprocessor(forModelChecking, forVisualisation);
		this.nameHandler = new NameHandler(this, currentGroup);
		this.parallelConstructHandler = new ParallelConstructHandler();
		this.typeGenerator = new TypeGenerator(currentGroup, nameHandler, this);
		this.importGenerator = new ImportGenerator(currentGroup, nameHandler, useBigInteger);
		this.backtrackingGenerator = new BacktrackingGenerator(currentGroup);
		this.iterationConstructHandler = new IterationConstructHandler(currentGroup, this, nameHandler, typeGenerator, importGenerator, backtrackingGenerator, useConstraintSolving);
		this.deferredSetAnalyzer = new DeferredSetAnalyzer(Integer.parseInt(deferredSetSize));
		this.infiniteSetGenerator = new SetWithPredicateGenerator(currentGroup, this, nameHandler, typeGenerator);
		this.identifierGenerator = new IdentifierGenerator(currentGroup, this, nameHandler, parallelConstructHandler, declarationGenerator);
		this.recordStructGenerator = new RecordStructGenerator(currentGroup, this, typeGenerator, importGenerator, nameHandler);
		this.declarationGenerator = new DeclarationGenerator(currentGroup, this, typeGenerator, importGenerator, nameHandler, deferredSetAnalyzer);
		this.expressionGenerator = new ExpressionGenerator(mode, currentGroup, this, useBigInteger, minint, maxint, nameHandler, importGenerator,
				declarationGenerator, identifierGenerator, typeGenerator, iterationConstructHandler, recordStructGenerator);
		this.predicateGenerator = new PredicateGenerator(currentGroup, this, nameHandler, importGenerator, iterationConstructHandler, infiniteSetGenerator);
		this.lambdaFunctionGenerator = new LambdaFunctionGenerator(currentGroup, expressionGenerator, predicateGenerator, typeGenerator, declarationGenerator);
		this.recordStructAnalyzer = new RecordStructAnalyzer(recordStructGenerator);
		this.substitutionGenerator = new SubstitutionGenerator(currentGroup, this, nameHandler, typeGenerator,
																expressionGenerator, predicateGenerator, identifierGenerator, iterationConstructHandler,
																parallelConstructHandler, recordStructGenerator, declarationGenerator, lambdaFunctionGenerator,
																infiniteSetGenerator, backtrackingGenerator, deferredSetAnalyzer, forVisualisation);
		this.operatorGenerator = new OperatorGenerator(mode, predicateGenerator, expressionGenerator);
		this.operationGenerator = new OperationGenerator(currentGroup, this, substitutionGenerator, declarationGenerator, identifierGenerator, nameHandler,
															typeGenerator, recordStructGenerator);
		this.checkReachabilityAnalyzer = new CheckReachabilityAnalyzer();
		this.modelCheckingGenerator = new ModelCheckingGenerator(currentGroup, nameHandler, typeGenerator, backtrackingGenerator, checkReachabilityAnalyzer);
		this.invariantGenerator = new InvariantGenerator(mode, currentGroup, this, iterationConstructHandler);
		this.transitionGenerator = new TransitionGenerator(currentGroup, nameHandler, this, typeGenerator, iterationConstructHandler);
		this.modelCheckingInfoGenerator = new ModelCheckingInfoGenerator(currentGroup, nameHandler, invariantGenerator, transitionGenerator, typeGenerator);
		this.iterationConstructDepth = 0;
		this.isIncludedMachine = isIncludedMachine;
		this.lambdaFunctions = new HashSet<>();
		this.infiniteSets = new HashSet<>();
		this.currentExpressionCount = 0;
		this.currentStateCount = 0;
		this.enumIdentifier = new HashSet<>();
	}

	public int getAndIncCurrentExpressionCount() {
		return currentExpressionCount++;
	}

	public boolean isUseBigInteger() { return useBigInteger; }

	public int getCurrentExpressionCount() {
		return currentExpressionCount;
	}

	public void setCurrentExpressionCount(int c) {
		currentExpressionCount = c;
	}

	public void resetCurrentExpressionCount() {
		this.currentExpressionCount = 0;
	}

	public int getAndIncCurrentStateCount() {
		return currentStateCount++;
	}

	public int getCurrentStateCount() {
		return currentStateCount;
	}

	public void setCurrentStateCount(int c) {
		currentStateCount = c;
	}

	public void resetCurrentStateCount() {
		this.currentStateCount = 0;
	}

	public List<String> getConstants() {
		return constants;
	}

	public Set<String> getEnumIdentifier() {
		return enumIdentifier;
	}

	/*
	* This function generates code for the whole machine with the given AST node.
	*/
	public String generateMachine(MachineNode node, GeneratorMode mode) {
		machinePreprocessor.visitMachineNode(node);
		MachineConstantsOptimizer machineConstantsOptimizer = new MachineConstantsOptimizer(node, forModelChecking, forVisualisation);
		machineConstantsOptimizer.visitMachineNode();
		if(node.getValues() != null && !node.getValues().isEmpty()) {
			throw new CodeGenerationException("VALUES clause is not supported.");
		}
		initialize(node);
		recordStructAnalyzer.visitMachineNode(node);
		deferredSetAnalyzer.analyze(node.getDeferredSets(), node.getProperties());
		backtrackingGenerator.calculateChoicePoints(node);

		ST machine = currentGroup.getInstanceOf("machine");
		TemplateHandler.add(machine, "forModelChecking", (forModelChecking || forVisualisation) && !isIncludedMachine);
		TemplateHandler.add(machine, "forVisualisation", forVisualisation);
		TemplateHandler.add(machine, "useBigInteger", useBigInteger);
		TemplateHandler.add(machine, "addition", addition);
		TemplateHandler.add(machine, "imports", importGenerator.getImports());
		TemplateHandler.add(machine, "methods", generateMethods(node));
		TemplateHandler.add(machine, "includedMachines", importGenerator.generateMachineImports(node));
		TemplateHandler.add(machine, "machine", nameHandler.handle(node.getName()));
		if (mode == GeneratorMode.PL) {
			TemplateHandler.add(machine, "props", modelCheckingGenerator.generateModelCheckingProBProp(node));
		}
		TemplateHandler.add(machine, "machineString", modelCheckingGenerator.generateToString());
		TemplateHandler.add(machine, "externalFunctions", machineNode.getOperations()
				.stream()
				.filter(op -> op.getName().startsWith("EXTERNAL_"))
				.map(op -> generateExternalFunction(operationGenerator.generateReturnType(op), op.getName(), op.getParams()
						.stream()
						.map(parameter -> declarationGenerator.generateParameter(parameter, false))
						.collect(Collectors.toList())))
				.collect(Collectors.toList()));
		generateBody(node, machine);
		return machine.render();
	}

	/*
	* This function initializes needed semantic information during code generation.
	*/
	private void initialize(MachineNode node) {
		this.machineNode = node;
		this.constants = node.getConstants()
				.stream()
				.map(DeclarationNode::getName)
				.collect(Collectors.toList());
		nameHandler.initialize(node);
		operationGenerator.mapOperationsToMachine(node);
		initializeLambdaFunctions();
		inspectInfiniteSets();
		if((forModelChecking || forVisualisation) && !isIncludedMachine) {
			importGenerator.addImport(new CoupleType(new UntypedType(), new UntypedType()));
		}
		modelCheckingGenerator.setModelCheckingInfo(modelCheckingInfoGenerator.generateModelCheckingInfo(node));
	}

	private void initializeLambdaFunctions() {
		lambdaFunctionGenerator.computeConstantsOnlyUsedInFunctionCall(machineNode);
		lambdaFunctions.addAll(lambdaFunctionGenerator.getLambdaFunctions(machineNode));
		for(MachineReferenceNode reference : machineNode.getMachineReferences()) {
			MachineNode machine = reference.getMachineNode();
			lambdaFunctions.addAll(lambdaFunctionGenerator.getLambdaFunctions(machine));
		}
	}

	private void inspectInfiniteSets() {
		infiniteSets.addAll(infiniteSetGenerator.getInfiniteSets(machineNode));
		for(MachineReferenceNode reference : machineNode.getMachineReferences()) {
			MachineNode machine = reference.getMachineNode();
			infiniteSets.addAll(infiniteSetGenerator.getInfiniteSets(machine));
		}
	}

	/*
	* This function generates the whole body of a machine from the given AST node for the machine.
	*/
	private void generateBody(MachineNode node, ST machine) {
		Set<String> identifier = new HashSet<>();
		TemplateHandler.add(machine, "constants_declarations", declarationGenerator.generateConstantsDeclarations(node));
		TemplateHandler.add(machine, "enums", declarationGenerator.generateEnumDeclarations(node, identifier));
		TemplateHandler.add(machine, "projectionClasses", generateProjectionClasses());
		enumIdentifier.addAll(identifier);
		TemplateHandler.add(machine, "enum_imports", importGenerator.getImportedEnums());
		TemplateHandler.add(machine, "sets", declarationGenerator.generateSetDeclarations(node));
		TemplateHandler.add(machine, "declarations", declarationGenerator.visitDeclarations(node.getVariables()));
		TemplateHandler.add(machine, "includes", declarationGenerator.generateIncludes(node));
		TemplateHandler.add(machine, "initialization", substitutionGenerator.visitInitialization(node));
		TemplateHandler.add(machine, "mainMethod", modelCheckingGenerator.generateMainMethod(node));
		TemplateHandler.add(machine, "copyConstructor", this.generateCopyConstructor(node));
		TemplateHandler.add(machine, "operations", operationGenerator.visitOperations(node.getOperations(), node.getVariables().stream()
				.map(DeclarationNode::getName)
				.collect(Collectors.toList())));
		List<DeclarationNode> declarationNodesForGetter = new ArrayList<>();
		declarationNodesForGetter.addAll(node.getConstants());
		declarationNodesForGetter.addAll(node.getVariables());
		node.getEnumeratedSets().forEach(enumeratedSet -> {
			declarationNodesForGetter.add(enumeratedSet.getSetDeclarationNode());
		});
		List<MachineNode> machineNodesForGetter = node.getMachineReferences()
				.stream()
				.map(MachineReferenceNode::getMachineNode).collect(Collectors.toList());
		TemplateHandler.add(machine, "getters", generateGetters(declarationNodesForGetter, machineNodesForGetter));
		TemplateHandler.add(machine, "transitions", generateTransitions(node.getOperations()));
		TemplateHandler.add(machine, "projection", modelCheckingGenerator.generateProjection());
		TemplateHandler.add(machine, "transitionCachesDeclaration", transitionGenerator.generateTransitionCaches(node.getOperations()));
		TemplateHandler.add(machine, "invariant", generateInvariants(node.getInvariant()));
		TemplateHandler.add(machine, "copy", this.generateCopy(node));
		TemplateHandler.add(machine, "hash_equal", modelCheckingGenerator.generateHashEqualToString());
		TemplateHandler.add(machine, "modelcheck", modelCheckingGenerator.generate(node, forModelChecking, isIncludedMachine, forVisualisation));
		TemplateHandler.add(machine, "choicePoints", backtrackingGenerator.getChoicePointDeclarations());
		TemplateHandler.add(machine, "choicePointsGetters", backtrackingGenerator.getChoicePointGetters());
		TemplateHandler.add(machine, "choicePointOperationFlags", backtrackingGenerator.getChoicePointOperationFlagDeclarations());
		TemplateHandler.add(machine, "choicePointOperationFlagGetters", backtrackingGenerator.getChoicePointOperationFlagGetters());
		TemplateHandler.add(machine, "choicePointOperationFlagResets", backtrackingGenerator.getChoicePointOperationFlagResets());
		TemplateHandler.add(machine, "choicePointOperationApplies", backtrackingGenerator.getChoicePointOperationApplies());
		TemplateHandler.add(machine, "choicePointOperationTriggeredFlags", backtrackingGenerator.getChoicePointOperationTriggeredFlags());
		TemplateHandler.add(machine, "choicePointOperationTriggered", backtrackingGenerator.getChoicePointOperationTriggered());
		TemplateHandler.add(machine, "choicePointOperationTriggeredResets", backtrackingGenerator.getChoicePointOperationTriggeredResets());
		TemplateHandler.add(machine, "lambdaFunctions", lambdaFunctionGenerator.generateFunctions(node));
		TemplateHandler.add(machine, "structs", recordStructGenerator.generateStructs());
	}

	private String generateExternalFunction(String type, String name, List<String> parameters) {
		ST template = currentGroup.getInstanceOf("external_function");
		TemplateHandler.add(template, "type", type);
		TemplateHandler.add(template, "name", name);
		TemplateHandler.add(template, "parameters", parameters);
		return template.render();
	}

	private List<String> generateProjectionClasses() {
		List<String> projectionClasses = new ArrayList<>();
		for(OperationNode operation : machineNode.getOperations()) {
			projectionClasses.add(modelCheckingGenerator.generateClassesForOpReuse(machineNode, true, false, false, operation.getName()));
			projectionClasses.add(modelCheckingGenerator.generateClassesForOpReuse(machineNode, true, true, false, operation.getName()));
			projectionClasses.add(modelCheckingGenerator.generateClassesForOpReuse(machineNode, false, false, false, operation.getName()));
		}
		for(String invariant : modelCheckingGenerator.getModelCheckingInfo().getInvariantFunctions()) {
			projectionClasses.add(modelCheckingGenerator.generateClassesForOpReuse(machineNode, true, false, true, invariant));
		}
		return projectionClasses;
	}

	public List<String> generateTransitions(List<OperationNode> operations) {
		return transitionGenerator.generateTransitions(operations);
	}

	public List<String> generateInvariants(PredicateNode invariantNode) {
		return invariantGenerator.generateInvariants(invariantNode);
	}

	/*
	* This function generates code for all getters for variables if the machine is an included machine
	*/
	private List<String> generateGetters(List<DeclarationNode> variables, List<MachineNode> includedMachines) {
		Set<String> lambdaFunctions = getLambdaFunctions();
		Set<String> infiniteSets = getInfiniteSets();
		List<String> getters = new ArrayList<>();
		getters.addAll(variables.stream()
				.filter(variable -> !lambdaFunctions.contains(variable.getName()))
				.filter(variable -> !infiniteSets.contains(variable.getName()))
				.map(this::generateGetter)
				.collect(Collectors.toList()));
		getters.addAll(includedMachines.stream()
				.map(this::generateGetter)
				.collect(Collectors.toList()));
		return getters;
	}

	/*
	* This function generates code for the given variable if the machine is an included machine
	*/
	private String generateGetter(DeclarationNode variable) {
		ST getter = currentGroup.getInstanceOf("getter");
		TemplateHandler.add(getter, "variable", (variable.getKind().equals(DeclarationNode.Kind.ENUMERATED_SET) ? "_": "") + nameHandler.handleIdentifier(variable.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
		TemplateHandler.add(getter, "isConstant", DeclarationNode.Kind.CONSTANT.equals(variable.getKind()) || DeclarationNode.Kind.ENUMERATED_SET.equals(variable.getKind()));
		TemplateHandler.add(getter, "machine", nameHandler.handle(variable.getSurroundingMachineNode().getName()));
		TemplateHandler.add(getter, "returnType", typeGenerator.generate(variable.getType()));
		TemplateHandler.add(getter, "machineName", nameHandler.handle(machineNode.getName()));
		return getter.render();
	}

	private String generateGetter(MachineNode includedMachine) {
		ST getter = currentGroup.getInstanceOf("getter");
		TemplateHandler.add(getter, "variable", nameHandler.handleIdentifier(includedMachine.getName(), NameHandler.IdentifierHandlingEnum.MACHINES));
		TemplateHandler.add(getter, "isConstant", false);
		TemplateHandler.add(getter, "machine", nameHandler.handle(includedMachine.getName()));
		TemplateHandler.add(getter, "returnType", nameHandler.handle(includedMachine.getName()));
		TemplateHandler.add(getter, "machineName", nameHandler.handle(machineNode.getName()));
		return getter.render();
	}

	private String generateCopyConstructor(MachineNode node) {
		ST template = currentGroup.getInstanceOf("copy_constructor");
		TemplateHandler.add(template, "machine", nameHandler.handle(node.getName()));
		List<DeclarationNode> parameters = new ArrayList<>(node.getConstants());
		parameters.addAll(node.getVariables());

		List<String> assignments = new ArrayList<>();
		assignments.addAll(parameters.stream()
				.map(this::generateCopyAssignment)
				.collect(Collectors.toList()));
		assignments.addAll(node.getMachineReferences().stream()
				.map(this::generateCopyMachine)
				.collect(Collectors.toList()));

		TemplateHandler.add(template, "parameters", declarationGenerator.generateDeclarations(parameters, OperationGenerator.DeclarationType.PARAMETER, false));
		TemplateHandler.add(template, "assignments", assignments);
		TemplateHandler.add(template, "hasExternals", node.getOperations().stream().anyMatch(op -> op.getName().startsWith("EXTERNAL_")));

		return template.render();

	}

	public String generateCopyAssignment(DeclarationNode declaration) {
		ST template = currentGroup.getInstanceOf("copy_assignment");
		TemplateHandler.add(template, "variable", nameHandler.handleIdentifier(declaration.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
		return template.render();
	}

	public String generateCopyIncludedMachine(MachineReferenceNode machineReferenceNode) {
		ST template = currentGroup.getInstanceOf("copy_included_machine");
		TemplateHandler.add(template, "machine", nameHandler.handle(machineReferenceNode.getMachineName()));
		TemplateHandler.add(template, "variable", nameHandler.handleIdentifier(machineReferenceNode.getMachineName(), NameHandler.IdentifierHandlingEnum.MACHINES));
		return template.render();
	}

	public String generateCopyMachine(MachineReferenceNode node) {
		ST template = currentGroup.getInstanceOf("copy_machine");
		TemplateHandler.add(template, "machine", nameHandler.handleIdentifier(node.getMachineName(), NameHandler.IdentifierHandlingEnum.MACHINES));
		return template.render();
	}

	private String generateCopy(MachineNode node) {
		ST template = currentGroup.getInstanceOf("copy");
		List<DeclarationNode> parameters = new ArrayList<>(node.getConstants());
		parameters.addAll(node.getVariables());
		TemplateHandler.add(template, "machine", nameHandler.handle(node.getName()));
		TemplateHandler.add(template, "parameters", parameters.stream()
				.map(variable -> nameHandler.handleIdentifier(variable.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
				.collect(Collectors.toList()));
		TemplateHandler.add(template, "operations", node.getOperations().stream()
				.map(op -> nameHandler.handleIdentifier(op.getName(), NameHandler.IdentifierHandlingEnum.INCLUDED_MACHINES))
				.collect(Collectors.toList()));
		return template.render();
	}

	/*
	* This function generates code for functions for programming languages where functions must be declared before implementation from the given AST node for the machine.
	*/
	private List<String> generateMethods(MachineNode node) {
		ST method = currentGroup.getInstanceOf("method");
		TemplateHandler.add(method, "operationName", "initialize");
		TemplateHandler.add(method, "argsTypes", "");
		TemplateHandler.add(method, "returnType", typeGenerator.generate(new UntypedType()));
		List<String> result = new ArrayList<>();
		result.add(method.render());
		result.addAll(node.getOperations().stream()
			.map(this::generateMethod)
			.collect(Collectors.toList()));
		return result;
	}

	/*
	* This function generates code for a function for programming languages where functions must be declared before implementation from the given AST node for the machine.
	*/
	private String generateMethod(OperationNode node) {
		ST method = currentGroup.getInstanceOf("method");
		TemplateHandler.add(method, "operationName", nameHandler.handle(node.getName()));
		TemplateHandler.add(method, "argsTypes", node.getParams().stream()
				.map(param -> typeGenerator.generate(param.getType()))
				.collect(Collectors.toList()));
		//TODO: generate method for many return parameters (Clojure issue)
		if(node.getOutputParams().size() > 0) {
			TemplateHandler.add(method, "returnType", typeGenerator.generate(node.getOutputParams().get(0).getType()));
		} else {
			TemplateHandler.add(method, "returnType", typeGenerator.generate(new UntypedType()));
		}
		return method.render();
	}

	@Override
	public String visitExprNode(ExprNode node, Void expected) {
		return expressionGenerator.visitExprNode(node);
	}

	@Override
	public String visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
		return expressionGenerator.visitExprOperatorNode(node);
	}

	@Override
	public String visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
		return expressionGenerator.visitIdentifierExprNode(node);
	}

	@Override
	public String visitCastPredicateExpressionNode(CastPredicateExpressionNode node, Void expected) {
		return expressionGenerator.visitCastPredicateExpressionNode(node);
	}

	@Override
	public String visitNumberNode(NumberNode node, Void expected) {
		return expressionGenerator.visitNumberNode(node);
	}

	@Override
	public String visitRealNumberNode(RealNumberNode node, Void expected) {
		// TODO
		return null;
	}

	@Override
	public String visitStringNode(StringNode node, Void expected) {
		return expressionGenerator.visitStringNode(node);
	}

	@Override
	public String visitQuantifiedExpressionNode(QuantifiedExpressionNode node, Void expected) {
		return expressionGenerator.visitQuantifiedExpressionNode(node);
	}

	/*
	*
	*/
	@Override
	public String visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void expected) {
		return predicateGenerator.generateQuantifiedPredicateNode(node);
	}

	/*
	*
	*/
	@Override
	public String visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
		return expressionGenerator.visitSetComprehensionNode(node);
	}

	@Override
	public String visitLambdaNode(LambdaNode node, Void expected) {
		return expressionGenerator.visitLambdaNode(node);
	}

	/*
    * Code is not generated from identifier predicates in the given subset of B
    */
	@Override
	public String visitIdentifierPredicateNode(IdentifierPredicateNode node, Void expected) {
		throw new RuntimeException("Given node is not implemented: " + node.getClass());
	}

	/*
	* This function generates code for a predicate with the belonging AST node
	*/
	@Override
	public String visitPredicateOperatorNode(PredicateOperatorNode node, Void expected) {
		return predicateGenerator.visitPredicateOperatorNode(node);
	}

	/*
	* This function generates code for a predicate with expression as arguments with the belonging AST node
	*/
	@Override
	public String visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
		return predicateGenerator.visitPredicateOperatorWithExprArgs(node);
	}


	@Override
	public String visitIfOrSelectSubstitutionsNode(IfOrSelectSubstitutionsNode node, Void expected) {
		return substitutionGenerator.visitIfOrSelectSubstitutionsNode(node);
	}

	@Override
	public String visitIfExpressionNode(IfExpressionNode node, Void expected) {
		return expressionGenerator.visitIfExpressionNode(node);
	}

	@Override
	public String visitIfPredicateNode(IfPredicateNode node, Void expected) {
		return predicateGenerator.visitIfPredicateNode(node);
	}

	@Override
	public String visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
		return substitutionGenerator.visitChoiceSubstitutionNode(node, expected);
	}

	/*
  * This function generates code for empty functions
  * Most times this is the empty String
  */
	@Override
	public String visitSkipSubstitutionNode(SkipSubstitutionNode node, Void expected) {
		ST skip = currentGroup.getInstanceOf("skip");
		return skip.render();
	}

	@Override
	public String visitConditionSubstitutionNode(ConditionSubstitutionNode node, Void expected) {
		return substitutionGenerator.visitConditionSubstitutionNode(node);
	}

	@Override
	public String visitAnySubstitution(AnySubstitutionNode node, Void expected) {
		return substitutionGenerator.visitAnySubstitutionNode(node);
	}

	@Override
	public String visitLetSubstitution(LetSubstitutionNode node, Void expected) {
		return substitutionGenerator.visitAnySubstitutionNode(new AnySubstitutionNode(node.getSourceCodePosition(), node.getLocalIdentifiers(), node.getPredicate(), node.getBody()));
	}

	@Override
	public String visitLetExpressionNode(LetExpressionNode node, Void aVoid) {
		return expressionGenerator.visitLetExpressionNode(node);
	}

	@Override
	public String visitLetPredicateNode(LetPredicateNode node, Void expected) {
		return predicateGenerator.visitLetPredicateNode(node);
	}

	@Override
	public String visitAssignSubstitutionNode(AssignSubstitutionNode node, Void expected) {
		return substitutionGenerator.visitAssignSubstitutionNode(node);
	}

	@Override
	public String visitListSubstitutionNode(ListSubstitutionNode node, Void expected) {
		return substitutionGenerator.visitListSubstitutionNode(node);
	}

	@Override
	public String visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void expected) {
		return substitutionGenerator.visitBecomesElementOfSubstitutionNode(node);
	}

	@Override
	public String visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void expected) {
		return substitutionGenerator.visitBecomesSuchThatSubstitutionNode(node);
	}

	/*
	* Generating code for LTL formulae results in an empty string as it is proven.
	*/
	@Override
	public String visitLTLPrefixOperatorNode(LTLPrefixOperatorNode node, Void expected) {
		return "";
	}

	/*
	* Generating code for LTL formulae results in an empty string as it is proven.
	*/
	@Override
	public String visitLTLKeywordNode(LTLKeywordNode node, Void expected) {
		return "";
	}

	/*
	* Generating code for LTL formulae results in an empty string as it is proven.
	*/
	@Override
	public String visitLTLInfixOperatorNode(LTLInfixOperatorNode node, Void expected) {
		return "";
	}

	/*
	* Generating code for LTL formulae results in an empty string as it is proven.
	*/
	@Override
	public String visitLTLBPredicateNode(LTLBPredicateNode node, Void expected) {
		return "";
	}

	@Override
	public String visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
		return substitutionGenerator.visitSubstitutionIdentifierCallNode(node, expected);
	}

	@Override
	public String visitWhileSubstitutionNode(WhileSubstitutionNode node, Void expected) {
		return substitutionGenerator.visitWhileSubstitutionNode(node, expected);
	}

	@Override
	public String visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
		return substitutionGenerator.visitVarSubstitutionNode(node, expected);
	}

	@Override
	public String visitRecordNode(RecordNode node, Void expected) {
		return expressionGenerator.visitExprNode(node);
	}

	@Override
	public String visitStructNode(StructNode node, Void expected) {
		return "";
	}

	@Override
	public String visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
		return expressionGenerator.visitExprNode(node);
	}

	public String visitEnumIdentifier(Node node) {
		return expressionGenerator.visitEnumIdentifier(node);
	}

	public NameHandler getNameHandler() {
		return nameHandler;
	}

	public DeclarationGenerator getDeclarationGenerator() {
		return declarationGenerator;
	}

	public RecordStructGenerator getRecordStructGenerator() {
		return recordStructGenerator;
	}

	public String getMachineName() {
		return machineNode.getName();
	}

	/*
	* This function must be invoked when the next level for an iteration construct is entered
	*/
	public void inIterationConstruct(List<DeclarationNode> boundedVariables) {
		for(DeclarationNode variable : boundedVariables) {
			String name = variable.getName();
			if(boundedVariablesDepth.containsKey(name)) {
				int depth = boundedVariablesDepth.get(name);
				boundedVariablesDepth.put(name, depth + 1);
			} else {
				boundedVariablesDepth.put(name, 1);
			}
		}
		iterationConstructDepth++;
	}

	public void inIterationConstruct() {
		iterationConstructDepth++;
	}

	/*
	* This function must be invoked when the current level for an iteration construct is left.
	*/
	public void leaveIterationConstruct(List<DeclarationNode> boundedVariables) {
		for(DeclarationNode variable : boundedVariables) {
			String name = variable.getName();
			int depth = boundedVariablesDepth.get(name);
			if(depth == 1) {
				boundedVariablesDepth.remove(name);
			} else {
				boundedVariablesDepth.put(name, depth - 1);
			}
		}
		iterationConstructDepth--;
	}

	public void leaveIterationConstruct() {
		iterationConstructDepth--;
	}

	public Map<String, Integer> getBoundedVariablesDepth() {
		return boundedVariablesDepth;
	}

	/*
	* This function checks whether the current visited construct is within an iteration construct
	*/
	public boolean isInIterationConstruct() {
		return iterationConstructDepth > 0;
	}


	public void resetIterationConstruct() {
		iterationConstructDepth = 0;
		this.boundedVariablesDepth.clear();
	}

	public int getIterationConstructDepth() {
		return iterationConstructDepth;
	}

	public void setIterationConstructDepth(int iterationConstructDepth) {
		this.iterationConstructDepth = iterationConstructDepth;
	}

	public MachineNode getMachineNode() {
		return machineNode;
	}

	public Set<String> getLambdaFunctions() {
		return lambdaFunctions;
	}

	public Set<String> getInfiniteSets() {
		return infiniteSets;
	}

	public ModelCheckingInfo generateModelCheckingInfo(MachineNode node) {
		return modelCheckingInfoGenerator.generateModelCheckingInfo(node);
	}

	public ImportGenerator getImportGenerator() {
		return importGenerator;
	}

	public ExpressionGenerator getExpressionGenerator() {
		return expressionGenerator;
	}

	public IterationConstructHandler getIterationConstructHandler() {
		return iterationConstructHandler;
	}

	public boolean isForModelChecking() {
		return forModelChecking;
	}

	public boolean isForVisualisation() {
		return forVisualisation;
	}

	public boolean isIncludedMachine() {
		return isIncludedMachine;
	}

	public InvariantGenerator getInvariantGenerator() {
		return invariantGenerator;
	}

	public GeneratorMode getMode() {
		return mode;
	}

	public void setMode(GeneratorMode mode) {
		this.mode = mode;
	}

	public String getServerLink() {
		return serverLink;
	}

}
