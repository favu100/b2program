MACHINE microbenchmarks_unequal_integer

SEES LibraryLustre

VARIABLES microbenchmarks_unequal_integer_is_initialisation, microbenchmarks_unequal_integer_var_res

SETS microbenchmarks_unequal_integer_clocks = {microbenchmarks_unequal_integer_clock___basic__}

INVARIANT ((microbenchmarks_unequal_integer_is_initialisation : microbenchmarks_unequal_integer_clocks --> BOOL) & ((microbenchmarks_unequal_integer_var_res : REF +-> BOOL) & ((microbenchmarks_unequal_integer_is_initialisation(microbenchmarks_unequal_integer_clock___basic__) = FALSE) => (microbenchmarks_unequal_integer_var_res /= {}))))

INITIALISATION
    microbenchmarks_unequal_integer_is_initialisation := (microbenchmarks_unequal_integer_clocks * {TRUE});
    microbenchmarks_unequal_integer_var_res := {}


OPERATIONS

    microbenchmarks_unequal_integer_clock_step(microbenchmarks_unequal_integer_param_x, microbenchmarks_unequal_integer_param_y) =
        PRE
            ((microbenchmarks_unequal_integer_param_x : REF --> INTEGER) & (microbenchmarks_unequal_integer_param_y : REF --> INTEGER))
        THEN
            VAR microbenchmarks_unequal_integer_var_x, microbenchmarks_unequal_integer_var_y IN
                microbenchmarks_unequal_integer_var_x := microbenchmarks_unequal_integer_param_x;
                microbenchmarks_unequal_integer_var_y := microbenchmarks_unequal_integer_param_y;
                microbenchmarks_unequal_integer_var_res := l_unequal_integer(microbenchmarks_unequal_integer_var_x |-> microbenchmarks_unequal_integer_var_y);
                microbenchmarks_unequal_integer_is_initialisation(microbenchmarks_unequal_integer_clock___basic__) := FALSE

            END

        END



END
