MACHINE microbenchmarks_greater_integer

SEES LibraryLustre

VARIABLES microbenchmarks_greater_integer_is_initialisation, microbenchmarks_greater_integer_var_res

SETS microbenchmarks_greater_integer_clocks = {microbenchmarks_greater_integer_clock___basic__}

INVARIANT ((microbenchmarks_greater_integer_is_initialisation : microbenchmarks_greater_integer_clocks --> BOOL) & ((microbenchmarks_greater_integer_var_res : REF +-> BOOL) & ((microbenchmarks_greater_integer_is_initialisation(microbenchmarks_greater_integer_clock___basic__) = FALSE) => (microbenchmarks_greater_integer_var_res /= {}))))

INITIALISATION 
    microbenchmarks_greater_integer_is_initialisation := (microbenchmarks_greater_integer_clocks * {TRUE}); 
    microbenchmarks_greater_integer_var_res := {}


OPERATIONS 

    microbenchmarks_greater_integer_clock_step(microbenchmarks_greater_integer_param_x, microbenchmarks_greater_integer_param_y) = 
        PRE
            ((microbenchmarks_greater_integer_param_x : REF --> INTEGER) & (microbenchmarks_greater_integer_param_y : REF --> INTEGER))
        THEN
            VAR microbenchmarks_greater_integer_var_x, microbenchmarks_greater_integer_var_y IN
                microbenchmarks_greater_integer_var_x := microbenchmarks_greater_integer_param_x; 
                microbenchmarks_greater_integer_var_y := microbenchmarks_greater_integer_param_y; 
                microbenchmarks_greater_integer_var_res := l_greater(microbenchmarks_greater_integer_var_x |-> microbenchmarks_greater_integer_var_y); 
                microbenchmarks_greater_integer_is_initialisation(microbenchmarks_greater_integer_clock___basic__) := FALSE

            END

        END



END