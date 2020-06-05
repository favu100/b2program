MACHINE M_Clock6

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_clock, var_res, var_clock, var_val

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_clock : BOOL) & ((var_val : LUSTRE_INT) & ((var_clock : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((is_initialisation_clock = FALSE) => (var_res /= {})))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_clock := TRUE; 
    var_res := {}; 
    var_clock := {}; 
    var_val := {}


OPERATIONS 

    clock_step(param_clock, param_val) = 
        PRE
            ((param_clock : LUSTRE_BOOL_NOT_NIL) & (param_val : LUSTRE_INT_NOT_NIL))
        THEN
            VAR hvar_val IN
                hvar_val := var_val; 
                var_clock := param_clock; 
                PRE (var_clock /= {}) THEN skip END; 
                IF (var_clock = {ref |-> TRUE}) THEN
                    var_val := param_val
                END;
                IF (var_clock = {ref |-> TRUE}) THEN
                    var_res := hvar_val
                END;
                SELECT (assert_ok = TRUE) THEN skip END;
                IF (var_clock = {ref |-> TRUE}) THEN
                    is_initialisation_clock := FALSE
                END

            END

        END;


     out <-- getRes = BEGIN out := var_res END



END

