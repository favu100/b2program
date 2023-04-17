import {ActivationKind} from "./ActivationKind.js";

export class Activation {

    private operation: string;
    private time: number;
    private additionalGuards: string;
    private activationKind: ActivationKind;
    private fixedVariables: Map<string, string>;
    private probabilisticVariables: any;
    private firingTransitionParameters: Array<string>;
    private firingTransitionParametersPredicate: string;

    constructor(operation: string, time: number, additionalGuards: string, activationKind: ActivationKind,
                fixedVariables: Map<string, string>, probabilisticVariables: any,
                firingTransitionParameters: Array<string>, firingTransitionParametersPredicate: string) {
        this.operation = operation;
        this.time = time;
        this.additionalGuards = additionalGuards;
        this.activationKind = activationKind;
        this.fixedVariables = fixedVariables;
        this.probabilisticVariables = probabilisticVariables;
        this.firingTransitionParameters = firingTransitionParameters;
        this.firingTransitionParametersPredicate = firingTransitionParametersPredicate;
    }

    decreaseTime(delta: number): void {
        this.time -= delta;
    }

    getOperation(): string {
        return this.operation;
    }

    getTime(): number {
        return this.time;
    }

    getAdditionalGuards(): string {
        return this.additionalGuards;
    }

    getActivationKind(): ActivationKind {
        return this.activationKind;
    }

    getFixedVariables(): Map<string, string> {
        return this.fixedVariables;
    }

    getProbabilisticVariables(): any {
        return this.probabilisticVariables;
    }

    getFiringTransitionParameters(): Array<string> {
        return this.firingTransitionParameters;
    }

    getFiringTransitionParametersPredicate(): string {
        return this.firingTransitionParametersPredicate;
    }

    equals(other: Activation): boolean {
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
