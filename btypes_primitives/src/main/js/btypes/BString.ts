import {BObject} from "./BObject.js";
import {BBoolean} from "./BBoolean.js";

export class BString implements BObject {
	value: string;

	constructor(value: string) {
		this.value = value;
	}

	getValue() {
		return this.value;
	}

	equals(o: any): boolean {
		if (o == null || o !instanceof BString) {
			return false;
		}

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

	isCase(o:any): boolean {
		return this.value == o;
	}

	isString(): BBoolean {
		return new BBoolean(true);
	}

	isNotString(): BBoolean {
		return new BBoolean(false);
	}

	hashCode(): number {
		let hash = 0;
		if (this.value.length === 0) {
			return hash;
		}
		for (let i = 0; i < this.value.length; i++) {
			let chr   = this.value.charCodeAt(i);
			hash  = ((hash << 5) - hash) + chr;
			hash |= 0; // Convert to 32bit integer
		}
		return hash;
	};
}
