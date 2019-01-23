#include <iostream>
#include <string>
#include <cstdarg>
#include "BSet.cpp"
#include "BCouple.cpp"

#ifndef BRELATION_H
#define BRELATION_H

using namespace std;

template<typename S, typename T>
class BRelation<S,T> : public BSet<BCouple<S,T>> {

    BSet<T> relationImage(const BSet<S>& domain) {
        immer::set<T,Hash, HashEqual> result;
        for(typename immer::set<BCouple<S,T>,Hash, HashEqual>::const_iterator it = this->set.begin(); it != this->set.end(); ++it) {
            BCouple<S,T> couple = *it;
            if(domain.set.count(couple.getFirst()) == 0) {
                result = result.insert(couple.getSecond());
            }
        }
        return BSet(result);
    }


    T functionCall(const S& arg) {
        for(typename immer::set<<BCouple<S,T>>,Hash, HashEqual>::const_iterator it = this->set.begin(); it != this->set.end(); ++it) {
            BCouple<S,T> couple = *it;
            if(couple.getFirst() == arg) {
                return couple.getSecond();
            }
        }
        throw runtime_error("Argument is not in the key set of this map");
    }

}