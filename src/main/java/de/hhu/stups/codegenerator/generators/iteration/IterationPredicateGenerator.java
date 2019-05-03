package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by fabian on 04.03.19.
 */
public class IterationPredicateGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final TypeGenerator typeGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private boolean inLoop;

    public IterationPredicateGenerator(final STGroup group, final MachineGenerator machineGenerator,
                                       final TypeGenerator typeGenerator, final IterationConstructHandler iterationConstructHandler) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.typeGenerator = typeGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.inLoop = false;
    }

    public ST generateEnumeration(ST template, DeclarationNode declarationNode) {
        TemplateHandler.add(template, "type", typeGenerator.generate(declarationNode.getType()));
        TemplateHandler.add(template, "identifier", "_ic_" + declarationNode.getName());
        return template;
    }

    public void checkPredicate(PredicateNode predicate, List<DeclarationNode> declarations) {
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

    private void checkEnumerationPredicate(ExprNode lhs, DeclarationNode declarationNode) {
        if(!(lhs instanceof IdentifierExprNode) || !(((IdentifierExprNode) lhs).getName().equals(declarationNode.getName()))) {
            throw new RuntimeException("The expression on the left hand side of the first predicates must match the first identifier names");
        }
    }

    private ST getElementOfTemplate(DeclarationNode declarationNode, ExprNode lhs) {
        checkEnumerationPredicate(lhs, declarationNode);
        ST template = group.getInstanceOf("iteration_construct_enumeration");
        return generateEnumeration(template, declarationNode);
    }

    private ST getEqualTemplate(DeclarationNode declarationNode, ExprNode lhs) {
        checkEnumerationPredicate(lhs, declarationNode);
        ST template = group.getInstanceOf("iteration_construct_assignment");
        return generateEnumeration(template, declarationNode);
    }

    private ST getSubsetTemplate(DeclarationNode declarationNode, ExprNode lhs) {
        checkEnumerationPredicate(lhs, declarationNode);
        ST template = group.getInstanceOf("iteration_construct_subset");
        return generateEnumeration(template, declarationNode);
    }

    private ST getSubsetNeqTemplate(DeclarationNode declarationNode, ExprNode lhs) {
        checkEnumerationPredicate(lhs, declarationNode);
        ST template = group.getInstanceOf("iteration_construct_subsetneq");
        return generateEnumeration(template, declarationNode);
    }

    public List<ST> getEnumerationTemplates(IterationConstructGenerator iterationConstructGenerator, List<DeclarationNode> declarations, PredicateNode predicate) {
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
                enumerationTemplate = getElementOfTemplate(declarationNode, innerPredicate.getExpressionNodes().get(0));
                inLoop = true;
            } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL) {
                enumerationTemplate = getEqualTemplate(declarationNode, innerPredicate.getExpressionNodes().get(0));
                inLoop = false;
            } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.INCLUSION) {
                enumerationTemplate = getSubsetTemplate(declarationNode, innerPredicate.getExpressionNodes().get(0));
                inLoop = true;
            } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.STRICT_INCLUSION) {
                enumerationTemplate = getSubsetNeqTemplate(declarationNode, innerPredicate.getExpressionNodes().get(0));
                inLoop = true;
            } else {
                throw new RuntimeException("Other operations within predicate node not supported yet");
            }
            generateOtherIterationConstructs(iterationConstructGenerator, enumerationTemplate, innerPredicate);
            TemplateHandler.add(enumerationTemplate, "set", machineGenerator.visitExprNode(innerPredicate.getExpressionNodes().get(1), null));
            enumerationTemplates.add(enumerationTemplate);
        }
        return enumerationTemplates;
    }

    public ST evaluateEnumerationTemplates(List<ST> enumerationTemplates, String innerBody) {
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

    private void generateOtherIterationConstructs(IterationConstructGenerator iterationConstructGenerator, ST template, PredicateNode predicate) {
        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectPredicate(predicate);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());
    }

    public boolean isInLoop() {
        return inLoop;
    }

    public void reset() {
        inLoop = false;
    }

}
