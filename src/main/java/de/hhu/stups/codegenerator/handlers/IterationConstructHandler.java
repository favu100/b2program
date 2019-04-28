package de.hhu.stups.codegenerator.handlers;

import de.hhu.stups.codegenerator.generators.ImportGenerator;
import de.hhu.stups.codegenerator.generators.iteration.IterationConstructGenerator;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.substitution.SubstitutionNode;
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

    private final NameHandler nameHandler;

    private final TypeGenerator typeGenerator;

    private final ImportGenerator importGenerator;

    private final STGroup group;

    public IterationConstructHandler(final STGroup group, final MachineGenerator machineGenerator, final NameHandler nameHandler,
                                     final TypeGenerator typeGenerator, final ImportGenerator importGenerator) {
        this.currentIterationConstructGenerator = null;
        this.iterationConstructCounter = 0;
        this.machineGenerator = machineGenerator;
        this.nameHandler = nameHandler;
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
        iterationConstructGenerator.getBoundedVariables().addAll(this.currentIterationConstructGenerator.getBoundedVariables());
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    public IterationConstructGenerator inspectPredicate(PredicateNode predicate) {
        return inspectPredicate(new IterationConstructGenerator(this, machineGenerator, nameHandler, group, typeGenerator, importGenerator), predicate);
    }

    public IterationConstructGenerator inspectPredicates(IterationConstructGenerator iterationConstructGenerator, List<PredicateNode> predicates) {
        predicates.forEach(predicate -> iterationConstructGenerator.visitPredicateNode(predicate, null));
        if(currentIterationConstructGenerator != null) {
            iterationConstructGenerator.getBoundedVariables().addAll(this.currentIterationConstructGenerator.getBoundedVariables());
        }
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    public IterationConstructGenerator inspectPredicates(List<PredicateNode> predicates) {
        return inspectPredicates(new IterationConstructGenerator(this, machineGenerator, nameHandler, group, typeGenerator, importGenerator), predicates);
    }

    public IterationConstructGenerator inspectExpression(IterationConstructGenerator iterationConstructGenerator, ExprNode expression) {
        iterationConstructGenerator.visitExprNode(expression, null);
        if(currentIterationConstructGenerator != null) {
            iterationConstructGenerator.getBoundedVariables().addAll(this.currentIterationConstructGenerator.getBoundedVariables());
        }
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    public IterationConstructGenerator inspectExpression(ExprNode expression) {
        return inspectExpression(new IterationConstructGenerator(this, machineGenerator, nameHandler, group, typeGenerator, importGenerator), expression);
    }


    public IterationConstructGenerator inspectSubstitution(IterationConstructGenerator iterationConstructGenerator, SubstitutionNode substitution) {
        iterationConstructGenerator.visitSubstitutionNode(substitution, null);
        if(currentIterationConstructGenerator != null) {
            iterationConstructGenerator.getBoundedVariables().addAll(this.currentIterationConstructGenerator.getBoundedVariables());
        }
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    public IterationConstructGenerator inspectSubstitution(SubstitutionNode substitution) {
        return inspectSubstitution(new IterationConstructGenerator(this, machineGenerator, nameHandler, group, typeGenerator, importGenerator), substitution);
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
