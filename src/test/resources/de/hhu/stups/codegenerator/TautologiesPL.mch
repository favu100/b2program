MACHINE TautologiesPL
/* A list of tautologies taken from
   http://pythonism.wordpress.com/2010/09/13/propositional-logic-and-some-tautologiess
   in turn taken from the book "Logic" by Wilfried Hodges
*/
VARIABLES p,q,r
INVARIANT
  not((p=TRUE) & not((p=TRUE)))
 &
  ((p=TRUE) or not((p=TRUE)))
 &
  ((p=TRUE) <=> not(not((p=TRUE))))
 &
  (((p=TRUE) or (q=TRUE)) <=> not(not((p=TRUE)) & not((q=TRUE))))
 &
  (((p=TRUE) or (q=TRUE)) <=> (not((p=TRUE)) => (q=TRUE)))
 &
  (((p=TRUE) or (q=TRUE)) <=> ((q=TRUE) or (p=TRUE)))
 &
  ((((p=TRUE) or (q=TRUE)) or (r=TRUE)) <=> ((p=TRUE) or ((q=TRUE) or (r=TRUE))))
 &
  (((p=TRUE) or (p=TRUE)) <=> (p=TRUE))
 &
  ((p=TRUE) => ((p=TRUE) or (q=TRUE)))
 &
  (((p=TRUE) => (r=TRUE)) => (((q=TRUE) => (r=TRUE)) => (((p=TRUE) or (q=TRUE)) => (r=TRUE))))
 &
  (not((p=TRUE)) => (((p=TRUE) or (q=TRUE)) <=> (q=TRUE)))
 &
  (((p=TRUE) & (q=TRUE)) <=> not(not((p=TRUE)) or not((q=TRUE))))
 &
  (((p=TRUE) & (q=TRUE)) <=> not((p=TRUE) => not((q=TRUE))))
 &
  (((p=TRUE) & (q=TRUE)) <=> ((q=TRUE) & (p=TRUE)))
 &
  ((((p=TRUE) & (q=TRUE)) & (r=TRUE)) <=> ((p=TRUE) & ((q=TRUE) & (r=TRUE))))
 &
  (((p=TRUE) & (p=TRUE)) => (p=TRUE))
 &
  (((p=TRUE) & (q=TRUE)) => (p=TRUE))
 &
  (((p=TRUE) & (q=TRUE)) => (q=TRUE))
 &
  ((p=TRUE) => ((q=TRUE) => ((p=TRUE) & (q=TRUE))))
 &
  (((p=TRUE) => (q=TRUE)) => (((p=TRUE) => (r=TRUE)) => ((p=TRUE) => ((q=TRUE) & (r=TRUE)))))
 &
  ((p=TRUE) => (((p=TRUE) & (q=TRUE)) <=> (q=TRUE)))
 &
  (((p=TRUE) & ((q=TRUE) or (p=TRUE))) <=> (p=TRUE))
 &
  (((p=TRUE) or ((q=TRUE) & (p=TRUE))) <=> (p=TRUE))
 &
  (((p=TRUE) & ((q=TRUE) or (r=TRUE))) <=> (((p=TRUE) & (q=TRUE)) or ((p=TRUE) & (r=TRUE))))
 &
  (((p=TRUE) or ((q=TRUE) & (r=TRUE))) <=> (((p=TRUE) or (q=TRUE)) & ((p=TRUE) or (r=TRUE))))
 &
  ((((p=TRUE) or (q=TRUE)) & not((p=TRUE))) => (q=TRUE))
 &
  ((p=TRUE) <=> (((p=TRUE) & (q=TRUE)) or ((p=TRUE) & not((q=TRUE)))))
 &
  ((p=TRUE) <=> (((p=TRUE) or (q=TRUE)) & ((p=TRUE) or not((q=TRUE)))))
 &
  (((p=TRUE) => (q=TRUE)) <=> (not((p=TRUE)) or (q=TRUE)))
 &
  (((p=TRUE) => (q=TRUE)) <=> not((p=TRUE) & not((q=TRUE))))
 &
  ((p=TRUE) => (p=TRUE))
 &
  ((p=TRUE) => ((q=TRUE) => (p=TRUE)))
 &
  ((((p=TRUE) => (q=TRUE)) => (p=TRUE)) => (p=TRUE))
 &
  (((p=TRUE) => ((q=TRUE) => (r=TRUE))) => (((p=TRUE) => (q=TRUE)) => ((p=TRUE) => (r=TRUE))))
 &
  (((p=TRUE) => (q=TRUE)) => (((q=TRUE) => (r=TRUE)) => ((p=TRUE) => (r=TRUE))))
 &
  (not((p=TRUE)) => ((p=TRUE) => (q=TRUE)))
 &
  ((not((q=TRUE)) => not((p=TRUE))) => ((p=TRUE) => (q=TRUE)))
 &
  (((p=TRUE) => ((q=TRUE) => (r=TRUE)) <=> (((p=TRUE) & (q=TRUE)) => (r=TRUE))))
 &
  (((p=TRUE) <=> (q=TRUE)) <=> (((p=TRUE) & (q=TRUE)) or (not((p=TRUE)) & not((q=TRUE)))))
 &
  (((p=TRUE) <=> (q=TRUE)) <=> (not((p=TRUE) & not((q=TRUE))) & not(not((p=TRUE)) & (q=TRUE))))
 &
  (((p=TRUE) <=> (q=TRUE)) <=> (((p=TRUE) => (q=TRUE)) & ((q=TRUE) => (p=TRUE))))
 &
  ((p=TRUE) <=> (p=TRUE))
 &
  (((p=TRUE) <=> (q=TRUE)) => ((p=TRUE) => (q=TRUE)))
 &
  (((p=TRUE) <=> (q=TRUE)) <=> ((q=TRUE) <=> (p=TRUE)))
 &
  (((p=TRUE) <=> (q=TRUE)) => (((q=TRUE) <=> (r=TRUE)) => ((p=TRUE) <=> (r=TRUE))))
 &
  (((p=TRUE) <=> (q=TRUE)) <=> (not((p=TRUE)) <=> not((q=TRUE))))
 &
  (((p=TRUE) <=> (q=TRUE)) <=> not((p=TRUE) <=> not((q=TRUE))))
INITIALISATION p := TRUE || q := TRUE || r := TRUE
OPERATIONS
  op(x,y,z) = PRE x : BOOL & y : BOOL & z : BOOL THEN p := x || q := y || r := z END
END
