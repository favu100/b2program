MACHINE M_Clock12

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock, var_res, var_clock, var_var1, var_var2

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock : BOOL) & ((var_var1 : LUSTRE_INT) & ((var_clock : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((var_var2 : LUSTRE_INT) & ((is_initialisation_clock = FALSE) => (var_res /= {})))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock := TRUE; 
    var_res := {}; 
    var_clock := {}; 
    var_var1 := {}; 
    var_var2 := {}


OPERATIONS 

    clock_step(param_clock, param_var1) = 
        PRE
            ((param_clock : LUSTRE_BOOL_NOT_NIL) & (param_var1 : LUSTRE_INT_NOT_NIL))
        THEN
            VAR var_tmp_0 IN
                var_clock := param_clock; 
                PRE (var_clock /= {}) THEN skip END; 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    var_var1 := param_var1
                END; 
                var_tmp_0 := {ref |-> 1}; 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    var_var2 := l_plus(var_var1 |-> var_tmp_0)
                END; 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    var_res := l_plus(var_var1 |-> var_var2)
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
tmp_0: 1
*/
