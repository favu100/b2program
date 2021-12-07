package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class InvariantGenerator {

    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final List<String> invariantFunctions;

    private int invariantCounter;

    public InvariantGenerator(final STGroup currentGroup, final MachineGenerator machineGenerator, final IterationConstructHandler iterationConstructHandler) {
        this.currentGroup = currentGroup;
        this.machineGenerator = machineGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.invariantFunctions = new ArrayList<>();
        this.invariantCounter = 0;
    }

    public List<PredicateNode> splitInvariant(PredicateNode predicate) {
        List<PredicateNode> predicates = new ArrayList<>();
        if(predicate instanceof PredicateOperatorNode) {
            PredicateOperatorNode predicateOperatorNode = (PredicateOperatorNode) predicate;
            if(predicateOperatorNode.getOperator() == PredicateOperatorNode.PredicateOperator.AND) {
                predicates.addAll(predicateOperatorNode.getPredicateArguments());
            } else {
                predicates.add(predicate);
            }
        } else {
            predicates.add(predicate);
        }
        return predicates;
    }

    public List<String> generateInvariants(PredicateNode predicateNode) {
        if((machineGenerator.isForModelChecking() || machineGenerator.isForVisualisation()) && !machineGenerator.isIncludedMachine()) {
            List<PredicateNode> conjuncts = splitInvariant(predicateNode);
            return conjuncts.stream().map(this::generateInvariant).collect(Collectors.toList());
        }
        return new ArrayList<>();
    }

    public String generateInvariant(PredicateNode predicate) {
        // TODO: Discard typing predicates
        invariantCounter++;
        String functionName = "_check_inv_" + invariantCounter;
        ST template = currentGroup.getInstanceOf("invariant");
        TemplateHandler.add(template, "invariantFunction", functionName);
        TemplateHandler.add(template, "iterationConstruct", iterationConstructHandler.inspectPredicate(predicate).getIterationsMapCode().values());
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicate, null));
        invariantFunctions.add(functionName);
        return template.render();
    }

    public List<String> getInvariantFunctions() {
        return invariantFunctions;
    }
}
