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
use btypes::bboolean::IntoBool;
use btypes::binteger::BInteger;
use btypes::bboolean::BBoolean;
use btypes::brelation::BRelation;
use btypes::bset::BSet;
use btypes::btuple::BTuple;

#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }



#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct sort_m2_data1000_MC {
    j: BInteger,
    k: BInteger,
    l: BInteger,
    g: BRelation<BInteger, BInteger>,
    n: BInteger,
    f: BRelation<BInteger, BInteger>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_progress: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_prog1: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_prog2: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_final_evt: Option<bool>,}

impl sort_m2_data1000_MC {

    pub fn new() -> sort_m2_data1000_MC {
        //values: ''
        let mut m: sort_m2_data1000_MC = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.n = BInteger::new(300);
        let mut _ic_set_0 = BRelation::<BInteger, BInteger>::new(vec![]);
        for _ic_i_1 in BSet::<BInteger>::interval(&BInteger::new(1), &self.n).clone().iter().cloned() {
            _ic_set_0 = _ic_set_0._union(&BRelation::<BInteger, BInteger>::new(vec![BTuple::new(_ic_i_1, BInteger::new(15000).minus(&_ic_i_1))]));

        }
        self.f = _ic_set_0;
        self.g = self.f.clone().clone();
        self.k = BInteger::new(1);
        self.l = BInteger::new(1);
        self.j = BInteger::new(1);
    }

    pub fn get_n(&self) -> BInteger {
        return self.n.clone();
    }

    pub fn get_f(&self) -> BRelation<BInteger, BInteger> {
        return self.f.clone();
    }

    pub fn get_j(&self) -> BInteger {
        return self.j.clone();
    }

    pub fn get_k(&self) -> BInteger {
        return self.k.clone();
    }

    pub fn get_l(&self) -> BInteger {
        return self.l.clone();
    }

    pub fn get_g(&self) -> BRelation<BInteger, BInteger> {
        return self.g.clone();
    }

    pub fn progress(&mut self) -> () {
        if (self.k.unequal(&self.n).booleanValue() && self.j.equal(&self.n).booleanValue()).booleanValue() {
            let mut _ld_g = self.g.clone();
            let mut _ld_k = self.k.clone();
            let mut _ld_l = self.l.clone();
            self.g = _ld_g._override(&BRelation::new(vec![BTuple::from_refs(&_ld_k, &_ld_g.functionCall(&_ld_l))])._override(&BRelation::new(vec![BTuple::from_refs(&_ld_l, &_ld_g.functionCall(&_ld_k))]))).clone().clone();
            self.k = _ld_k.plus(&BInteger::new(1));
            self.j = _ld_k.plus(&BInteger::new(1));
            self.l = _ld_k.plus(&BInteger::new(1));
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn prog1(&mut self) -> () {
        if (self.k.unequal(&self.n).booleanValue() && self.j.unequal(&self.n).booleanValue().booleanValue() && self.g.functionCall(&self.l).lessEqual(&self.g.functionCall(&self.j.plus(&BInteger::new(1)))).booleanValue()).booleanValue() {
            let mut _ld_j = self.j.clone();
            let mut _ld_l = self.l.clone();
            self.l = _ld_l;
            self.j = _ld_j.plus(&BInteger::new(1));
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn prog2(&mut self) -> () {
        if (self.k.unequal(&self.n).booleanValue() && self.j.unequal(&self.n).booleanValue().booleanValue() && self.g.functionCall(&self.l).greater(&self.g.functionCall(&self.j.plus(&BInteger::new(1)))).booleanValue()).booleanValue() {
            let mut _ld_j = self.j.clone();
            self.j = _ld_j.plus(&BInteger::new(1));
            self.l = _ld_j.plus(&BInteger::new(1));
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn final_evt(&mut self) -> () {
        if (self.k.equal(&self.n)).booleanValue() {
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn _tr_progress(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_progress.is_none() {
            let mut __tmp__val__ = self.k.unequal(&self.n).booleanValue() && self.j.equal(&self.n).booleanValue().booleanValue();
            self._tr_cache_progress = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_progress.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_prog1(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_prog1.is_none() {
            let mut __tmp__val__ = self.k.unequal(&self.n).booleanValue() && self.j.unequal(&self.n).booleanValue().booleanValue() && self.g.functionCall(&self.l).lessEqual(&self.g.functionCall(&self.j.plus(&BInteger::new(1)))).booleanValue().booleanValue();
            self._tr_cache_prog1 = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_prog1.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_prog2(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_prog2.is_none() {
            let mut __tmp__val__ = self.k.unequal(&self.n).booleanValue() && self.j.unequal(&self.n).booleanValue().booleanValue() && self.g.functionCall(&self.l).greater(&self.g.functionCall(&self.j.plus(&BInteger::new(1)))).booleanValue().booleanValue();
            self._tr_cache_prog2 = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_prog2.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_final_evt(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_final_evt.is_none() {
            let mut __tmp__val__ = self.k.equal(&self.n).booleanValue();
            self._tr_cache_final_evt = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_final_evt.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return self.j.greaterEqual(&self.k).booleanValue();
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        return self.j.lessEqual(&self.n).booleanValue();
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        return self.l.greaterEqual(&self.k).booleanValue();
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        return self.j.lessEqual(&self.j).booleanValue();
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return self.g.functionCall(&self.l).equal(&self.g.relationImage(&BSet::<BInteger>::interval(&self.k, &self.j))._min()).booleanValue();
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        return self.g.checkDomain(&BSet::<BInteger>::interval(&BInteger::new(1), &self.n)).and(&self.g.checkRangeNatural()).and(&self.g.isFunction()).and(&self.g.isTotal(&BSet::<BInteger>::interval(&BInteger::new(1), &self.n))).booleanValue();
    }

    fn invalidate_caches(&mut self, to_invalidate: &HashSet<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        //if caching is enabled globally, this will just prefill those, if caching is
        for trans in to_invalidate.iter() {
            match *trans {
                "_tr_progress" => {self._tr_progress(false);},
                "_tr_prog1" => {self._tr_prog1(false);},
                "_tr_prog2" => {self._tr_prog2(false);},
                "_tr_final_evt" => {self._tr_final_evt(false);},
                _ => {},
            }
        }
    }

    //model_check_next_states
    fn generateNextStates(state: &mut sort_m2_data1000_MC,
                          isCaching: bool,
                          invariant_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_invariant_m: Arc<Mutex<HashMap<sort_m2_data1000_MC, HashSet<&str>>>>,
                          guard_dependency: &HashMap<&str, HashSet<&'static str>>,
                          transitions: Arc<AtomicI64>) -> HashSet<sort_m2_data1000_MC> {
        let mut result = HashSet::<sort_m2_data1000_MC>::new();
        if isCaching {
            //model_check_transition
            let mut _trid_1 = state._tr_progress(isCaching);
            if _trid_1 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.progress();
                match guard_dependency.get("progress") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("progress").unwrap().clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_2 = state._tr_prog1(isCaching);
            if _trid_2 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.prog1();
                match guard_dependency.get("prog1") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("prog1").unwrap().clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_3 = state._tr_prog2(isCaching);
            if _trid_3 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.prog2();
                match guard_dependency.get("prog2") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("prog2").unwrap().clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_4 = state._tr_final_evt(isCaching);
            if _trid_4 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.final_evt();
                match guard_dependency.get("final_evt") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("final_evt").unwrap().clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
        } else {
            //model_check_transition
            if state._tr_progress(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.progress();
                match guard_dependency.get("progress") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_prog1(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.prog1();
                match guard_dependency.get("prog1") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_prog2(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.prog2();
                match guard_dependency.get("prog2") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_final_evt(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.final_evt();
                match guard_dependency.get("final_evt") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

        }
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &sort_m2_data1000_MC,
                           isCaching: bool,
                           dependent_invariant_m: Arc<Mutex<HashMap<sort_m2_data1000_MC, HashSet<&str>>>> ) -> bool
    {
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
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_3") {
                if !state._check_inv_3() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_4") {
                if !state._check_inv_4() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_5") {
                if !state._check_inv_5() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_6") {
                if !state._check_inv_6() {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6());
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
    fn next(collection_m: Arc<Mutex<LinkedList<sort_m2_data1000_MC>>>, mc_type: MC_TYPE) -> sort_m2_data1000_MC {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
            MC_TYPE::BFS   => collection.pop_front().unwrap(),
            MC_TYPE::DFS   => collection.pop_back().unwrap(),
            MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
        };
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = sort_m2_data1000_MC::new();

        let invariant_violated = AtomicBool::new(false);
        let deadlock_detected = AtomicBool::new(false);
        let stop_threads = AtomicBool::new(false);

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() {
            invariant_violated.store(true, Ordering::Release);
        }

        let mut states = HashSet::<sort_m2_data1000_MC>::new();
        states.insert(machine.clone());
        let number_states = AtomicI64::new(1);

        let collection_m = Arc::new(Mutex::new(LinkedList::<sort_m2_data1000_MC>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<sort_m2_data1000_MC, HashSet<&str>>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("prog2", HashSet::from(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("prog1", HashSet::from(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("progress", HashSet::from(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("final_evt", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("prog2", HashSet::from(["_tr_progress", "_tr_prog1", "_tr_prog2"]));
            //model_check_init_static
            guardDependency.insert("prog1", HashSet::from(["_tr_progress", "_tr_prog1", "_tr_prog2"]));
            //model_check_init_static
            guardDependency.insert("progress", HashSet::from(["_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2"]));
            //model_check_init_static
            guardDependency.insert("final_evt", HashSet::from([]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
        }

        let transitions = Arc::new(AtomicI64::new(0));

        while !stop_threads.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, &mut invariantDependency, Arc::clone(&dependent_invariant_m), &mut guardDependency, Arc::clone(&transitions));

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

        let machine = sort_m2_data1000_MC::new();


        let invariant_violated_b = Arc::new(AtomicBool::new(false));
        let deadlock_detected_b = Arc::new(AtomicBool::new(false));
        let stop_threads_b = Arc::new(AtomicBool::new(false));
        let possible_queue_changes_b = Arc::new(AtomicI32::new(0));

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() {
            invariant_violated_b.store(true, Ordering::Release);
        }

        let states_m = Arc::new(Mutex::new(HashSet::<sort_m2_data1000_MC>::new()));
        states_m.lock().unwrap().insert(machine.clone());
        let number_states_arc = Arc::new(AtomicI64::new(1));

        let collection_m = Arc::new(Mutex::new(LinkedList::<sort_m2_data1000_MC>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<sort_m2_data1000_MC, HashSet<&str>>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("prog2", HashSet::from(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("prog1", HashSet::from(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("progress", HashSet::from(["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5"]));
            //model_check_init_static
            invariantDependency.insert("final_evt", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("prog2", HashSet::from(["_tr_progress", "_tr_prog1", "_tr_prog2"]));
            //model_check_init_static
            guardDependency.insert("prog1", HashSet::from(["_tr_progress", "_tr_prog1", "_tr_prog2"]));
            //model_check_init_static
            guardDependency.insert("progress", HashSet::from(["_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2"]));
            //model_check_init_static
            guardDependency.insert("final_evt", HashSet::from([]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
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
            let transitions = Arc::clone(&num_transitions);
            let states_m2 = Arc::clone(&states_m);
            let number_states = Arc::clone(&number_states_arc);
            let tx = tx.clone();
            //println!("Thread {:?} spawning a thread", thread::current().id());
            threadPool.execute(move|| {
                let next_states = Self::generateNextStates(&mut state, is_caching, &invariant_dependency, Arc::clone(&dependent_invariant_m2), &guard_dependency, Arc::clone(&transitions));

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
        sort_m2_data1000_MC::model_check_single_threaded(mc_type, is_caching);
    } else {
        sort_m2_data1000_MC::modelCheckMultiThreaded(mc_type, threads, is_caching);
    }
}
