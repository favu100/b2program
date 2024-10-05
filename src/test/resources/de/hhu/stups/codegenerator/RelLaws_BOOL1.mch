MACHINE RelLaws_BOOL1
// BOOL is BOOL
/* This machine is intended so that you can check whether ProB deals
with basic laws associated to functions and relations. ProB should
not find an invariant violation. */
SETS
 setY = {y1,y2}

VARIABLES
ff,gg,hh,rx,ry



INVARIANT

ff: BOOL <-> setY & gg: BOOL <-> setY & rx: BOOL <-> BOOL & ry: setY <-> setY &
hh: BOOL <-> BOOL &


( (ff<+gg) = (gg \/ (dom(gg)<<|ff)) )
&
 ( ff<+{} = ff &  {}<+ff = ff &  ff<+ff = ff) &
/*( (ff+>gg) = (ff \/ (dom(ff)<<|gg)) )
&
( (ff+>gg) = (gg<+ff) )
&*/
(ff~ = {yy,xx|xx:dom(ff)&yy:ran(ff)&({xx|->yy}<:ff)})
&
(id(ff) = {xx,yy|xx:ff&yy:ff&xx=yy})
&
(prj1(ff,gg) = ({xx,yy,zz|xx:(ff)&yy:(gg)&zz=xx}) )
&
(prj2(ff,gg) = ({xx,yy,zz|xx:(ff)&yy:(gg)&zz=yy}) )
&
  (iterate(hh,1)=(hh))
&
/* some laws about the direct product */

(dom(ff><gg) = dom(ff)/\dom(gg))
&
ran(ff><gg) = {y,z|y:ran((dom(gg))<|(ff)) & z:ran((dom(ff))<|(gg)) &
                   #(x).(x:BOOL & x:dom(ff) & x:dom(gg) & x|->y:ff & x|->z:gg)}
&
!(fx,fy,gy).(fx:BOOL & fy:setY & gy:setY =>
                  ((fx|->fy:ff & fx|->gy:gg) <=> fx|->(fy,gy) : (ff><gg))) &
 card((ff><gg)) <= card(ff)*card(gg) &

/* some laws about the parallel product */
 dom((ff||gg)) = dom(ff)*dom(gg) &
 ran((ff||gg)) = ran(ff)*ran(gg) &
 card((ff||gg)) = card(ff)*card(gg) &
 //(ff||gg) = {xy,mn|#(x,y,m,n).(xy=(x,y) & mn=(m,n) & (x,m):ff & (y,n):gg)} &
 !(fx,fy,gx,gy).(fx:BOOL & gx:BOOL & fy:setY & gy:setY =>
                  ((fx|->fy:ff & gx|->gy:gg) <=> (fx,gx)|->(fy,gy) : (ff||gg))) &


(!(nn).((nn:0..100 &nn>0) => (iterate(hh,nn)=(iterate(hh,nn-1);hh))))
&

 ff[dom(rx)] =  ran((id(dom(rx));ff)) &  /* rule f[S] = ran((id(S);f)) */


(id(BOOL) ; ff) = ff & (ff ; id(setY)) = ff &
(id(BOOL) ; rx) = rx &
(id(BOOL) ; gg) = gg &
(id(setY) ; ry) = ry &

(rx ; ff)~ = (ff~ ; rx~) &

(dom(ff\/gg) = dom(ff) \/ dom(gg)) &
(ran(ff\/gg) = ran(ff) \/ ran(gg)) &
(dom(ff/\gg) <: dom(ff) /\ dom(gg)) &
(ran(ff/\gg) <: ran(ff) /\ ran(gg)) &
( (ff \/ gg)~ = ff~ \/ gg~) &
(dom((ff ; (gg~))) <: dom(ff)) &
(!(xx,yy).(xx:BOOL & yy:setY & xx|->yy : ff  =>  yy: ran(gg))
              =>  (dom((ff ; (gg~))) = dom(ff))) &
(ff : BOOL --> setY  <=>  (ff: BOOL +-> setY & dom(ff) = BOOL)) &
(ff : BOOL +-> setY  <=> (!(xx,yy,zz).((xx:BOOL & yy:setY & zz:setY &
                    xx|->yy:ff & xx|->zz:ff) => (yy=zz)))) &

(ff : BOOL >->> setY  <=>  (ff : BOOL >-> setY  &  ff~: setY >-> BOOL)) &
(ff : BOOL >+> setY  <=> (ff: BOOL +-> setY &
                                     !(xx,yy).(xx:BOOL & yy:BOOL & xx/=yy & xx:dom(ff) &
                                       yy: dom(ff)  => ff(xx)/=ff(yy))))  &

(ff : BOOL +->> setY  <=>  (ff: BOOL +-> setY &
                                       !yy.(yy:setY => yy: ran(ff)))) &

(ff: BOOL >-> setY <=> (ff: BOOL >+> setY & ff: BOOL --> setY)) &
(ff: BOOL -->> setY <=> (ff: BOOL +->> setY & ff: BOOL --> setY)) &
(ff: BOOL >->> setY <=> (ff: BOOL -->> setY & ff: BOOL >-> setY)) &


(ff <: ff \/ gg & gg <: ff \/ gg) &
(ff /\ gg <: ff & ff /\ gg <: gg) &

( {xx | xx: ff & xx:gg} = ff /\ gg) &
( {xx | xx: ff & not(xx:gg)} = ff \ gg) &

(!xx.(xx:ff & xx:gg => xx: ff /\ gg)) &
(!xx.(xx:ff & not(xx:gg) => (xx: ff \ gg & xx /: gg))) &

(#xx.(xx:ff & xx/:gg) => not(ff \/ gg = gg) & not(ff \ gg = {})) &


 /* laws for <<:, <:, /<: and /<<: */
( ff <<: gg  or ff /<<: gg ) &
( ff <: gg  or ff /<: gg ) &
( ff : POW(gg)  or ff /: POW(gg) ) &

( (ff <: gg & ff /<<: gg) => ff = gg) &
(  ff <: gg => (ff /= gg  <=> ff <<: gg)) &
( (ff <<: gg ) => (ff /= gg & card(gg)>0)) &
( (ff = gg ) => ff /<<: gg) &
( ff <<: gg  => ff <: gg) &
( ff <<: gg => #xx.(xx:gg & xx/:ff)) &
( ff <: gg <=> !x.(x:ff => x:gg) ) &

(ff <<: gg => (card(ff) < card(gg))) &
(ff <: gg => (card(ff) <= card(gg))) &
(card(ff) < card(gg) => (gg /<: ff)) &
(card(ff \/ gg) <= (card(ff) + card(gg))) &

(ff /\ gg = {}  <=> ff <: (BOOL*setY) - gg) &
(ff \ gg = ff-gg) &
(gg-ff = gg\ff) &

   (UNION(ss).(ss<:ff | ss) = ff) &
   (card(ff) /= 1  <=> UNION(ss).(ss<<:ff | ss) = ff) &
   (INTER(ss).(ss<:ff | ss) = {})


   &
   (ff /\ gg /= {}  <=>   #ee.(ee:ff & ee:gg) )
   &
   ( ff /<: gg  <=>  #ee.(ee:ff & ee/:gg))
   &
   ( ff<<:gg <=>  (ff<:gg & #ee.(ee:gg & ee/:ff)))

   &
   (ff: dom(gg) <-> ran(gg)  <=>  (dom(ff)<:dom(gg) & ran(ff) <:ran(gg)) )

   &

   ( ff |>  {} = {}) &
   ( ff |>  ran(ff) = ff) &
   ( ff |>> {} = ff) &
   ( ff |>> ran(ff) = {}) &
   ( ff: BOOL +-> setY => (ff |>  ran(gg) = %fx.(fx:dom(ff) & ff(fx):ran(gg) | ff(fx)) ) ) &
   ( ff: BOOL +-> setY => (ff |>> ran(gg) = %fx.(fx:dom(ff) & ff(fx)/:ran(gg)| ff(fx)) ) ) &
   ( ff |>  ran(gg) = {xy|xy:ff & prj2(BOOL,setY)(xy):ran(gg)} ) &
   ( ff |>> ran(gg) = {xy|xy:ff & prj2(BOOL,setY)(xy)/:ran(gg)} ) &

   (      {}  <| ff = {}) &
   ( dom(ff)  <| ff = ff) &
   (      {} <<| ff = ff) &
   ( dom(ff) <<| ff = {}) &
   ( dom(gg)  <| ff  = {xy|xy:ff & prj1(BOOL,setY)(xy):dom(gg)} ) &
   ( dom(gg) <<| ff  = {xy|xy:ff & prj1(BOOL,setY)(xy)/:dom(gg)} ) &

   /*( {dd | dd <| ff = ff} = {dd| dom(ff) <: dd} ) &
   ( {rr | ff |> rr = ff} = {rr| ran(ff) <: rr} ) &
   ( {dd | dd <<| ff = ff} = {dd| dom(ff) /\ dd = {}} ) &
   ( {rr | ff |>> rr = ff} = {rr| ran(ff) /\ rr = {}} )

    &*/
   rx <: closure1(rx) &
   rx <: closure(rx) &
   id( dom(rx) \/ ran(rx) ) <: closure(rx) &
   closure(rx) = closure(rx) \/ id( dom(rx) \/ ran(rx)) &
   closure(rx) = closure(rx \/ id( dom(rx) \/ ran(rx))) &
   closure1(rx) \/ id( dom(rx) \/ ran(rx)) <: closure(rx) &  // ProB interpretation of closure was =
   closure1(rx \/ id( dom(rx) \/ ran(rx))) <: closure(rx) &  // ProB interpretation of closure was =
   closure1(rx) \/ id( BOOL ) = closure(rx) & // new Defintion of closure
   closure1(rx \/ id( BOOL )) = closure(rx) & // new Defintion of closure
   iterate(rx,1) = rx &
   iterate(rx,0) = id(BOOL) & // used to be: id( dom(rx) \/ ran(rx) ) &
   (rx <: hh => (closure1(rx) <: closure1(hh) & closure(rx) <: closure(hh))) &
   closure(rx) = closure(closure(rx)) &
   closure(rx) = closure1(closure(rx)) &
   (closure(rx) ; closure(rx)) = closure(rx) &

   closure(rx)~ = closure(rx~)  & /* &

   (rx[ran(hh)] <: ran(hh) => closure(rx)[ran(hh)] = ran(hh)) */ /* this law is violated by current version of closure */
   (rx[dom(hh)] <: dom(hh) => closure(rx)[dom(hh)]=dom(hh)) & // law in B-Book, page 169, a=dom(hh)


   /* Laws from page 170 of B-Book */
   /* closure1(rx) = UNION(n).(n>0 & n<= card(rx) | iterate(rx,n)) &  use the following in case we don't have CLPFD enabled*/
   closure1(rx) = UNION(n).(n:1..card(rx) | iterate(rx,n)) &
   closure(rx) = UNION(n).(n:0..card(rx) | iterate(rx,n)) &
   (closure1(rx) ; closure1(rx)) <: closure1(rx) &
   closure1(rx) = closure1(closure1(rx)) &
   closure1(rx)~ = closure1(rx~) &
   (rx <: hh => closure1(rx) <: closure1(hh)) &
   closure1(rx)[ dom(hh) ] =  rx[dom(hh)] \/ ((closure1(rx);rx)[dom(hh)]) /* a = dom(hh) */ &
  /* closure1(rx)[dom(hh)] = UNION(n).(n>0 & n<= card(rx) | iterate(rx,n)[dom(hh)]) & also replaced by following one for CLPFD FALSE mode */
   closure1(rx)[dom(hh)] = UNION(n).(n:1..card(rx) | iterate(rx,n)[dom(hh)]) &
   (rx[dom(hh)] <: dom(hh) => closure1(rx)[dom(hh)] <: dom(hh)) /* a = dom(hh) */ &


   /* -- */
   ff[{}] = {} & gg[{}] = {} & hh[{}] = {} &
   ff[dom(ff)] = ran(ff) &
   gg[dom(gg)] = ran(gg) &
   hh[dom(hh)] = ran(hh) &
   ff~[ran(ff)] = dom(ff) &
   gg~[ran(gg)] = dom(gg) &
   hh~[ran(hh)] = dom(hh) &


   (ff*hh = gg*hh  <=>  (((ff={} or hh={}) & (gg={} or hh={})) or (ff=gg & hh=hh))) &
   (id(ff)=id(gg) <=> ff=gg) &
   (id(ff) <: id(gg) <=> ff <: gg)
   &
   fnc(ff) : dom(ff) --> POW(ran(ff)) &
   rel(fnc(ff)) = ff &
   !x.(x:dom(ff) => fnc(ff)(x) = ff[{x}]) &

   /* Definitions from page 78 of B-Book */
   ff~ = {b,a| (a,b):ff} &
   dom(ff) = {a | #b.( a|->b : ff)} &
   ran(ff) = dom(ff~) &
   (ff;ry) = {a,c| #b.((a,b):ff & (b,c):ry)} &
   id(dom(ff)) = {a,b| (a,b):(dom(ff)*dom(ff)) & a=b} &
   dom(ff) <| gg = (id(dom(ff));gg) &
   gg |> ran(ff) = (gg ; id(ran(ff))) &
   dom(ff) <<| gg = (dom(gg)-dom(ff)) <| gg &
   gg |>> ran(ff) = gg |> (ran(gg)-ran(ff)) &
   ran(ff) = {b | #a.( a|->b : ff)} &
   dom(ff) <| gg = {a,b| (a,b):gg & a:dom(ff)} &
   gg |> ran(ff) = {a,b| (a,b):gg & b:ran(ff)} &
   dom(ff) <<| gg = {a,b| (a,b):gg & a/:dom(ff)} &
   gg |>> ran(ff) = {a,b| (a,b):gg & b/:ran(ff)} &

   /* Definitions from page 80 of B-Book */
   ff[dom(gg)] = ran(dom(gg) <| ff) & /* p[w] = ran(w <| p) with w=dom(gg) */
   gg <+ ff = (dom(ff) <<| gg) \/ ff & /* q<+ r = ... in book, error in book p should be r */
   ff >< gg = {a,bc| #(b,c).(bc=(b,c) & (a,b) : ff & (a,c) : gg)} &
   prj1(BOOL,setY) = (id(BOOL) >< (BOOL * setY))~ &
   prj2(BOOL,setY) = ((setY*BOOL) >< id(setY))~ &
   (ff||hh) = (prj1(BOOL,BOOL);ff) >< (prj2(BOOL,BOOL);hh) &
   (ff||ry) = (prj1(BOOL,setY);ff) >< (prj2(BOOL,setY);ry) &

   ff[dom(gg)] = {b| #a.(a:dom(gg) & (a,b):ff)} & /* again error in B-Book (a,b) instead of (x,y) */
   gg <+ ff = {a,b | ( (a,b):gg & a/:dom(ff) ) or (a,b):ff} &
   //prj1(BOOL,setY) = {a,b,c| (a,b,c) : BOOL*setY*BOOL & c=a} &
   //prj2(BOOL,setY) = {a,b,c| (a,b,c) : BOOL*setY*setY & c=b} &
   (ff||hh) = {ab,cd | #(a,b,c,d).(ab=(a,b) & cd = (c,d) & (a,c):ff & (b,d):hh)} &
   (ff||ry) = {ab,cd | #(a,b,c,d).(ab=(a,b) & cd = (c,d) & (a,c):ff & (b,d):ry)} &

   /* Laws from page 111 of B-Book */
   (ff ; ry)[dom(hh)] = ry[ff[dom(hh)]]  /* p=ff, q=ry, u=dom(hh) */ &
   ((dom(hh) <: dom(ff) & ff~: setY +-> BOOL) => (ff ; ff~)[dom(hh)] = dom(hh)) &
   id(dom(hh))[dom(ff)] = dom(hh) /\ dom(ff)  /* u=dom(hh), v = dom(ff) */ &
   /* ... laws not yet encoded ... */
   (dom(hh)/\dom(ff) /= {} => (dom(hh) * dom(ry)) [dom(ff)] = dom(ry)) /*t=dom(ry), u=dom(hh), v=dom(ff) */ &
   (dom(hh)/\dom(ff) = {} => (dom(hh) * dom(ry)) [dom(ff)] = {}) /*t=dom(ry), u=dom(hh), v=dom(ff) */


   & /* Law from Oliveira TSE paper (Alloy meets the Algebra of Programming: a Case Study) */
   (rx ; {}) = {} & {} = ({} ; rx) &
   (ff ; gg~) = {b,c| #a.( (b,a):ff & (a,c):gg~)} &
   ((ff~ ; ff) <: id(setY) <=> ff : BOOL +-> setY) &
   (rx ; (ff ; ry)) =  ((rx ; ff) ; ry) &
   rx <: (rx ; rx~ ; rx)
INITIALISATION

ff,gg,hh,rx,ry := {},{},{},{},{}

OPERATIONS

add_ff(xx,yy) = PRE xx:BOOL & yy:setY & xx |-> yy /: ff THEN
ff := ff \/ {xx |-> yy}
END;
add_gg(xx,yy) = PRE xx:BOOL & yy:setY & xx |-> yy /: gg THEN
gg := gg \/ {xx |-> yy}
END;
add_hh(xx,yy) = PRE xx:BOOL & yy:BOOL & xx |-> yy /: hh THEN
hh := hh \/ {xx |-> yy}
END;
add_rx(xx,yy) = PRE xx:BOOL & yy:BOOL & xx |-> yy /: rx THEN
rx := rx \/ {xx |-> yy}
END;
add_ry(xx,yy) = PRE xx:setY & yy:setY & xx |-> yy /: ry THEN
ry := ry \/ {xx |-> yy}
END
END
