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



    private:



        BSet<BInteger > numbers;
        BInteger cur;
        BInteger limit;

    public:

        Sieve() {
            numbers = static_cast<BSet<BInteger > >((BSet<BInteger>::range((BInteger(2)),(BInteger(10000)))));
            cur = static_cast<BInteger >((BInteger(2)));
            limit = static_cast<BInteger >((BInteger(10000)));
        }

        BInteger ComputeNumberOfPrimes() {
            BInteger res;
            while((cur.greater((BInteger(1)))._and(cur.multiply(cur).lessEqual(limit))).booleanValue()) {
                if((numbers.elementOf(cur)).booleanValue()) {
                    BInteger n;
                    BSet<BInteger > set;
                    n = static_cast<BInteger >(cur);
                    set = static_cast<BSet<BInteger > >((BSet<BInteger >()));
                    while((n.lessEqual(limit.divide(cur))).booleanValue()) {
                        set = static_cast<BSet<BInteger > >(set._union((BSet<BInteger >(cur.multiply(n)))));
                        n = static_cast<BInteger >(n.plus((BInteger(1))));
                    }
                    numbers = static_cast<BSet<BInteger > >(numbers.complement(set));
                } 
                cur = static_cast<BInteger >(cur.plus((BInteger(1))));
            }
            res = static_cast<BInteger >(numbers.card());
            return res;
        }

};
int main() {
    clock_t start,finish;
    double time;
    Sieve exec;
    start = clock();
    exec.ComputeNumberOfPrimes();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

