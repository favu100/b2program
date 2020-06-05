MACHINE M_fedge

INCLUDES Node_1.M_redge

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_f

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_f : LUSTRE_BOOL)))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_f := {}


OPERATIONS 

    clock_step(param_signal) = 
        PRE
            (param_signal : LUSTRE_BOOL)
        THEN
            VAR var_signal IN
                var_signal := param_signal; 
                Node_1.clock_step(l_not(var_signal)); 
                var_f := Node_1.var_r; 
                is_initialisation := FALSE

            END

        END



END

/*
Node_1: redge(not(signal))
*/
