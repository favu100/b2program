package de.hhu.stups.codegenerator.cpp;

import org.junit.Ignore;
import org.junit.Test;

@Ignore
public class TestLustre extends TestCpp {

    @Test
    public void testCOUNT() throws Exception {
        testCpp("lustre/M_COUNT", "M_COUNT", "M_COUNTAddition.stcpp", true);
    }

    @Test
    public void testClock4() throws Exception {
        testCpp("lustre/M_Clock4", "M_Clock4", "M_Clock4Addition.stcpp", true);
    }

    @Test
    public void testClock6() throws Exception {
        testCpp("lustre/M_Clock6", "M_Clock6", "M_Clock6Addition.stcpp", true);
    }

    @Test
    public void testClock7() throws Exception {
        testCpp("lustre/M_Clock7", "M_Clock7", "M_Clock7Addition.stcpp", true);
    }

    @Test
    public void testClock8() throws Exception {
        testCpp("lustre/M_Clock8", "M_Clock8", "M_Clock8Addition.stcpp", true);
    }

    @Test
    public void testClock12() throws Exception {
        testCpp("lustre/M_Clock12", "M_Clock12", "M_Clock12Addition.stcpp", true);
    }

    @Test
    public void testCurrent() throws Exception {
        testCpp("lustre/M_Current", "M_Current", "M_CurrentAddition.stcpp", true);
    }

    @Test
    public void testCurrent2() throws Exception {
        testCpp("lustre/M_Current2", "M_Current2", "M_Current2Addition.stcpp", true);
    }

    @Test
    public void testCurrent3() throws Exception {
        testCpp("lustre/M_Current3", "M_Current3", "M_Current3Addition.stcpp", true);
    }

    @Test
    public void testExprList() throws Exception {
        testCpp("lustre/M_expr_list", "M_expr_list", "M_expr_listAddition.stcpp", true);
    }

    @Test
    public void testExprList2() throws Exception {
        testCpp("lustre/M_expr_list2", "M_expr_list2", "M_expr_list2Addition.stcpp", true);
    }

    @Test
    public void testExprList3() throws Exception {
        testCpp("lustre/M_expr_list3", "M_expr_list3", "M_expr_list3Addition.stcpp", true);
    }

    @Test
    public void testExprList4() throws Exception {
        testCpp("lustre/M_expr_list4", "M_expr_list4", "M_expr_list4Addition.stcpp", true);
    }

    @Test
    public void testExprList5() throws Exception {
        testCpp("lustre/M_expr_list5", "M_expr_list5", "M_expr_list5Addition.stcpp", true);
    }

    @Test
    public void testExprList6() throws Exception {
        testCpp("lustre/M_expr_list6", "M_expr_list6", "M_expr_list6Addition.stcpp", true);
    }

    @Test
    public void testExprList9() throws Exception {
        testCpp("lustre/M_expr_list9", "M_expr_list9", "M_expr_list9Addition.stcpp", true);
    }

    @Test
    public void testDivision() throws Exception {
        testCpp("lustre/M_Division", "M_Division", "M_DivisionAddition.stcpp", true);
    }

    @Test
    public void testModulo() throws Exception {
        testCpp("lustre/M_Modulo", "M_Modulo", "M_ModuloAddition.stcpp", true);
    }

    @Test
    public void testMachine() throws Exception {
        testCpp("lustre/M_Machine", "M_Machine", "M_MachineAddition.stcpp", true);
    }

    @Test
    public void testUnequal() throws Exception {
        testCpp("lustre/M_Unequal", "M_Unequal", "M_UnequalAddition.stcpp", true);
    }

    @Test
    public void testNil() throws Exception {
        testCpp("lustre/M_Nil", "M_Nil", "M_NilAddition.stcpp", true);
    }

    @Test
    public void testNil3() throws Exception {
        testCpp("lustre/M_Nil3", "M_Nil3", "M_Nil3Addition.stcpp", true);
    }

    @Test
    public void testNilChecking() throws Exception {
        testCpp("lustre/M_NilChecking", "M_NilChecking", "M_NilCheckingAddition.stcpp", true);
    }

    @Test
    public void testNilChecking2() throws Exception {
        testCpp("lustre/M_NilChecking2", "M_NilChecking2", "M_NilChecking2Addition.stcpp", true);
    }

    @Test
    public void testNilChecking5() throws Exception {
        testCpp("lustre/M_NilChecking5", "M_NilChecking5", "M_NilChecking5Addition.stcpp", true);
    }

    @Test
    public void testNilChecking6() throws Exception {
        testCpp("lustre/M_NilChecking6", "M_NilChecking6", "M_NilChecking6Addition.stcpp", true);
    }

    @Test
    public void testNodeCallClock() throws Exception {
        testCpp("lustre/M_NodeCall_Clock", "M_NodeCall_Clock", "M_NodeCall_ClockAddition.stcpp", true);
    }


    @Test
    public void testNodeCallClock2() throws Exception {
        testCpp("lustre/M_NodeCall_Clock2", "M_NodeCall_Clock2", "M_NodeCall_Clock2Addition.stcpp", true);
    }


    @Test
    public void testNodeCallClock3() throws Exception {
        testCpp("lustre/M_NodeCall_Clock3", "M_NodeCall_Clock3", "M_NodeCall_Clock3Addition.stcpp", true);
    }


    @Test
    public void testNodeCall() throws Exception {
        testCpp("lustre/M_NodeCall", "M_NodeCall", "M_NodeCallAddition.stcpp", true);
    }


    @Test
    public void testAssertionClock() throws Exception {
        testCpp("lustre/M_AssertionClock", "M_AssertionClock", "M_AssertionClockAddition.stcpp", true);
    }

    @Test
    public void testAssertionExample() throws Exception {
        testCpp("lustre/M_AssertionExample", "M_AssertionExample", "M_AssertionExampleAddition.stcpp", true);
    }


    @Test
    public void testFby() throws Exception {
        testCpp("lustre/M_Fby", "M_Fby", "M_FbyAddition.stcpp", true);
    }

    @Test
    public void testFby2() throws Exception {
        testCpp("lustre/M_Fby2", "M_Fby2", "M_Fby2Addition.stcpp", true);
    }

    @Test
    public void testFby3() throws Exception {
        testCpp("lustre/M_Fby3", "M_Fby3", "M_Fby3Addition.stcpp", true);
    }

    @Test
    public void testIfThenElse() throws Exception {
        testCpp("lustre/M_If_Then_Else", "M_If_Then_Else", "M_If_Then_ElseAddition.stcpp", true);
    }

    @Test
    public void testIfThenElse2() throws Exception {
        testCpp("lustre/M_If_Then_Else2", "M_If_Then_Else2", "M_If_Then_Else2Addition.stcpp", true);
    }

    @Test
    public void testLift() throws Exception {
        testCpp("lustre/M_Lift", "M_Lift", "M_LiftAddition.stcpp", true);
    }

    @Test
    public void testPre() throws Exception {
        testCpp("lustre/M_Pre", "M_Pre", "M_PreAddition.stcpp", true);
    }

    @Test
    public void testPre2() throws Exception {
        testCpp("lustre/M_Pre2", "M_Pre2", "M_Pre2Addition.stcpp", true);
    }

    @Test
    public void testPre3() throws Exception {
        testCpp("lustre/M_Pre3", "M_Pre3", "M_Pre3Addition.stcpp", true);
    }

    @Test
    public void testPre4() throws Exception {
        testCpp("lustre/M_Pre4", "M_Pre4", "M_Pre4Addition.stcpp", true);
    }

    @Test
    public void testPre5() throws Exception {
        testCpp("lustre/M_Pre5", "M_Pre5", "M_Pre5Addition.stcpp", true);
    }

    @Test
    public void testPre6() throws Exception {
        testCpp("lustre/M_Pre6", "M_Pre6", "M_Pre6Addition.stcpp", true);
    }

    @Test
    public void testPre7() throws Exception {
        testCpp("lustre/M_Pre7", "M_Pre7", "M_Pre7Addition.stcpp", true);
    }

    @Test
    public void testSLOW_TIME_STABLE() throws Exception {
        testCpp("lustre/M_SLOW_TIME_STABLE", "M_SLOW_TIME_STABLE", "M_SLOW_TIME_STABLEAddition.stcpp", true);
    }

    @Test
    public void testTIME_STABLE() throws Exception {
        testCpp("lustre/M_TIME_STABLE", "M_TIME_STABLE", "M_TIME_STABLEAddition.stcpp", true);
    }

    @Test
    public void testWhen() throws Exception {
        testCpp("lustre/M_When", "M_When", "M_WhenAddition.stcpp", true);
    }

    @Test
    public void testWhen2() throws Exception {
        testCpp("lustre/M_When2", "M_When2", "M_When2Addition.stcpp", true);
    }

    @Test
    public void testWhen3() throws Exception {
        testCpp("lustre/M_When3", "M_When3", "M_When3Addition.stcpp", true);
    }

    @Test
    public void testWhen4() throws Exception {
        testCpp("lustre/M_When4", "M_When4", "M_When4Addition.stcpp", true);
    }

    @Test
    public void testWhen5() throws Exception {
        testCpp("lustre/M_When5", "M_When5", "M_When5Addition.stcpp", true);
    }

    @Test
    public void testWhen6() throws Exception {
        testCpp("lustre/M_When6", "M_When6", "M_When6Addition.stcpp", true);
    }

    @Test
    public void testWhen7() throws Exception {
        testCpp("lustre/M_When7", "M_When7", "M_When7Addition.stcpp", true);
    }

    @Test
    public void testWhen8() throws Exception {
        testCpp("lustre/M_When8", "M_When8", "M_When8Addition.stcpp", true);
    }

    @Test
    public void testWhen9() throws Exception {
        testCpp("lustre/M_When9", "M_When9", "M_When9Addition.stcpp", true);
    }

    @Test
    public void testWhen10() throws Exception {
        testCpp("lustre/M_When10", "M_When10", "M_When10Addition.stcpp", true);
    }

    @Test
    public void testWhen11() throws Exception {
        testCpp("lustre/M_When11", "M_When11", "M_When11Addition.stcpp", true);
    }

    @Test
    public void testUMS() throws Exception {
        testCpp("lustre/M_UMS_main", "M_UMS_main", "M_UMS_mainAddition.stcpp", true);
    }

    @Test
    public void testUMS_verif() throws Exception {
        testCpp("lustre/M_UMS_verif", "M_UMS_verif", "M_UMS_verifAddition.stcpp", true);
    }

    @Test
    public void testSpeed() throws Exception {
        testCpp("lustre/M_speed_main", "M_speed_main", "M_speed_mainAddition.stcpp", true);
    }

    @Test
    public void testSpeedVerif() throws Exception {
        testCpp("lustre/M_speed_verif", "M_speed_verif", "M_speed_verifAddition.stcpp", true);
    }

    @Test
    public void testMovingItem() throws Exception {
        testCpp("lustre/M_MovingItem_main", "M_MovingItem_main", "M_MovingItem_mainAddition.stcpp", true);
    }

    @Test
    public void testVerifyMovingItem() throws Exception {
        testCpp("lustre/M_VerifyMovingItem", "M_VerifyMovingItem", "M_VerifyMovingItemAddition.stcpp", true);
    }

    @Test
    public void testSubmodeExample() throws Exception {
        testCpp("lustre/M_SubmodeExample", "M_SubmodeExample", "M_SubmodeExampleAddition.stcpp", true);
    }

    @Test
    public void testCarlights() throws Exception {
        testCpp("lustre/M_carlights2_v4", "M_carlights2_v4", "M_carlights2_v4Addition.stcpp", true);
    }

    @Test
    public void testPilotFlying() throws Exception {
        testCpp("lustre/M_pilot_flying", "M_pilot_flying", "M_pilot_flyingAddition.stcpp", true);
    }

}
