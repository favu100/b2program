MACHINE M_microbenchmarks_when_integer

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_y, is_initialisation, var_res, var_y

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_y : BOOL) & ((is_initialisation : BOOL) & ((var_y : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((is_initialisation_y = FALSE) => (var_res /= {})))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_y := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_y := {}


OPERATIONS 

    clock_step(param_y, param_x) = 
        PRE
            ((param_y : LUSTRE_BOOL_NOT_NIL) & (param_x : LUSTRE_INT_NOT_NIL))
        THEN
            VAR var_x IN
                var_y := param_y; 
                PRE (var_y /= {}) THEN skip END; 
                var_x := param_x; 
                IF (var_y = {ref |-> TRUE}) THEN 
                    var_res := var_x
                END; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                IF (var_y = {ref |-> TRUE}) THEN 
                    is_initialisation_y := FALSE
                END; 
                is_initialisation := FALSE

            END

        END



END

