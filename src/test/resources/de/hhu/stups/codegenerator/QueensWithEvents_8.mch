/*
From ProB examples
*/
MACHINE QueensWithEvents_8
// rewritten for B2Program by inlining DEFINITIONS
// v2: rewrote perm(1..n) for B2Program
CONSTANTS n
PROPERTIES
 n : NATURAL &
 n = 8
VARIABLES queens
INVARIANT
  queens : 1..n +-> 1..n
INITIALISATION
  queens := {}
OPERATIONS
  Solve =
      ANY solution WHERE
        solution : POW((1..n) * (1..n))
      & solution : perm(1..n)
      &
        !(q1,q2).(
         (
          q1 : 1..n
          &
          q2 : (1..n) \ {1}
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