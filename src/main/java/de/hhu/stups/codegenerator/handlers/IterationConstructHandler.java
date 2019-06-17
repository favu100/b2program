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

    /*
    * This function should be invoked when the next iteration construct is entered
    */
    public void incrementIterationConstructCounter() {
        iterationConstructCounter++;
    }

    /*
    * This function returns a new IterationConstructGenerator
    */
    public IterationConstructGenerator getNewIterationConstructGenerator() {
        return new IterationConstructGenerator(this, machineGenerator, nameHandler, group, typeGenerator, importGenerator);
    }

    /*
    * This function gets an IterationConstructGenerator and a predicate as a parameter. Then it analyze the predicate with a new IterationConstructGenerator and returns it.
    */
    public IterationConstructGenerator inspectPredicate(IterationConstructGenerator iterationConstructGenerator, PredicateNode predicate) {
        iterationConstructGenerator.visitPredicateNode(predicate, null);
        if(currentIterationConstructGenerator != null) {
            iterationConstructGenerator.getAllBoundedVariables().addAll(this.currentIterationConstructGenerator.getAllBoundedVariables());
        }
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    /*
    * This function gets a predicate and analyze the predicate on a new created IterationConstructGenerator
    */
    public IterationConstructGenerator inspectPredicate(PredicateNode predicate) {
        return inspectPredicate(getNewIterationConstructGenerator(), predicate);
    }

    /*
    * This function gets an IterationConstructGenerator and many predicates as parameters. Then it analyze the predicates with a new IterationConstructGenerator and returns it.
    */
    public IterationConstructGenerator inspectPredicates(IterationConstructGenerator iterationConstructGenerator, List<PredicateNode> predicates) {
        predicates.forEach(predicate -> iterationConstructGenerator.visitPredicateNode(predicate, null));
        if(currentIterationConstructGenerator != null) {
            iterationConstructGenerator.getAllBoundedVariables().addAll(this.currentIterationConstructGenerator.getAllBoundedVariables());
        }
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    /*
    * This function gets many predicates and analyze it on a new created IterationConstructGenerator
    */
    public IterationConstructGenerator inspectPredicates(List<PredicateNode> predicates) {
        return inspectPredicates(getNewIterationConstructGenerator(), predicates);
    }

    /*
    * This function gets an IterationConstructGenerator and an expression as parameters. Then it analyze the expression with a new IterationConstructGenerator and returns it.
    */
    public IterationConstructGenerator inspectExpression(IterationConstructGenerator iterationConstructGenerator, ExprNode expression) {
        iterationConstructGenerator.visitExprNode(expression, null);
        if(currentIterationConstructGenerator != null) {
            iterationConstructGenerator.getAllBoundedVariables().addAll(this.currentIterationConstructGenerator.getAllBoundedVariables());
        }
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    /*
    * This function inspects an expression with a new created IterationConstructGenerator
    */
    public IterationConstructGenerator inspectExpression(ExprNode expression) {
        return inspectExpression(getNewIterationConstructGenerator(), expression);
    }


    /*
    * This function gets an IterationConstructGenerator and a substitution as parameters. Then it analyze the substitution with a new IterationConstructGenerator and returns it.
    */
    public IterationConstructGenerator inspectSubstitution(IterationConstructGenerator iterationConstructGenerator, SubstitutionNode substitution) {
        iterationConstructGenerator.visitSubstitutionNode(substitution, null);
        if(currentIterationConstructGenerator != null) {
            iterationConstructGenerator.getAllBoundedVariables().addAll(this.currentIterationConstructGenerator.getAllBoundedVariables());
        }
        this.setIterationConstructGenerator(iterationConstructGenerator);
        return iterationConstructGenerator;
    }

    /*
    * This function inspects a substitution with a new created IterationConstructGenerator
    */
    public IterationConstructGenerator inspectSubstitution(SubstitutionNode substitution) {
        return inspectSubstitution(getNewIterationConstructGenerator(), substitution);
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
