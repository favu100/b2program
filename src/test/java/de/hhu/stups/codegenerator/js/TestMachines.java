package de.hhu.stups.codegenerator.js;

import org.junit.Ignore;
import org.junit.Test;

public class TestMachines extends TestJs {

    @Test
    public void testExample() throws Exception {
        testJs("Example");
    }

    @Test
    public void testOperation() throws Exception {
        testJs("Operation", "Operation", "OperationAddition.stjs", true);
    }

    @Test
    public void testOperation2() throws Exception {
        testJs("Operation2");
    }

    @Test
    public void testLocalDeclaration() throws Exception {
        testJs("LocalDeclaration");
    }

    @Test
    public void testCounter() throws Exception {
        testJs("Counter", "Counter", "CounterAddition.stjs", true);
    }

    @Test
    public void testBakery0() throws Exception {
        testJs("Bakery0", "Bakery0", "Bakery0Addition.stjs", true);
    }

    @Test
    public void testGCD() throws Exception {
        testJs("GCD");
    }

    @Test
    public void testACounter() throws Exception {
        testJs("ACounter", "ACounter", "ACounterAddition.stjs", true);
    }

    @Test
    public void testLift() throws Exception {
        testJs("Lift", "Lift", "LiftAddition.stjs", true);
    }

    @Test
    public void testLiftMC() throws Exception {
        testJSMC("Lift_MC");
    }


    @Test
    public void testTravelAgency() throws Exception {
        testJs("TravelAgency");
    }

    @Test
    public void testTrafficLight() throws Exception {
        testJs("TrafficLight", "TrafficLight", "TrafficLightAddition.stjs", true);
    }

    @Test
    public void testPhonebook() throws Exception {
        testJs("phonebook");
    }

    @Test
    public void testPhonebook6() throws Exception {
        testJs("phonebook6");
    }

    @Test
    public void testSieve() throws Exception {
        testJs("Sieve", "Sieve", "SieveAddition.stjs", false);
    }

    @Ignore
    @Test
    public void testSieveParallel() throws Exception {
        testJs("SieveParallel", "SieveParallel", "SieveParallelAddition.stjs", true);
    }

    @Test
    public void testSortExec() throws Exception {
        testJs("sort_m2_data1000_exec", "sort_m2_data1000_exec", "sort_m2_data1000_execAddition.stjs", false);
    }

    @Test
    public void testSchedulerExec() throws Exception {
        testJs("scheduler_deterministic_exec", "scheduler_deterministic_exec", "scheduler_deterministic_execAddition.stjs", false);
    }

    @Test
    public void testTrainExec() throws Exception {
        testJs("Train_1_beebook_deterministic_exec", "Train_1_beebook_deterministic_exec", "Train_1_beebook_deterministic_execAddition.stjs", false);
    }

    @Test
    public void testCruiseExec() throws Exception {
        testJs("Cruise_finite1_deterministic_exec", "Cruise_finite1_deterministic_exec", "Cruise_finite1_deterministic_execAddition.stjs", false);
    }

    @Test
    public void testCANBUSExec() throws Exception {
        testJs("CAN_BUS_tlc_exec", "CAN_BUS_tlc_exec", "CAN_BUS_tlc_execAddition.stjs", false);
    }

    @Test
    public void testLiftExec() throws Exception {
        testJs("LiftExec", "LiftExec", "LiftExecAddition.stjs", false);
    }

    @Test
    public void testTrafficLightExec() throws Exception {
        testJs("TrafficLightExec", "TrafficLightExec", "TrafficLightExecAddition.stjs", false);
    }

    @Test
    public void testReset() throws Exception {
        testJs("Reset");
    }

    @Test
    public void testCruiseController1() throws Exception {
        testJs("Cruise_finite1");
    }

    @Test
    public void testCruiseControllerk() throws Exception {
        testJs("Cruise_finite_k");
    }

    @Test
    public void testCruiseControllerDeterministic() throws Exception {
        testJs("Cruise_finite1_deterministic");
    }

    @Test
    public void testCruiseControllerDeterministicExec() throws Exception {
        testJs("Cruise_finite1_deterministic_exec");
    }

    @Test
    public void testScheduler() throws Exception {
        testJs("scheduler");
    }

    @Test
    public void testSchedulerDeterministic() throws Exception {
        testJs("scheduler_deterministic");
    }

    @Test
    public void testSchedulerDeterministicExec() throws Exception {
        testJs("scheduler_deterministic_exec");
    }

    @Test
    public void testCanBusTLC() throws Exception {
        testJs("CAN_BUS_tlc");
    }

    @Test
    public void testCanBusTLC_MC() throws Exception {
        testJSMC("CAN_BUS_tlc");
    }

    @Test
    public void testLandingGear() throws Exception {
        testJSMC("landing_gear/LandingGear_R6");
    }

    @Ignore
    @Test
    public void testCanBusTLCExec() throws Exception {
        testJs("CAN_BUS_tlc_exec");
    }

    @Test
    public void testCore() throws Exception {
        testJs("Core");
    }

    @Ignore
    @Test
    public void testSetLawsNAT() throws Exception {
        testJs("SetLawsNAT");
    }

    @Test
    public void SimpsonFourSlot() throws Exception {
        testJs("Simpson_Four_Slot");
    }

    @Test
    public void Train1BeebookTLC() throws Exception {
        testJs("Train_1_beebook_TLC");
    }

    @Test
    public void Train1BeebookDeterministic() throws Exception {
        testJs("Train_1_beebook_deterministic");
    }

    @Test
    public void Train1BeebookDeterministicExec() throws Exception {
        testJs("Train_1_beebook_deterministic_exec");
    }

    @Test
    public void Train1() throws Exception {
        testJs("train_1");
    }

    @Test
    public void Train1BeebookDeterministic_MC_POR() throws Exception {
        testJSMC("Train_1_beebook_deterministic_MC_POR");
    }

    @Test
    public void Train1BeebookDeterministic_MC_POR_v2() throws Exception {
        testJSMC("Train_1_beebook_deterministic_MC_POR_v2");
    }

    @Ignore
    @Test
    public void testEarley2() throws Exception {
        testJs("earley_2");
    }

    @Ignore
    @Test
    public void testOBSW_M001() throws Exception {
        testJs("obsw_M001");
    }

    @Ignore
    @Test
    public void testRef5Switch() throws Exception {
        testJs("Ref5_Switch");
    }

    @Ignore
    @Test
    public void testrether_mch1() throws Exception {
        testJs("rether_mch1");
    }

    @Test
    public void testsort_m2_data1000_MC() throws Exception {
        testJSMC("sort_m2_data1000_MC");
    }

    @Test
    public void testNota2() throws Exception {
        testJSMC("nota_v2");
    }

    @Test
    public void testCruiseControllerDeterministic_MC() throws Exception {
        testJSMC("Cruise_finite1_deterministic_MC");
    }

    @Test
    public void testLift_MC_Large() throws Exception {
        testJSMC("Lift_MC_Large");
    }

    @Test
    public void testQueensWithEvents_4() throws Exception {
        testJSMC("QueensWithEvents_4");
    }

}
