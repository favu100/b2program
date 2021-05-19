package de.hhu.stups.codegenerator.json.visb;

import de.prob.parser.antlr.BProject;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.expression.ExprNode;

import java.util.ArrayList;
import java.util.List;

public class VisBProject {

    private final BProject project;

    private final VisBVisualisation visualisation;

    public VisBProject(List<MachineNode> machineNodeList, VisBVisualisation visualisation) {
        this.project = new BProject(machineNodeList);
        this.visualisation = visualisation;
    }

    public VisBVisualisation getVisualisation() {
        return visualisation;
    }

    public BProject getProject() {
        return project;
    }
}
