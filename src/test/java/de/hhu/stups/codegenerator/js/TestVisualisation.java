package de.hhu.stups.codegenerator.js;

import org.junit.Ignore;
import org.junit.Test;

public class TestVisualisation extends TestJs {

    @Test
    public void testTrafficLight() throws Exception {
        testJs("visualisation/TrafficLight", "TrafficLight", "TrafficLightAddition.stjs", "traffic_light.json", false);
    }

    @Test
    public void testButton() throws Exception {
        testJs("visualisation/Button", "Button", null, "button.json", false);
    }

    @Test
    public void testLightmodel() throws Exception {
        testJs("visualisation/PitmanController_TIME_MC_v4", "PitmanController_TIME_MC_v4", null, "blinking_visb_v4.json", false);
    }
}
