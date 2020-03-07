MACHINE after_h

SEES LibraryLustre

VARIABLES after_h_is_initialisation, after_h_var_e1, after_h_var_a, after_h_var_e2_since_last_e1

SETS after_h_clocks = {after_h_clock___basic__}

INVARIANT ((after_h_is_initialisation : after_h_clocks --> BOOL) & ((after_h_var_e2_since_last_e1 : REF +-> BOOL) & ((after_h_var_a : REF +-> BOOL) & (after_h_var_e1 : REF +-> BOOL))))

INITIALISATION 
    after_h_is_initialisation := (after_h_clocks * {TRUE}); 
    after_h_var_e1 := {}; 
    after_h_var_a := {}; 
    after_h_var_e2_since_last_e1 := {}


OPERATIONS 

    after_h_clock_step(after_h_param_e1, after_h_param_e2) = 
        PRE
            ((after_h_param_e1 : REF +-> BOOL) & (after_h_param_e2 : REF +-> BOOL))
        THEN
            VAR after_h_var_e2 IN
                after_h_var_e1 := after_h_param_e1; 
                after_h_var_e2 := after_h_param_e2; 
                after_h_var_e2_since_last_e1 := l_fby_boolean(after_h_is_initialisation(after_h_clock___basic__) |-> after_h_var_e2 |-> l_ite_boolean(after_h_var_e2 |-> {ref |-> TRUE} |-> l_ite_boolean(after_h_var_e1 |-> {ref |-> FALSE} |-> after_h_var_e2_since_last_e1))); 
                after_h_var_a := l_and(after_h_var_e1 |-> after_h_var_e2_since_last_e1); 
                after_h_is_initialisation(after_h_clock___basic__) := FALSE

            END

        END



END