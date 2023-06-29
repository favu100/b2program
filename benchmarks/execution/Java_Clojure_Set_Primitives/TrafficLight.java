import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BBoolean;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
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

    private static BSet<colors> _colors = new BSet<colors>(colors.red, colors.redyellow, colors.yellow, colors.green);

    private colors tl_cars;
    private colors tl_peds;

    public TrafficLight() {
        tl_cars = colors.red;
        tl_peds = colors.red;
    }

    public void cars_ry() {
        if((new BBoolean(tl_cars.equal(colors.red).booleanValue() && tl_peds.equal(colors.red).booleanValue())).booleanValue()) {
            tl_cars = colors.redyellow;
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void cars_y() {
        if((new BBoolean(tl_cars.equal(colors.green).booleanValue() && tl_peds.equal(colors.red).booleanValue())).booleanValue()) {
            tl_cars = colors.yellow;
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void cars_g() {
        if((new BBoolean(tl_cars.equal(colors.redyellow).booleanValue() && tl_peds.equal(colors.red).booleanValue())).booleanValue()) {
            tl_cars = colors.green;
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void cars_r() {
        if((new BBoolean(tl_cars.equal(colors.yellow).booleanValue() && tl_peds.equal(colors.red).booleanValue())).booleanValue()) {
            tl_cars = colors.red;
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void peds_r() {
        if((new BBoolean(tl_peds.equal(colors.green).booleanValue() && tl_cars.equal(colors.red).booleanValue())).booleanValue()) {
            tl_peds = colors.red;
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public void peds_g() {
        if((new BBoolean(tl_peds.equal(colors.red).booleanValue() && tl_cars.equal(colors.red).booleanValue())).booleanValue()) {
            tl_peds = colors.green;
        } else {
            throw new StateNotReachableError("State is not reachable.");
        }

    }

    public colors _get_tl_cars() {
        return tl_cars;
    }

    public colors _get_tl_peds() {
        return tl_peds;
    }

    public BSet<colors> _get__colors() {
        return _colors;
    }



}
