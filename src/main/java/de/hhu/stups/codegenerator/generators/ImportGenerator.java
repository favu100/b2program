package de.hhu.stups.codegenerator.generators;


import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.MachineReferenceNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.BoolType;
import de.prob.parser.ast.types.CoupleType;
import de.prob.parser.ast.types.DeferredSetElementType;
import de.prob.parser.ast.types.EnumeratedSetElementType;
import de.prob.parser.ast.types.IntegerType;
import de.prob.parser.ast.types.RecordType;
import de.prob.parser.ast.types.SetType;
import de.prob.parser.ast.types.StringType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class ImportGenerator {

    private final STGroup group;

    private final NameHandler nameHandler;

    private final Set<String> imports;

    private final Set<String> importedTypes;

    private final Set<String> importedEnums;

    private final Set<String> importedMachines;

    private final boolean useBigInteger;

    private boolean forVisualization;


    public ImportGenerator(final STGroup group, final NameHandler nameHandler, final boolean useBigInteger) {
        this.group = group;
        this.nameHandler = nameHandler;
        this.imports = new HashSet<>();
        this.importedTypes = new HashSet<>();
        this.importedEnums = new HashSet<>();
        this.importedMachines = new HashSet<>();
        this.useBigInteger = useBigInteger;
        this.forVisualization = false;
    }

    /*
    * This function adds import for the types used in the generated code
    */
    public void addImport(BType type) {
        if(type instanceof IntegerType) {
            importBInteger();
        } else if(type instanceof BoolType) {
            importBBoolean();
        } else if(type instanceof StringType) {
            importBString();
        } else if(type instanceof SetType) {
            importSetType((SetType) type);
        } else if(type instanceof EnumeratedSetElementType) {
            importBObject();
            importBBoolean();
            importEnum((EnumeratedSetElementType) type);
        } else if(type instanceof DeferredSetElementType) {
            importBObject();
            importBBoolean();
            importEnum((DeferredSetElementType) type);
        } else if(type instanceof CoupleType) {
            importTuple((CoupleType) type);
        } else if(type instanceof RecordType) {
            importBObject();
            importStruct((RecordType) type);
            importBBoolean();
        }
    }

    private void importEnum(EnumeratedSetElementType enumType) {
        boolean fromOtherMachine = nameHandler.getEnumToMachine().get(enumType.getSetName()) != null && !nameHandler.getMachineName().equals(nameHandler.getEnumToMachine().get(enumType.getSetName()));
        if (fromOtherMachine || forVisualization) {
            ST enumImport = group.getInstanceOf("enum_import");
            TemplateHandler.add(enumImport, "name", enumType.getSetName());
            TemplateHandler.add(enumImport, "machineName", nameHandler.getEnumToMachine().get(enumType.getSetName()));
            importedEnums.add(enumImport.render());
        }
    }

    private void importEnum(DeferredSetElementType enumType) {
        boolean fromOtherMachine = nameHandler.getEnumToMachine().get(enumType.getSetName()) != null && !nameHandler.getMachineName().equals(nameHandler.getEnumToMachine().get(enumType.getSetName()));
        if (fromOtherMachine || forVisualization) {
            ST enumImport = group.getInstanceOf("enum_import");
            TemplateHandler.add(enumImport, "name", enumType.getSetName());
            TemplateHandler.add(enumImport, "machineName", nameHandler.getEnumToMachine().get(enumType.getSetName()));
            importedEnums.add(enumImport.render());
        }
    }


    /*
    * This function generates an import for a type and its subtype
    */
    public void addImportInIteration(BType type) {
        addImport(type);
        if(type instanceof SetType) {
            addImport(((SetType) type).getSubType());
        }
    }

    /*
    * This function generates code for import of other included machines
    */
    public Set<String> generateMachineImports(MachineNode node) {
        return node.getMachineReferences().stream()
                .map(this::generateMachineImport)
                .collect(Collectors.toSet());
    }

    /*
    * This function generates code for an import of an included machine
    */
    private String generateMachineImport(MachineReferenceNode reference) {
        ST imp = group.getInstanceOf("import_machine");
        String machine = reference.getMachineName();
        TemplateHandler.add(imp, "machine", nameHandler.handle(machine));
        importedMachines.add(nameHandler.handle(machine));
        return imp.render();
    }

    /*
    * This function generates code for importing BInteger
    */
    private void importBInteger() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BInteger");
        TemplateHandler.add(template, "useBigInteger", useBigInteger);
        imports.add(template.render());
        importedTypes.add("BInteger");
    }

    /*
    * This function generates code for importing BObject
    */
    private void importBObject() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BObject");
        TemplateHandler.add(template, "useBigInteger", useBigInteger);
        imports.add(template.render());
        importedTypes.add("BObject");
    }

    /*
    * This function generates code for importing BBoolean
    */
    private void importBBoolean() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BBoolean");
        TemplateHandler.add(template, "useBigInteger", useBigInteger);
        imports.add(template.render());
        importedTypes.add("BBoolean");
    }

    /*
    * This function generates code for importing BString
    */
    private void importBString() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BString");
        TemplateHandler.add(template, "useBigInteger", useBigInteger);
        imports.add(template.render());
        importedTypes.add("BString");
    }

    /*
    * This function generates code for importing BTuple and its subtypes
    */
    private void importTuple(CoupleType type) {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BTuple");
        TemplateHandler.add(template, "useBigInteger", useBigInteger);
        imports.add(template.render());
        addImport(type.getLeft());
        addImport(type.getRight());
        importedTypes.add("BTuple");
    }

    /*
    * This function generates code for importing subtypes of the given struct
    */
    private void importStruct(RecordType type) {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BStruct");
        TemplateHandler.add(template, "useBigInteger", useBigInteger);
        type.getSubtypes().forEach(this::addImport);
        imports.add(template.render());
        importedTypes.add("BStruct");
    }

    /*
    * This function generates code for importing BSet and its subtype
    */
    private void importSetType(SetType type) {
        if(type.getSubType() instanceof CoupleType) {
            importRelationType((CoupleType) type.getSubType());
        } else {
            ST template = group.getInstanceOf("import_type");
            TemplateHandler.add(template, "type", "BSet");
            TemplateHandler.add(template, "useBigInteger", useBigInteger);
            imports.add(template.render());
            addImport(type.getSubType());
            importedTypes.add("BSet");
        }
    }

    /*
    * This function generates code for importing subtypes of a relation
    */
    private void importRelationType(CoupleType type) {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BRelation");
        TemplateHandler.add(template, "useBigInteger", useBigInteger);
        imports.add(template.render());
        addImport(type);
        addImport(type.getLeft());
        addImport(type.getRight());
        importedTypes.add("BRelation");
    }

    public Set<String> getImports() {
        return imports;
    }

    public Set<String> getImportedTypes() {
        return importedTypes;
    }

    public Set<String> getImportedEnums() {
        return importedEnums;
    }

    public Set<String> getImportedMachines() {
        return importedMachines;
    }

    public void activateForVisualization() {
        this.forVisualization = true;
    }

    public void deactivateForVisualization() {
        this.forVisualization = false;
    }
}
