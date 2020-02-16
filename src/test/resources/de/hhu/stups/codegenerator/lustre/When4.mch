MACHINE When4

SEES LibraryLustre

VARIABLES When4_is_initialisation, When4_var_clock, When4_var_a, When4_var_b, When4_var_res, When4_var_tmp_0

SETS When4_clocks = {When4_clock___basic__, When4_clock_clock}

INVARIANT ((When4_is_initialisation : When4_clocks --> BOOL) & ((When4_var_clock : REF +-> BOOL) & ((When4_var_a : REF +-> INTEGER) & ((When4_var_b : REF +-> INTEGER) & ((When4_var_res : REF +-> INTEGER) & ((When4_var_tmp_0 : REF +-> INTEGER) & (((When4_is_initialisation(When4_clock_clock) = FALSE) => (When4_var_res /= {})) & ((When4_is_initialisation(When4_clock_clock) = FALSE) => (When4_var_clock /= {})))))))))

INITIALISATION 
    When4_is_initialisation := (When4_clocks * {TRUE}); 
    When4_var_clock := {}; 
    When4_var_a := {}; 
    When4_var_b := {}; 
    When4_var_res := {}; 
    When4_var_tmp_0 := {}


OPERATIONS 

    When4_clock_step(When4_param_clock) = 
        PRE
            (When4_param_clock : REF --> BOOL)
        THEN
            When4_var_clock := When4_param_clock; 
            When4_var_a := {ref |-> 1}; 
            When4_var_b := {ref |-> 2}; 
            When4_var_tmp_0 := l_fby_integer(When4_is_initialisation(When4_clock___basic__) |-> When4_var_a |-> When4_var_b); 
            IF (When4_var_clock = {ref |-> TRUE}) THEN 
                When4_var_res := When4_var_tmp_0
            END; 
            When4_is_initialisation(When4_clock___basic__) := FALSE; 
            IF (When4_var_clock = {ref |-> TRUE}) THEN 
                When4_is_initialisation(When4_clock_clock) := FALSE
            END

        END;


        out <-- getRes = BEGIN out := When4_var_res END



END