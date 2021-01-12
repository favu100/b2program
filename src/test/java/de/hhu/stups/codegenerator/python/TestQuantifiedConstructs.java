package de.hhu.stups.codegenerator.python;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Test;

public class TestQuantifiedConstructs extends TestPython {

    @Test
    public void testSetComprehension1() throws Exception {
        testPython("SetComprehension1", "SetComprehension1", "SetComprehension1Addition.stpy", true);
    }

    @Test
    public void testSetComprehension2() throws Exception {
        testPython("SetComprehension2", "SetComprehension2", "SetComprehension2Addition.stpy", true);
    }

    @Test
    public void testSetComprehension3() throws Exception {
        testPython("SetComprehension3", "SetComprehension3", "SetComprehension3Addition.stpy", true);
    }

    @Test
    public void testSetComprehension4() throws Exception {
        testPython("SetComprehension4", "SetComprehension4", "SetComprehension4Addition.stpy", true);
    }

    @Test
    public void testSetComprehension5() throws Exception {
        testPython("SetComprehension5", "SetComprehension5", "SetComprehension5Addition.stpy", true);
    }

    @Test
    public void testSetComprehension6() throws Exception {
        testPython("SetComprehension6", "SetComprehension6", "SetComprehension6Addition.stpy", true);
    }

    @Test
    public void testSetComprehension7() throws Exception {
        testPython("SetComprehension7", "SetComprehension7", "SetComprehension7Addition.stpy", true);
    }

    @Test
    public void testSetComprehension8() throws Exception {
        testPython("SetComprehension8", "SetComprehension8", "SetComprehension8Addition.stpy", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testSetComprehension9() throws Exception {
        testPython("SetComprehension9", "SetComprehension9", "SetComprehension9Addition.stpy", true);
    }

    @Test
    public void testLambda() throws Exception {
        testPython("Lambda", "Lambda", "LambdaAddition.stpy", true);
    }

    @Test
    public void testLambda2() throws Exception {
        testPython("Lambda2", "Lambda2", "Lambda2Addition.stpy", true);
    }

    @Test
    public void testQuantifiedPredicate() throws Exception {
        testPython("QuantifiedPredicate", "QuantifiedPredicate", "QuantifiedPredicateAddition.stpy", true);
    }

    @Test
    public void testQuantifiedPredicate2() throws Exception {
        testPython("QuantifiedPredicate2", "QuantifiedPredicate2", "QuantifiedPredicate2Addition.stpy", true);
    }

    @Test
    public void testQuantifiedPredicate3() throws Exception {
        testPython("QuantifiedPredicate3", "QuantifiedPredicate3", "QuantifiedPredicate3Addition.stpy", true);
    }

    @Test
    public void testQuantifiedPredicate4() throws Exception {
        testPython("QuantifiedPredicate4", "QuantifiedPredicate4", "QuantifiedPredicate4Addition.stpy", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate5() throws Exception {
        testPython("QuantifiedPredicate5", "QuantifiedPredicate5", "QuantifiedPredicate5Addition.stpy", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate6() throws Exception {
        testPython("QuantifiedPredicate6", "QuantifiedPredicate6", "QuantifiedPredicate6Addition.stpy", true);
    }

    @Test
    public void testQuantifiedPredicate7() throws Exception {
        testPython("QuantifiedPredicate7", "QuantifiedPredicate7", "QuantifiedPredicate7Addition.stpy", true);
    }

    @Test
    public void testQuantifiedExpression1() throws Exception {
        testPython("QuantifiedExpression1", "QuantifiedExpression1", "QuantifiedExpression1Addition.stpy", true);
    }

    @Test
    public void testQuantifiedExpression2() throws Exception {
        testPython("QuantifiedExpression2", "QuantifiedExpression2", "QuantifiedExpression2Addition.stpy", true);
    }

    @Test
    public void testQuantifiedExpression3() throws Exception {
        testPython("QuantifiedExpression3", "QuantifiedExpression3", "QuantifiedExpression3Addition.stpy", true);
    }

    @Test
    public void testQuantifiedExpression4() throws Exception {
        testPython("QuantifiedExpression4", "QuantifiedExpression4", "QuantifiedExpression4Addition.stpy", true);
    }

    @Test
    public void testQuantifiedExpression5() throws Exception {
        testPython("QuantifiedExpression5", "QuantifiedExpression5", "QuantifiedExpression5Addition.stpy", true);
    }


    @Test
    public void testLetExpression() throws Exception {
        testPython("LetExpression", "LetExpression", "LetExpressionAddition.stpy", true);
    }


    @Test
    public void testLetPredicate() throws Exception {
        testPython("LetPredicate", "LetPredicate", "LetPredicateAddition.stpy", true);
    }

    @Test
    public void testLetSubstitution() throws Exception {
        testPython("LetSubstitution", "LetSubstitution", "LetSubstitutionAddition.stpy", true);
    }

    @Test
    public void testChoiceByPredicate() throws Exception {
        testPython("ChoiceByPredicate");
    }


}
