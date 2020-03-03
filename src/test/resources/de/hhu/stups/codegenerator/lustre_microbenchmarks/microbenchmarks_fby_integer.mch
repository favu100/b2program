MACHINE microbenchmarks_fby_integer

SEES LibraryLustre

VARIABLES microbenchmarks_fby_integer_is_initialisation, microbenchmarks_fby_integer_var_res

SETS microbenchmarks_fby_integer_clocks = {microbenchmarks_fby_integer_clock___basic__}

INVARIANT ((microbenchmarks_fby_integer_is_initialisation : microbenchmarks_fby_integer_clocks --> BOOL) & ((microbenchmarks_fby_integer_var_res : REF +-> INTEGER) & ((microbenchmarks_fby_integer_is_initialisation(microbenchmarks_fby_integer_clock___basic__) = FALSE) => (microbenchmarks_fby_integer_var_res /= {}))))

INITIALISATION 
    microbenchmarks_fby_integer_is_initialisation := (microbenchmarks_fby_integer_clocks * {TRUE}); 
    microbenchmarks_fby_integer_var_res := {}


OPERATIONS 

    microbenchmarks_fby_integer_clock_step(microbenchmarks_fby_integer_param_x, microbenchmarks_fby_integer_param_y) = 
        PRE
            ((microbenchmarks_fby_integer_param_x : REF --> INTEGER) & (microbenchmarks_fby_integer_param_y : REF --> INTEGER))
        THEN
            VAR microbenchmarks_fby_integer_var_x, microbenchmarks_fby_integer_var_y IN
                microbenchmarks_fby_integer_var_x := microbenchmarks_fby_integer_param_x; 
                microbenchmarks_fby_integer_var_y := microbenchmarks_fby_integer_param_y; 
                microbenchmarks_fby_integer_var_res := l_fby_integer(microbenchmarks_fby_integer_is_initialisation(microbenchmarks_fby_integer_clock___basic__) |-> microbenchmarks_fby_integer_var_x |-> microbenchmarks_fby_integer_var_y); 
                microbenchmarks_fby_integer_is_initialisation(microbenchmarks_fby_integer_clock___basic__) := FALSE

            END

        END



END