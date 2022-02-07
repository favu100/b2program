import de.hhu.stups.btypes.BTuple;
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







    private BInteger level;

    public Lift_MC_Large() {
        level = new BInteger(0);
    }

    public Lift_MC_Large(BInteger level) {
        this.level = level;
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


    public boolean _tr_inc() {
        return level.less(new BInteger(1000000)).booleanValue();
    }

    public boolean _tr_dec() {
        return level.greater(new BInteger(0)).booleanValue();
    }

    public boolean _check_inv_1() {
        return level.greaterEqual(new BInteger(0)).booleanValue();
    }

    public boolean _check_inv_2() {
        return level.lessEqual(new BInteger(1000000)).booleanValue();
    }

    public Lift_MC_Large _copy() {
        return new Lift_MC_Large(level);
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

    @SuppressWarnings("unchecked")
    private static Set<Lift_MC_Large> generateNextStates(Object guardLock, Lift_MC_Large state, boolean isCaching, Map<String, Set<String>> invariantDependency, Map<Lift_MC_Large, Set<String>> dependentInvariant, Map<String, Set<String>> guardDependency, Map<Lift_MC_Large, Set<String>> dependentGuard, Map<Lift_MC_Large, PersistentHashMap> guardCache, Map<Lift_MC_Large, Lift_MC_Large> parents, Map<Lift_MC_Large, String> stateAccessedVia, AtomicInteger transitions) {
        Set<Lift_MC_Large> result = new HashSet<>();
        if(isCaching) {
            PersistentHashMap parentsGuard = guardCache.get(parents.get(state));
            PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
            Set<String> dependentGuardsOfState = dependentGuard.get(state);
            Object cachedValue = null;
            boolean dependentGuardsBoolean = true;
            boolean _trid_1;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_inc");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_inc");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_inc();
            } else {
                _trid_1 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_inc", _trid_1);
            if(_trid_1) {
                Lift_MC_Large copiedState = state._copy();
                copiedState.inc();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("inc"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("inc"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "inc");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_2;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_dec");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_dec");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_dec();
            } else {
                _trid_2 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_dec", _trid_2);
            if(_trid_2) {
                Lift_MC_Large copiedState = state._copy();
                copiedState.dec();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("dec"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("dec"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "dec");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

            synchronized(guardLock) {
                guardCache.put(state, newCache);
            }
        } else {
            if(state._tr_inc()) {
                Lift_MC_Large copiedState = state._copy();
                copiedState.inc();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "inc");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_dec()) {
                Lift_MC_Large copiedState = state._copy();
                copiedState.dec();
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "dec");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

        }
        return result;
    }


    public static boolean checkInvariants(Object guardLock, Lift_MC_Large state, boolean isCaching, Map<Lift_MC_Large, Set<String>> dependentInvariant) {
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
            if(dependentInvariantsOfState.contains("_check_inv_2")) {
                if(!state._check_inv_2()) {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2());
    }

    private static void printResult(int states, int transitions, boolean deadlockDetected, boolean invariantViolated, List<Lift_MC_Large> counterExampleState, Map<Lift_MC_Large, Lift_MC_Large> parents, Map<Lift_MC_Large, String> stateAccessedVia) {

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
                Lift_MC_Large currentState = counterExampleState.get(0);
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

    private static Lift_MC_Large next(LinkedList<Lift_MC_Large> collection, Object lock, Type type) {
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

        Lift_MC_Large machine = new Lift_MC_Large();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);

        Set<Lift_MC_Large> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<Lift_MC_Large> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<Lift_MC_Large, Set<String>> dependentInvariant = new HashMap<>();
        Map<Lift_MC_Large, Set<String>> dependentGuard = new HashMap<>();
        Map<Lift_MC_Large, PersistentHashMap> guardCache = new HashMap<>();
        Map<Lift_MC_Large, Lift_MC_Large> parents = new HashMap<>();
        Map<Lift_MC_Large, String> stateAccessedVia = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("dec", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_1")));
            invariantDependency.put("inc", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_1")));
            guardDependency.put("dec", new HashSet<>(Arrays.asList("_tr_dec", "_tr_inc")));
            guardDependency.put("inc", new HashSet<>(Arrays.asList("_tr_dec", "_tr_inc")));
            dependentInvariant.put(machine, new HashSet<>());
        }
        List<Lift_MC_Large> counterExampleState = new ArrayList<>();
        parents.put(machine, null);

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            Lift_MC_Large state = next(collection, lock, type);

            Set<Lift_MC_Large> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);

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

        Lift_MC_Large machine = new Lift_MC_Large();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);
        AtomicInteger possibleQueueChanges = new AtomicInteger(0);

        Set<Lift_MC_Large> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<Lift_MC_Large> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<Lift_MC_Large, Set<String>> dependentInvariant = new HashMap<>();
        Map<Lift_MC_Large, Set<String>> dependentGuard = new HashMap<>();
        Map<Lift_MC_Large, PersistentHashMap> guardCache = new HashMap<>();
        Map<Lift_MC_Large, Lift_MC_Large> parents = new HashMap<>();
        Map<Lift_MC_Large, String> stateAccessedVia = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("dec", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_1")));
            invariantDependency.put("inc", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_1")));
            guardDependency.put("dec", new HashSet<>(Arrays.asList("_tr_dec", "_tr_inc")));
            guardDependency.put("inc", new HashSet<>(Arrays.asList("_tr_dec", "_tr_inc")));
            dependentInvariant.put(machine, new HashSet<>());
        }
        List<Lift_MC_Large> counterExampleState = new ArrayList<>();
        parents.put(machine, null);
        stateAccessedVia.put(machine, null);

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            possibleQueueChanges.incrementAndGet();
            Lift_MC_Large state = next(collection, lock, type);
            Runnable task = () -> {
                Set<Lift_MC_Large> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);

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
