MACHINE microbenchmarks_current_boolean

SEES LibraryLustre

VARIABLES microbenchmarks_current_boolean_is_initialisation, microbenchmarks_current_boolean_var_res, microbenchmarks_current_boolean_var_x

SETS microbenchmarks_current_boolean_clocks = {microbenchmarks_current_boolean_clock___basic__}

INVARIANT ((microbenchmarks_current_boolean_is_initialisation : microbenchmarks_current_boolean_clocks --> BOOL) & ((microbenchmarks_current_boolean_var_x : REF +-> BOOL) & ((microbenchmarks_current_boolean_var_res : REF +-> BOOL) & ((microbenchmarks_current_boolean_is_initialisation(microbenchmarks_current_boolean_clock___basic__) = FALSE) => (microbenchmarks_current_boolean_var_res /= {})))))

INITIALISATION 
    microbenchmarks_current_boolean_is_initialisation := (microbenchmarks_current_boolean_clocks * {TRUE}); 
    microbenchmarks_current_boolean_var_res := {}; 
    microbenchmarks_current_boolean_var_x := {}


OPERATIONS 

    microbenchmarks_current_boolean_clock_step(microbenchmarks_current_boolean_param_x) = 
        PRE
            (microbenchmarks_current_boolean_param_x : REF --> BOOL)
        THEN
            microbenchmarks_current_boolean_var_x := microbenchmarks_current_boolean_param_x; 
            microbenchmarks_current_boolean_var_res := microbenchmarks_current_boolean_var_x; 
            microbenchmarks_current_boolean_is_initialisation(microbenchmarks_current_boolean_clock___basic__) := FALSE

        END



END