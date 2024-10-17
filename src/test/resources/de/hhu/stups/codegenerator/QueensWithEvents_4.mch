MACHINE QueensWithEvents_4
// rewritten for B2Program by inlining DEFINITIONS
// v2: rewrote perm(1..n) for B2Program
CONSTANTS n, interval, allFields
PROPERTIES
 n : NATURAL &
 n = 4 &
 interval = 1..n &
 allFields = POW(interval * interval)
VARIABLES queens
INVARIANT
  queens : interval +-> interval
INITIALISATION
  queens := {}
OPERATIONS
  Solve =
      ANY solution WHERE
        solution : allFields
      & solution : perm(interval)
      &
        !(q1,q2).(
         (
          q1 : interval
          &
          q2 : interval \ {1}
          &
          q2 > q1
         )
         =>
         (
          (solution(q1) + q2) - q1 /= solution(q2)
          &
          (solution(q1) - q2) + q1 /= solution(q2)
         )
        )
      &
        !x.(
         x : dom(queens)
         =>
         solution(x) = queens(x)
        )
  THEN
     queens := solution
  END

END