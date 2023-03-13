package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Ignore;
import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestBenchmarks extends TestRSE {

    public TestBenchmarks() throws URISyntaxException, IOException {}

    @Test
    public void testLiftBenchmarks() throws Exception {
        testRSE("liftbenchmarks/LiftExec", "LiftExecAddition.strs");
    }

    @Test
    public void testTrafficLightBenchmarks() throws Exception {
        testRSE("trafficlightbenchmarks/TrafficLightExec", "TrafficLightExecAddition.strs");
    }

    @Ignore
    @Test //Interger-Set, so unsupported in embedded
    public void testSieveBenchmarks() throws Exception {
        testRSE("sievebenchmarks/Sieve", "SieveAddition.strs");
    }

    @Ignore
    @Test
    public void testIncreasingSet() throws Exception {
        testRSE("setoperationbenchmarks/IncreasingSet", "IncreasingSetAddition.strs");
    }

    @Ignore
    @Test
    public void testSetOperation() throws Exception {
        testRSE("setoperationbenchmarks/SetOperation",  "SetOperationAddition.strs");
    }

    //TODO: CAN_BUS: either allow const-intSet or rewrite machine

    @Test
    public void testCruise_finite_deterministic() throws Exception {
        testRSE("Cruise_finite1_deterministic_exec", "Cruise_finite1_deterministic_execAddition.strs");
    }

    @Test
    public void testScheduler_deterministic() throws Exception {
        testRSE("scheduler_deterministic_exec", "scheduler_deterministic_execAddition.strs");
    }

    @Test
    public void testTrafficLight() throws Exception {
        testRSE("TrafficLightExec", "TrafficLightExecAddition.strs");
    }

    @Test
    public void testTrain_1_beebook_deterministic_exec() throws Exception {
        testRSE("Train_1_beebook_deterministic_exec", "Train_1_beebook_deterministic_execAddition.strs");
    }
}
