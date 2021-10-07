package de.hhu.stups.codegenerator.json.visb;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonPrimitive;
import com.google.gson.JsonSyntaxException;
import com.google.gson.stream.JsonReader;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
* This file was taken from an earlier version of ProB2-UI
*/

public class VisBFileHandler {

    /**
     * This method takes a JSON / VisB file as input and returns a {@link VisBVisualisation} object.
     * @param inputFile File class object
     * @return VisBVisualisation object
     * @throws IOException If the file cannot be found, does not exist or is otherwise not accessible.
     * @throws RuntimeException If the file does not have the VisB format.
     */
    public static VisBVisualisation constructVisualisationFromJSON(File inputFile) throws IOException, RuntimeException, JsonSyntaxException {
        Gson gson = new Gson();
        JsonReader reader = new JsonReader(new FileReader(inputFile));
        JsonObject visBFile = gson.fromJson(reader, JsonObject.class);
        String parentFile = inputFile.getParentFile().toString();
        Path svgPath;

        if (visBFile.has("svg")) {
            String filePath = visBFile.get("svg").getAsString();
            if (filePath == null || filePath.isEmpty()) {
                throw new RuntimeException("There was no path to an SVG file found in your VisB file. Make sure, that you include one under the id \"svg\".");
            } else {
                svgPath = Paths.get(filePath);
                if (!svgPath.isAbsolute()) {
                    svgPath = Paths.get(parentFile, filePath);
                }
            }
        } else {
            throw new RuntimeException("There was no path to an SVG file found in your VisB file. Make sure, that you include one under the id \"svg\".");
        }

        List<VisBItem> visBItems = new ArrayList<>();
        List<VisBEvent> visBEvents = new ArrayList<>();

        Set<String> visBFiles = new HashSet<>();
        visBFiles.add(inputFile.toString());

        processCoreFile(gson, visBFile, parentFile, visBFiles, visBItems, visBEvents);

        return new VisBVisualisation(visBEvents, visBItems, svgPath, inputFile);
    }


    private static void processCoreFile(Gson gson, JsonObject visBFile, String parentFile, Set<String> visBFiles,
                                         List<VisBItem> visBItems, List<VisBEvent> visBEvents) throws IOException, RuntimeException {

        if(visBFile.has("include")) {
            String includedFileName = visBFile.get("include").getAsString();
            Path includedFilePath = Paths.get(includedFileName);
            if (!includedFilePath.isAbsolute()) {
                includedFilePath = Paths.get(parentFile, includedFileName);
            }
            // TO DO : check for cycles in inclusion
            if (visBFiles.contains(includedFilePath.toString())) {
                throw new RuntimeException("There is a loop in your VisB include statements leading to: " +  includedFileName);
            } else {
                visBFiles.add(includedFilePath.toString());
                System.out.println("Processing subsidiary VisB JSON file: " + includedFilePath);
                JsonReader reader = new JsonReader(new FileReader(includedFilePath.toFile()));
                JsonObject includedVisBFile = gson.fromJson(reader, JsonObject.class);
                processCoreFile(gson, includedVisBFile,  parentFile, visBFiles, visBItems, visBEvents);
            }
        }
        assembleItemList(visBFile, visBItems);
        assembleEventList(visBFile, visBEvents);
    }


    /**
     * This method assembles the events into a {@link List}. There is only one event possible for on click events for SVGs.
     * @param visBFile {@link JsonObject} containing possible events
     * @param visBEvents {@link List} into which the events are assembled
     * @throws RuntimeException If the format of the file is not right.
     */
    private static void assembleEventList(JsonObject visBFile, List<VisBEvent> visBEvents)
            throws RuntimeException{
        if(!visBFile.has("events"))
            return;
        JsonArray array = (JsonArray) visBFile.get("events");
        if(array == null || array.isJsonNull() || array.size() == 0) return;
        for (Object event : array) {
            JsonObject currentObj = (JsonObject) event;
            if(currentObj.isJsonNull()){
                continue;
            }
            if(currentObj.has("id") && currentObj.has("event")) {
                String id = currentObj.get("id").getAsString();
                if(id.isEmpty()){
                    throw new RuntimeException("An event in your visualisation file has an empty id.");
                }
                if (currentObj.has("ignore")) {
                    System.out.println("Ignoring VisB Event for " + id);
                } else {
                    String eventS = currentObj.get("event").getAsString();
                    // we now also allow empty event in case we only want to hover
                    List<String> predicates = new ArrayList<>();
                    if(currentObj.has("predicates")){
                        JsonArray jsonPredicates = currentObj.getAsJsonArray("predicates");
                        for(int i = 0; i < jsonPredicates.size();i++){
                            predicates.add(jsonPredicates.get(i).getAsString());
                        }
                    }

                    JsonArray repArray = getRepeatArray(currentObj,"event "+id);
                    if (repArray != null) {
                        // a list of strings which will replace %0, ...
                        System.out.println("repeats = " + repArray);
                        for(JsonElement rep : repArray) {
                            // now replace %0, %1, ... by values provided
                            String repId = id;
                            String repEvent = eventS;
                            List<String> repPreds = new ArrayList<>(predicates);

                            JsonArray replaceArr = getJsonArray(rep);
                            for(int i =0; i<replaceArr.size();i++) {
                                String thisVal = replaceArr.get(i).getAsString();
                                String pattern = "%"+i;
                                System.out.println("Repeating event " + id + " for '" + pattern + "' = " + thisVal);
                                repId = repId.replace(pattern, thisVal);
                                repEvent = repEvent.replace(pattern, thisVal);
                                for(int j = 0; j < repPreds.size(); j++) {
                                    repPreds.set(j,repPreds.get(j).replace(pattern, thisVal));
                                }
                                // we could check that all arrays have same size; otherwise a pattern will not be replaced
                            }
                            addVisBEvent(visBEvents, repId, repEvent, repPreds, currentObj,replaceArr);
                        }
                    } else { // no repititions have to be applied
                        addVisBEvent(visBEvents, id, eventS, predicates, currentObj,null);
                    }
                }
            } else if (!currentObj.has("id")){
                throw new RuntimeException("There is a event in your visualisation file, that has no \"id\" attribute.");
            } else if (!currentObj.has("event")){
                String id = currentObj.get("id").getAsString();
                throw new RuntimeException("The event for " + id + " in your visualisation file has no \"event\" attribute.");
            }
        }
    }

    // utility function to apply a replacement Array to replace %0, %1, ... in a string
    private static String applyReplacement(String str, JsonArray replaceArr) {
        if (replaceArr==null) {return str;}
        for(int i =0; i<replaceArr.size();i++) {
            String thisVal = replaceArr.get(i).getAsString();
            String pattern = "%"+i;
            str = str.replace(pattern, thisVal);
            System.out.println("Replaced "+pattern+" to "+thisVal+" in "+str);
        }
        return str;
    }

    // utility to get attribute and throw exception if it does not exist
    private static String getAttrString(JsonObject obj, String attr,String ctxt) throws RuntimeException {
        JsonElement el = obj.get(attr);
        if(el==null) {
            throw new RuntimeException("Missing attribute "+attr+" for "+ctxt);
        }
        return el.getAsString();
    }

    // create the VisB Event, after assembling hover information
    private static void addVisBEvent(List<VisBEvent> visBEvents,
                                     String id, String eventS, List<String> predicates,
                                     JsonObject currentObj,
                                     JsonArray replaceArr) throws RuntimeException {

        List<VisBHover> hovers = new ArrayList<>();
        if(currentObj.has("hovers")){
            JsonArray jsonHovers = currentObj.getAsJsonArray("hovers");
            for(int i = 0; i < jsonHovers.size();i++){
                JsonObject hv = jsonHovers.get(i).getAsJsonObject();

                String hoverID;
                String hoverAttr = getAttrString(hv,"attr","hover within event "+ id);
                String hoverEnter = applyReplacement(getAttrString(hv,"enter","hover within event "+id),replaceArr);
                String hoverLeave = applyReplacement(getAttrString(hv,"leave","hover within event "+id),replaceArr);
                if(hv.has("id")) {
                    hoverID = applyReplacement(getAttrString(hv,"id","hover within event "+id),replaceArr);
                } else {
                    hoverID = id;
                }
                System.out.println("Detected hover: " +id + " for "+ hoverAttr);
                hovers.add(new VisBHover(id, hoverID, hoverAttr, hoverEnter, hoverLeave));
            }
        }
        // TODO: Check whether ID is correct
        //Boolean optional = (currentObj.has("optional") && currentObj.get("optional").getAsBoolean());
        VisBEvent visBEvent = new VisBEvent(id , eventS, predicates, hovers);
        if(!containsId(visBEvents, id)) {
            visBEvents.add(visBEvent);
        } else {
            throw new RuntimeException("This id has already an event: " +id+".");
        }
    }

    private static boolean containsId(List<VisBEvent> visBEvents, String id){
        for(VisBEvent visBEvent : visBEvents){
            if(id.equals(visBEvent.getId())){
                return true;
            }
        }
        return false;
    }

    /**
     * This method assembles the visualisation items into an {@link List}. There are multiple possible attribute changes for an SVG element after a state changed.
     * @param visBFile {@link JsonObject} containing possible items
     * @param visBItems {@link List} into which the {@link VisBItem}s are assembled
     * @throws RuntimeException If the format of the file is not right.
     */
    private static void assembleItemList(JsonObject visBFile, List<VisBItem> visBItems)
            throws RuntimeException{
        if(!visBFile.has("items"))
            return;
        JsonArray array = (JsonArray) visBFile.get("items");
        if(array == null || array.isJsonNull() || array.size() == 0) return;
        for (Object item : array) {
            JsonObject currentObj = (JsonObject) item;
            if(currentObj.isJsonNull()){
                continue;
            }
            if(currentObj.has("id") && currentObj.has("attr") && currentObj.has("value")) {
                String id = currentObj.get("id").getAsString();
                String attribute = currentObj.get("attr").getAsString();
                String value = currentObj.get("value").getAsString();
                Boolean optional = (currentObj.has("optional") && currentObj.get("optional").getAsBoolean());
                if(id.isEmpty() || attribute.isEmpty() || value.isEmpty()){
                    throw new RuntimeException("There is an item in your visualisation file, that has an empty id, attr, or value body.");
                }
                if (currentObj.has("ignore")) {
                    System.out.println("Ignoring VisB Item: " + id + "." + attribute);
                } else {
                    JsonArray repArray = getRepeatArray(currentObj,"VisB item "+id+ "." + attribute);
                    if (repArray != null) {
                        // a list of strings which will replace %0, ... in the id and value attributes:
                        for(JsonElement rep : repArray) {
                            // now replace %0, %1, ... by values provided
                            String repId = new String(id);
                            // no need to replace in attribute
                            String repVal = new String(value);

                            JsonArray replaceArr = getJsonArray(rep);
                            for(int i =0; i<replaceArr.size();i++) {
                                String thisVal = replaceArr.get(i).getAsString();
                                String pattern = new String("%"+i);
                                System.out.println("Repeating item " + id + "." + attribute + " for '" + pattern + "' = " + thisVal);
                                repId = repId.replace(pattern, thisVal);
                                repVal = repVal.replace(pattern, thisVal);
                                // we could check that all arrays have same size; otherwise a pattern will not be replaced
                            }
                            // TODO: Check whether description and source are correct
                            visBItems.add(new VisBItem(repId, attribute, repVal, "", ""));
                            // note: we do not check if an old item for this id and attribute already exists;
                            // this actually allows overriding VisB items from included files
                            // TODO: we could remove the old item if it exists; we could provide a warning if the old item is in the same file; it would probably be better to use a hash map then
                        }
                    } else { // no repetitions
                        // TODO: Check whether description and source are correct
                        visBItems.add(new VisBItem(id, attribute, value, "", "")); // see comment above
                    }
                }
            } else if (!currentObj.has("id")){
                throw new RuntimeException("There is a item in your visualisation file, that has no \"id\" member.");
            } else if (!currentObj.has("attr")){
                throw new RuntimeException("There is a item in your visualisation file, that has no \"attr\" member.");
            } else if (!currentObj.has("value")){
                throw new RuntimeException("There is a item in your visualisation file, that has no \"value\" member.");
            }
        }
    }

    // utility to get a JsonArray; a single Object is automatically transformed into a single item array
    private static JsonArray getJsonArray (JsonElement rep) {
        if(rep instanceof JsonArray) {
            return rep.getAsJsonArray();
        } else {
            JsonArray replaceArr = new JsonArray();
            replaceArr.add(rep); // create a one element array
            return replaceArr;
        }
    }

    // get a JsonArray of repetitions; either as a repeat list of explicit strings, or a for loop
    private static JsonArray getRepeatArray (JsonObject currentObj, String ctxt) throws RuntimeException {
        if (currentObj.has("for")) {
            JsonObject forloop = (JsonObject) currentObj.get("for"); // To do: check if JsonElement instanceof JsonObject
            if (!(forloop.has("from") && forloop.has("to"))) {
                throw new RuntimeException("A for loop requires both a from and to attribute within "+ctxt);
            }
            int from = forloop.get("from").getAsInt();
            int to = forloop.get("to").getAsInt();
            int step = 1;
            if (forloop.has("step")) {
                step = forloop.get("step").getAsInt();
                if (step<1) {
                    throw new RuntimeException("The step " + step + " must be > 0 in for loop " + from + ".." + to + " within "+ctxt);
                }
            }
            if ((to-from)/step > 100000) {
                throw new RuntimeException("The for loop " + from + ".." + to + " seems too large within "+ctxt);
            }
            JsonArray replaceArr = new JsonArray();
            for(int i=from; i <= to; i += step) {
                if (currentObj.has("repeat")) {
                    for(JsonElement rep : (JsonArray) currentObj.get("repeat") ) {
                        JsonArray arrInner = new JsonArray();
                        arrInner.add(new JsonPrimitive(i)); // add i at end of beginning of list
                        arrInner.addAll(getJsonArray(rep)); // now copy original rep list
                        replaceArr.add(arrInner); // add modified repetition list to overall list
                    }
                } else {
                    replaceArr.add(new JsonPrimitive(i) );
                }
                System.out.println("repeat-for: " + i + " within "+ctxt);
            }
            return replaceArr;
        }  else if (currentObj.has("repeat")) { // repeat without for
            return (JsonArray) currentObj.get("repeat");
        } else {
            return null;
        }
    }

    /**
     * @param file {@link File}
     * @return String representation of the file
     * @throws IOException If the file cannot be found, does not exist or is otherwise not accessible.
     */
    String fileToString(File file) throws IOException{
        StringBuilder sb = new StringBuilder();
        BufferedReader bufferedReader = new BufferedReader(new FileReader(file));
        String s = bufferedReader.readLine();
        while (s != null) {
            sb.append(s);
            s = bufferedReader.readLine();
        }
        return sb.toString();
    }
}