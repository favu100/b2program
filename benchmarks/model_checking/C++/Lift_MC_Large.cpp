#include <iostream>
#include <string>
#include <immer/map.hpp>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <atomic>
#include <mutex>
#include <future>
#include <boost/asio/post.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/any.hpp>
#include <boost/optional.hpp>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
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

    private:




        BInteger level;

        mutable boost::optional<bool> _tr_cache_inc;
        mutable boost::optional<bool> _tr_cache_dec;

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


        bool _tr_inc(bool isCaching) const {
            if (this->_tr_cache_inc == boost::none){
                bool __tmp_result = (level.less((BInteger(1000000)))).booleanValue();
                if (isCaching) this->_tr_cache_inc = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_inc.get();
        }

        bool _tr_dec(bool isCaching) const {
            if (this->_tr_cache_dec == boost::none){
                bool __tmp_result = (level.greater((BInteger(0)))).booleanValue();
                if (isCaching) this->_tr_cache_dec = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_dec.get();
        }

        bool _check_inv_1() const {
            return (level.greaterEqual((BInteger(0)))).booleanValue();
        }

        bool _check_inv_2() const {
            return (level.lessEqual((BInteger(1000000)))).booleanValue();
        }

        static constexpr unsigned int strHash(const char *s, int off = 0) {
            return !s[off] ? 5381 : (strHash(s, off+1)*33) ^ s[off];
        }

        Lift_MC_Large _copy(unordered_set<string> toInvalidate) const {
            static const char* allTransitions[] = {"_tr_inc", "_tr_dec"};

            Lift_MC_Large result = Lift_MC_Large(level);

            for (const auto &item : allTransitions) {
                if(toInvalidate.find(item) == toInvalidate.end()) {
                    switch(strHash(item)) {
                        case strHash("_tr_inc"): result._tr_cache_inc = this->_tr_cache_inc; break;
                        case strHash("_tr_dec"): result._tr_cache_dec = this->_tr_cache_dec; break;
                        default: cout << "Transition " << item << " not found!";
                    }
                }
            }
            return result;
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
        std::mutex guardMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        Lift_MC_Large counterExampleState;

        std::unordered_map<string, std::unordered_set<string>> invariantDependency;
        std::unordered_map<string, std::unordered_set<string>> guardDependency;
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

            if (isCaching) {
                initCache(machine);
            }

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

            if(isCaching) {
                initCache(machine);
            }

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
                                unvisitedStates.push_back(nextState); // TODO: sync ?
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
                    while (unvisitedStates.empty() && possibleQueueChanges > 0) {
                        waitCV.wait(lock, [&] {
                            return waitFlag == false;
                        });
                    }
                }
            }
            workers.join();
            printResult();
        }

        void initCache(Lift_MC_Large& machine) {
            invariantDependency.insert({"dec", {"_check_inv_2", "_check_inv_1"}});
            invariantDependency.insert({"inc", {"_check_inv_2", "_check_inv_1"}});
            invariantDependency.insert({"", {}});
            guardDependency.insert({"dec", {"_tr_dec", "_tr_inc"}});
            guardDependency.insert({"inc", {"_tr_dec", "_tr_inc"}});
        }


    private:
        Lift_MC_Large next() {
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
            };
        }

        std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> generateNextStates(const Lift_MC_Large& state) {
            std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> result = std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>();
            if(state._tr_inc(isCaching)) {
                Lift_MC_Large copiedState = state._copy(guardDependency["inc"]);
                copiedState.inc();
                copiedState.stateAccessedVia = "inc";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_dec(isCaching)) {
                Lift_MC_Large copiedState = state._copy(guardDependency["dec"]);
                copiedState.dec();
                copiedState.stateAccessedVia = "dec";
                result.insert(copiedState);
                transitions += 1;
            }

            return result;
        }

        bool invariantViolated(const Lift_MC_Large& state) {
            std::unordered_set<string> dependentInvariantsOfState;
            if(isCaching) {
                dependentInvariantsOfState = invariantDependency[state.stateAccessedVia];
            }
            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_1") != dependentInvariantsOfState.end()) {
                    if(!state._check_inv_1()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_1()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
                  return true;
                }
            }
            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_2") != dependentInvariantsOfState.end()) {
                    if(!state._check_inv_2()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_2()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
                  return true;
                }
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