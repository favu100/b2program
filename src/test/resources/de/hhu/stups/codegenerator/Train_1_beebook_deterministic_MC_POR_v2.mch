/*
Original model:
J.-R. Abrial. Modeling in Event-B: System and Software Engineering. Cambridge University Press, 2010.

Model applies Partial Order Reduction manually.
Rewritten version for B2Program
*/
MACHINE Train_1_beebook_deterministic_MC_POR_v2
SETS /* enumerated */
  BLOCKS={A,B,C,D,E,F,G,H,I,J,K,L,M,N};
  ROUTES={R1,R2,R3,R4,R5,R6,R7,R8,R9,R10}
CONCRETE_CONSTANTS
  fst,
  lst,
  nxt,
  rtbl
ABSTRACT_VARIABLES
  LBT,
  TRK,
  frm,
  OCC,
  resbl,
  resrt,
  rsrtbl
/* PROMOTED OPERATIONS
  route_reservation,
  route_freeing,
  FRONT_MOVE_1,
  FRONT_MOVE_2,
  BACK_MOVE_1,
  BACK_MOVE_2,
  point_positionning,
  route_formation */
PROPERTIES
    /* @axm2 */ dom(rtbl) = BLOCKS
  & /* @axm3 */ ran(rtbl) = ROUTES
  & /* @axm4 */ dom(nxt) = ROUTES & ran(nxt) <: (BLOCKS >+> BLOCKS)
  & /* @axm5 */ fst : ROUTES --> BLOCKS
  & /* @axm6 */ lst : ROUTES --> BLOCKS
  & /* @axm7 */ fst~ <: rtbl
  & /* @axm8 */ lst~ <: rtbl
  & /* @axm11 */ !(r).(r : ROUTES => fst(r) /= lst(r))
  & /* @axm10 */ !(r).(r : ROUTES => !(S).(S <: ran(nxt(r)) & S <: nxt(r)[S] => S = {}))
  & /* @axm9 */ !(r).(r : ROUTES => nxt(r) : (rtbl~)[{r}] \ {lst(r)} >->> (rtbl~)[{r}] \ {fst(r)})
  & /* @axm12 */ !(r,s).((r : ROUTES & s : ROUTES) & r /= s => fst(r) /: (rtbl~)[{s}] \ {fst(s),lst(s)})
  & /* @axm13 */ !(r,s).((r : ROUTES & s : ROUTES) & r /= s => lst(r) /: (rtbl~)[{s}] \ {fst(s),lst(s)})
  & /* @compute_rtbl_from_nxt */ rtbl = {b,r|b : BLOCKS & r : ROUTES & (r : dom(nxt) & (b : dom(nxt(r)) or b : ran(nxt(r))))}
  & /* @axm40 */ nxt = {R1 |-> {L |-> A,A |-> B,B |-> C},R2 |-> {L |-> A,A |-> B,B |-> D,D |-> E,E |-> F,F |-> G},R3 |-> {L |-> A,A |-> B,B |-> D,D |-> K,K |-> J,J |-> N},R4 |-> {M |-> H,H |-> I,I |-> K,K |-> F,F |-> G},R5 |-> {M |-> H,H |-> I,I |-> J,J |-> N},R6 |-> {C |-> B,B |-> A,A |-> L},R7 |-> {G |-> F,F |-> E,E |-> D,D |-> B,B |-> A,A |-> L},R8 |-> {N |-> J,J |-> K,K |-> D,D |-> B,B |-> A,A |-> L},R9 |-> {G |-> F,F |-> K,K |-> I,I |-> H,H |-> M},R10 |-> {N |-> J,J |-> I,I |-> H,H |-> M}}
  & /* @axm41 */ fst = {R1 |-> L,R2 |-> L,R3 |-> L,R4 |-> M,R5 |-> M,R6 |-> C,R7 |-> G,R8 |-> N,R9 |-> G,R10 |-> N}
  & /* @axm42 */ lst = {R1 |-> C,R2 |-> G,R3 |-> N,R4 |-> G,R5 |-> N,R6 |-> L,R7 |-> L,R8 |-> L,R9 |-> M,R10 |-> M}
INVARIANT
  /* @inv1 */ TRK : BLOCKS >+> BLOCKS

  & /* @inv4 */ !(r,a).(r : resrt \ frm & a = {r} => rtbl |> a = rsrtbl |> a)
  & /* @inv5 */ !(x,y).(x : dom(TRK) & y : TRK[{x}] => #(r).(r : ROUTES & x |-> y : nxt(r)))
  & /* @inv6 */ !(r,a).(r : frm & a = (rsrtbl~)[{r}] => a <| nxt(r) = a <| TRK)
  & /* @inv7 */ LBT <: OCC
  & /* @inv8 */ !(a,b,c,d).(a : dom(rsrtbl) & b : LBT & c = rsrtbl(b) & d = nxt(c) &
                            (b : ran(d) & (a = (d~)(b))) => rsrtbl(a) /= c)
  & /* @inv9 */ rsrtbl : resbl --> resrt
  & /* @inv10 */ rsrtbl <: rtbl
  & /* @inv11 */ OCC <: resbl
  & /* @inv12 */ !(r,a,b,c).(r : ROUTES & a = nxt(r) & b = (rsrtbl~)[{r}] & c = b \ OCC =>
                                    a[(rtbl~)[{r}] \ b] /\ c = {} &
                                    a[b] <: b &
                                    a[c] <: c)
  & /* @inv2 */ frm <: resrt
  & /* @inv3 */ rsrtbl[OCC] <: frm
ASSERTIONS
  /* @thm1 */ !(b).(b : OCC & b : dom(TRK) => nxt(rsrtbl(b))(b) = TRK(b));
  /* @thm2 */ ran(lst) /\ dom(TRK) \ ran(fst) = {};
  /* @thm3 */ ran(fst) /\ ran(TRK) \ ran(lst) = {}
INITIALISATION
         resrt := {}
      ||
         resbl := {}
      ||
         rsrtbl := {}
      ||
         OCC := {}
      ||
         TRK := {}
      ||
         frm := {}
      ||
         LBT := {}

OPERATIONS
  route_reservation(r) =

    PRE
      /* @grd1 */ r : ROUTES \ resrt
      & /* @grd2 */ (rtbl~)[{r}] /\ resbl = {}
      & ({} = resrt \ ran(rsrtbl)) /* POR REDUCTION */
    THEN
         resrt := resrt \/ {r}
      ||
         rsrtbl := rsrtbl \/ (rtbl |> {r})
      ||
         resbl := resbl \/ (rtbl~)[{r}]
    END;

  route_freeing(r) =
    PRE
        /* @grd1 */ r : resrt \ ran(rsrtbl)
    THEN
         resrt := resrt \ {r}
      ||
         frm := frm \ {r}
    END;

  FRONT_MOVE_1(r) =
    PRE
        /* @grd1 */ r : frm
      & /* @grd3 */ fst(r) : resbl \ OCC
      & /* @grd2 */ r = rsrtbl(fst(r))
      & ({} = resrt \ ran(rsrtbl)) /* POR REDUCTION */
    THEN
         OCC := OCC \/ {fst(r)}
      ||
         LBT := LBT \/ {fst(r)}
    END;

  FRONT_MOVE_2(b) =
    PRE
        /* @grd1 */ b : OCC /\ dom(TRK)
      & /* @grd2 */ TRK(b) /: OCC
    THEN
         OCC := OCC \/ {TRK(b)}
    END;

  BACK_MOVE_1(b) =
    PRE
      /* @grd1 */ b : LBT \ dom(TRK)
      & ({} = resrt \ ran(rsrtbl)) /* POR REDUCTION */
    THEN
         OCC := OCC \ {b}
      ||
         rsrtbl := {b} <<| rsrtbl
      ||
         resbl := resbl \ {b}
      ||
         LBT := LBT \ {b}
    END;

  BACK_MOVE_2(b) =
    PRE
        /* @grd1 */ b : LBT /\ dom(TRK)
      & /* @grd2 */ TRK(b) : OCC
      & ({} = resrt \ ran(rsrtbl)) /* POR REDUCTION */
    THEN
         OCC := OCC \ {b}
      ||
         rsrtbl := {b} <<| rsrtbl
      ||
         resbl := resbl \ {b}
      ||
         LBT := LBT \ {b} \/ {TRK(b)}

    END;

  point_positionning(r) =
    PRE
        /* @grd1 */ r : resrt \ frm
        & ({} = resrt \ ran(rsrtbl)) /* POR REDUCTION */
    THEN
         TRK := ((dom(nxt(r)) <<| TRK) |>> ran(nxt(r))) \/ nxt(r)
    END;

  route_formation(r) =
    PRE
        /* @grd1 */ r : resrt \ frm
      & /* @grd2 */ (rsrtbl~)[{r}] <| nxt(r) = (rsrtbl~)[{r}] <| TRK
      & ({} = resrt \ ran(rsrtbl)) /* POR REDUCTION */
    THEN
         frm := frm \/ {r}
    END

END

