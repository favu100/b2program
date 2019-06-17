package de.hhu.stups.codegenerator.handlers;

import org.stringtemplate.v4.ST;

/*
* This class is used for avoding exceptions when replacing information in the placeholder. StringTemplate needs all used placeholders in all programming languages to be declared for each programming language.
* So this class makes it possible so that the arguments of the templates are always used arguments for this programming language only.
*/
public class TemplateHandler {

    /*
    * This function replaces the given placeholder by the given information to the given template
    */
    public static void add(ST template, String key, Object object) {
        if(template.getAttributes() != null && template.getAttributes().keySet().contains(key)) {
            template.add(key,object);
        }
    }

}