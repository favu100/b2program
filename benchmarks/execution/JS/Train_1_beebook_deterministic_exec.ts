import {BInteger} from './btypes/BInteger.js';
import {BBoolean} from './btypes/BBoolean.js';
import {BObject} from './btypes/BObject.js';
import {enum_BLOCKS} from "./Train_1_beebook_deterministic.js"
import {BLOCKS} from "./Train_1_beebook_deterministic.js"
import {enum_ROUTES} from "./Train_1_beebook_deterministic.js"
import {ROUTES} from "./Train_1_beebook_deterministic.js"
import Train_1_beebook_deterministic from './Train_1_beebook_deterministic.js';
import {BUtils} from "./btypes/BUtils.js";
import {SelectError} from "./btypes/BUtils.js";



export default class Train_1_beebook_deterministic_exec {

    _Train_1_beebook_deterministic: Train_1_beebook_deterministic = new Train_1_beebook_deterministic();



    private counter: BInteger;

    constructor() {
        this.counter = new BInteger(0);
    }


     simulate(): void {
        while((this.counter.less(new BInteger(10000))).booleanValue()) {
            this._Train_1_beebook_deterministic.route_reservation(new ROUTES(enum_ROUTES.R1));
            this._Train_1_beebook_deterministic.route_reservation(new ROUTES(enum_ROUTES.R4));
            this._Train_1_beebook_deterministic.point_positionning(new ROUTES(enum_ROUTES.R1));
            this._Train_1_beebook_deterministic.point_positionning(new ROUTES(enum_ROUTES.R4));
            this._Train_1_beebook_deterministic.route_formation(new ROUTES(enum_ROUTES.R1));
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(new ROUTES(enum_ROUTES.R1));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.L));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.A));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.B));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.L));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.A));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.B));
            this._Train_1_beebook_deterministic.BACK_MOVE_1(new BLOCKS(enum_BLOCKS.C));
            this._Train_1_beebook_deterministic.route_reservation(new ROUTES(enum_ROUTES.R6));
            this._Train_1_beebook_deterministic.route_freeing(new ROUTES(enum_ROUTES.R1));
            this._Train_1_beebook_deterministic.route_formation(new ROUTES(enum_ROUTES.R4));
            this._Train_1_beebook_deterministic.point_positionning(new ROUTES(enum_ROUTES.R6));
            this._Train_1_beebook_deterministic.route_formation(new ROUTES(enum_ROUTES.R6));
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(new ROUTES(enum_ROUTES.R4));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.M));
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(new ROUTES(enum_ROUTES.R6));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.C));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.H));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.C));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.M));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.I));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.H));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.B));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.B));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.I));
            this._Train_1_beebook_deterministic.route_reservation(new ROUTES(enum_ROUTES.R5));
            this._Train_1_beebook_deterministic.point_positionning(new ROUTES(enum_ROUTES.R5));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.A));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.K));
            this._Train_1_beebook_deterministic.route_formation(new ROUTES(enum_ROUTES.R5));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.A));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.K));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.F));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.F));
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(new ROUTES(enum_ROUTES.R5));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.M));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.M));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.H));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.H));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.I));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.J));
            this._Train_1_beebook_deterministic.BACK_MOVE_1(new BLOCKS(enum_BLOCKS.L));
            this._Train_1_beebook_deterministic.BACK_MOVE_1(new BLOCKS(enum_BLOCKS.G));
            this._Train_1_beebook_deterministic.route_reservation(new ROUTES(enum_ROUTES.R1));
            this._Train_1_beebook_deterministic.point_positionning(new ROUTES(enum_ROUTES.R1));
            this._Train_1_beebook_deterministic.route_formation(new ROUTES(enum_ROUTES.R1));
            this._Train_1_beebook_deterministic.route_freeing(new ROUTES(enum_ROUTES.R4));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.I));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.J));
            this._Train_1_beebook_deterministic.route_freeing(new ROUTES(enum_ROUTES.R6));
            this._Train_1_beebook_deterministic.route_reservation(new ROUTES(enum_ROUTES.R9));
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(new ROUTES(enum_ROUTES.R1));
            this._Train_1_beebook_deterministic.BACK_MOVE_1(new BLOCKS(enum_BLOCKS.N));
            this._Train_1_beebook_deterministic.point_positionning(new ROUTES(enum_ROUTES.R9));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.L));
            this._Train_1_beebook_deterministic.route_formation(new ROUTES(enum_ROUTES.R9));
            this._Train_1_beebook_deterministic.route_freeing(new ROUTES(enum_ROUTES.R5));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.L));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.A));
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(new ROUTES(enum_ROUTES.R9));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.B));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.G));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.A));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.G));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.B));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.F));
            this._Train_1_beebook_deterministic.BACK_MOVE_1(new BLOCKS(enum_BLOCKS.C));
            this._Train_1_beebook_deterministic.route_reservation(new ROUTES(enum_ROUTES.R6));
            this._Train_1_beebook_deterministic.point_positionning(new ROUTES(enum_ROUTES.R6));
            this._Train_1_beebook_deterministic.route_formation(new ROUTES(enum_ROUTES.R6));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.F));
            this._Train_1_beebook_deterministic.route_freeing(new ROUTES(enum_ROUTES.R1));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.K));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.I));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.H));
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(new ROUTES(enum_ROUTES.R6));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.C));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.B));
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(new BLOCKS(enum_BLOCKS.A));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.K));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.I));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.H));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.C));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.B));
            this._Train_1_beebook_deterministic.BACK_MOVE_2(new BLOCKS(enum_BLOCKS.A));
            this._Train_1_beebook_deterministic.BACK_MOVE_1(new BLOCKS(enum_BLOCKS.L));
            this._Train_1_beebook_deterministic.BACK_MOVE_1(new BLOCKS(enum_BLOCKS.M));
            this._Train_1_beebook_deterministic.route_freeing(new ROUTES(enum_ROUTES.R6));
            this._Train_1_beebook_deterministic.route_freeing(new ROUTES(enum_ROUTES.R9));
            this.counter = this.counter.plus(new BInteger(1));
        }
    }

    _get_counter(): BInteger {
        return this.counter;
    }


}

let exec: Train_1_beebook_deterministic_exec = new Train_1_beebook_deterministic_exec();
exec.simulate();