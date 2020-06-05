MACHINE M_speed_verif

INCLUDES Node_2.M_speed

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_OK, var_late, var_early

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_OK : LUSTRE_BOOL) & ((var_early : LUSTRE_BOOL) & ((var_late : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_OK /= {})) & ((is_initialisation = FALSE) => (var_OK = {ref |-> TRUE}))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_OK := {}; 
    var_late := {}; 
    var_early := {}


OPERATIONS 

    clock_step(param_beacon, param_second) = 
        PRE
            ((param_beacon : LUSTRE_BOOL_NOT_NIL) & (param_second : LUSTRE_BOOL_NOT_NIL))
        THEN
            VAR hvar_early, hvar_late, var_beacon, var_second IN
                hvar_early := var_early; 
                hvar_late := var_late; 
                var_beacon := param_beacon; 
                var_second := param_second; 
                Node_2.clock_step(var_beacon, var_second); 
                var_late := Node_2.var_late; 
                var_early := Node_2.var_early; 
                var_OK := l_and(l_and(l_not(l_and(var_late |-> var_early)) |-> l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> l_not(l_and(var_late |-> hvar_early)))) |-> l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> l_not(l_and(hvar_late |-> var_early)))); 
                SELECT ((assert_ok = TRUE) & (Node_2.assert_ok = TRUE)) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

    out <-- getOK = BEGIN out := var_OK END



END

/*
Node_2: speed(beacon, second)
*/
