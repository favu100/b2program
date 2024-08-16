package de.hhu.stups.codegenerator.java;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Test;

public class TestQuantifiedConstructs extends TestJava {

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
    public void testSetComprehension6() throws Exception {
        testJava("SetComprehension6", "SetComprehension6", "SetComprehension6Addition.stjava", true);
    }

    @Test
    public void testSetComprehension7() throws Exception {
        testJava("SetComprehension7", "SetComprehension7", "SetComprehension7Addition.stjava", true);
    }

    @Test
    public void testSetComprehension8() throws Exception {
        testJava("SetComprehension8", "SetComprehension8", "SetComprehension8Addition.stjava", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testSetComprehension9() throws Exception {
        testJava("SetComprehension9", "SetComprehension9", "SetComprehension9Addition.stjava", true);
    }

    @Test
    public void testSetComprehension_Old() throws Exception {
        testJava("SetComprehension_Old");
    }

    @Test
    public void testSetComprehension_Pruning() throws Exception {
        testJava("SetComprehension_Pruning");
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
    public void testQuantifiedPredicate4() throws Exception {
        testJava("QuantifiedPredicate4", "QuantifiedPredicate4", "QuantifiedPredicate4Addition.stjava", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate5() throws Exception {
        testJava("QuantifiedPredicate5", "QuantifiedPredicate5", "QuantifiedPredicate5Addition.stjava", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate6() throws Exception {
        testJava("QuantifiedPredicate6", "QuantifiedPredicate6", "QuantifiedPredicate6Addition.stjava", true);
    }

    @Test
    public void testQuantifiedPredicate7() throws Exception {
        testJava("QuantifiedPredicate7", "QuantifiedPredicate7", "QuantifiedPredicate7Addition.stjava", true);
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


}
