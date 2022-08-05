#include <iostream>
#include <string>
#include <cstdarg>
#include <cstddef>
#include <immer/set.hpp>
#include <immer/map.hpp>


#include "BTuple.hpp"
#include "BSet.hpp"
#include "BStruct.hpp"

#ifndef BRELATION_H
#define BRELATION_H


using namespace std;

template<typename S, typename T>
class BRelation : public BObject {

    public:

        struct BRelationIterator {

            using iterator_category = std::forward_iterator_tag;
            using difference_type = std::ptrdiff_t;
            using value_type = BTuple<S,T>;

            BRelationIterator(const BRelation<S,T>& rel):
                relation(rel),
                keyIterator(((this->relation).map).begin()),
                valueIterator(keyIterator == ((this->relation).map).end() ? BSet<T>().getSet().end() : ((this->relation).map[(*keyIterator).first]).begin())
            {}

            BTuple<S,T> operator*() const {
                return BTuple<S,T>((*keyIterator).first, *valueIterator);
            }

            BTuple<S,T>* operator->() const {
                return new BTuple<S,T>((*keyIterator).first, *valueIterator);
            }

            // Prefix increment
            BRelationIterator& operator++() {
                valueIterator++;
                if(keyIterator != ((this->relation).map).end() && valueIterator == ((this->relation).map[(*keyIterator).first]).end()) {
                    keyIterator++;
                    if(keyIterator != ((this->relation).map).end()) {
                        valueIterator = ((this->relation).map[(*keyIterator).first]).begin();
                    }
                }
                return *this;
            }

            // Postfix increment
            BRelationIterator operator++(int) {
                BRelationIterator tmp = *this;
                valueIterator++;
                if(keyIterator != ((this->relation).map).end() && valueIterator == ((this->relation).map[(*keyIterator).first]).end()) {
                    keyIterator++;
                    if(keyIterator != ((this->relation).map).end()) {
                        valueIterator = ((this->relation).map[(*keyIterator).first]).begin();
                    }
                }
                return tmp;
            }

            friend bool operator==(const BRelationIterator& a, const BRelationIterator& b) {
                return (a.keyIterator == b.keyIterator && a.keyIterator == ((a.relation).map).end()) || (a.keyIterator == b.keyIterator && a.valueIterator == b.valueIterator);
            };

            friend bool operator!=(const BRelationIterator& a, const BRelationIterator& b) {
                return !((a.keyIterator == b.keyIterator && a.keyIterator == ((a.relation).map).end()) || (a.keyIterator == b.keyIterator && a.valueIterator == b.valueIterator));
            };

            public:
                BRelation<S,T> relation;
                typename immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                   typename BSet<S>::Hash,
                                                                   typename BSet<S>::HashEqual>::const_iterator keyIterator;
                typename immer::set<T,typename BSet<T>::Hash, typename BSet<T>::HashEqual>::const_iterator valueIterator;


        };

        typedef BRelation<S,T> current_type;
        typedef BTuple<S,T> value_type;
        typedef S left_type;
        typedef T right_type;


        BRelation<S,T>(const immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                        typename BSet<S>::Hash,
                                        typename BSet<S>::HashEqual>& elements) {
            this->map = elements;
        }

        template<typename... Args>
        BRelation<S,T>(const Args&... args) {
          this->map = var(args...);
        }

        immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                typename BSet<S>::Hash,
                                                typename BSet<S>::HashEqual> var() {
          return immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                 typename BSet<S>::Hash,
                                                                 typename BSet<S>::HashEqual>();
        }

        template<typename R, typename... Args>
        immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                typename BSet<S>::Hash,
                                                typename BSet<S>::HashEqual> var(const R& first, const Args&... args) {
            BTuple<S,T> tuple = (BTuple<S,T>) first;
            S lhs = tuple.projection1();
            T rhs = tuple.projection2();

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                typename BSet<S>::Hash,
                                                typename BSet<S>::HashEqual> map = var(args...);
            const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* rangePtr = map.find(lhs);
            if(rangePtr == nullptr) {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet;
                resultSet = resultSet.insert(rhs);
                map = map.set(lhs, resultSet);
            } else {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet = *rangePtr;
                resultSet = resultSet.insert(rhs);
                map = map.set(lhs, resultSet);
            }
            return map;
        }

        BRelation<S,T>() {
            this->map = immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                        typename BSet<S>::Hash,
                                                                        typename BSet<S>::HashEqual>();
        }

        BRelation<S,T>(const BRelation<S,T>& relation) {
            this->map = relation.map;
        }

        BRelation<S,T>(const BSet<BTuple<S,T>>& set) {
            this->map = immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                        typename BSet<S>::Hash,
                                                                        typename BSet<S>::HashEqual>();

            immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual> otherSet = set.getSet();
            for(const BTuple<S,T>& tuple : otherSet) {
                S first = tuple.projection1();
                T second = tuple.projection2();
                const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* rangePtr = this->map.find(first);
                if(rangePtr == nullptr) {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet;
                    resultSet = resultSet.insert(second);
                    this->map = this->map.set(first, resultSet);
                } else {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet = *rangePtr;
                    resultSet = resultSet.insert(second);
                    this->map = this->map.set(first, resultSet);
                }
            }
        }

        BRelation<S,T>(const immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual>& otherSet) {
            this->map = immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                        typename BSet<S>::Hash,
                                                                        typename BSet<S>::HashEqual>();

            for(const BTuple<S,T>& tuple : otherSet) {
                S first = tuple.projection1();
                T second = tuple.projection2();
                const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* rangePtr = this->map.find(first);
                if(rangePtr == nullptr) {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet;
                    resultSet = resultSet.insert(second);
                    this->map = this->map.set(first, resultSet);
                } else {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet = *rangePtr;
                    resultSet = resultSet.insert(second);
                    this->map = this->map.set(first, resultSet);
                }
            }
        }

        BRelation<S,T> intersect(const BRelation<S,T>& relation) const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> otherMap = relation.map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;

            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : thisMap) {
                S domainElement = pair.first;
                const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* otherRangePtr = otherMap.find(domainElement);
                if(otherRangePtr == nullptr) {
                    resultMap = resultMap.erase(domainElement);
                } else {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> otherRange = *otherRangePtr;
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> thisRange = thisMap[domainElement];
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet = otherRange;
                    for(const T& rangeElement : otherRange) {
                        if(thisRange.count(rangeElement) == 0) {
                            resultSet = resultSet.erase(rangeElement);
                        }
                    }
                    if(resultSet.size() == 0) {
                        resultMap = resultMap.erase(domainElement);
                    } else {
                        resultMap = resultMap.set(domainElement, resultSet);
                    }
                }
            }
            return BRelation<S,T>(resultMap);
        }

        BRelation<S,T> difference(const BRelation<S,T>& relation) const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> otherMap = relation.map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;

            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : thisMap) {
                S domainElement = pair.first;
                const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* otherRangePtr = otherMap.find(domainElement);
                if(otherRangePtr != nullptr) {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> otherRange = *otherRangePtr;
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> thisRange = thisMap[domainElement];
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet = thisRange;
                    for(const T& rangeElement : otherRange) {
                        if(thisRange.count(rangeElement) > 0) {
                            resultSet = resultSet.erase(rangeElement);
                        }
                    }
                    if(resultSet.size() == 0) {
                        resultMap = resultMap.erase(domainElement);
                    } else {
                        resultMap = resultMap.set(domainElement, resultSet);
                    }
                }
            }
            return BRelation<S,T>(resultMap);
        }

        BRelation<S,T> _union(const BRelation<S,T>& relation) {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> otherMap = relation.map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;

            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : otherMap) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> otherRange = pair.second;
                const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* thisRangePtr = thisMap.find(domainElement);
                if(thisRangePtr == nullptr) {
                    resultMap = resultMap.set(domainElement, otherRange);
                } else {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> thisRange = *thisRangePtr;
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet = *thisRangePtr;
                    for(const T& rangeElement : otherRange) {
                        if(thisRange.count(rangeElement) == 0) {
                            resultSet = resultSet.insert(rangeElement);
                        }
                    }
                    resultMap = resultMap.set(domainElement, resultSet);
                }
            }
            return BRelation<S,T>(resultMap);
        }

        int size() const {
            int size = 0;
            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : this->map) {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> thisRangeSet = pair.second;
                size += thisRangeSet.size();
            }
            return size;
        }

        BInteger card() const {
            return BInteger(this->size());
        }

        BInteger _size() const {
            return BInteger(this->size());
        }

        BSet<T> relationImage(const BSet<S>& domain) const {
            immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet;

            immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> domainSet = domain.getSet();
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;
            for (const S& obj : domainSet) {
                const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* rangePtr = thisMap.find(obj);
                if(rangePtr == nullptr) {
                    continue;
                }
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = *rangePtr;
                for (const T& rangeElement : range) {
                    if(resultSet.count(rangeElement) == 0) {
                        resultSet = resultSet.insert(rangeElement);
                    }
                }
            }
            return BSet<T>(resultSet);
        }

        T functionCall(const S& arg) const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;
            const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* rangePtr = thisMap.find(arg);
            if(rangePtr == nullptr) {
                throw runtime_error("Argument is not in the domain of this function");
            }
            immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = *rangePtr;
            for (const T& rangeElement : range) {
                return rangeElement;
            }
            throw runtime_error("Argument is not in the domain of this function");
        }


        template<typename R,typename A>
        static BRelation<R,A> cartesianProduct(const BSet<R> arg1, const BSet<A>& arg2) {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap;
            for(const R& e1 : arg1.getSet()) {
                if(arg2.size() > 0) {
                    resultMap = resultMap.set(e1, arg2.getSet());
                }
            }

            return BRelation<R,A>(resultMap);
        }

        template<typename R,typename A,typename B>
        static BRelation<BTuple<R,A>,B> cartesianProduct(const BRelation<R,A> arg1, const BSet<B>& arg2) {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,                                 typename BSet<S>::HashEqual> resultMap;
            for(const BTuple<R,A>& e1 : arg1) {
                if(arg2.size() > 0) {
                    resultMap = resultMap.set(e1, arg2.getSet());
                }
            }
            return BRelation<BTuple<R,A>,B>(resultMap);
        }

    	BSet<S> domain() const {
            immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> resultSet;
            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : this->map) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> thisRangeSet = pair.second;
                if(thisRangeSet.size() > 0) {
                    resultSet = resultSet.insert(domainElement);
                }
            }
            return BSet<S>(resultSet);
    	}

    	BSet<T> range() const {
            immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet;
            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : this->map) {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> thisRangeSet = pair.second;
                for (const T& obj : thisRangeSet) {
                    if(resultSet.count(obj) == 0) {
                        resultSet = resultSet.insert(obj);
                    }
                }
            }
            return BSet<T>(resultSet);
    	}

        BRelation<T,S> inverse() const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<T,immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual>,
                                                               typename BSet<T>::Hash,
                                                               typename BSet<T>::HashEqual> resultMap;


            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : this->map) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = pair.second;
                for(const T& rangeElement : range) {
                    const immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual>* currentRangePtr = resultMap.find(rangeElement);
                    immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> currentRange;
                    if(currentRangePtr != nullptr) {
                        currentRange = *currentRangePtr;
                    }
                    currentRange = currentRange.insert(domainElement);
                    resultMap = resultMap.set(rangeElement, currentRange);
                }
            }
            return BRelation<T,S>(resultMap);
        }

        BRelation<S,T> domainRestriction(const BSet<S>& arg) const {
            immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> otherSet = arg.getSet();

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;

            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : this->map) {
                S domainElement = pair.first;
                if(otherSet.count(domainElement) == 0) {
                    resultMap = resultMap.erase(domainElement);
                }
            }
            return BRelation<S,T>(resultMap);
        }

        BRelation<S,T> domainSubstraction(const BSet<S>& arg) const {
            immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> otherSet = arg.getSet();

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;
            for(const S& domainElement : otherSet) {
                resultMap = resultMap.erase(domainElement);
            }
            return BRelation<S,T>(resultMap);
        }

        BRelation<S,T> rangeRestriction(const BSet<T>& arg) const {
            immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> otherSet = arg.getSet();

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;

            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : thisMap) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = pair.second;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultRange = range;

                for(const T& rangeElement : range) {
                    if(otherSet.count(rangeElement) == 0) {
                        resultRange = resultRange.erase(rangeElement);
                    }
                }

                if(resultRange.size() == 0) {
                    resultMap = resultMap.erase(domainElement);
                } else {
                    resultMap = resultMap.set(domainElement, resultRange);
                }
            }
            return BRelation<S,T>(resultMap);
        }

        BRelation<S,T> rangeSubstraction(const BSet<T>& arg) const {
            immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> otherSet = arg.getSet();

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;

            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : thisMap) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = pair.second;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultRange = range;

                for(const T& rangeElement : range) {
                    if(otherSet.count(rangeElement) > 0) {
                        resultRange = resultRange.erase(rangeElement);
                    }
                }

                if(resultRange.size() == 0) {
                    resultMap = resultMap.erase(domainElement);
                } else {
                    resultMap = resultMap.set(domainElement, resultRange);
                }
            }
            return BRelation<S,T>(resultMap);
        }

        BBoolean subset(const BRelation<S,T>& arg) const {

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> otherMap = arg.map;

            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : thisMap) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = pair.second;

                const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* rangePtr = otherMap.find(domainElement);
                if(rangePtr == nullptr) {
                    return BBoolean(false);
                }

                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> thisRange = thisMap[domainElement];
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> otherRange = otherMap[domainElement];
                if(thisRange.size() > 0 && otherRange.size() == 0) {
                    return BBoolean(false);
                }

                for(const T& rangeElement : thisRange) {
                    if(otherRange.count(rangeElement) == 0) {
                        return BBoolean(false);
                    }
                }
            }
            return new BBoolean(true);
        }

        BBoolean notSubset(const BRelation<S,T>& arg) const {
            return subset(arg)._not();
        }

    	BSet<BRelation<S,T>> pow() const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;


    		BSet<BRelation<S,T>> result = BSet<BRelation<S,T>>();
    		BRelation<S,T> start = BRelation<S,T>();

    		queue<BRelation<S,T>> q = queue<BRelation<S,T>>();
    		q.push(start);

    		result = result._union(BSet<BRelation<S,T>>(start));
    		while(!q.empty()) {
    			BRelation<S,T> currentSet = q.front();
    			q.pop();

                for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : this->map) {
                    S domainElement = pair.first;
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = pair.second;

                    for(const T& rangeElement : range) {
                        BRelation<S,T> nextRelation = currentSet._union(BRelation<S,T>(BSet<BTuple<S,T>>(BTuple<S,T>(domainElement, rangeElement))));
                        int previousSize = result.size();
                        result = result._union(BSet<BRelation<S,T>>(nextRelation));
                        if(previousSize < result.size()) {
                            q.push(nextRelation);
                        }
                    }
                }
    		}
    		return result;
    	}

    	BSet<BRelation<S,T>> pow1() const {
    		return this->pow().difference(BSet<BRelation<S,T>>(BRelation<S,T>()));
    	}

    	BSet<BRelation<S,T>> fin() const {
    		return this->pow();
    	}

    	BSet<BRelation<S,T>> fin1() const {
    		return this->pow1();
    	}

        BRelation<S,T> override(const BRelation<S,T>& arg) const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> otherMap = arg.map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;
            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : otherMap) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = otherMap[domainElement];
                if(range.size() == 0) {
                    resultMap = resultMap.erase(domainElement);
                } else {
                    resultMap = resultMap.set(domainElement, range);
                }
            }
            return BRelation<S,T>(resultMap);
        }

    	T first() const {
    		return functionCall((S) BInteger(1));
    	}

    	T last() const {
    		return functionCall((S) this->card());
    	}

    	BRelation<S,T> reverse() const {
    		BInteger size = this->card();
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap;
            for(BInteger i = BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range;
                T rangeElement = this->functionCall((S) size.minus(i).succ());
                range = range.insert(rangeElement);
                resultMap = resultMap.set(i, range);
            }
            return BRelation<S,T>(resultMap);
    	}

    	BRelation<S,T> front() const {
    		return this->domainSubstraction(BSet<S>((S) this->card()));
    	}

    	BRelation<S,T> tail() const {
    	    BInteger size = this->_size();
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap;
            for(BInteger i = BInteger(2); i.lessEqual(size).booleanValue(); i = i.succ()) {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range;
                T rangeElement = this->functionCall((S) i);
                range = range.insert(rangeElement);
                resultMap = resultMap.set(i.pred(), range);
            }
            return BRelation<S,T>(resultMap);
    	}

    	BRelation<S,T> take(const BInteger& n) const {
    	    BInteger size = this->_size();
    	    if(n.greaterEqual(size).booleanValue()) {
    	        return BRelation<S,T>(this->map);
    	    }
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;

            for(BInteger i = n.succ(); i.lessEqual(size).booleanValue(); i = i.succ()) {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range;
                resultMap = resultMap.set(i, range);
            }
            return BRelation<S,T>(resultMap);
    	}

    	BRelation<S,T> drop(const BInteger& n) const {
    	    BInteger size = this->_size();
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap;

    	    for(BInteger i = n.succ(); i.lessEqual(size).booleanValue(); i = i.succ()) {
    	        const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* currentSetPtr = thisMap.find(i);
    	        immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> currentSet = *currentSetPtr;
    	        resultMap = resultMap.set(i.minus(n), currentSet);
    	    }
    	    return BRelation<S,T>(resultMap);
    	}

    	BRelation<S,T> concat(const BRelation<S,T>& arg) const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> otherMap = arg.map;

            BInteger size = this->card();
            for(BInteger i = BInteger(1); i.lessEqual(arg._size()).booleanValue(); i = i.succ()) {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> currentSet = otherMap[i];
                resultMap = resultMap.set(size.plus(i), currentSet);
            }
            return BRelation<S,T>(resultMap);
    	}

    	template<typename R = typename T::left_type, typename A = typename T::right_type>
    	BRelation<R,A> conc() const {
    		BRelation<R,A> result = BRelation<R,A>();
    		BInteger size = this->card();
    		for(BInteger i = BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
    			result = result.concat((BRelation<R,A>) functionCall((S) i));
    		}
    		return result;
    	}

    	BRelation<S,T> append(const T& arg) const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap = this->map;

            immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> range;
            range = range.insert(arg);
            resultMap = resultMap.set(this->card().succ(), range);
            return BRelation<S,T>(resultMap);
    	}

    	BRelation<S,T> prepend(const T& arg) const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap;
            BInteger size = this->_size();

            for(BInteger i = BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> currentSet = thisMap[i];
                resultMap = resultMap.set(i.succ(), currentSet);
            }
            immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> firstSet;
            firstSet = firstSet.insert(arg);
            resultMap = resultMap.set(BInteger(1), firstSet);
            return BRelation<S,T>(resultMap);
    	}

    	template<typename R>
    	BRelation<S,BTuple<T,R>> directProduct(const BRelation<S,R>& arg) const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;
            immer::map<S,immer::set<R, typename BSet<R>::Hash, typename BSet<R>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> otherMap = arg.map;

            immer::map<S,immer::set<BTuple<T,R>, typename BSet<BTuple<T,R>>::Hash, typename BSet<BTuple<T,R>>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap;

            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : this->map) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> thisRange = pair.second;
                const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* otherRangePtr = otherMap.find(domainElement);
                if(otherRangePtr == nullptr) {
                    continue;
                }
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> otherRange = *otherRangePtr;
                immer::set<BTuple<T,R>, typename BSet<BTuple<T,R>>::Hash, typename BSet<BTuple<T,R>>::HashEqual> resultRange;
                for(const T& lhsElement : thisRange) {
                    for(const R& rhsElement : otherRange) {
                        resultRange = resultRange.insert(BTuple<T,R>(lhsElement, rhsElement));
                    }
                }
                resultMap = resultMap.set(domainElement, resultRange);
            }
            return BRelation<S, BTuple<T,R>>(resultMap);
    	}

    	template<typename R,typename A>
    	BRelation<BTuple<S,R>,BTuple<T,A>> parallelProduct(const BRelation<R,A>& arg) const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<S,immer::set<R, typename BSet<R>::Hash, typename BSet<R>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> otherMap = arg.map;

            immer::map<BTuple<S,R>,immer::set<BTuple<T,A>, typename BSet<BTuple<T,A>>::Hash, typename BSet<BTuple<T,A>>::HashEqual>,
                                                               typename BSet<BTuple<S,R>>::Hash,
                                                               typename BSet<BTuple<S,R>>::HashEqual> resultMap;

            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair1 : thisMap) {
                for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair2 : otherMap) {
                    S domainElementThisElement = pair1.first;
                    R domainElementOtherElement = pair2.first;

                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> thisRange = pair1.second;
                    immer::set<A, typename BSet<A>::Hash, typename BSet<A>::HashEqual> otherRange = pair2.second;

                    immer::set<BTuple<T,A>, typename BSet<BTuple<T,A>>::Hash, typename BSet<BTuple<T,A>>::HashEqual> resultRange;

                    for(const T& lhsElement : thisRange) {
                        for(const A& rhsElement : otherRange) {
                            resultRange = resultRange.insert(BTuple<T,A>(lhsElement, rhsElement));
                        }
                    }
                    BTuple<S,R> tuple = BTuple<S,R>(domainElementThisElement, domainElementOtherElement);
                    resultMap = resultMap.set(tuple, resultRange);
                }
            }
            return BRelation<BTuple<S,R>, BTuple<T,A>>(resultMap);
    	}

    	template<typename R>
    	BRelation<S,R> composition(const BRelation<T,R>& arg) const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> thisMap = this->map;

            immer::map<T,immer::set<R, typename BSet<R>::Hash, typename BSet<R>::HashEqual>,
                                                               typename BSet<T>::Hash,
                                                               typename BSet<T>::HashEqual> otherMap = arg.map;

            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                               typename BSet<S>::Hash,
                                                               typename BSet<S>::HashEqual> resultMap;
            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : thisMap) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = pair.second;

                immer::set<R, typename BSet<R>::Hash, typename BSet<R>::HashEqual> set;
                for(const T& rangeElement : range) {
                    immer::set<R, typename BSet<R>::Hash, typename BSet<R>::HashEqual> otherRange = otherMap[rangeElement];
                    for(const R& otherRangeElement : otherRange) {
                        set = set.insert(otherRangeElement);
                    }
                }
                if(set.size() == 0) {
                    continue;
                }

                resultMap = resultMap.set(domainElement, set);
            }
            return BRelation<S,R>(resultMap);
    	}

        static BRelation<T,T> identity(const BSet<T>& set) {
            immer::map<T,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                 typename BSet<T>::Hash,
                                                                 typename BSet<T>::HashEqual> resultMap;
            for(const T& e : set.getSet()) {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range;
                range = range.insert(e);
                resultMap = resultMap.set(e, range);
            }
            return BRelation<T,T>(resultMap);
        }

    	BRelation<S,S> iterate(const BInteger& n) const {
    		BRelation<S,S> thisRelation = (BRelation<S,S>) *this;
            BRelation<S,S> result = BRelation<S,S>::identity(this->domain()._union(thisRelation->range()));
    		for(BInteger i = BInteger(1); i.lessEqual(n).booleanValue(); i = i.succ()) {
    			result = result.composition(thisRelation);
    		}
    		return result;
    	}

    	BRelation<S,S> closure() const {
    		BRelation<S,S> thisRelation = (BRelation<S,S>) *this;
            BRelation<S,S> result = BRelation<S,S>::identity(this->domain()._union(thisRelation->range()));
    		BRelation<S,S> nextResult = result.composition(thisRelation);
    		BRelation<S,S> lastResult;
    		do {
    		    lastResult = result;
    			result = result._union(nextResult);
    			nextResult = result.composition(thisRelation);
    		} while(!result.equal(lastResult).booleanValue());
    		return result;
    	}

    	BRelation<S,S> closure1() const {
    		BRelation<S,S> thisRelation = (BRelation<S,S>) *this;
    		BRelation<S,S> result = (BRelation<S,S>) *this;
    		BRelation<S,S> nextResult = result.composition(thisRelation);
    		BRelation<S,S> lastResult;
    		do {
    		    lastResult = result;
    			result = result._union(nextResult);
    			nextResult = result.composition(thisRelation);
    		} while(!result.equal(lastResult).booleanValue());
    		return result;
    	}

        static BRelation<BTuple<S,T>, S> projection1(const BSet<S>& arg1, const BSet<T>& arg2) {
            immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> argSet1 = arg1.getSet();
            immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> argSet2 = arg2.getSet();

            immer::map<BTuple<S,T>,immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual>,
                                                                 typename BSet<BTuple<S,T>>::Hash,
                                                                 typename BSet<BTuple<S,T>>::HashEqual> resultMap;


            for(const S& e1 : argSet1) {
                for(const T& e2 : argSet2) {
                    BTuple<S,T> tuple = BTuple<S,T>(e1, e2);
                    immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> range;
                    range = range.insert(e1);
                    resultMap = resultMap.set(tuple, range);
                }
            }
            return BRelation<BTuple<S,T>, S>(resultMap);
        }

        static BRelation<BTuple<S,T>, S> projection2(const BSet<S>& arg1, const BSet<T>& arg2) {
            immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> argSet1 = arg1.getSet();
            immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> argSet2 = arg2.getSet();

            immer::map<BTuple<S,T>,immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual>,
                                                                 typename BSet<BTuple<S,T>>::Hash,
                                                                 typename BSet<BTuple<S,T>>::HashEqual> resultMap;


            for(const S& e1 : argSet1) {
                for(const T& e2 : argSet2) {
                    BTuple<S,T> tuple = BTuple<S,T>(e1, e2);
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range;
                    range = range.insert(e2);
                    resultMap = resultMap.set(tuple, range);
                }
            }
            return BRelation<BTuple<S,T>, T>(resultMap);
        }

    	BRelation<S,BSet<T>> fnc() const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                 typename BSet<S>::Hash,
                                                                 typename BSet<S>::HashEqual> thisMap = this->map;
    	    immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> domain = this->domain().getSet();

            immer::map<S,immer::set<BSet<T>, typename BSet<BSet<T>>::Hash, typename BSet<BSet<T>>::HashEqual>,
                                                                 typename BSet<S>::Hash,
                                                                 typename BSet<S>::HashEqual> resultMap;

            for(const S& domainElement : domain) {
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = thisMap[domainElement];
                BSet<T> rangeSet = BSet<T>(range);

                immer::set<BSet<T>, typename BSet<BSet<T>>::Hash, typename BSet<BSet<T>>::HashEqual> currentRange;
                currentRange = currentRange.insert(rangeSet);
                resultMap = resultMap.set(domainElement, currentRange);
            }
            return BRelation<S, BSet<T>>(resultMap);
    	}

    	template<typename R = typename T::value_type>
    	BRelation<S,R> rel() const {
    	    BSet<S> domain = this->domain();

            immer::map<S,immer::set<R, typename BSet<R>::Hash, typename BSet<R>::HashEqual>,
                                                                 typename BSet<S>::Hash,
                                                                 typename BSet<S>::HashEqual> resultMap;

            for(const S& domainElement : domain.getSet()) {
                BSet<R> range = (BSet<R>) this->functionCall(domainElement);
                immer::set<R, typename BSet<R>::Hash, typename BSet<R>::HashEqual> rangeSet = range.getSet();
                resultMap = resultMap.set(domainElement, rangeSet);
            }
            return BRelation<S,R>(resultMap);
    	}

    	BBoolean isTotal(const BSet<S>& domain) const {
    		return this->domain().equal(domain);
    	}

        template<typename R1 = typename S::left_type, typename R2 = typename S::right_type>
        BBoolean isTotal(const BRelation<R1, R2>& domain) const {
            BSet<BTuple<R1, R2>> domainAsSet = BSet<BTuple<R1, R2>>();
            for(const BTuple<R1, R2>& tuple : domain) {
                domainAsSet = domainAsSet._union(BSet<BTuple<R1, R2>>(tuple));
            }
            return this->domain().equal((BSet<S>) domainAsSet);
        }

    	BBoolean isTotalInteger() const {
    		return BBoolean(false);
    	}

    	BBoolean isTotalNatural() const {
    		return BBoolean(false);
    	}

    	BBoolean isTotalNatural1() const {
    		return BBoolean(false);
    	}

    	BBoolean isTotalString() const {
    		return BBoolean(false);
    	}

    	BBoolean isTotalStruct() const {
    	    return BBoolean(false);
    	}

    	BBoolean isPartial(const BSet<S>& domain) const {
    		return this->domain().subset(domain);
    	}

        template<typename A1 = typename S::left_type, typename A2 = typename S::right_type>
        BBoolean isPartial(const BRelation<A1, A2>& domain) const {
            for(S element : this->domain()) {
                BTuple<A1, A2> elementAsTuple = (BTuple<A1, A2>) element;
                const immer::set<A2, typename BSet<A2>::Hash, typename BSet<A2>::HashEqual>* rangePtr = domain.map.find(elementAsTuple.projection1());
                if(rangePtr == nullptr) {
                    return BBoolean(false);
                }
                const immer::set<A2, typename BSet<A2>::Hash, typename BSet<A2>::HashEqual> range = *rangePtr;
                if(range.find(elementAsTuple.projection2()) == nullptr) {
                    return BBoolean(false);
                }
            }
            return BBoolean(true);
        }


    	BBoolean isPartialInteger() const {
    		for(const S& element : this->domain()) {
    			if(typeid(element) == typeid(BInteger)) {
    				return BBoolean(true);
    			} else {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean isPartialNatural() const {
    		for(const S& element : this->domain()) {
    			if(typeid(element) == typeid(BInteger) && !((BInteger) element).isNatural().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean isPartialNatural1() const {
    		for(const S& element : this->domain()) {
    			if(typeid(element) == typeid(BInteger) && !((BInteger)element).isNatural1().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean isPartialString() const {
    		for(const S& element : this->domain()) {
    			if(typeid(element) == typeid(BString) && !((BString)element).isString().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean isPartialStruct() const {
    		for(const S& element : this->domain()) {
    			if(typeid(element) == typeid(BStruct) && !((BStruct) element).isRecord().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean checkDomain(const BSet<S>& domain) const {
    		return this->domain().subset(domain);
    	}

        template<typename A1 = typename S::left_type, typename A2 = typename S::right_type>
        BBoolean checkDomain(const BRelation<A1, A2>& domain) const {
            for(S element : this->domain()) {
                BTuple<A1, A2> elementAsTuple = (BTuple<A1, A2>) element;
                const immer::set<A2, typename BSet<A2>::Hash, typename BSet<A2>::HashEqual>* rangePtr = domain.map.find(elementAsTuple.projection1());
                if(rangePtr == nullptr) {
                    return BBoolean(false);
                }
                const immer::set<A2, typename BSet<A2>::Hash, typename BSet<A2>::HashEqual> range = *rangePtr;
                if(range.find(elementAsTuple.projection2()) == nullptr) {
                    return BBoolean(false);
                }
            }
            return BBoolean(true);
        }

    	BBoolean checkDomainInteger() const {
    		for(const S& element : this->domain()) {
    			if(typeid(element) == typeid(BInteger)) {
    				return BBoolean(true);
    			} else {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean checkDomainNatural() const {
    		for(const S& element : this->domain()) {
    			if(typeid(element) == typeid(BInteger) && !((BInteger)element).isNatural().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean checkDomainNatural1() const {
    		for(const S& element : this->domain()) {
    			if(typeid(element) == typeid(BInteger) && !((BInteger)element).isNatural1().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean checkDomainString() const {
    		for(const S& element : this->domain()) {
    			if(typeid(element) == typeid(BString) && !((BString)element).isString().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean checkDomainStruct() const {
    		for(const S& element : this->domain()) {
    			if(typeid(element) == typeid(BStruct) && !((BStruct) element).isRecord().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean checkRange(const BSet<T>& range) const {
    		return this->range().subset(range);
    	}

        template<typename A1 = typename T::left_type, typename A2 = typename T::right_type>
        BBoolean checkRange(const BRelation<A1, A2>& range) const {
            for(S element : this->range()) {
                BTuple<A1, A2> elementAsTuple = (BTuple<A1, A2>) element;
                const immer::set<A2, typename BSet<A2>::Hash, typename BSet<A2>::HashEqual>* rangeRangePtr = range.map.find(elementAsTuple.projection1());
                if(rangeRangePtr == nullptr) {
                    return BBoolean(false);
                }
                const immer::set<A2, typename BSet<A2>::Hash, typename BSet<A2>::HashEqual> rangeRange = *rangeRangePtr;
                if(rangeRange.find(elementAsTuple.projection2()) == nullptr) {
                    return BBoolean(false);
                }
            }
            return BBoolean(true);
        }

    	BBoolean checkRangeInteger() const {
    		for(const T& element : this->range()) {
    			if(typeid(element) == typeid(BInteger)) {
    				return BBoolean(true);
    			} else {
    				return BBoolean(false);
    			}
    		}
    		return new BBoolean(true);
    	}

    	BBoolean checkRangeNatural() const {
    		for(const T& element : this->range()) {
    			if(typeid(element) == typeid(BInteger) && !((BInteger)element).isNatural().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean checkRangeNatural1() const {
    		for(const T& element : this->range()) {
    			if(typeid(element) == typeid(BInteger) && !((BInteger)element).isNatural1().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean checkRangeString() const {
    		for(const T& element : this->range()) {
    			if(typeid(element) == typeid(BString) && !((BString)element).isString().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean checkRangeStruct() const {
    		for(const T& element : this->range()) {
    			if(typeid(element) == typeid(BStruct) && !((BStruct) element).isRecord().booleanValue()) {
    				return BBoolean(false);
    			}
    		}
    		return BBoolean(true);
    	}

    	BBoolean isRelation() const {
    		return BBoolean(true);
    	}

    	BBoolean isFunction() const {
    	    for(const S& element : this->domain()) {
    	        immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = this->map[element];
    	        if(range.size() > 1) {
    	            return BBoolean(false);
    	        }
    	    }
    	    return BBoolean(true);
    	}

    	BBoolean isSurjection(const BSet<T>& range) const {
    		return this->range().equal(range);
    	}

    	BBoolean isSurjectionInteger() const {
    		return BBoolean(false);
    	}

    	BBoolean isSurjectionNatural() const {
    		return BBoolean(false);
    	}

    	BBoolean isSurjectionNatural1() const {
    		return BBoolean(false);
    	}

    	BBoolean isSurjectionString() const {
    		return BBoolean(false);
    	}

    	BBoolean isSurjectionStruct() const {
    		return BBoolean(false);
    	}

    	BBoolean isInjection() const {
    	    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> visited;
    	    for(const S& element : this->domain()) {
    	        immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = this->map[element];
    	        for(const T& rangeElement : range) {
    	            if(visited.count(rangeElement) > 0) {
    	                return BBoolean(false);
    	            }
    	            visited = visited.insert(rangeElement);
    	        }
    	    }
    	    return BBoolean(true);
    	}

    	BBoolean isBijection(const BSet<T>& range) const {
    		return isSurjection(range)._and(isInjection());
    	}

    	BBoolean isBijectionInteger() const {
    		return BBoolean(false);
    	}

    	BBoolean isBijectionNatural() const {
    		return BBoolean(false);
    	}

    	BBoolean isBijectionNatural1() const {
    		return BBoolean(false);
    	}

    	BBoolean isBijectionString() const {
    		return BBoolean(false);
    	}

    	BBoolean isBijectionStruct() const {
    		return BBoolean(false);
    	}

        void operator =(const BRelation<S,T>& other) {
            this->map = other.map;
        }

        void operator =(const BSet<BTuple<S,T>>& other) {
            this->map = immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                        typename BSet<S>::Hash,
                                                                        typename BSet<S>::HashEqual>();

            immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual> otherSet = other.getSet();
            for(const BTuple<S,T>& tuple : otherSet) {
                S first = tuple.projection1();
                T second = tuple.projection2();
                const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* rangePtr = this->map.find(first);
                if(rangePtr == nullptr) {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet;
                    resultSet = resultSet.insert(second);
                    this->map = this->map.set(first, resultSet);
                } else {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet = *rangePtr;
                    resultSet = resultSet.insert(second);
                    this->map = this->map.set(first, resultSet);
                }
            }
        }

        void operator =(const immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual>& otherSet) {
            this->map = immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                        typename BSet<S>::Hash,
                                                                        typename BSet<S>::HashEqual>();

            for(const BTuple<S,T>& tuple : otherSet) {
                S first = tuple.projection1();
                T second = tuple.projection2();
                const immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>* rangePtr = this->map.find(first);
                if(rangePtr == nullptr) {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet;
                    resultSet = resultSet.insert(second);
                    this->map = this->map.set(first, resultSet);
                } else {
                    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> resultSet = *rangePtr;
                    resultSet = resultSet.insert(second);
                    this->map = this->map.set(first, resultSet);
                }
            }
        }

        friend bool operator !=(const BRelation<S,T>& o1, const BRelation<S,T>& o2) {
            return o1.map != o2.map;
        }

        friend bool operator ==(const BRelation<S,T>& o1, const BRelation<S,T>& o2) {
            return o1.map == o2.map;
        }

        BTuple<S,T> nondeterminism() const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                 typename BSet<S>::Hash,
                                                                 typename BSet<S>::HashEqual> thisMap = this->map;

            immer::set<S, typename BSet<S>::Hash, typename BSet<S>::HashEqual> domain = (this->domain()).getSet();
		    int index = rand() % domain.size();
		    int i = 0;

		    S domainElement;
		    for(const S& obj : domain) {
		        if(i == index) {
		            domainElement = obj;
		            break;
		        }
		        ++i;
		    }

		    immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = thisMap[domainElement];
		    index = rand() % range.size();
		    i = 0;
		    for(const T& obj : range) {
		        if(i == index) {
		            return BTuple<S,T>(domainElement, obj);
		        }
		        ++i;
		    }
		    return BTuple<S,T>();
	    }

        BBoolean equal(const BRelation<S,T>& other) const {
            return BBoolean(this->map == other.map);
        }

        BBoolean unequal(const BRelation<S,T>& other) const {
            return BBoolean(this->map != other.map);
        }

        BBoolean elementOf(const BTuple<S,T>& object) const {
            S prj1 = object.projection1();
            T prj2 = object.projection2();

            if(this->domain().getSet().count(prj1) == 0) {
                return BBoolean(false);
            }
            immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = this->map[prj1];
            return BBoolean(range.count(prj2) > 0);
        }

        BBoolean notElementOf(const BTuple<S,T>& object) const {
            S prj1 = object.projection1();
            T prj2 = object.projection2();

            if(this->domain().getSet().count(prj1) == 0) {
                return BBoolean(true);
            }
            immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = this->map[prj1];
            return BBoolean(range.count(prj2) == 0);
        }

        friend std::ostream& operator<<(std::ostream &strm, const BRelation<S,T>& rel) {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                 typename BSet<S>::Hash,
                                                                 typename BSet<S>::HashEqual> thisMap = rel.map;

            int size = rel.size();
            int i = 0;

            strm << "{";
            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : thisMap) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = pair.second;
                for(const T& rangeElement : range) {
                    strm << "(";
                    strm << domainElement;
                    strm << " |-> ";
                    strm << rangeElement;
                    strm << ")";
                    if(i+1 < size) {
                        strm << ", ";
                    }
                    ++i;
                }
            }
            strm << "}";
            return strm;
        }

        int hashCode() const {
            immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                                 typename BSet<S>::Hash,
                                                                 typename BSet<S>::HashEqual> thisMap = this->map;

            int size = this->size();
            int i = 0;
            int result = 1;
            for(const std::pair<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>>& pair : thisMap) {
                S domainElement = pair.first;
                immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual> range = pair.second;
                for(const T& rangeElement : range) {
                    result = result ^ ((domainElement.hashCode() ^ (rangeElement.hashCode() << 1)) << 1);
                    ++i;
                }

            }
            return result;
        }

        BRelationIterator begin() const {
            return BRelationIterator(*this);
        }

        BRelationIterator end() const {
            return BRelationIterator(BRelation())++;
        }

    public:
        immer::map<S,immer::set<T, typename BSet<T>::Hash, typename BSet<T>::HashEqual>,
                                                           typename BSet<S>::Hash,
                                                           typename BSet<S>::HashEqual> map;
};

#endif
