#include <iostream>
#include <string>
#include <cstdarg>
#include <immer/set.hpp>
#include "BTuple.cpp"
#include "BSet.cpp"

#ifndef BRELATION_H
#define BRELATION_H


using namespace std;

template<typename S, typename T>
class BRelation : public BSet<BTuple<S,T>> {

    public:

        typedef BTuple<S,T> value_type;

        struct Hash {
            public:
                size_t operator()(const BTuple<S,T>& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const BTuple<S,T>& obj1, const BTuple<S,T>& obj2) const {

                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                }
        };

        BRelation<S,T>(const immer::set<BTuple<S,T>, Hash, HashEqual>& elements) {
            this->set = elements;
        }

        template<typename... Args>
        BRelation<S,T>(const Args&... args) {
          this->set = var(args...);
        }

        immer::set<BTuple<S,T>, BRelation<S,T>::Hash, BRelation<S,T>::HashEqual> var() {
          return immer::set<BTuple<S,T>, BRelation<S,T>::Hash, BRelation<S,T>::HashEqual>();
        }

        template<typename R, typename... Args>
        immer::set<BTuple<S,T>, BRelation<S,T>::Hash, BRelation<S,T>::HashEqual> var(const R& first, const Args&... args) {
          return var(args...).insert(first);
        }

        BRelation<S,T>() {
            this->set = immer::set<BTuple<S,T>, typename BRelation<S,T>::Hash, typename BRelation<S,T>::HashEqual>();
        }

        BRelation<S,T>(const BRelation<S,T>& set) {
            this->set = set.set;
        }

        BInteger card() {
            return BInteger(set.size());
        }

        BRelation<S,T> _union(const BRelation<S,T>& set) const {
            if(this->size() > set.size()) {
                immer::set<BTuple<S,T>,Hash, HashEqual> result = this->set;
                for (const BTuple<S,T>& obj : set.set) {
                    if(result.count(obj) == 0) {
                        result = std::move(result).insert(obj);
                    }
                }
                return BRelation(result);
            } else {
                immer::set<BTuple<S,T>,Hash, HashEqual> result = set.set;
                for (const BTuple<S,T>& obj : this->set) {
                    if(result.count(obj) == 0) {
                        result = std::move(result).insert(obj);
                    }
                }
                return BRelation(result);
            }
        }

        BSet<T> relationImage(const BSet<S>& domain) {
            immer::set<T,typename BSet<T>::Hash, typename BSet<T>::HashEqual> result;
            for(BTuple<S,T> tuple : this->set) {
                if(domain.contains(tuple.projection1())) {
                    result = result.insert(tuple.projection2());
                }
            }
            return BSet<T>(result);
        }


        T functionCall(const S& arg) {
            for(BTuple<S,T> tuple : this->set) {
                if(tuple.projection1() == arg) {
                    return tuple.projection2();
                }
            }
            throw runtime_error("Argument is not in the key set of this map");
        }

    	BSet<S> domain() const {
    	    immer::set<S,typename BSet<S>::Hash, typename BSet<S>::HashEqual> result;
    	    for(BTuple<S,T> tuple : this->set) {
                result = result.insert(tuple.projection1());
    	    }
            return BSet<S>(result);
    	}

    	BSet<T> range() const {
    	    immer::set<T,typename BSet<T>::Hash, typename BSet<T>::HashEqual> result;
    	    for(BTuple<S,T> tuple : this->set) {
                result = result.insert(tuple.projection2());
    	    }
            return BSet<T>(result);
    	}

        BRelation<T,S> inverse() {
            immer::set<BTuple<T,S>,typename BRelation<T,S>::Hash, typename BRelation<T,S>::HashEqual> result;
            for(BTuple<S,T> tuple : this->set) {
                result = result.insert(BTuple<T,S>(tuple.projection2(), tuple.projection1()));
            }
            return BRelation<T,S>(result);
        }

        BRelation<S,T> domainRestriction(const BSet<S>& arg) {
            immer::set<BTuple<S,T>,typename BRelation<S,T>::Hash, typename BRelation<S,T>::HashEqual> result;
            for(BTuple<S,T> tuple : this->set) {
                if(arg.contains(tuple.projection1())) {
                    result = result.insert(tuple);
                }
            }
            return BRelation<S,T>(result);
        }

        BRelation<S,T> domainSubstraction(const BSet<S>& arg) {
            immer::set<BTuple<S,T>,typename BRelation<S,T>::Hash, typename BRelation<S,T>::HashEqual> result;
            for(BTuple<S,T> tuple : this->set) {
                if(!arg.contains(tuple.projection1())) {
                    result = result.insert(tuple);
                }
            }
            return BRelation<S,T>(result);
        }

        BRelation<S,T> rangeRestriction(const BSet<T>& arg) {
            immer::set<BTuple<S,T>,typename BRelation<S,T>::Hash, typename BRelation<S,T>::HashEqual> result;
            for(BTuple<S,T> tuple : this->set) {
                if(arg.contains(tuple.projection2())) {
                    result = result.insert(tuple);
                }
            }
            return BRelation<S,T>(result);
        }

        BRelation<S,T> rangeSubstraction(const BSet<T>& arg) {
            immer::set<BTuple<S,T>,typename BRelation<S,T>::Hash, typename BRelation<S,T>::HashEqual> result;
            for(BTuple<S,T> tuple : this->set) {
                if(!arg.contains(tuple.projection2())) {
                    result = result.insert(tuple);
                }
            }
            return BRelation<S,T>(result);
        }

        BRelation<S,T> override(const BRelation<S,T>& arg) {
            return arg._union(this->domainRestriction(arg.domain()));
        }

    	T first() {
    		return functionCall((S) BInteger(1));
    	}

    	T last() {
    		return functionCall((S) card());
    	}

    	BRelation<S,T> reverse() {
    		BInteger size = card();
    		BRelation<S,T> result = BRelation<S,T>();
    		for(BInteger i = BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
    			result = result._union(BRelation<S,T>(BTuple<S,T>((S) i, (T) functionCall((S) size.minus(i).succ()))));
    		}
    		return result;
    	}

    	BRelation<S,T> front() {
    		return domainSubstraction(BSet<S>((S) card()));
    	}

    	BRelation<S,T> tail() {
    		BRelation<S,T> result = BRelation<S,T>();
    		BRelation<S,T> tuplesWithoutFirst = domainSubstraction(BSet<S>((S) BInteger(1)));
    		for(BTuple<S,T> tuple : tuplesWithoutFirst) {
    			result = result._union(BRelation<S,T>(BTuple<S,T>((S) ((BInteger) tuple.projection1()).pred(), tuple.projection2())));
    		}
    		return result;
    	}

    	BRelation<S,T> take(const BInteger& n) {
    		BRelation<S,T> result = BRelation<S,T>();
    		for(BTuple<S,T> tuple : this->set) {
    			if(((BInteger) tuple.projection1()).lessEqual(n).booleanValue()) {
    				result = result._union(BRelation<S,T>(tuple));
    			}
    		}
    		return result;
    	}

    	BRelation<S,T> drop(const BInteger& n) {
    		BRelation<S,T> result = BRelation<S,T>();
    		for(BTuple<S,T> tuple : this->set) {
    			if(((BInteger) tuple.projection1()).greater(n).booleanValue()) {
    				result = result._union(BRelation<S,T>(tuple));
    			}
    		}
    		return result;
    	}

    	BRelation<S,T> concat(const BRelation<S,T>& arg) {
    		BRelation<S,T> result = *this;
    		BInteger size = card();
    		for(BTuple<S,T> tuple : arg.set) {
    			result = result._union(BRelation<S,T>(BTuple<S,T>((S) size.plus((BInteger) tuple.projection1()), tuple.projection2())));
    		}
    		return result;
    	}

    	BRelation<S,T> append(const T& arg) {
    		BInteger size = card();
    		return _union(BRelation<S,T>(BTuple<S,T>((S) size.succ(), arg)));
    	}

    	BRelation<S,T> prepend(const T& arg) {
    		BRelation<S,T> result = BRelation<S,T>(BTuple<S,T>((S) BInteger(1), arg));
    		for(BTuple<S,T> tuple : this->set) {
    			result = result._union(BRelation<S,T>(BTuple<S,T>((S) ((BInteger) tuple.projection1()).succ(), tuple.projection2())));
    		}
    		return result;
    	}

    	template<typename R>
    	BRelation<S,BTuple<T,R>> directProduct(const BRelation<S,R>& arg) {
    		BRelation<S,BTuple<T,R>> result = BRelation<S,BTuple<T,R>>();
    		for(BTuple<S,T> e1 : this->set) {
    			for(BTuple<S,R> e2 : arg.set) {
    				if(e1.projection1().equal(e2.projection1()).booleanValue()) {
    					result = result._union(BRelation<S, BTuple<T, R>>(BTuple<S, BTuple<T,R>>(e1.projection1(), BTuple<T,R>(e1.projection2(), e2.projection2()))));
    				}
    			}
    		}
    		return result;
    	}

    	template<typename R,typename A>
    	BRelation<BTuple<S,R>,BTuple<T,A>> parallelProduct(const BRelation<R,A>& arg) {
    		BRelation<BTuple<S,R>, BTuple<T,A>> result = BRelation<BTuple<S, R>, BTuple<T, A>>();
    		for(BTuple<S,T> e1 : this->set) {
    			for(BTuple<R,A> e2 : arg.set) {
    				result = result._union(BRelation<BTuple<S, R>, BTuple<T, A>>(BTuple<BTuple<S, R>, BTuple<T, A>>(BTuple<S,R>(e1.projection1(), e2.projection1()), BTuple<T,A>(e1.projection2(), e2.projection2()))));
    			}
    		}
    		return result;
    	}

    	template <typename R>
    	BRelation<S,R> composition(const BRelation<T,R>& arg) {
    		BRelation<S,R> result = BRelation<S,R>();
    		for(BTuple<S,T> e1 : this->set) {
    			for(BTuple <T,R> e2 : arg.set) {
    				if(e1.projection2().equal(e2.projection1()).booleanValue()) {
    					result = result._union(BRelation<S,R>(BTuple<S,R>(e1.projection1(), e2.projection2())));
    				}
    			}
    		}
    		return result;
    	}

        static BRelation<T,T> identity(const BSet<T>& set) {
            BRelation<T,T> result;
            for(const T& e : set.getSet()) {
                result = result._union(BRelation<T,T>(BTuple<T,T>(e,e)));
            }
            return result;
        }

    	BRelation<S,S> iterate(BInteger n) {
    		BRelation<S,S> thisRelation = (BRelation<S,S>) *this;
            BRelation<T,T> result;
            for(const T& e : this->domain()) {
                result = result._union(BRelation<T,T>(BTuple<T,T>(e,e)));
            }
    		for(BInteger i = BInteger(1); i.lessEqual(n).booleanValue(); i = i.succ()) {
    			result = thisRelation.composition(result);
    		}
    		return result;
    	}

    	BRelation<S,S> closure() {
    		BRelation<S,S> thisRelation = (BRelation<S,S>) *this;
            BRelation<T,T> result;
            for(const T& e : this->domain()) {
                result = result._union(BRelation<T,T>(BTuple<T,T>(e,e)));
            }
    		BRelation<S,S> nextResult = result.composition(thisRelation);
    		while(!result.equal(nextResult).booleanValue()) {
    			result = nextResult;
    			nextResult = result.composition(thisRelation);
    		}
    		return result;
    	}

    	BRelation<S,S> closure1() {
    		BRelation<S,S> thisRelation = (BRelation<S,S>) *this;
    		BRelation<S,S> result = (BRelation<S,S>) *this;
    		BRelation<S,S> nextResult = result.composition(thisRelation);
    		while(!result.equal(nextResult).booleanValue()) {
    			result = nextResult;
    			nextResult = result.composition(thisRelation);
    		}
    		return result;
    	}

        static BRelation<BTuple<S,T>, S> projection1(const BSet<S>& arg1, const BSet<T>& arg2) {
            BRelation<BTuple<S,T>, S> result = BRelation<BTuple<S,T>, S>();
            for(S e1 : arg1.getSet()) {
                for(T e2 : arg2.getSet()) {
                    result = result._union(BRelation<BTuple<S,T>, S>(BTuple<BTuple<S,T>, S>(BTuple<S,T>(e1,e2), e1)));
                }
            }
            return result;
        }

    	static BRelation<BTuple<S,T>, T> projection2(const BSet<S>& arg1, const BSet<T>& arg2) {
    		BRelation<BTuple<S,T>, T> result = BRelation<BTuple<S,T>, T>();
    		for(S e1 : arg1.getSet()) {
    			for(T e2 : arg2.getSet()) {
    				result = result._union(BRelation<BTuple<S,T>, T>(BTuple<BTuple<S,T>, T>(BTuple<S,T>(e1,e2), e2)));
    			}
    		}
    		return result;
    	}

    	BRelation<S,BSet<T>> fnc() {
    		BRelation<S,BSet<T>> result = BRelation<S, BSet<T>>();
    		BSet<S> domain = this->domain();
    		for(S e : domain) {
    			BSet<T> range = this->relationImage(BSet<S>(e));
    			result = result._union(BRelation<S, BSet<T>>(BTuple<S, BSet<T>>(e, range)));
    		}
    		return result;
    	}

    	template<typename R = typename T::value_type>
    	BRelation<S,R> rel() {
    		BRelation<S,R> result = BRelation<S, R>();
    		BSet<S> domain = this->domain();
    		for(S e1 : domain) {
    			BSet<R> range = (BSet<R>) this->functionCall(e1);
    			for(R e2 : range) {
    				result = result._union(BRelation<S, R>(BTuple<S,R>(e1,e2)));
    			}
    		}
    		return result;
    	}

        void operator =(const BRelation<S,T>& other) {
            this->set = other.set;
        }

        int hashCode() const {
            return 0;
        }

        friend std::ostream& operator<<(std::ostream &strm, const BRelation<S,T>& rel) {
            strm << "{";
            typename immer::set<BTuple<S,T>,Hash, HashEqual>::const_iterator it = rel.begin();
            while(it != rel.end()) {
                BTuple<S,T> tuple = *it;
                strm << tuple;
                ++it;
                if(it != rel.end()) {
                    strm << ",";
                }
            }
            strm << "}";
            return strm;
        }

        typename immer::set<BTuple<S,T>,Hash, HashEqual>::const_iterator begin() const {
            return set.begin();
        }

        typename immer::set<BTuple<S,T>,Hash, HashEqual>::const_iterator end() const {
            return set.end();
        }

        protected:
            immer::set<BTuple<S,T>,Hash, HashEqual> set;

};

#endif