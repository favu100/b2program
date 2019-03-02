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

    private final IterationConstructHandler iterationConstructHandler;

    private final MachineGenerator machineGenerator;

    private final STGroup group;

    private final TypeGenerator typeGenerator;

    private final ImportGenerator importGenerator;

    private final HashMap<String, String> iterationsMapCode;

    private final HashMap<String, String> iterationsMapIdentifier;

    private final List<String> boundedVariables;

    public IterationConstructGenerator(final IterationConstructHandler iterationConstructHandler, final MachineGenerator machineGenerator, final STGroup group,
                                       final TypeGenerator typeGenerator, final ImportGenerator importGenerator) {
        this.iterationConstructHandler = iterationConstructHandler;
        this.machineGenerator = machineGenerator;
        this.group = group;
        this.importGenerator = importGenerator;
        this.typeGenerator = typeGenerator;
        this.iterationsMapCode = new HashMap<>();
        this.iterationsMapIdentifier = new HashMap<>();
        this.boundedVariables = new ArrayList<>();
    }

    public ST generateEnumeration(ST template, DeclarationNode declarationNode) {
        TemplateHandler.add(template, "type", typeGenerator.generate(declarationNode.getType()));
        TemplateHandler.add(template, "identifier", "_ic_" + declarationNode.getName());
        return template;
    }

    private void checkPredicate(PredicateNode predicate, List<DeclarationNode> declarations) {
        if(!(predicate instanceof PredicateOperatorNode)) {
            //TODO
            if(declarations.size() != 1) {
                throw new RuntimeException("Predicate for iteration must be a conjunction");
            }
        } else {
            PredicateOperatorNode predicateOperatorNode = ((PredicateOperatorNode) predicate);
            if(predicateOperatorNode.getOperator() != PredicateOperatorNode.PredicateOperator.AND) {
                throw new RuntimeException("Predicate for iteration must be a conjunction");
            } else {
                for(int i = 0; i < declarations.size(); i++) {
                    PredicateNode innerPredicate = predicateOperatorNode.getPredicateArguments().get(i);
                    if(!(innerPredicate instanceof PredicateOperatorWithExprArgsNode)) {
                        throw new RuntimeException("First predicates must declare the set to iterate over");
                    }
                }
            }
        }
    }

    private ST getElementOfTemplate(DeclarationNode declarationNode, ExprNode lhs, ExprNode rhs) {
        if(!(lhs instanceof IdentifierExprNode) || !(((IdentifierExprNode) lhs).getName().equals(declarationNode.getName()))) {
            throw new RuntimeException("The expression on the left hand side of the first predicates must match the first identifier names");
        }
        ST template = group.getInstanceOf("iteration_construct_enumeration");
        ST enumerationTemplate = generateEnumeration(template, declarationNode);
        TemplateHandler.add(enumerationTemplate, "set", machineGenerator.visitExprNode(rhs, null));
        return enumerationTemplate;
    }

    private ST getEqualTemplate(DeclarationNode declarationNode, ExprNode lhs, ExprNode rhs) {
        if(!(lhs instanceof IdentifierExprNode) || !(((IdentifierExprNode) lhs).getName().equals(declarationNode.getName()))) {
            throw new RuntimeException("The expression on the left hand side of the first predicates must match the first identifier names");
        }
        ST template = group.getInstanceOf("iteration_construct_assignment");
        ST enumerationTemplate = generateEnumeration(template, declarationNode);
        TemplateHandler.add(enumerationTemplate, "expression", machineGenerator.visitExprNode(rhs, null));
        return enumerationTemplate;
    }

    private ST getSubsetTemplate(DeclarationNode declarationNode, ExprNode lhs, ExprNode rhs) {
        if(!(lhs instanceof IdentifierExprNode) || !(((IdentifierExprNode) lhs).getName().equals(declarationNode.getName()))) {
            throw new RuntimeException("The expression on the left hand side of the first predicates must match the first identifier names");
        }
        ST template = group.getInstanceOf("iteration_construct_subset");
        ST enumerationTemplate = generateEnumeration(template, declarationNode);
        TemplateHandler.add(enumerationTemplate, "set", machineGenerator.visitExprNode(rhs, null));
        return enumerationTemplate;
    }

    private ST getSubsetNeqTemplate(DeclarationNode declarationNode, ExprNode lhs, ExprNode rhs) {
        if(!(lhs instanceof IdentifierExprNode) || !(((IdentifierExprNode) lhs).getName().equals(declarationNode.getName()))) {
            throw new RuntimeException("The expression on the left hand side of the first predicates must match the first identifier names");
        }
        ST template = group.getInstanceOf("iteration_construct_subsetneq");
        ST enumerationTemplate = generateEnumeration(template, declarationNode);
        TemplateHandler.add(enumerationTemplate, "set", machineGenerator.visitExprNode(rhs, null));
        return enumerationTemplate;
    }

    private List<ST> getEnumerationTemplates(List<DeclarationNode> declarations, PredicateNode predicate) {
        ST enumerationTemplate = null;
        List<ST> enumerationTemplates = new ArrayList<>();
        for(int i = 0; i < declarations.size(); i++) {
            DeclarationNode declarationNode = declarations.get(i);
            PredicateOperatorWithExprArgsNode innerPredicate;
            if(predicate instanceof PredicateOperatorWithExprArgsNode) {
                innerPredicate = (PredicateOperatorWithExprArgsNode) predicate;
            } else {
                innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(i);
            }
            if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF) {
                enumerationTemplate = getElementOfTemplate(declarationNode, innerPredicate.getExpressionNodes().get(0), innerPredicate.getExpressionNodes().get(1));
            } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL) {
                enumerationTemplate = getEqualTemplate(declarationNode, innerPredicate.getExpressionNodes().get(0), innerPredicate.getExpressionNodes().get(1));
            } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.INCLUSION) {
                enumerationTemplate = getSubsetTemplate(declarationNode, innerPredicate.getExpressionNodes().get(0), innerPredicate.getExpressionNodes().get(1));
            } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.STRICT_INCLUSION) {
                enumerationTemplate = getSubsetNeqTemplate(declarationNode, innerPredicate.getExpressionNodes().get(0), innerPredicate.getExpressionNodes().get(1));
            } else {
                throw new RuntimeException("Other operations within predicate node not supported yet");
            }
            enumerationTemplates.add(enumerationTemplate);
        }
        return enumerationTemplates;
    }

    private ST evaluateEnumerationTemplates(List<ST> enumerationTemplates, String innerBody) {

        int enumerationSize = enumerationTemplates.size();
        ST lastEnumeration = enumerationTemplates.get(enumerationSize - 1);

        TemplateHandler.add(lastEnumeration, "body", innerBody);

        int i = enumerationSize - 2;
        while(i >= 0) {
            ST currentEnumeration = enumerationTemplates.get(i);
            TemplateHandler.add(currentEnumeration, "body", lastEnumeration.render());
            lastEnumeration = currentEnumeration;
            i--;
        }
        return lastEnumeration;
    }

    public String getElementFromBoundedVariables(List<DeclarationNode> declarations) {
        if(declarations.size() == 1) {
            return "_ic_" + declarations.get(declarations.size() - 1).getName();
        } else {
            ST firstCouple = group.getInstanceOf("couple_create");
            TemplateHandler.add(firstCouple, "arg1", "_ic_" + declarations.get(0).getName());
            TemplateHandler.add(firstCouple, "arg2", "_ic_" + declarations.get(1).getName());
            return declarations.subList(2, declarations.size()).stream()
                    .map(DeclarationNode::getName)
                    .reduce(firstCouple.render(), (a,e) -> {
                ST couple = group.getInstanceOf("couple_create");
                TemplateHandler.add(couple, "arg1", a);
                TemplateHandler.add(couple, "arg2", "_ic_" + e);
                return couple.render();
            });
        }
    }

    public String generateSetComprehension(SetComprehensionNode node) {
        PredicateNode predicate = node.getPredicateNode();
        List<DeclarationNode> declarations = node.getDeclarationList();
        addBoundedVariables(declarations);
        checkPredicate(predicate, declarations);
        importGenerator.addImportInIteration(node.getType());

        ST template = group.getInstanceOf("set_comprehension");

        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectPredicate(predicate);
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            this.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();

        List<ST> enumerationTemplates = getEnumerationTemplates(declarations, predicate);

        iterationConstructHandler.setIterationConstructGenerator(this);

        String elementName = getElementFromBoundedVariables(declarations);
        String innerBody = generateSetComprehensionPredicate(predicate, "_ic_set_" + iterationConstructCounter, elementName);
        String comprehension = evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();

        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(template, "identifier", "_ic_set_" + iterationConstructCounter);
        TemplateHandler.add(template, "isRelation", node.getDeclarationList().size() > 1);
        TemplateHandler.add(template, "comprehension", comprehension);
        String result = template.render();
        addIteration(node.toString(), "_ic_set_"+ iterationConstructCounter, result);
        clearBoundedVariables(declarations);
        return result;
    }

    public String generateLambda(LambdaNode node) {
        PredicateNode predicate = node.getPredicate();
        List<DeclarationNode> declarations = node.getDeclarations();
        addBoundedVariables(declarations);
        checkPredicate(predicate, declarations);
        ExprNode expression = node.getExpression();
        importGenerator.addImportInIteration(node.getType());

        ST template = group.getInstanceOf("lambda");

        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectExpression(
                iterationConstructHandler.inspectPredicate(predicate), expression);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            this.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }

        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());

        List<ST> enumerationTemplates = getEnumerationTemplates(declarations, predicate);

        iterationConstructHandler.setIterationConstructGenerator(this);

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String innerBody = generateLambdaExpression(predicate, expression, "_ic_set_" + iterationConstructCounter, "_ic_" + declarations.get(declarations.size() - 1).getName());
        String lambda = evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();


        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(template, "identifier", "_ic_set_" + iterationConstructCounter);
        TemplateHandler.add(template, "lambda", lambda);
        String result = template.render();
        addIteration(node.toString(), "_ic_set_"+ iterationConstructCounter, result);
        clearBoundedVariables(declarations);
        return result;
    }

    public String generateQuantifiedPredicate(QuantifiedPredicateNode node) {
        PredicateNode predicate = node.getPredicateNode();
        List<DeclarationNode> declarations = node.getDeclarationList();
        addBoundedVariables(declarations);

        checkPredicate(predicate, declarations);
        boolean forAll = node.getOperator() == QuantifiedPredicateNode.QuantifiedPredicateOperator.UNIVERSAL_QUANTIFICATION;
        importGenerator.addImportInIteration(node.getType());

        ST template = group.getInstanceOf("quantified_predicate");

        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectPredicate(predicate);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            this.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }

        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());

        List<ST> enumerationTemplates = getEnumerationTemplates(declarations, predicate);

        iterationConstructHandler.setIterationConstructGenerator(this);

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String innerBody = generateQuantifiedPredicateEvaluation(predicate, "_ic_boolean_" + iterationConstructCounter, forAll);
        String predicateString = evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();

        TemplateHandler.add(template, "identifier", "_ic_boolean_" + iterationConstructCounter);
        TemplateHandler.add(template, "forall", forAll);
        TemplateHandler.add(template, "predicate", predicateString);
        String result = template.render();
        addIteration(node.toString(), "_ic_boolean_"+ iterationConstructCounter, result);
        clearBoundedVariables(declarations);
        return result;
    }

    public String generateSetComprehensionPredicate(PredicateNode predicateNode, String setName, String elementName) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("set_comprehension_predicate");
        machineGenerator.inIterationConstruct();
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(template, "set", setName);
        TemplateHandler.add(template, "isRelation", boundedVariables.size() > 1);
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

    public String generateQuantifiedPredicateEvaluation(PredicateNode predicateNode, String identifier, boolean forAll) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("quantified_evaluation");
        machineGenerator.inIterationConstruct();
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "forall", forAll);
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
        iterationConstructHandler.incrementIterationConstructCounter();
        return null;
    }

    @Override
    public Void visitLambdaNode(LambdaNode node, Void aVoid) {
        iterationsMapCode.put(node.toString(), generateLambda(node));
        iterationConstructHandler.incrementIterationConstructCounter();
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
    public Void visitPredicateOperatorNode(PredicateOperatorNode node, Void expected) {
        node.getPredicateArguments().forEach(pred -> visitPredicateNode(pred, expected));
        return null;
    }

    @Override
    public Void visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    @Override
    public Void visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void aVoid) {
        iterationsMapCode.put(node.toString(), generateQuantifiedPredicate(node));
        iterationConstructHandler.incrementIterationConstructCounter();
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

    public void addBoundedVariables(List<DeclarationNode> declarations) {
        boundedVariables.addAll(declarations.stream().map(DeclarationNode::toString).collect(Collectors.toList()));
    }

    public void clearBoundedVariables(List<DeclarationNode> declarations) {
        boundedVariables.removeAll(declarations.stream().map(DeclarationNode::toString).collect(Collectors.toList()));
    }

    public List<String> getBoundedVariables() {
        return boundedVariables;
    }

    private void addIteration(String node, String identifier, String code) {
        iterationsMapIdentifier.put(node, identifier);
        iterationsMapCode.put(node, code);
    }

    public HashMap<String, String> getIterationsMapCode() {
        return iterationsMapCode;
    }

    public HashMap<String, String> getIterationsMapIdentifier() {
        return iterationsMapIdentifier;
    }
}
