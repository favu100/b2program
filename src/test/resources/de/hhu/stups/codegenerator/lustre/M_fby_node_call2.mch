MACHINE M_fby_node_call2

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_z

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_z : LUSTRE_INT)))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_z := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT)
        THEN
            VAR var_x IN
                var_x := param_x; 
                var_z := {ref |-> 0}; 
                is_initialisation := FALSE

            END

        END



END

