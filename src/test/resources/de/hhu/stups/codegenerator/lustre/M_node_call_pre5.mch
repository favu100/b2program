MACHINE M_node_call_pre5

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_z, var_x

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_x : LUSTRE_INT) & (var_z : LUSTRE_INT))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_z := {}; 
    var_x := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT)
        THEN
            VAR hvar_x IN
                hvar_x := var_x; 
                var_x := param_x; 
                var_z := hvar_x; 
                is_initialisation := FALSE

            END

        END



END

