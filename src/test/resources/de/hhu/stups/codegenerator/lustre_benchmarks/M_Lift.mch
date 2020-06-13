MACHINE M_Lift

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_exec_up, var_exec_down, var_floor

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_floor : LUSTRE_INT) & ((var_exec_down : LUSTRE_BOOL) & ((var_exec_up : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_floor /= {})) & (((is_initialisation = FALSE) => (var_exec_down /= {})) & ((is_initialisation = FALSE) => (var_exec_up /= {})))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_exec_up := {}; 
    var_exec_down := {}; 
    var_floor := {}


OPERATIONS 

    clock_step(param_up, param_down) = 
        PRE
            ((param_up : LUSTRE_BOOL_NOT_NIL) & (param_down : LUSTRE_BOOL_NOT_NIL))
        THEN
            VAR var_up, var_down, var_old_floor IN
                var_up := param_up; 
                var_down := param_down; 
                var_old_floor := l_fby_integer(is_initialisation |-> {ref |-> 0} |-> var_floor); 
                var_exec_up := l_and(var_up |-> l_less(var_old_floor |-> {ref |-> 100})); 
                var_exec_down := l_and(var_down |-> l_greater(var_old_floor |-> {ref |-> 0})); 
                var_floor := l_ite_integer(var_exec_up |-> l_plus(var_old_floor |-> {ref |-> 1}) |-> l_ite_integer(var_exec_down |-> l_minus(var_old_floor |-> {ref |-> 1}) |-> var_old_floor)); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END



END

