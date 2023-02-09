package de.hhu.stups.codegenerator.definitions;

import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.SetType;
import org.stringtemplate.v4.ST;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/**
 * setType = POW(SomeSet) <=> elements : SomeSet
 * represents every subset of {@code setType}
 */
public class SetDefinition {

    private String name;
    private final BType setType;
    private final List<String> elements;

    private boolean isConstant = false;
    private List<List<String>> subSets = null;
    private List<boolean[]> subSetVecs = null;
    private Map<String, boolean[]> elementToBitArr = null;

    public SetDefinition(BType setType, List<String> elements) {
        this.setType = setType;
        this.elements = elements;
    }

    public SetDefinition(BType setType, List<String> elements, Map<String, boolean[]> elementToBitArr) {
        this.setType = setType;
        this.elements = elements;
        this.elementToBitArr = elementToBitArr;
    }

    public void setVariations() {
        throw new RuntimeException("should variation generation be done here?");
    }

    public SetDefinition getPowSetDefinition(ST setElementNameGenerator) {
        int maxCard = elements.size();
        //TODO: limit may become configurable?
        if (maxCard >= 12) throw new RuntimeException(String.format("Set %s is too large with its size of 2^%d", setType.toString(), maxCard));

        final int variantCount = (1 << maxCard);
        List<String> powElements = new ArrayList<>(variantCount);
        String emptySet = elementSetToSetElement(setElementNameGenerator, new ArrayList<>());
        powElements.add(emptySet);
        Map<String, boolean[]> powElementToBitArr = new HashMap<>();
        powElementToBitArr.put(emptySet, new boolean[maxCard]);

        for (int i = 1; i < variantCount; i++) { //i is current subset as binary
            ArrayList<String> currentSubSet = new ArrayList<>(maxCard);
            boolean[] currentBitVec = new boolean[maxCard];
            for (int j = 0; j < maxCard; j++) {
                if ((i & (1 << j)) > 0) { //check if jth element is in subset
                    currentSubSet.add(elements.get(j));
                    currentBitVec[j] = true;
                }
            }
            String elementName = elementSetToSetElement(setElementNameGenerator, currentSubSet);
            powElements.add(elementName);
            powElementToBitArr.put(elementName, currentBitVec);
        }

        return new SetDefinition(new SetType(this.setType), powElements, powElementToBitArr);
    }

    private String elementSetToSetElement(ST setElementNameGenerator, List<String> elementSet) {
        setElementNameGenerator.remove("elements");
        setElementNameGenerator.add("elements", elementSet);
        return setElementNameGenerator.render();
    }

    public String getName() { return this.name; }
    public void setName(String newName) { this.name = newName; }

    public BType getSetType() { return this.setType; }

    public List<String> getElements() { return this.elements; }
    public void addElement(String element, boolean[] bitArr) {
        if (!this.elements.contains(element)) {
            this.elements.add(element);
            this.elementToBitArr.put(element, bitArr);
        }
    }

    public boolean isConstant() { return this.isConstant; }
    public void makeConstant() {
        this.isConstant = true;
        this.elementToBitArr = new HashMap<>();
    }
    public List<List<String>> getSubSets() {
        if (subSets == null) setVariations();
        return this.subSets;
    }

    public Map<Integer, String> elementsIndexed() {
        return listIndexed(elements);
    }

    public Map<Integer, boolean[]> bitArrIndexed() {
        return elementsIndexed().keySet().stream().collect(Collectors.toMap(Function.identity(), idx -> elementToBitArr.get(elements.get(idx))));
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
