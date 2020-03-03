MACHINE microbenchmarks_unequal_boolean

SEES LibraryLustre

VARIABLES microbenchmarks_unequal_boolean_is_initialisation, microbenchmarks_unequal_boolean_var_res

SETS microbenchmarks_unequal_boolean_clocks = {microbenchmarks_unequal_boolean_clock___basic__}

INVARIANT ((microbenchmarks_unequal_boolean_is_initialisation : microbenchmarks_unequal_boolean_clocks --> BOOL) & ((microbenchmarks_unequal_boolean_var_res : REF +-> BOOL) & ((microbenchmarks_unequal_boolean_is_initialisation(microbenchmarks_unequal_boolean_clock___basic__) = FALSE) => (microbenchmarks_unequal_boolean_var_res /= {}))))

INITIALISATION
    microbenchmarks_unequal_boolean_is_initialisation := (microbenchmarks_unequal_boolean_clocks * {TRUE});
    microbenchmarks_unequal_boolean_var_res := {}


OPERATIONS

    microbenchmarks_unequal_boolean_clock_step(microbenchmarks_unequal_boolean_param_x, microbenchmarks_unequal_boolean_param_y) =
        PRE
            ((microbenchmarks_unequal_boolean_param_x : REF --> BOOL) & (microbenchmarks_unequal_boolean_param_y : REF --> BOOL))
        THEN
            VAR microbenchmarks_unequal_boolean_var_x, microbenchmarks_unequal_boolean_var_y IN
                microbenchmarks_unequal_boolean_var_x := microbenchmarks_unequal_boolean_param_x;
                microbenchmarks_unequal_boolean_var_y := microbenchmarks_unequal_boolean_param_y;
                microbenchmarks_unequal_boolean_var_res := l_unequal_boolean(microbenchmarks_unequal_boolean_var_x |-> microbenchmarks_unequal_boolean_var_y);
                microbenchmarks_unequal_boolean_is_initialisation(microbenchmarks_unequal_boolean_clock___basic__) := FALSE

            END

        END



END
