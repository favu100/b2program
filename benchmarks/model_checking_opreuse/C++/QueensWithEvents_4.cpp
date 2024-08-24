#include <iostream>
#include <string>
#include <immer/map.hpp>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <atomic>
#include <any>
#include <mutex>
#include <future>
#include <boost/asio/post.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/any.hpp>
#include <boost/optional.hpp>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/VariantViolation.hpp>
#include <btypes_primitives/LoopInvariantViolation.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BRelation.hpp>
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef QueensWithEvents_4_H
#define QueensWithEvents_4_H

using namespace std;

class QueensWithEvents_4 {

    public:

        enum Type { BFS, DFS, MIXED };



        struct Hash {
            public:
                size_t operator()(const QueensWithEvents_4& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const QueensWithEvents_4& obj1, const QueensWithEvents_4& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

        class _ProjectionRead_Solve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_Solve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_Solve& obj1, const _ProjectionRead_Solve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > queens;

                _ProjectionRead_Solve(const BRelation<BInteger, BInteger >& queens) {
                    this->queens = queens;
                }

                friend bool operator ==(const _ProjectionRead_Solve& o1, const _ProjectionRead_Solve& o2) {
                    return o1.queens == (o2.queens);
                }

                friend bool operator !=(const _ProjectionRead_Solve& o1, const _ProjectionRead_Solve& o2) {
                    return o1.queens != (o2.queens);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_Solve& e) {
                    strm << "{";
                    strm << "queens: " << e.queens;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (queens.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_Solve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_Solve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_Solve& obj1, const _ProjectionRead__tr_Solve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > queens;

                _ProjectionRead__tr_Solve(const BRelation<BInteger, BInteger >& queens) {
                    this->queens = queens;
                }

                friend bool operator ==(const _ProjectionRead__tr_Solve& o1, const _ProjectionRead__tr_Solve& o2) {
                    return o1.queens == (o2.queens);
                }

                friend bool operator !=(const _ProjectionRead__tr_Solve& o1, const _ProjectionRead__tr_Solve& o2) {
                    return o1.queens != (o2.queens);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_Solve& e) {
                    strm << "{";
                    strm << "queens: " << e.queens;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (queens.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_Solve {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_Solve& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_Solve& obj1, const _ProjectionWrite_Solve& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > queens;

                _ProjectionWrite_Solve(const BRelation<BInteger, BInteger >& queens) {
                    this->queens = queens;
                }

                friend bool operator ==(const _ProjectionWrite_Solve& o1, const _ProjectionWrite_Solve& o2) {
                    return o1.queens == (o2.queens);
                }

                friend bool operator !=(const _ProjectionWrite_Solve& o1, const _ProjectionWrite_Solve& o2) {
                    return o1.queens != (o2.queens);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_Solve& e) {
                    strm << "{";
                    strm << "queens: " << e.queens;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (queens.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_1& obj1, const _ProjectionRead__check_inv_1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > queens;

                _ProjectionRead__check_inv_1(const BRelation<BInteger, BInteger >& queens) {
                    this->queens = queens;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.queens == (o2.queens);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.queens != (o2.queens);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "queens: " << e.queens;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (queens.hashCode() << 1);
                    return result;
                }

        };



    private:

        BInteger n;
        BSet<BInteger > interval;
        BSet<BRelation<BInteger, BInteger > > allFields;



        BRelation<BInteger, BInteger > queens;


    public:

        std::string stateAccessedVia;

        QueensWithEvents_4() {
            n = (BInteger(4));
            interval = (BSet<BInteger>::interval((BInteger(1)),n));
            allFields = (BRelation<BInteger, BInteger >::cartesianProduct(interval, interval)).pow();
            queens = (BRelation<BInteger, BInteger >());
        }

        QueensWithEvents_4(const BInteger& n, const BSet<BInteger >& interval, const BSet<BRelation<BInteger, BInteger > >& allFields, const BRelation<BInteger, BInteger >& queens) {
            this->n = n;
            this->interval = interval;
            this->allFields = allFields;
            this->queens = queens;
        }

        void Solve(const BRelation<BInteger, BInteger >& solution) {
            queens = solution;

        }

        BInteger _get_n() const {
            return n;
        }

        BSet<BInteger > _get_interval() const {
            return interval;
        }

        BSet<BRelation<BInteger, BInteger > > _get_allFields() const {
            return allFields;
        }

        BRelation<BInteger, BInteger > _get_queens() const {
            return queens;
        }


        BSet<BRelation<BInteger, BInteger >> _tr_Solve() const {
            BSet<BRelation<BInteger, BInteger >> _ic_set_4 = BSet<BRelation<BInteger, BInteger >>();
            for(const BRelation<BInteger, BInteger >& _ic_solution_1 : allFields) {
                BBoolean _ic_boolean_5 = BBoolean(true);
                for(const BInteger& _ic_x_1 : interval) {
                    for(const BInteger& _ic_y_1 : interval) {
                        BBoolean _ic_boolean_4 = BBoolean(true);
                        for(const BInteger& _ic_z_1 : interval) {
                            if(!((BBoolean(!(BBoolean(interval.elementOf(_ic_z_1).booleanValue() && _ic_solution_1.elementOf((BTuple<BInteger, BInteger >(_ic_x_1, _ic_z_1))).booleanValue())).booleanValue() || _ic_y_1.equal(_ic_z_1).booleanValue()))).booleanValue()) {
                                _ic_boolean_4 = BBoolean(false);
                                break;
                            }

                        }
                        if(((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()))).booleanValue()) {
                            if(!((BBoolean(!(BBoolean((BBoolean(interval.elementOf(_ic_x_1).booleanValue() && interval.elementOf(_ic_y_1).booleanValue())).booleanValue() && _ic_solution_1.elementOf((BTuple<BInteger, BInteger >(_ic_x_1, _ic_y_1))).booleanValue())).booleanValue() || _ic_boolean_4.booleanValue()))).booleanValue()) {
                                _ic_boolean_5 = BBoolean(false);
                                break;
                            }
                        }

                    }
                }BBoolean _ic_boolean_6 = BBoolean(true);
                for(const BInteger& _ic_q1_1 : interval) {
                    for(const BInteger& _ic_q2_1 : interval.difference((BSet<BInteger >((BInteger(1)))))) {
                        if(((BBoolean((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue())).booleanValue() && _ic_boolean_5.booleanValue()))).booleanValue()) {
                            if(!((BBoolean(!(BBoolean((BBoolean(interval.elementOf(_ic_q1_1).booleanValue() && interval.difference((BSet<BInteger >((BInteger(1))))).elementOf(_ic_q2_1).booleanValue())).booleanValue() && _ic_q2_1.greater(_ic_q1_1).booleanValue())).booleanValue() || (BBoolean(_ic_solution_1.functionCall(_ic_q1_1).plus(_ic_q2_1).minus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue() && _ic_solution_1.functionCall(_ic_q1_1).minus(_ic_q2_1).plus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue())).booleanValue()))).booleanValue()) {
                                _ic_boolean_6 = BBoolean(false);
                                break;
                            }
                        }

                    }
                }BBoolean _ic_boolean_7 = BBoolean(true);
                for(const BInteger& _ic_x_1 : queens.domain()) {
                    if(((BBoolean((BBoolean((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue())).booleanValue() && _ic_boolean_5.booleanValue())).booleanValue() && _ic_boolean_6.booleanValue()))).booleanValue()) {
                        if(!((BBoolean(!queens.domain().elementOf(_ic_x_1).booleanValue() || _ic_solution_1.functionCall(_ic_x_1).equal(queens.functionCall(_ic_x_1)).booleanValue()))).booleanValue()) {
                            _ic_boolean_7 = BBoolean(false);
                            break;
                        }
                    }

                }
                if(((BBoolean((BBoolean((BBoolean((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue())).booleanValue() && _ic_boolean_5.booleanValue())).booleanValue() && _ic_boolean_6.booleanValue())).booleanValue() && _ic_boolean_7.booleanValue()))).booleanValue()) {
                    _ic_set_4 = _ic_set_4._union(BSet<BRelation<BInteger, BInteger >>(_ic_solution_1));
                }

            }
            return _ic_set_4;
        }

        _ProjectionRead_Solve _projected_state_for_Solve() const {
            return _ProjectionRead_Solve(queens);
        }

        _ProjectionRead__tr_Solve _projected_state_for__tr_Solve() const {
            return _ProjectionRead__tr_Solve(queens);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(queens);
        }

        _ProjectionWrite_Solve _update_for_Solve() const {
            return _ProjectionWrite_Solve(queens);
        }

        void _apply_update_for_Solve(const _ProjectionWrite_Solve& update) {
            this->queens = update.queens;
        }

        bool _check_inv_1() const {
            return (((queens.checkDomain(interval))._and((queens.checkRange(interval)))._and((queens.isFunction()))._and((queens.isPartial(interval))))).booleanValue();
        }

        QueensWithEvents_4 _copy() const {
            return QueensWithEvents_4(n, interval, allFields, queens);
        }

        friend bool operator ==(const QueensWithEvents_4& o1, const QueensWithEvents_4& o2) {
            return o1._get_queens() == o2._get_queens();
        }

        friend bool operator !=(const QueensWithEvents_4& o1, const QueensWithEvents_4& o2) {
            return o1._get_queens() != o2._get_queens();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_queens()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_queens()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const QueensWithEvents_4 &machine) {
          strm << "_get_queens: " << machine._get_queens() << "\n";
          return strm;
        }


};


class ModelChecker {
    private:
        QueensWithEvents_4::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<QueensWithEvents_4> unvisitedStates;
        std::unordered_set<QueensWithEvents_4, QueensWithEvents_4::Hash, QueensWithEvents_4::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        QueensWithEvents_4 counterExampleState;

        std::unordered_map<BSet<BRelation<BInteger, BInteger >>, std::unordered_map<QueensWithEvents_4::_ProjectionRead_Solve, QueensWithEvents_4::_ProjectionWrite_Solve, QueensWithEvents_4::_ProjectionRead_Solve::Hash, QueensWithEvents_4::_ProjectionRead_Solve::HashEqual>, BSet<BRelation<BInteger, BInteger >>::SetHash, BSet<BRelation<BInteger, BInteger >>::SetHashEqual> _OpCache_Solve;
        std::unordered_map<QueensWithEvents_4::_ProjectionRead__tr_Solve,  BSet<BRelation<BInteger, BInteger >>, QueensWithEvents_4::_ProjectionRead__tr_Solve::Hash, QueensWithEvents_4::_ProjectionRead__tr_Solve::HashEqual> _OpCache_tr_Solve;
        std::mutex _ProjectionRead_Solve_mutex;
        std::mutex _ProjectionRead__tr_Solve_mutex;

        std::unordered_map<QueensWithEvents_4::_ProjectionRead__check_inv_1, bool, QueensWithEvents_4::_ProjectionRead__check_inv_1::Hash, QueensWithEvents_4::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;

        std::unordered_map<QueensWithEvents_4, QueensWithEvents_4, QueensWithEvents_4::Hash, QueensWithEvents_4::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(QueensWithEvents_4::Type type, int threads, bool isCaching, bool isDebug) {
            this->type = type;
            this->threads = threads;
            this->isCaching = isCaching;
            this->isDebug = isDebug;
            this->invariantViolatedBool = false;
            this->deadlockDetected = false;
            this->transitions = 0;
        }

        void modelCheck() {
            if (isDebug) {
                cout << "Starting Modelchecking, STRATEGY=" << type << ", THREADS=" << threads << ", CACHING=" << isCaching << "\n";
            }

            if (threads <= 1) {
                modelCheckSingleThreaded();
            } else {
                boost::asio::thread_pool workers(threads); // threads indicates the number of workers (without the coordinator)
                modelCheckMultiThreaded(workers);
            }
        }

        void modelCheckSingleThreaded() {
            QueensWithEvents_4 machine = QueensWithEvents_4();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                QueensWithEvents_4 state = next();

                std::unordered_set<QueensWithEvents_4, QueensWithEvents_4::Hash, QueensWithEvents_4::HashEqual> nextStates = generateNextStates(state);

                for(auto& nextState : nextStates) {
                    if(states.find(nextState) == states.end()) {
                        states.insert(nextState);
                        parents.insert({nextState, state});
                        unvisitedStates.push_back(nextState);
                        if(states.size() % 50000 == 0) {
                            cout << "VISITED STATES: " << states.size() << "\n";
                            cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                            cout << "-------------------" << "\n";
                        }
                    }
                }

                if(invariantViolated(state)) {
                    invariantViolatedBool = true;
                    counterExampleState = state;
                    break;
                }

                if(nextStates.empty()) {
                    deadlockDetected = true;
                    counterExampleState = state;
                    break;
                }

            }
            printResult();
        }

        void modelCheckMultiThreaded(boost::asio::thread_pool& workers) {
            QueensWithEvents_4 machine = QueensWithEvents_4();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            std::atomic<bool> stopThreads;
            stopThreads = false;
            std::atomic<int> possibleQueueChanges;
            possibleQueueChanges = 0;

            std::atomic<bool> waitFlag;
            waitFlag = true;

            while(!unvisitedStates.empty() && !stopThreads) {
                possibleQueueChanges += 1;
                QueensWithEvents_4 state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<QueensWithEvents_4, QueensWithEvents_4::Hash, QueensWithEvents_4::HashEqual> nextStates = generateNextStates(state);

                    for(auto& nextState : nextStates) {
                        {
                            std::unique_lock<std::mutex> lock(mutex);
                            if(states.find(nextState) == states.end()) {
                                states.insert(nextState);
                                parents.insert({nextState, state});
                                unvisitedStates.push_back(nextState);
                                if(isDebug && states.size() % 50000 == 0) {
                                    cout << "VISITED STATES: " << states.size() << "\n";
                                    cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                                    cout << "-------------------" << "\n";
                                }
                            }
                        }
                    }

                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        possibleQueueChanges -= 1;
                        int running = possibleQueueChanges;
                        if (!unvisitedStates.empty() || running == 0) {
                            {
                                std::unique_lock<std::mutex> lock(waitMutex);
                                waitFlag = false;
                                waitCV.notify_one();
                            }
                        }
                    }


                    if(invariantViolated(state)) {
                        invariantViolatedBool = true;
                        counterExampleState = state;
                        stopThreads = true;
                    }

                    if(nextStates.empty()) {
                        deadlockDetected = true;
                        counterExampleState = state;
                        stopThreads = true;
                    }

                });

                waitFlag = true;
                boost::asio::post(workers, std::move(task));

                {
                    std::unique_lock<std::mutex> lock(waitMutex);
                    if(unvisitedStates.empty() && possibleQueueChanges > 0) {
                        waitCV.wait(lock, [&] {
                            return waitFlag == false;
                        });
                    }
                }
            }
            workers.join();
            printResult();
        }


    private:
        QueensWithEvents_4 next() {
            {
                std::unique_lock<std::mutex> lock(mutex);
                switch(type) {
                    case QueensWithEvents_4::BFS: {
                        QueensWithEvents_4 state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    }
                    case QueensWithEvents_4::DFS: {
                        QueensWithEvents_4 state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                    case QueensWithEvents_4::MIXED: {
                        if(unvisitedStates.size() % 2 == 0) {
                            QueensWithEvents_4 state = unvisitedStates.front();
                            unvisitedStates.pop_front();
                            return state;
                        } else {
                            QueensWithEvents_4 state = unvisitedStates.back();
                            unvisitedStates.pop_back();
                            return state;
                        }
                    }
                }
            };
        }

        std::unordered_set<QueensWithEvents_4, QueensWithEvents_4::Hash, QueensWithEvents_4::HashEqual> generateNextStates(const QueensWithEvents_4& state) {
            std::unordered_set<QueensWithEvents_4, QueensWithEvents_4::Hash, QueensWithEvents_4::HashEqual> result = std::unordered_set<QueensWithEvents_4, QueensWithEvents_4::Hash, QueensWithEvents_4::HashEqual>();
            if(isCaching) {
                QueensWithEvents_4::_ProjectionRead__tr_Solve read__tr_Solve_state = state._projected_state_for__tr_Solve();
                BSet<BRelation<BInteger, BInteger >> _trid_1;
                auto _trid_1_ptr = _OpCache_tr_Solve.find(read__tr_Solve_state);
                if(_trid_1_ptr == _OpCache_tr_Solve.end()) {
                    _trid_1 = state._tr_Solve();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_Solve_lock(_ProjectionRead__tr_Solve_mutex);
                        _OpCache_tr_Solve.insert({read__tr_Solve_state, _trid_1});
                    }
                } else {
                    _trid_1 = _trid_1_ptr->second;
                }

                for(const BRelation<BInteger, BInteger >& param : _trid_1) {
                    BRelation<BInteger, BInteger > _tmp_1 = param;

                    QueensWithEvents_4 copiedState = state._copy();
                    QueensWithEvents_4::_ProjectionRead_Solve readState = state._projected_state_for_Solve();

                    auto _OpCache_with_parameter_Solve_ptr = _OpCache_Solve.find(param);
                    if(_OpCache_with_parameter_Solve_ptr == _OpCache_Solve.end()) {
                        copiedState.Solve(_tmp_1);
                        QueensWithEvents_4::_ProjectionWrite_Solve writeState = copiedState._update_for_Solve();
                        std::unordered_map<QueensWithEvents_4::_ProjectionRead_Solve, QueensWithEvents_4::_ProjectionWrite_Solve, QueensWithEvents_4::_ProjectionRead_Solve::Hash, QueensWithEvents_4::_ProjectionRead_Solve::HashEqual> _OpCache_with_parameter_Solve;
                        _OpCache_with_parameter_Solve.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_Solve_lock(_ProjectionRead_Solve_mutex);
                            _OpCache_Solve.insert({param, _OpCache_with_parameter_Solve});
                        }

                    } else {
                        std::unordered_map<QueensWithEvents_4::_ProjectionRead_Solve, QueensWithEvents_4::_ProjectionWrite_Solve, QueensWithEvents_4::_ProjectionRead_Solve::Hash, QueensWithEvents_4::_ProjectionRead_Solve::HashEqual> _OpCache_with_parameter_Solve = _OpCache_with_parameter_Solve_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_Solve.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_Solve.end()) {
                            QueensWithEvents_4::_ProjectionWrite_Solve writeState = writeState_ptr->second;
                            copiedState._apply_update_for_Solve(writeState);
                        } else {
                            copiedState.Solve(_tmp_1);
                            QueensWithEvents_4::_ProjectionWrite_Solve writeState = copiedState._update_for_Solve();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_Solve_lock(_ProjectionRead_Solve_mutex);
                                _OpCache_with_parameter_Solve.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "Solve";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            } else {
                BSet<BRelation<BInteger, BInteger >> _trid_1 = state._tr_Solve();
                for(const BRelation<BInteger, BInteger >& param : _trid_1) {
                    BRelation<BInteger, BInteger > _tmp_1 = param;

                    QueensWithEvents_4 copiedState = state._copy();
                    copiedState.Solve(_tmp_1);
                    copiedState.stateAccessedVia = "Solve";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            }
            return result;
        }

        bool invariantViolated(const QueensWithEvents_4& state) {
            bool _check_inv_1;
            if(isCaching) {
                QueensWithEvents_4::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
                auto _obj__check_inv_1_ptr = _InvCache__check_inv_1.find(read__check_inv_1_state);
                if(_obj__check_inv_1_ptr == _InvCache__check_inv_1.end()) {
                    _check_inv_1 = state._check_inv_1();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_1_lock(_ProjectionRead__check_inv_1_mutex);
                        _InvCache__check_inv_1.insert({read__check_inv_1_state, _check_inv_1});
                    }
                } else {
                    _check_inv_1 = _obj__check_inv_1_ptr->second;
                }
            } else {
                _check_inv_1 = state._check_inv_1();
            }
            if(!_check_inv_1) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
              return true;
            }
            return false;
        }

        void printResult() {
            if(deadlockDetected || invariantViolatedBool) {
                if(deadlockDetected) {
                    cout << "DEADLOCK DETECTED" << "\n";
                } else {
                    cout << "INVARIANT VIOLATED" << "\n";
                }

                cout << "COUNTER EXAMPLE TRACE: " << "\n";

                std::string trace = "";
                while(parents.find(counterExampleState) != parents.end()) {
                    std::stringstream stringStream;
                    stringStream << counterExampleState;
                    trace.insert(0, stringStream.str());
                    trace.insert(0, "\n");
                    trace.insert(0, counterExampleState.stateAccessedVia);
                    trace.insert(0, "\n\n");
                    counterExampleState = parents[counterExampleState];
                }
                cout << trace;
            } else {
                cout << "MODEL CHECKING SUCCESSFUL" << "\n";
            }

            cout << "Number of States: " << states.size() << "\n";
            cout << "Number of Transitions: " << transitions << "\n";
        }
};

int main(int argc, char *argv[]) {
    if(argc != 4) {
        cout << "Number of arguments errorneous\n";
        return -1;
    }
    string strategy = argv[1];
    string numberThreads = argv[2];
    string caching = argv[3];

    QueensWithEvents_4::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = QueensWithEvents_4::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = QueensWithEvents_4::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = QueensWithEvents_4::Type::DFS;
    } else {
        cout << "Input for strategy is wrong.\n";
        return -1;
    }

    int threads = 0;
    try {
        threads = std::stoi(numberThreads);
    } catch(std::invalid_argument e) {
        cout << "Input for number of threads is wrong.\n";
        return -1;
    }

    if(threads <= 0) {
        cout << "Input for number of threads is wrong.\n";
        return -1;
    }

    bool isCaching = true;


    if(std::string("true").compare(caching) == 0) {
        isCaching = true;
    } else if(std::string("false").compare(caching) == 0) {
        isCaching = false;
    } else {
        cout << "Input for caching is wrong.\n";
        return - 1;
    }

    bool isDebug = true;
    // TODO

    ModelChecker modelchecker(type, threads, isCaching, isDebug);
    modelchecker.modelCheck();

    return 0;
}



#endif