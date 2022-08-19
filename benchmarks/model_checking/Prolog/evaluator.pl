:- module(evaluator, [elementOf/3,
                      notElementOf/3,
                      isNatural/2,
                      cartesianProduct/3,
                      pow/3,
                      range/3,
                      domain/3,
                      card/3,
                      less/2,
                      less/3,
                      greater/2,
                      greater/3,
                      lessEqual/2,
                      lessEqual/3,
                      greaterEqual/2,
                      greaterEqual/3,
                      equal/3,
                      unequal/3,
                      plus/4,
                      minus/4,
                      mult/4,
                      div/4,
                      difference/4,
                      union/4,
                      intersect/4,
                      subset/3,
                      empty/1,
                      update/4,
                      avl2List/2,
                      b_member/2]).

:- use_module(library(avl)).
:- use_module(library(lists)).
:- use_module(library(sets)).

elementOf(State, X, List) :-
    (var(X); (nonvar(X), \+ avl:avl_fetch(X, State))),
    lists:is_list(List),
    member(X, List),
    !.
elementOf(State, X, Key) :-
    var(X),
    avl:avl_fetch(Key, State, List),
    member(X, List),
    !.
elementOf(State, Key, interval(A, B)) :-
    nonvar(Key),
    avl:avl_fetch(Key, State, Value),
    greaterEqual(Value, A),
    lessEqual(Value, B),
    !.
elementOf(State, Key, List) :-
    nonvar(Key),
    avl:avl_fetch(Key, State, Value),
    member(Value, List),
    !.

notElementOf(S, A, B) :-
    \+ elementOf(S, A, B),
    !.

isNatural(State, Key) :-
    avl:avl_fetch(Key, State, Value),
    Value > 0,
    integer(Value),
    !.

% implement (e.g. 1..100 * 1..100, NAT * NAT)
% avl-tree key: integer, value: list of integer
cartesianProduct(_, _, notImplemented).

pow(_, List, Pow) :-
    sets:setof(P, lists:subseq0(List, P), Pow),
    !.

range(State, Key, Range) :-
    avl:avl_fetch(Key, State, Value),
    range(Value, Range),
    !.

range([], []) :- !.
range([(R/_) | Tail], [R | Range]) :-
    range(Tail, Range),
    !.

domain(State, Key, Domain) :-
    avl:avl_fetch(Key, State, Value),
    domain(Value, Domain), !.

domain([], []) :- !.
domain([(_/D) | Tail], [D | Domain]) :-
    domain(Tail, Domain),
    !.

card(State, Key, Card) :-
    avl:avl_fetch(Key, State, Value),
    length(Value, Card), !.

less(A, B) :- A < B.
less(State, Key, X) :-
    avl:avl_fetch(Key, State, Value),
    less(Value, X).

greater(A, B) :- A > B.
greater(State, Key, X) :-
    avl:avl_fetch(Key, State, Value),
    greater(Value, X).

lessEqual(A, B) :- A =< B.
lessEqual(State, Key, X) :-
    avl:avl_fetch(Key, State, Value),
    lessEqual(Value, X).
lessEqual(_, A, B) :- lessEqual(A, B).

greaterEqual(A, B) :- A >= B.
greaterEqual(State, Key, X) :-
    avl:avl_fetch(Key, State, Value),
    greaterEqual(Value, X).

equal(State, Key, Value) :-
    avl:avl_fetch(Key, State, Value),
    !.

unequal(State, Key, Value) :-
    avl:avl_fetch(Key, State, X),
    X \= Value,
    !.

plus(State, Key, X, NewValue) :-
    avl:avl_fetch(Key, State, Value),
    NewValue is Value + X.

minus(State, Key, X, NewValue) :-
    avl:avl_fetch(Key, State, Value),
    NewValue is Value - X.

mult(State, Key, X, NewValue) :-
    avl:avl_fetch(Key, State, Value),
    NewValue is Value * X.

div(State, Key, X, NewValue) :-
    avl:avl_fetch(Key, State, Value),
    NewValue is Value / X.

difference(State, Key, Set, Diff) :-
    nonvar(Key),
    avl:avl_fetch(Key, State, Value),
    findall(X,
        (member(X, Value), \+ member(X, Set)),
        Diff),
    !.

union(State, Key, Set, Union) :-
    nonvar(Key),
    lists:is_list(Set),
    avl:avl_fetch(Key, State, Value),
    sets:union(Value, Set, Union),
    !.
union(State, Set, Key, Union) :-
    nonvar(Key),
    lists:is_list(Set),
    avl:avl_fetch(Key, State, Value),
    sets:union(Value, Set, Union),
    !.
union(State, Key1, Key2, Union) :-
    nonvar(Key1),
    nonvar(Key2),
    avl:avl_fetch(Key1, State, Value1),
    avl:avl_fetch(Key2, State, Value2),
    sets:union(Value1, Value2, Union),
    !.

intersect(State, Key, Set, Inter) :-
    nonvar(Key),
    lists:is_list(Set),
    avl:avl_fetch(Key, State, Value),
    sets:intersection(Value, Set, Inter),
    !.
intersect(State, Set, Key, Inter) :-
    nonvar(Key),
    lists:is_list(Set),
    avl:avl_fetch(Key, State, Value),
    sets:intersection(Value, Set, Inter),
    !.
intersect(State, Key1, Key2, Inter) :-
    nonvar(Key1),
    nonvar(Key2),
    avl:avl_fetch(Key1, State, Value1),
    avl:avl_fetch(Key2, State, Value2),
    sets:intersection(Value1, Value2, Inter),
    !.

subset(State, Key, Set) :-
    nonvar(Key),
    lists:is_list(Set);
    avl:avl_fetch(Key, State, Value),
    lists:subseq0(Value, Set),
    !.

b_member(Val, interval(Val, Val)) :- !.
b_member(A, interval(A, B)) :-
    A < B.
b_member(Val, interval(A, B)) :-
    A1 is A + 1,
    b_member(Val, interval(A1, B)).


next(interval(A, A), A, empty).
next(interval(A, B), A, interval(A1, B)) :-
    A \= B,
    A1 is A + 1.


% AVL TREE
empty(T) :- avl:empty_avl(T).

update(Key, Value, AVL, NewAVL) :-
    avl:avl_store(Key, AVL, Value, NewAVL).

avl2List(Tree, List) :-
    avl:avl_to_list(Tree, List).