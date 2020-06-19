MACHINE M_When

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_millisecond, var_res, var_millisecond, var_syn_second

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_millisecond : BOOL) & ((var_millisecond : LUSTRE_BOOL) & ((var_res : LUSTRE_BOOL) & ((var_syn_second : LUSTRE_BOOL) & ((is_initialisation_millisecond = FALSE) => (var_res /= {}))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_millisecond := TRUE; 
    var_res := {}; 
    var_millisecond := {}; 
    var_syn_second := {}


OPERATIONS 

    clock_step(param_millisecond) = 
        PRE
            (param_millisecond : LUSTRE_BOOL_NOT_NIL)
        THEN
            VAR var_tmp_0 IN
                var_millisecond := param_millisecond; 
                PRE (var_millisecond /= {}) THEN skip END; 
                var_tmp_0 := {ref |-> TRUE}; 
                IF (var_millisecond = {ref |-> TRUE}) THEN 
                    var_syn_second := var_tmp_0
                END; 
                IF (var_millisecond = {ref |-> TRUE}) THEN 
                    var_res := var_syn_second
                END; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var_millisecond = {ref |-> TRUE}) THEN 
                    is_initialisation_millisecond := FALSE
                END

            END

        END;

    out <-- getRes = BEGIN out := var_res END



END

/*
tmp_0: true
*/
