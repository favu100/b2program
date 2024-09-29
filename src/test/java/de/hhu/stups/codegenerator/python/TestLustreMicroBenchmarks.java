package de.hhu.stups.codegenerator.python;

import org.junit.Ignore;
import org.junit.Test;

@Ignore
public class TestLustreMicroBenchmarks extends TestPython {

	@Test
	public void testAnd() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_and_exec", "M_microbenchmarks_and_exec", "M_microbenchmarks_and_execAddition.stpy", false);
	}

	@Test
	public void testCurrentBoolean() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_current_boolean_exec", "M_microbenchmarks_current_boolean_exec", "M_microbenchmarks_current_boolean_execAddition.stpy", false);
	}

	@Test
	public void testCurrentInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_current_integer_exec", "M_microbenchmarks_current_integer_exec", "M_microbenchmarks_current_integer_execAddition.stpy", false);
	}

	@Test
	public void testDivideInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_divide_integer_exec", "M_microbenchmarks_divide_integer_exec", "M_microbenchmarks_divide_integer_execAddition.stpy", false);
	}

	@Test
	public void testModulo() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_modulo_exec", "M_microbenchmarks_modulo_exec", "M_microbenchmarks_modulo_execAddition.stpy", false);
	}

	@Test
	public void testEqualBoolean() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_equal_boolean_exec", "M_microbenchmarks_equal_boolean_exec", "M_microbenchmarks_equal_boolean_execAddition.stpy", false);
	}

	@Test
	public void testEqualInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_equal_integer_exec", "M_microbenchmarks_equal_integer_exec", "M_microbenchmarks_equal_integer_execAddition.stpy", false);
	}

	@Test
	public void testFbyBoolean() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_fby_boolean_exec", "M_microbenchmarks_fby_boolean_exec", "M_microbenchmarks_fby_boolean_execAddition.stpy", false);
	}

	@Test
	public void testFbyInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_fby_integer_exec", "M_microbenchmarks_fby_integer_exec", "M_microbenchmarks_fby_integer_execAddition.stpy", false);
	}

	@Test
	public void testGreaterEqualInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_greater_equal_integer_exec", "M_microbenchmarks_greater_equal_integer_exec", "M_microbenchmarks_greater_equal_integer_execAddition.stpy", false);
	}

	@Test
	public void testGreaterInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_greater_integer_exec", "M_microbenchmarks_greater_integer_exec", "M_microbenchmarks_greater_integer_execAddition.stpy", false);
	}

	@Test
	public void testIteBoolean() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_ite_boolean_exec", "M_microbenchmarks_ite_boolean_exec", "M_microbenchmarks_ite_boolean_execAddition.stpy", false);
	}

	@Test
	public void testIteInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_ite_integer_exec", "M_microbenchmarks_ite_integer_exec", "M_microbenchmarks_ite_integer_execAddition.stpy", false);
	}

	@Test
	public void testLessEqualInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_less_equal_integer_exec", "M_microbenchmarks_less_equal_integer_exec", "M_microbenchmarks_less_equal_integer_execAddition.stpy", false);
	}

	@Test
	public void testLessInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_less_integer_exec", "M_microbenchmarks_less_integer_exec", "M_microbenchmarks_less_integer_execAddition.stpy", false);
	}

	@Test
	public void testMinusInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_minus_integer_exec", "M_microbenchmarks_minus_integer_exec", "M_microbenchmarks_minus_integer_execAddition.stpy", false);
	}

    @Test
    public void testUnaryMinusInteger() throws Exception {
        testPython("lustre_microbenchmarks/M_microbenchmarks_unary_minus_integer_exec", "M_microbenchmarks_unary_minus_integer_exec", "M_microbenchmarks_unary_minus_integer_execAddition.stpy", false);
    }

	@Test
	public void testMultiplyInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_multiply_integer_exec", "M_microbenchmarks_multiply_integer_exec", "M_microbenchmarks_multiply_integer_execAddition.stpy", false);
	}

	@Test
	public void testNot() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_not_exec", "M_microbenchmarks_not_exec", "M_microbenchmarks_not_execAddition.stpy", false);
	}

	@Test
	public void testOr() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_or_exec", "M_microbenchmarks_or_exec", "M_microbenchmarks_or_execAddition.stpy", false);
	}

	@Test
	public void testPlusInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_plus_integer_exec", "M_microbenchmarks_plus_integer_exec", "M_microbenchmarks_plus_integer_execAddition.stpy", false);
	}

	@Test
	public void testPreBoolean() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_pre_boolean_exec", "M_microbenchmarks_pre_boolean_exec", "M_microbenchmarks_pre_boolean_execAddition.stpy", false);
	}

	@Test
	public void testPreInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_pre_integer_exec", "M_microbenchmarks_pre_integer_exec", "M_microbenchmarks_pre_integer_execAddition.stpy", false);
	}

	@Test
	public void testUnequalBoolean() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_unequal_boolean_exec", "M_microbenchmarks_unequal_boolean_exec", "M_microbenchmarks_unequal_boolean_execAddition.stpy", false);
	}

	@Test
	public void testUnequalInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_unequal_integer_exec", "M_microbenchmarks_unequal_integer_exec", "M_microbenchmarks_unequal_integer_execAddition.stpy", false);
	}

	@Test
	public void testWhenBoolean() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_when_boolean_exec", "M_microbenchmarks_when_boolean_exec", "M_microbenchmarks_when_boolean_execAddition.stpy", false);
	}

	@Test
	public void testWhenInteger() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_when_integer_exec", "M_microbenchmarks_when_integer_exec", "M_microbenchmarks_when_integer_execAddition.stpy", false);
	}

	@Test
	public void testAssertion() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_assertion_exec", "M_microbenchmarks_assertion_exec", "M_microbenchmarks_assertion_execAddition.stpy", false);
	}

    @Test
    public void testNodeCall() throws Exception {
        testPython("lustre_microbenchmarks/M_microbenchmarks_node_call_exec", "M_microbenchmarks_node_call_exec", "M_microbenchmarks_node_call_execAddition.stpy", false);
    }

	@Test
	public void testManyClocks() throws Exception {
		testPython("lustre_microbenchmarks/M_microbenchmarks_many_clocks_exec", "M_microbenchmarks_many_clocks_exec", "M_microbenchmarks_many_clocks_execAddition.stpy", false);
	}

    @Test
    public void testManyLocalClocks() throws Exception {
        testPython("lustre_microbenchmarks/M_microbenchmarks_many_local_clocks_exec", "M_microbenchmarks_many_local_clocks_exec", "M_microbenchmarks_many_local_clocks_execAddition.stpy", false);
    }

}