package de.hhu.stups.codegenerator.java;

import org.junit.Test;

public class TestLustreMicroBenchmarks extends TestJava {

	@Test
	public void testAnd() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_and_exec", "M_microbenchmarks_and_exec", "M_microbenchmarks_and_execAddition.stjava", false);
	}

	@Test
	public void testCurrentBoolean() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_current_boolean_exec", "M_microbenchmarks_current_boolean_exec", "M_microbenchmarks_current_boolean_execAddition.stjava", false);
	}

	@Test
	public void testCurrentInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_current_integer_exec", "M_microbenchmarks_current_integer_exec", "M_microbenchmarks_current_integer_execAddition.stjava", false);
	}

	@Test
	public void testDivideInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_divide_integer_exec", "M_microbenchmarks_divide_integer_exec", "M_microbenchmarks_divide_integer_execAddition.stjava", false);
	}

	@Test
	public void testModulo() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_modulo_exec", "M_microbenchmarks_modulo_exec", "M_microbenchmarks_modulo_execAddition.stjava", false);
	}

	@Test
	public void testEqualBoolean() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_equal_boolean_exec", "M_microbenchmarks_equal_boolean_exec", "M_microbenchmarks_equal_boolean_execAddition.stjava", false);
	}

	@Test
	public void testEqualInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_equal_integer_exec", "M_microbenchmarks_equal_integer_exec", "M_microbenchmarks_equal_integer_execAddition.stjava", false);
	}

	@Test
	public void testFbyBoolean() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_fby_boolean_exec", "M_microbenchmarks_fby_boolean_exec", "M_microbenchmarks_fby_boolean_execAddition.stjava", false);
	}

	@Test
	public void testFbyInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_fby_integer_exec", "M_microbenchmarks_fby_integer_exec", "M_microbenchmarks_fby_integer_execAddition.stjava", false);
	}

	@Test
	public void testGreaterEqualInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_greater_equal_integer_exec", "M_microbenchmarks_greater_equal_integer_exec", "M_microbenchmarks_greater_equal_integer_execAddition.stjava", false);
	}

	@Test
	public void testGreaterInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_greater_integer_exec", "M_microbenchmarks_greater_integer_exec", "M_microbenchmarks_greater_integer_execAddition.stjava", false);
	}

	@Test
	public void testIteBoolean() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_ite_boolean_exec", "M_microbenchmarks_ite_boolean_exec", "M_microbenchmarks_ite_boolean_execAddition.stjava", false);
	}

	@Test
	public void testIteInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_ite_integer_exec", "M_microbenchmarks_ite_integer_exec", "M_microbenchmarks_ite_integer_execAddition.stjava", false);
	}

	@Test
	public void testLessEqualInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_less_equal_integer_exec", "M_microbenchmarks_less_equal_integer_exec", "M_microbenchmarks_less_equal_integer_execAddition.stjava", false);
	}

	@Test
	public void testLessInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_less_integer_exec", "M_microbenchmarks_less_integer_exec", "M_microbenchmarks_less_integer_execAddition.stjava", false);
	}

	@Test
	public void testMinusInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_minus_integer_exec", "M_microbenchmarks_minus_integer_exec", "M_microbenchmarks_minus_integer_execAddition.stjava", false);
	}

    @Test
    public void testUnaryMinusInteger() throws Exception {
        testJava("lustre_microbenchmarks/M_microbenchmarks_unary_minus_integer_exec", "M_microbenchmarks_unary_minus_integer_exec", "M_microbenchmarks_unary_minus_integer_execAddition.stjava", false);
    }

	@Test
	public void testMultiplyInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_multiply_integer_exec", "M_microbenchmarks_multiply_integer_exec", "M_microbenchmarks_multiply_integer_execAddition.stjava", false);
	}

	@Test
	public void testNot() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_not_exec", "M_microbenchmarks_not_exec", "M_microbenchmarks_not_execAddition.stjava", false);
	}

	@Test
	public void testOr() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_or_exec", "M_microbenchmarks_or_exec", "M_microbenchmarks_or_execAddition.stjava", false);
	}

	@Test
	public void testPlusInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_plus_integer_exec", "M_microbenchmarks_plus_integer_exec", "M_microbenchmarks_plus_integer_execAddition.stjava", false);
	}

	@Test
	public void testPreBoolean() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_pre_boolean_exec", "M_microbenchmarks_pre_boolean_exec", "M_microbenchmarks_pre_boolean_execAddition.stjava", false);
	}

	@Test
	public void testPreInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_pre_integer_exec", "M_microbenchmarks_pre_integer_exec", "M_microbenchmarks_pre_integer_execAddition.stjava", false);
	}

	@Test
	public void testUnequalBoolean() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_unequal_boolean_exec", "M_microbenchmarks_unequal_boolean_exec", "M_microbenchmarks_unequal_boolean_execAddition.stjava", false);
	}

	@Test
	public void testUnequalInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_unequal_integer_exec", "M_microbenchmarks_unequal_integer_exec", "M_microbenchmarks_unequal_integer_execAddition.stjava", false);
	}

	@Test
	public void testWhenBoolean() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_when_boolean_exec", "M_microbenchmarks_when_boolean_exec", "M_microbenchmarks_when_boolean_execAddition.stjava", false);
	}

	@Test
	public void testWhenInteger() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_when_integer_exec", "M_microbenchmarks_when_integer_exec", "M_microbenchmarks_when_integer_execAddition.stjava", false);
	}

	@Test
	public void testAssertion() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_assertion_exec", "M_microbenchmarks_assertion_exec", "M_microbenchmarks_assertion_execAddition.stjava", false);
	}

	@Test
	public void testManyClocks() throws Exception {
		testJava("lustre_microbenchmarks/M_microbenchmarks_many_clocks_exec", "M_microbenchmarks_many_clocks_exec", "M_microbenchmarks_many_clocks_execAddition.stjava", false);
	}

}