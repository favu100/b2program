package de.hhu.stups.codegenerator.python;

import org.junit.Ignore;
import org.junit.Test;

public class TestBenchmarks extends TestPython {

	@Test
	public void testPlus() throws Exception {
		testPython("arithmetic/Plus", "Plus", "PlusAddition.stpy", true);
	}

	@Test
	public void testMinus2() throws Exception {
		testPython("arithmetic/Minus", "Minus", "MinusAddition.stpy", true);
	}

	@Test
	public void testMultiply2() throws Exception {
		testPython("arithmetic/Multiply", "Multiply", "MultiplyAddition.stpy", true);
	}

	@Test
	public void testDivide2() throws Exception {
		testPython("arithmetic/Divide", "Divide", "DivideAddition.stpy", true);
	}


	@Test
	public void testModulo2() throws Exception {
		testPython("arithmetic/Modulo", "Modulo", "ModuloAddition.stpy", true);
	}

	@Test
	public void testNegative() throws Exception {
		testPython("arithmetic/Negative", "Negative", "NegativeAddition.stpy", true);
	}

	@Ignore
	@Test
	public void testPositive() throws Exception {
		testPython("arithmetic/Positive");
	}

	/*@Test
	public void testSmallNumbers() throws Exception {
		testPython();("integers/SmallNumbers", "SmallNumbersAddition.stpy", true);
	}

	@Test
	public void testBigNumbers() throws Exception {
		testPython();("integers/BigNumbers", "BigNumbersAddition.stpy", true);
	}*/

	@Test
	public void testAnd2() throws Exception {
		testPython("logical/And", "And", "AndAddition.stpy", true);
	}


	@Test
	public void testOr2() throws Exception {
		testPython("logical/Or", "Or", "OrAddition.stpy", true);
	}


	@Test
	public void testImpliesPerformance() throws Exception {
		testPython("logical/Implies", "Implies", "ImpliesAddition.stpy", true);
	}

	@Test
	public void testNot2() throws Exception {
		testPython("logical/Not");
	}

	@Test
	public void testEquivalent2() throws Exception {
		testPython("logical/Equivalent", "Equivalent", "EquivalentAddition.stpy", true);
	}

	@Test
	public void testBooleanExpression() throws Exception {
		testPython("logical/BooleanExpression");
	}

	@Test
	public void testBooleanConstant() throws Exception {
		testPython("logical/BooleanConstant");
	}

	@Test
	public void testLess2() throws Exception {
		testPython("comparison/Less", "Less", "LessAddition.stpy", true);
	}

	@Test
	public void testLessEqual2() throws Exception {
		testPython("comparison/LessEqual", "LessEqual", "LessEqualAddition.stpy", true);
	}

	@Test
	public void testGreater2() throws Exception {
		testPython("comparison/Greater", "Greater", "GreaterAddition.stpy", true);
	}


	@Test
	public void testGreaterEqual2() throws Exception {
		testPython("comparison/GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stpy", true);
	}


	@Test
	public void tessEqual() throws Exception {
		testPython("comparison/Equal", "Equal", "EqualAddition.stpy", true);
	}


	@Test
	public void testUnequal2() throws Exception {
		testPython("comparison/Unequal", "Unequal", "UnequalAddition.stpy", true);
	}

	@Test
	public void testCardBig() throws Exception {
		testPython("setoperation_big/SetCardBig", "SetCardBig", "SetCardBigAddition.stpy", false);
	}

	@Test
	public void testCardBig2() throws Exception {
		testPython("setoperation_big/SetCardBig2");
	}


	@Test
	public void testDifferenceBig() throws Exception {
		testPython("setoperation_big/SetDifferenceBig", "SetDifferenceBig", "SetDifferenceBigAddition.stpy", true);
	}

	@Test
	public void testDifferenceBig2() throws Exception {
		testPython("setoperation_big/SetDifferenceBig2");
	}

	@Test
	public void testElementOfBig() throws Exception {
		testPython("setoperation_big/SetElementOfBig", "SetElementOfBig", "SetElementOfBigAddition.stpy", true);
	}

	@Test
	public void testElementOfBig2() throws Exception {
		testPython("setoperation_big/SetElementOfBig2");
	}

	@Test
	public void testIntersectionBig() throws Exception {
		testPython("setoperation_big/SetIntersectionBig", "SetIntersectionBig", "SetIntersectionBigAddition.stpy", true);
	}

	@Test
	public void testIntersectionBig2() throws Exception {
		testPython("setoperation_big/SetIntersectionBig2");
	}

	@Test
	public void testUnionBig() throws Exception {
		testPython("setoperation_big/SetUnionBig", "SetUnionBig", "SetUnionBigAddition.stpy", false);
	}

	@Test
	public void testUnionBig2() throws Exception {
		testPython("setoperation_big/SetUnionBig2");
	}


	@Test
	public void testCardSmall() throws Exception {
		testPython("setoperation_small/SetCardSmall", "SetCardSmall", "SetCardSmallAddition.stpy", true);
	}

	@Test
	public void testCardSmall2() throws Exception {
		testPython("setoperation_small/SetCardSmall2");
	}


	@Test
	public void testDifferenceSmall() throws Exception {
		testPython("setoperation_small/SetDifferenceSmall", "SetDifferenceSmall", "SetDifferenceSmallAddition.stpy", true);
	}

	@Test
	public void testDifferenceSmall2() throws Exception {
		testPython("setoperation_small/SetDifferenceSmall2");
	}


	@Test
	public void testElementOfSmall() throws Exception {
		testPython("setoperation_small/SetElementOfSmall", "SetElementOfSmall", "SetElementOfSmallAddition.stpy", true);
	}

	@Test
	public void testElementOfSmall2() throws Exception {
		testPython("setoperation_small/SetElementOfSmall2");
	}


	@Test
	public void testIntersectionSmall() throws Exception {
		testPython("setoperation_small/SetIntersectionSmall", "SetIntersectionSmall", "SetIntersectionSmallAddition.stpy", true);
	}

	@Test
	public void testIntersectionSmall2() throws Exception {
		testPython("setoperation_small/SetIntersectionSmall2");
	}

	@Test
	public void testUnionSmall() throws Exception {
		testPython("setoperation_small/SetUnionSmall", "SetUnionSmall", "SetUnionSmallAddition.stpy", true);
	}

	@Test
	public void testUnionSmall2() throws Exception {
		testPython("setoperation_small/SetUnionSmall2");
	}

	@Test
	public void testRangeBig() throws Exception {
		testPython("range_big/RangeBig", "RangeBig", "RangeBigAddition.stpy", true);
	}

	@Test
	public void testRangeCardBig() throws Exception {
		testPython("range_big/RangeCardBig", "RangeCardBig", "RangeCardBigAddition.stpy", false);
	}

	@Test
	public void testRangeCardBig2() throws Exception {
		testPython("range_big/RangeCardBig2");
	}


	@Test
	public void testRangeDifferenceBig() throws Exception {
		testPython("range_big/RangeDifferenceBig", "RangeDifferenceBig", "RangeDifferenceBigAddition.stpy", true);
	}

	@Test
	public void testRangeDifferenceBig2() throws Exception {
		testPython("range_big/RangeDifferenceBig2");
	}


	@Test
	public void testRangeElementOfBig() throws Exception {
		testPython("range_big/RangeElementOfBig", "RangeElementOfBig", "RangeElementOfBigAddition.stpy", true);
	}

	@Test
	public void testRangeElementOfBig2() throws Exception {
		testPython("range_big/RangeElementOfBig2");
	}


	@Test
	public void testRangeIntersectionBig() throws Exception {
		testPython("range_big/RangeIntersectionBig", "RangeIntersectionBig", "RangeIntersectionBigAddition.stpy", true);
	}

	@Test
	public void testRangeIntersectionBig2() throws Exception {
		testPython("range_big/RangeIntersectionBig2");
	}


	@Test
	public void testRangeUnionBig() throws Exception {
		testPython("range_big/RangeUnionBig", "RangeUnionBig", "RangeUnionBigAddition.stpy", false);
	}

	@Test
	public void testRangeUnionBig2() throws Exception {
		testPython("range_big/RangeUnionBig2");
	}


	@Test
	public void testRangeSmall() throws Exception {
		testPython("range_small/RangeSmall", "RangeSmall", "RangeSmallAddition.stpy", true);
	}


	@Test
	public void testRangeCardSmall() throws Exception {
		testPython("range_small/RangeCardSmall", "RangeCardSmall", "RangeCardSmallAddition.stpy", true);
	}

	@Test
	public void testRangeCardSmall2() throws Exception {
		testPython("range_small/RangeCardSmall2");
	}


	@Test
	public void testRangeDifferenceSmall() throws Exception {
		testPython("range_small/RangeDifferenceSmall", "RangeDifferenceSmall", "RangeDifferenceSmallAddition.stpy", true);
	}

	@Test
	public void testRangeDifferenceSmall2() throws Exception {
		testPython("range_small/RangeDifferenceSmall2");
	}

	@Test
	public void testRangeElementOfSmall() throws Exception {
		testPython("range_small/RangeElementOfSmall", "RangeElementOfSmall", "RangeElementOfSmallAddition.stpy", true);
	}

	@Test
	public void testRangeElementOfSmall2() throws Exception {
		testPython("range_small/RangeElementOfSmall2");
	}

	@Test
	public void testRangeIntersectionSmall() throws Exception {
		testPython("range_small/RangeIntersectionSmall", "RangeIntersectionSmall", "RangeIntersectionSmallAddition.stpy", true);
	}

	@Test
	public void testRangeIntersectionSmall2() throws Exception {
		testPython("range_small/RangeIntersectionSmall2");
	}

	@Test
	public void testRangeUnionSmall() throws Exception {
		testPython("range_small/RangeUnionSmall", "RangeUnionSmall", "RangeUnionSmallAddition.stpy", true);
	}

	@Test
	public void testRangeUnionSmall2() throws Exception {
		testPython("range_small/RangeUnionSmall2");
	}

	@Test
	public void testLiftBenchmarks() throws Exception {
		testPython("liftbenchmarks/LiftExec", "LiftExec", "LiftExecAddition.stpy", true);
	}


	@Test
	public void testSieveBenchmarks() throws Exception {
		testPython("sievebenchmarks/Sieve", "Sieve", "SieveAddition.stpy", true);
	}

	@Test
	public void testTrafficLightBenchmarks() throws Exception {
		testPython("trafficlightbenchmarks/TrafficLightExec", "TrafficLightExec", "TrafficLightExecAddition.stpy", true);
	}

	@Test
	public void testIncreasingSet() throws Exception {
		testPython("setoperationbenchmarks/IncreasingSet");
	}

	@Test
	public void testSetOperation() throws Exception {
		testPython("setoperationbenchmarks/SetOperation", "SetOperation", "SetOperationAddition.stpy", true);
	}

}