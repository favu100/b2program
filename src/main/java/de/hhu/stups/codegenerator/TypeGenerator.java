package de.hhu.stups.codegenerator;


import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.BoolType;
import de.prob.parser.ast.types.CoupleType;
import de.prob.parser.ast.types.EnumeratedSetElementType;
import de.prob.parser.ast.types.IntegerType;
import de.prob.parser.ast.types.SetType;
import de.prob.parser.ast.types.UntypedType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

public class TypeGenerator {

    private final STGroup group;

    private final NameHandler nameHandler;

    private final boolean useBigInteger;

    public TypeGenerator(final STGroup group, final NameHandler nameHandler, final boolean useBigInteger) {
        this.group = group;
        this.nameHandler = nameHandler;
        this.useBigInteger = useBigInteger;
    }

    /*
    * This function generates code for a type with the given type and the information whether the type is generated for casting an object
    */
    public String generate(BType type, boolean cast) {
        ST template = group.getInstanceOf("type");
        if(type instanceof IntegerType) {
            if(useBigInteger) {
                TemplateHandler.add(template, "type", "BBigInteger");
            } else {
                TemplateHandler.add(template, "type", "BInteger");
            }
            TemplateHandler.add(template, "cast", cast);
            return template.render();
        } else if(type instanceof BoolType) {
            TemplateHandler.add(template, "type", "BBoolean");
            TemplateHandler.add(template, "cast", cast);
            return template.render();
        } else if(type instanceof SetType) {
            template = group.getInstanceOf("set_type");
            TemplateHandler.add(template, "type", generate(((SetType) type).getSubType(), false));
            TemplateHandler.add(template, "cast", cast);
            return template.render();
        } else if(type instanceof EnumeratedSetElementType) {
            TemplateHandler.add(template, "type", nameHandler.handleIdentifier(type.toString(), NameHandler.IdentifierHandlingEnum.INCLUDED_MACHINES));
            TemplateHandler.add(template, "cast", cast);
            return template.render();
        } else if(type instanceof CoupleType) {
            TemplateHandler.add(template, "type", "BCouple");
            TemplateHandler.add(template, "cast", cast);
            return template.render();
        } else if(type instanceof UntypedType) {
            return generateUntyped();
        }
        return "";
    }

    /*
    * This function generates code for untyped nodes.
    */
    private String generateUntyped() {
        return group.getInstanceOf("void").render();
    }

}
