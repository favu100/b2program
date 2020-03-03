MACHINE microbenchmarks_ite_integer

SEES LibraryLustre

VARIABLES microbenchmarks_ite_integer_is_initialisation, microbenchmarks_ite_integer_var_res

SETS microbenchmarks_ite_integer_clocks = {microbenchmarks_ite_integer_clock___basic__}

INVARIANT ((microbenchmarks_ite_integer_is_initialisation : microbenchmarks_ite_integer_clocks --> BOOL) & ((microbenchmarks_ite_integer_var_res : REF +-> INTEGER) & ((microbenchmarks_ite_integer_is_initialisation(microbenchmarks_ite_integer_clock___basic__) = FALSE) => (microbenchmarks_ite_integer_var_res /= {}))))

INITIALISATION 
    microbenchmarks_ite_integer_is_initialisation := (microbenchmarks_ite_integer_clocks * {TRUE}); 
    microbenchmarks_ite_integer_var_res := {}


OPERATIONS 

    microbenchmarks_ite_integer_clock_step(microbenchmarks_ite_integer_param_x, microbenchmarks_ite_integer_param_y, microbenchmarks_ite_integer_param_z) = 
        PRE
            ((microbenchmarks_ite_integer_param_x : REF --> BOOL) & ((microbenchmarks_ite_integer_param_y : REF --> INTEGER) & (microbenchmarks_ite_integer_param_z : REF --> INTEGER)))
        THEN
            VAR microbenchmarks_ite_integer_var_y, microbenchmarks_ite_integer_var_x, microbenchmarks_ite_integer_var_z IN
                microbenchmarks_ite_integer_var_x := microbenchmarks_ite_integer_param_x; 
                microbenchmarks_ite_integer_var_y := microbenchmarks_ite_integer_param_y; 
                microbenchmarks_ite_integer_var_z := microbenchmarks_ite_integer_param_z; 
                microbenchmarks_ite_integer_var_res := l_ite_integer(microbenchmarks_ite_integer_var_x |-> microbenchmarks_ite_integer_var_y |-> microbenchmarks_ite_integer_var_z); 
                microbenchmarks_ite_integer_is_initialisation(microbenchmarks_ite_integer_clock___basic__) := FALSE

            END

        END



END