MACHINE When8

INCLUDES Node_1.invoked_node, Node_2.invoked_node, Node_3.invoked_node

SEES LibraryLustre

VARIABLES When8_is_initialisation, When8_var_res1, When8_var_clock2, When8_var_clock1, When8_var_res, When8_var_tmp_0, When8_var_res2, When8_var_tmp_1

SETS When8_clocks = {When8_clock___basic__, When8_clock_clock1, When8_clock_clock2}

INVARIANT ((When8_is_initialisation : When8_clocks --> BOOL) & ((When8_var_res1 : REF +-> INTEGER) & ((When8_var_clock2 : REF +-> BOOL) & ((When8_var_clock1 : REF +-> BOOL) & ((When8_var_res : REF +-> INTEGER) & ((When8_var_tmp_0 : REF +-> INTEGER) & ((When8_var_res2 : REF +-> INTEGER) & ((When8_var_tmp_1 : REF +-> INTEGER) & (((When8_is_initialisation(When8_clock___basic__) = FALSE) => (When8_var_res /= {})) & (((When8_is_initialisation(When8_clock_clock1) = FALSE) => (When8_var_res1 /= {})) & (((When8_is_initialisation(When8_clock_clock2) = FALSE) => (When8_var_res2 /= {})) & (((When8_is_initialisation(When8_clock_clock1) = FALSE) => (When8_var_clock1 /= {})) & ((When8_is_initialisation(When8_clock_clock2) = FALSE) => (When8_var_clock2 /= {}))))))))))))))

INITIALISATION 
    When8_is_initialisation := (When8_clocks * {TRUE}); 
    When8_var_res1 := {}; 
    When8_var_clock2 := {}; 
    When8_var_clock1 := {}; 
    When8_var_res := {}; 
    When8_var_tmp_0 := {}; 
    When8_var_res2 := {}; 
    When8_var_tmp_1 := {}


OPERATIONS 

    When8_clock_step(When8_param_clock1, When8_param_clock2) = 
        PRE
            ((When8_param_clock1 : REF --> BOOL) & (When8_param_clock2 : REF --> BOOL))
        THEN
            When8_var_clock1 := When8_param_clock1; 
            When8_var_clock2 := When8_param_clock2; 
            Node_1.invoked_node_clock_step({ref |-> TRUE}); 
            When8_var_res := Node_1.invoked_node_var_res; 
            Node_2.invoked_node_clock_step({ref |-> TRUE}); 
            When8_var_tmp_0 := Node_2.invoked_node_var_res; 
            IF (When8_var_clock1 = {ref |-> TRUE}) THEN 
                When8_var_res1 := When8_var_tmp_0
            END; 
            Node_3.invoked_node_clock_step({ref |-> TRUE}); 
            When8_var_tmp_1 := Node_3.invoked_node_var_res; 
            IF (When8_var_clock2 = {ref |-> TRUE}) THEN 
                When8_var_res2 := When8_var_tmp_1
            END; 
            IF (When8_var_clock1 = {ref |-> TRUE}) THEN 
                When8_is_initialisation(When8_clock_clock1) := FALSE
            END; 
            When8_is_initialisation(When8_clock___basic__) := FALSE; 
            IF (When8_var_clock2 = {ref |-> TRUE}) THEN 
                When8_is_initialisation(When8_clock_clock2) := FALSE
            END

        END;

        out <-- getRes = BEGIN out := When8_var_res END;
        out <-- getRes1 = BEGIN out := When8_var_res1 END;
        out <-- getRes2 = BEGIN out := When8_var_res2 END



END