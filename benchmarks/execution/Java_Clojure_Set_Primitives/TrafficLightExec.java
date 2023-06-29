import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
import de.hhu.stups.btypes.BUtils;


public class TrafficLightExec {




    private TrafficLight _TrafficLight = new TrafficLight();



    private BInteger counter;

    public TrafficLightExec() {
        counter = new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(500000))).booleanValue()) {
            this._TrafficLight.cars_ry();
            this._TrafficLight.cars_g();
            this._TrafficLight.cars_y();
            this._TrafficLight.cars_r();
            this._TrafficLight.peds_g();
            this._TrafficLight.peds_r();
            counter = counter.plus(new BInteger(1));
        }
    }

    public BInteger getCounter() {
        BInteger out = null;
        out = counter;
        return out;
    }

    public BInteger _get_counter() {
        return counter;
    }


    public static void main(String[] args) {
        TrafficLightExec traffic = new TrafficLightExec();
        traffic.simulate();;
        System.out.println(traffic.getCounter());
    }

}
