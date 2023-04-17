package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Ignore;
import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestMCBenchmarks extends TestRSE {
    public TestMCBenchmarks() throws URISyntaxException, IOException {}

    @Test
    public void testCanBusMC() throws Exception {
        testRSEMC("CAN_BUS_tlc");
    }

    @Test
    public void testCruiseControllerDeterministic_MC() throws Exception {
        testRSEMC("Cruise_finite1_deterministic_MC");
    }

    @Test
    public void testLandingGear_MC() throws Exception {
        testRSEMC("landing_gear/LandingGear_R6");
    }

    @Test
    public void testLift_MC() throws Exception {
        testRSEMC("Lift_MC_Large");
    }

    @Test
    public void testNotaV2_MC() throws Exception {
        testRSEMC("nota_v2");
    }

    @Test
    @Ignore
    public void testQueens4_MC() throws Exception {
        testRSEMC("QueensWithEvents_4");
    }

    @Test
    public void testsort_m2_data1000_MC() throws Exception {
        testRSEMC("sort_m2_data1000_MC");
    }

    @Test
    public void testTrain1_Lukas_POR_v3() throws Exception {
        testRSEMC("Train1_Lukas_POR_v3");
    }

    @Test
    public void testTrain_1_beebook_deterministic_MC_POR_v2() throws Exception {
        testRSEMC("Train_1_beebook_deterministic_MC_POR_v2");
    }
}
