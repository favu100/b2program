MACHINE microbenchmarks_multiply_integer

SEES LibraryLustre

VARIABLES microbenchmarks_multiply_integer_is_initialisation, microbenchmarks_multiply_integer_var_res

SETS microbenchmarks_multiply_integer_clocks = {microbenchmarks_multiply_integer_clock___basic__}

INVARIANT ((microbenchmarks_multiply_integer_is_initialisation : microbenchmarks_multiply_integer_clocks --> BOOL) & ((microbenchmarks_multiply_integer_var_res : REF +-> INTEGER) & ((microbenchmarks_multiply_integer_is_initialisation(microbenchmarks_multiply_integer_clock___basic__) = FALSE) => (microbenchmarks_multiply_integer_var_res /= {}))))

INITIALISATION 
    microbenchmarks_multiply_integer_is_initialisation := (microbenchmarks_multiply_integer_clocks * {TRUE}); 
    microbenchmarks_multiply_integer_var_res := {}


OPERATIONS 

    microbenchmarks_multiply_integer_clock_step(microbenchmarks_multiply_integer_param_x, microbenchmarks_multiply_integer_param_y) = 
        PRE
            ((microbenchmarks_multiply_integer_param_x : REF --> INTEGER) & (microbenchmarks_multiply_integer_param_y : REF --> INTEGER))
        THEN
            VAR microbenchmarks_multiply_integer_var_x, microbenchmarks_multiply_integer_var_y IN
                microbenchmarks_multiply_integer_var_x := microbenchmarks_multiply_integer_param_x; 
                microbenchmarks_multiply_integer_var_y := microbenchmarks_multiply_integer_param_y; 
                microbenchmarks_multiply_integer_var_res := l_multiply(microbenchmarks_multiply_integer_var_x |-> microbenchmarks_multiply_integer_var_y); 
                microbenchmarks_multiply_integer_is_initialisation(microbenchmarks_multiply_integer_clock___basic__) := FALSE

            END

        END



END