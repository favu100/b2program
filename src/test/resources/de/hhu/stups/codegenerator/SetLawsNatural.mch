/*
From ProB Examples, originally used to test ProB,
rewritten for B2Program
*/
MACHINE SetLawsNatural
VARIABLES
   SS, TT, VV


INVARIANT
  SS : POW(NATURAL) & TT : POW(NATURAL) & VV : POW(NATURAL) &
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
 ( {xx | xx: 0..8 & (xx: SS or xx:TT)} = SS \/ TT) &
 ( {xx | xx: 0..8 & xx: SS & (xx: TT or xx:VV)} = SS /\ (VV \/TT)) &
 ( {xx | xx: SS & not(xx:TT)} = SS \ TT) &

 (!xx.(xx:SS & xx:TT => xx: SS /\ TT)) &
 (!xx.(xx:SS & not(xx:TT) => (xx: SS \ TT & xx /: TT))) &

 (#xx.(xx:SS & xx:TT & xx:VV) => not(SS /\ TT /\ VV = {})) &
 (#xx.(xx:SS & xx/:TT) => not(SS \/ TT = TT) & not(SS \ TT = {})) &


 /* laws for <<:, <:, /<: and /<<: */
 ( SS <<: VV  or SS /<<: VV ) &
 ( (VV <<: SS & SS <: TT) => (VV <<: TT)) &
 ( (VV <: SS & SS <<: TT) => (VV <<: TT)) &
 ( SS <: VV  or SS /<: VV ) &
 ( SS : POW(TT)  or SS /: POW(TT) ) &

 ( (SS <: VV & SS /<<: VV) => SS = VV) &
 (  SS <: VV => (SS /= VV  <=> SS <<: VV)) &
 ( (SS <<: VV ) => SS /= VV) &
 ( (SS = VV ) => SS /<<: VV) &
 ( SS <<: VV  => SS <: VV) &
 ( SS <<: VV => #xx.(xx:VV & xx/:SS)) &
 ( SS <: VV <=> !x.(x:SS => x:VV) ) &

 (SS <<: VV => (card(SS) < card(VV))) &
 (SS <: VV => (card(SS) <= card(VV))) &
 (card(SS) < card(VV) => (VV /<: SS)) &
 (card(SS \/ VV) <= (card(SS) + card(VV))) &
 (card(SS) = card(VV) => (VV /<<: SS)) &
 (card(SS) <= card(VV) => (VV /<<: SS)) &
 (SS = VV => (card(SS) = card(VV))) &
 (card(SS /\ VV) <= card(SS) & card(SS /\ VV) <= card(VV)) &

 //(SS /\ VV = {}  <=> SS <: INTEGER - VV) &
 (SS \ VV = SS-VV) &
 (VV-SS = VV\SS)
   &

   (SS<<:VV or not(SS<<:VV)) & not(SS<<:VV & not(SS<<:VV)) &
   (SS<:VV or not(SS<:VV)) & not(SS<:VV & not(SS<:VV)) &

   (SS/<<:VV or not(SS/<<:VV)) & not(SS/<<:VV & not(SS/<<:VV)) &
   (SS/<:VV or not(SS/<:VV)) & not(SS/<:VV & not(SS/<:VV)) &
   (SS/:POW(TT) or not(SS/:POW(TT))) & not(SS/:POW(TT) & not(SS/:POW(TT))) &
   (SS:POW(TT) or not(SS:POW(TT))) & not(SS:POW(TT) & not(SS:POW(TT))) &
   ((POW1(SS)) = (POW(SS)-{{}})) &
   ((FIN1(SS)) = (FIN(SS)-{{}})) &
   {} : POW(SS) &
   {} : FIN(SS) &  /* this was false due to a bug in the Parser, which returned FIN1 for FIN */
   {} /: POW1(SS) & {} /: FIN1(SS) &

   (UNION(ss).(ss<:SS | ss) = SS) &
   (card(SS) /= 1  <=> UNION(ss).(ss<<:SS | ss) = SS) &
   (INTER(ss).(ss<:SS | ss) = {}) &

   (SS : POW(TT) <=> SS <: TT) &
   (SS <: TT <=>   (SS - TT = {})) &
   (SS=TT <=> POW(SS) = POW(TT)) &
   (POW(SS-TT) = { xx | xx<:SS & xx /\ TT = {} }) &

   ((SS=VV & SS /= {}) => (max(SS) = max(VV) & min(SS)=min(VV))) &

   (SS=VV or SS/=VV) & not(SS=VV & SS/=VV) &

   ((SS <: VV & SS/= {})  => (max(SS) <= max(VV) & min(SS) >= min(VV))) &

   (card(SS)=1  <=> (SS /={} & max(SS) = min(SS))) &
   (card(SS)=1  => (SS /={} & max(SS) = SIGMA (gg).(gg:SS|gg))) &
   (card(SS)=1  => (SS /={} & max(SS) = PI (gg).(gg:SS|gg)))&
   ((SS /={} & 1 /: SS & max(SS) = PI (gg).(gg:SS|gg)) => card(SS)=1) &

   (UNION(ss).(ss<:SS & card(ss)<3 | ss) = SS)  &
   (card(SS) /= 1  <=> UNION(ss).(ss<<:SS | ss) = SS) &
   (INTER(ss).(ss<:SS & card(ss)<3 | ss) = {})

   &
   (SS/={} <=> #ee.(ee:SS) )
   &
   (SS /\ TT /= {}  <=>   #ee.(ee:SS & ee:TT) )
   &
   ( SS /<: TT  <=>  #ee.(ee:SS & ee/:TT))
   &
   ( SS<<:TT <=>  (SS<:TT & #ee.(ee:TT & ee/:SS)))

   & !(xx,yy).(xx:0..8&yy:1..8 => (xx mod yy = xx - (xx/yy)*yy ))

   &
   (id(SS)=SS*SS <=> card(SS)<2) &
   (SS*VV = TT*VV  <=>  (((SS={} or VV={}) & (TT={} or VV={})) or (SS=TT & VV=VV))) &
   (id(SS)=id(TT) <=> SS=TT) &
   (id(SS) <: id(TT) <=> SS <: TT) &

   SS = ran(%x.(x:SS|x*1))
   //&
   //SS = {z|z:INTEGER & #x.(x:SS & z=x*1)}

    &
    ((SS/={} & TT/={}) =>
       min(SS \/ TT) = min( {min(SS),min(TT)} )) & /* law about min from page 156 of B-Book */
   ((SS/={} & TT/={}) =>
       max(SS \/ TT) = max( {max(SS),max(TT)} )) & /* law about max from page 158 of B-Book */
   (SS/={} => min(SS):SS & max(SS):SS & SS <: min(SS)..max(SS) &
              !el.(el:SS => el>=min(SS) & el<=max(SS)) )
   &
   (SS /={} => SS <: min(SS)..max(SS)) &
   (SS/={} & card(SS)=1+max(SS)-min(SS) => SS=min(SS)..max(SS)) &
   /* (SS/={} & card(SS)=1+max(SS)-min(SS) => #(x,y).(x..y=SS)) & can induce expansion of infinite set */
   (card(SS)=0 <=> SS={}) &

   (SS /= {} =>  (SS-{min(SS)} <: SS & SS-{max(SS)} <: SS & SS-{max(SS),min(SS)} <: SS &
                  SS-{min(SS)}\/{min(SS)} = SS) &
                  {min(SS)} <: SS & min(SS):SS &
                  min(SS) <= max(SS) &
                  (card(SS)>1 <=> min(SS)/=max(SS)) &
                  (SS-{min(SS)}-{max(SS)} = SS-{max(SS)}-{min(SS)})
                 ) &
  (SS /\ TT /= {} =>
       ( max(SS) >= max(SS /\ TT) &
         max(TT) >= max(SS /\ TT) &
         max(SS/\TT) >= max({min(SS),min(TT)}) &
         min(SS) <= min(SS /\ TT) &
         min(TT) <= min(SS /\ TT) &
         min(SS/\TT) <= min({max(SS),max(TT)})
        )) &

   /* laws on page 124 of B-Book */
   (inter({SS}) = {x| x : 0..8 & !y.(y:{SS} => x:y)}) &
   (inter({SS,TT}) = {x| x : 0..8 & !y.(y:{SS,TT} => x:y)}) &
   (inter({SS,TT,VV}) = {x| x : 0..8 & !y.(y:{SS,TT,VV} => x:y)}) &
   (union({}) = {x| x<:TT & #y.(y:{} & x:y)}) &
   (union({SS}) = {x| x : 0..8 & #y.(y:{SS} & x:y)}) &
   (union({SS,TT}) = {x| x : 0..8 & #y.(y:{SS,TT} & x:y)}) &
   (union({SS,TT,VV}) = {x| x : 0..8 & #y.(y:{SS,TT,VV} & x:y)})  &

  /* laws from page 127 of B-Book */
   (inter({SS}) = SS) &
   (union({SS}) = SS) &
   (inter({SS,TT}) = SS /\ TT) &
   (union({SS,TT}) = SS \/ TT)
INITIALISATION

   SS,TT,VV := {},{},{}

OPERATIONS

/* cc <-- compr = BEGIN cc := {xx | xx: SS & xx:TT} END;
cc <-- inte = BEGIN cc := SS /\ TT END;
cc <-- sig = BEGIN cc := SIGMA (gg).(gg:SS|gg) END;
cc <-- mx = PRE SS /= {} THEN cc := max(SS) END;

ss_neq_vv = PRE SS/= VV THEN skip END;
ss_eq_vv = PRE SS = VV THEN skip END; */
add_SS(el) = PRE el: 0..8 & el /: SS & el<20 THEN  SS := SS \/ {el} END;
add_TT(el) = PRE el: 0..8 & el /: TT & el<20 THEN  TT := TT \/ {el} END;
add_VV(el) = PRE el: 0..8 & el /: VV & el<20 THEN  VV := VV \/ {el} END ;

set_SS_NAT = BEGIN SS := 0..8 END;
set_SS_01 = BEGIN SS := {xx | xx:0..8 & xx>=0 & xx< 2} END;
set_SS_0 = BEGIN SS := {xx | xx:0..8 & xx>=0 & xx< 1} END;
add_SS_MAXINTP1 = BEGIN SS := SS \/ {4+1} END;
add_SS_MAXINTP2 = BEGIN SS := SS \/ {4+2} END;
add_TT_MAXINTP1 = BEGIN TT := TT \/ {4+1} END;
add_TT_MAXINTP2 = BEGIN TT := TT \/ {4+2} END;
add_VV_MAXINTP1 = BEGIN VV := VV \/ {4+1} END;
set_SS_empty = BEGIN SS := {xx | xx:0..8 & xx>=0 & xx< 0} END;
set_TT_NAT = BEGIN TT := 0..8 END;
set_VV_NAT = BEGIN VV := 0..8 END/* ;

laws_ok = PRE law1 & law2 & law3 & law4 & law5 &
              law6 & law7 & law8 & law9 & law10 & law11 THEN skip END */

END

