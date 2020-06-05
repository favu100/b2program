MACHINE M_AssertionClock

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_clock, is_initialisation, var_clock, var_res, var_val

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_clock : BOOL) & ((is_initialisation : BOOL) & ((var_val : LUSTRE_BOOL) & ((var_clock : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_res /= {}))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_clock := TRUE; 
    is_initialisation := TRUE; 
    var_clock := {}; 
    var_res := {}; 
    var_val := {}


OPERATIONS 

    clock_step(param_clock, param_val) = 
        PRE
            ((param_clock : LUSTRE_BOOL_NOT_NIL) & (param_val : LUSTRE_BOOL_NOT_NIL))
        THEN
            var_clock := param_clock; 
            PRE (var_clock /= {}) THEN skip END; 
            var_val := param_val; 
            PRE (var_val /= {}) THEN skip END; 
            assert_ok := bool(((assert_ok = TRUE) & (var_val = {ref |-> TRUE}))); 
            var_res := {ref |-> 10}; 
            SELECT (assert_ok = TRUE) THEN skip END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                is_initialisation_clock := FALSE
            END; 
            is_initialisation := FALSE

        END;

    out <-- getRes = BEGIN out := var_res END



END

