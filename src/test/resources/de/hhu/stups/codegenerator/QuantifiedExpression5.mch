MACHINE QuantifiedExpression5

VARIABLES  set

INVARIANT  set : POW(INTEGER)

INITIALISATION set := {}

OPERATIONS

    calculate = BEGIN set := UNION(x,y).(x : 1..10 & y : x..3 & y > x| {x + y}) END;
    out <-- getRes = out := card(set)

END