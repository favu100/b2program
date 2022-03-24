#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::env;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, mpsc, Mutex};
use std::collections::{HashSet, LinkedList};
use dashmap::DashSet;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::time::{Duration};
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bboolean::{IntoBool, BBooleanT};
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

impl fmt::Display for sort_m2_data1000_MC {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "sort_m2_data1000_MC: (".to_owned();
        result += &format!("_get_j: {}, ", self._get_j());
        result += &format!("_get_k: {}, ", self._get_k());
        result += &format!("_get_l: {}, ", self._get_l());
        result += &format!("_get_g: {}, ", self._get_g());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl sort_m2_data1000_MC {

    pub fn new() -> sort_m2_data1000_MC {
        //values: ''
        let mut m: sort_m2_data1000_MC = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.n = BInteger::new(1000);
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

    pub fn _get_n(&self) -> BInteger {
        return self.n.clone();
    }

    pub fn _get_f(&self) -> BRelation<BInteger, BInteger> {
        return self.f.clone();
    }

    pub fn _get_j(&self) -> BInteger {
        return self.j.clone();
    }

    pub fn _get_k(&self) -> BInteger {
        return self.k.clone();
    }

    pub fn _get_l(&self) -> BInteger {
        return self.l.clone();
    }

    pub fn _get_g(&self) -> BRelation<BInteger, BInteger> {
        return self.g.clone();
    }

    pub fn progress(&mut self) -> () {
        if ((self.k.unequal(&self.n) && self.j.equal(&self.n))).booleanValue() {
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
        if (((self.k.unequal(&self.n) && self.j.unequal(&self.n)) && self.g.functionCall(&self.l).lessEqual(&self.g.functionCall(&self.j.plus(&BInteger::new(1)))))).booleanValue() {
            let mut _ld_j = self.j.clone();
            let mut _ld_l = self.l.clone();
            self.l = _ld_l;
            self.j = _ld_j.plus(&BInteger::new(1));
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn prog2(&mut self) -> () {
        if (((self.k.unequal(&self.n) && self.j.unequal(&self.n)) && self.g.functionCall(&self.l).greater(&self.g.functionCall(&self.j.plus(&BInteger::new(1)))))).booleanValue() {
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
            let mut __tmp__val__ = (self.k.unequal(&self.n) && self.j.equal(&self.n)).booleanValue();
            self._tr_cache_progress = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_progress.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_prog1(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_prog1.is_none() {
            let mut __tmp__val__ = ((self.k.unequal(&self.n) && self.j.unequal(&self.n)) && self.g.functionCall(&self.l).lessEqual(&self.g.functionCall(&self.j.plus(&BInteger::new(1))))).booleanValue();
            self._tr_cache_prog1 = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_prog1.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_prog2(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_prog2.is_none() {
            let mut __tmp__val__ = ((self.k.unequal(&self.n) && self.j.unequal(&self.n)) && self.g.functionCall(&self.l).greater(&self.g.functionCall(&self.j.plus(&BInteger::new(1))))).booleanValue();
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

    fn invalidate_caches(&mut self, to_invalidate: Vec<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        for trans in to_invalidate {
            match trans {
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
                          transitions: Arc<AtomicU64>) -> HashSet<(sort_m2_data1000_MC, &'static str)> {
        let mut result = HashSet::<(sort_m2_data1000_MC, &'static str)>::new();
        let mut evaluated_transitions: u64 = 0;
        //model_check_transition
        if state._tr_progress(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.progress();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("progress")); }
            result.insert((copiedState, "progress"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_prog1(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.prog1();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("prog1")); }
            result.insert((copiedState, "prog1"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_prog2(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.prog2();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("prog2")); }
            result.insert((copiedState, "prog2"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_final_evt(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.final_evt();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("final_evt")); }
            result.insert((copiedState, "final_evt"));
            evaluated_transitions += 1;
        }


        transitions.fetch_add(evaluated_transitions, Ordering::AcqRel);
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &sort_m2_data1000_MC, last_op: &'static str, isCaching: bool) -> bool {
        if isCaching {
            let dependent_invariants_of_state = Self::get_invariant_dependencies(last_op);
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_1") {
                if !state._check_inv_1() {
                    println!("_check_inv_1 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_2") {
                if !state._check_inv_2() {
                    println!("_check_inv_2 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_3") {
                if !state._check_inv_3() {
                    println!("_check_inv_3 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_4") {
                if !state._check_inv_4() {
                    println!("_check_inv_4 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_5") {
                if !state._check_inv_5() {
                    println!("_check_inv_5 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_6") {
                if !state._check_inv_6() {
                    println!("_check_inv_6 failed!");
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6());
    }

    //model_check_print
    fn print_result(states: usize, transitions: u64, error_detected: bool) {
        if !error_detected { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<(sort_m2_data1000_MC, &'static str)>>>, mc_type: MC_TYPE) -> (sort_m2_data1000_MC, &'static str) {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
            MC_TYPE::BFS   => collection.pop_front().unwrap(),
            MC_TYPE::DFS   => collection.pop_back().unwrap(),
            MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
        };
    }

    fn get_guard_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "prog2" => vec!["_tr_progress", "_tr_prog1", "_tr_prog2"],
            //model_check_init_static
            "prog1" => vec!["_tr_progress", "_tr_prog1", "_tr_prog2"],
            //model_check_init_static
            "progress" => vec!["_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2"],
            //model_check_init_static
            "final_evt" => vec![],
            _ => vec![],
        }
    }

    fn get_invariant_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "prog2" => vec!["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"],
            //model_check_init_static
            "prog1" => vec!["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"],
            //model_check_init_static
            "progress" => vec!["_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5"],
            //model_check_init_static
            "final_evt" => vec![],
            _ => vec![],
        }
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = sort_m2_data1000_MC::new();

        let mut all_states = HashSet::<sort_m2_data1000_MC>::new();
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(sort_m2_data1000_MC, &'static str)>::new()));
        states_to_process_mutex.lock().unwrap().push_back((machine.clone(), ""));

        let num_transitions = Arc::new(AtomicU64::new(0));

        let mut stop_threads = false;

        while !stop_threads && !states_to_process_mutex.lock().unwrap().is_empty() {
            let (mut state, last_op) = Self::next(Arc::clone(&states_to_process_mutex), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, Arc::clone(&num_transitions));

            if !Self::checkInvariants(&state, last_op, is_caching) {
                println!("INVARIANT VIOLATED");
                stop_threads = true;
            }
            if next_states.is_empty() {
                print!("DEADLOCK DETECTED");
                stop_threads = true;
            }

            next_states.into_iter()
                       .filter(|(next_state, _)| all_states.insert((*next_state).clone()))
                       .for_each(|(next_state, last_op)| states_to_process_mutex.lock().unwrap().push_back((next_state, last_op)));

            if all_states.len() % 50000 == 0 {
                println!("VISITED STATES: {}", all_states.len());
                println!("EVALUATED TRANSITIONS: {}", num_transitions.load(Ordering::Acquire));
                println!("-------------------");
            }
        }
        Self::print_result(all_states.len(), num_transitions.load(Ordering::Acquire), stop_threads);
    }

    fn modelCheckMultiThreaded(mc_type: MC_TYPE, threads: usize, is_caching: bool) {
        let threadPool = ThreadPool::new(threads);

        let machine = sort_m2_data1000_MC::new();

        let all_states = Arc::new(DashSet::<sort_m2_data1000_MC>::new());
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(sort_m2_data1000_MC, &'static str)>::new()));
        states_to_process_mutex.lock().unwrap().push_back((machine, ""));

        let num_transitions = Arc::new(AtomicU64::new(0));

        let mut stop_threads = false;
        let mut spawned_tasks: u64 = 0;
        let mut finished_tasks: u64 = 0;

        let (tx, rx) = channel();
        //println!("Thread {:?} starting threads", thread::current().id());
        while !stop_threads && !states_to_process_mutex.lock().unwrap().is_empty() {
            let (mut state, last_op) = Self::next(Arc::clone(&states_to_process_mutex), mc_type);

            let states_to_process = Arc::clone(&states_to_process_mutex);
            let transitions = Arc::clone(&num_transitions);
            let states = Arc::clone(&all_states);
            let tx = tx.clone();
            //println!("Thread {:?} spawning a thread", thread::current().id());
            threadPool.execute(move|| {
                if !Self::checkInvariants(&state, last_op, is_caching) {
                    let _ = tx.send(Err("INVARIANT VIOLATED"));
                }

                let next_states = Self::generateNextStates(&mut state, is_caching, transitions);
                if next_states.is_empty() { let _ = tx.send(Err("DEADLOCK DETECTED")); }

                //println!("Thread {:?} executing", thread::current().id());
                next_states.into_iter()
                           .filter(|(next_state, _)| states.insert((*next_state).clone()))
                           .for_each(|(next_state, last_op)| states_to_process.lock().unwrap().push_back((next_state, last_op)));

                //println!("Thread {:?} done", thread::current().id());
                let _ = tx.send(Ok(1));
            });

            spawned_tasks += 1;
            if spawned_tasks % 50000 == 0 {
                println!("VISITED STATES: {}", all_states.len());
                println!("EVALUATED TRANSITIONS: {}", num_transitions.load(Ordering::Acquire));
                println!("-------------------");
            }

            while states_to_process_mutex.lock().unwrap().is_empty() && spawned_tasks - finished_tasks > 0 {
                //println!("Thread {:?} (main) waiting for a thread to finish", thread::current().id());
                match rx.recv_timeout(Duration::from_secs(1)) {
                    Ok(val)  => match val {
                            Ok(_) => finished_tasks += 1,
                            Err(msg) => { println!("{}", msg); stop_threads = true; },
                        },
                    Err(_) => (),
                }
                if threadPool.panic_count() > 0 { stop_threads = true; }
            }
        }

        Self::print_result(all_states.len(), num_transitions.load(Ordering::Acquire), stop_threads);
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
