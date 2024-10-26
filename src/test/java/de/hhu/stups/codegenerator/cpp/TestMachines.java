package de.hhu.stups.codegenerator.cpp;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Ignore;
import org.junit.Test;

public class TestMachines extends TestCpp {

    @Test
    public void testExample() throws Exception {
        testCpp("Example");
    }

    @Test
    public void testOperation() throws Exception {
        testCpp("Operation", "Operation", "OperationAddition.stcpp", true);
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
        testCpp("Counter", "Counter", "CounterAddition.stcpp", true);
    }

    @Test
    public void testBakery0() throws Exception {
        testCpp("Bakery0", "Bakery0", "Bakery0Addition.stcpp", true);
    }

    @Test
    public void testGCD() throws Exception {
        testCpp("GCD");
    }

    @Test
    public void testACounter() throws Exception {
        testCpp("ACounter", "ACounter", "ACounterAddition.stcpp", true);
    }

    @Test
    public void testLift() throws Exception {
        testCpp("Lift", "Lift", "LiftAddition.stcpp", true);
    }

    @Test
    public void testTravelAgency() throws Exception {
        testCpp("TravelAgency");
    }

    @Test
    public void testTrafficLight() throws Exception {
        testCpp("TrafficLight", "TrafficLight", "TrafficLightAddition.stcpp", true);
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
        testCpp("Sieve", "Sieve", "SieveAddition.stcpp", true);
    }

    @Test
    public void testSieveParallel() throws Exception {
        testCpp("SieveParallel", "SieveParallel", "SieveParallelAddition.stcpp", true);
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
        testCppMC("Cruise_finite1_deterministic_MC", "Cruise_finite1_deterministic_MC", true, 1, false);
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
        testCppMC("CAN_BUS_tlc", "CAN_BUS_tlc", true, 1, false);
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

    @Test
    public void testSetLawsNAT() throws Exception {
        testCppMC("SetLawsNat", "SetLawsNat", true, 1, false);
    }

    @Test
    public void testSetLawsPow() throws Exception {
        testCppMC("SetLawsPow", "SetLawsPow", true, 1, false);
    }

    @Test
    public void testSetLawsPow2() throws Exception {
        testCppMC("SetLawsPow2", "SetLawsPow2", true, 1, false);
    }

    @Test
    public void testSetRelLaws_NatBool() throws Exception {
        testCppMC("SetRelLaws_NatBool", "SetRelLaws_NatBool", false, 1, false);
    }

    @Test
    public void testSetLawsPowPow() throws Exception {
        testCppMC("SetLawsPowPow");
    }

    @Test
    public void testSetLawsPowPowCart() throws Exception {
        testCppMC("SetLawsPowPowCart");
    }

    @Ignore
    @Test
    public void testRelLaws() throws Exception {
        testCppMC("RelLaws", "RelLaws", false, 1, false);
    }

    @Test
    public void testRelLaws_Small() throws Exception {
        testCppMC("RelLaws_Small", "RelLaws_Small", true, 1, false);
    }

    @Test
    public void testRelLaws_Small2() throws Exception {
        testCppMC("RelLaws_Small2", "RelLaws_Small2", true, 1, false);
    }

    @Test
    public void testCompositionEmpty() throws Exception {
        testCppMC("CompositionEmpty", "CompositionEmpty", true, 1, false);
    }

    @Test
    public void testFunLaws() throws Exception {
        testCppMC("FunLaws", "FunLaws", true, 1, false);
    }

    @Test
    public void testBoolLawsSetCompr() throws Exception {
        testCppMC("BoolLaws_SetCompr", "BoolLaws_SetCompr", true, 1, false);
    }

    @Test
    public void testSeqLaws() throws Exception {
        testCppMC("SeqLaws", "SeqLaws", true, 1, false);
    }

    @Test
    public void testNatRangeLaws() throws Exception {
        testCppMC("NatRangeLaws", "NatRangeLaws", true, 1, true);
    }

    @Test
    public void testLargeFunction() throws Exception {
        testCppMC("LargeFunction", "LargeFunction", true, 1, false);
    }

    @Test
    public void testFin1Test() throws Exception {
        testCppMC("Fin1Test", "Fin1Test", true, 1, false);
    }

    @Test
    public void testCardinalityLaws() throws Exception {
        testCppMC("CardinalityLaws", "CardinalityLaws", true, 1, false);
    }

    @Test
    public void testEqualityLaws() throws Exception {
        testCppMC("EqualityLaws", "EqualityLaws", true, 1, false);
    }

    @Test
    public void testSubsetLaws() throws Exception {
        testCppMC("SubsetLaws", "SubsetLaws", true, 1, false);
    }

    @Test
    public void testINTEGERSET_Laws() throws Exception {
        testCppMC("INTEGERSET_Laws", "INTEGERSET_Laws", true, 1, false);
    }

    @Test
    public void testFinitenessLaws() throws Exception {
        testCppMC("FinitenessLaws", "FinitenessLaws", true, 1, false);
    }

    @Test
    public void testSubstitutionLaws() throws Exception {
        testCppMC("SubstitutionLaws", "SubstitutionLaws", true, 1, false);
    }

    @Test
    public void testBoolWithArithLaws_With_Execute() throws Exception {
        testCppMC("BoolWithArithLaws", "BoolWithArithLaws", true, 1, false);
    }

    @Test
    public void testArithmeticLaws_With_Execute() throws Exception {
        testCppMC("ArithmeticLaws", "ArithmeticLaws", true, 1, false);
    }

    @Test
    public void testArithmeticExpLaws_With_Execute() throws Exception {
        testCppMC("ArithmeticExpLaws", "ArithmeticExpLaws", false, 1, false);
    }

    @Test
    public void testBoolLaws_With_Execute() throws Exception {
        testCppMC("BoolLaws", "BoolLaws", true, 1, false);
    }

    @Test
    public void testExplicitChecks() throws Exception {
        testCppMC("ExplicitChecks", "ExplicitChecks", true, 1, false);
    }

    @Test
    public void testExplicitComputations_Small() throws Exception {
        testCppMC("ExplicitComputations_Small", "ExplicitComputations_Small", true, 1, false);
    }

    @Test
    public void testExplicitComputations_Small2() throws Exception {
        testCppMC("ExplicitComputations_Small2", "ExplicitComputations_Small2", true, 1, false);
    }

    @Test
    public void testExplicitComputations2() throws Exception {
        testCppMC("ExplicitComputations2", "ExplicitComputations2", true, 1, false);
    }

    @Test(expected = CodeGenerationException.class)
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
    public void Train1BeebookDeterministic_MC_POR_v3() throws Exception {
        testCppMC("Train_1_beebook_deterministic_MC_POR_v3", "Train_1_beebook_deterministic_MC_POR_v3", false, 1, true);
    }

    @Test
    public void testLandingGear_MC() throws Exception {
        testCppMC("landing_gear/LandingGear_R6", "LandingGear_R6", true, 1, false);
    }

    @Test
    public void Train1BeebookDeterministicExec() throws Exception {
        testCpp("Train_1_beebook_deterministic_exec");
    }

    @Test(expected = CodeGenerationException.class)
    public void Train1() throws Exception {
        testCpp("train_1");
    }

    @Test
    public void Train2() throws Exception {
        testCpp("train_2");
    }

    @Ignore
    @Test
    public void testEarley2() throws Exception {
        testCpp("earley_2");
    }

    @Test
    public void testOBSW_M001_1() throws Exception {
        testCppMC("obsw_M001_1", "obsw_M001_1", true, 1, false);
    }

    @Test
    public void testOBSW_M001_2() throws Exception {
        testCppMC("obsw_M001_2", "obsw_M001_2", true, 1, false);
    }

    @Ignore
    @Test
    public void testRef5Switch() throws Exception {
        testCpp("Ref5_Switch");
    }

    @Test
    public void testRether() throws Exception {
        testCppMC("rether", "rether", true, 1, false);
    }

    @Test
    public void testQueensWithEvents_4() throws Exception {
        testCppMC("QueensWithEvents_4");
    }

    @Test
    public void testQueensWithEvents_8() throws Exception {
        testCppMC("QueensWithEvents_8");
    }

    @Test
    public void testNota2() throws Exception {
        testCppMC("nota_v2", "nota_v2", true, 1, false);
    }

    @Test
    public void testArithmeticLaws() throws Exception {
        testCppMC("ArithmeticLaws");
    }

    @Test
    public void testLift_MC_Large() throws Exception {
        testCppMC("Lift_MC_Large", "Lift_MC_Large", true, 1, false);
    }

    @Test
    public void testProBOneWaySeq8() throws Exception {
        testCppMC("prob_oneway8seq", "prob_oneway8seq", true, 1, false);
    }

    @Test
    public void testLift_MC() throws Exception {
        testCppMC("Lift_MC", "Lift_MC", true, 1, false);
    }

    @Test
    public void testWhile2() throws Exception {
        testCppMC("While2");
    }

}
