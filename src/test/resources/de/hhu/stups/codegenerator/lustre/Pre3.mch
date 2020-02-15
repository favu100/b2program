MACHINE Pre3

VARIABLES Pre3_is_initialisation, Pre3_var_tmp_0, Pre3_var_a, Pre3_var_x

SETS Pre3_clocks = {Pre3_clock___basic__}; Pre3_refs = {Pre3_ref}

INVARIANT ((Pre3_is_initialisation : Pre3_clocks --> BOOL) & ((Pre3_var_tmp_0 : Pre3_refs +-> INTEGER) & ((Pre3_var_a : Pre3_refs +-> INTEGER) & ((Pre3_var_x : Pre3_refs +-> BOOL) & ((Pre3_is_initialisation(Pre3_clock___basic__) = FALSE) => (Pre3_var_a /= {}))))))

INITIALISATION 
    Pre3_is_initialisation := (Pre3_clocks * {TRUE}); 
    Pre3_var_tmp_0 := {}; 
    Pre3_var_a := {}; 
    Pre3_var_x := {}


OPERATIONS 

    Pre3_clock_step(Pre3_param_x) = 
        PRE
            (Pre3_param_x : BOOL)
        THEN
            VAR Pre3_tmp_0_history IN
                Pre3_tmp_0_history := Pre3_var_tmp_0; 
                Pre3_var_x(Pre3_ref) := bool((Pre3_param_x = TRUE)); 
                Pre3_var_tmp_0(Pre3_ref) := 1; 
                IF (Pre3_tmp_0_history /= {}) THEN 
                    Pre3_var_a(Pre3_ref) := Pre3_tmp_0_history(Pre3_ref)
                ELSE 
                    Pre3_var_a := {}
                END; 
                Pre3_is_initialisation(Pre3_clock___basic__) := FALSE

            END

        END;

        out <-- getA = BEGIN out := Pre3_var_a END



END