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
            numbers = (BSet<BInteger>::range((BInteger(2)),(BInteger(10000))));
            cur = (BInteger(2));
            limit = (BInteger(10000));
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
    clock_t start,finish;
    double time;
    Sieve exec;
    start = clock();
    BInteger result = exec.ComputeNumberOfPrimes();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    printf("%d\n", result.intValue());
    return 0;
}
#endif

