package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.CodeGenerator;
import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.prob.parser.antlr.BProject;
import de.prob.parser.ast.nodes.MachineReferenceNode;
import de.prob.parser.ast.types.RecordType;

import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Map;
import java.util.regex.Pattern;

public class MachineReferenceGenerator {

    private NameHandler nameHandler = null;

    private DeclarationGenerator declarationGenerator = null;

    private RecordStructGenerator recordStructGenerator = null;

    private final CodeGenerator codeGenerator;

    public MachineReferenceGenerator(CodeGenerator codeGenerator) {
        this.codeGenerator = codeGenerator;
    }

    /*
    * This function generates code for all included machines from the given options
    */
    public void generateIncludedMachines(BProject project, Path path, GeneratorMode mode, boolean useBigInteger, String minint, String maxint, String deferredSetSize, boolean forModelChecking, boolean useConstraintSolving, boolean forVisualisation, String serverLink) throws IOException {
        for(MachineReferenceNode referenceNode : project.getMainMachine().getMachineReferences()) {
            Path currentPath = Paths.get(path.getParent().toString(), referenceNode.getMachineName() + ".mch");
            if(!codeGenerator.getPaths().contains(currentPath)) {
                codeGenerator.generate(currentPath, mode, useBigInteger, minint, maxint, deferredSetSize, forModelChecking, useConstraintSolving, false, null, true, forVisualisation, null, serverLink);
            }
        }
    }

    /*
    * This function updates the NameHandler for other machines in the hierarchy. This is needed because variables from included machines can be using by the machines they are included by.
    */
    public void updateNameHandler(MachineGenerator generator) {
        if(nameHandler != null) {
            Map<String, List<String>> enumTypes = nameHandler.getEnumTypes();
            for(String key : enumTypes.keySet()) {
                generator.getNameHandler().getEnumTypes().put(key, enumTypes.get(key));
            }
            generator.getNameHandler().getDeferredTypes().addAll(nameHandler.getDeferredTypes());
            generator.getNameHandler().getReservedMachines().addAll(nameHandler.getReservedMachines());
            generator.getNameHandler().getReservedMachinesAndFunctions().addAll(nameHandler.getReservedMachinesAndFunctions());
            generator.getNameHandler().getReservedMachinesAndFunctionsAndVariables().addAll(nameHandler.getReservedMachinesAndFunctionsAndVariables());
            generator.getNameHandler().getReservedMachinesWithIncludedMachines().addAll(nameHandler.getReservedMachinesWithIncludedMachines());

        }
        nameHandler = generator.getNameHandler();
    }

    /*
    * This function updates the DeclarationGenerator for other machines in the hierarchy. This is needed because variables from included machines can be using by the machines they are included by.
    */
    public void updateDeclarationGenerator(MachineGenerator generator) {
        if(declarationGenerator != null) {
            Map<String, List<String>> setToEnum = declarationGenerator.getSetToEnum();
            for(String key : setToEnum.keySet()) {
                generator.getDeclarationGenerator().getSetToEnum().put(key, setToEnum.get(key));
            }
            Map<String, String> enumToMachine = declarationGenerator.getEnumToMachine();
            for(String key : enumToMachine.keySet()) {
                generator.getDeclarationGenerator().getEnumToMachine().put(key, enumToMachine.get(key));
            }
        }
        declarationGenerator = generator.getDeclarationGenerator();
    }

    /*
    * This function updates the RecordStructGenerator for other machines in the hierarchy. This is needed because variables from included machines can be using by the machines they are included by.
    */
    public void updateRecordStructGenerator(MachineGenerator generator) {
        if(recordStructGenerator != null) {
            List<RecordType> structs = recordStructGenerator.getStructs();
            generator.getRecordStructGenerator().getStructs().addAll(structs);
            Map<String, String> nodeToClassName = recordStructGenerator.getNodeToClassName();
            for(String key : nodeToClassName.keySet()) {
                generator.getRecordStructGenerator().getNodeToClassName().put(key, nodeToClassName.get(key));
            }
        }
        recordStructGenerator = generator.getRecordStructGenerator();
    }

}
