#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BBoolean.hpp>

#ifndef Sieve_H
#define Sieve_H

using namespace std;

class Sieve {

    public:



    private:




        BSet<BInteger > numbers;
        BInteger cur;
        BInteger limit;

    public:

        Sieve() {
            numbers = (BSet<BInteger>::interval((BInteger(2)),(BInteger(1000000))));
            cur = (BInteger(2));
            limit = (BInteger(1000000));
        }

        BInteger ComputeNumberOfPrimes() {
            BInteger res;
            while(((BBoolean(cur.greater((BInteger(1))).booleanValue() && cur.multiply(cur).lessEqual(limit).booleanValue()))).booleanValue()) {
                if((numbers.elementOf(cur)).booleanValue()) {
                    BInteger n;
                    BSet<BInteger > set;
                    n = cur;
                    set = (BSet<BInteger >());
                    while((n.lessEqual(limit.divide(cur))).booleanValue()) {
                        set = set._union((BSet<BInteger >(cur.multiply(n))));
                        n = n.plus((BInteger(1)));
                    }
                    numbers = numbers.difference(set);
                } 
                cur = cur.plus((BInteger(1)));
            }
            res = numbers.card();
            return res;
        }

};

int main() {
    Sieve sieve;
    cout << sieve.ComputeNumberOfPrimes();
    return 0;
}

#endif
