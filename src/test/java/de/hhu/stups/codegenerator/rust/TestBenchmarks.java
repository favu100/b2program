package de.hhu.stups.codegenerator.rust;

import org.junit.Ignore;
import org.junit.Test;

public class TestBenchmarks extends TestRS {

	@Test
	public void testPlus() throws Exception {
		testRS("arithmetic/Plus", "Plus", "PlusAddition.strs", true);
	}

	@Test
	public void testMinus2() throws Exception {
		testRS("arithmetic/Minus", "Minus", "MinusAddition.strs", true);
	}

	@Test
	public void testMultiply2() throws Exception {
		testRS("arithmetic/Multiply", "Multiply", "MultiplyAddition.strs", true);
	}

	@Test
	public void testDivide2() throws Exception {
		testRS("arithmetic/Divide", "Divide", "DivideAddition.strs", true);
	}


	@Test
	public void testModulo2() throws Exception {
		testRS("arithmetic/Modulo", "Modulo", "ModuloAddition.strs", true);
	}

	@Test
	public void testNegative() throws Exception {
		testRS("arithmetic/Negative", "Negative", "NegativeAddition.strs", true);
	}

	@Ignore
	@Test
	public void testPositive() throws Exception {
		testRS("arithmetic/Positive");
	}

	/*@Test
	public void testSmallNumbers() throws Exception {
		testRS("integers/SmallNumbers", "SmallNumbersAddition.strs", true);
	}

	@Test
	public void testBigNumbers() throws Exception {
		testRS("integers/BigNumbers", "BigNumbersAddition.strs", true);
	}*/

	@Test
	public void testAnd2() throws Exception {
		testRS("logical/And", "And", "AndAddition.strs", true);
	}


	@Test
	public void testOr2() throws Exception {
		testRS("logical/Or", "Or", "OrAddition.strs", true);
	}


	@Test
	public void testImpliesPerformance() throws Exception {
		testRS("logical/Implies", "Implies", "ImpliesAddition.strs", true);
	}

	@Test
	public void testNot2() throws Exception {
		testRS("logical/Not");
	}

	@Test
	public void testEquivalent2() throws Exception {
		testRS("logical/Equivalent", "Equivalent", "EquivalentAddition.strs", true);
	}

	@Test
	public void testBooleanExpression() throws Exception {
		testRS("logical/BooleanExpression");
	}

	@Test
	public void testBooleanConstant() throws Exception {
		testRS("logical/BooleanConstant");
	}

	@Test
	public void testLess2() throws Exception {
		testRS("comparison/Less", "Less", "LessAddition.strs", true);
	}

	@Test
	public void testLessEqual2() throws Exception {
		testRS("comparison/LessEqual", "LessEqual", "LessEqualAddition.strs", true);
	}

	@Test
	public void testGreater2() throws Exception {
		testRS("comparison/Greater", "Greater", "GreaterAddition.strs", true);
	}


	@Test
	public void testGreaterEqual2() throws Exception {
		testRS("comparison/GreaterEqual", "GreaterEqual", "GreaterEqualAddition.strs", true);
	}


	@Test
	public void tessEqual() throws Exception {
		testRS("comparison/Equal", "Equal", "EqualAddition.strs", true);
	}


	@Test
	public void testUnequal2() throws Exception {
		testRS("comparison/Unequal", "Unequal", "UnequalAddition.strs", true);
	}

	@Test
	public void testCardBig() throws Exception {
		testRS("setoperation_big/SetCardBig", "SetCardBig", "SetCardBigAddition.strs", false);
	}

	@Test
	public void testCardBig2() throws Exception {
		testRS("setoperation_big/SetCardBig2");
	}


	@Test
	public void testDifferenceBig() throws Exception {
		testRS("setoperation_big/SetDifferenceBig", "SetDifferenceBig", "SetDifferenceBigAddition.strs", true);
	}

	@Test
	public void testDifferenceBig2() throws Exception {
		testRS("setoperation_big/SetDifferenceBig2");
	}

	@Test
	public void testElementOfBig() throws Exception {
		testRS("setoperation_big/SetElementOfBig", "SetElementOfBig", "SetElementOfBigAddition.strs", true);
	}

	@Test
	public void testElementOfBig2() throws Exception {
		testRS("setoperation_big/SetElementOfBig2");
	}

	@Test
	public void testIntersectionBig() throws Exception {
		testRS("setoperation_big/SetIntersectionBig", "SetIntersectionBig", "SetIntersectionBigAddition.strs", true);
	}

	@Test
	public void testIntersectionBig2() throws Exception {
		testRS("setoperation_big/SetIntersectionBig2");
	}

	@Test
	public void testUnionBig() throws Exception {
		testRS("setoperation_big/SetUnionBig", "SetUnionBig", "SetUnionBigAddition.strs", false);
	}

	@Test
	public void testUnionBig2() throws Exception {
		testRS("setoperation_big/SetUnionBig2");
	}


	@Test
	public void testCardSmall() throws Exception {
		testRS("setoperation_small/SetCardSmall", "SetCardSmall", "SetCardSmallAddition.strs", true);
	}

	@Test
	public void testCardSmall2() throws Exception {
		testRS("setoperation_small/SetCardSmall2");
	}


	@Test
	public void testDifferenceSmall() throws Exception {
		testRS("setoperation_small/SetDifferenceSmall", "SetDifferenceSmall", "SetDifferenceSmallAddition.strs", true);
	}

	@Test
	public void testDifferenceSmall2() throws Exception {
		testRS("setoperation_small/SetDifferenceSmall2");
	}


	@Test
	public void testElementOfSmall() throws Exception {
		testRS("setoperation_small/SetElementOfSmall", "SetElementOfSmall", "SetElementOfSmallAddition.strs", true);
	}

	@Test
	public void testElementOfSmall2() throws Exception {
		testRS("setoperation_small/SetElementOfSmall2");
	}


	@Test
	public void testIntersectionSmall() throws Exception {
		testRS("setoperation_small/SetIntersectionSmall", "SetIntersectionSmall", "SetIntersectionSmallAddition.strs", true);
	}

	@Test
	public void testIntersectionSmall2() throws Exception {
		testRS("setoperation_small/SetIntersectionSmall2");
	}

	@Test
	public void testUnionSmall() throws Exception {
		testRS("setoperation_small/SetUnionSmall", "SetUnionSmall", "SetUnionSmallAddition.strs", true);
	}

	@Test
	public void testUnionSmall2() throws Exception {
		testRS("setoperation_small/SetUnionSmall2");
	}

	@Test
	public void testRangeBig() throws Exception {
		testRS("range_big/RangeBig", "RangeBig", "RangeBigAddition.strs", true);
	}

	@Test
	public void testRangeCardBig() throws Exception {
		testRS("range_big/RangeCardBig", "RangeCardBig", "RangeCardBigAddition.strs", false);
	}

	@Test
	public void testRangeCardBig2() throws Exception {
		testRS("range_big/RangeCardBig2");
	}


	@Test
	public void testRangeDifferenceBig() throws Exception {
		testRS("range_big/RangeDifferenceBig", "RangeDifferenceBig", "RangeDifferenceBigAddition.strs", true);
	}

	@Test
	public void testRangeDifferenceBig2() throws Exception {
		testRS("range_big/RangeDifferenceBig2");
	}


	@Test
	public void testRangeElementOfBig() throws Exception {
		testRS("range_big/RangeElementOfBig", "RangeElementOfBig", "RangeElementOfBigAddition.strs", true);
	}

	@Test
	public void testRangeElementOfBig2() throws Exception {
		testRS("range_big/RangeElementOfBig2");
	}


	@Test
	public void testRangeIntersectionBig() throws Exception {
		testRS("range_big/RangeIntersectionBig", "RangeIntersectionBig", "RangeIntersectionBigAddition.strs", true);
	}

	@Test
	public void testRangeIntersectionBig2() throws Exception {
		testRS("range_big/RangeIntersectionBig2");
	}


	@Test
	public void testRangeUnionBig() throws Exception {
		testRS("range_big/RangeUnionBig", "RangeUnionBig", "RangeUnionBigAddition.strs", false);
	}

	@Test
	public void testRangeUnionBig2() throws Exception {
		testRS("range_big/RangeUnionBig2");
	}


	@Test
	public void testRangeSmall() throws Exception {
		testRS("range_small/RangeSmall", "RangeSmall", "RangeSmallAddition.strs", true);
	}


	@Test
	public void testRangeCardSmall() throws Exception {
		testRS("range_small/RangeCardSmall", "RangeCardSmall", "RangeCardSmallAddition.strs", true);
	}

	@Test
	public void testRangeCardSmall2() throws Exception {
		testRS("range_small/RangeCardSmall2");
	}


	@Test
	public void testRangeDifferenceSmall() throws Exception {
		testRS("range_small/RangeDifferenceSmall", "RangeDifferenceSmall", "RangeDifferenceSmallAddition.strs", true);
	}

	@Test
	public void testRangeDifferenceSmall2() throws Exception {
		testRS("range_small/RangeDifferenceSmall2");
	}

	@Test
	public void testRangeElementOfSmall() throws Exception {
		testRS("range_small/RangeElementOfSmall", "RangeElementOfSmall", "RangeElementOfSmallAddition.strs", true);
	}

	@Test
	public void testRangeElementOfSmall2() throws Exception {
		testRS("range_small/RangeElementOfSmall2");
	}

	@Test
	public void testRangeIntersectionSmall() throws Exception {
		testRS("range_small/RangeIntersectionSmall", "RangeIntersectionSmall", "RangeIntersectionSmallAddition.strs", true);
	}

	@Test
	public void testRangeIntersectionSmall2() throws Exception {
		testRS("range_small/RangeIntersectionSmall2");
	}

	@Test
	public void testRangeUnionSmall() throws Exception {
		testRS("range_small/RangeUnionSmall", "RangeUnionSmall", "RangeUnionSmallAddition.strs", true);
	}

	@Test
	public void testRangeUnionSmall2() throws Exception {
		testRS("range_small/RangeUnionSmall2");
	}

	@Test
	public void testLiftBenchmarks() throws Exception {
		testRS("liftbenchmarks/LiftExec", "LiftExec", "LiftExecAddition.strs", true);
	}


	@Test
	public void testSieveBenchmarks() throws Exception {
		testRS("sievebenchmarks/Sieve", "Sieve", "SieveAddition.strs", true);
	}

	@Test
	public void testTrafficLightBenchmarks() throws Exception {
		testRS("trafficlightbenchmarks/TrafficLightExec", "TrafficLightExec", "TrafficLightExecAddition.strs", true);
	}

	@Test
	public void testIncreasingSet() throws Exception {
		testRS("setoperationbenchmarks/IncreasingSet");
	}

	@Test
	public void testSetOperation() throws Exception {
		testRS("setoperationbenchmarks/SetOperation", "SetOperation", "SetOperationAddition.strs", true);
	}

}