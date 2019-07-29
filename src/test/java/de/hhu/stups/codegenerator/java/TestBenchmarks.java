package de.hhu.stups.codegenerator.java;

import org.junit.Ignore;
import org.junit.Test;

public class TestBenchmarks extends TestJava {

	@Test
	public void testPlus() throws Exception {
		testJava("arithmetic/Plus", "Plus", "PlusAddition.stjava", true);
	}

	@Test
	public void testMinus2() throws Exception {
		testJava("arithmetic/Minus", "Minus", "MinusAddition.stjava", true);
	}

	@Test
	public void testMultiply2() throws Exception {
		testJava("arithmetic/Multiply", "Multiply", "MultiplyAddition.stjava", true);
	}

	@Test
	public void testDivide2() throws Exception {
		testJava("arithmetic/Divide", "Divide", "DivideAddition.stjava", true);
	}


	@Test
	public void testModulo2() throws Exception {
		testJava("arithmetic/Modulo", "Modulo", "ModuloAddition.stjava", true);
	}

	@Test
	public void testNegative() throws Exception {
		testJava("arithmetic/Negative", "Negative", "NegativeAddition.stjava", true);
	}

	@Ignore
	@Test
	public void testPositive() throws Exception {
		testJava("arithmetic/Positive");
	}

	/*@Test
	public void testSmallNumbers() throws Exception {
		testJava("integers/SmallNumbers", "SmallNumbersAddition.stjava", true);
	}

	@Test
	public void testBigNumbers() throws Exception {
		testJava("integers/BigNumbers", "BigNumbersAddition.stjava", true);
	}*/

	@Test
	public void testAnd2() throws Exception {
		testJava("logical/And", "And", "AndAddition.stjava", true);
	}


	@Test
	public void testOr2() throws Exception {
		testJava("logical/Or", "Or", "OrAddition.stjava", true);
	}


	@Test
	public void testImpliesPerformance() throws Exception {
		testJava("logical/Implies", "Implies", "ImpliesAddition.stjava", true);
	}

	@Test
	public void testNot2() throws Exception {
		testJava("logical/Not");
	}

	@Test
	public void testEquivalent2() throws Exception {
		testJava("logical/Equivalent", "Equivalent", "EquivalentAddition.stjava", true);
	}

	@Test
	public void testBooleanExpression() throws Exception {
		testJava("logical/BooleanExpression");
	}

	@Test
	public void testBooleanConstant() throws Exception {
		testJava("logical/BooleanConstant");
	}

	@Test
	public void testLess2() throws Exception {
		testJava("comparison/Less", "Less", "LessAddition.stjava", true);
	}

	@Test
	public void testLessEqual2() throws Exception {
		testJava("comparison/LessEqual", "LessEqual", "LessEqualAddition.stjava", true);
	}

	@Test
	public void testGreater2() throws Exception {
		testJava("comparison/Greater", "Greater", "GreaterAddition.stjava", true);
	}


	@Test
	public void testGreaterEqual2() throws Exception {
		testJava("comparison/GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stjava", true);
	}


	@Test
	public void tessEqual() throws Exception {
		testJava("comparison/Equal", "Equal", "EqualAddition.stjava", true);
	}


	@Test
	public void testUnequal2() throws Exception {
		testJava("comparison/Unequal", "Unequal", "UnequalAddition.stjava", true);
	}

	@Test
	public void testCardBig() throws Exception {
		testJava("setoperation_big/SetCardBig", "SetCardBig", "SetCardBigAddition.stjava", false);
	}

	@Test
	public void testCardBig2() throws Exception {
		testJava("setoperation_big/SetCardBig2");
	}


	@Test
	public void testDifferenceBig() throws Exception {
		testJava("setoperation_big/SetDifferenceBig", "SetDifferenceBig", "SetDifferenceBigAddition.stjava", true);
	}

	@Test
	public void testDifferenceBig2() throws Exception {
		testJava("setoperation_big/SetDifferenceBig2");
	}

	@Test
	public void testElementOfBig() throws Exception {
		testJava("setoperation_big/SetElementOfBig", "SetElementOfBig", "SetElementOfBigAddition.stjava", true);
	}

	@Test
	public void testElementOfBig2() throws Exception {
		testJava("setoperation_big/SetElementOfBig2");
	}

	@Test
	public void testIntersectionBig() throws Exception {
		testJava("setoperation_big/SetIntersectionBig", "SetIntersectionBig", "SetIntersectionBigAddition.stjava", true);
	}

	@Test
	public void testIntersectionBig2() throws Exception {
		testJava("setoperation_big/SetIntersectionBig2");
	}

	@Test
	public void testUnionBig() throws Exception {
		testJava("setoperation_big/SetUnionBig", "SetUnionBig", "SetUnionBigAddition.stjava", false);
	}

	@Test
	public void testUnionBig2() throws Exception {
		testJava("setoperation_big/SetUnionBig2");
	}


	@Test
	public void testCardSmall() throws Exception {
		testJava("setoperation_small/SetCardSmall", "SetCardSmall", "SetCardSmallAddition.stjava", true);
	}

	@Test
	public void testCardSmall2() throws Exception {
		testJava("setoperation_small/SetCardSmall2");
	}


	@Test
	public void testDifferenceSmall() throws Exception {
		testJava("setoperation_small/SetDifferenceSmall", "SetDifferenceSmall", "SetDifferenceSmallAddition.stjava", true);
	}

	@Test
	public void testDifferenceSmall2() throws Exception {
		testJava("setoperation_small/SetDifferenceSmall2");
	}


	@Test
	public void testElementOfSmall() throws Exception {
		testJava("setoperation_small/SetElementOfSmall", "SetElementOfSmall", "SetElementOfSmallAddition.stjava", true);
	}

	@Test
	public void testElementOfSmall2() throws Exception {
		testJava("setoperation_small/SetElementOfSmall2");
	}


	@Test
	public void testIntersectionSmall() throws Exception {
		testJava("setoperation_small/SetIntersectionSmall", "SetIntersectionSmall", "SetIntersectionSmallAddition.stjava", true);
	}

	@Test
	public void testIntersectionSmall2() throws Exception {
		testJava("setoperation_small/SetIntersectionSmall2");
	}

	@Test
	public void testUnionSmall() throws Exception {
		testJava("setoperation_small/SetUnionSmall", "SetUnionSmall", "SetUnionSmallAddition.stjava", true);
	}

	@Test
	public void testUnionSmall2() throws Exception {
		testJava("setoperation_small/SetUnionSmall2");
	}

	@Test
	public void testRangeBig() throws Exception {
		testJava("range_big/RangeBig", "RangeBig", "RangeBigAddition.stjava", true);
	}

	@Test
	public void testRangeCardBig() throws Exception {
		testJava("range_big/RangeCardBig", "RangeCardBig", "RangeCardBigAddition.stjava", false);
	}

	@Test
	public void testRangeCardBig2() throws Exception {
		testJava("range_big/RangeCardBig2");
	}


	@Test
	public void testRangeDifferenceBig() throws Exception {
		testJava("range_big/RangeDifferenceBig", "RangeDifferenceBig", "RangeDifferenceBigAddition.stjava", true);
	}

	@Test
	public void testRangeDifferenceBig2() throws Exception {
		testJava("range_big/RangeDifferenceBig2");
	}


	@Test
	public void testRangeElementOfBig() throws Exception {
		testJava("range_big/RangeElementOfBig", "RangeElementOfBig", "RangeElementOfBigAddition.stjava", true);
	}

	@Test
	public void testRangeElementOfBig2() throws Exception {
		testJava("range_big/RangeElementOfBig2");
	}


	@Test
	public void testRangeIntersectionBig() throws Exception {
		testJava("range_big/RangeIntersectionBig", "RangeIntersectionBig", "RangeIntersectionBigAddition.stjava", true);
	}

	@Test
	public void testRangeIntersectionBig2() throws Exception {
		testJava("range_big/RangeIntersectionBig2");
	}


	@Test
	public void testRangeUnionBig() throws Exception {
		testJava("range_big/RangeUnionBig", "RangeUnionBig", "RangeUnionBigAddition.stjava", false);
	}

	@Test
	public void testRangeUnionBig2() throws Exception {
		testJava("range_big/RangeUnionBig2");
	}


	@Test
	public void testRangeSmall() throws Exception {
		testJava("range_small/RangeSmall", "RangeSmall", "RangeSmallAddition.stjava", true);
	}


	@Test
	public void testRangeCardSmall() throws Exception {
		testJava("range_small/RangeCardSmall", "RangeCardSmall", "RangeCardSmallAddition.stjava", true);
	}

	@Test
	public void testRangeCardSmall2() throws Exception {
		testJava("range_small/RangeCardSmall2");
	}


	@Test
	public void testRangeDifferenceSmall() throws Exception {
		testJava("range_small/RangeDifferenceSmall", "RangeDifferenceSmall", "RangeDifferenceSmallAddition.stjava", true);
	}

	@Test
	public void testRangeDifferenceSmall2() throws Exception {
		testJava("range_small/RangeDifferenceSmall2");
	}

	@Test
	public void testRangeElementOfSmall() throws Exception {
		testJava("range_small/RangeElementOfSmall", "RangeElementOfSmall", "RangeElementOfSmallAddition.stjava", true);
	}

	@Test
	public void testRangeElementOfSmall2() throws Exception {
		testJava("range_small/RangeElementOfSmall2");
	}

	@Test
	public void testRangeIntersectionSmall() throws Exception {
		testJava("range_small/RangeIntersectionSmall", "RangeIntersectionSmall", "RangeIntersectionSmallAddition.stjava", true);
	}

	@Test
	public void testRangeIntersectionSmall2() throws Exception {
		testJava("range_small/RangeIntersectionSmall2");
	}

	@Test
	public void testRangeUnionSmall() throws Exception {
		testJava("range_small/RangeUnionSmall", "RangeUnionSmall", "RangeUnionSmallAddition.stjava", true);
	}

	@Test
	public void testRangeUnionSmall2() throws Exception {
		testJava("range_small/RangeUnionSmall2");
	}

	@Test
	public void testLiftBenchmarks() throws Exception {
		testJava("liftbenchmarks/LiftExec", "LiftExec", "LiftExecAddition.stjava", true);
	}


	@Test
	public void testSieveBenchmarks() throws Exception {
		testJava("sievebenchmarks/Sieve", "Sieve", "SieveAddition.stjava", true);
	}

	@Test
	public void testTrafficLightBenchmarks() throws Exception {
		testJava("trafficlightbenchmarks/TrafficLightExec", "TrafficLightExec", "TrafficLightExecAddition.stjava", true);
	}

	@Test
	public void testIncreasingSet() throws Exception {
		testJava("setoperationbenchmarks/IncreasingSet");
	}

	@Test
	public void testSetOperation() throws Exception {
		testJava("setoperationbenchmarks/SetOperation", "SetOperation", "SetOperationAddition.stjava", true);
	}

}