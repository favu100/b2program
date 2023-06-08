package de.hhu.stups.codegenerator.blackbox;

import org.junit.Test;

public class TestAgents extends TestBlackBox {

    @Test
    public void testLunarLander() throws Exception {
        testBlackBox("LunarLander", "LunarLander-v2", "model/LunarLander-v2", "A2C", 100);
    }

}
