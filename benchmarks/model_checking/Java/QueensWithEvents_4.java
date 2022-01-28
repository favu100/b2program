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

    public QueensWithEvents_4(BInteger n, BSet<BInteger> interval, BSet<BRelation<BInteger, BInteger>> allFields, BRelation<BInteger, BInteger> queens) {
        this.n = n;
        this.interval = interval;
        this.allFields = allFields;
        this.queens = queens;
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


    public BSet<BRelation<BInteger, BInteger>> _tr_Solve() {
        BSet<BRelation<BInteger, BInteger>> _ic_set_4 = new BSet<BRelation<BInteger, BInteger>>();
        for(BRelation<BInteger, BInteger> _ic_solution_1 : allFields) {
            BBoolean _ic_boolean_5 = new BBoolean(true);
            if(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue()) {
                for(BInteger _ic_x_1 : interval) {
                    for(BInteger _ic_y_1 : interval) {
                        BBoolean _ic_boolean_4 = new BBoolean(true);
                        for(BInteger _ic_z_1 : interval) {
                            if(!(new BBoolean(!_ic_solution_1.elementOf(new BTuple<>(_ic_x_1, _ic_z_1)).booleanValue() || _ic_y_1.equal(_ic_z_1).booleanValue())).booleanValue()) {
                                _ic_boolean_4 = new BBoolean(false);
                                break;
                            }

                        }

                        if(!(new BBoolean(!_ic_solution_1.elementOf(new BTuple<>(_ic_x_1, _ic_y_1)).booleanValue() || _ic_boolean_4.booleanValue())).booleanValue()) {
                            _ic_boolean_5 = new BBoolean(false);
                            break;
                        }

                    }
                }
            }
            BBoolean _ic_boolean_6 = new BBoolean(true);
            if(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue() && _ic_boolean_5.booleanValue()).booleanValue()) {
                for(BInteger _ic_q1_1 : interval) {
                    for(BInteger _ic_q2_1 : interval.difference(new BSet<BInteger>(new BInteger(1)))) {
                        if(!(new BBoolean(!_ic_q2_1.greater(_ic_q1_1).booleanValue() || new BBoolean(_ic_solution_1.functionCall(_ic_q1_1).plus(_ic_q2_1).minus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue() && _ic_solution_1.functionCall(_ic_q1_1).minus(_ic_q2_1).plus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue()).booleanValue())).booleanValue()) {
                            _ic_boolean_6 = new BBoolean(false);
                            break;
                        }

                    }
                }
            }
            BBoolean _ic_boolean_7 = new BBoolean(true);
            if(new BBoolean(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue() && _ic_boolean_5.booleanValue()).booleanValue() && _ic_boolean_6.booleanValue()).booleanValue()) {
                for(BInteger _ic_x_1 : queens.domain()) {
                    if(!(_ic_solution_1.functionCall(_ic_x_1).equal(queens.functionCall(_ic_x_1))).booleanValue()) {
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

    public boolean _check_inv_1() {
        return queens.checkDomain(interval).and(queens.checkRange(interval)).and(queens.isFunction()).and(queens.isPartial(interval)).booleanValue();
    }

    public QueensWithEvents_4 _copy() {
        return new QueensWithEvents_4(n, interval, allFields, queens);
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

    @SuppressWarnings("unchecked")
    private static Set<QueensWithEvents_4> generateNextStates(Object guardLock, QueensWithEvents_4 state, boolean isCaching, Map<String, Set<String>> invariantDependency, Map<QueensWithEvents_4, Set<String>> dependentInvariant, Map<String, Set<String>> guardDependency, Map<QueensWithEvents_4, Set<String>> dependentGuard, Map<QueensWithEvents_4, PersistentHashMap> guardCache, Map<QueensWithEvents_4, QueensWithEvents_4> parents, Map<QueensWithEvents_4, String> stateAccessedVia, AtomicInteger transitions) {
        Set<QueensWithEvents_4> result = new HashSet<>();
        if(isCaching) {
            PersistentHashMap parentsGuard = guardCache.get(parents.get(state));
            PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
            Set<String> dependentGuardsOfState = dependentGuard.get(state);
            Object cachedValue = null;
            boolean dependentGuardsBoolean = true;
            BSet<BRelation<BInteger, BInteger>> _trid_1;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_Solve");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_Solve");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_Solve();
            } else {
                _trid_1 = (BSet<BRelation<BInteger, BInteger>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_Solve", _trid_1);
            for(BRelation<BInteger, BInteger> param : _trid_1) {
                BRelation<BInteger, BInteger> _tmp_1 = param;

                QueensWithEvents_4 copiedState = state._copy();
                copiedState.Solve(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("Solve"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("Solve"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "Solve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

            synchronized(guardLock) {
                guardCache.put(state, newCache);
            }
        } else {
            BSet<BRelation<BInteger, BInteger>> _trid_1 = state._tr_Solve();
            for(BRelation<BInteger, BInteger> param : _trid_1) {
                BRelation<BInteger, BInteger> _tmp_1 = param;

                QueensWithEvents_4 copiedState = state._copy();
                copiedState.Solve(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "Solve");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

        }
        return result;
    }


    public static boolean checkInvariants(Object guardLock, QueensWithEvents_4 state, boolean isCaching, Map<QueensWithEvents_4, Set<String>> dependentInvariant) {
        if(isCaching) {
            Set<String> dependentInvariantsOfState;
            synchronized(guardLock) {
                dependentInvariantsOfState = dependentInvariant.get(state);
            }
            if(dependentInvariantsOfState.contains("_check_inv_1")) {
                if(!state._check_inv_1()) {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1());
    }

    private static void printResult(int states, int transitions, boolean deadlockDetected, boolean invariantViolated, List<QueensWithEvents_4> counterExampleState, Map<QueensWithEvents_4, QueensWithEvents_4> parents, Map<QueensWithEvents_4, String> stateAccessedVia) {

        if(invariantViolated || deadlockDetected) {
            if(deadlockDetected) {
                System.out.println("DEADLOCK DETECTED");
            }
            if(invariantViolated) {
                System.out.println("INVARIANT VIOLATED");
            }
            System.out.println("COUNTER EXAMPLE TRACE: ");
            StringBuilder sb = new StringBuilder();
            if(counterExampleState.size() >= 1) {
                QueensWithEvents_4 currentState = counterExampleState.get(0);
                while(currentState != null) {
                    sb.insert(0, currentState.toString());
                    sb.insert(0, "\n");
                    sb.insert(0, stateAccessedVia.get(currentState));
                    sb.insert(0, "\n\n");
                    currentState = parents.get(currentState);
                }
            }
            System.out.println(sb.toString());

        }
        if(!deadlockDetected && !invariantViolated) {
            System.out.println("MODEL CHECKING SUCCESSFUL");
        }
        System.out.println("Number of States: " + states);
        System.out.println("Number of Transitions: " + transitions);
    }

    private static QueensWithEvents_4 next(LinkedList<QueensWithEvents_4> collection, Object lock, Type type) {
        synchronized(lock) {
            return switch(type) {
                case BFS -> collection.removeFirst();
                case DFS -> collection.removeLast();
                case MIXED -> collection.size() % 2 == 0 ? collection.removeFirst() : collection.removeLast();
            };
        }
    }

    private static void modelCheckSingleThreaded(Type type, boolean isCaching, boolean isDebug) {
        Object lock = new Object();
        Object guardLock = new Object();

        QueensWithEvents_4 machine = new QueensWithEvents_4();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);

        Set<QueensWithEvents_4> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<QueensWithEvents_4> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<QueensWithEvents_4, Set<String>> dependentInvariant = new HashMap<>();
        Map<QueensWithEvents_4, Set<String>> dependentGuard = new HashMap<>();
        Map<QueensWithEvents_4, PersistentHashMap> guardCache = new HashMap<>();
        Map<QueensWithEvents_4, QueensWithEvents_4> parents = new HashMap<>();
        Map<QueensWithEvents_4, String> stateAccessedVia = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("Solve", new HashSet<>(Arrays.asList("_check_inv_1")));
            guardDependency.put("Solve", new HashSet<>(Arrays.asList("_tr_Solve")));
            dependentInvariant.put(machine, new HashSet<>());
        }
        List<QueensWithEvents_4> counterExampleState = new ArrayList<>();
        parents.put(machine, null);

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            QueensWithEvents_4 state = next(collection, lock, type);

            Set<QueensWithEvents_4> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);

            nextStates.forEach(nextState -> {
                if(!states.contains(nextState)) {
                    numberStates.getAndIncrement();
                    states.add(nextState);
                    collection.add(nextState);
                    if(numberStates.get() % 5000 == 0) {
                        System.out.println("VISITED STATES: " + numberStates.get());
                        System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                        System.out.println("-------------------");
                    }
                }
            });

            if(!checkInvariants(guardLock, state, isCaching, dependentInvariant)) {
                invariantViolated.set(true);
                stopThreads.set(true);
                counterExampleState.add(state);
            }

            if(nextStates.isEmpty()) {
                deadlockDetected.set(true);
                stopThreads.set(true);
            }

        }
        printResult(numberStates.get(), transitions.get(), deadlockDetected.get(), invariantViolated.get(), counterExampleState, parents, stateAccessedVia);
    }


    private static void modelCheckMultiThreaded(Type type, int threads, boolean isCaching, boolean isDebug) {
        Object lock = new Object();
        Object guardLock = new Object();
        Object waitLock = new Object();
        ThreadPoolExecutor threadPool = (ThreadPoolExecutor) Executors.newFixedThreadPool(threads);

        QueensWithEvents_4 machine = new QueensWithEvents_4();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);
        AtomicInteger possibleQueueChanges = new AtomicInteger(0);

        Set<QueensWithEvents_4> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<QueensWithEvents_4> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<QueensWithEvents_4, Set<String>> dependentInvariant = new HashMap<>();
        Map<QueensWithEvents_4, Set<String>> dependentGuard = new HashMap<>();
        Map<QueensWithEvents_4, PersistentHashMap> guardCache = new HashMap<>();
        Map<QueensWithEvents_4, QueensWithEvents_4> parents = new HashMap<>();
        Map<QueensWithEvents_4, String> stateAccessedVia = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("Solve", new HashSet<>(Arrays.asList("_check_inv_1")));
            guardDependency.put("Solve", new HashSet<>(Arrays.asList("_tr_Solve")));
            dependentInvariant.put(machine, new HashSet<>());
        }
        List<QueensWithEvents_4> counterExampleState = new ArrayList<>();
        parents.put(machine, null);
        stateAccessedVia.put(machine, null);

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            possibleQueueChanges.incrementAndGet();
            QueensWithEvents_4 state = next(collection, lock, type);
            Runnable task = () -> {
                Set<QueensWithEvents_4> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);

                nextStates.forEach(nextState -> {
                    synchronized(lock) {
                        if(!states.contains(nextState)) {
                            numberStates.getAndIncrement();
                            states.add(nextState);
                            collection.add(nextState);
                            if(numberStates.get() % 5000 == 0) {
                                if( isDebug || numberStates.get() % 50000 == 0) {
                                    System.out.println("VISITED STATES: " + numberStates.get());
                                    System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                    System.out.println("-------------------");
                                }
                            }
                        }
                    }
                });

                synchronized (lock) {
                    int running = possibleQueueChanges.decrementAndGet();
                    if (!collection.isEmpty() || running == 0) {
                        synchronized (waitLock) {
                            waitLock.notify();
                        }
                    }
                }

                if(nextStates.isEmpty()) {
                    deadlockDetected.set(true);
                    stopThreads.set(true);
                }

                if(!checkInvariants(guardLock, state, isCaching, dependentInvariant)) {
                    invariantViolated.set(true);
                    stopThreads.set(true);
                    counterExampleState.add(state);
                }


            };
            threadPool.submit(task);
            synchronized(waitLock) {
                if (collection.isEmpty() && possibleQueueChanges.get() > 0) {
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
            threadPool.awaitTermination(5, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        printResult(numberStates.get(), transitions.get(), deadlockDetected.get(), invariantViolated.get(), counterExampleState, parents, stateAccessedVia);
    }

    public static void debugPrint (String msg, Boolean isDebug) {
       if (isDebug) {
          System.out.println(msg);
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

        debugPrint("Starting Modelchecking, STRATEGY=" + type + "THREADS=" + threads + ", CACHING=" + isCaching, isDebug);
        if(threads == 1) {
            modelCheckSingleThreaded(type, isCaching, isDebug);
        } else {
            modelCheckMultiThreaded(type, threads, isCaching, isDebug);
        }
    }




}
