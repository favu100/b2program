MACHINE once_from_to

INCLUDES Node_1.jafter, Node_2.switch

SEES LibraryLustre

VARIABLES once_from_to_is_initialisation, once_from_to_var_OK

SETS once_from_to_clocks = {once_from_to_clock___basic__}

INVARIANT ((once_from_to_is_initialisation : once_from_to_clocks --> BOOL) & (once_from_to_var_OK : REF +-> BOOL))

INITIALISATION 
    once_from_to_is_initialisation := (once_from_to_clocks * {TRUE}); 
    once_from_to_var_OK := {}


OPERATIONS 

    once_from_to_clock_step(once_from_to_param_A, once_from_to_param_B, once_from_to_param_X) = 
        PRE
            ((once_from_to_param_A : REF +-> BOOL) & ((once_from_to_param_B : REF +-> BOOL) & (once_from_to_param_X : REF +-> BOOL)))
        THEN
            VAR once_from_to_var_B, once_from_to_var_A, once_from_to_var_X, once_from_to_var_between_A_and_X IN
                once_from_to_var_A := once_from_to_param_A; 
                once_from_to_var_B := once_from_to_param_B; 
                once_from_to_var_X := once_from_to_param_X; 
                Node_1.jafter_clock_step(once_from_to_var_X); 
                Node_2.switch_clock_step({ref |-> FALSE}, once_from_to_var_A, Node_1.jafter_var_after); 
                once_from_to_var_between_A_and_X := Node_2.switch_var_value; 
                once_from_to_var_OK := l_not(l_and(once_from_to_var_between_A_and_X |-> once_from_to_var_B)); 
                once_from_to_is_initialisation(once_from_to_clock___basic__) := FALSE

            END

        END



END