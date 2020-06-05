MACHINE M_invoked_nil

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res, var_x

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_x : LUSTRE_INT) & (var_res : LUSTRE_INT))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_x := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT)
        THEN
            VAR hvar_x IN
                hvar_x := var_x; 
                var_x := param_x; 
                var_res := hvar_x; 
                is_initialisation := FALSE

            END

        END



END

