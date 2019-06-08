#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdarg>
#include <immer/set.hpp>
#include "BInteger.cpp"
#include "BString.cpp"
#include "BStruct.cpp"

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

        /*BSet<T>(const BSet<T>& set) {
            this->set = set.set;
        }*/

	/*public BSet(java.util.Set<BObject> elements) {
		this.set = HashTreePSet.from(elements);
	}

	public BSet(PSet<BObject> elements) {
		this.set = elements;
	}

	public BSet(BObject... elements) {
		this.set = HashTreePSet.from(Arrays.asList(elements));
	}*/

	/*public static LinkedHashSet<BObject> newStorage() {
		return new LinkedHashSet<>();
	}

	public java.lang.String toString() {
		Iterator<BObject> it = this.iterator();
		StringBuffer sb = new StringBuffer();
		sb.append("{");
		while (it.hasNext()) {
			BObject b = (BObject) it.next();
			sb.append(b.toString());
			if (it.hasNext()) {
				sb.append(", ");
			}
		}
		sb.append("}");
		return sb.toString();
	}*/

        int size() const {
            return set.size();
        }

        bool isEmpty() {
            return set.empty();
        }

        bool contains(const T& o) const {
            return set.count(o) > 0;
        }

        /*boolean add(BObject bObject) {
            throw new UnsupportedOperationException();
        }

        boolean remove(Object o) {
            throw new UnsupportedOperationException();
        }

        void clear() {
            throw new UnsupportedOperationException();
        }*/

        /*boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;

            BSet bObjects = (BSet) o;

            if (!set.equals(bObjects.set))
                return false;

            return true;
        }

        int hashCode() {
            return set.hashCode();
        }

        boolean removeAll(Collection<?> c) {
            throw new UnsupportedOperationException();
        }

        Object[] toArray() {
            return set.toArray();
        }

        <T> T[] toArray(T[] a) {
            return set.toArray(a);
        }

        boolean containsAll(Collection<?> c) {
            return set.containsAll(c);
        }

        boolean addAll(Collection<? extends BObject> c) {
            throw new UnsupportedOperationException();
        }

        boolean retainAll(Collection<?> c) {
            throw new UnsupportedOperationException();
        }

        Iterator<BObject> iterator() {
            return set.iterator();
        }*/


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
     	K intersect() const {
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
     	K _union() const {
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
            return BBoolean(false);
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

        BBoolean subsetOfInteger() {
            for(T e : this->set) {
                if(typeid(e) == typeid(BInteger)) {
                    return BBoolean(true);
                } else {
                    return BBoolean(false);
                }
            }
            return BBoolean(true);
        }

        BBoolean strictSubsetOfInteger() {
            return this->subsetOfInteger();
        }

        BBoolean notSubsetOfInteger() {
            return this->subsetOfInteger()._not();
        }

        BBoolean equalInteger() {
            return BBoolean(false);
        }

        BBoolean unequalInteger() {
            return BBoolean(true);
        }

        BBoolean equalNatural() {
            return BBoolean(false);
        }

        BBoolean unequalNatural() {
            return BBoolean(true);
        }

        BBoolean equalNatural1() {
            return BBoolean(false);
        }

        BBoolean unequalNatural1() {
            return BBoolean(true);
        }

        BBoolean equalString() {
            return BBoolean(false);
        }

        BBoolean unequalString() {
            return BBoolean(true);
        }

        BBoolean equalStruct() {
            return BBoolean(false);
        }

        BBoolean unequalStruct() {
            return BBoolean(true);
        }

        BBoolean notStrictSubsetOfInteger() {
            return this->strictSubsetOfInteger()._not();
        }

        BBoolean subsetOfNatural() {
            for(T e : this->set) {
                BInteger element = (BInteger) e;
                if(!element.isNatural().booleanValue()) {
                    return BBoolean(false);
                }
            }
            return BBoolean(true);
        }

        BBoolean strictSubsetOfNatural() {
            return this->subsetOfNatural();
        }

        BBoolean notSubsetOfNatural() {
            return this->subsetOfNatural()._not();
        }

        BBoolean notStrictSubsetOfNatural() {
            return strictSubsetOfNatural()._not();
        }

        BBoolean subsetOfNatural1() {
            for(T e : this->set) {
                BInteger element = (BInteger) e;
                if(!element.isNatural1().booleanValue()) {
                    return BBoolean(false);
                }
            }
            return BBoolean(true);
        }

        BBoolean strictSubsetOfNatural1() {
            return this->subsetOfNatural1();
        }

        BBoolean notSubsetOfNatural1() {
            return this->subsetOfNatural1()._not();
        }

        BBoolean notStrictSubsetOfNatural1() {
            return this->strictSubsetOfNatural1()._not();
        }

        BBoolean subsetOfString() {
            for(T e : this->set) {
                BString element = (BString) e;
                if(!element.isString().booleanValue()) {
                    return BBoolean(false);
                }
            }
            return BBoolean(true);
        }

        BBoolean strictSubsetOfString() {
            return this->subsetOfString();
        }

        BBoolean notSubsetOfString() {
            return this->subsetOfString()._not();
        }

        BBoolean notStrictSubsetOfString() {
            return this->strictSubsetOfString()._not();
        }

        BBoolean subsetOfStruct() {
            for(T e : this->set) {
                BStruct element = (BStruct) e;
                if(!element.isRecord().booleanValue()) {
                    return BBoolean(false);
                }
            }
            return BBoolean(true);
        }

        BBoolean strictSubsetOfStruct() {
            return this->subsetOfStruct();
        }

        BBoolean notSubsetOfStruct() {
            return this->subsetOfStruct()._not();
        }

        BBoolean notStrictSubsetOfStruct() {
            return this->strictSubsetOfStruct()._not();
        }

        void operator =(const BSet<T>& other) {
            this->set = other.set;
        }

        int hashCode() const {
            int result = 0;
            int i = 0;
            for(const T& s : this->set) {
                if(i == 0) {
                    result = s.hashCode();
                }
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