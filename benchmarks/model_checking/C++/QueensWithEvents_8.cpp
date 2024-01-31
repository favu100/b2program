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
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BRelation.hpp>
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef QueensWithEvents_8_H
#define QueensWithEvents_8_H

using namespace std;

class QueensWithEvents_8 {

    public:

        enum Type { BFS, DFS, MIXED };



        struct Hash {
            public:
                size_t operator()(const QueensWithEvents_8& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const QueensWithEvents_8& obj1, const QueensWithEvents_8& obj2) const {
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

        mutable boost::optional<BSet<BRelation<BInteger, BInteger >>> _tr_cache_Solve;

    public:

        std::string stateAccessedVia;

        QueensWithEvents_8() {
            n = (BInteger(8));
            interval = (BSet<BInteger>::interval((BInteger(1)),n));
            allFields = (BRelation<BInteger, BInteger >::cartesianProduct(interval, interval)).pow();
            queens = (BRelation<BInteger, BInteger >());
        }

        QueensWithEvents_8(const BInteger& n, const BSet<BInteger >& interval, const BSet<BRelation<BInteger, BInteger > >& allFields, const BRelation<BInteger, BInteger >& queens) {
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


        BSet<BRelation<BInteger, BInteger >> _tr_Solve(bool isCaching) const {
            if (this->_tr_cache_Solve == boost::none){
                BSet<BRelation<BInteger, BInteger >> _ic_set_4 = BSet<BRelation<BInteger, BInteger >>();
                for(const BRelation<BInteger, BInteger >& _ic_solution_1 : allFields) {
                    BBoolean _ic_boolean_5 = BBoolean(true);
                    for(const BInteger& _ic_x_1 : interval) {
                        for(const BInteger& _ic_y_1 : interval) {
                            BBoolean _ic_boolean_4 = BBoolean(true);
                            for(const BInteger& _ic_z_1 : interval) {
                                if(!((BBoolean(!_ic_solution_1.elementOf((BTuple<BInteger, BInteger >(_ic_x_1, _ic_z_1))).booleanValue() || _ic_y_1.equal(_ic_z_1).booleanValue()))).booleanValue()) {
                                    _ic_boolean_4 = BBoolean(false);
                                    break;
                                }

                            }
                            if(((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue()))).booleanValue()) {
                                if(!((BBoolean(!_ic_solution_1.elementOf((BTuple<BInteger, BInteger >(_ic_x_1, _ic_y_1))).booleanValue() || _ic_boolean_4.booleanValue()))).booleanValue()) {
                                    _ic_boolean_5 = BBoolean(false);
                                    break;
                                }
                            }

                        }
                    }BBoolean _ic_boolean_6 = BBoolean(true);
                    for(const BInteger& _ic_q1_1 : interval) {
                        for(const BInteger& _ic_q2_1 : interval.difference((BSet<BInteger >((BInteger(1)))))) {
                            if(((BBoolean((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue())).booleanValue() && _ic_boolean_5.booleanValue()))).booleanValue()) {
                                if(!((BBoolean(!_ic_q2_1.greater(_ic_q1_1).booleanValue() || (BBoolean(_ic_solution_1.functionCall(_ic_q1_1).plus(_ic_q2_1).minus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue() && _ic_solution_1.functionCall(_ic_q1_1).minus(_ic_q2_1).plus(_ic_q1_1).unequal(_ic_solution_1.functionCall(_ic_q2_1)).booleanValue())).booleanValue()))).booleanValue()) {
                                    _ic_boolean_6 = BBoolean(false);
                                    break;
                                }
                            }

                        }
                    }BBoolean _ic_boolean_7 = BBoolean(true);
                    for(const BInteger& _ic_x_1 : queens.domain()) {
                        if(((BBoolean((BBoolean((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue())).booleanValue() && _ic_boolean_5.booleanValue())).booleanValue() && _ic_boolean_6.booleanValue()))).booleanValue()) {
                            if(!(_ic_solution_1.functionCall(_ic_x_1).equal(queens.functionCall(_ic_x_1))).booleanValue()) {
                                _ic_boolean_7 = BBoolean(false);
                                break;
                            }
                        }

                    }
                    if(((BBoolean((BBoolean((BBoolean((BBoolean(_ic_solution_1.domain().equal(interval).booleanValue() && _ic_solution_1.range().equal(interval).booleanValue())).booleanValue() && _ic_boolean_5.booleanValue())).booleanValue() && _ic_boolean_6.booleanValue())).booleanValue() && _ic_boolean_7.booleanValue()))).booleanValue()) {
                        _ic_set_4 = _ic_set_4._union(BSet<BRelation<BInteger, BInteger >>(_ic_solution_1));
                    }

                }
                if (isCaching) this->_tr_cache_Solve = _ic_set_4;
                else return _ic_set_4;
            }
            return this->_tr_cache_Solve.get();
        }

        bool _check_inv_1() const {
            return (((queens.checkDomain(interval))._and((queens.checkRange(interval)))._and((queens.isFunction()))._and((queens.isPartial(interval))))).booleanValue();
        }

        static constexpr unsigned int strHash(const char *s, int off = 0) {
            return !s[off] ? 5381 : (strHash(s, off+1)*33) ^ s[off];
        }

        QueensWithEvents_8 _copy(unordered_set<string> toInvalidate) const {
            static const char* allTransitions[] = {"_tr_Solve"};

            QueensWithEvents_8 result = QueensWithEvents_8(n, interval, allFields, queens);

            for (const auto &item : allTransitions) {
                if(toInvalidate.find(item) == toInvalidate.end()) {
                    switch(strHash(item)) {
                        case strHash("_tr_Solve"): result._tr_cache_Solve = this->_tr_cache_Solve; break;
                        default: cout << "Transition " << item << " not found!";
                    }
                }
            }
            return result;
        }

        friend bool operator ==(const QueensWithEvents_8& o1, const QueensWithEvents_8& o2) {
            return o1._get_queens() == o2._get_queens();
        }

        friend bool operator !=(const QueensWithEvents_8& o1, const QueensWithEvents_8& o2) {
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

        friend std::ostream& operator<<(std::ostream &strm, const QueensWithEvents_8 &machine) {
          strm << "_get_queens: " << machine._get_queens() << "\n";
          return strm;
        }


};


class ModelChecker {
    private:
        QueensWithEvents_8::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<QueensWithEvents_8> unvisitedStates;
        std::unordered_set<QueensWithEvents_8, QueensWithEvents_8::Hash, QueensWithEvents_8::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex guardMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        QueensWithEvents_8 counterExampleState;

        std::unordered_map<string, std::unordered_set<string>> invariantDependency;
        std::unordered_map<string, std::unordered_set<string>> guardDependency;
        std::unordered_map<QueensWithEvents_8, QueensWithEvents_8, QueensWithEvents_8::Hash, QueensWithEvents_8::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(QueensWithEvents_8::Type type, int threads, bool isCaching, bool isDebug) {
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
            QueensWithEvents_8 machine = QueensWithEvents_8();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            if (isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.empty()) {
                QueensWithEvents_8 state = next();

                std::unordered_set<QueensWithEvents_8, QueensWithEvents_8::Hash, QueensWithEvents_8::HashEqual> nextStates = generateNextStates(state);

                for(auto& nextState : nextStates) {
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
            QueensWithEvents_8 machine = QueensWithEvents_8();
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
                QueensWithEvents_8 state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<QueensWithEvents_8, QueensWithEvents_8::Hash, QueensWithEvents_8::HashEqual> nextStates = generateNextStates(state);

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

        void initCache(QueensWithEvents_8& machine) {
            invariantDependency.insert({"Solve", {"_check_inv_1"}});
            invariantDependency.insert({"", {}});
            guardDependency.insert({"Solve", {"_tr_Solve"}});
        }


    private:
        QueensWithEvents_8 next() {
            std::unique_lock<std::mutex> lock(mutex);
            switch(type) {
                case QueensWithEvents_8::BFS: {
                    QueensWithEvents_8 state = unvisitedStates.front();
                    unvisitedStates.pop_front();
                    return state;
                }
                case QueensWithEvents_8::DFS: {
                    QueensWithEvents_8 state = unvisitedStates.back();
                    unvisitedStates.pop_back();
                    return state;
                }
                case QueensWithEvents_8::MIXED: {
                    if(unvisitedStates.size() % 2 == 0) {
                        QueensWithEvents_8 state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    } else {
                        QueensWithEvents_8 state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                }
            };
        }

        std::unordered_set<QueensWithEvents_8, QueensWithEvents_8::Hash, QueensWithEvents_8::HashEqual> generateNextStates(const QueensWithEvents_8& state) {
            std::unordered_set<QueensWithEvents_8, QueensWithEvents_8::Hash, QueensWithEvents_8::HashEqual> result = std::unordered_set<QueensWithEvents_8, QueensWithEvents_8::Hash, QueensWithEvents_8::HashEqual>();
            BSet<BRelation<BInteger, BInteger >> _trid_1 = state._tr_Solve(isCaching);
            for(const BRelation<BInteger, BInteger >& param : _trid_1) {
                BRelation<BInteger, BInteger > _tmp_1 = param;

                QueensWithEvents_8 copiedState = state._copy(guardDependency["Solve"]);
                copiedState.Solve(_tmp_1);
                copiedState.stateAccessedVia = "Solve";
                result.insert(copiedState);
                transitions += 1;
            }

            return result;
        }

        bool invariantViolated(const QueensWithEvents_8& state) {
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

    QueensWithEvents_8::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = QueensWithEvents_8::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = QueensWithEvents_8::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = QueensWithEvents_8::Type::DFS;
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

    bool isDebug = false;
    // TODO

    ModelChecker modelchecker(type, threads, isCaching, isDebug);
    modelchecker.modelCheck();

    return 0;
}



#endif