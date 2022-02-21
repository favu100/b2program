package de.hhu.stups.codegenerator.rust;

import org.junit.Test;

public class TestMachines extends TestRS {

    @Test
    public void testExample() throws Exception {
        testRS("Example");
    }

    @Test
    public void testOperation() throws Exception {
        testRS("Operation", "Operation", "OperationAddition.strs", true);
    }

    @Test
    public void testOperation2() throws Exception {
        testRS("Operation2");
    }

    @Test
    public void testLocalDeclaration() throws Exception {
        testRS("LocalDeclaration");
    }

    @Test
    public void testCounter() throws Exception {
        testRS("Counter", "Counter", "CounterAddition.strs", true);
    }

    @Test
    public void testBakery0() throws Exception {
        testRS("Bakery0", "Bakery0", "Bakery0Addition.strs", true);
    }

    @Test
    public void testGCD() throws Exception {
        testRS("GCD");
    }

    @Test
    public void testACounter() throws Exception {
        testRS("ACounter", "ACounter", "ACounterAddition.strs", true);
    }

    @Test
    public void testLift() throws Exception {
        testRS("Lift", "Lift", "LiftAddition.strs", true);
    }

    @Test
    public void testLift_MC() throws Exception {
        testRSMC("Lift_MC");
    }


    @Test
    public void testTravelAgency() throws Exception {
        testRS("TravelAgency");
    }

    @Test
    public void testTrafficLight() throws Exception {
        testRS("TrafficLight", "TrafficLight", "TrafficLightAddition.strs", true);
    }

    @Test
    public void testTrafficLightMC() throws Exception {
        testRSMC("TrafficLight_MC");
    }

    @Test
    public void testPhonebook() throws Exception {
        testRS("phonebook");
    }

    @Test
    public void testPhonebook6() throws Exception {
        testRS("phonebook6");
    }

    @Test
    public void testSieve() throws Exception {
        testRS("Sieve", "Sieve", "SieveAddition.strs", true);
    }

    @Test
    public void testSieveParallel() throws Exception {
        testRS("SieveParallel", "SieveParallel", "SieveParallelAddition.strs", true);
    }

    @Test
    public void testReset() throws Exception {
        testRS("Reset");
    }

    @Test
    public void testCruiseController1() throws Exception {
        testRS("Cruise_finite1");
    }

    @Test
    public void testCruiseControllerk() throws Exception {
        testRS("Cruise_finite_k");
    }

    @Test
    public void testCruiseControllerDeterministic() throws Exception {
        testRS("Cruise_finite1_deterministic");
    }

    @Test
    public void testCruiseControllerDeterministic_MC() throws Exception {
        testRSMC("Cruise_finite1_deterministic_MC");
    }

    @Test
    public void testCruiseControllerDeterministicExec() throws Exception {
        testRS("Cruise_finite1_deterministic_exec");
    }

    @Test
    public void testScheduler() throws Exception {
        testRS("scheduler");
    }

    @Test
    public void testSchedulerDeterministic() throws Exception {
        testRS("scheduler_deterministic");
    }

    @Test
    public void testSchedulerDeterministicMC() throws Exception {
        testRSMC("scheduler_deterministic_MC");
    }

    @Test
    public void testSchedulerDeterministicExec() throws Exception {
        testRS("scheduler_deterministic_exec");
    }

    @Test
    public void testCanBusTLC() throws Exception {
        testRS("CAN_BUS_tlc");
    }

    @Test
    public void testCanBusMC() throws Exception {
        testRSMC("CAN_BUS_tlc");
    }

    @Test
    public void testCanBus_testMC() throws Exception {
        testRSMC("CAN_BUS_tlc_test");
    }

    @Test
    public void testCanBusTLCExec() throws Exception {
        testRS("CAN_BUS_tlc_exec");
    }

    @Test
    public void testCore() throws Exception {
        testRS("Core");
    }

    @Test
    public void testSetLawsNAT() throws Exception {
        testRS("SetLawsNAT");
    }

    // totalFunction currently not supported (and maybe never will)
    @Test(expected = Exception.class)
    public void SimpsonFourSlot() throws Exception {
        testRS("Simpson_Four_Slot");
    }

    @Test
    public void Train1BeebookTLC() throws Exception {
        testRS("Train_1_beebook_TLC");
    }

    @Test
    public void Train1BeebookDeterministic() throws Exception {
        testRS("Train_1_beebook_deterministic");
    }

    @Test
    public void Train1BeebookDeterministic_MC() throws Exception {
        testRSMC("Train_1_beebook_deterministic_MC");
    }

    @Test
    public void Train1BeebookDeterministicExec() throws Exception {
        testRS("Train_1_beebook_deterministic_exec");
    }

    @Test
    public void Train1LukasPOR() throws Exception {
        testRSMC("Train1_Lukas_POR", false);
    }

    @Test
    public void Train1LukasPORv3() throws Exception {
        testRSMC("Train1_Lukas_POR_v3", false);
    }

    @Test
    public void Train1LukasPORv4() throws Exception {
        testRSMC("Train1_Lukas_POR_v4", false);
    }

    @Test
    public void Train1BeebookDeterministic_MC_POR() throws Exception {
        testRSMC("Train_1_beebook_deterministic_MC_POR");
    }

    @Test
    public void Train1BeebookDeterministic_MC_POR_v2() throws Exception {
        testRSMC("Train_1_beebook_deterministic_MC_POR_v2", false);
    }

    @Test
    public void Train1() throws Exception {
        testRS("train_1");
    }

    @Test
    public void IncrementalStagePackingTestLargeSlow() throws Exception {
        testRSMC("IncrementalStatePackingTestLargeSlow");
    }

    @Test
    public void IncrementalStagePackingTestLargeSlow2() throws Exception {
        testRSMC("IncrementalStatePackingTestLargeSlow2", false);
    }

    @Test
    public void ThreeCounter() throws Exception {
        testRSMC("ThreeCounter", false);
    }

    @Test
    public void ThreeCounter2() throws Exception {
        testRSMC("ThreeCounter2");
    }

    @Test
    public void testEarley2() throws Exception {
        testRS("earley_2");
    }

    @Test
    public void testOBSW_M001() throws Exception {
        testRS("obsw_M001");
    }

    @Test
    public void testRef5Switch() throws Exception {
        testRS("Ref5_Switch");
    }

    @Test
    public void testrether_mch1() throws Exception {
        testRS("rether_mch1");
    }

    @Test
    public void testsort_m2_data1000() throws Exception {
        testRS("sort_m2_data1000");
    }

    @Test
    public void testsort_m2_data1000_MC() throws Exception {
        testRSMC("sort_m2_data1000_MC");
    }

    @Test
    public void testSimpleParameters() throws Exception {
        testRS("SimpleParameters");
    }

    @Test
    public void testPitmanController_TIME_MC_v4() throws Exception {
        testRS("visualisation/PitmanController_TIME_MC_v4");
    }

    @Test
    public void testLandingGear_MC() throws Exception {
        testRSMC("landing_gear/LandingGear_R6");
    }

    @Test
    public void testNotaV2_MC() throws Exception {
        testRSMC("nota_v2");
    }
}
