MACHINE microbenchmarks_or

SEES LibraryLustre

VARIABLES microbenchmarks_or_is_initialisation, microbenchmarks_or_var_res

SETS microbenchmarks_or_clocks = {microbenchmarks_or_clock___basic__}

INVARIANT ((microbenchmarks_or_is_initialisation : microbenchmarks_or_clocks --> BOOL) & ((microbenchmarks_or_var_res : REF +-> BOOL) & ((microbenchmarks_or_is_initialisation(microbenchmarks_or_clock___basic__) = FALSE) => (microbenchmarks_or_var_res /= {}))))

INITIALISATION 
    microbenchmarks_or_is_initialisation := (microbenchmarks_or_clocks * {TRUE}); 
    microbenchmarks_or_var_res := {}


OPERATIONS 

    microbenchmarks_or_clock_step(microbenchmarks_or_param_x, microbenchmarks_or_param_y) = 
        PRE
            ((microbenchmarks_or_param_x : REF --> BOOL) & (microbenchmarks_or_param_y : REF --> BOOL))
        THEN
            VAR microbenchmarks_or_var_x, microbenchmarks_or_var_y IN
                microbenchmarks_or_var_x := microbenchmarks_or_param_x; 
                microbenchmarks_or_var_y := microbenchmarks_or_param_y; 
                microbenchmarks_or_var_res := l_or(microbenchmarks_or_var_x |-> microbenchmarks_or_var_y); 
                microbenchmarks_or_is_initialisation(microbenchmarks_or_clock___basic__) := FALSE

            END

        END



END