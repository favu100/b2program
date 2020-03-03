MACHINE microbenchmarks_pre_integer

SEES LibraryLustre

VARIABLES microbenchmarks_pre_integer_is_initialisation, microbenchmarks_pre_integer_var_res, microbenchmarks_pre_integer_var_tmp_0

SETS microbenchmarks_pre_integer_clocks = {microbenchmarks_pre_integer_clock___basic__}

INVARIANT ((microbenchmarks_pre_integer_is_initialisation : microbenchmarks_pre_integer_clocks --> BOOL) & ((microbenchmarks_pre_integer_var_tmp_0 : REF +-> INTEGER) & ((microbenchmarks_pre_integer_var_res : REF +-> INTEGER) & ((microbenchmarks_pre_integer_is_initialisation(microbenchmarks_pre_integer_clock___basic__) = FALSE) => (microbenchmarks_pre_integer_var_res /= {})))))

INITIALISATION 
    microbenchmarks_pre_integer_is_initialisation := (microbenchmarks_pre_integer_clocks * {TRUE}); 
    microbenchmarks_pre_integer_var_res := {}; 
    microbenchmarks_pre_integer_var_tmp_0 := {}


OPERATIONS 

    microbenchmarks_pre_integer_clock_step(microbenchmarks_pre_integer_param_x) = 
        PRE
            (microbenchmarks_pre_integer_param_x : REF --> INTEGER)
        THEN
            VAR microbenchmarks_pre_integer_tmp_0_history, microbenchmarks_pre_integer_var_x IN
                microbenchmarks_pre_integer_tmp_0_history := microbenchmarks_pre_integer_var_tmp_0; 
                microbenchmarks_pre_integer_var_x := microbenchmarks_pre_integer_param_x; 
                microbenchmarks_pre_integer_var_tmp_0 := microbenchmarks_pre_integer_var_x; 
                microbenchmarks_pre_integer_var_res := microbenchmarks_pre_integer_tmp_0_history; 
                microbenchmarks_pre_integer_is_initialisation(microbenchmarks_pre_integer_clock___basic__) := FALSE

            END

        END



END