package de.hhu.stups.codegenerator.cpp;

import org.junit.Test;

public class TestLustreBenchmarks extends TestCpp {

	@Test
	public void testLift() throws Exception {
		testCpp("lustre_benchmarks/Lift_main_exec", "Lift_main_exec", "Lift_main_execAddition.stcpp", false);
	}

	@Test
	public void testLiftVerif() throws Exception {
		testCpp("lustre_benchmarks/Lift_verif_exec", "Lift_verif_exec", "Lift_verif_execAddition.stcpp", false);
	}

	@Test
	public void testSLOW_TIME_STABLE() throws Exception {
		testCpp("lustre_benchmarks/SLOW_TIME_STABLE_exec", "SLOW_TIME_STABLE_exec", "SLOW_TIME_STABLE_execAddition.stcpp", false);
	}

	@Test
	public void testSpeed() throws Exception {
		testCpp("lustre_benchmarks/speed_main_exec", "speed_main_exec", "speed_main_execAddition.stcpp", false);
	}

	@Test
	public void testSpeedVerif() throws Exception {
		testCpp("lustre_benchmarks/speed_verif_exec", "speed_verif_exec", "speed_verif_execAddition.stcpp", false);
	}

	@Test
	public void testUMS() throws Exception {
		testCpp("lustre_benchmarks/UMS_main_exec", "UMS_main_exec", "UMS_main_execAddition.stcpp", false);
	}

	@Test
	public void testUMSVerif() throws Exception {
		testCpp("lustre_benchmarks/UMS_verif_exec", "UMS_verif_exec", "UMS_verif_execAddition.stcpp", false);
	}

}