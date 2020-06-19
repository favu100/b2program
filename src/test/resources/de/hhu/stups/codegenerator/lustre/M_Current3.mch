MACHINE M_Current3

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock, var_res, var_clock, var_tmp_1

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock : BOOL) & ((var_clock : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((var_tmp_1 : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_res /= {}))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock := TRUE; 
    var_res := {}; 
    var_clock := {}; 
    var_tmp_1 := {}


OPERATIONS 

    clock_step(param_clock) = 
        PRE
            (param_clock : LUSTRE_BOOL_NOT_NIL)
        THEN
            VAR var_tmp_0 IN
                var_clock := param_clock; 
                PRE (var_clock /= {}) THEN skip END; 
                var_tmp_0 := {ref |-> 1}; 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    var_tmp_1 := var_tmp_0
                END; 
                var_res := var_tmp_1; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    is_initialisation_clock := FALSE
                END

            END

        END;

    out <-- getRes = BEGIN out := var_res END



END

/*
tmp_0: 1
tmp_1: (1 when clock)
*/
