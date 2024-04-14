package de.hhu.stups.codegenerator.java;

import org.junit.Ignore;
import org.junit.Test;

public class TestOptimizations extends TestJava {

    @Test
    public void testNatural() throws Exception {
        testJava("Natural", "Natural", "NaturalAddition.stjava", true);
    }

    @Test
    public void testNatural1() throws Exception {
        testJava("Natural1", "Natural1", "Natural1Addition.stjava", true);
    }

    @Test
    public void testNotNatural() throws Exception {
        testJava("NotNatural", "NotNatural", "NotNaturalAddition.stjava", true);
    }

    @Test
    public void testNotNatural1() throws Exception {
        testJava("NotNatural1", "NotNatural1", "NotNatural1Addition.stjava", true);
    }

    @Test
    public void testInteger() throws Exception {
        testJava("Integer", "Integer", "IntegerAddition.stjava", true);
    }

    @Test
    public void testNotInteger() throws Exception {
        testJava("NotInteger", "NotInteger", "NotIntegerAddition.stjava", true);
    }


}
