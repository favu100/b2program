import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
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


public class QueensWithEvents {


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
        n = new BInteger(8);
        interval = BSet.interval(new BInteger(1), n);
        allFields = BRelation.cartesianProduct(interval, interval).pow();
    }

    public QueensWithEvents() {
        queens = new BRelation<BInteger, BInteger>();
    }

    public QueensWithEvents(BInteger n, BSet<BInteger> interval, BSet<BRelation<BInteger, BInteger>> allFields, BRelation<BInteger, BInteger> queens) {
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
        BSet<BRelation<BInteger, BInteger>> _ic_set_3 = new BSet<BRelation<BInteger, BInteger>>();
        for(BRelation<BInteger, BInteger> _ic_solution_1 : allFields) {
            BBoolean _ic_boolean_3 = new BBoolean(true);
            if(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue()) {
                for(BInteger _ic_x_1 : interval) {
                    for(BInteger _ic_y_1 : interval) {
                        for(BInteger _ic_z_1 : interval) {
                            if(!(new BBoolean(!new BBoolean(_ic_solution_1.elementOf(new BTuple<>(_ic_x_1, _ic_y_1)).booleanValue() && _ic_solution_1.elementOf(new BTuple<>(_ic_x_1, _ic_z_1)).booleanValue()).booleanValue() || _ic_y_1.equal(_ic_z_1).booleanValue())).booleanValue()) {
                                _ic_boolean_3 = new BBoolean(false);
                                break;
                            }

                        }
                    }
                }
            }
            BBoolean _ic_boolean_4 = new BBoolean(true);
            if(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue()) {
                for(BInteger _ic_q1_1 : interval) {
                    for(BInteger _ic_q2_1 : interval.difference(new BSet<BInteger>(new BInteger(1)))) {
                        if(!(new BBoolean(!_ic_q2_1.greater(_ic_q1_1).booleanValue() || new BBoolean(_ic_solution_1.functionCall(_ic_q1_1).plus(_ic_q2_1).minus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue() && _ic_solution_1.functionCall(_ic_q1_1).minus(_ic_q2_1).plus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue()).booleanValue())).booleanValue()) {
                            _ic_boolean_4 = new BBoolean(false);
                            break;
                        }

                    }
                }
            }
            BBoolean _ic_boolean_5 = new BBoolean(true);
            if(new BBoolean(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue()) {
                for(BInteger _ic_x_1 : queens.domain()) {
                    if(!(_ic_solution_1.functionCall(_ic_x_1).equal(queens.functionCall(_ic_x_1))).booleanValue()) {
                        _ic_boolean_5 = new BBoolean(false);
                        break;
                    }

                }
            }

            if((new BBoolean(new BBoolean(new BBoolean(new BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()).booleanValue() && _ic_boolean_3.booleanValue()).booleanValue() && _ic_boolean_4.booleanValue()).booleanValue() && _ic_boolean_5.booleanValue())).booleanValue()) {
                _ic_set_3 = _ic_set_3.union(new BSet<BRelation<BInteger, BInteger>>(_ic_solution_1));
            }

        }
        return _ic_set_3;
    }

    public boolean _check_inv_1() {
        return queens.checkDomain(interval).and(queens.checkRange(interval)).and(queens.isFunction()).and(queens.isPartial(interval)).booleanValue();
    }

    public QueensWithEvents _copy() {
        return new QueensWithEvents(n, interval, allFields, queens);
    }

    @Override
    public boolean equals(Object o) {
        QueensWithEvents o1 = this;
        QueensWithEvents o2 = (QueensWithEvents) o;
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
    private static Set<QueensWithEvents> generateNextStates(Object guardLock, QueensWithEvents state, boolean isCaching, Map<String, Set<String>> invariantDependency, Map<QueensWithEvents, Set<String>> dependentInvariant, Map<String, Set<String>> guardDependency, Map<QueensWithEvents, Set<String>> dependentGuard, Map<QueensWithEvents, PersistentHashMap> guardCache, Map<QueensWithEvents, QueensWithEvents> parents, AtomicInteger transitions) {
        Set<QueensWithEvents> result = new HashSet<>();
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

                QueensWithEvents copiedState = state._copy();
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

                QueensWithEvents copiedState = state._copy();
                copiedState.Solve(_tmp_1);
                result.add(copiedState);
                transitions.getAndIncrement();
            }

        }
        return result;
    }


    public static boolean checkInvariants(Object guardLock, QueensWithEvents state, boolean isCaching, Map<QueensWithEvents, Set<String>> dependentInvariant) {
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

    private static void printResult(int states, int transitions, boolean deadlockDetected, boolean invariantViolated) {
        if(deadlockDetected) {
            System.out.println("DEADLOCK DETECTED");
        }
        if(invariantViolated) {
            System.out.println("INVARIANT VIOLATED");
        }
        if(!deadlockDetected && !invariantViolated) {
            System.out.println("MODEL CHECKING SUCCESSFUL");
        }
        System.out.println("Number of States: " + states);
        System.out.println("Number of Transitions: " + transitions);
    }

    private static QueensWithEvents next(LinkedList<QueensWithEvents> collection, Object lock, Type type) {
        synchronized(lock) {
            return switch(type) {
                case BFS -> collection.removeFirst();
                case DFS -> collection.removeLast();
                case MIXED -> collection.size() % 2 == 0 ? collection.removeFirst() : collection.removeLast();
            };
        }
    }

    private static void modelCheckSingleThreaded(Type type, boolean isCaching) {
        Object lock = new Object();
        Object guardLock = new Object();

        QueensWithEvents machine = new QueensWithEvents();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);

        Set<QueensWithEvents> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<QueensWithEvents> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<QueensWithEvents, Set<String>> dependentInvariant = new HashMap<>();
        Map<QueensWithEvents, Set<String>> dependentGuard = new HashMap<>();
        Map<QueensWithEvents, PersistentHashMap> guardCache = new HashMap<>();
        Map<QueensWithEvents, QueensWithEvents> parents = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("Solve", new HashSet<>(Arrays.asList("_check_inv_1")));
            guardDependency.put("Solve", new HashSet<>(Arrays.asList("_tr_Solve")));
            dependentInvariant.put(machine, new HashSet<>());
            parents.put(machine, null);
        }

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            QueensWithEvents state = next(collection, lock, type);

            if(!checkInvariants(guardLock, state, isCaching, dependentInvariant)) {
                invariantViolated.set(true);
                stopThreads.set(true);
                break;
            }

            Set<QueensWithEvents> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);

            nextStates.forEach(nextState -> {
                if(!states.contains(nextState)) {
                    numberStates.getAndIncrement();
                    states.add(nextState);
                    collection.add(nextState);
                    if(numberStates.get() % 50000 == 0) {
                        System.out.println("VISITED STATES: " + numberStates.get());
                        System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                        System.out.println("-------------------");
                    }
                }
            });

            if(nextStates.isEmpty()) {
                deadlockDetected.set(true);
                stopThreads.set(true);
            }
        }
        printResult(numberStates.get(), transitions.get(), deadlockDetected.get(), invariantViolated.get());
    }


    private static void modelCheckMultiThreaded(Type type, int threads, boolean isCaching) {
        Object lock = new Object();
        Object guardLock = new Object();
        Object waitLock = new Object();
        ThreadPoolExecutor threadPool = (ThreadPoolExecutor) Executors.newFixedThreadPool(threads);

        QueensWithEvents machine = new QueensWithEvents();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);
        AtomicInteger possibleQueueChanges = new AtomicInteger(0);

        Set<QueensWithEvents> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<QueensWithEvents> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<QueensWithEvents, Set<String>> dependentInvariant = new HashMap<>();
        Map<QueensWithEvents, Set<String>> dependentGuard = new HashMap<>();
        Map<QueensWithEvents, PersistentHashMap> guardCache = new HashMap<>();
        Map<QueensWithEvents, QueensWithEvents> parents = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("Solve", new HashSet<>(Arrays.asList("_check_inv_1")));
            guardDependency.put("Solve", new HashSet<>(Arrays.asList("_tr_Solve")));
            dependentInvariant.put(machine, new HashSet<>());
            parents.put(machine, null);
        }

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            possibleQueueChanges.incrementAndGet();
            QueensWithEvents state = next(collection, lock, type);
            Runnable task = () -> {
                Set<QueensWithEvents> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);

                nextStates.forEach(nextState -> {
                    synchronized(lock) {
                        if(!states.contains(nextState)) {
                            numberStates.getAndIncrement();
                            states.add(nextState);
                            collection.add(nextState);
                            if(numberStates.get() % 50000 == 0) {
                                System.out.println("VISITED STATES: " + numberStates.get());
                                System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                System.out.println("-------------------");
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
        printResult(numberStates.get(), transitions.get(), deadlockDetected.get(), invariantViolated.get());
    }


    public static void main(String[] args) {
        if(args.length != 3) {
            System.out.println("Number of arguments errorneous");
            return;
        }
        String strategy = args[0];
        String numberThreads = args[1];
        String caching = args[2];

        Type type;

        if("mixed".equals(strategy)) {
            type = Type.MIXED;
        } else if("bf".equals(strategy)) {
            type = Type.BFS;
        } else if ("df".equals(strategy)) {
            type = Type.DFS;
        } else {
            System.out.println("Input for strategy is wrong.");
            return;
        }

        int threads = 0;
        try {
            threads = Integer.parseInt(numberThreads);
        } catch(NumberFormatException e) {
            System.out.println("Input for number of threads is wrong.");
            return;
        }
        if(threads <= 0) {
            System.out.println("Input for number of threads is wrong.");
            return;
        }

        boolean isCaching = true;
        try {
            isCaching = Boolean.parseBoolean(caching);
        } catch(Exception e) {
            System.out.println("Input for caching is wrong.");
            return;
        }
        if(threads == 1) {
            modelCheckSingleThreaded(type, isCaching);
        } else {
            modelCheckMultiThreaded(type, threads, isCaching);
        }
    }




}
