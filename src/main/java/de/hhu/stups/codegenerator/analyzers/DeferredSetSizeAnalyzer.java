package de.hhu.stups.codegenerator.analyzers;

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
public class DeferredSetSizeAnalyzer {

    private final int defaultSetSize;

    private final Map<String, Integer> setToSize;

    private final Map<String, List<String>> setToEnumeratedElements;

    private final List<String> deferredSetsWithDefaultSize;

    public DeferredSetSizeAnalyzer(int defaultSetSize) {
        this.defaultSetSize = defaultSetSize;
        this.setToSize = new HashMap<>();
        this.setToEnumeratedElements = new HashMap<>();
        this.deferredSetsWithDefaultSize = new ArrayList<>();
    }

    public void analyze(List<DeclarationNode> deferredSets, PredicateNode properties) {
        if(properties == null || !isConjunction(properties)) {
            for (DeclarationNode deferredSet : deferredSets) {
                setToSize.put(deferredSet.getName(), getDefaultSetSize());
            }
        } else {
            for (DeclarationNode deferredSet : deferredSets) {
                analyzeSize(deferredSet, properties);
                analyzeEnumeratedElements(deferredSet, properties);
            }
        }
    }

    private boolean isConjunction(PredicateNode predicate) {
        if(predicate instanceof PredicateOperatorNode) {
            PredicateOperatorNode predicateOperatorNode = ((PredicateOperatorNode) predicate);
            if(predicateOperatorNode.getOperator() != PredicateOperatorNode.PredicateOperator.AND) {
                return false;
            }
        }
        return true;
    }

    private void analyzeSize(DeclarationNode deferredSet, PredicateNode properties) {
        if(properties instanceof PredicateOperatorWithExprArgsNode) {
            if(isRelevantSizeConjunct(deferredSet, properties)) {
                int size = extractSizeFromConjunct(deferredSet, properties);
                setToSize.put(deferredSet.getName(), size);
            } else {
                setToSize.put(deferredSet.getName(), getDefaultSetSize());
                deferredSetsWithDefaultSize.add(deferredSet.getName());
            }
        } else if(properties instanceof PredicateOperatorNode) {
            PredicateOperatorNode predicate = (PredicateOperatorNode) properties;
            for (PredicateNode conjunct: predicate.getPredicateArguments()) {
                if(isRelevantSizeConjunct(deferredSet, conjunct)) {
                    int size = extractSizeFromConjunct(deferredSet, conjunct);
                    setToSize.put(deferredSet.getName(), size);
                    return;
                }
            }
            setToSize.put(deferredSet.getName(), getDefaultSetSize());
            deferredSetsWithDefaultSize.add(deferredSet.getName());
        }
    }

    private void analyzeEnumeratedElements(DeclarationNode deferredSet, PredicateNode properties) {
        if(properties instanceof PredicateOperatorWithExprArgsNode) {
            if(isRelevantEnumeratedSetConjunct(deferredSet, properties)) {
                List<String> enumeratedElements = extractEnumeratedElements(deferredSet, properties);
                setToEnumeratedElements.put(deferredSet.getName(), enumeratedElements);
            }
        } else if(properties instanceof PredicateOperatorNode) {
            PredicateOperatorNode predicate = (PredicateOperatorNode) properties;
            for (PredicateNode conjunct: predicate.getPredicateArguments()) {
                if(isRelevantEnumeratedSetConjunct(deferredSet, conjunct)) {
                    List<String> enumeratedElements = extractEnumeratedElements(deferredSet, conjunct);
                    setToEnumeratedElements.put(deferredSet.getName(), enumeratedElements);
                    return;
                }
            }
        }
        checkEnumeratedElements(deferredSet);
    }

    private void checkEnumeratedElements(DeclarationNode deferredSet) {
        String name = deferredSet.getName();
        if(setToEnumeratedElements.keySet().contains(name) && deferredSetsWithDefaultSize.contains(name)) {
            throw new RuntimeException("Declaration of deferred set as enumerated set must contain a conjunct ensuring the number of the set being equal to number of the enumeration");
        }
    }

    public boolean isDeclaredByEnumeration(DeclarationNode node) {
        return setToEnumeratedElements.containsKey(node.getName());
    }

    private boolean isRelevantSizeConjunct(DeclarationNode deferredSet, PredicateNode predicate) {
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

    public int getSetSize(DeclarationNode node) {
        return setToSize.get(node.getName());
    }

    public List<String> getElements(DeclarationNode node) {
        return setToEnumeratedElements.get(node.getName());
    }

    private int getDefaultSetSize() {
        return defaultSetSize;
    }
}
