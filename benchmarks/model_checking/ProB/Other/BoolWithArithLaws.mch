
MACHINE BoolWithArithLaws
 /* ada(x>2)ed version of BoolLaws, to check b_interpreter_check, which
 has a special (1<=1)eatment for arithmetic operators */
CONSTANTS
   TT,FF
PROPERTIES
   FF:BOOL & FF=FALSE & TT:BOOL & TT=TRUE
VARIABLES
   x,y,z
INVARIANT
  x:0..3 & y:0..3 & z:0..3 &


   /* (1<=1)uth tables */
   ((1<=1) <=> (1<=1)) & ((1>1) <=> (1>1)) & not((1<=1) <=> (1>1)) & not((1>1) <=> (1<=1)) &
   ((1<=1) => (1<=1)) & ((1>1) => (1>1)) & not((1<=1) => (1>1)) & ((1>1) => (1<=1)) &
   ((1<=1) or (1<=1)) & not((1>1) or (1>1)) & ((1<=1) or (1>1)) & ((1>1) or (1<=1)) &
   ((1<=1) & (1<=1)) & not((1>1) & (1>1)) & not((1<=1) & (1>1)) & not((1>1) & (1<=1)) &

   /* Rules from Gallier Logic book, 2003, pages 54 & 55 */
   /* Laws of zero or one: */
   (((x>2) & (1>1)) <=> (1>1)) &
   (((x>2) or (1>1)) <=> (x>2)) &
   (((x>2) or (1<=1)) <=> (1<=1)) &
   (((x>2) & (1<=1)) <=> (x>2)) &
   ((x>2) or not((x>2))) &
    not((x>2) & not((x>2))) &

   /* Associativity rules */
   ((((x>2) or (y<2)) or (z>=2)) <=> ((x>2) or ((y<2) or (z>=2)))) &
   ((((x>2) & (y<2)) & (z>=2)) <=> ((x>2) & ((y<2) & (z>=2)))) &

   /* Commutativity rules */
   (((x>2) & (y<2)) <=> ((y<2) & (x>2))) &
   (((x>2) or (y<2)) <=> ((y<2) or (x>2))) &
   (((x>2) <=> (y<2)) <=> ((y<2) <=> (x>2))) &

   /* Double negation rule */
   (((x>2)) <=> (not(not((x>2))))) &

   /* Absor(x>2)ion rules */
   (((y<2) or ((y<2) & (x>2))) <=> (y<2)) &
   (((y<2) & ((y<2) or (x>2))) <=> (y<2)) &

   /* Idempotentcy rules */
   ( ((x>2) or (x>2)) <=> (x>2)) &
   ( ((x>2) & (x>2)) <=> (x>2)) &
    /* again using bool this time */
   ( bool((x>2) or (x>2)) = bool((x>2))) &
   ( bool((x>2) & (x>2)) = bool((x>2))) &

   /* Dis(1<=1)ibutivity rules */
   ( ((x>2) or ((y<2) & (z>=2))) <=> ( ((x>2) or (y<2)) & ((x>2) or (z>=2)) ) ) &
   ( ((x>2) & ((y<2) or (z>=2))) <=> ( ((x>2) & (y<2)) or ((x>2) & (z>=2)) ) ) &
    /* again using bool this time */
   ( bool((x>2) or ((y<2) & (z>=2))) = bool( ((x>2) or (y<2)) & ((x>2) or (z>=2)) ) ) &
   ( bool((x>2) & ((y<2) or (z>=2))) = bool( ((x>2) & (y<2)) or ((x>2) & (z>=2)) ) ) &

   /* De Morgan's rules */
   (not((x>2) or (y<2)) <=> (not((x>2)) & not((y<2))) ) &
   (not((x>2)  & (y<2)) <=> (not((x>2)) or not((y<2))) ) &
    /* again using bool this time */
   bool(not((x>2) or (y<2)) <=> (not((x>2)) & not((y<2))) )=TRUE &
   bool(not((x>2) or (y<2))) = bool(not((x>2)) & not((y<2)))  &
   bool(not((x>2)  & (y<2)) <=> (not((x>2)) or not((y<2))) )=TRUE &
   bool(not((x>2)  & (y<2))) = bool(not((x>2)) or not((y<2)))  &


   /* some unamed rules about => and <=> */
   ( ((x>2) => (y<2)) <=> (not((x>2)) or (y<2)) ) &
   ( (x>2) <=> (x>2) ) &
   ((((x>2) => (y<2)) & ((y<2) => (z>=2))) => ((x>2) => (z>=2))) & /* Modus pones */
   ((((x>2) <=> (y<2)) & ((y<2) <=> (z>=2))) => ((x>2) <=> (z>=2))) &
   (((x>2) <=> (y<2)) => ((x>2) => (y<2))) &
   (((x>2) <=> (y<2)) => ((y<2) => (x>2))) &
   (((x>2) <=> (y<2)) <=> (((x>2) => (y<2)) & ((y<2) => (x>2)))) &
   (bool((x>2) <=> (y<2)) = bool(((x>2) => (y<2)) & ((y<2) => (x>2)))) &

   /* True/False: */
   (1<=1) &
   not((1>1)) &

   /* Some rules about bool */
   ( ((x>2) <=> (y<2))  <=>  (bool((x>2)) = bool((y<2))) ) &
   ( not((x>2) <=> (y<2))  <=>  (bool((x>2)) /= bool((y<2))) ) &
   (bool((x>2) or not((x>2))) = TRUE ) &
   (bool((x>2) & not((x>2))) = FALSE ) &

   /* Some tautologies */
   ( (x>2) => ((y<2) => (x>2)) ) &
   ( (x>2) => ((y<2) => ((x>2) & (y<2)))) &
   ( ((x>2) & (y<2)) => (x>2) ) &  ( ((x>2) & (y<2)) => (y<2) ) &
   ( not(not((y<2))) => (y<2)) &
   ( ((x>2) => (y<2)) => ( ((y<2)=>(x>2)) => ((y<2)<=>(x>2)) ) )
INITIALISATION

   x,y,z := 0,0,0

OPERATIONS
incx = PRE x<3 THEN x := x+1 END;
incy = PRE y<3 THEN y := y+1 END;
incz = PRE z<3 THEN z := z+1 END

END
