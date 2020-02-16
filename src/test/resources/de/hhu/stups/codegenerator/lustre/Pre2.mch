MACHINE Pre2

SEES LibraryLustre

VARIABLES Pre2_is_initialisation, Pre2_var_tmp_2, Pre2_var_tmp_0, Pre2_var_res1, Pre2_var_clock2, Pre2_var_clock1, Pre2_var_res, Pre2_var_res2, Pre2_var_tmp_11, Pre2_var_tmp_1, Pre2_var_tmp_10, Pre2_var_tmp_12, Pre2_var_tmp_13, Pre2_var_tmp_6, Pre2_var_tmp_4, Pre2_var_tmp_3, Pre2_var_tmp_5, Pre2_var_tmp_8, Pre2_var_tmp_7, Pre2_var_tmp_9

SETS Pre2_clocks = {Pre2_clock___basic__, Pre2_clock_clock1, Pre2_clock_clock2}

INVARIANT ((Pre2_is_initialisation : Pre2_clocks --> BOOL) & ((Pre2_var_tmp_2 : REF +-> INTEGER) & ((Pre2_var_tmp_0 : REF +-> INTEGER) & ((Pre2_var_res1 : REF +-> INTEGER) & ((Pre2_var_clock2 : REF +-> BOOL) & ((Pre2_var_clock1 : REF +-> BOOL) & ((Pre2_var_res : REF +-> INTEGER) & ((Pre2_var_res2 : REF +-> INTEGER) & ((Pre2_var_tmp_11 : REF +-> INTEGER) & ((Pre2_var_tmp_1 : REF +-> INTEGER) & ((Pre2_var_tmp_10 : REF +-> INTEGER) & ((Pre2_var_tmp_12 : REF +-> INTEGER) & ((Pre2_var_tmp_13 : REF +-> INTEGER) & ((Pre2_var_tmp_6 : REF +-> INTEGER) & ((Pre2_var_tmp_4 : REF +-> INTEGER) & ((Pre2_var_tmp_3 : REF +-> INTEGER) & ((Pre2_var_tmp_5 : REF +-> INTEGER) & ((Pre2_var_tmp_8 : REF +-> INTEGER) & ((Pre2_var_tmp_7 : REF +-> INTEGER) & ((Pre2_var_tmp_9 : REF +-> INTEGER) & (((Pre2_is_initialisation(Pre2_clock___basic__) = FALSE) => (Pre2_var_res /= {})) & (((Pre2_is_initialisation(Pre2_clock___basic__) = FALSE) => (Pre2_var_res1 /= {})) & (((Pre2_is_initialisation(Pre2_clock___basic__) = FALSE) => (Pre2_var_res2 /= {})) & (((Pre2_is_initialisation(Pre2_clock_clock1) = FALSE) => (Pre2_var_clock1 /= {})) & ((Pre2_is_initialisation(Pre2_clock_clock2) = FALSE) => (Pre2_var_clock2 /= {}))))))))))))))))))))))))))

INITIALISATION 
    Pre2_is_initialisation := (Pre2_clocks * {TRUE}); 
    Pre2_var_tmp_2 := {}; 
    Pre2_var_tmp_0 := {}; 
    Pre2_var_res1 := {}; 
    Pre2_var_clock2 := {}; 
    Pre2_var_clock1 := {}; 
    Pre2_var_res := {}; 
    Pre2_var_res2 := {}; 
    Pre2_var_tmp_11 := {}; 
    Pre2_var_tmp_1 := {}; 
    Pre2_var_tmp_10 := {}; 
    Pre2_var_tmp_12 := {}; 
    Pre2_var_tmp_13 := {}; 
    Pre2_var_tmp_6 := {}; 
    Pre2_var_tmp_4 := {}; 
    Pre2_var_tmp_3 := {}; 
    Pre2_var_tmp_5 := {}; 
    Pre2_var_tmp_8 := {}; 
    Pre2_var_tmp_7 := {}; 
    Pre2_var_tmp_9 := {}


OPERATIONS 

    Pre2_clock_step(Pre2_param_clock1, Pre2_param_clock2) = 
        PRE
            ((Pre2_param_clock1 : REF --> BOOL) & (Pre2_param_clock2 : REF --> BOOL))
        THEN
            VAR Pre2_tmp_0_history, Pre2_tmp_6_history, Pre2_tmp_12_history IN
                Pre2_tmp_0_history := Pre2_var_tmp_0; 
                Pre2_tmp_6_history := Pre2_var_tmp_6; 
                Pre2_tmp_12_history := Pre2_var_tmp_12; 
                Pre2_var_clock1 := Pre2_param_clock1; 
                Pre2_var_clock2 := Pre2_param_clock2; 
                Pre2_var_tmp_1 := Pre2_tmp_0_history; 
                Pre2_var_res := l_plus(l_fby_integer(Pre2_is_initialisation(Pre2_clock___basic__) |-> {ref |-> 0} |-> Pre2_var_tmp_1) |-> {ref |-> 1}); 
                Pre2_var_tmp_2 := Pre2_var_res; 
                IF (Pre2_var_clock1 = {ref |-> TRUE}) THEN 
                    Pre2_var_tmp_3 := Pre2_var_tmp_2
                END; 
                IF (Pre2_var_clock1 = {ref |-> TRUE}) THEN 
                    Pre2_var_tmp_4 := Pre2_var_tmp_3
                END; 
                Pre2_var_tmp_5 := Pre2_var_tmp_4; 
                Pre2_var_tmp_6 := l_fby_integer(Pre2_is_initialisation(Pre2_clock___basic__) |-> l_unary_minus({ref |-> 1}) |-> Pre2_var_tmp_5); 
                Pre2_var_tmp_7 := Pre2_tmp_6_history; 
                Pre2_var_res1 := l_fby_integer(Pre2_is_initialisation(Pre2_clock___basic__) |-> {ref |-> 0} |-> Pre2_var_tmp_7); 
                Pre2_var_tmp_8 := Pre2_var_res; 
                IF (Pre2_var_clock2 = {ref |-> TRUE}) THEN 
                    Pre2_var_tmp_9 := Pre2_var_tmp_8
                END; 
                IF (Pre2_var_clock2 = {ref |-> TRUE}) THEN 
                    Pre2_var_tmp_10 := Pre2_var_tmp_9
                END; 
                Pre2_var_tmp_11 := Pre2_var_tmp_10; 
                Pre2_var_tmp_12 := l_fby_integer(Pre2_is_initialisation(Pre2_clock___basic__) |-> l_unary_minus({ref |-> 1}) |-> Pre2_var_tmp_11); 
                Pre2_var_tmp_13 := Pre2_tmp_12_history; 
                Pre2_var_res2 := l_fby_integer(Pre2_is_initialisation(Pre2_clock___basic__) |-> {ref |-> 0} |-> Pre2_var_tmp_13); 
                Pre2_var_tmp_0 := Pre2_var_res; 
                IF (Pre2_var_clock1 = {ref |-> TRUE}) THEN 
                    Pre2_is_initialisation(Pre2_clock_clock1) := FALSE
                END; 
                Pre2_is_initialisation(Pre2_clock___basic__) := FALSE; 
                IF (Pre2_var_clock2 = {ref |-> TRUE}) THEN 
                    Pre2_is_initialisation(Pre2_clock_clock2) := FALSE
                END

            END

        END;

        out <-- getRes = BEGIN out := Pre2_var_res END;
        out <-- getRes1 = BEGIN out := Pre2_var_res1 END;
        out <-- getRes2 = BEGIN out := Pre2_var_res2 END

END