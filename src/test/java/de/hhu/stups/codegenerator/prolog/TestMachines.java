package de.hhu.stups.codegenerator.prolog;

import org.junit.Test;

public class TestMachines extends TestProlog {
    @Test
    public void testLift() throws Exception {
        testProlog("Lift", "Lift", "LiftAddition.stjava", true);
    }

    @Test
    public void testLift_MC() throws Exception {
        testPrologMC("Lift_MC");
    }

}
