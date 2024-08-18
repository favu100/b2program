MACHINE SeqLaws
SETS
  setY = {y1,y2}

VARIABLES
 ff,gg

INVARIANT

 ff: seq(setY) & gg: seq(setY) &

 (dom(ff\/gg) = dom(ff) \/ dom(gg)) &
 (ran(ff\/gg) = ran(ff) \/ ran(gg)) &
 (dom(ff/\gg) <: dom(ff) /\ dom(gg)) &
 (ran(ff/\gg) <: ran(ff) /\ ran(gg)) &
 ( (ff \/ gg)~ = ff~ \/ gg~) &
 (dom((ff ; (gg~))) <: dom(ff)) &
 (!(xx,yy).(xx:1..4 & yy:setY & xx|->yy : ff  =>  yy: ran(gg))
             =>  (dom((ff ; (gg~))) = dom(ff))) &
 (ff : 1..4 --> setY  <=>  (ff: 1..4 +-> setY & dom(ff) = 1..4)) &
 (ff : 1..4 +-> setY  => (!(xx,yy,zz).((xx:1..4 & yy:setY & zz:setY &
                   xx|->yy:ff & xx|->zz:ff) => (yy=zz)))) &
 ((!(xx,yy,zz).((xx:1..4 & yy:setY & zz:setY &
                   xx|->yy:ff & xx|->zz:ff) => (yy=zz))) => ff : 1..4 +-> setY) &

 (ff : 1..4 >->> setY  <=>  (ff : 1..4 >-> setY  &  ff~: setY >-> 1..4)) &
 (ff : 1..4 >+> setY  <=> (ff: 1..4 +-> setY &
                                    !(xx,yy).(xx:1..4 & yy:1..4 & xx/=yy & xx:dom(ff) &
                                      yy: dom(ff)  => ff(xx)/=ff(yy))))  &

 (ff : 1..4 +->> setY  <=>  (ff: 1..4 +-> setY &
                                      !yy.(yy:setY => yy: ran(ff)))) &

 (ff: 1..4 >-> setY  <=> (ff: 1..4 >+> setY & ff: 1..4 --> setY)) &
 (ff: 1..4 -->> setY <=> (ff: 1..4 +->> setY & ff: 1..4 --> setY)) &
 (ff: 1..4 >->> setY <=> (ff: 1..4 -->> setY & ff: 1..4 >-> setY)) &

 (ff: 1..4 --> setY  =>  ff: 1..4 +-> setY) &
 (ff: 1..4 >+> setY  =>  ff: 1..4 +-> setY)  &
 (ff: 1..4 >-> setY  =>  ff: 1..4 >+> setY)  &
 (ff: 1..4 >-> setY  =>  ff: 1..4 --> setY)  &
 (ff: 1..4 >->> setY  =>  ff: 1..4 --> setY) &
 (ff: 1..4 +->> setY  =>  ff: 1..4 +-> setY)  &
 (ff: 1..4 -->> setY  =>  (ff: 1..4 --> setY & ff: 1..4 +->> setY))

 &

 (ff: 1..4 +->> setY => ran(ff) = setY) &
 (ran(ff) <<: setY => not(ff: 1..4 +->> setY)) &

 (ff:1..4-->>setY or not(ff:1..4-->>setY)) &  not(ff:1..4-->>setY & not(ff:1..4-->>setY))&
 (ff:1..4>+>setY or not(ff:1..4>+>setY)) &  not(ff:1..4>+>setY & not(ff:1..4>+>setY))&
 (ff:1..4>->setY or not(ff:1..4>->setY)) &  not(ff:1..4>->setY & not(ff:1..4>->setY))&
 (ff:1..4+->>setY or not(ff:1..4+->>setY)) &  not(ff:1..4+->>setY & not(ff:1..4+->>setY))&
 (ff:1..4>->>setY or not(ff:1..4>->>setY)) &  not(ff:1..4>->>setY & not(ff:1..4>->>setY))&
 (ff:1..4-->setY or not(ff:1..4-->setY)) &  not(ff:1..4-->setY & not(ff:1..4-->setY))&
 (ff:1..4+->setY or not(ff:1..4+->setY)) &  not(ff:1..4+->setY & not(ff:1..4+->setY))&

 (!xx.(xx:1..4 & xx:dom(ff) => ff(xx):ran(ff))) &

 (dom(ff) = {xx | xx: 1..4 & #yy.(yy:setY & xx|->yy:ff)}) & /* <-- problem if MAXINT<4 */
 (ran(ff) = {yy | yy: setY & #xx.(xx:1..4 & xx|->yy:ff)}) &



   (ff /\ gg /= {}  <=>   #ee.(ee:ff & ee:gg) )
   &
   ( ff /<: gg  <=>  #ee.(ee:ff & ee/:gg))
   &
   ( ff<<:gg <=>  (ff<:gg & #ee.(ee:gg & ee/:ff)))
   &
 /* ---------------------------------------- */

 /* some laws about reverse */
 (ff=gg <=> rev(ff)=rev(gg)) &
 (rev(ff) <: rev(gg) & rev(gg) <: rev(ff) => ff=gg) &
 (ff /= {} & rev(ff) <: rev(gg) => last(ff) = last(gg)) &
 (ff /= {}  =>
    first(rev(ff)) = last(ff) &
    last(rev(ff)) = first(ff) &
    rev(ff) = last(ff) -> rev(front(ff)) &
    rev(ff) = rev(tail(ff)) <- first(ff)
  ) &

 (ff=gg => (dom(ff)=dom(gg) & ran(ff)=ran(gg) & size(ff) = size(gg))) &

 ((ff=gg & ff/= []) => (tail(ff)=tail(gg) & front(ff)=front(gg))) &

 (ff/=[] => (first(ff) = last(rev(ff)) & last(ff) = first(rev(ff)))) &

 (ff: seq1(setY) <=> ff/=[]) &

 (ff: iseq(setY) <=>  card(ran(ff)) = size(ff)) &

 (ff: perm(setY) <=>  (ff: iseq(setY) & size(ff) = card(setY))) &

 (ff /=[] => (front(ff) <- last(ff) = ff)) &

 (ff /=[] => (first(ff) -> tail(ff) = ff)) &

 (conc([ ff, [y1]]) = ff<-y1)

 & ( (size(ff)>=2 & ff:1..4>+>setY) => ( !xx.(xx:1..4&xx:1..(size(ff)) => (( (ff/|\xx)/\(ff\|/xx) ) = [] ))))
 & ( (size(ff)>=2) => ( !xx.(xx:1..4&xx:1..(size(ff)) => (( (ff/|\xx)^(ff\|/xx) ) = ff ))))
 & ( (size(ff)>=2) => ( !xx.(xx:1..4&xx:1..(size(ff)) => (( (ff/|\xx) ) = ((1..xx)<|ff) ))))

 &


   /* Inclusion Properties from page 98 of B-Book (not complete) */
   id(dom(ff)) <: (ff; ff~) &
   id(ran(ff)) <: (ff~;ff) &
   ff[1..2 /\ {1}] <: ff[1..2] /\ ff[{1}] &
   ff[1..2] - ff[{1}] <: ff[(1..2) - {1}] &
   dom(ff /\ gg) <: dom(ff) /\ dom(gg) &
   dom(ff) - dom(gg) <: dom(ff-gg) &
   ran(ff /\ gg) <: ran(ff) /\ ran(gg) &
   ran(ff) - ran(gg) <: ran(ff-gg) &
   (ff /\ gg)[1..2] <: ff[1..2] /\ gg[1..2] &
   ff[1..2] - gg[1..2] <: (ff-gg) [1..2] &


   /* Inverse Properties from page 100 of B-Book (just a few) */
   (ff~)~ = ff &
   (ff ; (gg~))~ = ((gg~)~ ; ff~) &
   (1..2 <| ff)~ = ff~ |> 1..2 &
   (ff |> setY)~ = setY <| ff~ &
   (1..2 <<| ff)~ = ff~ |>> 1..2 &
   (ff |>> setY)~ = setY <<| ff~ &
   (ff <+ gg)~ = (ff~|>>dom(gg)) \/ gg~ &
   (ff || gg)~ = (ff~ || gg~) &
   (ff \/ gg)~ = ff~ \/ gg~ &
   (ff /\ gg)~ = ff~ /\ gg~ &
   (ff - gg)~ = ff~ - gg~ &


   /* Domain Properties from pages 100-101 of B-Book (not all) */
   (ff: 1..2 --> setY => (dom(ff) = 1..2)) &
   dom(ff~) = ran(ff) &
   dom(ff ; (gg~)) = ff~[dom(gg~)] &
   (ran(ff) <: dom(gg~) => dom(ff ; (gg~)) = dom(ff) ) &
   dom(1..2 <| ff) = 1..2 /\ dom(ff) &
   dom(ff |> setY) = ff~[setY] &
   dom(1..2 <<| ff) = dom(ff)-(1..2) &
   (ff: INTEGER +-> setY => dom(ff |>> setY) = dom(ff) - ff~[setY]) &
   dom(ff<+gg) = dom(ff) \/ dom(gg) &
   dom(ff><gg) = dom(ff) /\ dom(gg) &
   dom(ff||gg) = dom(ff) * dom(gg) &
   dom(ff \/ gg) = dom(ff) \/ dom(gg) &
   (ff:INTEGER +-> setY & gg:INTEGER +-> setY &
     dom(ff) <| gg = dom(gg) <| ff
    => (dom(ff /\ gg) = dom(ff) /\ dom(gg) &
       dom(ff - gg) = dom(ff) - dom(gg))
    ) &

   /* Range Properties from pages 102-103 of B-Book (not all) */
   (ff: INTEGER +->> setY => (ran(ff) = setY)) &
   ran(ff~) = dom(ff) &
   ran((ff ; (gg~))) = (gg~)[ran(ff)] &
   (dom(gg~) <: ran(ff) => ran((ff ; (gg~))) = ran(gg~)) /* error in B-Book: should be ran(q) not ran(p) */ &
   ran(1..2 <| ff) = ff[1..2] &
   ran(ff |> setY) = ran(ff) /\ setY &
   (ff~:setY +-> 1..2 => ran(1..2 <<| ff) = ran(ff)-ff[1..2]) &
   ran(ff |>> setY) = ran(ff) - setY &
   ran(ff <+ gg) = ran(dom(gg)<<|ff) \/ ran(gg) &
   ran(ff><gg) = (ff~ ; gg) &
   ran(ff||gg) = ran(ff)*ran(gg) &
   ran(ff \/ gg) = ran(ff) \/ ran(gg) &
   (ff~:setY +-> INTEGER & gg~:setY +-> INTEGER &
     ff |> ran(gg) = gg |> ran(ff)
    => (ran(ff /\ gg) = ran(ff) /\ ran(gg) &
        ran(ff - gg) = ran(ff) - ran(gg))) &

   /* Definitions from page 179 of B-Book (not yet complete) */
   size(ff) = card(dom(ff)) &
   ff ^ [] = ff &
   ff ^ (gg ^ ff) = (ff ^ gg) ^ ff &
   size(ff ^ gg) = size(ff) + size(gg) &

   size(rev(ff)) = size(ff) &
   rev(rev(ff)) = ff &

   /* Definitions from page 181 of B-Book */
   !n.(n:0..size(ff) =>
        ( ff /|\ n = (1..n)<| ff))
   // &
   //!n.(n:0..size(ff) =>
   //     ( ff \|/ n = ((%x.(x:INTEGER|x+n)) ; ((1..n)<<|ff)) ))
    &
   (ff:seq1(setY) =>
      ( first(ff) = ff(1) &
        last(ff) = ff(size(ff)) &
        tail(ff) = ff \|/ 1 &
        front(ff) = ff /|\ (size(ff)-1) ) )

INITIALISATION

 ff,gg := [],[]

OPERATIONS
 //take_ff = PRE ff/=[] THEN ANY xx WHERE xx:1..size(ff) THEN ff := ff/|\xx END END;
 //drop_ff = PRE ff/=[] THEN ANY xx WHERE xx:1..size(ff) THEN ff := ff\|/xx END END;

 ispartinj = PRE ff:1..4>+>setY THEN skip END;
 isnotpartinj = PRE not(ff:1..4>+>setY) THEN skip END;

 /* ispf = PRE ff: 1..4+->setY THEN skip END;
 nispf = PRE not(ff: 1..4+->setY) THEN skip END;
 istf = PRE ff: 1..4-->setY THEN skip END;
 nistf = PRE not(ff: 1..4-->setY) THEN skip END;
 is_total = PRE dom(ff)=1..4 THEN skip END;
 df <-- domff = BEGIN df := dom(ff) END;
 n1 <-- n1 = BEGIN n1 := 1..4 END; */

 /*hh<--test =   hh := (dom(gg)<|gg);
 hi<--test2 =   hi := ({x,y | x:dom(gg)&y:ran(gg)});*/

 ispartialsurj = PRE ff : 1..4 +->> setY THEN skip END;
 isnotpartialsurj = PRE not(ff : 1..4 +->> setY) THEN skip END;

 add_ff(xx) = PRE xx:setY & size(ff)<4 THEN
                    ff := ff ^ [xx]
              END;
 tail_ff = PRE ff/=[] THEN ff := tail(ff) END;
 revff = BEGIN ff := rev(ff) END;
 add_gg(xx) = PRE xx:setY & size(gg)<3 THEN
                    gg := gg ^ [xx]
              END;
 x <-- range_violated(r1,r2) = PRE r1=ran(ff) & r2<:setY &  /* needed for type inference */
                    r2= {yy | yy: setY & #xx.(xx:1..4 & xx|->yy:ff)} THEN
          x := bool(r1=r2) END;
 range1(r1) = PRE r1 = ran(ff) THEN skip END;
 range2(r2) = PRE r2<: setY & r2= {yy | yy: setY & #xx.(xx:1..4 & xx|->yy:ff)} THEN skip END

END
