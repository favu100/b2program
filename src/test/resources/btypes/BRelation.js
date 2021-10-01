import { BTuple } from "./BTuple.js";
import { BSet } from "./BSet.js";
import { BInteger } from "./BInteger.js";
import { BBoolean } from "./BBoolean.js";
import { BString } from "./BString.js";
import { BStruct } from "./BStruct.js";
import * as immutable from "../immutable/dist/immutable.es.js";
export class BRelation {
    constructor(...args) {
        if (args.length === 0) {
            this.map = immutable.Map();
        }
        else if (args.length == 1 && args[0] instanceof immutable.Map) {
            this.map = args[0];
        }
        else {
            this.map = immutable.Map();
            for (let e of args) {
                let key = e.projection1();
                let value = e.projection2();
                let set = this.map.get(key);
                if (set == null) {
                    set = immutable.Set();
                }
                set = set.add(value);
                this.map = this.map.set(key, set);
            }
        }
    }
    static fromSet(set) {
        let resultMap = immutable.Map();
        set.getSet().forEach(e => {
            let key = e.projection1();
            let value = e.projection2();
            let range = resultMap.get(key);
            if (range == null) {
                range = immutable.Set([value]);
                resultMap = resultMap.set(key, range);
            }
            else {
                range = range.add(value);
                resultMap = resultMap.set(key, range);
            }
        });
        return new BRelation(resultMap);
    }
    equals(o) {
        if (o == null || !(o instanceof BRelation))
            return false;
        return this.map.equals(o.map);
    }
    intersect(relation) {
        let otherMap = relation.map;
        let otherDomain = immutable.Set(otherMap.keys());
        let thisDomain = immutable.Set(this.map.keys());
        let intersectionDomain = thisDomain.intersect(otherDomain);
        let differenceDomain = thisDomain.subtract(otherDomain);
        let resultMap = this.map;
        intersectionDomain.forEach((domainElement) => {
            let thisRangeSet = this.map.get(domainElement);
            let otherRangeSet = otherMap.get(domainElement);
            resultMap = resultMap.set(domainElement, thisRangeSet.intersect(otherRangeSet));
        });
        differenceDomain.forEach((domainElement) => {
            resultMap = resultMap.set(domainElement, immutable.Set());
        });
        return new BRelation(resultMap);
    }
    difference(relation) {
        let otherMap = relation.map;
        let otherDomain = otherMap.keys();
        let thisDomain = immutable.Set(this.map.keys());
        let differenceDomain = thisDomain.subtract(otherDomain);
        let restDomain = thisDomain.subtract(differenceDomain);
        let resultMap = this.map;
        differenceDomain.forEach((domainElement) => {
            let thisRangeSet = this.map.get(domainElement);
            let otherRangeSet = otherMap.get(domainElement);
            resultMap = resultMap.set(domainElement, thisRangeSet.subtract(otherRangeSet));
        });
        restDomain.forEach((domainElement) => {
            resultMap = resultMap.set(domainElement, immutable.Set());
        });
        return new BRelation(resultMap);
    }
    union(relation) {
        let otherMap = relation.map;
        let otherDomain = immutable.Set(otherMap.keys());
        let resultMap = this.map;
        for (let domainElement of otherDomain) {
            let thisRangeSet = this.map.get(domainElement);
            let otherRangeSet = otherMap.get(domainElement);
            resultMap = resultMap.set(domainElement, thisRangeSet == null ? otherRangeSet : otherRangeSet == null ? otherRangeSet : thisRangeSet.union(otherRangeSet));
        }
        return new BRelation(resultMap);
    }
    size() {
        let size = 0;
        let thisDomain = immutable.Set(this.map.keys());
        for (let domainElement of thisDomain) {
            let thisRangeSet = this.map.get(domainElement);
            if (thisRangeSet == null) {
                continue;
            }
            size += thisRangeSet.size;
        }
        return size;
    }
    card() {
        return new BInteger(this.size());
    }
    equal(o) {
        return new BBoolean(this.equals(o));
    }
    unequal(o) {
        return new BBoolean(!this.equals(o));
    }
    elementOf(object) {
        let prj1 = object.projection1();
        let prj2 = object.projection2();
        if (!this.map.has(prj1)) {
            return new BBoolean(false);
        }
        let range = this.map.get(prj1);
        return new BBoolean(range.has(prj2));
    }
    notElementOf(object) {
        let prj1 = object.projection1();
        let prj2 = object.projection2();
        if (!this.map.has(prj1)) {
            return new BBoolean(true);
        }
        let range = this.map.get(prj1);
        return new BBoolean(!range.has(prj2));
    }
    relationImage(domain) {
        let resultSet = immutable.Set();
        for (let this_domain_elem of this.map.keys()) {
            for (let other_domain_elem of domain.set) {
                if (other_domain_elem.equals(this_domain_elem)) {
                    let thisRangeSet = this.map.get(this_domain_elem);
                    if (thisRangeSet != null) {
                        resultSet = BSet.immutableSetUnion(resultSet, thisRangeSet);
                    }
                }
            }
        }
        return new BSet(resultSet);
    }
    functionCall(arg) {
        let range = undefined;
        for (let elem of this.map.keys()) {
            if (elem.equals(arg)) {
                range = this.map.get(elem);
            }
        }
        if (range == null) {
            throw new Error("Argument is not in the domain of this relation");
        }
        for (let element of range) {
            return element;
        }
        throw new Error("Argument is not in the domain of this relation");
    }
    pow() {
        let thisMap = this.map;
        let thisDomain = immutable.Set(thisMap.keys());
        let result = new BSet();
        let start = new BRelation();
        let queue = [];
        queue.push(start);
        result = result.union(new BSet(start));
        while (queue.length !== 0) {
            let currentSet = queue.pop();
            for (let domainElement of thisDomain) {
                let range = thisMap.get(domainElement);
                range.forEach(rangeElement => {
                    let nextRelation = currentSet.union(BRelation.fromSet(new BSet(new BTuple(domainElement, rangeElement))));
                    let previousSize = result.size().intValue();
                    result = result.union(new BSet(nextRelation));
                    if (previousSize < result.size().intValue()) {
                        queue.push(nextRelation);
                    }
                });
            }
        }
        return result;
    }
    pow1() {
        return this.pow().difference(new BSet(new BRelation()));
    }
    fin() {
        return this.pow();
    }
    fin1() {
        return this.pow1();
    }
    domain() {
        let resultSet = immutable.Set(this.map.keys());
        for (let domainElement of this.map.keys()) {
            let range = this.map.get(domainElement);
            if (range.size === 0) {
                resultSet = resultSet.remove(domainElement);
            }
        }
        return new BSet(resultSet);
    }
    range() {
        let set = immutable.Set.union(this.map.values());
        return new BSet(set);
    }
    inverse() {
        let thisMap = this.map;
        let keys = immutable.Set(thisMap.keys());
        let resultMap = immutable.Map();
        for (let domainElement of keys) {
            let range = this.map.get(domainElement);
            range.forEach((rangeElement) => {
                let currentRange = resultMap.get(rangeElement);
                if (currentRange == null) {
                    currentRange = immutable.Set();
                }
                currentRange = currentRange.union(immutable.Set([domainElement]));
                resultMap = resultMap.set(rangeElement, currentRange);
            });
        }
        return new BRelation(resultMap);
    }
    domainRestriction(arg) {
        let resultMap = this.map;
        outer_loop: for (let obj of resultMap.keys()) {
            for (let obj2 of arg.set) {
                if (obj2.equals(obj)) {
                    continue outer_loop;
                }
            }
            resultMap = resultMap.delete(obj);
        }
        return new BRelation(resultMap);
    }
    domainSubstraction(arg) {
        let resultMap = this.map;
        for (let obj of resultMap.keys()) {
            for (let obj2 of arg.set) {
                if (obj2.equals(obj)) {
                    resultMap = resultMap.delete(obj);
                    break;
                }
            }
        }
        return new BRelation(resultMap);
    }
    rangeRestriction(arg) {
        let otherSet = arg.getSet();
        let thisDomain = immutable.Set(this.map.keys());
        let resultMap = this.map;
        for (let domainElement of thisDomain) {
            let thisRangeSet = this.map.get(domainElement);
            resultMap = resultMap.set(domainElement, BSet.immutableSetIntersection(thisRangeSet, otherSet));
        }
        return new BRelation(resultMap);
    }
    rangeSubstraction(arg) {
        let otherSet = arg.getSet();
        let thisDomain = immutable.Set(this.map.keys());
        let resultMap = this.map;
        for (let domainElement of thisDomain) {
            let thisRangeSet = this.map.get(domainElement);
            resultMap = resultMap.set(domainElement, BSet.immutableSetDifference(thisRangeSet, otherSet));
        }
        return new BRelation(resultMap);
    }
    override(arg) {
        let otherMap = arg.map;
        let otherDomain = immutable.Set(otherMap.keys());
        let resultMap = this.map;
        outer_loop: for (let domainElement of otherDomain) {
            for (let thisDomainElement of resultMap.keys()) {
                if (thisDomainElement.equals(domainElement)) {
                    let range = otherMap.get(domainElement);
                    resultMap = resultMap.set(thisDomainElement, range);
                    continue outer_loop;
                }
            }
            resultMap = resultMap.set(domainElement, otherMap.get(domainElement));
        }
        return new BRelation(resultMap);
    }
    first() {
        return this.functionCall(new BInteger(1));
    }
    last() {
        return this.functionCall(this.card());
    }
    reverse() {
        let size = this.card();
        let resultMap = immutable.Map();
        for (let i = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
            let rangeElement = this.functionCall(size.minus(i).succ());
            resultMap = resultMap.set(i, immutable.Set([rangeElement]));
        }
        return new BRelation(resultMap);
    }
    front() {
        return this.domainSubstraction(new BSet(this.card()));
    }
    tail() {
        let size = this.card();
        let resultMap = immutable.Map();
        for (let i = new BInteger(2); i.lessEqual(size).booleanValue(); i = i.succ()) {
            let rangeElement = this.functionCall(i);
            resultMap = resultMap.set(i.pred(), immutable.Set([rangeElement]));
        }
        return new BRelation(resultMap);
    }
    take(n) {
        let size = this.card();
        if (n.greaterEqual(size).booleanValue()) {
            return new BRelation(this.map);
        }
        let resultMap = this.map;
        //Remove immutable.Sets with index greater than n
        for (let i = n.succ(); i.lessEqual(size).booleanValue(); i = i.succ()) {
            for (let index of resultMap.keys()) {
                if (index.equals(i)) {
                    resultMap = resultMap.delete(index);
                    break;
                }
            }
        }
        return new BRelation(resultMap);
    }
    drop(n) {
        let size = this.card();
        let thisMap = this.map;
        let resultMap = immutable.Map();
        for (let i = n.succ(); i.lessEqual(size).booleanValue(); i = i.succ()) {
            let currentSet = thisMap.get(i);
            resultMap = resultMap.set(i.minus(n), currentSet);
        }
        return new BRelation(resultMap);
    }
    concat(arg) {
        let resultMap = this.map;
        let otherMap = arg.map;
        let size = this.card();
        for (let i = new BInteger(1); i.lessEqual(arg.card()).booleanValue(); i = i.succ()) {
            resultMap = resultMap.set(size.plus(i), otherMap.get(i));
        }
        return new BRelation(resultMap);
    }
    conc() {
        let result = new BRelation();
        let size = this.card();
        for (let i = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
            result = result.concat(this.functionCall(i));
        }
        return result;
    }
    append(arg) {
        let resultMap = this.map;
        resultMap = resultMap.set(this.card().succ(), immutable.Set([arg]));
        return new BRelation(resultMap);
    }
    prepend(arg) {
        let resultMap = immutable.Map();
        let thisMap = this.map;
        let size = this.card();
        for (let i = new BInteger(1); i.lessEqual(size).booleanValue(); i = i.succ()) {
            resultMap = resultMap.set(i.succ(), thisMap.get(i));
        }
        resultMap = resultMap.set(new BInteger(1), immutable.Set([arg]));
        return new BRelation(resultMap);
    }
    directProduct(arg) {
        let thisMap = this.map;
        let thisDomain = immutable.Set(thisMap.keys());
        let otherMap = arg.map;
        let resultMap = immutable.Map();
        for (let domainElement of thisDomain) {
            let thisRange = this.map.get(domainElement);
            let otherRange = otherMap.get(domainElement);
            if (otherRange == undefined) {
                continue;
            }
            let resultRange = immutable.Set();
            thisRange.forEach(lhs => {
                otherRange.forEach(rhs => {
                    resultRange = immutable.Set.union([resultRange, immutable.Set([new BTuple(lhs, rhs)])]);
                });
            });
            resultMap = resultMap.set(domainElement, resultRange);
        }
        return new BRelation(resultMap);
    }
    parallelProduct(arg) {
        let thisMap = this.map;
        let thisDomain = immutable.Set(thisMap.keys());
        let otherMap = arg.map;
        let otherDomain = immutable.Set(otherMap.keys());
        let resultMap = immutable.Map();
        for (let domainElementThis of thisDomain) {
            for (let domainElementOther of otherDomain) {
                let thisRange = thisMap.get(domainElementThis);
                let otherRange = otherMap.get(domainElementOther);
                let resultRange = immutable.Set();
                thisRange.forEach(lhs => {
                    otherRange.forEach(rhs => {
                        resultRange = resultRange.union(immutable.Set([new BTuple(lhs, rhs)]));
                    });
                });
                let tuple = new BTuple(domainElementThis, domainElementOther);
                resultMap = resultMap.set(tuple, resultRange);
            }
        }
        return new BRelation(resultMap);
    }
    composition(arg) {
        let thisMap = this.map;
        let otherMap = arg.map;
        let resultMap = immutable.Map();
        for (let domainElement of this.map.keys()) {
            let range = this.map.get(domainElement);
            let set = immutable.Set();
            range.forEach((rangeElement) => {
                let union_element = otherMap.get(rangeElement);
                if (union_element == null) {
                    return;
                }
                set = set.union(union_element);
            });
            resultMap = resultMap.set(domainElement, set);
        }
        return new BRelation(resultMap);
    }
    iterate(n) {
        let thisRelation = this;
        let result = BRelation.identity(this.domain());
        for (let i = new BInteger(1); i.lessEqual(n).booleanValue(); i = i.succ()) {
            result = result.union(result.composition(thisRelation));
        }
        return result;
    }
    closure() {
        let thisRelation = this;
        let result = BRelation.identity(this.domain());
        let nextResult = result.composition(thisRelation);
        let lastResult = result;
        do {
            lastResult = result;
            result = result.union(nextResult);
            nextResult = result.composition(thisRelation);
        } while (!result.equal(lastResult).booleanValue());
        return result;
    }
    closure1() {
        let thisRelation = this;
        let result = this;
        let nextResult = result.composition(thisRelation);
        let lastResult = null;
        do {
            lastResult = result;
            result = result.union(nextResult);
            nextResult = result.composition(thisRelation);
        } while (!result.equal(lastResult).booleanValue());
        return result;
    }
    static projection1(arg1, arg2) {
        let argSet1 = arg1.getSet();
        let argSet2 = arg2.getSet();
        let resultMap = immutable.Map();
        argSet1.forEach(e1 => {
            argSet2.forEach(e2 => {
                let tuple = new BTuple(e1, e2);
                resultMap = resultMap.set(tuple, immutable.Set([e1]));
            });
        });
        return new BRelation(resultMap);
    }
    static projection2(arg1, arg2) {
        let argSet1 = arg1.getSet();
        let argSet2 = arg2.getSet();
        let resultMap = immutable.Map();
        argSet1.forEach(e1 => {
            argSet2.forEach(e2 => {
                let tuple = new BTuple(e1, e2);
                resultMap = resultMap.set(tuple, immutable.Set([e2]));
            });
        });
        return new BRelation(resultMap);
    }
    fnc() {
        let thisMap = this.map;
        let domain = this.domain().getSet();
        let resultMap = immutable.Map();
        domain.forEach(domainElement => {
            let range = thisMap.get(domainElement);
            let rangeSet = new BSet([range]);
            resultMap = resultMap.set(domainElement, immutable.Set([rangeSet]));
        });
        return new BRelation(resultMap);
    }
    rel() {
        let domain = this.domain().getSet();
        let resultMap = immutable.Map();
        domain.forEach(domainElement => {
            let range = this.functionCall(domainElement);
            let rangeSet = range.getSet();
            resultMap = resultMap.set(domainElement, rangeSet);
        });
        return new BRelation(resultMap);
    }
    static identity(arg) {
        let resultMap = immutable.Map();
        arg.getSet().forEach(e => {
            resultMap = resultMap.set(e, immutable.Set([e]));
        });
        return new BRelation(resultMap);
    }
    static cartesianProduct(arg1, arg2) {
        let resultMap = immutable.Map();
        arg1.getSet().forEach(e1 => {
            resultMap = resultMap.set(e1, arg2.getSet());
        });
        return new BRelation(resultMap);
    }
    nondeterminism() {
        let domain = immutable.Set(this.map.keys());
        let index = Math.floor(Math.random() * domain.size);
        let i = 0;
        let domainElement = undefined;
        for (let obj of domain) {
            if (i == index) {
                domainElement = obj;
                break;
            }
            i++;
        }
        if (domainElement == undefined) {
            return null;
        }
        let range = this.map.get(domainElement);
        if (range != null) {
            index = Math.floor(Math.random() * range.size);
            i = 0;
            for (let obj of range) {
                if (i == index) {
                    return new BTuple(domainElement, obj);
                }
                i++;
            }
        }
        return null;
    }
    isTotal(domain) {
        return new BBoolean(this.domain().equal(domain));
    }
    isTotalInteger() {
        return new BBoolean(false);
    }
    isTotalNatural() {
        return new BBoolean(false);
    }
    isTotalNatural1() {
        return new BBoolean(false);
    }
    isTotalString() {
        return new BBoolean(false);
    }
    isTotalStruct() {
        return new BBoolean(false);
    }
    isPartial(domain) {
        return this.domain().strictSubset(domain);
    }
    isPartialInteger() {
        this.domain().getSet().forEach(e => {
            if (e instanceof BInteger) {
                return new BBoolean(true);
            }
            else {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    isPartialNatural() {
        this.domain().getSet().forEach(e => {
            if (e instanceof BInteger && !e.isNatural().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    isPartialNatural1() {
        this.domain().getSet().forEach(e => {
            if (e instanceof BInteger && !e.isNatural1().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    isPartialString() {
        this.domain().getSet().forEach(e => {
            if (e instanceof BString && !e.isString().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    isPartialStruct() {
        this.domain().getSet().forEach(e => {
            if (e instanceof BStruct && !e.isRecord().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    checkDomain(domain) {
        return this.domain().subset(domain);
    }
    checkDomainInteger() {
        this.domain().getSet().forEach(e => {
            if (e instanceof BInteger) {
                return new BBoolean(true);
            }
            else {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    checkDomainNatural() {
        this.domain().getSet().forEach(e => {
            if (e instanceof BInteger && !e.isNatural().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    checkDomainNatural1() {
        this.domain().getSet().forEach(e => {
            if (e instanceof BInteger && !e.isNatural1().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    checkDomainString() {
        this.domain().getSet().forEach(e => {
            if (e instanceof BString && !e.isString().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    checkDomainStruct() {
        this.domain().getSet().forEach(e => {
            if (e instanceof BStruct && !e.isRecord().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    checkRange(range) {
        return this.range().subset(range);
    }
    checkRangeInteger() {
        this.range().getSet().forEach(e => {
            if (e instanceof BInteger) {
                return new BBoolean(true);
            }
            else {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    checkRangeNatural() {
        this.range().getSet().forEach(e => {
            if (e instanceof BInteger && !e.isNatural().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    checkRangeNatural1() {
        this.range().getSet().forEach(e => {
            if (e instanceof BInteger && !e.isNatural1().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    checkRangeString() {
        this.range().getSet().forEach(e => {
            if (e instanceof BString && !e.isString().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    checkRangeStruct() {
        this.range().getSet().forEach(e => {
            if (e instanceof BStruct && !e.isRecord().booleanValue()) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    isRelation() {
        return new BBoolean(true);
    }
    isFunction() {
        this.domain().getSet().forEach(element => {
            let range = this.map.get(element);
            if (range.size > 1) {
                return new BBoolean(false);
            }
        });
        return new BBoolean(true);
    }
    isSurjection(range) {
        return new BBoolean(this.range().equal(range));
    }
    isSurjectionInteger() {
        return new BBoolean(false);
    }
    isSurjectionNatural() {
        return new BBoolean(false);
    }
    isSurjectionNatural1() {
        return new BBoolean(false);
    }
    isSurjectionString() {
        return new BBoolean(false);
    }
    isSurjectionStruct() {
        return new BBoolean(false);
    }
    isInjection() {
        let visited = immutable.Set();
        this.domain().getSet().forEach(element => {
            let range = this.map.get(element);
            range.forEach(rangeElement => {
                if (visited.contains(rangeElement)) {
                    return new BBoolean(false);
                }
                visited = visited.union(immutable.Set([rangeElement]));
            });
        });
        return new BBoolean(true);
    }
    isBijection(range) {
        return this.isSurjection(range).and(this.isInjection());
    }
    isBijectionInteger() {
        return new BBoolean(false);
    }
    isBijectionNatural() {
        return new BBoolean(false);
    }
    isBijectionNatural1() {
        return new BBoolean(false);
    }
    isBijectionString() {
        return new BBoolean(false);
    }
    isBijectionStruct() {
        return new BBoolean(false);
    }
    toString() {
        let size = this.size();
        let i = 0;
        let sb = "";
        sb = sb + "{";
        for (let domainElement of this.map.keys()) {
            let range = this.map.get(domainElement);
            range.forEach(rangeElement => {
                sb += "(";
                sb += domainElement.toString();
                sb += " |-> ";
                sb += rangeElement.toString();
                sb += ")";
                if (i + 1 < size) {
                    sb += ", ";
                }
                i++;
            });
        }
        sb += "}";
        return sb.toString();
    }
    hashCode() {
        return this.map.hashCode();
    }
}
