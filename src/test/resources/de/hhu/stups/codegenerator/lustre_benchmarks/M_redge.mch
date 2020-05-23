MACHINE M_redge

SEES LibraryLustre

VARIABLES is_initialisation, var_r, var_tmp_0

INVARIANT ((var_r : LUSTRE_BOOL) & ((var_tmp_0 : LUSTRE_BOOL) & (is_initialisation : BOOL)))

INITIALISATION 
    is_initialisation := TRUE; 
    var_r := {}; 
    var_tmp_0 := {}


OPERATIONS 

    clock_step(param_signal) = 
        PRE
            (param_signal : LUSTRE_BOOL)
        THEN
            VAR hvar_tmp_0, var_signal IN
                hvar_tmp_0 := var_tmp_0; 
                var_signal := param_signal; 
                var_tmp_0 := l_not(var_signal); 
                var_r := l_fby_boolean(is_initialisation |-> var_signal |-> l_and(var_signal |-> hvar_tmp_0)); 
                is_initialisation := FALSE

            END

        END



END

/*
tmp_0: not(signal)
*/
