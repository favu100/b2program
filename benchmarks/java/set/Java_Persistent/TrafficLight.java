import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class TrafficLight {




    public enum colors implements BObject {
        red, 
        redyellow, 
        yellow, 
        green;

        public BBoolean equal(colors o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(colors o) {
            return new BBoolean(this != o);
        }
    }

    private BSet _colors = new BSet(colors.red, colors.redyellow, colors.yellow, colors.green);

    private colors tl_cars;
    private colors tl_peds;

    public TrafficLight() {
        tl_cars = (colors) colors.red;
        tl_peds = (colors) colors.red;
    }

    public void cars_ry() {
        if((tl_cars.equal(colors.red).and(tl_peds.equal(colors.red))).booleanValue()) {
            tl_cars = (colors) colors.redyellow;
        } else {
            throw new RuntimeException("Invocation of the operation is not possible");
        }
    }

    public void cars_y() {
        if((tl_cars.equal(colors.green).and(tl_peds.equal(colors.red))).booleanValue()) {
            tl_cars = (colors) colors.yellow;
        } else {
            throw new RuntimeException("Invocation of the operation is not possible");
        }
    }

    public void cars_g() {
        if((tl_cars.equal(colors.redyellow).and(tl_peds.equal(colors.red))).booleanValue()) {
            tl_cars = (colors) colors.green;
        } else {
            throw new RuntimeException("Invocation of the operation is not possible");
        }
    }

    public void cars_r() {
        if((tl_cars.equal(colors.yellow).and(tl_peds.equal(colors.red))).booleanValue()) {
            tl_cars = (colors) colors.red;
        } else {
            throw new RuntimeException("Invocation of the operation is not possible");
        }
    }

    public void peds_r() {
        if((tl_peds.equal(colors.green).and(tl_cars.equal(colors.red))).booleanValue()) {
            tl_peds = (colors) colors.red;
        } else {
            throw new RuntimeException("Invocation of the operation is not possible");
        }
    }

    public void peds_g() {
        if((tl_peds.equal(colors.red).and(tl_cars.equal(colors.red))).booleanValue()) {
            tl_peds = (colors) colors.green;
        } else {
            throw new RuntimeException("Invocation of the operation is not possible");
        }
    }



}
