MACHINE M_Rbase_main

INCLUDES Node_15.M_MovingItem, Node_19.M_sustain, Node_18.M_sustain, Node_17.M_sustain, Node_16.M_sustain, Node_21.M_sustain, Node_20.M_sustain

SEES LibraryLustre

VARIABLES is_initialisation, var_Rleft, var_Rright, var_Rstop

INVARIANT ((var_Rstop : LUSTRE_BOOL) & ((var_Rright : LUSTRE_BOOL) & ((var_Rleft : LUSTRE_BOOL) & ((is_initialisation : BOOL) & (((is_initialisation = FALSE) => (var_Rstop /= {})) & (((is_initialisation = FALSE) => (var_Rright /= {})) & ((is_initialisation = FALSE) => (var_Rleft /= {}))))))))

INITIALISATION
    is_initialisation := TRUE;
    var_Rleft := {};
    var_Rright := {};
    var_Rstop := {}


OPERATIONS

    clock_step(param_ArmsMayPassPress, param_Rget1, param_Rput1, param_ToTable, param_ToPress1, param_Rget2, param_Rput2, param_ToDBelt, param_ToPress2) =
        PRE
            ((param_ArmsMayPassPress : LUSTRE_BOOL_NOT_NIL) & ((param_Rget1 : LUSTRE_BOOL_NOT_NIL) & ((param_Rput1 : LUSTRE_BOOL_NOT_NIL) & ((param_ToTable : LUSTRE_BOOL_NOT_NIL) & ((param_ToPress1 : LUSTRE_BOOL_NOT_NIL) & ((param_Rget2 : LUSTRE_BOOL_NOT_NIL) & ((param_Rput2 : LUSTRE_BOOL_NOT_NIL) & ((param_ToDBelt : LUSTRE_BOOL_NOT_NIL) & (param_ToPress2 : LUSTRE_BOOL_NOT_NIL)))))))))
        THEN
            VAR var_ArmsMayPassPress, var_Rget1, var_Rput1, var_ToTable, var_ToPress1, var_Rget2, var_Rput2, var_ToDBelt, var_ToPress2, var_left, var_right, var_BeforeFirstRput1 IN
                var_ArmsMayPassPress := param_ArmsMayPassPress;
                var_Rget1 := param_Rget1;
                var_Rput1 := param_Rput1;
                var_ToTable := param_ToTable;
                var_ToPress1 := param_ToPress1;
                var_Rget2 := param_Rget2;
                var_Rput2 := param_Rput2;
                var_ToDBelt := param_ToDBelt;
                var_ToPress2 := param_ToPress2;
                Node_20.clock_step(l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> var_Rput1), var_ToTable);
                var_right := Node_20.var_s;
                Node_21.clock_step(l_fby_boolean(is_initialisation |-> l_not(var_Rput1) |-> {ref |-> FALSE}), var_Rput1);
                var_BeforeFirstRput1 := Node_21.var_s;
                Node_16.clock_step(var_Rget1, var_ToPress2);
                Node_17.clock_step(var_Rput2, var_ToPress1);
                Node_18.clock_step(var_Rget2, var_ToDBelt);
                Node_19.clock_step(var_Rget1, var_ToPress1);
                var_left := l_or(l_or(l_or(Node_16.var_s |-> Node_17.var_s) |-> Node_18.var_s) |-> l_and(Node_19.var_s |-> var_BeforeFirstRput1));
                Node_15.clock_step(var_ArmsMayPassPress, var_left, var_right);
                var_Rleft := Node_15.var_start1;
                var_Rright := Node_15.var_start2;
                var_Rstop := Node_15.var_stop;
                is_initialisation := FALSE

            END

        END



END

/*
Node_15: MovingItem(ArmsMayPassPress, left, right)
Node_16: sustain(Rget1, ToPress2)
Node_17: sustain(Rput2, ToPress1)
Node_18: sustain(Rget2, ToDBelt)
Node_19: sustain(Rget1, ToPress1)
Node_20: sustain((true -> Rput1), ToTable)
Node_21: sustain((not(Rput1) -> false), Rput1)
*/
