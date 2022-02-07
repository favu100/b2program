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


    public:

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


static std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> generateNextStates(std::mutex& guardMutex, const Lift_MC_Large& state, bool isCaching, std::unordered_map<string, std::unordered_set<string>>& invariantDependency, std::unordered_map<Lift_MC_Large, std::unordered_set<string>, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>& dependentInvariant, std::unordered_map<string, std::unordered_set<string>>& guardDependency, std::unordered_map<Lift_MC_Large, std::unordered_set<string>, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>& dependentGuard, std::unordered_map<Lift_MC_Large, immer::map<string, boost::any>, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>& guardCache, std::unordered_map<Lift_MC_Large, Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>& parents, std::unordered_map<Lift_MC_Large, string, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>& stateAccessedVia, std::atomic<int>& transitions) {
    std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> result = std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>();
    if(isCaching) {
        immer::map<string, boost::any> parentsGuard;
        std::unordered_set<string> dependentGuardsOfState;
        bool parentsExist = false;
        bool dependentGuardsExist = false;
        {
            std::unique_lock<std::mutex> lock(guardMutex);
            parentsExist = (parents.find(state) != parents.end());
            dependentGuardsExist = (dependentGuard.find(state) != dependentGuard.end());
            if(parentsExist) {
                parentsGuard = guardCache[parents[state]];
            }
            if(dependentGuardsExist) {
                dependentGuardsOfState = dependentGuard[state];
            }
        }
        immer::map<string, boost::any> newCache = parentsGuard;
        boost::any cachedValue;
        bool dependentGuardsBoolean = true;
        bool _trid_1;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_inc"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_inc") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_1 = state._tr_inc();
        } else {
            _trid_1 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_inc", _trid_1);
        if(_trid_1) {
            Lift_MC_Large copiedState = state._copy();
            copiedState.inc();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["inc"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["inc"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "inc"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_2;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_dec"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_dec") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_2 = state._tr_dec();
        } else {
            _trid_2 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_dec", _trid_2);
        if(_trid_2) {
            Lift_MC_Large copiedState = state._copy();
            copiedState.dec();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["dec"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["dec"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "dec"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }

        {
            std::unique_lock<std::mutex> lock(guardMutex);
            guardCache.insert({state, newCache});
        }
    } else {
        if(state._tr_inc()) {
            Lift_MC_Large copiedState = state._copy();
            copiedState.inc();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "inc"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_dec()) {
            Lift_MC_Large copiedState = state._copy();
            copiedState.dec();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "dec"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }

    }
    return result;
}

static void printResult(int states, int transitions, bool deadlockDetected, bool invariantViolated, Lift_MC_Large& counterExampleState, std::unordered_map<Lift_MC_Large, Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>& parents, std::unordered_map<Lift_MC_Large, string, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>& stateAccessedVia) {
    if(deadlockDetected || invariantViolated) {
        if(deadlockDetected) {
            cout << "DEADLOCK DETECTED" << "\n";
        }
        if(invariantViolated) {
            cout << "INVARIANT VIOLATED" << "\n";
        }
        cout << "COUNTER EXAMPLE TRACE: " << "\n";

        Lift_MC_Large currentState = counterExampleState;
        std::string trace = "";
        while(parents.find(currentState) != parents.end()) {
            std::stringstream stringStream;
            stringStream << currentState;
            trace.insert(0, stringStream.str());
            trace.insert(0, "\n");
            trace.insert(0, stateAccessedVia[currentState]);
            trace.insert(0, "\n\n");
            currentState = parents[currentState];
        }
        cout << trace;
    }

    if(!deadlockDetected && !invariantViolated) {
        cout << "MODEL CHECKING SUCCESSFUL" << "\n";
    }
    cout << "Number of States: " << states << "\n";
    cout << "Number of Transitions: " << transitions << "\n";
}

static bool checkInvariants(std::mutex& guardMutex, const Lift_MC_Large& state, bool isCaching, std::unordered_map<Lift_MC_Large, std::unordered_set<string>, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>& dependentInvariant) {
    if(isCaching) {
        std::unordered_set<string> dependentInvariantsOfState;
        {
            std::unique_lock<std::mutex> lock(guardMutex);
            dependentInvariantsOfState = dependentInvariant[state];
        }
        if(dependentInvariantsOfState.find("_check_inv_1") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_1()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_2") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_2()) {
                return false;
            }
        }
        return true;
    }
    return !(!state._check_inv_1() || !state._check_inv_2());
}

static Lift_MC_Large next(std::list<Lift_MC_Large>& collection, std::mutex& mutex, Lift_MC_Large::Type type) {
    std::unique_lock<std::mutex> lock(mutex);
    switch(type) {
        case Lift_MC_Large::BFS: {
            Lift_MC_Large state = collection.front();
            collection.pop_front();
            return state;
        }
        case Lift_MC_Large::DFS: {
            Lift_MC_Large state = collection.back();
            collection.pop_back();
            return state;
        }
        case Lift_MC_Large::MIXED: {
            if(collection.size() % 2 == 0) {
                Lift_MC_Large state = collection.front();
                collection.pop_front();
                return state;
            } else {
                Lift_MC_Large state = collection.back();
                collection.pop_back();
                return state;
            }
        }
    };
}

static void modelCheckSingleThreaded(Lift_MC_Large::Type type, bool isCaching) {
    std::mutex mutex;
    std::mutex guardMutex;

    Lift_MC_Large machine = Lift_MC_Large();

    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> states = std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<Lift_MC_Large> collection = std::list<Lift_MC_Large>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<Lift_MC_Large, std::unordered_set<string>, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> dependentInvariant;
    std::unordered_map<Lift_MC_Large, std::unordered_set<string>, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> dependentGuard;
    std::unordered_map<Lift_MC_Large, immer::map<string, boost::any>, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> guardCache;
    std::unordered_map<Lift_MC_Large, Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> parents;
    std::unordered_map<Lift_MC_Large, string, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> stateAccessedVia;
    if(isCaching) {
        invariantDependency.insert({"dec", {"_check_inv_2", "_check_inv_1"}});
        invariantDependency.insert({"inc", {"_check_inv_2", "_check_inv_1"}});
        guardDependency.insert({"dec", {"_tr_dec", "_tr_inc"}});
        guardDependency.insert({"inc", {"_tr_dec", "_tr_inc"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }
    Lift_MC_Large counterExampleState;

    while(!collection.empty() && !stopThreads) {
        Lift_MC_Large state = next(collection, mutex, type);

        std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);
        for(auto nextState : nextStates) {
            if(states.find(nextState) == states.end()) {
                numberStates += 1;
                states.insert(nextState);
                collection.push_back(nextState);
                if(numberStates % 50000 == 0) {
                    cout << "VISITED STATES: " << numberStates << "\n";
                    cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                    cout << "-------------------" << "\n";
                }
            }
        }

        if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
            invariantViolated = true;
            stopThreads = true;
            counterExampleState = state;
        }

        if(nextStates.empty()) {
            deadlockDetected = true;
            stopThreads = true;
            counterExampleState = state;
        }

    }
    printResult(numberStates, transitions, deadlockDetected, invariantViolated, counterExampleState, parents, stateAccessedVia);
}

static void modelCheckMultiThreaded(Lift_MC_Large::Type type, int threads, bool isCaching) {
    std::mutex mutex;
    std::mutex waitMutex;
    std::mutex guardMutex;
    std::condition_variable waitCV;

    Lift_MC_Large machine = Lift_MC_Large();


    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> states = std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<Lift_MC_Large> collection = std::list<Lift_MC_Large>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::atomic<int> possibleQueueChanges;
    possibleQueueChanges = 0;

    std::atomic<bool> waitFlag;
    waitFlag = true;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<Lift_MC_Large, std::unordered_set<string>, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> dependentInvariant;
    std::unordered_map<Lift_MC_Large, std::unordered_set<string>, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> dependentGuard;
    std::unordered_map<Lift_MC_Large, immer::map<string, boost::any>, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> guardCache;
    std::unordered_map<Lift_MC_Large, Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> parents;
    std::unordered_map<Lift_MC_Large, string, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> stateAccessedVia;
    if(isCaching) {
        invariantDependency.insert({"dec", {"_check_inv_2", "_check_inv_1"}});
        invariantDependency.insert({"inc", {"_check_inv_2", "_check_inv_1"}});
        guardDependency.insert({"dec", {"_tr_dec", "_tr_inc"}});
        guardDependency.insert({"inc", {"_tr_dec", "_tr_inc"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }
    Lift_MC_Large counterExampleState;

    boost::asio::thread_pool workers(threads);

    while(!collection.empty() && !stopThreads) {
        possibleQueueChanges += 1;
        Lift_MC_Large state = next(collection, mutex, type);
        std::packaged_task<void()> task([&, state] {
            std::unordered_set<Lift_MC_Large, Lift_MC_Large::Hash, Lift_MC_Large::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);


            for(auto nextState : nextStates) {
                {
                    std::unique_lock<std::mutex> lock(mutex);
                    if(states.find(nextState) == states.end()) {
                        numberStates += 1;
                        states.insert(nextState);
                        collection.push_back(nextState);
                        if(numberStates % 50000 == 0) {
                            cout << "VISITED STATES: " << numberStates << "\n";
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
                if (!collection.empty() || running == 0) {
                    {
                        std::unique_lock<std::mutex> lock(waitMutex);
                        waitFlag = false;
                        waitCV.notify_one();
                    }
                }
            }

            if(nextStates.empty()) {
                deadlockDetected = true;
                stopThreads = true;
                counterExampleState = state;
            }

            if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
                invariantViolated = true;
                stopThreads = true;
                counterExampleState = state;
            }


        });
        waitFlag = true;
        boost::asio::post(workers, std::move(task));

        {
            std::unique_lock<std::mutex> lock(waitMutex);
            if (collection.empty() && possibleQueueChanges > 0) {
                waitCV.wait(lock, [&] {
                    return waitFlag == false;
                });
            }
        }
    }
    workers.join();
    printResult(numberStates, transitions, deadlockDetected, invariantViolated, counterExampleState, parents, stateAccessedVia);
}

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

    if(threads == 1) {
        modelCheckSingleThreaded(type, isCaching);
    } else {
        modelCheckMultiThreaded(type, threads, isCaching);
    }
    return 0;
}



#endif