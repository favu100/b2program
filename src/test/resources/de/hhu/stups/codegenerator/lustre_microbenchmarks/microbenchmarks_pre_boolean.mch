MACHINE microbenchmarks_pre_boolean

SEES LibraryLustre

VARIABLES microbenchmarks_pre_boolean_is_initialisation, microbenchmarks_pre_boolean_var_res, microbenchmarks_pre_boolean_var_tmp_0

SETS microbenchmarks_pre_boolean_clocks = {microbenchmarks_pre_boolean_clock___basic__}

INVARIANT ((microbenchmarks_pre_boolean_is_initialisation : microbenchmarks_pre_boolean_clocks --> BOOL) & ((microbenchmarks_pre_boolean_var_tmp_0 : REF +-> BOOL) & ((microbenchmarks_pre_boolean_var_res : REF +-> BOOL) & ((microbenchmarks_pre_boolean_is_initialisation(microbenchmarks_pre_boolean_clock___basic__) = FALSE) => (microbenchmarks_pre_boolean_var_res /= {})))))

INITIALISATION 
    microbenchmarks_pre_boolean_is_initialisation := (microbenchmarks_pre_boolean_clocks * {TRUE}); 
    microbenchmarks_pre_boolean_var_res := {}; 
    microbenchmarks_pre_boolean_var_tmp_0 := {}


OPERATIONS 

    microbenchmarks_pre_boolean_clock_step(microbenchmarks_pre_boolean_param_x) = 
        PRE
            (microbenchmarks_pre_boolean_param_x : REF --> BOOL)
        THEN
            VAR microbenchmarks_pre_boolean_tmp_0_history, microbenchmarks_pre_boolean_var_x IN
                microbenchmarks_pre_boolean_tmp_0_history := microbenchmarks_pre_boolean_var_tmp_0; 
                microbenchmarks_pre_boolean_var_x := microbenchmarks_pre_boolean_param_x; 
                microbenchmarks_pre_boolean_var_tmp_0 := microbenchmarks_pre_boolean_var_x; 
                microbenchmarks_pre_boolean_var_res := microbenchmarks_pre_boolean_tmp_0_history; 
                microbenchmarks_pre_boolean_is_initialisation(microbenchmarks_pre_boolean_clock___basic__) := FALSE

            END

        END



END