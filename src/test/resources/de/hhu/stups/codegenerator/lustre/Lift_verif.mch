MACHINE Lift_verif

INCLUDES Node_1.Lift

SEES LibraryLustre

VARIABLES Lift_verif_is_initialisation, Lift_verif_var_ok, Lift_verif_var_exec_up, Lift_verif_var_exec_down, Lift_verif_var_down, Lift_verif_var_not_higher_than_highest_floor, Lift_verif_var_floor, Lift_verif_var_not_lower_than_lowest_floor, Lift_verif_var_up, Lift_verif_var_only_exec_up_or_down

SETS Lift_verif_clocks = {Lift_verif_clock___basic__}

INVARIANT ((Lift_verif_is_initialisation : Lift_verif_clocks --> BOOL) & ((Lift_verif_var_ok : REF +-> BOOL) & ((Lift_verif_var_exec_up : REF +-> BOOL) & ((Lift_verif_var_exec_down : REF +-> BOOL) & ((Lift_verif_var_down : REF +-> BOOL) & ((Lift_verif_var_not_higher_than_highest_floor : REF +-> BOOL) & ((Lift_verif_var_floor : REF +-> INTEGER) & ((Lift_verif_var_not_lower_than_lowest_floor : REF +-> BOOL) & ((Lift_verif_var_up : REF +-> BOOL) & ((Lift_verif_var_only_exec_up_or_down : REF +-> BOOL) & (((Lift_verif_is_initialisation(Lift_verif_clock___basic__) = FALSE) => (Lift_verif_var_ok /= {})) & (((Lift_verif_is_initialisation(Lift_verif_clock___basic__) = FALSE) & (Lift_verif_var_ok /= {})) => (Lift_verif_var_ok(ref) = TRUE)))))))))))))

INITIALISATION 
    Lift_verif_is_initialisation := (Lift_verif_clocks * {TRUE}); 
    Lift_verif_var_ok := {}; 
    Lift_verif_var_exec_up := {}; 
    Lift_verif_var_exec_down := {}; 
    Lift_verif_var_down := {}; 
    Lift_verif_var_not_higher_than_highest_floor := {}; 
    Lift_verif_var_floor := {}; 
    Lift_verif_var_not_lower_than_lowest_floor := {}; 
    Lift_verif_var_up := {}; 
    Lift_verif_var_only_exec_up_or_down := {}


OPERATIONS 

    Lift_verif_clock_step(Lift_verif_param_up, Lift_verif_param_down) = 
        PRE
            ((Lift_verif_param_up : REF --> BOOL) & (Lift_verif_param_down : REF --> BOOL))
        THEN
            Lift_verif_var_up := Lift_verif_param_up; 
            Lift_verif_var_down := Lift_verif_param_down; 
            Node_1.Lift_clock_step(Lift_verif_var_up, Lift_verif_var_down); 
            Lift_verif_var_exec_up := Node_1.Lift_var_exec_up; 
            Lift_verif_var_exec_down := Node_1.Lift_var_exec_down; 
            Lift_verif_var_floor := Node_1.Lift_var_floor; 
            Lift_verif_var_only_exec_up_or_down := l_not(l_and(Lift_verif_var_exec_up |-> Lift_verif_var_exec_down)); 
            Lift_verif_var_not_lower_than_lowest_floor := l_greater_equal(Lift_verif_var_floor |-> {ref |-> 0}); 
            Lift_verif_var_not_higher_than_highest_floor := l_less_equal(Lift_verif_var_floor |-> {ref |-> 100}); 
            Lift_verif_var_ok := l_and(Lift_verif_var_only_exec_up_or_down |-> l_and(Lift_verif_var_not_lower_than_lowest_floor |-> Lift_verif_var_not_higher_than_highest_floor)); 
            ASSERT (l_not(l_and(Lift_verif_var_up |-> Lift_verif_var_down)) = {ref |-> TRUE}) THEN skip END
; 
            Lift_verif_is_initialisation(Lift_verif_clock___basic__) := FALSE

        END;

        out <-- getFloor = BEGIN out := Lift_verif_var_floor END



END