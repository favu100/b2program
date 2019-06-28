#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BTuple.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"
#include "BRelation.cpp"

#ifndef InsertionSortWhile_H
#define InsertionSortWhile_H

using namespace std;

class InsertionSortWhile {

    public:



    private:

        BInteger n;



        BRelation<BInteger, BInteger > arr;
        BBoolean sorted;

    public:

        InsertionSortWhile() {
            n = (BInteger(1000));
            BRelation<BInteger, BInteger > _ic_set_0 = BRelation<BInteger, BInteger >();
            for(BInteger _ic_i : (BSet<BInteger>::interval((BInteger(1)),n))) {
                _ic_set_0 = _ic_set_0._union(BRelation<BInteger, BInteger>(BTuple<BInteger, BInteger>(_ic_i, n.minus(_ic_i))));

            }
            arr = _ic_set_0;
            sorted = (BBoolean(false));
        }

        void Sort() {
            if((sorted.equal((BBoolean(false)))).booleanValue()) {
                BInteger i;
                i = (BInteger(2));
                while((i.lessEqual(n)).booleanValue()) {
                    BInteger key;
                    BInteger j;
                    key = arr.functionCall(i);
                    j = i.minus((BInteger(1)));
                    while((j.greaterEqual((BInteger(1)))._and(arr.functionCall(j).greater(key))).booleanValue()) {
                        arr = arr.override(BRelation<BInteger, BInteger>(BTuple<BInteger, BInteger>(j.plus((BInteger(1))),arr.functionCall(j))));
                        j = j.minus((BInteger(1)));
                    }
                    arr = arr.override(BRelation<BInteger, BInteger>(BTuple<BInteger, BInteger>(j.plus((BInteger(1))),key)));
                    i = i.plus((BInteger(1)));
                }
                sorted = (BBoolean(true));
            }
        }

};


#endif