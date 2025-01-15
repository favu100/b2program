package de.hhu.stups.codegenerator.generators;

/**
 * Created by fabian on 31.05.18.
 */
public class CodeGenerationException extends RuntimeException {
    public CodeGenerationException(String message, Throwable cause) {
        super(message, cause);
    }

    public CodeGenerationException(String message) {
        this(message, null);
    }

    public CodeGenerationException(Throwable cause) {
        this(cause.getMessage(), cause);
    }
}
