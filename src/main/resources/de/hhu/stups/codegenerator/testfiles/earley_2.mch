
MACHINE earley_2
SETS /* enumerated */
  P={axiom,Pr2,Pr3,Pr4,Pr5,Pr6};
  S={Init,Expr,Term,Factor,plus,mult,number}
CONCRETE_CONSTANTS
  N,
  input,
  left,
  right,
  s,
  size
ABSTRACT_VARIABLES
  lists,
  size_l,
  sets,
  item,
  return
/* PROMOTED OPERATIONS
  selector,
  predictor,
  completer,
  final */
PROPERTIES
    /* @axm3  */ s : NAT
  & /* @axm4  */ input : 1 .. s --> S \ N
  & /* @axm5  */ left : P --> N
  & /* @axm6  */ size : P --> NAT1
  & /* @axm7  */ right : P --> (NAT +-> S)
  & /* @axm8  */ !p.(p : P => right(p) : 1 .. size(p) --> S)
  & /* @axm51  */ N = {Init,Expr,Term,Factor}
  & /* @axm52  */ s = 5
  & /* @axm53  */ input = {1 |-> number,2 |-> plus,3 |-> number,4 |-> mult,5 |-> number}
  & /* @axm55  */ left = {axiom |-> Init,Pr2 |-> Expr,Pr3 |-> Expr,Pr4 |-> Term,Pr5 |-> Term,Pr6 |-> Factor}
  & /* @axm54  */ size = {axiom |-> 1,Pr2 |-> 1,Pr3 |-> 3,Pr4 |-> 1,Pr5 |-> 3,Pr6 |-> 1}
  & /* @axm56  */ right = {axiom |-> {1 |-> Expr},Pr2 |-> {1 |-> Term},Pr3 |-> {1 |-> Expr,2 |-> plus,3 |-> Term},Pr4 |-> {1 |-> Factor},Pr5 |-> {1 |-> Term,2 |-> mult,3 |-> Factor},Pr6 |-> {1 |-> number}}
INVARIANT
    /* @inv1  */ lists : 0 .. s --> (NAT +-> P ** NAT ** NAT)
  & /* @inv2  */ size_l : 0 .. s --> NAT
  & /* @inv3  */ !j.(j : 0 .. s => lists(j) : 1 .. size_l(j) >-> P ** NAT ** NAT)
  & /* @inv4  */ !j.(j : 0 .. s => sets(j) = ran(lists(j)))
  & /* @inv2  */ sets : 0 .. s --> POW(P ** NAT ** NAT)
  & /* @inv1  */ !p,k,i,j.(j : dom(sets) & p |-> k |-> i : sets(j) => p |-> k |-> (i |-> j) : item)
  & /* @inv1  */ item : P ** NAT <-> NAT ** NAT
INITIALISATION
    EVENT INITIALISATION = /* of machine earley_2 */
    THEN
         return := FALSE
      ||
         lists := (1 .. s) ** {{}} <+ {0 |-> {1 |-> (axiom |-> 0 |-> 0)}}
      ||
         size_l := (1 .. s) ** {0} <+ {0 |-> 1}
    REFINES
      EVENT INITIALISATION = /* of machine earley_1 */
      THEN
           sets := (1 .. s) ** {{}} <+ {0 |-> {axiom |-> 0 |-> 0}}
      REFINES
        EVENT INITIALISATION = /* of machine earley_0 */
        THEN
             item := {axiom |-> 0 |-> (0 |-> 0)}
        REFINES
          EVENT INITIALISATION = /* of machine early_00 */
          THEN
            skip
          END
        END
      END
    END
OPERATIONS
  selector(i,j,k,p) =
    EVENT selector = /* of machine earley_2 */
    ANY i,j,k,p
    WHERE
        /* @grd5  */ j : dom(lists)
      & /* @grd1  */ p |-> k |-> i : ran(lists(j))
      & /* @grd2  */ k < size(p)
      & /* @grd3  */ j < s
      & /* @grd4  */ right(p)(k + 1) = input(j + 1)
      & /* @grd6  */ (p |-> k + 1 |-> i) /: ran(lists(j + 1))
    THEN
         lists := lists <+ {j + 1 |-> (lists(j + 1) \/ {size_l(j + 1) + 1 |-> (p |-> k + 1 |-> i)})}
      ||
         size_l := size_l <+ {j + 1 |-> size_l(j + 1) + 1}
    REFINES
      EVENT selector = /* of machine earley_1 */
      WHEN
          /* @grd5  */ j : dom(sets)
        & /* @grd1  */ p |-> k |-> i : sets(j)
      THEN
           sets := sets <+ {j + 1 |-> (sets(j + 1) \/ {p |-> k + 1 |-> i})}
      REFINES
        EVENT selector = /* of machine earley_0 */
        WHEN
            /* @grd1  */ p |-> k |-> (i |-> j) : item
        THEN
             item := item \/ {p |-> k + 1 |-> (i |-> j + 1)}
        END
      END
    END;

  predictor(i,j,k,p,q) =
    EVENT predictor = /* of machine earley_2 */
    ANY i,j,k,p,q
    WHERE
        /* @grd4  */ j : dom(lists)
      & /* @grd1  */ p |-> k |-> i : ran(lists(j))
      & /* @grd2  */ k < size(p)
      & /* @grd3  */ left(q) = right(p)(k + 1)
      & /* @grd5  */ (q |-> 0 |-> j) /: ran(lists(j))
    THEN
         lists := lists <+ {j |-> (lists(j) \/ {size_l(j) + 1 |-> (q |-> 0 |-> j)})}
      ||
         size_l := size_l <+ {j |-> size_l(j) + 1}
    REFINES
      EVENT predictor = /* of machine earley_1 */
      WHEN
          /* @grd4  */ j : dom(sets)
        & /* @grd1  */ p |-> k |-> i : sets(j)
      THEN
           sets := sets <+ {j |-> (sets(j) \/ {q |-> 0 |-> j})}
      REFINES
        EVENT predictor = /* of machine earley_0 */
        WHEN
            /* @grd1  */ p |-> k |-> (i |-> j) : item
        THEN
             item := item \/ {q |-> 0 |-> (j |-> j)}
        END
      END
    END;

  completer(i,ip,j,k,kp,p,q) =
    EVENT completer = /* of machine earley_2 */
    ANY i,ip,j,k,kp,p,q
    WHERE
        /* @grd6  */ j : dom(lists)
      & /* @grd1  */ p |-> k |-> i : ran(lists(j))
      & /* @grd2  */ k = size(p)
      & /* @grd3  */ q |-> kp |-> ip : ran(lists(i))
      & /* @grd4  */ kp < size(q)
      & /* @grd5  */ right(q)(kp + 1) = left(p)
      & /* @grd7  */ (q |-> kp + 1 |-> ip) /: ran(lists(j))
    THEN
         lists := lists <+ {j |-> (lists(j) \/ {size_l(j) + 1 |-> (q |-> kp + 1 |-> ip)})}
      ||
         size_l := size_l <+ {j |-> size_l(j) + 1}
    REFINES
      EVENT completer = /* of machine earley_1 */
      WHEN
          /* @grd6  */ j : dom(sets)
        & /* @grd1  */ p |-> k |-> i : sets(j)
        & /* @grd3  */ q |-> kp |-> ip : sets(i)
      THEN
           sets := sets <+ {j |-> (sets(j) \/ {q |-> kp + 1 |-> ip})}
      REFINES
        EVENT completer = /* of machine earley_0 */
        WHEN
            /* @grd1  */ p |-> k |-> (i |-> j) : item
          & /* @grd3  */ q |-> kp |-> (ip |-> i) : item
        THEN
             item := item \/ {q |-> kp + 1 |-> (ip |-> j)}
        END
      END
    END;

  final =
    EVENT final = /* of machine earley_2 */
    WHEN
        /* @grd1  */ axiom |-> size(axiom) |-> 0 : ran(lists(s))
    THEN
         return := TRUE
    REFINES
      EVENT final = /* of machine earley_1 */
      WHEN
          /* @grd1  */ axiom |-> size(axiom) |-> 0 : sets(s)
      THEN
        skip
      REFINES
        EVENT final = /* of machine earley_0 */
        WHEN
            /* @grd1  */ axiom |-> size(axiom) |-> (0 |-> s) : item
        THEN
          skip
        REFINES
          EVENT final = /* of machine early_00 */
          THEN
            skip
          END
        END
      END
    END
END
