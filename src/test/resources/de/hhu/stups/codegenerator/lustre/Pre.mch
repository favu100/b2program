MACHINE Pre

SEES LibraryLustre

VARIABLES Pre_is_initialisation, Pre_var_tmp_3, Pre_var_tmp_0, Pre_var_c, Pre_var_b, Pre_var_a, Pre_var_e, Pre_var_d, Pre_var_tmp_16, Pre_var_tmp_12, Pre_var_tmp_10, Pre_var_tmp_1, Pre_var_tmp_11, Pre_var_tmp_14, Pre_var_tmp_13, Pre_var_tmp_15, Pre_var_tmp_18, Pre_var_tmp_17, Pre_var_tmp_2, Pre_var_tmp_19, Pre_var_tmp_6, Pre_var_tmp_5, Pre_var_tmp_4, Pre_var_x, Pre_var_tmp_8, Pre_var_tmp_7, Pre_var_tmp_9, Pre_var_y

SETS Pre_clocks = {Pre_clock___basic__}

INVARIANT ((Pre_is_initialisation : Pre_clocks --> BOOL) & ((Pre_var_tmp_3 : REF +-> INTEGER) & ((Pre_var_tmp_0 : REF +-> INTEGER) & ((Pre_var_c : REF +-> INTEGER) & ((Pre_var_b : REF +-> INTEGER) & ((Pre_var_a : REF +-> INTEGER) & ((Pre_var_e : REF +-> INTEGER) & ((Pre_var_d : REF +-> INTEGER) & ((Pre_var_tmp_16 : REF +-> INTEGER) & ((Pre_var_tmp_12 : REF +-> INTEGER) & ((Pre_var_tmp_10 : REF +-> INTEGER) & ((Pre_var_tmp_1 : REF +-> INTEGER) & ((Pre_var_tmp_11 : REF +-> INTEGER) & ((Pre_var_tmp_14 : REF +-> INTEGER) & ((Pre_var_tmp_13 : REF +-> INTEGER) & ((Pre_var_tmp_15 : REF +-> INTEGER) & ((Pre_var_tmp_18 : REF +-> INTEGER) & ((Pre_var_tmp_17 : REF +-> INTEGER) & ((Pre_var_tmp_2 : REF +-> INTEGER) & ((Pre_var_tmp_19 : REF +-> INTEGER) & ((Pre_var_tmp_6 : REF +-> INTEGER) & ((Pre_var_tmp_5 : REF +-> INTEGER) & ((Pre_var_tmp_4 : REF +-> INTEGER) & ((Pre_var_x : REF +-> INTEGER) & ((Pre_var_tmp_8 : REF +-> INTEGER) & ((Pre_var_tmp_7 : REF +-> INTEGER) & ((Pre_var_tmp_9 : REF +-> INTEGER) & ((Pre_var_y : REF +-> INTEGER) & (((Pre_is_initialisation(Pre_clock___basic__) = FALSE) => (Pre_var_a /= {})) & (((Pre_is_initialisation(Pre_clock___basic__) = FALSE) => (Pre_var_b /= {})) & (((Pre_is_initialisation(Pre_clock___basic__) = FALSE) => (Pre_var_c /= {})) & (((Pre_is_initialisation(Pre_clock___basic__) = FALSE) => (Pre_var_d /= {})) & ((Pre_is_initialisation(Pre_clock___basic__) = FALSE) => (Pre_var_e /= {}))))))))))))))))))))))))))))))))))

INITIALISATION 
    Pre_is_initialisation := (Pre_clocks * {TRUE}); 
    Pre_var_tmp_3 := {}; 
    Pre_var_tmp_0 := {}; 
    Pre_var_c := {}; 
    Pre_var_b := {}; 
    Pre_var_a := {}; 
    Pre_var_e := {}; 
    Pre_var_d := {}; 
    Pre_var_tmp_16 := {}; 
    Pre_var_tmp_12 := {}; 
    Pre_var_tmp_10 := {}; 
    Pre_var_tmp_1 := {}; 
    Pre_var_tmp_11 := {}; 
    Pre_var_tmp_14 := {}; 
    Pre_var_tmp_13 := {}; 
    Pre_var_tmp_15 := {}; 
    Pre_var_tmp_18 := {}; 
    Pre_var_tmp_17 := {}; 
    Pre_var_tmp_2 := {}; 
    Pre_var_tmp_19 := {}; 
    Pre_var_tmp_6 := {}; 
    Pre_var_tmp_5 := {}; 
    Pre_var_tmp_4 := {}; 
    Pre_var_x := {}; 
    Pre_var_tmp_8 := {}; 
    Pre_var_tmp_7 := {}; 
    Pre_var_tmp_9 := {}; 
    Pre_var_y := {}


OPERATIONS 

    Pre_clock_step(Pre_param_x, Pre_param_y) = 
        PRE
            ((Pre_param_x : REF --> INTEGER) & (Pre_param_y : REF --> INTEGER))
        THEN
            VAR Pre_tmp_0_history, Pre_tmp_2_history, Pre_tmp_4_history, Pre_tmp_6_history, Pre_tmp_8_history, Pre_tmp_10_history, Pre_tmp_12_history, Pre_tmp_14_history, Pre_tmp_16_history, Pre_tmp_18_history IN
                Pre_tmp_0_history := Pre_var_tmp_0; 
                Pre_tmp_2_history := Pre_var_tmp_2; 
                Pre_tmp_4_history := Pre_var_tmp_4; 
                Pre_tmp_6_history := Pre_var_tmp_6; 
                Pre_tmp_8_history := Pre_var_tmp_8; 
                Pre_tmp_10_history := Pre_var_tmp_10; 
                Pre_tmp_12_history := Pre_var_tmp_12; 
                Pre_tmp_14_history := Pre_var_tmp_14; 
                Pre_tmp_16_history := Pre_var_tmp_16; 
                Pre_tmp_18_history := Pre_var_tmp_18; 
                Pre_var_x := Pre_param_x; 
                Pre_var_y := Pre_param_y; 
                Pre_var_tmp_0 := Pre_var_x; 
                Pre_var_tmp_1 := Pre_tmp_0_history; 
                Pre_var_a := l_fby_integer(Pre_is_initialisation(Pre_clock___basic__) |-> {ref |-> 0} |-> Pre_var_tmp_1); 
                Pre_var_tmp_2 := Pre_var_x; 
                Pre_var_tmp_3 := Pre_tmp_2_history; 
                Pre_var_tmp_4 := Pre_var_y; 
                Pre_var_tmp_5 := Pre_tmp_4_history; 
                Pre_var_b := l_fby_integer(Pre_is_initialisation(Pre_clock___basic__) |-> {ref |-> 0} |-> l_plus(Pre_var_tmp_3 |-> Pre_var_tmp_5)); 
                Pre_var_tmp_6 := l_plus(Pre_var_x |-> Pre_var_y); 
                Pre_var_tmp_7 := Pre_tmp_6_history; 
                Pre_var_c := l_fby_integer(Pre_is_initialisation(Pre_clock___basic__) |-> {ref |-> 0} |-> Pre_var_tmp_7); 
                Pre_var_tmp_8 := Pre_var_x; 
                Pre_var_tmp_9 := Pre_tmp_8_history; 
                Pre_var_tmp_10 := l_fby_integer(Pre_is_initialisation(Pre_clock___basic__) |-> {ref |-> 2} |-> Pre_var_tmp_9); 
                Pre_var_tmp_11 := Pre_tmp_10_history; 
                Pre_var_tmp_12 := l_fby_integer(Pre_is_initialisation(Pre_clock___basic__) |-> {ref |-> 1} |-> Pre_var_tmp_11); 
                Pre_var_tmp_13 := Pre_tmp_12_history; 
                Pre_var_d := l_fby_integer(Pre_is_initialisation(Pre_clock___basic__) |-> {ref |-> 0} |-> Pre_var_tmp_13); 
                Pre_var_tmp_14 := Pre_var_x; 
                Pre_var_tmp_15 := Pre_tmp_14_history; 
                Pre_var_tmp_16 := l_fby_integer(Pre_is_initialisation(Pre_clock___basic__) |-> {ref |-> 1} |-> Pre_var_tmp_15); 
                Pre_var_tmp_17 := Pre_tmp_16_history; 
                Pre_var_tmp_18 := Pre_var_y; 
                Pre_var_tmp_19 := Pre_tmp_18_history; 
                Pre_var_e := l_fby_integer(Pre_is_initialisation(Pre_clock___basic__) |-> {ref |-> 0} |-> l_fby_integer(Pre_is_initialisation(Pre_clock___basic__) |-> l_plus(Pre_var_tmp_17 |-> {ref |-> 0}) |-> Pre_var_tmp_19)); 
                Pre_is_initialisation(Pre_clock___basic__) := FALSE

            END

        END;

        out <-- getD = BEGIN out := Pre_var_d END



END