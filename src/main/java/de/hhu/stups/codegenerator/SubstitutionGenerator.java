package de.hhu.stups.codegenerator;


import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.substitution.AssignSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.BecomesElementOfSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ChoiceSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.IfOrSelectSubstitutionsNode;
import de.prob.parser.ast.nodes.substitution.ListSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.OperationCallSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.SubstitutionNode;
import de.prob.parser.ast.nodes.substitution.VarSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.WhileSubstitutionNode;
import de.prob.parser.ast.types.BoolType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class SubstitutionGenerator {

    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private OperationGenerator operationGenerator;

    private final NameHandler nameHandler;

    private final TypeGenerator typeGenerator;

    private final DeclarationGenerator declarationGenerator;

    private final ExpressionGenerator expressionGenerator;

    private final IdentifierGenerator identifierGenerator;

    private final ImportGenerator importGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private int currentLocalScope;

    private int localScopes;

    private int parallelNestingLevel;

    public SubstitutionGenerator(final STGroup currentGroup, final MachineGenerator machineGenerator, final NameHandler nameHandler,
                                 final TypeGenerator typeGenerator, final DeclarationGenerator declarationGenerator, final ExpressionGenerator expressionGenerator,
                                 final IdentifierGenerator identifierGenerator, final ImportGenerator importGenerator,
                                 final IterationConstructHandler iterationConstructHandler) {
        this.currentGroup = currentGroup;
        this.machineGenerator = machineGenerator;
        this.nameHandler = nameHandler;
        this.typeGenerator = typeGenerator;
        this.declarationGenerator = declarationGenerator;
        this.expressionGenerator = expressionGenerator;
        this.expressionGenerator.setSubstitutionGenerator(this);
        this.identifierGenerator = identifierGenerator;
        this.importGenerator = importGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.currentLocalScope = 0;
        this.localScopes = 0;
        this.parallelNestingLevel = 0;
    }

    /*
    * This function generates code for the initialization for the given AST node of the machine.
    */
    public String visitInitialization(MachineNode node) {
        ST initialization = currentGroup.getInstanceOf("initialization");
        TemplateHandler.add(initialization, "machine", nameHandler.handle(node.getName()));
        TemplateHandler.add(initialization, "machines", node.getMachineReferences().stream()
                .map(reference -> nameHandler.handle(reference.getMachineNode().getName()))
                .collect(Collectors.toList()));
        TemplateHandler.add(initialization, "constants_initializations", declarationGenerator.generateConstantsInitializations(node));
        TemplateHandler.add(initialization, "body", machineGenerator.visitSubstitutionNode(node.getInitialisation(), null));
        return initialization.render();
    }

    /*
    * This function generates code for if substitutions and select substitutions from the belonging AST node.
    */
    public String visitIfOrSelectSubstitutionsNode(IfOrSelectSubstitutionsNode node) {
        if (node.getOperator() == IfOrSelectSubstitutionsNode.Operator.SELECT) {
            return visitSelectSubstitution(node);
        }
        return visitIfSubstitution(node);
    }

    /*
    * This function generates code for select substitutions from the belonging AST node and the belonging template.
    */
    private String visitSelectSubstitution(IfOrSelectSubstitutionsNode node) {
        ST select = currentGroup.getInstanceOf("select");
        TemplateHandler.add(select, "iterationConstruct", iterationConstructHandler.inspectPredicates(node.getConditions()).getIterationsMapCode().values());
        TemplateHandler.add(select, "predicate", machineGenerator.visitPredicateNode(node.getConditions().get(0), null));
        TemplateHandler.add(select, "then", machineGenerator.visitSubstitutionNode(node.getSubstitutions().get(0), null));
        return select.render();
    }

    /*
    * This function generates code for if substitutions with and without else-branches from the belonging AST node and the belonging template.
    */
    private String visitIfSubstitution(IfOrSelectSubstitutionsNode node) {
        ST ifST = currentGroup.getInstanceOf("if");
        TemplateHandler.add(ifST, "iterationConstruct", iterationConstructHandler.inspectPredicates(node.getConditions()).getIterationsMapCode().values());

        TemplateHandler.add(ifST, "predicate", machineGenerator.visitPredicateNode(node.getConditions().get(0), null));
        TemplateHandler.add(ifST, "then", machineGenerator.visitSubstitutionNode(node.getSubstitutions().get(0), null));
        TemplateHandler.add(ifST, "else1", generateElseIfs(node));

        if (node.getElseSubstitution() != null) {
            TemplateHandler.add(ifST, "else1", generateElse(node));
        }
        return ifST.render();
    }

    /*
    * This function generates code from the else if branches with the belonging AST node.
    */
    private List<String> generateElseIfs(IfOrSelectSubstitutionsNode node) {
        List<String> conditions = node.getConditions().subList(1, node.getConditions().size()).stream()
                .map(condition -> machineGenerator.visitPredicateNode(condition, null))
                .collect(Collectors.toList());
        List<String> then = node.getSubstitutions().subList(1, node.getSubstitutions().size()).stream()
                .map(substitutionNode -> machineGenerator.visitSubstitutionNode(substitutionNode, null))
                .collect(Collectors.toList());

        List<String> elseIfs = new ArrayList<>();

        for (int i = 0; i < conditions.size(); i++) {
            ST elseST = currentGroup.getInstanceOf("elseif");
            TemplateHandler.add(elseST, "predicate", conditions.get(i));
            TemplateHandler.add(elseST, "then", then.get(i));
            elseIfs.add(elseST.render());
        }

        return elseIfs;
    }

    /*
    * This function generates code from the else branch from the belonging AST node.
    */
    private String generateElse(IfOrSelectSubstitutionsNode node) {
        ST elseST = currentGroup.getInstanceOf("else");
        TemplateHandler.add(elseST, "then", machineGenerator.visitSubstitutionNode(node.getElseSubstitution(), null));
        return elseST.render();
    }


    public String visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
        ST choice = currentGroup.getInstanceOf("choice");
        int length = node.getSubstitutions().size();
        List<SubstitutionNode> substitutions = node.getSubstitutions();
        TemplateHandler.add(choice, "len", length);
        TemplateHandler.add(choice, "then", machineGenerator.visitSubstitutionNode(substitutions.get(0), null));
        TemplateHandler.add(choice, "choice1", generateOtherChoices(node));
        if(substitutions.size() > 1) {
            ST choice2 = currentGroup.getInstanceOf("choice2");
            TemplateHandler.add(choice2, "then", machineGenerator.visitSubstitutionNode(substitutions.get(length - 1), expected));
            TemplateHandler.add(choice, "choice1", choice2.render());
        }
        return choice.render();
    }

    private List<String> generateOtherChoices(ChoiceSubstitutionNode node) {
        List<String> otherChoices = new ArrayList<>();
        for (int i = 1; i < node.getSubstitutions().size() - 1; i++) {
            ST choice = currentGroup.getInstanceOf("choice1");
            TemplateHandler.add(choice, "counter", i);
            TemplateHandler.add(choice, "then", machineGenerator.visitSubstitutionNode(node.getSubstitutions().get(i), null));
            otherChoices.add(choice.render());
        }
        return otherChoices;
    }

    public String generateAnyParameters(List<DeclarationNode> parameters, DeclarationNode parameter,
                                        PredicateNode predicateNode, SubstitutionNode substitutionNode, int index, int length) {
        ST substitution = currentGroup.getInstanceOf("any");
        TemplateHandler.add(substitution, "machine", nameHandler.handle(machineGenerator.getMachineName()));
        TemplateHandler.add(substitution, "type", typeGenerator.generate(parameter.getType()));
        TemplateHandler.add(substitution, "identifier", nameHandler.handle(parameter.getName()));
        if(!(parameter.getType() instanceof BoolType)) {
            TemplateHandler.add(substitution, "set", nameHandler.handleIdentifier(parameter.getType().toString(), NameHandler.IdentifierHandlingEnum.VARIABLES));
            TemplateHandler.add(substitution, "isBool", false);
        } else {
            TemplateHandler.add(substitution, "set", expressionGenerator.generateBooleans());
            TemplateHandler.add(substitution, "isBool", true);
        }
        TemplateHandler.add(substitution, "index", index);
        if(index == length - 1) {
            TemplateHandler.add(substitution, "body", generateAnyBody(predicateNode, substitutionNode));
        } else {
            TemplateHandler.add(substitution, "body", generateAnyParameters(parameters, parameters.get(index + 1), predicateNode, substitutionNode, index + 1, length));
        }
        return substitution.render();
    }

    private String generateAnyBody(PredicateNode predicateNode, SubstitutionNode substitutionNode) {
        ST body = currentGroup.getInstanceOf("any_body");
        TemplateHandler.add(body, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(body, "body", machineGenerator.visitSubstitutionNode(substitutionNode, null));
        return body.render();
    }

    /*
    * This function generates code for a list of assignments from the belonging AST node.
    */
    public String visitAssignSubstitutionNode(AssignSubstitutionNode node) {
        ST substitutions = currentGroup.getInstanceOf("assignments");
        List<String> assignments = new ArrayList<>();
        //TODO: For now, the variable on the left-hand side and on the right-hand side must be distinct
        for (int i = 0; i < node.getLeftSide().size(); i++) {
            assignments.add(generateAssignment(node.getLeftSide().get(i), node.getRightSide().get(i)));
        }
        TemplateHandler.add(substitutions, "assignments", assignments);
        return substitutions.render();
    }

    /*
    * This function generates code for one assignment with the expressions and the belonging template
    */
    public String generateAssignment(ExprNode lhs, ExprNode rhs) {
        ST substitution = currentGroup.getInstanceOf("assignment");
        TemplateHandler.add(substitution, "iterationConstruct", iterationConstructHandler.inspectExpression(rhs).getIterationsMapCode().values());
        TemplateHandler.add(substitution, "machine", nameHandler.handle(machineGenerator.getMachineName()));
        if(identifierGenerator.getParallelConstructAnalyzer() != null) {
            identifierGenerator.setLhsInParallel(true);
        }
        if(lhs instanceof IdentifierExprNode) {
            TemplateHandler.add(substitution, "isIdentifierLhs", true);
            TemplateHandler.add(substitution, "identifier", machineGenerator.visitExprNode(lhs, null));
            TemplateHandler.add(substitution, "isPrivate", nameHandler.getGlobals().contains(((IdentifierExprNode) lhs).getName()));
            if(identifierGenerator.getParallelConstructAnalyzer() != null) {
                identifierGenerator.setLhsInParallel(false);
            }
        } else if(lhs instanceof ExpressionOperatorNode) {
            TemplateHandler.add(substitution, "isIdentifierLhs", false);
            TemplateHandler.add(substitution, "identifier", machineGenerator.visitExprNode(((ExpressionOperatorNode) lhs).getExpressionNodes().get(0), null));
            TemplateHandler.add(substitution, "isPrivate", nameHandler.getGlobals().contains(((IdentifierExprNode) ((ExpressionOperatorNode) lhs).getExpressionNodes().get(0)).getName()));
            //TODO generate code for couples as arguments
            TemplateHandler.add(substitution, "arg", machineGenerator.visitExprNode(((ExpressionOperatorNode) lhs).getExpressionNodes().get(1), null));
            if(identifierGenerator.getParallelConstructAnalyzer() != null) {
                identifierGenerator.setLhsInParallel(false);
            }
            TemplateHandler.add(substitution, "modified_identifier", machineGenerator.visitExprNode(((ExpressionOperatorNode) lhs).getExpressionNodes().get(0), null));
        }
        TemplateHandler.add(substitution, "val", machineGenerator.visitExprNode(rhs, null));
        return substitution.render();
    }

    /*
    * This function generates code for sequential substitution and throws an exception for parallel substitutions as
    * code generation for parallel subsitutition is not supported in the given subset of B.
    * Therefore the belonging AST node is used.
    */
    public String visitListSubstitutionNode(ListSubstitutionNode node) {
        if(node.getOperator() == ListSubstitutionNode.ListOperator.Parallel) {
            return visitParallelSubstitutionNode(node);
        }
        return visitSequentialSubstitutionNode(node);
    }

    private String visitParallelSubstitutionNode(ListSubstitutionNode node) {
        //TODO Implement handling iteration construct
        //TODO implement parallel execution of operation call from included machine
        parallelNestingLevel++;
        ST substitutions = currentGroup.getInstanceOf("parallel");
        ParallelConstructAnalyzer parallelConstructAnalyzer;
        if(identifierGenerator.getParallelConstructAnalyzer() == null) {
            parallelConstructAnalyzer = new ParallelConstructAnalyzer();
            identifierGenerator.setParallelConstructAnalyzer(parallelConstructAnalyzer);
        } else {
            parallelConstructAnalyzer = new ParallelConstructAnalyzer();
            parallelConstructAnalyzer.getDefinedIdentifiersInParallel().addAll(identifierGenerator.getParallelConstructAnalyzer().getDefinedIdentifiersInParallel());
            identifierGenerator.setParallelConstructAnalyzer(parallelConstructAnalyzer);
        }
        parallelConstructAnalyzer.visitSubstitutionNode(node, null);

        identifierGenerator.setLhsInParallel(true);
        Set<String> loads = parallelConstructAnalyzer.getDefinedLoadsInParallel().stream()
                .map(this::visitParallelLoad)
                .collect(Collectors.toSet());
        TemplateHandler.add(substitutions, "machine", nameHandler.handle(machineGenerator.getMachineName()));
        TemplateHandler.add(substitutions, "loads", loads);
        identifierGenerator.setLhsInParallel(false);
        parallelConstructAnalyzer.resetParallel();
        List<String> others = node.getSubstitutions().stream()
                .map(subs -> machineGenerator.visitSubstitutionNode(subs, null))
                .collect(Collectors.toList());
        identifierGenerator.setParallelConstructAnalyzer(parallelConstructAnalyzer);
        TemplateHandler.add(substitutions, "others", others);
        parallelNestingLevel--;
        if(parallelNestingLevel == 0) {
            identifierGenerator.setParallelConstructAnalyzer(null);
        }
        return substitutions.render();
    }

    private String visitParallelLoad(ExprNode expr) {
        ST substitution = currentGroup.getInstanceOf("parallel_load");
        TemplateHandler.add(substitution, "machine", machineGenerator.getMachineName());
        TemplateHandler.add(substitution, "type", typeGenerator.generate(expr.getType()));
        TemplateHandler.add(substitution, "identifier", machineGenerator.visitExprNode(expr, null));
        TemplateHandler.add(substitution, "isPrivate", nameHandler.getGlobals().contains(((IdentifierExprNode) expr).getName()));
        return substitution.render();
    }

    /*
    * This function generates code for a sequential substitution with the belonging AST node.
    */
    private String visitSequentialSubstitutionNode(ListSubstitutionNode node) {
        List<String> substitutionCodes = node.getSubstitutions().stream()
                .map(substitutionNode -> machineGenerator.visitSubstitutionNode(substitutionNode, null))
                .collect(Collectors.toList());
        return String.join("\n", substitutionCodes);
    }

    public String visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node) {
        ST substitutions = currentGroup.getInstanceOf("assignments");
        List<String> assignments = new ArrayList<>();
        for (int i = 0; i < node.getIdentifiers().size(); i++) {
            assignments.add(generateNondeterminism(node.getIdentifiers().get(i), node.getExpression()));
        }
        TemplateHandler.add(substitutions, "assignments", assignments);
        return substitutions.render();
    }

    private String generateNondeterminism(ExprNode lhs, ExprNode rhs) {
        ST substitution = currentGroup.getInstanceOf("nondeterminism");
        TemplateHandler.add(substitution, "iterationConstruct", iterationConstructHandler.inspectExpression(rhs).getIterationsMapCode().values());
        TemplateHandler.add(substitution, "machine", machineGenerator.getMachineName());
        if(identifierGenerator.getParallelConstructAnalyzer() != null) {
            identifierGenerator.setLhsInParallel(true);
        }
        if(lhs instanceof IdentifierExprNode) {
            TemplateHandler.add(substitution, "isIdentifierLhs", true);
            TemplateHandler.add(substitution, "identifier", machineGenerator.visitExprNode(lhs, null));
            TemplateHandler.add(substitution, "isPrivate", nameHandler.getGlobals().contains(((IdentifierExprNode) lhs).getName()));
            if(identifierGenerator.getParallelConstructAnalyzer() != null) {
                identifierGenerator.setLhsInParallel(false);
            }
        } else if(lhs instanceof ExpressionOperatorNode) {
            TemplateHandler.add(substitution, "isIdentifierLhs", false);
            TemplateHandler.add(substitution, "identifier", machineGenerator.visitExprNode(((ExpressionOperatorNode) lhs).getExpressionNodes().get(0), null));
            TemplateHandler.add(substitution, "isPrivate", nameHandler.getGlobals().contains(((IdentifierExprNode) ((ExpressionOperatorNode) lhs).getExpressionNodes().get(0)).getName()));
            //TODO generate code for couples as arguments
            if(identifierGenerator.getParallelConstructAnalyzer() != null) {
                identifierGenerator.setLhsInParallel(false);
            }
            TemplateHandler.add(substitution, "modified_identifier", machineGenerator.visitExprNode(((ExpressionOperatorNode) lhs).getExpressionNodes().get(0), null));
            TemplateHandler.add(substitution, "arg", machineGenerator.visitExprNode(((ExpressionOperatorNode) lhs).getExpressionNodes().get(1), null));
        }

        TemplateHandler.add(substitution, "set", machineGenerator.visitExprNode(rhs, null));
        return substitution.render();
    }

    public String visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
        List<String> variables = node.getAssignedVariables().stream()
                .map(var -> machineGenerator.visitExprNode(var, expected))
                .collect(Collectors.toList());
        String operationName = node.getOperationNode().getName();
        String machineName = operationGenerator.getMachineFromOperation().get(operationName);
        ST functionCall;
        //Size of variables must be less equal than 1 for now.
        //TODO: Implement Records
        if(variables.size() > 0) {
            functionCall = currentGroup.getInstanceOf("operation_call_with_assignment");
            TemplateHandler.add(functionCall, "var", variables.get(0));
            TemplateHandler.add(functionCall, "isPrivate", nameHandler.getGlobals().contains(variables.get(0)));
        } else {
            functionCall = currentGroup.getInstanceOf("operation_call_without_assignment");
        }
        TemplateHandler.add(functionCall, "thisName", machineGenerator.getMachineName());
        TemplateHandler.add(functionCall, "machine", nameHandler.handleIdentifier(machineName, NameHandler.IdentifierHandlingEnum.MACHINES));
        TemplateHandler.add(functionCall, "function", operationName);
        TemplateHandler.add(functionCall, "args", node.getArguments().stream()
                .map(expr -> machineGenerator.visitExprNode(expr, expected))
                .collect(Collectors.toList()));
        TemplateHandler.add(functionCall,"this", machineName.equals(machineGenerator.getMachineName()));
        return functionCall.render();
    }

    /*
    * This function generates code for a while loop with the belonging AST node and the belonging template.
    */
    public String visitWhileSubstitutionNode(WhileSubstitutionNode node, Void expected) {
        ST whileST = currentGroup.getInstanceOf("while");
        TemplateHandler.add(whileST, "iterationConstruct1", iterationConstructHandler.inspectPredicate(node.getCondition()).getIterationsMapCode().values());
        TemplateHandler.add(whileST, "predicate", machineGenerator.visitPredicateNode(node.getCondition(), expected));
        TemplateHandler.add(whileST, "then", machineGenerator.visitSubstitutionNode(node.getBody(), expected));
        TemplateHandler.add(whileST, "iterationConstruct2", iterationConstructHandler.inspectPredicate(node.getCondition()).getIterationsMapCode().values());
        return whileST.render();
    }

    /*
    * This function generates from a var substitution with the belonging AST node and template. During this step the
    * flag for local scope is set to true and finally resetted to false. This is needed for handling collisions between
    * local variables and output parameters.
    */
    public String visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
        ST varST = currentGroup.getInstanceOf("var");
        this.localScopes++;
        this.currentLocalScope++;
        identifierGenerator.push(localScopes);
        node.getLocalIdentifiers().forEach(identifier -> identifierGenerator.addLocal(identifier.getName()));
        TemplateHandler.add(varST, "machine", nameHandler.handle(machineGenerator.getMachineName()));
        TemplateHandler.add(varST, "locals", generateVariablesInVar(node.getLocalIdentifiers()));
        TemplateHandler.add(varST, "body", machineGenerator.visitSubstitutionNode(node.getBody(), expected));
        identifierGenerator.pop();
        node.getLocalIdentifiers().forEach(identifier -> identifierGenerator.resetLocal(identifier.getName()));
        this.currentLocalScope--;
        return varST.render();
    }

    /*
    * This function generates code for all declarations of local variables from a var substitution from the list of identifiers as AST nodes.
    */
    private List<String> generateVariablesInVar(List<DeclarationNode> identifiers) {
        return identifiers.stream()
                .map(this::generateVariableInVar)
                .collect(Collectors.toList());
    }

    /*
    * This function generates code for one declaration of a local variable from a var substitution node from the belonging AST node and template.
    */
    private String generateVariableInVar(DeclarationNode identifier) {
        ST declaration = currentGroup.getInstanceOf("local_declaration");
        TemplateHandler.add(declaration, "type", typeGenerator.generate(identifier.getType()));
        TemplateHandler.add(declaration, "identifier", identifierGenerator.generateVarDeclaration(identifier.getName(), true));
        return declaration.render();
    }

    public int getCurrentLocalScope() {
        return currentLocalScope;
    }

    public void setOperationGenerator(OperationGenerator operationGenerator) {
        this.operationGenerator = operationGenerator;
    }
}
