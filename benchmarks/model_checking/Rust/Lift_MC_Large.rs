#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::env;
use std::sync::atomic::{AtomicI32, AtomicI64, AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use std::collections::{HashMap, HashSet, LinkedList};
use im::HashMap as PersistentHashMap;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
use btypes::btuple::BTuple;

#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }



#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct Lift_MC_Large {
    level: BInteger,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_inc: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_dec: Option<bool>,}

impl Lift_MC_Large {

    pub fn new() -> Lift_MC_Large {
        //values: ''
        let mut m: Lift_MC_Large = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.level = BInteger::new(0);
    }

    pub fn get_level(&self) -> BInteger {
        return self.level.clone();
    }

    pub fn inc(&mut self) -> () {
        //pre_assert
        self.level = self.level.plus(&BInteger::new(1));

    }

    pub fn dec(&mut self) -> () {
        //pre_assert
        self.level = self.level.minus(&BInteger::new(1));

    }

    pub fn _tr_inc(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_inc.is_none() {
            let mut __tmp__val__ = self.level.less(&BInteger::new(1000000)).booleanValue();
            self._tr_cache_inc = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_inc.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_dec(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_dec.is_none() {
            let mut __tmp__val__ = self.level.greater(&BInteger::new(0)).booleanValue();
            self._tr_cache_dec = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_dec.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return self.level.greaterEqual(&BInteger::new(0)).booleanValue();
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        return self.level.lessEqual(&BInteger::new(1000000)).booleanValue();
    }

    fn invalidate_caches(&mut self, to_invalidate: &HashSet<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        //if caching is enabled globally, this will just prefill those, if caching is
        for trans in to_invalidate.iter() {
            match *trans {
                "_tr_inc" => {self._tr_inc(false);}, 
                "_tr_dec" => {self._tr_dec(false);}, 
                _ => {},
            }
        }
    }

    //model_check_next_states
    fn generateNextStates(state: &mut Lift_MC_Large,
                          isCaching: bool,
                          invariant_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_invariant_m: Arc<Mutex<HashMap<Lift_MC_Large, HashSet<&str>>>>,
                          guard_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_guard_m: Arc<Mutex<HashMap<Lift_MC_Large, HashSet<&str>>>>,
                          guardCache: Arc<Mutex<HashMap<Lift_MC_Large, PersistentHashMap<&str, bool>>>>,
                          parents_m: Arc<Mutex<HashMap<Lift_MC_Large, Lift_MC_Large>>>,
                          transitions: Arc<AtomicI64>) -> HashSet<Lift_MC_Large> {
        let mut result = HashSet::<Lift_MC_Large>::new();
        if isCaching {
            let mut parents_guard_o = parents_m.lock().unwrap().get(state).and_then(|p| guardCache.lock().unwrap().get(p).cloned());
            let mut newCache = if parents_guard_o.is_none() { PersistentHashMap::new() } else { parents_guard_o.as_ref().unwrap().clone() };
            //model_check_transition
            let mut _trid_1 = state._tr_inc(isCaching);
            if _trid_1 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.inc();
                match guard_dependency.get("inc") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("inc").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("inc").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_2 = state._tr_dec(isCaching);
            if _trid_2 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.dec();
                match guard_dependency.get("dec") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("dec").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("dec").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

            guardCache.lock().unwrap().insert(state.clone(), newCache);
        } else {
            //model_check_transition
            if state._tr_inc(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.inc();
                match guard_dependency.get("inc") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_dec(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.dec();
                match guard_dependency.get("dec") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

        }
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &Lift_MC_Large,
                           isCaching: bool,
                           dependent_invariant_m: Arc<Mutex<HashMap<Lift_MC_Large, HashSet<&str>>>> ) -> bool {
        let cached_invariants = dependent_invariant_m.lock().unwrap().get(&state).cloned();
        if cached_invariants.is_some() && isCaching {
            let dependent_invariants_of_state = cached_invariants.unwrap().clone();
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_1") {
                if !state._check_inv_1() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_2") {
                if !state._check_inv_2() {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2());
    }

    //model_check_print
    fn print_result(states: i64, transitions: i64, deadlock_detected: bool, invariant_violated: bool) {
        if deadlock_detected { println!("DEADLOCK DETECTED"); }
        if invariant_violated { println!("INVARIANT VIOLATED"); }
        if !deadlock_detected && !invariant_violated { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<Lift_MC_Large>>>, mc_type: MC_TYPE) -> Lift_MC_Large {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
                MC_TYPE::BFS   => collection.pop_front().unwrap(),
                MC_TYPE::DFS   => collection.pop_back().unwrap(),
                MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
            };
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = Lift_MC_Large::new();

        let invariant_violated = AtomicBool::new(false);
        let deadlock_detected = AtomicBool::new(false);
        let stop_threads = AtomicBool::new(false);

        if !machine._check_inv_1() || !machine._check_inv_2() {
            invariant_violated.store(true, Ordering::Release);
        }

        let mut states = HashSet::<Lift_MC_Large>::new();
        states.insert(machine.clone());
        let number_states = AtomicI64::new(1);

        let collection_m = Arc::new(Mutex::new(LinkedList::<Lift_MC_Large>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<Lift_MC_Large, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<Lift_MC_Large, HashSet<&str>>::new()));
        let mut guard_cache = Arc::new(Mutex::new(HashMap::<Lift_MC_Large, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<Lift_MC_Large, Lift_MC_Large>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("dec", HashSet::from(["_check_inv_2", "_check_inv_1"]));
            //model_check_init_static
            invariantDependency.insert("inc", HashSet::from(["_check_inv_2", "_check_inv_1"]));
            //model_check_init_static
            guardDependency.insert("dec", HashSet::from(["_tr_dec", "_tr_inc"]));
            //model_check_init_static
            guardDependency.insert("inc", HashSet::from(["_tr_dec", "_tr_inc"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let transitions = Arc::new(AtomicI64::new(0));

        while !stop_threads.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, &mut invariantDependency, Arc::clone(&dependent_invariant_m), &mut guardDependency, Arc::clone(&dependent_guard_m), Arc::clone(&guard_cache), Arc::clone(&parents_m), Arc::clone(&transitions));

            next_states.iter().for_each(|next_state| {
                if !states.contains(next_state) {
                    let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                    states.insert(next_state.clone());
                    collection_m.lock().unwrap().push_back(next_state.clone());
                    if cnum_states % 50000 == 0 {
                        println!("VISITED STATES: {}", cnum_states);
                        println!("EVALUATED TRANSITIONS: {}", transitions.load(Ordering::Acquire));
                        println!("-------------------");
                    }
                }
            });

            if next_states.is_empty() {
                deadlock_detected.store(true, Ordering::Release);
                stop_threads.store(true, Ordering::Release);
            }

            if !Self::checkInvariants(&state, is_caching, Arc::clone(&dependent_invariant_m)) {
                invariant_violated.store(true, Ordering::Release);
                stop_threads.store(true, Ordering::Release);
            }

        }
        Self::print_result(number_states.load(Ordering::Acquire), transitions.load(Ordering::Acquire), deadlock_detected.load(Ordering::Acquire), invariant_violated.load(Ordering::Acquire));
    }

    fn modelCheckMultiThreaded(mc_type: MC_TYPE, threads: usize, is_caching: bool) {
        let threadPool = ThreadPool::new(threads);

        let machine = Lift_MC_Large::new();


        let invariant_violated_b = Arc::new(AtomicBool::new(false));
        let deadlock_detected_b = Arc::new(AtomicBool::new(false));
        let stop_threads_b = Arc::new(AtomicBool::new(false));
        let possible_queue_changes_b = Arc::new(AtomicI32::new(0));

        if !machine._check_inv_1() || !machine._check_inv_2() {
                invariant_violated_b.store(true, Ordering::Release);
        }

        let states_m = Arc::new(Mutex::new(HashSet::<Lift_MC_Large>::new()));
        states_m.lock().unwrap().insert(machine.clone());
        let number_states_arc = Arc::new(AtomicI64::new(1));

        let collection_m = Arc::new(Mutex::new(LinkedList::<Lift_MC_Large>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<Lift_MC_Large, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<Lift_MC_Large, HashSet<&str>>::new()));
        let mut guard_cache_b = Arc::new(Mutex::new(HashMap::<Lift_MC_Large, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<Lift_MC_Large, Lift_MC_Large>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("dec", HashSet::from(["_check_inv_2", "_check_inv_1"]));
            //model_check_init_static
            invariantDependency.insert("inc", HashSet::from(["_check_inv_2", "_check_inv_1"]));
            //model_check_init_static
            guardDependency.insert("dec", HashSet::from(["_tr_dec", "_tr_inc"]));
            //model_check_init_static
            guardDependency.insert("inc", HashSet::from(["_tr_dec", "_tr_inc"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let num_transitions = Arc::new(AtomicI64::new(0));
        let invariant_dependency_arc = Arc::new(invariantDependency);
        let guard_dependency_arc = Arc::new(guardDependency);

        let (tx, rx) = channel();
        //println!("Thread {:?} starting threads", thread::current().id());
        while !stop_threads_b.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            possible_queue_changes_b.fetch_add(1, Ordering::AcqRel);
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let invariant_violated = Arc::clone(&invariant_violated_b);
            let deadlock_detected = Arc::clone(&deadlock_detected_b);
            let stop_threads = Arc::clone(&stop_threads_b);
            let possible_queue_changes = Arc::clone(&possible_queue_changes_b);
            let collection_m2 = Arc::clone(&collection_m);
            let invariant_dependency = Arc::clone(&invariant_dependency_arc);
            let guard_dependency = Arc::clone(&guard_dependency_arc);
            let dependent_invariant_m2 = Arc::clone(&dependent_invariant_m);
            let dependent_guard_m2 = Arc::clone(&dependent_guard_m);
            let parents_m2 = Arc::clone(&parents_m);
            let guard_cache = Arc::clone(&guard_cache_b);
            let transitions = Arc::clone(&num_transitions);
            let states_m2 = Arc::clone(&states_m);
            let number_states = Arc::clone(&number_states_arc);
            let tx = tx.clone();
            //println!("Thread {:?} spawning a thread", thread::current().id());
            threadPool.execute(move|| {
                let next_states = Self::generateNextStates(&mut state, is_caching, &invariant_dependency, Arc::clone(&dependent_invariant_m2), &guard_dependency, dependent_guard_m2, guard_cache, parents_m2, Arc::clone(&transitions));

                //println!("Thread {:?} executing", thread::current().id());
                next_states.iter().for_each(|next_state| {
                    {
                        let mut states = states_m2.lock().unwrap();
                        let mut collection = collection_m2.lock().unwrap();
                        if !states.contains(next_state) {
                            let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                            states.insert(next_state.clone());
                            collection.push_back(next_state.clone());
                            //println!("Thread {:?}: states in collection {}", thread::current().id(), collection.len());
                            if cnum_states % 50000 == 0 {
                                println!("VISITED STATES: {}", cnum_states);
                                println!("EVALUATED TRANSITIONS: {}", transitions.load(Ordering::Acquire));
                                println!("-------------------");
                            }
                        }
                    }
                });
                possible_queue_changes.fetch_sub(1, Ordering::AcqRel);

                if next_states.is_empty() {
                    deadlock_detected.store(true, Ordering::Release);
                    stop_threads.store(true, Ordering::Release);
                }

                if !Self::checkInvariants(&state, is_caching, Arc::clone(&dependent_invariant_m2)) {
                    invariant_violated.store(true, Ordering::Release);
                    stop_threads.store(true, Ordering::Release);
                }
                //println!("Thread {:?} done", thread::current().id());
                tx.send(1).expect("");
            });
            while collection_m.lock().unwrap().is_empty() && possible_queue_changes_b.load(Ordering::Acquire) > 0 {
                //println!("Thread {:?} (main) waiting for a thread to finish", thread::current().id());
                rx.recv().expect("Waiting for a thread to finish: ");
            }
        }

        Self::print_result(number_states_arc.load(Ordering::Acquire), num_transitions.load(Ordering::Acquire), deadlock_detected_b.load(Ordering::Acquire), invariant_violated_b.load(Ordering::Acquire));
    }

}


fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 4 { panic!("Number of arguments errorneous"); }

    let threads = args.get(2).unwrap().parse::<usize>().unwrap();
    if threads <= 0 { panic!("Input for number of threads is wrong."); }

    let is_caching = args.get(3).unwrap().parse::<bool>().unwrap();
    let mc_type = match args.get(1).unwrap().as_str() {
        "mixed" => MC_TYPE::MIXED,
        "bf" => MC_TYPE::BFS,
        "df" => MC_TYPE::DFS,
        _    => panic!("Input for strategy is wrong.")
    };

    if threads == 1 {
        Lift_MC_Large::model_check_single_threaded(mc_type, is_caching);
    } else {
        Lift_MC_Large::modelCheckMultiThreaded(mc_type, threads, is_caching);
    }
}
