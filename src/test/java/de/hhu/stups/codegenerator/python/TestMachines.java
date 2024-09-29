package de.hhu.stups.codegenerator.python;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Ignore;
import org.junit.Test;

public class TestMachines extends TestPython {

    @Test
    public void testExample() throws Exception {
        testPython("Example");
    }

    @Test
    public void testOperation() throws Exception {
        testPython("Operation", "Operation", "OperationAddition.stpy", true);
    }

    @Test
    public void testOperation2() throws Exception {
        testPython("Operation2");
    }

    @Test
    public void testLocalDeclaration() throws Exception {
        testPython("LocalDeclaration");
    }

    @Test
    public void testCounter() throws Exception {
        testPython("Counter", "Counter", "CounterAddition.stpy", true);
    }

    @Test
    public void testBakery0() throws Exception {
        testPython("Bakery0", "Bakery0", "Bakery0Addition.stpy", true);
    }

    @Test
    public void testGCD() throws Exception {
        testPython("GCD");
    }

    @Test
    public void testACounter() throws Exception {
        testPython("ACounter", "ACounter", "ACounterAddition.stpy", true);
    }

    @Test
    public void testLift() throws Exception {
        testPython("Lift", "Lift", "LiftAddition.stpy", true);
    }

    @Test
    public void testTravelAgency() throws Exception {
        testPython("TravelAgency");
    }

    @Test
    public void testTrafficLight() throws Exception {
        testPython("TrafficLight", "TrafficLight", "TrafficLightAddition.stpy", true);
    }

    @Test
    public void testPhonebook() throws Exception {
        testPython("phonebook");
    }

    @Test
    public void testPhonebook6() throws Exception {
        testPython("phonebook6");
    }

    @Test
    public void testSieve() throws Exception {
        testPython("Sieve", "Sieve", "SieveAddition.stpy", true);
    }

    @Test
    public void testSieveParallel() throws Exception {
        testPython("SieveParallel", "SieveParallel", "SieveParallelAddition.stpy", true);
    }

    @Test
    public void testReset() throws Exception {
        testPython("Reset");
    }

    @Test
    public void testCruiseController1() throws Exception {
        testPython("Cruise_finite1");
    }

    @Test
    public void testCruiseControllerk() throws Exception {
        testPython("Cruise_finite_k");
    }

    @Test
    public void testCruiseControllerDeterministic() throws Exception {
        testPython("Cruise_finite1_deterministic");
    }

    @Test
    public void testCruiseControllerDeterministicExec() throws Exception {
        testPython("Cruise_finite1_deterministic_exec");
    }

    @Test
    public void testScheduler() throws Exception {
        testPython("scheduler");
    }

    @Test
    public void testSchedulerDeterministic() throws Exception {
        testPython("scheduler_deterministic");
    }

    @Test
    public void testSchedulerDeterministicExec() throws Exception {
        testPython("scheduler_deterministic_exec");
    }

    @Test
    public void testCanBusTLC() throws Exception {
        testPython("CAN_BUS_tlc");
    }

    @Test
    public void testCanBusTLCExec() throws Exception {
        testPython("CAN_BUS_tlc_exec");
    }

    @Test
    public void testCore() throws Exception {
        testPython("Core");
    }

    @Ignore
    @Test
    public void testSetLawsNAT() throws Exception {
        testPython("SetLawsNAT");
    }

    @Test(expected = CodeGenerationException.class)
    public void SimpsonFourSlot() throws Exception {
        testPython("Simpson_Four_Slot");
    }

    @Test
    public void Train1BeebookTLC() throws Exception {
        testPython("Train_1_beebook_TLC");
    }

    @Test
    public void Train1BeebookDeterministic() throws Exception {
        testPython("Train_1_beebook_deterministic");
    }

    @Test
    public void Train1BeebookDeterministicExec() throws Exception {
        testPython("Train_1_beebook_deterministic_exec");
    }

    @Test
    public void Train1() throws Exception {
        testPython("train_1");
    }

    @Ignore
    @Test
    public void testEarley2() throws Exception {
        testPython("earley_2");
    }

    @Ignore
    @Test
    public void testOBSW_M001() throws Exception {
        testPython("obsw_M001");
    }

    @Ignore
    @Test
    public void testRef5Switch() throws Exception {
        testPython("Ref5_Switch");
    }

    @Ignore
    @Test
    public void testrether_mch1() throws Exception {
        testPython("rether_mch1");
    }

}
