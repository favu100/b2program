package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.CoupleType;
import de.prob.parser.ast.types.SetType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.List;

/**
 * Created by fabian on 04.03.19.
 */
public class LambdaGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final IterationConstructGenerator iterationConstructGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final IterationPredicateGenerator iterationPredicateGenerator;

    private final TypeGenerator typeGenerator;

    public LambdaGenerator(final STGroup group, final MachineGenerator machineGenerator, final IterationConstructGenerator iterationConstructGenerator,
                                     final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator,
                                     final TypeGenerator typeGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
        this.typeGenerator = typeGenerator;
    }

    public String generateLambda(LambdaNode node) {
        PredicateNode predicate = node.getPredicate();
        List<DeclarationNode> declarations = node.getDeclarations();
        ExprNode expression = node.getExpression();
        BType type = node.getType();

        iterationConstructGenerator.prepareGeneration(predicate, declarations, type);

        ST template = group.getInstanceOf("lambda");
        generateOtherIterationConstructs(template, predicate, expression);

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String identifier = "_ic_set_" + iterationConstructCounter;

        CoupleType coupleType = (CoupleType) ((SetType) node.getType()).getSubType();
        String leftType = typeGenerator.generate(coupleType.getLeft());
        String rightType = typeGenerator.generate(coupleType.getRight());

        generateBody(template, identifier, predicate, leftType, rightType, declarations, expression, type);

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), identifier, declarations, result);
        return result;
    }

    private void generateOtherIterationConstructs(ST template, PredicateNode predicate, ExprNode expression) {
        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectExpression(
                iterationConstructHandler.inspectPredicate(predicate), expression);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());
    }

    private void generateBody(ST template, String identifier, PredicateNode predicate, String leftType, String rightType, List<DeclarationNode> declarations, ExprNode expression, BType type) {
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(declarations, predicate);

        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);



        String innerBody = generateLambdaExpression(predicate, leftType, rightType, expression, identifier, "_ic_" + declarations.get(declarations.size() - 1).getName());
        String lambda = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();

        TemplateHandler.add(template, "type", typeGenerator.generate(type));
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "lambda", lambda);
    }

    public String generateLambdaExpression(PredicateNode predicateNode, String leftType, String rightType, ExprNode expression, String relationName, String elementName) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("lambda_expression");
        machineGenerator.inIterationConstruct();
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(template, "leftType", leftType);
        TemplateHandler.add(template, "rightType", rightType);
        TemplateHandler.add(template, "relation", relationName);
        TemplateHandler.add(template, "element", elementName);
        TemplateHandler.add(template, "expression", machineGenerator.visitExprNode(expression, null));
        machineGenerator.leaveIterationConstruct();
        return template.render();
    }

}
