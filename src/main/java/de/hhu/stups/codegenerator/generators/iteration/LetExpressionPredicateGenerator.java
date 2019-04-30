package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.LetExpressionNode;
import de.prob.parser.ast.nodes.predicate.LetPredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.types.BType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.List;

/**
 * Created by fabian on 30.04.19.
 */
public class LetExpressionPredicateGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final TypeGenerator typeGenerator;

    private final IterationConstructGenerator iterationConstructGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final IterationPredicateGenerator iterationPredicateGenerator;


    public LetExpressionPredicateGenerator(final STGroup group, final MachineGenerator machineGenerator, final TypeGenerator typeGenerator, final IterationConstructGenerator iterationConstructGenerator,
                                           final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.typeGenerator = typeGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
    }

    public String generateLetExpression(LetExpressionNode node) {
        machineGenerator.inIterationConstruct();
        BType type = node.getType();
        PredicateNode predicate = node.getPredicate();
        ExprNode expression = node.getExpression();
        List<DeclarationNode> declarations = node.getLocalIdentifiers();

        ST template = group.getInstanceOf("let_expression_predicate");

        iterationConstructGenerator.prepareGeneration(predicate, declarations);

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String identifier = "_ic_let_"+ iterationConstructCounter;
        generateBody(template, identifier, type, predicate, expression, declarations);

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), identifier, declarations, result);

        machineGenerator.leaveIterationConstruct();
        return result;
    }

    public String generateLetPredicate(LetPredicateNode node) {
        machineGenerator.inIterationConstruct();
        BType type = node.getType();
        PredicateNode letPredicate = node.getWherePredicate();
        PredicateNode thenPredicate = node.getPredicate();
        List<DeclarationNode> declarations = node.getLocalIdentifiers();

        ST template = group.getInstanceOf("let_expression_predicate");

        iterationConstructGenerator.prepareGeneration(letPredicate, declarations);
        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String identifier = "_ic_let_"+ iterationConstructCounter;

        generateBody(template, identifier, type, letPredicate, thenPredicate, declarations);

        String result = template.render();

        iterationConstructGenerator.addGeneration(node.toString(), identifier, declarations, result);

        machineGenerator.leaveIterationConstruct();
        return result;
    }

    private String generateLetBody(String identifier, BType type, ExprNode exprNode) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("let_expression_predicate_body");
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "type", typeGenerator.generate(type));
        TemplateHandler.add(template, "val", machineGenerator.visitExprNode(exprNode, null));
        return template.render();
    }

    private String generateLetBody(String identifier, BType type, PredicateNode thenPredicateNode) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("let_expression_predicate_body");
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "type", typeGenerator.generate(type));
        TemplateHandler.add(template, "val", machineGenerator.visitPredicateNode(thenPredicateNode, null));
        return template.render();
    }

    private void generateBody(ST template, String identifier, BType type, PredicateNode letPredicate, PredicateNode thenPredicate, List<DeclarationNode> declarations) {
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(declarations, letPredicate);
        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);
        String innerBody = generateLetBody(identifier, type, thenPredicate);
        String body = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();
        TemplateHandler.add(template, "body", body);
    }

    private void generateBody(ST template, String identifier, BType type, PredicateNode predicate, ExprNode expression, List<DeclarationNode> declarations) {
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(declarations, predicate);
        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);
        String innerBody = generateLetBody(identifier, type, expression);
        String body = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();
        TemplateHandler.add(template, "body", body);
    }

}
