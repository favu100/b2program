package de.hhu.stups.codegenerator.js;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
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
        testJSMC("Lift_MC", "Lift_MC", true, false);
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
        testJSMC("CAN_BUS_tlc", "CAN_BUS_tlc", true, false);
    }

    @Test
    public void testLandingGear() throws Exception {
        testJSMC("landing_gear/LandingGear_R6", "LandingGear_R6", true, false);
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

    @Test
    public void testSetLawsNAT() throws Exception {
        testJSMC("SetLawsNat", "SetLawsNat", true, false);
    }

    @Test
    public void testSetLawsPow() throws Exception {
        testJSMC("SetLawsPow", "SetLawsPow", true, false);
    }

    @Test
    public void testSetLawsPow2() throws Exception {
        testJSMC("SetLawsPow2", "SetLawsPow2", true, false);
    }

    @Test
    public void testSetRelLaws_NatBool() throws Exception {
        testJSMC("SetRelLaws_NatBool", "SetRelLaws_NatBool", false, false);
    }

    @Test
    public void testSetLawsPowPow() throws Exception {
        testJSMC("SetLawsPowPow");
    }

    @Test
    public void testSetLawsPowPowCart() throws Exception {
        testJSMC("SetLawsPowPowCart");
    }

    @Test
    public void testSubsetLaws() throws Exception {
        testJSMC("SubsetLaws", "SubsetLaws", true, false);
    }

    @Test
    public void testINTEGERSET_Laws() throws Exception {
        testJSMC("INTEGERSET_Laws", "INTEGERSET_Laws", true, false);
    }

    @Test
    public void testFinitenessLaws() throws Exception {
        testJSMC("FinitenessLaws", "FinitenessLaws", true, false);
    }

    @Test
    public void testSubstitutionLaws() throws Exception {
        testJSMC("SubstitutionLaws", "SubstitutionLaws", true, false);
    }

    @Test(expected = CodeGenerationException.class)
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

    @Test(expected = CodeGenerationException.class)
    public void Train1() throws Exception {
        testJs("train_1");
    }

    @Test
    public void Train2() throws Exception {
        testJs("train_2");
    }

    @Test
    public void Train1BeebookDeterministic_MC_POR() throws Exception {
        testJSMC("Train_1_beebook_deterministic_MC_POR");
    }

    @Test
    public void Train1BeebookDeterministic_MC_POR_v2() throws Exception {
        testJSMC("Train_1_beebook_deterministic_MC_POR_v2");
    }

    @Test
    public void Train1BeebookDeterministic_MC_POR_v3() throws Exception {
        testJSMC("Train_1_beebook_deterministic_MC_POR_v3", "Train_1_beebook_deterministic_MC_POR_v3", true, true);
    }

    @Ignore
    @Test
    public void testEarley2() throws Exception {
        testJs("earley_2");
    }

    @Test
    public void testOBSW_M001_1() throws Exception {
        testJSMC("obsw_M001_1", "obsw_M001_1", true, false);
    }

    @Test
    public void testOBSW_M001() throws Exception {
        testJSMC("obsw_M001_2", "obsw_M001_2", true, false);
    }

    @Ignore
    @Test
    public void testRef5Switch() throws Exception {
        testJs("Ref5_Switch");
    }

    @Test
    public void testrether_mch1() throws Exception {
        testJSMC("rether", "rether", true, true);
    }

    @Test
    public void testsort_m2_data1000_MC() throws Exception {
        testJSMC("sort_m2_data1000_MC");
    }

    @Test
    public void testNota2() throws Exception {
        testJSMC("nota_v2", "nota_v2", true, false);
    }

    @Test
    public void testCruiseControllerDeterministic_MC() throws Exception {
        testJSMC("Cruise_finite1_deterministic_MC", "Cruise_finite1_deterministic_MC", true, false);
    }

    @Test
    public void testLift_MC_Large() throws Exception {
        testJSMC("Lift_MC_Large", "Lift_MC_Large", true, false);
    }

    @Test
    public void testQueensWithEvents_4() throws Exception {
        testJSMC("QueensWithEvents_4");
    }

    @Test
    public void testProBOneWay8Seq() throws Exception {
        testJSMC("prob_oneway8seq");
    }

    @Test
    public void testWhile2() throws Exception {
        testJSMC("While2");
    }

}
