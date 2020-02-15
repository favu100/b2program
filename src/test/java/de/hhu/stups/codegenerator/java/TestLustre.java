package de.hhu.stups.codegenerator.java;

import org.junit.Test;

public class TestLustre extends TestJava {

    @Test
    public void testCOUNT() throws Exception {
        testJava("lustre/COUNT", "COUNT", "COUNTAddition.stjava", true);
    }

    @Test
    public void testCurrent2() throws Exception {
        testJava("lustre/Current2", "Current2", "Current2Addition.stjava", true);
    }

    @Test
    public void testExprList() throws Exception {
        testJava("lustre/expr_list", "expr_list", "expr_listAddition.stjava", true);
    }

    @Test
    public void testExprList2() throws Exception {
        testJava("lustre/expr_list2", "expr_list2", "expr_list2Addition.stjava", true);
    }

    @Test
    public void testExprList3() throws Exception {
        testJava("lustre/expr_list3", "expr_list3", "expr_list3Addition.stjava", true);
    }

    @Test
    public void testExprList4() throws Exception {
        testJava("lustre/expr_list4", "expr_list4", "expr_list4Addition.stjava", true);
    }

    @Test
    public void testExprList5() throws Exception {
        testJava("lustre/expr_list5", "expr_list5", "expr_list5Addition.stjava", true);
    }

    @Test
    public void testExprList6() throws Exception {
        testJava("lustre/expr_list6", "expr_list6", "expr_list6Addition.stjava", true);
    }

    @Test
    public void testFby2() throws Exception {
        testJava("lustre/Fby2", "Fby2", "Fby2Addition.stjava", true);
    }

    @Test
    public void testLift() throws Exception {
        testJava("lustre/Lift", "Lift", "LiftAddition.stjava", true);
    }

    @Test
    public void testLiftVerif() throws Exception {
        testJava("lustre/Lift_verif", "Lift_verif", "Lift_verifAddition.stjava", true);
    }

    @Test
    public void testLiftVerifError() throws Exception {
        testJava("lustre/Lift_verif_error", "Lift_verif_error", "Lift_verif_errorAddition.stjava", true);
    }

    @Test
    public void testPre() throws Exception {
        testJava("lustre/Pre", "Pre", "PreAddition.stjava", true);
    }

    @Test
    public void testPre2() throws Exception {
        testJava("lustre/Pre2", "Pre2", "Pre2Addition.stjava", true);
    }

    @Test
    public void testPre3() throws Exception {
        testJava("lustre/Pre3", "Pre3", "Pre3Addition.stjava", true);
    }

    @Test
    public void testPre4() throws Exception {
        testJava("lustre/Pre4", "Pre4", "Pre4Addition.stjava", true);
    }

    @Test
    public void testPre5() throws Exception {
        testJava("lustre/Pre5", "Pre5", "Pre5Addition.stjava", true);
    }

    @Test
    public void testPre6() throws Exception {
        testJava("lustre/Pre6", "Pre6", "Pre6Addition.stjava", true);
    }

    @Test
    public void testSLOW_TIME_STABLE() throws Exception {
        testJava("lustre/SLOW_TIME_STABLE", "SLOW_TIME_STABLE", "SLOW_TIME_STABLEAddition.stjava", true);
    }

    @Test
    public void testTIME_STABLE() throws Exception {
        testJava("lustre/TIME_STABLE", "TIME_STABLE", "TIME_STABLEAddition.stjava", true);
    }

    @Test
    public void testWhen4() throws Exception {
        testJava("lustre/When4", "When4", "When4Addition.stjava", true);
    }

    @Test
    public void testWhen8() throws Exception {
        testJava("lustre/When8", "When8", "When8Addition.stjava", true);
    }

    @Test
    public void testUMS() throws Exception {
        testJava("lustre/UMS", "UMS", "UMSAddition.stjava", true);
    }

    @Test
    public void testUMS_verif() throws Exception {
        testJava("lustre/UMS_verif", "UMS_verif", "UMS_verifAddition.stjava", true);
    }

}
