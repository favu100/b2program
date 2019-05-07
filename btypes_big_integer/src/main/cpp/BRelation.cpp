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
        typedef S left_type;
        typedef T right_type;

        BRelation<S,T>(const immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual>& elements) {
            this->set = elements;
        }

        template<typename... Args>
        BRelation<S,T>(const Args&... args) {
          this->set = var(args...);
        }

        immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual> var() {
          return immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual>();
        }

        template<typename R, typename... Args>
        immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual> var(const R& first, const Args&... args) {
          return var(args...).insert(first);
        }

        BRelation<S,T>() {
            this->set = immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual>();
        }

        BRelation<S,T>(const BRelation<S,T>& set) {
            this->set = set.set;
        }

        BRelation<S,T>(const BSet<BTuple<S,T>>& set) {
            immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual> otherSet = set.getSet();
            this->set = immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual>();
            for(const BTuple<S,T>& tuple : otherSet) {
                this->set = this->set.insert(tuple);
            }
        }

        BInteger _size() const {
            return BInteger(this->set.size());
        }

        BSet<T> relationImage(const BSet<S>& domain) const {
            immer::set<T,typename BSet<T>::Hash, typename BSet<T>::HashEqual> result;
            for(BTuple<S,T> tuple : this->set) {
                if(domain.contains(tuple.projection1())) {
                    result = result.insert(tuple.projection2());
                }
            }
            return BSet<T>(result);
        }


        T functionCall(const S& arg) const {
            for(const BTuple<S,T>& tuple : this->set) {
                if((tuple.projection1()).equal(arg).booleanValue()) {
                    return tuple.projection2();
                }
            }
            throw runtime_error("Argument is not in the domain of this function");
        }

    	BSet<S> domain() const {
    	    immer::set<S,typename BSet<S>::Hash, typename BSet<S>::HashEqual> result;
    	    for(const BTuple<S,T>& tuple : this->set) {
                result = result.insert(tuple.projection1());
    	    }
            return BSet<S>(result);
    	}

    	BSet<T> range() const {
    	    immer::set<T,typename BSet<T>::Hash, typename BSet<T>::HashEqual> result;
    	    for(const BTuple<S,T>& tuple : this->set) {
                result = result.insert(tuple.projection2());
    	    }
            return BSet<T>(result);
    	}

        BRelation<T,S> inverse() const {
            immer::set<BTuple<T,S>,typename BRelation<T,S>::Hash, typename BRelation<T,S>::HashEqual> result;
            for(const BTuple<S,T>& tuple : this->set) {
                result = result.insert(BTuple<T,S>(tuple.projection2(), tuple.projection1()));
            }
            return BRelation<T,S>(result);
        }

        BRelation<S,T> domainRestriction(const BSet<S>& arg) const {
            immer::set<BTuple<S,T>,typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual> result;
            for(const BTuple<S,T>& tuple : this->set) {
                if(arg.contains(tuple.projection1())) {
                    result = result.insert(tuple);
                }
            }
            return BRelation<S,T>(result);
        }

        BRelation<S,T> domainSubstraction(const BSet<S>& arg) const {
            immer::set<BTuple<S,T>,typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual> result;
            for(const BTuple<S,T>& tuple : this->set) {
                if(!arg.contains(tuple.projection1())) {
                    result = result.insert(tuple);
                }
            }
            return BRelation<S,T>(result);
        }

        BRelation<S,T> rangeRestriction(const BSet<T>& arg) const {
            immer::set<BTuple<S,T>,typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual> result;
            for(const BTuple<S,T>& tuple : this->set) {
                if(arg.contains(tuple.projection2())) {
                    result = result.insert(tuple);
                }
            }
            return BRelation<S,T>(result);
        }

        BRelation<S,T> rangeSubstraction(const BSet<T>& arg) const {
            immer::set<BTuple<S,T>,typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual> result;
            for(const BTuple<S,T>& tuple : this->set) {
                if(!arg.contains(tuple.projection2())) {
                    result = result.insert(tuple);
                }
            }
            return BRelation<S,T>(result);
        }

        BRelation<S,T> override(const BRelation<S,T>& arg) const {
            return arg._union(this->domainSubstraction(arg.domain()));
        }

    	T first() const {
    		return functionCall((S) BInteger("1"));
    	}

    	T last() const {
    		return functionCall((S) this->card());
    	}

    	BRelation<S,T> reverse() const {
    		BInteger size = this->card();
    		BRelation<S,T> result = BRelation<S,T>();
    		for(BInteger i = BInteger("1"); i.lessEqual(size).booleanValue(); i = i.succ()) {
    			result = result._union(BRelation<S,T>(BTuple<S,T>((S) i, (T) functionCall((S) size.minus(i).succ()))));
    		}
    		return result;
    	}

    	BRelation<S,T> front() const {
    		return this->domainSubstraction(BSet<S>((S) this->card()));
    	}

    	BRelation<S,T> tail() const {
    		BRelation<S,T> result = BRelation<S,T>();
    		BRelation<S,T> tuplesWithoutFirst = domainSubstraction(BSet<S>((S) BInteger("1")));
    		for(const BTuple<S,T>& tuple : tuplesWithoutFirst) {
    			result = result._union(BRelation<S,T>(BTuple<S,T>((S) ((BInteger) tuple.projection1()).pred(), tuple.projection2())));
    		}
    		return result;
    	}

    	BRelation<S,T> take(const BInteger& n) const {
    		BRelation<S,T> result = BRelation<S,T>();
    		for(const BTuple<S,T>& tuple : this->set) {
    			if(((BInteger) tuple.projection1()).lessEqual(n).booleanValue()) {
    				result = result._union(BRelation<S,T>(tuple));
    			}
    		}
    		return result;
    	}

    	BRelation<S,T> drop(const BInteger& n) const {
    		BRelation<S,T> result = BRelation<S,T>();
    		for(const BTuple<S,T>& tuple : this->set) {
    		    BInteger projection1 = (BInteger) tuple.projection1();
    			if(projection1.greater(n).booleanValue()) {
    				result = result._union(BRelation<S,T>(BTuple<S,T>((S) projection1.minus(n), tuple.projection2())));
    			}
    		}
    		return result;
    	}

    	BRelation<S,T> concat(const BRelation<S,T>& arg) const {
    		BRelation<S,T> result = *this;
    		BInteger size = this->card();
    		for(const BTuple<S,T>& tuple : arg.set) {
    			result = result._union(BRelation<S,T>(BTuple<S,T>((S) size.plus((BInteger) tuple.projection1()), tuple.projection2())));
    		}
    		return result;
    	}

    	template<typename R = typename T::left_type, typename A = typename T::right_type>
    	BRelation<R,A> conc() const {
    		BRelation<R,A> result = BRelation<R,A>();
    		BInteger size = this->card();
    		for(BInteger i = BInteger("1"); i.lessEqual(size).booleanValue(); i = i.succ()) {
    			result = result.concat((BRelation<R,A>) functionCall((S) i));
    		}
    		return result;
    	}

    	BRelation<S,T> append(const T& arg) {
    		BInteger size = this->card();
    		return this->_union(BRelation<S,T>(BTuple<S,T>((S) size.succ(), arg)));
    	}

    	BRelation<S,T> prepend(const T& arg) {
    		BRelation<S,T> result = BRelation<S,T>(BTuple<S,T>((S) BInteger("1"), arg));
    		for(const BTuple<S,T>& tuple : this->set) {
    			result = result._union(BRelation<S,T>(BTuple<S,T>((S) ((BInteger) tuple.projection1()).succ(), tuple.projection2())));
    		}
    		return result;
    	}

    	template<typename R>
    	BRelation<S,BTuple<T,R>> directProduct(const BRelation<S,R>& arg) {
    		BRelation<S,BTuple<T,R>> result = BRelation<S,BTuple<T,R>>();
    		for(const BTuple<S,T>& e1 : this->set) {
    			for(const BTuple<S,R>& e2 : arg.set) {
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
    		for(const BTuple<S,T>& e1 : this->set) {
    			for(const BTuple<R,A>& e2 : arg.set) {
    				result = result._union(BRelation<BTuple<S, R>, BTuple<T, A>>(BTuple<BTuple<S, R>, BTuple<T, A>>(BTuple<S,R>(e1.projection1(), e2.projection1()), BTuple<T,A>(e1.projection2(), e2.projection2()))));
    			}
    		}
    		return result;
    	}

    	template<typename R>
    	BRelation<S,R> composition(const BRelation<T,R>& arg) {
    		BRelation<S,R> result = BRelation<S,R>();
    		for(const BTuple<S,T>& e1 : this->set) {
    			for(const BTuple <T,R>& e2 : arg.set) {
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

    	BRelation<S,S> iterate(const BInteger& n) const {
    		BRelation<S,S> thisRelation = (BRelation<S,S>) *this;
            BRelation<S,S> result = BRelation<S,S>::identity(this->domain());
    		for(BInteger i = BInteger("1"); i.lessEqual(n).booleanValue(); i = i.succ()) {
    			result = result._union(result.composition(thisRelation));
    		}
    		return result;
    	}

    	BRelation<S,S> closure() const {
    		BRelation<S,S> thisRelation = (BRelation<S,S>) *this;
            BRelation<S,S> result = BRelation<S,S>::identity(this->domain());
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
            BRelation<BTuple<S,T>, S> result = BRelation<BTuple<S,T>, S>();
            for(const S& e1 : arg1.getSet()) {
                for(const T& e2 : arg2.getSet()) {
                    result = result._union(BRelation<BTuple<S,T>, S>(BTuple<BTuple<S,T>, S>(BTuple<S,T>(e1,e2), e1)));
                }
            }
            return result;
        }

    	static BRelation<BTuple<S,T>, T> projection2(const BSet<S>& arg1, const BSet<T>& arg2) {
    		BRelation<BTuple<S,T>, T> result = BRelation<BTuple<S,T>, T>();
    		for(const S& e1 : arg1.getSet()) {
    			for(const T& e2 : arg2.getSet()) {
    				result = result._union(BRelation<BTuple<S,T>, T>(BTuple<BTuple<S,T>, T>(BTuple<S,T>(e1,e2), e2)));
    			}
    		}
    		return result;
    	}

    	BRelation<S,BSet<T>> fnc() const {
    		BRelation<S,BSet<T>> result = BRelation<S, BSet<T>>();
    		BSet<S> domain = this->domain();
    		for(const S& e : domain) {
    			BSet<T> range = this->relationImage(BSet<S>(e));
    			result = result._union(BRelation<S, BSet<T>>(BTuple<S, BSet<T>>(e, range)));
    		}
    		return result;
    	}

    	template<typename R = typename T::value_type>
    	BRelation<S,R> rel() const {
    		BRelation<S,R> result = BRelation<S, R>();
    		BSet<S> domain = this->domain();
    		for(const S& e1 : domain) {
    			BSet<R> range = (BSet<R>) this->functionCall(e1);
    			for(const R& e2 : range) {
    				result = result._union(BRelation<S, R>(BTuple<S,R>(e1,e2)));
    			}
    		}
    		return result;
    	}

        void operator =(const BRelation<S,T>& other) {
            this->set = other.set;
        }

        void operator =(const BSet<BTuple<S,T>>& other) {
            immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual> otherSet = other.getSet();
            this->set = immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual>();
            for(const BTuple<S,T>& tuple : otherSet) {
                this->set = this->set.insert(tuple);
            }
        }

        friend bool operator !=(const BRelation<S,T>& o1, const BRelation<S,T>& o2) {
            return o1.set != o2.set;
        }

        friend bool operator ==(const BRelation<S,T>& o1, const BRelation<S,T>& o2) {
            return o1.set == o2.set;
        }

        BBoolean equal(const BRelation<S,T>& other) const {
            return BBoolean(this->set == other.set);
        }

        BBoolean unequal(const BRelation<S,T>& other) const {
            return BBoolean(this->set != other.set);
        }

        friend std::ostream& operator<<(std::ostream &strm, const BRelation<S,T>& rel) {
            strm << "{";
            typename immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual>::const_iterator it = rel.begin();
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

        typename immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual>::const_iterator begin() const {
            return this->set.begin();
        }

        typename immer::set<BTuple<S,T>, typename BSet<BTuple<S,T>>::Hash, typename BSet<BTuple<S,T>>::HashEqual>::const_iterator end() const {
            return this->set.end();
        }
};

#endif