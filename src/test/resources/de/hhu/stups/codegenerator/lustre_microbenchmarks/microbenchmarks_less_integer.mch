MACHINE microbenchmarks_less_integer

SEES LibraryLustre

VARIABLES microbenchmarks_less_integer_is_initialisation, microbenchmarks_less_integer_var_res

SETS microbenchmarks_less_integer_clocks = {microbenchmarks_less_integer_clock___basic__}

INVARIANT ((microbenchmarks_less_integer_is_initialisation : microbenchmarks_less_integer_clocks --> BOOL) & ((microbenchmarks_less_integer_var_res : REF +-> BOOL) & ((microbenchmarks_less_integer_is_initialisation(microbenchmarks_less_integer_clock___basic__) = FALSE) => (microbenchmarks_less_integer_var_res /= {}))))

INITIALISATION 
    microbenchmarks_less_integer_is_initialisation := (microbenchmarks_less_integer_clocks * {TRUE}); 
    microbenchmarks_less_integer_var_res := {}


OPERATIONS 

    microbenchmarks_less_integer_clock_step(microbenchmarks_less_integer_param_x, microbenchmarks_less_integer_param_y) = 
        PRE
            ((microbenchmarks_less_integer_param_x : REF --> INTEGER) & (microbenchmarks_less_integer_param_y : REF --> INTEGER))
        THEN
            VAR microbenchmarks_less_integer_var_x, microbenchmarks_less_integer_var_y IN
                microbenchmarks_less_integer_var_x := microbenchmarks_less_integer_param_x; 
                microbenchmarks_less_integer_var_y := microbenchmarks_less_integer_param_y; 
                microbenchmarks_less_integer_var_res := l_less(microbenchmarks_less_integer_var_x |-> microbenchmarks_less_integer_var_y); 
                microbenchmarks_less_integer_is_initialisation(microbenchmarks_less_integer_clock___basic__) := FALSE

            END

        END



END