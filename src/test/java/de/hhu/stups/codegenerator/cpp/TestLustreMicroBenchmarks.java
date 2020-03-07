package de.hhu.stups.codegenerator.cpp;

import org.junit.Test;

public class TestLustreMicroBenchmarks extends TestCpp {

	@Test
	public void testAnd() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_and_exec", "microbenchmarks_and_exec", "microbenchmarks_and_execAddition.stcpp", false);
	}

	@Test
	public void testCurrentBoolean() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_current_boolean_exec", "microbenchmarks_current_boolean_exec", "microbenchmarks_current_boolean_execAddition.stcpp", false);
	}

	@Test
	public void testCurrentInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_current_integer_exec", "microbenchmarks_current_integer_exec", "microbenchmarks_current_integer_execAddition.stcpp", false);
	}

	@Test
	public void testDivideInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_divide_integer_exec", "microbenchmarks_divide_integer_exec", "microbenchmarks_divide_integer_execAddition.stcpp", false);
	}

	@Test
	public void testEqualBoolean() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_equal_boolean_exec", "microbenchmarks_equal_boolean_exec", "microbenchmarks_equal_boolean_execAddition.stcpp", false);
	}

	@Test
	public void testEqualInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_equal_integer_exec", "microbenchmarks_equal_integer_exec", "microbenchmarks_equal_integer_execAddition.stcpp", false);
	}

	@Test
	public void testFbyBoolean() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_fby_boolean_exec", "microbenchmarks_fby_boolean_exec", "microbenchmarks_fby_boolean_execAddition.stcpp", false);
	}

	@Test
	public void testFbyInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_fby_integer_exec", "microbenchmarks_fby_integer_exec", "microbenchmarks_fby_integer_execAddition.stcpp", false);
	}

	@Test
	public void testGreaterEqualInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_greater_equal_integer_exec", "microbenchmarks_greater_equal_integer_exec", "microbenchmarks_greater_equal_integer_execAddition.stcpp", false);
	}

	@Test
	public void testGreaterInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_greater_integer_exec", "microbenchmarks_greater_integer_exec", "microbenchmarks_greater_integer_execAddition.stcpp", false);
	}

	@Test
	public void testIteBoolean() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_ite_boolean_exec", "microbenchmarks_ite_boolean_exec", "microbenchmarks_ite_boolean_execAddition.stcpp", false);
	}

	@Test
	public void testIteInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_ite_integer_exec", "microbenchmarks_ite_integer_exec", "microbenchmarks_ite_integer_execAddition.stcpp", false);
	}

	@Test
	public void testLessEqualInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_less_equal_integer_exec", "microbenchmarks_less_equal_integer_exec", "microbenchmarks_less_equal_integer_execAddition.stcpp", false);
	}

	@Test
	public void testLessInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_less_integer_exec", "microbenchmarks_less_integer_exec", "microbenchmarks_less_integer_execAddition.stcpp", false);
	}

	@Test
	public void testMinusInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_minus_integer_exec", "microbenchmarks_minus_integer_exec", "microbenchmarks_minus_integer_execAddition.stcpp", false);
	}

	@Test
	public void testMultiplyInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_multiply_integer_exec", "microbenchmarks_multiply_integer_exec", "microbenchmarks_multiply_integer_execAddition.stcpp", false);
	}

	@Test
	public void testNot() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_not_exec", "microbenchmarks_not_exec", "microbenchmarks_not_execAddition.stcpp", false);
	}

	@Test
	public void testOr() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_or_exec", "microbenchmarks_or_exec", "microbenchmarks_or_execAddition.stcpp", false);
	}

	@Test
	public void testPlusInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_plus_integer_exec", "microbenchmarks_plus_integer_exec", "microbenchmarks_plus_integer_execAddition.stcpp", false);
	}

	@Test
	public void testPreBoolean() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_pre_boolean_exec", "microbenchmarks_pre_boolean_exec", "microbenchmarks_pre_boolean_execAddition.stcpp", false);
	}

	@Test
	public void testPreInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_pre_integer_exec", "microbenchmarks_pre_integer_exec", "microbenchmarks_pre_integer_execAddition.stcpp", false);
	}

	@Test
	public void testUnequalBoolean() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_unequal_boolean_exec", "microbenchmarks_unequal_boolean_exec", "microbenchmarks_unequal_boolean_execAddition.stcpp", false);
	}

	@Test
	public void testUnequalInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_unequal_integer_exec", "microbenchmarks_unequal_integer_exec", "microbenchmarks_unequal_integer_execAddition.stcpp", false);
	}

	@Test
	public void testWhenBoolean() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_when_boolean_exec", "microbenchmarks_when_boolean_exec", "microbenchmarks_when_boolean_execAddition.stcpp", false);
	}

	@Test
	public void testWhenInteger() throws Exception {
		testCpp("lustre_microbenchmarks/microbenchmarks_when_integer_exec", "microbenchmarks_when_integer_exec", "microbenchmarks_when_integer_execAddition.stcpp", false);
	}

}