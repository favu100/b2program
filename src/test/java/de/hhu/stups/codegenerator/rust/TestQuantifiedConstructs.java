package de.hhu.stups.codegenerator.rust;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import de.hhu.stups.codegenerator.java.TestJava;
import org.junit.Ignore;
import org.junit.Test;

@Ignore
public class TestQuantifiedConstructs extends TestRS {

    @Test
    public void testSetComprehension1() throws Exception {
        testRS("SetComprehension1", "SetComprehension1", "SetComprehension1Addition.strs", true);
    }

    @Test
    public void testSetComprehension2() throws Exception {
        testRS("SetComprehension2", "SetComprehension2", "SetComprehension2Addition.strs", true);
    }

    @Test
    public void testSetComprehension3() throws Exception {
        testRS("SetComprehension3", "SetComprehension3", "SetComprehension3Addition.strs", true);
    }

    @Test
    public void testSetComprehension4() throws Exception {
        testRS("SetComprehension4", "SetComprehension4", "SetComprehension4Addition.strs", true);
    }

    @Test
    public void testSetComprehension5() throws Exception {
        testRS("SetComprehension5", "SetComprehension5", "SetComprehension5Addition.strs", true);
    }

    @Test
    public void testSetComprehension6() throws Exception {
        testRS("SetComprehension6", "SetComprehension6", "SetComprehension6Addition.strs", true);
    }

    @Test
    public void testSetComprehension7() throws Exception {
        testRS("SetComprehension7", "SetComprehension7", "SetComprehension7Addition.strs", true);
    }

    @Test
    public void testSetComprehension8() throws Exception {
        testRS("SetComprehension8", "SetComprehension8", "SetComprehension8Addition.strs", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testSetComprehension9() throws Exception {
        testRS("SetComprehension9", "SetComprehension9", "SetComprehension9Addition.strs", true);
    }

    @Test
    public void testLambda() throws Exception {
        testRS("Lambda", "Lambda", "LambdaAddition.strs", true);
    }

    @Test
    public void testLambda2() throws Exception {
        testRS("Lambda2", "Lambda2", "Lambda2Addition.strs", true);
    }

    @Test
    public void testQuantifiedPredicate() throws Exception {
        testRS("QuantifiedPredicate", "QuantifiedPredicate", "QuantifiedPredicateAddition.strs", true);
    }

    @Test
    public void testQuantifiedPredicate2() throws Exception {
        testRS("QuantifiedPredicate2", "QuantifiedPredicate2", "QuantifiedPredicate2Addition.strs", true);
    }

    @Test
    public void testQuantifiedPredicate3() throws Exception {
        testRS("QuantifiedPredicate3", "QuantifiedPredicate3", "QuantifiedPredicate3Addition.strs", true);
    }

    /**
     * Test will error, since SELECT statement is {@code False}, but the function is called anyways and in rust
     * we panic here. In B, this function is not even allowed to be called at all, so this behaviour should be ok.
     */
    @Test(expected = Exception.class)
    public void testQuantifiedPredicate4() throws Exception {
        testRS("QuantifiedPredicate4", "QuantifiedPredicate4", "QuantifiedPredicate4Addition.strs", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate5() throws Exception {
        testRS("QuantifiedPredicate5", "QuantifiedPredicate5", "QuantifiedPredicate5Addition.strs", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate6() throws Exception {
        testRS("QuantifiedPredicate6", "QuantifiedPredicate6", "QuantifiedPredicate6Addition.strs", true);
    }

    @Test
    public void testQuantifiedPredicate7() throws Exception {
        testRS("QuantifiedPredicate7", "QuantifiedPredicate7", "QuantifiedPredicate7Addition.strs", true);
    }

    @Test
    public void testQuantifiedExpression1() throws Exception {
        testRS("QuantifiedExpression1", "QuantifiedExpression1", "QuantifiedExpression1Addition.strs", true);
    }

    @Test
    public void testQuantifiedExpression2() throws Exception {
        testRS("QuantifiedExpression2", "QuantifiedExpression2", "QuantifiedExpression2Addition.strs", true);
    }

    @Test
    public void testQuantifiedExpression3() throws Exception {
        testRS("QuantifiedExpression3", "QuantifiedExpression3", "QuantifiedExpression3Addition.strs", true);
    }

    @Test
    public void testQuantifiedExpression4() throws Exception {
        testRS("QuantifiedExpression4", "QuantifiedExpression4", "QuantifiedExpression4Addition.strs", true);
    }

    @Test
    public void testQuantifiedExpression5() throws Exception {
        testRS("QuantifiedExpression5", "QuantifiedExpression5", "QuantifiedExpression5Addition.strs", true);
    }


    @Test
    public void testLetExpression() throws Exception {
        testRS("LetExpression", "LetExpression", "LetExpressionAddition.strs", true);
    }


    @Test
    public void testLetPredicate() throws Exception {
        testRS("LetPredicate", "LetPredicate", "LetPredicateAddition.strs", true);
    }

    @Test
    public void testLetSubstitution() throws Exception {
        testRS("LetSubstitution", "LetSubstitution", "LetSubstitutionAddition.strs", true);
    }

    @Test
    public void testChoiceByPredicate() throws Exception {
        testRS("ChoiceByPredicate");
    }


}
