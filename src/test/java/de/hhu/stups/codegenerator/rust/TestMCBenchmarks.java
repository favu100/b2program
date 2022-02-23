package de.hhu.stups.codegenerator.rust;

import org.junit.Test;

public class TestMCBenchmarks extends TestRS {

    @Test
    public void testCanBusMC() throws Exception {
        testRSMC("CAN_BUS_tlc");
    }

    @Test
    public void testCruiseControllerDeterministic_MC() throws Exception {
        testRSMC("Cruise_finite1_deterministic_MC");
    }

    @Test
    public void testLandingGear_MC() throws Exception {
        testRSMC("landing_gear/LandingGear_R6");
    }

    @Test
    public void testLift_MC() throws Exception {
        testRSMC("Lift_MC_Large");
    }

    @Test
    public void testNotaV2_MC() throws Exception {
        testRSMC("nota_v2");
    }

    @Test
    public void testQueens4_MC() throws Exception {
        testRSMC("QueensWithEvents_4");
    }

    @Test
    public void testQueens8_MC() throws Exception {
        testRSMC("QueensWithEvents_8");
    }

    @Test
    public void testsort_m2_data1000_MC() throws Exception {
        testRSMC("sort_m2_data1000_MC");
    }

    @Test
    public void testTrain1_Lukas_POR() throws Exception {
        testRSMC("Train1_Lukas_POR");
    }

    @Test
    public void testTrain_1_beebook_deterministic_MC_POR() throws Exception {
        testRSMC("Train_1_beebook_deterministic_MC_POR", false);
    }
}
