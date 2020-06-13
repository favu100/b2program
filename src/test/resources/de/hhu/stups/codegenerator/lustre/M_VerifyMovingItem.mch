//generated from Lustre
//taken from Production cell in Lustre, Leszek Holenderski

MACHINE M_VerifyMovingItem

INCLUDES Node_32.M_redge, Node_31.M_redge, Node_26.M_sustain, Node_30.M_fedge, Node_29.M_fedge, Node_28.M_redge, Node_27.M_redge

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_OK, var_tmp_0, var_tmp_1, var_TryToMove1, var_TryToMove2, var_start1, var_start2, var_stop, var_moving, var_MaySafelyMove

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_TryToMove2 : LUSTRE_BOOL) & ((var_TryToMove1 : LUSTRE_BOOL) & ((var_MaySafelyMove : LUSTRE_BOOL) & ((var_OK : LUSTRE_BOOL) & ((var_tmp_1 : LUSTRE_BOOL) & ((var_tmp_0 : LUSTRE_BOOL) & ((var_moving : LUSTRE_BOOL) & ((var_stop : LUSTRE_BOOL) & ((var_start2 : LUSTRE_BOOL) & ((var_start1 : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_OK /= {})) & ((is_initialisation = FALSE) => (var_OK = {ref |-> TRUE})))))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_OK := {}; 
    var_tmp_0 := {}; 
    var_tmp_1 := {}; 
    var_TryToMove1 := {}; 
    var_TryToMove2 := {}; 
    var_start1 := {}; 
    var_start2 := {}; 
    var_stop := {}; 
    var_moving := {}; 
    var_MaySafelyMove := {}


OPERATIONS 

    clock_step(param_MaySafelyMove, param_TryToMove1, param_TryToMove2) = 
        PRE
            ((param_MaySafelyMove : LUSTRE_BOOL_NOT_NIL) & ((param_TryToMove1 : LUSTRE_BOOL_NOT_NIL) & (param_TryToMove2 : LUSTRE_BOOL_NOT_NIL)))
        THEN
            VAR hvar_tmp_0, hvar_tmp_1, var_MayMove1, var_MayMove2 IN
                hvar_tmp_0 := var_tmp_0; 
                hvar_tmp_1 := var_tmp_1; 
                var_MaySafelyMove := param_MaySafelyMove; 
                var_TryToMove1 := param_TryToMove1; 
                var_TryToMove2 := param_TryToMove2; 
                var_tmp_1 := l_not(var_TryToMove1); 
                var_tmp_0 := l_not(var_TryToMove2); 
                var_MayMove1 := l_and(var_TryToMove1 |-> var_MaySafelyMove); 
                var_MayMove2 := l_and(var_TryToMove2 |-> var_MaySafelyMove); 
                Node_27.clock_step(l_and(var_MayMove1 |-> l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> hvar_tmp_0))); 
                var_start1 := Node_27.var_r; 
                Node_28.clock_step(l_and(var_MayMove2 |-> l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> hvar_tmp_1))); 
                var_start2 := Node_28.var_r; 
                Node_29.clock_step(var_MayMove1); 
                Node_30.clock_step(var_MayMove2); 
                var_stop := l_or(Node_29.var_f |-> Node_30.var_f); 
                Node_26.clock_step(l_and(var_start1 |-> var_start2), var_stop); 
                var_moving := Node_26.var_s; 
                Node_31.clock_step(var_TryToMove1); 
                Node_32.clock_step(var_TryToMove2); 
                var_OK := l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> l_ite_boolean(l_or(l_not(Node_31.var_r) |-> l_not(Node_32.var_r)) |-> l_and(l_and(l_or(l_or(l_and(l_not(var_start1) |-> l_not(var_start2)) |-> l_and(l_not(var_start2) |-> l_not(var_stop))) |-> l_and(l_not(var_start1) |-> l_not(var_stop))) |-> l_not(l_and(l_and(var_start1 |-> var_start2) |-> var_stop))) |-> l_ite_boolean(var_moving |-> var_MaySafelyMove |-> {ref |-> TRUE})) |-> {ref |-> TRUE})); 
                SELECT ((assert_ok = TRUE) & ((Node_32.assert_ok = TRUE) & ((Node_31.assert_ok = TRUE) & ((Node_26.assert_ok = TRUE) & ((Node_30.assert_ok = TRUE) & ((Node_29.assert_ok = TRUE) & ((Node_28.assert_ok = TRUE) & (Node_27.assert_ok = TRUE)))))))) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

    out <-- getOK = BEGIN out := var_OK END



END

/*
Node_26: sustain((start1 and start2), stop)
Node_27: redge((MayMove1 and (true -> pre(not(TryToMove2)))))
Node_28: redge((MayMove2 and (true -> pre(not(TryToMove1)))))
Node_29: fedge(MayMove1)
Node_30: fedge(MayMove2)
Node_31: redge(TryToMove1)
Node_32: redge(TryToMove2)
tmp_0: not(TryToMove2)
tmp_1: not(TryToMove1)
*/
