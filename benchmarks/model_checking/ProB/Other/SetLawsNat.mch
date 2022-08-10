MACHINE SetLawsNat
VARIABLES
   SS, TT, VV

INVARIANT
  SS : POW(NAT) & TT : POW(NAT) & VV : POW(NAT) &
    (SS \/ SS = SS  &  SS = SS \/ {}  &  SS = SS /\ SS  &  SS = SS \ {}) & (SS /\ {} = {} & {} = SS \ SS &  ({} \ SS = {})) & (SS \/ TT = TT \/ SS   &  SS /\ TT = TT /\ SS) & (( SS \/ (TT \/ VV) = (SS \/TT) \/ VV) & ( SS /\ (TT /\ VV) = (SS /\ TT) /\ VV)) & ( SS \/ (TT /\ VV) = (SS \/ TT) /\ (SS \/ VV)) & ( SS /\ (TT \/ VV) = (SS /\ TT) \/ (SS /\ VV)) & ( (SS /\ TT) \/ (SS \ TT) = SS) & ((SS \ TT) /\ TT = {}) &
   (SS \ (TT \ VV) = (SS \ TT) \/ (SS /\ VV)) & ((SS \ TT) \ VV = (SS \ (TT \/ VV))) & (SS \/ (TT \ VV) = (SS \/ TT) \ (VV \ SS)) & (SS /\ (TT \ VV) = (SS /\ TT) \ VV) & ((SS \/ TT) \ VV = (SS \ VV) \/ (TT \ VV)) & (SS \ (TT /\ VV) = ( SS \ TT) \/ (SS \ VV)) &
   (SS <: SS \/ TT & TT <: SS \/ TT) & ( ( SS <: VV & TT <: VV) => (SS\/TT <: VV)) & (SS /\ TT <: SS & SS /\ TT <: TT) & ( (VV <: SS & VV <: TT) => (VV <: SS /\ TT)) &
   ( {xx | xx: SS & xx:TT} = SS /\ TT)  & ( {xx | xx: NAT & (xx: SS or xx:TT)} = SS \/ TT) & ( {xx | xx: NAT & xx: SS & (xx: TT or xx:VV)} = SS /\ (VV \/TT)) & ( {xx | xx: SS & not(xx:TT)} = SS \ TT) &
   (!xx.(xx:SS & xx:TT => xx: SS /\ TT)) & (!xx.(xx:SS & not(xx:TT) => (xx: SS \ TT & xx /: TT))) & (#xx.(xx:SS & xx:TT & xx:VV) => not(SS /\ TT /\ VV = {})) & (#xx.(xx:SS & xx/:TT) => not(SS \/ TT = TT) & not(SS \ TT = {})) &

   ( SS <<: VV  or SS /<<: VV ) & ( (VV <<: SS & SS <: TT) => (VV <<: TT)) & ( (VV <: SS & SS <<: TT) => (VV <<: TT)) &
   ( SS <: VV  or SS /<: VV ) & ( SS : POW(TT)  or SS /: POW(TT) ) &
   ( (SS <: VV & SS /<<: VV) => SS = VV) & (  SS <: VV => (SS /= VV  <=> SS <<: VV)) & ( (SS <<: VV ) => SS /= VV) & ( (SS = VV ) => SS /<<: VV) & ( SS <<: VV  => SS <: VV) & ( SS <<: VV => #xx.(xx:VV & xx/:SS)) & ( SS <: VV <=> !x.(x:SS => x:VV) ) &

   (SS <<: VV => (card(SS) < card(VV))) & (SS <: VV => (card(SS) <= card(VV))) & (card(SS) < card(VV) => (VV /<: SS)) & (card(SS \/ VV) <= (card(SS) + card(VV))) & (card(SS) = card(VV) => (VV /<<: SS)) & (card(SS) <= card(VV) => (VV /<<: SS)) & (SS = VV => (card(SS) = card(VV))) & (card(SS /\ VV) <= card(SS) & card(SS /\ VV) <= card(VV))
   &
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

   ((SS=VV & SS /= {}) => (max(SS) = max(VV) & min(SS)=min(VV))) &

   (SS=VV or SS/=VV) & not(SS=VV & SS/=VV) &

   ((SS <: VV & SS/= {})  => (max(SS) <= max(VV) & min(SS) >= min(VV))) &
   ((SS <: VV & SS/= {})  => (min(SS)..max(SS) <: min(VV)..max(VV))) &

   (card(SS)=1  <=> (SS /={} & max(SS) = min(SS))) &
   (card(SS)=1  => (SS /={} & max(SS) = SIGMA (gg).(gg:SS|gg))) &
   (card(SS)=1  => (SS /={} & max(SS) = PI (gg).(gg:SS|gg)))&
   ((SS /={} & 1 /: SS & max(SS) = PI (gg).(gg:SS|gg)) => card(SS)=1) &

   (UNION(ss).(ss<:SS & card(ss)<3 | ss) = SS)  &
   (card(SS) /= 1  <=> UNION(ss).(ss<<:SS | ss) = SS) &
   (INTER(ss).(ss<:SS & card(ss)<3 | ss) = {})

   & !(xx,yy).(xx:NAT&yy:NAT1 => (xx mod yy = xx - (xx/yy)*yy ))


   &
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
   (SS/={} & card(SS)=1+max(SS)-min(SS) => #(x,y).(x : SS & y : SS & x..y=SS)) &
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
        ))
INITIALISATION

   SS,TT,VV := {},{},{}

OPERATIONS

/* cc <-- compr = BEGIN cc := {xx | xx: SS & xx:TT} END;
cc <-- inte = BEGIN cc := SS /\ TT END;
cc <-- sig = BEGIN cc := SIGMA (gg).(gg:SS|gg) END;
cc <-- mx = PRE SS /= {} THEN cc := max(SS) END;

ss_neq_vv = PRE SS/= VV THEN skip END;
ss_eq_vv = PRE SS = VV THEN skip END; */
add_SS(el) = PRE el: NAT & el /: SS THEN  SS := SS \/ {el} END;
add_TT(el) = PRE el: NAT & el /: TT THEN  TT := TT \/ {el} END;
add_VV(el) = PRE el: NAT & el /: VV THEN  VV := VV \/ {el} END ;

set_SS_Interval(el) = PRE el:NAT THEN SS := 1..el END;
set_TT_Interval(el) = PRE el:NAT THEN TT := 1..el END;
set_VV_Interval(el) = PRE el:NAT THEN VV := 1..el END;

set_SS_NAT = BEGIN SS := NAT END;
set_SS_01 = BEGIN SS := {xx | xx:NAT & xx>=0 & xx< 2} END;
set_SS_0 = BEGIN SS := {xx | xx:NAT & xx>=0 & xx< 1} END;
set_SS_empty = BEGIN SS := {xx | xx:NAT & xx>=0 & xx< 0} END;
set_TT_NAT = BEGIN TT := NAT END;
set_VV_NAT = BEGIN VV := NAT END/* ;

laws_ok = PRE  (SS \/ SS = SS  &  SS = SS \/ {}  &  SS = SS /\ SS  &  SS = SS \ {}) & (SS /\ {} = {} & {} = SS \ SS &  ({} \ SS = {})) & (SS \/ TT = TT \/ SS   &  SS /\ TT = TT /\ SS) & (( SS \/ (TT \/ VV) = (SS \/TT) \/ VV) & ( SS /\ (TT /\ VV) = (SS /\ TT) /\ VV)) & ( SS \/ (TT /\ VV) = (SS \/ TT) /\ (SS \/ VV)) &
              ( SS /\ (TT \/ VV) = (SS /\ TT) \/ (SS /\ VV)) & ( (SS /\ TT) \/ (SS \ TT) = SS) & ((SS \ TT) /\ TT = {}) & (SS \ (TT \ VV) = (SS \ TT) \/ (SS /\ VV)) & ((SS \ TT) \ VV = (SS \ (TT \/ VV))) & (SS \/ (TT \ VV) = (SS \/ TT) \ (VV \ SS)) THEN skip END */

END
