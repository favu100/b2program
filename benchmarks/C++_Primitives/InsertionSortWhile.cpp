#include <iostream>
#include <string>
#include "BUtils.hpp"
#include "BSet.hpp"
#include "BTuple.hpp"
#include "BInteger.hpp"
#include "BBoolean.hpp"
#include "BRelation.hpp"

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
                    while(((BBoolean(j.greaterEqual((BInteger(1))).booleanValue() && arr.functionCall(j).greater(key).booleanValue()))).booleanValue()) {
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

int main() {
    InsertionSortWhile exec;
    exec.Sort();
    return 0;
}

#endif