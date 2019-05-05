package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.substitution.AnySubstitutionNode;
import de.prob.parser.ast.nodes.substitution.SubstitutionNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.Collection;
import java.util.List;

/**
 * Created by fabian on 28.04.19.
 */
public class AnySubstitutionGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final IterationConstructGenerator iterationConstructGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final IterationPredicateGenerator iterationPredicateGenerator;


    public AnySubstitutionGenerator(final STGroup group, final MachineGenerator machineGenerator, final IterationConstructGenerator iterationConstructGenerator,
                                     final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
    }

    public String generateAnySubstitution(AnySubstitutionNode node) {
        machineGenerator.inIterationConstruct();
        PredicateNode predicate = node.getWherePredicate();
        SubstitutionNode substitution = node.getThenSubstitution();
        List<DeclarationNode> declarations = node.getParameters();

        ST template = group.getInstanceOf("any");

        iterationConstructGenerator.prepareGeneration(predicate, declarations);
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(iterationConstructGenerator, declarations, predicate);
        Collection<String> otherConstructs = generateOtherIterationConstructs(predicate);

        generateBody(template, otherConstructs, enumerationTemplates, predicate, substitution, declarations.size());

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), declarations, result);

        machineGenerator.leaveIterationConstruct();
        return result;
    }

    private String generateAnyBody(Collection<String> otherConstructs, PredicateNode predicateNode, SubstitutionNode substitutionNode, boolean inLoop, int numberDeclarations) {
        PredicateNode subpredicate = iterationPredicateGenerator.subpredicate(predicateNode, numberDeclarations);
        ST template = group.getInstanceOf("any_body");
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructs);
        TemplateHandler.add(template, "emptyPredicate", ((PredicateOperatorNode) subpredicate).getPredicateArguments().size() == 0);
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(subpredicate, null));
        TemplateHandler.add(template, "body", machineGenerator.visitSubstitutionNode(substitutionNode, null));
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

    private void generateBody(ST template, Collection<String> otherConstructs, List<ST> enumerationTemplates, PredicateNode predicate, SubstitutionNode substitution, int numberDeclarations) {
        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);
        boolean inLoop = iterationPredicateGenerator.isInLoop();
        iterationPredicateGenerator.reset();
        String innerBody = generateAnyBody(otherConstructs, predicate, substitution, inLoop, numberDeclarations);
        String body = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();
        TemplateHandler.add(template, "body", body);
    }

}
