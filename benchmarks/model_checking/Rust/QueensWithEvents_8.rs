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
use btypes::brelation::BRelation;
use btypes::bset::BSet;
use btypes::btuple::BTuple;

#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }



#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct QueensWithEvents_8 {
    queens: BRelation<BInteger, BInteger>,
    n: BInteger,
    interval: BSet<BInteger>,
    allFields: BSet<BRelation<BInteger, BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_Solve: Option<BSet<BRelation<BInteger, BInteger>>>,}

impl QueensWithEvents_8 {

    pub fn new() -> QueensWithEvents_8 {
        //values: ''
        let mut m: QueensWithEvents_8 = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.n = BInteger::new(4);
        self.interval = BSet::<BInteger>::interval(&BInteger::new(1), &self.n);
        self.allFields = BRelation::cartesianProduct(&self.interval, &self.interval).pow();
        self.queens = BRelation::new(vec![]).clone().clone();
    }

    pub fn get_n(&self) -> BInteger {
        return self.n.clone();
    }

    pub fn get_interval(&self) -> BSet<BInteger> {
        return self.interval.clone();
    }

    pub fn get_allFields(&self) -> BSet<BRelation<BInteger, BInteger>> {
        return self.allFields.clone();
    }

    pub fn get_queens(&self) -> BRelation<BInteger, BInteger> {
        return self.queens.clone();
    }

    pub fn Solve(&mut self, mut solution: BRelation<BInteger, BInteger>) -> () {
        //quantified_predicate
        let mut _ic_boolean_1 = BBoolean::new(true);
        if solution.domain().equal(&self.interval).and(&solution.range().equal(&self.interval)).booleanValue() {
            for _ic_x_1 in self.interval.clone().iter().cloned() {
                for _ic_y_1 in self.interval.clone().iter().cloned() {
                    //quantified_predicate
                    let mut _ic_boolean_0 = BBoolean::new(true);
                    for _ic_z_1 in self.interval.clone().iter().cloned() {
                        if !(solution.elementOf(&BTuple::from_refs(&_ic_x_1, &_ic_z_1)).implies(&_ic_y_1.equal(&_ic_z_1))).booleanValue() {
                            _ic_boolean_0 = BBoolean::new(false);
                            break;
                        }

                    }

                    if !(solution.elementOf(&BTuple::from_refs(&_ic_x_1, &_ic_y_1)).implies(&_ic_boolean_0)).booleanValue() {
                        _ic_boolean_1 = BBoolean::new(false);
                        break;
                    }

                }
            }
        }

        //quantified_predicate
        let mut _ic_boolean_2 = BBoolean::new(true);
        if solution.domain().equal(&self.interval).and(&solution.range().equal(&self.interval)).and(&_ic_boolean_1).booleanValue() {
            for _ic_q1_1 in self.interval.clone().iter().cloned() {
                for _ic_q2_1 in self.interval.difference(&BSet::new(vec![BInteger::new(1)])).clone().iter().cloned() {
                    if !(_ic_q2_1.greater(&_ic_q1_1).implies(&solution.functionCall(&_ic_q1_1).plus(&_ic_q2_1).minus(&_ic_q1_1).unequal(&solution.functionCall(&_ic_q2_1)).and(&solution.functionCall(&_ic_q1_1).minus(&_ic_q2_1).plus(&_ic_q1_1).unequal(&solution.functionCall(&_ic_q2_1))))).booleanValue() {
                        _ic_boolean_2 = BBoolean::new(false);
                        break;
                    }

                }
            }
        }

        //quantified_predicate
        let mut _ic_boolean_3 = BBoolean::new(true);
        if solution.domain().equal(&self.interval).and(&solution.range().equal(&self.interval)).and(&_ic_boolean_1).and(&_ic_boolean_2).booleanValue() {
            for _ic_x_1 in self.queens.domain().clone().iter().cloned() {
                if !(solution.functionCall(&_ic_x_1).equal(&self.queens.functionCall(&_ic_x_1))).booleanValue() {
                    _ic_boolean_3 = BBoolean::new(false);
                    break;
                }

            }
        }

        if (self.allFields.elementOf(&solution).and(&solution.domain().equal(&self.interval)).and(&solution.range().equal(&self.interval)).and(&_ic_boolean_1).and(&_ic_boolean_2).and(&_ic_boolean_3)).booleanValue() {
            self.queens = solution.clone().clone();
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn _tr_Solve(&mut self, is_caching: bool) -> BSet<BRelation<BInteger, BInteger>> {
        //transition
        if !is_caching || self._tr_cache_Solve.is_none() {
            let mut _ic_set_4: BSet<BRelation<BInteger, BInteger>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_solution_1 in self.allFields.clone().iter().cloned() {
                //quantified_predicate
                let mut _ic_boolean_5 = BBoolean::new(true);
                if _ic_solution_1.domain().equal(&self.interval).and(&_ic_solution_1.range().equal(&self.interval)).booleanValue() {
                    for _ic_x_1 in self.interval.clone().iter().cloned() {
                        for _ic_y_1 in self.interval.clone().iter().cloned() {
                            //quantified_predicate
                            let mut _ic_boolean_4 = BBoolean::new(true);
                            for _ic_z_1 in self.interval.clone().iter().cloned() {
                                if !(_ic_solution_1.elementOf(&BTuple::from_refs(&_ic_x_1, &_ic_z_1)).implies(&_ic_y_1.equal(&_ic_z_1))).booleanValue() {
                                    _ic_boolean_4 = BBoolean::new(false);
                                    break;
                                }

                            }

                            if !(_ic_solution_1.elementOf(&BTuple::from_refs(&_ic_x_1, &_ic_y_1)).implies(&_ic_boolean_4)).booleanValue() {
                                _ic_boolean_5 = BBoolean::new(false);
                                break;
                            }

                        }
                    }
                }
                //quantified_predicate
                let mut _ic_boolean_6 = BBoolean::new(true);
                if _ic_solution_1.domain().equal(&self.interval).and(&_ic_solution_1.range().equal(&self.interval)).and(&_ic_boolean_5).booleanValue() {
                    for _ic_q1_1 in self.interval.clone().iter().cloned() {
                        for _ic_q2_1 in self.interval.difference(&BSet::new(vec![BInteger::new(1)])).clone().iter().cloned() {
                            if !(_ic_q2_1.greater(&_ic_q1_1).implies(&_ic_solution_1.functionCall(&_ic_q1_1).plus(&_ic_q2_1).minus(&_ic_q1_1).unequal(&_ic_solution_1.functionCall(&_ic_q2_1)).and(&_ic_solution_1.functionCall(&_ic_q1_1).minus(&_ic_q2_1).plus(&_ic_q1_1).unequal(&_ic_solution_1.functionCall(&_ic_q2_1))))).booleanValue() {
                                _ic_boolean_6 = BBoolean::new(false);
                                break;
                            }

                        }
                    }
                }
                //quantified_predicate
                let mut _ic_boolean_7 = BBoolean::new(true);
                if _ic_solution_1.domain().equal(&self.interval).and(&_ic_solution_1.range().equal(&self.interval)).and(&_ic_boolean_5).and(&_ic_boolean_6).booleanValue() {
                    for _ic_x_1 in self.queens.domain().clone().iter().cloned() {
                        if !(_ic_solution_1.functionCall(&_ic_x_1).equal(&self.queens.functionCall(&_ic_x_1))).booleanValue() {
                            _ic_boolean_7 = BBoolean::new(false);
                            break;
                        }

                    }
                }

                if (_ic_solution_1.domain().equal(&self.interval).and(&_ic_solution_1.range().equal(&self.interval)).and(&_ic_boolean_5).and(&_ic_boolean_6).and(&_ic_boolean_7)).booleanValue() {
                    _ic_set_4 = _ic_set_4._union(&BSet::new(vec![_ic_solution_1]));
                }

            }
            self._tr_cache_Solve = Option::Some(_ic_set_4.clone());
            return _ic_set_4;
        } else {
            return self._tr_cache_Solve.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return self.queens.checkDomain(&self.interval).and(&self.queens.checkRange(&self.interval)).and(&self.queens.isFunction()).and(&self.queens.isPartial(&self.interval)).booleanValue();
    }

    fn invalidate_caches(&mut self, to_invalidate: &HashSet<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        //if caching is enabled globally, this will just prefill those, if caching is
        for trans in to_invalidate.iter() {
            match *trans {
                "_tr_Solve" => {self._tr_Solve(false);},
                _ => {},
            }
        }
    }

    //model_check_next_states
    fn generateNextStates(state: &mut QueensWithEvents_8,
                          isCaching: bool,
                          invariant_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_invariant_m: Arc<Mutex<HashMap<QueensWithEvents_8, HashSet<&str>>>>,
                          guard_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_guard_m: Arc<Mutex<HashMap<QueensWithEvents_8, HashSet<&str>>>>,
                          guardCache: Arc<Mutex<HashMap<QueensWithEvents_8, PersistentHashMap<&str, bool>>>>,
                          parents_m: Arc<Mutex<HashMap<QueensWithEvents_8, QueensWithEvents_8>>>,
                          transitions: Arc<AtomicI64>) -> HashSet<QueensWithEvents_8> {
        let mut result = HashSet::<QueensWithEvents_8>::new();
        if isCaching {
            let mut parents_guard_o = parents_m.lock().unwrap().get(state).and_then(|p| guardCache.lock().unwrap().get(p).cloned());
            let mut newCache = if parents_guard_o.is_none() { PersistentHashMap::new() } else { parents_guard_o.as_ref().unwrap().clone() };
            //model_check_transition
            let mut _trid_1 = state._tr_Solve(isCaching);
            for param in _trid_1.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.Solve(_tmp_1);
                match guard_dependency.get("Solve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("Solve").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("Solve").unwrap().clone());
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
            let mut _trid_1 = state._tr_Solve(isCaching);
            for param in _trid_1.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.Solve(_tmp_1);
                match guard_dependency.get("Solve") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

        }
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &QueensWithEvents_8,
                           isCaching: bool,
                           dependent_invariant_m: Arc<Mutex<HashMap<QueensWithEvents_8, HashSet<&str>>>> ) -> bool {
        let cached_invariants = dependent_invariant_m.lock().unwrap().get(&state).cloned();
        if cached_invariants.is_some() && isCaching {
            let dependent_invariants_of_state = cached_invariants.unwrap().clone();
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_1") {
                if !state._check_inv_1() {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1());
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
    fn next(collection_m: Arc<Mutex<LinkedList<QueensWithEvents_8>>>, mc_type: MC_TYPE) -> QueensWithEvents_8 {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
            MC_TYPE::BFS   => collection.pop_front().unwrap(),
            MC_TYPE::DFS   => collection.pop_back().unwrap(),
            MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
        };
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = QueensWithEvents_8::new();

        let invariant_violated = AtomicBool::new(false);
        let deadlock_detected = AtomicBool::new(false);
        let stop_threads = AtomicBool::new(false);

        if !machine._check_inv_1() {
            invariant_violated.store(true, Ordering::Release);
        }

        let mut states = HashSet::<QueensWithEvents_8>::new();
        states.insert(machine.clone());
        let number_states = AtomicI64::new(1);

        let collection_m = Arc::new(Mutex::new(LinkedList::<QueensWithEvents_8>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<QueensWithEvents_8, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<QueensWithEvents_8, HashSet<&str>>::new()));
        let mut guard_cache = Arc::new(Mutex::new(HashMap::<QueensWithEvents_8, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<QueensWithEvents_8, QueensWithEvents_8>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("Solve", HashSet::from(["_check_inv_1"]));
            //model_check_init_static
            guardDependency.insert("Solve", HashSet::from(["_tr_Solve"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let transitions = Arc::new(AtomicI64::new(0));

        while !stop_threads.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, &mut invariantDependency, Arc::clone(&dependent_invariant_m), &mut guardDependency, Arc::clone(&dependent_guard_m), Arc::clone(&guard_cache), Arc::clone(&parents_m), Arc::clone(&transitions));

            next_states.iter().cloned().for_each(|next_state| {
                if !states.contains(&next_state) {
                    let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                    states.insert(next_state.clone());
                    collection_m.lock().unwrap().push_back(next_state);
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

        let machine = QueensWithEvents_8::new();


        let invariant_violated_b = Arc::new(AtomicBool::new(false));
        let deadlock_detected_b = Arc::new(AtomicBool::new(false));
        let stop_threads_b = Arc::new(AtomicBool::new(false));
        let possible_queue_changes_b = Arc::new(AtomicI32::new(0));

        if !machine._check_inv_1() {
            invariant_violated_b.store(true, Ordering::Release);
        }

        let states_m = Arc::new(Mutex::new(HashSet::<QueensWithEvents_8>::new()));
        states_m.lock().unwrap().insert(machine.clone());
        let number_states_arc = Arc::new(AtomicI64::new(1));

        let collection_m = Arc::new(Mutex::new(LinkedList::<QueensWithEvents_8>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<QueensWithEvents_8, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<QueensWithEvents_8, HashSet<&str>>::new()));
        let mut guard_cache_b = Arc::new(Mutex::new(HashMap::<QueensWithEvents_8, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<QueensWithEvents_8, QueensWithEvents_8>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("Solve", HashSet::from(["_check_inv_1"]));
            //model_check_init_static
            guardDependency.insert("Solve", HashSet::from(["_tr_Solve"]));
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
                next_states.iter().cloned().for_each(|next_state| {
                    {
                        let mut states = states_m2.lock().unwrap();
                        let mut collection = collection_m2.lock().unwrap();
                        if !states.contains(&next_state) {
                            let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                            states.insert(next_state.clone());
                            collection.push_back(next_state);
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
        QueensWithEvents_8::model_check_single_threaded(mc_type, is_caching);
    } else {
        QueensWithEvents_8::modelCheckMultiThreaded(mc_type, threads, is_caching);
    }
}
