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
			.filter(object -> domain.contains(((BCouple<S,T>)object).getFirst()))
			.map(object -> ((BCouple<S,T>) object).getSecond())
			.collect(Collectors.toSet())));
	}


	public T functionCall(S arg) {
		List<BCouple<S,T>> matchedCouples = this.stream()
			.filter(couple -> couple.getFirst().equals(arg))
			.collect(Collectors.toList());
		if(matchedCouples.size() > 0) {
			return matchedCouples.get(0).getSecond();
		}
		throw new RuntimeException("Argument is not in the key set of this map");
	}

	public BSet<S> domain() {
		return new BSet(PersistentHashSet.create(this.set.stream()
				.map(object -> ((BCouple<S,T>) object).getFirst())
				.collect(Collectors.toList())));
	}

	public BSet<T> range() {
		return new BSet(PersistentHashSet.create(this.set.stream()
				.map(object -> ((BCouple<S,T>) object).getSecond())
				.collect(Collectors.toList())));
	}

	public BRelation<T,S> inverse() {
		return new BRelation<T, S>(PersistentHashSet.create(this.set.stream()
			.map(object -> {
				BCouple<S,T> couple = (BCouple<S,T>) object;
				return new BCouple<T,S>(couple.getSecond(), couple.getFirst());
			})
			.collect(Collectors.toList())));
	}

	public BRelation<S,T> domainRestriction(BSet<S> arg) {
		return new BRelation(PersistentHashSet.create(this.set.stream()
				.filter(object -> arg.contains(((BCouple<S,T>) object).getFirst()))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> domainSubstraction(BSet<S> arg) {
		return new BRelation(PersistentHashSet.create(this.set.stream()
				.filter(object -> !arg.contains(((BCouple<S,T>) object).getFirst()))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> rangeRestriction(BSet<T> arg) {
		return new BRelation(PersistentHashSet.create(this.set.stream()
				.filter(object -> arg.contains(((BCouple<S,T>) object).getSecond()))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> rangeSubstraction(BSet<T> arg) {
		return new BRelation(PersistentHashSet.create(this.set.stream()
				.filter(object -> !arg.contains(((BCouple<S,T>) object).getSecond()))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> override(BRelation<S,T> arg) {
		return arg.union(this.domainRestriction(arg.domain()));
	}

}
