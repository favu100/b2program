package de.hhu.stups.codegenerator.analyzers;

import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by fabian on 06.06.19.
 */
public class DeferredSetSizeAnalyzer {

    private final int defaultSetSize;

    private final Map<String, Integer> setToSize;

    public DeferredSetSizeAnalyzer(int defaultSetSize) {
        this.defaultSetSize = defaultSetSize;
        this.setToSize = new HashMap<>();
    }

    public void analyze(List<DeclarationNode> deferredSets, PredicateNode properties) {

    }

    public int getSetSize(DeclarationNode node) {
        return setToSize.get(node.getName());
    }

    public int getDefaultSetSize() {
        return defaultSetSize;
    }
}
