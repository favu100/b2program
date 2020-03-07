MACHINE after

SEES LibraryLustre

VARIABLES after_is_initialisation, after_var_afterA, after_var_tmp_0

SETS after_clocks = {after_clock___basic__}

INVARIANT ((after_is_initialisation : after_clocks --> BOOL) & ((after_var_tmp_0 : REF +-> BOOL) & (after_var_afterA : REF +-> BOOL)))

INITIALISATION 
    after_is_initialisation := (after_clocks * {TRUE}); 
    after_var_afterA := {}; 
    after_var_tmp_0 := {}


OPERATIONS 

    after_clock_step(after_param_A) = 
        PRE
            (after_param_A : REF +-> BOOL)
        THEN
            VAR after_var_A IN
                after_var_A := after_param_A; 
                after_var_afterA := l_fby_boolean(after_is_initialisation(after_clock___basic__) |-> {ref |-> FALSE} |-> after_var_tmp_0); 
                after_var_tmp_0 := l_or(after_var_A |-> after_var_afterA); 
                after_is_initialisation(after_clock___basic__) := FALSE

            END

        END



END