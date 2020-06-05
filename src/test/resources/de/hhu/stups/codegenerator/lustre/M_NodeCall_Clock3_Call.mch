MACHINE M_NodeCall_Clock3_Call

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_c, var_a, var_tmp_0, var_c

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_c : BOOL) & ((var_c : LUSTRE_BOOL) & ((var_a : LUSTRE_INT) & (var_tmp_0 : LUSTRE_INT))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_c := TRUE; 
    var_a := {}; 
    var_tmp_0 := {}; 
    var_c := {}


OPERATIONS 

    clock_step(param_c, param_x) = 
        PRE
            ((param_c : LUSTRE_BOOL) & (param_x : LUSTRE_INT))
        THEN
            VAR var_x IN
                var_c := param_c; 
                PRE (var_c /= {}) THEN skip END; 
                var_x := param_x; 
                var_tmp_0 := l_plus(var_x |-> {ref |-> 1}); 
                IF (var_c = {ref |-> TRUE}) THEN 
                    var_a := var_tmp_0
                END; 
                is_initialisation := FALSE; 
                IF (var_c = {ref |-> TRUE}) THEN 
                    is_initialisation_c := FALSE
                END

            END

        END



END

/*
tmp_0: (x + 1)
*/
