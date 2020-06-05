MACHINE M_edge

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_EDGE, var_X

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_X : LUSTRE_BOOL) & (var_EDGE : LUSTRE_BOOL))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_EDGE := {}; 
    var_X := {}


OPERATIONS 

    clock_step(param_X) = 
        PRE
            (param_X : LUSTRE_BOOL)
        THEN
            VAR hvar_X IN
                hvar_X := var_X; 
                var_X := param_X; 
                var_EDGE := l_fby_boolean(is_initialisation |-> var_X |-> l_and(var_X |-> l_not(hvar_X))); 
                is_initialisation := FALSE

            END

        END



END

