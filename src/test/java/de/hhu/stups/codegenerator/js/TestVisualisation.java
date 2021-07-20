package de.hhu.stups.codegenerator.js;

import org.junit.Ignore;
import org.junit.Test;

public class TestVisualisation extends TestJs {

    @Test
    public void testTrafficLight() throws Exception {
        testJs("visualisation/TrafficLight", "TrafficLight", "TrafficLightAddition.stjs", "0.json", false);
    }
}
