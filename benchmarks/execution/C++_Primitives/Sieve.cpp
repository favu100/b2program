#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BInteger.hpp>

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

        BSet<BInteger > _get_numbers() const {
            return numbers;
        }

        BInteger _get_cur() const {
            return cur;
        }

        BInteger _get_limit() const {
            return limit;
        }

        friend std::ostream& operator<<(std::ostream &strm, const Sieve &machine) {
          strm << "_get_numbers: " << machine._get_numbers() << "\n";
          strm << "_get_cur: " << machine._get_cur() << "\n";
          strm << "_get_limit: " << machine._get_limit() << "\n";
          return strm;
        }

};

int main() {
    Sieve sieve;
    cout << sieve.ComputeNumberOfPrimes();
    return 0;
}

#endif