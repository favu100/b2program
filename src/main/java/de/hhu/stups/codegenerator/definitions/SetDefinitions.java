package de.hhu.stups.codegenerator.definitions;

import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.CoupleType;
import org.stringtemplate.v4.ST;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Stream;

public class SetDefinitions {
    private final Map<String, SetDefinition> setDefinitions = new HashMap<>();
    private final ST relNameGenerator;

    public SetDefinitions(ST typeNameTemplate) {
        this.relNameGenerator = typeNameTemplate;
    }

    public void addDefinition(SetDefinition definition) {
        if (!containsDefinition(definition.getSetType())) {
            setDefinitions.put(definition.getSetType().toString(), definition);
        } else {
            throw new RuntimeException("Definition for the given type already exists!");
        }
    }

    public boolean containsDefinition(BType type) {
        //EnumeratedSetElementType and others does not implement hash
        return setDefinitions.containsKey(type.toString());
        /*for (BType key : setDefinitions.keySet()) {
            if(key.toString().equals(type.toString())) return true;
        }
        return false;*/
    }
    public Stream<SetDefinition> getSetDefinitions() { return setDefinitions.values().stream(); }

    public SetDefinition getDefinition(BType type) {
        //EnumeratedSetElementType does not implement hash
        return setDefinitions.get(type.toString());
        /*for (Map.Entry<BType, SetDefinition> entry : setDefinitions.entrySet()) {
            if (entry.getKey().equals(type)) return entry.getValue();
        }
        return null;*/
    }

    private String getRelationName(CoupleType type) {
        this.relNameGenerator.remove("leftType");
        this.relNameGenerator.remove("rightType");
        this.relNameGenerator.add("leftType", getDefinition(type.getLeft()).getName());
        this.relNameGenerator.add("rightType", getDefinition(type.getRight()).getName());
        return this.relNameGenerator.render();
    }
}
