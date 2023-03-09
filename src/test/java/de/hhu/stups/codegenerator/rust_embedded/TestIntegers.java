package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestIntegers extends TestRSE {

    public TestIntegers() throws URISyntaxException, IOException {}

    @Test
    public void testSmallNumbers() throws Exception {
        testRSE("integers/SmallNumbers", "SmallNumbersAddition.strs");
    }

    @Test
    public void testBigNumbers() throws Exception {
        testRSE("integers/BigNumbers", "BigNumbersAddition.strs");
    }
}
