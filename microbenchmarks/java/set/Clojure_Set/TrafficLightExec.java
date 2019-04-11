import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
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

    public static void main(String[] args) {
        TrafficLightExec exec = new TrafficLightExec();
        long start = System.nanoTime();
        exec.simulate();
        long end = System.nanoTime();
        System.out.println(exec.getClass().toString() + " Execution: " + (end - start));

        Runtime runtime = Runtime.getRuntime();
        long memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Used memory is bytes: " + memory);
        System.out.println("Used memory is megabytes: "
                + (memory / (1024L * 1024L)));
    }

}
