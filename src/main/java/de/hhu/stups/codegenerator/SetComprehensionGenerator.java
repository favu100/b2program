package de.hhu.stups.codegenerator;

import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
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
public class SetComprehensionGenerator implements AbstractVisitor<Void, Void> {

    private final MachineGenerator machineGenerator;

    private final STGroup group;

    private final ExpressionGenerator expressionGenerator;

    private final TypeGenerator typeGenerator;

    private final HashMap<String, String> comprehensionsMapCode;

    private final HashMap<String, String> comprehensionMapIdentifier;

    private final List<String> boundedVariables;

    public SetComprehensionGenerator(final MachineGenerator machineGenerator, final STGroup group,
                                     final ExpressionGenerator expressionGenerator, final TypeGenerator typeGenerator) {
        this.machineGenerator = machineGenerator;
        this.group = group;
        this.expressionGenerator = expressionGenerator;
        this.typeGenerator = typeGenerator;
        this.comprehensionsMapCode = new HashMap<>();
        this.comprehensionMapIdentifier = new HashMap<>();
        this.boundedVariables = new ArrayList<>();
    }

    public String generate(SetComprehensionNode node) {
        PredicateNode predicate = node.getPredicateNode();
        if(!(predicate instanceof PredicateOperatorNode)) {
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
        int comprehensionCounter = expressionGenerator.getComprehensionCounter();
        ST template = group.getInstanceOf("set_comprehension");
        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(template, "identifier", "_sc_set_" + comprehensionCounter);
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
                TemplateHandler.add(enumerationTemplate, "body", generatePredicate(predicate, "_sc_set_" + comprehensionCounter, "_sc_" + declarationNode.getName()));
            }
            TemplateHandler.add(template, "comprehension", enumerationTemplate.render());
        }
        String result = template.render();
        comprehensionMapIdentifier.put(node.toString(), "_sc_set_"+ comprehensionCounter);
        comprehensionsMapCode.put(node.toString(), result);
        return result;
    }

    public ST generateEnumeration(DeclarationNode declarationNode) {
        ST template = group.getInstanceOf("set_comprehension_enumeration");
        TemplateHandler.add(template, "type", typeGenerator.generate(declarationNode.getType()));
        TemplateHandler.add(template, "identifier", "_sc_" + declarationNode.getName());
        return template;
    }

    public String generatePredicate(PredicateNode predicateNode, String setName, String elementName) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("set_comprehension_predicate");
        machineGenerator.inSetComprehension();
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(template, "set", setName);
        TemplateHandler.add(template, "element", elementName);
        machineGenerator.leaveSetComprehesion();
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
        comprehensionsMapCode.put(node.toString(), generate(node));
        expressionGenerator.incrementComprehensionCounter();
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

    public HashMap<String, String> getComprehensionsMapCode() {
        return comprehensionsMapCode;
    }

    public HashMap<String, String> getComprehensionMapIdentifier() {
        return comprehensionMapIdentifier;
    }
}
