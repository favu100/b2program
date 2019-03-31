package de.hhu.stups.btypes;

import clojure.lang.PersistentHashSet;

import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by fabian on 15.01.19.
 */
public class BRelation<S,T> extends BSet<BCouple<S,T>> {

	public BRelation(PersistentHashSet elements) {
		super(elements);
	}

	@SafeVarargs
	public BRelation(BCouple<S,T>... elements) {
		super(elements);
	}

	public BRelation<S,T> intersect(BRelation<S,T> set) {
		return new BRelation<>((PersistentHashSet) INTERSECTION.invoke(this.set, set.set));
	}

	public BRelation<S,T> difference(BRelation<S,T>set) {
		return new BRelation<>((PersistentHashSet) DIFFERENCE.invoke(this.set, set.set));
	}

	public BRelation<S,T> union(BRelation<S,T> set) {
		return new BRelation<>((PersistentHashSet) UNION.invoke(this.set, set.set));
	}

	public BInteger card() {
		return new BInteger(String.valueOf((int) COUNT.invoke(this.set)));
	}

	public BBoolean elementOf(BCouple<S,T> object) {
		return new BBoolean(this.set.contains(object));
	}

	public BBoolean notElementOf(BCouple<S,T> object) {
		return new BBoolean(!this.set.contains(object));
	}

	public BBoolean equal(BRelation<S,T> o) {
		return new BBoolean(equals(o));
	}

	public BBoolean unequal(BRelation<S,T> o) {
		return new BBoolean(!equals(o));
	}

	public BCouple<S,T> nondeterminism() {
		int index = (int) Math.floor(Math.random() * set.size());
		return toArray()[index];
	}

	public BSet<T> relationImage(BSet<S> domain) {
		return new BSet<T>(PersistentHashSet.create(this.set.stream()
			.filter(object -> domain.contains(((BCouple<S,T>)object).projection1()))
			.map(object -> ((BCouple<S,T>) object).projection2())
			.collect(Collectors.toSet())));
	}


	public T functionCall(S arg) {
		List<BCouple<S,T>> matchedCouples = this.stream()
			.filter(couple -> couple.projection1().equals(arg))
			.collect(Collectors.toList());
		if(matchedCouples.size() > 0) {
			return matchedCouples.get(0).projection2();
		}
		throw new RuntimeException("Argument is not in the key set of this map");
	}

	public BSet<S> domain() {
		return new BSet(PersistentHashSet.create(this.set.stream()
				.map(object -> ((BCouple<S,T>) object).projection1())
				.collect(Collectors.toList())));
	}

	public BSet<T> range() {
		return new BSet(PersistentHashSet.create(this.set.stream()
				.map(object -> ((BCouple<S,T>) object).projection2())
				.collect(Collectors.toList())));
	}

	public BRelation<T,S> inverse() {
		return new BRelation<T, S>(PersistentHashSet.create(this.set.stream()
			.map(object -> {
				BCouple<S,T> couple = (BCouple<S,T>) object;
				return new BCouple<T,S>(couple.projection2(), couple.projection1());
			})
			.collect(Collectors.toList())));
	}

	public BRelation<S,T> domainRestriction(BSet<S> arg) {
		return new BRelation(PersistentHashSet.create(this.set.stream()
				.filter(object -> arg.contains(((BCouple<S,T>) object).projection1()))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> domainSubstraction(BSet<S> arg) {
		return new BRelation(PersistentHashSet.create(this.set.stream()
				.filter(object -> !arg.contains(((BCouple<S,T>) object).projection1()))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> rangeRestriction(BSet<T> arg) {
		return new BRelation(PersistentHashSet.create(this.set.stream()
				.filter(object -> arg.contains(((BCouple<S,T>) object).projection2()))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> rangeSubstraction(BSet<T> arg) {
		return new BRelation(PersistentHashSet.create(this.set.stream()
				.filter(object -> !arg.contains(((BCouple<S,T>) object).projection2()))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> override(BRelation<S,T> arg) {
		return arg.union(this.domainRestriction(arg.domain()));
	}

	public T first() {
		return this.functionCall((S) new BInteger("1"));
	}

	public T last() {
		return this.functionCall((S) this.card());
	}

	public BRelation<S,T> reverse() {
		BInteger size = this.card();
		BRelation<S,T> result = new BRelation<>();
		for(BInteger i = new BInteger("1"); i.lessEqual(size).booleanValue(); i = i.next()) {
			result = result.union(new BRelation<>(new BCouple<>((S) i, (T) this.functionCall((S) size.minus(i).next()))));
		}
		return result;
	}

	public BRelation<S,T> front() {
		return this.domainSubstraction(new BSet<>((S) this.card()));
	}

	public BRelation<S,T> tail() {
		BRelation<S,T> result = new BRelation<>();
		BRelation<S,T> couplesWithoutFirst = this.domainSubstraction(new BSet<>((S) new BInteger("1")));
		for(BCouple<S,T> couple : couplesWithoutFirst) {
			result = result.union(new BRelation<>(new BCouple<>((S) ((BInteger) couple.projection1()).previous(), couple.projection2())));
		}
		return result;
	}

	public BRelation<S,T> take(BInteger n) {
		BRelation<S,T> result = new BRelation<>();
		for(BCouple<S,T> couple : this) {
			if(((BInteger) couple.projection1()).lessEqual(n).booleanValue()) {
				result = result.union(new BRelation<>(couple));
			}
		}
		return result;
	}

	public BRelation<S,T> drop(BInteger n) {
		BRelation<S,T> result = new BRelation<>();
		for(BCouple<S,T> couple : this) {
			if(((BInteger) couple.projection1()).greater(n).booleanValue()) {
				result = result.union(new BRelation<>(couple));
			}
		}
		return result;
	}

	public BRelation<S,T> concat(BRelation<S,T> arg) {
		BRelation<S,T> result = this;
		BInteger size = this.card();
		for(BCouple<S,T> couple : arg) {
			result = result.union(new BRelation<>(new BCouple<>((S) size.plus((BInteger) couple.projection1()), couple.projection2())));
		}
		return result;
	}

	public BRelation<S,T> append(T arg) {
		BInteger size = this.card();
		return this.union(new BRelation<>(new BCouple<>((S) size.next(), arg)));
	}

	public BRelation<S,T> prepend(T arg) {
		BRelation<S,T> result = new BRelation<>(new BCouple<>((S) new BInteger("1"), arg));
		for(BCouple<S,T> couple : this) {
			result = result.union(new BRelation<>(new BCouple<>((S) ((BInteger) couple.projection1()).next(), couple.projection2())));
		}
		return result;
	}

	public <R> BRelation<S,BCouple<T,R>> directProduct(BRelation<S,R> arg) {
		BRelation<S,BCouple<T,R>> result = new BRelation<>();
		for(BCouple<S,T> e1 : this) {
			for(BCouple<S,R> e2 : arg) {
				if(e1.projection1().equals(e2.projection1())) {
					result = result.union(new BRelation<>(new BCouple<>(e1.projection1(), new BCouple<>(e1.projection2(), e2.projection2()))));
				}
			}
		}
		return result;
	}

	public <R,A> BRelation<BCouple<S,R>,BCouple<T,A>> parallelProduct(BRelation<R,A> arg) {
		BRelation<BCouple<S,R>, BCouple<T,A>> result = new BRelation<>();
		for(BCouple<S,T> e1 : this) {
			for(BCouple<R,A> e2 : arg) {
				result = result.union(new BRelation<>(new BCouple<>(new BCouple<>(e1.projection1(), e2.projection1()), new BCouple<>(e1.projection2(), e2.projection2()))));
			}
		}
		return result;
	}

	public <R> BRelation<S,R> composition(BRelation<T,R> arg) {
		BRelation<S,R> result = new BRelation<>();
		for(BCouple<S,T> e1 : this) {
			for(BCouple <T,R> e2 : arg) {
				if(e1.projection2().equals(e2.projection1())) {
					result = result.union(new BRelation<>(new BCouple<>(e1.projection1(), e2.projection2())));
				}
			}
		}
		return result;
	}

	public BRelation<S,S> iterate(BInteger n) {
		BRelation<S,S> thisRelation = (BRelation<S,S>) this;
		BRelation<S,S> result = this.domain().identity();
		for(BInteger i = new BInteger("1"); i.lessEqual(n).booleanValue(); i = i.next()) {
			result = result.composition(thisRelation);
		}
		return result;
	}

}
