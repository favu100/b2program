package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.SourceCodePosition;
import de.prob.parser.ast.nodes.Node;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import de.prob.parser.ast.nodes.predicate.QuantifiedPredicateNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


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
        String prefix = machineGenerator.getMode().equals(GeneratorMode.PL) ? "PL" : "";
        TemplateHandler.add(template, "identifier", prefix + "_ic_" + declarationNode.getName() + "_" + machineGenerator.getBoundedVariablesDepth().get(declarationNode.getName()));
        return template;
    }

    /*
    * This function checks whether the predicate is a conjunction and whether first predicate declares a set to iterate over for a bounded variable
    */
    public void checkPredicate(PredicateNode predicate, List<DeclarationNode> declarations, boolean universalQuantification) {
        if(!(predicate instanceof PredicateOperatorNode)) {
            if(universalQuantification) {
                throw new CodeGenerationException("Predicate for universal quantification must contain an implication at top-level " + GetNodeLocationAndText(predicate));
            }
            if(declarations.size() != 1) {
                throw new CodeGenerationException("Predicate for iteration must be a conjunction " + GetNodeLocationAndText(predicate));
            }
        } else {
            PredicateOperatorNode predicateOperatorNode = ((PredicateOperatorNode) predicate);
            if(universalQuantification) {
                if(predicateOperatorNode.getOperator() != PredicateOperatorNode.PredicateOperator.IMPLIES) {
                    throw new CodeGenerationException("Predicate for universal quantification must contain an implicaton at top-level " + GetNodeLocationAndText(predicate));
                }
                checkPredicate(predicateOperatorNode.getPredicateArguments().get(0), declarations, false);
            } else {
                if(predicateOperatorNode.getOperator() != PredicateOperatorNode.PredicateOperator.AND) {
                    throw new CodeGenerationException("Predicate for iteration must be a conjunction " + GetNodeLocationAndText(predicate));
                }
                checkPredicateIteration(declarations, predicateOperatorNode);
            }
        }
    }

    /*
    * This function checks whether first predicate declares a set to iterate over for a bounded variable
    */
    private void checkPredicateIteration(List<DeclarationNode> declarations, PredicateOperatorNode predicate) {
        if(predicate.getPredicateArguments().size() < declarations.size()) {
            throw new CodeGenerationException("For n bounded variables, the i-th predicate must constrain the i-th variable for each i from 1 to n.\nThe failed predicate is " +  GetNodeLocationAndText(predicate));
        }
        for(int i = 0; i < declarations.size(); i++) {
            PredicateNode innerPredicate = predicate.getPredicateArguments().get(i);
            if(!(innerPredicate instanceof PredicateOperatorWithExprArgsNode)) {
                throw new CodeGenerationException("For n bounded variables, the i-th predicate must constrain the i-th variable for each i from 1 to n.\nThe failed predicate is " + GetNodeLocationAndText(innerPredicate));
            }
        }
    }

    private boolean checkEnumerationPredicateAsBoolean(ExprNode lhs, Set<String> declarationProcessed, DeclarationNode declarationNode) {
        if(declarationProcessed.contains(((IdentifierExprNode) lhs).getName())) {
            return true;
        }
        if(!((IdentifierExprNode) lhs).getName().equals(declarationNode.getName())) {
            return false;
        }
        return true;
    }

    public PredicateNode subpredicate(PredicateNode predicate, List<DeclarationNode> declarations, boolean universalQuantification) {
        List<PredicateNode> subpredicates = new ArrayList<>();
        Set<String> declarationProcessed = new HashSet<>();
        int j = 0;
        int subpredicateIndex = 0;
        for(int i = 0; i < declarations.size(); i++, j++) {
            DeclarationNode declarationNode = declarations.get(i);
            PredicateOperatorWithExprArgsNode innerPredicate = null;
            if(universalQuantification) {
                if(predicate instanceof PredicateOperatorWithExprArgsNode) {
                    innerPredicate = (PredicateOperatorWithExprArgsNode) predicate;
                } else if(predicate instanceof PredicateOperatorNode) {
                    if(((PredicateOperatorNode) predicate).getPredicateArguments().get(0) instanceof PredicateOperatorWithExprArgsNode) {
                        innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(0);
                    } else {
                        innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(0)).getPredicateArguments().get(j);
                    }
                }
            } else {
                if(predicate instanceof PredicateOperatorWithExprArgsNode) {
                    innerPredicate = (PredicateOperatorWithExprArgsNode) predicate;
                } else {
                    if(j < ((PredicateOperatorNode) predicate).getPredicateArguments().size()) {
                        innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(j);
                    } else {
                        subpredicateIndex = Math.max(j-1, subpredicateIndex);
                        break;
                    }
                }
            }
            ST enumerationTemplate = getEnumerationTemplate(declarationNode, declarationProcessed, innerPredicate);
            if(enumerationTemplate == null) {
                i = i - 1;
                subpredicateIndex = Math.max(j-1, subpredicateIndex);
                continue;
            }
            declarationProcessed.add(declarationNode.getName());

        }
        PredicateNode subpredicate = subpredicate(predicate, subpredicateIndex, universalQuantification);
        if(subpredicate == null) {
            return null;
        }
        subpredicates.add(subpredicate);
        return new PredicateOperatorNode(predicate.getSourceCodePosition(), PredicateOperatorNode.PredicateOperator.AND, subpredicates);
    }

    /*
    * This function returns the subpredicate of the last n conjuncts of the given predicate
    */
    private PredicateNode subpredicate(PredicateNode predicate, int n, boolean universalQuantification) {
        if(predicate instanceof PredicateOperatorWithExprArgsNode) {
            return null;
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
        throw new RuntimeException("Given predicate is not supported" + GetNodeLocationAndText(predicate));
    }
   
    // todo: probably move this somewhere else so that we can use it for other error messages
    public static String GetNodeLocationAndText (Node node) {
      return 
            "at line " + node.getSourceCodePosition().getStartLine() + 
            " and column " + node.getSourceCodePosition().getStartColumn() + 
            ": " + node.getSourceCodePosition().getText();
    }

    /*
    * This function returns the subpredicate of the last n conjuncts of the given predicate represented by a PredicateOperatorNode.
    */
    private PredicateNode subpredicate(PredicateOperatorNode predicate, int n) {
        PredicateOperatorNode.PredicateOperator operator = predicate.getOperator();
        int size = predicate.getPredicateArguments().size();
        if(n > predicate.getPredicateArguments().size()) {
            return null;
        }
        List<PredicateNode> predicates = predicate.getPredicateArguments().subList(n, size);
        if(predicates.isEmpty()) {
            return null;
        }
        PredicateNode result = new PredicateOperatorNode(predicate.getSourceCodePosition(), operator, predicates);
        result.setParent(predicate.getParent());
        result.setType(predicate.getType());
        return result;
    }

    /*
    * This function checks an enumeration with the given DeclarationNode and left-hand side of a predicate and then returns a template for an enumeration with element of as predicate.
    * The placeholders for the enumeration are already replaced but a template is returned because it must be evaluated later.
    */
    private ST getElementOfTemplate(DeclarationNode declarationNode, Set<String> declarationProcessed, ExprNode lhs) {
        if(!(lhs instanceof IdentifierExprNode) || declarationProcessed.contains(((IdentifierExprNode) lhs).getName())) {
            return null;
        }
        ST template = group.getInstanceOf("iteration_construct_enumeration");
        return generateEnumeration(template, declarationNode);
    }

    /*
    * This function checks an enumeration with the given DeclarationNode and left-hand side of a predicate and then returns a template for an enumeration with equal as predicate.
    * The placeholders for the enumeration are already replaced but a template is returned because it must be evaluated later.
    */
    private ST getEqualTemplate(DeclarationNode declarationNode, Set<String> declarationProcessed, ExprNode lhs) {
        if(!(lhs instanceof IdentifierExprNode) || declarationProcessed.contains(((IdentifierExprNode) lhs).getName())) {
            return null;
        }
        ST template = group.getInstanceOf("iteration_construct_assignment");
        return generateEnumeration(template, declarationNode);
    }

    /*
    * This function checks an enumeration with the given DeclarationNode and left-hand side of a predicate and then returns a template for an enumeration with subset as predicate.
    * The placeholders for the enumeration are already replaced but a template is returned because it must be evaluated later.
    */
    private ST getSubsetTemplate(DeclarationNode declarationNode, Set<String> declarationProcessed, ExprNode lhs) {
        if(!(lhs instanceof IdentifierExprNode) || declarationProcessed.contains(((IdentifierExprNode) lhs).getName())) {
            return null;
        }
        ST template = group.getInstanceOf("iteration_construct_subset");
        return generateEnumeration(template, declarationNode);
    }

    /*
    * This function checks an enumeration with the given DeclarationNode and left-hand side of a predicate and then returns a template for an enumeration with strict subset as predicate.
    * The placeholders for the enumeration are already replaced but a template is returned because it must be evaluated later.
    */
    private ST getSubsetNeqTemplate(DeclarationNode declarationNode, Set<String> declarationProcessed, ExprNode lhs) {
        if(!(lhs instanceof IdentifierExprNode) || declarationProcessed.contains(((IdentifierExprNode) lhs).getName())) {
            return null;
        }
        ST template = group.getInstanceOf("iteration_construct_subsetneq");
        return generateEnumeration(template, declarationNode);
    }

    /*
    * 1. Implement functions to check whether this is a predicate which assigns a declaration node
    * 2. Sort declaration nodes
    * 3. Use sorted declaration nodes instead
    */
    /*
    * This function returns all templates for enumeration in the whole iteration construct from the given list of declarations representing bounded variables and the given predicate
    */
    public List<ST> getEnumerationTemplates(IterationConstructGenerator iterationConstructGenerator, List<DeclarationNode> declarations, PredicateNode predicate, boolean universalQuantification) {
        ST enumerationTemplate = null;
        List<ST> enumerationTemplates = new ArrayList<>();
        List<DeclarationNode> sortedDeclarations = this.sortDeclarationNodes(declarations, predicate, universalQuantification);
        Set<String> declarationProcessed = new HashSet<>();

        for(int i = 0, j = 0; i < sortedDeclarations.size(); i++, j++) {
            DeclarationNode declarationNode = sortedDeclarations.get(i);
            PredicateOperatorWithExprArgsNode innerPredicate = null;
            if(universalQuantification) {
                if(predicate instanceof PredicateOperatorWithExprArgsNode) {
                    innerPredicate = (PredicateOperatorWithExprArgsNode) predicate;
                } else if(predicate instanceof PredicateOperatorNode) {
                    if(((PredicateOperatorNode) predicate).getPredicateArguments().get(0) instanceof PredicateOperatorWithExprArgsNode) {
                       innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(0);
                    } else {
                        innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(0)).getPredicateArguments().get(j);
                    }
                }
            } else {
                innerPredicate = predicate instanceof PredicateOperatorWithExprArgsNode ? (PredicateOperatorWithExprArgsNode) predicate
                        : (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(j);
            }
            enumerationTemplate = getEnumerationTemplate(declarationNode, declarationProcessed, innerPredicate);
            if(enumerationTemplate == null) {
                i = i - 1;
                enumerationTemplate = group.getInstanceOf("iteration_construct_pruning");
                TemplateHandler.add(enumerationTemplate, "predicate", machineGenerator.visitPredicateNode(innerPredicate, null));
                enumerationTemplates.add(enumerationTemplate);
                continue;
            }
            generateOtherIterationConstructs(iterationConstructGenerator, enumerationTemplate, innerPredicate);
            TemplateHandler.add(enumerationTemplate, "set", machineGenerator.visitExprNode(innerPredicate.getExpressionNodes().get(1), null));
            enumerationTemplates.add(enumerationTemplate);
            declarationProcessed.add(declarationNode.getName());
        }
        return enumerationTemplates;
    }

    private List<DeclarationNode> sortDeclarationNodes(List<DeclarationNode> declarations, PredicateNode predicateNode, boolean universalQuantification) {
        List<DeclarationNode> result = new ArrayList<>();
        Set<String> declarationProcessed = new HashSet<>();
        int i = 0;
        while(i < declarations.size() && declarations.size() != declarationProcessed.size()) {
            DeclarationNode nextDeclaration = getNextDeclarationInEnumerationPredicate(declarations, declarationProcessed, predicateNode, universalQuantification);
            if(nextDeclaration == null) {
                throw new RuntimeException("There are not enough predicates to constraint bounded variables at: " + "line: " + predicateNode.getSourceCodePosition().getStartLine() + " column: " + predicateNode.getSourceCodePosition().getStartColumn());
            }
            result.add(nextDeclaration);
            declarationProcessed.add(nextDeclaration.getName());
            i++;
        }
        return result;
    }

    private DeclarationNode getNextDeclarationInEnumerationPredicate(List<DeclarationNode> declarations, Set<String> declarationProcessed, PredicateNode predicate, boolean universalQuantification) {
        PredicateNode innerPredicate = null;
        int numberConjuncts = 0;
        if(universalQuantification) {
            if(predicate instanceof PredicateOperatorWithExprArgsNode) {
                numberConjuncts = 1;
            } else if(predicate instanceof PredicateOperatorNode) {
                if(((PredicateOperatorNode) predicate).getPredicateArguments().get(0) instanceof PredicateOperatorWithExprArgsNode) {
                    numberConjuncts = 1;
                } else {
                    numberConjuncts = ((PredicateOperatorNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(0)).getPredicateArguments().size();
                }
            }
        } else {
            numberConjuncts = predicate instanceof PredicateOperatorWithExprArgsNode ? 1
                    : predicate instanceof QuantifiedPredicateNode ? 1
                    : ((PredicateOperatorNode) predicate).getPredicateArguments().size();
        }

        for(int i = 0; i < numberConjuncts; i++) {
            if(universalQuantification) {
                if(predicate instanceof PredicateOperatorWithExprArgsNode) {
                    innerPredicate = (PredicateOperatorWithExprArgsNode) predicate;
                } else {
                    if(((PredicateOperatorNode) predicate).getPredicateArguments().get(0) instanceof PredicateOperatorWithExprArgsNode) {
                        innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(0);
                    } else {
                        innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(0)).getPredicateArguments().get(i);
                    }
                }
            } else {
                if(predicate instanceof PredicateOperatorWithExprArgsNode) {
                    innerPredicate = (PredicateOperatorWithExprArgsNode) predicate;
                } else if(predicate instanceof QuantifiedPredicateNode) {
                    innerPredicate = (QuantifiedPredicateNode) predicate;
                } else {
                    innerPredicate = (PredicateOperatorWithExprArgsNode) ((PredicateOperatorNode) predicate).getPredicateArguments().get(i);
                }
            }
            for(DeclarationNode declaration : declarations) {
                if(innerPredicate instanceof PredicateOperatorWithExprArgsNode) {
                    PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = ((PredicateOperatorWithExprArgsNode) innerPredicate).getOperator();
                    if (operator == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF ||
                            operator == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL ||
                            operator == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.INCLUSION ||
                            operator == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.STRICT_INCLUSION) {
                        ExprNode lhs = ((PredicateOperatorWithExprArgsNode) innerPredicate).getExpressionNodes().get(0);
                        if (lhs instanceof IdentifierExprNode && !declarationProcessed.contains(((IdentifierExprNode) lhs).getName())) {
                            if (declaration.getName().equals(((IdentifierExprNode) lhs).getName())) {
                                return declaration;
                            }
                        }
                    }
                }
            }
        }

        return null;
    }

    /*
    * This function returns an enumeration template for a declaration representing a bounded variable and the given predicate declaring an enumeration
    */
    private ST getEnumerationTemplate(DeclarationNode declaration, Set<String> declarationProcessed, PredicateOperatorWithExprArgsNode innerPredicate) {
        ST enumerationTemplate = null;
        if(innerPredicate == null) {
            return null;
        }
        if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF) {
            enumerationTemplate = getElementOfTemplate(declaration, declarationProcessed, innerPredicate.getExpressionNodes().get(0));
            inLoop = true;
        } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL) {
            enumerationTemplate = getEqualTemplate(declaration, declarationProcessed, innerPredicate.getExpressionNodes().get(0));
            inLoop = false;
        } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.INCLUSION) {
            enumerationTemplate = getSubsetTemplate(declaration, declarationProcessed, innerPredicate.getExpressionNodes().get(0));
            inLoop = true;
        } else if(innerPredicate.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.STRICT_INCLUSION) {
            enumerationTemplate = getSubsetNeqTemplate(declaration, declarationProcessed, innerPredicate.getExpressionNodes().get(0));
            inLoop = true;
        } else {
            return null;
            //throw new RuntimeException("Only =,:,<:,<<: operators are supported within the enumeration predicate " +
            //                           GetNodeLocationAndText(innerPredicate));
        }
        return enumerationTemplate;
    }

    /*
    * This function gets a list of partly analyzed enumeration templates and a string for the inner part of the body for code generation. It then evaluates the given templates and reduced it to one template with replaced placeholders
    */
    public ST evaluateEnumerationTemplates(List<ST> enumerationTemplates, String innerBody, PredicateNode conditionalPredicate) {
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

        TemplateHandler.add(lastEnumeration, "hasCondition", conditionalPredicate != null);
        if(conditionalPredicate != null) {
            TemplateHandler.add(lastEnumeration, "conditionalPredicate", machineGenerator.visitPredicateNode(conditionalPredicate, null));
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
