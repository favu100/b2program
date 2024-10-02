package de.hhu.stups.codegenerator.ajs;

import org.junit.Ignore;
import org.junit.Test;

public class TestBenchmarks extends TestJs {

	@Test
	public void testPlus() throws Exception {
		testJs("arithmetic/Plus", "Plus", "PlusAddition.stjs", true);
	}

	@Test
	public void testMinus2() throws Exception {
		testJs("arithmetic/Minus", "Minus", "MinusAddition.stjs", true);
	}

	@Test
	public void testMultiply2() throws Exception {
		testJs("arithmetic/Multiply", "Multiply", "MultiplyAddition.stjs", true);
	}

	@Test
	public void testDivide2() throws Exception {
		testJs("arithmetic/Divide", "Divide", "DivideAddition.stjs", true);
	}


	@Test
	public void testModulo2() throws Exception {
		testJs("arithmetic/Modulo", "Modulo", "ModuloAddition.stjs", true);
	}

	@Test
	public void testNegative() throws Exception {
		testJs("arithmetic/Negative", "Negative", "NegativeAddition.stjs", true);
	}

	@Ignore
	@Test
	public void testPositive() throws Exception {
		testJs("arithmetic/Positive");
	}

	/*@Test
	public void testSmallNumbers() throws Exception {
		testJs("integers/SmallNumbers", "SmallNumbersAddition.stjs", true);
	}

	@Test
	public void testBigNumbers() throws Exception {
		testJs("integers/BigNumbers", "BigNumbersAddition.stjs", true);
	}*/

	@Test
	public void testAnd2() throws Exception {
		testJs("logical/And", "And", "AndAddition.stjs", true);
	}


	@Test
	public void testOr2() throws Exception {
		testJs("logical/Or", "Or", "OrAddition.stjs", true);
	}


	@Test
	public void testImpliesPerformance() throws Exception {
		testJs("logical/Implies", "Implies", "ImpliesAddition.stjs", true);
	}

	@Test
	public void testNot2() throws Exception {
		testJs("logical/Not");
	}

	@Test
	public void testEquivalent2() throws Exception {
		testJs("logical/Equivalent", "Equivalent", "EquivalentAddition.stjs", true);
	}

	@Test
	public void testBooleanExpression() throws Exception {
		testJs("logical/BooleanExpression");
	}

	@Test
	public void testBooleanConstant() throws Exception {
		testJs("logical/BooleanConstant");
	}

	@Test
	public void testLess2() throws Exception {
		testJs("comparison/Less", "Less", "LessAddition.stjs", true);
	}

	@Test
	public void testLessEqual2() throws Exception {
		testJs("comparison/LessEqual", "LessEqual", "LessEqualAddition.stjs", true);
	}

	@Test
	public void testGreater2() throws Exception {
		testJs("comparison/Greater", "Greater", "GreaterAddition.stjs", true);
	}


	@Test
	public void testGreaterEqual2() throws Exception {
		testJs("comparison/GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stjs", true);
	}


	@Test
	public void tessEqual() throws Exception {
		testJs("comparison/Equal", "Equal", "EqualAddition.stjs", true);
	}


	@Test
	public void testUnequal2() throws Exception {
		testJs("comparison/Unequal", "Unequal", "UnequalAddition.stjs", true);
	}

	@Test
	public void testCardBig() throws Exception {
		testJs("setoperation_big/SetCardBig", "SetCardBig", "SetCardBigAddition.stjs", false);
	}

	@Test
	public void testCardBig2() throws Exception {
		testJs("setoperation_big/SetCardBig2");
	}


	@Test
	public void testDifferenceBig() throws Exception {
		testJs("setoperation_big/SetDifferenceBig", "SetDifferenceBig", "SetDifferenceBigAddition.stjs", true);
	}

	@Test
	public void testDifferenceBig2() throws Exception {
		testJs("setoperation_big/SetDifferenceBig2");
	}

	@Test
	public void testElementOfBig() throws Exception {
		testJs("setoperation_big/SetElementOfBig", "SetElementOfBig", "SetElementOfBigAddition.stjs", true);
	}

	@Test
	public void testElementOfBig2() throws Exception {
		testJs("setoperation_big/SetElementOfBig2");
	}

	@Test
	public void testIntersectionBig() throws Exception {
		testJs("setoperation_big/SetIntersectionBig", "SetIntersectionBig", "SetIntersectionBigAddition.stjs", true);
	}

	@Test
	public void testIntersectionBig2() throws Exception {
		testJs("setoperation_big/SetIntersectionBig2");
	}

	@Test
	public void testUnionBig() throws Exception {
		testJs("setoperation_big/SetUnionBig", "SetUnionBig", "SetUnionBigAddition.stjs", false);
	}

	@Test
	public void testUnionBig2() throws Exception {
		testJs("setoperation_big/SetUnionBig2");
	}


	@Test
	public void testCardSmall() throws Exception {
		testJs("setoperation_small/SetCardSmall", "SetCardSmall", "SetCardSmallAddition.stjs", true);
	}

	@Test
	public void testCardSmall2() throws Exception {
		testJs("setoperation_small/SetCardSmall2");
	}


	@Test
	public void testDifferenceSmall() throws Exception {
		testJs("setoperation_small/SetDifferenceSmall", "SetDifferenceSmall", "SetDifferenceSmallAddition.stjs", true);
	}

	@Test
	public void testDifferenceSmall2() throws Exception {
		testJs("setoperation_small/SetDifferenceSmall2");
	}


	@Test
	public void testElementOfSmall() throws Exception {
		testJs("setoperation_small/SetElementOfSmall", "SetElementOfSmall", "SetElementOfSmallAddition.stjs", true);
	}

	@Test
	public void testElementOfSmall2() throws Exception {
		testJs("setoperation_small/SetElementOfSmall2");
	}


	@Test
	public void testIntersectionSmall() throws Exception {
		testJs("setoperation_small/SetIntersectionSmall", "SetIntersectionSmall", "SetIntersectionSmallAddition.stjs", true);
	}

	@Test
	public void testIntersectionSmall2() throws Exception {
		testJs("setoperation_small/SetIntersectionSmall2");
	}

	@Test
	public void testUnionSmall() throws Exception {
		testJs("setoperation_small/SetUnionSmall", "SetUnionSmall", "SetUnionSmallAddition.stjs", true);
	}

	@Test
	public void testUnionSmall2() throws Exception {
		testJs("setoperation_small/SetUnionSmall2");
	}

	@Test
	public void testRangeBig() throws Exception {
		testJs("range_big/RangeBig", "RangeBig", "RangeBigAddition.stjs", true);
	}

	@Test
	public void testRangeCardBig() throws Exception {
		testJs("range_big/RangeCardBig", "RangeCardBig", "RangeCardBigAddition.stjs", false);
	}

	@Test
	public void testRangeCardBig2() throws Exception {
		testJs("range_big/RangeCardBig2");
	}


	@Test
	public void testRangeDifferenceBig() throws Exception {
		testJs("range_big/RangeDifferenceBig", "RangeDifferenceBig", "RangeDifferenceBigAddition.stjs", true);
	}

	@Test
	public void testRangeDifferenceBig2() throws Exception {
		testJs("range_big/RangeDifferenceBig2");
	}


	@Test
	public void testRangeElementOfBig() throws Exception {
		testJs("range_big/RangeElementOfBig", "RangeElementOfBig", "RangeElementOfBigAddition.stjs", true);
	}

	@Test
	public void testRangeElementOfBig2() throws Exception {
		testJs("range_big/RangeElementOfBig2");
	}


	@Test
	public void testRangeIntersectionBig() throws Exception {
		testJs("range_big/RangeIntersectionBig", "RangeIntersectionBig", "RangeIntersectionBigAddition.stjs", true);
	}

	@Test
	public void testRangeIntersectionBig2() throws Exception {
		testJs("range_big/RangeIntersectionBig2");
	}


	@Test
	public void testRangeUnionBig() throws Exception {
		testJs("range_big/RangeUnionBig", "RangeUnionBig", "RangeUnionBigAddition.stjs", false);
	}

	@Test
	public void testRangeUnionBig2() throws Exception {
		testJs("range_big/RangeUnionBig2");
	}


	@Test
	public void testRangeSmall() throws Exception {
		testJs("range_small/RangeSmall", "RangeSmall", "RangeSmallAddition.stjs", true);
	}


	@Test
	public void testRangeCardSmall() throws Exception {
		testJs("range_small/RangeCardSmall", "RangeCardSmall", "RangeCardSmallAddition.stjs", true);
	}

	@Test
	public void testRangeCardSmall2() throws Exception {
		testJs("range_small/RangeCardSmall2");
	}


	@Test
	public void testRangeDifferenceSmall() throws Exception {
		testJs("range_small/RangeDifferenceSmall", "RangeDifferenceSmall", "RangeDifferenceSmallAddition.stjs", true);
	}

	@Test
	public void testRangeDifferenceSmall2() throws Exception {
		testJs("range_small/RangeDifferenceSmall2");
	}

	@Test
	public void testRangeElementOfSmall() throws Exception {
		testJs("range_small/RangeElementOfSmall", "RangeElementOfSmall", "RangeElementOfSmallAddition.stjs", true);
	}

	@Test
	public void testRangeElementOfSmall2() throws Exception {
		testJs("range_small/RangeElementOfSmall2");
	}

	@Test
	public void testRangeIntersectionSmall() throws Exception {
		testJs("range_small/RangeIntersectionSmall", "RangeIntersectionSmall", "RangeIntersectionSmallAddition.stjs", true);
	}

	@Test
	public void testRangeIntersectionSmall2() throws Exception {
		testJs("range_small/RangeIntersectionSmall2");
	}

	@Test
	public void testRangeUnionSmall() throws Exception {
		testJs("range_small/RangeUnionSmall", "RangeUnionSmall", "RangeUnionSmallAddition.stjs", true);
	}

	@Test
	public void testRangeUnionSmall2() throws Exception {
		testJs("range_small/RangeUnionSmall2");
	}

	@Test
	public void testLiftBenchmarks() throws Exception {
		testJs("liftbenchmarks/LiftExec", "LiftExec", "LiftExecAddition.stjs", true);
	}


	@Test
	public void testSieveBenchmarks() throws Exception {
		testJs("sievebenchmarks/Sieve", "Sieve", "SieveAddition.stjs", true);
	}

	@Test
	public void testTrafficLightBenchmarks() throws Exception {
		testJs("trafficlightbenchmarks/TrafficLightExec", "TrafficLightExec", "TrafficLightExecAddition.stjs", true);
	}

	@Test
	public void testIncreasingSet() throws Exception {
		testJs("setoperationbenchmarks/IncreasingSet");
	}

	@Test
	public void testSetOperation() throws Exception {
		testJs("setoperationbenchmarks/SetOperation", "SetOperation", "SetOperationAddition.stjs", true);
	}

}