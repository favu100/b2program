package de.hhu.stups.codegenerator.python;

import org.junit.Ignore;
import org.junit.Test;

@Ignore
public class TestLustre extends TestPython {

    @Test
    public void testCOUNT() throws Exception {
        testPython("lustre/M_COUNT", "M_COUNT", "M_COUNTAddition.stpy", true);
    }

    @Test
    public void testClock4() throws Exception {
        testPython("lustre/M_Clock4", "M_Clock4", "M_Clock4Addition.stpy", true);
    }

    @Test
    public void testClock6() throws Exception {
        testPython("lustre/M_Clock6", "M_Clock6", "M_Clock6Addition.stpy", true);
    }

    @Test
    public void testClock7() throws Exception {
        testPython("lustre/M_Clock7", "M_Clock7", "M_Clock7Addition.stpy", true);
    }

    @Test
    public void testClock8() throws Exception {
        testPython("lustre/M_Clock8", "M_Clock8", "M_Clock8Addition.stpy", true);
    }

    @Test
    public void testClock12() throws Exception {
        testPython("lustre/M_Clock12", "M_Clock12", "M_Clock12Addition.stpy", true);
    }

    @Test
    public void testCurrent() throws Exception {
        testPython("lustre/M_Current", "M_Current", "M_CurrentAddition.stpy", true);
    }

    @Test
    public void testCurrent2() throws Exception {
        testPython("lustre/M_Current2", "M_Current2", "M_Current2Addition.stpy", true);
    }

    @Test
    public void testCurrent3() throws Exception {
        testPython("lustre/M_Current3", "M_Current3", "M_Current3Addition.stpy", true);
    }

    @Test
    public void testExprList() throws Exception {
        testPython("lustre/M_expr_list", "M_expr_list", "M_expr_listAddition.stpy", true);
    }

    @Test
    public void testExprList2() throws Exception {
        testPython("lustre/M_expr_list2", "M_expr_list2", "M_expr_list2Addition.stpy", true);
    }

    @Test
    public void testExprList3() throws Exception {
        testPython("lustre/M_expr_list3", "M_expr_list3", "M_expr_list3Addition.stpy", true);
    }

    @Test
    public void testExprList4() throws Exception {
        testPython("lustre/M_expr_list4", "M_expr_list4", "M_expr_list4Addition.stpy", true);
    }

    @Test
    public void testExprList5() throws Exception {
        testPython("lustre/M_expr_list5", "M_expr_list5", "M_expr_list5Addition.stpy", true);
    }

    @Test
    public void testExprList6() throws Exception {
        testPython("lustre/M_expr_list6", "M_expr_list6", "M_expr_list6Addition.stpy", true);
    }

    @Test
    public void testExprList9() throws Exception {
        testPython("lustre/M_expr_list9", "M_expr_list9", "M_expr_list9Addition.stpy", true);
    }

    @Test
    public void testDivision() throws Exception {
        testPython("lustre/M_Division", "M_Division", "M_DivisionAddition.stpy", true);
    }

    @Test
    public void testModulo() throws Exception {
        testPython("lustre/M_Modulo", "M_Modulo", "M_ModuloAddition.stpy", true);
    }

    @Test
    public void testMachine() throws Exception {
        testPython("lustre/M_Machine", "M_Machine", "M_MachineAddition.stpy", true);
    }

    @Test
    public void testUnequal() throws Exception {
        testPython("lustre/M_Unequal", "M_Unequal", "M_UnequalAddition.stpy", true);
    }

    @Test
    public void testNil() throws Exception {
        testPython("lustre/M_Nil", "M_Nil", "M_NilAddition.stpy", true);
    }

    @Test
    public void testNil3() throws Exception {
        testPython("lustre/M_Nil3", "M_Nil3", "M_Nil3Addition.stpy", true);
    }

    @Test
    public void testNilChecking() throws Exception {
        testPython("lustre/M_NilChecking", "M_NilChecking", "M_NilCheckingAddition.stpy", true);
    }

    @Test
    public void testNilChecking2() throws Exception {
        testPython("lustre/M_NilChecking2", "M_NilChecking2", "M_NilChecking2Addition.stpy", true);
    }

    @Test
    public void testNilChecking5() throws Exception {
        testPython("lustre/M_NilChecking5", "M_NilChecking5", "M_NilChecking5Addition.stpy", true);
    }

    @Test
    public void testNilChecking6() throws Exception {
        testPython("lustre/M_NilChecking6", "M_NilChecking6", "M_NilChecking6Addition.stpy", true);
    }

    @Test
    public void testNodeCallClock() throws Exception {
        testPython("lustre/M_NodeCall_Clock", "M_NodeCall_Clock", "M_NodeCall_ClockAddition.stpy", true);
    }


    @Test
    public void testNodeCallClock2() throws Exception {
        testPython("lustre/M_NodeCall_Clock2", "M_NodeCall_Clock2", "M_NodeCall_Clock2Addition.stpy", true);
    }


    @Test
    public void testNodeCallClock3() throws Exception {
        testPython("lustre/M_NodeCall_Clock3", "M_NodeCall_Clock3", "M_NodeCall_Clock3Addition.stpy", true);
    }


    @Test
    public void testNodeCall() throws Exception {
        testPython("lustre/M_NodeCall", "M_NodeCall", "M_NodeCallAddition.stpy", true);
    }

    @Test
    public void testAssertionClock() throws Exception {
        testPython("lustre/M_AssertionClock", "M_AssertionClock", "M_AssertionClockAddition.stpy", true);
    }

    @Test
    public void testAssertionExample() throws Exception {
        testPython("lustre/M_AssertionExample", "M_AssertionExample", "M_AssertionExampleAddition.stpy", true);
    }

    @Test
    public void testFby() throws Exception {
        testPython("lustre/M_Fby", "M_Fby", "M_FbyAddition.stpy", true);
    }

    @Test
    public void testFby2() throws Exception {
        testPython("lustre/M_Fby2", "M_Fby2", "M_Fby2Addition.stpy", true);
    }

    @Test
    public void testFby3() throws Exception {
        testPython("lustre/M_Fby3", "M_Fby3", "M_Fby3Addition.stpy", true);
    }

    @Test
    public void testIfThenElse() throws Exception {
        testPython("lustre/M_If_Then_Else", "M_If_Then_Else", "M_If_Then_ElseAddition.stpy", true);
    }

    @Test
    public void testIfThenElse2() throws Exception {
        testPython("lustre/M_If_Then_Else2", "M_If_Then_Else2", "M_If_Then_Else2Addition.stpy", true);
    }

    @Test
    public void testLift() throws Exception {
        testPython("lustre/M_Lift", "M_Lift", "M_LiftAddition.stpy", true);
    }

    @Test
    public void testPre() throws Exception {
        testPython("lustre/M_Pre", "M_Pre", "M_PreAddition.stpy", true);
    }

    @Test
    public void testPre2() throws Exception {
        testPython("lustre/M_Pre2", "M_Pre2", "M_Pre2Addition.stpy", true);
    }

    @Test
    public void testPre3() throws Exception {
        testPython("lustre/M_Pre3", "M_Pre3", "M_Pre3Addition.stpy", true);
    }

    @Test
    public void testPre4() throws Exception {
        testPython("lustre/M_Pre4", "M_Pre4", "M_Pre4Addition.stpy", true);
    }

    @Test
    public void testPre5() throws Exception {
        testPython("lustre/M_Pre5", "M_Pre5", "M_Pre5Addition.stpy", true);
    }

    @Test
    public void testPre6() throws Exception {
        testPython("lustre/M_Pre6", "M_Pre6", "M_Pre6Addition.stpy", true);
    }

    @Test
    public void testPre7() throws Exception {
        testPython("lustre/M_Pre7", "M_Pre7", "M_Pre7Addition.stpy", true);
    }

    @Test
    public void testSLOW_TIME_STABLE() throws Exception {
        testPython("lustre/M_SLOW_TIME_STABLE", "M_SLOW_TIME_STABLE", "M_SLOW_TIME_STABLEAddition.stpy", true);
    }

    @Test
    public void testTIME_STABLE() throws Exception {
        testPython("lustre/M_TIME_STABLE", "M_TIME_STABLE", "M_TIME_STABLEAddition.stpy", true);
    }

    @Test
    public void testWhen() throws Exception {
        testPython("lustre/M_When", "M_When", "M_WhenAddition.stpy", true);
    }

    @Test
    public void testWhen2() throws Exception {
        testPython("lustre/M_When2", "M_When2", "M_When2Addition.stpy", true);
    }

    @Test
    public void testWhen3() throws Exception {
        testPython("lustre/M_When3", "M_When3", "M_When3Addition.stpy", true);
    }

    @Test
    public void testWhen4() throws Exception {
        testPython("lustre/M_When4", "M_When4", "M_When4Addition.stpy", true);
    }

    @Test
    public void testWhen5() throws Exception {
        testPython("lustre/M_When5", "M_When5", "M_When5Addition.stpy", true);
    }

    @Test
    public void testWhen6() throws Exception {
        testPython("lustre/M_When6", "M_When6", "M_When6Addition.stpy", true);
    }

    @Test
    public void testWhen7() throws Exception {
        testPython("lustre/M_When7", "M_When7", "M_When7Addition.stpy", true);
    }

    @Test
    public void testWhen8() throws Exception {
        testPython("lustre/M_When8", "M_When8", "M_When8Addition.stpy", true);
    }

    @Test
    public void testWhen9() throws Exception {
        testPython("lustre/M_When9", "M_When9", "M_When9Addition.stpy", true);
    }

    @Test
    public void testWhen10() throws Exception {
        testPython("lustre/M_When10", "M_When10", "M_When10Addition.stpy", true);
    }

    @Test
    public void testWhen11() throws Exception {
        testPython("lustre/M_When11", "M_When11", "M_When11Addition.stpy", true);
    }

    @Test
    public void testUMS() throws Exception {
        testPython("lustre/M_UMS_main", "M_UMS_main", "M_UMS_mainAddition.stpy", true);
    }

    @Test
    public void testUMS_verif() throws Exception {
        testPython("lustre/M_UMS_verif", "M_UMS_verif", "M_UMS_verifAddition.stpy", true);
    }

    @Test
    public void testSpeed() throws Exception {
        testPython("lustre/M_speed_main", "M_speed_main", "M_speed_mainAddition.stpy", true);
    }

    @Test
    public void testSpeedVerif() throws Exception {
        testPython("lustre/M_speed_verif", "M_speed_verif", "M_speed_verifAddition.stpy", true);
    }

    @Test
    public void testMovingItem() throws Exception {
        testPython("lustre/M_MovingItem_main", "M_MovingItem_main", "M_MovingItem_mainAddition.stpy", true);
    }

    @Test
    public void testVerifyMovingItem() throws Exception {
        testPython("lustre/M_VerifyMovingItem", "M_VerifyMovingItem", "M_VerifyMovingItemAddition.stpy", true);
    }

    @Test
    public void testSubmodeExample() throws Exception {
        testPython("lustre/M_SubmodeExample", "M_SubmodeExample", "M_SubmodeExampleAddition.stpy", true);
    }

    @Test
    public void testCarlights() throws Exception {
        testPython("lustre/M_carlights2_v4", "M_carlights2_v4", "M_carlights2_v4Addition.stpy", true);
    }

    @Test
    public void testPilotFlying() throws Exception {
        testPython("lustre/M_pilot_flying", "M_pilot_flying", "M_pilot_flyingAddition.stpy", true);
    }

}
