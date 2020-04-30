package de.hhu.stups.codegenerator.java;

import org.junit.Test;

public class TestLustreBenchmarks extends TestJava {

	@Test
	public void testLift() throws Exception {
		testJava("lustre_benchmarks/M_Lift_exec", "M_Lift_exec", "M_Lift_execAddition.stjava", false);
	}

	@Test
	public void testSLOW_TIME_STABLE() throws Exception {
		testJava("lustre_benchmarks/M_SLOW_TIME_STABLE_exec", "M_SLOW_TIME_STABLE_exec", "M_SLOW_TIME_STABLE_execAddition.stjava", false);
	}

	@Test
	public void testSpeed() throws Exception {
		testJava("lustre_benchmarks/M_speed_main_exec", "M_speed_main_exec", "M_speed_main_execAddition.stjava", false);
	}

	@Test
	public void testSpeedVerif() throws Exception {
		testJava("lustre_benchmarks/M_speed_verif_exec", "M_speed_verif_exec", "M_speed_verif_execAddition.stjava", false);
	}

	@Test
	public void testUMS() throws Exception {
		testJava("lustre_benchmarks/M_UMS_main_exec", "M_UMS_main_exec", "M_UMS_main_execAddition.stjava", false);
	}

	@Test
	public void testUMSVerif() throws Exception {
		testJava("lustre_benchmarks/M_UMS_verif_exec", "M_UMS_verif_exec", "M_UMS_verif_execAddition.stjava", false);
	}

	@Test
	public void testPilotFlying() throws Exception {
		testJava("lustre_benchmarks/M_pilot_flying_exec", "M_pilot_flying_exec", "M_pilot_flying_execAddition.stjava", false);
	}

}