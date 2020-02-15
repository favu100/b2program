package de.hhu.stups.codegenerator.cpp;

import org.junit.Test;

public class TestLustre extends TestCpp {

    @Test
    public void testCOUNT() throws Exception {
        testCpp("lustre/COUNT", "COUNT", "COUNTAddition.stcpp", true);
    }

    @Test
    public void testCurrent2() throws Exception {
        testCpp("lustre/Current2", "Current2", "Current2Addition.stcpp", true);
    }

    @Test
    public void testExprList() throws Exception {
        testCpp("lustre/expr_list", "expr_list", "expr_listAddition.stcpp", true);
    }

    @Test
    public void testExprList2() throws Exception {
        testCpp("lustre/expr_list2", "expr_list2", "expr_list2Addition.stcpp", true);
    }

    @Test
    public void testExprList3() throws Exception {
        testCpp("lustre/expr_list3", "expr_list3", "expr_list3Addition.stcpp", true);
    }

    @Test
    public void testExprList4() throws Exception {
        testCpp("lustre/expr_list4", "expr_list4", "expr_list4Addition.stcpp", true);
    }

    @Test
    public void testExprList5() throws Exception {
        testCpp("lustre/expr_list5", "expr_list5", "expr_list5Addition.stcpp", true);
    }

    @Test
    public void testExprList6() throws Exception {
        testCpp("lustre/expr_list6", "expr_list6", "expr_list6Addition.stcpp", true);
    }

    @Test
    public void testFby2() throws Exception {
        testCpp("lustre/Fby2", "Fby2", "Fby2Addition.stcpp", true);
    }

    @Test
    public void testLift() throws Exception {
        testCpp("lustre/Lift", "Lift", "LiftAddition.stcpp", true);
    }

    @Test
    public void testLiftVerif() throws Exception {
        testCpp("lustre/Lift_verif", "Lift_verif", "Lift_verifAddition.stcpp", true);
    }

    @Test
    public void testLiftVerifError() throws Exception {
        testCpp("lustre/Lift_verif_error", "Lift_verif_error", "Lift_verif_errorAddition.stcpp", true);
    }

    @Test
    public void testPre() throws Exception {
        testCpp("lustre/Pre", "Pre", "PreAddition.stcpp", true);
    }

    @Test
    public void testPre2() throws Exception {
        testCpp("lustre/Pre2", "Pre2", "Pre2Addition.stcpp", true);
    }

    @Test
    public void testPre3() throws Exception {
        testCpp("lustre/Pre3", "Pre3", "Pre3Addition.stcpp", true);
    }

    @Test
    public void testPre4() throws Exception {
        testCpp("lustre/Pre4", "Pre4", "Pre4Addition.stcpp", true);
    }

    @Test
    public void testPre5() throws Exception {
        testCpp("lustre/Pre5", "Pre5", "Pre5Addition.stcpp", true);
    }

    @Test
    public void testPre6() throws Exception {
        testCpp("lustre/Pre6", "Pre6", "Pre6Addition.stcpp", true);
    }

    @Test
    public void testSLOW_TIME_STABLE() throws Exception {
        testCpp("lustre/SLOW_TIME_STABLE", "SLOW_TIME_STABLE", "SLOW_TIME_STABLEAddition.stcpp", true);
    }

    @Test
    public void testTIME_STABLE() throws Exception {
        testCpp("lustre/TIME_STABLE", "TIME_STABLE", "TIME_STABLEAddition.stcpp", true);
    }

    @Test
    public void testWhen4() throws Exception {
        testCpp("lustre/When4", "When4", "When4Addition.stcpp", true);
    }

    @Test
    public void testWhen8() throws Exception {
        testCpp("lustre/When8", "When8", "When8Addition.stcpp", true);
    }

    @Test
    public void testUMS() throws Exception {
        testCpp("lustre/UMS", "UMS", "UMSAddition.stcpp", true);
    }

    @Test
    public void testUMS_verif() throws Exception {
        testCpp("lustre/UMS_verif", "UMS_verif", "UMS_verifAddition.stcpp", true);
    }

}
