MACHINE M_Current

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_millisecond, is_initialisation, var_res3, var_res2, var_a, var_millisecond, var_c, var_res1, var_tmp_0

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_millisecond : BOOL) & ((is_initialisation : BOOL) & ((var_a : LUSTRE_INT) & ((var_c : LUSTRE_INT) & ((var_millisecond : LUSTRE_BOOL) & ((var_res1 : LUSTRE_INT) & ((var_res2 : LUSTRE_INT) & ((var_res3 : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & (((is_initialisation = FALSE) => (var_res1 /= {})) & (((is_initialisation = FALSE) => (var_res2 /= {})) & ((is_initialisation = FALSE) => (var_res3 /= {}))))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_millisecond := TRUE; 
    is_initialisation := TRUE; 
    var_res3 := {}; 
    var_res2 := {}; 
    var_a := {}; 
    var_millisecond := {}; 
    var_c := {}; 
    var_res1 := {}; 
    var_tmp_0 := {}


OPERATIONS 

    clock_step(param_millisecond, param_c, param_a, param_b) = 
        PRE
            ((param_millisecond : LUSTRE_BOOL_NOT_NIL) & ((param_c : LUSTRE_INT_NOT_NIL) & ((param_a : LUSTRE_INT_NOT_NIL) & (param_b : LUSTRE_INT_NOT_NIL))))
        THEN
            VAR var_b IN
                var_millisecond := param_millisecond; 
                PRE (var_millisecond /= {}) THEN skip END; 
                IF (var_millisecond = {ref |-> TRUE}) THEN
                    var_c := param_c
                END;
                var_a := param_a; 
                var_b := param_b; 
                IF (var_millisecond = {ref |-> TRUE}) THEN 
                    var_tmp_0 := var_a
                END; 
                var_res1 := l_fby_integer(is_initialisation |-> {ref |-> 0} |-> l_plus(var_c |-> var_res1)); 
                var_res2 := l_plus(var_a |-> var_b); 
                var_res3 := l_fby_integer(is_initialisation |-> {ref |-> 0} |-> var_tmp_0); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                IF (var_millisecond = {ref |-> TRUE}) THEN 
                    is_initialisation_millisecond := FALSE
                END; 
                is_initialisation := FALSE

            END

        END;

     out <-- getRes1 = BEGIN out := var_res1 END;
     out <-- getRes2 = BEGIN out := var_res2 END;
     out <-- getRes3 = BEGIN out := var_res3 END



END

/*
tmp_0: (a when millisecond)
*/
