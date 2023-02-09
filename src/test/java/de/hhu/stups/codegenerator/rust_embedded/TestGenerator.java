package de.hhu.stups.codegenerator.rust_embedded;

import de.hhu.stups.codegenerator.CodeGenerator;
import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.definitions.SetDefinition;
import de.hhu.stups.codegenerator.definitions.SetDefinitions;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.prob.parser.antlr.BProject;
import de.prob.parser.ast.types.EnumeratedSetElementType;
import org.junit.Test;

import java.io.File;
import java.util.List;
import java.util.Map;

import static org.junit.Assert.*;


public class TestGenerator {

    private MachineGenerator getMachineGenerator(String machine) {
        ClassLoader classLoader = this.getClass().getClassLoader();
        File file = new File(classLoader.getResource("de/hhu/stups/codegenerator/embedded/"+machine).getFile());
        assertTrue(file.exists());
        MachineGenerator machineGenerator = new MachineGenerator(GeneratorMode.RS, false, "-2147483648", "2147483647",
                "10", false, false, null, false, false, null, true);

        BProject bProject = CodeGenerator.parseProject(file.toPath());
        machineGenerator.generateMachine(bProject.getMainMachine(), GeneratorMode.RS);
        return machineGenerator;
    }

    @Test
    public void test_SimpleEnumeratedSet() {
        MachineGenerator machineGenerator = getMachineGenerator("SimpleEnumeratedSet.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(1, setDefinitions.size());

        SetDefinition setCounters = setDefinitions.getDefinition(new EnumeratedSetElementType("Counters", null));
        assertNotNull(setCounters);
        assertEquals(3, setCounters.getElements().size());
    }

    @Test
    public void test_SimplePowEnumeratedSet() {
        MachineGenerator machineGenerator = getMachineGenerator("SimplePowEnumeratedSet.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(2, setDefinitions.size());

        SetDefinition setCounters = setDefinitions.getDefinition(new EnumeratedSetElementType("POW(Counters)", null));
        assertNotNull(setCounters);
        assertEquals(8, setCounters.getElements().size());
    }

    @Test
    public void test_SimplePowPowEnumeratedSet() {
        MachineGenerator machineGenerator = getMachineGenerator("SimplePowPowEnumeratedSet.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(3, setDefinitions.size());

        SetDefinition setCounters = setDefinitions.getDefinition(new EnumeratedSetElementType("POW(POW(Counters))", null));
        assertNotNull(setCounters);
        assertEquals(16, setCounters.getElements().size());
    }

    @Test
    public void test_MaxPowEnumeratedSet() {
        MachineGenerator machineGenerator = getMachineGenerator("MaxPowEnumeratedSet.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(4, setDefinitions.size());

        SetDefinition setCounters = setDefinitions.getDefinition(new EnumeratedSetElementType("POW(POW(POW(Counters)))", null));
        assertNotNull(setCounters);
        assertEquals(16, setCounters.getElements().size());
    }

    @Test
    public void test_SimpleRelation() {
        MachineGenerator machineGenerator = getMachineGenerator("SimpleRelation.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        //relation itself does not need an enum, only when its needed as an SetItem (i.e. powerset/nested relation)
        assertEquals(2, setDefinitions.size());
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Counters", null)));
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Persons", null)));
    }

    @Test
    public void test_PowRelation() {
        MachineGenerator machineGenerator = getMachineGenerator("PowRelation.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(4, setDefinitions.size());
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Counters", null)));
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Persons", null)));
        SetDefinition rel = setDefinitions.getDefinition(new EnumeratedSetElementType("Counters*Persons", null));
        assertNotNull(rel);
        assertEquals(6, rel.getElements().size());
        SetDefinition powRel = setDefinitions.getDefinition(new EnumeratedSetElementType("POW(Counters*Persons)", null));
        assertNotNull(powRel);
        assertEquals(64, powRel.getElements().size());
    }

    @Test
    public void test_NestedRelation() {
        MachineGenerator machineGenerator = getMachineGenerator("NestedRelation.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(5, setDefinitions.size());
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Counters", null)));
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Persons", null)));
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Shift", null)));
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Counters*Persons", null)));
        SetDefinition powRel = setDefinitions.getDefinition(new EnumeratedSetElementType("POW(Counters*Persons)", null));
        assertNotNull(powRel);
        assertEquals(16, powRel.getElements().size());
    }

    @Test
    public void test_RedundantConstSet() {
        MachineGenerator machineGenerator = getMachineGenerator("RedundantConstSet.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(1, setDefinitions.size());
        SetDefinition personsSet = setDefinitions.getDefinition(new EnumeratedSetElementType("Persons", null));
        assertNotNull(personsSet);
        assertEquals(3, personsSet.getElements().size());
    }

    @Test
    public void test_ConstPowSet() {
        MachineGenerator machineGenerator = getMachineGenerator("ConstPowSet.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(2, setDefinitions.size());
        SetDefinition groupsSet = setDefinitions.getDefinition(new EnumeratedSetElementType("POW(Persons)", null));
        assertNotNull(groupsSet);
        assertTrue(groupsSet.isConstant());
        List<String> groupElements = groupsSet.getElements();
        assertEquals(2, groupElements.size());
        Integer p1_p3_Idx = null;
        Integer p2_Idx = null;
        for (int i = 0; i < groupElements.size(); i++) {
            switch (groupElements.get(i)) {
                case "SET_P1__P3_TES": p1_p3_Idx = i; break;
                case "SET_P2_TES": p2_Idx = i; break;
            }
        }
        assertNotNull(p1_p3_Idx);
        assertNotNull(p2_Idx);
        Map<Integer, boolean[]> idxToBitarr = groupsSet.bitArrIndexed();
        assertArrayEquals(new boolean[]{true, false, true}, idxToBitarr.get(p1_p3_Idx));
        assertArrayEquals(new boolean[]{false, true, false}, idxToBitarr.get(p2_Idx));
    }

    @Test
    public void test_RedundantConstRelation() {
        MachineGenerator machineGenerator = getMachineGenerator("RedundantConstRelation.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(2, setDefinitions.size());
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Counters", null)));
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Persons", null)));
    }

    @Test
    public void test_ConstPowRelation() {
        MachineGenerator machineGenerator = getMachineGenerator("ConstPowRelation.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(4, setDefinitions.size());
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Counters", null)));
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Persons", null)));
        SetDefinition rel = setDefinitions.getDefinition(new EnumeratedSetElementType("Counters*Persons", null));
        assertNotNull(rel);
        assertEquals(6, rel.getElements().size());
        SetDefinition powRel = setDefinitions.getDefinition(new EnumeratedSetElementType("POW(Counters*Persons)", null));
        assertNotNull(powRel);
        assertEquals(2, powRel.getElements().size());
    }

    @Test
    public void test_ConstNestedRelation() {
        MachineGenerator machineGenerator = getMachineGenerator("ConstNestedRelation.mch");
        SetDefinitions setDefinitions = machineGenerator.getSetDefinitions();

        assertEquals(5, setDefinitions.size());
        //TODO?: currently, setDef for 'Persons*POW(Counters*Counters)' is generated, not sure if that is necessary
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Counters", null)));
        assertTrue(setDefinitions.containsDefinition(new EnumeratedSetElementType("Persons", null)));
        SetDefinition rel = setDefinitions.getDefinition(new EnumeratedSetElementType("Counters*Counters", null));
        assertNotNull(rel);
        assertEquals(36, rel.getElements().size());
        SetDefinition powRel = setDefinitions.getDefinition(new EnumeratedSetElementType("POW(Counters*Counters)", null));
        assertNotNull(powRel);
        assertEquals(2, powRel.getElements().size());
    }
}
