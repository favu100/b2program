MACHINE M_NodeCall_Clock2_Call

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_a

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_a : LUSTRE_INT)))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_a := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT)
        THEN
            VAR var_x IN
                var_x := param_x; 
                var_a := l_plus(var_x |-> {ref |-> 1}); 
                is_initialisation := FALSE

            END

        END



END

