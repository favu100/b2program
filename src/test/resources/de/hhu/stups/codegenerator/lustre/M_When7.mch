MACHINE M_When7

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock1, is_initialisation_res1, var_res2, var_clock1, var_tmp_1, var_res1

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock1 : BOOL) & ((is_initialisation_res1 : BOOL) & ((var_clock1 : LUSTRE_BOOL) & ((var_res2 : LUSTRE_INT) & ((var_res1 : LUSTRE_BOOL) & ((var_tmp_1 : LUSTRE_INT) & (((is_initialisation_res1 = FALSE) => (var_res2 /= {})) & ((is_initialisation_clock1 = FALSE) => (var_res1 /= {})))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock1 := TRUE; 
    is_initialisation_res1 := TRUE; 
    var_res2 := {}; 
    var_clock1 := {}; 
    var_tmp_1 := {}; 
    var_res1 := {}


OPERATIONS 

    clock_step(param_val, param_clock1) = 
        PRE
            ((param_val : LUSTRE_BOOL_NOT_NIL) & (param_clock1 : LUSTRE_BOOL_NOT_NIL))
        THEN
            VAR var_val, var_tmp_0 IN
                var_val := param_val; 
                var_clock1 := param_clock1; 
                PRE (var_clock1 /= {}) THEN skip END; 
                var_tmp_0 := {ref |-> 0}; 
                IF (var_clock1 = {ref |-> TRUE}) THEN 
                    var_res1 := var_val; 
                    PRE (var_res1 /= {}) THEN skip END

                END; 
                IF (var_clock1 = {ref |-> TRUE}) THEN 
                    var_tmp_1 := var_tmp_0
                END; 
                IF ((var_clock1 = {ref |-> TRUE}) & (var_res1 = {ref |-> TRUE})) THEN 
                    var_res2 := var_tmp_1
                END; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var_clock1 = {ref |-> TRUE}) THEN 
                    is_initialisation_clock1 := FALSE
                END; 
                IF ((var_clock1 = {ref |-> TRUE}) & (var_res1 = {ref |-> TRUE})) THEN 
                    is_initialisation_res1 := FALSE
                END

            END

        END;

    out <-- getRes1 = BEGIN out := var_res1 END;
    out <-- getRes2 = BEGIN out := var_res2 END



END

/*
tmp_0: 0
tmp_1: (0 when clock1)
*/
