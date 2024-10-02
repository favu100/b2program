package de.hhu.stups.codegenerator.ajs;

import org.junit.Test;

public class TestStaticConstants extends TestJs{
    @Test
    public void sameMachine() throws Exception {
        testJs("staticConstants/SameMachine", "SameMachine", "SameMachineAddition.stjs", true);
    }

    @Test
    public void otherMachine() throws Exception {
        testJs("staticConstants/OtherMachine", "OtherMachine", "OtherMachineAddition.stjs", true);
    }
}
