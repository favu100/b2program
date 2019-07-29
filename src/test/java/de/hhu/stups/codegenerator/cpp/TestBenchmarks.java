package de.hhu.stups.codegenerator.cpp;

import org.junit.Ignore;
import org.junit.Test;

public class TestBenchmarks extends TestCpp {

	@Test
	public void testPlus() throws Exception {
		testCpp("arithmetic/Plus", "Plus", "PlusAddition.stCpp", true);
	}

	@Test
	public void testMinus2() throws Exception {
		testCpp("arithmetic/Minus", "Minus", "MinusAddition.stCpp", true);
	}

	@Test
	public void testMultiply2() throws Exception {
		testCpp("arithmetic/Multiply", "Multiply", "MultiplyAddition.stCpp", true);
	}

	@Test
	public void testDivide2() throws Exception {
		testCpp("arithmetic/Divide", "Divide", "DivideAddition.stCpp", true);
	}


	@Test
	public void testModulo2() throws Exception {
		testCpp("arithmetic/Modulo", "Modulo", "ModuloAddition.stCpp", true);
	}

	@Test
	public void testNegative() throws Exception {
		testCpp("arithmetic/Negative", "Negative", "NegativeAddition.stCpp", true);
	}

	@Ignore
	@Test
	public void testPositive() throws Exception {
		testCpp("arithmetic/Positive");
	}

	/*@Test
	public void testSmallNumbers() throws Exception {
		testCpp("integers/SmallNumbers", "SmallNumbersAddition.stCpp", true);
	}

	@Test
	public void testBigNumbers() throws Exception {
		testCpp("integers/BigNumbers", "BigNumbersAddition.stCpp", true);
	}*/

	@Test
	public void testAnd2() throws Exception {
		testCpp("logical/And", "And", "AndAddition.stCpp", true);
	}


	@Test
	public void testOr2() throws Exception {
		testCpp("logical/Or", "Or", "OrAddition.stCpp", true);
	}


	@Test
	public void testImpliesPerformance() throws Exception {
		testCpp("logical/Implies", "Implies", "ImpliesAddition.stCpp", true);
	}

	@Test
	public void testNot2() throws Exception {
		testCpp("logical/Not");
	}

	@Test
	public void testEquivalent2() throws Exception {
		testCpp("logical/Equivalent", "Equivalent", "EquivalentAddition.stCpp", true);
	}

	@Test
	public void testBooleanExpression() throws Exception {
		testCpp("logical/BooleanExpression");
	}

	@Test
	public void testBooleanConstant() throws Exception {
		testCpp("logical/BooleanConstant");
	}

	@Test
	public void testLess2() throws Exception {
		testCpp("comparison/Less", "Less", "LessAddition.stCpp", true);
	}

	@Test
	public void testLessEqual2() throws Exception {
		testCpp("comparison/LessEqual", "LessEqual", "LessEqualAddition.stCpp", true);
	}

	@Test
	public void testGreater2() throws Exception {
		testCpp("comparison/Greater", "Greater", "GreaterAddition.stCpp", true);
	}


	@Test
	public void testGreaterEqual2() throws Exception {
		testCpp("comparison/GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stCpp", true);
	}


	@Test
	public void tessEqual() throws Exception {
		testCpp("comparison/Equal", "Equal", "EqualAddition.stCpp", true);
	}


	@Test
	public void testUnequal2() throws Exception {
		testCpp("comparison/Unequal", "Unequal", "UnequalAddition.stCpp", true);
	}

	@Test
	public void testCardBig() throws Exception {
		testCpp("setoperation_big/SetCardBig", "SetCardBig", "SetCardBigAddition.stCpp", false);
	}

	@Test
	public void testCardBig2() throws Exception {
		testCpp("setoperation_big/SetCardBig2");
	}


	@Test
	public void testDifferenceBig() throws Exception {
		testCpp("setoperation_big/SetDifferenceBig", "SetDifferenceBig", "SetDifferenceBigAddition.stCpp", true);
	}

	@Test
	public void testDifferenceBig2() throws Exception {
		testCpp("setoperation_big/SetDifferenceBig2");
	}

	@Test
	public void testElementOfBig() throws Exception {
		testCpp("setoperation_big/SetElementOfBig", "SetElementOfBig", "SetElementOfBigAddition.stCpp", true);
	}

	@Test
	public void testElementOfBig2() throws Exception {
		testCpp("setoperation_big/SetElementOfBig2");
	}

	@Test
	public void testIntersectionBig() throws Exception {
		testCpp("setoperation_big/SetIntersectionBig", "SetIntersectionBig", "SetIntersectionBigAddition.stCpp", true);
	}

	@Test
	public void testIntersectionBig2() throws Exception {
		testCpp("setoperation_big/SetIntersectionBig2");
	}

	@Test
	public void testUnionBig() throws Exception {
		testCpp("setoperation_big/SetUnionBig", "SetUnionBig", "SetUnionBigAddition.stCpp", false);
	}

	@Test
	public void testUnionBig2() throws Exception {
		testCpp("setoperation_big/SetUnionBig2");
	}


	@Test
	public void testCardSmall() throws Exception {
		testCpp("setoperation_small/SetCardSmall", "SetCardSmall", "SetCardSmallAddition.stCpp", true);
	}

	@Test
	public void testCardSmall2() throws Exception {
		testCpp("setoperation_small/SetCardSmall2");
	}


	@Test
	public void testDifferenceSmall() throws Exception {
		testCpp("setoperation_small/SetDifferenceSmall", "SetDifferenceSmall", "SetDifferenceSmallAddition.stCpp", true);
	}

	@Test
	public void testDifferenceSmall2() throws Exception {
		testCpp("setoperation_small/SetDifferenceSmall2");
	}


	@Test
	public void testElementOfSmall() throws Exception {
		testCpp("setoperation_small/SetElementOfSmall", "SetElementOfSmall", "SetElementOfSmallAddition.stCpp", true);
	}

	@Test
	public void testElementOfSmall2() throws Exception {
		testCpp("setoperation_small/SetElementOfSmall2");
	}


	@Test
	public void testIntersectionSmall() throws Exception {
		testCpp("setoperation_small/SetIntersectionSmall", "SetIntersectionSmall", "SetIntersectionSmallAddition.stCpp", true);
	}

	@Test
	public void testIntersectionSmall2() throws Exception {
		testCpp("setoperation_small/SetIntersectionSmall2");
	}

	@Test
	public void testUnionSmall() throws Exception {
		testCpp("setoperation_small/SetUnionSmall", "SetUnionSmall", "SetUnionSmallAddition.stCpp", true);
	}

	@Test
	public void testUnionSmall2() throws Exception {
		testCpp("setoperation_small/SetUnionSmall2");
	}

	@Test
	public void testRangeBig() throws Exception {
		testCpp("range_big/RangeBig", "RangeBig", "RangeBigAddition.stCpp", true);
	}

	@Test
	public void testRangeCardBig() throws Exception {
		testCpp("range_big/RangeCardBig", "RangeCardBig", "RangeCardBigAddition.stCpp", false);
	}

	@Test
	public void testRangeCardBig2() throws Exception {
		testCpp("range_big/RangeCardBig2");
	}


	@Test
	public void testRangeDifferenceBig() throws Exception {
		testCpp("range_big/RangeDifferenceBig", "RangeDifferenceBig", "RangeDifferenceBigAddition.stCpp", true);
	}

	@Test
	public void testRangeDifferenceBig2() throws Exception {
		testCpp("range_big/RangeDifferenceBig2");
	}


	@Test
	public void testRangeElementOfBig() throws Exception {
		testCpp("range_big/RangeElementOfBig", "RangeElementOfBig", "RangeElementOfBigAddition.stCpp", true);
	}

	@Test
	public void testRangeElementOfBig2() throws Exception {
		testCpp("range_big/RangeElementOfBig2");
	}


	@Test
	public void testRangeIntersectionBig() throws Exception {
		testCpp("range_big/RangeIntersectionBig", "RangeIntersectionBig", "RangeIntersectionBigAddition.stCpp", true);
	}

	@Test
	public void testRangeIntersectionBig2() throws Exception {
		testCpp("range_big/RangeIntersectionBig2");
	}


	@Test
	public void testRangeUnionBig() throws Exception {
		testCpp("range_big/RangeUnionBig", "RangeUnionBig", "RangeUnionBigAddition.stCpp", false);
	}

	@Test
	public void testRangeUnionBig2() throws Exception {
		testCpp("range_big/RangeUnionBig2");
	}


	@Test
	public void testRangeSmall() throws Exception {
		testCpp("range_small/RangeSmall", "RangeSmall", "RangeSmallAddition.stCpp", true);
	}


	@Test
	public void testRangeCardSmall() throws Exception {
		testCpp("range_small/RangeCardSmall", "RangeCardSmall", "RangeCardSmallAddition.stCpp", true);
	}

	@Test
	public void testRangeCardSmall2() throws Exception {
		testCpp("range_small/RangeCardSmall2");
	}


	@Test
	public void testRangeDifferenceSmall() throws Exception {
		testCpp("range_small/RangeDifferenceSmall", "RangeDifferenceSmall", "RangeDifferenceSmallAddition.stCpp", true);
	}

	@Test
	public void testRangeDifferenceSmall2() throws Exception {
		testCpp("range_small/RangeDifferenceSmall2");
	}

	@Test
	public void testRangeElementOfSmall() throws Exception {
		testCpp("range_small/RangeElementOfSmall", "RangeElementOfSmall", "RangeElementOfSmallAddition.stCpp", true);
	}

	@Test
	public void testRangeElementOfSmall2() throws Exception {
		testCpp("range_small/RangeElementOfSmall2");
	}

	@Test
	public void testRangeIntersectionSmall() throws Exception {
		testCpp("range_small/RangeIntersectionSmall", "RangeIntersectionSmall", "RangeIntersectionSmallAddition.stCpp", true);
	}

	@Test
	public void testRangeIntersectionSmall2() throws Exception {
		testCpp("range_small/RangeIntersectionSmall2");
	}

	@Test
	public void testRangeUnionSmall() throws Exception {
		testCpp("range_small/RangeUnionSmall", "RangeUnionSmall", "RangeUnionSmallAddition.stCpp", true);
	}

	@Test
	public void testRangeUnionSmall2() throws Exception {
		testCpp("range_small/RangeUnionSmall2");
	}

	@Test
	public void testLiftBenchmarks() throws Exception {
		testCpp("liftbenchmarks/LiftExec", "LiftExec", "LiftExecAddition.stCpp", true);
	}


	@Test
	public void testSieveBenchmarks() throws Exception {
		testCpp("sievebenchmarks/Sieve", "Sieve", "SieveAddition.stCpp", true);
	}

	@Test
	public void testTrafficLightBenchmarks() throws Exception {
		testCpp("trafficlightbenchmarks/TrafficLightExec", "TrafficLightExec", "TrafficLightExecAddition.stCpp", true);
	}

	@Test
	public void testIncreasingSet() throws Exception {
		testCpp("setoperationbenchmarks/IncreasingSet");
	}

	@Test
	public void testSetOperation() throws Exception {
		testCpp("setoperationbenchmarks/SetOperation", "SetOperation", "SetOperationAddition.stCpp", true);
	}

}