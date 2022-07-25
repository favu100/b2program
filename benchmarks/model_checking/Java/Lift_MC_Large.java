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
    public Set<String> dependentGuard = new HashSet<>();
    public PersistentHashMap guardCache = PersistentHashMap.EMPTY;
    public Set<String> dependentInvariant = new HashSet<>();
    public String stateAccessedVia;







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

        private final Map<String, Set<String>> invariantDependency = new HashMap<>();
        private final Map<String, Set<String>> guardDependency = new HashMap<>();

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
            states.add(machine); // TODO: store hashes instead of machine?
            unvisitedStates.add(machine);

            if(isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.isEmpty()) {
                Lift_MC_Large state = next();

                Set<Lift_MC_Large> nextStates = generateNextStates(state);

                nextStates.forEach(nextState -> {
                    if(!states.contains(nextState)) {
                        states.add(nextState);
                        unvisitedStates.add(nextState);
                        if(states.size() % 50000 == 0 && isDebug) {
                            System.out.println("VISITED STATES: " + states.size());
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

            if(isCaching) {
                initCache(machine);
            }

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
                            if(states.size() % 50000 == 0 && isDebug) {
                                System.out.println("VISITED STATES: " + states.size());
                                System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                System.out.println("-------------------");
                            }
                        }
                    });

                    synchronized (unvisitedStates) {
                        int running = possibleQueueChanges.decrementAndGet();
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

        private void initCache(final Lift_MC_Large machine) {
            invariantDependency.put("dec", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_1")));
            invariantDependency.put("inc", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_1")));
            guardDependency.put("dec", new HashSet<>(Arrays.asList("_tr_dec", "_tr_inc")));
            guardDependency.put("inc", new HashSet<>(Arrays.asList("_tr_dec", "_tr_inc")));
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
                PersistentHashMap parentsGuard = state.guardCache;
                PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
                Object cachedValue = null;
                boolean dependentGuardsBoolean = true;
                boolean _trid_1;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_inc");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_inc");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_1 = state._tr_inc();
                } else {
                    _trid_1 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_inc", _trid_1);
                if(_trid_1) {
                    Lift_MC_Large copiedState = state._copy();
                    copiedState.inc();
                    copiedState.parent = state;
                    addCachedInfos("inc", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_2;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_dec");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_dec");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_2 = state._tr_dec();
                } else {
                    _trid_2 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_dec", _trid_2);
                if(_trid_2) {
                    Lift_MC_Large copiedState = state._copy();
                    copiedState.dec();
                    copiedState.parent = state;
                    addCachedInfos("dec", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

                state.guardCache = newCache;
            } else {
                if(state._tr_inc()) {
                    Lift_MC_Large copiedState = state._copy();
                    copiedState.inc();
                    copiedState.parent = state;
                    addCachedInfos("inc", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_dec()) {
                    Lift_MC_Large copiedState = state._copy();
                    copiedState.dec();
                    copiedState.parent = state;
                    addCachedInfos("dec", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final Lift_MC_Large state) {
            if(!isCaching || state.dependentInvariant.contains("_check_inv_1")) {
                if(!state._check_inv_1()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_2")) {
                if(!state._check_inv_2()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
                    return true;
                }
            }
            return false;
        }

        private void addCachedInfos(final String operation, final Lift_MC_Large state, final Lift_MC_Large copiedState) {
            if(isCaching) {
                copiedState.dependentInvariant = invariantDependency.get(operation);
                copiedState.dependentGuard = guardDependency.get(operation);
            }
            copiedState.stateAccessedVia = operation;
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

        ModelChecker modelchecker = new ModelChecker(type, threads, isCaching, isDebug);
        modelchecker.modelCheck();
    }




}
