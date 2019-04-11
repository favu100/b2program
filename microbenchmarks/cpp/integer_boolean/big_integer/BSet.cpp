#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include <immer/set.hpp>
#include "BInteger.cpp"
#include "BCouple.cpp"

#ifndef BSET_H
#define BSET_H

using namespace std;

template<typename T>
class BSet : public BObject {



    public:

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

        BSet<T>(const BSet<T>& set) {
            this->set = set.set;
        }

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

        static BSet<BInteger> range(const BInteger& a, const BInteger& b) {
            immer::set<BInteger, Hash, HashEqual> result;
            int end = b.intValue();
            for(int i = a.intValue(); i < end; ++i) {
                result = result.insert(i);
            }
            return BSet(result);
        }


        BInteger card() {
            return BInteger(set.size());
        }

        BBoolean elementOf(const T& object) {
            return BBoolean(set.count(object) > 0);
        }

        BBoolean notElementOf(const T& object) {
            return BBoolean(set.count(object) == 0);
        }

        T nondeterminism() {
		    int index = rand() % set.size();
		    typename immer::set<T,Hash, HashEqual>::const_iterator it = std::next(set.begin(), index);
		    return *it;
	    }

        friend bool operator !=(const BSet<T>& o1, const BSet<T>& o2) {
            return o1.value != o2.value;
        }

        friend bool operator ==(const BSet<T>& o1, const BSet<T>& o2) {
            return o1.value == o2.value;
        }

        BBoolean equal(const BSet<T>& other) {
            return BBoolean(this->set == other.set);
        }

        BBoolean unequal(const BSet<T>& other) {
            return BBoolean(this->set != other.set);
        }

        void operator =(const BSet<T>& other) {
            this->set = other.set;
        }

        int hashCode() const {
            return 0;
        }

        typename immer::set<T,Hash, HashEqual>::const_iterator begin() {
            return set.begin();
        }

        typename immer::set<T,Hash, HashEqual>::const_iterator end() {
            return set.end();
        }

        protected:
            immer::set<T,Hash, HashEqual> set;
};
#endif