package de.hhu.stups.codegenerator.generators.iteration;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.OperatorGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.predicate.IdentifierPredicateNode;
import de.prob.parser.ast.nodes.predicate.IfPredicateNode;
import de.prob.parser.ast.nodes.predicate.LetPredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import de.prob.parser.ast.nodes.predicate.QuantifiedPredicateNode;
import de.prob.parser.ast.visitors.generic.ParametrisedPredicateVisitor;

public class ConstraintSolverPredicateGenerator implements ParametrisedPredicateVisitor<String, Void> {

  /*
   * Hard-coded lists for identifying the type of the operators for predicates
   */
  private static final List<PredicateOperatorNode.PredicateOperator> BINARY_PREDICATE_OPERATORS =
      Arrays.asList(PredicateOperatorNode.PredicateOperator.AND, PredicateOperatorNode.PredicateOperator.OR,
          PredicateOperatorNode.PredicateOperator.IMPLIES, PredicateOperatorNode.PredicateOperator.EQUIVALENCE);

  private static final List<PredicateOperatorNode.PredicateOperator> UNARY_PREDICATE_OPERATORS =
      Collections.singletonList(PredicateOperatorNode.PredicateOperator.NOT);

  private static final List<PredicateOperatorNode.PredicateOperator> PREDICATE_BOOLEANS =
      Arrays.asList(PredicateOperatorNode.PredicateOperator.TRUE, PredicateOperatorNode.PredicateOperator.FALSE);

  private static final List<ExpressionOperatorNode.ExpressionOperator> POWER_SET_EXPRESSIONS =
      Arrays.asList(ExpressionOperatorNode.ExpressionOperator.POW, ExpressionOperatorNode.ExpressionOperator.POW1, ExpressionOperatorNode.ExpressionOperator.FIN, ExpressionOperatorNode.ExpressionOperator.FIN1);



  private final MachineGenerator machineGenerator;
  private OperatorGenerator operatorGenerator;

  public ConstraintSolverPredicateGenerator(MachineGenerator machineGenerator,
                                            IterationConstructHandler iterationConstructHandler) {
    this.machineGenerator = machineGenerator;
    iterationConstructHandler.setConstraintSolverPredicateGenerator(this);
  }

  @Override
  public String visitIdentifierPredicateNode(IdentifierPredicateNode node, Void expected) {
    throw new RuntimeException("Given node is not implemented: " + node.getClass());
  }

  @Override
  public String visitPredicateOperatorNode(PredicateOperatorNode node, Void expected) {
    List<String> expressionList = node.getPredicateArguments().stream()
        .map(expr -> machineGenerator.visitPredicateNode(expr, null))
        .collect(Collectors.toList());
    return generatePredicate(node, expressionList);
  }

  @Override
  public String visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
    List<String> expressionList = node.getExpressionNodes().stream()
        .map(expr -> machineGenerator.visitExprNode(expr, null))
        .collect(Collectors.toList());
    return operatorGenerator.generateBinary(node::getOperator, expressionList);
  }

  @Override
  public String visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void expected) {
    //TODO
    throw new RuntimeException("Given node is not implemented: " + node.getClass());
  }

  @Override
  public String visitLetPredicateNode(LetPredicateNode node, Void expected) {
    //TODO
    throw new RuntimeException("Given node is not implemented: " + node.getClass());
  }

  @Override
  public String visitIfPredicateNode(IfPredicateNode node, Void expected) {
    //TODO
    throw new RuntimeException("Given node is not implemented: " + node.getClass());
  }

  /*
   * This function generates code for a predicate with the given AST node and the list of expressions within the predicate.
   */
  public String generatePredicate(PredicateOperatorNode node, List<String> expressionList) {
    PredicateOperatorNode.PredicateOperator operator = node.getOperator();
    if(BINARY_PREDICATE_OPERATORS.contains(operator)) {
      return operatorGenerator.generateBinary(() -> operator, expressionList);
    } else if(UNARY_PREDICATE_OPERATORS.contains(operator)) {
      return "";//generateUnaryPredicate(operator, expressionList);
    } else if(PREDICATE_BOOLEANS.contains(operator)) {
      return "";//generateBoolean(operator);
    }
    throw new RuntimeException("Given operator is not implemented: " + node.getOperator());
  }

  public void setOperatorGenerator(OperatorGenerator operatorGenerator) {
    this.operatorGenerator = operatorGenerator;
  }
}
