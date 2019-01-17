package de.hhu.stups.btypes;

import clojure.lang.PersistentHashSet;

import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by fabian on 15.01.19.
 */
public class BRelation<S,T> extends BSet<BCouple<S,T>> {

    @SafeVarargs
    public BRelation(BCouple<S,T>... elements) {
        super(elements);
    }

    public BSet<T> relationImage(BSet<S> domain) {
        return new BSet(HashTreePSet.from(set.stream()
                .filter(object -> domain.contains(((BCouple) object).getFirst()))
                .map(object -> ((BCouple) object).getSecond())
                .collect(Collectors.toSet())));
    }


    public T functionCall(BObject arg) {
        List<T> matchedCouples = set.stream()
                .map(object -> (BCouple) object)
                .filter(couple -> couple.getFirst().equals(arg))
                .collect(Collectors.toList());
        if(matchedCouples.size() > 0) {
            return matchedCouples.get(0).getSecond();
        }
        throw new RuntimeException("Argument is not in the key set of this map");
    }

}
