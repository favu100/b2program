MACHINE microbenchmarks_and

SEES LibraryLustre

VARIABLES microbenchmarks_and_is_initialisation, microbenchmarks_and_var_res

SETS microbenchmarks_and_clocks = {microbenchmarks_and_clock___basic__}

INVARIANT ((microbenchmarks_and_is_initialisation : microbenchmarks_and_clocks --> BOOL) & ((microbenchmarks_and_var_res : REF +-> BOOL) & ((microbenchmarks_and_is_initialisation(microbenchmarks_and_clock___basic__) = FALSE) => (microbenchmarks_and_var_res /= {}))))

INITIALISATION 
    microbenchmarks_and_is_initialisation := (microbenchmarks_and_clocks * {TRUE}); 
    microbenchmarks_and_var_res := {}


OPERATIONS 

    microbenchmarks_and_clock_step(microbenchmarks_and_param_x, microbenchmarks_and_param_y) = 
        PRE
            ((microbenchmarks_and_param_x : REF --> BOOL) & (microbenchmarks_and_param_y : REF --> BOOL))
        THEN
            VAR microbenchmarks_and_var_x, microbenchmarks_and_var_y IN
                microbenchmarks_and_var_x := microbenchmarks_and_param_x; 
                microbenchmarks_and_var_y := microbenchmarks_and_param_y; 
                microbenchmarks_and_var_res := l_and(microbenchmarks_and_var_x |-> microbenchmarks_and_var_y); 
                microbenchmarks_and_is_initialisation(microbenchmarks_and_clock___basic__) := FALSE

            END

        END



END