MACHINE Pre6

SEES LibraryLustre

VARIABLES Pre6_is_initialisation, Pre6_var_tmp_2, Pre6_var_res1, Pre6_var_B, Pre6_var_X, Pre6_var_tmp_0, Pre6_var_res2, Pre6_var_tmp_10, Pre6_var_tmp_1, Pre6_var_tmp_11, Pre6_var_tmp_6, Pre6_var_tmp_4, Pre6_var_tmp_3, Pre6_var_tmp_5, Pre6_var_tmp_8, Pre6_var_tmp_7, Pre6_var_tmp_9

SETS Pre6_clocks = {Pre6_clock_B, Pre6_clock___basic__}

INVARIANT ((Pre6_is_initialisation : Pre6_clocks --> BOOL) & ((Pre6_var_tmp_2 : REF +-> INTEGER) & ((Pre6_var_res1 : REF +-> INTEGER) & ((Pre6_var_B : REF +-> BOOL) & ((Pre6_var_X : REF +-> INTEGER) & ((Pre6_var_tmp_0 : REF +-> INTEGER) & ((Pre6_var_res2 : REF +-> INTEGER) & ((Pre6_var_tmp_10 : REF +-> INTEGER) & ((Pre6_var_tmp_1 : REF +-> INTEGER) & ((Pre6_var_tmp_11 : REF +-> INTEGER) & ((Pre6_var_tmp_6 : REF +-> INTEGER) & ((Pre6_var_tmp_4 : REF +-> INTEGER) & ((Pre6_var_tmp_3 : REF +-> INTEGER) & ((Pre6_var_tmp_5 : REF +-> INTEGER) & ((Pre6_var_tmp_8 : REF +-> INTEGER) & ((Pre6_var_tmp_7 : REF +-> INTEGER) & ((Pre6_var_tmp_9 : REF +-> INTEGER) & (((Pre6_is_initialisation(Pre6_clock___basic__) = FALSE) => (Pre6_var_res1 /= {})) & (((Pre6_is_initialisation(Pre6_clock___basic__) = FALSE) => (Pre6_var_res2 /= {})) & ((Pre6_is_initialisation(Pre6_clock_B) = FALSE) => (Pre6_var_B /= {})))))))))))))))))))))

INITIALISATION 
    Pre6_is_initialisation := (Pre6_clocks * {TRUE}); 
    Pre6_var_tmp_2 := {}; 
    Pre6_var_res1 := {}; 
    Pre6_var_B := {}; 
    Pre6_var_X := {}; 
    Pre6_var_tmp_0 := {}; 
    Pre6_var_res2 := {}; 
    Pre6_var_tmp_10 := {}; 
    Pre6_var_tmp_1 := {}; 
    Pre6_var_tmp_11 := {}; 
    Pre6_var_tmp_6 := {}; 
    Pre6_var_tmp_4 := {}; 
    Pre6_var_tmp_3 := {}; 
    Pre6_var_tmp_5 := {}; 
    Pre6_var_tmp_8 := {}; 
    Pre6_var_tmp_7 := {}; 
    Pre6_var_tmp_9 := {}


OPERATIONS 

    Pre6_clock_step(Pre6_param_B) = 
        PRE
            (Pre6_param_B : REF --> BOOL)
        THEN
            VAR Pre6_tmp_0_history, Pre6_tmp_2_history, Pre6_tmp_9_history IN
                Pre6_tmp_0_history := Pre6_var_tmp_0; 
                Pre6_tmp_2_history := Pre6_var_tmp_2; 
                Pre6_tmp_9_history := Pre6_var_tmp_9; 
                Pre6_var_B := Pre6_param_B; 
                Pre6_var_tmp_1 := Pre6_tmp_0_history; 
                Pre6_var_X := l_fby_integer(Pre6_is_initialisation(Pre6_clock___basic__) |-> {ref |-> 1} |-> l_plus(Pre6_var_tmp_1 |-> {ref |-> 1})); 
                Pre6_var_tmp_2 := Pre6_var_X; 
                Pre6_var_tmp_3 := Pre6_tmp_2_history; 
                Pre6_var_tmp_4 := Pre6_var_tmp_3; 
                IF (Pre6_var_B = {ref |-> TRUE}) THEN 
                    Pre6_var_tmp_5 := Pre6_var_tmp_4
                END; 
                IF (Pre6_var_B = {ref |-> TRUE}) THEN 
                    Pre6_var_tmp_6 := Pre6_var_tmp_5
                END; 
                Pre6_var_res1 := Pre6_var_tmp_6; 
                Pre6_var_tmp_7 := Pre6_var_X; 
                IF (Pre6_var_B = {ref |-> TRUE}) THEN 
                    Pre6_var_tmp_8 := Pre6_var_tmp_7
                END; 
                IF (Pre6_var_B = {ref |-> TRUE}) THEN 
                    Pre6_var_tmp_9 := Pre6_var_tmp_8
                END; 
                IF (Pre6_var_B = {ref |-> TRUE}) THEN 
                    Pre6_var_tmp_10 := Pre6_tmp_9_history
                END; 
                IF (Pre6_var_B = {ref |-> TRUE}) THEN 
                    Pre6_var_tmp_11 := Pre6_var_tmp_10
                END; 
                Pre6_var_res2 := Pre6_var_tmp_11; 
                Pre6_var_tmp_0 := Pre6_var_X; 
                Pre6_is_initialisation(Pre6_clock___basic__) := FALSE; 
                IF (Pre6_var_B = {ref |-> TRUE}) THEN 
                    Pre6_is_initialisation(Pre6_clock_B) := FALSE
                END

            END

        END;

        out <-- getRes1 = BEGIN out := Pre6_var_res1 END;
        out <-- getRes2 = BEGIN out := Pre6_var_res2 END

END