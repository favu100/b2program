MACHINE Clock4

SEES LibraryLustre

VARIABLES Clock4_is_initialisation, Clock4_var_tmp_0, Clock4_var_clock2, Clock4_var_clock1, Clock4_var_res, Clock4_var_tmp_2, Clock4_var_tmp_1, Clock4_var_val

SETS Clock4_clocks = {Clock4_clock___basic__, Clock4_clock_clock1, Clock4_clock_clock2}

INVARIANT ((Clock4_is_initialisation : Clock4_clocks --> BOOL) & ((Clock4_var_tmp_0 : REF +-> INTEGER) & ((Clock4_var_clock2 : REF +-> BOOL) & ((Clock4_var_clock1 : REF +-> BOOL) & ((Clock4_var_res : REF +-> INTEGER) & ((Clock4_var_tmp_2 : REF +-> INTEGER) & ((Clock4_var_tmp_1 : REF +-> INTEGER) & ((Clock4_var_val : REF +-> INTEGER) & (((Clock4_is_initialisation(Clock4_clock_clock2) = FALSE) => (Clock4_var_res /= {})) & (((Clock4_is_initialisation(Clock4_clock_clock1) = FALSE) => (Clock4_var_clock1 /= {})) & ((Clock4_is_initialisation(Clock4_clock_clock2) = FALSE) => (Clock4_var_clock2 /= {}))))))))))))

INITIALISATION 
    Clock4_is_initialisation := (Clock4_clocks * {TRUE}); 
    Clock4_var_tmp_0 := {}; 
    Clock4_var_clock2 := {}; 
    Clock4_var_clock1 := {}; 
    Clock4_var_res := {}; 
    Clock4_var_tmp_2 := {}; 
    Clock4_var_tmp_1 := {}; 
    Clock4_var_val := {}


OPERATIONS 

    Clock4_clock_step(Clock4_param_val, Clock4_param_clock1, Clock4_param_clock2) = 
        PRE
            ((Clock4_param_val : REF --> INTEGER) & ((Clock4_param_clock1 : REF --> BOOL) & (Clock4_param_clock2 : REF --> BOOL)))
        THEN
            Clock4_var_val := Clock4_param_val; 
            Clock4_var_clock1 := Clock4_param_clock1; 
            IF (Clock4_var_clock1 = {ref |-> TRUE}) THEN 
                Clock4_var_clock2 := Clock4_param_clock2
            END; 
            Clock4_var_tmp_0 := Clock4_var_val; 
            IF (Clock4_var_clock1 = {ref |-> TRUE}) THEN 
                Clock4_var_tmp_1 := Clock4_var_tmp_0
            END; 
            IF (Clock4_var_clock1 = {ref |-> TRUE}) THEN 
                Clock4_var_tmp_2 := Clock4_var_tmp_1
            END; 
            IF ((Clock4_var_clock1 = {ref |-> TRUE}) & (Clock4_var_clock2 = {ref |-> TRUE})) THEN 
                Clock4_var_res := Clock4_var_tmp_2
            END; 
            IF (Clock4_var_clock1 = {ref |-> TRUE}) THEN 
                Clock4_is_initialisation(Clock4_clock_clock1) := FALSE
            END; 
            Clock4_is_initialisation(Clock4_clock___basic__) := FALSE; 
            IF ((Clock4_var_clock1 = {ref |-> TRUE}) & (Clock4_var_clock2 = {ref |-> TRUE})) THEN 
                Clock4_is_initialisation(Clock4_clock_clock2) := FALSE
            END

        END



END