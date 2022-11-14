package de.hhu.stups.codegenerator.definitions;

import de.prob.parser.ast.types.BType;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class SetDefinition {

    private String name;
    private final BType setType;
    private final List<String> elements;
    private List<List<String>> subSets = null;
    private List<boolean[]> subSetVecs = null;

    public SetDefinition(BType setType, List<String> elements) {
        this.setType = setType;
        this.elements = elements;
    }

    public void setVariations() {
        int maxCard = elements.size();
        //TODO: limit may become configurable?
        if (maxCard >= 12) throw new RuntimeException(String.format("Set %s is too large with its size of 2^%d", setType.toString(), maxCard));
        final int variantCount = (1 << maxCard);
        subSets = new ArrayList<>(variantCount);
        subSetVecs = new ArrayList<>(variantCount);
        subSets.add(0, new ArrayList<>());
        subSetVecs.add(0, new boolean[maxCard]);
        for (int i = 1; i < variantCount; i++) { //i is current subset as binary
            ArrayList<String> currentSubSet = new ArrayList<>(maxCard);
            boolean[] currentBitVec = new boolean[maxCard];
            for (int j = 0; j < maxCard; j++) {
                if ((i & (1 << j)) > 0) { //check if jth element is in subset
                    currentSubSet.add(elements.get(j));
                    currentBitVec[j] = true;
                }
            }
            subSets.add(i, currentSubSet);
            subSetVecs.add(i, currentBitVec);
        }
    }

    public String getName() { return this.name; }
    public void setName(String newName) { this.name = newName; }

    public BType getSetType() { return this.setType; }

    public List<String> getElements() { return this.elements; }
    public List<List<String>> getSubSets() {
        if (subSets == null) setVariations();
        return this.subSets;
    }

    public Map<Integer, String> elementsIndexed() {
        return listIndexed(elements);
    }

    public Map<Integer, List<String>> subSetsIndexed() { return listIndexed(getSubSets()); }

    public Map<Integer, boolean[]> subSetVecsIndexed() {
        if (subSetVecs == null) setVariations();
        return listIndexed(subSetVecs);
    }

    private <T> Map<Integer, T> listIndexed(List<T> list) {
        return IntStream.range(0, list.size()).boxed()
                .collect(Collectors.toMap(Function.identity(), list::get));
    }
    
    public List<String> toBitVec(List<String> containedElements) {
        return elements.stream().map(containedElements::contains).map(Object::toString).collect(Collectors.toList());
    }
}
