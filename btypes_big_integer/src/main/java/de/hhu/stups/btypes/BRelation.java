package de.hhu.stups.btypes;

import clojure.lang.PersistentHashSet;

import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by fabian on 15.01.19.
 */
public class BRelation<S,T> extends BSet<BTuple<S,T>> {

	public BRelation(PersistentHashSet elements) {
		super(elements);
	}

	@SafeVarargs
	public BRelation(BTuple<S,T>... elements) {
		super(elements);
	}

	@SuppressWarnings("unchecked")
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || getClass() != o.getClass())
			return false;

		BRelation<S,T> bObjects = (BRelation<S,T>) o;

		if (!set.equals(bObjects.set))
			return false;

		return true;
	}

	public int hashCode() {
		return set.hashCode();
	}

	public BRelation<S,T> intersect(BRelation<S,T> set) {
		return fromSet(super.intersect(set));
	}

	public BRelation<S,T> difference(BRelation<S,T>set) {
		return fromSet(super.difference(set));
	}

	public BRelation<S,T> union(BRelation<S,T> set) {
		return fromSet(super.union(set));
	}

	public static <S,T> BRelation<S,T> fromSet(BSet<BTuple<S,T>> set) {
		return new BRelation<S,T>(set.set);
	}

	public BInteger _size() {
		return new BInteger(COUNT.invoke(this.set).toString());
	}

	public BBoolean equal(BRelation<S,T> o) {
		return new BBoolean(equals(o));
	}

	public BBoolean unequal(BRelation<S,T> o) {
		return new BBoolean(!equals(o));
	}

	public BSet<T> relationImage(BSet<S> domain) {
		BSet<T> result = new BSet<T>();
		for(BTuple<S,T> tuple : this) {
			if(domain.contains(tuple.projection1())) {
				result = result.union(new BSet<T>(tuple.projection2()));
			}
		}
		return result;
	}


	public T functionCall(S arg) {
		for(BTuple<S,T> tuple : this) {
			if(tuple.projection1().equals(arg)) {
				return tuple.projection2();
			}
		}
		throw new RuntimeException("Argument is not in the domain of this relation");
	}

	public BSet<S> domain() {
		BSet<S> result = new BSet<S>();
		for(BTuple<S,T> tuple : this) {
			result = result.union(new BSet<S>(tuple.projection1()));
		}
		return result;
	}

	public BSet<T> range() {
		BSet<T> result = new BSet<T>();
		for(BTuple<S,T> tuple : this) {
			result = result.union(new BSet<T>(tuple.projection2()));
		}
		return result;
	}

	public BRelation<T,S> inverse() {
		BRelation<T,S> result = new BRelation<T,S>();
		for(BTuple<S,T> tuple : this) {
			result = result.union(new BRelation<T,S>(new BTuple<T,S>(tuple.projection2(), tuple.projection1())));
		}
		return result;
	}

	public BRelation<S,T> domainRestriction(BSet<S> arg) {
		BRelation<S,T> result = new BRelation<S,T>();
		for(BTuple<S,T> tuple : this) {
			if(arg.contains(tuple.projection1())) {
				result = result.union(new BRelation<S,T>(tuple));
			}
		}
		return result;
	}

	public BRelation<S,T> domainSubstraction(BSet<S> arg) {
		BRelation<S,T> result = new BRelation<S,T>();
		for(BTuple<S,T> tuple : this) {
			if(!arg.contains(tuple.projection1())) {
				result = result.union(new BRelation<S,T>(tuple));
			}
		}
		return result;
	}

	public BRelation<S,T> rangeRestriction(BSet<T> arg) {
		BRelation<S,T> result = new BRelation<S,T>();
		for(BTuple<S,T> tuple : this) {
			if(arg.contains(tuple.projection2())) {
				result = result.union(new BRelation<S,T>(tuple));
			}
		}
		return result;
	}

	public BRelation<S,T> rangeSubstraction(BSet<T> arg) {
		BRelation<S,T> result = new BRelation<S,T>();
		for(BTuple<S,T> tuple : this) {
			if(!arg.contains(tuple.projection2())) {
				result = result.union(new BRelation<S,T>(tuple));
			}
		}
		return result;
	}

	public BRelation<S,T> override(BRelation<S,T> arg) {
		return arg.union(this.domainSubstraction(arg.domain()));
	}

	@SuppressWarnings("unchecked")
	public T first() {
		return this.functionCall((S) new BInteger("1"));
	}

	@SuppressWarnings("unchecked")
	public T last() {
		return this.functionCall((S) this.card());
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> reverse() {
		BInteger size = this.card();
		BRelation<S,T> result = new BRelation<S,T>();
		for(BInteger i = new BInteger("1"); i.lessEqual(size).booleanValue(); i = i.succ()) {
			result = result.union(new BRelation<S,T>(new BTuple<S,T>((S) i, (T) this.functionCall((S) size.minus(i).succ()))));
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> front() {
		return this.domainSubstraction(new BSet<S>((S) this.card()));
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> tail() {
		BRelation<S,T> result = new BRelation<S,T>();
		BRelation<S,T> tuplesWithoutFirst = this.domainSubstraction(new BSet<S>((S) new BInteger("1")));
		for(BTuple<S,T> tuple : tuplesWithoutFirst) {
			result = result.union(new BRelation<S,T>(new BTuple<S,T>((S) ((BInteger) tuple.projection1()).pred(), tuple.projection2())));
		}
		return result;
	}

	public BRelation<S,T> take(BInteger n) {
		BRelation<S,T> result = new BRelation<S,T>();
		for(BTuple<S,T> tuple : this) {
			if(((BInteger) tuple.projection1()).lessEqual(n).booleanValue()) {
				result = result.union(new BRelation<S,T>(tuple));
			}
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> drop(BInteger n) {
		BRelation<S,T> result = new BRelation<S,T>();
		for(BTuple<S,T> tuple : this) {
			BInteger projection1 = (BInteger) tuple.projection1();
			if(projection1.greater(n).booleanValue()) {
				result = result.union(new BRelation<S,T>(new BTuple<S,T>((S) projection1.minus(n), tuple.projection2())));
			}
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> concat(BRelation<S,T> arg) {
		BRelation<S,T> result = this;
		BInteger size = this.card();
		for(BTuple<S,T> tuple : arg) {
			result = result.union(new BRelation<S,T>(new BTuple<S,T>((S) size.plus((BInteger) tuple.projection1()), tuple.projection2())));
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public <R,A> BRelation<R,A> conc() {
		BRelation<R,A> result = new BRelation<R,A>();
		BInteger size = this.card();
		for(BInteger i = new BInteger("1"); i.lessEqual(size).booleanValue(); i = i.succ()) {
			result = result.concat((BRelation<R,A>) functionCall((S) i));
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> append(T arg) {
		BInteger size = this.card();
		return this.union(new BRelation<S,T>(new BTuple<S,T>((S) size.succ(), arg)));
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,T> prepend(T arg) {
		BRelation<S,T> result = new BRelation<S,T>(new BTuple<S,T>((S) new BInteger("1"), arg));
		for(BTuple<S,T> tuple : this) {
			result = result.union(new BRelation<S,T>(new BTuple<S,T>((S) ((BInteger) tuple.projection1()).succ(), tuple.projection2())));
		}
		return result;
	}

	public <R> BRelation<S,BTuple<T,R>> directProduct(BRelation<S,R> arg) {
		BRelation<S,BTuple<T,R>> result = new BRelation<S,BTuple<T,R>>();
		for(BTuple<S,T> e1 : this) {
			for(BTuple<S,R> e2 : arg) {
				if(e1.projection1().equals(e2.projection1())) {
					result = result.union(new BRelation<S,BTuple<T,R>>(new BTuple<S,BTuple<T,R>>(e1.projection1(), new BTuple<>(e1.projection2(), e2.projection2()))));
				}
			}
		}
		return result;
	}

	public <R,A> BRelation<BTuple<S,R>,BTuple<T,A>> parallelProduct(BRelation<R,A> arg) {
		BRelation<BTuple<S,R>, BTuple<T,A>> result = new BRelation<BTuple<S,R>, BTuple<T,A>>();
		for(BTuple<S,T> e1 : this) {
			for(BTuple<R,A> e2 : arg) {
				result = result.union(new BRelation<BTuple<S,R>, BTuple<T,A>>(new BTuple<BTuple<S,R>, BTuple<T,A>>(new BTuple<S,R>(e1.projection1(), e2.projection1()), new BTuple<T,A>(e1.projection2(), e2.projection2()))));
			}
		}
		return result;
	}

	public <R> BRelation<S,R> composition(BRelation<T,R> arg) {
		BRelation<S,R> result = new BRelation<S,R>();
		for(BTuple<S,T> e1 : this) {
			for(BTuple <T,R> e2 : arg) {
				if(e1.projection2().equals(e2.projection1())) {
					result = result.union(new BRelation<S,R>(new BTuple<S,R>(e1.projection1(), e2.projection2())));
				}
			}
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,S> iterate(BInteger n) {
		BRelation<S,S> thisRelation = (BRelation<S,S>) this;
		BRelation<S,S> result = identity(this.domain());
		for(BInteger i = new BInteger("1"); i.lessEqual(n).booleanValue(); i = i.succ()) {
			result = result.union(result.composition(thisRelation));
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,S> closure() {
		BRelation<S,S> thisRelation = (BRelation<S,S>) this;
		BRelation<S,S> result = identity(this.domain());
		BRelation<S,S> nextResult = result.composition(thisRelation);
		BRelation<S,S> lastResult = null;
		do {
			lastResult = result;
			result = result.union(nextResult);
			nextResult = result.composition(thisRelation);
		} while(!result.equal(lastResult).booleanValue());
		return result;
	}

	@SuppressWarnings("unchecked")
	public BRelation<S,S> closure1() {
		BRelation<S,S> thisRelation = (BRelation<S,S>) this;
		BRelation<S,S> result = (BRelation<S,S>) this;
		BRelation<S,S> nextResult = result.composition(thisRelation);
		BRelation<S,S> lastResult = null;
		do {
			lastResult = result;
			result = result.union(nextResult);
			nextResult = result.composition(thisRelation);
		} while(!result.equal(lastResult).booleanValue());
		return result;
	}

	public static <S,T> BRelation<BTuple<S,T>, S> projection1(BSet<S> arg1, BSet<T> arg2) {
		BRelation<BTuple<S,T>, S> result = new BRelation<BTuple<S,T>, S>();
		for(S e1 : arg1) {
			for(T e2 : arg2) {
				result = result.union(new BRelation<BTuple<S,T>, S>(new BTuple<BTuple<S,T>, S>(new BTuple<S,T>(e1,e2), e1)));
			}
		}
		return result;
	}

	public static <S,T> BRelation<BTuple<S,T>, T> projection2(BSet<S> arg1, BSet<T> arg2) {
		BRelation<BTuple<S,T>, T> result = new BRelation<BTuple<S,T>, T>();
		for(S e1 : arg1) {
			for(T e2 : arg2) {
				result = result.union(new BRelation<BTuple<S,T>, T>(new BTuple<BTuple<S,T>, T>(new BTuple<S,T>(e1,e2), e2)));
			}
		}
		return result;
	}

	public BRelation<S,BSet<T>> fnc() {
		BRelation<S,BSet<T>> result = new BRelation<S, BSet<T>>();
		BSet<S> domain = this.domain();
		for(S e : domain) {
			BSet<T> range = this.relationImage(new BSet<S>(e));
			result = result.union(new BRelation<S, BSet<T>>(new BTuple<S, BSet<T>>(e, range)));
		}
		return result;
	}

	@SuppressWarnings("unchecked")
	public <R> BRelation<S,R> rel() {
		BRelation<S,R> result = new BRelation<S, R>();
		BSet<S> domain = this.domain();
		for(S e1 : domain) {
			BSet<R> range = (BSet<R>) this.functionCall(e1);
			for(R e2 : range) {
				result = result.union(new BRelation<S, R>(new BTuple<S,R>(e1,e2)));
			}
		}
		return result;
	}

	public static <T> BRelation<T,T> identity(BSet<T> arg) {
		BRelation<T,T> result = new BRelation<T,T>();
		for(T e : arg) {
			result = result.union(new BRelation<T,T>(new BTuple<T,T>(e,e)));
		}
		return result;
	}

	public BBoolean isTotal(BSet<S> domain) {
		return this.domain().equal(domain);
	}

	public BBoolean isPartial(BSet<S> domain) {
		return this.domain().strictSubset(domain);
	}

	public BBoolean isRelation() {
		return new BBoolean(true);
	}

	public BBoolean isFunction() {
		BSet<S> visited = new BSet<>();
		for(BTuple<S,T> couple : this) {
			S element = couple.projection1();
			if(visited.contains(element)) {
				return new BBoolean(false);
			}
			visited = visited.union(new BSet<>(element));
		}
		return new BBoolean(true);
	}

	public BBoolean isSurjection(BSet<T> range) {
		return this.range().equal(range);
	}

	public BBoolean isInjection(BSet<S> domain) {
		BSet<T> visited = new BSet<>();
		for(BTuple<S,T> couple : this) {
			T element = couple.projection2();
			if(visited.contains(element)) {
				return new BBoolean(false);
			}
			visited = visited.union(new BSet<>(element));
		}
		return new BBoolean(true);
	}

	public BBoolean isBijection(BSet<S> domain, BSet<T> range) {
		return isSurjection(range).and(isInjection(domain));
	}
}
