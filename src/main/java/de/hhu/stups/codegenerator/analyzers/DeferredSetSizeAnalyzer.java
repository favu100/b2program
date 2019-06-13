package de.hhu.stups.codegenerator.analyzers;

import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.expression.NumberNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;

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
        if(properties == null || !isConjunction(properties)) {
            for (DeclarationNode deferredSet : deferredSets) {
                setToSize.put(deferredSet.getName(), getDefaultSetSize());
            }
        } else {
            for (DeclarationNode deferredSet : deferredSets) {
                analyze(deferredSet, properties);
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

    private void analyze(DeclarationNode deferredSet, PredicateNode properties) {
        if(properties instanceof PredicateOperatorWithExprArgsNode) {
            if(isRelevantConjunct(deferredSet, properties)) {
                int size = extractSizeFromConjunct(deferredSet, properties);
                setToSize.put(deferredSet.getName(), size);
            } else {
                setToSize.put(deferredSet.getName(), getDefaultSetSize());
            }
        } else if(properties instanceof PredicateOperatorNode) {
            PredicateOperatorNode predicate = (PredicateOperatorNode) properties;
            for (PredicateNode conjunct: predicate.getPredicateArguments()) {
                if(isRelevantConjunct(deferredSet, conjunct)) {
                    int size = extractSizeFromConjunct(deferredSet, conjunct);
                    setToSize.put(deferredSet.getName(), size);
                    return;
                }
            }
            setToSize.put(deferredSet.getName(), getDefaultSetSize());
        }
    }

    private boolean isRelevantConjunct(DeclarationNode deferredSet, PredicateNode predicate) {
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

    public int getSetSize(DeclarationNode node) {
        return setToSize.get(node.getName());
    }

    private int getDefaultSetSize() {
        return defaultSetSize;
    }
}
