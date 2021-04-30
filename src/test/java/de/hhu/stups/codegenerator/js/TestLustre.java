package de.hhu.stups.codegenerator.js;

import org.junit.Test;

public class TestLustre extends TestJs {

    @Test
    public void testCOUNT() throws Exception {
        testJs("lustre/M_COUNT", "M_COUNT", "M_COUNTAddition.stjs", true);
    }

    @Test
    public void testClock4() throws Exception {
        testJs("lustre/M_Clock4", "M_Clock4", "M_Clock4Addition.stjs", true);
    }

    @Test
    public void testClock6() throws Exception {
        testJs("lustre/M_Clock6", "M_Clock6", "M_Clock6Addition.stjs", true);
    }

    @Test
    public void testClock7() throws Exception {
        testJs("lustre/M_Clock7", "M_Clock7", "M_Clock7Addition.stjs", true);
    }

    @Test
    public void testClock8() throws Exception {
        testJs("lustre/M_Clock8", "M_Clock8", "M_Clock8Addition.stjs", true);
    }

    @Test
    public void testClock12() throws Exception {
        testJs("lustre/M_Clock12", "M_Clock12", "M_Clock12Addition.stjs", true);
    }

    @Test
    public void testCurrent() throws Exception {
        testJs("lustre/M_Current", "M_Current", "M_CurrentAddition.stjs", true);
    }

    @Test
    public void testCurrent2() throws Exception {
        testJs("lustre/M_Current2", "M_Current2", "M_Current2Addition.stjs", true);
    }

    @Test
    public void testCurrent3() throws Exception {
        testJs("lustre/M_Current3", "M_Current3", "M_Current3Addition.stjs", true);
    }

    @Test
    public void testExprList() throws Exception {
        testJs("lustre/M_expr_list", "M_expr_list", "M_expr_listAddition.stjs", true);
    }

    @Test
    public void testExprList2() throws Exception {
        testJs("lustre/M_expr_list2", "M_expr_list2", "M_expr_list2Addition.stjs", true);
    }

    @Test
    public void testExprList3() throws Exception {
        testJs("lustre/M_expr_list3", "M_expr_list3", "M_expr_list3Addition.stjs", true);
    }

    @Test
    public void testExprList4() throws Exception {
        testJs("lustre/M_expr_list4", "M_expr_list4", "M_expr_list4Addition.stjs", true);
    }

    @Test
    public void testExprList5() throws Exception {
        testJs("lustre/M_expr_list5", "M_expr_list5", "M_expr_list5Addition.stjs", true);
    }

    @Test
    public void testExprList6() throws Exception {
        testJs("lustre/M_expr_list6", "M_expr_list6", "M_expr_list6Addition.stjs", true);
    }

    @Test
    public void testExprList9() throws Exception {
        testJs("lustre/M_expr_list9", "M_expr_list9", "M_expr_list9Addition.stjs", true);
    }

    @Test
    public void testDivision() throws Exception {
        testJs("lustre/M_Division", "M_Division", "M_DivisionAddition.stjs", true);
    }

    @Test
    public void testModulo() throws Exception {
        testJs("lustre/M_Modulo", "M_Modulo", "M_ModuloAddition.stjs", true);
    }

    @Test
    public void testMachine() throws Exception {
        testJs("lustre/M_Machine", "M_Machine", "M_MachineAddition.stjs", true);
    }

    @Test
    public void testUnequal() throws Exception {
        testJs("lustre/M_Unequal", "M_Unequal", "M_UnequalAddition.stjs", true);
    }

    @Test
    public void testNil() throws Exception {
        testJs("lustre/M_Nil", "M_Nil", "M_NilAddition.stjs", true);
    }

    @Test
    public void testNil3() throws Exception {
        testJs("lustre/M_Nil3", "M_Nil3", "M_Nil3Addition.stjs", true);
    }

    @Test
    public void testNilChecking() throws Exception {
        testJs("lustre/M_NilChecking", "M_NilChecking", "M_NilCheckingAddition.stjs", true);
    }

    @Test
    public void testNilChecking2() throws Exception {
        testJs("lustre/M_NilChecking2", "M_NilChecking2", "M_NilChecking2Addition.stjs", true);
    }

    @Test
    public void testNilChecking5() throws Exception {
        testJs("lustre/M_NilChecking5", "M_NilChecking5", "M_NilChecking5Addition.stjs", true);
    }

    @Test
    public void testNilChecking6() throws Exception {
        testJs("lustre/M_NilChecking6", "M_NilChecking6", "M_NilChecking6Addition.stjs", true);
    }

    @Test
    public void testNodeCallClock() throws Exception {
        testJs("lustre/M_NodeCall_Clock", "M_NodeCall_Clock", "M_NodeCall_ClockAddition.stjs", true);
    }


    @Test
    public void testNodeCallClock2() throws Exception {
        testJs("lustre/M_NodeCall_Clock2", "M_NodeCall_Clock2", "M_NodeCall_Clock2Addition.stjs", true);
    }


    @Test
    public void testNodeCallClock3() throws Exception {
        testJs("lustre/M_NodeCall_Clock3", "M_NodeCall_Clock3", "M_NodeCall_Clock3Addition.stjs", true);
    }


    @Test
    public void testNodeCall() throws Exception {
        testJs("lustre/M_NodeCall", "M_NodeCall", "M_NodeCallAddition.stjs", true);
    }

    @Test
    public void testAssertionClock() throws Exception {
        testJs("lustre/M_AssertionClock", "M_AssertionClock", "M_AssertionClockAddition.stjs", true);
    }

    @Test
    public void testAssertionExample() throws Exception {
        testJs("lustre/M_AssertionExample", "M_AssertionExample", "M_AssertionExampleAddition.stjs", true);
    }

    @Test
    public void testFby() throws Exception {
        testJs("lustre/M_Fby", "M_Fby", "M_FbyAddition.stjs", true);
    }

    @Test
    public void testFby2() throws Exception {
        testJs("lustre/M_Fby2", "M_Fby2", "M_Fby2Addition.stjs", true);
    }

    @Test
    public void testFby3() throws Exception {
        testJs("lustre/M_Fby3", "M_Fby3", "M_Fby3Addition.stjs", true);
    }

    @Test
    public void testIfThenElse() throws Exception {
        testJs("lustre/M_If_Then_Else", "M_If_Then_Else", "M_If_Then_ElseAddition.stjs", true);
    }

    @Test
    public void testIfThenElse2() throws Exception {
        testJs("lustre/M_If_Then_Else2", "M_If_Then_Else2", "M_If_Then_Else2Addition.stjs", true);
    }

    @Test
    public void testLift() throws Exception {
        testJs("lustre/M_Lift", "M_Lift", "M_LiftAddition.stjs", true);
    }

    @Test
    public void testPre() throws Exception {
        testJs("lustre/M_Pre", "M_Pre", "M_PreAddition.stjs", true);
    }

    @Test
    public void testPre2() throws Exception {
        testJs("lustre/M_Pre2", "M_Pre2", "M_Pre2Addition.stjs", true);
    }

    @Test
    public void testPre3() throws Exception {
        testJs("lustre/M_Pre3", "M_Pre3", "M_Pre3Addition.stjs", true);
    }

    @Test
    public void testPre4() throws Exception {
        testJs("lustre/M_Pre4", "M_Pre4", "M_Pre4Addition.stjs", true);
    }

    @Test
    public void testPre5() throws Exception {
        testJs("lustre/M_Pre5", "M_Pre5", "M_Pre5Addition.stjs", true);
    }

    @Test
    public void testPre6() throws Exception {
        testJs("lustre/M_Pre6", "M_Pre6", "M_Pre6Addition.stjs", true);
    }

    @Test
    public void testPre7() throws Exception {
        testJs("lustre/M_Pre7", "M_Pre7", "M_Pre7Addition.stjs", true);
    }

    @Test
    public void testSLOW_TIME_STABLE() throws Exception {
        testJs("lustre/M_SLOW_TIME_STABLE", "M_SLOW_TIME_STABLE", "M_SLOW_TIME_STABLEAddition.stjs", true);
    }

    @Test
    public void testTIME_STABLE() throws Exception {
        testJs("lustre/M_TIME_STABLE", "M_TIME_STABLE", "M_TIME_STABLEAddition.stjs", true);
    }

    @Test
    public void testWhen() throws Exception {
        testJs("lustre/M_When", "M_When", "M_WhenAddition.stjs", true);
    }

    @Test
    public void testWhen2() throws Exception {
        testJs("lustre/M_When2", "M_When2", "M_When2Addition.stjs", true);
    }

    @Test
    public void testWhen3() throws Exception {
        testJs("lustre/M_When3", "M_When3", "M_When3Addition.stjs", true);
    }

    @Test
    public void testWhen4() throws Exception {
        testJs("lustre/M_When4", "M_When4", "M_When4Addition.stjs", true);
    }

    @Test
    public void testWhen5() throws Exception {
        testJs("lustre/M_When5", "M_When5", "M_When5Addition.stjs", true);
    }

    @Test
    public void testWhen6() throws Exception {
        testJs("lustre/M_When6", "M_When6", "M_When6Addition.stjs", true);
    }

    @Test
    public void testWhen7() throws Exception {
        testJs("lustre/M_When7", "M_When7", "M_When7Addition.stjs", true);
    }

    @Test
    public void testWhen8() throws Exception {
        testJs("lustre/M_When8", "M_When8", "M_When8Addition.stjs", true);
    }

    @Test
    public void testWhen9() throws Exception {
        testJs("lustre/M_When9", "M_When9", "M_When9Addition.stjs", true);
    }

    @Test
    public void testWhen10() throws Exception {
        testJs("lustre/M_When10", "M_When10", "M_When10Addition.stjs", true);
    }

    @Test
    public void testWhen11() throws Exception {
        testJs("lustre/M_When11", "M_When11", "M_When11Addition.stjs", true);
    }

    @Test
    public void testUMS() throws Exception {
        testJs("lustre/M_UMS_main", "M_UMS_main", "M_UMS_mainAddition.stjs", true);
    }

    @Test
    public void testUMS_verif() throws Exception {
        testJs("lustre/M_UMS_verif", "M_UMS_verif", "M_UMS_verifAddition.stjs", true);
    }

    @Test
    public void testSpeed() throws Exception {
        testJs("lustre/M_speed_main", "M_speed_main", "M_speed_mainAddition.stjs", true);
    }

    @Test
    public void testSpeedVerif() throws Exception {
        testJs("lustre/M_speed_verif", "M_speed_verif", "M_speed_verifAddition.stjs", true);
    }

    @Test
    public void testMovingItem() throws Exception {
        testJs("lustre/M_MovingItem_main", "M_MovingItem_main", "M_MovingItem_mainAddition.stjs", true);
    }

    @Test
    public void testVerifyMovingItem() throws Exception {
        testJs("lustre/M_VerifyMovingItem", "M_VerifyMovingItem", "M_VerifyMovingItemAddition.stjs", true);
    }

    @Test
    public void testSubmodeExample() throws Exception {
        testJs("lustre/M_SubmodeExample", "M_SubmodeExample", "M_SubmodeExampleAddition.stjs", true);
    }

    @Test
    public void testCarlights() throws Exception {
        testJs("lustre/M_carlights2_v4", "M_carlights2_v4", "M_carlights2_v4Addition.stjs", true);
    }

    @Test
    public void testPilotFlying() throws Exception {
        testJs("lustre/M_pilot_flying", "M_pilot_flying", "M_pilot_flyingAddition.stjs", true);
    }

}
