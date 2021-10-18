package de.hhu.stups.codegenerator.handlers;

import de.hhu.stups.codegenerator.analyzers.ParallelConstructAnalyzer;

/**
 * Created by fabian on 04.03.19.
 */

/*
* This class stores the information about whether the current visited part of the AST is the left-hand side on an assignment
*/
public class ParallelConstructHandler {

    private ParallelConstructAnalyzer parallelConstructAnalyzer;

    private boolean lhsInParallel;

    private boolean isDefiningLdVariable;

    public ParallelConstructHandler() {
        this.lhsInParallel = false;
    }

    public void setLhsInParallel(boolean lhsInParallel) {
        this.lhsInParallel = lhsInParallel;
    }

    public void setParallelConstructAnalyzer(ParallelConstructAnalyzer parallelConstructAnalyzer) {
        this.parallelConstructAnalyzer = parallelConstructAnalyzer;
    }

    public ParallelConstructAnalyzer getParallelConstructAnalyzer() {
        return parallelConstructAnalyzer;
    }

    public boolean isLhsInParallel() {
        return lhsInParallel;
    }

    public boolean isDefiningLdVariable() {
        return isDefiningLdVariable;
    }

    public void setDefiningLdVariable(boolean definingLdVariable) {
        isDefiningLdVariable = definingLdVariable;
    }
}
