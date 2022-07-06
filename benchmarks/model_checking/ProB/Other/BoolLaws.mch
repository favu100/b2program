MACHINE BoolLaws
CONSTANTS
    TT,FF
PROPERTIES
    FF:BOOL & FF=FALSE & TT:BOOL & TT=TRUE
VARIABLES
    PP, QQ, RR
DEFINITIONS
  pt == (PP=TRUE);
  qt == (QQ=TRUE);
  rt == (RR=TRUE);
  tr == (TT=TT);
  fail == (TT=FF);
INVARIANT
   PP:BOOL & QQ:BOOL & RR:BOOL &
    (((PP=TRUE) & (QQ=TRUE)) <=> ((QQ=TRUE) & (PP=TRUE)))&
    ((PP=TRUE) or not((PP=TRUE))) &
    not((PP=TRUE) & not((PP=TRUE))) &
    (((PP=TRUE) & bfalse) <=> bfalse) &
    (((PP=TRUE) or bfalse) <=> (PP=TRUE)) &
    (((PP=TRUE) or btrue) <=> btrue) &
    (((PP=TRUE) & btrue) <=> (PP=TRUE)) &
    ((((PP=TRUE) => (QQ=TRUE)) & ((QQ=TRUE) => (RR=TRUE))) => ((PP=TRUE) => (RR=TRUE))) &
    ((((PP=TRUE) <=> (QQ=TRUE)) & ((QQ=TRUE) <=> (RR=TRUE))) => ((PP=TRUE) <=> (RR=TRUE))) &
    (((PP=TRUE) <=> (QQ=TRUE)) => ((PP=TRUE) => (QQ=TRUE))) &
    (((PP=TRUE) <=> (QQ=TRUE)) => ((QQ=TRUE) => (PP=TRUE))) &
    (((PP=TRUE) <=> (QQ=TRUE)) <=> (((PP=TRUE) => (QQ=TRUE)) & ((QQ=TRUE) => (PP=TRUE)))) &
   (((PP=TRUE) or (QQ=TRUE)) <=> ((QQ=TRUE) or (PP=TRUE))) &
   (((PP=TRUE)) <=> (not(not((PP=TRUE))))) &
    btrue &
    not(bfalse)
INITIALISATION

    PP,QQ,RR := FALSE,FALSE,FALSE

OPERATIONS
 set_pp = BEGIN PP:=TRUE END;
 set_qq = BEGIN QQ:=TRUE END;
 set_rr = BEGIN RR:=TRUE END

END

