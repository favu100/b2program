MACHINE M_When2

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_millisecond, var_res2, var_res1, var_millisecond, var_c

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_millisecond : BOOL) & ((var_c : LUSTRE_INT) & ((var_millisecond : LUSTRE_BOOL) & ((var_res1 : LUSTRE_INT) & ((var_res2 : LUSTRE_INT) & (((is_initialisation_millisecond = FALSE) => (var_res1 /= {})) & ((is_initialisation = FALSE) => (var_res2 /= {}))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_millisecond := TRUE; 
    var_res2 := {}; 
    var_res1 := {}; 
    var_millisecond := {}; 
    var_c := {}


OPERATIONS 

    clock_step(param_millisecond, param_c, param_a, param_b) = 
        PRE
            ((param_millisecond : LUSTRE_BOOL_NOT_NIL) & ((param_c : LUSTRE_INT_NOT_NIL) & ((param_a : LUSTRE_INT_NOT_NIL) & (param_b : LUSTRE_INT_NOT_NIL))))
        THEN
            VAR var_a, var_b, var_tmp_0 IN
                var_millisecond := param_millisecond; 
                PRE (var_millisecond /= {}) THEN skip END; 
                IF (var_millisecond = {ref |-> TRUE}) THEN 
                    var_c := param_c
                END; 
                var_a := param_a; 
                var_b := param_b; 
                var_tmp_0 := l_plus(var_a |-> var_b); 
                IF (var_millisecond = {ref |-> TRUE}) THEN 
                    var_res1 := l_plus(var_tmp_0 |-> var_c)
                END; 
                var_res2 := l_plus(var_a |-> var_b); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var_millisecond = {ref |-> TRUE}) THEN 
                    is_initialisation_millisecond := FALSE
                END

            END

        END;

    out <-- getRes1 = BEGIN out := var_res1 END;
    out <-- getRes2 = BEGIN out := var_res2 END



END

/*
tmp_0: (a + b)
*/
