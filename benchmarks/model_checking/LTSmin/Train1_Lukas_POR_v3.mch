MACHINE Train1_Lukas_POR_v3  /* uses POR style reduction by giving priority to route_freeing */
SETS /* enumerated */
  BLOCKS={A,B,C,D,E,F,G,H,I};
  ROUTES={R1,R2,R3,R4,R5,R6,R7,R8}  /* a simplified topology by Lukas; not the one by Abrial */
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
  & /* @axm4 */ nxt : ROUTES --> (BLOCKS >+> BLOCKS)
  & /* @axm5 */ fst : ROUTES --> BLOCKS
  & /* @axm6 */ lst : ROUTES --> BLOCKS
  & /* @axm7 */ fst~ <: rtbl
  & /* @axm8 */ lst~ <: rtbl
  & /* @axm11 */ !(r).(r : ROUTES => fst(r) /= lst(r))
  & /* @axm10 */ !(r).(r : ROUTES => !(S).((S <: ran(nxt(r)) & S <: nxt(r)[S]) => S = {}))
  & /* @axm9 */ !(r).(r : ROUTES => nxt(r) : (rtbl~)[{r}] \ {lst(r)} >->> (rtbl~)[{r}] \ {fst(r)})
  & /* @axm12 */ !(r,s).((r : ROUTES & s : ROUTES) & r /= s => fst(r) /: (rtbl~)[{s}] \ {fst(s),lst(s)})
  & /* @axm13 */ !(r,s).((r : ROUTES & s : ROUTES) & r /= s => lst(r) /: (rtbl~)[{s}] \ {fst(s),lst(s)})
  & /* @axm14 */ rtbl = {A |-> R1,A |-> R2,A |-> R5,A |-> R6,B |-> R1,B |-> R2,B |-> R5,B |-> R6,C |-> R1,C |-> R5,D |-> R2,D |-> R6,E |-> R2,E |-> R3,E |-> R4,E |-> R6,E |-> R7,E |-> R8,F |-> R2,F |-> R3,F |-> R4,F |-> R6,F |-> R7,F |-> R8,G |-> R3,G |-> R4,G |-> R4,G |-> R7,G |-> R8,H |-> R3,H |-> R7,I |-> R4,I |-> R8}
  & /* @axm40 */ nxt = {R1 |-> {A |-> B,B |-> C},R2 |-> {A |-> B,B |-> D,D |-> E,E |-> F},R3 |-> {H |-> G,G |-> E,E |-> F},R4 |-> {I |-> G,G |-> E,E |-> F},R5 |-> {C |-> B,B |-> A},R6 |-> {F |-> E,E |-> D,D |-> B,B |-> A},R7 |-> {F |-> E,E |-> G,G |-> H},R8 |-> {F |-> E,E |-> G,G |-> I}}
  & /* @axm41 */ fst = {R1 |-> A,R2 |-> A,R3 |-> H,R4 |-> I,R5 |-> C,R6 |-> F,R7 |-> F,R8 |-> F}
  & /* @axm42 */ lst = {R1 |-> C,R2 |-> F,R3 |-> F,R4 |-> F,R5 |-> A,R6 |-> A,R7 |-> H,R8 |-> I}
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
      & /* @grd3 */ TRK(b) /: OCC
      & ({} = resrt \ ran(rsrtbl)) /* POR REDUCTION */
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
      & /* @grd3 */ TRK(b) : OCC
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
