import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class sort_m2_data1000_exec {


    private sort_m2_data1000 _sort_m2_data1000 = new sort_m2_data1000();



    private BInteger counter;
    private BInteger sorted;

    public sort_m2_data1000_exec() {
        counter = new BInteger(0);
        sorted = new BInteger(0);
    }

    public void simulate() {
        while((sorted.less(new BInteger(500))).booleanValue()) {
            counter = new BInteger(0);
            while((counter.less(new BInteger(999).minus(new BInteger(2).multiply(sorted)))).booleanValue()) {
                this._sort_m2_data1000.prog2();
                counter = counter.plus(new BInteger(1));
            }
            counter = new BInteger(0);
            while((counter.less(sorted)).booleanValue()) {
                this._sort_m2_data1000.prog1();
                counter = counter.plus(new BInteger(1));
            }
            this._sort_m2_data1000.progress();
            sorted = sorted.plus(new BInteger(1));
        }
        while((sorted.less(new BInteger(999))).booleanValue()) {
            counter = new BInteger(0);
            while((counter.less(new BInteger(999).minus(sorted))).booleanValue()) {
                this._sort_m2_data1000.prog1();
                counter = counter.plus(new BInteger(1));
            }
            this._sort_m2_data1000.progress();
            sorted = sorted.plus(new BInteger(1));
        }
        this._sort_m2_data1000.final_evt();
    }

    public static void main(String[] args) {
        sort_m2_data1000_exec exec = new sort_m2_data1000_exec();
        exec.simulate();
    }

}
