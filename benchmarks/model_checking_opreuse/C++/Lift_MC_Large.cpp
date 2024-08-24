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
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef Lift_MC_Large_H
#define Lift_MC_Large_H

using namespace std;

class Lift_MC_Large {

    public:

        enum Type { BFS, DFS, MIXED };



        struct Hash {
            public:
                size_t operator()(const Lift_MC_Large& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const Lift_MC_Large& obj1, const Lift_MC_Large& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

        class _ProjectionRead_inc {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_inc& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_inc& obj1, const _ProjectionRead_inc& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger level;

                _ProjectionRead_inc(const BInteger& level) {
                    this->level = level;
                }

                friend bool operator ==(const _ProjectionRead_inc& o1, const _ProjectionRead_inc& o2) {
                    return o1.level == (o2.level);
                }

                friend bool operator !=(const _ProjectionRead_inc& o1, const _ProjectionRead_inc& o2) {
                    return o1.level != (o2.level);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_inc& e) {
                    strm << "{";
                    strm << "level: " << e.level;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (level.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_inc {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_inc& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_inc& obj1, const _ProjectionRead__tr_inc& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger level;

                _ProjectionRead__tr_inc(const BInteger& level) {
                    this->level = level;
                }

                friend bool operator ==(const _ProjectionRead__tr_inc& o1, const _ProjectionRead__tr_inc& o2) {
                    return o1.level == (o2.level);
                }

                friend bool operator !=(const _ProjectionRead__tr_inc& o1, const _ProjectionRead__tr_inc& o2) {
                    return o1.level != (o2.level);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_inc& e) {
                    strm << "{";
                    strm << "level: " << e.level;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (level.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_inc {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_inc& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_inc& obj1, const _ProjectionWrite_inc& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger level;

                _ProjectionWrite_inc(const BInteger& level) {
                    this->level = level;
                }

                friend bool operator ==(const _ProjectionWrite_inc& o1, const _ProjectionWrite_inc& o2) {
                    return o1.level == (o2.level);
                }

                friend bool operator !=(const _ProjectionWrite_inc& o1, const _ProjectionWrite_inc& o2) {
                    return o1.level != (o2.level);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_inc& e) {
                    strm << "{";
                    strm << "level: " << e.level;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (level.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_dec {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_dec& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_dec& obj1, const _ProjectionRead_dec& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger level;

                _ProjectionRead_dec(const BInteger& level) {
                    this->level = level;
                }

                friend bool operator ==(const _ProjectionRead_dec& o1, const _ProjectionRead_dec& o2) {
                    return o1.level == (o2.level);
                }

                friend bool operator !=(const _ProjectionRead_dec& o1, const _ProjectionRead_dec& o2) {
                    return o1.level != (o2.level);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_dec& e) {
                    strm << "{";
                    strm << "level: " << e.level;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (level.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_dec {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_dec& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_dec& obj1, const _ProjectionRead__tr_dec& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger level;

                _ProjectionRead__tr_dec(const BInteger& level) {
                    this->level = level;
                }

                friend bool operator ==(const _ProjectionRead__tr_dec& o1, const _ProjectionRead__tr_dec& o2) {
                    return o1.level == (o2.level);
                }

                friend bool operator !=(const _ProjectionRead__tr_dec& o1, const _ProjectionRead__tr_dec& o2) {
                    return o1.level != (o2.level);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_dec& e) {
                    strm << "{";
                    strm << "level: " << e.level;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (level.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_dec {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_dec& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_dec& obj1, const _ProjectionWrite_dec& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger level;

                _ProjectionWrite_dec(const BInteger& level) {
                    this->level = level;
                }

                friend bool operator ==(const _ProjectionWrite_dec& o1, const _ProjectionWrite_dec& o2) {
                    return o1.level == (o2.level);
                }

                friend bool operator !=(const _ProjectionWrite_dec& o1, const _ProjectionWrite_dec& o2) {
                    return o1.level != (o2.level);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_dec& e) {
                    strm << "{";
                    strm << "level: " << e.level;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (level.hashCode() << 1);
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

                BInteger level;

                _ProjectionRead__check_inv_1(const BInteger& level) {
                    this->level = level;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.level == (o2.level);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.level != (o2.level);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "level: " << e.level;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (level.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_2& obj1, const _ProjectionRead__check_inv_2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger level;

                _ProjectionRead__check_inv_2(const BInteger& level) {
                    this->level = level;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.level == (o2.level);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.level != (o2.level);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_2& e) {
                    strm << "{";
                    strm << "level: " << e.level;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (level.hashCode() << 1);
                    return result;
                }

        };



    private:




        BInteger level;


    public:

        std::string stateAccessedVia;

        Lift_MC_Large() {
            level = (BInteger(0));
        }

        Lift_MC_Large(const BInteger& level) {
            this->level = level;
        }

        void inc() {
            level = level.plus((BInteger(1)));

        }

        void dec() {
            level = level.minus((BInteger(1)));

        }

        BInteger _get_level() const {
            return level;
        }


        bool _tr_inc() const {
            return (level.less((BInteger(1000000)))).booleanValue();
        }

        bool _tr_dec() const {
            return (level.greater((BInteger(0)))).booleanValue();
        }

        _ProjectionRead_dec _projected_state_for_dec() const {
            return _ProjectionRead_dec(level);
        }

        _ProjectionRead_inc _projected_state_for_inc() const {
            return _ProjectionRead_inc(level);
        }

        _ProjectionRead__tr_dec _projected_state_for__tr_dec() const {
            return _ProjectionRead__tr_dec(level);
        }

        _ProjectionRead__tr_inc _projected_state_for__tr_inc() const {
            return _ProjectionRead__tr_inc(level);
        }

        _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() const {
            return _ProjectionRead__check_inv_2(level);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(level);
        }

        _ProjectionWrite_dec _update_for_dec() const {
            return _ProjectionWrite_dec(level);
        }

        _ProjectionWrite_inc _update_for_inc() const {
            return _ProjectionWrite_inc(level);
        }

        void _apply_update_for_dec(const _ProjectionWrite_dec& update) {
            this->level = update.level;
        }

        void _apply_update_for_inc(const _ProjectionWrite_inc& update) {
            this->level = update.level;
        }

        bool _check_inv_1() const {
            return (level.greaterEqual((BInteger(0)))).booleanValue();
        }

        bool _check_inv_2() const {
            return (level.lessEqual((BInteger(1000000)))).booleanValue();
        }

        Lift_MC_Large _copy() const {
            return Lift_MC_Large(level);
        }

        friend bool operator ==(const Lift_MC_Large& o1, const Lift_MC_Large& o2) {
            return o1._get_level() == o2._get_level();
        }

        friend bool operator !=(const Lift_MC_Large& o1, const Lift_MC_Large& o2) {
            return o1._get_level() != o2._get_level();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_level()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_level()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const Lift_MC_Large &machine) {
          strm << "_get_level: " << machine._get_level() << "\n";
          return strm;
        }


};


class ModelChecker {
    private:
        Lift_MC_Large::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<Lift_MC_Large> unvisitedStates;
        std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        Lift_MC_Large counterExampleState;

        std::unordered_map<bool, std::unordered_map<Lift_MC_Large::_ProjectionRead_inc, Lift_MC_Large::_ProjectionWrite_inc, Lift_MC_Large::_ProjectionRead_inc::Hash, Lift_MC_Large::_ProjectionRead_inc::HashEqual>> _OpCache_inc;
        std::unordered_map<Lift_MC_Large::_ProjectionRead__tr_inc, bool, Lift_MC_Large::_ProjectionRead__tr_inc::Hash, Lift_MC_Large::_ProjectionRead__tr_inc::HashEqual> _OpCache_tr_inc;
        std::mutex _ProjectionRead_inc_mutex;
        std::mutex _ProjectionRead__tr_inc_mutex;

        std::unordered_map<bool, std::unordered_map<Lift_MC_Large::_ProjectionRead_dec, Lift_MC_Large::_ProjectionWrite_dec, Lift_MC_Large::_ProjectionRead_dec::Hash, Lift_MC_Large::_ProjectionRead_dec::HashEqual>> _OpCache_dec;
        std::unordered_map<Lift_MC_Large::_ProjectionRead__tr_dec, bool, Lift_MC_Large::_ProjectionRead__tr_dec::Hash, Lift_MC_Large::_ProjectionRead__tr_dec::HashEqual> _OpCache_tr_dec;
        std::mutex _ProjectionRead_dec_mutex;
        std::mutex _ProjectionRead__tr_dec_mutex;

        std::unordered_map<Lift_MC_Large::_ProjectionRead__check_inv_1, bool, Lift_MC_Large::_ProjectionRead__check_inv_1::Hash, Lift_MC_Large::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;
        std::unordered_map<Lift_MC_Large::_ProjectionRead__check_inv_2, bool, Lift_MC_Large::_ProjectionRead__check_inv_2::Hash, Lift_MC_Large::_ProjectionRead__check_inv_2::HashEqual> _InvCache__check_inv_2;
        std::mutex _ProjectionRead__check_inv_2_mutex;

        std::unordered_map<Lift_MC_Large, Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(Lift_MC_Large::Type type, int threads, bool isCaching, bool isDebug) {
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
            Lift_MC_Large machine = Lift_MC_Large();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                Lift_MC_Large state = next();

                std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> nextStates = generateNextStates(state);

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
            Lift_MC_Large machine = Lift_MC_Large();
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
                Lift_MC_Large state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> nextStates = generateNextStates(state);

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
        Lift_MC_Large next() {
            {
                std::unique_lock<std::mutex> lock(mutex);
                switch(type) {
                    case Lift_MC_Large::BFS: {
                        Lift_MC_Large state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    }
                    case Lift_MC_Large::DFS: {
                        Lift_MC_Large state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                    case Lift_MC_Large::MIXED: {
                        if(unvisitedStates.size() % 2 == 0) {
                            Lift_MC_Large state = unvisitedStates.front();
                            unvisitedStates.pop_front();
                            return state;
                        } else {
                            Lift_MC_Large state = unvisitedStates.back();
                            unvisitedStates.pop_back();
                            return state;
                        }
                    }
                }
            };
        }

        std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> generateNextStates(const Lift_MC_Large& state) {
            std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> result = std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>();
            if(isCaching) {
                Lift_MC_Large::_ProjectionRead__tr_inc read__tr_inc_state = state._projected_state_for__tr_inc();
                bool _trid_1;
                auto _obj__trid_1_ptr = _OpCache_tr_inc.find(read__tr_inc_state);
                if(_obj__trid_1_ptr == _OpCache_tr_inc.end()) {
                    _trid_1 = state._tr_inc();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_inc_lock(_ProjectionRead__tr_inc_mutex);
                        _OpCache_tr_inc.insert({read__tr_inc_state, _trid_1});
                    }
                } else {
                    _trid_1 = _obj__trid_1_ptr->second;
                }
                if(_trid_1) {
                    Lift_MC_Large copiedState = state._copy();
                    Lift_MC_Large::_ProjectionRead_inc readState = state._projected_state_for_inc();

                    auto _OpCache_with_parameter_inc_ptr = _OpCache_inc.find(_trid_1);
                    if(_OpCache_with_parameter_inc_ptr == _OpCache_inc.end()) {
                        copiedState.inc();
                        Lift_MC_Large::_ProjectionWrite_inc writeState = copiedState._update_for_inc();
                        std::unordered_map<Lift_MC_Large::_ProjectionRead_inc, Lift_MC_Large::_ProjectionWrite_inc, Lift_MC_Large::_ProjectionRead_inc::Hash, Lift_MC_Large::_ProjectionRead_inc::HashEqual> _OpCache_with_parameter_inc;
                        _OpCache_with_parameter_inc.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_inc_lock(_ProjectionRead_inc_mutex);
                            _OpCache_inc.insert({_trid_1, _OpCache_with_parameter_inc});
                        }

                    } else {
                        std::unordered_map<Lift_MC_Large::_ProjectionRead_inc, Lift_MC_Large::_ProjectionWrite_inc, Lift_MC_Large::_ProjectionRead_inc::Hash, Lift_MC_Large::_ProjectionRead_inc::HashEqual> _OpCache_with_parameter_inc = _OpCache_with_parameter_inc_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_inc.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_inc.end()) {
                            Lift_MC_Large::_ProjectionWrite_inc writeState = writeState_ptr->second;
                            copiedState._apply_update_for_inc(writeState);
                        } else {
                            copiedState.inc();
                            Lift_MC_Large::_ProjectionWrite_inc writeState = copiedState._update_for_inc();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_inc_lock(_ProjectionRead_inc_mutex);
                                _OpCache_with_parameter_inc.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "inc";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                Lift_MC_Large::_ProjectionRead__tr_dec read__tr_dec_state = state._projected_state_for__tr_dec();
                bool _trid_2;
                auto _obj__trid_2_ptr = _OpCache_tr_dec.find(read__tr_dec_state);
                if(_obj__trid_2_ptr == _OpCache_tr_dec.end()) {
                    _trid_2 = state._tr_dec();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_dec_lock(_ProjectionRead__tr_dec_mutex);
                        _OpCache_tr_dec.insert({read__tr_dec_state, _trid_2});
                    }
                } else {
                    _trid_2 = _obj__trid_2_ptr->second;
                }
                if(_trid_2) {
                    Lift_MC_Large copiedState = state._copy();
                    Lift_MC_Large::_ProjectionRead_dec readState = state._projected_state_for_dec();

                    auto _OpCache_with_parameter_dec_ptr = _OpCache_dec.find(_trid_2);
                    if(_OpCache_with_parameter_dec_ptr == _OpCache_dec.end()) {
                        copiedState.dec();
                        Lift_MC_Large::_ProjectionWrite_dec writeState = copiedState._update_for_dec();
                        std::unordered_map<Lift_MC_Large::_ProjectionRead_dec, Lift_MC_Large::_ProjectionWrite_dec, Lift_MC_Large::_ProjectionRead_dec::Hash, Lift_MC_Large::_ProjectionRead_dec::HashEqual> _OpCache_with_parameter_dec;
                        _OpCache_with_parameter_dec.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_dec_lock(_ProjectionRead_dec_mutex);
                            _OpCache_dec.insert({_trid_2, _OpCache_with_parameter_dec});
                        }

                    } else {
                        std::unordered_map<Lift_MC_Large::_ProjectionRead_dec, Lift_MC_Large::_ProjectionWrite_dec, Lift_MC_Large::_ProjectionRead_dec::Hash, Lift_MC_Large::_ProjectionRead_dec::HashEqual> _OpCache_with_parameter_dec = _OpCache_with_parameter_dec_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_dec.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_dec.end()) {
                            Lift_MC_Large::_ProjectionWrite_dec writeState = writeState_ptr->second;
                            copiedState._apply_update_for_dec(writeState);
                        } else {
                            copiedState.dec();
                            Lift_MC_Large::_ProjectionWrite_dec writeState = copiedState._update_for_dec();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_dec_lock(_ProjectionRead_dec_mutex);
                                _OpCache_with_parameter_dec.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "dec";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            } else {
                if(state._tr_inc()) {
                    Lift_MC_Large copiedState = state._copy();
                    copiedState.inc();
                    copiedState.stateAccessedVia = "inc";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_dec()) {
                    Lift_MC_Large copiedState = state._copy();
                    copiedState.dec();
                    copiedState.stateAccessedVia = "dec";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            }
            return result;
        }

        bool invariantViolated(const Lift_MC_Large& state) {
            bool _check_inv_1;
            if(isCaching) {
                Lift_MC_Large::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
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
            bool _check_inv_2;
            if(isCaching) {
                Lift_MC_Large::_ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
                auto _obj__check_inv_2_ptr = _InvCache__check_inv_2.find(read__check_inv_2_state);
                if(_obj__check_inv_2_ptr == _InvCache__check_inv_2.end()) {
                    _check_inv_2 = state._check_inv_2();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_2_lock(_ProjectionRead__check_inv_2_mutex);
                        _InvCache__check_inv_2.insert({read__check_inv_2_state, _check_inv_2});
                    }
                } else {
                    _check_inv_2 = _obj__check_inv_2_ptr->second;
                }
            } else {
                _check_inv_2 = state._check_inv_2();
            }
            if(!_check_inv_2) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
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

    Lift_MC_Large::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = Lift_MC_Large::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = Lift_MC_Large::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = Lift_MC_Large::Type::DFS;
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