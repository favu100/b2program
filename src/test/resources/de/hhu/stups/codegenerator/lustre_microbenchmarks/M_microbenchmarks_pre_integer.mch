MACHINE M_microbenchmarks_pre_integer

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res, var_x

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_x : LUSTRE_INT) & ((var_res : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_res /= {}))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_x := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR hvar_x IN
                hvar_x := var_x; 
                var_x := param_x; 
                var_res := hvar_x; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END



END

