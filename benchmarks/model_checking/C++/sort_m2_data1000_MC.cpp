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

#ifndef sort_m2_data1000_MC_H
#define sort_m2_data1000_MC_H

using namespace std;

class sort_m2_data1000_MC {

    public:

        enum Type { BFS, DFS, MIXED };



        struct Hash {
            public:
                size_t operator()(const sort_m2_data1000_MC& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const sort_m2_data1000_MC& obj1, const sort_m2_data1000_MC& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

    private:

        BInteger n;
        BRelation<BInteger, BInteger > f;



        BInteger j;
        BInteger k;
        BInteger l;
        BRelation<BInteger, BInteger > g;

        mutable boost::optional<bool> _tr_cache_progress;
        mutable boost::optional<bool> _tr_cache_prog1;
        mutable boost::optional<bool> _tr_cache_prog2;
        mutable boost::optional<bool> _tr_cache_final_evt;

    public:

        std::string stateAccessedVia;

        sort_m2_data1000_MC() {
            n = (BInteger(1000));
            BRelation<BInteger, BInteger > _ic_set_0 = BRelation<BInteger, BInteger >();
            for(const BInteger& _ic_i_1 : (BSet<BInteger>::interval((BInteger(1)),n))) {
                _ic_set_0 = _ic_set_0._union(BRelation<BInteger, BInteger>(BTuple<BInteger, BInteger>(_ic_i_1, (BInteger(15000)).minus(_ic_i_1))));

            }

            f = _ic_set_0;
            g = f;
            k = (BInteger(1));
            l = (BInteger(1));
            j = (BInteger(1));
        }

        sort_m2_data1000_MC(const BInteger& n, const BRelation<BInteger, BInteger >& f, const BInteger& j, const BInteger& k, const BInteger& l, const BRelation<BInteger, BInteger >& g) {
            this->n = n;
            this->f = f;
            this->j = j;
            this->k = k;
            this->l = l;
            this->g = g;
        }

        void progress() {
            BRelation<BInteger, BInteger > _ld_g = g;
            BInteger _ld_k = k;
            BInteger _ld_l = l;
            g = _ld_g.override((BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >(_ld_k, _ld_g.functionCall(_ld_l))))).override((BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >(_ld_l, _ld_g.functionCall(_ld_k)))))));
            k = _ld_k.plus((BInteger(1)));
            j = _ld_k.plus((BInteger(1)));
            l = _ld_k.plus((BInteger(1)));

        }

        void prog1() {
            BInteger _ld_j = j;
            BInteger _ld_l = l;
            l = _ld_l;
            j = _ld_j.plus((BInteger(1)));

        }

        void prog2() {
            BInteger _ld_j = j;
            j = _ld_j.plus((BInteger(1)));
            l = _ld_j.plus((BInteger(1)));

        }

        void final_evt() {
        }

        BInteger _get_n() const {
            return n;
        }

        BRelation<BInteger, BInteger > _get_f() const {
            return f;
        }

        BInteger _get_j() const {
            return j;
        }

        BInteger _get_k() const {
            return k;
        }

        BInteger _get_l() const {
            return l;
        }

        BRelation<BInteger, BInteger > _get_g() const {
            return g;
        }


        bool _tr_progress(bool isCaching) const {
            if (this->_tr_cache_progress == boost::none){
                bool __tmp_result = ((BBoolean(k.unequal(n).booleanValue() && j.equal(n).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_progress = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_progress.get();
        }

        bool _tr_prog1(bool isCaching) const {
            if (this->_tr_cache_prog1 == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue())).booleanValue() && g.functionCall(l).lessEqual(g.functionCall(j.plus((BInteger(1))))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_prog1 = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_prog1.get();
        }

        bool _tr_prog2(bool isCaching) const {
            if (this->_tr_cache_prog2 == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue())).booleanValue() && g.functionCall(l).greater(g.functionCall(j.plus((BInteger(1))))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_prog2 = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_prog2.get();
        }

        bool _tr_final_evt(bool isCaching) const {
            if (this->_tr_cache_final_evt == boost::none){
                bool __tmp_result = (k.equal(n)).booleanValue();
                if (isCaching) this->_tr_cache_final_evt = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_final_evt.get();
        }

        bool _check_inv_1() const {
            return (j.greaterEqual(k)).booleanValue();
        }

        bool _check_inv_2() const {
            return (j.lessEqual(n)).booleanValue();
        }

        bool _check_inv_3() const {
            return (l.greaterEqual(k)).booleanValue();
        }

        bool _check_inv_4() const {
            return (j.lessEqual(j)).booleanValue();
        }

        bool _check_inv_5() const {
            return (g.functionCall(l).equal(g.relationImage((BSet<BInteger>::interval(k,j))).min())).booleanValue();
        }

        bool _check_inv_6() const {
            return (((g.checkDomain((BSet<BInteger>::interval((BInteger(1)),n))))._and((g.checkRangeNatural()))._and((g.isFunction()))._and((g.isTotal((BSet<BInteger>::interval((BInteger(1)),n))))))).booleanValue();
        }

        static constexpr unsigned int strHash(const char *s, int off = 0) {
            return !s[off] ? 5381 : (strHash(s, off+1)*33) ^ s[off];
        }

        sort_m2_data1000_MC _copy(unordered_set<string> toInvalidate) const {
            static const char* allTransitions[] = {"_tr_progress", "_tr_prog1", "_tr_prog2", "_tr_final_evt"};

            sort_m2_data1000_MC result = sort_m2_data1000_MC(n, f, j, k, l, g);

            for (const auto &item : allTransitions) {
                if(toInvalidate.find(item) == toInvalidate.end()) {
                    switch(strHash(item)) {
                        case strHash("_tr_progress"): result._tr_cache_progress = this->_tr_cache_progress; break;
                        case strHash("_tr_prog1"): result._tr_cache_prog1 = this->_tr_cache_prog1; break;
                        case strHash("_tr_prog2"): result._tr_cache_prog2 = this->_tr_cache_prog2; break;
                        case strHash("_tr_final_evt"): result._tr_cache_final_evt = this->_tr_cache_final_evt; break;
                        default: cout << "Transition " << item << " not found!";
                    }
                }
            }
            return result;
        }

        friend bool operator ==(const sort_m2_data1000_MC& o1, const sort_m2_data1000_MC& o2) {
            return o1._get_j() == o2._get_j() && o1._get_k() == o2._get_k() && o1._get_l() == o2._get_l() && o1._get_g() == o2._get_g();
        }

        friend bool operator !=(const sort_m2_data1000_MC& o1, const sort_m2_data1000_MC& o2) {
            return o1._get_j() != o2._get_j() || o1._get_k() != o2._get_k() || o1._get_l() != o2._get_l() || o1._get_g() != o2._get_g();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_j()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_k()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_l()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_g()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_j()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_k()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_l()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_g()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const sort_m2_data1000_MC &machine) {
          strm << "_get_j: " << machine._get_j() << "\n";
          strm << "_get_k: " << machine._get_k() << "\n";
          strm << "_get_l: " << machine._get_l() << "\n";
          strm << "_get_g: " << machine._get_g() << "\n";
          return strm;
        }


};


class ModelChecker {
    private:
        sort_m2_data1000_MC::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<sort_m2_data1000_MC> unvisitedStates;
        std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex guardMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        sort_m2_data1000_MC counterExampleState;

        std::unordered_map<string, std::unordered_set<string>> invariantDependency;
        std::unordered_map<string, std::unordered_set<string>> guardDependency;
        std::unordered_map<sort_m2_data1000_MC, sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(sort_m2_data1000_MC::Type type, int threads, bool isCaching, bool isDebug) {
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
            sort_m2_data1000_MC machine = sort_m2_data1000_MC();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            if (isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.empty()) {
                sort_m2_data1000_MC state = next();

                std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> nextStates = generateNextStates(state);
                transitions += nextStates.size();

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
            sort_m2_data1000_MC machine = sort_m2_data1000_MC();
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
                sort_m2_data1000_MC state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> nextStates = generateNextStates(state);
                    transitions += nextStates.size();

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

        void initCache(sort_m2_data1000_MC& machine) {
            invariantDependency.insert({"prog2", {"_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"}});
            invariantDependency.insert({"prog1", {"_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"}});
            invariantDependency.insert({"progress", {"_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5"}});
            invariantDependency.insert({"final_evt", {}});
            invariantDependency.insert({"", {}});
            guardDependency.insert({"prog2", {"_tr_progress", "_tr_prog1", "_tr_prog2"}});
            guardDependency.insert({"prog1", {"_tr_progress", "_tr_prog1", "_tr_prog2"}});
            guardDependency.insert({"progress", {"_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2"}});
            guardDependency.insert({"final_evt", {}});
        }


    private:
        sort_m2_data1000_MC next() {
            std::unique_lock<std::mutex> lock(mutex);
            switch(type) {
                case sort_m2_data1000_MC::BFS: {
                    sort_m2_data1000_MC state = unvisitedStates.front();
                    unvisitedStates.pop_front();
                    return state;
                }
                case sort_m2_data1000_MC::DFS: {
                    sort_m2_data1000_MC state = unvisitedStates.back();
                    unvisitedStates.pop_back();
                    return state;
                }
                case sort_m2_data1000_MC::MIXED: {
                    if(unvisitedStates.size() % 2 == 0) {
                        sort_m2_data1000_MC state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    } else {
                        sort_m2_data1000_MC state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                }
            }
        }

        std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> generateNextStates(const sort_m2_data1000_MC& state) {
            std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> result = std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>();
            if(state._tr_progress(isCaching)) {
                sort_m2_data1000_MC copiedState = state._copy(guardDependency["progress"]);
                copiedState.progress();
                copiedState.stateAccessedVia = "progress";
                result.insert(copiedState);
            }
            if(state._tr_prog1(isCaching)) {
                sort_m2_data1000_MC copiedState = state._copy(guardDependency["prog1"]);
                copiedState.prog1();
                copiedState.stateAccessedVia = "prog1";
                result.insert(copiedState);
            }
            if(state._tr_prog2(isCaching)) {
                sort_m2_data1000_MC copiedState = state._copy(guardDependency["prog2"]);
                copiedState.prog2();
                copiedState.stateAccessedVia = "prog2";
                result.insert(copiedState);
            }
            if(state._tr_final_evt(isCaching)) {
                sort_m2_data1000_MC copiedState = state._copy(guardDependency["final_evt"]);
                copiedState.final_evt();
                copiedState.stateAccessedVia = "final_evt";
                result.insert(copiedState);
            }

            return result;
        }

        bool invariantViolated(const sort_m2_data1000_MC& state) {
            if(isCaching) {
                std::unordered_set<string> dependentInvariantsOfState = invariantDependency[state.stateAccessedVia];
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
                if(dependentInvariantsOfState.find("_check_inv_3") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_3()) {
                        return false;
                    }
                }
                if(dependentInvariantsOfState.find("_check_inv_4") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_4()) {
                        return false;
                    }
                }
                if(dependentInvariantsOfState.find("_check_inv_5") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_5()) {
                        return false;
                    }
                }
                if(dependentInvariantsOfState.find("_check_inv_6") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_6()) {
                        return false;
                    }
                }
                return false;
            }
            return !(state._check_inv_1() && state._check_inv_2() && state._check_inv_3() && state._check_inv_4() && state._check_inv_5() && state._check_inv_6());
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

    sort_m2_data1000_MC::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = sort_m2_data1000_MC::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = sort_m2_data1000_MC::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = sort_m2_data1000_MC::Type::DFS;
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