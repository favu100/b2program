package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.hhu.stups.codegenerator.json.modelchecker.ModelCheckingInfo;
import de.hhu.stups.codegenerator.json.modelchecker.OperationFunctionInfo;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.DeferredSetElementType;
import de.prob.parser.ast.types.EnumeratedSetElementType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import static de.hhu.stups.codegenerator.handlers.NameHandler.IdentifierHandlingEnum.INCLUDED_MACHINES;

public class ModelCheckingInfoGenerator {

    private final STGroup currentGroup;

    private final NameHandler nameHandler;

    private final InvariantGenerator invariantGenerator;

    private final TypeGenerator typeGenerator;


    public ModelCheckingInfoGenerator(final STGroup currentGroup, final NameHandler nameHandler, final InvariantGenerator invariantGenerator,
                                      final TypeGenerator typeGenerator) {
        this.currentGroup = currentGroup;
        this.nameHandler = nameHandler;
        this.invariantGenerator = invariantGenerator;
        this.typeGenerator = typeGenerator;
    }

    public ModelCheckingInfo generateModelCheckingInfo(MachineNode node) {
        String machineName = nameHandler.handle(node.getName());
        List<String> variables = node.getVariables().stream()
                .map(variable -> "_get_" + nameHandler.handleIdentifier(variable.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
                .collect(Collectors.toList());

        Map<String, String> transitionEvaluationFunctions = new HashMap<>();
        for(OperationNode operation : node.getOperations()) {
            String opName = nameHandler.handleIdentifier(operation.getName(), INCLUDED_MACHINES);
            String transitionName = "_tr_" + operation.getName();
            transitionEvaluationFunctions.put(opName, transitionName);
        }

        List<OperationFunctionInfo> operationFunctions = new ArrayList<>();
        for(OperationNode operation : node.getOperations()) {
            String opName = nameHandler.handleIdentifier(operation.getName(), INCLUDED_MACHINES);
            List<String> parameterTypes = new ArrayList<>();
            for(DeclarationNode param : operation.getParams()) {
                BType type = param.getType();
                ST typeTemplate = currentGroup.getInstanceOf("mc_info_type");
                TemplateHandler.add(typeTemplate, "isSet", type instanceof EnumeratedSetElementType || type instanceof DeferredSetElementType);
                TemplateHandler.add(typeTemplate, "machine", machineName);
                TemplateHandler.add(typeTemplate, "type", typeGenerator.generate(type));
                parameterTypes.add(typeTemplate.render());
            }
            operationFunctions.add(new OperationFunctionInfo(opName, parameterTypes));
        }

        List<String> invariantFunctions = new ArrayList<>();
        int invariantSize = invariantGenerator.splitInvariant(node.getInvariant()).size();
        for(int i = 1; i <= invariantSize; i++) {
            invariantFunctions.add("_check_inv_" + i);
        }

        return new ModelCheckingInfo(machineName, variables, transitionEvaluationFunctions, operationFunctions, invariantFunctions);
    }

}
