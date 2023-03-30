MACHINE MultiLift

SETS LIFTS = {Lift1, Lift2, Lift3, Lift4}

CONCRETE_CONSTANTS LiftOrder

VARIABLES  ActiveLifts, InactiveLifts, NextActiveLift

PROPERTIES
  LiftOrder : LIFTS --> 1..4
  & LiftOrder = {Lift1 |-> 1, Lift2 |-> 2, Lift3 |-> 3, Lift4 |-> 4}

INVARIANT
  ActiveLifts : LIFTS +-> -2..10
  & card(dom(ActiveLifts)) > 0
  & InactiveLifts <: LIFTS
  & LIFTS \ InactiveLifts = dom(ActiveLifts)
  & NextActiveLift : dom(ActiveLifts) +-> dom(ActiveLifts)
  // Enforce ordered cycle in NextActiveLift, ie. keep NextActiveLift consistent no matter the insert order.
  & !(l).((l : dom(ActiveLifts)) => (LiftOrder(l) /= max(LiftOrder[dom(ActiveLifts)]) => LiftOrder(NextActiveLift(l)) = min(LiftOrder[{lift | lift : dom(NextActiveLift) & LiftOrder(lift) > LiftOrder(l)}]) ))
  & !(l).((l : dom(ActiveLifts)) => (LiftOrder(l) = max(LiftOrder[dom(ActiveLifts)]) => LiftOrder(NextActiveLift(l)) = min(LiftOrder[dom(NextActiveLift)])))

INITIALISATION
  ActiveLifts := {Lift1 |-> 0}
  || InactiveLifts := {Lift2, Lift3, Lift4}
  || NextActiveLift := {Lift1 |-> Lift1}

OPERATIONS

  inc_lift(l) =
    PRE
        l : dom(ActiveLifts)
      & ActiveLifts(l) < 10
    THEN
      ActiveLifts(l) := ActiveLifts(l) + 1
    END;

  dec_lift(l) =
    PRE
        l : dom(ActiveLifts)
      & ActiveLifts(l) > -2
    THEN
       ActiveLifts(l) := ActiveLifts(l) - 1
    END;

  init_lift(l) =
    PRE
      l : InactiveLifts
    THEN
      LET smallerLifts, biggerLifts BE smallerLifts = {al| al: dom(NextActiveLift) & LiftOrder(al) < LiftOrder(l)} & biggerLifts = {al| al: dom(NextActiveLift) & LiftOrder(al) > LiftOrder(l)}
      IN
        ActiveLifts(l) := 0
        || InactiveLifts := InactiveLifts \ { l }
        || IF card(smallerLifts) = 0
           THEN NextActiveLift(LiftOrder~(max(LiftOrder[biggerLifts]))) := l; NextActiveLift(l) := LiftOrder~(min(LiftOrder[biggerLifts])) // if smallerLifts is empty, biggerLifts cannot be empty (since ActiveLifts cannot be empty)
           ELSE NextActiveLift(LiftOrder~(max(LiftOrder[smallerLifts]))) := l; IF card(biggerLifts) = 0
                                                                                          THEN NextActiveLift(l) := LiftOrder~(min(LiftOrder[smallerLifts]))
                                                                                          ELSE NextActiveLift(l) := LiftOrder~(min(LiftOrder[biggerLifts]))
                                                                                          END
           END
        // For some reason, B2Program doesn't like the if here...
        /*; IF card(biggerLifts) = 0
           THEN NextActiveLift(l) := LiftOrder~(min(LiftOrder[smallerLifts]))
           ELSE NextActiveLift(l) := LiftOrder~(min(LiftOrder[biggerLifts]))
           END*/
      END
    END;

  close_lift(l) =
    PRE
      l : dom(ActiveLifts)
      & card(dom(ActiveLifts)) > 1
    THEN
      ActiveLifts := {l} <<| ActiveLifts
      || InactiveLifts := InactiveLifts \/ { l }
      || LET l_pred, l_succ BE l_pred = NextActiveLift~(l) & l_succ = NextActiveLift(l) IN
         NextActiveLift := NextActiveLift \ {l |-> l_succ}
         ; NextActiveLift(l_pred) := l_succ
         END
    END;

  out <-- getFloor(l) =
    PRE
      l : dom(ActiveLifts)
    THEN
      out := ActiveLifts(l)
    END

END