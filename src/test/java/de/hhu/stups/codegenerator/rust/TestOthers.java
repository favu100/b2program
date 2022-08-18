package de.hhu.stups.codegenerator.rust;

import org.junit.Test;

public class TestOthers extends TestRS{
    private final String PROB_OTHER_PATH = "../../../../benchmarks/model_checking/ProB/Other";
    @Test
    public void test_SetRelationConstructs() throws Exception {
        testRSMC("SetRelationConstructs", true);
    }

    @Test
    public void test_ArithmeticExpLaws() throws Exception {
        testRSMC("ArithmeticExpLaws", PROB_OTHER_PATH, true, true);
    }

    @Test
    public void test_ArithmeticLaws() throws Exception {
        testRSMC("ArithmeticLaws", PROB_OTHER_PATH, true);
    }

    @Test
    public void test_BoolLaws() throws Exception {
        testRSMC("BoolLaws", PROB_OTHER_PATH, true);
    }

    @Test
    public void test_BoolLaws_SetCompr() throws Exception {
        testRSMC("BoolLaws_SetCompr", PROB_OTHER_PATH, true, true);
    }

    @Test
    public void test_BoolWithArithLaws() throws Exception {
        testRSMC("BoolWithArithLaws", PROB_OTHER_PATH, true, true);
    }

    @Test
    public void test_CardinalityLaws() throws Exception {
        testRSMC("CardinalityLaws", PROB_OTHER_PATH, true, true);
    }

    @Test
    public void test_CSM() throws Exception {
        testRSMC("CSM", PROB_OTHER_PATH, true);
    }

    @Test
    public void test_Doors() throws Exception {
        testRSMC("Doors", PROB_OTHER_PATH, true);
    }

    @Test
    public void test_EqualityLaws() throws Exception {
        testRSMC("EqualityLaws", PROB_OTHER_PATH, true);
    }

    @Test
    public void test_ExplicitChecks() throws Exception {
        testRSMC("ExplicitChecks", PROB_OTHER_PATH, false);
    }

    @Test
    public void test_Fin1Test() throws Exception {
        testRSMC("Fin1Test", PROB_OTHER_PATH, true, true);
    }

    @Test
    public void test_NatRangeLaws() throws Exception {
        testRSMC("NatRangeLaws", PROB_OTHER_PATH, false);
    }

    @Test
    public void test_SetLaws() throws Exception {
        testRSMC("SetLaws", PROB_OTHER_PATH, true);
    }

    @Test
    public void test_SetLawsNat() throws Exception {
        testRSMC("SetLawsNat", PROB_OTHER_PATH, false);
    }

    @Test
    public void test_SetLawsPow() throws Exception {
        testRSMC("SetLawsPow", PROB_OTHER_PATH, true);
    }

    @Test
    public void test_SetLawsPow2() throws Exception {
        testRSMC("SetLawsPow2", PROB_OTHER_PATH, true);
    }

    @Test
    public void test_SetLawsPowPow() throws Exception {
        testRSMC("SetLawsPowPow", PROB_OTHER_PATH, false);
    }

    @Test
    public void test_SetLawsPowPowCart() throws Exception {
        testRSMC("SetLawsPowPowCart", PROB_OTHER_PATH, false);
    }
}
