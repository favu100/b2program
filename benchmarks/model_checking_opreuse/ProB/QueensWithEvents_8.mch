MACHINE QueensWithEvents_8
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
  Solve(solution) = SELECT
        solution : allFields
      // & solution : perm(interval)
      &  dom(solution) = interval
      &  ran(solution) = interval
      // & !(x,y,z).(x : interval & y:interval & z:interval & x|->y : solution & x|->z: solution => y=z)
      // this version works better with ProB:
      & !(x,y).(x:interval & y:interval & x|->y : solution    => !z.(z:interval & x|->z: solution => y=z))
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