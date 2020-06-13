MACHINE M_microbenchmarks_ite_integer

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_res : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_res /= {})))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x, param_y, param_z) = 
        PRE
            ((param_x : LUSTRE_BOOL_NOT_NIL) & ((param_y : LUSTRE_INT_NOT_NIL) & (param_z : LUSTRE_INT_NOT_NIL)))
        THEN
            VAR var_x, var_y, var_z IN
                var_x := param_x; 
                var_y := param_y; 
                var_z := param_z; 
                var_res := l_ite_integer(var_x |-> var_y |-> var_z); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END



END

