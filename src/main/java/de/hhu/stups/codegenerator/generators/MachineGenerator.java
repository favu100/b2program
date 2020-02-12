package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.CodeGeneratorUtils;
import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.analyzers.DeferredSetAnalyzer;
import de.hhu.stups.codegenerator.analyzers.RecordStructAnalyzer;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.ParallelConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.expression.IfExpressionNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.expression.LetExpressionNode;
import de.prob.parser.ast.nodes.expression.NumberNode;
import de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode;
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
import de.prob.parser.ast.types.UntypedType;
import de.prob.parser.ast.visitors.AbstractVisitor;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/*
* The code generator is implemented by using the visitor pattern
*/

public class MachineGenerator implements AbstractVisitor<String, Void> {

	private final TypeGenerator typeGenerator;

	private final ImportGenerator importGenerator;

	private final IterationConstructHandler iterationConstructHandler;

	private final OperatorGenerator operatorGenerator;

	private final OperationGenerator operationGenerator;

	private DeclarationGenerator declarationGenerator;

	private final ExpressionGenerator expressionGenerator;

	private final PredicateGenerator predicateGenerator;

	private final SubstitutionGenerator substitutionGenerator;

	private final IdentifierGenerator identifierGenerator;

	private NameHandler nameHandler;

	private final ParallelConstructHandler parallelConstructHandler;

	private final RecordStructAnalyzer recordStructAnalyzer;

	private final RecordStructGenerator recordStructGenerator;

	private final DeferredSetAnalyzer deferredSetAnalyzer;

	private final boolean useBigInteger;

	private final Map<String, Integer> boundedVariablesDepth;

	private STGroup currentGroup;

	private MachineNode machineNode;

	private String addition;

	private int iterationConstructDepth;

	private boolean isIncludedMachine;

	public MachineGenerator(GeneratorMode mode, boolean useBigInteger, String minint, String maxint, String deferredSetSize, Path addition, boolean isIncludedMachine) {
		this.currentGroup = CodeGeneratorUtils.getGroup(mode);
		this.useBigInteger = useBigInteger;
		this.boundedVariablesDepth = new HashMap<>();
		if(addition != null) {
			try {
				this.addition = new String(Files.readAllBytes(addition));
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		this.nameHandler = new NameHandler(this, currentGroup);
		this.parallelConstructHandler = new ParallelConstructHandler();
		this.typeGenerator = new TypeGenerator(currentGroup, nameHandler, this);
		this.importGenerator = new ImportGenerator(currentGroup, nameHandler, useBigInteger);
		this.iterationConstructHandler = new IterationConstructHandler(currentGroup, this, nameHandler, typeGenerator, importGenerator);
		this.deferredSetAnalyzer = new DeferredSetAnalyzer(Integer.parseInt(deferredSetSize));
		this.declarationGenerator = new DeclarationGenerator(currentGroup, this, typeGenerator, importGenerator, nameHandler, deferredSetAnalyzer);
        this.identifierGenerator = new IdentifierGenerator(currentGroup, this, nameHandler, parallelConstructHandler, declarationGenerator);
		this.predicateGenerator = new PredicateGenerator(currentGroup, this, nameHandler, importGenerator, iterationConstructHandler);
		this.recordStructGenerator = new RecordStructGenerator(currentGroup, this, typeGenerator, importGenerator, nameHandler);
		this.recordStructAnalyzer = new RecordStructAnalyzer(recordStructGenerator);
		this.expressionGenerator = new ExpressionGenerator(currentGroup, this, useBigInteger, minint, maxint, nameHandler, importGenerator,
															declarationGenerator, identifierGenerator, typeGenerator, iterationConstructHandler, recordStructGenerator);
		this.substitutionGenerator = new SubstitutionGenerator(currentGroup, this, nameHandler, typeGenerator,
																expressionGenerator, identifierGenerator, iterationConstructHandler,
																parallelConstructHandler, recordStructGenerator, declarationGenerator);
		this.operatorGenerator = new OperatorGenerator(predicateGenerator, expressionGenerator);
		this.operationGenerator = new OperationGenerator(currentGroup, this, substitutionGenerator, declarationGenerator, identifierGenerator, nameHandler,
															typeGenerator, recordStructGenerator);
		this.iterationConstructDepth = 0;
		this.isIncludedMachine = isIncludedMachine;
	}

	/*
	* This function generates code for the whole machine with the given AST node.
	*/
	public String generateMachine(MachineNode node) {
		recordStructAnalyzer.visitMachineNode(node);
		deferredSetAnalyzer.analyze(node.getDeferredSets(), node.getProperties());
		initialize(node);
		ST machine = currentGroup.getInstanceOf("machine");
		TemplateHandler.add(machine, "useBigInteger", useBigInteger);
		TemplateHandler.add(machine, "addition", addition);
		TemplateHandler.add(machine, "imports", importGenerator.getImports());
		TemplateHandler.add(machine, "methods", generateMethods(node));
		TemplateHandler.add(machine, "includedMachines", importGenerator.generateMachineImports(node));
		TemplateHandler.add(machine, "machine", nameHandler.handle(node.getName()));
		generateBody(node, machine);
		return machine.render();
	}

	/*
	* This function initializes needed semantic information during code generation.
	*/
	private void initialize(MachineNode node) {
		this.machineNode = node;
		nameHandler.initialize(node);
		operationGenerator.mapOperationsToMachine(node);
	}

	/*
	* This function generates the whole body of a machine from the given AST node for the machine.
	*/
	private void generateBody(MachineNode node, ST machine) {
		TemplateHandler.add(machine, "constants_declarations", declarationGenerator.generateConstantsDeclarations(node));
		TemplateHandler.add(machine, "enums", declarationGenerator.generateEnumDeclarations(node));
		TemplateHandler.add(machine, "sets", declarationGenerator.generateSetDeclarations(node));
		TemplateHandler.add(machine, "declarations", declarationGenerator.visitDeclarations(node.getVariables()));
		TemplateHandler.add(machine, "includes", declarationGenerator.generateIncludes(node));
		TemplateHandler.add(machine, "initialization", substitutionGenerator.visitInitialization(node));
		TemplateHandler.add(machine, "operations", operationGenerator.visitOperations(node.getOperations(), node.getVariables().stream().map(DeclarationNode::getName).collect(Collectors.toList())));
		TemplateHandler.add(machine, "getters", isIncludedMachine ? generateGetters(node.getVariables()) : new ArrayList<>());
		TemplateHandler.add(machine, "structs", recordStructGenerator.generateStructs());
	}

	/*
	* This function generates code for all getters for variables if the machine is an included machine
	*/
	private List<String> generateGetters(List<DeclarationNode> variables) {
		return variables.stream()
				.map(this::generateGetter)
				.collect(Collectors.toList());
	}

	/*
	* This function generates code for the given variable if the machine is an included machine
	*/
	private String generateGetter(DeclarationNode variable) {
		ST getter = currentGroup.getInstanceOf("getter");
		TemplateHandler.add(getter, "variable", nameHandler.handleIdentifier(variable.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
		TemplateHandler.add(getter, "returnType", typeGenerator.generate(variable.getType()));
		return getter.render();
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
    * Generating code from the skip substitution results in an empty string.
    */
	@Override
	public String visitSkipSubstitutionNode(SkipSubstitutionNode node, Void expected) {
		return "";
	}

	@Override
	public String visitConditionSubstitutionNode(ConditionSubstitutionNode node, Void expected) {
		return visitSubstitutionNode(node.getSubstitution(), expected);
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
}
