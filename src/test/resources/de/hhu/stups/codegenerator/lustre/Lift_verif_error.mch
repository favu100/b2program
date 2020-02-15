MACHINE Lift_verif_error

INCLUDES Node_1.Lift_error

VARIABLES Lift_verif_error_is_initialisation, Lift_verif_error_var_ok, Lift_verif_error_var_exec_up, Lift_verif_error_var_exec_down, Lift_verif_error_var_down, Lift_verif_error_var_not_higher_than_highest_floor, Lift_verif_error_var_floor, Lift_verif_error_var_not_lower_than_lowest_floor, Lift_verif_error_var_up, Lift_verif_error_var_only_exec_up_or_down

SETS Lift_verif_error_clocks = {Lift_verif_error_clock___basic__}; Lift_verif_error_refs = {Lift_verif_error_ref}

INVARIANT ((Lift_verif_error_is_initialisation : Lift_verif_error_clocks --> BOOL) & ((Lift_verif_error_var_ok : Lift_verif_error_refs +-> BOOL) & ((Lift_verif_error_var_exec_up : Lift_verif_error_refs +-> BOOL) & ((Lift_verif_error_var_exec_down : Lift_verif_error_refs +-> BOOL) & ((Lift_verif_error_var_down : Lift_verif_error_refs +-> BOOL) & ((Lift_verif_error_var_not_higher_than_highest_floor : Lift_verif_error_refs +-> BOOL) & ((Lift_verif_error_var_floor : Lift_verif_error_refs +-> INTEGER) & ((Lift_verif_error_var_not_lower_than_lowest_floor : Lift_verif_error_refs +-> BOOL) & ((Lift_verif_error_var_up : Lift_verif_error_refs +-> BOOL) & ((Lift_verif_error_var_only_exec_up_or_down : Lift_verif_error_refs +-> BOOL) & (((Lift_verif_error_is_initialisation(Lift_verif_error_clock___basic__) = FALSE) => (Lift_verif_error_var_ok /= {})) & (((Lift_verif_error_is_initialisation(Lift_verif_error_clock___basic__) = FALSE) & (Lift_verif_error_var_ok /= {})) => (Lift_verif_error_var_ok(Lift_verif_error_ref) = TRUE)))))))))))))

INITIALISATION 
    Lift_verif_error_is_initialisation := (Lift_verif_error_clocks * {TRUE}); 
    Lift_verif_error_var_ok := {}; 
    Lift_verif_error_var_exec_up := {}; 
    Lift_verif_error_var_exec_down := {}; 
    Lift_verif_error_var_down := {}; 
    Lift_verif_error_var_not_higher_than_highest_floor := {}; 
    Lift_verif_error_var_floor := {}; 
    Lift_verif_error_var_not_lower_than_lowest_floor := {}; 
    Lift_verif_error_var_up := {}; 
    Lift_verif_error_var_only_exec_up_or_down := {}


OPERATIONS 

    Lift_verif_error_clock_step(Lift_verif_error_param_up, Lift_verif_error_param_down) = 
        PRE
            ((Lift_verif_error_param_up : BOOL) & (Lift_verif_error_param_down : BOOL))
        THEN
            VAR Lift_verif_error_ok_history, Lift_verif_error_exec_up_history, Lift_verif_error_exec_down_history, Lift_verif_error_down_history, Lift_verif_error_not_higher_than_highest_floor_history, Lift_verif_error_floor_history, Lift_verif_error_not_lower_than_lowest_floor_history, Lift_verif_error_up_history, Lift_verif_error_only_exec_up_or_down_history IN
                Lift_verif_error_ok_history := Lift_verif_error_var_ok; 
                Lift_verif_error_exec_up_history := Lift_verif_error_var_exec_up; 
                Lift_verif_error_exec_down_history := Lift_verif_error_var_exec_down; 
                Lift_verif_error_down_history := Lift_verif_error_var_down; 
                Lift_verif_error_not_higher_than_highest_floor_history := Lift_verif_error_var_not_higher_than_highest_floor; 
                Lift_verif_error_floor_history := Lift_verif_error_var_floor; 
                Lift_verif_error_not_lower_than_lowest_floor_history := Lift_verif_error_var_not_lower_than_lowest_floor; 
                Lift_verif_error_up_history := Lift_verif_error_var_up; 
                Lift_verif_error_only_exec_up_or_down_history := Lift_verif_error_var_only_exec_up_or_down; 
                Lift_verif_error_var_up(Lift_verif_error_ref) := bool((Lift_verif_error_param_up = TRUE)); 
                Lift_verif_error_var_down(Lift_verif_error_ref) := bool((Lift_verif_error_param_down = TRUE)); 
                IF ((Lift_verif_error_var_up /= {}) & (Lift_verif_error_var_down /= {})) THEN 
                    Node_1.Lift_error_clock_step(Lift_verif_error_var_up(Lift_verif_error_ref), Lift_verif_error_var_down(Lift_verif_error_ref))
                END; 
                IF ((Node_1.Lift_error_var_exec_up /= {}) & ((Node_1.Lift_error_var_exec_down /= {}) & (Node_1.Lift_error_var_floor /= {}))) THEN 
                    Lift_verif_error_var_exec_up(Lift_verif_error_ref) := bool((Node_1.Lift_error_var_exec_up(Lift_error_ref) = TRUE))
                ELSE 
                    Lift_verif_error_var_exec_up := {}
                END; 
                IF ((Node_1.Lift_error_var_exec_up /= {}) & ((Node_1.Lift_error_var_exec_down /= {}) & (Node_1.Lift_error_var_floor /= {}))) THEN 
                    Lift_verif_error_var_exec_down(Lift_verif_error_ref) := bool((Node_1.Lift_error_var_exec_down(Lift_error_ref) = TRUE))
                ELSE 
                    Lift_verif_error_var_exec_down := {}
                END; 
                IF ((Node_1.Lift_error_var_exec_up /= {}) & ((Node_1.Lift_error_var_exec_down /= {}) & (Node_1.Lift_error_var_floor /= {}))) THEN 
                    Lift_verif_error_var_floor(Lift_verif_error_ref) := Node_1.Lift_error_var_floor(Lift_error_ref)
                ELSE 
                    Lift_verif_error_var_floor := {}
                END; 
                IF ((Lift_verif_error_var_exec_up /= {}) & (Lift_verif_error_var_exec_down /= {})) THEN 
                    Lift_verif_error_var_only_exec_up_or_down(Lift_verif_error_ref) := bool(not(((Lift_verif_error_var_exec_up(Lift_verif_error_ref) = TRUE) & (Lift_verif_error_var_exec_down(Lift_verif_error_ref) = TRUE))))
                ELSE 
                    Lift_verif_error_var_only_exec_up_or_down := {}
                END; 
                IF (Lift_verif_error_var_floor /= {}) THEN 
                    Lift_verif_error_var_not_lower_than_lowest_floor(Lift_verif_error_ref) := bool((Lift_verif_error_var_floor(Lift_verif_error_ref) >= 0))
                ELSE 
                    Lift_verif_error_var_not_lower_than_lowest_floor := {}
                END; 
                IF (Lift_verif_error_var_floor /= {}) THEN 
                    Lift_verif_error_var_not_higher_than_highest_floor(Lift_verif_error_ref) := bool((Lift_verif_error_var_floor(Lift_verif_error_ref) <= 100))
                ELSE 
                    Lift_verif_error_var_not_higher_than_highest_floor := {}
                END; 
                IF ((Lift_verif_error_var_only_exec_up_or_down /= {}) & ((Lift_verif_error_var_not_lower_than_lowest_floor /= {}) & (Lift_verif_error_var_not_higher_than_highest_floor /= {}))) THEN 
                    Lift_verif_error_var_ok(Lift_verif_error_ref) := bool(((Lift_verif_error_var_only_exec_up_or_down(Lift_verif_error_ref) = TRUE) & ((Lift_verif_error_var_not_lower_than_lowest_floor(Lift_verif_error_ref) = TRUE) & (Lift_verif_error_var_not_higher_than_highest_floor(Lift_verif_error_ref) = TRUE))))
                ELSE 
                    Lift_verif_error_var_ok := {}
                END; 
                ASSERT (((Lift_verif_error_var_up /= {}) & ((Lift_verif_error_var_down /= {}) & ((Lift_verif_error_var_up /= {}) & (Lift_verif_error_var_down /= {})))) => (((Lift_verif_error_var_up(Lift_verif_error_ref) = TRUE) or (Lift_verif_error_var_down(Lift_verif_error_ref) = TRUE)) & not(((Lift_verif_error_var_up(Lift_verif_error_ref) = TRUE) & (Lift_verif_error_var_down(Lift_verif_error_ref) = TRUE))))) THEN skip END
; 
                Lift_verif_error_is_initialisation(Lift_verif_error_clock___basic__) := FALSE

            END

        END;

        out <-- getOK = BEGIN out := Lift_verif_error_var_ok END



END