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


    public:

        sort_m2_data1000_MC() {
            n = (BInteger(1000));
            BRelation<BInteger, BInteger > _ic_set_0 = BRelation<BInteger, BInteger >();
            for(BInteger _ic_i_1 : (BSet<BInteger>::interval((BInteger(1)),n))) {
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


        bool _tr_progress() const {
            return ((BBoolean(k.unequal(n).booleanValue() && j.equal(n).booleanValue()))).booleanValue();
        }

        bool _tr_prog1() const {
            return ((BBoolean((BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue())).booleanValue() && g.functionCall(l).lessEqual(g.functionCall(j.plus((BInteger(1))))).booleanValue()))).booleanValue();
        }

        bool _tr_prog2() const {
            return ((BBoolean((BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue())).booleanValue() && g.functionCall(l).greater(g.functionCall(j.plus((BInteger(1))))).booleanValue()))).booleanValue();
        }

        bool _tr_final_evt() const {
            return (k.equal(n)).booleanValue();
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

        sort_m2_data1000_MC _copy() const {
            return sort_m2_data1000_MC(n, f, j, k, l, g);
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


static std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> generateNextStates(std::mutex& guardMutex, const sort_m2_data1000_MC& state, bool isCaching, std::unordered_map<string, std::unordered_set<string>>& invariantDependency, std::unordered_map<sort_m2_data1000_MC, std::unordered_set<string>, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>& dependentInvariant, std::unordered_map<string, std::unordered_set<string>>& guardDependency, std::unordered_map<sort_m2_data1000_MC, std::unordered_set<string>, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>& dependentGuard, std::unordered_map<sort_m2_data1000_MC, immer::map<string, boost::any>, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>& guardCache, std::unordered_map<sort_m2_data1000_MC, sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>& parents, std::unordered_map<sort_m2_data1000_MC, string, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>& stateAccessedVia, std::atomic<int>& transitions) {
    std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> result = std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>();
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
            cachedValue = parentsGuard["_tr_progress"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_progress") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_1 = state._tr_progress();
        } else {
            _trid_1 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_progress", _trid_1);
        if(_trid_1) {
            sort_m2_data1000_MC copiedState = state._copy();
            copiedState.progress();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["progress"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["progress"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "progress"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_2;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_prog1"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_prog1") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_2 = state._tr_prog1();
        } else {
            _trid_2 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_prog1", _trid_2);
        if(_trid_2) {
            sort_m2_data1000_MC copiedState = state._copy();
            copiedState.prog1();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["prog1"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["prog1"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "prog1"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_3;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_prog2"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_prog2") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_3 = state._tr_prog2();
        } else {
            _trid_3 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_prog2", _trid_3);
        if(_trid_3) {
            sort_m2_data1000_MC copiedState = state._copy();
            copiedState.prog2();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["prog2"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["prog2"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "prog2"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_4;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_final_evt"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_final_evt") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_4 = state._tr_final_evt();
        } else {
            _trid_4 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_final_evt", _trid_4);
        if(_trid_4) {
            sort_m2_data1000_MC copiedState = state._copy();
            copiedState.final_evt();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["final_evt"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["final_evt"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "final_evt"});
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
        if(state._tr_progress()) {
            sort_m2_data1000_MC copiedState = state._copy();
            copiedState.progress();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "progress"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_prog1()) {
            sort_m2_data1000_MC copiedState = state._copy();
            copiedState.prog1();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "prog1"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_prog2()) {
            sort_m2_data1000_MC copiedState = state._copy();
            copiedState.prog2();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "prog2"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_final_evt()) {
            sort_m2_data1000_MC copiedState = state._copy();
            copiedState.final_evt();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "final_evt"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }

    }
    return result;
}

static void printResult(int states, int transitions, bool deadlockDetected, bool invariantViolated, sort_m2_data1000_MC& counterExampleState, std::unordered_map<sort_m2_data1000_MC, sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>& parents, std::unordered_map<sort_m2_data1000_MC, string, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>& stateAccessedVia) {
    if(deadlockDetected || invariantViolated) {
        if(deadlockDetected) {
            cout << "DEADLOCK DETECTED" << "\n";
        }
        if(invariantViolated) {
            cout << "INVARIANT VIOLATED" << "\n";
        }
        cout << "COUNTER EXAMPLE TRACE: " << "\n";

        sort_m2_data1000_MC currentState = counterExampleState;
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

static bool checkInvariants(std::mutex& guardMutex, const sort_m2_data1000_MC& state, bool isCaching, std::unordered_map<sort_m2_data1000_MC, std::unordered_set<string>, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>& dependentInvariant) {
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
        return true;
    }
    return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6());
}

static sort_m2_data1000_MC next(std::list<sort_m2_data1000_MC>& collection, std::mutex& mutex, sort_m2_data1000_MC::Type type) {
    std::unique_lock<std::mutex> lock(mutex);
    switch(type) {
        case sort_m2_data1000_MC::BFS: {
            sort_m2_data1000_MC state = collection.front();
            collection.pop_front();
            return state;
        }
        case sort_m2_data1000_MC::DFS: {
            sort_m2_data1000_MC state = collection.back();
            collection.pop_back();
            return state;
        }
        case sort_m2_data1000_MC::MIXED: {
            if(collection.size() % 2 == 0) {
                sort_m2_data1000_MC state = collection.front();
                collection.pop_front();
                return state;
            } else {
                sort_m2_data1000_MC state = collection.back();
                collection.pop_back();
                return state;
            }
        }
    };
}

static void modelCheckSingleThreaded(sort_m2_data1000_MC::Type type, bool isCaching) {
    std::mutex mutex;
    std::mutex guardMutex;

    sort_m2_data1000_MC machine = sort_m2_data1000_MC();

    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> states = std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<sort_m2_data1000_MC> collection = std::list<sort_m2_data1000_MC>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<sort_m2_data1000_MC, std::unordered_set<string>, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> dependentInvariant;
    std::unordered_map<sort_m2_data1000_MC, std::unordered_set<string>, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> dependentGuard;
    std::unordered_map<sort_m2_data1000_MC, immer::map<string, boost::any>, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> guardCache;
    std::unordered_map<sort_m2_data1000_MC, sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> parents;
    std::unordered_map<sort_m2_data1000_MC, string, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> stateAccessedVia;
    if(isCaching) {
        invariantDependency.insert({"prog2", {"_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"}});
        invariantDependency.insert({"prog1", {"_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"}});
        invariantDependency.insert({"progress", {"_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5"}});
        invariantDependency.insert({"final_evt", {}});
        guardDependency.insert({"prog2", {"_tr_progress", "_tr_prog1", "_tr_prog2"}});
        guardDependency.insert({"prog1", {"_tr_progress", "_tr_prog1", "_tr_prog2"}});
        guardDependency.insert({"progress", {"_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2"}});
        guardDependency.insert({"final_evt", {}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }
    sort_m2_data1000_MC counterExampleState;

    while(!collection.empty() && !stopThreads) {
        sort_m2_data1000_MC state = next(collection, mutex, type);

        std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);
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

static void modelCheckMultiThreaded(sort_m2_data1000_MC::Type type, int threads, bool isCaching) {
    std::mutex mutex;
    std::mutex waitMutex;
    std::mutex guardMutex;
    std::condition_variable waitCV;

    sort_m2_data1000_MC machine = sort_m2_data1000_MC();


    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> states = std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<sort_m2_data1000_MC> collection = std::list<sort_m2_data1000_MC>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::atomic<int> possibleQueueChanges;
    possibleQueueChanges = 0;

    std::atomic<bool> waitFlag;
    waitFlag = true;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<sort_m2_data1000_MC, std::unordered_set<string>, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> dependentInvariant;
    std::unordered_map<sort_m2_data1000_MC, std::unordered_set<string>, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> dependentGuard;
    std::unordered_map<sort_m2_data1000_MC, immer::map<string, boost::any>, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> guardCache;
    std::unordered_map<sort_m2_data1000_MC, sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> parents;
    std::unordered_map<sort_m2_data1000_MC, string, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> stateAccessedVia;
    if(isCaching) {
        invariantDependency.insert({"prog2", {"_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"}});
        invariantDependency.insert({"prog1", {"_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_4", "_check_inv_5"}});
        invariantDependency.insert({"progress", {"_check_inv_2", "_check_inv_3", "_check_inv_1", "_check_inv_6", "_check_inv_4", "_check_inv_5"}});
        invariantDependency.insert({"final_evt", {}});
        guardDependency.insert({"prog2", {"_tr_progress", "_tr_prog1", "_tr_prog2"}});
        guardDependency.insert({"prog1", {"_tr_progress", "_tr_prog1", "_tr_prog2"}});
        guardDependency.insert({"progress", {"_tr_final_evt", "_tr_progress", "_tr_prog1", "_tr_prog2"}});
        guardDependency.insert({"final_evt", {}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }
    sort_m2_data1000_MC counterExampleState;

    boost::asio::thread_pool workers(threads);

    while(!collection.empty() && !stopThreads) {
        possibleQueueChanges += 1;
        sort_m2_data1000_MC state = next(collection, mutex, type);
        std::packaged_task<void()> task([&, state] {
            std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);


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

    if(threads == 1) {
        modelCheckSingleThreaded(type, isCaching);
    } else {
        modelCheckMultiThreaded(type, threads, isCaching);
    }
    return 0;
}



#endif