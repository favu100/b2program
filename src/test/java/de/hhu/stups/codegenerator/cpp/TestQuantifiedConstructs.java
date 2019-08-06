package de.hhu.stups.codegenerator.cpp;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Test;

public class TestQuantifiedConstructs extends TestCpp {

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
    public void testSetComprehension6() throws Exception {
        testCpp("SetComprehension6", "SetComprehension6", "SetComprehension6Addition.stcpp", true);
    }

    @Test
    public void testSetComprehension7() throws Exception {
        testCpp("SetComprehension7", "SetComprehension7", "SetComprehension7Addition.stcpp", true);
    }

    @Test
    public void testSetComprehension8() throws Exception {
        testCpp("SetComprehension8", "SetComprehension8", "SetComprehension8Addition.stcpp", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testSetComprehension9() throws Exception {
        testCpp("SetComprehension9", "SetComprehension8", "SetComprehension8Addition.stcpp", true);
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
    public void testQuantifiedPredicate4() throws Exception {
        testCpp("QuantifiedPredicate4", "QuantifiedPredicate4", "QuantifiedPredicate4Addition.stcpp", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate5() throws Exception {
        testCpp("QuantifiedPredicate5", "QuantifiedPredicate5", "QuantifiedPredicate5Addition.stcpp", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate6() throws Exception {
        testCpp("QuantifiedPredicate6", "QuantifiedPredicate6", "QuantifiedPredicate6Addition.stcpp", true);
    }

    @Test
    public void testQuantifiedPredicate7() throws Exception {
        testCpp("QuantifiedPredicate7", "QuantifiedPredicate7", "QuantifiedPredicate7Addition.stcpp", true);
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


}
