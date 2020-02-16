MACHINE Current2

SEES LibraryLustre

VARIABLES Current2_is_initialisation, Current2_var_tmp_2, Current2_var_res1, Current2_var_clock2, Current2_var_clock1, Current2_var_res, Current2_var_tmp_0, Current2_var_res2, Current2_var_tmp_1, Current2_var_tmp_4, Current2_var_tmp_3, Current2_var_tmp_6, Current2_var_tmp_5, Current2_var_tmp_7

SETS Current2_clocks = {Current2_clock___basic__, Current2_clock_clock1, Current2_clock_clock2}

INVARIANT ((Current2_is_initialisation : Current2_clocks --> BOOL) & ((Current2_var_tmp_2 : REF +-> INTEGER) & ((Current2_var_res1 : REF +-> INTEGER) & ((Current2_var_clock2 : REF +-> BOOL) & ((Current2_var_clock1 : REF +-> BOOL) & ((Current2_var_res : REF +-> INTEGER) & ((Current2_var_tmp_0 : REF +-> INTEGER) & ((Current2_var_res2 : REF +-> INTEGER) & ((Current2_var_tmp_1 : REF +-> INTEGER) & ((Current2_var_tmp_4 : REF +-> INTEGER) & ((Current2_var_tmp_3 : REF +-> INTEGER) & ((Current2_var_tmp_6 : REF +-> INTEGER) & ((Current2_var_tmp_5 : REF +-> INTEGER) & ((Current2_var_tmp_7 : REF +-> INTEGER) & (((Current2_is_initialisation(Current2_clock___basic__) = FALSE) => (Current2_var_res /= {})) & (((Current2_is_initialisation(Current2_clock___basic__) = FALSE) => (Current2_var_res1 /= {})) & (((Current2_is_initialisation(Current2_clock___basic__) = FALSE) => (Current2_var_res2 /= {})) & (((Current2_is_initialisation(Current2_clock_clock1) = FALSE) => (Current2_var_clock1 /= {})) & ((Current2_is_initialisation(Current2_clock_clock2) = FALSE) => (Current2_var_clock2 /= {}))))))))))))))))))))

INITIALISATION 
    Current2_is_initialisation := (Current2_clocks * {TRUE}); 
    Current2_var_tmp_2 := {}; 
    Current2_var_res1 := {}; 
    Current2_var_clock2 := {}; 
    Current2_var_clock1 := {}; 
    Current2_var_res := {}; 
    Current2_var_tmp_0 := {}; 
    Current2_var_res2 := {}; 
    Current2_var_tmp_1 := {}; 
    Current2_var_tmp_4 := {}; 
    Current2_var_tmp_3 := {}; 
    Current2_var_tmp_6 := {}; 
    Current2_var_tmp_5 := {}; 
    Current2_var_tmp_7 := {}


OPERATIONS 

    Current2_clock_step(Current2_param_clock1, Current2_param_clock2) = 
        PRE
            ((Current2_param_clock1 : REF --> BOOL) & (Current2_param_clock2 : REF --> BOOL))
        THEN
            VAR Current2_tmp_0_history IN
                Current2_tmp_0_history := Current2_var_tmp_0; 
                Current2_var_clock1 := Current2_param_clock1; 
                Current2_var_clock2 := Current2_param_clock2; 
                Current2_var_tmp_1 := Current2_tmp_0_history; 
                Current2_var_res := l_plus(l_fby_integer(Current2_is_initialisation(Current2_clock___basic__) |-> {ref |-> 0} |-> Current2_var_tmp_1) |-> {ref |-> 1}); 
                Current2_var_tmp_2 := Current2_var_res; 
                IF (Current2_var_clock1 = {ref |-> TRUE}) THEN 
                    Current2_var_tmp_3 := Current2_var_tmp_2
                END; 
                IF (Current2_var_clock1 = {ref |-> TRUE}) THEN 
                    Current2_var_tmp_4 := Current2_var_tmp_3
                END; 
                Current2_var_res1 := Current2_var_tmp_4; 
                Current2_var_tmp_5 := Current2_var_res; 
                IF (Current2_var_clock2 = {ref |-> TRUE}) THEN 
                    Current2_var_tmp_6 := Current2_var_tmp_5
                END; 
                IF (Current2_var_clock2 = {ref |-> TRUE}) THEN 
                    Current2_var_tmp_7 := Current2_var_tmp_6
                END; 
                Current2_var_res2 := Current2_var_tmp_7; 
                Current2_var_tmp_0 := Current2_var_res; 
                IF (Current2_var_clock1 = {ref |-> TRUE}) THEN 
                    Current2_is_initialisation(Current2_clock_clock1) := FALSE
                END; 
                Current2_is_initialisation(Current2_clock___basic__) := FALSE; 
                IF (Current2_var_clock2 = {ref |-> TRUE}) THEN 
                    Current2_is_initialisation(Current2_clock_clock2) := FALSE
                END

            END

        END;

        out <-- getRes = BEGIN out := Current2_var_res END;
        out <-- getRes1 = BEGIN out := Current2_var_res1 END;
        out <-- getRes2 = BEGIN out := Current2_var_res2 END

END