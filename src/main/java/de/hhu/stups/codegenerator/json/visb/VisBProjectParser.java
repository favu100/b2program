package de.hhu.stups.codegenerator.json.visb;

import de.prob.parser.antlr.Antlr4BParser;
import de.prob.parser.antlr.MachineASTCreator;
import de.prob.parser.antlr.ScopeException;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.MachineReferenceNode;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.visitors.MachineScopeChecker;
import de.prob.parser.ast.visitors.TypeChecker;
import de.prob.parser.ast.visitors.TypeErrorException;
import files.BParser;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CodePointCharStream;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class VisBProjectParser extends Antlr4BParser {

    public static void checkEvents(MachineNode machineNode, List<VisBEvent> events) {
        Set<String> mainEvents = machineNode.getOperations().stream().map(OperationNode::getName).collect(Collectors.toSet());
        if(!mainEvents.containsAll(events.stream().map(VisBEvent::getEvent).collect(Collectors.toList()))) {
            throw new RuntimeException("Scope error in events");
        }
    }

    public static VisBProject createVisBProject(List<MachineNode> machineNodeList, VisBVisualisation visualisation, boolean typecheck) throws TypeErrorException, ScopeException {
        // determine machine order

        sortMachineNodes(machineNodeList);
        for (int i = machineNodeList.size() - 1; i >= 0; i--) {
            MachineNode machineNode = machineNodeList.get(i);
            MachineScopeChecker scopeChecker = new MachineScopeChecker(machineNode);
            // i == 0 means that it is the main machine
            if (i == 0) {
                checkEvents(machineNode, visualisation.getVisBEvents());
                visualisation.getVisBItems().forEach(item -> scopeChecker.checkExpression(item.getExprNode()));
            }
        }
        if(typecheck) {
            for (int i = machineNodeList.size() - 1; i >= 0; i--) {
                MachineNode machineNode = machineNodeList.get(i);
                TypeChecker typeChecker = new TypeChecker(machineNode);
                if (i == 0) {
                    visualisation.getVisBItems().forEach(item -> typeChecker.checkExprNode(item.getExprNode()));
                }
            }
        }
        return new VisBProject(machineNodeList, visualisation);
    }

    public static VisBProject createVisBProjectFromMainFile(File mainBFile, VisBVisualisation visualisation) throws TypeErrorException, ScopeException, IOException {
        return createVisBProjectFromMainFile(mainBFile, visualisation, true);
    }

    public static VisBProject createVisBProjectFromMainFile(File mainBFile, VisBVisualisation visualisation, boolean typecheck) throws IOException, TypeErrorException, ScopeException {
        final File parentFolder = mainBFile.getParentFile();
        final List<MachineNode> machines = new ArrayList<>();
        final BParser.StartContext mainMachineCST = parse(mainBFile);
        final MachineNode main = MachineASTCreator.createMachineAST(mainMachineCST);
        visualisation.getVisBItems().forEach(item -> {
            CodePointCharStream stream = CharStreams.fromString(item.getExpression());
            BParser.ExpressionContext expressionContext = parseExpression(stream);
            ExprNode exprNode = MachineASTCreator.createExpressionAST(expressionContext);
            item.setExprNode(exprNode);
        });
        checkMachineName(mainBFile, main.getName());

        machines.add(main);
        final Set<String> parsedMachines = new HashSet<>();
        parsedMachines.add(main.getName());
        final List<MachineReferenceNode> todo = new ArrayList<>();
        todo.addAll(main.getMachineReferences());
        while (!todo.isEmpty()) {
            final MachineReferenceNode next = todo.iterator().next();
            todo.remove(next);
            final String name = next.getMachineName();
            if (!parsedMachines.contains(name)) {
                final File file = getFile(parentFolder, name);
                checkMachineName(file, name);
                final BParser.StartContext cst = parse(file);
                final MachineNode ast = MachineASTCreator.createMachineAST(cst);
                ast.setPrefix(next.getPrefix());
                machines.add(ast);
                for (MachineReferenceNode machineReferenceNode : ast.getMachineReferences()) {
                    final String refName = machineReferenceNode.getMachineName();
                    if (!parsedMachines.contains(refName)) {
                        todo.add(machineReferenceNode);
                    }
                }
            }
        }
        return createVisBProject(machines, visualisation, typecheck);
    }

}
