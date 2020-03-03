MACHINE microbenchmarks_equal_boolean

SEES LibraryLustre

VARIABLES microbenchmarks_equal_boolean_is_initialisation, microbenchmarks_equal_boolean_var_res

SETS microbenchmarks_equal_boolean_clocks = {microbenchmarks_equal_boolean_clock___basic__}

INVARIANT ((microbenchmarks_equal_boolean_is_initialisation : microbenchmarks_equal_boolean_clocks --> BOOL) & ((microbenchmarks_equal_boolean_var_res : REF +-> BOOL) & ((microbenchmarks_equal_boolean_is_initialisation(microbenchmarks_equal_boolean_clock___basic__) = FALSE) => (microbenchmarks_equal_boolean_var_res /= {}))))

INITIALISATION 
    microbenchmarks_equal_boolean_is_initialisation := (microbenchmarks_equal_boolean_clocks * {TRUE}); 
    microbenchmarks_equal_boolean_var_res := {}


OPERATIONS 

    microbenchmarks_equal_boolean_clock_step(microbenchmarks_equal_boolean_param_x, microbenchmarks_equal_boolean_param_y) = 
        PRE
            ((microbenchmarks_equal_boolean_param_x : REF --> BOOL) & (microbenchmarks_equal_boolean_param_y : REF --> BOOL))
        THEN
            VAR microbenchmarks_equal_boolean_var_x, microbenchmarks_equal_boolean_var_y IN
                microbenchmarks_equal_boolean_var_x := microbenchmarks_equal_boolean_param_x; 
                microbenchmarks_equal_boolean_var_y := microbenchmarks_equal_boolean_param_y; 
                microbenchmarks_equal_boolean_var_res := l_equal_boolean(microbenchmarks_equal_boolean_var_x |-> microbenchmarks_equal_boolean_var_y); 
                microbenchmarks_equal_boolean_is_initialisation(microbenchmarks_equal_boolean_clock___basic__) := FALSE

            END

        END



END