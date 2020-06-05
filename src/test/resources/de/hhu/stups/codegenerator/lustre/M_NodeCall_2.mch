MACHINE M_NodeCall_2

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_res : LUSTRE_INT)))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x, param_y, param_z) = 
        PRE
            ((param_x : LUSTRE_INT) & ((param_y : LUSTRE_INT) & (param_z : LUSTRE_INT)))
        THEN
            VAR var_x, var_y, var_z IN
                var_x := param_x; 
                var_y := param_y; 
                var_z := param_z; 
                var_res := {ref |-> 3}; 
                is_initialisation := FALSE

            END

        END



END

