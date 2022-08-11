package de.hhu.stups.codegenerator.rust;

import org.junit.Test;

public class TestOthers extends TestRS{
    @Test
    public void test_SetRelationConstructs() throws Exception {
        testRSMC("SetRelationConstructs", true);
    }

    @Test
    public void test_ArithmeticExpLaws() throws Exception {
        testRSMC("ArithmeticExpLaws", "../../../../benchmarks/model_checking/ProB/Other", true, true);
    }
}
