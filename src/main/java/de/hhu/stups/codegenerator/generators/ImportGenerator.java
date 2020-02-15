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

import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;

public class ImportGenerator {

    private final STGroup group;

    private final NameHandler nameHandler;

    private final Set<String> imports;

    private final boolean useBigInteger;

    public ImportGenerator(final STGroup group, final NameHandler nameHandler, final boolean useBigInteger) {
        this.group = group;
        this.nameHandler = nameHandler;
        this.imports = new HashSet<>();
        this.useBigInteger = useBigInteger;
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
        } else if(type instanceof DeferredSetElementType) {
            importBObject();
            importBBoolean();
        } else if(type instanceof CoupleType) {
            importTuple((CoupleType) type);
        } else if(type instanceof RecordType) {
            importStruct((RecordType) type);
            importBBoolean();
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
    }

    /*
    * This function generates code for importing BObject
    */
    private void importBObject() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BObject");
        TemplateHandler.add(template, "useBigInteger", useBigInteger);
        imports.add(template.render());
    }

    /*
    * This function generates code for importing BBoolean
    */
    private void importBBoolean() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BBoolean");
        TemplateHandler.add(template, "useBigInteger", useBigInteger);
        imports.add(template.render());
    }

    /*
    * This function generates code for importing BString
    */
    private void importBString() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BString");
        TemplateHandler.add(template, "useBigInteger", useBigInteger);
        imports.add(template.render());
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
    }

    public Set<String> getImports() {
        return imports;
    }
}
