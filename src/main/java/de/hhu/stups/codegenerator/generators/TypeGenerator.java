package de.hhu.stups.codegenerator.generators;


import de.hhu.stups.codegenerator.definitions.SetDefinition;
import de.hhu.stups.codegenerator.definitions.SetDefinitions;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.BoolType;
import de.prob.parser.ast.types.CoupleType;
import de.prob.parser.ast.types.DeferredSetElementType;
import de.prob.parser.ast.types.EnumeratedSetElementType;
import de.prob.parser.ast.types.IntegerType;
import de.prob.parser.ast.types.RecordType;
import de.prob.parser.ast.types.SetType;
import de.prob.parser.ast.types.StringType;
import de.prob.parser.ast.types.UntypedType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.function.Function;
import java.util.stream.Collectors;

public class TypeGenerator {

    private final STGroup group;

    private final NameHandler nameHandler;

    private final MachineGenerator machineGenerator;

    private DeclarationGenerator declarationGenerator;

    private RecordStructGenerator recordStructGenerator;

    private final SetDefinitions setDefinitions;

    private boolean fromOutside = false;
    private boolean forEmbedded = false;

    public TypeGenerator(final STGroup group, final NameHandler nameHandler, final MachineGenerator machineGenerator, final SetDefinitions setDefinitions, boolean forEmbedded) {
        this.group = group;
        this.nameHandler = nameHandler;
        this.machineGenerator = machineGenerator;
        this.setDefinitions = setDefinitions;
        this.declarationGenerator = null;
        this.forEmbedded = forEmbedded;
    }

    public String generate(BType type) { return this.generate(type, false); }
    /**
    * This function generates code for a type with the given type and the information whether the type is generated for casting an object
    * @param constant: indicates if this type is used for a constant, used to optimize embedded code-generation
    **/
    public String generate(BType type, boolean constant) {
        if(type instanceof IntegerType) {
            return generateBInteger();
        } else if(type instanceof BoolType) {
            return generateBBoolean();
        } else if(type instanceof StringType) {
            return generateBString();
        } else if(type instanceof SetType) {
            return generateBSet((SetType) type, constant);
        } else if(type instanceof EnumeratedSetElementType) {
            return generateEnumeratedSetElement((EnumeratedSetElementType) type);
        } else if(type instanceof DeferredSetElementType) {
            return generateDeferredSetElement((DeferredSetElementType) type);
        } else if(type instanceof CoupleType) {
            return generateBTuple((CoupleType) type);
        } else if(type instanceof RecordType) {
            return generateBStruct((RecordType) type);
        } else if(type instanceof UntypedType) {
            return generateUntyped();
        }
        return "";
    }

    /*
    * This function generates code for BInteger
    */
    private String generateBInteger() {
        ST template = group.getInstanceOf("type");
        TemplateHandler.add(template, "fromOtherMachine", false);
        TemplateHandler.add(template, "type", "BInteger");
        return template.render();
    }

    /*
    * This function generates code for BBoolean
    */
    private String generateBBoolean() {
        ST template = group.getInstanceOf("type");
        TemplateHandler.add(template, "fromOtherMachine", false);
        TemplateHandler.add(template, "type", "BBoolean");
        return template.render();
    }

    /*
    * This function generates code for BString
    */
    private String generateBString() {
        ST template = group.getInstanceOf("type");
        TemplateHandler.add(template, "fromOtherMachine", false);
        TemplateHandler.add(template, "type", "BString");
        return template.render();
    }

    /*
    * This function generates code for BTuple and its subtypes from the given type
    */
    private String generateBTuple(CoupleType type) {
        ST template = group.getInstanceOf("tuple_type");
        TemplateHandler.add(template, "leftType", generate(type.getLeft()));
        TemplateHandler.add(template, "rightType", generate(type.getRight()));
        return template.render();
    }

    /*
    * This function generates code for a struct from the given type
    */
    private String generateBStruct(RecordType type) {
        ST template = group.getInstanceOf("type");
        TemplateHandler.add(template, "type", recordStructGenerator.getStruct(type));
        return template.render();
    }

    /*
    * This function generates code for BSet and its subtypes from the given type
    */
    private String generateBSet(SetType type, boolean constant) {
        BType subType = type.getSubType();
        if(subType instanceof CoupleType) {
            return generateBRelation((CoupleType) subType, constant);
        } else {
            addSetDefinition(subType, constant);
            ST template = group.getInstanceOf("set_type");
            TemplateHandler.add(template, "fromOtherMachine", false);
            if(!(subType instanceof UntypedType)) { // subType is a type other than couple type and void type
                if (forEmbedded) {
                    if (!setDefinitions.containsDefinition(subType)) generate(subType);
                    SetDefinition subDefinition = setDefinitions.getDefinition(subType);
                    TemplateHandler.add(template, "type", subDefinition.getName());
                } else {
                    TemplateHandler.add(template, "type", generate(subType));
                }
            }
            return template.render();

        }
    }

    /*
    * This function generates code for the subtypes of a relation from the given couple type
    */
    private String generateBRelation(CoupleType type, boolean constant) {
        ST template = group.getInstanceOf("relation_type");
        TemplateHandler.add(template, "leftType", generate(type.getLeft(), constant));
        addSetDefinition(type.getLeft(), constant);
        TemplateHandler.add(template, "leftName", declarationGenerator.generateSetEnumName(type.getLeft()));
        TemplateHandler.add(template, "rightType", generate(type.getRight(), constant));
        addSetDefinition(type.getRight(), constant);
        TemplateHandler.add(template, "rightName", declarationGenerator.generateSetEnumName(type.getRight()));
        addSetDefinition(type, constant);
        return template.render();
    }

    public SetDefinition addSetDefinition(BType type) { return this.addSetDefinition(type, false); }
    public SetDefinition addSetDefinition(BType type, boolean constant) {
        if (!this.forEmbedded) return null;
        SetDefinition existingDef = this.setDefinitions.getDefinition(type);
        if (existingDef != null) {
            if (constant || !existingDef.isConstant())
                return existingDef; //returns dynamic set if it exists, even if constant set is 'requested'. Caller needs to check for that. (we only keep const-definitions if there is no dynamic one)
            else this.setDefinitions.deleteDefinition(type); //dynamic set found after const-set -> overwrite
        }

        List<String> variants;
        String name = null;
        if (type instanceof SetType) {
            if (constant) {
                variants = new ArrayList<>();
            } else {
                BType subType = ((SetType) type).getSubType();
                SetDefinition subDefinition = this.setDefinitions.getDefinition(subType);
                if (subDefinition == null) subDefinition = addSetDefinition(subType);
                SetDefinition result = subDefinition.getPowSetDefinition(group.getInstanceOf("set_element_name"));
                this.setDefinitions.addDefinition(result);
                declarationGenerator.generateSetEnumName(type);
                return result;
            }
        } else if (type instanceof CoupleType) {
            variants = getTypeVariants(type);
        } else if (type instanceof EnumeratedSetElementType) {
            EnumeratedSetElementType enumType = (EnumeratedSetElementType) type;
            variants = enumType.getElements();
            name = nameHandler.handleIdentifier(enumType.getSetName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES);
        } else if (type instanceof IntegerType) {
            variants = new ArrayList<>();
            name = "BInteger";
            // The integer-set is hard-coded into the BType-library (since there isn't a good way of creating it dynamically with generated code)
            // Nesting of integer-sets is not supported at all (but the generator won't stop this)
        } else if(type instanceof BoolType) {
            variants = getTypeVariants(type);
            name = "BOOL";
        } else {
            throw new RuntimeException("cannot add setDef for type "+type);
        }
        SetDefinition setDefinition = new SetDefinition(type, variants);
        if (constant) setDefinition.makeConstant();
        if (name != null) setDefinition.setName(name);
        this.setDefinitions.addDefinition(setDefinition);
        return setDefinition;
    }

    private List<String> getTypeVariants(BType type) {
        if(type instanceof EnumeratedSetElementType) return ((EnumeratedSetElementType) type).getElements();
        else if (type instanceof SetType) return getSetVariants((SetType) type);
        else if (type instanceof CoupleType) return getRelationVariants((CoupleType) type);
        else if (type instanceof BoolType) return Arrays.asList("BFALSE", "BTRUE"); //TODO: put in template?
        else if (type instanceof IntegerType) return new ArrayList<>();

        throw new RuntimeException("cannot get Variants for type "+type);
    }

    public List<String> getSetVariants(SetType type) {
        if(!this.setDefinitions.containsDefinition(type)) {
            addSetDefinition(type);
        }
        return setDefinitions.getDefinition(type).getElements();
    }

    public List<String> getRelationVariants(CoupleType relType) {
        List<String> leftElements = getTypeVariants(relType.getLeft());
        List<String> rightElements = getTypeVariants(relType.getRight());
        //TODO: Limit size?
        ST relElementGenerator = group.getInstanceOf("relation_element_name");
        return leftElements.stream().flatMap(l ->
                rightElements.stream().map(r -> {
                    relElementGenerator.remove("leftElement");
                    relElementGenerator.remove("rightElement");
                    return relElementGenerator.add("leftElement", l).add("rightElement", r).render();
                })).collect(Collectors.toList());
    }

    /*
    * This function generates code for the type of an enumerated set element
    */
    private String generateEnumeratedSetElement(EnumeratedSetElementType type) {
        ST template = group.getInstanceOf("type");
        TemplateHandler.add(template, "fromOtherMachine", declarationGenerator.getEnumToMachine().get(type.getSetName()) != null && !machineGenerator.getMachineName().equals(declarationGenerator.getEnumToMachine().get(type.getSetName())));
        TemplateHandler.add(template, "otherMachine", declarationGenerator.getEnumToMachine().get(type.getSetName()));
        TemplateHandler.add(template, "fromOutside", fromOutside);
        TemplateHandler.add(template, "type", nameHandler.handleIdentifier(type.toString(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        return template.render();
    }

    /*
    * This function generates code for the type of an deferred set element
    */
    private String generateDeferredSetElement(DeferredSetElementType type) {
        ST template = group.getInstanceOf("type");
        TemplateHandler.add(template, "fromOtherMachine", declarationGenerator.getEnumToMachine().get(type.getSetName()) != null && !machineGenerator.getMachineName().equals(declarationGenerator.getEnumToMachine().get(type.getSetName())));
        TemplateHandler.add(template, "otherMachine", declarationGenerator.getEnumToMachine().get(type.getSetName()));
        TemplateHandler.add(template, "fromOutside", fromOutside);
        TemplateHandler.add(template, "type", nameHandler.handleIdentifier(type.toString(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        return template.render();
    }

    /*
    * This function generates code for untyped nodes.
    */
    private String generateUntyped() {
        return group.getInstanceOf("void").render();
    }

    public void setRecordStructGenerator(RecordStructGenerator recordStructGenerator) {
        this.recordStructGenerator = recordStructGenerator;
    }

    public void setDeclarationGenerator(DeclarationGenerator declarationGenerator) {
        this.declarationGenerator = declarationGenerator;
    }

    public void setFromOutside(boolean fromOutside) {
        this.fromOutside = fromOutside;
    }
}
