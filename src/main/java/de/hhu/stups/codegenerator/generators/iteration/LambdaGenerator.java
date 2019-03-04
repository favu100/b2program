package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.ImportGenerator;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
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

    private final ImportGenerator importGenerator;

    private final TypeGenerator typeGenerator;

    public LambdaGenerator(final STGroup group, final MachineGenerator machineGenerator, final IterationConstructGenerator iterationConstructGenerator,
                                     final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator, final ImportGenerator importGenerator,
                                     final TypeGenerator typeGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
        this.importGenerator = importGenerator;
        this.typeGenerator = typeGenerator;
    }

    public String generateLambda(LambdaNode node) {
        PredicateNode predicate = node.getPredicate();
        List<DeclarationNode> declarations = node.getDeclarations();
        iterationConstructGenerator.addBoundedVariables(declarations);
        iterationPredicateGenerator.checkPredicate(predicate, declarations);
        ExprNode expression = node.getExpression();
        importGenerator.addImportInIteration(node.getType());

        ST template = group.getInstanceOf("lambda");

        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectExpression(
                iterationConstructHandler.inspectPredicate(predicate), expression);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }

        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());

        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(declarations, predicate);

        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String innerBody = generateLambdaExpression(predicate, expression, "_ic_set_" + iterationConstructCounter, "_ic_" + declarations.get(declarations.size() - 1).getName());
        String lambda = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();


        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(template, "identifier", "_ic_set_" + iterationConstructCounter);
        TemplateHandler.add(template, "lambda", lambda);
        String result = template.render();
        iterationConstructGenerator.addIteration(node.toString(), "_ic_set_"+ iterationConstructCounter, result);
        iterationConstructGenerator.clearBoundedVariables(declarations);
        return result;
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

}
