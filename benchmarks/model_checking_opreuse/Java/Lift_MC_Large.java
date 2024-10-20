import de.hhu.stups.btypes.BTuple;
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


public class Lift_MC_Large {


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

    public Lift_MC_Large parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_inc {

        public BInteger level;

        public _ProjectionRead_inc(BInteger level) {
            this.level = level;
        }

        public String toString() {
            return "{" + "level: " + this.level + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_inc)) {
                return false;
            }
            _ProjectionRead_inc o = (_ProjectionRead_inc) other;
            return this.level.equals(o.level);
        }

        public int hashCode() {
            return Objects.hash(level);
        }
    }

    public static class _ProjectionRead__tr_inc {

        public BInteger level;

        public _ProjectionRead__tr_inc(BInteger level) {
            this.level = level;
        }

        public String toString() {
            return "{" + "level: " + this.level + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_inc)) {
                return false;
            }
            _ProjectionRead__tr_inc o = (_ProjectionRead__tr_inc) other;
            return this.level.equals(o.level);
        }

        public int hashCode() {
            return Objects.hash(level);
        }
    }

    public static class _ProjectionWrite_inc {

        public BInteger level;

        public _ProjectionWrite_inc(BInteger level) {
            this.level = level;
        }

        public String toString() {
            return "{" + "level: " + this.level + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_inc)) {
                return false;
            }
            _ProjectionWrite_inc o = (_ProjectionWrite_inc) other;
            return this.level.equals(o.level);
        }

        public int hashCode() {
            return Objects.hash(level);
        }
    }

    public static class _ProjectionRead_dec {

        public BInteger level;

        public _ProjectionRead_dec(BInteger level) {
            this.level = level;
        }

        public String toString() {
            return "{" + "level: " + this.level + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_dec)) {
                return false;
            }
            _ProjectionRead_dec o = (_ProjectionRead_dec) other;
            return this.level.equals(o.level);
        }

        public int hashCode() {
            return Objects.hash(level);
        }
    }

    public static class _ProjectionRead__tr_dec {

        public BInteger level;

        public _ProjectionRead__tr_dec(BInteger level) {
            this.level = level;
        }

        public String toString() {
            return "{" + "level: " + this.level + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_dec)) {
                return false;
            }
            _ProjectionRead__tr_dec o = (_ProjectionRead__tr_dec) other;
            return this.level.equals(o.level);
        }

        public int hashCode() {
            return Objects.hash(level);
        }
    }

    public static class _ProjectionWrite_dec {

        public BInteger level;

        public _ProjectionWrite_dec(BInteger level) {
            this.level = level;
        }

        public String toString() {
            return "{" + "level: " + this.level + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_dec)) {
                return false;
            }
            _ProjectionWrite_dec o = (_ProjectionWrite_dec) other;
            return this.level.equals(o.level);
        }

        public int hashCode() {
            return Objects.hash(level);
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public BInteger level;

        public _ProjectionRead__check_inv_1(BInteger level) {
            this.level = level;
        }

        public String toString() {
            return "{" + "level: " + this.level + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.level.equals(o.level);
        }

        public int hashCode() {
            return Objects.hash(level);
        }
    }

    public static class _ProjectionRead__check_inv_2 {

        public BInteger level;

        public _ProjectionRead__check_inv_2(BInteger level) {
            this.level = level;
        }

        public String toString() {
            return "{" + "level: " + this.level + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_2)) {
                return false;
            }
            _ProjectionRead__check_inv_2 o = (_ProjectionRead__check_inv_2) other;
            return this.level.equals(o.level);
        }

        public int hashCode() {
            return Objects.hash(level);
        }
    }








    private BInteger level;

    public Lift_MC_Large() {
        level = new BInteger(0);
    }

    public Lift_MC_Large(Lift_MC_Large copy) {
        this.level = copy.level;
    }

    public void inc() {
        level = level.plus(new BInteger(1));

    }

    public void dec() {
        level = level.minus(new BInteger(1));

    }

    public BInteger _get_level() {
        return level;
    }

    @Override
    public boolean equals(Object o) {
        Lift_MC_Large o1 = this;
        Lift_MC_Large o2 = (Lift_MC_Large) o;
        return o1._get_level().equals(o2._get_level());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_level()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_level()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_level: " + (this._get_level()).toString());
    }

    public Lift_MC_Large _copy() {
        return new Lift_MC_Large(this);
    }


    public boolean _tr_inc() {
        return level.less(new BInteger(1000000)).booleanValue();
    }

    public boolean _tr_dec() {
        return level.greater(new BInteger(0)).booleanValue();
    }

    public _ProjectionRead_dec _projected_state_for_dec() {
        return new _ProjectionRead_dec(level);
    }

    public _ProjectionRead_inc _projected_state_for_inc() {
        return new _ProjectionRead_inc(level);
    }

    public _ProjectionRead__tr_dec _projected_state_for__tr_dec() {
        return new _ProjectionRead__tr_dec(level);
    }

    public _ProjectionRead__tr_inc _projected_state_for__tr_inc() {
        return new _ProjectionRead__tr_inc(level);
    }

    public _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() {
        return new _ProjectionRead__check_inv_2(level);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(level);
    }

    public _ProjectionWrite_dec _update_for_dec() {
        return new _ProjectionWrite_dec(level);
    }

    public _ProjectionWrite_inc _update_for_inc() {
        return new _ProjectionWrite_inc(level);
    }

    public void _apply_update_for_dec(_ProjectionWrite_dec update) {
        this.level = update.level;
    }

    public void _apply_update_for_inc(_ProjectionWrite_inc update) {
        this.level = update.level;
    }

    public boolean _check_inv_1() {
        return level.greaterEqual(new BInteger(0)).booleanValue();
    }

    public boolean _check_inv_2() {
        return level.lessEqual(new BInteger(1000000)).booleanValue();
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<Lift_MC_Large> unvisitedStates = new LinkedList<>();
        private final Set<Lift_MC_Large> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private Lift_MC_Large counterExampleState = null;

        PersistentHashMap _OpCache_inc = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_inc = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_dec = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_dec = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_2 = PersistentHashMap.EMPTY;

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
            Lift_MC_Large machine = new Lift_MC_Large();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                Lift_MC_Large state = next();

                Set<Lift_MC_Large> nextStates = generateNextStates(state);

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
            Lift_MC_Large machine = new Lift_MC_Large();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                Lift_MC_Large state = next();
                Runnable task = () -> {
                    Set<Lift_MC_Large> nextStates = generateNextStates(state);

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

        private Lift_MC_Large next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<Lift_MC_Large> generateNextStates(final Lift_MC_Large state) {
            Set<Lift_MC_Large> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_inc read__tr_inc_state = state._projected_state_for__tr_inc();
                Object _obj__trid_1 = GET.invoke(_OpCache_tr_inc, read__tr_inc_state);
                boolean _trid_1;
                if(_obj__trid_1 == null) {
                    _trid_1 = state._tr_inc();
                    _OpCache_tr_inc = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_inc, read__tr_inc_state, _trid_1);
                } else {
                    _trid_1 = (boolean) _obj__trid_1;
                }
                if(_trid_1) {
                    Lift_MC_Large copiedState = state._copy();
                    _ProjectionRead_inc readState = state._projected_state_for_inc();
                    PersistentHashMap _OpCache_with_parameter_inc = (PersistentHashMap) GET.invoke(_OpCache_inc, _trid_1);
                    if(_OpCache_with_parameter_inc != null) {
                        _ProjectionWrite_inc writeState = (_ProjectionWrite_inc) GET.invoke(_OpCache_with_parameter_inc, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_inc(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.inc();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_inc();
                            _OpCache_with_parameter_inc = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_inc, readState, writeState);
                            _OpCache_inc = (PersistentHashMap) ASSOC.invoke(_OpCache_inc, _trid_1, _OpCache_with_parameter_inc);
                        }

                    } else {
                        copiedState.inc();
                        copiedState.parent = state;
                        _ProjectionWrite_inc writeState = copiedState._update_for_inc();
                        _OpCache_with_parameter_inc = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_inc = (PersistentHashMap) ASSOC.invoke(_OpCache_inc, _trid_1, _OpCache_with_parameter_inc);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_dec read__tr_dec_state = state._projected_state_for__tr_dec();
                Object _obj__trid_2 = GET.invoke(_OpCache_tr_dec, read__tr_dec_state);
                boolean _trid_2;
                if(_obj__trid_2 == null) {
                    _trid_2 = state._tr_dec();
                    _OpCache_tr_dec = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_dec, read__tr_dec_state, _trid_2);
                } else {
                    _trid_2 = (boolean) _obj__trid_2;
                }
                if(_trid_2) {
                    Lift_MC_Large copiedState = state._copy();
                    _ProjectionRead_dec readState = state._projected_state_for_dec();
                    PersistentHashMap _OpCache_with_parameter_dec = (PersistentHashMap) GET.invoke(_OpCache_dec, _trid_2);
                    if(_OpCache_with_parameter_dec != null) {
                        _ProjectionWrite_dec writeState = (_ProjectionWrite_dec) GET.invoke(_OpCache_with_parameter_dec, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_dec(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.dec();
                            copiedState.parent = state;
                            writeState = copiedState._update_for_dec();
                            _OpCache_with_parameter_dec = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_dec, readState, writeState);
                            _OpCache_dec = (PersistentHashMap) ASSOC.invoke(_OpCache_dec, _trid_2, _OpCache_with_parameter_dec);
                        }

                    } else {
                        copiedState.dec();
                        copiedState.parent = state;
                        _ProjectionWrite_dec writeState = copiedState._update_for_dec();
                        _OpCache_with_parameter_dec = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_dec = (PersistentHashMap) ASSOC.invoke(_OpCache_dec, _trid_2, _OpCache_with_parameter_dec);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                if(state._tr_inc()) {
                    Lift_MC_Large copiedState = state._copy();
                    copiedState.inc();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_dec()) {
                    Lift_MC_Large copiedState = state._copy();
                    copiedState.dec();
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final Lift_MC_Large state) {
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
