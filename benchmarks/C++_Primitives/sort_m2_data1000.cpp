#include <iostream>
#include <string>
#include "BUtils.hpp"
#include "BSet.hpp"
#include "BTuple.hpp"
#include "BInteger.hpp"
#include "BBoolean.hpp"
#include "BRelation.hpp"

#ifndef sort_m2_data1000_H
#define sort_m2_data1000_H

using namespace std;

class sort_m2_data1000 {

    public:



    private:

        BRelation<BInteger, BInteger > f;
        BInteger n;



        BInteger j;
        BInteger k;
        BInteger l;
        BRelation<BInteger, BInteger > g;

    public:

        sort_m2_data1000() {
            BRelation<BInteger, BInteger > _ic_set_0 = BRelation<BInteger, BInteger >();
            for(BInteger _ic_i : (BSet<BInteger>::interval((BInteger(1)),(BInteger(1000))))) {
                _ic_set_0 = _ic_set_0._union(BRelation<BInteger, BInteger>(BTuple<BInteger, BInteger>(_ic_i, (BInteger(1500)).minus(_ic_i))));

            }
            f = _ic_set_0;
            n = (BInteger(1000));
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
            }
        }

        void prog1() {
            if(((BBoolean((BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue())).booleanValue() && g.functionCall(l).lessEqual(g.functionCall(j.plus((BInteger(1))))).booleanValue()))).booleanValue()) {
                BInteger _ld_j = j;
                BInteger _ld_l = l;
                l = _ld_l;
                j = _ld_j.plus((BInteger(1)));
            }
        }

        void prog2() {
            if(((BBoolean((BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue())).booleanValue() && g.functionCall(l).greater(g.functionCall(j.plus((BInteger(1))))).booleanValue()))).booleanValue()) {
                BInteger _ld_j = j;
                j = _ld_j.plus((BInteger(1)));
                l = _ld_j.plus((BInteger(1)));
            }
        }

        void final_evt() {
            if((k.equal(n)).booleanValue()) {
            }
        }

};


#endif