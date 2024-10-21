package de.hhu.stups.codegenerator.java;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
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
    public void testLift_MC_With_Execute() throws Exception {
        testJavaMC("Lift_MC", "Lift_MC", true, 1, false);
    }

    @Test
    public void testTravelAgency() throws Exception {
        testJava("TravelAgency");
    }

    @Test
    public void testSortExec() throws Exception {
        testJava("sort_m2_data1000_exec", "sort_m2_data1000_exec", "sort_m2_data1000_execAddition.stjava", false);
    }

    @Test
    public void testSchedulerExec() throws Exception {
        testJava("scheduler_deterministic_exec", "scheduler_deterministic_exec", "scheduler_deterministic_execAddition.stjava", false);
    }

    @Test
    public void testTrainExec() throws Exception {
        testJava("Train_1_beebook_deterministic_exec", "Train_1_beebook_deterministic_exec", "Train_1_beebook_deterministic_execAddition.stjava", false);
    }

    @Test
    public void testCruiseExec() throws Exception {
        testJava("Cruise_finite1_deterministic_exec", "Cruise_finite1_deterministic_exec", "Cruise_finite1_deterministic_execAddition.stjava", false);
    }

    @Test
    public void testCANBUSExec() throws Exception {
        testJava("CAN_BUS_tlc_exec", "CAN_BUS_tlc_exec", "CAN_BUS_tlc_execAddition.stjava", false);
    }

    @Test
    public void testTrafficLightMC() throws Exception {
        testJavaMC("TrafficLight_MC");
    }

    @Test
    public void testTrafficLightMC_With_Execute() throws Exception {
        testJavaMC("TrafficLight_MC", "TrafficLight_MC", true, 1, false);
    }

    @Test
    public void testTrafficLight() throws Exception {
        testJava("TrafficLight", "TrafficLight", "TrafficLightAddition.stjava", true);
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
    public void testCruiseControllerDeterministic_MC_With_Execute() throws Exception {
        testJavaMC("Cruise_finite1_deterministic_MC", "Cruise_finite1_deterministic_MC", true, 1, false);
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
    public void testSchedulerDeterministicMC_With_Execute() throws Exception {
        testJavaMC("scheduler_deterministic_MC", "scheduler_deterministic_MC", true, 1, false);
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
    public void testCanBusMC_With_Execute() throws Exception {
        testJavaMC("CAN_BUS_tlc", "CAN_BUS_tlc", true, 1, false);
    }

    @Test
    public void testCanBusTLCExec() throws Exception {
        testJava("CAN_BUS_tlc_exec");
    }

    @Test
    public void testCore() throws Exception {
        testJava("Core");
    }

    @Test
    public void testSetLawsNAT() throws Exception {
        testJava("SetLawsNat");
    }

    @Test(expected = CodeGenerationException.class)
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
    public void Train1LukasPORv3_With_Execute() throws Exception {
        testJavaMC("Train1_Lukas_POR_v3", "Train1_Lukas_POR_v3", true, 1, false);
    }

    @Test
    public void Train1LukasPORv4() throws Exception {
        testJavaMC("Train1_Lukas_POR_v4");
    }

    @Test
    public void Train1LukasPORv4_With_Execute() throws Exception {
        testJavaMC("Train1_Lukas_POR_v4", "Train1_Lukas_POR_v4", true, 1, false);
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
    public void Train1BeebookDeterministic_MC_POR_v3() throws Exception {
        testJavaMC("Train_1_beebook_deterministic_MC_POR_v3", "Train_1_beebook_deterministic_MC_POR_v3", true, 8, true);
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
    public void ThreeCounter_With_Execute() throws Exception {
        testJavaMC("ThreeCounter", "ThreeCounter", true, 1, false);
    }

    @Test
    public void ThreeCounter2() throws Exception {
        testJavaMC("ThreeCounter2");
    }

    @Test
    public void ThreeCounter2_With_Execute() throws Exception {
        testJavaMC("ThreeCounter2", "ThreeCounter2", true, 1, false);
    }

    @Test
    public void testsort_m2_data1000() throws Exception {
        testJava("sort_m2_data1000");
    }

    @Test
    public void testsort_m2_data1000_MC() throws Exception {
        testJavaMC("sort_m2_data1000_MC", "sort_m2_data1000_MC", true, 1, true);
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
    public void testSensors() throws Exception {
        testJavaMC("visualisation/Sensors");
    }

    @Test
    public void testBlinkLamps() throws Exception {
        testJavaMC("visualisation/BlinkLamps_v3");
    }

    @Test(expected = CodeGenerationException.class)
    public void testGenericTimers() throws Exception {
        testJavaMC("visualisation/GenericTimersMC");
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
    public void testLandingGear_MC_With_Execute() throws Exception {
        testJavaMC("landing_gear/LandingGear_R6", "LandingGear_R6", true, 1, false);
    }

    @Test
    public void testQueensWithEvents_4() throws Exception {
        testJavaMC("QueensWithEvents_4");
    }

    @Test
    public void testQueensWithEvents_4_With_Execute() throws Exception {
        testJavaMC("QueensWithEvents_4", "QueensWithEvents_4", true, 1, false);
    }

    @Test
    public void testQueensWithEvents_8() throws Exception {
        testJavaMC("QueensWithEvents_8");
    }

    @Test
    public void testArithmeticLaws() throws Exception {
        testJavaMC("ArithmeticLaws");
    }

    @Test
    public void testArithmeticLaws_With_Execute() throws Exception {
        testJavaMC("ArithmeticLaws", "ArithmeticLaws", true, 1, false);
    }

    @Test
    public void testArithmeticExpLaws_With_Execute() throws Exception {
        testJavaMC("ArithmeticExpLaws", "ArithmeticExpLaws", false, 1, false);
    }

    @Test
    public void testBoolLaws_With_Execute() throws Exception {
        testJavaMC("BoolLaws", "BoolLaws", true, 1, false);
    }

    @Test
    public void testBoolWithArithLaws_With_Execute() throws Exception {
        testJavaMC("BoolWithArithLaws", "BoolWithArithLaws", true, 1, false);
    }

    @Test
    public void testBoolLaws_SetCompr_With_Execute() throws Exception {
        testJavaMC("BoolLaws_SetCompr", "BoolLaws_SetCompr", true, 1, false);
    }

    @Test
    public void testCardinalityLaws() throws Exception {
        testJavaMC("CardinalityLaws", "CardinalityLaws", true, 1, false);
    }

    @Test
    public void testEqualityLaws() throws Exception {
        testJavaMC("EqualityLaws", "EqualityLaws", true, 1, false);
    }

    @Test
    public void testExplicitChecks() throws Exception {
        testJavaMC("ExplicitChecks", "ExplicitChecks", true, 1, false);
    }

    @Test
    public void testExplicitComputations() throws Exception {
        testJavaMC("ExplicitComputations", "ExplicitComputations", false, 1, false);
    }

    @Test
    public void testExplicitComputations_Small() throws Exception {
        testJavaMC("ExplicitComputations_Small", "ExplicitComputations_Small", true, 1, false);
    }

    @Test
    public void testExplicitComputations_Small2() throws Exception {
        testJavaMC("ExplicitComputations_Small2", "ExplicitComputations_Small2", true, 1, false);
    }

    @Test
    public void testExplicitComputations2() throws Exception {
        testJavaMC("ExplicitComputations2", "ExplicitComputations2", true, 1, false);
    }

    @Test
    public void testExplicitChecks_Old() throws Exception {
        testJavaMC("ExplicitChecks_Old", "ExplicitChecks_Old", true, 1, false);
    }

    @Test
    public void testExplicitChecks_Small() throws Exception {
        testJavaMC("ExplicitChecks_Small", "ExplicitChecks_Old", false, 1, false);
    }

    @Test
    public void testFin1Test() throws Exception {
        testJavaMC("Fin1Test", "Fin1Test", true, 1, false);
    }

    @Test
    public void testLargeFunction() throws Exception {
        testJavaMC("LargeFunction", "LargeFunction", true, 1, false);
    }

    @Test
    public void testSetLaws() throws Exception {
        testJavaMC("SetLaws", "SetLaws", true, 1, false);
    }

    @Test
    public void testSetRelLaws_NatBool() throws Exception {
        testJavaMC("SetRelLaws_NatBool", "SetRelLaws_NatBool", true, 1, false);
    }

    @Test
    public void testWDCheck() throws Exception {
        testJavaMC("WDCheck", "WDCheck", true, 1, false);
    }

    @Test
    public void testSetLawsNat() throws Exception {
        testJavaMC("SetLawsNat", "SetLawsNat", true, 1, false);
    }

    @Test
    public void testSetLawsNatural() throws Exception {
        testJavaMC("SetLawsNatural", "SetLawsNatural", false, 1, false);
    }

    @Test
    public void testSetLawsPow() throws Exception {
        testJavaMC("SetLawsPow", "SetLawsPow", true, 1, false);
    }

    @Test
    public void testSetLawsPow2() throws Exception {
        testJavaMC("SetLawsPow2", "SetLawsPow2", true, 1, false);
    }

    @Test
    public void testSetLawsPowPow() throws Exception {
        testJavaMC("SetLawsPowPow", "SetLawsPowPow", false, 1, false);
    }

    @Test
    public void testSetLawsPowPowCart() throws Exception {
        testJavaMC("SetLawsPowPowCart", "SetLawsPowPowCart", false, 1, false);
    }

    @Test
    public void testSeqLaws() throws Exception {
        testJavaMC("SeqLaws", "SeqLaws", true, 1, false);
    }

    @Test
    public void testINTEGERSET_Laws() throws Exception {
        testJavaMC("INTEGERSET_Laws", "INTEGERSET_Laws", true, 1, false);
    }

    @Test
    public void testStringLaws() throws Exception {
        testJavaMC("StringLaws", "StringLaws", true, 1, false);
    }

    @Test
    public void testSubsetLaws() throws Exception {
        testJavaMC("SubsetLaws", "SubsetLaws", true, 1, false);
    }

    @Test
    public void testSubstitutionLaws() throws Exception {
        testJavaMC("SubstitutionLaws", "SubstitutionLaws", true, 1, false);
    }

    @Test
    public void testNatRangeLaws() throws Exception {
        testJavaMC("NatRangeLaws", "NatRangeLaws", true, 1, true);
    }

    @Test
    public void testRelLaws() throws Exception {
        testJavaMC("RelLaws", "RelLaws", false, 1, false);
    }

    @Test
    public void testRelLaws_Small() throws Exception {
        testJavaMC("RelLaws_Small", "RelLaws_Small", true, 1, false);
    }

    @Test
    public void testRelLaws_Small2() throws Exception {
        testJavaMC("RelLaws_Small2", "RelLaws_Small2", true, 1, false);
    }

    @Test
    public void testCompositionEmpty() throws Exception {
        testJavaMC("CompositionEmpty", "CompositionEmpty", true, 1, false);
    }

    @Test
    public void testFunLaws() throws Exception {
        testJavaMC("FunLaws", "FunLaws", true, 1, false);
    }

    @Test
    public void testRelLaws_BOOL1() throws Exception {
        testJavaMC("RelLaws_BOOL1", "RelLaws_BOOL1", false, 1, false);
    }

    @Test
    public void testRether() throws Exception {
        testJavaMC("rether", "rether", true, 1, false);
    }

    @Test
    public void testOBSW1() throws Exception {
        testJavaMC("obsw_M001_1", "obsw_M001_1", true, 1, false);
    }

    @Test
    public void testOBSW2() throws Exception {
        testJavaMC("obsw_M001_2", "obsw_M001_2", true, 1, true);
    }

    @Test
    public void testPruningTest() throws Exception {
        testJavaMC("PruningTest", "PruningTest", true, 1, false);
    }

    @Test
    public void testFinitenessLaws() throws Exception {
        testJavaMC("FinitenessLaws", "FinitenessLaws", true, 1, false);
    }

    @Test
    public void testTautologiesPL() throws Exception {
        testJavaMC("TautologiesPL", "TautologiesPL", true, 1, false);
    }

    @Test
    public void testTicTac() throws Exception {
        testJavaMC("tictac", "tictac", true, 1, false);
    }

    @Ignore
    @Test
    public void testNota() throws Exception {
        testJavaMC("nota");
    }

    @Test
    public void testNota2() throws Exception {
        testJavaMC("nota_v2");
    }

    @Test
    public void testNota2_With_Execute() throws Exception {
        testJavaMC("nota_v2", "nota_v2", true, 1, false);
    }

    @Test
    public void testIntervalInterval() throws Exception {
        testJavaMC("IntervalInterval", "IntervalInterval", true, 1, false);
    }

    @Test
    public void testNotInDomainOptimization() throws Exception {
        testJavaMC("NotInDomainOptimization", "NotInDomainOptimization", true, 1, false);
    }

    @Test
    public void testInDomainOptimization() throws Exception {
        testJavaMC("InDomainOptimization", "InDomainOptimization", true, 1, false);
    }

    @Test
    public void testRange() throws Exception {
        testJavaMC("Range");
    }

    @Test
    public void testFunctionAssigningConstant() throws Exception {
        testJavaMC("FunctionAssigningConstant", "FunctionAssigningConstant", true, 1, false);
    }

    @Test(expected = CodeGenerationException.class)
    public void testLibrary3_3() throws Exception {
        testJavaMC("Library_3_3");
    }

    @Test
    public void testLift_MC_Large() throws Exception {
        testJavaMC("Lift_MC_Large");
    }

    @Ignore
    @Test
    public void testNondeterministic_MC() throws Exception {
        testJavaMC("Nondeterminism_MC");
    }

    @Ignore
    @Test
    public void testNondeterministic2_MC() throws Exception {
        testJavaMC("Nondeterminism2_MC");
    }

    @Ignore
    @Test
    public void testNondeterministic3_MC() throws Exception {
        testJavaMC("Nondeterminism3_MC");
    }

    @Ignore
    @Test
    public void testNondeterministic4_MC() throws Exception {
        testJavaMC("Nondeterminism4_MC");
    }

    @Ignore
    @Test
    public void testNondeterministic5_MC() throws Exception {
        testJavaMC("Nondeterminism5_MC");
    }

    @Ignore
    @Test
    public void testNondeterministic6_MC() throws Exception {
        testJavaMC("Nondeterminism6_MC");
    }

    @Ignore
    @Test
    public void testNondeterministic7_MC() throws Exception {
        testJavaMC("Nondeterminism7_MC");
    }

    @Ignore
    @Test
    public void testNondeterministic8_MC() throws Exception {
        testJavaMC("Nondeterminism8_MC");
    }

    @Ignore
    @Test
    public void testNondeterministic9_MC() throws Exception {
        testJavaMC("Nondeterminism9_MC");
    }

    @Ignore
    @Test
    public void testNondeterministic10_MC() throws Exception {
        testJavaMC("Nondeterminism10_MC");
    }

    @Ignore
    @Test
    public void testChoice_MC() throws Exception {
        testJavaMC("Choice_MC");
    }


    // Constants not assigned specifically
    @Test(expected = CodeGenerationException.class)
    public void testGenerated100MC() throws Exception {
        testJavaMC("Generated100");
    }

    @Test
    public void testGenerated126_small_mc() throws Exception {
        testJavaMC("Generated126_small_mc");
    }

    @Test
    public void testWhile2() throws Exception {
        testJavaMC("While2");
    }

    @Test
    public void testProb_oneway8seq() throws Exception {
        testJavaMC("prob_oneway8seq", "prob_oneway8seq", true, 1, false);
    }

}