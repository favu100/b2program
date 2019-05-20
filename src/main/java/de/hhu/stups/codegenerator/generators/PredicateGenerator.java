package de.hhu.stups.codegenerator.generators;


import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.predicate.IfPredicateNode;
import de.prob.parser.ast.nodes.predicate.LetPredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import de.prob.parser.ast.nodes.predicate.QuantifiedPredicateNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class PredicateGenerator {

    /*
    * Hard-coded lists for identifying the type of the operators for predicates
    */

    private static final List<PredicateOperatorNode.PredicateOperator> BINARY_PREDICATE_OPERATORS =
            Arrays.asList(PredicateOperatorNode.PredicateOperator.AND, PredicateOperatorNode.PredicateOperator.OR,
                    PredicateOperatorNode.PredicateOperator.IMPLIES, PredicateOperatorNode.PredicateOperator.EQUIVALENCE);

    private static final List<PredicateOperatorNode.PredicateOperator> UNARY_PREDICATE_OPERATORS =
            Collections.singletonList(PredicateOperatorNode.PredicateOperator.NOT);

    private static final List<PredicateOperatorNode.PredicateOperator> PREDICATE_BOOLEANS =
            Arrays.asList(PredicateOperatorNode.PredicateOperator.TRUE, PredicateOperatorNode.PredicateOperator.FALSE);

    private static final List<PredicateOperatorWithExprArgsNode.PredOperatorExprArgs> INFINITE_PREDICATE_OPERATORS =
            Arrays.asList(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.INCLUSION,
                    PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.STRICT_INCLUSION, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NON_INCLUSION, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.STRICT_NON_INCLUSION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> INFINITE_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.INTEGER, ExpressionOperatorNode.ExpressionOperator.NATURAL, ExpressionOperatorNode.ExpressionOperator.NATURAL1);

    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final NameHandler nameHandler;

    private final ImportGenerator importGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private OperatorGenerator operatorGenerator;

    public PredicateGenerator(final STGroup currentGroup, final MachineGenerator machineGenerator, final NameHandler nameHandler,
                              final ImportGenerator importGenerator, final IterationConstructHandler iterationConstructHandler) {
        this.currentGroup = currentGroup;
        this.machineGenerator = machineGenerator;
        this.nameHandler = nameHandler;
        this.importGenerator = importGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
    }

    /*
    * This function generates code for a predicate with the belonging AST node
    */
    public String visitPredicateOperatorNode(PredicateOperatorNode node) {
        importGenerator.addImport(node.getType());
        List<String> expressionList = node.getPredicateArguments().stream()
                .map(expr -> machineGenerator.visitPredicateNode(expr, null))
                .collect(Collectors.toList());
        return generatePredicate(node, expressionList);
    }

    /*
    * This function generates code for a predicate with expression as arguments with the belonging AST node
    */
    public String visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node) {
        importGenerator.addImport(node.getType());
        if(checkInfinite(node)) {
            return generateInfinite(node);
        }
        List<String> expressionList = node.getExpressionNodes().stream()
                .map(expr -> machineGenerator.visitExprNode(expr, null))
                .collect(Collectors.toList());
        return operatorGenerator.generateBinary(node::getOperator, expressionList);
    }

    private boolean checkInfinite(PredicateOperatorWithExprArgsNode node) {
        List<ExprNode> expressions = node.getExpressionNodes();
        PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = node.getOperator();
        if(expressions.size() == 2 && INFINITE_PREDICATE_OPERATORS.contains(operator)) {
            ExprNode rhs = node.getExpressionNodes().get(1);
            if(rhs instanceof ExpressionOperatorNode && INFINITE_EXPRESSIONS.contains(((ExpressionOperatorNode) rhs).getOperator())) {
                return true;
            }
        }
        return false;
    }

    /*
    * This function generates code for a predicate with the given AST node and the list of expresions within the predicate.
    */
    public String generatePredicate(PredicateOperatorNode node, List<String> expressionList) {
        PredicateOperatorNode.PredicateOperator operator = node.getOperator();
        if(BINARY_PREDICATE_OPERATORS.contains(operator)) {
            return operatorGenerator.generateBinary(() -> operator, expressionList);
        } else if(UNARY_PREDICATE_OPERATORS.contains(operator)) {
            return generateUnaryPredicate(operator, expressionList);
        } else if (PREDICATE_BOOLEANS.contains(operator)) {
            return generateBoolean(operator);
        }
        throw new RuntimeException("Given operator is not implemented: " + node.getOperator());
    }

    public String generateQuantifiedPredicateNode(QuantifiedPredicateNode node) {
        return iterationConstructHandler.getIterationsMapIdentifier().get(node.toString());
    }

    /*
    * This function generates code for an unary predicate with the given operator and arguments.
    */
    private String generateUnaryPredicate(PredicateOperatorNode.PredicateOperator operator, List<String> expressionList) {
        ST expression = generateUnary(operator);
        TemplateHandler.add(expression, "obj", expressionList.get(0));
        TemplateHandler.add(expression, "args", expressionList.subList(1, expressionList.size()));
        return expression.render();
    }

    /*
    * This functions gets the template for unary predicates and replaces the placeholder with the given operator.
    */
    private ST generateUnary(PredicateOperatorNode.PredicateOperator operator) {
        ST template = currentGroup.getInstanceOf("unary");
        String operatorName;
        switch(operator) {
            case NOT:
                operatorName = "not";
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        TemplateHandler.add(template, "operator", nameHandler.handle(operatorName));
        return template;
    }

    /*
    * This functions gets the template for binary predicates and replaces the placeholder with the given operator.
    */
    public ST generateBinary(PredicateOperatorNode.PredicateOperator operator) {
        ST template = currentGroup.getInstanceOf("binary");
        String operatorName;
        switch(operator) {
            case AND:
                operatorName = "and";
                break;
            case OR:
                operatorName = "or";
                break;
            case IMPLIES:
                operatorName = "implies";
                break;
            case EQUIVALENCE:
                operatorName = "equivalent";
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        TemplateHandler.add(template, "operator", nameHandler.handle(operatorName));
        return template;
    }

    /*
    * This functions gets the template for binary predicates with expression arguments and replaces the placeholder with the given operator.
    */
    public ST generateBinary(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator) {
        ST template = currentGroup.getInstanceOf("binary");
        String operatorName;
        switch(operator) {
            case ELEMENT_OF:
                operatorName = "elementOf";
                break;
            case NOT_BELONGING:
                operatorName = "notElementOf";
                break;
            case INCLUSION:
                operatorName = "subset";
                break;
            case NON_INCLUSION:
                operatorName = "notSubset";
                break;
            case STRICT_INCLUSION:
                operatorName = "strictSubset";
                break;
            case STRICT_NON_INCLUSION:
                operatorName = "strictNotSubset";
                break;
            case EQUAL:
                operatorName = "equal";
                break;
            case NOT_EQUAL:
                operatorName = "unequal";
                break;
            case LESS:
                operatorName = "less";
                break;
            case LESS_EQUAL:
                operatorName = "lessEqual";
                break;
            case GREATER:
                operatorName = "greater";
                break;
            case GREATER_EQUAL:
                operatorName = "greaterEqual";
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        TemplateHandler.add(template, "operator", nameHandler.handle(operatorName));
        return template;
    }

    private String generateInfiniteInteger(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator) {
        String operatorName;
        switch (operator) {
            case ELEMENT_OF:
                operatorName = "isInteger";
                break;
            case NOT_BELONGING:
                operatorName = "isNotInteger";
                break;
            case INCLUSION:
                operatorName = "subsetOfInteger";
                break;
            case NON_INCLUSION:
                operatorName = "notSubsetOfInteger";
                break;
            case STRICT_INCLUSION:
                operatorName = "strictSubsetOfInteger";
                break;
            case STRICT_NON_INCLUSION:
                operatorName = "notStrictSubsetOfInteger";
                break;
            case EQUAL:
                operatorName = "equalInteger";
                break;
            case NOT_EQUAL:
                operatorName = "unequalInteger";
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        return operatorName;
    }

    private String generateInfiniteNatural(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator) {
        String operatorName;
        switch (operator) {
            case ELEMENT_OF:
                operatorName = "isNatural";
                break;
            case NOT_BELONGING:
                operatorName = "isNotNatural";
                break;
            case INCLUSION:
                operatorName = "subsetOfNatural";
                break;
            case NON_INCLUSION:
                operatorName = "notSubsetOfNatural";
                break;
            case STRICT_INCLUSION:
                operatorName = "strictSubsetOfNatural";
                break;
            case STRICT_NON_INCLUSION:
                operatorName = "notStrictSubsetOfNatural";
                break;
            case EQUAL:
                operatorName = "equalNatural";
                break;
            case NOT_EQUAL:
                operatorName = "unequalNatural";
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        return operatorName;
    }

    private String generateInfiniteNatural1(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator) {
        String operatorName;
        switch (operator) {
            case ELEMENT_OF:
                operatorName = "isNatural1";
                break;
            case NOT_BELONGING:
                operatorName = "isNotNatural1";
                break;
            case INCLUSION:
                operatorName = "subsetOfNatural1";
                break;
            case NON_INCLUSION:
                operatorName = "notSubsetOfNatural1";
                break;
            case STRICT_INCLUSION:
                operatorName = "strictSubsetOfNatural1";
                break;
            case STRICT_NON_INCLUSION:
                operatorName = "notStrictSubsetOfNatural1";
                break;
            case EQUAL:
                operatorName = "equalNatural1";
                break;
            case NOT_EQUAL:
                operatorName = "unequalNatural1";
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        return operatorName;
    }

    private String generateInfinite(PredicateOperatorWithExprArgsNode node) {
        PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = node.getOperator();
        ST template = currentGroup.getInstanceOf("infinite_predicate");
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        ExpressionOperatorNode.ExpressionOperator rhsOperator = ((ExpressionOperatorNode) rhs).getOperator();
        String operatorName;
        switch(rhsOperator) {
            case INTEGER:
                operatorName = generateInfiniteInteger(operator);
                break;
            case NATURAL:
                operatorName = generateInfiniteNatural(operator);
                break;
            case NATURAL1:
                operatorName = generateInfiniteNatural1(operator);
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        TemplateHandler.add(template, "operator", nameHandler.handle(operatorName));
        return template.render();
    }

    /*
    * This function generates code for boolean constants as predicates.
    */
    private String generateBoolean(PredicateOperatorNode.PredicateOperator operator) {
        ST val = currentGroup.getInstanceOf("boolean_val");
        TemplateHandler.add(val, "val", operator == PredicateOperatorNode.PredicateOperator.TRUE);
        return val.render();
    }

    public String visitIfPredicateNode(IfPredicateNode node) {
        ST template = currentGroup.getInstanceOf("if_expression_predicate");
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(node.getCondition(), null));
        TemplateHandler.add(template, "ifThen", machineGenerator.visitPredicateNode(node.getThenPredicate(), null));
        TemplateHandler.add(template, "ifElse", machineGenerator.visitPredicateNode(node.getElsePredicate(), null));
        return template.render();
    }

    public String visitLetPredicateNode(LetPredicateNode node) {
        return iterationConstructHandler.getIterationsMapIdentifier().get(node.toString());
    }

    public void setOperatorGenerator(OperatorGenerator operatorGenerator) {
        this.operatorGenerator = operatorGenerator;
    }
}
