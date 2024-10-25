#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdarg>
#include <immer/set.hpp>
#include "BInteger.hpp"
#include "BString.hpp"
#include "BStruct.hpp"

#ifndef BSET_H
#define BSET_H

using namespace std;

template<typename T>
class BSet : public BObject {

    public:

        typedef BSet<T> current_type;
        typedef T value_type;
        typedef void left_type;
        typedef void right_type;

        struct SetHash {
            public:
                size_t operator()(const BSet<T>& obj) const {
                    return obj.hashCode();
                }
        };

        struct SetHashEqual {
            public:
                bool operator()(const BSet<T>& obj1, const BSet<T>& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

        struct Hash {
            public:
                size_t operator()(const T& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const T& obj1, const T& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

        /*Only used within this class*/
        BSet<T>(const immer::set<T, Hash, HashEqual>& elements) {
            this->set = elements;
        }

        template<typename... Args>
        BSet<T>(const Args&... args) {
          this->set = var(args...);
        }

        immer::set<T, Hash, HashEqual> var() {
          return immer::set<T,Hash, HashEqual>();
        }

        template<typename R, typename... Args>
        immer::set<R, Hash, HashEqual> var(const R& first, const Args&... args) {
          return var(args...).insert(first);
        }

        BSet<T>() {
            this->set = immer::set<T,Hash, HashEqual>();
        }

        int size() const {
            return set.size();
        }

        bool isEmpty() {
            return set.empty();
        }

        bool contains(const T& o) const {
            return set.count(o) > 0;
        }

        BSet<T> intersect(const BSet<T>& set) const {
            immer::set<T,Hash, HashEqual> result = this->set;
            for (const T& obj : this->set) {
                if(set.set.count(obj) == 0) {
                    result = result.erase(obj);
                }
            }
            return BSet(result);
        }

     	template<typename K = value_type>
     	K intersectForSets() const {
     	    if(this->size() == 0) {
     	        return K();
     	    }
     	    K result;
     	    int i = 0;
            for(const T& s : this->set) {
                if(i == 0) {
                    result = K(s);
                }
                ++i;
                result = result.intersect(K(s));
            }
            return result;
     	}


        template<typename K = value_type>
        K intersectForRelations() const {
            if(this->size() == 0) {
                return K();
            }
            K result;
            int i = 0;
            for(const T& s : this->set) {
                if(i == 0) {
                    result = K(s);
                }
                ++i;
                result = result.intersect(K(s));
            }
            return result;
        }

        BSet<T> difference(const BSet<T>& set) const {
            if(this->size() == 0) {
                return BSet(this->set);
            }
            immer::set<T, Hash, HashEqual> result = this->set;
            for (const T& obj : set.set) {
                if(result.count(obj) == 1) {
                    result = result.erase(obj);
                }
            }
            return BSet(result);
        }

        BSet<T> _union(const BSet<T>& set) const {
            int thisSize = this->size();
            int otherSize = set.size();
            if(thisSize > otherSize) {
                immer::set<T,Hash, HashEqual> result = this->set;
                for (const T& obj : set.set) {
                    if(result.count(obj) == 0) {
                        result = result.insert(obj);
                    }
                }
                return BSet(result);
            } else {
                immer::set<T,Hash, HashEqual> result = set.set;
                for (const T& obj : this->set) {
                    if(result.count(obj) == 0) {
                        result = result.insert(obj);
                    }
                }
                return BSet(result);
            }
        }

     	template<typename K = value_type>
     	K unionForSets() const {
     	    K result;
            for(const T& s : this->set) {
                result = result._union(K(s));
            }
            return result;
     	}

        template<typename K = value_type>
        K unionForRelations() const {
            K result;
            for(const T& s : this->set) {
                result = result._union(K(s));
            }
            return result;
        }

        static BSet<BInteger> interval(const BInteger& a, const BInteger& b) {
            immer::set<BInteger, Hash, HashEqual> result;
            int end = b.intValue();
            for(int i = a.intValue(); i <= end; ++i) {
                result = result.insert(i);
            }
            return BSet(result);
        }


        BInteger card() const {
            return BInteger(set.size());
        }

        BInteger _size() const {
            return BInteger(set.size());
        }

        BBoolean elementOf(const T& object) const {
            return BBoolean(set.count(object) > 0);
        }

        BBoolean notElementOf(const T& object) const {
            return BBoolean(set.count(object) == 0);
        }

        BBoolean subset(const BSet<T>& set) const {
            for (const T& obj : this->set) {
                if(set.set.count(obj) == 0) {
                    return BBoolean(false);
                }
            }
            return BBoolean(true);
        }

        BBoolean notSubset(const BSet<T>& set) const {
            for (const T& obj : this->set) {
                if(set.set.count(obj) == 0) {
                    return BBoolean(true);
                }
            }
            return BBoolean(false);
        }

        BBoolean strictSubset(const BSet<T>& set) const {
            if(this->set.size() != set.size()) {
                for (const T& obj : this->set) {
                    if(set.set.count(obj) == 0) {
                        return BBoolean(false);
                    }
                }
                return BBoolean(true);
            }
            return BBoolean(false);
        }

        BBoolean strictNotSubset(const BSet<T>& set) const {
            if(this->set.size() != set.size()) {
                for (const T& obj : this->set) {
                    if(set.set.count(obj) == 0) {
                        return BBoolean(true);
                    }
                }
                return BBoolean(false);
            }
            return BBoolean(true);
        }

        template<typename K = current_type>
    	BSet<K> pow() const {
    		BSet<K> result = BSet<K>();
    		K start = K();
    		queue<K> q = queue<K>();
    		q.push(start);
    		result = result._union(BSet<K>(start));
    		while(!q.empty()) {
    			K currentSet = q.front();
    			q.pop();
    			for(const T& element : this->set) {
    				K nextSet = currentSet._union(K(element));
    				int previousSize = result.size();
    				result = result._union(BSet<K>(nextSet));
    				if(previousSize < result.size()) {
    					q.push(nextSet);
    				}
    			}
    		}
    		return result;
    	}

        template<typename K = current_type>
    	BSet<K> pow1() const {
            K emptySet = K();
    		return this->pow().difference(BSet<K>(K()));
    	}

        template<typename K = current_type>
    	BSet<K> fin() const {
    		return this->pow();
    	}

        template<typename K = current_type>
    	BSet<K> fin1() const {
    		return this->pow1();
    	}

        BInteger min() const {
            BInteger result;
            int i = 0;
            for(const T& obj : this->set) {
                BInteger e = obj;
                if(i == 0) {
                    result = e;
                }
                if(e.less(result).booleanValue()) {
                    result = e;
                }
                ++i;
            }
            return result;
        }

        BInteger max() const {
            BInteger result;
            int i = 0;
            for(const T& obj : this->set) {
                BInteger e = obj;
                if(i == 0) {
                    result = e;
                }
                if(e.greater(result).booleanValue()) {
                    result = e;
                }
                ++i;
            }
            return result;
        }

        T nondeterminism() const {
		    int index = rand() % set.size();
		    typename immer::set<T,Hash, HashEqual>::const_iterator it = std::next(set.begin(), index);
		    return *it;
	    }

        friend bool operator !=(const BSet<T>& o1, const BSet<T>& o2) {
            return o1.set != o2.set;
        }

        friend bool operator ==(const BSet<T>& o1, const BSet<T>& o2) {
            return o1.set == o2.set;
        }

        BBoolean equal(const BSet<T>& other) const {
            return BBoolean(this->set == other.set);
        }

        BBoolean unequal(const BSet<T>& other) const {
            return BBoolean(this->set != other.set);
        }

         BBoolean subsetOfBoolean() const {
             for(const T& e : this->set) {
                 if(typeid(e) == typeid(BBoolean)) {
                     return BBoolean(true);
                 } else {
                     return BBoolean(false);
                 }
             }
             return BBoolean(true);
         }

         BBoolean strictSubsetOfBoolean() const {
             return this->subsetOfBoolean();
         }

         BBoolean notSubsetOfBoolean() const {
             return this->subsetOfBoolean()._not();
         }

         BBoolean equalBoolean() const {
             return BBoolean(subsetOfBoolean().booleanValue() && this->size() == 2);
         }

         BBoolean notEqualBoolean() const {
             return BBoolean(subsetOfBoolean().booleanValue() && this->size() < 2);
         }

         BBoolean subsetOfInteger() const {
             for(const T& e : this->set) {
                 if(typeid(e) == typeid(BInteger)) {
                     return BBoolean(true);
                 } else {
                     return BBoolean(false);
                 }
             }
             return BBoolean(true);
         }

         BBoolean strictSubsetOfInteger() const {
             return this->subsetOfInteger();
         }

         BBoolean notSubsetOfInteger() const {
             return this->subsetOfInteger()._not();
         }

         BBoolean equalInteger() const {
             return BBoolean(false);
         }

         BBoolean unequalInteger() const {
             return BBoolean(true);
         }

         BBoolean equalNatural() const {
             return BBoolean(false);
         }

         BBoolean unequalNatural() const {
             return BBoolean(true);
         }

         BBoolean equalNatural1() const {
             return BBoolean(false);
         }

         BBoolean unequalNatural1() const {
             return BBoolean(true);
         }

         BBoolean equalString() const {
             return BBoolean(false);
         }

         BBoolean unequalString() const {
             return BBoolean(true);
         }

         BBoolean equalStruct() const {
             return BBoolean(false);
         }

         BBoolean unequalStruct() const {
             return BBoolean(true);
         }

         BBoolean notStrictSubsetOfInteger() const {
             return this->strictSubsetOfInteger()._not();
         }

         BBoolean subsetOfNatural() const {
             for(const T& e : this->set) {
                 BInteger element = (BInteger) e;
                 if(!element.isNatural().booleanValue()) {
                     return BBoolean(false);
                 }
             }
             return BBoolean(true);
         }

         BBoolean strictSubsetOfNatural() const {
             return this->subsetOfNatural();
         }

         BBoolean notSubsetOfNatural() const {
             return this->subsetOfNatural()._not();
         }

         BBoolean notStrictSubsetOfNatural() const {
             return strictSubsetOfNatural()._not();
         }

         BBoolean subsetOfNatural1() const {
             for(const T& e : this->set) {
                 BInteger element = (BInteger) e;
                 if(!element.isNatural1().booleanValue()) {
                     return BBoolean(false);
                 }
             }
             return BBoolean(true);
         }

         BBoolean strictSubsetOfNatural1() const {
             return this->subsetOfNatural1();
         }

         BBoolean notSubsetOfNatural1() const {
             return this->subsetOfNatural1()._not();
         }

         BBoolean notStrictSubsetOfNatural1() const {
             return this->strictSubsetOfNatural1()._not();
         }

         BBoolean subsetOfString() const {
             for(const T& e : this->set) {
                 BString element = (BString) e;
                 if(!element.isString().booleanValue()) {
                     return BBoolean(false);
                 }
             }
             return BBoolean(true);
         }

         BBoolean strictSubsetOfString() const {
             return this->subsetOfString();
         }

         BBoolean notSubsetOfString() const {
             return this->subsetOfString()._not();
         }

         BBoolean notStrictSubsetOfString() const {
             return this->strictSubsetOfString()._not();
         }

         BBoolean subsetOfStruct() const {
             for(const T& e : this->set) {
                 BStruct element = (BStruct) e;
                 if(!element.isRecord().booleanValue()) {
                     return BBoolean(false);
                 }
             }
             return BBoolean(true);
         }

         BBoolean strictSubsetOfStruct() const {
             return this->subsetOfStruct();
         }

         BBoolean notSubsetOfStruct() const {
             return this->subsetOfStruct()._not();
         }

         BBoolean notStrictSubsetOfStruct() const {
             return this->strictSubsetOfStruct()._not();
         }

        void operator =(const BSet<T>& other) {
            this->set = other.set;
        }

        int hashCode() const {
            int result = 1;
            int i = 0;
            for(const T& s : this->set) {
                result = result ^ (s.hashCode() << 1);
                ++i;
            }
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const BSet<T>& set) {
            strm << "{";
            typename immer::set<T,Hash, HashEqual>::const_iterator it = set.begin();
            while(it != set.end()) {
                T element = *it;
                strm << element;
                ++it;
                if(it != set.end()) {
                    strm << ",";
                }
            }
            strm << "}";
            return strm;
        }

        typename immer::set<T,Hash, HashEqual>::const_iterator begin() const {
            return set.begin();
        }

        typename immer::set<T,Hash, HashEqual>::const_iterator end() const {
            return set.end();
        }

        immer::set<T,Hash, HashEqual> getSet() const {
            return set;
        }

        protected:
            immer::set<T,Hash, HashEqual> set;

};

#endif