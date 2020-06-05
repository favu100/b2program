MACHINE M_When4

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock, var_res, var_tmp_0, var_clock

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock : BOOL) & ((var_clock : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & ((is_initialisation_clock = FALSE) => (var_res /= {}))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock := TRUE; 
    var_res := {}; 
    var_tmp_0 := {}; 
    var_clock := {}


OPERATIONS 

    clock_step(param_clock) = 
        PRE
            (param_clock : LUSTRE_BOOL_NOT_NIL)
        THEN
            VAR var_a, var_b IN
                var_clock := param_clock; 
                PRE (var_clock /= {}) THEN skip END; 
                var_a := {ref |-> 1}; 
                var_b := {ref |-> 2}; 
                var_tmp_0 := l_fby_integer(is_initialisation |-> var_a |-> var_b); 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    var_res := var_tmp_0
                END; 
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
tmp_0: (a -> b)
*/
