package de.hhu.stups.codegenerator.generators;


import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.EnumeratedSetElementNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.Node;
import de.prob.parser.ast.nodes.OperatorNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.expression.IfExpressionNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.expression.LetExpressionNode;
import de.prob.parser.ast.nodes.expression.NumberNode;
import de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode;
import de.prob.parser.ast.nodes.expression.RecordFieldAccessNode;
import de.prob.parser.ast.nodes.expression.RecordNode;
import de.prob.parser.ast.nodes.expression.SetComprehensionNode;
import de.prob.parser.ast.nodes.expression.StringNode;
import de.prob.parser.ast.nodes.expression.StructNode;
import de.prob.parser.ast.nodes.predicate.CastPredicateExpressionNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.CoupleType;
import de.prob.parser.ast.types.IntegerType;
import de.prob.parser.ast.types.SetType;
import de.prob.parser.ast.types.UntypedType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.BOOL;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.CARD;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.CARTESIAN_PRODUCT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.CLOSURE;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.CLOSURE1;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.COMPOSITION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.CONC;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.CONCAT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.COUPLE;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.DIRECT_PRODUCT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.DIVIDE;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.DOMAIN;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.DOMAIN_RESTRICTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.DOMAIN_SUBTRACTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.FALSE;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.FIN;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.FIN1;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.FIRST;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.FNC;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.FRONT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.GENERALIZED_INTER;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.GENERALIZED_UNION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.ID;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.INSERT_FRONT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.INSERT_TAIL;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.INT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.INTERSECTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.INTERVAL;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.INVERSE_RELATION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.ISEQ;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.ISEQ1;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.ITERATE;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.LAST;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.MAX;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.MAXINT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.MIN;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.MININT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.MINUS;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.MOD;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.MULT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.NAT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.NAT1;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.OVERWRITE_RELATION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.PARALLEL_PRODUCT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.PARTIAL_BIJECTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.PARTIAL_FUNCTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.PARTIAL_INJECTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.PARTIAL_SURJECTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.PERM;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.PLUS;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.POW;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.POW1;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.POWER_OF;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.PRED;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.PRJ1;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.PRJ2;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.RANGE;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.RANGE_RESTRICTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.RANGE_SUBTRACTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.REL;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.RELATIONAL_IMAGE;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.RESTRICT_FRONT;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.RESTRICT_TAIL;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.REV;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.SEQ;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.SEQ1;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.SEQ_ENUMERATION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.SET_ENUMERATION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.SET_RELATION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.SET_SUBTRACTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.SIZE;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.SUCC;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.TAIL;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.TOTAL_BIJECTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.TOTAL_FUNCTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.TOTAL_INJECTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.TOTAL_RELATION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION_RELATION;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.TRUE;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.UNARY_MINUS;
import static de.prob.parser.ast.nodes.expression.ExpressionOperatorNode.ExpressionOperator.UNION;

public class ExpressionGenerator {

    /*
    * Hard-coded lists for identifying the type of the operators for expression
    */
    private static final Set<ExpressionOperatorNode.ExpressionOperator> BINARY_EXPRESSION_OPERATORS =
            new HashSet<>(Arrays.asList(PLUS,MINUS,MULT,DIVIDE,MOD, POWER_OF, INTERSECTION, UNION, SET_SUBTRACTION, RELATIONAL_IMAGE,
                    OVERWRITE_RELATION, DOMAIN_RESTRICTION, DOMAIN_SUBTRACTION,
                    RANGE_RESTRICTION, RANGE_SUBTRACTION, DIRECT_PRODUCT, PARALLEL_PRODUCT, COMPOSITION, TOTAL_BIJECTION, TOTAL_FUNCTION, TOTAL_INJECTION,
                    TOTAL_RELATION, TOTAL_SURJECTION, TOTAL_SURJECTION_RELATION, PARTIAL_BIJECTION, PARTIAL_FUNCTION, PARTIAL_INJECTION,
                    PARTIAL_SURJECTION, INSERT_FRONT, INSERT_TAIL, RESTRICT_FRONT, RESTRICT_TAIL, CONCAT));

    private static final Set<ExpressionOperatorNode.ExpressionOperator> UNARY_EXPRESSION_OPERATORS =
            new HashSet<>(Arrays.asList(UNARY_MINUS, PRED, SUCC, CARD, DOMAIN, RANGE, CLOSURE, CLOSURE1, ITERATE, INVERSE_RELATION, FNC, REL, MIN, MAX, FIN, FIN1, POW, POW1, GENERALIZED_UNION, GENERALIZED_INTER,
                    FIRST, LAST, FRONT, TAIL, CONC, SEQ, SEQ1, ISEQ, ISEQ1, PERM, SIZE, REV));

    private static final Set<ExpressionOperatorNode.ExpressionOperator> EXPRESSION_BOOLEANS =
            new HashSet<>(Arrays.asList(TRUE,FALSE));

    private final GeneratorMode mode;

    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final NameHandler nameHandler;

    private final boolean useBigInteger;

    private final String minint;

    private final String maxint;

    private final ImportGenerator importGenerator;

    private final DeclarationGenerator declarationGenerator;

    private final IdentifierGenerator identifierGenerator;

    private final TypeGenerator typeGenerator;

    private final RecordStructGenerator recordStructGenerator;

    private SubstitutionGenerator substitutionGenerator;

    private OperatorGenerator operatorGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    public ExpressionGenerator(final GeneratorMode mode, final STGroup currentGroup, final MachineGenerator machineGenerator, boolean useBigInteger, String minint, String maxint, final NameHandler nameHandler,
                               final ImportGenerator importGenerator, final DeclarationGenerator declarationGenerator,
                               final IdentifierGenerator identifierGenerator, final TypeGenerator typeGenerator,
                               final IterationConstructHandler iterationConstructHandler, final RecordStructGenerator recordStructGenerator) {
        this.mode = mode;
        this.currentGroup = currentGroup;
        this.machineGenerator = machineGenerator;
        this.useBigInteger = useBigInteger;
        this.minint = minint;
        this.maxint = maxint;
        this.nameHandler = nameHandler;
        this.importGenerator = importGenerator;
        this.declarationGenerator = declarationGenerator;
        this.identifierGenerator = identifierGenerator;
        this.typeGenerator = typeGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationConstructHandler.setExpressionGenerator(this);
        this.recordStructGenerator = recordStructGenerator;
    }

    /*
     * This function generates code from an expression in B and tracks if the node is a parameter.
     * This is important for expressions in Prolog.
     */
    public String visitExprNode(ExprNode node, boolean isParameter) {
        if (!isParameter) return visitExprNode(node);
        importGenerator.addImport(node.getType());

        if (node instanceof ExpressionOperatorNode) {
            return visitExprOperatorNode((ExpressionOperatorNode) node, true);
        }
        return visitExprNode(node);
    }

    /*
    * This function generates code from an expression in B.
    */
    public String visitExprNode(ExprNode node) {
        importGenerator.addImport(node.getType());
        if (node instanceof NumberNode) {
            return visitNumberNode((NumberNode) node);
        } else if(node instanceof StringNode) {
            return visitStringNode((StringNode) node);
        } else if (node instanceof ExpressionOperatorNode) {
            return visitExprOperatorNode((ExpressionOperatorNode) node);
        } else if (node instanceof EnumeratedSetElementNode) {
            EnumeratedSetElementNode element = (EnumeratedSetElementNode) node;
            return declarationGenerator.callEnum(element.getType().toString(), element.getDeclarationNode());
        } else if(node instanceof IdentifierExprNode) {
            Map<String, List<String>> enumTypes = nameHandler.getEnumTypes();
            //This is the case where the name of an enumerated set element is returned as an IdentifierExprNode
            String nodeName = ((IdentifierExprNode) node).getName();
            String[] nodeNameAsList = nodeName.split("\\.");
            if((enumTypes.containsKey(node.getType().toString()) &&
                    enumTypes.get(node.getType().toString()).contains(nodeNameAsList[nodeNameAsList.length - 1]))) {
                return declarationGenerator.callEnum(node.getType().toString(), ((IdentifierExprNode) node).getDeclarationNode());
            }
            return visitIdentifierExprNode((IdentifierExprNode) node);
        } else if(node instanceof CastPredicateExpressionNode) {
            return visitCastPredicateExpressionNode((CastPredicateExpressionNode) node);
        } else if(node instanceof QuantifiedExpressionNode) {
            return visitQuantifiedExpressionNode((QuantifiedExpressionNode) node);
        } else if(node instanceof SetComprehensionNode) {
            return visitSetComprehensionNode((SetComprehensionNode) node);
        } else if(node instanceof LambdaNode) {
            return visitLambdaNode((LambdaNode) node);
        } else if(node instanceof IfExpressionNode) {
            return visitIfExpressionNode((IfExpressionNode) node);
        } else if(node instanceof LetExpressionNode) {
            return visitLetExpressionNode((LetExpressionNode) node);
        } else if(node instanceof RecordNode) {
            return visitRecordNode((RecordNode) node);
        } else if(node instanceof StructNode) {
            return "";
        } else if(node instanceof RecordFieldAccessNode) {
            return visitRecordFieldAccessNode((RecordFieldAccessNode) node);
        }
        throw new RuntimeException("Given node is not implemented: " + node.getClass() + " at line " + node.getSourceCodePosition().getStartLine());
    }

    /*
     * This function generates code for an expression and tracks if the node is a method parameter.
     */
    public String visitExprOperatorNode(ExpressionOperatorNode node, boolean isParameter) {
        if (!isParameter) return visitExprOperatorNode(node);
        if(checkTupleProjections(node)) {
            return generateTupleProjection(node);
        }
        return generateExpression(node, true);
    }

    /*
    * This function generates code for an expression.
    */
    public String visitExprOperatorNode(ExpressionOperatorNode node) {
        if(checkTupleProjections(node)) {
            return generateTupleProjection(node);
        }
        return generateExpression(node);
    }

    /*
    * This function checks whether the given expression node is a couple projection
    */
    private boolean checkTupleProjections(ExpressionOperatorNode node) {
        if(node.getOperator() == FUNCTION_CALL) {
            ExprNode first = node.getExpressionNodes().get(0);
            if(first instanceof ExpressionOperatorNode) {
                ExpressionOperatorNode.ExpressionOperator operator = ((ExpressionOperatorNode) first).getOperator();
                return operator == PRJ1 || operator == PRJ2;
            }
        }
        return false;
    }

    /*
    * This function generates code for an identifier from the belonging AST node.
    */
    public String visitIdentifierExprNode(IdentifierExprNode node) {
        if(machineGenerator.getInfiniteSets().contains(node.getName())) {
            throw new CodeGenerationException("Infinite Set Declarations are not supported: " + node.getName() + " at line " + node.getSourceCodePosition().getStartLine() + " column " + node.getSourceCodePosition().getStartColumn());
        }
        if(node.isPrimed()) {
            String prefix = machineGenerator.getMode().equals(GeneratorMode.PL) ? "PL" : "";
            return prefix + "_primed_" + node.getName();
        }
        if(machineGenerator.isInIterationConstruct() && machineGenerator.getBoundedVariablesDepth().containsKey(node.getName())) {
            String prefix = machineGenerator.getMode().equals(GeneratorMode.PL) ? "PL" : "";
            return prefix + "_ic_" + node.getName() + "_" + machineGenerator.getBoundedVariablesDepth().get(node.getName());
        }
        if(substitutionGenerator.getCurrentLocalScope() > 0 && identifierGenerator.getCurrentLocals().containsKey(node.getName())) {
            boolean isAssigned = identifierGenerator.isAssigned(node, node.getParent());
            boolean isParam = node.getDeclarationNode() != null && DeclarationNode.Kind.OP_INPUT_PARAMETER.equals(node.getDeclarationNode().getKind());
            return identifierGenerator.generateVarDeclaration(node.getName(), isAssigned, isParam);
        }
        return identifierGenerator.generate(node);
    }

    /*
    * This function generates code for numbers from the belonging AST node and the belonging template
    */
    public String visitNumberNode(NumberNode node) {
        ST number = currentGroup.getInstanceOf("number");
        TemplateHandler.add(number, "number", node.getValue().toString());
        TemplateHandler.add(number, "useBigInteger", useBigInteger);
        return number.render();
    }

    /*
    * This function generates code for a string from the given StringNode and the belonging template
    */
    public String visitStringNode(StringNode node) {
        ST number = currentGroup.getInstanceOf("string");
        TemplateHandler.add(number, "string", node.getValue());
        return number.render();
    }

    /*
    * This function generates code for cast predicates
    */
    public String visitCastPredicateExpressionNode(CastPredicateExpressionNode node) {
        return machineGenerator.visitPredicateNode(node.getPredicate(), null);
    }

    public String visitEnumIdentifier(Node node) {
        List<ExprNode> expressionNodes;
        if (node instanceof PredicateOperatorWithExprArgsNode) {
            expressionNodes = ((PredicateOperatorWithExprArgsNode) node).getExpressionNodes();
        }
        else if (node instanceof ExpressionOperatorNode) {
            expressionNodes = ((ExpressionOperatorNode) node).getExpressionNodes();
        }
        else {
            return "";
        }

        List<String> exprOpNodes = new ArrayList<>();
        List<String> expressionList = new ArrayList<>();
        for (ExprNode n : expressionNodes) {
            if (n instanceof ExpressionOperatorNode) {
                List<ExprNode> identifier = ((ExpressionOperatorNode) n).getExpressionNodes().stream().filter(exp -> machineGenerator.getEnumIdentifier().contains(exp.toString())).collect(Collectors.toList());
                if (!identifier.isEmpty()) {
                    for (ExprNode id : identifier) {
                        ST assignment = currentGroup.getInstanceOf("enum_assignment");
                        TemplateHandler.add(assignment, "identifier", id.toString());
                        TemplateHandler.add(assignment, "ExprCount", machineGenerator.getAndIncCurrentExpressionCount());
                        exprOpNodes.add(visitExprNode(n, true));
                        expressionList.add("Expr_" + (machineGenerator.getCurrentExpressionCount()-1));
                    }
                } else {
                    String s = machineGenerator.visitExprOperatorNode((ExpressionOperatorNode) n, null);
                    if (machineGenerator.getCurrentExpressionCount() == 0 && !s.contains("=") && (!s.contains("(") || isNoMethod(s))) { // is not assignment or method call
                        expressionList.add(s);
                    } else {
                        exprOpNodes.add(s);
                        expressionList.add("Expr_" + (machineGenerator.getCurrentExpressionCount()-1));
                    }
                }
            } else if (n instanceof IdentifierExprNode && machineGenerator.getEnumIdentifier().contains(n.toString())) {
                ST assignment = currentGroup.getInstanceOf("enum_assignment");
                TemplateHandler.add(assignment, "identifier", n.toString());
                TemplateHandler.add(assignment, "ExprCount", machineGenerator.getAndIncCurrentExpressionCount());
                exprOpNodes.add(assignment.render());
                expressionList.add("Expr_" + (machineGenerator.getCurrentExpressionCount()-1));
            } else {
                expressionList.add(machineGenerator.visitExprNode(n, null));
            }
        }
        return operatorGenerator.generateBinary(((OperatorNode<?>) node)::getOperator, expressionList, machineGenerator, exprOpNodes);
    }

    private boolean isNoMethod(String s) {
        return s.contains("interval") || s.contains("bSet");
    }

    /*
     * This function generates code for an expression with the given AST node and the list of expressions within the expression.
     * It is also tracked whether the node is a method parameter.
     */
    public String generateExpression(ExpressionOperatorNode node, boolean isParameter) {
        if (!isParameter) return generateExpression(node);

        if(node.getOperator() == SET_ENUMERATION) {
            List<String> expressionList = node.getExpressionNodes().stream().map(n -> visitExprNode(n, true)).collect(Collectors.toList());
            return generateSetEnumeration(node.getType(), expressionList, true);
        } else if(node.getOperator() == SEQ_ENUMERATION) {
            List<String> expressionList = node.getExpressionNodes().stream().map(n -> visitExprNode(n, true)).collect(Collectors.toList());
            return generateSeqEnumeration(node.getType(), expressionList, true);
        } else if(BINARY_EXPRESSION_OPERATORS.contains(node.getOperator())) {
            if (mode == GeneratorMode.PL) {
                return machineGenerator.visitEnumIdentifier(node);
            } else {
                List<String> expressionList = node.getExpressionNodes().stream().map(this::visitExprNode).collect(Collectors.toList());
                return operatorGenerator.generateBinary(node::getOperator, expressionList, machineGenerator);
            }
        }
        return generateExpression(node);
    }

    /*
    * This function generates code for an expression with the given AST node and the list of expressions within the expression.
    */
    public String generateExpression(ExpressionOperatorNode node) {
        ExpressionOperatorNode.ExpressionOperator operator = node.getOperator();
        if(BINARY_EXPRESSION_OPERATORS.contains(operator)) {
            if (mode == GeneratorMode.PL) {
                return machineGenerator.visitEnumIdentifier(node);
            } else {
                List<String> expressionList = node.getExpressionNodes().stream().map(this::visitExprNode).collect(Collectors.toList());
                return operatorGenerator.generateBinary(node::getOperator, expressionList, machineGenerator);
            }
        } else if(UNARY_EXPRESSION_OPERATORS.contains(operator)) {
            List<String> expressionList = node.getExpressionNodes().stream().map(this::visitExprNode).collect(Collectors.toList());
            boolean isRelation = node.getType() instanceof SetType && ((SetType) node.getType()).getSubType() instanceof CoupleType;
            return generateUnaryExpression(operator, expressionList, isRelation);
        } else if(EXPRESSION_BOOLEANS.contains(operator)) {
            return generateBoolean(operator);
        } else if(node.getOperator() == SET_ENUMERATION) {
            List<String> expressionList = node.getExpressionNodes().stream().map(this::visitExprNode).collect(Collectors.toList());
            return generateSetEnumeration(node.getType(), expressionList);
        } else if(node.getOperator() == SEQ_ENUMERATION) {
            List<String> expressionList = node.getExpressionNodes().stream().map(this::visitExprNode).collect(Collectors.toList());
            return generateSeqEnumeration(node.getType(), expressionList);
        } else if(node.getOperator() == INTERVAL) {
            List<String> expressionList = node.getExpressionNodes().stream().map(this::visitExprNode).collect(Collectors.toList());
            return generateInterval(expressionList);
        } else if(node.getOperator() == PRJ1 || node.getOperator() == PRJ2) {
            List<String> expressionList = node.getExpressionNodes().stream().map(this::visitExprNode).collect(Collectors.toList());
            return generateProjection(node.getOperator(), ((SetType) node.getExpressionNodes().get(0).getType()).getSubType(), ((SetType) node.getExpressionNodes().get(1).getType()).getSubType(), expressionList);
        } else if(node.getOperator() == ID) {
            List<String> expressionList = node.getExpressionNodes().stream().map(this::visitExprNode).collect(Collectors.toList());
            return generateIdentity(expressionList, ((SetType) node.getExpressionNodes().get(0).getType()).getSubType());
        } else if(node.getOperator() == CARTESIAN_PRODUCT) {
            List<String> expressionList = node.getExpressionNodes().stream().map(this::visitExprNode).collect(Collectors.toList());
            return generateCartesianProduct(expressionList, ((SetType) node.getExpressionNodes().get(0).getType()).getSubType(), ((SetType) node.getExpressionNodes().get(1).getType()).getSubType());
        } else if(node.getOperator() == COUPLE) {
            List<String> expressionList = node.getExpressionNodes().stream().map(this::visitExprNode).collect(Collectors.toList());
            return generateTuple(expressionList, node.getExpressionNodes().get(0).getType(), node.getExpressionNodes().get(1).getType());
        } else if(node.getOperator() == FUNCTION_CALL) {
            return generateFunctionCall(node.getExpressionNodes());
        } else if(node.getOperator() == SET_RELATION) {
            ExpressionOperatorNode cartesianProductNode = new ExpressionOperatorNode(node.getSourceCodePosition(), node.getExpressionNodes(), CARTESIAN_PRODUCT);
            return generateExpression(new ExpressionOperatorNode(node.getSourceCodePosition(), Collections.singletonList(cartesianProductNode), POW));
        } else if(node.getOperator() == BOOL) {
            return generateBooleans();
        } else if(node.getOperator() == MININT) {
            return generateMinInt();
        } else if(node.getOperator() == MAXINT) {
            return generateMaxInt();
        } else if(node.getOperator() == INT) {
            return generateInt();
        } else if(node.getOperator() == NAT) {
            return generateNat();
        } else if(node.getOperator() == NAT1) {
            return generateNat1();
        }
        throw new CodeGenerationException("Given operator is not supported: " + node.getOperator() + " at line " + node.getSourceCodePosition().getStartLine() + " column " + node.getSourceCodePosition().getStartColumn());
    }

    /*
    * This function generates code for an unary expression with the given operator and arguments.
    */
    private String generateUnaryExpression(ExpressionOperatorNode.ExpressionOperator operator, List<String> expressionList, boolean isRelation) {
        ST expression = generateUnary(operator, isRelation);
        if (mode == GeneratorMode.PL) {
            if (machineGenerator.getEnumIdentifier().contains(expressionList.get(0))) {
                List<String> exprOpNodes = new ArrayList<>();
                ST assignment = currentGroup.getInstanceOf("enum_assignment");
                TemplateHandler.add(assignment, "identifier", expressionList.get(0));
                exprOpNodes.add(assignment.render());
                TemplateHandler.add(expression, "obj", "Expr_" + machineGenerator.getCurrentExpressionCount());
                TemplateHandler.add(assignment, "ExprCount", machineGenerator.getAndIncCurrentExpressionCount());
                TemplateHandler.add(expression, "exprBefore", exprOpNodes);
            } else {
                TemplateHandler.add(expression, "exprBefore", expressionList);
                TemplateHandler.add(expression, "parameterEvaluated", true);
                TemplateHandler.add(expression, "obj", (machineGenerator.getCurrentExpressionCount() - 1));
            }
        } else {
            TemplateHandler.add(expression, "obj", expressionList.get(0));
        }
        TemplateHandler.add(expression, "args", expressionList.subList(1, expressionList.size()));
        TemplateHandler.add(expression, "exprCount", machineGenerator.getAndIncCurrentExpressionCount());
        TemplateHandler.add(expression, "stateCount", machineGenerator.getCurrentStateCount());
        return expression.render();
    }

    /*
    * This function gets the template for unary expressions and replaces the placeholder with the given operator.
    */
    private ST generateUnary(ExpressionOperatorNode.ExpressionOperator operator, boolean isRelation) {
        ST template = currentGroup.getInstanceOf("unary");
        boolean isOverloadedOperator = false; // indicates if the unary-operator has a binary equivalent, used for languages that don't support method overloading (like rust)
        String operatorName;
        switch (operator) {
            case UNARY_MINUS:
                operatorName = "negative";
                break;
            case PRED:
                operatorName = "pred";
                break;
            case SUCC:
                operatorName = "succ";
                break;
            case CARD:
                operatorName = "card";
                break;
            case DOMAIN:
                operatorName = isRelation ? "domainForRelations" : "domain";
                break;
            case RANGE:
                operatorName = isRelation ? "rangeForRelations" : "range";
                break;
            case CLOSURE:
                operatorName = "closure";
                break;
            case CLOSURE1:
                operatorName = "closure1";
                break;
            case ITERATE:
                operatorName = "iterate";
                break;
            case INVERSE_RELATION:
                operatorName = "inverse";
                break;
            case FNC:
                operatorName = "fnc";
                break;
            case REL:
                operatorName = "rel";
                break;
            case MIN:
                operatorName = "min";
                break;
            case MAX:
                operatorName = "max";
                break;
            case POW:
                operatorName = "pow";
                break;
            case POW1:
                operatorName = "pow1";
                break;
            case FIN:
                operatorName = "fin";
                break;
            case FIN1:
                operatorName = "fin1";
                break;
            case GENERALIZED_UNION:
                operatorName = isRelation ? "unionForRelations" : "unionForSets";
                isOverloadedOperator = true;
                break;
            case GENERALIZED_INTER:
                operatorName = isRelation ? "intersectForRelations" : "intersectForSets";
                isOverloadedOperator = true;
                break;
            case FIRST:
                operatorName = "first";
                break;
            case LAST:
                operatorName = "last";
                break;
            case FRONT:
                operatorName = "front";
                break;
            case TAIL:
                operatorName = "tail";
                break;
            case CONC:
                operatorName = "conc";
                break;
            case SEQ:
            case SEQ1:
            case ISEQ:
            case ISEQ1:
            case PERM:
                throw new CodeGenerationException("Operator only supported in element of: " + operator);
            case SIZE:
                operatorName = "size";
                break;
            case REV:
                operatorName = "reverse";
                break;
            default:
                throw new RuntimeException("Given operator is not implemented: " + operator);
        }
        TemplateHandler.add(template, "operator", nameHandler.handle(operatorName));
        TemplateHandler.add(template, "isOverloadedOperator", isOverloadedOperator);
        return template;
    }

    /*
    * This function gets the template for binary expressions and replaces the placeholder with the given operator.
    */
    public ST generateBinary(ExpressionOperatorNode.ExpressionOperator operator) {
        ST template = currentGroup.getInstanceOf("binary");
        String operatorName;
        switch(operator) {
            case PLUS:
                operatorName = "plus";
                break;
            case MINUS:
                operatorName = "minus";
                break;
            case MULT:
                operatorName = "multiply";
                break;
            case DIVIDE:
                operatorName = "divide";
                break;
            case MOD:
                operatorName = "modulo";
                break;
            case POWER_OF:
                operatorName = "power";
                break;
            case INTERSECTION:
                operatorName = "intersect";
                break;
            case UNION:
                operatorName = "union";
                break;
            case SET_SUBTRACTION:
                operatorName = "difference";
                break;
            case RELATIONAL_IMAGE:
                operatorName = "relationImage";
                break;
            case OVERWRITE_RELATION:
                operatorName = "override";
                break;
            case DOMAIN_RESTRICTION:
                operatorName = "domainRestriction";
                break;
            case DOMAIN_SUBTRACTION:
                operatorName = "domainSubstraction";
                break;
            case RANGE_RESTRICTION:
                operatorName = "rangeRestriction";
                break;
            case RANGE_SUBTRACTION:
                operatorName = "rangeSubstraction";
                break;
            case DIRECT_PRODUCT:
                operatorName = "directProduct";
                break;
            case PARALLEL_PRODUCT:
                operatorName = "parallelProduct";
                break;
            case COMPOSITION:
                operatorName = "composition";
                break;
            case TOTAL_FUNCTION:
            case TOTAL_BIJECTION:
            case TOTAL_INJECTION:
            case TOTAL_SURJECTION:
            case TOTAL_RELATION:
            case TOTAL_SURJECTION_RELATION:
            case PARTIAL_BIJECTION:
            case PARTIAL_SURJECTION:
            case PARTIAL_FUNCTION:
            case PARTIAL_INJECTION:
                throw new CodeGenerationException("Operator only supported in element of: " + operator + " at ");
            case INSERT_FRONT:
                operatorName = "prepend";
                break;
            case INSERT_TAIL:
                operatorName = "append";
                break;
            case RESTRICT_FRONT:
                operatorName = "take";
                break;
            case RESTRICT_TAIL:
                operatorName = "drop";
                break;
            case CONCAT:
                operatorName = "concat";
                break;
            default:
                throw new RuntimeException("Given operator is not implemented: " + operator);
        }
        TemplateHandler.add(template, "operator", nameHandler.handle(operatorName));
        return template;
    }

    /*
    * This function generates code for an interval with the given arguments.
    */
    private String generateInterval(List<String> arguments) {
        ST interval = currentGroup.getInstanceOf("interval");
        TemplateHandler.add(interval, "arg1", arguments.get(0));
        TemplateHandler.add(interval, "arg2", arguments.get(1));
        return interval.render();
    }

    /*
    * This function generates code for a function call
    */
    private String generateFunctionCall(List<ExprNode> expressions) {
        ST functionCall;
        ExprNode lhs = expressions.get(0);
        ExprNode argument = getArgumentFromExpressions(expressions.subList(1, expressions.size()));
        Set<String> lambdaFunctions = machineGenerator.getLambdaFunctions();
        if(lhs instanceof IdentifierExprNode && lambdaFunctions.contains(((IdentifierExprNode) lhs).getName())) {
            List<String> arguments = new ArrayList<>();
            getExpressionsFromArgument(argument, arguments);
            functionCall = currentGroup.getInstanceOf("lambda_function_call");
            boolean fromOtherMachine = !((IdentifierExprNode) lhs).getDeclarationNode().getSurroundingMachineNode().equals(machineGenerator.getMachineNode());
            MachineNode otherMachine = ((IdentifierExprNode) lhs).getDeclarationNode().getSurroundingMachineNode();
            TemplateHandler.add(functionCall, "otherMachine", nameHandler.handleIdentifier(otherMachine.getPrefix() != null ? otherMachine.getPrefix() : otherMachine.getName(), NameHandler.IdentifierHandlingEnum.MACHINES));
            TemplateHandler.add(functionCall, "fromOtherMachine", fromOtherMachine);
            TemplateHandler.add(functionCall, "arg1", nameHandler.handleIdentifier(((IdentifierExprNode) lhs).getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
            TemplateHandler.add(functionCall, "arg2", arguments);
        } else {
            functionCall = currentGroup.getInstanceOf("binary");
            TemplateHandler.add(functionCall, "arg1", machineGenerator.visitExprNode(lhs, null));
            TemplateHandler.add(functionCall, "operator", "functionCall");
            TemplateHandler.add(functionCall, "arg2", machineGenerator.visitExprNode(argument, null));
        }
        return functionCall.render();
    }

    /*
    * This function gets the argument of a function call from a list of expression nodes.
    */
    public ExprNode getArgumentFromExpressions(List<ExprNode> expressions) {
        ExprNode result = expressions.get(0);
        for(int i = 1; i < expressions.size(); i++) {
            ExprNode rhsElement = expressions.get(i);
            BType leftType = result.getType();
            result = new ExpressionOperatorNode(result.getSourceCodePosition(), Arrays.asList(result, rhsElement), ExpressionOperatorNode.ExpressionOperator.COUPLE);
            result.setType(new CoupleType(leftType, rhsElement.getType()));
        }
        return result;
    }

    public void getExpressionsFromArgument(ExprNode node, List<String> result) {
        if(node instanceof ExpressionOperatorNode && ((ExpressionOperatorNode) node).getOperator() == COUPLE) {
            List<ExprNode> expressions = ((ExpressionOperatorNode) node).getExpressionNodes();
            ExprNode lhs = expressions.get(0);
            ExprNode rhs = expressions.get(1);
            getExpressionsFromArgument(lhs, result);
            getExpressionsFromArgument(rhs, result);
            return;
        }
        result.add(machineGenerator.visitExprNode(node, null));
    }

    /*
    * This function generates code for a projection function from the given semantic information
    */
    private String generateProjection(ExpressionOperatorNode.ExpressionOperator operator, BType domainType, BType rangeType, List<String> arguments) {
        ST projection = currentGroup.getInstanceOf("projection");
        TemplateHandler.add(projection, "domainType", typeGenerator.generate(domainType));
        TemplateHandler.add(projection, "rangeType", typeGenerator.generate(rangeType));
        TemplateHandler.add(projection, "arg1", arguments.get(0));
        TemplateHandler.add(projection, "arg2", arguments.get(1));
        TemplateHandler.add(projection, "isProjection1", operator == PRJ1);
        return projection.render();
    }


    /*
    * This function generates code for calling projection on a tuple directly
    */
    private String generateTupleProjection(ExpressionOperatorNode node) {
        ST projection = currentGroup.getInstanceOf("projection_tuple");
        ExpressionOperatorNode function = (ExpressionOperatorNode) node.getExpressionNodes().get(0);
        TemplateHandler.add(projection, "arg", visitExprNode(node.getExpressionNodes().get(1)));
        TemplateHandler.add(projection, "isProjection1", function.getOperator() == PRJ1);
        return projection.render();
    }

    /*
    * This function generates code for identity function from the given semantic information
    */
    private String generateIdentity(List<String> expressionList, BType type) {
        ST identity = currentGroup.getInstanceOf("identity");
        if(type instanceof CoupleType) {
            TemplateHandler.add(identity, "leftType", typeGenerator.generate(((CoupleType) type).getLeft()));
            TemplateHandler.add(identity, "rightType", typeGenerator.generate(((CoupleType) type).getRight()));
        }
        TemplateHandler.add(identity, "type", typeGenerator.generate(type));
        TemplateHandler.add(identity, "arg", expressionList.get(0));
        TemplateHandler.add(identity, "relationalArg", type instanceof CoupleType);
        return identity.render();
    }

    /*
    * This function generates code for cartesian product from the given semantic information
    */
    private String generateCartesianProduct(List<String> expressionList, BType leftType, BType rightType) {
        ST identity = currentGroup.getInstanceOf("cartesian_product");
        TemplateHandler.add(identity, "leftType", typeGenerator.generate(leftType));
        TemplateHandler.add(identity, "rightType", typeGenerator.generate(rightType));
        TemplateHandler.add(identity, "stateCount", machineGenerator.getCurrentStateCount());
        TemplateHandler.add(identity, "arg1", expressionList.get(0));
        TemplateHandler.add(identity, "arg2", expressionList.get(1));
        TemplateHandler.add(identity, "exprCount", machineGenerator.getAndIncCurrentExpressionCount());
        return identity.render();
    }

    /*
    * This function generates code for a tuple with the given arguments.
    */
    public String generateTuple(List<String> arguments, BType leftType, BType rightType) {
        ST tuple = currentGroup.getInstanceOf("tuple_create");
        TemplateHandler.add(tuple, "leftType", typeGenerator.generate(leftType));
        TemplateHandler.add(tuple, "rightType", typeGenerator.generate(rightType));
        TemplateHandler.add(tuple, "arg1", arguments.get(0));
        TemplateHandler.add(tuple, "arg2", arguments.get(1));
        return tuple.render();
    }

    /*
     * This function generates code for set enumerations with the given arguments and checks if the node is a method parameter.
     */
    private String generateSetEnumeration(BType type, List<String> expressions, boolean isParameter) {
        ST enumeration = currentGroup.getInstanceOf("set_enumeration");
        BType subType = ((SetType) type).getSubType();
        TemplateHandler.add(enumeration,"enums", expressions);
        if(subType instanceof CoupleType) {
            TemplateHandler.add(enumeration, "leftType", typeGenerator.generate(((CoupleType) subType).getLeft()));
            TemplateHandler.add(enumeration, "rightType", typeGenerator.generate(((CoupleType) subType).getRight()));
        } else if(!(subType instanceof UntypedType)) { // subType is a type other than couple type and void type
            TemplateHandler.add(enumeration, "type", typeGenerator.generate(subType));
        }
        TemplateHandler.add(enumeration, "isRelation", subType instanceof CoupleType);
        TemplateHandler.add(enumeration, "exprCount", machineGenerator.getAndIncCurrentExpressionCount());
        TemplateHandler.add(enumeration, "isParameter", isParameter);
        return enumeration.render();
    }

    /*
    * This function generates code for set enumerations with the given arguments.
    */
    private String generateSetEnumeration(BType type, List<String> expressions) {
        ST enumeration = currentGroup.getInstanceOf("set_enumeration");
        BType subType = ((SetType) type).getSubType();
        TemplateHandler.add(enumeration,"enums", expressions);
        if(subType instanceof CoupleType) {
            TemplateHandler.add(enumeration, "leftType", typeGenerator.generate(((CoupleType) subType).getLeft()));
            TemplateHandler.add(enumeration, "rightType", typeGenerator.generate(((CoupleType) subType).getRight()));
        } else if(!(subType instanceof UntypedType)) { // subType is a type other than couple type and void type
            TemplateHandler.add(enumeration, "type", typeGenerator.generate(subType));
        }
        TemplateHandler.add(enumeration, "isRelation", subType instanceof CoupleType);
        TemplateHandler.add(enumeration, "exprCount", machineGenerator.getAndIncCurrentExpressionCount());
        return enumeration.render();
    }

    /*
     * This function generates code for sequence enumeration from the given semantic information
     */
    private String generateSeqEnumeration(BType type, List<String> expressions, boolean isParameter) {
        ST enumeration = currentGroup.getInstanceOf("seq_enumeration");
        BType subType = ((SetType) type).getSubType();
        BType rhsType = ((CoupleType) subType).getRight();
        List<String> tuples = new ArrayList<>();
        if(expressions.size() > 0) {
            importGenerator.addImport(new CoupleType(new UntypedType(), new UntypedType()));
        }
        importGenerator.addImport(IntegerType.getInstance());
        for(int i = 1; i <= expressions.size(); i++) {
            ST number = currentGroup.getInstanceOf("number");
            TemplateHandler.add(number, "number", String.valueOf(i));
            TemplateHandler.add(number, "useBigInteger", useBigInteger);
            String lhs = number.render();
            tuples.add(generateTuple(Arrays.asList(lhs, expressions.get(i-1)), IntegerType.getInstance(), rhsType));
        }
        TemplateHandler.add(enumeration,"elements", tuples);
        TemplateHandler.add(enumeration, "type", typeGenerator.generate(rhsType));
        TemplateHandler.add(enumeration, "isParameter", isParameter);
        return enumeration.render();
    }

    /*
    * This function generates code for sequence enumeration from the given semantic information
    */
    private String generateSeqEnumeration(BType type, List<String> expressions) {
        ST enumeration = currentGroup.getInstanceOf("seq_enumeration");
        BType subType = ((SetType) type).getSubType();
        BType rhsType = ((CoupleType) subType).getRight();
        List<String> tuples = new ArrayList<>();
        if(expressions.size() > 0) {
            importGenerator.addImport(new CoupleType(new UntypedType(), new UntypedType()));
        }
        importGenerator.addImport(IntegerType.getInstance());
        for(int i = 1; i <= expressions.size(); i++) {
            ST number = currentGroup.getInstanceOf("number");
            TemplateHandler.add(number, "number", String.valueOf(i));
            TemplateHandler.add(number, "useBigInteger", useBigInteger);
            String lhs = number.render();
            tuples.add(generateTuple(Arrays.asList(lhs, expressions.get(i-1)), IntegerType.getInstance(), rhsType));
        }
        TemplateHandler.add(enumeration,"elements", tuples);
        TemplateHandler.add(enumeration, "type", typeGenerator.generate(rhsType));
        return enumeration.render();
    }

    /*
    * This function generates code for boolean constants as expressions.
    */
    private String generateBoolean(ExpressionOperatorNode.ExpressionOperator operator) {
        ST val = currentGroup.getInstanceOf("boolean_val");
        TemplateHandler.add(val, "val", operator == TRUE);
        return val.render();
    }

    /*
    * This function generates code for quantified expressions by invoking pre-generated code from IterationConstructHandler
    */
    public String visitQuantifiedExpressionNode(QuantifiedExpressionNode node) {
        return iterationConstructHandler.getIterationsMapIdentifier().get(node.toString());
    }

    /*
    * This function generates code for set comprehensions by invoking pre-generated code from IterationConstructHandler
    */
    public String visitSetComprehensionNode(SetComprehensionNode node) {
        return iterationConstructHandler.getIterationsMapIdentifier().get(node.toString());
    }

    /*
    * This function generates code for lambda expressions by invoking pre-generated code from IterationConstructHandler
    */
    public String visitLambdaNode(LambdaNode node) {
        return iterationConstructHandler.getIterationsMapIdentifier().get(node.toString());
    }

    /*
    * This functon generates code for if expressions.
    */
    public String visitIfExpressionNode(IfExpressionNode node) {
        ST template = currentGroup.getInstanceOf("if_expression_predicate");
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(node.getCondition(), null));
        TemplateHandler.add(template, "ifThen", machineGenerator.visitExprNode(node.getThenExpression(), null));
        TemplateHandler.add(template, "ifElse", machineGenerator.visitExprNode(node.getElseExpression(), null));
        return template.render();
    }

    /*
    * This function generates code for let expressions by invoking pre-generated code from IterationConstructHandler
    */
    public String visitLetExpressionNode(LetExpressionNode node) {
        return iterationConstructHandler.getIterationsMapIdentifier().get(node.toString());
    }

    /*
    * This function generates code for BOOL
    */
    private String generateBooleans() {
        return currentGroup.getInstanceOf("bool").render();
    }

    /*
    * This function generates code for MININT
    */
    public String generateMinInt() {
        ST number = currentGroup.getInstanceOf("number");
        TemplateHandler.add(number, "number", minint);
        TemplateHandler.add(number, "useBigInteger", useBigInteger);
        return number.render();
    }

    /*
     * This function generates code for 0
     */
    private String generateZero() {
        ST number = currentGroup.getInstanceOf("number");
        TemplateHandler.add(number, "number", 0);
        TemplateHandler.add(number, "useBigInteger", useBigInteger);
        return number.render();
    }

    /*
     * This function generates code for 0
     */
    private String generateOne() {
        ST number = currentGroup.getInstanceOf("number");
        TemplateHandler.add(number, "number", 1);
        TemplateHandler.add(number, "useBigInteger", useBigInteger);
        return number.render();
    }

    /*
    * This function generates code for MAXINT
    */
    public String generateMaxInt() {
        ST number = currentGroup.getInstanceOf("number");
        TemplateHandler.add(number, "number", maxint);
        TemplateHandler.add(number, "useBigInteger", useBigInteger);
        return number.render();
    }

    /*
    * This function generates code for INT
    */
    private String generateInt() {
        ST interval = currentGroup.getInstanceOf("interval");
        TemplateHandler.add(interval, "arg1", generateMinInt());
        TemplateHandler.add(interval, "arg2", generateMaxInt());
        return interval.render();
    }

    /*
     * This function generates code for NAT
     */
    private String generateNat() {
        ST interval = currentGroup.getInstanceOf("interval");
        TemplateHandler.add(interval, "arg1", generateZero());
        TemplateHandler.add(interval, "arg2", generateMaxInt());
        return interval.render();
    }

    /*
     * This function generates code for NAT1
     */
    private String generateNat1() {
        ST interval = currentGroup.getInstanceOf("interval");
        TemplateHandler.add(interval, "arg1", generateOne());
        TemplateHandler.add(interval, "arg2", generateMaxInt());
        return interval.render();
    }

    /*
    * This function generates code for a record by invoking the belonging function in RecordStructGenerator
    */
    private String visitRecordNode(RecordNode node) {
        return recordStructGenerator.visitRecordNode(node);
    }

    /*
    * This function generates code for a record field access by invoking the belonging function in RecordStructGenerator
    */
    private String visitRecordFieldAccessNode(RecordFieldAccessNode node) {
        return recordStructGenerator.visitRecordFieldAccessNode(node);
    }

    public void setOperatorGenerator(OperatorGenerator operatorGenerator) {
        this.operatorGenerator = operatorGenerator;
    }

    public void setSubstitutionGenerator(SubstitutionGenerator substitutionGenerator) {
        this.substitutionGenerator = substitutionGenerator;
    }

    public NameHandler getNameHandler() {
        return this.nameHandler;
    }

    public boolean isUseBigInteger() {
        return useBigInteger;
    }
}
