/*
From ProB examples
*/
MACHINE QueensWithEvents_Original_8 // close to the original
// rewritten for B2Program by inlining DEFINITIONS
// but not rewriting perm
CONSTANTS n, interval
PROPERTIES
 n : NATURAL &
 n = 8 &
 interval = 1..n
VARIABLES queens
INVARIANT
  queens : interval +-> interval
INITIALISATION
  queens := {}
OPERATIONS
  Solve(solution) = SELECT
      solution : perm(interval)
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