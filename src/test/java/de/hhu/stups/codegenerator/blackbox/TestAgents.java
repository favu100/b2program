package de.hhu.stups.codegenerator.blackbox;

import org.junit.Test;

public class TestAgents extends TestBlackBox {

    @Test
    public void testLunarLander() throws Exception {
        testBlackBox("LunarLander", "LunarLander-v2", "model/LunarLander-v2", "A2C", 100);
    }

    @Test
    public void testHighwayEnvironment() throws Exception {
        testBlackBox("HighwayEnvironment", "highway-fast-v0", "highway_dqn/highway_dqn/DQNFast3/rl_model_500000_steps", "DQN", 100);
    }

}
