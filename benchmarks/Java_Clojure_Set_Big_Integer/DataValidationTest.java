import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class DataValidationTest {

    private final BInteger n;
    private final BSet<BInteger> ids;
    private final BRelation<BInteger, BInteger> value;
    private final BRelation<BInteger, BInteger> ids_for_value;




    private BInteger counter;
    private BBoolean error;
    private BBoolean checked;

    public DataValidationTest() {
        n = new BInteger("20000");
        ids = BSet.interval(new BInteger("1"),n);
        BRelation<BInteger, BInteger> _ic_set_0 = new BRelation<BInteger, BInteger>();
        for(BInteger _ic_x : BSet.interval(new BInteger("1"),n)) {
            _ic_set_0 = _ic_set_0.union(new BRelation<BInteger, BInteger>(new BTuple<>(_ic_x, _ic_x.modulo(new BInteger("100")))));

        }
        value = _ic_set_0;
        ids_for_value = value.inverse();
        counter = new BInteger("0");
        error = new BBoolean(false);
        checked = new BBoolean(false);
    }

    public void Validate() {
        BSet<BInteger> interval = BSet.interval(new BInteger("0"),new BInteger("9"));
        while((counter.less(n)).booleanValue()) {
            counter = counter.plus(new BInteger("1"));
            if((ids.notElementOf(counter)).booleanValue()) {
                error = new BBoolean(false);
            } else if((interval.notElementOf(value.functionCall(counter))).booleanValue()) {
                error = new BBoolean(false);
            } else if((ids_for_value.relationImage(new BSet<BInteger>(value.functionCall(counter))).card().less(n.divide(new BInteger("100")))).booleanValue()) {
                error = new BBoolean(false);
            }
        }
        checked = new BBoolean(true);
    }

    public static void main(String[] args) {
        DataValidationTest validationTest = new DataValidationTest();
        validationTest.Validate();
    }

}
