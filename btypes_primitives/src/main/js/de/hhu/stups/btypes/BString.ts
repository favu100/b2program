import {BObject} from "./BObject";
import {BBoolean} from "./BBoolean";

export class BString implements BObject {
	value: string;

	constructor(value: string) {
		this.value = value;
	}

	getValue() {
		return this.value;
	}

	equals(o): boolean {
		if (this == o)
			return true;
		if (o == null || o !instanceof BString)
			return false;

		return this.value === o.value;
	}

	length(): number {
		return this.value.length;
	}

	isEmpty(): boolean {
		return this.value === "";
	}

	toString(): string {
		return '"' + this.value + '"';
	}

	isCase(o): boolean {
		return this.value === o;
	}

	isString(): BBoolean {
		return new BBoolean(true);
	}

	isNotString(): BBoolean {
		return new BBoolean(false);
	}
}
