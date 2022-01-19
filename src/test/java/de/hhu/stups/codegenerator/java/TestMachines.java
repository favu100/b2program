package de.hhu.stups.codegenerator.java;

import org.junit.Ignore;
import org.junit.Test;

public class TestMachines extends TestJava {

    @Test
    public void testExample() throws Exception {
        testJava("Example");
    }

    @Test
    public void testOperation() throws Exception {
        testJava("Operation", "Operation", "OperationAddition.stjava", true);
    }

    @Test
    public void testOperation2() throws Exception {
        testJava("Operation2");
    }

    @Test
    public void testLocalDeclaration() throws Exception {
        testJava("LocalDeclaration");
    }

    @Test
    public void testCounter() throws Exception {
        testJava("Counter", "Counter", "CounterAddition.stjava", true);
    }

    @Test
    public void testBakery0() throws Exception {
        testJava("Bakery0", "Bakery0", "Bakery0Addition.stjava", true);
    }

    @Test
    public void testGCD() throws Exception {
        testJava("GCD");
    }

    @Test
    public void testACounter() throws Exception {
        testJava("ACounter", "ACounter", "ACounterAddition.stjava", true);
    }

    @Test
    public void testLift() throws Exception {
        testJava("Lift", "Lift", "LiftAddition.stjava", true);
    }

    @Test
    public void testLift_MC() throws Exception {
        testJavaMC("Lift_MC");
    }


    @Test
    public void testTravelAgency() throws Exception {
        testJava("TravelAgency");
    }

    @Test
    public void testTrafficLight() throws Exception {
        testJava("TrafficLight", "TrafficLight", "TrafficLightAddition.stjava", true);
    }

    @Test
    public void testTrafficLightMC() throws Exception {
        testJavaMC("TrafficLight_MC");
    }

    @Test
    public void testPhonebook() throws Exception {
        testJava("phonebook");
    }

    @Test
    public void testPhonebook6() throws Exception {
        testJava("phonebook6");
    }

    @Test
    public void testSieve() throws Exception {
        testJava("Sieve", "Sieve", "SieveAddition.stjava", true);
    }

    @Test
    public void testSieveParallel() throws Exception {
        testJava("SieveParallel", "SieveParallel", "SieveParallelAddition.stjava", true);
    }

    @Test
    public void testReset() throws Exception {
        testJava("Reset");
    }

    @Test
    public void testCruiseController1() throws Exception {
        testJava("Cruise_finite1");
    }

    @Test
    public void testCruiseControllerk() throws Exception {
        testJava("Cruise_finite_k");
    }

    @Test
    public void testCruiseControllerDeterministic() throws Exception {
        testJava("Cruise_finite1_deterministic");
    }

    @Test
    public void testCruiseControllerDeterministic_MC() throws Exception {
        testJavaMC("Cruise_finite1_deterministic_MC");
    }

    @Test
    public void testCruiseControllerDeterministicExec() throws Exception {
        testJava("Cruise_finite1_deterministic_exec");
    }

    @Test
    public void testScheduler() throws Exception {
        testJava("scheduler");
    }

    @Test
    public void testSchedulerDeterministic() throws Exception {
        testJava("scheduler_deterministic");
    }

    @Test
    public void testSchedulerDeterministicMC() throws Exception {
        testJavaMC("scheduler_deterministic_MC");
    }

    @Test
    public void testSchedulerDeterministicExec() throws Exception {
        testJava("scheduler_deterministic_exec");
    }

    @Test
    public void testCanBusTLC() throws Exception {
        testJava("CAN_BUS_tlc");
    }

    @Test
    public void testCanBusMC() throws Exception {
        testJavaMC("CAN_BUS_tlc");
    }

    @Test
    public void testCanBusTLCExec() throws Exception {
        testJava("CAN_BUS_tlc_exec");
    }

    @Test
    public void testCore() throws Exception {
        testJava("Core");
    }

    @Ignore
    @Test
    public void testSetLawsNAT() throws Exception {
        testJava("SetLawsNAT");
    }

    @Test
    public void SimpsonFourSlot() throws Exception {
        testJava("Simpson_Four_Slot");
    }

    @Test
    public void Train1BeebookTLC() throws Exception {
        testJava("Train_1_beebook_TLC");
    }

    @Test
    public void Train1BeebookDeterministic() throws Exception {
        testJava("Train_1_beebook_deterministic");
    }

    @Test
    public void Train1BeebookDeterministic_MC() throws Exception {
        testJavaMC("Train_1_beebook_deterministic_MC");
    }

    @Test
    public void Train1BeebookDeterministicExec() throws Exception {
        testJava("Train_1_beebook_deterministic_exec");
    }

    @Test
    public void Train1LukasPOR() throws Exception {
        testJavaMC("Train1_Lukas_POR");
    }

    @Test
    public void Train1LukasPORv3() throws Exception {
        testJavaMC("Train1_Lukas_POR_v3");
    }

    @Test
    public void Train1LukasPORv4() throws Exception {
        testJavaMC("Train1_Lukas_POR_v4");
    }

    @Test
    public void Train1BeebookDeterministic_MC_POR() throws Exception {
        testJavaMC("Train_1_beebook_deterministic_MC_POR");
    }

    @Test
    public void Train1BeebookDeterministic_MC_POR_v2() throws Exception {
        testJavaMC("Train_1_beebook_deterministic_MC_POR_v2");
    }

    @Test
    public void Train1() throws Exception {
        testJava("train_1");
    }

    @Test
    public void IncrementalStagePackingTestLargeSlow() throws Exception {
        testJavaMC("IncrementalStatePackingTestLargeSlow");
    }

    @Test
    public void IncrementalStagePackingTestLargeSlow2() throws Exception {
        testJavaMC("IncrementalStatePackingTestLargeSlow2");
    }

    @Test
    public void ThreeCounter() throws Exception {
        testJavaMC("ThreeCounter");
    }

    @Test
    public void ThreeCounter2() throws Exception {
        testJavaMC("ThreeCounter2");
    }

    @Ignore
    @Test
    public void testEarley2() throws Exception {
        testJava("earley_2");
    }

    @Ignore
    @Test
    public void testOBSW_M001() throws Exception {
        testJava("obsw_M001");
    }

    @Ignore
    @Test
    public void testRef5Switch() throws Exception {
        testJava("Ref5_Switch");
    }

    @Ignore
    @Test
    public void testrether_mch1() throws Exception {
        testJava("rether_mch1");
    }

    @Test
    public void testsort_m2_data1000() throws Exception {
        testJava("sort_m2_data1000");
    }

    @Test
    public void testsort_m2_data1000_MC() throws Exception {
        testJavaMC("sort_m2_data1000_MC");
    }

    @Test
    public void testSimpleParameters() throws Exception {
        testJava("SimpleParameters");
    }

    @Test
    public void testPitmanController_TIME_MC_v4() throws Exception {
        testJava("visualisation/PitmanController_TIME_MC_v4");
    }

    @Test
    public void testPitmanController_TIME_MC_v4_MC() throws Exception {
        testJavaMC("visualisation/PitmanController_TIME_MC_v4");
    }

    @Test
    public void testButton() throws Exception {
        testJavaMC("visualisation/Button");
    }

    @Test
    public void testLandingGear_MC() throws Exception {
        testJavaMC("landing_gear/LandingGear_R6");
    }

    @Test
    public void testQueensWithEvents() throws Exception {
        testJavaMC("QueensWithEvents");
    }

    @Test
    public void testArithmeticLaws() throws Exception {
        testJavaMC("ArithmeticLaws");
    }



}
