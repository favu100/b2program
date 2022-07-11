MACHINE BoolLaws_SetCompr
/* Boolean Laws expressed using set comprehensions */
CONSTANTS
   TT,FF
PROPERTIES
   FF:BOOL & FF=FALSE & TT:BOOL & TT=TRUE

INVARIANT

   /* Associativity rules */
   {p,q,r|p : BOOL & q : BOOL & r : BOOL & (((p=TRUE) or (q=TRUE)) or (r=TRUE))}  =  {p,q,r|p : BOOL & q : BOOL & r : BOOL & ((p=TRUE) or ((q=TRUE) or (r=TRUE)))} &
   {p,q,r|p : BOOL & q : BOOL & r : BOOL & (((p=TRUE) & (q=TRUE)) & (r=TRUE))} =  {p,q,r|p : BOOL & q : BOOL & r : BOOL & ((p=TRUE) & ((q=TRUE) & (r=TRUE)))} &


   /* Commutativity rules */
   {p,q|p : BOOL & q : BOOL & ((p=TRUE) & (q=TRUE))}   = {p,q|p : BOOL & q : BOOL & ((q=TRUE) & (p=TRUE))} &
   {p,q|p : BOOL & q : BOOL & ((p=TRUE) or (q=TRUE))}  = {p,q|p : BOOL & q : BOOL & ((q=TRUE) or (p=TRUE))} &
   {p,q|p : BOOL & q : BOOL & ((p=TRUE) <=> (q=TRUE))} = {p,q|p : BOOL & q : BOOL & ((q=TRUE) <=> (p=TRUE))} &


   /* Distributivity rules */
   {p,q,r| p : BOOL & q : BOOL & r : BOOL & ((p=TRUE) or ((q=TRUE) & (r=TRUE)))} = {p,q,r| p : BOOL & q : BOOL & r : BOOL & (((p=TRUE) or (q=TRUE)) & ((p=TRUE) or (r=TRUE))) } &
   {p,q,r| p : BOOL & q : BOOL & r : BOOL & ((p=TRUE) & ((q=TRUE) or (r=TRUE)))} = {p,q,r| p : BOOL & q : BOOL & r : BOOL & (((p=TRUE) & (q=TRUE)) or ((p=TRUE) & (r=TRUE))) } &

   /* De Morgan's rules */
   {p,q|p : BOOL & q : BOOL & (not((p=TRUE) or (q=TRUE)))}   =  {p,q|p : BOOL & q : BOOL & (not((p=TRUE)) & not((q=TRUE)))} &
   {p,q|p : BOOL & q : BOOL & (not((p=TRUE)  & (q=TRUE)))}   =  {p,q|p : BOOL & q : BOOL & (not((p=TRUE)) or not((q=TRUE)))} &

 /* some unamed rules about => and <=> */
  {p,q|   p : BOOL & q : BOOL & ( ((p=TRUE) => (q=TRUE)) <=> (not((p=TRUE)) or (q=TRUE)) ) } = BOOL*BOOL &
  {p|     p : BOOL & ( (p=TRUE) <=> (p=TRUE) )} = BOOL &
  {p,q,r| p : BOOL & q : BOOL & r : BOOL & ((((p=TRUE) => (q=TRUE)) & ((q=TRUE) => (r=TRUE))) => ((p=TRUE) => (r=TRUE))) } = BOOL*BOOL*BOOL & /* Modus pones */
  {p,q,r| p : BOOL & q : BOOL & r : BOOL & ((((p=TRUE) <=> (q=TRUE)) & ((q=TRUE) <=> (r=TRUE))) => ((p=TRUE) <=> (r=TRUE))) } = BOOL*BOOL*BOOL &
  {p,q|   p : BOOL & q : BOOL & (((p=TRUE) <=> (q=TRUE)) => ((p=TRUE) => (q=TRUE))) } = BOOL*BOOL &
  {p,q|   p : BOOL & q : BOOL & (((p=TRUE) <=> (q=TRUE)) => ((q=TRUE) => (p=TRUE))) } = BOOL*BOOL &
  {p,q|   p : BOOL & q : BOOL & (((p=TRUE) <=> (q=TRUE)) <=> (((p=TRUE) => (q=TRUE)) & ((q=TRUE) => (p=TRUE)))) } = BOOL*BOOL &

  {p,q|   p : BOOL & q : BOOL & ( (p=TRUE) => (q=TRUE) or (p=TRUE) )} = BOOL*BOOL &
  {p,q|   p : BOOL & q : BOOL & ( ((p=TRUE)=>(q=TRUE)) or (p=TRUE) ) & ( (p=TRUE) => ((q=TRUE) or (p=TRUE)) ) } = BOOL*BOOL &


   /* Some tautologies */
   {p,q| p : BOOL & q : BOOL & ((p=TRUE) => ((q=TRUE) => (p=TRUE))) } = BOOL*BOOL &
   {p,q| p : BOOL & q : BOOL & ((p=TRUE) => ((q=TRUE) => ((p=TRUE) & (q=TRUE))))} = BOOL*BOOL &
   {p,q| p : BOOL & q : BOOL & ((((p=TRUE) & (q=TRUE)) => (p=TRUE) ) &  ( ((p=TRUE) & (q=TRUE)) => (q=TRUE) ) )} = BOOL*BOOL &
   {q| q : BOOL & (not(not((q=TRUE))) => (q=TRUE))} = BOOL &
   {p,q| p : BOOL & q : BOOL & (((p=TRUE) => (q=TRUE)) => ( ((q=TRUE)=>(p=TRUE)) => ((q=TRUE)<=>(p=TRUE)) ) )} = BOOL*BOOL &

 TT/=FF
END
