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

	public BSet<T> domain() {
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

	public BRelation<S,T> domainRestriction(S arg) {
		return new BRelation<S, T>(PersistentHashSet.create(this.set.stream()
				.filter(object -> ((BCouple<S,T>) object).getFirst().equals(arg))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> domainSubstraction(S arg) {
		return new BRelation<S, T>(PersistentHashSet.create(this.set.stream()
				.filter(object -> !(((BCouple<S,T>) object).getFirst().equals(arg)))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> rangeRestriction(S arg) {
		return new BRelation<S, T>(PersistentHashSet.create(this.set.stream()
				.filter(object -> ((BCouple<S,T>) object).getSecond().equals(arg))
				.collect(Collectors.toList())));
	}

	public BRelation<S,T> rangeSubstraction(S arg) {
		return new BRelation<S, T>(PersistentHashSet.create(this.set.stream()
				.filter(object -> !(((BCouple<S,T>) object).getSecond().equals(arg)))
				.collect(Collectors.toList())));
	}

}
