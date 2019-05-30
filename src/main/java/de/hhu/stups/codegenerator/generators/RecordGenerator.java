package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.analyzers.RecordStructAnalyzer;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.RecordNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.RecordType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.stream.Collectors;

/**
 * Created by fabian on 29.05.19.
 */
public class RecordGenerator {

    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final RecordStructAnalyzer recordStructAnalyzer;

    public RecordGenerator(STGroup group, MachineGenerator machineGenerator, RecordStructAnalyzer recordStructAnalyzer) {
        this.currentGroup = group;
        this.machineGenerator = machineGenerator;
        this.recordStructAnalyzer = recordStructAnalyzer;

    }

    public String visitRecordNode(RecordNode node) {
        ST record = currentGroup.getInstanceOf("record");
        BType type = node.getType();
        recordStructAnalyzer.createNewStruct((RecordType) type);
        String struct = recordStructAnalyzer.getStruct(type);
        TemplateHandler.add(record, "struct", struct);
        TemplateHandler.add(record, "parameters", node.getExpressions().stream()
            .map(expression -> machineGenerator.visitExprNode(expression, null))
            .collect(Collectors.toList()));
        return record.render();
    }

}
