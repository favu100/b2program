MACHINE microbenchmarks_divide_integer

SEES LibraryLustre

VARIABLES microbenchmarks_divide_integer_is_initialisation, microbenchmarks_divide_integer_var_res

SETS microbenchmarks_divide_integer_clocks = {microbenchmarks_divide_integer_clock___basic__}

INVARIANT ((microbenchmarks_divide_integer_is_initialisation : microbenchmarks_divide_integer_clocks --> BOOL) & ((microbenchmarks_divide_integer_var_res : REF +-> INTEGER) & ((microbenchmarks_divide_integer_is_initialisation(microbenchmarks_divide_integer_clock___basic__) = FALSE) => (microbenchmarks_divide_integer_var_res /= {}))))

INITIALISATION 
    microbenchmarks_divide_integer_is_initialisation := (microbenchmarks_divide_integer_clocks * {TRUE}); 
    microbenchmarks_divide_integer_var_res := {}


OPERATIONS 

    microbenchmarks_divide_integer_clock_step(microbenchmarks_divide_integer_param_x, microbenchmarks_divide_integer_param_y) = 
        PRE
            ((microbenchmarks_divide_integer_param_x : REF --> INTEGER) & (microbenchmarks_divide_integer_param_y : REF --> INTEGER))
        THEN
            VAR microbenchmarks_divide_integer_var_x, microbenchmarks_divide_integer_var_y IN
                microbenchmarks_divide_integer_var_x := microbenchmarks_divide_integer_param_x; 
                microbenchmarks_divide_integer_var_y := microbenchmarks_divide_integer_param_y; 
                microbenchmarks_divide_integer_var_res := l_divide(microbenchmarks_divide_integer_var_x |-> microbenchmarks_divide_integer_var_y); 
                microbenchmarks_divide_integer_is_initialisation(microbenchmarks_divide_integer_clock___basic__) := FALSE

            END

        END



END