package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.generators.ImportGenerator;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.CoupleType;
import de.prob.parser.ast.types.SetType;
import de.prob.parser.ast.types.UntypedType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.Collection;
import java.util.List;

import static de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode.QuantifiedExpressionOperator.PI;
import static de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode.QuantifiedExpressionOperator.SIGMA;

/**
 * Created by fabian on 06.03.19.
 */
public class QuantifiedExpressionGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final NameHandler nameHandler;

    private final TypeGenerator typeGenerator;

    private final ImportGenerator importGenerator;

    private final IterationConstructGenerator iterationConstructGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final IterationPredicateGenerator iterationPredicateGenerator;

    public QuantifiedExpressionGenerator(final STGroup group, final MachineGenerator machineGenerator, final NameHandler nameHandler, final TypeGenerator typeGenerator, final ImportGenerator importGenerator,
                                         final IterationConstructGenerator iterationConstructGenerator, final IterationConstructHandler iterationConstructHandler,
                                         final IterationPredicateGenerator iterationPredicateGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.nameHandler = nameHandler;
        this.typeGenerator = typeGenerator;
        this.importGenerator = importGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
    }

    /*
    * This function generates code for a quantified expression from the belonging AST node
    */
    public String generateQuantifiedExpression(PredicateNode conditionalPredicate, QuantifiedExpressionNode node) {
        machineGenerator.inIterationConstruct(node.getDeclarationList());
        PredicateNode predicate = node.getPredicateNode();
        List<DeclarationNode> declarations = node.getDeclarationList();
        ExprNode expression = node.getExpressionNode();
        BType type = node.getType();
        ST template = group.getInstanceOf("quantified_expression");

        iterationConstructGenerator.prepareGeneration(predicate, declarations, type, false);
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(iterationConstructGenerator, declarations, predicate, false);
        Collection<String> otherConstructs = generateOtherIterationConstructs(predicate, expression);

        QuantifiedExpressionNode.QuantifiedExpressionOperator operator = node.getOperator();
        boolean isInteger = !(operator == QuantifiedExpressionNode.QuantifiedExpressionOperator.QUANTIFIED_UNION) && !(operator == QuantifiedExpressionNode.QuantifiedExpressionOperator.QUANTIFIED_INTER);
        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String prefix = machineGenerator.getMode().equals(GeneratorMode.PL) ? "" : "_";
        String identifier = isInteger ? prefix + "ic_integer_" + iterationConstructCounter : prefix + "ic_set_"+ iterationConstructCounter;

        boolean isRelation = false;

        if(node.getType() instanceof SetType) {
            BType subType = ((SetType) node.getType()).getSubType();
            if(subType instanceof CoupleType) {
                isRelation = true;
            }
        }

        if(isRelation) {
            importGenerator.addImport(new SetType(new CoupleType(new UntypedType(), new UntypedType())));
        } else {
            importGenerator.addImport(new SetType(new UntypedType()));
        }

        generateBody(template, enumerationTemplates, otherConstructs, identifier, isRelation, node, conditionalPredicate, predicate, expression, declarations);
        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), identifier, declarations, result);
        machineGenerator.leaveIterationConstruct(node.getDeclarationList());
        return result;
    }

    /*
    * This function generates code for the identity element from the belonging operator
    */
    private String getIdentity(QuantifiedExpressionNode.QuantifiedExpressionOperator operator) {
        String identity = "";
        if(operator == SIGMA) {
            identity = "0";
        } else if(operator == PI) {
            identity = "1";
        }
        return identity;
    }

    /*
    * This function generates code for the given operator of a quantified expression
    */
    private String getOperation(QuantifiedExpressionNode.QuantifiedExpressionOperator operator) {
        boolean isInteger = !(operator == QuantifiedExpressionNode.QuantifiedExpressionOperator.QUANTIFIED_UNION) && !(operator == QuantifiedExpressionNode.QuantifiedExpressionOperator.QUANTIFIED_INTER);
        String operation;
        if(isInteger) {
            if(operator == SIGMA) {
                operation = "plus";
            } else {
                operation = "multiply";
            }
        } else {
            if(operator == QuantifiedExpressionNode.QuantifiedExpressionOperator.QUANTIFIED_UNION) {
                operation = "union";
            } else {
                operation = "intersect";
            }
        }
        return nameHandler.handle(operation);
    }

    /*
    * This function generates code for other iteration constructs used within the quantified expression
    */
    private Collection<String> generateOtherIterationConstructs(PredicateNode predicate, ExprNode expression) {
        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.getNewIterationConstructGenerator();
        otherConstructsGenerator.getAllBoundedVariables().addAll(iterationConstructGenerator.getAllBoundedVariables());
        for (String key : iterationConstructGenerator.getIterationsMapIdentifier().keySet()) {
            otherConstructsGenerator.getIterationsMapIdentifier().put(key, iterationConstructGenerator.getIterationsMapIdentifier().get(key));
        }
        iterationConstructHandler.inspectExpression(iterationConstructHandler.inspectPredicate(otherConstructsGenerator, predicate), expression);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }
        return otherConstructsGenerator.getIterationsMapCode().values();
    }

    /*
    * This function generates code for the body of the quantified expression
    */
    private void generateBody(ST template, List<ST> enumerationTemplates, Collection<String> otherConstructs, String identifier, boolean isRelation, QuantifiedExpressionNode node, PredicateNode conditionalPredicate, PredicateNode predicate, ExprNode expression, List<DeclarationNode> declarations) {
        QuantifiedExpressionNode.QuantifiedExpressionOperator operator = node.getOperator();
        boolean isInteger = !(operator == QuantifiedExpressionNode.QuantifiedExpressionOperator.QUANTIFIED_UNION) && !(operator == QuantifiedExpressionNode.QuantifiedExpressionOperator.QUANTIFIED_INTER);

        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);

        String innerBody = generateQuantifiedExpressionEvaluation(otherConstructs, conditionalPredicate, predicate, identifier, getOperation(operator), expression, declarations);
        String evaluation = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody, conditionalPredicate).render();

        TemplateHandler.add(template, "isJavaScript", machineGenerator.getMode() == GeneratorMode.JS);
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "identity", getIdentity(operator));
        TemplateHandler.add(template, "useBigInteger", machineGenerator.isUseBigInteger());
        generateSubType(template, node);
        TemplateHandler.add(template, "isInteger", isInteger);
        TemplateHandler.add(template, "isRelation", isRelation);
        TemplateHandler.add(template, "evaluation", evaluation);
    }

    /*
    * This function generates code for the evaluation of the quantified expression
    */
    private String generateQuantifiedExpressionEvaluation(Collection<String> otherConstructs, PredicateNode conditionalPredicate, PredicateNode predicateNode, String identifier, String operation, ExprNode expression, List<DeclarationNode> declarations) {
        PredicateNode subpredicate = iterationPredicateGenerator.subpredicate(predicateNode, declarations, false);
        ST template = group.getInstanceOf("quantified_expression_evaluation");
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructs);
        TemplateHandler.add(template, "emptyPredicate", subpredicate == null || ((PredicateOperatorNode) subpredicate).getPredicateArguments().size() == 0);
        TemplateHandler.add(template, "hasCondition", conditionalPredicate != null);
        if(conditionalPredicate != null) {
            TemplateHandler.add(template, "conditionalPredicate", machineGenerator.visitPredicateNode(conditionalPredicate, null));
        }
        if(subpredicate != null) {
            TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(subpredicate, null));
        }
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "operation", operation);
        TemplateHandler.add(template, "expression", machineGenerator.visitExprNode(expression, null));
        return template.render();
    }

    /*
     * This function generates code for the type of the set comprehension from the given semantic information
     */
    private void generateSubType(ST template, QuantifiedExpressionNode node) {
        if(node.getType() instanceof SetType) {
            SetType setType = (SetType) node.getType();
            BType subType = setType.getSubType();
            if (subType instanceof CoupleType) {
                BType leftType = ((CoupleType) subType).getLeft();
                BType rightType = ((CoupleType) subType).getRight();
                TemplateHandler.add(template, "leftType", typeGenerator.generate(leftType));
                TemplateHandler.add(template, "rightType", typeGenerator.generate(rightType));
            } else {
                TemplateHandler.add(template, "subType", typeGenerator.generate(subType));
            }
        }
    }

    /*
     * This function extracts the couple type from a list of declarations
     */
    private CoupleType extractTypeFromDeclarations(List<DeclarationNode> declarations) {
        CoupleType result = new CoupleType(declarations.get(0).getType(), declarations.get(1).getType());
        for(int i = 2; i < declarations.size(); i++) {
            result = new CoupleType(result, declarations.get(i).getType());
        }
        return result;
    }

}
