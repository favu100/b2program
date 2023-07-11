export class Activation {
    operation;
    time;
    additionalGuards;
    activationKind;
    fixedVariables;
    probabilisticVariables;
    firingTransitionParameters;
    firingTransitionParametersPredicate;
    constructor(operation, time, additionalGuards, activationKind, fixedVariables, probabilisticVariables, firingTransitionParameters, firingTransitionParametersPredicate) {
        this.operation = operation;
        this.time = time;
        this.additionalGuards = additionalGuards;
        this.activationKind = activationKind;
        this.fixedVariables = fixedVariables;
        this.probabilisticVariables = probabilisticVariables;
        this.firingTransitionParameters = firingTransitionParameters;
        this.firingTransitionParametersPredicate = firingTransitionParametersPredicate;
    }
    decreaseTime(delta) {
        this.time -= delta;
    }
    getOperation() {
        return this.operation;
    }
    getTime() {
        return this.time;
    }
    getAdditionalGuards() {
        return this.additionalGuards;
    }
    getActivationKind() {
        return this.activationKind;
    }
    getFixedVariables() {
        return this.fixedVariables;
    }
    getProbabilisticVariables() {
        return this.probabilisticVariables;
    }
    getFiringTransitionParameters() {
        return this.firingTransitionParameters;
    }
    getFiringTransitionParametersPredicate() {
        return this.firingTransitionParametersPredicate;
    }
    equals(other) {
        return (this.operation === other.operation &&
            this.time === other.time &&
            this.additionalGuards === other.additionalGuards &&
            this.activationKind === other.activationKind &&
            this.probabilisticVariables === other.probabilisticVariables &&
            this.firingTransitionParameters === other.firingTransitionParameters &&
            this.firingTransitionParametersPredicate ===
                other.firingTransitionParametersPredicate);
    }
}
