MACHINE microbenchmarks_when_integer

SEES LibraryLustre

VARIABLES microbenchmarks_when_integer_is_initialisation, microbenchmarks_when_integer_var_x, microbenchmarks_when_integer_var_res, microbenchmarks_when_integer_var_y

SETS microbenchmarks_when_integer_clocks = {microbenchmarks_when_integer_clock___basic__, microbenchmarks_when_integer_clock_y}

INVARIANT ((microbenchmarks_when_integer_is_initialisation : microbenchmarks_when_integer_clocks --> BOOL) & ((microbenchmarks_when_integer_var_y : REF +-> BOOL) & ((microbenchmarks_when_integer_var_res : REF +-> INTEGER) & ((microbenchmarks_when_integer_var_x : REF +-> INTEGER) & (((microbenchmarks_when_integer_is_initialisation(microbenchmarks_when_integer_clock_y) = FALSE) => (microbenchmarks_when_integer_var_res /= {})) & ((microbenchmarks_when_integer_is_initialisation(microbenchmarks_when_integer_clock_y) = FALSE) => (microbenchmarks_when_integer_var_y /= {})))))))

INITIALISATION 
    microbenchmarks_when_integer_is_initialisation := (microbenchmarks_when_integer_clocks * {TRUE}); 
    microbenchmarks_when_integer_var_x := {}; 
    microbenchmarks_when_integer_var_res := {}; 
    microbenchmarks_when_integer_var_y := {}


OPERATIONS 

    microbenchmarks_when_integer_clock_step(microbenchmarks_when_integer_param_y, microbenchmarks_when_integer_param_x) = 
        PRE
            ((microbenchmarks_when_integer_param_y : REF --> BOOL) & (microbenchmarks_when_integer_param_x : REF --> INTEGER))
        THEN
            microbenchmarks_when_integer_var_y := microbenchmarks_when_integer_param_y; 
            microbenchmarks_when_integer_var_x := microbenchmarks_when_integer_param_x; 
            IF (microbenchmarks_when_integer_var_y = {ref |-> TRUE}) THEN 
                microbenchmarks_when_integer_var_res := microbenchmarks_when_integer_var_x
            END; 
            IF (microbenchmarks_when_integer_var_y = {ref |-> TRUE}) THEN 
                microbenchmarks_when_integer_is_initialisation(microbenchmarks_when_integer_clock_y) := FALSE
            END; 
            microbenchmarks_when_integer_is_initialisation(microbenchmarks_when_integer_clock___basic__) := FALSE

        END



END