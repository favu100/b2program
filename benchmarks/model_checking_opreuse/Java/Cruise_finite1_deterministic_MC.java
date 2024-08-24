import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.Future;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import clojure.java.api.Clojure;
import clojure.lang.PersistentHashMap;
import clojure.lang.RT;
import clojure.lang.Var;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
import de.hhu.stups.btypes.LoopInvariantViolation;
import de.hhu.stups.btypes.VariantViolation;
import de.hhu.stups.btypes.BUtils;


public class Cruise_finite1_deterministic_MC {


    private static final Var ASSOC;
    private static final Var GET;

    static {
        RT.var("clojure.core", "require").invoke(Clojure.read("clojure.set"));
        ASSOC = RT.var("clojure.core", "assoc");
        GET = RT.var("clojure.core", "get");
    }

    public static enum Type {
        BFS,
        DFS,
        MIXED
    }

    public Cruise_finite1_deterministic_MC parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_CruiseBecomesNotAllowed {

        public BBoolean CruiseAllowed;

        public _ProjectionRead_CruiseBecomesNotAllowed(BBoolean CruiseAllowed) {
            this.CruiseAllowed = CruiseAllowed;
        }

        public String toString() {
            return "{" + "CruiseAllowed: " + this.CruiseAllowed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_CruiseBecomesNotAllowed)) {
                return false;
            }
            _ProjectionRead_CruiseBecomesNotAllowed o = (_ProjectionRead_CruiseBecomesNotAllowed) other;
            return this.CruiseAllowed.equals(o.CruiseAllowed);
        }

        public int hashCode() {
            return Objects.hash(CruiseAllowed);
        }
    }

    public static class _ProjectionRead__tr_CruiseBecomesNotAllowed {

        public BBoolean CruiseAllowed;

        public _ProjectionRead__tr_CruiseBecomesNotAllowed(BBoolean CruiseAllowed) {
            this.CruiseAllowed = CruiseAllowed;
        }

        public String toString() {
            return "{" + "CruiseAllowed: " + this.CruiseAllowed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_CruiseBecomesNotAllowed)) {
                return false;
            }
            _ProjectionRead__tr_CruiseBecomesNotAllowed o = (_ProjectionRead__tr_CruiseBecomesNotAllowed) other;
            return this.CruiseAllowed.equals(o.CruiseAllowed);
        }

        public int hashCode() {
            return Objects.hash(CruiseAllowed);
        }
    }

    public static class _ProjectionWrite_CruiseBecomesNotAllowed {

        public BBoolean VehicleTryKeepSpeed;
        public BBoolean CruiseSpeedAtMax;
        public BBoolean CruiseActive;
        public BBoolean VehicleAtCruiseSpeed;
        public BBoolean CruiseAllowed;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BInteger NumberOfSetCruise;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;
        public BBoolean VehicleCanKeepSpeed;
        public ODset ObstacleDistance;

        public _ProjectionWrite_CruiseBecomesNotAllowed(BBoolean VehicleTryKeepSpeed, BBoolean CruiseSpeedAtMax, BBoolean CruiseActive, BBoolean VehicleAtCruiseSpeed, BBoolean CruiseAllowed, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BInteger NumberOfSetCruise, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress, BBoolean VehicleCanKeepSpeed, ODset ObstacleDistance) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.CruiseSpeedAtMax = CruiseSpeedAtMax;
            this.CruiseActive = CruiseActive;
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this.CruiseAllowed = CruiseAllowed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.NumberOfSetCruise = NumberOfSetCruise;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "CruiseSpeedAtMax: " + this.CruiseSpeedAtMax + "," + "CruiseActive: " + this.CruiseActive + "," + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "," + "CruiseAllowed: " + this.CruiseAllowed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "NumberOfSetCruise: " + this.NumberOfSetCruise + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_CruiseBecomesNotAllowed)) {
                return false;
            }
            _ProjectionWrite_CruiseBecomesNotAllowed o = (_ProjectionWrite_CruiseBecomesNotAllowed) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.CruiseSpeedAtMax.equals(o.CruiseSpeedAtMax) && this.CruiseActive.equals(o.CruiseActive) && this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed) && this.CruiseAllowed.equals(o.CruiseAllowed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.NumberOfSetCruise.equals(o.NumberOfSetCruise) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, CruiseSpeedAtMax, CruiseActive, VehicleAtCruiseSpeed, CruiseAllowed, ObstacleStatusJustChanged, CCInitialisationInProgress, NumberOfSetCruise, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress, VehicleCanKeepSpeed, ObstacleDistance);
        }
    }

    public static class _ProjectionRead_CruiseBecomesAllowed {

        public BBoolean CruiseAllowed;

        public _ProjectionRead_CruiseBecomesAllowed(BBoolean CruiseAllowed) {
            this.CruiseAllowed = CruiseAllowed;
        }

        public String toString() {
            return "{" + "CruiseAllowed: " + this.CruiseAllowed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_CruiseBecomesAllowed)) {
                return false;
            }
            _ProjectionRead_CruiseBecomesAllowed o = (_ProjectionRead_CruiseBecomesAllowed) other;
            return this.CruiseAllowed.equals(o.CruiseAllowed);
        }

        public int hashCode() {
            return Objects.hash(CruiseAllowed);
        }
    }

    public static class _ProjectionRead__tr_CruiseBecomesAllowed {

        public BBoolean CruiseAllowed;

        public _ProjectionRead__tr_CruiseBecomesAllowed(BBoolean CruiseAllowed) {
            this.CruiseAllowed = CruiseAllowed;
        }

        public String toString() {
            return "{" + "CruiseAllowed: " + this.CruiseAllowed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_CruiseBecomesAllowed)) {
                return false;
            }
            _ProjectionRead__tr_CruiseBecomesAllowed o = (_ProjectionRead__tr_CruiseBecomesAllowed) other;
            return this.CruiseAllowed.equals(o.CruiseAllowed);
        }

        public int hashCode() {
            return Objects.hash(CruiseAllowed);
        }
    }

    public static class _ProjectionWrite_CruiseBecomesAllowed {

        public BBoolean CruiseAllowed;

        public _ProjectionWrite_CruiseBecomesAllowed(BBoolean CruiseAllowed) {
            this.CruiseAllowed = CruiseAllowed;
        }

        public String toString() {
            return "{" + "CruiseAllowed: " + this.CruiseAllowed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_CruiseBecomesAllowed)) {
                return false;
            }
            _ProjectionWrite_CruiseBecomesAllowed o = (_ProjectionWrite_CruiseBecomesAllowed) other;
            return this.CruiseAllowed.equals(o.CruiseAllowed);
        }

        public int hashCode() {
            return Objects.hash(CruiseAllowed);
        }
    }

    public static class _ProjectionRead_SetCruiseSpeed {

        public BBoolean CruiseActive;
        public BBoolean CruiseAllowed;
        public BBoolean SpeedAboveMax;
        public BInteger NumberOfSetCruise;

        public _ProjectionRead_SetCruiseSpeed(BBoolean CruiseActive, BBoolean CruiseAllowed, BBoolean SpeedAboveMax, BInteger NumberOfSetCruise) {
            this.CruiseActive = CruiseActive;
            this.CruiseAllowed = CruiseAllowed;
            this.SpeedAboveMax = SpeedAboveMax;
            this.NumberOfSetCruise = NumberOfSetCruise;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "CruiseAllowed: " + this.CruiseAllowed + "," + "SpeedAboveMax: " + this.SpeedAboveMax + "," + "NumberOfSetCruise: " + this.NumberOfSetCruise + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_SetCruiseSpeed)) {
                return false;
            }
            _ProjectionRead_SetCruiseSpeed o = (_ProjectionRead_SetCruiseSpeed) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.CruiseAllowed.equals(o.CruiseAllowed) && this.SpeedAboveMax.equals(o.SpeedAboveMax) && this.NumberOfSetCruise.equals(o.NumberOfSetCruise);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, CruiseAllowed, SpeedAboveMax, NumberOfSetCruise);
        }
    }

    public static class _ProjectionRead__tr_SetCruiseSpeed {

        public BBoolean CruiseAllowed;

        public _ProjectionRead__tr_SetCruiseSpeed(BBoolean CruiseAllowed) {
            this.CruiseAllowed = CruiseAllowed;
        }

        public String toString() {
            return "{" + "CruiseAllowed: " + this.CruiseAllowed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_SetCruiseSpeed)) {
                return false;
            }
            _ProjectionRead__tr_SetCruiseSpeed o = (_ProjectionRead__tr_SetCruiseSpeed) other;
            return this.CruiseAllowed.equals(o.CruiseAllowed);
        }

        public int hashCode() {
            return Objects.hash(CruiseAllowed);
        }
    }

    public static class _ProjectionWrite_SetCruiseSpeed {

        public BBoolean CruiseSpeedAtMax;
        public BBoolean CruiseActive;
        public BBoolean VehicleAtCruiseSpeed;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BInteger NumberOfSetCruise;
        public BBoolean CruiseSpeedChangeInProgress;
        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionWrite_SetCruiseSpeed(BBoolean CruiseSpeedAtMax, BBoolean CruiseActive, BBoolean VehicleAtCruiseSpeed, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BInteger NumberOfSetCruise, BBoolean CruiseSpeedChangeInProgress, BBoolean VehicleCanKeepSpeed) {
            this.CruiseSpeedAtMax = CruiseSpeedAtMax;
            this.CruiseActive = CruiseActive;
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.NumberOfSetCruise = NumberOfSetCruise;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "CruiseSpeedAtMax: " + this.CruiseSpeedAtMax + "," + "CruiseActive: " + this.CruiseActive + "," + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "NumberOfSetCruise: " + this.NumberOfSetCruise + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_SetCruiseSpeed)) {
                return false;
            }
            _ProjectionWrite_SetCruiseSpeed o = (_ProjectionWrite_SetCruiseSpeed) other;
            return this.CruiseSpeedAtMax.equals(o.CruiseSpeedAtMax) && this.CruiseActive.equals(o.CruiseActive) && this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.NumberOfSetCruise.equals(o.NumberOfSetCruise) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(CruiseSpeedAtMax, CruiseActive, VehicleAtCruiseSpeed, ObstacleStatusJustChanged, CCInitialisationInProgress, NumberOfSetCruise, CruiseSpeedChangeInProgress, VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionRead_CCInitialisationFinished {

        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public ODset ObstacleDistance;
        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;
        public BBoolean CruiseSpeedChangeInProgress;

        public _ProjectionRead_CCInitialisationFinished(BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, ODset ObstacleDistance, RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent, BBoolean CruiseSpeedChangeInProgress) {
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.ObstacleDistance = ObstacleDistance;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        }

        public String toString() {
            return "{" + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_CCInitialisationFinished)) {
                return false;
            }
            _ProjectionRead_CCInitialisationFinished o = (_ProjectionRead_CCInitialisationFinished) other;
            return this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress);
        }

        public int hashCode() {
            return Objects.hash(ObstacleStatusJustChanged, CCInitialisationInProgress, ObstacleDistance, ObstacleRelativeSpeed, ObstaclePresent, CruiseSpeedChangeInProgress);
        }
    }

    public static class _ProjectionRead__tr_CCInitialisationFinished {

        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public ODset ObstacleDistance;
        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;
        public BBoolean CruiseSpeedChangeInProgress;

        public _ProjectionRead__tr_CCInitialisationFinished(BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, ODset ObstacleDistance, RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent, BBoolean CruiseSpeedChangeInProgress) {
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.ObstacleDistance = ObstacleDistance;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        }

        public String toString() {
            return "{" + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_CCInitialisationFinished)) {
                return false;
            }
            _ProjectionRead__tr_CCInitialisationFinished o = (_ProjectionRead__tr_CCInitialisationFinished) other;
            return this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress);
        }

        public int hashCode() {
            return Objects.hash(ObstacleStatusJustChanged, CCInitialisationInProgress, ObstacleDistance, ObstacleRelativeSpeed, ObstaclePresent, CruiseSpeedChangeInProgress);
        }
    }

    public static class _ProjectionWrite_CCInitialisationFinished {

        public BBoolean VehicleTryKeepSpeed;
        public BBoolean VehicleTryKeepTimeGap;

        public _ProjectionWrite_CCInitialisationFinished(BBoolean VehicleTryKeepSpeed, BBoolean VehicleTryKeepTimeGap) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_CCInitialisationFinished)) {
                return false;
            }
            _ProjectionWrite_CCInitialisationFinished o = (_ProjectionWrite_CCInitialisationFinished) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, VehicleTryKeepTimeGap);
        }
    }

    public static class _ProjectionRead_CCInitialisationDelayFinished {

        public BBoolean VehicleTryKeepSpeed;
        public RSset ObstacleRelativeSpeed;
        public BBoolean CCInitialisationInProgress;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;
        public ODset ObstacleDistance;

        public _ProjectionRead_CCInitialisationDelayFinished(BBoolean VehicleTryKeepSpeed, RSset ObstacleRelativeSpeed, BBoolean CCInitialisationInProgress, BBoolean ObstacleStatusJustChanged, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress, ODset ObstacleDistance) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_CCInitialisationDelayFinished)) {
                return false;
            }
            _ProjectionRead_CCInitialisationDelayFinished o = (_ProjectionRead_CCInitialisationDelayFinished) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, ObstacleRelativeSpeed, CCInitialisationInProgress, ObstacleStatusJustChanged, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__tr_CCInitialisationDelayFinished {

        public BBoolean VehicleTryKeepSpeed;
        public RSset ObstacleRelativeSpeed;
        public BBoolean CCInitialisationInProgress;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;
        public ODset ObstacleDistance;

        public _ProjectionRead__tr_CCInitialisationDelayFinished(BBoolean VehicleTryKeepSpeed, RSset ObstacleRelativeSpeed, BBoolean CCInitialisationInProgress, BBoolean ObstacleStatusJustChanged, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress, ODset ObstacleDistance) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_CCInitialisationDelayFinished)) {
                return false;
            }
            _ProjectionRead__tr_CCInitialisationDelayFinished o = (_ProjectionRead__tr_CCInitialisationDelayFinished) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, ObstacleRelativeSpeed, CCInitialisationInProgress, ObstacleStatusJustChanged, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress, ObstacleDistance);
        }
    }

    public static class _ProjectionWrite_CCInitialisationDelayFinished {

        public BBoolean CCInitialisationInProgress;

        public _ProjectionWrite_CCInitialisationDelayFinished(BBoolean CCInitialisationInProgress) {
            this.CCInitialisationInProgress = CCInitialisationInProgress;
        }

        public String toString() {
            return "{" + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_CCInitialisationDelayFinished)) {
                return false;
            }
            _ProjectionWrite_CCInitialisationDelayFinished o = (_ProjectionWrite_CCInitialisationDelayFinished) other;
            return this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress);
        }

        public int hashCode() {
            return Objects.hash(CCInitialisationInProgress);
        }
    }

    public static class _ProjectionRead_CruiseSpeedChangeFinished {

        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public ODset ObstacleDistance;
        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;
        public BBoolean CruiseSpeedChangeInProgress;

        public _ProjectionRead_CruiseSpeedChangeFinished(BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, ODset ObstacleDistance, RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent, BBoolean CruiseSpeedChangeInProgress) {
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.ObstacleDistance = ObstacleDistance;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        }

        public String toString() {
            return "{" + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_CruiseSpeedChangeFinished)) {
                return false;
            }
            _ProjectionRead_CruiseSpeedChangeFinished o = (_ProjectionRead_CruiseSpeedChangeFinished) other;
            return this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress);
        }

        public int hashCode() {
            return Objects.hash(ObstacleStatusJustChanged, CCInitialisationInProgress, ObstacleDistance, ObstacleRelativeSpeed, ObstaclePresent, CruiseSpeedChangeInProgress);
        }
    }

    public static class _ProjectionRead__tr_CruiseSpeedChangeFinished {

        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public ODset ObstacleDistance;
        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;
        public BBoolean CruiseSpeedChangeInProgress;

        public _ProjectionRead__tr_CruiseSpeedChangeFinished(BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, ODset ObstacleDistance, RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent, BBoolean CruiseSpeedChangeInProgress) {
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.ObstacleDistance = ObstacleDistance;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        }

        public String toString() {
            return "{" + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_CruiseSpeedChangeFinished)) {
                return false;
            }
            _ProjectionRead__tr_CruiseSpeedChangeFinished o = (_ProjectionRead__tr_CruiseSpeedChangeFinished) other;
            return this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress);
        }

        public int hashCode() {
            return Objects.hash(ObstacleStatusJustChanged, CCInitialisationInProgress, ObstacleDistance, ObstacleRelativeSpeed, ObstaclePresent, CruiseSpeedChangeInProgress);
        }
    }

    public static class _ProjectionWrite_CruiseSpeedChangeFinished {

        public BBoolean VehicleTryKeepSpeed;
        public BBoolean VehicleTryKeepTimeGap;

        public _ProjectionWrite_CruiseSpeedChangeFinished(BBoolean VehicleTryKeepSpeed, BBoolean VehicleTryKeepTimeGap) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_CruiseSpeedChangeFinished)) {
                return false;
            }
            _ProjectionWrite_CruiseSpeedChangeFinished o = (_ProjectionWrite_CruiseSpeedChangeFinished) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, VehicleTryKeepTimeGap);
        }
    }

    public static class _ProjectionRead_CruiseSpeedChangeDelayFinished {

        public BBoolean VehicleTryKeepSpeed;
        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;
        public ODset ObstacleDistance;

        public _ProjectionRead_CruiseSpeedChangeDelayFinished(BBoolean VehicleTryKeepSpeed, RSset ObstacleRelativeSpeed, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress, ODset ObstacleDistance) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_CruiseSpeedChangeDelayFinished)) {
                return false;
            }
            _ProjectionRead_CruiseSpeedChangeDelayFinished o = (_ProjectionRead_CruiseSpeedChangeDelayFinished) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, ObstacleRelativeSpeed, ObstacleStatusJustChanged, CCInitialisationInProgress, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__tr_CruiseSpeedChangeDelayFinished {

        public BBoolean VehicleTryKeepSpeed;
        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;
        public ODset ObstacleDistance;

        public _ProjectionRead__tr_CruiseSpeedChangeDelayFinished(BBoolean VehicleTryKeepSpeed, RSset ObstacleRelativeSpeed, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress, ODset ObstacleDistance) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_CruiseSpeedChangeDelayFinished)) {
                return false;
            }
            _ProjectionRead__tr_CruiseSpeedChangeDelayFinished o = (_ProjectionRead__tr_CruiseSpeedChangeDelayFinished) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, ObstacleRelativeSpeed, ObstacleStatusJustChanged, CCInitialisationInProgress, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress, ObstacleDistance);
        }
    }

    public static class _ProjectionWrite_CruiseSpeedChangeDelayFinished {

        public BBoolean CruiseSpeedChangeInProgress;

        public _ProjectionWrite_CruiseSpeedChangeDelayFinished(BBoolean CruiseSpeedChangeInProgress) {
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        }

        public String toString() {
            return "{" + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_CruiseSpeedChangeDelayFinished)) {
                return false;
            }
            _ProjectionWrite_CruiseSpeedChangeDelayFinished o = (_ProjectionWrite_CruiseSpeedChangeDelayFinished) other;
            return this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress);
        }

        public int hashCode() {
            return Objects.hash(CruiseSpeedChangeInProgress);
        }
    }

    public static class _ProjectionRead_CruiseOff {

        public BBoolean CruiseActive;

        public _ProjectionRead_CruiseOff(BBoolean CruiseActive) {
            this.CruiseActive = CruiseActive;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_CruiseOff)) {
                return false;
            }
            _ProjectionRead_CruiseOff o = (_ProjectionRead_CruiseOff) other;
            return this.CruiseActive.equals(o.CruiseActive);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive);
        }
    }

    public static class _ProjectionRead__tr_CruiseOff {

        public BBoolean CruiseActive;

        public _ProjectionRead__tr_CruiseOff(BBoolean CruiseActive) {
            this.CruiseActive = CruiseActive;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_CruiseOff)) {
                return false;
            }
            _ProjectionRead__tr_CruiseOff o = (_ProjectionRead__tr_CruiseOff) other;
            return this.CruiseActive.equals(o.CruiseActive);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive);
        }
    }

    public static class _ProjectionWrite_CruiseOff {

        public BBoolean VehicleTryKeepSpeed;
        public BBoolean CruiseSpeedAtMax;
        public BBoolean CruiseActive;
        public BBoolean VehicleAtCruiseSpeed;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BInteger NumberOfSetCruise;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;
        public BBoolean VehicleCanKeepSpeed;
        public ODset ObstacleDistance;

        public _ProjectionWrite_CruiseOff(BBoolean VehicleTryKeepSpeed, BBoolean CruiseSpeedAtMax, BBoolean CruiseActive, BBoolean VehicleAtCruiseSpeed, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BInteger NumberOfSetCruise, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress, BBoolean VehicleCanKeepSpeed, ODset ObstacleDistance) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.CruiseSpeedAtMax = CruiseSpeedAtMax;
            this.CruiseActive = CruiseActive;
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.NumberOfSetCruise = NumberOfSetCruise;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "CruiseSpeedAtMax: " + this.CruiseSpeedAtMax + "," + "CruiseActive: " + this.CruiseActive + "," + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "NumberOfSetCruise: " + this.NumberOfSetCruise + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_CruiseOff)) {
                return false;
            }
            _ProjectionWrite_CruiseOff o = (_ProjectionWrite_CruiseOff) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.CruiseSpeedAtMax.equals(o.CruiseSpeedAtMax) && this.CruiseActive.equals(o.CruiseActive) && this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.NumberOfSetCruise.equals(o.NumberOfSetCruise) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, CruiseSpeedAtMax, CruiseActive, VehicleAtCruiseSpeed, ObstacleStatusJustChanged, CCInitialisationInProgress, NumberOfSetCruise, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress, VehicleCanKeepSpeed, ObstacleDistance);
        }
    }

    public static class _ProjectionRead_ExternalForcesBecomesExtreme {

        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionRead_ExternalForcesBecomesExtreme(BBoolean VehicleCanKeepSpeed) {
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ExternalForcesBecomesExtreme)) {
                return false;
            }
            _ProjectionRead_ExternalForcesBecomesExtreme o = (_ProjectionRead_ExternalForcesBecomesExtreme) other;
            return this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionRead__tr_ExternalForcesBecomesExtreme {

        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionRead__tr_ExternalForcesBecomesExtreme(BBoolean VehicleCanKeepSpeed) {
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ExternalForcesBecomesExtreme)) {
                return false;
            }
            _ProjectionRead__tr_ExternalForcesBecomesExtreme o = (_ProjectionRead__tr_ExternalForcesBecomesExtreme) other;
            return this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionWrite_ExternalForcesBecomesExtreme {

        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionWrite_ExternalForcesBecomesExtreme(BBoolean VehicleCanKeepSpeed) {
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ExternalForcesBecomesExtreme)) {
                return false;
            }
            _ProjectionWrite_ExternalForcesBecomesExtreme o = (_ProjectionWrite_ExternalForcesBecomesExtreme) other;
            return this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionRead_ExternalForcesBecomesNormal {

        public BBoolean CruiseActive;
        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionRead_ExternalForcesBecomesNormal(BBoolean CruiseActive, BBoolean VehicleCanKeepSpeed) {
            this.CruiseActive = CruiseActive;
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ExternalForcesBecomesNormal)) {
                return false;
            }
            _ProjectionRead_ExternalForcesBecomesNormal o = (_ProjectionRead_ExternalForcesBecomesNormal) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionRead__tr_ExternalForcesBecomesNormal {

        public BBoolean CruiseActive;
        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionRead__tr_ExternalForcesBecomesNormal(BBoolean CruiseActive, BBoolean VehicleCanKeepSpeed) {
            this.CruiseActive = CruiseActive;
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ExternalForcesBecomesNormal)) {
                return false;
            }
            _ProjectionRead__tr_ExternalForcesBecomesNormal o = (_ProjectionRead__tr_ExternalForcesBecomesNormal) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionWrite_ExternalForcesBecomesNormal {

        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionWrite_ExternalForcesBecomesNormal(BBoolean VehicleCanKeepSpeed) {
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ExternalForcesBecomesNormal)) {
                return false;
            }
            _ProjectionWrite_ExternalForcesBecomesNormal o = (_ProjectionWrite_ExternalForcesBecomesNormal) other;
            return this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionRead_VehicleLeavesCruiseSpeed {

        public BBoolean VehicleTryKeepSpeed;
        public BBoolean VehicleAtCruiseSpeed;
        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionRead_VehicleLeavesCruiseSpeed(BBoolean VehicleTryKeepSpeed, BBoolean VehicleAtCruiseSpeed, BBoolean VehicleCanKeepSpeed) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "," + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_VehicleLeavesCruiseSpeed)) {
                return false;
            }
            _ProjectionRead_VehicleLeavesCruiseSpeed o = (_ProjectionRead_VehicleLeavesCruiseSpeed) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed) && this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, VehicleAtCruiseSpeed, VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionRead__tr_VehicleLeavesCruiseSpeed {

        public BBoolean VehicleTryKeepSpeed;
        public BBoolean VehicleAtCruiseSpeed;
        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionRead__tr_VehicleLeavesCruiseSpeed(BBoolean VehicleTryKeepSpeed, BBoolean VehicleAtCruiseSpeed, BBoolean VehicleCanKeepSpeed) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "," + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_VehicleLeavesCruiseSpeed)) {
                return false;
            }
            _ProjectionRead__tr_VehicleLeavesCruiseSpeed o = (_ProjectionRead__tr_VehicleLeavesCruiseSpeed) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed) && this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, VehicleAtCruiseSpeed, VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionWrite_VehicleLeavesCruiseSpeed {

        public BBoolean VehicleAtCruiseSpeed;

        public _ProjectionWrite_VehicleLeavesCruiseSpeed(BBoolean VehicleAtCruiseSpeed) {
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        }

        public String toString() {
            return "{" + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_VehicleLeavesCruiseSpeed)) {
                return false;
            }
            _ProjectionWrite_VehicleLeavesCruiseSpeed o = (_ProjectionWrite_VehicleLeavesCruiseSpeed) other;
            return this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleAtCruiseSpeed);
        }
    }

    public static class _ProjectionRead_VehicleReachesCruiseSpeed {

        public BBoolean CruiseActive;
        public BBoolean VehicleAtCruiseSpeed;
        public BBoolean SpeedAboveMax;

        public _ProjectionRead_VehicleReachesCruiseSpeed(BBoolean CruiseActive, BBoolean VehicleAtCruiseSpeed, BBoolean SpeedAboveMax) {
            this.CruiseActive = CruiseActive;
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this.SpeedAboveMax = SpeedAboveMax;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "," + "SpeedAboveMax: " + this.SpeedAboveMax + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_VehicleReachesCruiseSpeed)) {
                return false;
            }
            _ProjectionRead_VehicleReachesCruiseSpeed o = (_ProjectionRead_VehicleReachesCruiseSpeed) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed) && this.SpeedAboveMax.equals(o.SpeedAboveMax);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, VehicleAtCruiseSpeed, SpeedAboveMax);
        }
    }

    public static class _ProjectionRead__tr_VehicleReachesCruiseSpeed {

        public BBoolean CruiseActive;
        public BBoolean VehicleAtCruiseSpeed;
        public BBoolean SpeedAboveMax;

        public _ProjectionRead__tr_VehicleReachesCruiseSpeed(BBoolean CruiseActive, BBoolean VehicleAtCruiseSpeed, BBoolean SpeedAboveMax) {
            this.CruiseActive = CruiseActive;
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this.SpeedAboveMax = SpeedAboveMax;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "," + "SpeedAboveMax: " + this.SpeedAboveMax + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_VehicleReachesCruiseSpeed)) {
                return false;
            }
            _ProjectionRead__tr_VehicleReachesCruiseSpeed o = (_ProjectionRead__tr_VehicleReachesCruiseSpeed) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed) && this.SpeedAboveMax.equals(o.SpeedAboveMax);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, VehicleAtCruiseSpeed, SpeedAboveMax);
        }
    }

    public static class _ProjectionWrite_VehicleReachesCruiseSpeed {

        public BBoolean VehicleAtCruiseSpeed;

        public _ProjectionWrite_VehicleReachesCruiseSpeed(BBoolean VehicleAtCruiseSpeed) {
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        }

        public String toString() {
            return "{" + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_VehicleReachesCruiseSpeed)) {
                return false;
            }
            _ProjectionWrite_VehicleReachesCruiseSpeed o = (_ProjectionWrite_VehicleReachesCruiseSpeed) other;
            return this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleAtCruiseSpeed);
        }
    }

    public static class _ProjectionRead_VehicleExceedsMaxCruiseSpeed {

        public BBoolean CruiseActive;
        public BBoolean SpeedAboveMax;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean CruiseSpeedChangeInProgress;
        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionRead_VehicleExceedsMaxCruiseSpeed(BBoolean CruiseActive, BBoolean SpeedAboveMax, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean CruiseSpeedChangeInProgress, BBoolean VehicleCanKeepSpeed) {
            this.CruiseActive = CruiseActive;
            this.SpeedAboveMax = SpeedAboveMax;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "SpeedAboveMax: " + this.SpeedAboveMax + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_VehicleExceedsMaxCruiseSpeed)) {
                return false;
            }
            _ProjectionRead_VehicleExceedsMaxCruiseSpeed o = (_ProjectionRead_VehicleExceedsMaxCruiseSpeed) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.SpeedAboveMax.equals(o.SpeedAboveMax) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, SpeedAboveMax, ObstacleStatusJustChanged, CCInitialisationInProgress, CruiseSpeedChangeInProgress, VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed {

        public BBoolean CruiseActive;
        public BBoolean SpeedAboveMax;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean CruiseSpeedChangeInProgress;
        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed(BBoolean CruiseActive, BBoolean SpeedAboveMax, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean CruiseSpeedChangeInProgress, BBoolean VehicleCanKeepSpeed) {
            this.CruiseActive = CruiseActive;
            this.SpeedAboveMax = SpeedAboveMax;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "SpeedAboveMax: " + this.SpeedAboveMax + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed)) {
                return false;
            }
            _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed o = (_ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.SpeedAboveMax.equals(o.SpeedAboveMax) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, SpeedAboveMax, ObstacleStatusJustChanged, CCInitialisationInProgress, CruiseSpeedChangeInProgress, VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionWrite_VehicleExceedsMaxCruiseSpeed {

        public BBoolean VehicleAtCruiseSpeed;
        public BBoolean SpeedAboveMax;

        public _ProjectionWrite_VehicleExceedsMaxCruiseSpeed(BBoolean VehicleAtCruiseSpeed, BBoolean SpeedAboveMax) {
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this.SpeedAboveMax = SpeedAboveMax;
        }

        public String toString() {
            return "{" + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "," + "SpeedAboveMax: " + this.SpeedAboveMax + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_VehicleExceedsMaxCruiseSpeed)) {
                return false;
            }
            _ProjectionWrite_VehicleExceedsMaxCruiseSpeed o = (_ProjectionWrite_VehicleExceedsMaxCruiseSpeed) other;
            return this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed) && this.SpeedAboveMax.equals(o.SpeedAboveMax);
        }

        public int hashCode() {
            return Objects.hash(VehicleAtCruiseSpeed, SpeedAboveMax);
        }
    }

    public static class _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed {

        public BBoolean CruiseSpeedAtMax;
        public BBoolean CruiseActive;
        public BBoolean SpeedAboveMax;

        public _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed(BBoolean CruiseSpeedAtMax, BBoolean CruiseActive, BBoolean SpeedAboveMax) {
            this.CruiseSpeedAtMax = CruiseSpeedAtMax;
            this.CruiseActive = CruiseActive;
            this.SpeedAboveMax = SpeedAboveMax;
        }

        public String toString() {
            return "{" + "CruiseSpeedAtMax: " + this.CruiseSpeedAtMax + "," + "CruiseActive: " + this.CruiseActive + "," + "SpeedAboveMax: " + this.SpeedAboveMax + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed)) {
                return false;
            }
            _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed o = (_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed) other;
            return this.CruiseSpeedAtMax.equals(o.CruiseSpeedAtMax) && this.CruiseActive.equals(o.CruiseActive) && this.SpeedAboveMax.equals(o.SpeedAboveMax);
        }

        public int hashCode() {
            return Objects.hash(CruiseSpeedAtMax, CruiseActive, SpeedAboveMax);
        }
    }

    public static class _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed {

        public BBoolean SpeedAboveMax;

        public _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed(BBoolean SpeedAboveMax) {
            this.SpeedAboveMax = SpeedAboveMax;
        }

        public String toString() {
            return "{" + "SpeedAboveMax: " + this.SpeedAboveMax + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed)) {
                return false;
            }
            _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed o = (_ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed) other;
            return this.SpeedAboveMax.equals(o.SpeedAboveMax);
        }

        public int hashCode() {
            return Objects.hash(SpeedAboveMax);
        }
    }

    public static class _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed {

        public BBoolean VehicleAtCruiseSpeed;
        public BBoolean SpeedAboveMax;

        public _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed(BBoolean VehicleAtCruiseSpeed, BBoolean SpeedAboveMax) {
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this.SpeedAboveMax = SpeedAboveMax;
        }

        public String toString() {
            return "{" + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "," + "SpeedAboveMax: " + this.SpeedAboveMax + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed)) {
                return false;
            }
            _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed o = (_ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed) other;
            return this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed) && this.SpeedAboveMax.equals(o.SpeedAboveMax);
        }

        public int hashCode() {
            return Objects.hash(VehicleAtCruiseSpeed, SpeedAboveMax);
        }
    }

    public static class _ProjectionRead_ObstacleDistanceBecomesVeryClose {

        public RSset ObstacleRelativeSpeed;
        public ODset ObstacleDistance;

        public _ProjectionRead_ObstacleDistanceBecomesVeryClose(RSset ObstacleRelativeSpeed, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleDistanceBecomesVeryClose)) {
                return false;
            }
            _ProjectionRead_ObstacleDistanceBecomesVeryClose o = (_ProjectionRead_ObstacleDistanceBecomesVeryClose) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose {

        public RSset ObstacleRelativeSpeed;
        public ODset ObstacleDistance;

        public _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose(RSset ObstacleRelativeSpeed, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose o = (_ProjectionRead__tr_ObstacleDistanceBecomesVeryClose) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstacleDistance);
        }
    }

    public static class _ProjectionWrite_ObstacleDistanceBecomesVeryClose {

        public BBoolean ObstacleStatusJustChanged;
        public ODset ObstacleDistance;

        public _ProjectionWrite_ObstacleDistanceBecomesVeryClose(BBoolean ObstacleStatusJustChanged, ODset ObstacleDistance) {
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleDistanceBecomesVeryClose)) {
                return false;
            }
            _ProjectionWrite_ObstacleDistanceBecomesVeryClose o = (_ProjectionWrite_ObstacleDistanceBecomesVeryClose) other;
            return this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleStatusJustChanged, ObstacleDistance);
        }
    }

    public static class _ProjectionRead_ObstacleDistanceBecomesClose {

        public RSset ObstacleRelativeSpeed;
        public BBoolean CruiseActive;
        public BBoolean ObstaclePresent;
        public ODset ObstacleDistance;

        public _ProjectionRead_ObstacleDistanceBecomesClose(RSset ObstacleRelativeSpeed, BBoolean CruiseActive, BBoolean ObstaclePresent, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.CruiseActive = CruiseActive;
            this.ObstaclePresent = ObstaclePresent;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "CruiseActive: " + this.CruiseActive + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleDistanceBecomesClose)) {
                return false;
            }
            _ProjectionRead_ObstacleDistanceBecomesClose o = (_ProjectionRead_ObstacleDistanceBecomesClose) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.CruiseActive.equals(o.CruiseActive) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, CruiseActive, ObstaclePresent, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__tr_ObstacleDistanceBecomesClose {

        public RSset ObstacleRelativeSpeed;
        public BBoolean CruiseActive;
        public BBoolean ObstaclePresent;
        public ODset ObstacleDistance;

        public _ProjectionRead__tr_ObstacleDistanceBecomesClose(RSset ObstacleRelativeSpeed, BBoolean CruiseActive, BBoolean ObstaclePresent, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.CruiseActive = CruiseActive;
            this.ObstaclePresent = ObstaclePresent;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "CruiseActive: " + this.CruiseActive + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleDistanceBecomesClose)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleDistanceBecomesClose o = (_ProjectionRead__tr_ObstacleDistanceBecomesClose) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.CruiseActive.equals(o.CruiseActive) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, CruiseActive, ObstaclePresent, ObstacleDistance);
        }
    }

    public static class _ProjectionWrite_ObstacleDistanceBecomesClose {

        public BBoolean ObstacleStatusJustChanged;
        public BBoolean VehicleTryKeepTimeGap;
        public ODset ObstacleDistance;

        public _ProjectionWrite_ObstacleDistanceBecomesClose(BBoolean ObstacleStatusJustChanged, BBoolean VehicleTryKeepTimeGap, ODset ObstacleDistance) {
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleDistanceBecomesClose)) {
                return false;
            }
            _ProjectionWrite_ObstacleDistanceBecomesClose o = (_ProjectionWrite_ObstacleDistanceBecomesClose) other;
            return this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleStatusJustChanged, VehicleTryKeepTimeGap, ObstacleDistance);
        }
    }

    public static class _ProjectionRead_ObstacleDistanceBecomesBig {

        public RSset ObstacleRelativeSpeed;
        public ODset ObstacleDistance;

        public _ProjectionRead_ObstacleDistanceBecomesBig(RSset ObstacleRelativeSpeed, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleDistanceBecomesBig)) {
                return false;
            }
            _ProjectionRead_ObstacleDistanceBecomesBig o = (_ProjectionRead_ObstacleDistanceBecomesBig) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__tr_ObstacleDistanceBecomesBig {

        public RSset ObstacleRelativeSpeed;
        public ODset ObstacleDistance;

        public _ProjectionRead__tr_ObstacleDistanceBecomesBig(RSset ObstacleRelativeSpeed, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleDistanceBecomesBig)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleDistanceBecomesBig o = (_ProjectionRead__tr_ObstacleDistanceBecomesBig) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstacleDistance);
        }
    }

    public static class _ProjectionWrite_ObstacleDistanceBecomesBig {

        public BBoolean ObstacleStatusJustChanged;
        public BBoolean VehicleTryKeepTimeGap;
        public ODset ObstacleDistance;

        public _ProjectionWrite_ObstacleDistanceBecomesBig(BBoolean ObstacleStatusJustChanged, BBoolean VehicleTryKeepTimeGap, ODset ObstacleDistance) {
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleDistanceBecomesBig)) {
                return false;
            }
            _ProjectionWrite_ObstacleDistanceBecomesBig o = (_ProjectionWrite_ObstacleDistanceBecomesBig) other;
            return this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleStatusJustChanged, VehicleTryKeepTimeGap, ObstacleDistance);
        }
    }

    public static class _ProjectionRead_ObstacleStartsTravelFaster {

        public RSset ObstacleRelativeSpeed;
        public BBoolean CruiseActive;
        public BBoolean ObstaclePresent;
        public ODset ObstacleDistance;

        public _ProjectionRead_ObstacleStartsTravelFaster(RSset ObstacleRelativeSpeed, BBoolean CruiseActive, BBoolean ObstaclePresent, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.CruiseActive = CruiseActive;
            this.ObstaclePresent = ObstaclePresent;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "CruiseActive: " + this.CruiseActive + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleStartsTravelFaster)) {
                return false;
            }
            _ProjectionRead_ObstacleStartsTravelFaster o = (_ProjectionRead_ObstacleStartsTravelFaster) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.CruiseActive.equals(o.CruiseActive) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, CruiseActive, ObstaclePresent, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__tr_ObstacleStartsTravelFaster {

        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;

        public _ProjectionRead__tr_ObstacleStartsTravelFaster(RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleStartsTravelFaster)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleStartsTravelFaster o = (_ProjectionRead__tr_ObstacleStartsTravelFaster) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstaclePresent);
        }
    }

    public static class _ProjectionWrite_ObstacleStartsTravelFaster {

        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean VehicleTryKeepTimeGap;

        public _ProjectionWrite_ObstacleStartsTravelFaster(RSset ObstacleRelativeSpeed, BBoolean ObstacleStatusJustChanged, BBoolean VehicleTryKeepTimeGap) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleStartsTravelFaster)) {
                return false;
            }
            _ProjectionWrite_ObstacleStartsTravelFaster o = (_ProjectionWrite_ObstacleStartsTravelFaster) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstacleStatusJustChanged, VehicleTryKeepTimeGap);
        }
    }

    public static class _ProjectionRead_ObstacleStopsTravelFaster {

        public RSset ObstacleRelativeSpeed;
        public BBoolean CruiseActive;

        public _ProjectionRead_ObstacleStopsTravelFaster(RSset ObstacleRelativeSpeed, BBoolean CruiseActive) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.CruiseActive = CruiseActive;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "CruiseActive: " + this.CruiseActive + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleStopsTravelFaster)) {
                return false;
            }
            _ProjectionRead_ObstacleStopsTravelFaster o = (_ProjectionRead_ObstacleStopsTravelFaster) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.CruiseActive.equals(o.CruiseActive);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, CruiseActive);
        }
    }

    public static class _ProjectionRead__tr_ObstacleStopsTravelFaster {

        public RSset ObstacleRelativeSpeed;

        public _ProjectionRead__tr_ObstacleStopsTravelFaster(RSset ObstacleRelativeSpeed) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleStopsTravelFaster)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleStopsTravelFaster o = (_ProjectionRead__tr_ObstacleStopsTravelFaster) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed);
        }
    }

    public static class _ProjectionWrite_ObstacleStopsTravelFaster {

        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstacleStatusJustChanged;

        public _ProjectionWrite_ObstacleStopsTravelFaster(RSset ObstacleRelativeSpeed, BBoolean ObstacleStatusJustChanged) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleStopsTravelFaster)) {
                return false;
            }
            _ProjectionWrite_ObstacleStopsTravelFaster o = (_ProjectionWrite_ObstacleStopsTravelFaster) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstacleStatusJustChanged);
        }
    }

    public static class _ProjectionRead_ObstacleStartsTravelSlower {

        public RSset ObstacleRelativeSpeed;
        public BBoolean CruiseActive;

        public _ProjectionRead_ObstacleStartsTravelSlower(RSset ObstacleRelativeSpeed, BBoolean CruiseActive) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.CruiseActive = CruiseActive;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "CruiseActive: " + this.CruiseActive + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleStartsTravelSlower)) {
                return false;
            }
            _ProjectionRead_ObstacleStartsTravelSlower o = (_ProjectionRead_ObstacleStartsTravelSlower) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.CruiseActive.equals(o.CruiseActive);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, CruiseActive);
        }
    }

    public static class _ProjectionRead__tr_ObstacleStartsTravelSlower {

        public RSset ObstacleRelativeSpeed;

        public _ProjectionRead__tr_ObstacleStartsTravelSlower(RSset ObstacleRelativeSpeed) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleStartsTravelSlower)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleStartsTravelSlower o = (_ProjectionRead__tr_ObstacleStartsTravelSlower) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed);
        }
    }

    public static class _ProjectionWrite_ObstacleStartsTravelSlower {

        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstacleStatusJustChanged;

        public _ProjectionWrite_ObstacleStartsTravelSlower(RSset ObstacleRelativeSpeed, BBoolean ObstacleStatusJustChanged) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleStartsTravelSlower)) {
                return false;
            }
            _ProjectionWrite_ObstacleStartsTravelSlower o = (_ProjectionWrite_ObstacleStartsTravelSlower) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstacleStatusJustChanged);
        }
    }

    public static class _ProjectionRead_ObstacleStopsTravelSlower {

        public RSset ObstacleRelativeSpeed;
        public BBoolean CruiseActive;

        public _ProjectionRead_ObstacleStopsTravelSlower(RSset ObstacleRelativeSpeed, BBoolean CruiseActive) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.CruiseActive = CruiseActive;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "CruiseActive: " + this.CruiseActive + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleStopsTravelSlower)) {
                return false;
            }
            _ProjectionRead_ObstacleStopsTravelSlower o = (_ProjectionRead_ObstacleStopsTravelSlower) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.CruiseActive.equals(o.CruiseActive);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, CruiseActive);
        }
    }

    public static class _ProjectionRead__tr_ObstacleStopsTravelSlower {

        public RSset ObstacleRelativeSpeed;

        public _ProjectionRead__tr_ObstacleStopsTravelSlower(RSset ObstacleRelativeSpeed) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleStopsTravelSlower)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleStopsTravelSlower o = (_ProjectionRead__tr_ObstacleStopsTravelSlower) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed);
        }
    }

    public static class _ProjectionWrite_ObstacleStopsTravelSlower {

        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstacleStatusJustChanged;

        public _ProjectionWrite_ObstacleStopsTravelSlower(RSset ObstacleRelativeSpeed, BBoolean ObstacleStatusJustChanged) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleStopsTravelSlower)) {
                return false;
            }
            _ProjectionWrite_ObstacleStopsTravelSlower o = (_ProjectionWrite_ObstacleStopsTravelSlower) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstacleStatusJustChanged);
        }
    }

    public static class _ProjectionRead_ObstacleAppearsWhenCruiseActive {

        public BBoolean CruiseActive;
        public BBoolean ObstaclePresent;

        public _ProjectionRead_ObstacleAppearsWhenCruiseActive(BBoolean CruiseActive, BBoolean ObstaclePresent) {
            this.CruiseActive = CruiseActive;
            this.ObstaclePresent = ObstaclePresent;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "ObstaclePresent: " + this.ObstaclePresent + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleAppearsWhenCruiseActive)) {
                return false;
            }
            _ProjectionRead_ObstacleAppearsWhenCruiseActive o = (_ProjectionRead_ObstacleAppearsWhenCruiseActive) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.ObstaclePresent.equals(o.ObstaclePresent);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, ObstaclePresent);
        }
    }

    public static class _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive {

        public BBoolean CruiseActive;
        public BBoolean ObstaclePresent;

        public _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive(BBoolean CruiseActive, BBoolean ObstaclePresent) {
            this.CruiseActive = CruiseActive;
            this.ObstaclePresent = ObstaclePresent;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "ObstaclePresent: " + this.ObstaclePresent + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive o = (_ProjectionRead__tr_ObstacleAppearsWhenCruiseActive) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.ObstaclePresent.equals(o.ObstaclePresent);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, ObstaclePresent);
        }
    }

    public static class _ProjectionWrite_ObstacleAppearsWhenCruiseActive {

        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;
        public BBoolean ObstacleStatusJustChanged;
        public ODset ObstacleDistance;

        public _ProjectionWrite_ObstacleAppearsWhenCruiseActive(RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent, BBoolean ObstacleStatusJustChanged, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleAppearsWhenCruiseActive)) {
                return false;
            }
            _ProjectionWrite_ObstacleAppearsWhenCruiseActive o = (_ProjectionWrite_ObstacleAppearsWhenCruiseActive) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstaclePresent, ObstacleStatusJustChanged, ObstacleDistance);
        }
    }

    public static class _ProjectionRead_ObstacleAppearsWhenCruiseInactive {

        public BBoolean CruiseActive;
        public BBoolean ObstaclePresent;

        public _ProjectionRead_ObstacleAppearsWhenCruiseInactive(BBoolean CruiseActive, BBoolean ObstaclePresent) {
            this.CruiseActive = CruiseActive;
            this.ObstaclePresent = ObstaclePresent;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "ObstaclePresent: " + this.ObstaclePresent + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleAppearsWhenCruiseInactive)) {
                return false;
            }
            _ProjectionRead_ObstacleAppearsWhenCruiseInactive o = (_ProjectionRead_ObstacleAppearsWhenCruiseInactive) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.ObstaclePresent.equals(o.ObstaclePresent);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, ObstaclePresent);
        }
    }

    public static class _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive {

        public BBoolean CruiseActive;
        public BBoolean ObstaclePresent;

        public _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive(BBoolean CruiseActive, BBoolean ObstaclePresent) {
            this.CruiseActive = CruiseActive;
            this.ObstaclePresent = ObstaclePresent;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "ObstaclePresent: " + this.ObstaclePresent + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive o = (_ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.ObstaclePresent.equals(o.ObstaclePresent);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, ObstaclePresent);
        }
    }

    public static class _ProjectionWrite_ObstacleAppearsWhenCruiseInactive {

        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;
        public ODset ObstacleDistance;

        public _ProjectionWrite_ObstacleAppearsWhenCruiseInactive(RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleAppearsWhenCruiseInactive)) {
                return false;
            }
            _ProjectionWrite_ObstacleAppearsWhenCruiseInactive o = (_ProjectionWrite_ObstacleAppearsWhenCruiseInactive) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstaclePresent, ObstacleDistance);
        }
    }

    public static class _ProjectionRead_ObstacleDisappears {

        public BBoolean CruiseActive;
        public BBoolean ObstaclePresent;

        public _ProjectionRead_ObstacleDisappears(BBoolean CruiseActive, BBoolean ObstaclePresent) {
            this.CruiseActive = CruiseActive;
            this.ObstaclePresent = ObstaclePresent;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "ObstaclePresent: " + this.ObstaclePresent + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleDisappears)) {
                return false;
            }
            _ProjectionRead_ObstacleDisappears o = (_ProjectionRead_ObstacleDisappears) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.ObstaclePresent.equals(o.ObstaclePresent);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, ObstaclePresent);
        }
    }

    public static class _ProjectionRead__tr_ObstacleDisappears {

        public BBoolean ObstaclePresent;

        public _ProjectionRead__tr_ObstacleDisappears(BBoolean ObstaclePresent) {
            this.ObstaclePresent = ObstaclePresent;
        }

        public String toString() {
            return "{" + "ObstaclePresent: " + this.ObstaclePresent + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleDisappears)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleDisappears o = (_ProjectionRead__tr_ObstacleDisappears) other;
            return this.ObstaclePresent.equals(o.ObstaclePresent);
        }

        public int hashCode() {
            return Objects.hash(ObstaclePresent);
        }
    }

    public static class _ProjectionWrite_ObstacleDisappears {

        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean VehicleTryKeepTimeGap;
        public ODset ObstacleDistance;

        public _ProjectionWrite_ObstacleDisappears(RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent, BBoolean ObstacleStatusJustChanged, BBoolean VehicleTryKeepTimeGap, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleDisappears)) {
                return false;
            }
            _ProjectionWrite_ObstacleDisappears o = (_ProjectionWrite_ObstacleDisappears) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstaclePresent, ObstacleStatusJustChanged, VehicleTryKeepTimeGap, ObstacleDistance);
        }
    }

    public static class _ProjectionRead_VehicleManageObstacle {

        public BBoolean CCInitialisationInProgress;
        public BBoolean ObstacleStatusJustChanged;
        public ODset ObstacleDistance;
        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;
        public BBoolean CruiseSpeedChangeInProgress;

        public _ProjectionRead_VehicleManageObstacle(BBoolean CCInitialisationInProgress, BBoolean ObstacleStatusJustChanged, ODset ObstacleDistance, RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent, BBoolean CruiseSpeedChangeInProgress) {
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.ObstacleDistance = ObstacleDistance;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        }

        public String toString() {
            return "{" + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "ObstacleDistance: " + this.ObstacleDistance + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_VehicleManageObstacle)) {
                return false;
            }
            _ProjectionRead_VehicleManageObstacle o = (_ProjectionRead_VehicleManageObstacle) other;
            return this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.ObstacleDistance.equals(o.ObstacleDistance) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress);
        }

        public int hashCode() {
            return Objects.hash(CCInitialisationInProgress, ObstacleStatusJustChanged, ObstacleDistance, ObstacleRelativeSpeed, ObstaclePresent, CruiseSpeedChangeInProgress);
        }
    }

    public static class _ProjectionRead__tr_VehicleManageObstacle {

        public BBoolean CCInitialisationInProgress;
        public BBoolean ObstacleStatusJustChanged;
        public ODset ObstacleDistance;
        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;
        public BBoolean CruiseSpeedChangeInProgress;

        public _ProjectionRead__tr_VehicleManageObstacle(BBoolean CCInitialisationInProgress, BBoolean ObstacleStatusJustChanged, ODset ObstacleDistance, RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent, BBoolean CruiseSpeedChangeInProgress) {
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.ObstacleDistance = ObstacleDistance;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        }

        public String toString() {
            return "{" + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "ObstacleDistance: " + this.ObstacleDistance + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_VehicleManageObstacle)) {
                return false;
            }
            _ProjectionRead__tr_VehicleManageObstacle o = (_ProjectionRead__tr_VehicleManageObstacle) other;
            return this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.ObstacleDistance.equals(o.ObstacleDistance) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress);
        }

        public int hashCode() {
            return Objects.hash(CCInitialisationInProgress, ObstacleStatusJustChanged, ObstacleDistance, ObstacleRelativeSpeed, ObstaclePresent, CruiseSpeedChangeInProgress);
        }
    }

    public static class _ProjectionWrite_VehicleManageObstacle {

        public BBoolean VehicleTryKeepSpeed;
        public BBoolean VehicleTryKeepTimeGap;

        public _ProjectionWrite_VehicleManageObstacle(BBoolean VehicleTryKeepSpeed, BBoolean VehicleTryKeepTimeGap) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_VehicleManageObstacle)) {
                return false;
            }
            _ProjectionWrite_VehicleManageObstacle o = (_ProjectionWrite_VehicleManageObstacle) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, VehicleTryKeepTimeGap);
        }
    }

    public static class _ProjectionRead_ObstacleBecomesOld {

        public BBoolean VehicleTryKeepSpeed;
        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;
        public ODset ObstacleDistance;

        public _ProjectionRead_ObstacleBecomesOld(BBoolean VehicleTryKeepSpeed, RSset ObstacleRelativeSpeed, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress, ODset ObstacleDistance) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_ObstacleBecomesOld)) {
                return false;
            }
            _ProjectionRead_ObstacleBecomesOld o = (_ProjectionRead_ObstacleBecomesOld) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, ObstacleRelativeSpeed, ObstacleStatusJustChanged, CCInitialisationInProgress, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__tr_ObstacleBecomesOld {

        public BBoolean VehicleTryKeepSpeed;
        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;
        public ODset ObstacleDistance;

        public _ProjectionRead__tr_ObstacleBecomesOld(BBoolean VehicleTryKeepSpeed, RSset ObstacleRelativeSpeed, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress, ODset ObstacleDistance) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_ObstacleBecomesOld)) {
                return false;
            }
            _ProjectionRead__tr_ObstacleBecomesOld o = (_ProjectionRead__tr_ObstacleBecomesOld) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, ObstacleRelativeSpeed, ObstacleStatusJustChanged, CCInitialisationInProgress, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress, ObstacleDistance);
        }
    }

    public static class _ProjectionWrite_ObstacleBecomesOld {

        public BBoolean ObstacleStatusJustChanged;

        public _ProjectionWrite_ObstacleBecomesOld(BBoolean ObstacleStatusJustChanged) {
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        }

        public String toString() {
            return "{" + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_ObstacleBecomesOld)) {
                return false;
            }
            _ProjectionWrite_ObstacleBecomesOld o = (_ProjectionWrite_ObstacleBecomesOld) other;
            return this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged);
        }

        public int hashCode() {
            return Objects.hash(ObstacleStatusJustChanged);
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public BBoolean CruiseAllowed;

        public _ProjectionRead__check_inv_1(BBoolean CruiseAllowed) {
            this.CruiseAllowed = CruiseAllowed;
        }

        public String toString() {
            return "{" + "CruiseAllowed: " + this.CruiseAllowed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.CruiseAllowed.equals(o.CruiseAllowed);
        }

        public int hashCode() {
            return Objects.hash(CruiseAllowed);
        }
    }

    public static class _ProjectionRead__check_inv_2 {

        public BBoolean CruiseActive;

        public _ProjectionRead__check_inv_2(BBoolean CruiseActive) {
            this.CruiseActive = CruiseActive;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_2)) {
                return false;
            }
            _ProjectionRead__check_inv_2 o = (_ProjectionRead__check_inv_2) other;
            return this.CruiseActive.equals(o.CruiseActive);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive);
        }
    }

    public static class _ProjectionRead__check_inv_3 {

        public BBoolean VehicleAtCruiseSpeed;

        public _ProjectionRead__check_inv_3(BBoolean VehicleAtCruiseSpeed) {
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        }

        public String toString() {
            return "{" + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_3)) {
                return false;
            }
            _ProjectionRead__check_inv_3 o = (_ProjectionRead__check_inv_3) other;
            return this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleAtCruiseSpeed);
        }
    }

    public static class _ProjectionRead__check_inv_4 {

        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionRead__check_inv_4(BBoolean VehicleCanKeepSpeed) {
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_4)) {
                return false;
            }
            _ProjectionRead__check_inv_4 o = (_ProjectionRead__check_inv_4) other;
            return this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionRead__check_inv_5 {

        public BBoolean VehicleTryKeepSpeed;

        public _ProjectionRead__check_inv_5(BBoolean VehicleTryKeepSpeed) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_5)) {
                return false;
            }
            _ProjectionRead__check_inv_5 o = (_ProjectionRead__check_inv_5) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed);
        }
    }

    public static class _ProjectionRead__check_inv_6 {

        public BBoolean SpeedAboveMax;

        public _ProjectionRead__check_inv_6(BBoolean SpeedAboveMax) {
            this.SpeedAboveMax = SpeedAboveMax;
        }

        public String toString() {
            return "{" + "SpeedAboveMax: " + this.SpeedAboveMax + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_6)) {
                return false;
            }
            _ProjectionRead__check_inv_6 o = (_ProjectionRead__check_inv_6) other;
            return this.SpeedAboveMax.equals(o.SpeedAboveMax);
        }

        public int hashCode() {
            return Objects.hash(SpeedAboveMax);
        }
    }

    public static class _ProjectionRead__check_inv_7 {

        public BBoolean VehicleTryKeepTimeGap;

        public _ProjectionRead__check_inv_7(BBoolean VehicleTryKeepTimeGap) {
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        }

        public String toString() {
            return "{" + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_7)) {
                return false;
            }
            _ProjectionRead__check_inv_7 o = (_ProjectionRead__check_inv_7) other;
            return this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepTimeGap);
        }
    }

    public static class _ProjectionRead__check_inv_8 {

        public BBoolean CruiseSpeedAtMax;

        public _ProjectionRead__check_inv_8(BBoolean CruiseSpeedAtMax) {
            this.CruiseSpeedAtMax = CruiseSpeedAtMax;
        }

        public String toString() {
            return "{" + "CruiseSpeedAtMax: " + this.CruiseSpeedAtMax + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_8)) {
                return false;
            }
            _ProjectionRead__check_inv_8 o = (_ProjectionRead__check_inv_8) other;
            return this.CruiseSpeedAtMax.equals(o.CruiseSpeedAtMax);
        }

        public int hashCode() {
            return Objects.hash(CruiseSpeedAtMax);
        }
    }

    public static class _ProjectionRead__check_inv_9 {

        public BInteger NumberOfSetCruise;

        public _ProjectionRead__check_inv_9(BInteger NumberOfSetCruise) {
            this.NumberOfSetCruise = NumberOfSetCruise;
        }

        public String toString() {
            return "{" + "NumberOfSetCruise: " + this.NumberOfSetCruise + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_9)) {
                return false;
            }
            _ProjectionRead__check_inv_9 o = (_ProjectionRead__check_inv_9) other;
            return this.NumberOfSetCruise.equals(o.NumberOfSetCruise);
        }

        public int hashCode() {
            return Objects.hash(NumberOfSetCruise);
        }
    }

    public static class _ProjectionRead__check_inv_10 {

        public BInteger NumberOfSetCruise;

        public _ProjectionRead__check_inv_10(BInteger NumberOfSetCruise) {
            this.NumberOfSetCruise = NumberOfSetCruise;
        }

        public String toString() {
            return "{" + "NumberOfSetCruise: " + this.NumberOfSetCruise + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_10)) {
                return false;
            }
            _ProjectionRead__check_inv_10 o = (_ProjectionRead__check_inv_10) other;
            return this.NumberOfSetCruise.equals(o.NumberOfSetCruise);
        }

        public int hashCode() {
            return Objects.hash(NumberOfSetCruise);
        }
    }

    public static class _ProjectionRead__check_inv_11 {

        public BBoolean ObstaclePresent;

        public _ProjectionRead__check_inv_11(BBoolean ObstaclePresent) {
            this.ObstaclePresent = ObstaclePresent;
        }

        public String toString() {
            return "{" + "ObstaclePresent: " + this.ObstaclePresent + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_11)) {
                return false;
            }
            _ProjectionRead__check_inv_11 o = (_ProjectionRead__check_inv_11) other;
            return this.ObstaclePresent.equals(o.ObstaclePresent);
        }

        public int hashCode() {
            return Objects.hash(ObstaclePresent);
        }
    }

    public static class _ProjectionRead__check_inv_12 {

        public ODset ObstacleDistance;

        public _ProjectionRead__check_inv_12(ODset ObstacleDistance) {
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_12)) {
                return false;
            }
            _ProjectionRead__check_inv_12 o = (_ProjectionRead__check_inv_12) other;
            return this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleDistance);
        }
    }

    public static class _ProjectionRead__check_inv_13 {

        public RSset ObstacleRelativeSpeed;

        public _ProjectionRead__check_inv_13(RSset ObstacleRelativeSpeed) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_13)) {
                return false;
            }
            _ProjectionRead__check_inv_13 o = (_ProjectionRead__check_inv_13) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed);
        }
    }

    public static class _ProjectionRead__check_inv_14 {

        public BBoolean ObstacleStatusJustChanged;

        public _ProjectionRead__check_inv_14(BBoolean ObstacleStatusJustChanged) {
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        }

        public String toString() {
            return "{" + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_14)) {
                return false;
            }
            _ProjectionRead__check_inv_14 o = (_ProjectionRead__check_inv_14) other;
            return this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged);
        }

        public int hashCode() {
            return Objects.hash(ObstacleStatusJustChanged);
        }
    }

    public static class _ProjectionRead__check_inv_15 {

        public BBoolean CCInitialisationInProgress;

        public _ProjectionRead__check_inv_15(BBoolean CCInitialisationInProgress) {
            this.CCInitialisationInProgress = CCInitialisationInProgress;
        }

        public String toString() {
            return "{" + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_15)) {
                return false;
            }
            _ProjectionRead__check_inv_15 o = (_ProjectionRead__check_inv_15) other;
            return this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress);
        }

        public int hashCode() {
            return Objects.hash(CCInitialisationInProgress);
        }
    }

    public static class _ProjectionRead__check_inv_16 {

        public BBoolean CruiseSpeedChangeInProgress;

        public _ProjectionRead__check_inv_16(BBoolean CruiseSpeedChangeInProgress) {
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        }

        public String toString() {
            return "{" + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_16)) {
                return false;
            }
            _ProjectionRead__check_inv_16 o = (_ProjectionRead__check_inv_16) other;
            return this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress);
        }

        public int hashCode() {
            return Objects.hash(CruiseSpeedChangeInProgress);
        }
    }

    public static class _ProjectionRead__check_inv_17 {

        public BBoolean CruiseActive;
        public BBoolean VehicleAtCruiseSpeed;

        public _ProjectionRead__check_inv_17(BBoolean CruiseActive, BBoolean VehicleAtCruiseSpeed) {
            this.CruiseActive = CruiseActive;
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_17)) {
                return false;
            }
            _ProjectionRead__check_inv_17 o = (_ProjectionRead__check_inv_17) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, VehicleAtCruiseSpeed);
        }
    }

    public static class _ProjectionRead__check_inv_18 {

        public BBoolean CruiseActive;
        public BBoolean VehicleCanKeepSpeed;

        public _ProjectionRead__check_inv_18(BBoolean CruiseActive, BBoolean VehicleCanKeepSpeed) {
            this.CruiseActive = CruiseActive;
            this.VehicleCanKeepSpeed = VehicleCanKeepSpeed;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "VehicleCanKeepSpeed: " + this.VehicleCanKeepSpeed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_18)) {
                return false;
            }
            _ProjectionRead__check_inv_18 o = (_ProjectionRead__check_inv_18) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.VehicleCanKeepSpeed.equals(o.VehicleCanKeepSpeed);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, VehicleCanKeepSpeed);
        }
    }

    public static class _ProjectionRead__check_inv_19 {

        public BBoolean VehicleTryKeepSpeed;
        public BBoolean CruiseActive;

        public _ProjectionRead__check_inv_19(BBoolean VehicleTryKeepSpeed, BBoolean CruiseActive) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.CruiseActive = CruiseActive;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "CruiseActive: " + this.CruiseActive + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_19)) {
                return false;
            }
            _ProjectionRead__check_inv_19 o = (_ProjectionRead__check_inv_19) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.CruiseActive.equals(o.CruiseActive);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, CruiseActive);
        }
    }

    public static class _ProjectionRead__check_inv_20 {

        public BBoolean CruiseActive;
        public BInteger NumberOfSetCruise;

        public _ProjectionRead__check_inv_20(BBoolean CruiseActive, BInteger NumberOfSetCruise) {
            this.CruiseActive = CruiseActive;
            this.NumberOfSetCruise = NumberOfSetCruise;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "NumberOfSetCruise: " + this.NumberOfSetCruise + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_20)) {
                return false;
            }
            _ProjectionRead__check_inv_20 o = (_ProjectionRead__check_inv_20) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.NumberOfSetCruise.equals(o.NumberOfSetCruise);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, NumberOfSetCruise);
        }
    }

    public static class _ProjectionRead__check_inv_21 {

        public BBoolean CruiseActive;
        public BBoolean VehicleTryKeepTimeGap;

        public _ProjectionRead__check_inv_21(BBoolean CruiseActive, BBoolean VehicleTryKeepTimeGap) {
            this.CruiseActive = CruiseActive;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_21)) {
                return false;
            }
            _ProjectionRead__check_inv_21 o = (_ProjectionRead__check_inv_21) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, VehicleTryKeepTimeGap);
        }
    }

    public static class _ProjectionRead__check_inv_22 {

        public BBoolean CruiseSpeedAtMax;
        public BBoolean CruiseActive;

        public _ProjectionRead__check_inv_22(BBoolean CruiseSpeedAtMax, BBoolean CruiseActive) {
            this.CruiseSpeedAtMax = CruiseSpeedAtMax;
            this.CruiseActive = CruiseActive;
        }

        public String toString() {
            return "{" + "CruiseSpeedAtMax: " + this.CruiseSpeedAtMax + "," + "CruiseActive: " + this.CruiseActive + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_22)) {
                return false;
            }
            _ProjectionRead__check_inv_22 o = (_ProjectionRead__check_inv_22) other;
            return this.CruiseSpeedAtMax.equals(o.CruiseSpeedAtMax) && this.CruiseActive.equals(o.CruiseActive);
        }

        public int hashCode() {
            return Objects.hash(CruiseSpeedAtMax, CruiseActive);
        }
    }

    public static class _ProjectionRead__check_inv_23 {

        public BBoolean CruiseActive;
        public ODset ObstacleDistance;

        public _ProjectionRead__check_inv_23(BBoolean CruiseActive, ODset ObstacleDistance) {
            this.CruiseActive = CruiseActive;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_23)) {
                return false;
            }
            _ProjectionRead__check_inv_23 o = (_ProjectionRead__check_inv_23) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__check_inv_24 {

        public BBoolean CruiseActive;
        public BBoolean ObstacleStatusJustChanged;

        public _ProjectionRead__check_inv_24(BBoolean CruiseActive, BBoolean ObstacleStatusJustChanged) {
            this.CruiseActive = CruiseActive;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_24)) {
                return false;
            }
            _ProjectionRead__check_inv_24 o = (_ProjectionRead__check_inv_24) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, ObstacleStatusJustChanged);
        }
    }

    public static class _ProjectionRead__check_inv_25 {

        public BBoolean CruiseActive;
        public BBoolean CCInitialisationInProgress;

        public _ProjectionRead__check_inv_25(BBoolean CruiseActive, BBoolean CCInitialisationInProgress) {
            this.CruiseActive = CruiseActive;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_25)) {
                return false;
            }
            _ProjectionRead__check_inv_25 o = (_ProjectionRead__check_inv_25) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, CCInitialisationInProgress);
        }
    }

    public static class _ProjectionRead__check_inv_26 {

        public BBoolean CruiseActive;
        public BBoolean CruiseSpeedChangeInProgress;

        public _ProjectionRead__check_inv_26(BBoolean CruiseActive, BBoolean CruiseSpeedChangeInProgress) {
            this.CruiseActive = CruiseActive;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_26)) {
                return false;
            }
            _ProjectionRead__check_inv_26 o = (_ProjectionRead__check_inv_26) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, CruiseSpeedChangeInProgress);
        }
    }

    public static class _ProjectionRead__check_inv_27 {

        public BBoolean ObstaclePresent;
        public BBoolean VehicleTryKeepTimeGap;

        public _ProjectionRead__check_inv_27(BBoolean ObstaclePresent, BBoolean VehicleTryKeepTimeGap) {
            this.ObstaclePresent = ObstaclePresent;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
        }

        public String toString() {
            return "{" + "ObstaclePresent: " + this.ObstaclePresent + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_27)) {
                return false;
            }
            _ProjectionRead__check_inv_27 o = (_ProjectionRead__check_inv_27) other;
            return this.ObstaclePresent.equals(o.ObstaclePresent) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap);
        }

        public int hashCode() {
            return Objects.hash(ObstaclePresent, VehicleTryKeepTimeGap);
        }
    }

    public static class _ProjectionRead__check_inv_28 {

        public BBoolean ObstaclePresent;
        public ODset ObstacleDistance;

        public _ProjectionRead__check_inv_28(BBoolean ObstaclePresent, ODset ObstacleDistance) {
            this.ObstaclePresent = ObstaclePresent;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstaclePresent: " + this.ObstaclePresent + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_28)) {
                return false;
            }
            _ProjectionRead__check_inv_28 o = (_ProjectionRead__check_inv_28) other;
            return this.ObstaclePresent.equals(o.ObstaclePresent) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstaclePresent, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__check_inv_29 {

        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstaclePresent;

        public _ProjectionRead__check_inv_29(RSset ObstacleRelativeSpeed, BBoolean ObstaclePresent) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstaclePresent = ObstaclePresent;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstaclePresent: " + this.ObstaclePresent + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_29)) {
                return false;
            }
            _ProjectionRead__check_inv_29 o = (_ProjectionRead__check_inv_29) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstaclePresent.equals(o.ObstaclePresent);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstaclePresent);
        }
    }

    public static class _ProjectionRead__check_inv_30 {

        public RSset ObstacleRelativeSpeed;
        public BBoolean VehicleTryKeepTimeGap;
        public ODset ObstacleDistance;

        public _ProjectionRead__check_inv_30(RSset ObstacleRelativeSpeed, BBoolean VehicleTryKeepTimeGap, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_30)) {
                return false;
            }
            _ProjectionRead__check_inv_30 o = (_ProjectionRead__check_inv_30) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, VehicleTryKeepTimeGap, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__check_inv_31 {

        public RSset ObstacleRelativeSpeed;
        public BBoolean VehicleTryKeepTimeGap;
        public ODset ObstacleDistance;

        public _ProjectionRead__check_inv_31(RSset ObstacleRelativeSpeed, BBoolean VehicleTryKeepTimeGap, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_31)) {
                return false;
            }
            _ProjectionRead__check_inv_31 o = (_ProjectionRead__check_inv_31) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, VehicleTryKeepTimeGap, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__check_inv_32 {

        public RSset ObstacleRelativeSpeed;
        public BBoolean VehicleTryKeepTimeGap;
        public ODset ObstacleDistance;

        public _ProjectionRead__check_inv_32(RSset ObstacleRelativeSpeed, BBoolean VehicleTryKeepTimeGap, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_32)) {
                return false;
            }
            _ProjectionRead__check_inv_32 o = (_ProjectionRead__check_inv_32) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, VehicleTryKeepTimeGap, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__check_inv_33 {

        public BBoolean CruiseActive;
        public BBoolean CruiseAllowed;

        public _ProjectionRead__check_inv_33(BBoolean CruiseActive, BBoolean CruiseAllowed) {
            this.CruiseActive = CruiseActive;
            this.CruiseAllowed = CruiseAllowed;
        }

        public String toString() {
            return "{" + "CruiseActive: " + this.CruiseActive + "," + "CruiseAllowed: " + this.CruiseAllowed + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_33)) {
                return false;
            }
            _ProjectionRead__check_inv_33 o = (_ProjectionRead__check_inv_33) other;
            return this.CruiseActive.equals(o.CruiseActive) && this.CruiseAllowed.equals(o.CruiseAllowed);
        }

        public int hashCode() {
            return Objects.hash(CruiseActive, CruiseAllowed);
        }
    }

    public static class _ProjectionRead__check_inv_34 {

        public BBoolean VehicleAtCruiseSpeed;
        public BBoolean SpeedAboveMax;

        public _ProjectionRead__check_inv_34(BBoolean VehicleAtCruiseSpeed, BBoolean SpeedAboveMax) {
            this.VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this.SpeedAboveMax = SpeedAboveMax;
        }

        public String toString() {
            return "{" + "VehicleAtCruiseSpeed: " + this.VehicleAtCruiseSpeed + "," + "SpeedAboveMax: " + this.SpeedAboveMax + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_34)) {
                return false;
            }
            _ProjectionRead__check_inv_34 o = (_ProjectionRead__check_inv_34) other;
            return this.VehicleAtCruiseSpeed.equals(o.VehicleAtCruiseSpeed) && this.SpeedAboveMax.equals(o.SpeedAboveMax);
        }

        public int hashCode() {
            return Objects.hash(VehicleAtCruiseSpeed, SpeedAboveMax);
        }
    }

    public static class _ProjectionRead__check_inv_35 {

        public BBoolean VehicleTryKeepSpeed;
        public BBoolean CruiseActive;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;

        public _ProjectionRead__check_inv_35(BBoolean VehicleTryKeepSpeed, BBoolean CruiseActive, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.CruiseActive = CruiseActive;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "CruiseActive: " + this.CruiseActive + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_35)) {
                return false;
            }
            _ProjectionRead__check_inv_35 o = (_ProjectionRead__check_inv_35) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.CruiseActive.equals(o.CruiseActive) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, CruiseActive, ObstacleStatusJustChanged, CCInitialisationInProgress, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress);
        }
    }

    public static class _ProjectionRead__check_inv_36 {

        public BBoolean VehicleTryKeepSpeed;
        public BBoolean CruiseActive;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean CruiseSpeedChangeInProgress;
        public ODset ObstacleDistance;

        public _ProjectionRead__check_inv_36(BBoolean VehicleTryKeepSpeed, BBoolean CruiseActive, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean CruiseSpeedChangeInProgress, ODset ObstacleDistance) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.CruiseActive = CruiseActive;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "CruiseActive: " + this.CruiseActive + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_36)) {
                return false;
            }
            _ProjectionRead__check_inv_36 o = (_ProjectionRead__check_inv_36) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.CruiseActive.equals(o.CruiseActive) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, CruiseActive, ObstacleStatusJustChanged, CCInitialisationInProgress, CruiseSpeedChangeInProgress, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__check_inv_37 {

        public RSset ObstacleRelativeSpeed;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;
        public ODset ObstacleDistance;

        public _ProjectionRead__check_inv_37(RSset ObstacleRelativeSpeed, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress, ODset ObstacleDistance) {
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_37)) {
                return false;
            }
            _ProjectionRead__check_inv_37 o = (_ProjectionRead__check_inv_37) other;
            return this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleRelativeSpeed, ObstacleStatusJustChanged, CCInitialisationInProgress, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__check_inv_38 {

        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean VehicleTryKeepTimeGap;
        public BBoolean CruiseSpeedChangeInProgress;
        public ODset ObstacleDistance;

        public _ProjectionRead__check_inv_38(BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean VehicleTryKeepTimeGap, BBoolean CruiseSpeedChangeInProgress, ODset ObstacleDistance) {
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "VehicleTryKeepTimeGap: " + this.VehicleTryKeepTimeGap + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_38)) {
                return false;
            }
            _ProjectionRead__check_inv_38 o = (_ProjectionRead__check_inv_38) other;
            return this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.VehicleTryKeepTimeGap.equals(o.VehicleTryKeepTimeGap) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(ObstacleStatusJustChanged, CCInitialisationInProgress, VehicleTryKeepTimeGap, CruiseSpeedChangeInProgress, ObstacleDistance);
        }
    }

    public static class _ProjectionRead__check_inv_39 {

        public BBoolean VehicleTryKeepSpeed;
        public RSset ObstacleRelativeSpeed;
        public BBoolean CruiseActive;
        public BBoolean ObstacleStatusJustChanged;
        public BBoolean CCInitialisationInProgress;
        public BBoolean CruiseSpeedChangeInProgress;
        public ODset ObstacleDistance;

        public _ProjectionRead__check_inv_39(BBoolean VehicleTryKeepSpeed, RSset ObstacleRelativeSpeed, BBoolean CruiseActive, BBoolean ObstacleStatusJustChanged, BBoolean CCInitialisationInProgress, BBoolean CruiseSpeedChangeInProgress, ODset ObstacleDistance) {
            this.VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this.ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this.CruiseActive = CruiseActive;
            this.ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this.CCInitialisationInProgress = CCInitialisationInProgress;
            this.CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this.ObstacleDistance = ObstacleDistance;
        }

        public String toString() {
            return "{" + "VehicleTryKeepSpeed: " + this.VehicleTryKeepSpeed + "," + "ObstacleRelativeSpeed: " + this.ObstacleRelativeSpeed + "," + "CruiseActive: " + this.CruiseActive + "," + "ObstacleStatusJustChanged: " + this.ObstacleStatusJustChanged + "," + "CCInitialisationInProgress: " + this.CCInitialisationInProgress + "," + "CruiseSpeedChangeInProgress: " + this.CruiseSpeedChangeInProgress + "," + "ObstacleDistance: " + this.ObstacleDistance + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_39)) {
                return false;
            }
            _ProjectionRead__check_inv_39 o = (_ProjectionRead__check_inv_39) other;
            return this.VehicleTryKeepSpeed.equals(o.VehicleTryKeepSpeed) && this.ObstacleRelativeSpeed.equals(o.ObstacleRelativeSpeed) && this.CruiseActive.equals(o.CruiseActive) && this.ObstacleStatusJustChanged.equals(o.ObstacleStatusJustChanged) && this.CCInitialisationInProgress.equals(o.CCInitialisationInProgress) && this.CruiseSpeedChangeInProgress.equals(o.CruiseSpeedChangeInProgress) && this.ObstacleDistance.equals(o.ObstacleDistance);
        }

        public int hashCode() {
            return Objects.hash(VehicleTryKeepSpeed, ObstacleRelativeSpeed, CruiseActive, ObstacleStatusJustChanged, CCInitialisationInProgress, CruiseSpeedChangeInProgress, ObstacleDistance);
        }
    }






    public enum RSset implements BObject {
        RSnone, 
        RSpos, 
        RSneg, 
        RSequal;

        public BBoolean equal(RSset o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(RSset o) {
            return new BBoolean(this != o);
        }
    }

    public enum ODset implements BObject {
        ODnone, 
        ODclose, 
        ODveryclose;

        public BBoolean equal(ODset o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(ODset o) {
            return new BBoolean(this != o);
        }
    }

    private static BSet<RSset> _RSset = new BSet<RSset>(RSset.RSnone, RSset.RSpos, RSset.RSneg, RSset.RSequal);
    private static BSet<ODset> _ODset = new BSet<ODset>(ODset.ODnone, ODset.ODclose, ODset.ODveryclose);

    private BBoolean CruiseAllowed;
    private BBoolean CruiseActive;
    private BBoolean VehicleAtCruiseSpeed;
    private BBoolean VehicleCanKeepSpeed;
    private BBoolean VehicleTryKeepSpeed;
    private BBoolean SpeedAboveMax;
    private BBoolean VehicleTryKeepTimeGap;
    private BBoolean CruiseSpeedAtMax;
    private BBoolean ObstaclePresent;
    private ODset ObstacleDistance;
    private RSset ObstacleRelativeSpeed;
    private BBoolean ObstacleStatusJustChanged;
    private BBoolean CCInitialisationInProgress;
    private BBoolean CruiseSpeedChangeInProgress;
    private BInteger NumberOfSetCruise;

    public Cruise_finite1_deterministic_MC() {
        CruiseAllowed = new BBoolean(true);
        CruiseActive = new BBoolean(false);
        VehicleAtCruiseSpeed = new BBoolean(false);
        VehicleCanKeepSpeed = new BBoolean(false);
        VehicleTryKeepSpeed = new BBoolean(false);
        SpeedAboveMax = new BBoolean(false);
        VehicleTryKeepTimeGap = new BBoolean(false);
        NumberOfSetCruise = new BInteger(0);
        CruiseSpeedAtMax = new BBoolean(false);
        ObstacleDistance = ODset.ODnone;
        ObstacleStatusJustChanged = new BBoolean(false);
        CCInitialisationInProgress = new BBoolean(false);
        CruiseSpeedChangeInProgress = new BBoolean(false);
        ObstaclePresent = new BBoolean(false);
        ObstacleRelativeSpeed = RSset.RSnone;
    }

    public Cruise_finite1_deterministic_MC(Cruise_finite1_deterministic_MC copy) {
        this.CruiseAllowed = copy.CruiseAllowed;
        this.CruiseActive = copy.CruiseActive;
        this.VehicleAtCruiseSpeed = copy.VehicleAtCruiseSpeed;
        this.VehicleCanKeepSpeed = copy.VehicleCanKeepSpeed;
        this.VehicleTryKeepSpeed = copy.VehicleTryKeepSpeed;
        this.SpeedAboveMax = copy.SpeedAboveMax;
        this.VehicleTryKeepTimeGap = copy.VehicleTryKeepTimeGap;
        this.CruiseSpeedAtMax = copy.CruiseSpeedAtMax;
        this.ObstaclePresent = copy.ObstaclePresent;
        this.ObstacleDistance = copy.ObstacleDistance;
        this.ObstacleRelativeSpeed = copy.ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = copy.ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = copy.CCInitialisationInProgress;
        this.CruiseSpeedChangeInProgress = copy.CruiseSpeedChangeInProgress;
        this.NumberOfSetCruise = copy.NumberOfSetCruise;
    }

    public void CruiseBecomesNotAllowed() {
        CruiseAllowed = new BBoolean(false);
        CruiseActive = new BBoolean(false);
        VehicleCanKeepSpeed = new BBoolean(false);
        VehicleTryKeepSpeed = new BBoolean(false);
        VehicleAtCruiseSpeed = new BBoolean(false);
        VehicleTryKeepTimeGap = new BBoolean(false);
        CruiseSpeedAtMax = new BBoolean(false);
        ObstacleDistance = ODset.ODnone;
        NumberOfSetCruise = new BInteger(0);
        ObstacleStatusJustChanged = new BBoolean(false);
        CCInitialisationInProgress = new BBoolean(false);
        CruiseSpeedChangeInProgress = new BBoolean(false);

    }

    public void CruiseBecomesAllowed() {
        CruiseAllowed = new BBoolean(true);

    }

    public void SetCruiseSpeed(BBoolean vcks, BBoolean csam) {
        BInteger _ld_NumberOfSetCruise = NumberOfSetCruise;
        BBoolean _ld_CruiseActive = CruiseActive;
        CruiseActive = new BBoolean(true);
        VehicleCanKeepSpeed = vcks;
        if((SpeedAboveMax.equal(new BBoolean(false))).booleanValue()) {
            VehicleAtCruiseSpeed = new BBoolean(true);
            CruiseSpeedAtMax = csam;
        } else {
            CruiseSpeedAtMax = new BBoolean(true);
        }

        ObstacleStatusJustChanged = new BBoolean(true);
        if((_ld_CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            CruiseSpeedChangeInProgress = new BBoolean(true);
        } else {
            CCInitialisationInProgress = new BBoolean(true);
        }

        if((_ld_NumberOfSetCruise.less(new BInteger(1))).booleanValue()) {
            NumberOfSetCruise = _ld_NumberOfSetCruise.plus(new BInteger(1));
        } 


    }

    public void CCInitialisationFinished(BBoolean vtks, BBoolean vtktg) {
        VehicleTryKeepTimeGap = vtktg;
        VehicleTryKeepSpeed = vtks;

    }

    public void CCInitialisationDelayFinished() {
        CCInitialisationInProgress = new BBoolean(true);

    }

    public void CruiseSpeedChangeFinished(BBoolean vtks, BBoolean vtktg) {
        VehicleTryKeepTimeGap = vtktg;
        VehicleTryKeepSpeed = vtks;

    }

    public void CruiseSpeedChangeDelayFinished() {
        CruiseSpeedChangeInProgress = new BBoolean(true);

    }

    public void CruiseOff() {
        CruiseActive = new BBoolean(false);
        VehicleCanKeepSpeed = new BBoolean(false);
        VehicleTryKeepSpeed = new BBoolean(false);
        VehicleAtCruiseSpeed = new BBoolean(false);
        VehicleTryKeepTimeGap = new BBoolean(false);
        CruiseSpeedAtMax = new BBoolean(false);
        ObstacleDistance = ODset.ODnone;
        NumberOfSetCruise = new BInteger(0);
        ObstacleStatusJustChanged = new BBoolean(false);
        CCInitialisationInProgress = new BBoolean(false);
        CruiseSpeedChangeInProgress = new BBoolean(false);

    }

    public void ExternalForcesBecomesExtreme() {
        VehicleCanKeepSpeed = new BBoolean(false);

    }

    public void ExternalForcesBecomesNormal() {
        VehicleCanKeepSpeed = new BBoolean(true);

    }

    public void VehicleLeavesCruiseSpeed() {
        VehicleAtCruiseSpeed = new BBoolean(false);

    }

    public void VehicleReachesCruiseSpeed() {
        VehicleAtCruiseSpeed = new BBoolean(true);

    }

    public void VehicleExceedsMaxCruiseSpeed() {
        SpeedAboveMax = new BBoolean(true);
        VehicleAtCruiseSpeed = new BBoolean(false);

    }

    public void VehicleFallsBelowMaxCruiseSpeed() {
        SpeedAboveMax = new BBoolean(false);
        if((new BBoolean(CruiseActive.equal(new BBoolean(true)).booleanValue() && CruiseSpeedAtMax.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
            VehicleAtCruiseSpeed = new BBoolean(true);
        } 


    }

    public void ObstacleDistanceBecomesVeryClose() {
        ObstacleDistance = ODset.ODveryclose;
        ObstacleStatusJustChanged = new BBoolean(true);

    }

    public void ObstacleDistanceBecomesClose() {
        ObstacleDistance = ODset.ODclose;
        ObstacleStatusJustChanged = new BBoolean(true);
        if((ObstacleRelativeSpeed.equal(RSset.RSpos)).booleanValue()) {
            VehicleTryKeepTimeGap = new BBoolean(false);
        } 


    }

    public void ObstacleDistanceBecomesBig() {
        ObstacleStatusJustChanged = new BBoolean(true);
        ObstacleDistance = ODset.ODnone;
        VehicleTryKeepTimeGap = new BBoolean(false);

    }

    public void ObstacleStartsTravelFaster() {
        ObstacleRelativeSpeed = RSset.RSpos;
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
        } 

        if((ObstacleDistance.unequal(ODset.ODveryclose)).booleanValue()) {
            VehicleTryKeepTimeGap = new BBoolean(false);
        } 


    }

    public void ObstacleStopsTravelFaster() {
        ObstacleRelativeSpeed = RSset.RSequal;
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
        } 


    }

    public void ObstacleStartsTravelSlower() {
        ObstacleRelativeSpeed = RSset.RSneg;
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
        } 


    }

    public void ObstacleStopsTravelSlower() {
        ObstacleRelativeSpeed = RSset.RSequal;
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
        } 


    }

    public void ObstacleAppearsWhenCruiseActive(RSset ors, ODset od) {
        ObstaclePresent = new BBoolean(true);
        ObstacleStatusJustChanged = new BBoolean(true);
        ObstacleRelativeSpeed = ors;
        ObstacleDistance = od;

    }

    public void ObstacleAppearsWhenCruiseInactive(RSset ors) {
        ObstaclePresent = new BBoolean(true);
        ObstacleRelativeSpeed = ors;
        ObstacleDistance = ODset.ODnone;

    }

    public void ObstacleDisappears() {
        ObstaclePresent = new BBoolean(false);
        ObstacleRelativeSpeed = RSset.RSnone;
        if((CruiseActive.equal(new BBoolean(true))).booleanValue()) {
            ObstacleStatusJustChanged = new BBoolean(true);
        } 

        ObstacleDistance = ODset.ODnone;
        VehicleTryKeepTimeGap = new BBoolean(false);

    }

    public void VehicleManageObstacle(BBoolean vtks, BBoolean vtktg) {
        VehicleTryKeepTimeGap = vtktg;
        VehicleTryKeepSpeed = vtks;

    }

    public void ObstacleBecomesOld() {
        ObstacleStatusJustChanged = new BBoolean(false);

    }

    public BBoolean _get_CruiseAllowed() {
        return CruiseAllowed;
    }

    public BBoolean _get_CruiseActive() {
        return CruiseActive;
    }

    public BBoolean _get_VehicleAtCruiseSpeed() {
        return VehicleAtCruiseSpeed;
    }

    public BBoolean _get_VehicleCanKeepSpeed() {
        return VehicleCanKeepSpeed;
    }

    public BBoolean _get_VehicleTryKeepSpeed() {
        return VehicleTryKeepSpeed;
    }

    public BBoolean _get_SpeedAboveMax() {
        return SpeedAboveMax;
    }

    public BBoolean _get_VehicleTryKeepTimeGap() {
        return VehicleTryKeepTimeGap;
    }

    public BBoolean _get_CruiseSpeedAtMax() {
        return CruiseSpeedAtMax;
    }

    public BBoolean _get_ObstaclePresent() {
        return ObstaclePresent;
    }

    public ODset _get_ObstacleDistance() {
        return ObstacleDistance;
    }

    public RSset _get_ObstacleRelativeSpeed() {
        return ObstacleRelativeSpeed;
    }

    public BBoolean _get_ObstacleStatusJustChanged() {
        return ObstacleStatusJustChanged;
    }

    public BBoolean _get_CCInitialisationInProgress() {
        return CCInitialisationInProgress;
    }

    public BBoolean _get_CruiseSpeedChangeInProgress() {
        return CruiseSpeedChangeInProgress;
    }

    public BInteger _get_NumberOfSetCruise() {
        return NumberOfSetCruise;
    }

    public BSet<RSset> _get__RSset() {
        return _RSset;
    }

    public BSet<ODset> _get__ODset() {
        return _ODset;
    }

    @Override
    public boolean equals(Object o) {
        Cruise_finite1_deterministic_MC o1 = this;
        Cruise_finite1_deterministic_MC o2 = (Cruise_finite1_deterministic_MC) o;
        return o1._get_CruiseAllowed().equals(o2._get_CruiseAllowed()) && o1._get_CruiseActive().equals(o2._get_CruiseActive()) && o1._get_VehicleAtCruiseSpeed().equals(o2._get_VehicleAtCruiseSpeed()) && o1._get_VehicleCanKeepSpeed().equals(o2._get_VehicleCanKeepSpeed()) && o1._get_VehicleTryKeepSpeed().equals(o2._get_VehicleTryKeepSpeed()) && o1._get_SpeedAboveMax().equals(o2._get_SpeedAboveMax()) && o1._get_VehicleTryKeepTimeGap().equals(o2._get_VehicleTryKeepTimeGap()) && o1._get_CruiseSpeedAtMax().equals(o2._get_CruiseSpeedAtMax()) && o1._get_ObstaclePresent().equals(o2._get_ObstaclePresent()) && o1._get_ObstacleDistance().equals(o2._get_ObstacleDistance()) && o1._get_ObstacleRelativeSpeed().equals(o2._get_ObstacleRelativeSpeed()) && o1._get_ObstacleStatusJustChanged().equals(o2._get_ObstacleStatusJustChanged()) && o1._get_CCInitialisationInProgress().equals(o2._get_CCInitialisationInProgress()) && o1._get_CruiseSpeedChangeInProgress().equals(o2._get_CruiseSpeedChangeInProgress()) && o1._get_NumberOfSetCruise().equals(o2._get_NumberOfSetCruise());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_CruiseAllowed()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_CruiseActive()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_VehicleAtCruiseSpeed()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_VehicleCanKeepSpeed()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_VehicleTryKeepSpeed()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_SpeedAboveMax()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_VehicleTryKeepTimeGap()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_CruiseSpeedAtMax()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_ObstaclePresent()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_ObstacleDistance()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_ObstacleRelativeSpeed()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_ObstacleStatusJustChanged()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_CCInitialisationInProgress()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_CruiseSpeedChangeInProgress()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_NumberOfSetCruise()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_CruiseAllowed()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_CruiseActive()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_VehicleAtCruiseSpeed()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_VehicleCanKeepSpeed()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_VehicleTryKeepSpeed()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_SpeedAboveMax()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_VehicleTryKeepTimeGap()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_CruiseSpeedAtMax()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_ObstaclePresent()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_ObstacleDistance()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_ObstacleRelativeSpeed()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_ObstacleStatusJustChanged()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_CCInitialisationInProgress()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_CruiseSpeedChangeInProgress()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_NumberOfSetCruise()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_CruiseAllowed: " + (this._get_CruiseAllowed()).toString(), "_get_CruiseActive: " + (this._get_CruiseActive()).toString(), "_get_VehicleAtCruiseSpeed: " + (this._get_VehicleAtCruiseSpeed()).toString(), "_get_VehicleCanKeepSpeed: " + (this._get_VehicleCanKeepSpeed()).toString(), "_get_VehicleTryKeepSpeed: " + (this._get_VehicleTryKeepSpeed()).toString(), "_get_SpeedAboveMax: " + (this._get_SpeedAboveMax()).toString(), "_get_VehicleTryKeepTimeGap: " + (this._get_VehicleTryKeepTimeGap()).toString(), "_get_CruiseSpeedAtMax: " + (this._get_CruiseSpeedAtMax()).toString(), "_get_ObstaclePresent: " + (this._get_ObstaclePresent()).toString(), "_get_ObstacleDistance: " + (this._get_ObstacleDistance()).toString(), "_get_ObstacleRelativeSpeed: " + (this._get_ObstacleRelativeSpeed()).toString(), "_get_ObstacleStatusJustChanged: " + (this._get_ObstacleStatusJustChanged()).toString(), "_get_CCInitialisationInProgress: " + (this._get_CCInitialisationInProgress()).toString(), "_get_CruiseSpeedChangeInProgress: " + (this._get_CruiseSpeedChangeInProgress()).toString(), "_get_NumberOfSetCruise: " + (this._get_NumberOfSetCruise()).toString());
    }

    public Cruise_finite1_deterministic_MC _copy() {
        return new Cruise_finite1_deterministic_MC(this);
    }


    public boolean _tr_CruiseBecomesNotAllowed() {
        return CruiseAllowed.equal(new BBoolean(true)).booleanValue();
    }

    public boolean _tr_CruiseBecomesAllowed() {
        return CruiseAllowed.equal(new BBoolean(false)).booleanValue();
    }

    public BSet<BTuple<BBoolean, BBoolean>> _tr_SetCruiseSpeed() {
        BSet<BTuple<BBoolean, BBoolean>> _ic_set_2 = new BSet<BTuple<BBoolean, BBoolean>>();
        for(BBoolean _ic_vcks_1 : BUtils.BOOL) {
            for(BBoolean _ic_csam_1 : BUtils.BOOL) {
                if((CruiseAllowed.equal(new BBoolean(true))).booleanValue()) {
                    _ic_set_2 = _ic_set_2.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple<>(_ic_vcks_1, _ic_csam_1)));
                }

            }
        }
        return _ic_set_2;
    }

    public BSet<BTuple<BBoolean, BBoolean>> _tr_CCInitialisationFinished() {
        BSet<BTuple<BBoolean, BBoolean>> _ic_set_3 = new BSet<BTuple<BBoolean, BBoolean>>();
        for(BBoolean _ic_vtks_1 : BUtils.BOOL) {
            for(BBoolean _ic_vtktg_1 : BUtils.BOOL) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_vtks_1.equal(new BBoolean(true)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_3 = _ic_set_3.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple<>(_ic_vtks_1, _ic_vtktg_1)));
                }

            }
        }
        return _ic_set_3;
    }

    public boolean _tr_CCInitialisationDelayFinished() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue();
    }

    public BSet<BTuple<BBoolean, BBoolean>> _tr_CruiseSpeedChangeFinished() {
        BSet<BTuple<BBoolean, BBoolean>> _ic_set_5 = new BSet<BTuple<BBoolean, BBoolean>>();
        for(BBoolean _ic_vtks_1 : BUtils.BOOL) {
            for(BBoolean _ic_vtktg_1 : BUtils.BOOL) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_vtks_1.equal(new BBoolean(true)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple<>(_ic_vtks_1, _ic_vtktg_1)));
                }

            }
        }
        return _ic_set_5;
    }

    public boolean _tr_CruiseSpeedChangeDelayFinished() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _tr_CruiseOff() {
        return CruiseActive.equal(new BBoolean(true)).booleanValue();
    }

    public boolean _tr_ExternalForcesBecomesExtreme() {
        return VehicleCanKeepSpeed.equal(new BBoolean(true)).booleanValue();
    }

    public boolean _tr_ExternalForcesBecomesNormal() {
        return new BBoolean(CruiseActive.equal(new BBoolean(true)).booleanValue() && VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _tr_VehicleLeavesCruiseSpeed() {
        return new BBoolean(new BBoolean(VehicleAtCruiseSpeed.equal(new BBoolean(true)).booleanValue() && new BBoolean(VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue() && VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _tr_VehicleReachesCruiseSpeed() {
        return new BBoolean(new BBoolean(CruiseActive.equal(new BBoolean(true)).booleanValue() && VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() && SpeedAboveMax.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _tr_VehicleExceedsMaxCruiseSpeed() {
        return new BBoolean(SpeedAboveMax.equal(new BBoolean(false)).booleanValue() && new BBoolean(new BBoolean(CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _tr_VehicleFallsBelowMaxCruiseSpeed() {
        return SpeedAboveMax.equal(new BBoolean(true)).booleanValue();
    }

    public boolean _tr_ObstacleDistanceBecomesVeryClose() {
        return new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue()).booleanValue();
    }

    public boolean _tr_ObstacleDistanceBecomesClose() {
        return new BBoolean(new BBoolean(ObstaclePresent.equal(new BBoolean(true)).booleanValue() && CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue()).booleanValue() || new BBoolean(ObstacleDistance.equal(ODset.ODnone).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue()).booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _tr_ObstacleDistanceBecomesBig() {
        return new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue()).booleanValue();
    }

    public boolean _tr_ObstacleStartsTravelFaster() {
        return new BBoolean(ObstaclePresent.equal(new BBoolean(true)).booleanValue() && ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue()).booleanValue();
    }

    public boolean _tr_ObstacleStopsTravelFaster() {
        return ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue();
    }

    public boolean _tr_ObstacleStartsTravelSlower() {
        return ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue();
    }

    public boolean _tr_ObstacleStopsTravelSlower() {
        return ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue();
    }

    public BSet<BTuple<RSset, ODset>> _tr_ObstacleAppearsWhenCruiseActive() {
        BSet<BTuple<RSset, ODset>> _ic_set_21 = new BSet<BTuple<RSset, ODset>>();
        for(RSset _ic_ors_1 : _RSset.difference(new BSet<RSset>(RSset.RSnone))) {
            for(ODset _ic_od_1 : _ODset.difference(new BSet<ODset>(ODset.ODnone))) {
                if((new BBoolean(ObstaclePresent.equal(new BBoolean(false)).booleanValue() && CruiseActive.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_21 = _ic_set_21.union(new BSet<BTuple<RSset, ODset>>(new BTuple<>(_ic_ors_1, _ic_od_1)));
                }

            }
        }
        return _ic_set_21;
    }

    public BSet<RSset> _tr_ObstacleAppearsWhenCruiseInactive() {
        BSet<RSset> _ic_set_22 = new BSet<RSset>();
        for(RSset _ic_ors_1 : _RSset.difference(new BSet<RSset>(RSset.RSnone))) {
            if((new BBoolean(ObstaclePresent.equal(new BBoolean(false)).booleanValue() && CruiseActive.equal(new BBoolean(false)).booleanValue())).booleanValue()) {
                _ic_set_22 = _ic_set_22.union(new BSet<RSset>(_ic_ors_1));
            }

        }
        return _ic_set_22;
    }

    public boolean _tr_ObstacleDisappears() {
        return ObstaclePresent.equal(new BBoolean(true)).booleanValue();
    }

    public BSet<BTuple<BBoolean, BBoolean>> _tr_VehicleManageObstacle() {
        BSet<BTuple<BBoolean, BBoolean>> _ic_set_24 = new BSet<BTuple<BBoolean, BBoolean>>();
        for(BBoolean _ic_vtks_1 : BUtils.BOOL) {
            for(BBoolean _ic_vtktg_1 : BUtils.BOOL) {
                if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_vtks_1.equal(new BBoolean(true)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || _ic_vtks_1.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() || _ic_vtktg_1.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() && ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue())).booleanValue()) {
                    _ic_set_24 = _ic_set_24.union(new BSet<BTuple<BBoolean, BBoolean>>(new BTuple<>(_ic_vtks_1, _ic_vtktg_1)));
                }

            }
        }
        return _ic_set_24;
    }

    public boolean _tr_ObstacleBecomesOld() {
        return new BBoolean(new BBoolean(new BBoolean(new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(true)).booleanValue() && new BBoolean(new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!ObstacleDistance.equal(ODset.ODnone).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue() && new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue()).booleanValue();
    }

    public _ProjectionRead_ObstacleStopsTravelSlower _projected_state_for_ObstacleStopsTravelSlower() {
        return new _ProjectionRead_ObstacleStopsTravelSlower(ObstacleRelativeSpeed,CruiseActive);
    }

    public _ProjectionRead_SetCruiseSpeed _projected_state_for_SetCruiseSpeed() {
        return new _ProjectionRead_SetCruiseSpeed(CruiseActive,CruiseAllowed,SpeedAboveMax,NumberOfSetCruise);
    }

    public _ProjectionRead_VehicleLeavesCruiseSpeed _projected_state_for_VehicleLeavesCruiseSpeed() {
        return new _ProjectionRead_VehicleLeavesCruiseSpeed(VehicleTryKeepSpeed,VehicleAtCruiseSpeed,VehicleCanKeepSpeed);
    }

    public _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed _projected_state_for_VehicleFallsBelowMaxCruiseSpeed() {
        return new _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed(CruiseSpeedAtMax,CruiseActive,SpeedAboveMax);
    }

    public _ProjectionRead_CCInitialisationFinished _projected_state_for_CCInitialisationFinished() {
        return new _ProjectionRead_CCInitialisationFinished(ObstacleStatusJustChanged,CCInitialisationInProgress,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
    }

    public _ProjectionRead_VehicleReachesCruiseSpeed _projected_state_for_VehicleReachesCruiseSpeed() {
        return new _ProjectionRead_VehicleReachesCruiseSpeed(CruiseActive,VehicleAtCruiseSpeed,SpeedAboveMax);
    }

    public _ProjectionRead_ObstacleAppearsWhenCruiseActive _projected_state_for_ObstacleAppearsWhenCruiseActive() {
        return new _ProjectionRead_ObstacleAppearsWhenCruiseActive(CruiseActive,ObstaclePresent);
    }

    public _ProjectionRead_ObstacleStartsTravelSlower _projected_state_for_ObstacleStartsTravelSlower() {
        return new _ProjectionRead_ObstacleStartsTravelSlower(ObstacleRelativeSpeed,CruiseActive);
    }

    public _ProjectionRead_CruiseBecomesNotAllowed _projected_state_for_CruiseBecomesNotAllowed() {
        return new _ProjectionRead_CruiseBecomesNotAllowed(CruiseAllowed);
    }

    public _ProjectionRead_ObstacleAppearsWhenCruiseInactive _projected_state_for_ObstacleAppearsWhenCruiseInactive() {
        return new _ProjectionRead_ObstacleAppearsWhenCruiseInactive(CruiseActive,ObstaclePresent);
    }

    public _ProjectionRead_CCInitialisationDelayFinished _projected_state_for_CCInitialisationDelayFinished() {
        return new _ProjectionRead_CCInitialisationDelayFinished(VehicleTryKeepSpeed,ObstacleRelativeSpeed,CCInitialisationInProgress,ObstacleStatusJustChanged,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
    }

    public _ProjectionRead_ObstacleDistanceBecomesClose _projected_state_for_ObstacleDistanceBecomesClose() {
        return new _ProjectionRead_ObstacleDistanceBecomesClose(ObstacleRelativeSpeed,CruiseActive,ObstaclePresent,ObstacleDistance);
    }

    public _ProjectionRead_ObstacleStartsTravelFaster _projected_state_for_ObstacleStartsTravelFaster() {
        return new _ProjectionRead_ObstacleStartsTravelFaster(ObstacleRelativeSpeed,CruiseActive,ObstaclePresent,ObstacleDistance);
    }

    public _ProjectionRead_ExternalForcesBecomesExtreme _projected_state_for_ExternalForcesBecomesExtreme() {
        return new _ProjectionRead_ExternalForcesBecomesExtreme(VehicleCanKeepSpeed);
    }

    public _ProjectionRead_CruiseOff _projected_state_for_CruiseOff() {
        return new _ProjectionRead_CruiseOff(CruiseActive);
    }

    public _ProjectionRead_CruiseSpeedChangeDelayFinished _projected_state_for_CruiseSpeedChangeDelayFinished() {
        return new _ProjectionRead_CruiseSpeedChangeDelayFinished(VehicleTryKeepSpeed,ObstacleRelativeSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
    }

    public _ProjectionRead_ObstacleStopsTravelFaster _projected_state_for_ObstacleStopsTravelFaster() {
        return new _ProjectionRead_ObstacleStopsTravelFaster(ObstacleRelativeSpeed,CruiseActive);
    }

    public _ProjectionRead_ObstacleDistanceBecomesVeryClose _projected_state_for_ObstacleDistanceBecomesVeryClose() {
        return new _ProjectionRead_ObstacleDistanceBecomesVeryClose(ObstacleRelativeSpeed,ObstacleDistance);
    }

    public _ProjectionRead_VehicleManageObstacle _projected_state_for_VehicleManageObstacle() {
        return new _ProjectionRead_VehicleManageObstacle(CCInitialisationInProgress,ObstacleStatusJustChanged,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
    }

    public _ProjectionRead_CruiseBecomesAllowed _projected_state_for_CruiseBecomesAllowed() {
        return new _ProjectionRead_CruiseBecomesAllowed(CruiseAllowed);
    }

    public _ProjectionRead_VehicleExceedsMaxCruiseSpeed _projected_state_for_VehicleExceedsMaxCruiseSpeed() {
        return new _ProjectionRead_VehicleExceedsMaxCruiseSpeed(CruiseActive,SpeedAboveMax,ObstacleStatusJustChanged,CCInitialisationInProgress,CruiseSpeedChangeInProgress,VehicleCanKeepSpeed);
    }

    public _ProjectionRead_CruiseSpeedChangeFinished _projected_state_for_CruiseSpeedChangeFinished() {
        return new _ProjectionRead_CruiseSpeedChangeFinished(ObstacleStatusJustChanged,CCInitialisationInProgress,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
    }

    public _ProjectionRead_ObstacleDisappears _projected_state_for_ObstacleDisappears() {
        return new _ProjectionRead_ObstacleDisappears(CruiseActive,ObstaclePresent);
    }

    public _ProjectionRead_ExternalForcesBecomesNormal _projected_state_for_ExternalForcesBecomesNormal() {
        return new _ProjectionRead_ExternalForcesBecomesNormal(CruiseActive,VehicleCanKeepSpeed);
    }

    public _ProjectionRead_ObstacleBecomesOld _projected_state_for_ObstacleBecomesOld() {
        return new _ProjectionRead_ObstacleBecomesOld(VehicleTryKeepSpeed,ObstacleRelativeSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
    }

    public _ProjectionRead_ObstacleDistanceBecomesBig _projected_state_for_ObstacleDistanceBecomesBig() {
        return new _ProjectionRead_ObstacleDistanceBecomesBig(ObstacleRelativeSpeed,ObstacleDistance);
    }

    public _ProjectionRead__tr_ObstacleStopsTravelSlower _projected_state_for__tr_ObstacleStopsTravelSlower() {
        return new _ProjectionRead__tr_ObstacleStopsTravelSlower(ObstacleRelativeSpeed);
    }

    public _ProjectionRead__tr_ObstacleDistanceBecomesClose _projected_state_for__tr_ObstacleDistanceBecomesClose() {
        return new _ProjectionRead__tr_ObstacleDistanceBecomesClose(ObstacleRelativeSpeed,CruiseActive,ObstaclePresent,ObstacleDistance);
    }

    public _ProjectionRead__tr_ExternalForcesBecomesExtreme _projected_state_for__tr_ExternalForcesBecomesExtreme() {
        return new _ProjectionRead__tr_ExternalForcesBecomesExtreme(VehicleCanKeepSpeed);
    }

    public _ProjectionRead__tr_ObstacleStartsTravelSlower _projected_state_for__tr_ObstacleStartsTravelSlower() {
        return new _ProjectionRead__tr_ObstacleStartsTravelSlower(ObstacleRelativeSpeed);
    }

    public _ProjectionRead__tr_VehicleReachesCruiseSpeed _projected_state_for__tr_VehicleReachesCruiseSpeed() {
        return new _ProjectionRead__tr_VehicleReachesCruiseSpeed(CruiseActive,VehicleAtCruiseSpeed,SpeedAboveMax);
    }

    public _ProjectionRead__tr_CruiseOff _projected_state_for__tr_CruiseOff() {
        return new _ProjectionRead__tr_CruiseOff(CruiseActive);
    }

    public _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed _projected_state_for__tr_VehicleFallsBelowMaxCruiseSpeed() {
        return new _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed(SpeedAboveMax);
    }

    public _ProjectionRead__tr_ObstacleBecomesOld _projected_state_for__tr_ObstacleBecomesOld() {
        return new _ProjectionRead__tr_ObstacleBecomesOld(VehicleTryKeepSpeed,ObstacleRelativeSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
    }

    public _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose _projected_state_for__tr_ObstacleDistanceBecomesVeryClose() {
        return new _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose(ObstacleRelativeSpeed,ObstacleDistance);
    }

    public _ProjectionRead__tr_ObstacleStopsTravelFaster _projected_state_for__tr_ObstacleStopsTravelFaster() {
        return new _ProjectionRead__tr_ObstacleStopsTravelFaster(ObstacleRelativeSpeed);
    }

    public _ProjectionRead__tr_SetCruiseSpeed _projected_state_for__tr_SetCruiseSpeed() {
        return new _ProjectionRead__tr_SetCruiseSpeed(CruiseAllowed);
    }

    public _ProjectionRead__tr_VehicleManageObstacle _projected_state_for__tr_VehicleManageObstacle() {
        return new _ProjectionRead__tr_VehicleManageObstacle(CCInitialisationInProgress,ObstacleStatusJustChanged,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
    }

    public _ProjectionRead__tr_CruiseBecomesAllowed _projected_state_for__tr_CruiseBecomesAllowed() {
        return new _ProjectionRead__tr_CruiseBecomesAllowed(CruiseAllowed);
    }

    public _ProjectionRead__tr_ObstacleDistanceBecomesBig _projected_state_for__tr_ObstacleDistanceBecomesBig() {
        return new _ProjectionRead__tr_ObstacleDistanceBecomesBig(ObstacleRelativeSpeed,ObstacleDistance);
    }

    public _ProjectionRead__tr_CruiseBecomesNotAllowed _projected_state_for__tr_CruiseBecomesNotAllowed() {
        return new _ProjectionRead__tr_CruiseBecomesNotAllowed(CruiseAllowed);
    }

    public _ProjectionRead__tr_ExternalForcesBecomesNormal _projected_state_for__tr_ExternalForcesBecomesNormal() {
        return new _ProjectionRead__tr_ExternalForcesBecomesNormal(CruiseActive,VehicleCanKeepSpeed);
    }

    public _ProjectionRead__tr_CruiseSpeedChangeFinished _projected_state_for__tr_CruiseSpeedChangeFinished() {
        return new _ProjectionRead__tr_CruiseSpeedChangeFinished(ObstacleStatusJustChanged,CCInitialisationInProgress,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
    }

    public _ProjectionRead__tr_ObstacleDisappears _projected_state_for__tr_ObstacleDisappears() {
        return new _ProjectionRead__tr_ObstacleDisappears(ObstaclePresent);
    }

    public _ProjectionRead__tr_CCInitialisationFinished _projected_state_for__tr_CCInitialisationFinished() {
        return new _ProjectionRead__tr_CCInitialisationFinished(ObstacleStatusJustChanged,CCInitialisationInProgress,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
    }

    public _ProjectionRead__tr_CCInitialisationDelayFinished _projected_state_for__tr_CCInitialisationDelayFinished() {
        return new _ProjectionRead__tr_CCInitialisationDelayFinished(VehicleTryKeepSpeed,ObstacleRelativeSpeed,CCInitialisationInProgress,ObstacleStatusJustChanged,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
    }

    public _ProjectionRead__tr_CruiseSpeedChangeDelayFinished _projected_state_for__tr_CruiseSpeedChangeDelayFinished() {
        return new _ProjectionRead__tr_CruiseSpeedChangeDelayFinished(VehicleTryKeepSpeed,ObstacleRelativeSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
    }

    public _ProjectionRead__tr_VehicleLeavesCruiseSpeed _projected_state_for__tr_VehicleLeavesCruiseSpeed() {
        return new _ProjectionRead__tr_VehicleLeavesCruiseSpeed(VehicleTryKeepSpeed,VehicleAtCruiseSpeed,VehicleCanKeepSpeed);
    }

    public _ProjectionRead__tr_ObstacleStartsTravelFaster _projected_state_for__tr_ObstacleStartsTravelFaster() {
        return new _ProjectionRead__tr_ObstacleStartsTravelFaster(ObstacleRelativeSpeed,ObstaclePresent);
    }

    public _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive _projected_state_for__tr_ObstacleAppearsWhenCruiseActive() {
        return new _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive(CruiseActive,ObstaclePresent);
    }

    public _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed _projected_state_for__tr_VehicleExceedsMaxCruiseSpeed() {
        return new _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed(CruiseActive,SpeedAboveMax,ObstacleStatusJustChanged,CCInitialisationInProgress,CruiseSpeedChangeInProgress,VehicleCanKeepSpeed);
    }

    public _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive _projected_state_for__tr_ObstacleAppearsWhenCruiseInactive() {
        return new _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive(CruiseActive,ObstaclePresent);
    }

    public _ProjectionRead__check_inv_18 _projected_state_for__check_inv_18() {
        return new _ProjectionRead__check_inv_18(CruiseActive,VehicleCanKeepSpeed);
    }

    public _ProjectionRead__check_inv_17 _projected_state_for__check_inv_17() {
        return new _ProjectionRead__check_inv_17(CruiseActive,VehicleAtCruiseSpeed);
    }

    public _ProjectionRead__check_inv_39 _projected_state_for__check_inv_39() {
        return new _ProjectionRead__check_inv_39(VehicleTryKeepSpeed,ObstacleRelativeSpeed,CruiseActive,ObstacleStatusJustChanged,CCInitialisationInProgress,CruiseSpeedChangeInProgress,ObstacleDistance);
    }

    public _ProjectionRead__check_inv_16 _projected_state_for__check_inv_16() {
        return new _ProjectionRead__check_inv_16(CruiseSpeedChangeInProgress);
    }

    public _ProjectionRead__check_inv_38 _projected_state_for__check_inv_38() {
        return new _ProjectionRead__check_inv_38(ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
    }

    public _ProjectionRead__check_inv_15 _projected_state_for__check_inv_15() {
        return new _ProjectionRead__check_inv_15(CCInitialisationInProgress);
    }

    public _ProjectionRead__check_inv_37 _projected_state_for__check_inv_37() {
        return new _ProjectionRead__check_inv_37(ObstacleRelativeSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
    }

    public _ProjectionRead__check_inv_19 _projected_state_for__check_inv_19() {
        return new _ProjectionRead__check_inv_19(VehicleTryKeepSpeed,CruiseActive);
    }

    public _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() {
        return new _ProjectionRead__check_inv_10(NumberOfSetCruise);
    }

    public _ProjectionRead__check_inv_32 _projected_state_for__check_inv_32() {
        return new _ProjectionRead__check_inv_32(ObstacleRelativeSpeed,VehicleTryKeepTimeGap,ObstacleDistance);
    }

    public _ProjectionRead__check_inv_31 _projected_state_for__check_inv_31() {
        return new _ProjectionRead__check_inv_31(ObstacleRelativeSpeed,VehicleTryKeepTimeGap,ObstacleDistance);
    }

    public _ProjectionRead__check_inv_30 _projected_state_for__check_inv_30() {
        return new _ProjectionRead__check_inv_30(ObstacleRelativeSpeed,VehicleTryKeepTimeGap,ObstacleDistance);
    }

    public _ProjectionRead__check_inv_14 _projected_state_for__check_inv_14() {
        return new _ProjectionRead__check_inv_14(ObstacleStatusJustChanged);
    }

    public _ProjectionRead__check_inv_36 _projected_state_for__check_inv_36() {
        return new _ProjectionRead__check_inv_36(VehicleTryKeepSpeed,CruiseActive,ObstacleStatusJustChanged,CCInitialisationInProgress,CruiseSpeedChangeInProgress,ObstacleDistance);
    }

    public _ProjectionRead__check_inv_13 _projected_state_for__check_inv_13() {
        return new _ProjectionRead__check_inv_13(ObstacleRelativeSpeed);
    }

    public _ProjectionRead__check_inv_35 _projected_state_for__check_inv_35() {
        return new _ProjectionRead__check_inv_35(VehicleTryKeepSpeed,CruiseActive,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress);
    }

    public _ProjectionRead__check_inv_12 _projected_state_for__check_inv_12() {
        return new _ProjectionRead__check_inv_12(ObstacleDistance);
    }

    public _ProjectionRead__check_inv_34 _projected_state_for__check_inv_34() {
        return new _ProjectionRead__check_inv_34(VehicleAtCruiseSpeed,SpeedAboveMax);
    }

    public _ProjectionRead__check_inv_11 _projected_state_for__check_inv_11() {
        return new _ProjectionRead__check_inv_11(ObstaclePresent);
    }

    public _ProjectionRead__check_inv_33 _projected_state_for__check_inv_33() {
        return new _ProjectionRead__check_inv_33(CruiseActive,CruiseAllowed);
    }

    public _ProjectionRead__check_inv_29 _projected_state_for__check_inv_29() {
        return new _ProjectionRead__check_inv_29(ObstacleRelativeSpeed,ObstaclePresent);
    }

    public _ProjectionRead__check_inv_28 _projected_state_for__check_inv_28() {
        return new _ProjectionRead__check_inv_28(ObstaclePresent,ObstacleDistance);
    }

    public _ProjectionRead__check_inv_27 _projected_state_for__check_inv_27() {
        return new _ProjectionRead__check_inv_27(ObstaclePresent,VehicleTryKeepTimeGap);
    }

    public _ProjectionRead__check_inv_26 _projected_state_for__check_inv_26() {
        return new _ProjectionRead__check_inv_26(CruiseActive,CruiseSpeedChangeInProgress);
    }

    public _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() {
        return new _ProjectionRead__check_inv_6(SpeedAboveMax);
    }

    public _ProjectionRead__check_inv_21 _projected_state_for__check_inv_21() {
        return new _ProjectionRead__check_inv_21(CruiseActive,VehicleTryKeepTimeGap);
    }

    public _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() {
        return new _ProjectionRead__check_inv_7(VehicleTryKeepTimeGap);
    }

    public _ProjectionRead__check_inv_20 _projected_state_for__check_inv_20() {
        return new _ProjectionRead__check_inv_20(CruiseActive,NumberOfSetCruise);
    }

    public _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() {
        return new _ProjectionRead__check_inv_4(VehicleCanKeepSpeed);
    }

    public _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() {
        return new _ProjectionRead__check_inv_5(VehicleTryKeepSpeed);
    }

    public _ProjectionRead__check_inv_25 _projected_state_for__check_inv_25() {
        return new _ProjectionRead__check_inv_25(CruiseActive,CCInitialisationInProgress);
    }

    public _ProjectionRead__check_inv_24 _projected_state_for__check_inv_24() {
        return new _ProjectionRead__check_inv_24(CruiseActive,ObstacleStatusJustChanged);
    }

    public _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() {
        return new _ProjectionRead__check_inv_8(CruiseSpeedAtMax);
    }

    public _ProjectionRead__check_inv_23 _projected_state_for__check_inv_23() {
        return new _ProjectionRead__check_inv_23(CruiseActive,ObstacleDistance);
    }

    public _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() {
        return new _ProjectionRead__check_inv_9(NumberOfSetCruise);
    }

    public _ProjectionRead__check_inv_22 _projected_state_for__check_inv_22() {
        return new _ProjectionRead__check_inv_22(CruiseSpeedAtMax,CruiseActive);
    }

    public _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() {
        return new _ProjectionRead__check_inv_2(CruiseActive);
    }

    public _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() {
        return new _ProjectionRead__check_inv_3(VehicleAtCruiseSpeed);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(CruiseAllowed);
    }

    public _ProjectionWrite_ObstacleStopsTravelSlower _update_for_ObstacleStopsTravelSlower() {
        return new _ProjectionWrite_ObstacleStopsTravelSlower(ObstacleRelativeSpeed,ObstacleStatusJustChanged);
    }

    public _ProjectionWrite_SetCruiseSpeed _update_for_SetCruiseSpeed() {
        return new _ProjectionWrite_SetCruiseSpeed(CruiseSpeedAtMax,CruiseActive,VehicleAtCruiseSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,NumberOfSetCruise,CruiseSpeedChangeInProgress,VehicleCanKeepSpeed);
    }

    public _ProjectionWrite_VehicleLeavesCruiseSpeed _update_for_VehicleLeavesCruiseSpeed() {
        return new _ProjectionWrite_VehicleLeavesCruiseSpeed(VehicleAtCruiseSpeed);
    }

    public _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed _update_for_VehicleFallsBelowMaxCruiseSpeed() {
        return new _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed(VehicleAtCruiseSpeed,SpeedAboveMax);
    }

    public _ProjectionWrite_CCInitialisationFinished _update_for_CCInitialisationFinished() {
        return new _ProjectionWrite_CCInitialisationFinished(VehicleTryKeepSpeed,VehicleTryKeepTimeGap);
    }

    public _ProjectionWrite_VehicleReachesCruiseSpeed _update_for_VehicleReachesCruiseSpeed() {
        return new _ProjectionWrite_VehicleReachesCruiseSpeed(VehicleAtCruiseSpeed);
    }

    public _ProjectionWrite_ObstacleAppearsWhenCruiseActive _update_for_ObstacleAppearsWhenCruiseActive() {
        return new _ProjectionWrite_ObstacleAppearsWhenCruiseActive(ObstacleRelativeSpeed,ObstaclePresent,ObstacleStatusJustChanged,ObstacleDistance);
    }

    public _ProjectionWrite_ObstacleStartsTravelSlower _update_for_ObstacleStartsTravelSlower() {
        return new _ProjectionWrite_ObstacleStartsTravelSlower(ObstacleRelativeSpeed,ObstacleStatusJustChanged);
    }

    public _ProjectionWrite_CruiseBecomesNotAllowed _update_for_CruiseBecomesNotAllowed() {
        return new _ProjectionWrite_CruiseBecomesNotAllowed(VehicleTryKeepSpeed,CruiseSpeedAtMax,CruiseActive,VehicleAtCruiseSpeed,CruiseAllowed,ObstacleStatusJustChanged,CCInitialisationInProgress,NumberOfSetCruise,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,VehicleCanKeepSpeed,ObstacleDistance);
    }

    public _ProjectionWrite_ObstacleAppearsWhenCruiseInactive _update_for_ObstacleAppearsWhenCruiseInactive() {
        return new _ProjectionWrite_ObstacleAppearsWhenCruiseInactive(ObstacleRelativeSpeed,ObstaclePresent,ObstacleDistance);
    }

    public _ProjectionWrite_CCInitialisationDelayFinished _update_for_CCInitialisationDelayFinished() {
        return new _ProjectionWrite_CCInitialisationDelayFinished(CCInitialisationInProgress);
    }

    public _ProjectionWrite_ObstacleDistanceBecomesClose _update_for_ObstacleDistanceBecomesClose() {
        return new _ProjectionWrite_ObstacleDistanceBecomesClose(ObstacleStatusJustChanged,VehicleTryKeepTimeGap,ObstacleDistance);
    }

    public _ProjectionWrite_ObstacleStartsTravelFaster _update_for_ObstacleStartsTravelFaster() {
        return new _ProjectionWrite_ObstacleStartsTravelFaster(ObstacleRelativeSpeed,ObstacleStatusJustChanged,VehicleTryKeepTimeGap);
    }

    public _ProjectionWrite_ExternalForcesBecomesExtreme _update_for_ExternalForcesBecomesExtreme() {
        return new _ProjectionWrite_ExternalForcesBecomesExtreme(VehicleCanKeepSpeed);
    }

    public _ProjectionWrite_CruiseOff _update_for_CruiseOff() {
        return new _ProjectionWrite_CruiseOff(VehicleTryKeepSpeed,CruiseSpeedAtMax,CruiseActive,VehicleAtCruiseSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,NumberOfSetCruise,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,VehicleCanKeepSpeed,ObstacleDistance);
    }

    public _ProjectionWrite_CruiseSpeedChangeDelayFinished _update_for_CruiseSpeedChangeDelayFinished() {
        return new _ProjectionWrite_CruiseSpeedChangeDelayFinished(CruiseSpeedChangeInProgress);
    }

    public _ProjectionWrite_ObstacleStopsTravelFaster _update_for_ObstacleStopsTravelFaster() {
        return new _ProjectionWrite_ObstacleStopsTravelFaster(ObstacleRelativeSpeed,ObstacleStatusJustChanged);
    }

    public _ProjectionWrite_ObstacleDistanceBecomesVeryClose _update_for_ObstacleDistanceBecomesVeryClose() {
        return new _ProjectionWrite_ObstacleDistanceBecomesVeryClose(ObstacleStatusJustChanged,ObstacleDistance);
    }

    public _ProjectionWrite_VehicleManageObstacle _update_for_VehicleManageObstacle() {
        return new _ProjectionWrite_VehicleManageObstacle(VehicleTryKeepSpeed,VehicleTryKeepTimeGap);
    }

    public _ProjectionWrite_CruiseBecomesAllowed _update_for_CruiseBecomesAllowed() {
        return new _ProjectionWrite_CruiseBecomesAllowed(CruiseAllowed);
    }

    public _ProjectionWrite_VehicleExceedsMaxCruiseSpeed _update_for_VehicleExceedsMaxCruiseSpeed() {
        return new _ProjectionWrite_VehicleExceedsMaxCruiseSpeed(VehicleAtCruiseSpeed,SpeedAboveMax);
    }

    public _ProjectionWrite_CruiseSpeedChangeFinished _update_for_CruiseSpeedChangeFinished() {
        return new _ProjectionWrite_CruiseSpeedChangeFinished(VehicleTryKeepSpeed,VehicleTryKeepTimeGap);
    }

    public _ProjectionWrite_ObstacleDisappears _update_for_ObstacleDisappears() {
        return new _ProjectionWrite_ObstacleDisappears(ObstacleRelativeSpeed,ObstaclePresent,ObstacleStatusJustChanged,VehicleTryKeepTimeGap,ObstacleDistance);
    }

    public _ProjectionWrite_ExternalForcesBecomesNormal _update_for_ExternalForcesBecomesNormal() {
        return new _ProjectionWrite_ExternalForcesBecomesNormal(VehicleCanKeepSpeed);
    }

    public _ProjectionWrite_ObstacleBecomesOld _update_for_ObstacleBecomesOld() {
        return new _ProjectionWrite_ObstacleBecomesOld(ObstacleStatusJustChanged);
    }

    public _ProjectionWrite_ObstacleDistanceBecomesBig _update_for_ObstacleDistanceBecomesBig() {
        return new _ProjectionWrite_ObstacleDistanceBecomesBig(ObstacleStatusJustChanged,VehicleTryKeepTimeGap,ObstacleDistance);
    }

    public void _apply_update_for_ObstacleStopsTravelSlower(_ProjectionWrite_ObstacleStopsTravelSlower update) {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
    }

    public void _apply_update_for_SetCruiseSpeed(_ProjectionWrite_SetCruiseSpeed update) {
        this.CruiseSpeedAtMax = update.CruiseSpeedAtMax;
        this.CruiseActive = update.CruiseActive;
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = update.CCInitialisationInProgress;
        this.NumberOfSetCruise = update.NumberOfSetCruise;
        this.CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
    }

    public void _apply_update_for_VehicleLeavesCruiseSpeed(_ProjectionWrite_VehicleLeavesCruiseSpeed update) {
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
    }

    public void _apply_update_for_VehicleFallsBelowMaxCruiseSpeed(_ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed update) {
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        this.SpeedAboveMax = update.SpeedAboveMax;
    }

    public void _apply_update_for_CCInitialisationFinished(_ProjectionWrite_CCInitialisationFinished update) {
        this.VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
    }

    public void _apply_update_for_VehicleReachesCruiseSpeed(_ProjectionWrite_VehicleReachesCruiseSpeed update) {
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
    }

    public void _apply_update_for_ObstacleAppearsWhenCruiseActive(_ProjectionWrite_ObstacleAppearsWhenCruiseActive update) {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstaclePresent = update.ObstaclePresent;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    public void _apply_update_for_ObstacleStartsTravelSlower(_ProjectionWrite_ObstacleStartsTravelSlower update) {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
    }

    public void _apply_update_for_CruiseBecomesNotAllowed(_ProjectionWrite_CruiseBecomesNotAllowed update) {
        this.VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
        this.CruiseSpeedAtMax = update.CruiseSpeedAtMax;
        this.CruiseActive = update.CruiseActive;
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        this.CruiseAllowed = update.CruiseAllowed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = update.CCInitialisationInProgress;
        this.NumberOfSetCruise = update.NumberOfSetCruise;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    public void _apply_update_for_ObstacleAppearsWhenCruiseInactive(_ProjectionWrite_ObstacleAppearsWhenCruiseInactive update) {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstaclePresent = update.ObstaclePresent;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    public void _apply_update_for_CCInitialisationDelayFinished(_ProjectionWrite_CCInitialisationDelayFinished update) {
        this.CCInitialisationInProgress = update.CCInitialisationInProgress;
    }

    public void _apply_update_for_ObstacleDistanceBecomesClose(_ProjectionWrite_ObstacleDistanceBecomesClose update) {
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    public void _apply_update_for_ObstacleStartsTravelFaster(_ProjectionWrite_ObstacleStartsTravelFaster update) {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
    }

    public void _apply_update_for_ExternalForcesBecomesExtreme(_ProjectionWrite_ExternalForcesBecomesExtreme update) {
        this.VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
    }

    public void _apply_update_for_CruiseOff(_ProjectionWrite_CruiseOff update) {
        this.VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
        this.CruiseSpeedAtMax = update.CruiseSpeedAtMax;
        this.CruiseActive = update.CruiseActive;
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.CCInitialisationInProgress = update.CCInitialisationInProgress;
        this.NumberOfSetCruise = update.NumberOfSetCruise;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        this.CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
        this.VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    public void _apply_update_for_CruiseSpeedChangeDelayFinished(_ProjectionWrite_CruiseSpeedChangeDelayFinished update) {
        this.CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
    }

    public void _apply_update_for_ObstacleStopsTravelFaster(_ProjectionWrite_ObstacleStopsTravelFaster update) {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
    }

    public void _apply_update_for_ObstacleDistanceBecomesVeryClose(_ProjectionWrite_ObstacleDistanceBecomesVeryClose update) {
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    public void _apply_update_for_VehicleManageObstacle(_ProjectionWrite_VehicleManageObstacle update) {
        this.VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
    }

    public void _apply_update_for_CruiseBecomesAllowed(_ProjectionWrite_CruiseBecomesAllowed update) {
        this.CruiseAllowed = update.CruiseAllowed;
    }

    public void _apply_update_for_VehicleExceedsMaxCruiseSpeed(_ProjectionWrite_VehicleExceedsMaxCruiseSpeed update) {
        this.VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        this.SpeedAboveMax = update.SpeedAboveMax;
    }

    public void _apply_update_for_CruiseSpeedChangeFinished(_ProjectionWrite_CruiseSpeedChangeFinished update) {
        this.VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
    }

    public void _apply_update_for_ObstacleDisappears(_ProjectionWrite_ObstacleDisappears update) {
        this.ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
        this.ObstaclePresent = update.ObstaclePresent;
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    public void _apply_update_for_ExternalForcesBecomesNormal(_ProjectionWrite_ExternalForcesBecomesNormal update) {
        this.VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
    }

    public void _apply_update_for_ObstacleBecomesOld(_ProjectionWrite_ObstacleBecomesOld update) {
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
    }

    public void _apply_update_for_ObstacleDistanceBecomesBig(_ProjectionWrite_ObstacleDistanceBecomesBig update) {
        this.ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        this.VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        this.ObstacleDistance = update.ObstacleDistance;
    }

    public boolean _check_inv_1() {
        return BUtils.BOOL.elementOf(CruiseAllowed).booleanValue();
    }

    public boolean _check_inv_2() {
        return BUtils.BOOL.elementOf(CruiseActive).booleanValue();
    }

    public boolean _check_inv_3() {
        return BUtils.BOOL.elementOf(VehicleAtCruiseSpeed).booleanValue();
    }

    public boolean _check_inv_4() {
        return BUtils.BOOL.elementOf(VehicleCanKeepSpeed).booleanValue();
    }

    public boolean _check_inv_5() {
        return BUtils.BOOL.elementOf(VehicleTryKeepSpeed).booleanValue();
    }

    public boolean _check_inv_6() {
        return BUtils.BOOL.elementOf(SpeedAboveMax).booleanValue();
    }

    public boolean _check_inv_7() {
        return BUtils.BOOL.elementOf(VehicleTryKeepTimeGap).booleanValue();
    }

    public boolean _check_inv_8() {
        return BUtils.BOOL.elementOf(CruiseSpeedAtMax).booleanValue();
    }

    public boolean _check_inv_9() {
        return NumberOfSetCruise.isNatural().booleanValue();
    }

    public boolean _check_inv_10() {
        return new BBoolean(NumberOfSetCruise.greaterEqual(new BInteger(0)).booleanValue() && NumberOfSetCruise.lessEqual(new BInteger(1)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_11() {
        return BUtils.BOOL.elementOf(ObstaclePresent).booleanValue();
    }

    public boolean _check_inv_12() {
        return _ODset.elementOf(ObstacleDistance).booleanValue();
    }

    public boolean _check_inv_13() {
        return _RSset.elementOf(ObstacleRelativeSpeed).booleanValue();
    }

    public boolean _check_inv_14() {
        return BUtils.BOOL.elementOf(ObstacleStatusJustChanged).booleanValue();
    }

    public boolean _check_inv_15() {
        return BUtils.BOOL.elementOf(CCInitialisationInProgress).booleanValue();
    }

    public boolean _check_inv_16() {
        return BUtils.BOOL.elementOf(CruiseSpeedChangeInProgress).booleanValue();
    }

    public boolean _check_inv_17() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_18() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleCanKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_19() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_20() {
        return new BBoolean((!NumberOfSetCruise.equal(new BInteger(0)).booleanValue() || CruiseActive.equal(new BBoolean(false)).booleanValue()) && (!CruiseActive.equal(new BBoolean(false)).booleanValue() || NumberOfSetCruise.equal(new BInteger(0)).booleanValue())).booleanValue();
    }

    public boolean _check_inv_21() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_22() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || CruiseSpeedAtMax.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_23() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue();
    }

    public boolean _check_inv_24() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_25() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_26() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(false)).booleanValue() || CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_27() {
        return new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_28() {
        return new BBoolean(!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue();
    }

    public boolean _check_inv_29() {
        return new BBoolean((!ObstaclePresent.equal(new BBoolean(false)).booleanValue() || ObstacleRelativeSpeed.equal(RSset.RSnone).booleanValue()) && (!ObstacleRelativeSpeed.equal(RSset.RSnone).booleanValue() || ObstaclePresent.equal(new BBoolean(false)).booleanValue())).booleanValue();
    }

    public boolean _check_inv_30() {
        return new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSequal).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_31() {
        return new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSneg).booleanValue() && ObstacleDistance.equal(ODset.ODnone).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_32() {
        return new BBoolean(!new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_33() {
        return new BBoolean(!CruiseAllowed.equal(new BBoolean(false)).booleanValue() || CruiseActive.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_34() {
        return new BBoolean(!SpeedAboveMax.equal(new BBoolean(true)).booleanValue() || VehicleAtCruiseSpeed.equal(new BBoolean(false)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_35() {
        return new BBoolean(!CruiseActive.equal(new BBoolean(true)).booleanValue() || new BBoolean(new BBoolean(VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue() || new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).not().booleanValue()).booleanValue()).booleanValue();
    }

    public boolean _check_inv_36() {
        return new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODnone).booleanValue() && CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_37() {
        return new BBoolean(!new BBoolean(new BBoolean(ObstacleDistance.equal(ODset.ODclose).booleanValue() && ObstacleRelativeSpeed.unequal(RSset.RSpos).booleanValue()).booleanValue() && new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_38() {
        return new BBoolean(!new BBoolean(ObstacleDistance.equal(ODset.ODveryclose).booleanValue() && new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepTimeGap.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }

    public boolean _check_inv_39() {
        return new BBoolean(!new BBoolean(new BBoolean(new BBoolean(ObstacleRelativeSpeed.equal(RSset.RSpos).booleanValue() && ObstacleDistance.unequal(ODset.ODveryclose).booleanValue()).booleanValue() && CruiseActive.equal(new BBoolean(true)).booleanValue()).booleanValue() && new BBoolean(new BBoolean(ObstacleStatusJustChanged.equal(new BBoolean(false)).booleanValue() && CCInitialisationInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue() && CruiseSpeedChangeInProgress.equal(new BBoolean(false)).booleanValue()).booleanValue()).booleanValue() || VehicleTryKeepSpeed.equal(new BBoolean(true)).booleanValue()).booleanValue();
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<Cruise_finite1_deterministic_MC> unvisitedStates = new LinkedList<>();
        private final Set<Cruise_finite1_deterministic_MC> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private Cruise_finite1_deterministic_MC counterExampleState = null;

        PersistentHashMap _OpCache_CruiseBecomesNotAllowed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_CruiseBecomesNotAllowed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_CruiseBecomesAllowed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_CruiseBecomesAllowed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_SetCruiseSpeed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_SetCruiseSpeed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_CCInitialisationFinished = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_CCInitialisationFinished = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_CCInitialisationDelayFinished = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_CCInitialisationDelayFinished = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_CruiseSpeedChangeFinished = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_CruiseSpeedChangeFinished = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_CruiseSpeedChangeDelayFinished = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_CruiseSpeedChangeDelayFinished = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_CruiseOff = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_CruiseOff = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ExternalForcesBecomesExtreme = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ExternalForcesBecomesExtreme = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ExternalForcesBecomesNormal = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ExternalForcesBecomesNormal = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_VehicleLeavesCruiseSpeed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_VehicleLeavesCruiseSpeed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_VehicleReachesCruiseSpeed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_VehicleReachesCruiseSpeed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_VehicleExceedsMaxCruiseSpeed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_VehicleExceedsMaxCruiseSpeed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_VehicleFallsBelowMaxCruiseSpeed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_VehicleFallsBelowMaxCruiseSpeed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleDistanceBecomesVeryClose = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleDistanceBecomesVeryClose = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleDistanceBecomesClose = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleDistanceBecomesClose = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleDistanceBecomesBig = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleDistanceBecomesBig = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleStartsTravelFaster = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleStartsTravelFaster = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleStopsTravelFaster = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleStopsTravelFaster = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleStartsTravelSlower = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleStartsTravelSlower = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleStopsTravelSlower = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleStopsTravelSlower = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleAppearsWhenCruiseActive = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleAppearsWhenCruiseActive = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleAppearsWhenCruiseInactive = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleAppearsWhenCruiseInactive = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleDisappears = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleDisappears = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_VehicleManageObstacle = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_VehicleManageObstacle = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_ObstacleBecomesOld = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_ObstacleBecomesOld = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_2 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_3 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_4 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_5 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_6 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_7 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_8 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_9 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_10 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_11 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_12 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_13 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_14 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_15 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_16 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_17 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_18 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_19 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_20 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_21 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_22 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_23 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_24 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_25 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_26 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_27 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_28 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_29 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_30 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_31 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_32 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_33 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_34 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_35 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_36 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_37 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_38 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_39 = PersistentHashMap.EMPTY;

        public ModelChecker(final Type type, final int threads, final boolean isCaching, final boolean isDebug) {
            this.type = type;
            this.threads = threads;
            this.isCaching = isCaching;
            this.isDebug = isDebug;
        }

        public void modelCheck() {
            if (isDebug) {
                System.out.println("Starting Modelchecking, STRATEGY=" + type + ", THREADS=" + threads + ", CACHING=" + isCaching);
            }

            if (threads <= 1) {

                modelCheckSingleThreaded();
            } else {
                this.threadPool = (ThreadPoolExecutor) Executors.newFixedThreadPool(threads-1);
                modelCheckMultiThreaded();
            }
        }

        private void modelCheckSingleThreaded() {
            Cruise_finite1_deterministic_MC machine = new Cruise_finite1_deterministic_MC();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                Cruise_finite1_deterministic_MC state = next();

                Set<Cruise_finite1_deterministic_MC> nextStates = generateNextStates(state);

                nextStates.forEach(nextState -> {
                    if(!states.contains(nextState)) {
                        states.add(nextState);
                        unvisitedStates.add(nextState);
                        if(isDebug && states.size() % 50000 == 0) {
                            System.out.println("VISITED STATES: " + states.size());
                            System.out.println("OPEN STATES: " + unvisitedStates.size());
                            System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                            System.out.println("-------------------");
                        }
                    }
                });

                if(invariantViolated(state)) {
                    invariantViolated.set(true);
                    counterExampleState = state;
                    break;
                }

                if(nextStates.isEmpty()) {
                    deadlockDetected.set(true);
                    counterExampleState = state;
                    break;
                }

            }
            printResult(states.size(), transitions.get());
        }

        private void modelCheckMultiThreaded() {
            Cruise_finite1_deterministic_MC machine = new Cruise_finite1_deterministic_MC();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                Cruise_finite1_deterministic_MC state = next();
                Runnable task = () -> {
                    Set<Cruise_finite1_deterministic_MC> nextStates = generateNextStates(state);

                    nextStates.forEach(nextState -> {
                        if(states.add(nextState)) {
                            synchronized (unvisitedStates) {
                                unvisitedStates.add(nextState);
                            }
                            if(isDebug && states.size() % 50000 == 0) {
                                System.out.println("VISITED STATES: " + states.size());
                                System.out.println("OPEN STATES: " + unvisitedStates.size());
                                System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                System.out.println("-------------------");
                            }
                        }
                    });

                    int running = possibleQueueChanges.decrementAndGet();
                    synchronized (unvisitedStates) {
                        if (!unvisitedStates.isEmpty() || running == 0) {
                            synchronized (waitLock) {
                                waitLock.notify();
                            }
                        }
                    }

                    if(invariantViolated(state)) {
                        invariantViolated.set(true);
                        counterExampleState = state;
                        stopThreads.set(true);
                    }

                    if(nextStates.isEmpty()) {
                        deadlockDetected.set(true);
                        counterExampleState = state;
                        stopThreads.set(true);
                    }
                };
                threadPool.submit(task);
                synchronized(waitLock) {
                    if (unvisitedStates.isEmpty() && possibleQueueChanges.get() > 0) {
                        try {
                            waitLock.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
            threadPool.shutdown();
            try {
                threadPool.awaitTermination(24, TimeUnit.HOURS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            printResult(states.size(), transitions.get());
        }

        private Cruise_finite1_deterministic_MC next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<Cruise_finite1_deterministic_MC> generateNextStates(final Cruise_finite1_deterministic_MC state) {
            Set<Cruise_finite1_deterministic_MC> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_CruiseBecomesNotAllowed read__tr_CruiseBecomesNotAllowed_state = state._projected_state_for__tr_CruiseBecomesNotAllowed();
                Object _obj__trid_1 = GET.invoke(_OpCache_tr_CruiseBecomesNotAllowed, read__tr_CruiseBecomesNotAllowed_state);
                boolean _trid_1;
                if(_obj__trid_1 == null) {
                    _trid_1 = state._tr_CruiseBecomesNotAllowed();
                    _OpCache_tr_CruiseBecomesNotAllowed = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_CruiseBecomesNotAllowed, read__tr_CruiseBecomesNotAllowed_state, _trid_1);
                } else {
                    _trid_1 = (boolean) _obj__trid_1;
                }
                if(_trid_1) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_CruiseBecomesNotAllowed readState = state._projected_state_for_CruiseBecomesNotAllowed();
                    PersistentHashMap _OpCache_with_parameter_CruiseBecomesNotAllowed = (PersistentHashMap) GET.invoke(_OpCache_CruiseBecomesNotAllowed, _trid_1);
                    if(_OpCache_with_parameter_CruiseBecomesNotAllowed != null) {
                        _ProjectionWrite_CruiseBecomesNotAllowed writeState = (_ProjectionWrite_CruiseBecomesNotAllowed) GET.invoke(_OpCache_with_parameter_CruiseBecomesNotAllowed, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_CruiseBecomesNotAllowed(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.CruiseBecomesNotAllowed();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_CruiseBecomesNotAllowed();
                            _OpCache_with_parameter_CruiseBecomesNotAllowed = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_CruiseBecomesNotAllowed, readState, writeState);
                            _OpCache_CruiseBecomesNotAllowed = (PersistentHashMap) ASSOC.invoke(_OpCache_CruiseBecomesNotAllowed, _trid_1, _OpCache_with_parameter_CruiseBecomesNotAllowed);
                        }

                    } else {
                        copiedState.CruiseBecomesNotAllowed();
                        copiedState.parent = state;
                        _ProjectionWrite_CruiseBecomesNotAllowed writeState = copiedState._update_for_CruiseBecomesNotAllowed();
                        _OpCache_with_parameter_CruiseBecomesNotAllowed = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_CruiseBecomesNotAllowed = (PersistentHashMap) ASSOC.invoke(_OpCache_CruiseBecomesNotAllowed, _trid_1, _OpCache_with_parameter_CruiseBecomesNotAllowed);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_CruiseBecomesAllowed read__tr_CruiseBecomesAllowed_state = state._projected_state_for__tr_CruiseBecomesAllowed();
                Object _obj__trid_2 = GET.invoke(_OpCache_tr_CruiseBecomesAllowed, read__tr_CruiseBecomesAllowed_state);
                boolean _trid_2;
                if(_obj__trid_2 == null) {
                    _trid_2 = state._tr_CruiseBecomesAllowed();
                    _OpCache_tr_CruiseBecomesAllowed = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_CruiseBecomesAllowed, read__tr_CruiseBecomesAllowed_state, _trid_2);
                } else {
                    _trid_2 = (boolean) _obj__trid_2;
                }
                if(_trid_2) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_CruiseBecomesAllowed readState = state._projected_state_for_CruiseBecomesAllowed();
                    PersistentHashMap _OpCache_with_parameter_CruiseBecomesAllowed = (PersistentHashMap) GET.invoke(_OpCache_CruiseBecomesAllowed, _trid_2);
                    if(_OpCache_with_parameter_CruiseBecomesAllowed != null) {
                        _ProjectionWrite_CruiseBecomesAllowed writeState = (_ProjectionWrite_CruiseBecomesAllowed) GET.invoke(_OpCache_with_parameter_CruiseBecomesAllowed, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_CruiseBecomesAllowed(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.CruiseBecomesAllowed();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_CruiseBecomesAllowed();
                            _OpCache_with_parameter_CruiseBecomesAllowed = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_CruiseBecomesAllowed, readState, writeState);
                            _OpCache_CruiseBecomesAllowed = (PersistentHashMap) ASSOC.invoke(_OpCache_CruiseBecomesAllowed, _trid_2, _OpCache_with_parameter_CruiseBecomesAllowed);
                        }

                    } else {
                        copiedState.CruiseBecomesAllowed();
                        copiedState.parent = state;
                        _ProjectionWrite_CruiseBecomesAllowed writeState = copiedState._update_for_CruiseBecomesAllowed();
                        _OpCache_with_parameter_CruiseBecomesAllowed = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_CruiseBecomesAllowed = (PersistentHashMap) ASSOC.invoke(_OpCache_CruiseBecomesAllowed, _trid_2, _OpCache_with_parameter_CruiseBecomesAllowed);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_SetCruiseSpeed read__tr_SetCruiseSpeed_state = state._projected_state_for__tr_SetCruiseSpeed();
                BSet<BTuple<BBoolean, BBoolean>> _trid_3 = (BSet<BTuple<BBoolean, BBoolean>>) GET.invoke(_OpCache_tr_SetCruiseSpeed, read__tr_SetCruiseSpeed_state);
                if(_trid_3 == null) {
                    _trid_3 = state._tr_SetCruiseSpeed();
                    _OpCache_tr_SetCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_SetCruiseSpeed, read__tr_SetCruiseSpeed_state, _trid_3);
                }
                for(BTuple<BBoolean, BBoolean> param : _trid_3) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_SetCruiseSpeed readState = state._projected_state_for_SetCruiseSpeed();
                    PersistentHashMap _OpCache_with_parameter_SetCruiseSpeed = (PersistentHashMap) GET.invoke(_OpCache_SetCruiseSpeed, param);
                    if(_OpCache_with_parameter_SetCruiseSpeed != null) {
                        _ProjectionWrite_SetCruiseSpeed writeState = (_ProjectionWrite_SetCruiseSpeed) GET.invoke(_OpCache_with_parameter_SetCruiseSpeed, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_SetCruiseSpeed(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_SetCruiseSpeed();
                            _OpCache_with_parameter_SetCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_SetCruiseSpeed, readState, writeState);
                            _OpCache_SetCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_SetCruiseSpeed, param, _OpCache_with_parameter_SetCruiseSpeed);
                        }

                    } else {
                        copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_SetCruiseSpeed writeState = copiedState._update_for_SetCruiseSpeed();
                        _OpCache_with_parameter_SetCruiseSpeed = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_SetCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_SetCruiseSpeed, param, _OpCache_with_parameter_SetCruiseSpeed);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_CCInitialisationFinished read__tr_CCInitialisationFinished_state = state._projected_state_for__tr_CCInitialisationFinished();
                BSet<BTuple<BBoolean, BBoolean>> _trid_4 = (BSet<BTuple<BBoolean, BBoolean>>) GET.invoke(_OpCache_tr_CCInitialisationFinished, read__tr_CCInitialisationFinished_state);
                if(_trid_4 == null) {
                    _trid_4 = state._tr_CCInitialisationFinished();
                    _OpCache_tr_CCInitialisationFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_CCInitialisationFinished, read__tr_CCInitialisationFinished_state, _trid_4);
                }
                for(BTuple<BBoolean, BBoolean> param : _trid_4) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_CCInitialisationFinished readState = state._projected_state_for_CCInitialisationFinished();
                    PersistentHashMap _OpCache_with_parameter_CCInitialisationFinished = (PersistentHashMap) GET.invoke(_OpCache_CCInitialisationFinished, param);
                    if(_OpCache_with_parameter_CCInitialisationFinished != null) {
                        _ProjectionWrite_CCInitialisationFinished writeState = (_ProjectionWrite_CCInitialisationFinished) GET.invoke(_OpCache_with_parameter_CCInitialisationFinished, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_CCInitialisationFinished(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_CCInitialisationFinished();
                            _OpCache_with_parameter_CCInitialisationFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_CCInitialisationFinished, readState, writeState);
                            _OpCache_CCInitialisationFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_CCInitialisationFinished, param, _OpCache_with_parameter_CCInitialisationFinished);
                        }

                    } else {
                        copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_CCInitialisationFinished writeState = copiedState._update_for_CCInitialisationFinished();
                        _OpCache_with_parameter_CCInitialisationFinished = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_CCInitialisationFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_CCInitialisationFinished, param, _OpCache_with_parameter_CCInitialisationFinished);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_CCInitialisationDelayFinished read__tr_CCInitialisationDelayFinished_state = state._projected_state_for__tr_CCInitialisationDelayFinished();
                Object _obj__trid_5 = GET.invoke(_OpCache_tr_CCInitialisationDelayFinished, read__tr_CCInitialisationDelayFinished_state);
                boolean _trid_5;
                if(_obj__trid_5 == null) {
                    _trid_5 = state._tr_CCInitialisationDelayFinished();
                    _OpCache_tr_CCInitialisationDelayFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_CCInitialisationDelayFinished, read__tr_CCInitialisationDelayFinished_state, _trid_5);
                } else {
                    _trid_5 = (boolean) _obj__trid_5;
                }
                if(_trid_5) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_CCInitialisationDelayFinished readState = state._projected_state_for_CCInitialisationDelayFinished();
                    PersistentHashMap _OpCache_with_parameter_CCInitialisationDelayFinished = (PersistentHashMap) GET.invoke(_OpCache_CCInitialisationDelayFinished, _trid_5);
                    if(_OpCache_with_parameter_CCInitialisationDelayFinished != null) {
                        _ProjectionWrite_CCInitialisationDelayFinished writeState = (_ProjectionWrite_CCInitialisationDelayFinished) GET.invoke(_OpCache_with_parameter_CCInitialisationDelayFinished, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_CCInitialisationDelayFinished(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.CCInitialisationDelayFinished();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_CCInitialisationDelayFinished();
                            _OpCache_with_parameter_CCInitialisationDelayFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_CCInitialisationDelayFinished, readState, writeState);
                            _OpCache_CCInitialisationDelayFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_CCInitialisationDelayFinished, _trid_5, _OpCache_with_parameter_CCInitialisationDelayFinished);
                        }

                    } else {
                        copiedState.CCInitialisationDelayFinished();
                        copiedState.parent = state;
                        _ProjectionWrite_CCInitialisationDelayFinished writeState = copiedState._update_for_CCInitialisationDelayFinished();
                        _OpCache_with_parameter_CCInitialisationDelayFinished = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_CCInitialisationDelayFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_CCInitialisationDelayFinished, _trid_5, _OpCache_with_parameter_CCInitialisationDelayFinished);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_CruiseSpeedChangeFinished read__tr_CruiseSpeedChangeFinished_state = state._projected_state_for__tr_CruiseSpeedChangeFinished();
                BSet<BTuple<BBoolean, BBoolean>> _trid_6 = (BSet<BTuple<BBoolean, BBoolean>>) GET.invoke(_OpCache_tr_CruiseSpeedChangeFinished, read__tr_CruiseSpeedChangeFinished_state);
                if(_trid_6 == null) {
                    _trid_6 = state._tr_CruiseSpeedChangeFinished();
                    _OpCache_tr_CruiseSpeedChangeFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_CruiseSpeedChangeFinished, read__tr_CruiseSpeedChangeFinished_state, _trid_6);
                }
                for(BTuple<BBoolean, BBoolean> param : _trid_6) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_CruiseSpeedChangeFinished readState = state._projected_state_for_CruiseSpeedChangeFinished();
                    PersistentHashMap _OpCache_with_parameter_CruiseSpeedChangeFinished = (PersistentHashMap) GET.invoke(_OpCache_CruiseSpeedChangeFinished, param);
                    if(_OpCache_with_parameter_CruiseSpeedChangeFinished != null) {
                        _ProjectionWrite_CruiseSpeedChangeFinished writeState = (_ProjectionWrite_CruiseSpeedChangeFinished) GET.invoke(_OpCache_with_parameter_CruiseSpeedChangeFinished, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_CruiseSpeedChangeFinished(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_CruiseSpeedChangeFinished();
                            _OpCache_with_parameter_CruiseSpeedChangeFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_CruiseSpeedChangeFinished, readState, writeState);
                            _OpCache_CruiseSpeedChangeFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_CruiseSpeedChangeFinished, param, _OpCache_with_parameter_CruiseSpeedChangeFinished);
                        }

                    } else {
                        copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_CruiseSpeedChangeFinished writeState = copiedState._update_for_CruiseSpeedChangeFinished();
                        _OpCache_with_parameter_CruiseSpeedChangeFinished = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_CruiseSpeedChangeFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_CruiseSpeedChangeFinished, param, _OpCache_with_parameter_CruiseSpeedChangeFinished);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_CruiseSpeedChangeDelayFinished read__tr_CruiseSpeedChangeDelayFinished_state = state._projected_state_for__tr_CruiseSpeedChangeDelayFinished();
                Object _obj__trid_7 = GET.invoke(_OpCache_tr_CruiseSpeedChangeDelayFinished, read__tr_CruiseSpeedChangeDelayFinished_state);
                boolean _trid_7;
                if(_obj__trid_7 == null) {
                    _trid_7 = state._tr_CruiseSpeedChangeDelayFinished();
                    _OpCache_tr_CruiseSpeedChangeDelayFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_CruiseSpeedChangeDelayFinished, read__tr_CruiseSpeedChangeDelayFinished_state, _trid_7);
                } else {
                    _trid_7 = (boolean) _obj__trid_7;
                }
                if(_trid_7) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_CruiseSpeedChangeDelayFinished readState = state._projected_state_for_CruiseSpeedChangeDelayFinished();
                    PersistentHashMap _OpCache_with_parameter_CruiseSpeedChangeDelayFinished = (PersistentHashMap) GET.invoke(_OpCache_CruiseSpeedChangeDelayFinished, _trid_7);
                    if(_OpCache_with_parameter_CruiseSpeedChangeDelayFinished != null) {
                        _ProjectionWrite_CruiseSpeedChangeDelayFinished writeState = (_ProjectionWrite_CruiseSpeedChangeDelayFinished) GET.invoke(_OpCache_with_parameter_CruiseSpeedChangeDelayFinished, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_CruiseSpeedChangeDelayFinished(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.CruiseSpeedChangeDelayFinished();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_CruiseSpeedChangeDelayFinished();
                            _OpCache_with_parameter_CruiseSpeedChangeDelayFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_CruiseSpeedChangeDelayFinished, readState, writeState);
                            _OpCache_CruiseSpeedChangeDelayFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_CruiseSpeedChangeDelayFinished, _trid_7, _OpCache_with_parameter_CruiseSpeedChangeDelayFinished);
                        }

                    } else {
                        copiedState.CruiseSpeedChangeDelayFinished();
                        copiedState.parent = state;
                        _ProjectionWrite_CruiseSpeedChangeDelayFinished writeState = copiedState._update_for_CruiseSpeedChangeDelayFinished();
                        _OpCache_with_parameter_CruiseSpeedChangeDelayFinished = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_CruiseSpeedChangeDelayFinished = (PersistentHashMap) ASSOC.invoke(_OpCache_CruiseSpeedChangeDelayFinished, _trid_7, _OpCache_with_parameter_CruiseSpeedChangeDelayFinished);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_CruiseOff read__tr_CruiseOff_state = state._projected_state_for__tr_CruiseOff();
                Object _obj__trid_8 = GET.invoke(_OpCache_tr_CruiseOff, read__tr_CruiseOff_state);
                boolean _trid_8;
                if(_obj__trid_8 == null) {
                    _trid_8 = state._tr_CruiseOff();
                    _OpCache_tr_CruiseOff = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_CruiseOff, read__tr_CruiseOff_state, _trid_8);
                } else {
                    _trid_8 = (boolean) _obj__trid_8;
                }
                if(_trid_8) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_CruiseOff readState = state._projected_state_for_CruiseOff();
                    PersistentHashMap _OpCache_with_parameter_CruiseOff = (PersistentHashMap) GET.invoke(_OpCache_CruiseOff, _trid_8);
                    if(_OpCache_with_parameter_CruiseOff != null) {
                        _ProjectionWrite_CruiseOff writeState = (_ProjectionWrite_CruiseOff) GET.invoke(_OpCache_with_parameter_CruiseOff, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_CruiseOff(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.CruiseOff();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_CruiseOff();
                            _OpCache_with_parameter_CruiseOff = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_CruiseOff, readState, writeState);
                            _OpCache_CruiseOff = (PersistentHashMap) ASSOC.invoke(_OpCache_CruiseOff, _trid_8, _OpCache_with_parameter_CruiseOff);
                        }

                    } else {
                        copiedState.CruiseOff();
                        copiedState.parent = state;
                        _ProjectionWrite_CruiseOff writeState = copiedState._update_for_CruiseOff();
                        _OpCache_with_parameter_CruiseOff = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_CruiseOff = (PersistentHashMap) ASSOC.invoke(_OpCache_CruiseOff, _trid_8, _OpCache_with_parameter_CruiseOff);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ExternalForcesBecomesExtreme read__tr_ExternalForcesBecomesExtreme_state = state._projected_state_for__tr_ExternalForcesBecomesExtreme();
                Object _obj__trid_9 = GET.invoke(_OpCache_tr_ExternalForcesBecomesExtreme, read__tr_ExternalForcesBecomesExtreme_state);
                boolean _trid_9;
                if(_obj__trid_9 == null) {
                    _trid_9 = state._tr_ExternalForcesBecomesExtreme();
                    _OpCache_tr_ExternalForcesBecomesExtreme = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ExternalForcesBecomesExtreme, read__tr_ExternalForcesBecomesExtreme_state, _trid_9);
                } else {
                    _trid_9 = (boolean) _obj__trid_9;
                }
                if(_trid_9) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ExternalForcesBecomesExtreme readState = state._projected_state_for_ExternalForcesBecomesExtreme();
                    PersistentHashMap _OpCache_with_parameter_ExternalForcesBecomesExtreme = (PersistentHashMap) GET.invoke(_OpCache_ExternalForcesBecomesExtreme, _trid_9);
                    if(_OpCache_with_parameter_ExternalForcesBecomesExtreme != null) {
                        _ProjectionWrite_ExternalForcesBecomesExtreme writeState = (_ProjectionWrite_ExternalForcesBecomesExtreme) GET.invoke(_OpCache_with_parameter_ExternalForcesBecomesExtreme, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ExternalForcesBecomesExtreme(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ExternalForcesBecomesExtreme();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ExternalForcesBecomesExtreme();
                            _OpCache_with_parameter_ExternalForcesBecomesExtreme = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ExternalForcesBecomesExtreme, readState, writeState);
                            _OpCache_ExternalForcesBecomesExtreme = (PersistentHashMap) ASSOC.invoke(_OpCache_ExternalForcesBecomesExtreme, _trid_9, _OpCache_with_parameter_ExternalForcesBecomesExtreme);
                        }

                    } else {
                        copiedState.ExternalForcesBecomesExtreme();
                        copiedState.parent = state;
                        _ProjectionWrite_ExternalForcesBecomesExtreme writeState = copiedState._update_for_ExternalForcesBecomesExtreme();
                        _OpCache_with_parameter_ExternalForcesBecomesExtreme = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ExternalForcesBecomesExtreme = (PersistentHashMap) ASSOC.invoke(_OpCache_ExternalForcesBecomesExtreme, _trid_9, _OpCache_with_parameter_ExternalForcesBecomesExtreme);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ExternalForcesBecomesNormal read__tr_ExternalForcesBecomesNormal_state = state._projected_state_for__tr_ExternalForcesBecomesNormal();
                Object _obj__trid_10 = GET.invoke(_OpCache_tr_ExternalForcesBecomesNormal, read__tr_ExternalForcesBecomesNormal_state);
                boolean _trid_10;
                if(_obj__trid_10 == null) {
                    _trid_10 = state._tr_ExternalForcesBecomesNormal();
                    _OpCache_tr_ExternalForcesBecomesNormal = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ExternalForcesBecomesNormal, read__tr_ExternalForcesBecomesNormal_state, _trid_10);
                } else {
                    _trid_10 = (boolean) _obj__trid_10;
                }
                if(_trid_10) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ExternalForcesBecomesNormal readState = state._projected_state_for_ExternalForcesBecomesNormal();
                    PersistentHashMap _OpCache_with_parameter_ExternalForcesBecomesNormal = (PersistentHashMap) GET.invoke(_OpCache_ExternalForcesBecomesNormal, _trid_10);
                    if(_OpCache_with_parameter_ExternalForcesBecomesNormal != null) {
                        _ProjectionWrite_ExternalForcesBecomesNormal writeState = (_ProjectionWrite_ExternalForcesBecomesNormal) GET.invoke(_OpCache_with_parameter_ExternalForcesBecomesNormal, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ExternalForcesBecomesNormal(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ExternalForcesBecomesNormal();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ExternalForcesBecomesNormal();
                            _OpCache_with_parameter_ExternalForcesBecomesNormal = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ExternalForcesBecomesNormal, readState, writeState);
                            _OpCache_ExternalForcesBecomesNormal = (PersistentHashMap) ASSOC.invoke(_OpCache_ExternalForcesBecomesNormal, _trid_10, _OpCache_with_parameter_ExternalForcesBecomesNormal);
                        }

                    } else {
                        copiedState.ExternalForcesBecomesNormal();
                        copiedState.parent = state;
                        _ProjectionWrite_ExternalForcesBecomesNormal writeState = copiedState._update_for_ExternalForcesBecomesNormal();
                        _OpCache_with_parameter_ExternalForcesBecomesNormal = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ExternalForcesBecomesNormal = (PersistentHashMap) ASSOC.invoke(_OpCache_ExternalForcesBecomesNormal, _trid_10, _OpCache_with_parameter_ExternalForcesBecomesNormal);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_VehicleLeavesCruiseSpeed read__tr_VehicleLeavesCruiseSpeed_state = state._projected_state_for__tr_VehicleLeavesCruiseSpeed();
                Object _obj__trid_11 = GET.invoke(_OpCache_tr_VehicleLeavesCruiseSpeed, read__tr_VehicleLeavesCruiseSpeed_state);
                boolean _trid_11;
                if(_obj__trid_11 == null) {
                    _trid_11 = state._tr_VehicleLeavesCruiseSpeed();
                    _OpCache_tr_VehicleLeavesCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_VehicleLeavesCruiseSpeed, read__tr_VehicleLeavesCruiseSpeed_state, _trid_11);
                } else {
                    _trid_11 = (boolean) _obj__trid_11;
                }
                if(_trid_11) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_VehicleLeavesCruiseSpeed readState = state._projected_state_for_VehicleLeavesCruiseSpeed();
                    PersistentHashMap _OpCache_with_parameter_VehicleLeavesCruiseSpeed = (PersistentHashMap) GET.invoke(_OpCache_VehicleLeavesCruiseSpeed, _trid_11);
                    if(_OpCache_with_parameter_VehicleLeavesCruiseSpeed != null) {
                        _ProjectionWrite_VehicleLeavesCruiseSpeed writeState = (_ProjectionWrite_VehicleLeavesCruiseSpeed) GET.invoke(_OpCache_with_parameter_VehicleLeavesCruiseSpeed, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_VehicleLeavesCruiseSpeed(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.VehicleLeavesCruiseSpeed();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_VehicleLeavesCruiseSpeed();
                            _OpCache_with_parameter_VehicleLeavesCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_VehicleLeavesCruiseSpeed, readState, writeState);
                            _OpCache_VehicleLeavesCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_VehicleLeavesCruiseSpeed, _trid_11, _OpCache_with_parameter_VehicleLeavesCruiseSpeed);
                        }

                    } else {
                        copiedState.VehicleLeavesCruiseSpeed();
                        copiedState.parent = state;
                        _ProjectionWrite_VehicleLeavesCruiseSpeed writeState = copiedState._update_for_VehicleLeavesCruiseSpeed();
                        _OpCache_with_parameter_VehicleLeavesCruiseSpeed = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_VehicleLeavesCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_VehicleLeavesCruiseSpeed, _trid_11, _OpCache_with_parameter_VehicleLeavesCruiseSpeed);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_VehicleReachesCruiseSpeed read__tr_VehicleReachesCruiseSpeed_state = state._projected_state_for__tr_VehicleReachesCruiseSpeed();
                Object _obj__trid_12 = GET.invoke(_OpCache_tr_VehicleReachesCruiseSpeed, read__tr_VehicleReachesCruiseSpeed_state);
                boolean _trid_12;
                if(_obj__trid_12 == null) {
                    _trid_12 = state._tr_VehicleReachesCruiseSpeed();
                    _OpCache_tr_VehicleReachesCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_VehicleReachesCruiseSpeed, read__tr_VehicleReachesCruiseSpeed_state, _trid_12);
                } else {
                    _trid_12 = (boolean) _obj__trid_12;
                }
                if(_trid_12) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_VehicleReachesCruiseSpeed readState = state._projected_state_for_VehicleReachesCruiseSpeed();
                    PersistentHashMap _OpCache_with_parameter_VehicleReachesCruiseSpeed = (PersistentHashMap) GET.invoke(_OpCache_VehicleReachesCruiseSpeed, _trid_12);
                    if(_OpCache_with_parameter_VehicleReachesCruiseSpeed != null) {
                        _ProjectionWrite_VehicleReachesCruiseSpeed writeState = (_ProjectionWrite_VehicleReachesCruiseSpeed) GET.invoke(_OpCache_with_parameter_VehicleReachesCruiseSpeed, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_VehicleReachesCruiseSpeed(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.VehicleReachesCruiseSpeed();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_VehicleReachesCruiseSpeed();
                            _OpCache_with_parameter_VehicleReachesCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_VehicleReachesCruiseSpeed, readState, writeState);
                            _OpCache_VehicleReachesCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_VehicleReachesCruiseSpeed, _trid_12, _OpCache_with_parameter_VehicleReachesCruiseSpeed);
                        }

                    } else {
                        copiedState.VehicleReachesCruiseSpeed();
                        copiedState.parent = state;
                        _ProjectionWrite_VehicleReachesCruiseSpeed writeState = copiedState._update_for_VehicleReachesCruiseSpeed();
                        _OpCache_with_parameter_VehicleReachesCruiseSpeed = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_VehicleReachesCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_VehicleReachesCruiseSpeed, _trid_12, _OpCache_with_parameter_VehicleReachesCruiseSpeed);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed read__tr_VehicleExceedsMaxCruiseSpeed_state = state._projected_state_for__tr_VehicleExceedsMaxCruiseSpeed();
                Object _obj__trid_13 = GET.invoke(_OpCache_tr_VehicleExceedsMaxCruiseSpeed, read__tr_VehicleExceedsMaxCruiseSpeed_state);
                boolean _trid_13;
                if(_obj__trid_13 == null) {
                    _trid_13 = state._tr_VehicleExceedsMaxCruiseSpeed();
                    _OpCache_tr_VehicleExceedsMaxCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_VehicleExceedsMaxCruiseSpeed, read__tr_VehicleExceedsMaxCruiseSpeed_state, _trid_13);
                } else {
                    _trid_13 = (boolean) _obj__trid_13;
                }
                if(_trid_13) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_VehicleExceedsMaxCruiseSpeed readState = state._projected_state_for_VehicleExceedsMaxCruiseSpeed();
                    PersistentHashMap _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed = (PersistentHashMap) GET.invoke(_OpCache_VehicleExceedsMaxCruiseSpeed, _trid_13);
                    if(_OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed != null) {
                        _ProjectionWrite_VehicleExceedsMaxCruiseSpeed writeState = (_ProjectionWrite_VehicleExceedsMaxCruiseSpeed) GET.invoke(_OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_VehicleExceedsMaxCruiseSpeed(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.VehicleExceedsMaxCruiseSpeed();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_VehicleExceedsMaxCruiseSpeed();
                            _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed, readState, writeState);
                            _OpCache_VehicleExceedsMaxCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_VehicleExceedsMaxCruiseSpeed, _trid_13, _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed);
                        }

                    } else {
                        copiedState.VehicleExceedsMaxCruiseSpeed();
                        copiedState.parent = state;
                        _ProjectionWrite_VehicleExceedsMaxCruiseSpeed writeState = copiedState._update_for_VehicleExceedsMaxCruiseSpeed();
                        _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_VehicleExceedsMaxCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_VehicleExceedsMaxCruiseSpeed, _trid_13, _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed read__tr_VehicleFallsBelowMaxCruiseSpeed_state = state._projected_state_for__tr_VehicleFallsBelowMaxCruiseSpeed();
                Object _obj__trid_14 = GET.invoke(_OpCache_tr_VehicleFallsBelowMaxCruiseSpeed, read__tr_VehicleFallsBelowMaxCruiseSpeed_state);
                boolean _trid_14;
                if(_obj__trid_14 == null) {
                    _trid_14 = state._tr_VehicleFallsBelowMaxCruiseSpeed();
                    _OpCache_tr_VehicleFallsBelowMaxCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_VehicleFallsBelowMaxCruiseSpeed, read__tr_VehicleFallsBelowMaxCruiseSpeed_state, _trid_14);
                } else {
                    _trid_14 = (boolean) _obj__trid_14;
                }
                if(_trid_14) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed readState = state._projected_state_for_VehicleFallsBelowMaxCruiseSpeed();
                    PersistentHashMap _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed = (PersistentHashMap) GET.invoke(_OpCache_VehicleFallsBelowMaxCruiseSpeed, _trid_14);
                    if(_OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed != null) {
                        _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed writeState = (_ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed) GET.invoke(_OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_VehicleFallsBelowMaxCruiseSpeed(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.VehicleFallsBelowMaxCruiseSpeed();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_VehicleFallsBelowMaxCruiseSpeed();
                            _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed, readState, writeState);
                            _OpCache_VehicleFallsBelowMaxCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_VehicleFallsBelowMaxCruiseSpeed, _trid_14, _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed);
                        }

                    } else {
                        copiedState.VehicleFallsBelowMaxCruiseSpeed();
                        copiedState.parent = state;
                        _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed writeState = copiedState._update_for_VehicleFallsBelowMaxCruiseSpeed();
                        _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_VehicleFallsBelowMaxCruiseSpeed = (PersistentHashMap) ASSOC.invoke(_OpCache_VehicleFallsBelowMaxCruiseSpeed, _trid_14, _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose read__tr_ObstacleDistanceBecomesVeryClose_state = state._projected_state_for__tr_ObstacleDistanceBecomesVeryClose();
                Object _obj__trid_15 = GET.invoke(_OpCache_tr_ObstacleDistanceBecomesVeryClose, read__tr_ObstacleDistanceBecomesVeryClose_state);
                boolean _trid_15;
                if(_obj__trid_15 == null) {
                    _trid_15 = state._tr_ObstacleDistanceBecomesVeryClose();
                    _OpCache_tr_ObstacleDistanceBecomesVeryClose = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleDistanceBecomesVeryClose, read__tr_ObstacleDistanceBecomesVeryClose_state, _trid_15);
                } else {
                    _trid_15 = (boolean) _obj__trid_15;
                }
                if(_trid_15) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleDistanceBecomesVeryClose readState = state._projected_state_for_ObstacleDistanceBecomesVeryClose();
                    PersistentHashMap _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose = (PersistentHashMap) GET.invoke(_OpCache_ObstacleDistanceBecomesVeryClose, _trid_15);
                    if(_OpCache_with_parameter_ObstacleDistanceBecomesVeryClose != null) {
                        _ProjectionWrite_ObstacleDistanceBecomesVeryClose writeState = (_ProjectionWrite_ObstacleDistanceBecomesVeryClose) GET.invoke(_OpCache_with_parameter_ObstacleDistanceBecomesVeryClose, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleDistanceBecomesVeryClose(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleDistanceBecomesVeryClose();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleDistanceBecomesVeryClose();
                            _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleDistanceBecomesVeryClose, readState, writeState);
                            _OpCache_ObstacleDistanceBecomesVeryClose = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleDistanceBecomesVeryClose, _trid_15, _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose);
                        }

                    } else {
                        copiedState.ObstacleDistanceBecomesVeryClose();
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleDistanceBecomesVeryClose writeState = copiedState._update_for_ObstacleDistanceBecomesVeryClose();
                        _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleDistanceBecomesVeryClose = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleDistanceBecomesVeryClose, _trid_15, _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleDistanceBecomesClose read__tr_ObstacleDistanceBecomesClose_state = state._projected_state_for__tr_ObstacleDistanceBecomesClose();
                Object _obj__trid_16 = GET.invoke(_OpCache_tr_ObstacleDistanceBecomesClose, read__tr_ObstacleDistanceBecomesClose_state);
                boolean _trid_16;
                if(_obj__trid_16 == null) {
                    _trid_16 = state._tr_ObstacleDistanceBecomesClose();
                    _OpCache_tr_ObstacleDistanceBecomesClose = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleDistanceBecomesClose, read__tr_ObstacleDistanceBecomesClose_state, _trid_16);
                } else {
                    _trid_16 = (boolean) _obj__trid_16;
                }
                if(_trid_16) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleDistanceBecomesClose readState = state._projected_state_for_ObstacleDistanceBecomesClose();
                    PersistentHashMap _OpCache_with_parameter_ObstacleDistanceBecomesClose = (PersistentHashMap) GET.invoke(_OpCache_ObstacleDistanceBecomesClose, _trid_16);
                    if(_OpCache_with_parameter_ObstacleDistanceBecomesClose != null) {
                        _ProjectionWrite_ObstacleDistanceBecomesClose writeState = (_ProjectionWrite_ObstacleDistanceBecomesClose) GET.invoke(_OpCache_with_parameter_ObstacleDistanceBecomesClose, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleDistanceBecomesClose(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleDistanceBecomesClose();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleDistanceBecomesClose();
                            _OpCache_with_parameter_ObstacleDistanceBecomesClose = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleDistanceBecomesClose, readState, writeState);
                            _OpCache_ObstacleDistanceBecomesClose = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleDistanceBecomesClose, _trid_16, _OpCache_with_parameter_ObstacleDistanceBecomesClose);
                        }

                    } else {
                        copiedState.ObstacleDistanceBecomesClose();
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleDistanceBecomesClose writeState = copiedState._update_for_ObstacleDistanceBecomesClose();
                        _OpCache_with_parameter_ObstacleDistanceBecomesClose = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleDistanceBecomesClose = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleDistanceBecomesClose, _trid_16, _OpCache_with_parameter_ObstacleDistanceBecomesClose);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleDistanceBecomesBig read__tr_ObstacleDistanceBecomesBig_state = state._projected_state_for__tr_ObstacleDistanceBecomesBig();
                Object _obj__trid_17 = GET.invoke(_OpCache_tr_ObstacleDistanceBecomesBig, read__tr_ObstacleDistanceBecomesBig_state);
                boolean _trid_17;
                if(_obj__trid_17 == null) {
                    _trid_17 = state._tr_ObstacleDistanceBecomesBig();
                    _OpCache_tr_ObstacleDistanceBecomesBig = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleDistanceBecomesBig, read__tr_ObstacleDistanceBecomesBig_state, _trid_17);
                } else {
                    _trid_17 = (boolean) _obj__trid_17;
                }
                if(_trid_17) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleDistanceBecomesBig readState = state._projected_state_for_ObstacleDistanceBecomesBig();
                    PersistentHashMap _OpCache_with_parameter_ObstacleDistanceBecomesBig = (PersistentHashMap) GET.invoke(_OpCache_ObstacleDistanceBecomesBig, _trid_17);
                    if(_OpCache_with_parameter_ObstacleDistanceBecomesBig != null) {
                        _ProjectionWrite_ObstacleDistanceBecomesBig writeState = (_ProjectionWrite_ObstacleDistanceBecomesBig) GET.invoke(_OpCache_with_parameter_ObstacleDistanceBecomesBig, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleDistanceBecomesBig(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleDistanceBecomesBig();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleDistanceBecomesBig();
                            _OpCache_with_parameter_ObstacleDistanceBecomesBig = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleDistanceBecomesBig, readState, writeState);
                            _OpCache_ObstacleDistanceBecomesBig = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleDistanceBecomesBig, _trid_17, _OpCache_with_parameter_ObstacleDistanceBecomesBig);
                        }

                    } else {
                        copiedState.ObstacleDistanceBecomesBig();
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleDistanceBecomesBig writeState = copiedState._update_for_ObstacleDistanceBecomesBig();
                        _OpCache_with_parameter_ObstacleDistanceBecomesBig = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleDistanceBecomesBig = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleDistanceBecomesBig, _trid_17, _OpCache_with_parameter_ObstacleDistanceBecomesBig);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleStartsTravelFaster read__tr_ObstacleStartsTravelFaster_state = state._projected_state_for__tr_ObstacleStartsTravelFaster();
                Object _obj__trid_18 = GET.invoke(_OpCache_tr_ObstacleStartsTravelFaster, read__tr_ObstacleStartsTravelFaster_state);
                boolean _trid_18;
                if(_obj__trid_18 == null) {
                    _trid_18 = state._tr_ObstacleStartsTravelFaster();
                    _OpCache_tr_ObstacleStartsTravelFaster = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleStartsTravelFaster, read__tr_ObstacleStartsTravelFaster_state, _trid_18);
                } else {
                    _trid_18 = (boolean) _obj__trid_18;
                }
                if(_trid_18) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleStartsTravelFaster readState = state._projected_state_for_ObstacleStartsTravelFaster();
                    PersistentHashMap _OpCache_with_parameter_ObstacleStartsTravelFaster = (PersistentHashMap) GET.invoke(_OpCache_ObstacleStartsTravelFaster, _trid_18);
                    if(_OpCache_with_parameter_ObstacleStartsTravelFaster != null) {
                        _ProjectionWrite_ObstacleStartsTravelFaster writeState = (_ProjectionWrite_ObstacleStartsTravelFaster) GET.invoke(_OpCache_with_parameter_ObstacleStartsTravelFaster, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleStartsTravelFaster(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleStartsTravelFaster();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleStartsTravelFaster();
                            _OpCache_with_parameter_ObstacleStartsTravelFaster = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleStartsTravelFaster, readState, writeState);
                            _OpCache_ObstacleStartsTravelFaster = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleStartsTravelFaster, _trid_18, _OpCache_with_parameter_ObstacleStartsTravelFaster);
                        }

                    } else {
                        copiedState.ObstacleStartsTravelFaster();
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleStartsTravelFaster writeState = copiedState._update_for_ObstacleStartsTravelFaster();
                        _OpCache_with_parameter_ObstacleStartsTravelFaster = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleStartsTravelFaster = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleStartsTravelFaster, _trid_18, _OpCache_with_parameter_ObstacleStartsTravelFaster);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleStopsTravelFaster read__tr_ObstacleStopsTravelFaster_state = state._projected_state_for__tr_ObstacleStopsTravelFaster();
                Object _obj__trid_19 = GET.invoke(_OpCache_tr_ObstacleStopsTravelFaster, read__tr_ObstacleStopsTravelFaster_state);
                boolean _trid_19;
                if(_obj__trid_19 == null) {
                    _trid_19 = state._tr_ObstacleStopsTravelFaster();
                    _OpCache_tr_ObstacleStopsTravelFaster = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleStopsTravelFaster, read__tr_ObstacleStopsTravelFaster_state, _trid_19);
                } else {
                    _trid_19 = (boolean) _obj__trid_19;
                }
                if(_trid_19) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleStopsTravelFaster readState = state._projected_state_for_ObstacleStopsTravelFaster();
                    PersistentHashMap _OpCache_with_parameter_ObstacleStopsTravelFaster = (PersistentHashMap) GET.invoke(_OpCache_ObstacleStopsTravelFaster, _trid_19);
                    if(_OpCache_with_parameter_ObstacleStopsTravelFaster != null) {
                        _ProjectionWrite_ObstacleStopsTravelFaster writeState = (_ProjectionWrite_ObstacleStopsTravelFaster) GET.invoke(_OpCache_with_parameter_ObstacleStopsTravelFaster, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleStopsTravelFaster(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleStopsTravelFaster();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleStopsTravelFaster();
                            _OpCache_with_parameter_ObstacleStopsTravelFaster = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleStopsTravelFaster, readState, writeState);
                            _OpCache_ObstacleStopsTravelFaster = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleStopsTravelFaster, _trid_19, _OpCache_with_parameter_ObstacleStopsTravelFaster);
                        }

                    } else {
                        copiedState.ObstacleStopsTravelFaster();
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleStopsTravelFaster writeState = copiedState._update_for_ObstacleStopsTravelFaster();
                        _OpCache_with_parameter_ObstacleStopsTravelFaster = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleStopsTravelFaster = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleStopsTravelFaster, _trid_19, _OpCache_with_parameter_ObstacleStopsTravelFaster);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleStartsTravelSlower read__tr_ObstacleStartsTravelSlower_state = state._projected_state_for__tr_ObstacleStartsTravelSlower();
                Object _obj__trid_20 = GET.invoke(_OpCache_tr_ObstacleStartsTravelSlower, read__tr_ObstacleStartsTravelSlower_state);
                boolean _trid_20;
                if(_obj__trid_20 == null) {
                    _trid_20 = state._tr_ObstacleStartsTravelSlower();
                    _OpCache_tr_ObstacleStartsTravelSlower = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleStartsTravelSlower, read__tr_ObstacleStartsTravelSlower_state, _trid_20);
                } else {
                    _trid_20 = (boolean) _obj__trid_20;
                }
                if(_trid_20) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleStartsTravelSlower readState = state._projected_state_for_ObstacleStartsTravelSlower();
                    PersistentHashMap _OpCache_with_parameter_ObstacleStartsTravelSlower = (PersistentHashMap) GET.invoke(_OpCache_ObstacleStartsTravelSlower, _trid_20);
                    if(_OpCache_with_parameter_ObstacleStartsTravelSlower != null) {
                        _ProjectionWrite_ObstacleStartsTravelSlower writeState = (_ProjectionWrite_ObstacleStartsTravelSlower) GET.invoke(_OpCache_with_parameter_ObstacleStartsTravelSlower, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleStartsTravelSlower(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleStartsTravelSlower();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleStartsTravelSlower();
                            _OpCache_with_parameter_ObstacleStartsTravelSlower = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleStartsTravelSlower, readState, writeState);
                            _OpCache_ObstacleStartsTravelSlower = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleStartsTravelSlower, _trid_20, _OpCache_with_parameter_ObstacleStartsTravelSlower);
                        }

                    } else {
                        copiedState.ObstacleStartsTravelSlower();
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleStartsTravelSlower writeState = copiedState._update_for_ObstacleStartsTravelSlower();
                        _OpCache_with_parameter_ObstacleStartsTravelSlower = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleStartsTravelSlower = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleStartsTravelSlower, _trid_20, _OpCache_with_parameter_ObstacleStartsTravelSlower);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleStopsTravelSlower read__tr_ObstacleStopsTravelSlower_state = state._projected_state_for__tr_ObstacleStopsTravelSlower();
                Object _obj__trid_21 = GET.invoke(_OpCache_tr_ObstacleStopsTravelSlower, read__tr_ObstacleStopsTravelSlower_state);
                boolean _trid_21;
                if(_obj__trid_21 == null) {
                    _trid_21 = state._tr_ObstacleStopsTravelSlower();
                    _OpCache_tr_ObstacleStopsTravelSlower = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleStopsTravelSlower, read__tr_ObstacleStopsTravelSlower_state, _trid_21);
                } else {
                    _trid_21 = (boolean) _obj__trid_21;
                }
                if(_trid_21) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleStopsTravelSlower readState = state._projected_state_for_ObstacleStopsTravelSlower();
                    PersistentHashMap _OpCache_with_parameter_ObstacleStopsTravelSlower = (PersistentHashMap) GET.invoke(_OpCache_ObstacleStopsTravelSlower, _trid_21);
                    if(_OpCache_with_parameter_ObstacleStopsTravelSlower != null) {
                        _ProjectionWrite_ObstacleStopsTravelSlower writeState = (_ProjectionWrite_ObstacleStopsTravelSlower) GET.invoke(_OpCache_with_parameter_ObstacleStopsTravelSlower, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleStopsTravelSlower(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleStopsTravelSlower();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleStopsTravelSlower();
                            _OpCache_with_parameter_ObstacleStopsTravelSlower = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleStopsTravelSlower, readState, writeState);
                            _OpCache_ObstacleStopsTravelSlower = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleStopsTravelSlower, _trid_21, _OpCache_with_parameter_ObstacleStopsTravelSlower);
                        }

                    } else {
                        copiedState.ObstacleStopsTravelSlower();
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleStopsTravelSlower writeState = copiedState._update_for_ObstacleStopsTravelSlower();
                        _OpCache_with_parameter_ObstacleStopsTravelSlower = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleStopsTravelSlower = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleStopsTravelSlower, _trid_21, _OpCache_with_parameter_ObstacleStopsTravelSlower);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive read__tr_ObstacleAppearsWhenCruiseActive_state = state._projected_state_for__tr_ObstacleAppearsWhenCruiseActive();
                BSet<BTuple<RSset, ODset>> _trid_22 = (BSet<BTuple<RSset, ODset>>) GET.invoke(_OpCache_tr_ObstacleAppearsWhenCruiseActive, read__tr_ObstacleAppearsWhenCruiseActive_state);
                if(_trid_22 == null) {
                    _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive();
                    _OpCache_tr_ObstacleAppearsWhenCruiseActive = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleAppearsWhenCruiseActive, read__tr_ObstacleAppearsWhenCruiseActive_state, _trid_22);
                }
                for(BTuple<RSset, ODset> param : _trid_22) {
                    ODset _tmp_1 = param.projection2();
                    RSset _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleAppearsWhenCruiseActive readState = state._projected_state_for_ObstacleAppearsWhenCruiseActive();
                    PersistentHashMap _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive = (PersistentHashMap) GET.invoke(_OpCache_ObstacleAppearsWhenCruiseActive, param);
                    if(_OpCache_with_parameter_ObstacleAppearsWhenCruiseActive != null) {
                        _ProjectionWrite_ObstacleAppearsWhenCruiseActive writeState = (_ProjectionWrite_ObstacleAppearsWhenCruiseActive) GET.invoke(_OpCache_with_parameter_ObstacleAppearsWhenCruiseActive, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleAppearsWhenCruiseActive(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleAppearsWhenCruiseActive();
                            _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleAppearsWhenCruiseActive, readState, writeState);
                            _OpCache_ObstacleAppearsWhenCruiseActive = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleAppearsWhenCruiseActive, param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive);
                        }

                    } else {
                        copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleAppearsWhenCruiseActive writeState = copiedState._update_for_ObstacleAppearsWhenCruiseActive();
                        _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleAppearsWhenCruiseActive = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleAppearsWhenCruiseActive, param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive read__tr_ObstacleAppearsWhenCruiseInactive_state = state._projected_state_for__tr_ObstacleAppearsWhenCruiseInactive();
                BSet<RSset> _trid_23 = (BSet<RSset>) GET.invoke(_OpCache_tr_ObstacleAppearsWhenCruiseInactive, read__tr_ObstacleAppearsWhenCruiseInactive_state);
                if(_trid_23 == null) {
                    _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive();
                    _OpCache_tr_ObstacleAppearsWhenCruiseInactive = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleAppearsWhenCruiseInactive, read__tr_ObstacleAppearsWhenCruiseInactive_state, _trid_23);
                }
                for(RSset param : _trid_23) {
                    RSset _tmp_1 = param;

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleAppearsWhenCruiseInactive readState = state._projected_state_for_ObstacleAppearsWhenCruiseInactive();
                    PersistentHashMap _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive = (PersistentHashMap) GET.invoke(_OpCache_ObstacleAppearsWhenCruiseInactive, param);
                    if(_OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive != null) {
                        _ProjectionWrite_ObstacleAppearsWhenCruiseInactive writeState = (_ProjectionWrite_ObstacleAppearsWhenCruiseInactive) GET.invoke(_OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleAppearsWhenCruiseInactive(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleAppearsWhenCruiseInactive();
                            _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive, readState, writeState);
                            _OpCache_ObstacleAppearsWhenCruiseInactive = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleAppearsWhenCruiseInactive, param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive);
                        }

                    } else {
                        copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleAppearsWhenCruiseInactive writeState = copiedState._update_for_ObstacleAppearsWhenCruiseInactive();
                        _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleAppearsWhenCruiseInactive = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleAppearsWhenCruiseInactive, param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleDisappears read__tr_ObstacleDisappears_state = state._projected_state_for__tr_ObstacleDisappears();
                Object _obj__trid_24 = GET.invoke(_OpCache_tr_ObstacleDisappears, read__tr_ObstacleDisappears_state);
                boolean _trid_24;
                if(_obj__trid_24 == null) {
                    _trid_24 = state._tr_ObstacleDisappears();
                    _OpCache_tr_ObstacleDisappears = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleDisappears, read__tr_ObstacleDisappears_state, _trid_24);
                } else {
                    _trid_24 = (boolean) _obj__trid_24;
                }
                if(_trid_24) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleDisappears readState = state._projected_state_for_ObstacleDisappears();
                    PersistentHashMap _OpCache_with_parameter_ObstacleDisappears = (PersistentHashMap) GET.invoke(_OpCache_ObstacleDisappears, _trid_24);
                    if(_OpCache_with_parameter_ObstacleDisappears != null) {
                        _ProjectionWrite_ObstacleDisappears writeState = (_ProjectionWrite_ObstacleDisappears) GET.invoke(_OpCache_with_parameter_ObstacleDisappears, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleDisappears(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleDisappears();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleDisappears();
                            _OpCache_with_parameter_ObstacleDisappears = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleDisappears, readState, writeState);
                            _OpCache_ObstacleDisappears = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleDisappears, _trid_24, _OpCache_with_parameter_ObstacleDisappears);
                        }

                    } else {
                        copiedState.ObstacleDisappears();
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleDisappears writeState = copiedState._update_for_ObstacleDisappears();
                        _OpCache_with_parameter_ObstacleDisappears = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleDisappears = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleDisappears, _trid_24, _OpCache_with_parameter_ObstacleDisappears);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_VehicleManageObstacle read__tr_VehicleManageObstacle_state = state._projected_state_for__tr_VehicleManageObstacle();
                BSet<BTuple<BBoolean, BBoolean>> _trid_25 = (BSet<BTuple<BBoolean, BBoolean>>) GET.invoke(_OpCache_tr_VehicleManageObstacle, read__tr_VehicleManageObstacle_state);
                if(_trid_25 == null) {
                    _trid_25 = state._tr_VehicleManageObstacle();
                    _OpCache_tr_VehicleManageObstacle = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_VehicleManageObstacle, read__tr_VehicleManageObstacle_state, _trid_25);
                }
                for(BTuple<BBoolean, BBoolean> param : _trid_25) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_VehicleManageObstacle readState = state._projected_state_for_VehicleManageObstacle();
                    PersistentHashMap _OpCache_with_parameter_VehicleManageObstacle = (PersistentHashMap) GET.invoke(_OpCache_VehicleManageObstacle, param);
                    if(_OpCache_with_parameter_VehicleManageObstacle != null) {
                        _ProjectionWrite_VehicleManageObstacle writeState = (_ProjectionWrite_VehicleManageObstacle) GET.invoke(_OpCache_with_parameter_VehicleManageObstacle, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_VehicleManageObstacle(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_VehicleManageObstacle();
                            _OpCache_with_parameter_VehicleManageObstacle = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_VehicleManageObstacle, readState, writeState);
                            _OpCache_VehicleManageObstacle = (PersistentHashMap) ASSOC.invoke(_OpCache_VehicleManageObstacle, param, _OpCache_with_parameter_VehicleManageObstacle);
                        }

                    } else {
                        copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_VehicleManageObstacle writeState = copiedState._update_for_VehicleManageObstacle();
                        _OpCache_with_parameter_VehicleManageObstacle = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_VehicleManageObstacle = (PersistentHashMap) ASSOC.invoke(_OpCache_VehicleManageObstacle, param, _OpCache_with_parameter_VehicleManageObstacle);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_ObstacleBecomesOld read__tr_ObstacleBecomesOld_state = state._projected_state_for__tr_ObstacleBecomesOld();
                Object _obj__trid_26 = GET.invoke(_OpCache_tr_ObstacleBecomesOld, read__tr_ObstacleBecomesOld_state);
                boolean _trid_26;
                if(_obj__trid_26 == null) {
                    _trid_26 = state._tr_ObstacleBecomesOld();
                    _OpCache_tr_ObstacleBecomesOld = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_ObstacleBecomesOld, read__tr_ObstacleBecomesOld_state, _trid_26);
                } else {
                    _trid_26 = (boolean) _obj__trid_26;
                }
                if(_trid_26) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    _ProjectionRead_ObstacleBecomesOld readState = state._projected_state_for_ObstacleBecomesOld();
                    PersistentHashMap _OpCache_with_parameter_ObstacleBecomesOld = (PersistentHashMap) GET.invoke(_OpCache_ObstacleBecomesOld, _trid_26);
                    if(_OpCache_with_parameter_ObstacleBecomesOld != null) {
                        _ProjectionWrite_ObstacleBecomesOld writeState = (_ProjectionWrite_ObstacleBecomesOld) GET.invoke(_OpCache_with_parameter_ObstacleBecomesOld, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_ObstacleBecomesOld(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.ObstacleBecomesOld();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_ObstacleBecomesOld();
                            _OpCache_with_parameter_ObstacleBecomesOld = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_ObstacleBecomesOld, readState, writeState);
                            _OpCache_ObstacleBecomesOld = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleBecomesOld, _trid_26, _OpCache_with_parameter_ObstacleBecomesOld);
                        }

                    } else {
                        copiedState.ObstacleBecomesOld();
                        copiedState.parent = state;
                        _ProjectionWrite_ObstacleBecomesOld writeState = copiedState._update_for_ObstacleBecomesOld();
                        _OpCache_with_parameter_ObstacleBecomesOld = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_ObstacleBecomesOld = (PersistentHashMap) ASSOC.invoke(_OpCache_ObstacleBecomesOld, _trid_26, _OpCache_with_parameter_ObstacleBecomesOld);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                if(state._tr_CruiseBecomesNotAllowed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseBecomesNotAllowed();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_CruiseBecomesAllowed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseBecomesAllowed();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_3 = state._tr_SetCruiseSpeed();
                for(BTuple<BBoolean, BBoolean> param : _trid_3) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_4 = state._tr_CCInitialisationFinished();
                for(BTuple<BBoolean, BBoolean> param : _trid_4) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_CCInitialisationDelayFinished()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CCInitialisationDelayFinished();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_6 = state._tr_CruiseSpeedChangeFinished();
                for(BTuple<BBoolean, BBoolean> param : _trid_6) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_CruiseSpeedChangeDelayFinished()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseSpeedChangeDelayFinished();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_CruiseOff()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseOff();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ExternalForcesBecomesExtreme()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ExternalForcesBecomesExtreme();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ExternalForcesBecomesNormal()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ExternalForcesBecomesNormal();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_VehicleLeavesCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleLeavesCruiseSpeed();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_VehicleReachesCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleReachesCruiseSpeed();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_VehicleExceedsMaxCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleExceedsMaxCruiseSpeed();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_VehicleFallsBelowMaxCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleFallsBelowMaxCruiseSpeed();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleDistanceBecomesVeryClose()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesVeryClose();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleDistanceBecomesClose()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesClose();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleDistanceBecomesBig()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesBig();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleStartsTravelFaster()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStartsTravelFaster();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleStopsTravelFaster()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStopsTravelFaster();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleStartsTravelSlower()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStartsTravelSlower();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleStopsTravelSlower()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStopsTravelSlower();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<RSset, ODset>> _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive();
                for(BTuple<RSset, ODset> param : _trid_22) {
                    ODset _tmp_1 = param.projection2();
                    RSset _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<RSset> _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive();
                for(RSset param : _trid_23) {
                    RSset _tmp_1 = param;

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleDisappears()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDisappears();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<BBoolean, BBoolean>> _trid_25 = state._tr_VehicleManageObstacle();
                for(BTuple<BBoolean, BBoolean> param : _trid_25) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_ObstacleBecomesOld()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleBecomesOld();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final Cruise_finite1_deterministic_MC state) {
            boolean _check_inv_1;
            if(isCaching) {
                _ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
                Object _obj__check_inv_1 = GET.invoke(_InvCache__check_inv_1, read__check_inv_1_state);
                if(_obj__check_inv_1 == null) {
                    _check_inv_1 = state._check_inv_1();
                    _InvCache__check_inv_1 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_1, read__check_inv_1_state, _check_inv_1);
                } else {
                    _check_inv_1 = (boolean) _obj__check_inv_1;
                }
            } else {
                _check_inv_1 = state._check_inv_1();
            }
            if(!_check_inv_1) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                return true;
            }
            boolean _check_inv_2;
            if(isCaching) {
                _ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
                Object _obj__check_inv_2 = GET.invoke(_InvCache__check_inv_2, read__check_inv_2_state);
                if(_obj__check_inv_2 == null) {
                    _check_inv_2 = state._check_inv_2();
                    _InvCache__check_inv_2 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_2, read__check_inv_2_state, _check_inv_2);
                } else {
                    _check_inv_2 = (boolean) _obj__check_inv_2;
                }
            } else {
                _check_inv_2 = state._check_inv_2();
            }
            if(!_check_inv_2) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
                return true;
            }
            boolean _check_inv_3;
            if(isCaching) {
                _ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
                Object _obj__check_inv_3 = GET.invoke(_InvCache__check_inv_3, read__check_inv_3_state);
                if(_obj__check_inv_3 == null) {
                    _check_inv_3 = state._check_inv_3();
                    _InvCache__check_inv_3 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_3, read__check_inv_3_state, _check_inv_3);
                } else {
                    _check_inv_3 = (boolean) _obj__check_inv_3;
                }
            } else {
                _check_inv_3 = state._check_inv_3();
            }
            if(!_check_inv_3) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
                return true;
            }
            boolean _check_inv_4;
            if(isCaching) {
                _ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
                Object _obj__check_inv_4 = GET.invoke(_InvCache__check_inv_4, read__check_inv_4_state);
                if(_obj__check_inv_4 == null) {
                    _check_inv_4 = state._check_inv_4();
                    _InvCache__check_inv_4 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_4, read__check_inv_4_state, _check_inv_4);
                } else {
                    _check_inv_4 = (boolean) _obj__check_inv_4;
                }
            } else {
                _check_inv_4 = state._check_inv_4();
            }
            if(!_check_inv_4) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
                return true;
            }
            boolean _check_inv_5;
            if(isCaching) {
                _ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
                Object _obj__check_inv_5 = GET.invoke(_InvCache__check_inv_5, read__check_inv_5_state);
                if(_obj__check_inv_5 == null) {
                    _check_inv_5 = state._check_inv_5();
                    _InvCache__check_inv_5 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_5, read__check_inv_5_state, _check_inv_5);
                } else {
                    _check_inv_5 = (boolean) _obj__check_inv_5;
                }
            } else {
                _check_inv_5 = state._check_inv_5();
            }
            if(!_check_inv_5) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
                return true;
            }
            boolean _check_inv_6;
            if(isCaching) {
                _ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
                Object _obj__check_inv_6 = GET.invoke(_InvCache__check_inv_6, read__check_inv_6_state);
                if(_obj__check_inv_6 == null) {
                    _check_inv_6 = state._check_inv_6();
                    _InvCache__check_inv_6 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_6, read__check_inv_6_state, _check_inv_6);
                } else {
                    _check_inv_6 = (boolean) _obj__check_inv_6;
                }
            } else {
                _check_inv_6 = state._check_inv_6();
            }
            if(!_check_inv_6) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
                return true;
            }
            boolean _check_inv_7;
            if(isCaching) {
                _ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
                Object _obj__check_inv_7 = GET.invoke(_InvCache__check_inv_7, read__check_inv_7_state);
                if(_obj__check_inv_7 == null) {
                    _check_inv_7 = state._check_inv_7();
                    _InvCache__check_inv_7 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_7, read__check_inv_7_state, _check_inv_7);
                } else {
                    _check_inv_7 = (boolean) _obj__check_inv_7;
                }
            } else {
                _check_inv_7 = state._check_inv_7();
            }
            if(!_check_inv_7) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_7");
                return true;
            }
            boolean _check_inv_8;
            if(isCaching) {
                _ProjectionRead__check_inv_8 read__check_inv_8_state = state._projected_state_for__check_inv_8();
                Object _obj__check_inv_8 = GET.invoke(_InvCache__check_inv_8, read__check_inv_8_state);
                if(_obj__check_inv_8 == null) {
                    _check_inv_8 = state._check_inv_8();
                    _InvCache__check_inv_8 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_8, read__check_inv_8_state, _check_inv_8);
                } else {
                    _check_inv_8 = (boolean) _obj__check_inv_8;
                }
            } else {
                _check_inv_8 = state._check_inv_8();
            }
            if(!_check_inv_8) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_8");
                return true;
            }
            boolean _check_inv_9;
            if(isCaching) {
                _ProjectionRead__check_inv_9 read__check_inv_9_state = state._projected_state_for__check_inv_9();
                Object _obj__check_inv_9 = GET.invoke(_InvCache__check_inv_9, read__check_inv_9_state);
                if(_obj__check_inv_9 == null) {
                    _check_inv_9 = state._check_inv_9();
                    _InvCache__check_inv_9 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_9, read__check_inv_9_state, _check_inv_9);
                } else {
                    _check_inv_9 = (boolean) _obj__check_inv_9;
                }
            } else {
                _check_inv_9 = state._check_inv_9();
            }
            if(!_check_inv_9) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_9");
                return true;
            }
            boolean _check_inv_10;
            if(isCaching) {
                _ProjectionRead__check_inv_10 read__check_inv_10_state = state._projected_state_for__check_inv_10();
                Object _obj__check_inv_10 = GET.invoke(_InvCache__check_inv_10, read__check_inv_10_state);
                if(_obj__check_inv_10 == null) {
                    _check_inv_10 = state._check_inv_10();
                    _InvCache__check_inv_10 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_10, read__check_inv_10_state, _check_inv_10);
                } else {
                    _check_inv_10 = (boolean) _obj__check_inv_10;
                }
            } else {
                _check_inv_10 = state._check_inv_10();
            }
            if(!_check_inv_10) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_10");
                return true;
            }
            boolean _check_inv_11;
            if(isCaching) {
                _ProjectionRead__check_inv_11 read__check_inv_11_state = state._projected_state_for__check_inv_11();
                Object _obj__check_inv_11 = GET.invoke(_InvCache__check_inv_11, read__check_inv_11_state);
                if(_obj__check_inv_11 == null) {
                    _check_inv_11 = state._check_inv_11();
                    _InvCache__check_inv_11 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_11, read__check_inv_11_state, _check_inv_11);
                } else {
                    _check_inv_11 = (boolean) _obj__check_inv_11;
                }
            } else {
                _check_inv_11 = state._check_inv_11();
            }
            if(!_check_inv_11) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_11");
                return true;
            }
            boolean _check_inv_12;
            if(isCaching) {
                _ProjectionRead__check_inv_12 read__check_inv_12_state = state._projected_state_for__check_inv_12();
                Object _obj__check_inv_12 = GET.invoke(_InvCache__check_inv_12, read__check_inv_12_state);
                if(_obj__check_inv_12 == null) {
                    _check_inv_12 = state._check_inv_12();
                    _InvCache__check_inv_12 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_12, read__check_inv_12_state, _check_inv_12);
                } else {
                    _check_inv_12 = (boolean) _obj__check_inv_12;
                }
            } else {
                _check_inv_12 = state._check_inv_12();
            }
            if(!_check_inv_12) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_12");
                return true;
            }
            boolean _check_inv_13;
            if(isCaching) {
                _ProjectionRead__check_inv_13 read__check_inv_13_state = state._projected_state_for__check_inv_13();
                Object _obj__check_inv_13 = GET.invoke(_InvCache__check_inv_13, read__check_inv_13_state);
                if(_obj__check_inv_13 == null) {
                    _check_inv_13 = state._check_inv_13();
                    _InvCache__check_inv_13 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_13, read__check_inv_13_state, _check_inv_13);
                } else {
                    _check_inv_13 = (boolean) _obj__check_inv_13;
                }
            } else {
                _check_inv_13 = state._check_inv_13();
            }
            if(!_check_inv_13) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_13");
                return true;
            }
            boolean _check_inv_14;
            if(isCaching) {
                _ProjectionRead__check_inv_14 read__check_inv_14_state = state._projected_state_for__check_inv_14();
                Object _obj__check_inv_14 = GET.invoke(_InvCache__check_inv_14, read__check_inv_14_state);
                if(_obj__check_inv_14 == null) {
                    _check_inv_14 = state._check_inv_14();
                    _InvCache__check_inv_14 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_14, read__check_inv_14_state, _check_inv_14);
                } else {
                    _check_inv_14 = (boolean) _obj__check_inv_14;
                }
            } else {
                _check_inv_14 = state._check_inv_14();
            }
            if(!_check_inv_14) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_14");
                return true;
            }
            boolean _check_inv_15;
            if(isCaching) {
                _ProjectionRead__check_inv_15 read__check_inv_15_state = state._projected_state_for__check_inv_15();
                Object _obj__check_inv_15 = GET.invoke(_InvCache__check_inv_15, read__check_inv_15_state);
                if(_obj__check_inv_15 == null) {
                    _check_inv_15 = state._check_inv_15();
                    _InvCache__check_inv_15 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_15, read__check_inv_15_state, _check_inv_15);
                } else {
                    _check_inv_15 = (boolean) _obj__check_inv_15;
                }
            } else {
                _check_inv_15 = state._check_inv_15();
            }
            if(!_check_inv_15) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_15");
                return true;
            }
            boolean _check_inv_16;
            if(isCaching) {
                _ProjectionRead__check_inv_16 read__check_inv_16_state = state._projected_state_for__check_inv_16();
                Object _obj__check_inv_16 = GET.invoke(_InvCache__check_inv_16, read__check_inv_16_state);
                if(_obj__check_inv_16 == null) {
                    _check_inv_16 = state._check_inv_16();
                    _InvCache__check_inv_16 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_16, read__check_inv_16_state, _check_inv_16);
                } else {
                    _check_inv_16 = (boolean) _obj__check_inv_16;
                }
            } else {
                _check_inv_16 = state._check_inv_16();
            }
            if(!_check_inv_16) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_16");
                return true;
            }
            boolean _check_inv_17;
            if(isCaching) {
                _ProjectionRead__check_inv_17 read__check_inv_17_state = state._projected_state_for__check_inv_17();
                Object _obj__check_inv_17 = GET.invoke(_InvCache__check_inv_17, read__check_inv_17_state);
                if(_obj__check_inv_17 == null) {
                    _check_inv_17 = state._check_inv_17();
                    _InvCache__check_inv_17 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_17, read__check_inv_17_state, _check_inv_17);
                } else {
                    _check_inv_17 = (boolean) _obj__check_inv_17;
                }
            } else {
                _check_inv_17 = state._check_inv_17();
            }
            if(!_check_inv_17) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_17");
                return true;
            }
            boolean _check_inv_18;
            if(isCaching) {
                _ProjectionRead__check_inv_18 read__check_inv_18_state = state._projected_state_for__check_inv_18();
                Object _obj__check_inv_18 = GET.invoke(_InvCache__check_inv_18, read__check_inv_18_state);
                if(_obj__check_inv_18 == null) {
                    _check_inv_18 = state._check_inv_18();
                    _InvCache__check_inv_18 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_18, read__check_inv_18_state, _check_inv_18);
                } else {
                    _check_inv_18 = (boolean) _obj__check_inv_18;
                }
            } else {
                _check_inv_18 = state._check_inv_18();
            }
            if(!_check_inv_18) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_18");
                return true;
            }
            boolean _check_inv_19;
            if(isCaching) {
                _ProjectionRead__check_inv_19 read__check_inv_19_state = state._projected_state_for__check_inv_19();
                Object _obj__check_inv_19 = GET.invoke(_InvCache__check_inv_19, read__check_inv_19_state);
                if(_obj__check_inv_19 == null) {
                    _check_inv_19 = state._check_inv_19();
                    _InvCache__check_inv_19 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_19, read__check_inv_19_state, _check_inv_19);
                } else {
                    _check_inv_19 = (boolean) _obj__check_inv_19;
                }
            } else {
                _check_inv_19 = state._check_inv_19();
            }
            if(!_check_inv_19) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_19");
                return true;
            }
            boolean _check_inv_20;
            if(isCaching) {
                _ProjectionRead__check_inv_20 read__check_inv_20_state = state._projected_state_for__check_inv_20();
                Object _obj__check_inv_20 = GET.invoke(_InvCache__check_inv_20, read__check_inv_20_state);
                if(_obj__check_inv_20 == null) {
                    _check_inv_20 = state._check_inv_20();
                    _InvCache__check_inv_20 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_20, read__check_inv_20_state, _check_inv_20);
                } else {
                    _check_inv_20 = (boolean) _obj__check_inv_20;
                }
            } else {
                _check_inv_20 = state._check_inv_20();
            }
            if(!_check_inv_20) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_20");
                return true;
            }
            boolean _check_inv_21;
            if(isCaching) {
                _ProjectionRead__check_inv_21 read__check_inv_21_state = state._projected_state_for__check_inv_21();
                Object _obj__check_inv_21 = GET.invoke(_InvCache__check_inv_21, read__check_inv_21_state);
                if(_obj__check_inv_21 == null) {
                    _check_inv_21 = state._check_inv_21();
                    _InvCache__check_inv_21 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_21, read__check_inv_21_state, _check_inv_21);
                } else {
                    _check_inv_21 = (boolean) _obj__check_inv_21;
                }
            } else {
                _check_inv_21 = state._check_inv_21();
            }
            if(!_check_inv_21) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_21");
                return true;
            }
            boolean _check_inv_22;
            if(isCaching) {
                _ProjectionRead__check_inv_22 read__check_inv_22_state = state._projected_state_for__check_inv_22();
                Object _obj__check_inv_22 = GET.invoke(_InvCache__check_inv_22, read__check_inv_22_state);
                if(_obj__check_inv_22 == null) {
                    _check_inv_22 = state._check_inv_22();
                    _InvCache__check_inv_22 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_22, read__check_inv_22_state, _check_inv_22);
                } else {
                    _check_inv_22 = (boolean) _obj__check_inv_22;
                }
            } else {
                _check_inv_22 = state._check_inv_22();
            }
            if(!_check_inv_22) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_22");
                return true;
            }
            boolean _check_inv_23;
            if(isCaching) {
                _ProjectionRead__check_inv_23 read__check_inv_23_state = state._projected_state_for__check_inv_23();
                Object _obj__check_inv_23 = GET.invoke(_InvCache__check_inv_23, read__check_inv_23_state);
                if(_obj__check_inv_23 == null) {
                    _check_inv_23 = state._check_inv_23();
                    _InvCache__check_inv_23 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_23, read__check_inv_23_state, _check_inv_23);
                } else {
                    _check_inv_23 = (boolean) _obj__check_inv_23;
                }
            } else {
                _check_inv_23 = state._check_inv_23();
            }
            if(!_check_inv_23) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_23");
                return true;
            }
            boolean _check_inv_24;
            if(isCaching) {
                _ProjectionRead__check_inv_24 read__check_inv_24_state = state._projected_state_for__check_inv_24();
                Object _obj__check_inv_24 = GET.invoke(_InvCache__check_inv_24, read__check_inv_24_state);
                if(_obj__check_inv_24 == null) {
                    _check_inv_24 = state._check_inv_24();
                    _InvCache__check_inv_24 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_24, read__check_inv_24_state, _check_inv_24);
                } else {
                    _check_inv_24 = (boolean) _obj__check_inv_24;
                }
            } else {
                _check_inv_24 = state._check_inv_24();
            }
            if(!_check_inv_24) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_24");
                return true;
            }
            boolean _check_inv_25;
            if(isCaching) {
                _ProjectionRead__check_inv_25 read__check_inv_25_state = state._projected_state_for__check_inv_25();
                Object _obj__check_inv_25 = GET.invoke(_InvCache__check_inv_25, read__check_inv_25_state);
                if(_obj__check_inv_25 == null) {
                    _check_inv_25 = state._check_inv_25();
                    _InvCache__check_inv_25 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_25, read__check_inv_25_state, _check_inv_25);
                } else {
                    _check_inv_25 = (boolean) _obj__check_inv_25;
                }
            } else {
                _check_inv_25 = state._check_inv_25();
            }
            if(!_check_inv_25) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_25");
                return true;
            }
            boolean _check_inv_26;
            if(isCaching) {
                _ProjectionRead__check_inv_26 read__check_inv_26_state = state._projected_state_for__check_inv_26();
                Object _obj__check_inv_26 = GET.invoke(_InvCache__check_inv_26, read__check_inv_26_state);
                if(_obj__check_inv_26 == null) {
                    _check_inv_26 = state._check_inv_26();
                    _InvCache__check_inv_26 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_26, read__check_inv_26_state, _check_inv_26);
                } else {
                    _check_inv_26 = (boolean) _obj__check_inv_26;
                }
            } else {
                _check_inv_26 = state._check_inv_26();
            }
            if(!_check_inv_26) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_26");
                return true;
            }
            boolean _check_inv_27;
            if(isCaching) {
                _ProjectionRead__check_inv_27 read__check_inv_27_state = state._projected_state_for__check_inv_27();
                Object _obj__check_inv_27 = GET.invoke(_InvCache__check_inv_27, read__check_inv_27_state);
                if(_obj__check_inv_27 == null) {
                    _check_inv_27 = state._check_inv_27();
                    _InvCache__check_inv_27 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_27, read__check_inv_27_state, _check_inv_27);
                } else {
                    _check_inv_27 = (boolean) _obj__check_inv_27;
                }
            } else {
                _check_inv_27 = state._check_inv_27();
            }
            if(!_check_inv_27) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_27");
                return true;
            }
            boolean _check_inv_28;
            if(isCaching) {
                _ProjectionRead__check_inv_28 read__check_inv_28_state = state._projected_state_for__check_inv_28();
                Object _obj__check_inv_28 = GET.invoke(_InvCache__check_inv_28, read__check_inv_28_state);
                if(_obj__check_inv_28 == null) {
                    _check_inv_28 = state._check_inv_28();
                    _InvCache__check_inv_28 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_28, read__check_inv_28_state, _check_inv_28);
                } else {
                    _check_inv_28 = (boolean) _obj__check_inv_28;
                }
            } else {
                _check_inv_28 = state._check_inv_28();
            }
            if(!_check_inv_28) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_28");
                return true;
            }
            boolean _check_inv_29;
            if(isCaching) {
                _ProjectionRead__check_inv_29 read__check_inv_29_state = state._projected_state_for__check_inv_29();
                Object _obj__check_inv_29 = GET.invoke(_InvCache__check_inv_29, read__check_inv_29_state);
                if(_obj__check_inv_29 == null) {
                    _check_inv_29 = state._check_inv_29();
                    _InvCache__check_inv_29 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_29, read__check_inv_29_state, _check_inv_29);
                } else {
                    _check_inv_29 = (boolean) _obj__check_inv_29;
                }
            } else {
                _check_inv_29 = state._check_inv_29();
            }
            if(!_check_inv_29) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_29");
                return true;
            }
            boolean _check_inv_30;
            if(isCaching) {
                _ProjectionRead__check_inv_30 read__check_inv_30_state = state._projected_state_for__check_inv_30();
                Object _obj__check_inv_30 = GET.invoke(_InvCache__check_inv_30, read__check_inv_30_state);
                if(_obj__check_inv_30 == null) {
                    _check_inv_30 = state._check_inv_30();
                    _InvCache__check_inv_30 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_30, read__check_inv_30_state, _check_inv_30);
                } else {
                    _check_inv_30 = (boolean) _obj__check_inv_30;
                }
            } else {
                _check_inv_30 = state._check_inv_30();
            }
            if(!_check_inv_30) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_30");
                return true;
            }
            boolean _check_inv_31;
            if(isCaching) {
                _ProjectionRead__check_inv_31 read__check_inv_31_state = state._projected_state_for__check_inv_31();
                Object _obj__check_inv_31 = GET.invoke(_InvCache__check_inv_31, read__check_inv_31_state);
                if(_obj__check_inv_31 == null) {
                    _check_inv_31 = state._check_inv_31();
                    _InvCache__check_inv_31 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_31, read__check_inv_31_state, _check_inv_31);
                } else {
                    _check_inv_31 = (boolean) _obj__check_inv_31;
                }
            } else {
                _check_inv_31 = state._check_inv_31();
            }
            if(!_check_inv_31) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_31");
                return true;
            }
            boolean _check_inv_32;
            if(isCaching) {
                _ProjectionRead__check_inv_32 read__check_inv_32_state = state._projected_state_for__check_inv_32();
                Object _obj__check_inv_32 = GET.invoke(_InvCache__check_inv_32, read__check_inv_32_state);
                if(_obj__check_inv_32 == null) {
                    _check_inv_32 = state._check_inv_32();
                    _InvCache__check_inv_32 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_32, read__check_inv_32_state, _check_inv_32);
                } else {
                    _check_inv_32 = (boolean) _obj__check_inv_32;
                }
            } else {
                _check_inv_32 = state._check_inv_32();
            }
            if(!_check_inv_32) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_32");
                return true;
            }
            boolean _check_inv_33;
            if(isCaching) {
                _ProjectionRead__check_inv_33 read__check_inv_33_state = state._projected_state_for__check_inv_33();
                Object _obj__check_inv_33 = GET.invoke(_InvCache__check_inv_33, read__check_inv_33_state);
                if(_obj__check_inv_33 == null) {
                    _check_inv_33 = state._check_inv_33();
                    _InvCache__check_inv_33 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_33, read__check_inv_33_state, _check_inv_33);
                } else {
                    _check_inv_33 = (boolean) _obj__check_inv_33;
                }
            } else {
                _check_inv_33 = state._check_inv_33();
            }
            if(!_check_inv_33) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_33");
                return true;
            }
            boolean _check_inv_34;
            if(isCaching) {
                _ProjectionRead__check_inv_34 read__check_inv_34_state = state._projected_state_for__check_inv_34();
                Object _obj__check_inv_34 = GET.invoke(_InvCache__check_inv_34, read__check_inv_34_state);
                if(_obj__check_inv_34 == null) {
                    _check_inv_34 = state._check_inv_34();
                    _InvCache__check_inv_34 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_34, read__check_inv_34_state, _check_inv_34);
                } else {
                    _check_inv_34 = (boolean) _obj__check_inv_34;
                }
            } else {
                _check_inv_34 = state._check_inv_34();
            }
            if(!_check_inv_34) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_34");
                return true;
            }
            boolean _check_inv_35;
            if(isCaching) {
                _ProjectionRead__check_inv_35 read__check_inv_35_state = state._projected_state_for__check_inv_35();
                Object _obj__check_inv_35 = GET.invoke(_InvCache__check_inv_35, read__check_inv_35_state);
                if(_obj__check_inv_35 == null) {
                    _check_inv_35 = state._check_inv_35();
                    _InvCache__check_inv_35 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_35, read__check_inv_35_state, _check_inv_35);
                } else {
                    _check_inv_35 = (boolean) _obj__check_inv_35;
                }
            } else {
                _check_inv_35 = state._check_inv_35();
            }
            if(!_check_inv_35) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_35");
                return true;
            }
            boolean _check_inv_36;
            if(isCaching) {
                _ProjectionRead__check_inv_36 read__check_inv_36_state = state._projected_state_for__check_inv_36();
                Object _obj__check_inv_36 = GET.invoke(_InvCache__check_inv_36, read__check_inv_36_state);
                if(_obj__check_inv_36 == null) {
                    _check_inv_36 = state._check_inv_36();
                    _InvCache__check_inv_36 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_36, read__check_inv_36_state, _check_inv_36);
                } else {
                    _check_inv_36 = (boolean) _obj__check_inv_36;
                }
            } else {
                _check_inv_36 = state._check_inv_36();
            }
            if(!_check_inv_36) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_36");
                return true;
            }
            boolean _check_inv_37;
            if(isCaching) {
                _ProjectionRead__check_inv_37 read__check_inv_37_state = state._projected_state_for__check_inv_37();
                Object _obj__check_inv_37 = GET.invoke(_InvCache__check_inv_37, read__check_inv_37_state);
                if(_obj__check_inv_37 == null) {
                    _check_inv_37 = state._check_inv_37();
                    _InvCache__check_inv_37 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_37, read__check_inv_37_state, _check_inv_37);
                } else {
                    _check_inv_37 = (boolean) _obj__check_inv_37;
                }
            } else {
                _check_inv_37 = state._check_inv_37();
            }
            if(!_check_inv_37) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_37");
                return true;
            }
            boolean _check_inv_38;
            if(isCaching) {
                _ProjectionRead__check_inv_38 read__check_inv_38_state = state._projected_state_for__check_inv_38();
                Object _obj__check_inv_38 = GET.invoke(_InvCache__check_inv_38, read__check_inv_38_state);
                if(_obj__check_inv_38 == null) {
                    _check_inv_38 = state._check_inv_38();
                    _InvCache__check_inv_38 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_38, read__check_inv_38_state, _check_inv_38);
                } else {
                    _check_inv_38 = (boolean) _obj__check_inv_38;
                }
            } else {
                _check_inv_38 = state._check_inv_38();
            }
            if(!_check_inv_38) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_38");
                return true;
            }
            boolean _check_inv_39;
            if(isCaching) {
                _ProjectionRead__check_inv_39 read__check_inv_39_state = state._projected_state_for__check_inv_39();
                Object _obj__check_inv_39 = GET.invoke(_InvCache__check_inv_39, read__check_inv_39_state);
                if(_obj__check_inv_39 == null) {
                    _check_inv_39 = state._check_inv_39();
                    _InvCache__check_inv_39 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_39, read__check_inv_39_state, _check_inv_39);
                } else {
                    _check_inv_39 = (boolean) _obj__check_inv_39;
                }
            } else {
                _check_inv_39 = state._check_inv_39();
            }
            if(!_check_inv_39) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_39");
                return true;
            }
            return false;
        }

        private void printResult(final int states, final int transitions) {
            if(invariantViolated.get() || deadlockDetected.get()) {
                if(deadlockDetected.get()) {
                    System.out.println("DEADLOCK DETECTED");
                } else {
                    System.out.println("INVARIANT VIOLATED");
                }

                System.out.println("COUNTER EXAMPLE TRACE: ");
                StringBuilder sb = new StringBuilder();
                while(counterExampleState != null) {
                    sb.insert(0, counterExampleState);
                    sb.insert(0, "\n");
                    if(counterExampleState.stateAccessedVia != null) {
                        sb.insert(0, counterExampleState.stateAccessedVia);
                    }
                    sb.insert(0, "\n\n");
                    counterExampleState = counterExampleState.parent;
                }
                System.out.println(sb);
            } else {
                System.out.println("MODEL CHECKING SUCCESSFUL");
            }

            System.out.println("Number of States: " + states);
            System.out.println("Number of Transitions: " + transitions);
        }
    }


    public static void main(String[] args) {
        if(args.length > 4) {
            System.out.println("Expecting 3 command-line arguments: STRATEGY THREADS CACHING DEBUG");
            return;
        }
        Type type = Type.MIXED;
        int threads = 0;
        boolean isCaching = false;
        boolean isDebug = false;

        if(args.length > 0) { 
            if("mixed".equals(args[0])) {
                type = Type.MIXED;
            } else if("bf".equals(args[0])) {
                type = Type.BFS;
            } else if ("df".equals(args[0])) {
                type = Type.DFS;
            } else {
                System.out.println("Value for command-line argument STRATEGY is wrong.");
                System.out.println("Expecting mixed, bf or df.");
                return;
            }
        }
        if(args.length > 1) { 
            try {
                threads = Integer.parseInt(args[1]);
            } catch(NumberFormatException e) {
                System.out.println("Value for command-line argument THREADS is not a number.");
                return;
            }
            if(threads <= 0) {
                System.out.println("Value for command-line argument THREADS must be positive.");
                return;
            }
        }
        if(args.length > 2) { 
            try {
                isCaching = Boolean.parseBoolean(args[2]);
            } catch(Exception e) {
                System.out.println("Value for command-line argument CACHING is not a boolean.");
                return;
            }
        }
        if(args.length > 3) { 
            try {
                isDebug = Boolean.parseBoolean(args[3]);
            } catch(Exception e) {
                System.out.println("Value for command-line argument DEBUG is not a boolean.");
                return;
            }
        }

        System.out.println("Starting Model Checking, Search: "+type+", Threads: "+threads+", Caching: "+isCaching);
        long start = java.lang.System.currentTimeMillis();
        ModelChecker modelchecker = new ModelChecker(type, threads, isCaching, isDebug);
        modelchecker.modelCheck();
        long stop = java.lang.System.currentTimeMillis();
        System.out.println("Model Checking Time: "+ (stop-start) + " ms");
    }




}
