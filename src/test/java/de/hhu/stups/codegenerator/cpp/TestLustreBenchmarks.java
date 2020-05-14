package de.hhu.stups.codegenerator.cpp;

import org.junit.Test;

public class TestLustreBenchmarks extends TestCpp {

	@Test
	public void testLift() throws Exception {
		testCpp("lustre_benchmarks/M_Lift_exec", "M_Lift_exec", "M_Lift_execAddition.stcpp", false);
	}

	@Test
	public void testSLOW_TIME_STABLE() throws Exception {
		testCpp("lustre_benchmarks/M_SLOW_TIME_STABLE_exec", "M_SLOW_TIME_STABLE_exec", "M_SLOW_TIME_STABLE_execAddition.stcpp", false);
	}

	@Test
	public void testSpeed() throws Exception {
		testCpp("lustre_benchmarks/M_speed_main_exec", "M_speed_main_exec", "M_speed_main_execAddition.stcpp", false);
	}

	@Test
	public void testSpeedVerif() throws Exception {
		testCpp("lustre_benchmarks/M_speed_verif_exec", "M_speed_verif_exec", "M_speed_verif_execAddition.stcpp", false);
	}

	@Test
	public void testUMS() throws Exception {
		testCpp("lustre_benchmarks/M_UMS_main_exec", "M_UMS_main_exec", "M_UMS_main_execAddition.stcpp", false);
	}

	@Test
	public void testUMSVerif() throws Exception {
		testCpp("lustre_benchmarks/M_UMS_verif_exec", "M_UMS_verif_exec", "M_UMS_verif_execAddition.stcpp", false);
	}

    @Test
    public void testPilotFlying() throws Exception {
        testCpp("lustre_benchmarks/M_pilot_flying_exec", "M_pilot_flying_exec", "M_pilot_flying_execAddition.stcpp", false);
    }

	@Test
	public void testCarlights() throws Exception {
		testCpp("lustre_benchmarks/M_carlights2_v4_exec", "M_carlights2_v4_exec", "M_carlights2_v4_execAddition.stcpp", false);
	}

}