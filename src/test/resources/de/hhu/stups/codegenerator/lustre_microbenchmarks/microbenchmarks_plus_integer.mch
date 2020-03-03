MACHINE microbenchmarks_plus_integer

SEES LibraryLustre

VARIABLES microbenchmarks_plus_integer_is_initialisation, microbenchmarks_plus_integer_var_res

SETS microbenchmarks_plus_integer_clocks = {microbenchmarks_plus_integer_clock___basic__}

INVARIANT ((microbenchmarks_plus_integer_is_initialisation : microbenchmarks_plus_integer_clocks --> BOOL) & ((microbenchmarks_plus_integer_var_res : REF +-> INTEGER) & ((microbenchmarks_plus_integer_is_initialisation(microbenchmarks_plus_integer_clock___basic__) = FALSE) => (microbenchmarks_plus_integer_var_res /= {}))))

INITIALISATION 
    microbenchmarks_plus_integer_is_initialisation := (microbenchmarks_plus_integer_clocks * {TRUE}); 
    microbenchmarks_plus_integer_var_res := {}


OPERATIONS 

    microbenchmarks_plus_integer_clock_step(microbenchmarks_plus_integer_param_x, microbenchmarks_plus_integer_param_y) = 
        PRE
            ((microbenchmarks_plus_integer_param_x : REF --> INTEGER) & (microbenchmarks_plus_integer_param_y : REF --> INTEGER))
        THEN
            VAR microbenchmarks_plus_integer_var_x, microbenchmarks_plus_integer_var_y IN
                microbenchmarks_plus_integer_var_x := microbenchmarks_plus_integer_param_x; 
                microbenchmarks_plus_integer_var_y := microbenchmarks_plus_integer_param_y; 
                microbenchmarks_plus_integer_var_res := l_plus(microbenchmarks_plus_integer_var_x |-> microbenchmarks_plus_integer_var_y); 
                microbenchmarks_plus_integer_is_initialisation(microbenchmarks_plus_integer_clock___basic__) := FALSE

            END

        END



END