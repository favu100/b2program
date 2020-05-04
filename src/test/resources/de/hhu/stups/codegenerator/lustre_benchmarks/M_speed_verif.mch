MACHINE M_speed_verif

INCLUDES Node_2.M_speed

SEES LibraryLustre

VARIABLES is_initialisation, var_OK, var_late, var_early

INVARIANT ((var_OK : LUSTRE_BOOL) & ((var_early : LUSTRE_BOOL) & ((var_late : LUSTRE_BOOL) & ((is_initialisation : BOOL) & ((is_initialisation = FALSE) => (var_OK = {ref |-> TRUE}))))))

INITIALISATION 
    is_initialisation := TRUE; 
    var_OK := {}; 
    var_late := {}; 
    var_early := {}


OPERATIONS 

    clock_step(param_beacon, param_second) = 
        PRE
            ((param_beacon : LUSTRE_BOOL) & (param_second : LUSTRE_BOOL))
        THEN
            VAR hvar_early, hvar_late, var_beacon, var_second IN
                hvar_early := var_early; 
                hvar_late := var_late; 
                var_beacon := param_beacon; 
                var_second := param_second; 
                Node_2.clock_step(var_beacon, var_second); 
                var_late := Node_2.var_late; 
                var_early := Node_2.var_early; 
                var_OK := l_and(l_not(l_and(var_late |-> var_early)) |-> l_and(l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> l_not(l_and(var_late |-> hvar_early))) |-> l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> l_not(l_and(hvar_late |-> var_early))))); 
                is_initialisation := FALSE

            END

        END



END

/*
Node_2: speed(beacon, second)
*/
