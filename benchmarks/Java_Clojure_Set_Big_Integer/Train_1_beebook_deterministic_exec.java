import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class Train_1_beebook_deterministic_exec {


    private Train_1_beebook_deterministic _Train_1_beebook_deterministic = new Train_1_beebook_deterministic();



    private BInteger counter;

    public Train_1_beebook_deterministic_exec() {
        counter = new BInteger("0");
    }

    public void simulate() {
        while((counter.less(new BInteger("10000"))).booleanValue()) {
            this._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic.ROUTES.R1);
            this._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic.ROUTES.R4);
            this._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic.ROUTES.R1);
            this._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic.ROUTES.R4);
            this._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic.ROUTES.R1);
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic.ROUTES.R1);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.L);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.A);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.B);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.L);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.A);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.B);
            this._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic.BLOCKS.C);
            this._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic.ROUTES.R6);
            this._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic.ROUTES.R1);
            this._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic.ROUTES.R4);
            this._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic.ROUTES.R6);
            this._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic.ROUTES.R6);
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic.ROUTES.R4);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.M);
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic.ROUTES.R6);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.C);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.H);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.C);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.M);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.I);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.H);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.B);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.B);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.I);
            this._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic.ROUTES.R5);
            this._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic.ROUTES.R5);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.A);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.K);
            this._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic.ROUTES.R5);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.A);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.K);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.F);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.F);
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic.ROUTES.R5);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.M);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.M);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.H);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.H);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.I);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.J);
            this._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic.BLOCKS.L);
            this._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic.BLOCKS.G);
            this._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic.ROUTES.R1);
            this._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic.ROUTES.R1);
            this._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic.ROUTES.R1);
            this._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic.ROUTES.R4);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.I);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.J);
            this._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic.ROUTES.R6);
            this._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic.ROUTES.R9);
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic.ROUTES.R1);
            this._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic.BLOCKS.N);
            this._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic.ROUTES.R9);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.L);
            this._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic.ROUTES.R9);
            this._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic.ROUTES.R5);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.L);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.A);
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic.ROUTES.R9);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.B);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.G);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.A);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.G);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.B);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.F);
            this._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic.BLOCKS.C);
            this._Train_1_beebook_deterministic.route_reservation(Train_1_beebook_deterministic.ROUTES.R6);
            this._Train_1_beebook_deterministic.point_positionning(Train_1_beebook_deterministic.ROUTES.R6);
            this._Train_1_beebook_deterministic.route_formation(Train_1_beebook_deterministic.ROUTES.R6);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.F);
            this._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic.ROUTES.R1);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.K);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.I);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.H);
            this._Train_1_beebook_deterministic.FRONT_MOVE_1(Train_1_beebook_deterministic.ROUTES.R6);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.C);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.B);
            this._Train_1_beebook_deterministic.FRONT_MOVE_2(Train_1_beebook_deterministic.BLOCKS.A);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.K);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.I);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.H);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.C);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.B);
            this._Train_1_beebook_deterministic.BACK_MOVE_2(Train_1_beebook_deterministic.BLOCKS.A);
            this._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic.BLOCKS.L);
            this._Train_1_beebook_deterministic.BACK_MOVE_1(Train_1_beebook_deterministic.BLOCKS.M);
            this._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic.ROUTES.R6);
            this._Train_1_beebook_deterministic.route_freeing(Train_1_beebook_deterministic.ROUTES.R9);
            counter = counter.plus(new BInteger("1"));
        }
    }

    public static void main(String[] args) {
        Train_1_beebook_deterministic_exec exec = new Train_1_beebook_deterministic_exec();
        exec.simulate();
    }

}
