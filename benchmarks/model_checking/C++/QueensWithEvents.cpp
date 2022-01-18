#include <iostream>
#include <string>
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
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BRelation.hpp>
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef QueensWithEvents_H
#define QueensWithEvents_H

using namespace std;

class QueensWithEvents {

    public:

        enum Type { BFS, DFS, MIXED };



        struct Hash {
            public:
                size_t operator()(const QueensWithEvents& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const QueensWithEvents& obj1, const QueensWithEvents& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

    private:

        BInteger n;
        BSet<BInteger > interval;
        BSet<BRelation<BInteger, BInteger > > allFields;



        BRelation<BInteger, BInteger > queens;


    public:

        QueensWithEvents() {
            n = (BInteger(8));
            interval = (BSet<BInteger>::interval((BInteger(1)),n));
            allFields = (BRelation<BInteger, BInteger >::cartesianProduct(interval, interval)).pow();
            queens = (BRelation<BInteger, BInteger >());
        }

        QueensWithEvents(const BInteger& n, const BSet<BInteger >& interval, const BSet<BRelation<BInteger, BInteger > >& allFields, const BRelation<BInteger, BInteger >& queens) {
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
            BSet<BRelation<BInteger, BInteger >> _ic_set_3 = BSet<BRelation<BInteger, BInteger >>();
            for(BRelation<BInteger, BInteger > _ic_solution_1 : allFields) {
                BBoolean _ic_boolean_3 = BBoolean(true);
                if(((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()))).booleanValue()) {
                    for(BInteger _ic_x_1 : interval) {
                        for(BInteger _ic_y_1 : interval) {
                            for(BInteger _ic_z_1 : interval) {
                                if(!((BBoolean(!(BBoolean(_ic_solution_1.elementOf((BTuple<BInteger, BInteger >(_ic_x_1, _ic_y_1))).booleanValue() && _ic_solution_1.elementOf((BTuple<BInteger, BInteger >(_ic_x_1, _ic_z_1))).booleanValue())).booleanValue() || _ic_y_1.equal(_ic_z_1).booleanValue()))).booleanValue()) {
                                    _ic_boolean_3 = BBoolean(false);
                                    break;
                                }

                            }
                        }
                    }
                }
                BBoolean _ic_boolean_4 = BBoolean(true);
                if(((BBoolean((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue())).booleanValue() && _ic_boolean_3.booleanValue()))).booleanValue()) {
                    for(BInteger _ic_q1_1 : interval) {
                        for(BInteger _ic_q2_1 : interval.difference((BSet<BInteger >((BInteger(1)))))) {
                            if(!((BBoolean(!_ic_q2_1.greater(_ic_q1_1).booleanValue() || (BBoolean(_ic_solution_1.functionCall(_ic_q1_1).plus(_ic_q2_1).minus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue() && _ic_solution_1.functionCall(_ic_q1_1).minus(_ic_q2_1).plus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue())).booleanValue()))).booleanValue()) {
                                _ic_boolean_4 = BBoolean(false);
                                break;
                            }

                        }
                    }
                }
                BBoolean _ic_boolean_5 = BBoolean(true);
                if(((BBoolean((BBoolean((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue())).booleanValue() && _ic_boolean_3.booleanValue())).booleanValue() && _ic_boolean_4.booleanValue()))).booleanValue()) {
                    for(BInteger _ic_x_1 : queens.domain()) {
                        if(!(_ic_solution_1.functionCall(_ic_x_1).equal(queens.functionCall(_ic_x_1))).booleanValue()) {
                            _ic_boolean_5 = BBoolean(false);
                            break;
                        }

                    }
                }

                if(((BBoolean((BBoolean((BBoolean((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue())).booleanValue() && _ic_boolean_3.booleanValue())).booleanValue() && _ic_boolean_4.booleanValue())).booleanValue() && _ic_boolean_5.booleanValue()))).booleanValue()) {
                    _ic_set_3 = _ic_set_3._union(BSet<BRelation<BInteger, BInteger >>(_ic_solution_1));
                }

            }
            return _ic_set_3;
        }

        bool _check_inv_1() const {
            return (((queens.checkDomain(interval))._and((queens.checkRange(interval)))._and((queens.isFunction()))._and((queens.isPartial(interval))))).booleanValue();
        }

        QueensWithEvents _copy() const {
            return QueensWithEvents(n, interval, allFields, queens);
        }

        friend bool operator ==(const QueensWithEvents& o1, const QueensWithEvents& o2) {
            return o1._get_queens() == o2._get_queens();
        }

        friend bool operator !=(const QueensWithEvents& o1, const QueensWithEvents& o2) {
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

        friend std::ostream& operator<<(std::ostream &strm, const QueensWithEvents &machine) {
          strm << "_get_queens: " << machine._get_queens() << "\n";
          return strm;
        }


};


static std::unordered_set<QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual> generateNextStates(std::mutex& guardMutex, const QueensWithEvents& state, bool isCaching, std::unordered_map<string, std::unordered_set<string>>& invariantDependency, std::unordered_map<QueensWithEvents, std::unordered_set<string>, QueensWithEvents::Hash, QueensWithEvents::HashEqual>& dependentInvariant, std::unordered_map<string, std::unordered_set<string>>& guardDependency, std::unordered_map<QueensWithEvents, std::unordered_set<string>, QueensWithEvents::Hash, QueensWithEvents::HashEqual>& dependentGuard, std::unordered_map<QueensWithEvents, immer::map<string, boost::any>, QueensWithEvents::Hash, QueensWithEvents::HashEqual>& guardCache, std::unordered_map<QueensWithEvents, QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual>& parents, std::atomic<int>& transitions) {
    std::unordered_set<QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual> result = std::unordered_set<QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual>();
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
        BSet<BRelation<BInteger, BInteger >> _trid_1;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_Solve"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_Solve") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_1 = state._tr_Solve();
        } else {
            _trid_1 = boost::any_cast<BSet<BRelation<BInteger, BInteger >>>(cachedValue);
        }
        newCache = newCache.set("_tr_Solve", _trid_1);
        for(const BRelation<BInteger, BInteger >& param : _trid_1) {
            BRelation<BInteger, BInteger > _tmp_1 = param;

            QueensWithEvents copiedState = state._copy();
            copiedState.Solve(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["Solve"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["Solve"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
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
        BSet<BRelation<BInteger, BInteger >> _trid_1 = state._tr_Solve();
        for(const BRelation<BInteger, BInteger >& param : _trid_1) {
            BRelation<BInteger, BInteger > _tmp_1 = param;

            QueensWithEvents copiedState = state._copy();
            copiedState.Solve(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }

    }
    return result;
}

static void printResult(int states, int transitions, bool deadlockDetected, bool invariantViolated) {
    if(deadlockDetected) {
        cout << "DEADLOCK DETECTED" << "\n";
    }
    if(invariantViolated) {
        cout << "INVARIANT VIOLATED" << "\n";
    }
    if(!deadlockDetected && !invariantViolated) {
        cout << "MODEL CHECKING SUCCESSFUL" << "\n";
    }
    cout << "Number of States: " << states << "\n";
    cout << "Number of Transitions: " << transitions << "\n";
}

static bool checkInvariants(std::mutex& guardMutex, const QueensWithEvents& state, bool isCaching, std::unordered_map<QueensWithEvents, std::unordered_set<string>, QueensWithEvents::Hash, QueensWithEvents::HashEqual>& dependentInvariant) {
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
        return true;
    }
    return !(!state._check_inv_1());
}

static QueensWithEvents next(std::list<QueensWithEvents>& collection, std::mutex& mutex, QueensWithEvents::Type type) {
    std::unique_lock<std::mutex> lock(mutex);
    switch(type) {
        case QueensWithEvents::BFS: {
            QueensWithEvents state = collection.front();
            collection.pop_front();
            return state;
        }
        case QueensWithEvents::DFS: {
            QueensWithEvents state = collection.back();
            collection.pop_back();
            return state;
        }
        case QueensWithEvents::MIXED: {
            if(collection.size() % 2 == 0) {
                QueensWithEvents state = collection.front();
                collection.pop_front();
                return state;
            } else {
                QueensWithEvents state = collection.back();
                collection.pop_back();
                return state;
            }
        }
    };
}

static void modelCheckSingleThreaded(QueensWithEvents::Type type, bool isCaching) {
    std::mutex mutex;
    std::mutex guardMutex;

    QueensWithEvents machine = QueensWithEvents();

    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    if(!machine._check_inv_1()) {
        invariantViolated = true;
    }

    std::unordered_set<QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual> states = std::unordered_set<QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<QueensWithEvents> collection = std::list<QueensWithEvents>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<QueensWithEvents, std::unordered_set<string>, QueensWithEvents::Hash, QueensWithEvents::HashEqual> dependentInvariant;
    std::unordered_map<QueensWithEvents, std::unordered_set<string>, QueensWithEvents::Hash, QueensWithEvents::HashEqual> dependentGuard;
    std::unordered_map<QueensWithEvents, immer::map<string, boost::any>, QueensWithEvents::Hash, QueensWithEvents::HashEqual> guardCache;
    std::unordered_map<QueensWithEvents, QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual> parents;
    if(isCaching) {
        invariantDependency.insert({"Solve", {"_check_inv_1"}});
        guardDependency.insert({"Solve", {"_tr_Solve"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }

    while(!collection.empty() && !stopThreads) {
        QueensWithEvents state = next(collection, mutex, type);
        std::unordered_set<QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);
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

        if(nextStates.empty()) {
            deadlockDetected = true;
            stopThreads = true;
        }

        if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
            invariantViolated = true;
            stopThreads = true;
        }

    }
    printResult(numberStates, transitions, deadlockDetected, invariantViolated);
}

static void modelCheckMultiThreaded(QueensWithEvents::Type type, int threads, bool isCaching) {
    std::mutex mutex;
    std::mutex waitMutex;
    std::mutex guardMutex;
    std::condition_variable waitCV;

    QueensWithEvents machine = QueensWithEvents();


    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    if(!machine._check_inv_1()) {
        invariantViolated = true;
    }

    std::unordered_set<QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual> states = std::unordered_set<QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<QueensWithEvents> collection = std::list<QueensWithEvents>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::atomic<int> possibleQueueChanges;
    possibleQueueChanges = 0;

    std::atomic<bool> waitFlag;
    waitFlag = true;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<QueensWithEvents, std::unordered_set<string>, QueensWithEvents::Hash, QueensWithEvents::HashEqual> dependentInvariant;
    std::unordered_map<QueensWithEvents, std::unordered_set<string>, QueensWithEvents::Hash, QueensWithEvents::HashEqual> dependentGuard;
    std::unordered_map<QueensWithEvents, immer::map<string, boost::any>, QueensWithEvents::Hash, QueensWithEvents::HashEqual> guardCache;
    std::unordered_map<QueensWithEvents, QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual> parents;
    if(isCaching) {
        invariantDependency.insert({"Solve", {"_check_inv_1"}});
        guardDependency.insert({"Solve", {"_tr_Solve"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }

    boost::asio::thread_pool workers(threads);

    while(!collection.empty() && !stopThreads) {
        possibleQueueChanges += 1;
        QueensWithEvents state = next(collection, mutex, type);
        std::packaged_task<void()> task([&, state] {
            std::unordered_set<QueensWithEvents, QueensWithEvents::Hash, QueensWithEvents::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);


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
            }

            if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
                invariantViolated = true;
                stopThreads = true;
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
    printResult(numberStates, transitions, deadlockDetected, invariantViolated);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout << "Number of arguments errorneous\n";
        return -1;
    }
    string strategy = argv[0];
    string numberThreads = argv[1];
    string caching = argv[2];

    QueensWithEvents::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = QueensWithEvents::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = QueensWithEvents::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = QueensWithEvents::Type::DFS;
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
    } else if(std::string("false").compare(strategy) == 0) {
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