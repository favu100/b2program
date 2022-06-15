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
    public void testRange() throws Exception {
        testProlog("Range");
    }
}
