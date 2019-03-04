package de.hhu.stups.codegenerator.handlers;

import de.hhu.stups.codegenerator.analyzers.ParallelConstructAnalyzer;

/**
 * Created by fabian on 04.03.19.
 */
public class ParallelConstructHandler {

    private ParallelConstructAnalyzer parallelConstructAnalyzer;

    private boolean lhsInParallel;

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

}
