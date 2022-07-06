MACHINE GenericTimersMC

SETS TIMERS = {blink_deadline, tip_deadline}

VARIABLES
  curDeadlines

INVARIANT
  curDeadlines : TIMERS +-> NATURAL


INITIALISATION
  curDeadlines := {}

OPERATIONS
  
  AbsoluteSetDeadline(timer,deadline) = PRE timer:TIMERS & deadline:NATURAL THEN
     curDeadlines(timer) := deadline
  END;
  
  AddDeadline(timer,deadline) = PRE timer:TIMERS & deadline:NATURAL THEN
     curDeadlines(timer) := deadline
  END;
  
  // Increase time without exceeding a deadline
  IncreaseTime(delta) = SELECT delta:NATURAL & 
      (curDeadlines/={} => delta <= min(ran(curDeadlines))) THEN
     curDeadlines := %x.(x:dom(curDeadlines)|curDeadlines(x)-delta)
  END;
  
  IncreaseTimeUntilDeadline(timer,delta) =
   SELECT timer : dom(curDeadlines) &
          delta:NATURAL &
          delta = min(ran(curDeadlines)) & 
          delta = curDeadlines(timer) THEN
     curDeadlines := %x.(x:dom(curDeadlines) \ {timer}|curDeadlines(x)-delta)
  END;
  
  IncreaseTimeUntilCyclicDeadline(timer,delta,newDelta) =
   SELECT timer : dom(curDeadlines) &
          delta:NATURAL &
          newDelta:NATURAL &
          delta = curDeadlines(timer)  &
          delta = min(ran(curDeadlines))
  THEN
     curDeadlines := %x.(x:dom(curDeadlines) \ {timer}|curDeadlines(x)-delta) \/ {timer |-> newDelta}
  END

END
  
  