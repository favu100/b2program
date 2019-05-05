package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.analyzers.PrimedIdentifierAnalyzer;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.substitution.BecomesSuchThatSubstitutionNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by fabian on 28.04.19.
 */
public class BecomesSuchThatGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final TypeGenerator typeGenerator;

    private final IterationConstructGenerator iterationConstructGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final IterationPredicateGenerator iterationPredicateGenerator;


    public BecomesSuchThatGenerator(final STGroup group, final MachineGenerator machineGenerator, final TypeGenerator typeGenerator,
                                    final IterationConstructGenerator iterationConstructGenerator,
                                    final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.typeGenerator = typeGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
    }

    public String generateBecomesSuchThat(BecomesSuchThatSubstitutionNode node) {
        machineGenerator.inIterationConstruct();
        PredicateNode predicate = node.getPredicate();

        List<DeclarationNode> declarations = node.getIdentifiers()
                .stream()
                .map(IdentifierExprNode::getDeclarationNode)
                .collect(Collectors.toList());

        ST template = group.getInstanceOf("becomes_such_that");

        generateLoads(template, predicate);

        iterationConstructGenerator.prepareGeneration(predicate, declarations);
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(iterationConstructGenerator, declarations, predicate);
        Collection<String> otherConstructs = generateOtherIterationConstructs(predicate);

        generateBody(template, otherConstructs, enumerationTemplates, predicate, node.getIdentifiers());

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), declarations, result);

        machineGenerator.leaveIterationConstruct();
        return result;
    }

    private String generateBecomesSuchThatBody(Collection<String> otherConstructs, List<IdentifierExprNode> identifiers, PredicateNode predicateNode, boolean inLoop) {
        PredicateNode subpredicate = iterationPredicateGenerator.subpredicate(predicateNode, identifiers.size());
        ST template = group.getInstanceOf("becomes_such_that_body");
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructs);

        TemplateHandler.add(template, "emptyPredicate", ((PredicateOperatorNode) subpredicate).getPredicateArguments().size() == 0);
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(subpredicate, null));

        List<String> stores = identifiers.stream().map(this::generateStore).collect(Collectors.toList());
        TemplateHandler.add(template, "stores", stores);

        TemplateHandler.add(template, "inLoop", inLoop);
        return template.render();
    }

    private Collection<String> generateOtherIterationConstructs(PredicateNode predicate) {
        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.getNewIterationConstructGenerator();
        otherConstructsGenerator.getAllBoundedVariables().addAll(iterationConstructGenerator.getAllBoundedVariables());
        for (String key : iterationConstructGenerator.getIterationsMapIdentifier().keySet()) {
            otherConstructsGenerator.getIterationsMapIdentifier().put(key, iterationConstructGenerator.getIterationsMapIdentifier().get(key));
        }
        iterationConstructHandler.inspectPredicate(otherConstructsGenerator, predicate);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }
        return otherConstructsGenerator.getIterationsMapCode().values();
    }

    private void generateBody(ST template, Collection<String> otherConstructs, List<ST> enumerationTemplates, PredicateNode predicate, List<IdentifierExprNode> identifiers) {
        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);
        boolean inLoop = iterationPredicateGenerator.isInLoop();
        iterationPredicateGenerator.reset();
        String innerBody = generateBecomesSuchThatBody(otherConstructs, identifiers, predicate, inLoop);
        String body = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();
        TemplateHandler.add(template, "body", body);
    }

    private void generateLoads(ST template, PredicateNode predicate) {
        PrimedIdentifierAnalyzer primedAnalyzer = new PrimedIdentifierAnalyzer();
        primedAnalyzer.visitPredicateNode(predicate, null);
        List<String> loads = primedAnalyzer.getPrimedIdentifiers().stream().map(this::generateLoad).collect(Collectors.toList());
        TemplateHandler.add(template, "loads", loads);
    }

    private String generateLoad(IdentifierExprNode node) {
        IdentifierExprNode rhs = new IdentifierExprNode(node.getSourceCodePosition(), node.getName(), false);
        rhs.setDeclarationNode(node.getDeclarationNode());
        rhs.setType(node.getType());
        rhs.setParent(node.getParent());
        ST template = group.getInstanceOf("becomes_such_that_load");
        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(template, "lhs", machineGenerator.visitExprNode(node, null));
        TemplateHandler.add(template, "rhs", machineGenerator.visitExprNode(rhs, null));
        return template.render();
    }

    private String generateStore(IdentifierExprNode node) {
        ST template = group.getInstanceOf("becomes_such_that_store");
        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        int depth = machineGenerator.getIterationConstructDepth();
        machineGenerator.resetIterationConstruct();
        TemplateHandler.add(template, "lhs", machineGenerator.visitExprNode(node, null));
        machineGenerator.setIterationConstructDepth(depth);
        TemplateHandler.add(template, "rhs", machineGenerator.visitExprNode(node, null));
        return template.render();
    }
}
