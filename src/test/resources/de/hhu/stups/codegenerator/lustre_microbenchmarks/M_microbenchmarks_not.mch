MACHINE M_microbenchmarks_not

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_res : LUSTRE_BOOL) & ((is_initialisation = FALSE) => (var_res /= {})))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_BOOL_NOT_NIL)
        THEN
            VAR var_x IN
                var_x := param_x; 
                var_res := l_not(var_x); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END



END

