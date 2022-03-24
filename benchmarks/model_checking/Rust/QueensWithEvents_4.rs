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
pub struct QueensWithEvents_4 {
    queens: BRelation<BInteger, BInteger>,
    n: BInteger,
    interval: BSet<BInteger>,
    allFields: BSet<BRelation<BInteger, BInteger>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_Solve: Option<BSet<BRelation<BInteger, BInteger>>>,}

impl fmt::Display for QueensWithEvents_4 {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "QueensWithEvents_4: (".to_owned();
        result += &format!("_get_queens: {}, ", self._get_queens());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl QueensWithEvents_4 {

    pub fn new() -> QueensWithEvents_4 {
        //values: ''
        let mut m: QueensWithEvents_4 = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self.n = BInteger::new(4);
        self.interval = BSet::<BInteger>::interval(&BInteger::new(1), &self.n);
        self.allFields = BRelation::cartesianProduct(&self.interval, &self.interval).pow();
        self.queens = BRelation::new(vec![]).clone().clone();
    }

    pub fn _get_n(&self) -> BInteger {
        return self.n.clone();
    }

    pub fn _get_interval(&self) -> BSet<BInteger> {
        return self.interval.clone();
    }

    pub fn _get_allFields(&self) -> BSet<BRelation<BInteger, BInteger>> {
        return self.allFields.clone();
    }

    pub fn _get_queens(&self) -> BRelation<BInteger, BInteger> {
        return self.queens.clone();
    }

    pub fn Solve(&mut self, mut solution: BRelation<BInteger, BInteger>) -> () {
        //quantified_predicate
        let mut _ic_boolean_1 = BBoolean::new(true);
        if (solution.domain().equal(&self.interval) && solution.range().equal(&self.interval)).booleanValue() {
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
        if ((solution.domain().equal(&self.interval) && solution.range().equal(&self.interval)) && _ic_boolean_1).booleanValue() {
            for _ic_q1_1 in self.interval.clone().iter().cloned() {
                for _ic_q2_1 in self.interval.difference(&BSet::new(vec![BInteger::new(1)])).clone().iter().cloned() {
                    if !(_ic_q2_1.greater(&_ic_q1_1).implies(&(solution.functionCall(&_ic_q1_1).plus(&_ic_q2_1).minus(&_ic_q1_1).unequal(&solution.functionCall(&_ic_q2_1)) && solution.functionCall(&_ic_q1_1).minus(&_ic_q2_1).plus(&_ic_q1_1).unequal(&solution.functionCall(&_ic_q2_1))))).booleanValue() {
                        _ic_boolean_2 = BBoolean::new(false);
                        break;
                    }

                }
            }
        }

        //quantified_predicate
        let mut _ic_boolean_3 = BBoolean::new(true);
        if (((solution.domain().equal(&self.interval) && solution.range().equal(&self.interval)) && _ic_boolean_1) && _ic_boolean_2).booleanValue() {
            for _ic_x_1 in self.queens.domain().clone().iter().cloned() {
                if !(solution.functionCall(&_ic_x_1).equal(&self.queens.functionCall(&_ic_x_1))).booleanValue() {
                    _ic_boolean_3 = BBoolean::new(false);
                    break;
                }

            }
        }

        if ((((((self.allFields.elementOf(&solution) && solution.domain().equal(&self.interval)) && solution.range().equal(&self.interval)) && _ic_boolean_1) && _ic_boolean_2) && _ic_boolean_3)).booleanValue() {
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
                if (_ic_solution_1.domain().equal(&self.interval) && _ic_solution_1.range().equal(&self.interval)).booleanValue() {
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
                if ((_ic_solution_1.domain().equal(&self.interval) && _ic_solution_1.range().equal(&self.interval)) && _ic_boolean_5).booleanValue() {
                    for _ic_q1_1 in self.interval.clone().iter().cloned() {
                        for _ic_q2_1 in self.interval.difference(&BSet::new(vec![BInteger::new(1)])).clone().iter().cloned() {
                            if !(_ic_q2_1.greater(&_ic_q1_1).implies(&(_ic_solution_1.functionCall(&_ic_q1_1).plus(&_ic_q2_1).minus(&_ic_q1_1).unequal(&_ic_solution_1.functionCall(&_ic_q2_1)) && _ic_solution_1.functionCall(&_ic_q1_1).minus(&_ic_q2_1).plus(&_ic_q1_1).unequal(&_ic_solution_1.functionCall(&_ic_q2_1))))).booleanValue() {
                                _ic_boolean_6 = BBoolean::new(false);
                                break;
                            }

                        }
                    }
                }
                //quantified_predicate
                let mut _ic_boolean_7 = BBoolean::new(true);
                if (((_ic_solution_1.domain().equal(&self.interval) && _ic_solution_1.range().equal(&self.interval)) && _ic_boolean_5) && _ic_boolean_6).booleanValue() {
                    for _ic_x_1 in self.queens.domain().clone().iter().cloned() {
                        if !(_ic_solution_1.functionCall(&_ic_x_1).equal(&self.queens.functionCall(&_ic_x_1))).booleanValue() {
                            _ic_boolean_7 = BBoolean::new(false);
                            break;
                        }

                    }
                }

                if (((((_ic_solution_1.domain().equal(&self.interval) && _ic_solution_1.range().equal(&self.interval)) && _ic_boolean_5) && _ic_boolean_6) && _ic_boolean_7)).booleanValue() {
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

    fn invalidate_caches(&mut self, to_invalidate: Vec<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        for trans in to_invalidate {
            match trans {
                "_tr_Solve" => {self._tr_Solve(false);},
                _ => {},
            }
        }
    }

    //model_check_next_states
    fn generateNextStates(state: &mut QueensWithEvents_4,
                          isCaching: bool,
                          transitions: Arc<AtomicU64>) -> HashSet<(QueensWithEvents_4, &'static str)> {
        let mut result = HashSet::<(QueensWithEvents_4, &'static str)>::new();
        let mut evaluated_transitions: u64 = 0;
        //model_check_transition
        let mut _trid_1 = state._tr_Solve(isCaching);
        for param in _trid_1.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.Solve(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("Solve")); }
            result.insert((copiedState, "Solve"));
            evaluated_transitions += 1;
        }


        transitions.fetch_add(evaluated_transitions, Ordering::AcqRel);
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &QueensWithEvents_4, last_op: &'static str, isCaching: bool) -> bool {
        if isCaching {
            let dependent_invariants_of_state = Self::get_invariant_dependencies(last_op);
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_1") {
                if !state._check_inv_1() {
                    println!("_check_inv_1 failed!");
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1());
    }

    //model_check_print
    fn print_result(states: usize, transitions: u64, error_detected: bool) {
        if !error_detected { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<(QueensWithEvents_4, &'static str)>>>, mc_type: MC_TYPE) -> (QueensWithEvents_4, &'static str) {
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
            "Solve" => vec!["_tr_Solve"],
            _ => vec![],
        }
    }

    fn get_invariant_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "Solve" => vec!["_check_inv_1"],
            _ => vec![],
        }
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = QueensWithEvents_4::new();

        let mut all_states = HashSet::<QueensWithEvents_4>::new();
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(QueensWithEvents_4, &'static str)>::new()));
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

        let machine = QueensWithEvents_4::new();

        let all_states = Arc::new(DashSet::<QueensWithEvents_4>::new());
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(QueensWithEvents_4, &'static str)>::new()));
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
        QueensWithEvents_4::model_check_single_threaded(mc_type, is_caching);
    } else {
        QueensWithEvents_4::modelCheckMultiThreaded(mc_type, threads, is_caching);
    }
}
