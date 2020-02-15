MACHINE Lift_error

VARIABLES Lift_error_is_initialisation, Lift_error_var_exec_up, Lift_error_var_down, Lift_error_var_exec_down, Lift_error_var_old_floor, Lift_error_var_floor, Lift_error_var_tmp_1, Lift_error_var_tmp_0, Lift_error_var_up

SETS Lift_error_clocks = {Lift_error_clock___basic__}; Lift_error_refs = {Lift_error_ref}

INVARIANT ((Lift_error_is_initialisation : Lift_error_clocks --> BOOL) & ((Lift_error_var_exec_up : Lift_error_refs +-> BOOL) & ((Lift_error_var_down : Lift_error_refs +-> BOOL) & ((Lift_error_var_exec_down : Lift_error_refs +-> BOOL) & ((Lift_error_var_old_floor : Lift_error_refs +-> INTEGER) & ((Lift_error_var_floor : Lift_error_refs +-> INTEGER) & ((Lift_error_var_tmp_1 : Lift_error_refs +-> INTEGER) & ((Lift_error_var_tmp_0 : Lift_error_refs +-> INTEGER) & (Lift_error_var_up : Lift_error_refs +-> BOOL)))))))))

INITIALISATION 
    Lift_error_is_initialisation := (Lift_error_clocks * {TRUE}); 
    Lift_error_var_exec_up := {}; 
    Lift_error_var_down := {}; 
    Lift_error_var_exec_down := {}; 
    Lift_error_var_old_floor := {}; 
    Lift_error_var_floor := {}; 
    Lift_error_var_tmp_1 := {}; 
    Lift_error_var_tmp_0 := {}; 
    Lift_error_var_up := {}


OPERATIONS 

    Lift_error_clock_step(Lift_error_param_up, Lift_error_param_down) = 
        PRE
            ((Lift_error_param_up : BOOL) & (Lift_error_param_down : BOOL))
        THEN
            VAR Lift_error_exec_up_history, Lift_error_down_history, Lift_error_exec_down_history, Lift_error_old_floor_history, Lift_error_floor_history, Lift_error_tmp_1_history, Lift_error_tmp_0_history, Lift_error_up_history IN
                Lift_error_exec_up_history := Lift_error_var_exec_up; 
                Lift_error_down_history := Lift_error_var_down; 
                Lift_error_exec_down_history := Lift_error_var_exec_down; 
                Lift_error_old_floor_history := Lift_error_var_old_floor; 
                Lift_error_floor_history := Lift_error_var_floor; 
                Lift_error_tmp_1_history := Lift_error_var_tmp_1; 
                Lift_error_tmp_0_history := Lift_error_var_tmp_0; 
                Lift_error_up_history := Lift_error_var_up; 
                Lift_error_var_up(Lift_error_ref) := bool((Lift_error_param_up = TRUE)); 
                Lift_error_var_down(Lift_error_ref) := bool((Lift_error_param_down = TRUE)); 
                IF (Lift_error_tmp_0_history /= {}) THEN 
                    Lift_error_var_tmp_1(Lift_error_ref) := Lift_error_tmp_0_history(Lift_error_ref)
                ELSE 
                    Lift_error_var_tmp_1 := {}
                END; 
                IF (not((Lift_error_is_initialisation(Lift_error_clock___basic__) = TRUE)) => (Lift_error_var_tmp_1 /= {})) THEN 
                    Lift_error_var_old_floor(Lift_error_ref) := IF (Lift_error_is_initialisation(Lift_error_clock___basic__) = TRUE) THEN 0 ELSE Lift_error_var_tmp_1(Lift_error_ref) END
                ELSE 
                    Lift_error_var_old_floor := {}
                END; 
                IF ((Lift_error_var_up /= {}) & (Lift_error_var_old_floor /= {})) THEN 
                    Lift_error_var_exec_up(Lift_error_ref) := bool(((Lift_error_var_up(Lift_error_ref) = TRUE) & (Lift_error_var_old_floor(Lift_error_ref) < 102)))
                ELSE 
                    Lift_error_var_exec_up := {}
                END; 
                IF ((Lift_error_var_down /= {}) & (Lift_error_var_old_floor /= {})) THEN 
                    Lift_error_var_exec_down(Lift_error_ref) := bool(((Lift_error_var_down(Lift_error_ref) = TRUE) & (Lift_error_var_old_floor(Lift_error_ref) > 0)))
                ELSE 
                    Lift_error_var_exec_down := {}
                END; 
                IF ((Lift_error_var_exec_up /= {}) & (((Lift_error_var_exec_up(Lift_error_ref) = TRUE) => (Lift_error_var_old_floor /= {})) or (not((Lift_error_var_exec_up(Lift_error_ref) = TRUE)) => ((Lift_error_var_exec_down /= {}) & (((Lift_error_var_exec_down(Lift_error_ref) = TRUE) => (Lift_error_var_old_floor /= {})) or (not((Lift_error_var_exec_down(Lift_error_ref) = TRUE)) => (Lift_error_var_old_floor /= {}))))))) THEN 
                    Lift_error_var_floor(Lift_error_ref) := IF (Lift_error_var_exec_up(Lift_error_ref) = TRUE) THEN (Lift_error_var_old_floor(Lift_error_ref) + 1) ELSE IF (Lift_error_var_exec_down(Lift_error_ref) = TRUE) THEN (Lift_error_var_old_floor(Lift_error_ref) - 1) ELSE Lift_error_var_old_floor(Lift_error_ref) END END
                ELSE 
                    Lift_error_var_floor := {}
                END; 
                IF (Lift_error_var_floor /= {}) THEN 
                    Lift_error_var_tmp_0(Lift_error_ref) := Lift_error_var_floor(Lift_error_ref)
                ELSE 
                    Lift_error_var_tmp_0 := {}
                END; 
                Lift_error_is_initialisation(Lift_error_clock___basic__) := FALSE

            END

        END



END