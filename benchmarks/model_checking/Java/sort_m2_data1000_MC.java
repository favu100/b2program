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

    @SuppressWarnings("unchecked")
    private static Set<sort_m2_data1000_MC> generateNextStates(Object guardLock, sort_m2_data1000_MC state, boolean isCaching, Map<String, Set<String>> invariantDependency, Map<sort_m2_data1000_MC, Set<String>> dependentInvariant, Map<String, Set<String>> guardDependency, Map<sort_m2_data1000_MC, Set<String>> dependentGuard, Map<sort_m2_data1000_MC, PersistentHashMap> guardCache, Map<sort_m2_data1000_MC, sort_m2_data1000_MC> parents, AtomicInteger transitions) {
        Set<sort_m2_data1000_MC> result = new HashSet<>();
        if(isCaching) {
            PersistentHashMap parentsGuard = guardCache.get(parents.get(state));
            PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
            Set<String> dependentGuardsOfState = dependentGuard.get(state);
            Object cachedValue = null;
            boolean dependentGuardsBoolean = true;
            boolean _trid_1;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_progress");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_progress");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_progress();
            } else {
                _trid_1 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_progress", _trid_1);
            if(_trid_1) {
                sort_m2_data1000_MC copiedState = state._copy();
                copiedState.progress();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("progress"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("progress"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_2;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_prog1");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_prog1");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_prog1();
            } else {
                _trid_2 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_prog1", _trid_2);
            if(_trid_2) {
                sort_m2_data1000_MC copiedState = state._copy();
                copiedState.prog1();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("prog1"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("prog1"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_3;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_prog2");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_prog2");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_prog2();
            } else {
                _trid_3 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_prog2", _trid_3);
            if(_trid_3) {
                sort_m2_data1000_MC copiedState = state._copy();
                copiedState.prog2();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("prog2"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("prog2"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            boolean _trid_4;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_final_evt");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_final_evt");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_final_evt();
            } else {
                _trid_4 = (boolean) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_final_evt", _trid_4);
            if(_trid_4) {
                sort_m2_data1000_MC copiedState = state._copy();
                copiedState.final_evt();
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("final_evt"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("final_evt"));
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
            if(state._tr_progress()) {
                sort_m2_data1000_MC copiedState = state._copy();
                copiedState.progress();
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_prog1()) {
                sort_m2_data1000_MC copiedState = state._copy();
                copiedState.prog1();
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_prog2()) {
                sort_m2_data1000_MC copiedState = state._copy();
                copiedState.prog2();
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            if(state._tr_final_evt()) {
                sort_m2_data1000_MC copiedState = state._copy();
                copiedState.final_evt();
                result.add(copiedState);
                transitions.getAndIncrement();
            }

        }
        return result;
    }


    public static boolean checkInvariants(Object guardLock, sort_m2_data1000_MC state, boolean isCaching, Map<sort_m2_data1000_MC, Set<String>> dependentInvariant) {
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
            if(dependentInvariantsOfState.contains("_check_inv_3")) {
                if(!state._check_inv_3()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_4")) {
                if(!state._check_inv_4()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_5")) {
                if(!state._check_inv_5()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_6")) {
                if(!state._check_inv_6()) {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6());
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

    private static sort_m2_data1000_MC next(LinkedList<sort_m2_data1000_MC> collection, Object lock, Type type) {
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

        sort_m2_data1000_MC machine = new sort_m2_data1000_MC();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);

        Set<sort_m2_data1000_MC> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<sort_m2_data1000_MC> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<sort_m2_data1000_MC, Set<String>> dependentInvariant = new HashMap<>();
        Map<sort_m2_data1000_MC, Set<String>> dependentGuard = new HashMap<>();
        Map<sort_m2_data1000_MC, PersistentHashMap> guardCache = new HashMap<>();
        Map<sort_m2_data1000_MC, sort_m2_data1000_MC> parents = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("prog2", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5")));
            invariantDependency.put("prog1", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5")));
            invariantDependency.put("progress", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5")));
            invariantDependency.put("final_evt", new HashSet<>(Arrays.asList()));
            guardDependency.put("prog2", new HashSet<>(Arrays.asList("_tr_progress", "_tr_prog1", "_tr_prog2")));
            guardDependency.put("prog1", new HashSet<>(Arrays.asList("_tr_progress", "_tr_prog1", "_tr_prog2")));
            guardDependency.put("progress", new HashSet<>(Arrays.asList("_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2")));
            guardDependency.put("final_evt", new HashSet<>(Arrays.asList()));
            dependentInvariant.put(machine, new HashSet<>());
            parents.put(machine, null);
        }

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            sort_m2_data1000_MC state = next(collection, lock, type);

            Set<sort_m2_data1000_MC> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);

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

            if(!checkInvariants(guardLock, state, isCaching, dependentInvariant)) {
                invariantViolated.set(true);
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

        sort_m2_data1000_MC machine = new sort_m2_data1000_MC();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);
        AtomicInteger possibleQueueChanges = new AtomicInteger(0);

        Set<sort_m2_data1000_MC> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<sort_m2_data1000_MC> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<sort_m2_data1000_MC, Set<String>> dependentInvariant = new HashMap<>();
        Map<sort_m2_data1000_MC, Set<String>> dependentGuard = new HashMap<>();
        Map<sort_m2_data1000_MC, PersistentHashMap> guardCache = new HashMap<>();
        Map<sort_m2_data1000_MC, sort_m2_data1000_MC> parents = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("prog2", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5")));
            invariantDependency.put("prog1", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5")));
            invariantDependency.put("progress", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5")));
            invariantDependency.put("final_evt", new HashSet<>(Arrays.asList()));
            guardDependency.put("prog2", new HashSet<>(Arrays.asList("_tr_progress", "_tr_prog1", "_tr_prog2")));
            guardDependency.put("prog1", new HashSet<>(Arrays.asList("_tr_progress", "_tr_prog1", "_tr_prog2")));
            guardDependency.put("progress", new HashSet<>(Arrays.asList("_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2")));
            guardDependency.put("final_evt", new HashSet<>(Arrays.asList()));
            dependentInvariant.put(machine, new HashSet<>());
            parents.put(machine, null);
        }

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            possibleQueueChanges.incrementAndGet();
            sort_m2_data1000_MC state = next(collection, lock, type);
            Runnable task = () -> {
                Set<sort_m2_data1000_MC> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);

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
