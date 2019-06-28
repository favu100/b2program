#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BTuple.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"
#include "BRelation.cpp"

#ifndef DataValidationTest_H
#define DataValidationTest_H

using namespace std;

class DataValidationTest {

    public:

    private:

        BInteger n;
        BSet<BInteger > ids;
        BRelation<BInteger, BInteger > value;
        BRelation<BInteger, BInteger > ids_for_value;



        BInteger counter;
        BBoolean error;
        BBoolean checked;

    public:

        DataValidationTest() {
            n = (BInteger(20000));
            ids = (BSet<BInteger>::interval((BInteger(1)),n));
            BRelation<BInteger, BInteger > _ic_set_0 = BRelation<BInteger, BInteger >();
            for(BInteger _ic_x : (BSet<BInteger>::interval((BInteger(1)),n))) {
                _ic_set_0 = _ic_set_0._union(BRelation<BInteger, BInteger>(BTuple<BInteger, BInteger>(_ic_x, _ic_x.modulo((BInteger(100))))));

            }
            value = _ic_set_0;
            ids_for_value = value.inverse();
            counter = (BInteger(0));
            error = (BBoolean(false));
            checked = (BBoolean(false));
        }

        void Validate() {
            BSet<BInteger> interval = BSet<BInteger>::interval((BInteger(0)),(BInteger(9)));
            while((counter.less(n)).booleanValue()) {
                counter = counter.plus((BInteger(1)));
                if((ids.notElementOf(counter)).booleanValue()) {
                    error = (BBoolean(false));
                } else if((interval.notElementOf(value.functionCall(counter))).booleanValue()) {
                    error = (BBoolean(false));
                } else if((ids_for_value.relationImage((BSet<BInteger >(value.functionCall(counter)))).card().less(n.divide((BInteger(100))))).booleanValue()) {
                    error = (BBoolean(false));
                }
            }
            checked = (BBoolean(true));
        }

};

int main() {
    DataValidationTest validationTest;
    validationTest.Validate();
    return 0;
}

#endif