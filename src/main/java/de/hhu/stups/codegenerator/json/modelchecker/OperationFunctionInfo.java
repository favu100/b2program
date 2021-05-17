package de.hhu.stups.codegenerator.json.modelchecker;

import java.util.List;

public class OperationFunctionInfo {

    private final String opName;

    private final List<String> parameterTypes;

    public OperationFunctionInfo(final String opName, final List<String> parameterTypes) {
        this.opName = opName;
        this.parameterTypes = parameterTypes;
    }

    public String getOpName() {
        return opName;
    }

    public List<String> getParameterTypes() {
        return parameterTypes;
    }

    @Override
    public String toString() {
        return "OperationFunctionInfo{" +
                "opName='" + opName + '\'' +
                ", parameterTypes=" + parameterTypes +
                '}';
    }
}
