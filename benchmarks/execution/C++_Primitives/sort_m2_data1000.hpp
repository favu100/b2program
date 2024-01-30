#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BRelation.hpp>
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef sort_m2_data1000_H
#define sort_m2_data1000_H

using namespace std;

class sort_m2_data1000 {

    public:



    private:

        BInteger n;
        BRelation<BInteger, BInteger > f;



        BInteger j;
        BInteger k;
        BInteger l;
        BRelation<BInteger, BInteger > g;
    public:
        sort_m2_data1000() {
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

        void progress() {
            if(((BBoolean(k.unequal(n).booleanValue() && j.equal(n).booleanValue()))).booleanValue()) {
                BRelation<BInteger, BInteger > _ld_g = g;
                BInteger _ld_k = k;
                BInteger _ld_l = l;
                g = _ld_g.override((BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >(_ld_k, _ld_g.functionCall(_ld_l))))).override((BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >(_ld_l, _ld_g.functionCall(_ld_k)))))));
                k = _ld_k.plus((BInteger(1)));
                j = _ld_k.plus((BInteger(1)));
                l = _ld_k.plus((BInteger(1)));
            } else {
                throw StateNotReachableError();
            }

        }

        void prog1() {
            if(((BBoolean((BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue())).booleanValue() && g.functionCall(l).lessEqual(g.functionCall(j.plus((BInteger(1))))).booleanValue()))).booleanValue()) {
                BInteger _ld_j = j;
                BInteger _ld_l = l;
                l = _ld_l;
                j = _ld_j.plus((BInteger(1)));
            } else {
                throw StateNotReachableError();
            }

        }

        void prog2() {
            if(((BBoolean((BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue())).booleanValue() && g.functionCall(l).greater(g.functionCall(j.plus((BInteger(1))))).booleanValue()))).booleanValue()) {
                BInteger _ld_j = j;
                j = _ld_j.plus((BInteger(1)));
                l = _ld_j.plus((BInteger(1)));
            } else {
                throw StateNotReachableError();
            }

        }

        void final_evt() {
            if((k.equal(n)).booleanValue()) {
            } else {
                throw StateNotReachableError();
            }

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

        friend std::ostream& operator<<(std::ostream &strm, const sort_m2_data1000 &machine) {
          strm << "_get_j: " << machine._get_j() << "\n";
          strm << "_get_k: " << machine._get_k() << "\n";
          strm << "_get_l: " << machine._get_l() << "\n";
          strm << "_get_g: " << machine._get_g() << "\n";
          return strm;
        }

};


#endif