MACHINE microbenchmarks_not

SEES LibraryLustre

VARIABLES microbenchmarks_not_is_initialisation, microbenchmarks_not_var_res

SETS microbenchmarks_not_clocks = {microbenchmarks_not_clock___basic__}

INVARIANT ((microbenchmarks_not_is_initialisation : microbenchmarks_not_clocks --> BOOL) & ((microbenchmarks_not_var_res : REF +-> BOOL) & ((microbenchmarks_not_is_initialisation(microbenchmarks_not_clock___basic__) = FALSE) => (microbenchmarks_not_var_res /= {}))))

INITIALISATION 
    microbenchmarks_not_is_initialisation := (microbenchmarks_not_clocks * {TRUE}); 
    microbenchmarks_not_var_res := {}


OPERATIONS 

    microbenchmarks_not_clock_step(microbenchmarks_not_param_x) = 
        PRE
            (microbenchmarks_not_param_x : REF --> BOOL)
        THEN
            VAR microbenchmarks_not_var_x IN
                microbenchmarks_not_var_x := microbenchmarks_not_param_x; 
                microbenchmarks_not_var_res := l_not(microbenchmarks_not_var_x); 
                microbenchmarks_not_is_initialisation(microbenchmarks_not_clock___basic__) := FALSE

            END

        END



END