package de.hhu.stups.codegenerator.js;

import org.junit.Ignore;
import org.junit.Test;

@Ignore
public class TestLustreMicroBenchmarks extends TestJs {

	@Test
	public void testAnd() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_and_exec", "M_microbenchmarks_and_exec", "M_microbenchmarks_and_execAddition.stjs", false);
	}

	@Test
	public void testCurrentBoolean() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_current_boolean_exec", "M_microbenchmarks_current_boolean_exec", "M_microbenchmarks_current_boolean_execAddition.stjs", false);
	}

	@Test
	public void testCurrentInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_current_integer_exec", "M_microbenchmarks_current_integer_exec", "M_microbenchmarks_current_integer_execAddition.stjs", false);
	}

	@Test
	public void testDivideInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_divide_integer_exec", "M_microbenchmarks_divide_integer_exec", "M_microbenchmarks_divide_integer_execAddition.stjs", false);
	}

	@Test
	public void testModulo() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_modulo_exec", "M_microbenchmarks_modulo_exec", "M_microbenchmarks_modulo_execAddition.stjs", false);
	}

	@Test
	public void testEqualBoolean() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_equal_boolean_exec", "M_microbenchmarks_equal_boolean_exec", "M_microbenchmarks_equal_boolean_execAddition.stjs", false);
	}

	@Test
	public void testEqualInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_equal_integer_exec", "M_microbenchmarks_equal_integer_exec", "M_microbenchmarks_equal_integer_execAddition.stjs", false);
	}

	@Test
	public void testFbyBoolean() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_fby_boolean_exec", "M_microbenchmarks_fby_boolean_exec", "M_microbenchmarks_fby_boolean_execAddition.stjs", false);
	}

	@Test
	public void testFbyInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_fby_integer_exec", "M_microbenchmarks_fby_integer_exec", "M_microbenchmarks_fby_integer_execAddition.stjs", false);
	}

	@Test
	public void testGreaterEqualInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_greater_equal_integer_exec", "M_microbenchmarks_greater_equal_integer_exec", "M_microbenchmarks_greater_equal_integer_execAddition.stjs", false);
	}

	@Test
	public void testGreaterInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_greater_integer_exec", "M_microbenchmarks_greater_integer_exec", "M_microbenchmarks_greater_integer_execAddition.stjs", false);
	}

	@Test
	public void testIteBoolean() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_ite_boolean_exec", "M_microbenchmarks_ite_boolean_exec", "M_microbenchmarks_ite_boolean_execAddition.stjs", false);
	}

	@Test
	public void testIteInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_ite_integer_exec", "M_microbenchmarks_ite_integer_exec", "M_microbenchmarks_ite_integer_execAddition.stjs", false);
	}

	@Test
	public void testLessEqualInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_less_equal_integer_exec", "M_microbenchmarks_less_equal_integer_exec", "M_microbenchmarks_less_equal_integer_execAddition.stjs", false);
	}

	@Test
	public void testLessInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_less_integer_exec", "M_microbenchmarks_less_integer_exec", "M_microbenchmarks_less_integer_execAddition.stjs", false);
	}

	@Test
	public void testMinusInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_minus_integer_exec", "M_microbenchmarks_minus_integer_exec", "M_microbenchmarks_minus_integer_execAddition.stjs", false);
	}

    @Test
    public void testUnaryMinusInteger() throws Exception {
        testJs("lustre_microbenchmarks/M_microbenchmarks_unary_minus_integer_exec", "M_microbenchmarks_unary_minus_integer_exec", "M_microbenchmarks_unary_minus_integer_execAddition.stjs", false);
    }

	@Test
	public void testMultiplyInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_multiply_integer_exec", "M_microbenchmarks_multiply_integer_exec", "M_microbenchmarks_multiply_integer_execAddition.stjs", false);
	}

	@Test
	public void testNot() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_not_exec", "M_microbenchmarks_not_exec", "M_microbenchmarks_not_execAddition.stjs", false);
	}

	@Test
	public void testOr() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_or_exec", "M_microbenchmarks_or_exec", "M_microbenchmarks_or_execAddition.stjs", false);
	}

	@Test
	public void testPlusInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_plus_integer_exec", "M_microbenchmarks_plus_integer_exec", "M_microbenchmarks_plus_integer_execAddition.stjs", false);
	}

	@Test
	public void testPreBoolean() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_pre_boolean_exec", "M_microbenchmarks_pre_boolean_exec", "M_microbenchmarks_pre_boolean_execAddition.stjs", false);
	}

	@Test
	public void testPreInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_pre_integer_exec", "M_microbenchmarks_pre_integer_exec", "M_microbenchmarks_pre_integer_execAddition.stjs", false);
	}

	@Test
	public void testUnequalBoolean() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_unequal_boolean_exec", "M_microbenchmarks_unequal_boolean_exec", "M_microbenchmarks_unequal_boolean_execAddition.stjs", false);
	}

	@Test
	public void testUnequalInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_unequal_integer_exec", "M_microbenchmarks_unequal_integer_exec", "M_microbenchmarks_unequal_integer_execAddition.stjs", false);
	}

	@Test
	public void testWhenBoolean() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_when_boolean_exec", "M_microbenchmarks_when_boolean_exec", "M_microbenchmarks_when_boolean_execAddition.stjs", false);
	}

	@Test
	public void testWhenInteger() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_when_integer_exec", "M_microbenchmarks_when_integer_exec", "M_microbenchmarks_when_integer_execAddition.stjs", false);
	}

	@Test
	public void testAssertion() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_assertion_exec", "M_microbenchmarks_assertion_exec", "M_microbenchmarks_assertion_execAddition.stjs", false);
	}

    @Test
    public void testNodeCall() throws Exception {
        testJs("lustre_microbenchmarks/M_microbenchmarks_node_call_exec", "M_microbenchmarks_node_call_exec", "M_microbenchmarks_node_call_execAddition.stjs", false);
    }

	@Test
	public void testManyClocks() throws Exception {
		testJs("lustre_microbenchmarks/M_microbenchmarks_many_clocks_exec", "M_microbenchmarks_many_clocks_exec", "M_microbenchmarks_many_clocks_execAddition.stjs", false);
	}

    @Test
    public void testManyLocalClocks() throws Exception {
        testJs("lustre_microbenchmarks/M_microbenchmarks_many_local_clocks_exec", "M_microbenchmarks_many_local_clocks_exec", "M_microbenchmarks_many_local_clocks_execAddition.stjs", false);
    }

}