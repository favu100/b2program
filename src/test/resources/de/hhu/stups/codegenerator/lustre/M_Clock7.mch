MACHINE M_Clock7

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_clock1, is_initialisation, is_initialisation_clock2, is_initialisation_clock3, var_res, var_val, var_clock1, var_tmp_0, var_clock2, var_tmp_1, var_clock3

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_clock1 : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock2 : BOOL) & ((is_initialisation_clock3 : BOOL) & ((var_clock3 : LUSTRE_BOOL) & ((var_clock2 : LUSTRE_BOOL) & ((var_clock1 : LUSTRE_BOOL) & ((var_val : LUSTRE_INT) & ((var_res : LUSTRE_INT) & ((var_tmp_1 : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & ((is_initialisation_clock3 = FALSE) => (var_res /= {}))))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_clock1 := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock2 := TRUE; 
    is_initialisation_clock3 := TRUE; 
    var_res := {}; 
    var_val := {}; 
    var_clock1 := {}; 
    var_tmp_0 := {}; 
    var_clock2 := {}; 
    var_tmp_1 := {}; 
    var_clock3 := {}


OPERATIONS 

    clock_step(param_val, param_clock1, param_clock2, param_clock3) =
        PRE
            ((param_val : LUSTRE_INT_NOT_NIL) & ((param_clock1 : LUSTRE_BOOL_NOT_NIL) & ((param_clock2 : LUSTRE_BOOL_NOT_NIL) & (param_clock3 : LUSTRE_BOOL_NOT_NIL))))
        THEN
            var_val := param_val;
            var_clock1 := param_clock1;
            PRE (var_clock1 /= {}) THEN skip END;
            IF (var_clock1 = {ref |-> TRUE}) THEN
                var_clock2 := param_clock2;
                PRE (var_clock2 /= {}) THEN skip END

            END;
            IF ((var_clock1 = {ref |-> TRUE}) & (var_clock2 = {ref |-> TRUE})) THEN
                var_clock3 := param_clock3;
                PRE (var_clock3 /= {}) THEN skip END

            END;
            IF (var_clock1 = {ref |-> TRUE}) THEN
                var_tmp_0 := var_val
            END;
            IF ((var_clock1 = {ref |-> TRUE}) & (var_clock2 = {ref |-> TRUE})) THEN
                var_tmp_1 := var_tmp_0
            END;
            IF ((var_clock1 = {ref |-> TRUE}) & ((var_clock2 = {ref |-> TRUE}) & (var_clock3 = {ref |-> TRUE}))) THEN
                var_res := var_tmp_1
            END;
            SELECT (assert_ok = TRUE) THEN skip END;
            IF (var_clock1 = {ref |-> TRUE}) THEN
                is_initialisation_clock1 := FALSE
            END;
            is_initialisation := FALSE;
            IF ((var_clock1 = {ref |-> TRUE}) & (var_clock2 = {ref |-> TRUE})) THEN
                is_initialisation_clock2 := FALSE
            END;
            IF ((var_clock1 = {ref |-> TRUE}) & ((var_clock2 = {ref |-> TRUE}) & (var_clock3 = {ref |-> TRUE}))) THEN
                is_initialisation_clock3 := FALSE
            END

        END;



    out <-- getRes = BEGIN out := var_res END



END

/*
tmp_0: (val when clock1)
tmp_1: ((val when clock1) when clock2)
*/
