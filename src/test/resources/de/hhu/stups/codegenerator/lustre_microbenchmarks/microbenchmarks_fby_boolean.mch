MACHINE microbenchmarks_fby_boolean

SEES LibraryLustre

VARIABLES microbenchmarks_fby_boolean_is_initialisation, microbenchmarks_fby_boolean_var_res

SETS microbenchmarks_fby_boolean_clocks = {microbenchmarks_fby_boolean_clock___basic__}

INVARIANT ((microbenchmarks_fby_boolean_is_initialisation : microbenchmarks_fby_boolean_clocks --> BOOL) & ((microbenchmarks_fby_boolean_var_res : REF +-> BOOL) & ((microbenchmarks_fby_boolean_is_initialisation(microbenchmarks_fby_boolean_clock___basic__) = FALSE) => (microbenchmarks_fby_boolean_var_res /= {}))))

INITIALISATION 
    microbenchmarks_fby_boolean_is_initialisation := (microbenchmarks_fby_boolean_clocks * {TRUE}); 
    microbenchmarks_fby_boolean_var_res := {}


OPERATIONS 

    microbenchmarks_fby_boolean_clock_step(microbenchmarks_fby_boolean_param_x, microbenchmarks_fby_boolean_param_y) = 
        PRE
            ((microbenchmarks_fby_boolean_param_x : REF --> BOOL) & (microbenchmarks_fby_boolean_param_y : REF --> BOOL))
        THEN
            VAR microbenchmarks_fby_boolean_var_x, microbenchmarks_fby_boolean_var_y IN
                microbenchmarks_fby_boolean_var_x := microbenchmarks_fby_boolean_param_x; 
                microbenchmarks_fby_boolean_var_y := microbenchmarks_fby_boolean_param_y; 
                microbenchmarks_fby_boolean_var_res := l_fby_boolean(microbenchmarks_fby_boolean_is_initialisation(microbenchmarks_fby_boolean_clock___basic__) |-> microbenchmarks_fby_boolean_var_x |-> microbenchmarks_fby_boolean_var_y); 
                microbenchmarks_fby_boolean_is_initialisation(microbenchmarks_fby_boolean_clock___basic__) := FALSE

            END

        END



END