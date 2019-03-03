package de.hhu.stups.codegenerator.handlers;

import de.hhu.stups.codegenerator.generators.ImportGenerator;
import de.hhu.stups.codegenerator.generators.IterationConstructGenerator;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import org.stringtemplate.v4.STGroup;

import java.util.HashMap;
import java.util.List;

/**
 * Created by fabian on 06.02.19.
 */
public class IterationConstructHandler {

    private IterationConstructGenerator currentIterationConstructGenerator;

    private int iterationConstructCounter;

    private final MachineGenerator machineGenerator;

    private final TypeGenerator typeGenerator;

    private final ImportGenerator importGenerator;

    private final STGroup group;

    public IterationConstructHandler(final STGroup group, final MachineGenerator machineGenerator, final TypeGenerator typeGenerator,
                                     final ImportGenerator importGenerator) {
        this.currentIterationConstructGenerator = null;
        this.iterationConstructCounter = 0;
        this.machineGenerator = machineGenerator;
        this.typeGenerator = typeGenerator;
        this.importGenerator = importGenerator;
        this.group = group;
    }

    public void setIterationConstructGenerator(IterationConstructGenerator iterationConstructGenerator) {
        this.currentIterationConstructGenerator = iterationConstructGenerator;
    }

    public int getIterationConstructCounter() {
        return iterationConstructCounter;
    }

    public void incrementIterationConstructCounter() {
        iterationConstructCounter++;
    }

    public IterationConstructGenerator inspectPredicate(IterationConstructGenerator iterationConstructGenerator, PredicateNode predicate) {
        iterationConstructGenerator.visitPredicateNode(predicate, null);
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    public IterationConstructGenerator inspectPredicate(PredicateNode predicate) {
        return inspectPredicate(new IterationConstructGenerator(this, machineGenerator, group, typeGenerator, importGenerator), predicate);
    }

    public IterationConstructGenerator inspectPredicates(IterationConstructGenerator iterationConstructGenerator, List<PredicateNode> predicates) {
        predicates.forEach(predicate -> iterationConstructGenerator.visitPredicateNode(predicate, null));
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    public IterationConstructGenerator inspectPredicates(List<PredicateNode> predicates) {
        return inspectPredicates(new IterationConstructGenerator(this, machineGenerator, group, typeGenerator, importGenerator), predicates);
    }

    public IterationConstructGenerator inspectExpression(IterationConstructGenerator iterationConstructGenerator, ExprNode expression) {
        iterationConstructGenerator.visitExprNode(expression, null);
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    public IterationConstructGenerator inspectExpression(ExprNode expression) {
        return inspectExpression(new IterationConstructGenerator(this, machineGenerator, group, typeGenerator, importGenerator), expression);
    }


    public HashMap<String, String> getIterationsMapCode() {
        return currentIterationConstructGenerator.getIterationsMapCode();
    }

    public HashMap<String, String> getIterationsMapIdentifier() {
        return currentIterationConstructGenerator.getIterationsMapIdentifier();
    }

    public IterationConstructGenerator getCurrentIterationConstructGenerator() {
        return currentIterationConstructGenerator;
    }
}
