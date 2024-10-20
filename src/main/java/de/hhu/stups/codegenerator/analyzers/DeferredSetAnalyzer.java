package de.hhu.stups.codegenerator.analyzers;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import de.prob.parser.ast.SourceCodePosition;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.expression.NumberNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * Created by fabian on 06.06.19.
 */
public class DeferredSetAnalyzer {

    private final int defaultSetSize;

    private final Map<String, Integer> setToSize;

    private final Map<String, List<String>> setToEnumeratedElements;

    private final List<String> deferredSetsWithDefaultSize;

    public DeferredSetAnalyzer(int defaultSetSize) {
        this.defaultSetSize = defaultSetSize;
        this.setToSize = new HashMap<>();
        this.setToEnumeratedElements = new HashMap<>();
        this.deferredSetsWithDefaultSize = new ArrayList<>();
    }

    /*
    * This function analyzes the given list of deferred sets with the given predicate representing a PROPERTIES clause
    */
    public void analyze(List<DeclarationNode> deferredSets, PredicateNode properties) {
        if(properties == null || !isConjunction(properties)) {
            setDefaultSizeForDeferredSets(deferredSets);
        } else {
            analyzeDeferredSets(deferredSets, properties);
        }
    }

    /*
    * This function checks whether the given predicate is a conjunction
    */
    private boolean isConjunction(PredicateNode predicate) {
        if(predicate instanceof PredicateOperatorNode) {
            PredicateOperatorNode predicateOperatorNode = ((PredicateOperatorNode) predicate);
            if(predicateOperatorNode.getOperator() != PredicateOperatorNode.PredicateOperator.AND) {
                return false;
            }
        }
        return true;
    }

    /*
    * This function sets the default set size for a deferred set for the given list of deferred sets
    */
    private void setDefaultSizeForDeferredSets(List<DeclarationNode> deferredSets) {
        for (DeclarationNode deferredSet : deferredSets) {
            setToSize.put(deferredSet.getName(), getDefaultSetSize());
        }
    }

    /*
    * This function extracts the size and enumerated elements of the given list of deferred sets with the help of the given predicate representing the PROPERTIES clause
    */
    private void analyzeDeferredSets(List<DeclarationNode> deferredSets, PredicateNode properties) {
        for (DeclarationNode deferredSet : deferredSets) {
            analyzeSize(deferredSet, properties);
            analyzeEnumeratedElements(deferredSet, properties);
        }
    }

    /*
    * This function extracts the size of the given deferred set with the given predicate representing the PROPERTIES clause
    */
    private void analyzeSize(DeclarationNode deferredSet, PredicateNode properties) {
        if(properties instanceof PredicateOperatorWithExprArgsNode) {
            analyzeSize(deferredSet, (PredicateOperatorWithExprArgsNode) properties);
        } else if(properties instanceof PredicateOperatorNode) {
            analyzeSize(deferredSet, (PredicateOperatorNode) properties);
        }
    }

    /*
    * This function extracts the size of the given deferred set with the given predicate as PredicateOperatorWithExprArgsNode representing the PROPERTIES clause
    */
    private void analyzeSize(DeclarationNode deferredSet, PredicateOperatorWithExprArgsNode properties) {
        if(isRelevantSizeConjunct(deferredSet, properties)) {
            int size = extractSizeFromConjunct(deferredSet, properties);
            setToSize.put(deferredSet.getName(), size);
        } else {
            setToSize.put(deferredSet.getName(), getDefaultSetSize());
            deferredSetsWithDefaultSize.add(deferredSet.getName());
        }
    }

    /*
    * This function extracts the size of the given deferred set with the given predicate as PredicateOperatorNode representing the PROPERTIES clause
    */
    private void analyzeSize(DeclarationNode deferredSet, PredicateOperatorNode properties) {
        for (PredicateNode conjunct: properties.getPredicateArguments()) {
            if(isRelevantSizeConjunct(deferredSet, conjunct)) {
                int size = extractSizeFromConjunct(deferredSet, conjunct);
                setToSize.put(deferredSet.getName(), size);
                return;
            }
        }
        setToSize.put(deferredSet.getName(), getDefaultSetSize());
        deferredSetsWithDefaultSize.add(deferredSet.getName());
    }

    /*
    * This function extracts the enumerated elements of the given deferred set with the given predicate representing the PROPERTIES clause.
    * Finally, it checks the enumerated elements for correctness.
    */
    private void analyzeEnumeratedElements(DeclarationNode deferredSet, PredicateNode properties) {
        if(properties instanceof PredicateOperatorWithExprArgsNode) {
            analyzeEnumeratedElements(deferredSet, (PredicateOperatorWithExprArgsNode) properties);
        } else if(properties instanceof PredicateOperatorNode) {
            analyzeEnumeratedElements(deferredSet, (PredicateOperatorNode) properties);
        }
        checkEnumeratedElements(deferredSet);
    }

    /*
    * This function extracts the enumerated elements of the given deferred set with the given predicate as PredicateOperatorWithExprArgsNode representing the PROPERTIES clause.
    */
    private void analyzeEnumeratedElements(DeclarationNode deferredSet, PredicateOperatorWithExprArgsNode properties) {
        if(isRelevantEnumeratedSetConjunct(deferredSet, properties)) {
            List<String> enumeratedElements = extractEnumeratedElements(deferredSet, properties);
            setToEnumeratedElements.put(deferredSet.getName(), enumeratedElements);
        }
    }

    /*
    * This function extracts the enumerated elements of the given deferred set with the given predicate as PredicateOperatorNode representing the PROPERTIES clause.
    */
    private void analyzeEnumeratedElements(DeclarationNode deferredSet, PredicateOperatorNode properties) {
        for (PredicateNode conjunct: properties.getPredicateArguments()) {
            if(isRelevantEnumeratedSetConjunct(deferredSet, conjunct)) {
                List<String> enumeratedElements = extractEnumeratedElements(deferredSet, conjunct);
                setToEnumeratedElements.put(deferredSet.getName(), enumeratedElements);
                return;
            }
        }
    }

    /*
    * This function checks the size and enumerated elements of the given deferred set.
    */
    private void checkEnumeratedElements(DeclarationNode deferredSet) {
        String name = deferredSet.getName();
        if(setToEnumeratedElements.containsKey(name) && deferredSetsWithDefaultSize.contains(name)) {
            SourceCodePosition position = deferredSet.getSourceCodePosition();
            throw new CodeGenerationException("Declaration of deferred set as enumerated set must contain a conjunct ensuring the number of the set being equal to number of the enumeration at line:" + position.getStartLine() + " and column: " + position.getStartColumn());
        }
    }

    /*
    * This function checks whether the enumerated elements of the given deferred set is declared by an enumeration
    */
    public boolean isDeclaredByEnumeration(DeclarationNode node) {
        return setToEnumeratedElements.containsKey(node.getName());
    }

    /*
    * This function checks whether the given predicate is a relevant conjunct for extracting the size of the given deferred set
    */
    public boolean isRelevantSizeConjunct(DeclarationNode deferredSet, PredicateNode predicate) {
        if(predicate instanceof PredicateOperatorWithExprArgsNode) {
            PredicateOperatorWithExprArgsNode pred = (PredicateOperatorWithExprArgsNode) predicate;
            if(pred.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL) {
                ExprNode lhs = pred.getExpressionNodes().get(0);
                ExprNode rhs = pred.getExpressionNodes().get(1);
                if(lhs instanceof ExpressionOperatorNode) {
                    ExpressionOperatorNode lhsExpression = (ExpressionOperatorNode) lhs;
                    if(lhsExpression.getOperator() == ExpressionOperatorNode.ExpressionOperator.CARD) {
                        ExprNode set = lhsExpression.getExpressionNodes().get(0);
                        if(set instanceof IdentifierExprNode && ((IdentifierExprNode) set).getName().equals(deferredSet.getName())) {
                            if(rhs instanceof NumberNode) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    /*
    * This function checks whether the given predicate is a relevant conjunct for extracting the enumerated elements of the given deferred set
    */
    private boolean isRelevantEnumeratedSetConjunct(DeclarationNode deferredSet, PredicateNode predicate) {
        if(predicate instanceof PredicateOperatorWithExprArgsNode) {
            PredicateOperatorWithExprArgsNode pred = (PredicateOperatorWithExprArgsNode) predicate;
            if(pred.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL) {
                ExprNode lhs = pred.getExpressionNodes().get(0);
                ExprNode rhs = pred.getExpressionNodes().get(1);
                if(lhs instanceof IdentifierExprNode && ((IdentifierExprNode) lhs).getName().equals(deferredSet.getName())) {
                    if(rhs instanceof ExpressionOperatorNode && ((ExpressionOperatorNode) rhs).getOperator() == ExpressionOperatorNode.ExpressionOperator.SET_ENUMERATION) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    /*
    * This function extracts the size of the given deferred set from the given predicate
    */
    private int extractSizeFromConjunct(DeclarationNode deferredSet, PredicateNode predicate) {
        if(predicate instanceof PredicateOperatorWithExprArgsNode) {
            PredicateOperatorWithExprArgsNode pred = (PredicateOperatorWithExprArgsNode) predicate;
            if(pred.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL) {
                ExprNode lhs = pred.getExpressionNodes().get(0);
                ExprNode rhs = pred.getExpressionNodes().get(1);
                if(lhs instanceof ExpressionOperatorNode) {
                    ExpressionOperatorNode lhsExpression = (ExpressionOperatorNode) lhs;
                    if(lhsExpression.getOperator() == ExpressionOperatorNode.ExpressionOperator.CARD) {
                        ExprNode set = lhsExpression.getExpressionNodes().get(0);
                        if(set instanceof IdentifierExprNode && ((IdentifierExprNode) set).getName().equals(deferredSet.getName())) {
                            if(rhs instanceof NumberNode) {
                                return ((NumberNode) rhs).getValue().intValue();
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }

    /*
    * This function extracts the enumerated elements of the given deferred set from the given predicate
    */
    private List<String> extractEnumeratedElements(DeclarationNode deferredSet, PredicateNode predicate) {
        if(predicate instanceof PredicateOperatorWithExprArgsNode) {
            PredicateOperatorWithExprArgsNode pred = (PredicateOperatorWithExprArgsNode) predicate;
            if(pred.getOperator() == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL) {
                ExprNode lhs = pred.getExpressionNodes().get(0);
                ExprNode rhs = pred.getExpressionNodes().get(1);
                if(lhs instanceof IdentifierExprNode && ((IdentifierExprNode) lhs).getName().equals(deferredSet.getName())) {
                    if(rhs instanceof ExpressionOperatorNode && ((ExpressionOperatorNode) rhs).getOperator() == ExpressionOperatorNode.ExpressionOperator.SET_ENUMERATION) {
                        return ((ExpressionOperatorNode) rhs).getExpressionNodes()
                                .stream()
                                .map(element -> ((IdentifierExprNode) element).getName())
                                .collect(Collectors.toList());
                    }
                }
            }
        }
        return null;
    }

    /*
    * This function returns the size of the given deferred set represented by a DeclarationNode
    */
    public int getSetSize(DeclarationNode node) {
        return setToSize.get(node.getName());
    }

    /*
    * This function returns the enumerated elements of the given deferred set represented by a DeclarationNode
    */
    public List<String> getElements(DeclarationNode node) {
        return setToEnumeratedElements.get(node.getName());
    }

    private int getDefaultSetSize() {
        return defaultSetSize;
    }
}
