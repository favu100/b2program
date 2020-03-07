package de.hhu.stups.codegenerator.java;

import org.junit.Test;

public class TestLustreBenchmarks extends TestJava {

	@Test
	public void testLift() throws Exception {
		testJava("lustre_benchmarks/Lift_main_exec", "Lift_main_exec", "Lift_main_execAddition.stjava", false);
	}

	@Test
	public void testLiftVerif() throws Exception {
		testJava("lustre_benchmarks/Lift_verif_exec", "Lift_verif_exec", "Lift_verif_execAddition.stjava", false);
	}

	@Test
	public void testSLOW_TIME_STABLE() throws Exception {
		testJava("lustre_benchmarks/SLOW_TIME_STABLE_exec", "SLOW_TIME_STABLE_exec", "SLOW_TIME_STABLE_execAddition.stjava", false);
	}

	@Test
	public void testSpeed() throws Exception {
		testJava("lustre_benchmarks/speed_main_exec", "speed_main_exec", "speed_main_execAddition.stjava", false);
	}

	@Test
	public void testSpeedVerif() throws Exception {
		testJava("lustre_benchmarks/speed_verif_exec", "speed_verif_exec", "speed_verif_execAddition.stjava", false);
	}

	@Test
	public void testUMS() throws Exception {
		testJava("lustre_benchmarks/UMS_main_exec", "UMS_main_exec", "UMS_main_execAddition.stjava", false);
	}

	@Test
	public void testUMSVerif() throws Exception {
		testJava("lustre_benchmarks/UMS_verif_exec", "UMS_verif_exec", "UMS_verif_execAddition.stjava", false);
	}

}