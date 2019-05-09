package de.hhu.stups.codegenerator;


import org.junit.Ignore;
import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

import static org.junit.Assert.assertEquals;

/**
 * Created by fabian on 30.08.18.
 */

public class TestCpp {

	public static void writeInputToOutput(InputStream inputStream, OutputStream outputStream) throws IOException {
		int size;
		byte[] buffer = new byte[1024];
		while ((size = inputStream.read(buffer)) != -1)
			outputStream.write(buffer, 0, size);
	}

	public static void writeInputToSystem(InputStream inputStream) throws IOException {
		writeInputToOutput(inputStream, System.err);
	}

	private static String streamToString(InputStream inputStream) throws IOException {
		ByteArrayOutputStream result = new ByteArrayOutputStream();
		byte[] buffer = new byte[1024];
		int length;
		while ((length = inputStream.read(buffer)) != -1) {
			result.write(buffer, 0, length);
		}
		return result.toString();
	}


	public void testCpp(String machine) throws Exception {
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> cppFilePaths = codeGenerator.generate(mchPath, GeneratorMode.CPP, false, true, null);


		cppFilePaths.forEach(path -> {
			try {
				Process process = Runtime.getRuntime()
						.exec("g++ -std=c++14 -O2 -march=native -g -DIMMER_NO_THREAD_SAFETY -c " + path.toFile().getAbsoluteFile().toString());
				writeInputToSystem(process.getErrorStream());
				writeInputToOutput(process.getErrorStream(), process.getOutputStream());
				process.waitFor();
			} catch (IOException | InterruptedException e) {
				e.printStackTrace();
			}
		});

		Set<File> oFiles = cppFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machine + ".o"))
				.collect(Collectors.toSet());

		//javaFilePaths.forEach(path -> cleanUp(path.toString()));
		//classFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));
		//cFilePaths.forEach(path -> cleanUp(path.toString()));
	}


	public void testCpp(String machine, String machineName, String addition, boolean execute) throws Exception {
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> cppFilePaths = codeGenerator.generate(mchPath, GeneratorMode.CPP, false, true, addition);

		Runtime runtime = Runtime.getRuntime();

		Path mainPath = cppFilePaths.get(cppFilePaths.size() - 1);

		Process compileProcess = runtime
				.exec("g++ -std=c++14 -O2 -march=native -g -DIMMER_NO_THREAD_SAFETY -o " + machineName + ".exec" + " build/resources/test/de/hhu/stups/codegenerator/" + machine + ".cpp");
		compileProcess.waitFor();

		String error = streamToString(compileProcess.getErrorStream());
		if(!error.isEmpty()) {
			throw new RuntimeException(error);
		}

		if(!execute) {
			return;
		}

		Process executeProcess = runtime.exec("./" + machineName + ".exec");
		executeProcess.waitFor();

		error = streamToString(executeProcess.getErrorStream());
		if(!error.isEmpty()) {
			throw new RuntimeException(error);
		}

		String result = streamToString(executeProcess.getInputStream()).replaceAll("\n", "");
		String expectedOutput = streamToString(new FileInputStream(mainPath.toFile().getAbsoluteFile().toString().replaceAll(".cpp", ".out"))).replaceAll("\n", "");

		System.out.println("Assert: " + result + " = " + expectedOutput);

		assertEquals(result, expectedOutput);

		Set<File> execFiles = cppFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machine + ".exec"))
				.collect(Collectors.toSet());

		//javaFilePaths.forEach(path -> cleanUp(path.toString()));
		//classFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));
		//cFilePaths.forEach(path -> cleanUp(path.toString()));
	}

	@Test
	public void testExample() throws Exception {
		testCpp("Example");
	}

	@Test
	public void testOperation() throws Exception {
		testCpp("Operation", "Operation", "OperationAddition.stCpp", true);
	}

	@Test
	public void testOperation2() throws Exception {
		testCpp("Operation2");
	}

	@Test
	public void testLocalDeclaration() throws Exception {
		testCpp("LocalDeclaration");
	}

	@Ignore
	@Test
	public void testRefinement() throws Exception {
		// TODO VAR-Node
		testCpp("RefinementMachine");
	}

	@Test
	public void testWhile() throws Exception {
		testCpp("While", "While", "WhileAddition.stCpp", true);
	}

	@Test
	public void testEquivalence() throws Exception {
		testCpp("Equivalence", "Equivalence", "EquivalenceAddition.stCpp", true);
	}

	@Test
	public void testBooleanPredicate() throws Exception {
		testCpp("BooleanPredicate", "BooleanPredicate", "BooleanPredicateAddition.stCpp", true);
	}

	@Ignore
	@Test
	public void testRecords() throws Exception {
		testCpp("Records");
	}

	@Test
	public void testNondeterminism() throws Exception {
		testCpp("Nondeterminism", "Nondeterminism", "NondeterminismAddition.stCpp", true);
	}

	@Test
	public void testMapFunction() throws Exception {
		testCpp("MapFunction", "MapFunction", "MapFunctionAddition.stCpp", true);
	}

	@Test
	public void testSetUnion() throws Exception {
		testCpp("SetUnion");
	}


	@Test
	public void testCounter() throws Exception {
		testCpp("Counter", "Counter", "CounterAddition.stCpp", true);
	}

	@Test
	public void testBakery0() throws Exception {
		testCpp("Bakery0", "Bakery0", "Bakery0Addition.stCpp", true);
	}

	@Test
	public void testGCD() throws Exception {
		testCpp("GCD");
	}

	@Test
	public void testACounter() throws Exception {
		testCpp("ACounter", "ACounter", "ACounterAddition.stCpp", true);
	}

	@Test
	public void testLift() throws Exception {
		testCpp("Lift", "Lift", "LiftAddition.stCpp", true);
	}

	@Test
	public void testTravelAgency() throws Exception {
		testCpp("TravelAgency");
	}

	@Test
	public void testTrafficLight() throws Exception {
		testCpp("TrafficLight", "TrafficLight", "TrafficLightAddition.stCpp", true);
	}

	@Ignore
	@Test
	public void testPhonebook() throws Exception {
		// TODO
		testCpp("phonebook");
	}

	@Ignore
	@Test
	public void testPhonebook6() throws Exception {
		// TODO
		testCpp("phonebook6");
	}

	@Test
	public void testProject() throws Exception {
		//This might be a bug in the parser in the scoping part
		testCpp("project1/A", "A", "AAddition.stCpp", true);
	}

	@Test
	public void testProject3() throws Exception {
		testCpp("project3/A");
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

	@Test
	public void testProject2() throws Exception {
		testCpp("project2/MachineA", "MachineA", "MachineAAddition.stCpp", true);
	}

	@Test
	public void testSieve() throws Exception {
		testCpp("Sieve", "Sieve", "SieveAddition.stCpp", true);
	}

	@Test
	public void testSieveParallel() throws Exception {
		testCpp("SieveParallel", "SieveParallel", "SieveParallelAddition.stCpp", true);
	}

	@Test
	public void testReset() throws Exception {
		testCpp("Reset");
	}

	@Test
	public void testManyLocalDeclarations() throws Exception {
		testCpp("ManyLocalDeclarations", "ManyLocalDeclarations", "ManyLocalDeclarationsAddition.stCpp", true);
	}

	@Test
	public void testManyLocalDeclarations2() throws Exception {
		testCpp("ManyLocalDeclarations2", "ManyLocalDeclarations2", "ManyLocalDeclarations2Addition.stCpp", true);
	}

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
	public void testAssert() throws Exception {
		testCpp("Assert");
	}

	@Test
	public void testCruiseController1() throws Exception {
		testCpp("Cruise_finite1");
	}

	@Test
	public void testCruiseControllerk() throws Exception {
		testCpp("Cruise_finite_k");
	}

	@Test
	public void testCruiseControllerDeterministic() throws Exception {
		testCpp("Cruise_finite1_deterministic");
	}

	@Test
	public void testCruiseControllerDeterministicExec() throws Exception {
		testCpp("Cruise_finite1_deterministic_exec");
	}

	@Test
	public void testScheduler() throws Exception {
		testCpp("scheduler");
	}

	@Test
	public void testSchedulerDeterministic() throws Exception {
		testCpp("scheduler_deterministic");
	}

	@Test
	public void testSchedulerDeterministicExec() throws Exception {
		testCpp("scheduler_deterministic_exec");
	}

	@Test
	public void testCanBusTLC() throws Exception {
		testCpp("CAN_BUS_tlc");
	}

	@Test
	public void testCanBusTLCExec() throws Exception {
		testCpp("CAN_BUS_tlc_exec");
	}

	@Ignore
	@Test
	public void testCore() throws Exception {
		testCpp("Core");
	}

	@Ignore
	@Test
	public void testSetLawsNAT() throws Exception {
		testCpp("SetLawsNAT");
	}

	@Test
	public void SimpsonFourSlot() throws Exception {
		testCpp("Simpson_Four_Slot");
	}

	@Test
	public void Train1BeebookTLC() throws Exception {
		testCpp("Train_1_beebook_TLC");
	}

	@Test
	public void Train1BeebookDeterministic() throws Exception {
		testCpp("Train_1_beebook_deterministic");
	}

	@Test
	public void Train1BeebookDeterministicExec() throws Exception {
		testCpp("Train_1_beebook_deterministic_exec");
	}

	@Test
	public void Train1() throws Exception {
		testCpp("train_1");
	}

	@Ignore
	@Test
	public void testEarley2() throws Exception {
		testCpp("earley_2");
	}

	@Ignore
	@Test
	public void testOBSW_M001() throws Exception {
		testCpp("obsw_M001");
	}

	@Ignore
	@Test
	public void testRef5Switch() throws Exception {
		testCpp("Ref5_Switch");
	}

	@Ignore
	@Test
	public void testrether_mch1() throws Exception {
		testCpp("rether_mch1");
	}


	@Test
	public void testAnd() throws Exception {
		testCpp("And", "And", "AndAddition.stcpp", true);
	}

	@Test
	public void testCard() throws Exception {
		testCpp("Card", "Card", "CardAddition.stcpp", true);
	}

	@Test
	public void testChoice() throws Exception {
		testCpp("Choice", "Choice", "ChoiceAddition.stcpp", true);
	}

	@Test
	public void testDanglingElse() throws Exception {
		testCpp("DanglingElse", "DanglingElse", "DanglingElseAddition.stcpp", true);
	}

	@Test
	public void testDifference() throws Exception {
		testCpp("Difference", "Difference", "DifferenceAddition.stcpp", true);
	}

	@Test
	public void testDivide() throws Exception {
		testCpp("Divide", "Divide", "DivideAddition.stcpp", true);
	}

	@Test
	public void testDomain() throws Exception {
		testCpp("Domain", "Domain", "DomainAddition.stcpp", true);
	}

	@Test
	public void testDomainRestriction() throws Exception {
		testCpp("DomainRestriction", "DomainRestriction", "DomainRestrictionAddition.stcpp", true);
	}

	@Test
	public void testDomainSubstraction() throws Exception {
		testCpp("DomainSubstraction", "DomainSubstraction", "DomainSubstractionAddition.stcpp", true);
	}

	@Test
	public void testElementOf() throws Exception {
		testCpp("ElementOf", "ElementOf", "ElementOfAddition.stcpp", true);
	}

	@Test
	public void testEmptySet() throws Exception {
		testCpp("EmptySet", "EmptySet", "EmptySetAddition.stcpp", true);
	}

	@Test
	public void testEqual() throws Exception {
		testCpp("Equal", "Equal", "EqualAddition.stcpp", true);
	}

	@Test
	public void testEquivalent() throws Exception {
		testCpp("Equivalent", "Equivalent", "EquivalentAddition.stcpp", true);
	}

	@Test
	public void testGreater() throws Exception {
		testCpp("Greater", "Greater", "GreaterAddition.stcpp", true);
	}

	@Test
	public void testGreaterEqual() throws Exception {
		testCpp("GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stcpp", true);
	}

	@Test
	public void testIfAndPredicates() throws Exception {
		testCpp("IfAndPredicates");
	}

	@Test
	public void testImplies() throws Exception {
		testCpp("Implies", "Implies", "ImpliesAddition.stcpp", true);
	}

	@Test
	public void testIntersection() throws Exception {
		testCpp("Intersection", "Intersection", "IntersectionAddition.stcpp", true);
	}

	@Test
	public void testInterval() throws Exception {
		testCpp("Interval", "Interval", "IntervalAddition.stcpp", true);
	}

	@Test
	public void testInverse() throws Exception {
		testCpp("Inverse", "Inverse", "InverseAddition.stcpp", true);
	}

	@Test
	public void testLess() throws Exception {
		testCpp("Less", "Less", "LessAddition.stcpp", true);
	}

	@Test
	public void testLessEqual() throws Exception {
		testCpp("LessEqual", "LessEqual", "LessEqualAddition.stcpp", true);
	}

	@Test
	public void testMax() throws Exception {
		testCpp("Max", "MAx", "MaxAddition.stcpp", true);
	}

	@Test
	public void testMin() throws Exception {
		testCpp("Min", "Min", "MinAddition.stcpp", true);
	}

	@Test
	public void testMinus() throws Exception {
		testCpp("Minus", "Minus", "MinusAddition.stcpp", true);
	}

	@Test
	public void testModulo() throws Exception {
		testCpp("Modulo", "Modulo", "ModuloAddition.stcpp", true);
	}

	@Test
	public void testMultiply() throws Exception {
		testCpp("Multiply", "Multiply", "MultiplyAddition.stcpp", true);
	}

	@Test
	public void testNameCollision() throws Exception {
		testCpp("NameCollision", "NameCollision", "NameCollisionAddition.stcpp", true);
	}

	@Test
	public void testNot() throws Exception {
		testCpp("Not", "Not", "NotAddition.stcpp", true);
	}

	@Test
	public void testNotElementOf() throws Exception {
		testCpp("NotElementOf", "NotElementOf", "NotElementOfAddition.stcpp", true);
	}

	@Test
	public void testNotStrictSubset() throws Exception {
		testCpp("NotStrictSubset", "NotStrictSubset", "NotStrictSubsetAddition.stcpp", true);
	}

	@Test
	public void testNotSubset() throws Exception {
		testCpp("NotSubset", "NotSubset", "NotSubsetAddition.stcpp", true);
	}

	@Test
	public void testOr() throws Exception {
		testCpp("Or", "Or", "OrAddition.stcpp", true);
	}

	@Test
	public void testPlus2() throws Exception {
		testCpp("Plus", "Plus", "PlusAddition.stcpp", true);
	}

	@Test
	public void testRange() throws Exception {
		testCpp("Range", "Range", "RangeAddition.stcpp", true);
	}

	@Test
	public void testRangeRestriction() throws Exception {
		testCpp("RangeRestriction", "RangeRestriction", "RangeRestrictionAddition.stcpp", true);
	}

	@Test
	public void testRangeSubstraction() throws Exception {
		testCpp("RangeSubstraction", "RangeSubstraction", "RangeSubstractionAddition.stcpp", true);
	}

	@Test
	public void testRelationalImage() throws Exception {
		testCpp("RelationalImage", "RelationalImage", "RelationalImageAddition.stcpp", true);
	}

	@Test
	public void testStrictSubset() throws Exception {
		testCpp("StrictSubset", "StrictSubset", "StrictSubsetAddition.stcpp", true);
	}

	@Test
	public void testSubset() throws Exception {
		testCpp("Subset", "Subset", "SubsetAddition.stcpp", true);
	}

	@Test
	public void testSwap() throws Exception {
		testCpp("Swap", "Swap", "SwapAddition.stcpp", true);
	}


	@Test
	public void testSwap2() throws Exception {
		testCpp("Swap2", "Swap2", "Swap2Addition.stcpp", true);
	}

	@Test
	public void testUnaryMinus() throws Exception {
		testCpp("UnaryMinus", "UnaryMinus", "UnaryMinusAddition.stcpp", true);
	}

	@Test
	public void testUnequal() throws Exception {
		testCpp("Unequal", "Unequal", "UnequalAddition.stcpp", true);
	}

	@Test
	public void testUnion() throws Exception {
		testCpp("Union", "Union", "UnionAddition.stcpp", true);
	}

	@Test
	public void testSetComprehension1() throws Exception {
		testCpp("SetComprehension1", "SetComprehension1", "SetComprehension1Addition.stcpp", true);
	}

	@Test
	public void testSetComprehension2() throws Exception {
		testCpp("SetComprehension2", "SetComprehension2", "SetComprehension2Addition.stcpp", true);
	}

	@Test
	public void testSetComprehension3() throws Exception {
		testCpp("SetComprehension3", "SetComprehension3", "SetComprehension3Addition.stcpp", true);
	}

	@Test
	public void testSetComprehension4() throws Exception {
		testCpp("SetComprehension4", "SetComprehension4", "SetComprehension4Addition.stcpp", true);
	}

	@Test
	public void testSetComprehension5() throws Exception {
		testCpp("SetComprehension5", "SetComprehension5", "SetComprehension5Addition.stcpp", true);
	}

	@Test
	public void testLambda() throws Exception {
		testCpp("Lambda", "Lambda", "LambdaAddition.stcpp", true);
	}

	@Test
	public void testLambda2() throws Exception {
		testCpp("Lambda2", "Lambda2", "Lambda2Addition.stcpp", true);
	}

	@Test
	public void testQuantifiedPredicate() throws Exception {
		testCpp("QuantifiedPredicate", "QuantifiedPredicate", "QuantifiedPredicateAddition.stcpp", true);
	}

	@Test
	public void testQuantifiedPredicate2() throws Exception {
		testCpp("QuantifiedPredicate2", "QuantifiedPredicate2", "QuantifiedPredicate2Addition.stcpp", true);
	}

	@Test
	public void testQuantifiedPredicate3() throws Exception {
		testCpp("QuantifiedPredicate3", "QuantifiedPredicate3", "QuantifiedPredicate3Addition.stcpp", true);
	}

	@Test
	public void testQuantifiedExpression1() throws Exception {
		testCpp("QuantifiedExpression1", "QuantifiedExpression1", "QuantifiedExpression1Addition.stcpp", true);
	}

	@Test
	public void testQuantifiedExpression2() throws Exception {
		testCpp("QuantifiedExpression2", "QuantifiedExpression2", "QuantifiedExpression2Addition.stcpp", true);
	}

	@Test
	public void testQuantifiedExpression3() throws Exception {
		testCpp("QuantifiedExpression3", "QuantifiedExpression3", "QuantifiedExpression3Addition.stcpp", true);
	}

	@Test
	public void testQuantifiedExpression4() throws Exception {
		testCpp("QuantifiedExpression4", "QuantifiedExpression4", "QuantifiedExpression4Addition.stcpp", true);
	}

	@Test
	public void testQuantifiedExpression5() throws Exception {
		testCpp("QuantifiedExpression5", "QuantifiedExpression5", "QuantifiedExpression5Addition.stcpp", true);
	}


	@Test
	public void testLetExpression() throws Exception {
		testCpp("LetExpression", "LetExpression", "LetExpressionAddition.stcpp", true);
	}


	@Test
	public void testLetPredicate() throws Exception {
		testCpp("LetPredicate", "LetPredicate", "LetPredicateAddition.stcpp", true);
	}

	@Test
	public void testLetSubstitution() throws Exception {
		testCpp("LetSubstitution", "LetSubstitution", "LetSubstitutionAddition.stcpp", true);
	}

	@Test
	public void testChoiceByPredicate() throws Exception {
		testCpp("ChoiceByPredicate");
	}

	@Test
	public void testIfExpression() throws Exception {
		testCpp("IfExpression", "IfExpression", "IfExpressionAddition.stcpp", true);
	}

	@Test
	public void testIfPredicate() throws Exception {
		testCpp("IfPredicate", "IfPredicate", "IfPredicateAddition.stcpp", true);
	}


	@Test
	public void testGeneralizedUnion() throws Exception {
		testCpp("GeneralizedUnion");
	}

	@Test
	public void testGeneralizedIntersection() throws Exception {
		testCpp("GeneralizedIntersection");
	}


	@Test
	public void testFunctionalOverride() throws Exception {
		testCpp("FunctionalOverride", "FunctionalOverride", "FunctionalOverrideAddition.stcpp", true);
	}

	@Test
	public void testFunctionalOverride2() throws Exception {
		testCpp("FunctionalOverride2", "FunctionalOverride2", "FunctionalOverride2Addition.stcpp", true);
	}

	@Test
	public void testFunctionalOverride3() throws Exception {
		testCpp("FunctionalOverride3", "FunctionalOverride3", "FunctionalOverride3Addition.stcpp", true);
	}

	@Test
	public void testOverride() throws Exception {
		testCpp("Override", "Override", "OverrideAddition.stcpp", true);
	}

	@Test
	public void testPow() throws Exception {
		testCpp("Pow", "Pow", "PowAddition.stcpp", true);
	}

	@Test
	public void testRelationPow() throws Exception {
		testCpp("RelationPow", "RelationPow", "RelationPowAddition.stcpp", true);
	}

	@Test
	public void testRelationPow1() throws Exception {
		testCpp("RelationPow1", "RelationPow1", "RelationPow1Addition.stcpp", true);
	}

	@Test
	public void testPow1() throws Exception {
		testCpp("Pow1", "Pow1", "Pow1Addition.stcpp", true);
	}

	@Test
	public void testFin() throws Exception {
		testCpp("Fin", "Fin", "FinAddition.stcpp", true);
	}

	@Test
	public void testFin1() throws Exception {
		testCpp("Fin1", "Fin1", "Fin1Addition.stcpp", true);
	}

	@Test
	public void testId() throws Exception {
		testCpp("Id", "Id", "IdAddition.stcpp", true);
	}

	@Test
	public void testParallelProduct() throws Exception {
		testCpp("ParallelProduct", "ParallelProduct", "ParallelProductAddition.stcpp", true);
	}

	@Test
	public void testDirectProduct() throws Exception {
		testCpp("DirectProduct", "DirectProduct", "DirectProductAddition.stcpp", true);
	}

	@Test
	public void testComposition() throws Exception {
		testCpp("Composition", "Composition", "CompositionAddition.stcpp", true);
	}

	@Test
	public void testProjection1() throws Exception {
		testCpp("Projection1", "Projection1", "Projection1Addition.stcpp", true);
	}

	@Test
	public void testProjection2() throws Exception {
		testCpp("Projection2", "Projection2", "Projection2Addition.stcpp", true);
	}

	@Test
	public void testAppend() throws Exception {
		testCpp("Append", "Append", "AppendAddition.stcpp", true);
	}


	@Test
	public void testConc() throws Exception {
		testCpp("Conc", "Conc", "ConcAddition.stcpp", true);
	}

	@Test
	public void testConcat() throws Exception {
		testCpp("Concat", "Concat", "ConcatAddition.stcpp", true);
	}

	@Test
	public void testDrop() throws Exception {
		testCpp("Drop", "Drop", "DropAddition.stcpp", true);
	}

	@Test
	public void testEmptySequence() throws Exception {
		testCpp("EmptySequence", "EmptySequence", "EmptySequenceAddition.stcpp", true);
	}

	@Test
	public void testEnumeratedSequence() throws Exception {
		testCpp("EnumeratedSequence");
	}

	@Test
	public void testFirstElementSequence() throws Exception {
		testCpp("FirstElementSequence", "FirstElementSequence", "FirstElementSequenceAddition.stcpp", true);
	}

	@Test
	public void testFrontSequence() throws Exception {
		testCpp("FrontSequence", "FrontSequence", "FrontSequenceAddition.stcpp", true);
	}

	@Test
	public void testLastElementSequence() throws Exception {
		testCpp("LastElementSequence", "LastElementSequence", "LastElementSequenceAddition.stcpp", true);
	}

	@Test
	public void testPrepend() throws Exception {
		testCpp("Prepend", "Prepend", "PrependAddition.stcpp", true);
	}

	@Test
	public void testReverse() throws Exception {
		testCpp("ReverseSequence", "ReverseSequence", "ReverseSequenceAddition.stcpp", true);
	}

	@Test
	public void testSizeOfSequence() throws Exception {
		testCpp("SizeOfSequence");
	}

	@Test
	public void testTailSequence() throws Exception {
		testCpp("TailSequence", "TailSequence", "TailSequenceAddition.stcpp", true);
	}

	@Test
	public void testTake() throws Exception {
		testCpp("Take", "Take", "TakeAddition.stcpp", true);
	}

	@Test
	public void testSequenceOperateRelation() throws Exception {
		testCpp("SequenceOperateRelation", "SequenceOperateRelation", "SequenceOperateRelationAddition.stcpp", true);
	}

	@Test
	public void testPred() throws Exception {
		testCpp("Pred", "Pred", "PredAddition.stcpp", true);
	}

	@Test
	public void testSucc() throws Exception {
		testCpp("Succ", "Succ", "SuccAddition.stcpp", true);
	}

	@Test
	public void testIterate() throws Exception {
		testCpp("Iterate", "Iterate", "IterateAddition.stcpp", true);
	}

	@Test
	public void testClosure() throws Exception {
		testCpp("Closure", "Closure", "ClosureAddition.stcpp", true);
	}

	@Test
	public void testClosure1() throws Exception {
		testCpp("Closure1", "Closure1", "Closure1Addition.stcpp", true);
	}

	@Test
	public void testFnc() throws Exception {
		testCpp("Fnc", "Fnc", "FncAddition.stcpp", true);
	}

	@Test
	public void testRel() throws Exception {
		testCpp("Rel", "Rel", "RelAddition.stcpp", true);
	}

	private void cleanUp(String path) {
		File file = new File(path);
		if (file.exists()) {
			file.delete();
		}
	}

}
