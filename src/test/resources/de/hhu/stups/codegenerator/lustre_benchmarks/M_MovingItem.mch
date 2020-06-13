//generated from Lustre
//taken from Production cell in Lustre, Leszek Holenderski

MACHINE M_MovingItem

INCLUDES Node_5.M_fedge, Node_4.M_fedge, Node_3.M_redge, Node_2.M_redge

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_start1, var_start2, var_stop, var_tmp_0, var_tmp_1

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_stop : LUSTRE_BOOL) & ((var_start2 : LUSTRE_BOOL) & ((var_start1 : LUSTRE_BOOL) & ((var_tmp_1 : LUSTRE_BOOL) & (var_tmp_0 : LUSTRE_BOOL)))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_start1 := {}; 
    var_start2 := {}; 
    var_stop := {}; 
    var_tmp_0 := {}; 
    var_tmp_1 := {}


OPERATIONS 

    clock_step(param_MaySafelyMove, param_TryToMove1, param_TryToMove2) = 
        PRE
            ((param_MaySafelyMove : LUSTRE_BOOL) & ((param_TryToMove1 : LUSTRE_BOOL) & (param_TryToMove2 : LUSTRE_BOOL)))
        THEN
            VAR hvar_tmp_0, hvar_tmp_1, var_MaySafelyMove, var_TryToMove1, var_TryToMove2, var_MayMove1, var_MayMove2 IN
                hvar_tmp_0 := var_tmp_0; 
                hvar_tmp_1 := var_tmp_1; 
                var_MaySafelyMove := param_MaySafelyMove; 
                var_TryToMove1 := param_TryToMove1; 
                var_TryToMove2 := param_TryToMove2; 
                var_tmp_1 := l_not(var_TryToMove1); 
                var_tmp_0 := l_not(var_TryToMove2); 
                var_MayMove1 := l_and(var_TryToMove1 |-> var_MaySafelyMove); 
                var_MayMove2 := l_and(var_TryToMove2 |-> var_MaySafelyMove); 
                Node_2.clock_step(l_and(var_MayMove1 |-> l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> hvar_tmp_0))); 
                var_start1 := Node_2.var_r; 
                Node_3.clock_step(l_and(var_MayMove2 |-> l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> hvar_tmp_1))); 
                var_start2 := Node_3.var_r; 
                Node_4.clock_step(var_MayMove1); 
                Node_5.clock_step(var_MayMove2); 
                var_stop := l_or(Node_4.var_f |-> Node_5.var_f); 
                is_initialisation := FALSE

            END

        END



END

/*
Node_2: redge((MayMove1 and (true -> pre(not(TryToMove2)))))
Node_3: redge((MayMove2 and (true -> pre(not(TryToMove1)))))
Node_4: fedge(MayMove1)
Node_5: fedge(MayMove2)
tmp_0: not(TryToMove2)
tmp_1: not(TryToMove1)
*/
