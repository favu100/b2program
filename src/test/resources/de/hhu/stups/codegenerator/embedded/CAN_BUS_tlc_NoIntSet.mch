MACHINE CAN_BUS_tlc_NoIntSet

SETS
  T1state={T1_EN,T1_CALC,T1_SEND,T1_WAIT};
  T2mode={T2MODE_SENSE,T2MODE_TRANSMIT,T2MODE_RELEASE};
  T2state={T2_EN,T2_RCV,T2_PROC,T2_CALC,T2_SEND,T2_WAIT,T2_RELEASE};
  T3state={T3_READY,T3_WRITE,T3_RELEASE,T3_READ,T3_PROC,T3_WAIT};
  EINT={NEG_ONE,ZERO,ONE,TWO,THREE,FOUR,FIVE}
VARIABLES
  BUSpriority,
  BUSvalue,
  BUSwrite,
  T1_state,
  T1_timer,
  T1_writevalue,
  T2_mode,
  T2_readpriority,
  T2_readvalue,
  T2_state,
  T2_timer,
  T2_writevalue,
  T2v,
  T3_enabled,
  T3_evaluated,
  T3_readpriority,
  T3_readvalue,
  T3_state,
  NATSET
INVARIANT
   T2v : EINT &
   T3_evaluated : BOOL &
   T3_enabled : BOOL &
   T1_state : T1state &
   T2_state : T2state &
   T3_state : T3state &
   T1_writevalue : EINT &
   T2_writevalue : EINT &
   T2_readvalue : EINT &
   T1_timer : NATURAL &
   T2_timer : NATURAL &
   T2_mode : T2mode &
   BUSvalue : EINT &
   BUSpriority : NATSET &
   T3_readvalue : EINT &
   T3_readpriority : NATSET &
   T2_readpriority : NATSET &
   BUSwrite : NATSET +-> EINT &
   BUSwrite /= {} &
   ZERO : dom(BUSwrite)
INITIALISATION
         T2v := ZERO
      ||
         T3_evaluated := TRUE
      ||
         T3_enabled := TRUE
      ||
         T1_state := T1_EN
      ||
         T2_state := T2_EN
      ||
         T3_state := T3_READY
      ||
         T1_writevalue := ZERO
      ||
         T2_writevalue := ZERO
      ||
         T2_readvalue := ZERO
      ||
         T2_readpriority := ZERO
      ||
         T3_readvalue := ZERO
      ||
         T3_readpriority := ZERO
      ||
         T1_timer := 2
      ||
         T2_timer := 3
      ||
         BUSwrite := {ZERO |-> ZERO}
      ||
         BUSvalue := ZERO
      ||
         BUSpriority := ZERO
      ||
         T2_mode := T2MODE_SENSE
      ||
         NATSET := {ZERO,ONE,TWO,THREE,FOUR,FIVE}
OPERATIONS
  T1Evaluate =
    PRE
        /* @grd1 */ T1_timer = 0
      & /* @grd3 */ T1_state = T1_EN
    THEN
         T1_timer := 0
      ||
         T1_state := T1_CALC
    END;
  T1Calculate(p) =
    PRE
		p : {NEG_ONE, ZERO, ONE, TWO, THREE} &
        /* @grd2 */ T1_state = T1_CALC
    THEN
         T1_writevalue := p
      ||
         T1_state := T1_SEND
    END;
  T1SendResult(ppriority,pv) =
    PRE
        /* @grd2 */ ppriority = THREE
      & /* @grd1 */ pv = T1_writevalue
      & /* @grd3 */ T1_state = T1_SEND
    THEN
         BUSwrite := BUSwrite <+ {ppriority |-> pv}
      ||
         T1_state := T1_WAIT
    END;
  T1Wait(pt) =
    PRE
        /* @grd1 */ pt = 2
      & /* @grd2 */ T1_state = T1_WAIT
    THEN
         T1_timer := pt
      ||
         T1_state := T1_EN
    END;
  T2Evaluate =
    PRE
        /* @grd1 */ T2_timer = 0
      & /* @grd3 */ T2_state = T2_EN
    THEN
         T2_timer := 0
      ||
         T2_state := T2_RCV
    END;
  T2ReadBus(ppriority,pv) =
    PRE
        /* @grd2 */ ppriority = BUSpriority
      & /* @grd1 */ pv = BUSvalue
      & /* @grd3 */ T2_state = T2_RCV
    THEN
         T2_readvalue := pv
      ||
         T2_readpriority := ppriority
      ||
         T2_state := T2_PROC
    END;
  T2Reset =
    PRE
        /* @grd1 */ T2_readpriority = FOUR
      & /* @grd2 */ T2_state = T2_PROC
    THEN
         T2_writevalue := T2v
      ||
         T2v := ZERO
      ||
         T2_state := T2_SEND
      ||
         T2_mode := T2MODE_TRANSMIT
    END;
  T2Complete =
    PRE
        /* @grd2 */ T2_state = T2_PROC
      & /* @grd1 */ T2_readpriority = FIVE
      & /* @grd3 */ T2_mode = T2MODE_TRANSMIT
    THEN
         T2_state := T2_RELEASE
      ||
         T2_mode := T2MODE_SENSE
    END;
  T2ReleaseBus(ppriority) =
    PRE
        /* @grd1 */ ppriority = T2_readpriority
      & /* @grd3 */ ppriority : dom(BUSwrite)
      & /* @grd4 */ T2_state = T2_RELEASE
    THEN
         BUSwrite := {ppriority} <<| BUSwrite
      ||
         T2_state := T2_WAIT
    END;

  T2Calculate =
    PRE
        /* @grd1 */ T2_readpriority = THREE
      & /* @grd2 */ T2_state = T2_PROC
    THEN
         T2v := T2_readvalue
      ||
         T2_state := T2_WAIT
    END;

  T2WriteBus(ppriority,pv) =
    PRE
        /* @grd2 */ ppriority = FIVE
      & /* @grd1 */ pv = T2_writevalue
      & /* @grd3 */ T2_state = T2_SEND
    THEN
         BUSwrite := BUSwrite <+ {ppriority |-> pv}
      ||
         T2_state := T2_WAIT
    END;

  T2Wait(pt) =
    PRE
        /* @grd1 */ pt = 3
      & /* @grd2 */ T2_state = T2_WAIT
    THEN
         T2_timer := pt
      ||
         T2_state := T2_EN
    END;

  T3Initiate =
    PRE
        /* @grd1 */ T3_state = T3_READY
      & /* @grd2 */ T3_evaluated = FALSE
      & /* @grd3 */ T3_enabled = TRUE
    THEN
         T3_state := T3_WRITE
      ||
         T3_enabled := FALSE
    END;

  T3Evaluate =
    PRE
        /* @grd1 */ T3_state = T3_READY
      & /* @grd2 */ T3_evaluated = FALSE
      & /* @grd3 */ T3_enabled = FALSE
    THEN
         T3_state := T3_READ
    END;

  T3writebus(ppriority,pv) =
    PRE
         /* @grd2 */ ppriority = FOUR
      &  /* @grd1 */ pv = ZERO
      & /* @grd3 */ T3_state = T3_WRITE
    THEN
         BUSwrite := BUSwrite <+ {ppriority |-> pv}
      ||
         T3_state := T3_WAIT
    END;

  T3Read(ppriority,pv) =
    PRE
        /* @grd2 */ ppriority = BUSpriority
      & /* @grd1 */ pv = BUSvalue
      & /* @grd4 */ T3_state = T3_READ
    THEN
         T3_readvalue := pv
      ||
         T3_readpriority := ppriority
      ||
         T3_state := T3_PROC
    END;

  T3Poll =
    PRE
        /* @grd1 */ T3_readpriority : EINT \ {FIVE}
      & /* @grd2 */ T3_state = T3_PROC
    THEN
         T3_state := T3_WAIT
    END;

  T3ReleaseBus(ppriority) =
    PRE
        /* @grd1 */ ppriority = FOUR
      & /* @grd2 */ T3_readpriority = FIVE
      & /* @grd3 */ T3_state = T3_PROC
    THEN
         BUSwrite := {ppriority} <<| BUSwrite
      ||
         T3_state := T3_RELEASE
    END;

  T3Wait =
    PRE
        /* @grd1 */ T3_state = T3_WAIT
    THEN
         T3_state := T3_READY
      ||
         T3_evaluated := TRUE
    END;

  T3ReEnableWait =
    PRE
        /* @grd1 */ T3_state = T3_RELEASE
    THEN
         T3_state := T3_READY
      ||
         T3_evaluated := TRUE
      ||
         T3_enabled := TRUE
    END;

  Update(pmax) =
    PRE
        /* @grd1 */ pmax = IF FIVE : dom(BUSwrite) THEN FIVE
                           ELSE IF FOUR : dom(BUSwrite) THEN FOUR
                           ELSE IF THREE : dom(BUSwrite) THEN THREE
                           ELSE IF TWO : dom(BUSwrite) THEN TWO
                           ELSE IF ONE : dom(BUSwrite) THEN ONE ELSE ZERO END END END END END/* max(dom(BUSwrite)) */
      & /* @grd2 */ T1_timer > 0
      & /* @grd3 */ T2_timer > 0
      & (/* @grd4 */ T3_enabled = TRUE or T3_evaluated = TRUE)
    THEN
         BUSvalue := BUSwrite(pmax)
      ||
         BUSpriority := pmax
      ||
         T1_timer := T1_timer - 1
      ||
         T2_timer := T2_timer - 1
      ||
         T3_evaluated := FALSE
    END

END