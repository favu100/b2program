MACHINE Pre5

SEES LibraryLustre

VARIABLES Pre5_is_initialisation, Pre5_var_tmp_2, Pre5_var_res1, Pre5_var_B, Pre5_var_X, Pre5_var_tmp_0, Pre5_var_res2, Pre5_var_tmp_1, Pre5_var_tmp_4, Pre5_var_tmp_3, Pre5_var_tmp_6, Pre5_var_tmp_5, Pre5_var_tmp_7

SETS Pre5_clocks = {Pre5_clock_B, Pre5_clock___basic__}

INVARIANT ((Pre5_is_initialisation : Pre5_clocks --> BOOL) & ((Pre5_var_tmp_2 : REF +-> INTEGER) & ((Pre5_var_res1 : REF +-> INTEGER) & ((Pre5_var_B : REF +-> BOOL) & ((Pre5_var_X : REF +-> INTEGER) & ((Pre5_var_tmp_0 : REF +-> INTEGER) & ((Pre5_var_res2 : REF +-> INTEGER) & ((Pre5_var_tmp_1 : REF +-> INTEGER) & ((Pre5_var_tmp_4 : REF +-> INTEGER) & ((Pre5_var_tmp_3 : REF +-> INTEGER) & ((Pre5_var_tmp_6 : REF +-> INTEGER) & ((Pre5_var_tmp_5 : REF +-> INTEGER) & ((Pre5_var_tmp_7 : REF +-> INTEGER) & (((Pre5_is_initialisation(Pre5_clock_B) = FALSE) => (Pre5_var_res1 /= {})) & (((Pre5_is_initialisation(Pre5_clock_B) = FALSE) => (Pre5_var_res2 /= {})) & ((Pre5_is_initialisation(Pre5_clock_B) = FALSE) => (Pre5_var_B /= {})))))))))))))))))

INITIALISATION 
    Pre5_is_initialisation := (Pre5_clocks * {TRUE}); 
    Pre5_var_tmp_2 := {}; 
    Pre5_var_res1 := {}; 
    Pre5_var_B := {}; 
    Pre5_var_X := {}; 
    Pre5_var_tmp_0 := {}; 
    Pre5_var_res2 := {}; 
    Pre5_var_tmp_1 := {}; 
    Pre5_var_tmp_4 := {}; 
    Pre5_var_tmp_3 := {}; 
    Pre5_var_tmp_6 := {}; 
    Pre5_var_tmp_5 := {}; 
    Pre5_var_tmp_7 := {}


OPERATIONS 

    Pre5_clock_step(Pre5_param_B) = 
        PRE
            (Pre5_param_B : REF --> BOOL)
        THEN
            VAR Pre5_tmp_0_history, Pre5_tmp_2_history, Pre5_tmp_7_history IN
                Pre5_tmp_0_history := Pre5_var_tmp_0; 
                Pre5_tmp_2_history := Pre5_var_tmp_2; 
                Pre5_tmp_7_history := Pre5_var_tmp_7; 
                Pre5_var_B := Pre5_param_B; 
                Pre5_var_tmp_1 := Pre5_tmp_0_history; 
                Pre5_var_X := l_fby_integer(Pre5_is_initialisation(Pre5_clock___basic__) |-> {ref |-> 1} |-> l_plus(Pre5_var_tmp_1 |-> {ref |-> 1})); 
                Pre5_var_tmp_2 := Pre5_var_X; 
                Pre5_var_tmp_3 := Pre5_tmp_2_history; 
                Pre5_var_tmp_4 := Pre5_var_tmp_3; 
                IF (Pre5_var_B = {ref |-> TRUE}) THEN 
                    Pre5_var_res1 := Pre5_var_tmp_4
                END; 
                Pre5_var_tmp_5 := Pre5_var_X; 
                IF (Pre5_var_B = {ref |-> TRUE}) THEN 
                    Pre5_var_tmp_6 := Pre5_var_tmp_5
                END; 
                IF (Pre5_var_B = {ref |-> TRUE}) THEN 
                    Pre5_var_tmp_7 := Pre5_var_tmp_6
                END; 
                IF (Pre5_var_B = {ref |-> TRUE}) THEN 
                    Pre5_var_res2 := Pre5_tmp_7_history
                END; 
                Pre5_var_tmp_0 := Pre5_var_X; 
                Pre5_is_initialisation(Pre5_clock___basic__) := FALSE; 
                IF (Pre5_var_B = {ref |-> TRUE}) THEN 
                    Pre5_is_initialisation(Pre5_clock_B) := FALSE
                END

            END

        END;

        out <-- getRes1 = BEGIN out := Pre5_var_res1 END;
        out <-- getRes2 = BEGIN out := Pre5_var_res2 END



END