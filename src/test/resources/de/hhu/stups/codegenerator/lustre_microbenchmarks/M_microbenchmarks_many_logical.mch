MACHINE M_microbenchmarks_many_logical

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_res : LUSTRE_BOOL) & ((is_initialisation = FALSE) => (var_res /= {})))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x, param_y) = 
        PRE
            ((param_x : LUSTRE_BOOL_NOT_NIL) & (param_y : LUSTRE_BOOL_NOT_NIL))
        THEN
            VAR var_x, var_y IN
                var_x := param_x; 
                var_y := param_y; 
                var_res := l_or(l_or(l_and(l_or(l_not(var_x) |-> var_x) |-> l_or(l_not(var_y) |-> var_y)) |-> l_and(var_x |-> var_y)) |-> l_and(l_not(var_x) |-> l_not(var_y))); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END



END

