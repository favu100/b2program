package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by fabian on 21.05.19.
 */
public class RelationSetGenerator {

    private static final List<PredicateOperatorWithExprArgsNode.PredOperatorExprArgs> RELATION_FUNCTION_PREDICATE_OPERATORS =
            Arrays.asList(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING);

    private static final List<ExpressionOperatorNode.ExpressionOperator> RELATION_FUNCTION_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.SET_RELATION, ExpressionOperatorNode.ExpressionOperator.SURJECTION_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION_RELATION,
                    ExpressionOperatorNode.ExpressionOperator.PARTIAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_BIJECTION,
                    ExpressionOperatorNode.ExpressionOperator.TOTAL_BIJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_FUNCTION);

    public static final List<ExpressionOperatorNode.ExpressionOperator> TOTAL_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.TOTAL_BIJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_INJECTION);

    public static final List<ExpressionOperatorNode.ExpressionOperator> PARTIAL_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.PARTIAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_BIJECTION);

    public static final List<ExpressionOperatorNode.ExpressionOperator> SURJECTIVE_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.SURJECTION_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_SURJECTION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> INJECTIVE_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.PARTIAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_INJECTION);

    public static final List<ExpressionOperatorNode.ExpressionOperator> BIJECTIVE_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.PARTIAL_BIJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_BIJECTION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> FUNCTION_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.PARTIAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_INJECTION,
                            ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_BIJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_BIJECTION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> RELATION_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.SET_RELATION, ExpressionOperatorNode.ExpressionOperator.SURJECTION_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION_RELATION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> POWER_SET_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.POW, ExpressionOperatorNode.ExpressionOperator.POW1, ExpressionOperatorNode.ExpressionOperator.FIN, ExpressionOperatorNode.ExpressionOperator.FIN1);


    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final NameHandler nameHandler;

    private final InfiniteSetGenerator infiniteSetGenerator;

    public RelationSetGenerator(STGroup group, MachineGenerator machineGenerator, NameHandler nameHandler, InfiniteSetGenerator infiniteSetGenerator) {
        this.currentGroup = group;
        this.machineGenerator = machineGenerator;
        this.nameHandler = nameHandler;
        this.infiniteSetGenerator = infiniteSetGenerator;
    }

    /*
    * This function gets a predicate node and checks whether a set of relations is on the right-hand side of the predicate and whether code can be generated with the given operator.
    */
    public boolean checkRelation(PredicateOperatorWithExprArgsNode node) {
        List<ExprNode> expressions = node.getExpressionNodes();
        PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = node.getOperator();
        if(expressions.size() == 2 && RELATION_FUNCTION_PREDICATE_OPERATORS.contains(operator)) {
            ExprNode rhs = node.getExpressionNodes().get(1);
            if(rhs instanceof ExpressionOperatorNode) {
                ExpressionOperatorNode.ExpressionOperator rhsOperator = ((ExpressionOperatorNode) rhs).getOperator();
                if(RELATION_FUNCTION_EXPRESSIONS.contains(rhsOperator)) {
                    return true;
                } else if(POWER_SET_EXPRESSIONS.contains(rhsOperator)) {
                    ExprNode innerRhs = ((ExpressionOperatorNode) rhs).getExpressionNodes().get(0);
                    if(innerRhs instanceof ExpressionOperatorNode && ((ExpressionOperatorNode) innerRhs).getOperator() == ExpressionOperatorNode.ExpressionOperator.CARTESIAN_PRODUCT) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    /*
    * This function generates code for a predicate containing a set of relations on the right-hand side
    */
    public String generateRelation(PredicateOperatorWithExprArgsNode node) {
        PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = node.getOperator();
        List<String> predicates = new ArrayList<>();
        ST template = currentGroup.getInstanceOf("relation_predicate");
        ExprNode rhs = node.getExpressionNodes().get(1);
        ExpressionOperatorNode.ExpressionOperator rhsOperator = ((ExpressionOperatorNode) rhs).getOperator();
        predicates.add(checkDomain(node, rhsOperator));
        predicates.add(checkRange(node, rhsOperator));
        predicates.add(generateRelationFunction(node, rhsOperator));
        predicates.add(generateTotalPartial(node, rhsOperator));
        predicates.add(generateSurjectionInjectionBijection(node, rhsOperator));
        predicates = predicates.stream()
                .filter(str -> !str.isEmpty())
                .collect(Collectors.toList());
        String firstPredicate = predicates.get(0);
        TemplateHandler.add(template, "checkElementOf", operator == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF);
        TemplateHandler.add(template, "predicates", predicates.subList(1, predicates.size()).stream()
                                .reduce(firstPredicate, (a,e) -> {
                                    ST binary = currentGroup.getInstanceOf("binary");
                                    TemplateHandler.add(binary, "arg1", a);
                                    TemplateHandler.add(binary, "operator", nameHandler.handle("and"));
                                    TemplateHandler.add(binary, "arg2", e);
                                    return binary.render();
                                }));
        return template.render();
    }

    /*
    * This function generates code for checking the domain of a relation with a set of relations on the right-hand side
    */
    private String checkDomain(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator) {
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        ExpressionOperatorNode relation = (ExpressionOperatorNode) rhs;
        ExprNode domain = relation.getExpressionNodes().get(0);
        if(infiniteSetGenerator.isInfiniteExpression(domain)) {
            return infiniteSetGenerator.generateInfiniteDomainChecking(node, operator, domain);
        }

        ST template = currentGroup.getInstanceOf("relation_check_domain");
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        TemplateHandler.add(template, "domain", machineGenerator.visitExprNode(domain, null));

        return template.render();
    }

    /*
    * This function generates code for checking the range of a relation with a set of relations on the right-hand side
    */
    private String checkRange(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator) {
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        ExpressionOperatorNode relation = (ExpressionOperatorNode) rhs;
        ExprNode range = relation.getExpressionNodes().get(1);
        if(infiniteSetGenerator.isInfiniteExpression(range)) {
            return infiniteSetGenerator.generateInfiniteRangeChecking(node, operator, range);
        }

        ST template = currentGroup.getInstanceOf("relation_check_range");
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        TemplateHandler.add(template, "range", machineGenerator.visitExprNode(range, null));

        return template.render();
    }


    /*
    * This function generates code for checking total/partial relation with a set of relations on the right-hand side
    */
    private String generateTotalPartial(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator) {
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        ExpressionOperatorNode relation = (ExpressionOperatorNode) rhs;
        ExprNode domain = relation.getExpressionNodes().get(0);
        if(infiniteSetGenerator.isInfiniteExpression(domain)) {
            return infiniteSetGenerator.generateInfiniteTotalPartial(node, operator, domain);
        }

        ST template = currentGroup.getInstanceOf("relation_total_partial");
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        if(TOTAL_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", "isTotal");
        } else if(PARTIAL_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", "isPartial");
        } else {
            //Must be empty because predicate can be optional
            return "";
        }

        TemplateHandler.add(template, "domain", machineGenerator.visitExprNode(domain, null));
        return template.render();
    }

    /*
    * This function generates code for checking surjective/injective/bijective relation with a set of relations on the right-hand side
    */
    private String generateSurjectionInjectionBijection(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator) {
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        ExpressionOperatorNode relation = (ExpressionOperatorNode) rhs;
        ExprNode range = relation.getExpressionNodes().get(1);
        if(infiniteSetGenerator.isInfiniteExpression(range)) {
            return infiniteSetGenerator.generateInfiniteSurjectionInjectionBijection(node, operator, range);
        }
        ST template;
        if(SURJECTIVE_EXPRESSIONS.contains(operator)) {
            template = currentGroup.getInstanceOf("relation_surjection");
        } else if(INJECTIVE_EXPRESSIONS.contains(operator)) {
            template = currentGroup.getInstanceOf("relation_injection");
        } else if(BIJECTIVE_EXPRESSIONS.contains(operator)) {
            template = currentGroup.getInstanceOf("relation_bijection");
        } else {
            //Must be empty because predicate can be optional
            return "";
        }
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        TemplateHandler.add(template, "range", machineGenerator.visitExprNode(relation.getExpressionNodes().get(1), null));
        return template.render();
    }

    /*
    * This function generates code for checking a relation/function with a set of relations on the right-hand side
    */
    private String generateRelationFunction(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator) {
        ST template = currentGroup.getInstanceOf("relation_function");
        ExprNode lhs = node.getExpressionNodes().get(0);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        if(RELATION_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", "isRelation");
        } else if(FUNCTION_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", "isFunction");
        } else {
            //Must be empty because predicate can be optional
            return "";
        }
        return template.render();
    }

}
