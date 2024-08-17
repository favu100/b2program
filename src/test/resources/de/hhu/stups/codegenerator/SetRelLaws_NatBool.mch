MACHINE SetRelLaws_NatBool

/* SETS
   X = {x1,x2,x3}; Y = {y1,y2} */

VARIABLES
    SS, TT, VV


INVARIANT
   SS : POW(((11..13)*BOOL)) & TT : POW(((11..13)*BOOL)) & VV : POW(((11..13)*BOOL)) &
  (SS \/ SS = SS  &  SS = SS \/ {}  &  SS = SS /\ SS  &  SS = SS \ {}) &
  (SS /\ {} = {} & {} = SS \ SS &  ({} \ SS = {})) &
  (SS \/ TT = TT \/ SS   &  SS /\ TT = TT /\ SS) &
  (( SS \/ (TT \/ VV) = (SS \/TT) \/ VV) & ( SS /\ (TT /\ VV) = (SS /\ TT) /\ VV)) &
  ( SS \/ (TT /\ VV) = (SS \/ TT) /\ (SS \/ VV)) &
  ( SS /\ (TT \/ VV) = (SS /\ TT) \/ (SS /\ VV)) &
  ( (SS /\ TT) \/ (SS \ TT) = SS) &
  ((SS \ TT) /\ TT = {}) &
  (SS \ (TT \ VV) = (SS \ TT) \/ (SS /\ VV)) &
  ((SS \ TT) \ VV = (SS \ (TT \/ VV))) &
  (SS \/ (TT \ VV) = (SS \/ TT) \ (VV \ SS)) &
  (SS /\ (TT \ VV) = (SS /\ TT) \ VV) &
  ((SS \/ TT) \ VV = (SS \ VV) \/ (TT \ VV)) &
  (SS \ (TT /\ VV) = ( SS \ TT) \/ (SS \ VV)) &

  (SS <: SS \/ TT & TT <: SS \/ TT) &
  ( ( SS <: VV & TT <: VV) => (SS\/TT <: VV)) &
  (SS /\ TT <: SS & SS /\ TT <: TT) &
  ( (VV <: SS & VV <: TT) => (VV <: SS /\ TT)) &

  ( {xx | xx: SS & xx:TT} = SS /\ TT) &
  ( {xx | xx: ((11..13)*BOOL) & (xx: SS or xx:TT)} = SS \/ TT) &
  ( {xx | xx: ((11..13)*BOOL) & xx: SS & (xx: TT or xx:VV)} = SS /\ (VV \/TT)) &
  ( {xx | xx: SS & not(xx:TT)} = SS \ TT) &
  ( {xx | xx: ((11..13)*BOOL) & (xx: SS or xx:TT or xx:VV)} = SS \/ TT \/ VV) &
  ( {xx | xx: ((11..13)*BOOL) & (xx: SS or ((xx/:TT => xx:VV) & (xx:TT => xx:SS)))} = SS \/ (VV \ TT)) &

  (!xx.(xx:SS & xx:TT => xx: SS /\ TT)) &
  (!xx.(xx:SS & not(xx:TT) => (xx: SS \ TT & xx /: TT))) &

  (#xx.(xx:SS & xx:TT & xx:VV) => not(SS /\ TT /\ VV = {})) &
  (#xx.(xx:SS & xx/:TT) => not(SS \/ TT = TT) & not(SS \ TT = {})) &


  /* laws for <<: and /<<: */
  ( SS <<: VV  or SS /<<: VV ) &
  ( (VV <<: SS & SS <: TT) => (VV <<: TT)) &
  ( (VV <: SS & SS <<: TT) => (VV <<: TT)) &
  ( (SS <: VV & SS /<<: VV) => SS = VV) &
  ( (SS <<: VV ) => SS /= VV) &
  ( (SS = VV ) => SS /<<: VV) &
  ( SS <<: VV  => SS <: VV) &
  ( SS <<: VV => #xx.(xx:VV & xx/:SS)) &

  (SS <<: VV => (card(SS) < card(VV))) &
  (SS <: VV => (card(SS) <= card(VV))) &
  (card(SS) < card(VV) => (VV /<: SS)) &
  (card(SS \/ VV) <= (card(SS) + card(VV))) &

  (SS /\ VV = {}  <=> SS <: ((11..13)*BOOL) - VV) &
  (SS \ VV = SS-VV) &
    (SS<<:VV or not(SS<<:VV)) & not(SS<<:VV & not(SS<<:VV)) &
    (SS<:VV or not(SS<:VV)) & not(SS<:VV & not(SS<:VV)) &

    (UNION(ss).(ss<:SS | ss) = SS) &
    (INTER(ss).(ss<:SS | ss) = {}) &

    (SS : POW(TT) <=> SS <: TT) &
    (SS=TT <=> POW(SS) = POW(TT)) &
    (POW(SS-TT) = { xx | xx<:SS & xx /\ TT = {} })

    & /* new, July 2008 */
    SS /\ ((11..13)*BOOL) = SS &
    SS \/ ((11..13)*BOOL) = ((11..13)*BOOL) &
    SS \/ (((11..13)*BOOL) \ SS) = ((11..13)*BOOL) &
    SS /\ (((11..13)*BOOL) \ SS) = {} &
    (((11..13)*BOOL) \ (((11..13)*BOOL) \ SS) = SS)

INITIALISATION

    SS,TT,VV := {},{},{}

OPERATIONS
 /* cc <-- powss1 = BEGIN cc := POW(SS-TT) END;
 cc <-- powss2 = BEGIN cc := { xx | xx<:SS & xx /\ TT = {} } END; */
 add_SS(el) = PRE el: ((11..13)*BOOL) & el /: SS THEN  SS := SS \/ {el} END;
 add_TT(el) = PRE el: ((11..13)*BOOL) & el /: TT THEN  TT := TT \/ {el} END;
 add_VV(el) = PRE el: ((11..13)*BOOL) & el /: VV THEN  VV := VV \/ {el} END ;

 set_SS_setX = BEGIN SS := ((11..13)*BOOL) END;
 set_TT_setX = BEGIN TT := ((11..13)*BOOL) END;
 set_VV_setX = BEGIN VV := ((11..13)*BOOL) END/* ;

 laws_ok = PRE law1 & law2 & law3 & law4 & law5 &
               law6 & law7 & law8 & law9 & law10 & law11 THEN skip END */

END

