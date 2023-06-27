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
import de.hhu.stups.btypes.BUtils;


public class sort_m2_data1000_MC {


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

    public sort_m2_data1000_MC parent;
    public Set<String> dependentGuard = new HashSet<>();
    public PersistentHashMap guardCache = PersistentHashMap.EMPTY;
    public Set<String> dependentInvariant = new HashSet<>();
    public String stateAccessedVia;



    private static BInteger n;
    private static BRelation<BInteger, BInteger> f;




    private BInteger j;
    private BInteger k;
    private BInteger l;
    private BRelation<BInteger, BInteger> g;

    static {
        n = new BInteger(1000);
        BRelation<BInteger, BInteger> _ic_set_0 = new BRelation<BInteger, BInteger>();
        for(BInteger _ic_i_1 : BSet.interval(new BInteger(1), n)) {
            _ic_set_0 = _ic_set_0.union(new BRelation<BInteger, BInteger>(new BTuple<>(_ic_i_1, new BInteger(15000).minus(_ic_i_1))));

        }
        f = _ic_set_0;
    }

    public sort_m2_data1000_MC() {
        g = f;
        k = new BInteger(1);
        l = new BInteger(1);
        j = new BInteger(1);
    }


    public sort_m2_data1000_MC(BInteger n, BRelation<BInteger, BInteger> f, BInteger j, BInteger k, BInteger l, BRelation<BInteger, BInteger> g) {
        this.n = n;
        this.f = f;
        this.j = j;
        this.k = k;
        this.l = l;
        this.g = g;
    }


    public void progress() {
        BRelation<BInteger, BInteger> _ld_g = g;
        BInteger _ld_k = k;
        BInteger _ld_l = l;
        g = _ld_g.override(new BRelation<BInteger, BInteger>(new BTuple<>(_ld_k, _ld_g.functionCall(_ld_l))).override(new BRelation<BInteger, BInteger>(new BTuple<>(_ld_l, _ld_g.functionCall(_ld_k)))));
        k = _ld_k.plus(new BInteger(1));
        j = _ld_k.plus(new BInteger(1));
        l = _ld_k.plus(new BInteger(1));

    }

    public void prog1() {
        BInteger _ld_j = j;
        BInteger _ld_l = l;
        l = _ld_l;
        j = _ld_j.plus(new BInteger(1));

    }

    public void prog2() {
        BInteger _ld_j = j;
        j = _ld_j.plus(new BInteger(1));
        l = _ld_j.plus(new BInteger(1));

    }

    public void final_evt() {
    }

    public BInteger _get_n() {
        return n;
    }

    public BRelation<BInteger, BInteger> _get_f() {
        return f;
    }

    public BInteger _get_j() {
        return j;
    }

    public BInteger _get_k() {
        return k;
    }

    public BInteger _get_l() {
        return l;
    }

    public BRelation<BInteger, BInteger> _get_g() {
        return g;
    }


    public boolean _tr_progress() {
        return new BBoolean(k.unequal(n).booleanValue() && j.equal(n).booleanValue()).booleanValue();
    }

    public boolean _tr_prog1() {
        return new BBoolean(new BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue()).booleanValue() && g.functionCall(l).lessEqual(g.functionCall(j.plus(new BInteger(1)))).booleanValue()).booleanValue();
    }

    public boolean _tr_prog2() {
        return new BBoolean(new BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue()).booleanValue() && g.functionCall(l).greater(g.functionCall(j.plus(new BInteger(1)))).booleanValue()).booleanValue();
    }

    public boolean _tr_final_evt() {
        return k.equal(n).booleanValue();
    }

    public boolean _check_inv_1() {
        return j.greaterEqual(k).booleanValue();
    }

    public boolean _check_inv_2() {
        return j.lessEqual(n).booleanValue();
    }

    public boolean _check_inv_3() {
        return l.greaterEqual(k).booleanValue();
    }

    public boolean _check_inv_4() {
        return j.lessEqual(j).booleanValue();
    }

    public boolean _check_inv_5() {
        return g.functionCall(l).equal(g.relationImage(BSet.interval(k, j)).min()).booleanValue();
    }

    public boolean _check_inv_6() {
        return g.checkDomain(BSet.interval(new BInteger(1), n)).and(g.checkRangeNatural()).and(g.isFunction()).and(g.isTotal(BSet.interval(new BInteger(1), n))).booleanValue();
    }

    public sort_m2_data1000_MC _copy() {
        return new sort_m2_data1000_MC(n, f, j, k, l, g);
    }

    @Override
    public boolean equals(Object o) {
        sort_m2_data1000_MC o1 = this;
        sort_m2_data1000_MC o2 = (sort_m2_data1000_MC) o;
        return o1._get_j().equals(o2._get_j()) && o1._get_k().equals(o2._get_k()) && o1._get_l().equals(o2._get_l()) && o1._get_g().equals(o2._get_g());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_j()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_k()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_l()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_g()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_j()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_k()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_l()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_g()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_j: " + (this._get_j()).toString(), "_get_k: " + (this._get_k()).toString(), "_get_l: " + (this._get_l()).toString(), "_get_g: " + (this._get_g()).toString());
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<sort_m2_data1000_MC> unvisitedStates = new LinkedList<>();
        private final Set<sort_m2_data1000_MC> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private sort_m2_data1000_MC counterExampleState = null;

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
            sort_m2_data1000_MC machine = new sort_m2_data1000_MC();
            states.add(machine);
            unvisitedStates.add(machine);

            if(isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.isEmpty()) {
                sort_m2_data1000_MC state = next();

                Set<sort_m2_data1000_MC> nextStates = generateNextStates(state);

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
            sort_m2_data1000_MC machine = new sort_m2_data1000_MC();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            if(isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                sort_m2_data1000_MC state = next();
                Runnable task = () -> {
                    Set<sort_m2_data1000_MC> nextStates = generateNextStates(state);

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

        private void initCache(final sort_m2_data1000_MC machine) {
            invariantDependency.put("prog2", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5")));
            invariantDependency.put("prog1", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5")));
            invariantDependency.put("progress", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5")));
            invariantDependency.put("final_evt", new HashSet<>(Arrays.asList()));
            guardDependency.put("prog2", new HashSet<>(Arrays.asList("_tr_progress", "_tr_prog1", "_tr_prog2")));
            guardDependency.put("prog1", new HashSet<>(Arrays.asList("_tr_progress", "_tr_prog1", "_tr_prog2")));
            guardDependency.put("progress", new HashSet<>(Arrays.asList("_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2")));
            guardDependency.put("final_evt", new HashSet<>(Arrays.asList()));
        }

        private sort_m2_data1000_MC next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<sort_m2_data1000_MC> generateNextStates(final sort_m2_data1000_MC state) {
            Set<sort_m2_data1000_MC> result = new HashSet<>();
            if(isCaching) {
                PersistentHashMap parentsGuard = state.guardCache;
                PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
                Object cachedValue = null;
                boolean dependentGuardsBoolean = true;
                boolean _trid_1;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_progress");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_progress");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_1 = state._tr_progress();
                } else {
                    _trid_1 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_progress", _trid_1);
                if(_trid_1) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.progress();
                    copiedState.parent = state;
                    addCachedInfos("progress", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_2;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_prog1");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_prog1");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_2 = state._tr_prog1();
                } else {
                    _trid_2 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_prog1", _trid_2);
                if(_trid_2) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.prog1();
                    copiedState.parent = state;
                    addCachedInfos("prog1", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_3;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_prog2");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_prog2");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_3 = state._tr_prog2();
                } else {
                    _trid_3 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_prog2", _trid_3);
                if(_trid_3) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.prog2();
                    copiedState.parent = state;
                    addCachedInfos("prog2", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                boolean _trid_4;
                if(!state.dependentGuard.isEmpty()) {
                    cachedValue = GET.invoke(parentsGuard, "_tr_final_evt");
                    dependentGuardsBoolean = state.dependentGuard.contains("_tr_final_evt");
                }

                if(state.dependentGuard.isEmpty() || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                    _trid_4 = state._tr_final_evt();
                } else {
                    _trid_4 = (boolean) cachedValue;
                }

                newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_final_evt", _trid_4);
                if(_trid_4) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.final_evt();
                    copiedState.parent = state;
                    addCachedInfos("final_evt", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

                state.guardCache = newCache;
            } else {
                if(state._tr_progress()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.progress();
                    copiedState.parent = state;
                    addCachedInfos("progress", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_prog1()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.prog1();
                    copiedState.parent = state;
                    addCachedInfos("prog1", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_prog2()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.prog2();
                    copiedState.parent = state;
                    addCachedInfos("prog2", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                if(state._tr_final_evt()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.final_evt();
                    copiedState.parent = state;
                    addCachedInfos("final_evt", state, copiedState);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final sort_m2_data1000_MC state) {
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
            if(!isCaching || state.dependentInvariant.contains("_check_inv_3")) {
                if(!state._check_inv_3()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_4")) {
                if(!state._check_inv_4()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_5")) {
                if(!state._check_inv_5()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
                    return true;
                }
            }
            if(!isCaching || state.dependentInvariant.contains("_check_inv_6")) {
                if(!state._check_inv_6()) {
                    System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
                    return true;
                }
            }
            return false;
        }

        private void addCachedInfos(final String operation, final sort_m2_data1000_MC state, final sort_m2_data1000_MC copiedState) {
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
