
MACHINE SetLawsPow
SETS /* enumerated */
  elements={el1}
ABSTRACT_VARIABLES
  SS,
  TT,
  VV
/* PROMOTED OPERATIONS
  add_SS,
  add_TT,
  add_VV,
  set_SS_setX,
  set_TT_setX,
  set_VV_setX */
INVARIANT
  SS <: POW(POW(elements)) & TT <: POW(POW(elements)) & VV <: POW(POW(elements))
  & SS \/ SS = SS
  & SS = SS \/ {}
  & SS = SS /\ SS
  & SS = SS - {}
  & {} = SS - SS
  & {} - SS = {}
  & SS \/ TT = TT \/ SS
  & SS /\ TT = TT /\ SS
  & SS \/ (TT \/ VV) = SS \/ TT \/ VV
  & SS /\ (TT /\ VV) = SS /\ TT /\ VV
  & SS \/ (TT /\ VV) = (SS \/ TT) /\ (SS \/ VV)
  & SS /\ (TT \/ VV) = (SS /\ TT) \/ (SS /\ VV)
  & (SS /\ TT) \/ SS - TT = SS
  & SS - TT /\ TT = {}
  & SS - (TT - VV) = SS - TT \/ (SS /\ VV)
  & SS - TT - VV = SS - (TT \/ VV)
  & SS \/ TT - VV = (SS \/ TT) - (VV - SS)
  & SS /\ TT - VV = (SS /\ TT) - VV
  & (SS \/ TT) - VV = SS - VV \/ TT - VV
  & SS - (TT /\ VV) = SS - TT \/ SS - VV
  & SS <: SS \/ TT
  & TT <: SS \/ TT
  & (
     (
      SS <: VV
      &
      TT <: VV
     )
     =>
     (
      SS <: VV
      &
      TT <: VV
     )
    )
  & SS /\ TT <: SS
  & SS /\ TT <: TT
  & (
     (
      VV <: SS
      &
      VV <: TT
     )
     =>
     VV <: SS /\ TT
    )
  & {xx|xx : SS & xx : TT} = SS /\ TT
  & {xx|xx : SS} \/ {xx|xx : TT} = SS \/ TT
  & {xx|xx : SS & (xx : TT or xx : VV)} = SS /\ (VV \/ TT)
  & {xx|xx : SS & not(xx : TT)} = SS - TT
  &
    !xx.(
     (
      xx : SS
      &
      xx : TT
     )
     =>
     xx : SS /\ TT
    )
  &
    !xx.(
     (
      xx : SS
      &
      not(xx : TT)
     )
     =>
     (
      xx : SS - TT
      &
      xx /: TT
     )
    )
  & (
     (SS /\ TT /\ VV) /= {}
     =>
     not(SS /\ TT /\ VV = {})
    )
  & (

     #xx.(
      xx : SS
      &
      xx /: TT
     )
     =>
     (
      not(SS \/ TT = TT)
      &
      not(SS - TT = {})
     )
    )
  & (
     SS <<: VV
     or
     SS /<<: VV
    )
  & (
     (
      VV <<: SS
      &
      SS <: TT
     )
     =>
     VV <<: TT
    )
  & (
     (
      VV <: SS
      &
      SS <<: TT
     )
     =>
     VV <<: TT
    )
  & (
     SS <: VV
     or
     SS /<: VV
    )
  & (
     SS : POW(TT)
     or
     SS /: POW(TT)
    )
  & (
     (
      SS <: VV
      &
      SS /<<: VV
     )
     =>
     SS = VV
    )
  & (
     SS <: VV
     =>
     (
      SS /= VV
      <=>
      SS <<: VV
     )
    )
  & (
     SS <<: VV
     =>
     SS /= VV
    )
  & (
     SS = VV
     =>
     SS /<<: VV
    )
  & (
     SS <<: VV
     =>
     SS <: VV
    )
  & (
     SS <<: VV
     =>

     #xx.(
      xx : VV
      &
      xx /: SS
     )
    )
  & (
     SS <: VV
     <=>

     !x.(
      x : SS
      =>
      x : VV
     )
    )
  & (
     SS <<: VV
     =>
     card(SS) < card(VV)
    )
  & (
     SS <: VV
     =>
     card(SS) <= card(VV)
    )
  & (
     card(SS) < card(VV)
     =>
     VV /<: SS
    )
  & card(SS \/ VV) <= card(SS) + card(VV)
  & (
     card(SS) = card(VV)
     =>
     VV /<<: SS
    )
  & (
     card(SS) <= card(VV)
     =>
     VV /<<: SS
    )
  & (
     SS = VV
     =>
     card(SS) = card(VV)
    )
  & card(SS /\ VV) <= card(SS)
  & card(SS /\ VV) <= card(VV)
  & (
     SS <<: VV
     or
     not(SS <<: VV)
    )
  & not(
     SS <<: VV
     &
     not(SS <<: VV)
    )
  & (
     SS <: VV
     or
     not(SS <: VV)
    )
  & not(
     SS <: VV
     &
     not(SS <: VV)
    )
  & (
     SS /<<: VV
     or
     not(SS /<<: VV)
    )
  & not(
     SS /<<: VV
     &
     not(SS /<<: VV)
    )
  & (
     SS /<: VV
     or
     not(SS /<: VV)
    )
  & not(
     SS /<: VV
     &
     not(SS /<: VV)
    )
  & (
     SS /: POW(TT)
     or
     not(SS /: POW(TT))
    )
  & not(
     SS /: POW(TT)
     &
     not(SS /: POW(TT))
    )
  & (
     SS : POW(TT)
     or
     not(SS : POW(TT))
    )
  & not(
     SS : POW(TT)
     &
     not(SS : POW(TT))
    )
  & POW1(SS) = POW(SS) - {{}}
  & card(POW1(SS)) = card(POW(SS)) - 1
  & card(POW(SS) - {{}}) = card(POW(SS)) - 1
  & POW(SS) - {{}} \/ {{}} = POW(SS)
  & FIN1(SS) = FIN(SS) - {{}}
  & union({RANGE_LAMBDA__|RANGE_LAMBDA__ : POW(POW(POW(elements))) & #ss.(ss <: SS & RANGE_LAMBDA__ = ss)}) = SS
  & (
     card(SS) /= 1
     <=>
     (union({RANGE_LAMBDA__|RANGE_LAMBDA__ : POW(POW(POW(elements))) & #ss.(ss <<: SS & RANGE_LAMBDA__ = ss)}) = SS)
    )
  & inter({RANGE_LAMBDA__|RANGE_LAMBDA__ : POW(POW(POW(elements))) & #ss.(ss <: SS & RANGE_LAMBDA__ = ss)}) = {}
  & (
     (SS /\ TT) /= {}
     <=>
     (SS /\ TT) /= {}
    )
  & (
     SS /<: TT
     <=>

     #ee.(
      ee : SS
      &
      ee /: TT
     )
    )
  & (
     SS <<: TT
     <=>
     (
      SS <: TT
      &

      #ee.(
       ee : TT
       &
       ee /: SS
      )
     )
    )
  & (
     (SS : POW(TT))
     <=>
     SS <: TT
    )
  & (
     (SS = TT)
     <=>
     (POW(SS) = POW(TT))
    )
  & POW(SS - TT) = {xx|xx <: SS & xx /\ TT = {}}
  & (
     SS /= {}
     =>
     inter(SS) = {x|x : POW(elements) & !y.(y : SS => x : y)}
    )
  & SS /\ TT = {x|x : POW(POW(elements)) & !y.(y : {SS,TT} => x : y)}
  & SS /\ (TT /\ VV) = {x|x : POW(POW(elements)) & !y.(y : {SS,TT,VV} => x : y)}
  & union(SS) = {x|x : POW(elements) & #y.(y : SS & x : y)}
  & union({}) = {x|x <: TT & #y.(y : {} & x : y)}
  & SS \/ TT = {x|x : POW(POW(elements)) & #y.(y : {SS,TT} & x : y)}
  & SS \/ (TT \/ VV) = {x|x : POW(POW(elements)) & #y.(y : {SS,TT,VV} & x : y)}
  & (
     SS /= {}
     =>
     inter(SS) = inter({RANGE_LAMBDA__|RANGE_LAMBDA__ : POW(POW(elements)) & #y.(y : SS & RANGE_LAMBDA__ = y)})
    )
  & union(SS) = union({RANGE_LAMBDA__|RANGE_LAMBDA__ : POW(POW(elements)) & #y.(y : SS & RANGE_LAMBDA__ = y)})
  & (
     SS /= POW(POW(elements))
     =>
     inter({RANGE_LAMBDA__|RANGE_LAMBDA__ : POW(POW(elements)) & #x.(x : POW(POW(elements)) & x /: SS & RANGE_LAMBDA__ = x)}) = inter({RANGE_LAMBDA__|RANGE_LAMBDA__ : POW(POW(elements)) & #x.(x : POW(POW(elements)) & x /: SS & RANGE_LAMBDA__ = x)})
    )
  & (
     (
      SS /= {}
      &
      TT /= {}
     )
     =>
     inter(SS \/ TT) = inter(SS) /\ inter(TT)
    )
  & union(SS \/ TT) = union(SS) \/ union(TT)
  & (
     (
      SS /= {}
      &
      TT /= {}
     )
     =>
     inter(SS \/ TT) = inter(SS) /\ inter(TT)
    )
  & union(SS \/ TT) = union(SS) \/ union(TT)
INITIALISATION
    BEGIN
      SS,TT,VV := {},{},{}
    END
OPERATIONS
  add_SS(el) =
    PRE
        el : POW(POW(elements)) &
        el /: SS
    THEN
      SS := SS \/ {el}
    END;

  add_TT(el) =
    PRE
        el : POW(POW(elements)) &
        el /: TT
    THEN
      TT := TT \/ {el}
    END;

  add_VV(el) =
    PRE
        el : POW(POW(elements)) &
        el /: VV
    THEN
      VV := VV \/ {el}
    END;

  set_SS_setX =
    BEGIN
      SS := POW(POW(elements))
    END;

  set_TT_setX =
    BEGIN
      TT := POW(POW(elements))
    END;

  set_VV_setX =
    BEGIN
      VV := POW(POW(elements))
    END
/* DEFINITIONS
  EXPRESSION setX;
  PREDICATE orderlaw7;
  PREDICATE otherlaw1;
  PREDICATE orderlaw6;
  PREDICATE orderlaw5;
  PREDICATE cardlaw1;
  PREDICATE orderlaw4;
  PREDICATE orderlaw9;
  PREDICATE orderlaw8;
  PREDICATE law14;
  PREDICATE law13;
  PREDICATE law12;
  PREDICATE law11;
  PREDICATE law10;
  PREDICATE law4;
  PREDICATE law5;
  PREDICATE law2;
  PREDICATE existslaw2;
  PREDICATE law3;
  PREDICATE law8;
  PREDICATE law9;
  PREDICATE existslaw1;
  PREDICATE law6;
  PREDICATE foralllaw1;
  PREDICATE law7;
  PREDICATE cardlaw7;
  PREDICATE foralllaw2;
  PREDICATE cardlaw6;
  PREDICATE otherlaw6;
  PREDICATE cardlaw8;
  PREDICATE orderlaw3;
  PREDICATE otherlaw5;
  PREDICATE cardlaw3;
  PREDICATE orderlaw2;
  PREDICATE otherlaw4;
  PREDICATE cardlaw2;
  PREDICATE orderlaw1;
  PREDICATE otherlaw3;
  PREDICATE cardlaw5;
  PREDICATE otherlaw2;
  PREDICATE cardlaw4;
  PREDICATE otherlaw1b;
  PREDICATE setcomprlaw4;
  PREDICATE setcomprlaw3;
  PREDICATE setcomprlaw2;
  PREDICATE setcomprlaw1;
  PREDICATE law1; */
END
