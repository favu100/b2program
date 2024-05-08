
MACHINE RelLaws
SETS /* enumerated */
  setX={el1,el2};
  setY={y1,y2}
ABSTRACT_VARIABLES
  ff,
  gg,
  hh,
  rx,
  ry
/* PROMOTED OPERATIONS
  add_ff,
  add_gg,
  add_hh,
  add_rx,
  add_ry */
INVARIANT
    ff <+ gg = gg \/ (dom(gg) <<| ff)
  & hh : POW(setX * setX)
  & ry : POW(setY * setY)
  & ff <+ {} = ff
  & {} <+ ff = ff
  & ff <+ ff = ff
  & ff~ = {yy,xx|yy : ran(ff) & xx : dom(ff) & xx |-> yy : ff}
  & id(ff) = {xx,yy|xx : ff & yy : ff & xx = yy}
  & prj1(ff,gg) = prj1(ff,gg)
  & prj2(ff,gg) = prj2(ff,gg)
  & iterate(hh,1) = hh
  & dom(ff >< gg) = dom(ff) /\ dom(gg)
  & ran(ff >< gg) = {y,z|y : ran(dom(gg) <| ff) & z : ran(dom(ff) <| gg) & #x.(x : dom(ff) & x : dom(gg) & x |-> y : ff & x |-> z : gg)}
  &
    !(fx,fy,gy).(
     (
      fx : setX
      &
      fy : setY
      &
      gy : setY
     )
     =>
     (
      (
       fx |-> fy : ff
       &
       fx |-> gy : gg
      )
      <=>
      (fx |-> (fy |-> gy) : ff >< gg)
     )
    )
  & card(ff >< gg) <= card(ff) * card(gg)
  & dom((ff || gg)) = dom(ff) * dom(gg)
  & ran((ff || gg)) = ran(ff) * ran(gg)
  & card((ff || gg)) = card(ff) * card(gg)
  //& (ff || gg) = {xy,mn|#(x,y,m,n).(xy = x |-> y & mn = m |-> n & x |-> m : ff & y |-> n : gg)}
  &
    !(fx,fy,gx,gy).(
     (
      fx : setX
      &
      fy : setY
      &
      gx : setX
      &
      gy : setY
     )
     =>
     (
      (
       fx |-> fy : ff
       &
       gx |-> gy : gg
      )
      <=>
      (fx |-> gx |-> (fy |-> gy) : (ff || gg))
     )
    )
  &
    !nn.(
     (
      nn : 0 .. 100
      &
      nn > 0
     )
     =>
     iterate(hh,nn) = (iterate(hh,nn - 1) ; hh)
    )
  & ff[dom(rx)] = ran((id(dom(rx)) ; ff))
  & (id(setX) ; ff) = ff
  & (ff ; id(setY)) = ff
  & (id(setX) ; rx) = rx
  & (id(setX) ; gg) = gg
  & (id(setY) ; ry) = ry
  & (rx ; ff)~ = (ff~ ; rx~)
  & dom(ff \/ gg) = dom(ff) \/ dom(gg)
  & ran(ff \/ gg) = ran(ff) \/ ran(gg)
  & dom(ff /\ gg) <: dom(ff) /\ dom(gg)
  & ran(ff /\ gg) <: ran(ff) /\ ran(gg)
  & (ff \/ gg)~ = ff~ \/ gg~
  & dom((ff ; gg~)) <: dom(ff)
  & (

     !(xx,yy).(
      xx : dom(ff) &
      yy : ran(ff) &
      xx |-> yy : ff
      =>
      yy : ran(gg)
     )
     =>
     dom((ff ; gg~)) = dom(ff)
    )
  & (
     (ff : setX --> setY)
     <=>
     (
      ff : setX +-> setY
      &
      dom(ff) = setX
     )
    )
  & (
     (ff : setX +-> setY)
     <=>

     !(xx,yy,zz).(
      xx : dom(ff) &
      yy : ran(ff) &
      zz : ran(ff) &
      (
       xx |-> yy : ff
       &
       xx |-> zz : ff
      )
      =>
      yy = zz
     )
    )
  & (
     (ff : setX >->> setY)
     <=>
     (
      ff : setX >-> setY
      &
      ff~ : setY >-> setX
     )
    )
  & (
     (ff : setX >+> setY)
     <=>
     (
      ff : setX +-> setY
      &

      !(xx,yy).(
       (
        xx : dom(ff)
        &
        yy : dom(ff)
        &
        xx /= yy
        &
        1=1 /* LEQ_SYM(xx,yy) */
       )
       =>
       ff(xx) /= ff(yy)
      )
     )
    )
  & (
     (ff : setX +->> setY)
     <=>
     (
      ff : setX +-> setY
      &

      !yy.(
       yy : setY
       =>
       yy : ran(ff)
      )
     )
    )
  & (
     (ff : setX >-> setY)
     <=>
     (
      ff : setX >+> setY
      &
      ff : setX --> setY
     )
    )
  & (
     (ff : setX -->> setY)
     <=>
     (
      ff : setX +->> setY
      &
      ff : setX --> setY
     )
    )
  & (
     (ff : setX >->> setY)
     <=>
     (
      ff : setX -->> setY
      &
      ff : setX >-> setY
     )
    )
  & ff <: ff \/ gg
  & gg <: ff \/ gg
  & ff /\ gg <: ff
  & ff /\ gg <: gg
  & {xx|xx : ff & xx : gg} = ff /\ gg
  & {xx|xx : ff & not(xx : gg)} = ff - gg
  &
    !xx.(
     (
      xx : ff
      &
      xx : gg
     )
     =>
     xx : ff /\ gg
    )
  &
    !xx.(
     (
      xx : ff
      &
      not(xx : gg)
     )
     =>
     (
      xx : ff - gg
      &
      xx /: gg
     )
    )
  & (

     #xx.(
      xx : ff
      &
      xx /: gg
     )
     =>
     (
      not(ff \/ gg = gg)
      &
      not(ff - gg = {})
     )
    )
  & (
     ff <<: gg
     or
     ff /<<: gg
    )
  & (
     ff <: gg
     or
     ff /<: gg
    )
  & (
     ff : POW(gg)
     or
     ff /: POW(gg)
    )
  & (
     (
      ff <: gg
      &
      ff /<<: gg
     )
     =>
     ff = gg
    )
  & (
     ff <: gg
     =>
     (
      ff /= gg
      <=>
      ff <<: gg
     )
    )
  & (
     ff <<: gg
     =>
     (
      ff /= gg
      &
      gg /= {}
     )
    )
  & (
     ff = gg
     =>
     ff /<<: gg
    )
  & (
     ff <<: gg
     =>
     ff <: gg
    )
  & (
     ff <<: gg
     =>

     #xx.(
      xx : gg
      &
      xx /: ff
     )
    )
  & (
     ff <: gg
     <=>

     !x.(
      x : ff
      =>
      x : gg
     )
    )
  & (
     ff <<: gg
     =>
     card(ff) < card(gg)
    )
  & (
     ff <: gg
     =>
     card(ff) <= card(gg)
    )
  & (
     card(ff) < card(gg)
     =>
     gg /<: ff
    )
  & card(ff \/ gg) <= card(ff) + card(gg)
  & (
     (ff /\ gg = {})
     <=>
     ff <: setX * setY - gg
    )
  /*& union({RANGE_LAMBDA__|#ss.(ss <: ff & RANGE_LAMBDA__ = ss)}) = ff
  & (
     card(ff) /= 1
     <=>
     (union({RANGE_LAMBDA__|#ss.(ss <<: ff & RANGE_LAMBDA__ = ss)}) = ff)
    )
  & inter({RANGE_LAMBDA__|#ss.(ss <: ff & RANGE_LAMBDA__ = ss)}) = {}*/
  & (
     (ff /\ gg) /= {}
     <=>
     (ff /\ gg) /= {}
    )
  & (
     ff /<: gg
     <=>

     #ee.(
      ee : ff
      &
      ee /: gg
     )
    )
  & (
     ff <<: gg
     <=>
     (
      ff <: gg
      &

      #ee.(
       ee : gg
       &
       ee /: ff
      )
     )
    )
  & (
     (ff : dom(gg) <-> ran(gg))
     <=>
     (
      dom(ff) <: dom(gg)
      &
      ran(ff) <: ran(gg)
     )
    )
  & ff |> ran(ff) = ff
  & ff |>> {} = ff
  & ff |>> ran(ff) = {}
  & (
     ff : setX +-> setY
     =>
     ff |> ran(gg) = %fx.(fx : dom(ff) & ff(fx) : ran(gg)|ff(fx))
    )
  & (
     ff : setX +-> setY
     =>
     ff |>> ran(gg) = %fx.(fx : dom(ff) & ff(fx) /: ran(gg)|ff(fx))
    )
  & ff |> ran(gg) = {xy|xy : ff & prj2(setX,setY)(xy) : ran(gg)}
  & ff |>> ran(gg) = {xy|xy : ff & prj2(setX,setY)(xy) /: ran(gg)}
  & dom(ff) <| ff = ff
  & {} <<| ff = ff
  & dom(ff) <<| ff = {}
  & dom(gg) <| ff = {xy|xy : ff & prj1(setX,setY)(xy) : dom(gg)}
  & dom(gg) <<| ff = {xy|xy : ff & prj1(setX,setY)(xy) /: dom(gg)}
  & {dd|dd <: setX & dd <| ff = ff} = {dd|dd <: setX & dom(ff) <: dd}
  & {rr|rr <: setY & ff |> rr = ff} = {rr|rr <: setY & ran(ff) <: rr}
  & {dd|dd <: setX & dd <<| ff = ff} = {dd|dd <: setX & dom(ff) /\ dd = {}}
  & {rr|rr <: setY & ff |>> rr = ff} = {rr|rr <: setY & ran(ff) /\ rr = {}}
  & rx <: closure1(rx)
  & rx <: closure(rx)
  & id(dom(rx) \/ ran(rx)) <: closure(rx)
  & closure(rx) = closure(rx) \/ id(dom(rx) \/ ran(rx))
  & closure(rx) = closure(rx \/ id(dom(rx) \/ ran(rx)))
  & closure1(rx) <: closure(rx)
  & id(dom(rx) \/ ran(rx)) <: closure(rx)
  & closure1(rx \/ id(dom(rx) \/ ran(rx))) <: closure(rx)
  & closure1(rx) \/ id(setX) = closure(rx)
  & closure1(rx \/ id(setX)) = closure(rx)
  & iterate(rx,1) = rx
  & iterate(rx,0) = id(setX)
  & (
     rx <: hh
     =>
     (
      closure1(rx) <: closure1(hh)
      &
      id(setX) <: closure(hh)
      &
      closure1(rx) <: closure(hh)
     )
    )
  & closure(rx) = closure(closure(rx))
  & closure(rx) = closure1(closure(rx))
  & (closure(rx) ; closure(rx)) = closure(rx)
  & closure(rx)~ = closure(rx~)
  & (
     rx[dom(hh)] <: dom(hh)
     =>
     closure(rx)[dom(hh)] = dom(hh)
    )
  //& closure1(rx) = union({RANGE_LAMBDA__|#n.(n : 1 .. card(rx) & RANGE_LAMBDA__ = iterate(rx,n))})
  //& closure(rx) = union({RANGE_LAMBDA__|#n.(n : 0 .. card(rx) & RANGE_LAMBDA__ = iterate(rx,n))})
  & (closure1(rx) ; closure1(rx)) <: closure1(rx)
  & closure1(rx) = closure1(closure1(rx))
  & closure1(rx)~ = closure1(rx~)
  & (
     rx <: hh
     =>
     closure1(rx) <: closure1(hh)
    )
  & closure1(rx)[dom(hh)] = rx[dom(hh)] \/ (closure1(rx) ; rx)[dom(hh)]
  //& closure1(rx)[dom(hh)] = union({RANGE_LAMBDA__|#n.(n : 1 .. card(rx) & RANGE_LAMBDA__ = iterate(rx,n)[dom(hh)])})
  & (
     rx[dom(hh)] <: dom(hh)
     =>
     closure1(rx)[dom(hh)] <: dom(hh)
    )
  & ff[{}] = {}
  & gg[{}] = {}
  & hh[{}] = {}
  & ff[dom(ff)] = ran(ff)
  & gg[dom(gg)] = ran(gg)
  & hh[dom(hh)] = ran(hh)
  & (ff~)[ran(ff)] = dom(ff)
  & (gg~)[ran(gg)] = dom(gg)
  & (hh~)[ran(hh)] = dom(hh)
  & (
     (ff * hh = gg * hh)
     <=>
     (
      (
       (
        ff = {}
        or
        hh = {}
       )
       &
       (
        gg = {}
        or
        hh = {}
       )
      )
      or
      ff = gg
     )
    )
  & (
     (id(ff) = id(gg))
     <=>
     (ff = gg)
    )
  & (
     id(ff) <: id(gg)
     <=>
     ff <: gg
    )
  & %fnc_x.(fnc_x : dom(ff)|ff[{fnc_x}]) : dom(ff) --> POW(ran(ff))
  & {rel_x,rel_y|rel_x : dom(ff) & rel_y : union(%fnc_x.(fnc_x : dom(ff)|ff[{fnc_x}])[{rel_x}])} = ff
  &
    !x.(
     x : dom(ff)
     =>
     %fnc_x.(fnc_x : dom(ff)|ff[{fnc_x}])(x) = ff[{x}]
    )
  & ff~ = {b,a|b : ran(ff) & a : dom(ff) & a |-> b : ff}
  & dom(ff) = {a|a : dom(ff) & #b.(b : ran(ff) & a |-> b : ff)}
  & ran(ff) = dom(ff~)
  & (ff ; ry) = {a,c|a : dom(ff) & c : ran(ry) & #b.(b : ran(ff) & a |-> b : ff & b |-> c : ry)}
  & id(dom(ff)) = {a,b|a: dom(ff) & b : dom(ff) & a |-> b : dom(ff) * dom(ff) & a = b}
  & dom(ff) <| gg = (id(dom(ff)) ; gg)
  & gg |> ran(ff) = (gg ; id(ran(ff)))
  & dom(ff) <<| gg = dom(gg) - dom(ff) <| gg
  & gg |>> ran(ff) = gg |> ran(gg) - ran(ff)
  & ran(ff) = {b|b : ran(ff) & #a.(a : dom(ff) & a |-> b : ff)}
  & dom(ff) <| gg = {a,b|a : dom(gg) & b : ran(gg) & a |-> b : gg & a : dom(ff)}
  & gg |> ran(ff) = {a,b|a : dom(gg) & b : ran(gg) & a |-> b : gg & b : ran(ff)}
  & dom(ff) <<| gg = {a,b|a : dom(gg) & b : ran(gg) & a |-> b : gg & a /: dom(ff)}
  & gg |>> ran(ff) = {a,b|a : dom(gg) & b : ran(gg) & a |-> b : gg & b /: ran(ff)}
  & ff[dom(gg)] = ran(dom(gg) <| ff)
  & gg <+ ff = (dom(ff) <<| gg) \/ ff
  & ff >< gg = {a,bc|a : dom(gg) & bc : ran(ff) * ran(gg) & #(b,c).(b : ran(ff) & c : ran(gg) & bc = b |-> c & a |-> b : ff & a |-> c : gg)}
  & prj1(setX,setY) = (id(setX) >< setX * setY)~
  & prj2(setX,setY) = (setY * setX >< id(setY))~
  //& (ff || hh) = (prj1(setX,setX) ; ff) >< (prj2(setX,setX) ; hh)
  //& (ff || ry) = (prj1(setX,setY) ; ff) >< (prj2(setX,setY) ; ry)
  & ff[dom(gg)] = {b|b : ran(ff) & #a.(a : dom(gg) & a |-> b : ff)}
  & gg <+ ff = {a,b|a : dom(gg) & b : ran(gg) & ((a |-> b : gg & a /: dom(ff)) or a |-> b : ff)}
  & prj1(setX,setY) = prj1(setX,setY)
  & prj2(setX,setY) = prj2(setX,setY)
  //& (ff || hh) = {ab,cd|#(a,b,c,d).(ab = a |-> b & cd = c |-> d & a |-> c : ff & b |-> d : hh)}
  //& (ff || ry) = {ab,cd|#(a,b,c,d).(ab = a |-> b & cd = c |-> d & a |-> c : ff & b |-> d : ry)}
  & (ff ; ry)[dom(hh)] = ry[ff[dom(hh)]]
  & (
     (
      dom(hh) <: dom(ff)
      &
      ff~ : setY +-> setX
     )
     =>
     (ff ; ff~)[dom(hh)] = dom(hh)
    )
  & id(dom(hh))[dom(ff)] = dom(hh) /\ dom(ff)
  & (
     (dom(hh) /\ dom(ff)) /= {}
     =>
     (dom(hh) * dom(ry))[dom(ff)] = dom(ry)
    )
  & (
     dom(hh) /\ dom(ff) = {}
     =>
     (dom(hh) * dom(ry))[dom(ff)] = {}
    )
  & (rx ; {}) = {}
  & {} = ({} ; rx)
  & (ff ; gg~) = {b,c|b : dom(ff) & c : dom(gg) & #a.(a : ran(ff) & b |-> a : ff & c |-> a : gg)}
  & (
     (ff~ ; ff) <: id(setY)
     <=>
     (ff : setX +-> setY)
    )
  & (rx ; (ff ; ry)) = ((rx ; ff) ; ry)
  & rx <: ((rx ; rx~) ; rx)
INITIALISATION
    BEGIN
      ff,gg,hh,rx,ry := {},{},{},{},{}
    END
OPERATIONS
  add_ff(xx,yy) =
    PRE
        xx : setX &
        yy : setY &
        (xx |-> yy) /: ff
    THEN
      ff := ff \/ {xx |-> yy}
    END;

  add_gg(xx,yy) =
    PRE
        xx : setX &
        yy : setY &
        (xx |-> yy) /: gg
    THEN
      gg := gg \/ {xx |-> yy}
    END;

  add_hh(xx,yy) =
    PRE
        xx : setX &
        yy : setX &
        (xx |-> yy) /: hh
    THEN
      hh := hh \/ {xx |-> yy}
    END;

  add_rx(xx,yy) =
    PRE
        xx : setX &
        yy : setX &
        (xx |-> yy) /: rx
    THEN
      rx := rx \/ {xx |-> yy}
    END;

  add_ry(xx,yy) =
    PRE
        xx : setY &
        yy : setY &
        (xx |-> yy) /: ry
    THEN
      ry := ry \/ {xx |-> yy}
    END
/* DEFINITIONS
  PREDICATE otherlaw1;
  PREDICATE orderlaw5;
  PREDICATE cardlaw1;
  PREDICATE difflaw3;
  PREDICATE orderlaw9;
  PREDICATE difflaw1;
  PREDICATE orderlaw8;
  PREDICATE difflaw2;
  PREDICATE law15;
  PREDICATE law14;
  PREDICATE law13;
  PREDICATE law12;
  PREDICATE law11;
  PREDICATE law10;
  PREDICATE law4;
  PREDICATE law5;
  PREDICATE ff_is_pf;
  PREDICATE law2;
  PREDICATE existslaw2;
  PREDICATE law3;
  PREDICATE law8;
  PREDICATE law9;
  PREDICATE law6;
  PREDICATE foralllaw1;
  PREDICATE law7;
  PREDICATE foralllaw2;
  PREDICATE otherlaw6;
  PREDICATE orderlaw3;
  PREDICATE otherlaw5;
  PREDICATE cardlaw3;
  PREDICATE otherlaw4;
  PREDICATE cardlaw2;
  PREDICATE orderlaw1;
  PREDICATE otherlaw3;
  PREDICATE otherlaw2;
  PREDICATE cardlaw4;
  PREDICATE otherlaw1b;
  PREDICATE GOAL;
  PREDICATE setcomprlaw4;
  PREDICATE setcomprlaw1;
  PREDICATE law1; */
END
