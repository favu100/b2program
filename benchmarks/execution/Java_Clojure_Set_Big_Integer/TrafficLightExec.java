import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class TrafficLightExec {


    private TrafficLight _TrafficLight = new TrafficLight();



    private BInteger counter;

    public TrafficLightExec() {
        counter = new BInteger("0");
    }

    public void simulate() {
        while((counter.less(new BInteger("300000000"))).booleanValue()) {
            this._TrafficLight.cars_ry();
            this._TrafficLight.cars_g();
            this._TrafficLight.cars_y();
            this._TrafficLight.cars_r();
            this._TrafficLight.peds_g();
            this._TrafficLight.peds_r();
            counter = counter.plus(new BInteger("1"));
        }
    }

    public BInteger getCounter() {
        BInteger out = null;
        out = counter;
        return out;
    }

    public static void main(String[] args) {
        TrafficLightExec exec = new TrafficLightExec();
        exec.simulate();
    }

}
