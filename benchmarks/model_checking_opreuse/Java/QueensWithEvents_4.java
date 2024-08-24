import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BSet;
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


public class QueensWithEvents_4 {


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

    public QueensWithEvents_4 parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_Solve {

        public BRelation<BInteger, BInteger> queens;

        public _ProjectionRead_Solve(BRelation<BInteger, BInteger> queens) {
            this.queens = queens;
        }

        public String toString() {
            return "{" + "queens: " + this.queens + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_Solve)) {
                return false;
            }
            _ProjectionRead_Solve o = (_ProjectionRead_Solve) other;
            return this.queens.equals(o.queens);
        }

        public int hashCode() {
            return Objects.hash(queens);
        }
    }

    public static class _ProjectionRead__tr_Solve {

        public BRelation<BInteger, BInteger> queens;

        public _ProjectionRead__tr_Solve(BRelation<BInteger, BInteger> queens) {
            this.queens = queens;
        }

        public String toString() {
            return "{" + "queens: " + this.queens + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_Solve)) {
                return false;
            }
            _ProjectionRead__tr_Solve o = (_ProjectionRead__tr_Solve) other;
            return this.queens.equals(o.queens);
        }

        public int hashCode() {
            return Objects.hash(queens);
        }
    }

    public static class _ProjectionWrite_Solve {

        public BRelation<BInteger, BInteger> queens;

        public _ProjectionWrite_Solve(BRelation<BInteger, BInteger> queens) {
            this.queens = queens;
        }

        public String toString() {
            return "{" + "queens: " + this.queens + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_Solve)) {
                return false;
            }
            _ProjectionWrite_Solve o = (_ProjectionWrite_Solve) other;
            return this.queens.equals(o.queens);
        }

        public int hashCode() {
            return Objects.hash(queens);
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public BRelation<BInteger, BInteger> queens;

        public _ProjectionRead__check_inv_1(BRelation<BInteger, BInteger> queens) {
            this.queens = queens;
        }

        public String toString() {
            return "{" + "queens: " + this.queens + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.queens.equals(o.queens);
        }

        public int hashCode() {
            return Objects.hash(queens);
        }
    }




    private static BInteger n;
    private static BSet<BInteger> interval;
    private static BSet<BRelation<BInteger, BInteger>> allFields;




    private BRelation<BInteger, BInteger> queens;

    static {
        n = new BInteger(4);
        interval = BSet.interval(new BInteger(1), n);
        allFields = BRelation.cartesianProduct(interval, interval).pow();
    }

    public QueensWithEvents_4() {
        queens = new BRelation<BInteger, BInteger>();
    }

    public QueensWithEvents_4(QueensWithEvents_4 copy) {
        this.n = copy.n;
        this.interval = copy.interval;
        this.allFields = copy.allFields;
        this.queens = copy.queens;
    }

    public void Solve(BRelation<BInteger, BInteger> solution) {
        queens = solution;

    }

    public BInteger _get_n() {
        return n;
    }

    public BSet<BInteger> _get_interval() {
        return interval;
    }

    public BSet<BRelation<BInteger, BInteger>> _get_allFields() {
        return allFields;
    }

    public BRelation<BInteger, BInteger> _get_queens() {
        return queens;
    }

    @Override
    public boolean equals(Object o) {
        QueensWithEvents_4 o1 = this;
        QueensWithEvents_4 o2 = (QueensWithEvents_4) o;
        return o1._get_queens().equals(o2._get_queens());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_queens()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_queens()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_queens: " + (this._get_queens()).toString());
    }

    public QueensWithEvents_4 _copy() {
        return new QueensWithEvents_4(this);
    }


    public BSet<BRelation<BInteger, BInteger>> _tr_Solve() {
        BSet<BRelation<BInteger, BInteger>> _ic_set_4 = new BSet<BRelation<BInteger, BInteger>>();
        for(BRelation<BInteger, BInteger> _ic_solution_1 : allFields) {
            BBoolean _ic_boolean_5 = new BBoolean(true);
            for(BInteger _ic_x_1 : interval) {
                for(BInteger _ic_y_1 : interval) {
                    BBoolean _ic_boolean_4 = new BBoolean(true);
                    for(BInteger _ic_z_1 : interval) {
                        if(!(new BBoolean(!new BBoolean(interval.elementOf(_ic_z_1).booleanValue() && _ic_solution_1.elementOf(new BTuple<>(_ic_x_1, _ic_z_1)).booleanValue()).booleanValue() || _ic_y_1.equal(_ic_z_1).booleanValue())).booleanValue()) {
                            _ic_boolean_4 = new BBoolean(false);
                            break;
                        }

                    }
                    if(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue()) {
                        if(!(new BBoolean(!new BBoolean(new BBoolean(interval.elementOf(_ic_x_1).booleanValue() && interval.elementOf(_ic_y_1).booleanValue()).booleanValue() && _ic_solution_1.elementOf(new BTuple<>(_ic_x_1, _ic_y_1)).booleanValue()).booleanValue() || _ic_boolean_4.booleanValue())).booleanValue()) {
                            _ic_boolean_5 = new BBoolean(false);
                            break;
                        }
                    }

                }
            }BBoolean _ic_boolean_6 = new BBoolean(true);
            for(BInteger _ic_q1_1 : interval) {
                for(BInteger _ic_q2_1 : interval.difference(new BSet<BInteger>(new BInteger(1)))) {
                    if(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue() && _ic_boolean_5.booleanValue()).booleanValue()) {
                        if(!(new BBoolean(!new BBoolean(new BBoolean(interval.elementOf(_ic_q1_1).booleanValue() && interval.difference(new BSet<BInteger>(new BInteger(1))).elementOf(_ic_q2_1).booleanValue()).booleanValue() && _ic_q2_1.greater(_ic_q1_1).booleanValue()).booleanValue() || new BBoolean(_ic_solution_1.functionCall(_ic_q1_1).plus(_ic_q2_1).minus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue() && _ic_solution_1.functionCall(_ic_q1_1).minus(_ic_q2_1).plus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue()).booleanValue())).booleanValue()) {
                            _ic_boolean_6 = new BBoolean(false);
                            break;
                        }
                    }

                }
            }BBoolean _ic_boolean_7 = new BBoolean(true);
            for(BInteger _ic_x_1 : queens.domain()) {
                if(new BBoolean(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue() && _ic_boolean_5.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue()) {
                    if(!(new BBoolean(!queens.domain().elementOf(_ic_x_1).booleanValue() || _ic_solution_1.functionCall(_ic_x_1).equal(queens.functionCall(_ic_x_1)).booleanValue())).booleanValue()) {
                        _ic_boolean_7 = new BBoolean(false);
                        break;
                    }
                }

            }
            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue() && _ic_boolean_5.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue() && _ic_boolean_7.booleanValue())).booleanValue()) {
                _ic_set_4 = _ic_set_4.union(new BSet<BRelation<BInteger, BInteger>>(_ic_solution_1));
            }

        }
        return _ic_set_4;
    }

    public _ProjectionRead_Solve _projected_state_for_Solve() {
        return new _ProjectionRead_Solve(queens);
    }

    public _ProjectionRead__tr_Solve _projected_state_for__tr_Solve() {
        return new _ProjectionRead__tr_Solve(queens);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(queens);
    }

    public _ProjectionWrite_Solve _update_for_Solve() {
        return new _ProjectionWrite_Solve(queens);
    }

    public void _apply_update_for_Solve(_ProjectionWrite_Solve update) {
        this.queens = update.queens;
    }

    public boolean _check_inv_1() {
        return queens.checkDomain(interval).and(queens.checkRange(interval)).and(queens.isFunction()).and(queens.isPartial(interval)).booleanValue();
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<QueensWithEvents_4> unvisitedStates = new LinkedList<>();
        private final Set<QueensWithEvents_4> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private QueensWithEvents_4 counterExampleState = null;

        PersistentHashMap _OpCache_Solve = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_Solve = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_1 = PersistentHashMap.EMPTY;

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
            QueensWithEvents_4 machine = new QueensWithEvents_4();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                QueensWithEvents_4 state = next();

                Set<QueensWithEvents_4> nextStates = generateNextStates(state);

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
            QueensWithEvents_4 machine = new QueensWithEvents_4();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                QueensWithEvents_4 state = next();
                Runnable task = () -> {
                    Set<QueensWithEvents_4> nextStates = generateNextStates(state);

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

        private QueensWithEvents_4 next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<QueensWithEvents_4> generateNextStates(final QueensWithEvents_4 state) {
            Set<QueensWithEvents_4> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_Solve read__tr_Solve_state = state._projected_state_for__tr_Solve();
                BSet<BRelation<BInteger, BInteger>> _trid_1 = (BSet<BRelation<BInteger, BInteger>>) GET.invoke(_OpCache_tr_Solve, read__tr_Solve_state);
                if(_trid_1 == null) {
                    _trid_1 = state._tr_Solve();
                    _OpCache_tr_Solve = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_Solve, read__tr_Solve_state, _trid_1);
                }
                for(BRelation<BInteger, BInteger> param : _trid_1) {
                    BRelation<BInteger, BInteger> _tmp_1 = param;

                    QueensWithEvents_4 copiedState = state._copy();
                    _ProjectionRead_Solve readState = state._projected_state_for_Solve();
                    PersistentHashMap _OpCache_with_parameter_Solve = (PersistentHashMap) GET.invoke(_OpCache_Solve, param);
                    if(_OpCache_with_parameter_Solve != null) {
                        _ProjectionWrite_Solve writeState = (_ProjectionWrite_Solve) GET.invoke(_OpCache_with_parameter_Solve, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_Solve(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.Solve(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_Solve();
                            _OpCache_with_parameter_Solve = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_Solve, readState, writeState);
                            _OpCache_Solve = (PersistentHashMap) ASSOC.invoke(_OpCache_Solve, param, _OpCache_with_parameter_Solve);
                        }

                    } else {
                        copiedState.Solve(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_Solve writeState = copiedState._update_for_Solve();
                        _OpCache_with_parameter_Solve = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_Solve = (PersistentHashMap) ASSOC.invoke(_OpCache_Solve, param, _OpCache_with_parameter_Solve);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                BSet<BRelation<BInteger, BInteger>> _trid_1 = state._tr_Solve();
                for(BRelation<BInteger, BInteger> param : _trid_1) {
                    BRelation<BInteger, BInteger> _tmp_1 = param;

                    QueensWithEvents_4 copiedState = state._copy();
                    copiedState.Solve(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final QueensWithEvents_4 state) {
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
