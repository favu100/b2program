MACHINE QueensWithEvents
// rewritten for B2Program by inlining DEFINITIONS
// v2: rewrote perm(1..n)
CONSTANTS n, interval, allFields
PROPERTIES
 n : NATURAL &
 n = 8 &
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
      // & solution : perm(interval)
      & !(x,y,z).(x:interval & y:interval & z:interval & x|->y : solution & x|->z: solution => y=z)
      &  ran(solution) = interval
        // this actually implies it is a bijection
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