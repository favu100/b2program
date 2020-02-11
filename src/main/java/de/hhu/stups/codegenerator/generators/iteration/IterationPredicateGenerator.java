package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
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

    /*
    * This function replaces the placeholders for a bounded variable given by a DeclarationNode for the enumeration template of an iteration construct
    */
    public ST generateEnumeration(ST template, DeclarationNode declarationNode) {
        TemplateHandler.add(template, "type", typeGenerator.generate(declarationNode.getType()));
        TemplateHandler.add(template, "identifier", "_ic_" + declarationNode.getName() + "_" + machineGenerator.getIterationConstructDepth());
        return template;
    }

    /*
    * This function checks whether the predicate is a conjunction and whether first predicate declares a set to iterate over for a bounded variable
    */
    public void checkPredicate(PredicateNode predicate, List<DeclarationNode> declarations, boolean universalQuantification) {
        if(!(predicate instanceof PredicateOperatorNode)) {
            if(universalQuantification) {
                throw new CodeGenerationException("Predicate for universal quantification must contain an implication at top-level");
            }
            if(declarations.size() != 1) {
                throw new CodeGenerationException("Predicate for iteration must be a conjunction");
            }
        } else {
            PredicateOperatorNode predicateOperatorNode = ((PredicateOperatorNode) predicate);
            if(universalQuantification) {
                if(predicateOperatorNode.getOperator() != PredicateOperatorNode.PredicateOperator.IMPLIES) {
                    throw new CodeGenerationException("Predicate for universal quantification must contain an implicaton at top-level");
                }
                checkPredicate(predicateOperatorNode.getPredicateArguments().get(0), declarations, false);
            } else {
                if(predicateOperatorNode.getOperator() != PredicateOperatorNode.PredicateOperator.AND) {
                    throw new CodeGenerationException("Predicate for iteration must be a conjunction");
                }
                checkPredicateIteration(declarations, predicateOperatorNode);
            }
        }
    }

    /*
    * This function checks whether first predicate declares a set to iterate over for a bounded variable
    */
    private void checkPredicateIteration(List<DeclarationNode> declarations, PredicateOperatorNode predicate) {
        for(int i = 0; i < declarations.size(); i++) {
            PredicateNode innerPredicate = predicate.getPredicateArguments().get(i);
            if(!(innerPredicate instanceof PredicateOperatorWithExprArgsNode)) {
                throw new CodeGenerationException("First predicates must declare the set to iterate over");
            }
        }
    }

    /*
    * This function checks whether an identifier is on the left-hand side of a predicate and whether the i-th predicate constraints the i-th bounded variable.
    */
    private void checkEnumerationPredicate(ExprNode lhs, DeclarationNode declarationNode) {
        if(!(lhs instanceof IdentifierExprNode) || !(((IdentifierExprNode) lhs).getName().equals(declarationNode.getName()))) {
            throw new CodeGenerationException("The expression on the left-hand side of the first predicates must match the first identifier names");
        }
    }

    /*
    * This function returns the subpredicate of the last n conjuncts of the given predicate
    */
    public PredicateNode subpredicate(PredicateNode predicate, int n, boolean universalQuantification) {
        if(predicate instanceof PredicateOperatorWithExprArgsNode) {
            return subpredicate((PredicateOperatorWithExprArgsNode) predicate);
        } else if(predicate instanceof PredicateOperatorNode) {
            if(universalQuantification) {
                List<PredicateNode> subpredicates = new ArrayList<>();
                PredicateNode leftPredicate = ((PredicateOperatorNode) predicate).getPredicateArguments().get(0);
                PredicateNode rightPredicate = ((PredicateOperatorNode) predicate).getPredicateArguments().get(1);
                if(leftPredicate instanceof PredicateOperatorWithExprArgsNode || (leftPredicate instanceof PredicateOperatorNode && ((PredicateOperatorNode) leftPredicate).getPredicateArguments().size() <= n)) {
                    return rightPredicate;
                }
                subpredicates.add(subpredicate((PredicateOperatorNode) leftPredicate, n));
                subpredicates.add(rightPredicate);
                return new PredicateOperatorNode(predicate.getSourceCodePosition(), PredicateOperatorNode.PredicateOperator.IMPLIES, subpredicates);
            }
            return subpredicate((PredicateOperatorNode) predicate, n);
        }
        throw new RuntimeException("Given predicate is not supported");
    }

    /*
    * This function returns the subpredicate of the given predicate represented by a PredicateOperatorWithExprArgsNode. This predicate is empty.
    */
    private PredicateNode subpredicate(PredicateOperatorWithExprArgsNode predicate) {
        PredicateNode result = new PredicateOperatorNode(predicate.getSourceCodePosition(), PredicateOperatorNode.PredicateOperator.AND, new ArrayList<>());;
        result.setParent(predicate.getParent());
        result.setType(predicate.getType());
        return result;
    }

    /*
    * This function returns the subpredicate of the last n conjuncts of the given predicate represented by a PredicateOperatorNode.
    */
    private PredicateNode subpredicate(PredicateOperatorNode predicate, int n) {
        PredicateOperatorNode.PredicateOperator operator = predicate.getOperator();
        int size = predicate.getPredicateArguments().size();
        List<PredicateNode> predicates = predicate.getPredicateArguments().subList(n, size);
        PredicateNode result = new PredicateOperatorNode(predicate.getSourceCodePosition(), operator, predicates);
        result.setParent(predicate.getParent());
        result.setType(predicate.getType());
        return result;
    }

    /*
    * This function checks an enumeration with the given DeclarationNode and left-hand side of a predicate and then returns a template for an enumeration with element of as predicate.
    * The placeholders for the enumeration are already replaced but a template is returned because it must be evaluated later.
    */
    private ST getElementOfTemplate(DeclarationNode declarationNode, ExprNode lhs) {
        checkEnumerationPredicate(lhs, declarationNode);
        ST template = group.getInstanceOf("iteration_construct_enumeration");
        return generateEnumeration(template, declarationNode);
    }

    /*
    * This function checks an enumeration with the given DeclarationNode and left-hand side of a predicate and then returns a template for an enumeration with equal as predicate.
    * The placeholders for the enumeration are already replaced but a template is returned because it must be evaluated later.
    */
    private ST getEqualTemplate(DeclarationNode declarationNode, ExprNode lhs) {
        checkEnumerationPredicate(lhs, declarationNode);
        ST template = group.getInstanceOf("iteration_construct_assignment");
        return generateEnumeration(template, declarationNode);
    }

    /*
    * This function checks an enumeration with the given DeclarationNode and left-hand side of a predicate and then returns a template for an enumeration with subset as predicate.
    * The placeholders for the enumeration are already replaced but a template is returned because it must be evaluated later.
    */
    private ST getSubsetTemplate(DeclarationNode declarationNode, ExprNode lhs) {
        checkEnumerationPredicate(lhs, declarationNode);
        ST template = group.getInstanceOf("iteration_construct_subset");
        return generateEnumeration(template, declarationNode);
    }

    /*
    * This function checks an enumeration with the given DeclarationNode and left-hand side of a predicate and then returns a template for an enumeration with strict subset as predicate.
    * The placeholders for the enumeration are already replaced but a template is returned because it must be evaluated later.
    */
    private ST getSubsetNeqTemplate(DeclarationNode declarationNode, ExprNode lhs) {
        checkEnumerationPredicate(lhs, declarationNode);
        ST template = group.getInstanceOf("iteration_construct_subsetneq");
        return generateEnumeration(template, declarationNode);
    }

    /*
    * This function returns all templates for enumeration in the whole iteration construct from the given list of declarations representing bounded variables and the given predicate
    */
    public List<ST> getEnumerationTemplates(IterationConstructGenerator iterationConstructGenerator, List<DeclarationNode> declarations, PredicateNode predicate, boolean universalQuantification) {
        ST enumerationTemplate = null;
        List<ST> enumerationTemplates = new ArrayList<>();
        for(int i = 0; i < declarations.size(); i++) {
            DeclarationNode declarationNode = declarations.get(i);
            PredicateOperatorWithExprArgsNode innerPredicate = null;
            if(universalQuantification) {
                if(predicate instanceof PredicateOperatorWithExprArgsNode) {
                    innerPredicate = (PredicateOperatorWithExprArgsNode) predicate;
                } else if(predicate instanceof PredicateOperatorNode) {
                    if(((PredicateOperatorNode) predicate).getPredicateArguments().get(0) instanceof PredicateOperatorWithExprArgsNode) {
                       innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(0);
                    } else {
                        innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(0)).getPredicateArguments().get(i);
                    }
                }
            } else {
                innerPredicate = predicate instanceof PredicateOperatorWithExprArgsNode ? (PredicateOperatorWithExprArgsNode) predicate : (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(i);
            }
            enumerationTemplate = getEnumerationTemplate(declarationNode, innerPredicate);
            generateOtherIterationConstructs(iterationConstructGenerator, enumerationTemplate, innerPredicate);
            TemplateHandler.add(enumerationTemplate, "set", machineGenerator.visitExprNode(innerPredicate.getExpressionNodes().get(1), null));
            enumerationTemplates.add(enumerationTemplate);
        }
        return enumerationTemplates;
    }

    /*
    * This function returns an enumeration template for a declaration representing a bounded variable and the given predicate declaring an enumeration
    */
    private ST getEnumerationTemplate(DeclarationNode declaration, PredicateOperatorWithExprArgsNode innerPredicate) {
        ST enumerationTemplate = null;
        if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF) {
            enumerationTemplate = getElementOfTemplate(declaration, innerPredicate.getExpressionNodes().get(0));
            inLoop = true;
        } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL) {
            enumerationTemplate = getEqualTemplate(declaration, innerPredicate.getExpressionNodes().get(0));
            inLoop = false;
        } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.INCLUSION) {
            enumerationTemplate = getSubsetTemplate(declaration, innerPredicate.getExpressionNodes().get(0));
            inLoop = true;
        } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.STRICT_INCLUSION) {
            enumerationTemplate = getSubsetNeqTemplate(declaration, innerPredicate.getExpressionNodes().get(0));
            inLoop = true;
        } else {
            throw new RuntimeException("Other operations within predicate node are not supported");
        }
        return enumerationTemplate;
    }

    /*
    * This function gets a list of partly analyzed enumeration templates and a string for the inner part of the body for code generation. It then evaluates the given templates and reduced it to one template with replaced placeholders
    */
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

    /*
    * This function generates code for other iteration constructs in the predicate using for an iteration construct
    */
    private void generateOtherIterationConstructs(IterationConstructGenerator iterationConstructGenerator, ST template, PredicateNode predicate) {
        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectPredicate(predicate);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());
    }

}
