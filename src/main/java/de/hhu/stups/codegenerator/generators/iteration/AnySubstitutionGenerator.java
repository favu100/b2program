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

    /*
    * This function generates code for the ANY substitution from the belonging AST node
    */
    public String generateAnySubstitution(AnySubstitutionNode node) {
        machineGenerator.inIterationConstruct(node.getParameters());
        PredicateNode predicate = node.getWherePredicate();
        SubstitutionNode substitution = node.getThenSubstitution();
        List<DeclarationNode> declarations = node.getParameters();

        ST template = group.getInstanceOf("any");

        iterationConstructGenerator.prepareGeneration(predicate, declarations, false);
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(iterationConstructGenerator, declarations, predicate, false);
        Collection<String> otherConstructs = generateOtherIterationConstructs(predicate);

        generateBody(template, otherConstructs, enumerationTemplates, predicate, substitution, declarations.size());

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), declarations, result);

        machineGenerator.leaveIterationConstruct(node.getParameters());
        return result;
    }

    /*
    * This function generates code for the inner body of the ANY substitution
    */
    private String generateAnyBody(Collection<String> otherConstructs, PredicateNode predicateNode, SubstitutionNode substitutionNode, int numberDeclarations) {
        PredicateNode subpredicate = iterationPredicateGenerator.subpredicate(predicateNode, numberDeclarations, false);
        ST template = group.getInstanceOf("any_body");
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructs);
        TemplateHandler.add(template, "emptyPredicate", ((PredicateOperatorNode) subpredicate).getPredicateArguments().size() == 0);
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(subpredicate, null));
        TemplateHandler.add(template, "body", machineGenerator.visitSubstitutionNode(substitutionNode, null));
        return template.render();
    }

    /*
    * This function generates code for other iteration constructs within the ANY substitution from the given predicate
    */
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

    /*
    * This function generates code for the body of the ANY substitution
    */
    private void generateBody(ST template, Collection<String> otherConstructs, List<ST> enumerationTemplates, PredicateNode predicate, SubstitutionNode substitution, int numberDeclarations) {
        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);
        String innerBody = generateAnyBody(otherConstructs, predicate, substitution, numberDeclarations);
        String body = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();
        TemplateHandler.add(template, "body", body);
    }

}
