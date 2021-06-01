import {BBoolean} from "./BBoolean.js";
import {BObject} from "./BObject.js";

export class BTuple<S extends BObject,T extends BObject> implements BObject {

	first: S;

	second: T;

	constructor(first: S, second: T) {
		if (first == null || second == null) {
			throw new RangeError("Arguments of Tuple cant be null or undefined");
		}
		this.first = first;
		this.second = second;
	}


	equals(o: any): boolean {
		if (o == null || !(o instanceof BTuple)) {
			return false;
		}
		return o.projection1().equals(this.first) && o.projection2().equals(this.second);
	}

	toString(): string {
		return "(" + this.projection1() + " |-> " + this.projection2() + ')';
	}

	projection1(): S {
		return this.first;
	}

	projection2(): T {
		return this.second;
	}

	equal(o: BTuple<S, T>): BBoolean {
		return new BBoolean(this.equals(o));
	}

	unequal(o: BTuple<S, T>): BBoolean {
		return new BBoolean(!this.equals(o));
	}

	hashCode(): number {
		return this.first.hashCode() ^ (this.second.hashCode() << 1);
	}

}
