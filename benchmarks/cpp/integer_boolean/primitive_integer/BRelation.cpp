#include <iostream>
#include <string>
#include <cstdarg>
#include <immer/set.hpp>
#include "BSet.cpp"
#include "BCouple.cpp"

#ifndef BRELATION_H
#define BRELATION_H

using namespace std;

template<typename S, typename T>
class BRelation : public BSet<BCouple<S,T>> {

    struct Hash {
        public:
            size_t operator()(const BCouple<S,T>& obj) const {
                return obj.hashCode();
            }
    };

    struct HashEqual {
        public:
            bool operator()(const BCouple<S,T>& obj1, const BCouple<S,T>& obj2) const {

                if (obj1 == obj2)
                    return true;
                else
                    return false;
            }
    };

    public:

        template<typename... Args>
        BRelation<S,T>(const Args&... args) {
          this->set = var(args...);
        }

        immer::set<BCouple<S,T>, Hash, HashEqual> var() {
          return immer::set<BCouple<S,T>, Hash, HashEqual>();
        }

        template<typename R, typename... Args>
        immer::set<R, Hash, HashEqual> var(const R& first, const Args&... args) {
          return var(args...).insert(first);
        }

        BRelation<S,T>() {
            this->set = immer::set<BCouple<S,T>, Hash, HashEqual>();
        }

        BRelation<S,T>(const BRelation<S,T>& set) {
            this->set = set.set;
        }

        BSet<T> relationImage(const BSet<S>& domain) {
            immer::set<T,typename BSet<T>::Hash, typename BSet<T>::HashEqual> result;
            for(BCouple<S,T> couple : this->set) {
                if(!(domain.contains(couple.getFirst()))) {
                    result = result.insert(couple.getSecond());
                }
            }
            return BSet<T>(result);
        }


        T functionCall(const S& arg) {
            for(BCouple<S,T> couple : this->set) {
                if(couple.getFirst() == arg) {
                    return couple.getSecond();
                }
            }
            throw runtime_error("Argument is not in the key set of this map");
        }

        void operator =(const BRelation<S,T>& other) {
            this->set = other.set;
        }

        int hashCode() const {
            return 0;
        }

        protected:
            immer::set<BCouple<S,T>,Hash, HashEqual> set;
};
#endif