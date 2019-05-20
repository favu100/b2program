#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BInteger.cpp"
#include "BBoolean.cpp"

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
            numbers = (BSet<BInteger>::interval((BInteger(2)),(BInteger(2000000))));
            cur = (BInteger(2));
            limit = (BInteger(2000000));
        }

        BInteger ComputeNumberOfPrimes() {
            BInteger res;
            while((cur.greater((BInteger(1)))._and(cur.multiply(cur).lessEqual(limit))).booleanValue()) {
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
    sieve.ComputeNumberOfPrimes();
}


#endif