package de.hhu.stups.codegenerator.ajs;

import org.junit.Test;

public class TestVisualisation extends TestJs {

    @Test
    public void testTrafficLight() throws Exception {
        testJs("visualisation/TrafficLight", "TrafficLight", "TrafficLightAddition.stjs", "traffic_light.json", false, true);
    }

    @Test
    public void testLightmodel() throws Exception {
        testJs("visualisation/PitmanController_TIME_MC_v4", "PitmanController_TIME_MC_v4", null, "blinking_visb_v4.json", false, true);
    }

    @Test
    public void testButton() throws Exception {
        testJs("visualisation/Button", "Button", null, "button_visualization.json", false, true);
    }

    @Test
    public void testLift() throws Exception {
        testJs("visualisation/Lift", "Lift", null, "lift_groups.json", false, true);
    }

    @Test
    public void testLandingGear() throws Exception {
        testJs("landing_gear/LandingGear_R6", "LandingGear_R6", null, "LandingGear.json", false, true);
    }

    @Test
    public void testLandingGear2() throws Exception {
        testJs("landing_gear/LandingGear_R6", "LandingGear_R6", null, "LandingGear_GearsDoors.json", false, true);
    }

    @Test
    public void testAnd() throws Exception {
        testJs("visualisation/And", "And", null, null, false, true);
    }

    @Test
    public void testTravelAgency() throws Exception {
        testJs("visualisation/TravelAgency", "TravelAgency", null, null, false, true);
    }

    @Test
    public void testTrafficLightforServer() throws Exception {
        testJs("visualisation/TrafficLight", "TrafficLight", "TrafficLightAddition.stjs", "traffic_light.json", false, true, "https://favu100.github.io/b2program/visualizations/TrafficLight");
    }

    @Test
    public void testLightmodelforServer() throws Exception {
        testJs("visualisation/PitmanController_TIME_MC_v4", "PitmanController_TIME_MC_v4", null, "blinking_visb_v4.json", false, true, "https://favu100.github.io/b2program/visualizations/LightModel");
    }

    @Test
    public void testLandingGearforServer() throws Exception {
        testJs("landing_gear/LandingGear_R6", "LandingGear_R6", null, "LandingGear.json", false, true, "https://favu100.github.io/b2program/visualizations/LandingGear/HydraulicCircuit");
    }

    @Test
    public void testLandingGear2forServer() throws Exception {
        testJs("landing_gear/LandingGear_R6", "LandingGear_R6", null, "LandingGear_GearsDoors.json", false, true, "https://favu100.github.io/b2program/visualizations/LandingGear/GearsDoors");
    }

}
