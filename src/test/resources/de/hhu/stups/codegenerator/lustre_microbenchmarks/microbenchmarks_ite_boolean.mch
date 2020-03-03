MACHINE microbenchmarks_ite_boolean

SEES LibraryLustre

VARIABLES microbenchmarks_ite_boolean_is_initialisation, microbenchmarks_ite_boolean_var_res

SETS microbenchmarks_ite_boolean_clocks = {microbenchmarks_ite_boolean_clock___basic__}

INVARIANT ((microbenchmarks_ite_boolean_is_initialisation : microbenchmarks_ite_boolean_clocks --> BOOL) & ((microbenchmarks_ite_boolean_var_res : REF +-> BOOL) & ((microbenchmarks_ite_boolean_is_initialisation(microbenchmarks_ite_boolean_clock___basic__) = FALSE) => (microbenchmarks_ite_boolean_var_res /= {}))))

INITIALISATION 
    microbenchmarks_ite_boolean_is_initialisation := (microbenchmarks_ite_boolean_clocks * {TRUE}); 
    microbenchmarks_ite_boolean_var_res := {}


OPERATIONS 

    microbenchmarks_ite_boolean_clock_step(microbenchmarks_ite_boolean_param_x, microbenchmarks_ite_boolean_param_y, microbenchmarks_ite_boolean_param_z) = 
        PRE
            ((microbenchmarks_ite_boolean_param_x : REF --> BOOL) & ((microbenchmarks_ite_boolean_param_y : REF --> BOOL) & (microbenchmarks_ite_boolean_param_z : REF --> BOOL)))
        THEN
            VAR microbenchmarks_ite_boolean_var_y, microbenchmarks_ite_boolean_var_x, microbenchmarks_ite_boolean_var_z IN
                microbenchmarks_ite_boolean_var_x := microbenchmarks_ite_boolean_param_x; 
                microbenchmarks_ite_boolean_var_y := microbenchmarks_ite_boolean_param_y; 
                microbenchmarks_ite_boolean_var_z := microbenchmarks_ite_boolean_param_z; 
                microbenchmarks_ite_boolean_var_res := l_ite_boolean(microbenchmarks_ite_boolean_var_x |-> microbenchmarks_ite_boolean_var_y |-> microbenchmarks_ite_boolean_var_z); 
                microbenchmarks_ite_boolean_is_initialisation(microbenchmarks_ite_boolean_clock___basic__) := FALSE

            END

        END



END