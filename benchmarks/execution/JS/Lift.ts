import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BUtils} from "./btypes/BUtils.js";



export default class Lift {




    private floor: BInteger;

    constructor() {
        this.floor = new BInteger(0);
    }

     inc(): void {
        this.floor = this.floor.plus(new BInteger(1));
    }

     dec(): void {
        this.floor = this.floor.minus(new BInteger(1));
    }

    _get_floor(): BInteger {
        return this.floor;
    }


}

