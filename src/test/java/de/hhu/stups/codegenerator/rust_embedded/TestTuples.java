package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestTuples extends TestRSE {
    public TestTuples() throws URISyntaxException, IOException {}

    @Test
    public void testTupleProjection1() throws Exception {
        testRSE("TupleProjection1", "TupleProjection1Addition.strs");
    }

    @Test
    public void testTupleProjection2() throws Exception {
        testRSE("TupleProjection2", "TupleProjection2Addition.strs");
    }
}
