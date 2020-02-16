MACHINE Pre3

SEES LibraryLustre

VARIABLES Pre3_is_initialisation, Pre3_var_tmp_0, Pre3_var_a, Pre3_var_x

SETS Pre3_clocks = {Pre3_clock___basic__}

INVARIANT ((Pre3_is_initialisation : Pre3_clocks --> BOOL) & ((Pre3_var_tmp_0 : REF +-> INTEGER) & ((Pre3_var_a : REF +-> INTEGER) & ((Pre3_var_x : REF +-> BOOL) & ((Pre3_is_initialisation(Pre3_clock___basic__) = FALSE) => (Pre3_var_a /= {}))))))

INITIALISATION 
    Pre3_is_initialisation := (Pre3_clocks * {TRUE}); 
    Pre3_var_tmp_0 := {}; 
    Pre3_var_a := {}; 
    Pre3_var_x := {}


OPERATIONS 

    Pre3_clock_step(Pre3_param_x) = 
        PRE
            (Pre3_param_x : REF --> BOOL)
        THEN
            VAR Pre3_tmp_0_history IN
                Pre3_tmp_0_history := Pre3_var_tmp_0; 
                Pre3_var_x := Pre3_param_x; 
                Pre3_var_tmp_0 := {ref |-> 1}; 
                Pre3_var_a := Pre3_tmp_0_history; 
                Pre3_is_initialisation(Pre3_clock___basic__) := FALSE

            END

        END;

        out <-- getA = BEGIN out := Pre3_var_a END



END