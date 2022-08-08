package de.hhu.stups.codegenerator.prolog;

import org.junit.Test;

public class TestMachines extends TestProlog {
    @Test
    public void testLift() throws Exception {
        testProlog("Lift");
    }

    @Test
    public void testCruiseFiniteDeterministic_MC() throws Exception {
        testProlog("Cruise_finite1_deterministic_MC");
    }

    @Test
    public void testQueens4() throws Exception {
        testProlog("QueensWithEvents_4");
    }

    @Test
    public void testScheduler_Deterministic_MC() throws Exception {
        testProlog("scheduler_deterministic_MC");
    }

    @Test
    public void testRange() throws Exception {
        testProlog("Range");
    }

    @Test
    public void testQuantifiedPredicate() throws Exception {
        testProlog("QuantifiedPredicate");
    }

    @Test
    public void testQuantifiedPredicate2() throws Exception {
        testProlog("QuantifiedPredicate2");
    }

    @Test
    public void testQuantifiedPredicate3() throws Exception {
        testProlog("QuantifiedPredicate3");
    }

    @Test
    public void testQuantifiedPredicate4() throws Exception {
        testProlog("QuantifiedPredicate4");
    }

    @Test
    public void testQuantifiedPredicate5() throws Exception {
        testProlog("QuantifiedPredicate5");
    }

    @Test
    public void testQuantifiedPredicate6() throws Exception {
        testProlog("QuantifiedPredicate6");
    }

    @Test
    public void testQuantifiedPredicate7() throws Exception {
        testProlog("QuantifiedPredicate7");
    }
}
