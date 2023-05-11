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
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
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

impl fmt::Display for Lift_MC_Large {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "Lift_MC_Large: (".to_owned();
        result += &format!("_get_level: {}, ", self._get_level());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

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

    pub fn _get_level(&self) -> BInteger {
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

    fn invalidate_caches(&mut self, to_invalidate: Vec<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        for trans in to_invalidate {
            match trans {
                "_tr_inc" => {self._tr_inc(false);},
                "_tr_dec" => {self._tr_dec(false);},
                _ => {},
            }
        }
    }

    //model_check_next_states
    fn generateNextStates(state: &mut Lift_MC_Large,
                          isCaching: bool,
                          transitions: Arc<AtomicU64>) -> HashSet<(Lift_MC_Large, &'static str)> {
        let mut result = HashSet::<(Lift_MC_Large, &'static str)>::new();
        let mut evaluated_transitions: u64 = 0;
        //model_check_transition
        if state._tr_inc(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.inc();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("inc")); }
            result.insert((copiedState, "inc"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_dec(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.dec();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("dec")); }
            result.insert((copiedState, "dec"));
            evaluated_transitions += 1;
        }


        transitions.fetch_add(evaluated_transitions, Ordering::AcqRel);
        return result;
    }

    //model_check_invariants
    pub fn checkInvariants(state: &Lift_MC_Large, last_op: &'static str, isCaching: bool) -> bool {
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
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2());
    }

    //model_check_print
    fn print_result(states: usize, transitions: u64, error_detected: bool) {
        if !error_detected { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<(Lift_MC_Large, &'static str)>>>, mc_type: MC_TYPE) -> (Lift_MC_Large, &'static str) {
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
            "dec" => vec!["_tr_dec", "_tr_inc"],
            //model_check_init_static
            "inc" => vec!["_tr_dec", "_tr_inc"],
            _ => vec![],
        }
    }

    fn get_invariant_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "dec" => vec!["_check_inv_2", "_check_inv_1"],
            //model_check_init_static
            "inc" => vec!["_check_inv_2", "_check_inv_1"],
            _ => vec![],
        }
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool, no_dead: bool, no_inv: bool) {
        let mut machine = Lift_MC_Large::new();

        let mut all_states = HashSet::<Lift_MC_Large>::new();
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(Lift_MC_Large, &'static str)>::new()));
        states_to_process_mutex.lock().unwrap().push_back((machine.clone(), ""));

        let num_transitions = Arc::new(AtomicU64::new(0));

        let mut stop_threads = false;

        while !stop_threads && !states_to_process_mutex.lock().unwrap().is_empty() {
            let (mut state, last_op) = Self::next(Arc::clone(&states_to_process_mutex), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, Arc::clone(&num_transitions));

            if !no_inv && !Self::checkInvariants(&state, last_op, is_caching) {
                println!("INVARIANT VIOLATED");
                stop_threads = true;
            }
            if !no_dead && next_states.is_empty() {
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

    fn modelCheckMultiThreaded(mc_type: MC_TYPE, threads: usize, is_caching: bool, no_dead: bool, no_inv: bool) {
        let threadPool = ThreadPool::new(threads);

        let machine = Lift_MC_Large::new();

        let all_states = Arc::new(DashSet::<Lift_MC_Large>::new());
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(Lift_MC_Large, &'static str)>::new()));
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
                let next_states = Self::generateNextStates(&mut state, is_caching, transitions);
                if !no_dead && next_states.is_empty() { let _ = tx.send(Err("DEADLOCK DETECTED")); }

                //println!("Thread {:?} executing", thread::current().id());
                next_states.into_iter()
                           .filter(|(next_state, _)| states.insert((*next_state).clone()))
                           .for_each(|(next_state, last_op)| states_to_process.lock().unwrap().push_back((next_state, last_op)));

                if !no_inv && !Self::checkInvariants(&state, last_op, is_caching) {
                    let _ = tx.send(Err("INVARIANT VIOLATED"));
                }
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
                match rx.try_recv() {
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
    if args.len() < 4 { panic!("Number of arguments errorneous"); }

    let threads = args.get(2).unwrap().parse::<usize>().unwrap();
    if threads <= 0 { panic!("Input for number of threads is wrong."); }

    let is_caching = args.get(3).unwrap().parse::<bool>().unwrap();
    let mc_type = match args.get(1).unwrap().as_str() {
        "mixed" => MC_TYPE::MIXED,
        "bf" => MC_TYPE::BFS,
        "df" => MC_TYPE::DFS,
        _    => panic!("Input for strategy is wrong.")
    };

    let mut no_dead = false;
    let mut no_inv = false;

    if args.len() > 4 {
        for arg in args.iter().skip(4) {
            match arg.as_str() {
                "-nodead" => no_dead = true,
                "-noinv" => no_inv = true,
                _ => {}
            }
        }
    }

    if threads == 1 {
        Lift_MC_Large::model_check_single_threaded(mc_type, is_caching, no_dead, no_inv);
    } else {
        Lift_MC_Large::modelCheckMultiThreaded(mc_type, threads, is_caching, no_dead, no_inv);
    }
}
