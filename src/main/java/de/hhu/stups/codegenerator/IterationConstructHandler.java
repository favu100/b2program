package de.hhu.stups.codegenerator;

import java.util.HashMap;

/**
 * Created by fabian on 06.02.19.
 */
public class IterationConstructHandler {

    private IterationConstructGenerator currentIterationConstructGenerator;

    private int iterationConstructCounter;

    public IterationConstructHandler() {
        this.currentIterationConstructGenerator = null;
        this.iterationConstructCounter = 0;
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

    public HashMap<String, String> getIterationsMapCode() {
        return currentIterationConstructGenerator.getIterationsMapCode();
    }

    public HashMap<String, String> getIterationsMapIdentifier() {
        return currentIterationConstructGenerator.getIterationsMapIdentifier();
    }
}
