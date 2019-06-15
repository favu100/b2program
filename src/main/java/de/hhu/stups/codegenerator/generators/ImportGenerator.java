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
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class ImportGenerator {

    private final STGroup group;

    private final NameHandler nameHandler;

    private final Set<String> imports;

    public ImportGenerator(final STGroup group, final NameHandler nameHandler) {
        this.group = group;
        this.nameHandler = nameHandler;
        this.imports = new HashSet<>();
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
            importString();
        } else if(type instanceof SetType) {
            importSetType((SetType) type);
        } else if(type instanceof EnumeratedSetElementType) {
            importBObject();
            importBBoolean();
        } else if(type instanceof DeferredSetElementType) {
            importBObject();
        } else if(type instanceof CoupleType) {
            importTuple((CoupleType) type);
        } else if(type instanceof RecordType) {
            importStruct((RecordType) type);
        }
    }

    public void addImportInIteration(BType type) {
        addImport(type);
        if(type instanceof SetType) {
            addImport(((SetType) type).getSubType());
        }
    }

    public List<String> generateMachineImports(MachineNode node) {
        return node.getMachineReferences().stream()
                .map(this::generateMachineImport)
                .collect(Collectors.toList());
    }

    private String generateMachineImport(MachineReferenceNode reference) {
        ST imp = group.getInstanceOf("import_type");
        String machine = reference.getMachineName();
        TemplateHandler.add(imp, "type", nameHandler.handle(machine));
        return imp.render();
    }

    private void importBInteger() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BInteger");
        imports.add(template.render());
    }

    private void importBObject() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BObject");
        imports.add(template.render());
    }

    private void importBBoolean() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BBoolean");
        imports.add(template.render());
    }

    private void importString() {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BString");
        imports.add(template.render());
    }

    private void importTuple(CoupleType type) {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BTuple");
        imports.add(template.render());
        addImport(type.getLeft());
        addImport(type.getRight());
    }

    private void importStruct(RecordType type) {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BStruct");
        type.getSubtypes().forEach(this::addImport);
        imports.add(template.render());
    }

    private void importSetType(SetType type) {
        if(type.getSubType() instanceof CoupleType) {
            importRelationType((CoupleType) type.getSubType());
        } else {
            ST template = group.getInstanceOf("import_type");
            TemplateHandler.add(template, "type", "BSet");
            imports.add(template.render());
            addImport(type.getSubType());
        }
    }

    private void importRelationType(CoupleType type) {
        ST template = group.getInstanceOf("import_type");
        TemplateHandler.add(template, "type", "BRelation");
        imports.add(template.render());
        addImport(type.getLeft());
        addImport(type.getRight());
    }

    public Set<String> getImports() {
        return imports;
    }
}
