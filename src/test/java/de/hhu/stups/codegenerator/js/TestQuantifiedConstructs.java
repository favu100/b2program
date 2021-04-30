package de.hhu.stups.codegenerator.js;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Test;

public class TestQuantifiedConstructs extends TestJs {

    @Test
    public void testSetComprehension1() throws Exception {
        testJs("SetComprehension1", "SetComprehension1", "SetComprehension1Addition.stjs", true);
    }

    @Test
    public void testSetComprehension2() throws Exception {
        testJs("SetComprehension2", "SetComprehension2", "SetComprehension2Addition.stjs", true);
    }

    @Test
    public void testSetComprehension3() throws Exception {
        testJs("SetComprehension3", "SetComprehension3", "SetComprehension3Addition.stjs", true);
    }

    @Test
    public void testSetComprehension4() throws Exception {
        testJs("SetComprehension4", "SetComprehension4", "SetComprehension4Addition.stjs", true);
    }

    @Test
    public void testSetComprehension5() throws Exception {
        testJs("SetComprehension5", "SetComprehension5", "SetComprehension5Addition.stjs", true);
    }

    @Test
    public void testSetComprehension6() throws Exception {
        testJs("SetComprehension6", "SetComprehension6", "SetComprehension6Addition.stjs", true);
    }

    @Test
    public void testSetComprehension7() throws Exception {
        testJs("SetComprehension7", "SetComprehension7", "SetComprehension7Addition.stjs", true);
    }

    @Test
    public void testSetComprehension8() throws Exception {
        testJs("SetComprehension8", "SetComprehension8", "SetComprehension8Addition.stjs", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testSetComprehension9() throws Exception {
        testJs("SetComprehension9", "SetComprehension9", "SetComprehension9Addition.stjs", true);
    }

    @Test
    public void testLambda() throws Exception {
        testJs("Lambda", "Lambda", "LambdaAddition.stjs", true);
    }

    @Test
    public void testLambda2() throws Exception {
        testJs("Lambda2", "Lambda2", "Lambda2Addition.stjs", true);
    }

    @Test
    public void testQuantifiedPredicate() throws Exception {
        testJs("QuantifiedPredicate", "QuantifiedPredicate", "QuantifiedPredicateAddition.stjs", true);
    }

    @Test
    public void testQuantifiedPredicate2() throws Exception {
        testJs("QuantifiedPredicate2", "QuantifiedPredicate2", "QuantifiedPredicate2Addition.stjs", true);
    }

    @Test
    public void testQuantifiedPredicate3() throws Exception {
        testJs("QuantifiedPredicate3", "QuantifiedPredicate3", "QuantifiedPredicate3Addition.stjs", true);
    }

    @Test
    public void testQuantifiedPredicate4() throws Exception {
        testJs("QuantifiedPredicate4", "QuantifiedPredicate4", "QuantifiedPredicate4Addition.stjs", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate5() throws Exception {
        testJs("QuantifiedPredicate5", "QuantifiedPredicate5", "QuantifiedPredicate5Addition.stjs", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate6() throws Exception {
        testJs("QuantifiedPredicate6", "QuantifiedPredicate6", "QuantifiedPredicate6Addition.stjs", true);
    }

    @Test
    public void testQuantifiedPredicate7() throws Exception {
        testJs("QuantifiedPredicate7", "QuantifiedPredicate7", "QuantifiedPredicate7Addition.stjs", true);
    }

    @Test
    public void testQuantifiedExpression1() throws Exception {
        testJs("QuantifiedExpression1", "QuantifiedExpression1", "QuantifiedExpression1Addition.stjs", true);
    }

    @Test
    public void testQuantifiedExpression2() throws Exception {
        testJs("QuantifiedExpression2", "QuantifiedExpression2", "QuantifiedExpression2Addition.stjs", true);
    }

    @Test
    public void testQuantifiedExpression3() throws Exception {
        testJs("QuantifiedExpression3", "QuantifiedExpression3", "QuantifiedExpression3Addition.stjs", true);
    }

    @Test
    public void testQuantifiedExpression4() throws Exception {
        testJs("QuantifiedExpression4", "QuantifiedExpression4", "QuantifiedExpression4Addition.stjs", true);
    }

    @Test
    public void testQuantifiedExpression5() throws Exception {
        testJs("QuantifiedExpression5", "QuantifiedExpression5", "QuantifiedExpression5Addition.stjs", true);
    }


    @Test
    public void testLetExpression() throws Exception {
        testJs("LetExpression", "LetExpression", "LetExpressionAddition.stjs", true);
    }


    @Test
    public void testLetPredicate() throws Exception {
        testJs("LetPredicate", "LetPredicate", "LetPredicateAddition.stjs", true);
    }

    @Test
    public void testLetSubstitution() throws Exception {
        testJs("LetSubstitution", "LetSubstitution", "LetSubstitutionAddition.stjs", true);
    }

    @Test
    public void testChoiceByPredicate() throws Exception {
        testJs("ChoiceByPredicate");
    }


}
