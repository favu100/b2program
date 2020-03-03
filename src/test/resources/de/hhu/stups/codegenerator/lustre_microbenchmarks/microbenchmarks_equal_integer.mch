MACHINE microbenchmarks_equal_integer

SEES LibraryLustre

VARIABLES microbenchmarks_equal_integer_is_initialisation, microbenchmarks_equal_integer_var_res

SETS microbenchmarks_equal_integer_clocks = {microbenchmarks_equal_integer_clock___basic__}

INVARIANT ((microbenchmarks_equal_integer_is_initialisation : microbenchmarks_equal_integer_clocks --> BOOL) & ((microbenchmarks_equal_integer_var_res : REF +-> BOOL) & ((microbenchmarks_equal_integer_is_initialisation(microbenchmarks_equal_integer_clock___basic__) = FALSE) => (microbenchmarks_equal_integer_var_res /= {}))))

INITIALISATION 
    microbenchmarks_equal_integer_is_initialisation := (microbenchmarks_equal_integer_clocks * {TRUE}); 
    microbenchmarks_equal_integer_var_res := {}


OPERATIONS 

    microbenchmarks_equal_integer_clock_step(microbenchmarks_equal_integer_param_x, microbenchmarks_equal_integer_param_y) = 
        PRE
            ((microbenchmarks_equal_integer_param_x : REF --> INTEGER) & (microbenchmarks_equal_integer_param_y : REF --> INTEGER))
        THEN
            VAR microbenchmarks_equal_integer_var_x, microbenchmarks_equal_integer_var_y IN
                microbenchmarks_equal_integer_var_x := microbenchmarks_equal_integer_param_x; 
                microbenchmarks_equal_integer_var_y := microbenchmarks_equal_integer_param_y; 
                microbenchmarks_equal_integer_var_res := l_equal_integer(microbenchmarks_equal_integer_var_x |-> microbenchmarks_equal_integer_var_y); 
                microbenchmarks_equal_integer_is_initialisation(microbenchmarks_equal_integer_clock___basic__) := FALSE

            END

        END



END