MACHINE microbenchmarks_current_integer

SEES LibraryLustre

VARIABLES microbenchmarks_current_integer_is_initialisation, microbenchmarks_current_integer_var_res, microbenchmarks_current_integer_var_tmp_0

SETS microbenchmarks_current_integer_clocks = {microbenchmarks_current_integer_clock___basic__}

INVARIANT ((microbenchmarks_current_integer_is_initialisation : microbenchmarks_current_integer_clocks --> BOOL) & ((microbenchmarks_current_integer_var_tmp_0 : REF +-> INTEGER) & ((microbenchmarks_current_integer_var_res : REF +-> INTEGER) & ((microbenchmarks_current_integer_is_initialisation(microbenchmarks_current_integer_clock___basic__) = FALSE) => (microbenchmarks_current_integer_var_res /= {})))))

INITIALISATION 
    microbenchmarks_current_integer_is_initialisation := (microbenchmarks_current_integer_clocks * {TRUE}); 
    microbenchmarks_current_integer_var_res := {}; 
    microbenchmarks_current_integer_var_tmp_0 := {}


OPERATIONS 

    microbenchmarks_current_integer_clock_step(microbenchmarks_current_integer_param_x) = 
        PRE
            (microbenchmarks_current_integer_param_x : REF --> INTEGER)
        THEN
            VAR microbenchmarks_current_integer_var_x IN
                microbenchmarks_current_integer_var_x := microbenchmarks_current_integer_param_x; 
                microbenchmarks_current_integer_var_tmp_0 := microbenchmarks_current_integer_var_x; 
                microbenchmarks_current_integer_var_res := microbenchmarks_current_integer_var_tmp_0; 
                microbenchmarks_current_integer_is_initialisation(microbenchmarks_current_integer_clock___basic__) := FALSE

            END

        END



END