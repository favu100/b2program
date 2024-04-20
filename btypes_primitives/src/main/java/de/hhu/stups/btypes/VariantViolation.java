package de.hhu.stups.btypes;

public class VariantViolation extends RuntimeException {
    private static final long serialVersionUID = 1L;

    private final String message;

    public VariantViolation(String message) {
        super();
        this.message = message;
    }

    public String getMessage() {
        return message;
    }
}
