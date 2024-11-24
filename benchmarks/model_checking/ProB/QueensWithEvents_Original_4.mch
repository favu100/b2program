/*
From ProB examples
*/
MACHINE QueensWithEvents_Original_4 // close to the original
// rewritten for B2Program by inlining DEFINITIONS
// but not rewriting perm
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
  Solve(solution) = SELECT
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