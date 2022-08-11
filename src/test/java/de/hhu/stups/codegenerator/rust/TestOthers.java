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
}
