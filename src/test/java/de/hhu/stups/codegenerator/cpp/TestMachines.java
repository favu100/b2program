package de.hhu.stups.codegenerator.cpp;

import org.junit.Ignore;
import org.junit.Test;

public class TestMachines extends TestCpp {

    @Test
    public void testExample() throws Exception {
        testCpp("Example");
    }

    @Test
    public void testOperation() throws Exception {
        testCpp("Operation", "Operation", "OperationAddition.stCpp", true);
    }

    @Test
    public void testOperation2() throws Exception {
        testCpp("Operation2");
    }

    @Test
    public void testLocalDeclaration() throws Exception {
        testCpp("LocalDeclaration");
    }

    @Test
    public void testCounter() throws Exception {
        testCpp("Counter", "Counter", "CounterAddition.stCpp", true);
    }

    @Test
    public void testBakery0() throws Exception {
        testCpp("Bakery0", "Bakery0", "Bakery0Addition.stCpp", true);
    }

    @Test
    public void testGCD() throws Exception {
        testCpp("GCD");
    }

    @Test
    public void testACounter() throws Exception {
        testCpp("ACounter", "ACounter", "ACounterAddition.stCpp", true);
    }

    @Test
    public void testLift() throws Exception {
        testCpp("Lift", "Lift", "LiftAddition.stCpp", true);
    }

    @Test
    public void testTravelAgency() throws Exception {
        testCpp("TravelAgency");
    }

    @Test
    public void testTrafficLight() throws Exception {
        testCpp("TrafficLight", "TrafficLight", "TrafficLightAddition.stCpp", true);
    }

    @Test
    public void testPhonebook() throws Exception {
        testCpp("phonebook");
    }

    @Test
    public void testPhonebook6() throws Exception {
        testCpp("phonebook6");
    }

    @Test
    public void testSieve() throws Exception {
        testCpp("Sieve", "Sieve", "SieveAddition.stCpp", true);
    }

    @Test
    public void testSieveParallel() throws Exception {
        testCpp("SieveParallel", "SieveParallel", "SieveParallelAddition.stCpp", true);
    }

    @Test
    public void testReset() throws Exception {
        testCpp("Reset");
    }

    @Test
    public void testLiftMC() throws Exception {
        testCppMC("Lift_MC");
    }

    @Test
    public void testCruiseController1() throws Exception {
        testCpp("Cruise_finite1");
    }

    @Test
    public void testCruiseControllerk() throws Exception {
        testCpp("Cruise_finite_k");
    }

    @Test
    public void testCruiseControllerDeterministic() throws Exception {
        testCpp("Cruise_finite1_deterministic");
    }

    @Test
    public void testCruiseControllerDeterministic_MC() throws Exception {
        testCppMC("Cruise_finite1_deterministic_MC");
    }

    @Test
    public void testCruiseControllerDeterministicExec() throws Exception {
        testCpp("Cruise_finite1_deterministic_exec");
    }

    @Test
    public void testScheduler() throws Exception {
        testCpp("scheduler");
    }

    @Test
    public void testSchedulerDeterministic() throws Exception {
        testCpp("scheduler_deterministic");
    }

    @Test
    public void testSchedulerDeterministicExec() throws Exception {
        testCpp("scheduler_deterministic_exec");
    }

    @Test
    public void testCanBusTLC() throws Exception {
        testCpp("CAN_BUS_tlc");
    }

    @Test
    public void testCanBusMC() throws Exception {
        testCppMC("CAN_BUS_tlc");
    }

    @Test
    public void Train1LukasPORv3() throws Exception {
        testCppMC("Train1_Lukas_POR_v3");
    }

    @Test
    public void testCanBusTLCExec() throws Exception {
        testCpp("CAN_BUS_tlc_exec");
    }

    @Test
    public void testCore() throws Exception {
        testCpp("Core");
    }

    @Ignore
    @Test
    public void testSetLawsNAT() throws Exception {
        testCpp("SetLawsNAT");
    }

    @Test
    public void SimpsonFourSlot() throws Exception {
        testCpp("Simpson_Four_Slot");
    }

    @Test
    public void testsort_m2_data1000_MC() throws Exception {
        testCppMC("sort_m2_data1000_MC");
    }

    @Test
    public void Train1BeebookTLC() throws Exception {
        testCpp("Train_1_beebook_TLC");
    }

    @Test
    public void Train1BeebookDeterministic() throws Exception {
        testCpp("Train_1_beebook_deterministic");
    }

    @Test
    public void Train1BeebookDeterministic_MC_POR_v2() throws Exception {
        testCppMC("Train_1_beebook_deterministic_MC_POR_v2");
    }

    @Test
    public void Train1BeebookDeterministicExec() throws Exception {
        testCpp("Train_1_beebook_deterministic_exec");
    }

    @Test
    public void Train1() throws Exception {
        testCpp("train_1");
    }

    @Ignore
    @Test
    public void testEarley2() throws Exception {
        testCpp("earley_2");
    }

    @Ignore
    @Test
    public void testOBSW_M001() throws Exception {
        testCpp("obsw_M001");
    }

    @Ignore
    @Test
    public void testRef5Switch() throws Exception {
        testCpp("Ref5_Switch");
    }

    @Ignore
    @Test
    public void testrether_mch1() throws Exception {
        testCpp("rether_mch1");
    }

}
