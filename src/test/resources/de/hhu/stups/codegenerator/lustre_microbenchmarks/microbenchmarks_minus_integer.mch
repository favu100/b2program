MACHINE microbenchmarks_minus_integer

SEES LibraryLustre

VARIABLES microbenchmarks_minus_integer_is_initialisation, microbenchmarks_minus_integer_var_res

SETS microbenchmarks_minus_integer_clocks = {microbenchmarks_minus_integer_clock___basic__}

INVARIANT ((microbenchmarks_minus_integer_is_initialisation : microbenchmarks_minus_integer_clocks --> BOOL) & ((microbenchmarks_minus_integer_var_res : REF +-> INTEGER) & ((microbenchmarks_minus_integer_is_initialisation(microbenchmarks_minus_integer_clock___basic__) = FALSE) => (microbenchmarks_minus_integer_var_res /= {}))))

INITIALISATION 
    microbenchmarks_minus_integer_is_initialisation := (microbenchmarks_minus_integer_clocks * {TRUE}); 
    microbenchmarks_minus_integer_var_res := {}


OPERATIONS 

    microbenchmarks_minus_integer_clock_step(microbenchmarks_minus_integer_param_x, microbenchmarks_minus_integer_param_y) = 
        PRE
            ((microbenchmarks_minus_integer_param_x : REF --> INTEGER) & (microbenchmarks_minus_integer_param_y : REF --> INTEGER))
        THEN
            VAR microbenchmarks_minus_integer_var_x, microbenchmarks_minus_integer_var_y IN
                microbenchmarks_minus_integer_var_x := microbenchmarks_minus_integer_param_x; 
                microbenchmarks_minus_integer_var_y := microbenchmarks_minus_integer_param_y; 
                microbenchmarks_minus_integer_var_res := l_minus(microbenchmarks_minus_integer_var_x |-> microbenchmarks_minus_integer_var_y); 
                microbenchmarks_minus_integer_is_initialisation(microbenchmarks_minus_integer_clock___basic__) := FALSE

            END

        END



END