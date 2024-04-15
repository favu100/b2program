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

    @Test
    public void testInt() throws Exception {
        testJava("Int", "Int", "IntAddition.stjava", true);
    }

    @Test
    public void testNotInt() throws Exception {
        testJava("NotInt", "NotInt", "NotIntAddition.stjava", true);
    }

    @Test
    public void testString() throws Exception {
        testJava("Stringg", "Stringg", "StringAddition.stjava", true);
    }

    @Test
    public void testNotString() throws Exception {
        testJava("NotString", "NotString", "NotStringAddition.stjava", true);
    }

    @Test
    public void testBoolean() throws Exception {
        testJava("Booleann", "Booleann", "BooleanAddition.stjava", true);
    }

    @Test
    public void testNotBoolean() throws Exception {
        testJava("NotBoolean", "NotBoolean", "NotBooleanAddition.stjava", true);
    }

    @Test
    public void testIsInInterval() throws Exception {
        testJava("IsInInterval", "IsInInterval", "IsInInterval.stjava", true);
    }

    @Test
    public void testIsNotInInterval() throws Exception {
        testJava("IsNotInInterval", "IsNotInInterval", "IsNotInInterval.stjava", true);
    }
}
