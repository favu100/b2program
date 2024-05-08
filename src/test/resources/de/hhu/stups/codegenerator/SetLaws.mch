
MACHINE SetLaws
SETS /* enumerated */
  setX={el1,el2,el3}
ABSTRACT_VARIABLES
  SS,
  TT,
  VV
INVARIANT
    VV : POW(setX)
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
  & {xx|xx : setX & (xx : SS or xx : TT)} = SS \/ TT
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
     (
      SS /= VV
      &
      VV /= {}
     )
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
     (SS /\ VV = {})
     <=>
     SS <: setX - VV
    )
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
  & FIN1(SS) = FIN(SS) - {{}}
  & {} /: POW1(SS)
  & {} /: FIN1(SS)
  & union({RANGE_LAMBDA__|RANGE_LAMBDA__ : POW(setX) & #ss.(ss <: SS & RANGE_LAMBDA__ = ss)}) = SS
  & (
     card(SS) /= 1
     <=>
     (union({RANGE_LAMBDA__|RANGE_LAMBDA__ : POW(setX) & #ss.(ss <<: SS & RANGE_LAMBDA__ = ss)}) = SS)
    )
  & inter({RANGE_LAMBDA__|RANGE_LAMBDA__ : POW(setX) & #ss.(ss <: SS & RANGE_LAMBDA__ = ss)}) = {}
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
  & SS /\ setX = SS
  & SS \/ setX = setX
  & (setX = SS\/setX - SS & SS/\setX - SS = {})
  & setX - (setX - SS) = SS
  & (
     (SS /\ TT = {})
     <=>
     not((SS /\ TT) /= {})
    )
  & (
     (SS /\ TT /\ VV = {})
     <=>
     not((SS /\ TT /\ VV) /= {})
    )
  & (
     SS <: TT
     <=>
     not(#y.(y : SS & y /: TT))
    )
  & (
     SS /= {}
     <=>
     SS /= {}
    )
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
ASSERTIONS
     /* truth */ VV - SS = VV - SS
INITIALISATION
    BEGIN
      SS,TT,VV := {},{},{}
    END
OPERATIONS
  add_SS(el) =
    PRE
        el : setX
      & el /: SS
    THEN
      SS := SS \/ {el}
    END;

  add_TT(el) =
    PRE
        el : setX
      & el /: TT
    THEN
      TT := TT \/ {el}
    END;

  add_VV(el) =
    PRE
        el : setX
      & el /: VV
    THEN
      VV := VV \/ {el}
    END;

  set_SS_setX =
    BEGIN
      SS := setX
    END;

  set_TT_setX =
    BEGIN
      TT := setX
    END;

  set_VV_setX =
    BEGIN
      VV := setX
    END
END
