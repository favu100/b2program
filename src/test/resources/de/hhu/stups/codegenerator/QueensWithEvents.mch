MACHINE QueensWithEvents
CONSTANTS n
PROPERTIES
 n : NATURAL &
 n = 8
VARIABLES queens
INVARIANT
  queens : (1..n) +-> (1..n)
INITIALISATION
  queens := {}
OPERATIONS
  Solve(solution)= SELECT
        solution : (1 .. n) <-> (1 .. n)
      & solution : perm(1 .. n)
      &
        !(q1,q2).(
         (
          q1 : 1 .. n
          &
          q2 : 2 .. n
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