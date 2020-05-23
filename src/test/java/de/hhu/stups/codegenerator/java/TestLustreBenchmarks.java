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

	@Test
	public void testCarlights() throws Exception {
		testJava("lustre_benchmarks/M_carlights2_v4_exec", "M_carlights2_v4_exec", "M_carlights2_v4_execAddition.stjava", false);
	}

	@Test
	public void testMovingItem() throws Exception {
		testJava("lustre_benchmarks/M_MovingItem_main_exec", "M_MovingItem_main_exec", "M_MovingItem_main_execAddition.stjava", false);
	}

	@Test
	public void testPress() throws Exception {
		testJava("lustre_benchmarks/M_Press_main_exec", "M_Press_main_exec", "M_Press_main_execAddition.stjava", false);
	}

	@Test
	public void testRbase() throws Exception {
		testJava("lustre_benchmarks/M_Rbase_main_exec", "M_Rbase_main_exec", "M_Rbase_main_execAddition.stjava", false);
	}

	@Test
	public void testRgrips() throws Exception {
		testJava("lustre_benchmarks/M_Rgrips_main_exec", "M_Rgrips_main_exec", "M_Rgrips_main_execAddition.stjava", false);
	}

	@Test
	public void testSubmodeExample() throws Exception {
		testJava("lustre_benchmarks/M_SubmodeExample_exec", "M_SubmodeExample_exec", "M_SubmodeExample_execAddition.stjava", false);
	}

	@Test
	public void testVerifyMovingItem() throws Exception {
		testJava("lustre_benchmarks/M_VerifyMovingItem_exec", "M_VerifyMovingItem_exec", "M_VerifyMovingItem_execAddition.stjava", false);
	}

}