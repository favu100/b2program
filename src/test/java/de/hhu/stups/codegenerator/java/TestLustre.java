package de.hhu.stups.codegenerator.java;

import org.junit.Ignore;
import org.junit.Test;

@Ignore
public class TestLustre extends TestJava {

    @Test
    public void testCOUNT() throws Exception {
        testJava("lustre/M_COUNT", "M_COUNT", "M_COUNTAddition.stjava", true);
    }

    @Test
    public void testClock4() throws Exception {
        testJava("lustre/M_Clock4", "M_Clock4", "M_Clock4Addition.stjava", true);
    }

    @Test
    public void testClock6() throws Exception {
        testJava("lustre/M_Clock6", "M_Clock6", "M_Clock6Addition.stjava", true);
    }

    @Test
    public void testClock7() throws Exception {
        testJava("lustre/M_Clock7", "M_Clock7", "M_Clock7Addition.stjava", true);
    }

    @Test
    public void testClock8() throws Exception {
        testJava("lustre/M_Clock8", "M_Clock8", "M_Clock8Addition.stjava", true);
    }

    @Test
    public void testClock12() throws Exception {
        testJava("lustre/M_Clock12", "M_Clock12", "M_Clock12Addition.stjava", true);
    }

    @Test
    public void testCurrent() throws Exception {
        testJava("lustre/M_Current", "M_Current", "M_CurrentAddition.stjava", true);
    }

    @Test
    public void testCurrent2() throws Exception {
        testJava("lustre/M_Current2", "M_Current2", "M_Current2Addition.stjava", true);
    }

    @Test
    public void testCurrent3() throws Exception {
        testJava("lustre/M_Current3", "M_Current3", "M_Current3Addition.stjava", true);
    }

    @Test
    public void testExprList() throws Exception {
        testJava("lustre/M_expr_list", "M_expr_list", "M_expr_listAddition.stjava", true);
    }

    @Test
    public void testExprList2() throws Exception {
        testJava("lustre/M_expr_list2", "M_expr_list2", "M_expr_list2Addition.stjava", true);
    }

    @Test
    public void testExprList3() throws Exception {
        testJava("lustre/M_expr_list3", "M_expr_list3", "M_expr_list3Addition.stjava", true);
    }

    @Test
    public void testExprList4() throws Exception {
        testJava("lustre/M_expr_list4", "M_expr_list4", "M_expr_list4Addition.stjava", true);
    }

    @Test
    public void testExprList5() throws Exception {
        testJava("lustre/M_expr_list5", "M_expr_list5", "M_expr_list5Addition.stjava", true);
    }

    @Test
    public void testExprList6() throws Exception {
        testJava("lustre/M_expr_list6", "M_expr_list6", "M_expr_list6Addition.stjava", true);
    }

    @Test
    public void testExprList9() throws Exception {
        testJava("lustre/M_expr_list9", "M_expr_list9", "M_expr_list9Addition.stjava", true);
    }

    @Test
    public void testDivision() throws Exception {
        testJava("lustre/M_Division", "M_Division", "M_DivisionAddition.stjava", true);
    }

    @Test
    public void testModulo() throws Exception {
        testJava("lustre/M_Modulo", "M_Modulo", "M_ModuloAddition.stjava", true);
    }

    @Test
    public void testMachine() throws Exception {
        testJava("lustre/M_Machine", "M_Machine", "M_MachineAddition.stjava", true);
    }

    @Test
    public void testUnequal() throws Exception {
        testJava("lustre/M_Unequal", "M_Unequal", "M_UnequalAddition.stjava", true);
    }

    @Test
    public void testNil() throws Exception {
        testJava("lustre/M_Nil", "M_Nil", "M_NilAddition.stjava", true);
    }

    @Test
    public void testNil3() throws Exception {
        testJava("lustre/M_Nil3", "M_Nil3", "M_Nil3Addition.stjava", true);
    }

    @Test
    public void testNilChecking() throws Exception {
        testJava("lustre/M_NilChecking", "M_NilChecking", "M_NilCheckingAddition.stjava", true);
    }

    @Test
    public void testNilChecking2() throws Exception {
        testJava("lustre/M_NilChecking2", "M_NilChecking2", "M_NilChecking2Addition.stjava", true);
    }

    @Test
    public void testNilChecking5() throws Exception {
        testJava("lustre/M_NilChecking5", "M_NilChecking5", "M_NilChecking5Addition.stjava", true);
    }

    @Test
    public void testNilChecking6() throws Exception {
        testJava("lustre/M_NilChecking6", "M_NilChecking6", "M_NilChecking6Addition.stjava", true);
    }

    @Test
    public void testNodeCallClock() throws Exception {
        testJava("lustre/M_NodeCall_Clock", "M_NodeCall_Clock", "M_NodeCall_ClockAddition.stjava", true);
    }


    @Test
    public void testNodeCallClock2() throws Exception {
        testJava("lustre/M_NodeCall_Clock2", "M_NodeCall_Clock2", "M_NodeCall_Clock2Addition.stjava", true);
    }


    @Test
    public void testNodeCallClock3() throws Exception {
        testJava("lustre/M_NodeCall_Clock3", "M_NodeCall_Clock3", "M_NodeCall_Clock3Addition.stjava", true);
    }


    @Test
    public void testNodeCall() throws Exception {
        testJava("lustre/M_NodeCall", "M_NodeCall", "M_NodeCallAddition.stjava", true);
    }

    @Test
    public void testAssertionClock() throws Exception {
        testJava("lustre/M_AssertionClock", "M_AssertionClock", "M_AssertionClockAddition.stjava", true);
    }

    @Test
    public void testAssertionExample() throws Exception {
        testJava("lustre/M_AssertionExample", "M_AssertionExample", "M_AssertionExampleAddition.stjava", true);
    }

    @Test
    public void testFby() throws Exception {
        testJava("lustre/M_Fby", "M_Fby", "M_FbyAddition.stjava", true);
    }

    @Test
    public void testFby2() throws Exception {
        testJava("lustre/M_Fby2", "M_Fby2", "M_Fby2Addition.stjava", true);
    }

    @Test
    public void testFby3() throws Exception {
        testJava("lustre/M_Fby3", "M_Fby3", "M_Fby3Addition.stjava", true);
    }

    @Test
    public void testIfThenElse() throws Exception {
        testJava("lustre/M_If_Then_Else", "M_If_Then_Else", "M_If_Then_ElseAddition.stjava", true);
    }

    @Test
    public void testIfThenElse2() throws Exception {
        testJava("lustre/M_If_Then_Else2", "M_If_Then_Else2", "M_If_Then_Else2Addition.stjava", true);
    }

    @Test
    public void testLift() throws Exception {
        testJava("lustre/M_Lift", "M_Lift", "M_LiftAddition.stjava", true);
    }

    @Test
    public void testPre() throws Exception {
        testJava("lustre/M_Pre", "M_Pre", "M_PreAddition.stjava", true);
    }

    @Test
    public void testPre2() throws Exception {
        testJava("lustre/M_Pre2", "M_Pre2", "M_Pre2Addition.stjava", true);
    }

    @Test
    public void testPre3() throws Exception {
        testJava("lustre/M_Pre3", "M_Pre3", "M_Pre3Addition.stjava", true);
    }

    @Test
    public void testPre4() throws Exception {
        testJava("lustre/M_Pre4", "M_Pre4", "M_Pre4Addition.stjava", true);
    }

    @Test
    public void testPre5() throws Exception {
        testJava("lustre/M_Pre5", "M_Pre5", "M_Pre5Addition.stjava", true);
    }

    @Test
    public void testPre6() throws Exception {
        testJava("lustre/M_Pre6", "M_Pre6", "M_Pre6Addition.stjava", true);
    }

    @Test
    public void testPre7() throws Exception {
        testJava("lustre/M_Pre7", "M_Pre7", "M_Pre7Addition.stjava", true);
    }

    @Test
    public void testSLOW_TIME_STABLE() throws Exception {
        testJava("lustre/M_SLOW_TIME_STABLE", "M_SLOW_TIME_STABLE", "M_SLOW_TIME_STABLEAddition.stjava", true);
    }

    @Test
    public void testTIME_STABLE() throws Exception {
        testJava("lustre/M_TIME_STABLE", "M_TIME_STABLE", "M_TIME_STABLEAddition.stjava", true);
    }

    @Test
    public void testWhen() throws Exception {
        testJava("lustre/M_When", "M_When", "M_WhenAddition.stjava", true);
    }

    @Test
    public void testWhen2() throws Exception {
        testJava("lustre/M_When2", "M_When2", "M_When2Addition.stjava", true);
    }

    @Test
    public void testWhen3() throws Exception {
        testJava("lustre/M_When3", "M_When3", "M_When3Addition.stjava", true);
    }

    @Test
    public void testWhen4() throws Exception {
        testJava("lustre/M_When4", "M_When4", "M_When4Addition.stjava", true);
    }

    @Test
    public void testWhen5() throws Exception {
        testJava("lustre/M_When5", "M_When5", "M_When5Addition.stjava", true);
    }

    @Test
    public void testWhen6() throws Exception {
        testJava("lustre/M_When6", "M_When6", "M_When6Addition.stjava", true);
    }

    @Test
    public void testWhen7() throws Exception {
        testJava("lustre/M_When7", "M_When7", "M_When7Addition.stjava", true);
    }

    @Test
    public void testWhen8() throws Exception {
        testJava("lustre/M_When8", "M_When8", "M_When8Addition.stjava", true);
    }

    @Test
    public void testWhen9() throws Exception {
        testJava("lustre/M_When9", "M_When9", "M_When9Addition.stjava", true);
    }

    @Test
    public void testWhen10() throws Exception {
        testJava("lustre/M_When10", "M_When10", "M_When10Addition.stjava", true);
    }

    @Test
    public void testWhen11() throws Exception {
        testJava("lustre/M_When11", "M_When11", "M_When11Addition.stjava", true);
    }

    @Test
    public void testUMS() throws Exception {
        testJava("lustre/M_UMS_main", "M_UMS_main", "M_UMS_mainAddition.stjava", true);
    }

    @Test
    public void testUMS_verif() throws Exception {
        testJava("lustre/M_UMS_verif", "M_UMS_verif", "M_UMS_verifAddition.stjava", true);
    }

    @Test
    public void testSpeed() throws Exception {
        testJava("lustre/M_speed_main", "M_speed_main", "M_speed_mainAddition.stjava", true);
    }

    @Test
    public void testSpeedVerif() throws Exception {
        testJava("lustre/M_speed_verif", "M_speed_verif", "M_speed_verifAddition.stjava", true);
    }

    @Test
    public void testMovingItem() throws Exception {
        testJava("lustre/M_MovingItem_main", "M_MovingItem_main", "M_MovingItem_mainAddition.stjava", true);
    }

    @Test
    public void testVerifyMovingItem() throws Exception {
        testJava("lustre/M_VerifyMovingItem", "M_VerifyMovingItem", "M_VerifyMovingItemAddition.stjava", true);
    }

    @Test
    public void testSubmodeExample() throws Exception {
        testJava("lustre/M_SubmodeExample", "M_SubmodeExample", "M_SubmodeExampleAddition.stjava", true);
    }

    @Test
    public void testCarlights() throws Exception {
        testJava("lustre/M_carlights2_v4", "M_carlights2_v4", "M_carlights2_v4Addition.stjava", true);
    }

    @Test
    public void testPilotFlying() throws Exception {
        testJava("lustre/M_pilot_flying", "M_pilot_flying", "M_pilot_flyingAddition.stjava", true);
    }

}
