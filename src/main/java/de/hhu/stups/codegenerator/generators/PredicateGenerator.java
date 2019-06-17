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

import java.util.ArrayList;
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

    private static final List<ExpressionOperatorNode.ExpressionOperator> POWER_SET_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.POW, ExpressionOperatorNode.ExpressionOperator.POW1, ExpressionOperatorNode.ExpressionOperator.FIN, ExpressionOperatorNode.ExpressionOperator.FIN1);


    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final NameHandler nameHandler;

    private final ImportGenerator importGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final InfiniteSetGenerator infiniteSetGenerator;

    private final RelationSetGenerator relationSetGenerator;

    private OperatorGenerator operatorGenerator;

    public PredicateGenerator(final STGroup currentGroup, final MachineGenerator machineGenerator, final NameHandler nameHandler,
                              final ImportGenerator importGenerator, final IterationConstructHandler iterationConstructHandler) {
        this.currentGroup = currentGroup;
        this.machineGenerator = machineGenerator;
        this.nameHandler = nameHandler;
        this.importGenerator = importGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.infiniteSetGenerator = new InfiniteSetGenerator(currentGroup, machineGenerator, nameHandler);
        this.relationSetGenerator = new RelationSetGenerator(currentGroup, machineGenerator, nameHandler, infiniteSetGenerator);
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
        if(infiniteSetGenerator.checkInfinite(node)) {
            return infiniteSetGenerator.generateInfinite(node);
        }
        if(relationSetGenerator.checkRelation(node)) {
            generateRelationOnRhs(node);
        }
        List<String> expressionList = node.getExpressionNodes().stream()
                .map(expr -> machineGenerator.visitExprNode(expr, null))
                .collect(Collectors.toList());
        return operatorGenerator.generateBinary(node::getOperator, expressionList);
    }

    /*
    * This function generates code for predicates with a relation on the right-hand side
    */
    private String generateRelationOnRhs(PredicateOperatorWithExprArgsNode node) {
        ExpressionOperatorNode rhs = (ExpressionOperatorNode) node.getExpressionNodes().get(1);
        if(POWER_SET_EXPRESSIONS.contains(rhs.getOperator())) {
            return relationSetGenerator.generateRelation(transformPowNodeToRelationNode(node));
        }
        return relationSetGenerator.generateRelation(node);
    }

    /*
    * This function transforms the right-hand side with a POW node to a relation node
    */
    private PredicateOperatorWithExprArgsNode transformPowNodeToRelationNode(PredicateOperatorWithExprArgsNode node) {
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExpressionOperatorNode rhs = (ExpressionOperatorNode) node.getExpressionNodes().get(1);
        List<ExprNode> expressions = new ArrayList<>();
        ExprNode domain = rhs.getExpressionNodes().get(0);
        ExprNode range = rhs.getExpressionNodes().get(1);
        expressions.add(lhs);
        expressions.add(new ExpressionOperatorNode(node.getSourceCodePosition(), Arrays.asList(domain, range), ExpressionOperatorNode.ExpressionOperator.SET_RELATION));
        return new PredicateOperatorWithExprArgsNode(node.getSourceCodePosition(), PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, expressions);
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

    /*
    * This function generates code for boolean constants as predicates.
    */
    private String generateBoolean(PredicateOperatorNode.PredicateOperator operator) {
        ST val = currentGroup.getInstanceOf("boolean_val");
        TemplateHandler.add(val, "val", operator == PredicateOperatorNode.PredicateOperator.TRUE);
        return val.render();
    }

    /*
    * This function generates code for the if predicate
    */
    public String visitIfPredicateNode(IfPredicateNode node) {
        ST template = currentGroup.getInstanceOf("if_expression_predicate");
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(node.getCondition(), null));
        TemplateHandler.add(template, "ifThen", machineGenerator.visitPredicateNode(node.getThenPredicate(), null));
        TemplateHandler.add(template, "ifElse", machineGenerator.visitPredicateNode(node.getElsePredicate(), null));
        return template.render();
    }

    /*
    * This function generates code for let predicates by invoking pre-generated code from IterationConstructHandler
    */
    public String visitLetPredicateNode(LetPredicateNode node) {
        return iterationConstructHandler.getIterationsMapIdentifier().get(node.toString());
    }

    public void setOperatorGenerator(OperatorGenerator operatorGenerator) {
        this.operatorGenerator = operatorGenerator;
    }
}
