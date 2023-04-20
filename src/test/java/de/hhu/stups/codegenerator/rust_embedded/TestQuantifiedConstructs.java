package de.hhu.stups.codegenerator.rust_embedded;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Ignore;
import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestQuantifiedConstructs extends TestRSE {
    public TestQuantifiedConstructs() throws URISyntaxException, IOException {}

    @Test
    public void testSetComprehension1() throws Exception {
        testRSE("SetComprehension1", "SetComprehension1Addition.strs");
    }

    @Test
    public void testSetComprehension2() throws Exception {
        testRSE("SetComprehension2", "SetComprehension2Addition.strs");
    }

    @Test
    public void testSetComprehension3() throws Exception {
        testRSE("SetComprehension3", "SetComprehension3Addition.strs");
    }

    @Test
    public void testSetComprehension4() throws Exception {
        testRSE("SetComprehension4", "SetComprehension4Addition.strs");
    }

    @Test
    public void testSetComprehension5() throws Exception {
        testRSE("SetComprehension5", "SetComprehension5Addition.strs");
    }

    @Ignore //Tuples not supported as part of Sets/Relations
    @Test
    public void testSetComprehension6() throws Exception {
        testRSE("SetComprehension6", "SetComprehension6Addition.strs");
    }

    @Ignore //Tuples not supported as part of Sets/Relations
    @Test
    public void testSetComprehension7() throws Exception {
        testRSE("SetComprehension7", "SetComprehension7Addition.strs");
    }

    @Test
    public void testSetComprehension8() throws Exception {
        testRSE("SetComprehension8", "SetComprehension8Addition.strs");
    }

    @Test(expected = CodeGenerationException.class)
    public void testSetComprehension9() throws Exception {
        testRSE("SetComprehension9", "SetComprehension9Addition.strs");
    }

    @Test
    public void testLambda() throws Exception {
        testRSE("Lambda", "LambdaAddition.strs");
    }

    @Test
    public void testLambda2() throws Exception {
        testRSE("Lambda2", "Lambda2Addition.strs");
    }

    @Test
    public void testQuantifiedPredicate() throws Exception {
        testRSE("QuantifiedPredicate", "QuantifiedPredicateAddition.strs");
    }

    @Test
    public void testQuantifiedPredicate2() throws Exception {
        testRSE("QuantifiedPredicate2", "QuantifiedPredicate2Addition.strs");
    }

    @Test
    public void testQuantifiedPredicate3() throws Exception {
        testRSE("QuantifiedPredicate3", "QuantifiedPredicate3Addition.strs");
    }

    /**
     * Test will error, since SELECT statement is {@code False}, but the function is called anyways and in rust
     * we panic here. In B, this function is not even allowed to be called at all, so this behaviour should be ok.
     */
    @Test(expected = Exception.class)
    public void testQuantifiedPredicate4() throws Exception {
        testRSE("QuantifiedPredicate4", "QuantifiedPredicate4Addition.strs");
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate5() throws Exception {
        testRSE("QuantifiedPredicate5", "QuantifiedPredicate5Addition.strs");
    }

    @Test(expected = CodeGenerationException.class)
    public void testQuantifiedPredicate6() throws Exception {
        testRSE("QuantifiedPredicate6", "QuantifiedPredicate6Addition.strs");
    }

    @Test
    public void testQuantifiedPredicate7() throws Exception {
        testRSE("QuantifiedPredicate7", "QuantifiedPredicate7Addition.strs");
    }

    @Test
    public void testQuantifiedExpression1() throws Exception {
        testRSE("QuantifiedExpression1", "QuantifiedExpression1Addition.strs");
    }

    @Test
    public void testQuantifiedExpression2() throws Exception {
        testRSE("QuantifiedExpression2", "QuantifiedExpression2Addition.strs");
    }

    @Test
    public void testQuantifiedExpression3() throws Exception {
        testRSE("QuantifiedExpression3", "QuantifiedExpression3Addition.strs");
    }

    @Test
    public void testQuantifiedExpression4() throws Exception {
        testRSE("QuantifiedExpression4", "QuantifiedExpression4Addition.strs");
    }

    @Test
    public void testQuantifiedExpression5() throws Exception {
        testRSE("QuantifiedExpression5", "QuantifiedExpression5Addition.strs");
    }


    @Test
    public void testLetExpression() throws Exception {
        testRSE("LetExpression", "LetExpressionAddition.strs");
    }


    @Test
    public void testLetPredicate() throws Exception {
        testRSE("LetPredicate", "LetPredicateAddition.strs");
    }

    @Test
    public void testLetSubstitution() throws Exception {
        testRSE("LetSubstitution", "LetSubstitutionAddition.strs");
    }

    @Ignore // choice not really supported
    @Test
    public void testChoiceByPredicate() throws Exception {
        testRSE("ChoiceByPredicate", "ChoiceByPredicateAddition.strs");
    }
}
