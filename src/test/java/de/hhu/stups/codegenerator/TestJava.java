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
 * Created by fabian on 31.05.18.
 */

public class TestJava {

	public static void writeInputToSystem(InputStream inputStream) throws IOException {
		writeInputToOutput(inputStream, System.out);
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

	public static void writeInputToOutput(InputStream inputStream, OutputStream outputStream) throws IOException {
		int size;
		byte[] buffer = new byte[1024];
		while ((size = inputStream.read(buffer)) != -1)
			outputStream.write(buffer, 0, size);
	}

	public void testJava(String machine) throws Exception {
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> javaFilePaths = codeGenerator.generate(mchPath, GeneratorMode.JAVA, false,true, null);
		Process process = Runtime.getRuntime()
				.exec("javac -classpath btypes_persistent.jar " + String.join(" ", javaFilePaths.stream()
						.map(path -> path.toFile().getAbsoluteFile().toString())
						.collect(Collectors.toSet())));

		writeInputToSystem(process.getErrorStream());
		writeInputToOutput(process.getErrorStream(), process.getOutputStream());
		process.waitFor();

		Set<File> classFiles = javaFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machine + ".class"))
				.collect(Collectors.toSet());

		//javaFilePaths.forEach(path -> cleanUp(path.toString()));
		//classFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));
	}

	public void testJava(String machinePath, String machineName, String addition, boolean execute) throws Exception {
		testJava(machinePath);
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machinePath + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> javaFilePaths = codeGenerator.generate(mchPath, GeneratorMode.JAVA, false,true, addition);
		Runtime runtime = Runtime.getRuntime();
		Process compileProcess = runtime.exec("javac -cp btypes_persistent.jar " +
				String.join(" ", javaFilePaths.stream()
						.map(path -> path.toFile().getAbsoluteFile().toString())
						.collect(Collectors.toSet())));
		compileProcess.waitFor();

		String error = streamToString(compileProcess.getErrorStream());
		if(!error.isEmpty()) {
			throw new RuntimeException(error);
		}
		Path mainPath = javaFilePaths.get(javaFilePaths.size() - 1);

		if(!execute) {
			return;
		}

		Process executeProcess = runtime.exec("java -cp btypes_persistent.jar:build/resources/test/de/hhu/stups/codegenerator/" + machinePath.substring(0, machinePath.length() - machineName.length()) + " " + machineName);
		executeProcess.waitFor();

		error = streamToString(executeProcess.getErrorStream());
		if(!error.isEmpty()) {
			throw new RuntimeException(error);
		}

		String result = streamToString(executeProcess.getInputStream()).replaceAll("\n", "");
		String expectedOutput = streamToString(new FileInputStream(mainPath.toFile().getAbsoluteFile().toString().replaceAll(".java", ".out"))).replaceAll("\n", "");

		System.out.println("Assert: " + result + " = " + expectedOutput);

		assertEquals(result, expectedOutput);

		/*Set<File> classFiles = javaFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machinePath + ".class"))
				.collect(Collectors.toSet());

		javaFilePaths.forEach(path -> cleanUp(path.toString()));
		classFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));*/
	}

	@Test
	public void testExample() throws Exception {
		testJava("Example");
	}

	@Test
	public void testOperation() throws Exception {
		testJava("Operation", "Operation", "OperationAddition.stjava", true);
	}

	@Test
	public void testOperation2() throws Exception {
		testJava("Operation2");
	}

	@Test
	public void testLocalDeclaration() throws Exception {
		testJava("LocalDeclaration");
	}

	@Ignore
	@Test
	public void testRefinement() throws Exception {
		// TODO VAR-Node
		testJava("RefinementMachine");
	}

	@Test
	public void testWhile() throws Exception {
		testJava("While", "While", "WhileAddition.stjava", true);
	}

	@Test
	public void testEquivalence() throws Exception {
		testJava("Equivalence", "Equivalence", "EquivalenceAddition.stjava", true);
	}

	@Test
	public void testBooleanPredicate() throws Exception {
		testJava("BooleanPredicate", "BooleanPredicate", "BooleanPredicateAddition.stjava", true);
	}

	@Ignore
	@Test
	public void testRecords() throws Exception {
		testJava("Records");
	}

	@Test
	public void testNondeterminism() throws Exception {
		testJava("Nondeterminism", "Nondeterminism", "NondeterminismAddition.stjava", true);
	}

	@Test
	public void testMapFunction() throws Exception {
		testJava("MapFunction", "MapFunction", "MapFunctionAddition.stjava", true);
	}

	@Test
	public void testSetUnion() throws Exception {
		testJava("SetUnion");
	}


	@Test
	public void testCounter() throws Exception {
		testJava("Counter", "Counter", "CounterAddition.stjava", true);
	}

	@Test
	public void testBakery0() throws Exception {
		testJava("Bakery0", "Bakery0", "Bakery0Addition.stjava", true);
	}

	@Test
	public void testGCD() throws Exception {
		testJava("GCD");
	}

	@Test
	public void testACounter() throws Exception {
		testJava("ACounter", "ACounter", "ACounterAddition.stjava", true);
	}

	@Test
	public void testLift() throws Exception {
		testJava("Lift", "Lift", "LiftAddition.stjava", true);
	}

	@Test
	public void testTravelAgency() throws Exception {
		testJava("TravelAgency");
	}

	@Test
	public void testTrafficLight() throws Exception {
		testJava("TrafficLight", "TrafficLight", "TrafficLightAddition.stjava", true);
	}

	@Ignore
	@Test
	public void testPhonebook() throws Exception {
		// TODO
		testJava("phonebook");
	}

	@Ignore
	@Test
	public void testPhonebook6() throws Exception {
		// TODO
		testJava("phonebook6");
	}

	@Test
	public void testProject() throws Exception {
		//This might be a bug in the parser in the scoping part
		testJava("project1/A", "A", "AAddition.stjava", true);
	}

	@Test
	public void testProject3() throws Exception {
		testJava("project3/A");
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

	@Test
	public void testProject2() throws Exception {
		testJava("project2/MachineA", "MachineA", "MachineAAddition.stjava", true);
	}

	@Test
	public void testSieve() throws Exception {
		testJava("Sieve", "Sieve", "SieveAddition.stjava", true);
	}

	@Test
	public void testSieveParallel() throws Exception {
		testJava("SieveParallel", "SieveParallel", "SieveParallelAddition.stjava", true);
	}

	@Test
	public void testReset() throws Exception {
		testJava("Reset");
	}

	@Test
	public void testManyLocalDeclarations() throws Exception {
		testJava("ManyLocalDeclarations", "ManyLocalDeclarations", "ManyLocalDeclarationsAddition.stjava", true);
	}

	@Test
	public void testManyLocalDeclarations2() throws Exception {
		testJava("ManyLocalDeclarations2", "ManyLocalDeclarations2", "ManyLocalDeclarations2Addition.stjava", true);
	}

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
	public void testAndPerformance() throws Exception {
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
	public void testAssert() throws Exception {
		testJava("Assert");
	}

	@Test
	public void testCruiseController1() throws Exception {
		testJava("Cruise_finite1");
	}

	@Test
	public void testCruiseControllerk() throws Exception {
		testJava("Cruise_finite_k");
	}

	@Test
	public void testCruiseControllerDeterministic() throws Exception {
		testJava("Cruise_finite1_deterministic");
	}

	@Test
	public void testCruiseControllerDeterministicExec() throws Exception {
		testJava("Cruise_finite1_deterministic_exec");
	}

	@Test
	public void testScheduler() throws Exception {
		testJava("scheduler");
	}

	@Test
	public void testSchedulerDeterministic() throws Exception {
		testJava("scheduler_deterministic");
	}

	@Test
	public void testSchedulerDeterministicExec() throws Exception {
		testJava("scheduler_deterministic_exec");
	}

	@Test
	public void testCanBusTLC() throws Exception {
		testJava("CAN_BUS_tlc");
	}

	@Test
	public void testCanBusTLCExec() throws Exception {
		testJava("CAN_BUS_tlc_exec");
	}

	@Ignore
	@Test
	public void testCore() throws Exception {
		testJava("Core");
	}

	@Ignore
	@Test
	public void testSetLawsNAT() throws Exception {
		testJava("SetLawsNAT");
	}

	@Test
	public void SimpsonFourSlot() throws Exception {
		testJava("Simpson_Four_Slot");
	}

	@Test
	public void Train1BeebookTLC() throws Exception {
		testJava("Train_1_beebook_TLC");
	}

	@Test
	public void Train1BeebookDeterministic() throws Exception {
		testJava("Train_1_beebook_deterministic");
	}


	@Test
	public void Train1BeebookDeterministicExec() throws Exception {
		testJava("Train_1_beebook_deterministic_exec");
	}

	@Test
	public void Train1() throws Exception {
		testJava("train_1");
	}

	@Ignore
	@Test
	public void testEarley2() throws Exception {
		testJava("earley_2");
	}

	@Ignore
	@Test
	public void testOBSW_M001() throws Exception {
		testJava("obsw_M001");
	}

	@Ignore
	@Test
	public void testRef5Switch() throws Exception {
		testJava("Ref5_Switch");
	}

	@Ignore
	@Test
	public void testrether_mch1() throws Exception {
		testJava("rether_mch1");
	}

	@Test
	public void testAnd() throws Exception {
		testJava("And", "And", "AndAddition.stjava", true);
	}

	@Test
	public void testCard() throws Exception {
		testJava("Card", "Card", "CardAddition.stjava", true);
	}

	@Test
	public void testChoice() throws Exception {
		testJava("Choice", "Choice", "ChoiceAddition.stjava", true);
	}

	@Test
	public void testDanglingElse() throws Exception {
		testJava("DanglingElse", "DanglingElse", "DanglingElseAddition.stjava", true);
	}

	@Test
	public void testDifference() throws Exception {
		testJava("Difference", "Difference", "DifferenceAddition.stjava", true);
	}

	@Test
	public void testDivide() throws Exception {
		testJava("Divide", "Divide", "DivideAddition.stjava", true);
	}

	@Test
	public void testDomain() throws Exception {
		testJava("Domain", "Domain", "DomainAddition.stjava", true);
	}

	@Test
	public void testDomainRestriction() throws Exception {
		testJava("DomainRestriction", "DomainRestriction", "DomainRestrictionAddition.stjava", true);
	}

	@Test
	public void testDomainSubstraction() throws Exception {
		testJava("DomainSubstraction", "DomainSubstraction", "DomainSubstractionAddition.stjava", true);
	}

	@Test
	public void testElementOf() throws Exception {
		testJava("ElementOf", "ElementOf", "ElementOfAddition.stjava", true);
	}

	@Test
	public void testEmptySet() throws Exception {
		testJava("EmptySet", "EmptySet", "EmptySetAddition.stjava", true);
	}

	@Test
	public void testEqual() throws Exception {
		testJava("Equal", "Equal", "EqualAddition.stjava", true);
	}

	@Test
	public void testEquivalent() throws Exception {
		testJava("Equivalent", "Equivalent", "EquivalentAddition.stjava", true);
	}

	@Test
	public void testGreater() throws Exception {
		testJava("Greater", "Greater", "GreaterAddition.stjava", true);
	}

	@Test
	public void testGreaterEqual() throws Exception {
		testJava("GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stjava", true);
	}

	@Test
	public void testIfAndPredicates() throws Exception {
		testJava("IfAndPredicates");
	}

	@Test
	public void testImplies() throws Exception {
		testJava("Implies", "Implies", "ImpliesAddition.stjava", true);
	}

	@Test
	public void testIntersection() throws Exception {
		testJava("Intersection", "Intersection", "IntersectionAddition.stjava", true);
	}

	@Test
	public void testInterval() throws Exception {
		testJava("Interval", "Interval", "IntervalAddition.stjava", true);
	}

	@Test
	public void testInverse() throws Exception {
		testJava("Inverse", "Inverse", "InverseAddition.stjava", true);
	}

	@Test
	public void testLess() throws Exception {
		testJava("Less", "Less", "LessAddition.stjava", true);
	}

	@Test
	public void testLessEqual() throws Exception {
		testJava("LessEqual", "LessEqual", "LessEqualAddition.stjava", true);
	}

	@Test
	public void testMax() throws Exception {
		testJava("Max", "Max", "MaxAddition.stjava", true);
	}

	@Test
	public void testMin() throws Exception {
		testJava("Min", "Min", "MinAddition.stjava", true);
	}

	@Test
	public void testMinus() throws Exception {
		testJava("Minus", "Minus", "MinusAddition.stjava", true);
	}

	@Test
	public void testModulo() throws Exception {
		testJava("Modulo", "Modulo", "ModuloAddition.stjava", true);
	}

	@Test
	public void testMultiply() throws Exception {
		testJava("Multiply", "Multiply", "MultiplyAddition.stjava", true);
	}

	@Test
	public void testNameCollision() throws Exception {
		testJava("NameCollision", "NameCollision", "NameCollisionAddition.stjava", true);
	}

	@Test
	public void testNot() throws Exception {
		testJava("Not", "Not", "NotAddition.stjava", true);
	}

	@Test
	public void testNotElementOf() throws Exception {
		testJava("NotElementOf", "NotElementOf", "NotElementOfAddition.stjava", true);
	}

	@Test
	public void testNotStrictSubset() throws Exception {
		testJava("NotStrictSubset", "NotStrictSubset", "NotStrictSubsetAddition.stjava", true);
	}

	@Test
	public void testNotSubset() throws Exception {
		testJava("NotSubset", "NotSubset", "NotSubsetAddition.stjava", true);
	}

	@Test
	public void testOr() throws Exception {
		testJava("Or", "Or", "OrAddition.stjava", true);
	}

	@Test
	public void testPlus2() throws Exception {
		testJava("Plus", "Plus", "PlusAddition.stjava", true);
	}

	@Test
	public void testRange() throws Exception {
		testJava("Range", "Range", "RangeAddition.stjava", true);
	}

	@Test
	public void testRangeRestriction() throws Exception {
		testJava("RangeRestriction", "RangeRestriction", "RangeRestrictionAddition.stjava", true);
	}

	@Test
	public void testRangeSubstraction() throws Exception {
		testJava("RangeSubstraction", "RangeSubstraction", "RangeSubstractionAddition.stjava", true);
	}

	@Test
	public void testRelationalImage() throws Exception {
		testJava("RelationalImage", "RelationalImage", "RelationalImageAddition.stjava", true);
	}

	@Test
	public void testStrictSubset() throws Exception {
		testJava("StrictSubset", "StrictSubset", "StrictSubsetAddition.stjava", true);
	}

	@Test
	public void testSubset() throws Exception {
		testJava("Subset", "Subset", "SubsetAddition.stjava", true);
	}

	@Test
	public void testSwap() throws Exception {
		testJava("Swap", "Swap", "SwapAddition.stjava", true);
	}


	@Test
	public void testSwap2() throws Exception {
		testJava("Swap2", "Swap2", "Swap2Addition.stjava", true);
	}

	@Test
	public void testUnaryMinus() throws Exception {
		testJava("UnaryMinus", "UnaryMinus", "UnaryMinusAddition.stjava", true);
	}

	@Test
	public void testUnequal() throws Exception {
		testJava("Unequal", "Unequal", "UnequalAddition.stjava", true);
	}

	@Test
	public void testUnion() throws Exception {
		testJava("Union", "Union", "UnionAddition.stjava", true);
	}

	@Test
	public void testSetComprehension1() throws Exception {
		testJava("SetComprehension1", "SetComprehension1", "SetComprehension1Addition.stjava", true);
	}

	@Test
	public void testSetComprehension2() throws Exception {
		testJava("SetComprehension2", "SetComprehension2", "SetComprehension2Addition.stjava", true);
	}

	@Test
	public void testSetComprehension3() throws Exception {
		testJava("SetComprehension3", "SetComprehension3", "SetComprehension3Addition.stjava", true);
	}

	@Test
	public void testSetComprehension4() throws Exception {
		testJava("SetComprehension4", "SetComprehension4", "SetComprehension4Addition.stjava", true);
	}

	@Test
	public void testSetComprehension5() throws Exception {
		testJava("SetComprehension5", "SetComprehension5", "SetComprehension5Addition.stjava", true);
	}

	@Test
	public void testLetExpression() throws Exception {
		testJava("LetExpression", "LetExpression", "LetExpressionAddition.stjava", true);
	}


	@Test
	public void testLetPredicate() throws Exception {
		testJava("LetPredicate", "LetPredicate", "LetPredicateAddition.stjava", true);
	}

	@Test
	public void testLetSubstitution() throws Exception {
		testJava("LetSubstitution", "LetSubstitution", "LetSubstitutionAddition.stjava", true);
	}

	@Test
	public void testChoiceByPredicate() throws Exception {
		testJava("ChoiceByPredicate");
	}

	@Test
	public void testIfExpression() throws Exception {
		testJava("IfExpression", "IfExpression", "IfExpressionAddition.stjava", true);
	}

	@Test
	public void testIfPredicate() throws Exception {
		testJava("IfPredicate", "IfPredicate", "IfPredicateAddition.stjava", true);
	}

	@Test
	public void testLambda() throws Exception {
		testJava("Lambda", "Lambda", "LambdaAddition.stjava", true);
	}

	@Test
	public void testLambda2() throws Exception {
		testJava("Lambda2", "Lambda2", "Lambda2Addition.stjava", true);
	}

	@Test
	public void testQuantifiedPredicate() throws Exception {
		testJava("QuantifiedPredicate", "QuantifiedPredicate", "QuantifiedPredicateAddition.stjava", true);
	}

	@Test
	public void testQuantifiedPredicate2() throws Exception {
		testJava("QuantifiedPredicate2", "QuantifiedPredicate2", "QuantifiedPredicate2Addition.stjava", true);
	}

	@Test
	public void testQuantifiedPredicate3() throws Exception {
		testJava("QuantifiedPredicate3", "QuantifiedPredicate3", "QuantifiedPredicate3Addition.stjava", true);
	}

	@Test
	public void testQuantifiedExpression1() throws Exception {
		testJava("QuantifiedExpression1", "QuantifiedExpression1", "QuantifiedExpression1Addition.stjava", true);
	}

	@Test
	public void testQuantifiedExpression2() throws Exception {
		testJava("QuantifiedExpression2", "QuantifiedExpression2", "QuantifiedExpression2Addition.stjava", true);
	}

	@Test
	public void testQuantifiedExpression3() throws Exception {
		testJava("QuantifiedExpression3", "QuantifiedExpression3", "QuantifiedExpression3Addition.stjava", true);
	}

	@Test
	public void testQuantifiedExpression4() throws Exception {
		testJava("QuantifiedExpression4", "QuantifiedExpression4", "QuantifiedExpression4Addition.stjava", true);
	}

	@Test
	public void testQuantifiedExpression5() throws Exception {
		testJava("QuantifiedExpression5", "QuantifiedExpression5", "QuantifiedExpression5Addition.stjava", true);
	}


	@Test
	public void testGeneralizedUnion() throws Exception {
		testJava("GeneralizedUnion");
	}

	@Test
	public void testGeneralizedIntersection() throws Exception {
		testJava("GeneralizedIntersection");
	}


	@Test
	public void testFunctionalOverride() throws Exception {
		testJava("FunctionalOverride", "FunctionalOverride", "FunctionalOverrideAddition.stjava", true);
	}

	@Test
	public void testFunctionalOverride2() throws Exception {
		testJava("FunctionalOverride2", "FunctionalOverride2", "FunctionalOverride2Addition.stjava", true);
	}

	@Test
	public void testFunctionalOverride3() throws Exception {
		testJava("FunctionalOverride3", "FunctionalOverride3", "FunctionalOverride3Addition.stjava", true);
	}

	@Test
	public void testOverride() throws Exception {
		testJava("Override", "Override", "OverrideAddition.stjava", true);
	}

	@Test
	public void testPow() throws Exception {
		testJava("Pow", "Pow", "PowAddition.stjava", true);
	}

	@Test
	public void testPow1() throws Exception {
		testJava("Pow1", "Pow1", "Pow1Addition.stjava", true);
	}

	@Test
	public void testFin() throws Exception {
		testJava("Fin", "Fin", "FinAddition.stjava", true);
	}

	@Test
	public void testFin1() throws Exception {
		testJava("Fin1", "Fin1", "Fin1Addition.stjava", true);
	}

	@Test
	public void testId() throws Exception {
		testJava("Id", "Id", "IdAddition.stjava", true);
	}

	@Test
	public void testParallelProduct() throws Exception {
		testJava("ParallelProduct", "ParallelProduct", "ParallelProductAddition.stjava", true);
	}

	@Test
	public void testDirectProduct() throws Exception {
		testJava("DirectProduct", "DirectProduct", "DirectProductAddition.stjava", true);
	}

	@Test
	public void testComposition() throws Exception {
		testJava("Composition", "Composition", "CompositionAddition.stjava", true);
	}

	@Test
	public void testProjection1() throws Exception {
		testJava("Projection1", "Projection1", "Projection1Addition.stjava", true);
	}

	@Test
	public void testProjection2() throws Exception {
		testJava("Projection2", "Projection2", "Projection2Addition.stjava", true);
	}

	@Test
	public void testAppend() throws Exception {
		testJava("Append", "Append", "AppendAddition.stjava", true);
	}


	@Test
	public void testConc() throws Exception {
		testJava("Conc", "Conc", "ConcAddition.stjava", true);
	}

	@Test
	public void testConcat() throws Exception {
		testJava("Concat", "Concat", "ConcatAddition.stjava", true);
	}

	@Test
	public void testDrop() throws Exception {
		testJava("Drop", "Drop", "DropAddition.stjava", true);
	}

	@Test
	public void testEmptySequence() throws Exception {
		testJava("EmptySequence", "EmptySequence", "EmptySequenceAddition.stjava", true);
	}

	@Test
	public void testEnumeratedSequence() throws Exception {
		testJava("EnumeratedSequence");
	}

	@Test
	public void testFirstElementSequence() throws Exception {
		testJava("FirstElementSequence", "FirstElementSequence", "FirstElementSequenceAddition.stjava", true);
	}

	@Test
	public void testFrontSequence() throws Exception {
		testJava("FrontSequence", "FrontSequence", "FrontSequenceAddition.stjava", true);
	}

	@Test
	public void testLastElementSequence() throws Exception {
		testJava("LastElementSequence", "LastElementSequence", "LastElementSequenceAddition.stjava", true);
	}

	@Test
	public void testPrepend() throws Exception {
		testJava("Prepend", "Prepend", "PrependAddition.stjava", true);
	}

	@Test
	public void testReverse() throws Exception {
		testJava("ReverseSequence", "ReverseSequence", "ReverseSequenceAddition.stjava", true);
	}

	@Test
	public void testSizeOfSequence() throws Exception {
		testJava("SizeOfSequence");
	}

	@Test
	public void testTailSequence() throws Exception {
		testJava("TailSequence", "TailSequence", "TailSequenceAddition.stjava", true);
	}

	@Test
	public void testTake() throws Exception {
		testJava("Take", "Take", "TakeAddition.stjava", true);
	}

	@Test
	public void testSequenceOperateRelation() throws Exception {
		testJava("SequenceOperateRelation", "SequenceOperateRelation", "SequenceOperateRelationAddition.stjava", true);
	}

	@Test
	public void testPred() throws Exception {
		testJava("Pred", "Pred", "PredAddition.stjava", true);
	}

	@Test
	public void testSucc() throws Exception {
		testJava("Succ", "Succ", "SuccAddition.stjava", true);
	}

	@Test
	public void testIterate() throws Exception {
		testJava("Iterate", "Iterate", "IterateAddition.stjava", true);
	}

	@Test
	public void testClosure() throws Exception {
		testJava("Closure", "Closure", "ClosureAddition.stjava", true);
	}

	@Test
	public void testClosure1() throws Exception {
		testJava("Closure1", "Closure1", "Closure1Addition.stjava", true);
	}

	@Test
	public void testFnc() throws Exception {
		testJava("Fnc", "Fnc", "FncAddition.stjava", true);
	}

	@Test
	public void testRel() throws Exception {
		testJava("Rel", "Rel", "RelAddition.stjava", true);
	}


	private void cleanUp(String path) {
		File file = new File(path);
		if (file.exists()) {
			file.delete();
		}
	}

}
