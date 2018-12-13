import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class TrafficLightExec {



    private TrafficLight TrafficLight = new TrafficLight();



    private BInteger counter;

    public TrafficLightExec() {
        counter = (BInteger) new BInteger(0);
    }

    public void simulate() {
        while((counter.less(new BInteger(500000))).booleanValue()) {
            this.TrafficLight.cars_ry();
            this.TrafficLight.cars_g();
            this.TrafficLight.cars_y();
            this.TrafficLight.cars_r();
            this.TrafficLight.peds_g();
            this.TrafficLight.peds_r();
            counter = (BInteger) counter.plus(new BInteger(1));
        }
    }

    public static void main(String[] args) {
        TrafficLightExec exec = new TrafficLightExec();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));
    }

}
