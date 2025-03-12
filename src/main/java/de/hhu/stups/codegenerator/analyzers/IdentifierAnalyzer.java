package de.hhu.stups.codegenerator.analyzers;

import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.expression.IfExpressionNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.expression.LetExpressionNode;
import de.prob.parser.ast.nodes.expression.NumberNode;
import de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode;
import de.prob.parser.ast.nodes.expression.RealNumberNode;
import de.prob.parser.ast.nodes.expression.RecordFieldAccessNode;
import de.prob.parser.ast.nodes.expression.RecordNode;
import de.prob.parser.ast.nodes.expression.SetComprehensionNode;
import de.prob.parser.ast.nodes.expression.StringNode;
import de.prob.parser.ast.nodes.expression.StructNode;
import de.prob.parser.ast.nodes.ltl.LTLBPredicateNode;
import de.prob.parser.ast.nodes.ltl.LTLInfixOperatorNode;
import de.prob.parser.ast.nodes.ltl.LTLKeywordNode;
import de.prob.parser.ast.nodes.ltl.LTLPrefixOperatorNode;
import de.prob.parser.ast.nodes.predicate.CastPredicateExpressionNode;
import de.prob.parser.ast.nodes.predicate.IdentifierPredicateNode;
import de.prob.parser.ast.nodes.predicate.IfPredicateNode;
import de.prob.parser.ast.nodes.predicate.LetPredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import de.prob.parser.ast.nodes.predicate.QuantifiedPredicateNode;
import de.prob.parser.ast.nodes.substitution.AnySubstitutionNode;
import de.prob.parser.ast.nodes.substitution.AssignSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.BecomesElementOfSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.BecomesSuchThatSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ChoiceSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ConditionSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.IfOrSelectSubstitutionsNode;
import de.prob.parser.ast.nodes.substitution.LetSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ListSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.OperationCallSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.SkipSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.VarSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.WhileSubstitutionNode;
import de.prob.parser.ast.visitors.AbstractVisitor;

import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * Created by fabian on 08.12.21.
 */
public class IdentifierAnalyzer implements AbstractVisitor<Void, Void> {

    public enum Kind {
        WRITE, READ, READ_OUTER_SCOPE
    }

    private Kind kind;

    private Set<String> identifiers;

    private Set<String> innerIdentifiers;

    public IdentifierAnalyzer(Kind kind) {
        this.kind = kind;
        this.identifiers = new HashSet<>();
        this.innerIdentifiers = new HashSet<>();
    }

    @Override
    public Void visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    /*
    * This function checks whether the given identifier is primed. If yes, then it is added to the list of primed identifiers
    */
    @Override
    public Void visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
        if(kind == Kind.READ_OUTER_SCOPE) {
            if(!innerIdentifiers.contains(node.getName())) {
                identifiers.add(node.getName());
            }
            return null;
        }
        identifiers.add(node.getName());
        return null;
    }

    @Override
    public Void visitCastPredicateExpressionNode(CastPredicateExpressionNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), expected);
        return null;
    }

    @Override
    public Void visitNumberNode(NumberNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitRealNumberNode(RealNumberNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitQuantifiedExpressionNode(QuantifiedExpressionNode node, Void expected) {
        Set<String> previousInnerIdentifiers = new HashSet<>(innerIdentifiers);
        previousInnerIdentifiers.addAll(node.getDeclarationList().stream()
                .map(DeclarationNode::getName)
                .collect(Collectors.toSet()));
        visitExprNode(node.getExpressionNode(), expected);
        visitPredicateNode(node.getPredicateNode(), expected);
        this.innerIdentifiers = previousInnerIdentifiers;
        return null;
    }

    @Override
    public Void visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
        Set<String> previousInnerIdentifiers = new HashSet<>(innerIdentifiers);
        previousInnerIdentifiers.addAll(node.getDeclarationList().stream()
                .map(DeclarationNode::getName)
                .collect(Collectors.toSet()));
        visitPredicateNode(node.getPredicateNode(), expected);
        this.innerIdentifiers = previousInnerIdentifiers;
        return null;
    }

    @Override
    public Void visitLambdaNode(LambdaNode node, Void expected) {
        Set<String> previousInnerIdentifiers = new HashSet<>(innerIdentifiers);
        previousInnerIdentifiers.addAll(node.getDeclarations().stream()
                .map(DeclarationNode::getName)
                .collect(Collectors.toSet()));
        visitPredicateNode(node.getPredicate(), expected);
        visitExprNode(node.getExpression(), expected);
        this.innerIdentifiers = previousInnerIdentifiers;
        return null;
    }

    @Override
    public Void visitLetExpressionNode(LetExpressionNode node, Void expected) {
        Set<String> previousInnerIdentifiers = new HashSet<>(innerIdentifiers);
        previousInnerIdentifiers.addAll(node.getLocalIdentifiers().stream()
                .map(DeclarationNode::getName)
                .collect(Collectors.toSet()));
        visitPredicateNode(node.getPredicate(), expected);
        visitExprNode(node.getExpression(), expected);
        this.innerIdentifiers = previousInnerIdentifiers;
        return null;
    }

    @Override
    public Void visitIfExpressionNode(IfExpressionNode node, Void expected) {
        visitPredicateNode(node.getCondition(), expected);
        visitExprNode(node.getThenExpression(), expected);
        visitExprNode(node.getElseExpression(), expected);
        return null;
    }

    @Override
    public Void visitStringNode(StringNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLPrefixOperatorNode(LTLPrefixOperatorNode ltlPrefixOperatorNode, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLKeywordNode(LTLKeywordNode ltlKeywordNode, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLInfixOperatorNode(LTLInfixOperatorNode ltlInfixOperatorNode, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLBPredicateNode(LTLBPredicateNode ltlbPredicateNode, Void expected) {
        return null;
    }

    @Override
    public Void visitIdentifierPredicateNode(IdentifierPredicateNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitPredicateOperatorNode(PredicateOperatorNode node, Void expected) {
        node.getPredicateArguments().forEach(pred -> visitPredicateNode(pred, expected));
        return null;
    }

    @Override
    public Void visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    @Override
    public Void visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void expected) {
        Set<String> previousInnerIdentifiers = new HashSet<>(innerIdentifiers);
        previousInnerIdentifiers.addAll(node.getDeclarationList().stream()
                .map(DeclarationNode::getName)
                .collect(Collectors.toSet()));
        visitPredicateNode(node.getPredicateNode(), expected);
        this.innerIdentifiers = previousInnerIdentifiers;
        return null;
    }

    @Override
    public Void visitLetPredicateNode(LetPredicateNode node, Void expected) {
        visitPredicateNode(node.getWherePredicate(), expected);
        visitPredicateNode(node.getPredicate(), expected);
        return null;
    }

    @Override
    public Void visitIfPredicateNode(IfPredicateNode node, Void expected) {
        visitPredicateNode(node.getCondition(), expected);
        visitPredicateNode(node.getThenPredicate(), expected);
        visitPredicateNode(node.getElsePredicate(), expected);
        return null;
    }

    @Override
    public Void visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
        visitSubstitutionNode(node.getBody(), expected);
        return null;
    }

    @Override
    public Void visitWhileSubstitutionNode(WhileSubstitutionNode node, Void expected) {
        if(kind == Kind.READ || kind == Kind.READ_OUTER_SCOPE) {
            visitPredicateNode(node.getCondition(), expected);
        }
        visitSubstitutionNode(node.getBody(), expected);
        return null;
    }

    @Override
    public Void visitListSubstitutionNode(ListSubstitutionNode node, Void expected) {
        node.getSubstitutions().forEach(substitution -> visitSubstitutionNode(substitution, expected));
        return null;
    }

    @Override
    public Void visitIfOrSelectSubstitutionsNode(IfOrSelectSubstitutionsNode node, Void expected) {
        if(kind == Kind.READ || kind == Kind.READ_OUTER_SCOPE) {
            node.getConditions().forEach(cond -> visitPredicateNode(cond, expected));
        }
        node.getSubstitutions().forEach(subs -> visitSubstitutionNode(subs, expected));
        if(node.getElseSubstitution() != null) {
            visitSubstitutionNode(node.getElseSubstitution(), expected);
        }
        return null;
    }

    @Override
    public Void visitAssignSubstitutionNode(AssignSubstitutionNode node, Void expected) {
        if(kind == Kind.WRITE) {
            node.getLeftSide().forEach(lhs -> visitExprNode(lhs, expected));
        } else {
            node.getLeftSide().forEach(lhs -> {
                if(lhs instanceof ExpressionOperatorNode) {
                    ExpressionOperatorNode.ExpressionOperator operator = ((ExpressionOperatorNode) lhs).getOperator();
                    if(operator == ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL) {
                        visitExprNode(lhs, expected);
                    }
                }
            });
            node.getRightSide().forEach(rhs -> visitExprNode(rhs, expected));
        }
        return null;
    }

    @Override
    public Void visitSkipSubstitutionNode(SkipSubstitutionNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitConditionSubstitutionNode(ConditionSubstitutionNode node, Void expected) {
        if(kind == Kind.READ || kind == Kind.READ_OUTER_SCOPE) {
            visitPredicateNode(node.getCondition(), expected);
        }
        visitSubstitutionNode(node.getSubstitution(), expected);
        return null;
    }

    @Override
    public Void visitAnySubstitution(AnySubstitutionNode node, Void expected) {
        if(kind == Kind.READ || kind == Kind.READ_OUTER_SCOPE) {
            visitPredicateNode(node.getWherePredicate(), expected);
        }
        visitSubstitutionNode(node.getThenSubstitution(), expected);
        return null;
    }

    @Override
    public Void visitLetSubstitution(LetSubstitutionNode node, Void expected) {
        if(kind == Kind.READ || kind == Kind.READ_OUTER_SCOPE) {
            visitPredicateNode(node.getPredicate(), expected);
        }
        visitSubstitutionNode(node.getBody(), expected);
        return null;
    }

    @Override
    public Void visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void expected) {
        if(kind == Kind.WRITE) {
            identifiers.addAll(node.getIdentifiers().stream()
                    .map(IdentifierExprNode::toString)
                    .collect(Collectors.toList()));
        } else {
            visitExprNode(node.getExpression(), expected);
        }
        return null;
    }

    @Override
    public Void visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void expected) {
        if(kind == Kind.WRITE) {
            identifiers.addAll(node.getIdentifiers().stream()
                    .map(IdentifierExprNode::toString)
                    .collect(Collectors.toList()));
        } else {
            visitPredicateNode(node.getPredicate(), expected);
        }
        return null;
    }

    @Override
    public Void visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
        if(kind == Kind.READ || kind == Kind.READ_OUTER_SCOPE) {
            node.getArguments().forEach(arg -> visitExprNode(arg, expected));
        }
        return null;
    }

    @Override
    public Void visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
        node.getSubstitutions().forEach(substitution -> visitSubstitutionNode(substitution, expected));
        return null;
    }

    @Override
    public Void visitRecordNode(RecordNode node, Void expected) {
        node.getExpressions().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    @Override
    public Void visitStructNode(StructNode node, Void expected) {
        node.getExpressions().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    @Override
    public Void visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
        visitExprNode(node.getRecord(), expected);
        return null;
    }

    public Set<String> getIdentifiers() {
        return identifiers;
    }

    public boolean containsIdentifier(String name) {
        return identifiers.contains(name);
    }

    public void setInnerIdentifiers(Set<String> innerIdentifiers) {
        this.innerIdentifiers = innerIdentifiers;
    }
}
