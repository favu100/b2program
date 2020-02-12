package de.hhu.stups.codegenerator.generators;


import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.ParallelConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.Node;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.substitution.AssignSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.BecomesElementOfSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ListSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.OperationCallSubstitutionNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;
import java.util.stream.Collectors;

public class IdentifierGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final NameHandler nameHandler;

    private List<DeclarationNode> inputParams;

    private List<DeclarationNode> outputParams;

    private Map<String, Integer> currentLocals;

    private Map<String, Integer> maxLocals;

    private Stack<Integer> stackScope;

    private final ParallelConstructHandler parallelConstructHandler;

    private final DeclarationGenerator declarationGenerator;

    public IdentifierGenerator(final STGroup group, final MachineGenerator machineGenerator, final NameHandler nameHandler,
                               final ParallelConstructHandler parallelConstructHandler, final DeclarationGenerator declarationGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.nameHandler = nameHandler;
        this.parallelConstructHandler = parallelConstructHandler;
        this.declarationGenerator = declarationGenerator;
        this.inputParams = new ArrayList<>();
        this.outputParams = new ArrayList<>();
        this.currentLocals = new HashMap<>();
        this.maxLocals = new HashMap<>();
        this.stackScope = new Stack<>();
        stackScope.push(0);
    }

    /*
    * This function generates code for an identifier.
    * It also calculates whether the identifier is a output parameter and whether it is generated to a private variable within a machine.
    */
    public String generate(IdentifierExprNode node) {
        boolean isReturn = isReturn(node);
        boolean isPrivate = nameHandler.getGlobals().contains(node.getName());
        boolean isAssigned = node.getParent() == null || isAssigned(node, node.getParent());
        return generate(node, isReturn, isPrivate, isAssigned);
    }

    /*
    * This function checks whether the given identifier is an output parameter
    */
    private boolean isReturn(IdentifierExprNode node) {
        return outputParams.stream()
                .map(declarationNode -> nameHandler.getEnumTypes().keySet().contains(declarationNode.getName()) ||
                                        nameHandler.getDeferredTypes().contains(declarationNode.getName()) ?
                        nameHandler.handleIdentifier(declarationNode.getName(), NameHandler.IdentifierHandlingEnum.VARIABLES) :
                        nameHandler.handleIdentifier(declarationNode.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
                .collect(Collectors.toList())
                .contains(node.toString());
    }

    /*
    * This function checks where the given identifier is assigned to a variable in the given parent.
    */
    public boolean isAssigned(IdentifierExprNode node, Node parent) {
        boolean isAssigned = false;
        if(parent instanceof BecomesElementOfSubstitutionNode) {
            isAssigned = ((BecomesElementOfSubstitutionNode) parent).getIdentifiers().contains(node);
        } else if(parent instanceof AssignSubstitutionNode) {
            isAssigned = ((AssignSubstitutionNode) parent).getLeftSide().contains(node);
        } else if(parent instanceof ListSubstitutionNode) {
            isAssigned = ((ListSubstitutionNode) parent).getSubstitutions().stream()
                    .map(n -> isAssigned(node, n))
                    .anyMatch(val -> val);
        } else if(parent instanceof OperationCallSubstitutionNode) {
            isAssigned = ((OperationCallSubstitutionNode) parent).getAssignedVariables().contains(node);
        }
        return isAssigned;
    }

    /*
    * This function generates code for an identifier from the template directly with the given information.
    */
    private String generate(IdentifierExprNode node, boolean isReturn, boolean isPrivate, boolean isAssigned) {
        ST identifier = group.getInstanceOf("identifier");
        TemplateHandler.add(identifier, "machine", nameHandler.handle(machineGenerator.getMachineName()));
        String nodeName = node.getName();
        String[] nodeNameAsList = nodeName.split("\\.");
        String variable = nodeNameAsList[nodeNameAsList.length - 1];
        TemplateHandler.add(identifier, "identifier", node.getType() != null && (nameHandler.getEnumTypes().keySet().contains(nodeName) || nameHandler.getDeferredTypes().contains(nodeName)) ?
                nameHandler.handleIdentifier(variable, NameHandler.IdentifierHandlingEnum.VARIABLES) :
                nameHandler.handleIdentifier(variable, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        TemplateHandler.add(identifier, "isReturn", isReturn);
        TemplateHandler.add(identifier, "isPrivate", isPrivate);
        TemplateHandler.add(identifier, "isAssigned", isAssigned);
        TemplateHandler.add(identifier, "rhsOnLhs", rhsOnLhs(node.getName()));
        boolean fromOtherMachine = node.getDeclarationNode() == null || !node.getDeclarationNode().getSurroundingMachineNode().equals(machineGenerator.getMachineNode());
        TemplateHandler.add(identifier, "fromOtherMachine", fromOtherMachine);
        MachineNode otherMachine = node.getDeclarationNode().getSurroundingMachineNode();
        TemplateHandler.add(identifier, "otherMachine", nameHandler.handleIdentifier(otherMachine.getPrefix() != null ? otherMachine.getPrefix() : otherMachine.getName(), NameHandler.IdentifierHandlingEnum.MACHINES));
        return identifier.render();
    }

    /*
    * This function generates code for a declaration of a local variable in B.
    */
    public String generateVarDeclaration(String name, boolean isAssigned) {
        ST identifier = group.getInstanceOf("identifier");
        StringBuilder resultIdentifier = new StringBuilder(nameHandler.handleIdentifier(name, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        if(currentLocals.keySet().contains(name)) {
            for (int i = 0; i < currentLocals.get(name); i++) {
                resultIdentifier.insert(0, "_");
            }
        }
        TemplateHandler.add(identifier, "machine", nameHandler.handle(machineGenerator.getMachineName()));
        TemplateHandler.add(identifier, "identifier", resultIdentifier.toString());
        TemplateHandler.add(identifier, "isReturn", false);
        TemplateHandler.add(identifier, "isPrivate", false);
        TemplateHandler.add(identifier, "isAssigned", isAssigned);
        TemplateHandler.add(identifier, "rhsOnLhs", rhsOnLhs(name));
        TemplateHandler.add(identifier, "fromOtherMachine", false);
        return identifier.render();
    }

    /*
    * This function checks whether the name of an identifier is used on the left-hand side and on the right-hand side of an assignment
    */
    private boolean rhsOnLhs(String name) {
        return !parallelConstructHandler.isLhsInParallel() && parallelConstructHandler.getParallelConstructAnalyzer() != null && parallelConstructHandler.getParallelConstructAnalyzer().getDefinedIdentifiersInParallel()
                .stream()
                .map(IdentifierExprNode::getName)
                .collect(Collectors.toList())
                .contains(name);
    }

    /*
    * This function sets the output paramters and calculates the generated local variables (collision problem between output parameters and local variables).
    */
    public void setParams(List<DeclarationNode> inputParams, List<DeclarationNode> outputParams){
        this.inputParams = inputParams;
        this.outputParams = outputParams;
        this.currentLocals.clear();
        this.maxLocals.clear();
        List<String> parameters = outputParams.stream()
                .map(DeclarationNode::getName)
                .collect(Collectors.toList());
        parameters.addAll(inputParams.stream()
                .map(DeclarationNode::getName)
                .collect(Collectors.toList()));
        for(String parameter : parameters) {
            currentLocals.put(parameter, 0);
            maxLocals.put(parameter, 0);
        }
    }

    /*
    * This function is needed for solving the collision problem beteween output parameters and local variables.
    */
    public void addLocal(String local) {
        if(maxLocals.keySet().contains(local)) {
            int value = maxLocals.get(local);
            maxLocals.put(local, value + 1);
            currentLocals.put(local, value + 1);
        } else {
            maxLocals.put(local, 0);
            currentLocals.put(local, 0);
        }
    }

    /*
    * This function is needed for solving the collision problem beteween output parameters and local variables.
    */
    public void resetLocal(String local) {
        currentLocals.put(local, stackScope.peek());
    }

    /*
    * Puts an element on the stack handling collision problem between local variables
    */
    public void push(int value) {
        stackScope.push(value);
    }


    /*
    * Pops from the stack handling collision problem between local variables
    */
    public void pop() {
        stackScope.pop();
    }

    public List<DeclarationNode> getInputParams() {
        return inputParams;
    }

    public Map<String, Integer> getCurrentLocals() {
        return currentLocals;
    }
}
