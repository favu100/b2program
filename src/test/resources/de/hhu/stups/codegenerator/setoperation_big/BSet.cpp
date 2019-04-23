#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstdarg>
#include <immer/set.hpp>
#include "BInteger.cpp"

#ifndef BSET_H
#define BSET_H

using namespace std;

template<typename T>
class BSet : public BObject {

    public:
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
                    result = std::move(result).erase(obj);
                }
            }
            return BSet(result);
        }

     	template<typename K = typename T::value_type>
     	BSet<K> intersect() const {
     	    if(this->size() == 0) {
     	        return BSet<K>();
     	    }
     	    BSet<K> result;
     	    int i = 0;
            for(const T& s : this->set) {
                if(i == 0) {
                    result = (BSet<K>) s;
                }
                ++i;
                result = result.intersect((BSet<K>)s);
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
                    result = std::move(result).erase(obj);
                }
            }
            return BSet(result);
        }

        BSet<T> _union(const BSet<T>& set) const {
            if(this->size() > set.size()) {
                immer::set<T,Hash, HashEqual> result = this->set;
                for (const T& obj : set.set) {
                    if(result.count(obj) == 0) {
                        result = std::move(result).insert(obj);
                    }
                }
                return BSet(result);
            } else {
                immer::set<T,Hash, HashEqual> result = set.set;
                for (const T& obj : this->set) {
                    if(result.count(obj) == 0) {
                        result = std::move(result).insert(obj);
                    }
                }
                return BSet(result);
            }
        }

     	template<typename K = typename T::value_type>
     	BSet<K> _union() const {
     	    BSet<K> result;
            for(const T& s : this->set) {
                result = result._union((BSet<K>) s);
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

    	BSet<BSet<T>> pow() const {
    		BSet<BSet<T>> result = BSet<BSet<T>>();
    		BSet<T> start = BSet<T>();
    		queue<BSet<T>> q = queue<BSet<T>>();
    		q.push(start);
    		result = result._union(BSet<BSet<T>>(start));
    		while(!q.empty()) {
    			BSet<T> currentSet = q.front();
    			q.pop();
    			for(T element : this->set) {
    				BSet<T> nextSet = currentSet._union(BSet<T>(element));
    				int previousSize = result.size();
    				result = result._union(BSet<BSet<T>>(nextSet));
    				if(previousSize < result.size()) {
    					q.push(nextSet);
    				}
    			}
    		}
    		return result;
    	}

    	BSet<BSet<T>> pow1() const {
    		return this->pow().difference(BSet<BSet<T>>(BSet<T>()));
    	}

    	BSet<BSet<T>> fin() const {
    		return this->pow();
    	}

    	BSet<BSet<T>> fin1() const {
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

        void operator =(const BSet<T>& other) {
            this->set = other.set;
        }

        int hashCode() const {
            return 0;
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