package de.hhu.stups.codegenerator;

import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.expression.NumberNode;
import de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode;
import de.prob.parser.ast.nodes.expression.SetComprehensionNode;
import de.prob.parser.ast.nodes.ltl.LTLBPredicateNode;
import de.prob.parser.ast.nodes.ltl.LTLInfixOperatorNode;
import de.prob.parser.ast.nodes.ltl.LTLKeywordNode;
import de.prob.parser.ast.nodes.ltl.LTLPrefixOperatorNode;
import de.prob.parser.ast.nodes.predicate.CastPredicateExpressionNode;
import de.prob.parser.ast.nodes.predicate.IdentifierPredicateNode;
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
import de.prob.parser.ast.nodes.substitution.ListSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.OperationCallSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.SkipSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.VarSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.WhileSubstitutionNode;
import de.prob.parser.ast.types.SetType;
import de.prob.parser.ast.visitors.AbstractVisitor;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by fabian on 05.02.19.
 */
public class IterationConstructGenerator implements AbstractVisitor<Void, Void> {

    private final MachineGenerator machineGenerator;

    private final STGroup group;

    private final ExpressionGenerator expressionGenerator;

    private final TypeGenerator typeGenerator;

    private final ImportGenerator importGenerator;

    private final HashMap<String, String> iterationsMapCode;

    private final HashMap<String, String> iterationsMapIdentifier;

    private final List<String> boundedVariables;

    public IterationConstructGenerator(final MachineGenerator machineGenerator, final STGroup group,
                                       final ExpressionGenerator expressionGenerator, final TypeGenerator typeGenerator,
                                       final ImportGenerator importGenerator) {
        this.machineGenerator = machineGenerator;
        this.group = group;
        this.expressionGenerator = expressionGenerator;
        this.importGenerator = importGenerator;
        this.typeGenerator = typeGenerator;
        this.iterationsMapCode = new HashMap<>();
        this.iterationsMapIdentifier = new HashMap<>();
        this.boundedVariables = new ArrayList<>();
    }

    public ST generateEnumeration(DeclarationNode declarationNode) {
        ST template = group.getInstanceOf("iteration_construct_enumeration");
        TemplateHandler.add(template, "type", typeGenerator.generate(declarationNode.getType()));
        TemplateHandler.add(template, "identifier", "_ic_" + declarationNode.getName());
        return template;
    }

    public String generateSetComprehension(SetComprehensionNode node) {
        PredicateNode predicate = node.getPredicateNode();
        if(!(predicate instanceof PredicateOperatorNode)) {
            //TODO
            throw new RuntimeException("Predicate for Set Comprehension must be a conjunction");
        } else {
            PredicateOperatorNode predicateOperatorNode = ((PredicateOperatorNode) predicate);
            if(predicateOperatorNode.getOperator() != PredicateOperatorNode.PredicateOperator.AND) {
                throw new RuntimeException("Predicate for Set Comprehension must be a conjunction");
            } else {
                for(int i = 0; i < node.getDeclarationList().size(); i++) {
                    PredicateNode innerPredicate = predicateOperatorNode.getPredicateArguments().get(i);
                    if(!(innerPredicate instanceof PredicateOperatorWithExprArgsNode)) {
                        throw new RuntimeException("First predicates must declare the set to iterate over");
                    }
                }
            }
        }
        importGenerator.addImport(node.getType());
        int iterationConstructCounter = expressionGenerator.getIterationConstructCounter();
        ST template = group.getInstanceOf("set_comprehension");
        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(template, "identifier", "_ic_set_" + iterationConstructCounter);
        TemplateHandler.add(template, "isRelation", node.getDeclarationList().size() > 1);
        boundedVariables.clear();
        boundedVariables.addAll(node.getDeclarationList().stream().map(DeclarationNode::toString).collect(Collectors.toList()));
        for(int i = 0; i < node.getDeclarationList().size(); i++) {
            DeclarationNode declarationNode = node.getDeclarationList().get(i);
            PredicateOperatorWithExprArgsNode innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) node.getPredicateNode()).getPredicateArguments().get(i);
            ST enumerationTemplate;
            if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF) {
                ExprNode leftExpression = innerPredicate.getExpressionNodes().get(0);
                ExprNode rightExpression = innerPredicate.getExpressionNodes().get(1);
                if(!(leftExpression instanceof IdentifierExprNode) || !(((IdentifierExprNode) leftExpression).getName().equals(declarationNode.getName()))) {
                    throw new RuntimeException("The expression on the left hand side of the first predicates must match the first identifier names");
                }
                enumerationTemplate = generateEnumeration(declarationNode);
                TemplateHandler.add(enumerationTemplate, "set", machineGenerator.visitExprNode(rightExpression, null));
            } else {
                throw new RuntimeException("Other operations within predicate node not supported yet");
            }
            //TODO
            if(i == node.getDeclarationList().size() - 1) {
                TemplateHandler.add(enumerationTemplate, "body", generateSetComprehensionPredicate(predicate, "_ic_set_" + iterationConstructCounter, "_ic_" + declarationNode.getName()));
            }
            TemplateHandler.add(template, "comprehension", enumerationTemplate.render());
        }
        String result = template.render();
        iterationsMapIdentifier.put(node.toString(), "_ic_set_"+ iterationConstructCounter);
        iterationsMapCode.put(node.toString(), result);
        return result;
    }

    public String generateLambda(LambdaNode node) {
        PredicateNode predicate = node.getPredicate();
        ExprNode expression = node.getExpression();
        if(!(predicate instanceof PredicateOperatorNode)) {
            //TODO
            throw new RuntimeException("Predicate for Lambda Expression must be a conjunction");
        } else {
            PredicateOperatorNode predicateOperatorNode = ((PredicateOperatorNode) predicate);
            if(predicateOperatorNode.getOperator() != PredicateOperatorNode.PredicateOperator.AND) {
                throw new RuntimeException("Predicate for Lambda Expression must be a conjunction");
            } else {
                for(int i = 0; i < node.getDeclarations().size(); i++) {
                    PredicateNode innerPredicate = predicateOperatorNode.getPredicateArguments().get(i);
                    if(!(innerPredicate instanceof PredicateOperatorWithExprArgsNode)) {
                        throw new RuntimeException("First predicates must declare the set to iterate over");
                    }
                }
            }
        }
        importGenerator.addImport(node.getType());
        importGenerator.addImport(((SetType)node.getType()).getSubType());
        int iterationConstructCounter = expressionGenerator.getIterationConstructCounter();
        ST template = group.getInstanceOf("lambda");
        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(template, "identifier", "_ic_set_" + iterationConstructCounter);
        boundedVariables.clear();
        boundedVariables.addAll(node.getDeclarations().stream().map(DeclarationNode::toString).collect(Collectors.toList()));
        for(int i = 0; i < node.getDeclarations().size(); i++) {
            DeclarationNode declarationNode = node.getDeclarations().get(i);
            PredicateOperatorWithExprArgsNode innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(i);
            ST enumerationTemplate;
            if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF) {
                ExprNode leftExpression = innerPredicate.getExpressionNodes().get(0);
                ExprNode rightExpression = innerPredicate.getExpressionNodes().get(1);
                if(!(leftExpression instanceof IdentifierExprNode) || !(((IdentifierExprNode) leftExpression).getName().equals(declarationNode.getName()))) {
                    throw new RuntimeException("The expression on the left hand side of the first predicates must match the first identifier names");
                }
                enumerationTemplate = generateEnumeration(declarationNode);
                TemplateHandler.add(enumerationTemplate, "set", machineGenerator.visitExprNode(rightExpression, null));
            } else {
                throw new RuntimeException("Other operations within predicate node not supported yet");
            }
            //TODO
            if(i == node.getDeclarations().size() - 1) {
                TemplateHandler.add(enumerationTemplate, "body", generateLambdaExpression(predicate, expression, "_ic_set_" + iterationConstructCounter, "_ic_" + declarationNode.getName()));
            }
            TemplateHandler.add(template, "lambda", enumerationTemplate.render());
        }
        String result = template.render();
        iterationsMapIdentifier.put(node.toString(), "_ic_set_"+ iterationConstructCounter);
        iterationsMapCode.put(node.toString(), result);
        return result;
    }

    public String generateSetComprehensionPredicate(PredicateNode predicateNode, String setName, String elementName) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("set_comprehension_predicate");
        machineGenerator.inIterationConstruct();
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(template, "set", setName);
        TemplateHandler.add(template, "element", elementName);
        machineGenerator.leaveIterationConstruct();
        return template.render();
    }

    public String generateLambdaExpression(PredicateNode predicateNode, ExprNode expression, String relationName, String elementName) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("lambda_expression");
        machineGenerator.inIterationConstruct();
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(template, "relation", relationName);
        TemplateHandler.add(template, "element", elementName);
        TemplateHandler.add(template, "expression", machineGenerator.visitExprNode(expression, null));
        machineGenerator.leaveIterationConstruct();
        return template.render();
    }

    @Override
    public Void visitExprOperatorNode(ExpressionOperatorNode node, Void aVoid) {
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, null));
        return null;
    }

    @Override
    public Void visitIdentifierExprNode(IdentifierExprNode node, Void aVoid) {
        return null;
    }

    @Override
    public Void visitCastPredicateExpressionNode(CastPredicateExpressionNode castPredicateExpressionNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitNumberNode(NumberNode node, Void aVoid) {
        return null;
    }

    @Override
    public Void visitQuantifiedExpressionNode(QuantifiedExpressionNode quantifiedExpressionNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitSetComprehensionNode(SetComprehensionNode node, Void aVoid) {
        iterationsMapCode.put(node.toString(), generateSetComprehension(node));
        expressionGenerator.incrementIterationConstructCounter();
        return null;
    }

    @Override
    public Void visitLambdaNode(LambdaNode node, Void aVoid) {
        iterationsMapCode.put(node.toString(), generateLambda(node));
        expressionGenerator.incrementIterationConstructCounter();
        return null;
    }

    @Override
    public Void visitLTLPrefixOperatorNode(LTLPrefixOperatorNode ltlPrefixOperatorNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitLTLKeywordNode(LTLKeywordNode ltlKeywordNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitLTLInfixOperatorNode(LTLInfixOperatorNode ltlInfixOperatorNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitLTLBPredicateNode(LTLBPredicateNode ltlbPredicateNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitIdentifierPredicateNode(IdentifierPredicateNode identifierPredicateNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitPredicateOperatorNode(PredicateOperatorNode predicateOperatorNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode predicateOperatorWithExprArgsNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitQuantifiedPredicateNode(QuantifiedPredicateNode quantifiedPredicateNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitVarSubstitutionNode(VarSubstitutionNode varSubstitutionNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitWhileSubstitutionNode(WhileSubstitutionNode whileSubstitutionNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitListSubstitutionNode(ListSubstitutionNode node, Void aVoid) {
        node.getSubstitutions().forEach(subs -> visitSubstitutionNode(subs, null));
        return null;
    }

    @Override
    public Void visitIfOrSelectSubstitutionsNode(IfOrSelectSubstitutionsNode ifOrSelectSubstitutionsNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitAssignSubstitutionNode(AssignSubstitutionNode node, Void aVoid) {
        node.getLeftSide().forEach(lhs -> visitExprNode(lhs, null));
        node.getRightSide().forEach(rhs -> visitExprNode(rhs, null));
        return null;
    }

    @Override
    public Void visitSkipSubstitutionNode(SkipSubstitutionNode skipSubstitutionNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitConditionSubstitutionNode(ConditionSubstitutionNode conditionSubstitutionNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitAnySubstitution(AnySubstitutionNode anySubstitutionNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void aVoid) {
        node.getIdentifiers().forEach(id -> visitExprNode(id, null));
        visitExprNode(node.getExpression(), null);
        return null;
    }

    @Override
    public Void visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void aVoid) {
        node.getIdentifiers().forEach(id -> visitExprNode(id, null));
        visitPredicateNode(node.getPredicate(), null);
        return null;
    }

    @Override
    public Void visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode operationCallSubstitutionNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitChoiceSubstitutionNode(ChoiceSubstitutionNode choiceSubstitutionNode, Void aVoid) {
        return null;
    }

    public HashMap<String, String> getIterationsMapCode() {
        return iterationsMapCode;
    }

    public HashMap<String, String> getIterationsMapIdentifier() {
        return iterationsMapIdentifier;
    }
}
