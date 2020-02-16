MACHINE Lift_error

SEES LibraryLustre

VARIABLES Lift_error_is_initialisation, Lift_error_var_exec_up, Lift_error_var_down, Lift_error_var_exec_down, Lift_error_var_old_floor, Lift_error_var_floor, Lift_error_var_tmp_1, Lift_error_var_tmp_0, Lift_error_var_up

SETS Lift_error_clocks = {Lift_error_clock___basic__}

INVARIANT ((Lift_error_is_initialisation : Lift_error_clocks --> BOOL) & ((Lift_error_var_exec_up : REF +-> BOOL) & ((Lift_error_var_down : REF +-> BOOL) & ((Lift_error_var_exec_down : REF +-> BOOL) & ((Lift_error_var_old_floor : REF +-> INTEGER) & ((Lift_error_var_floor : REF +-> INTEGER) & ((Lift_error_var_tmp_1 : REF +-> INTEGER) & ((Lift_error_var_tmp_0 : REF +-> INTEGER) & (Lift_error_var_up : REF +-> BOOL)))))))))

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
            ((Lift_error_param_up : REF +-> BOOL) & (Lift_error_param_down : REF +-> BOOL))
        THEN
            VAR Lift_error_tmp_0_history IN
                Lift_error_tmp_0_history := Lift_error_var_tmp_0; 
                Lift_error_var_up := Lift_error_param_up; 
                Lift_error_var_down := Lift_error_param_down; 
                Lift_error_var_tmp_1 := Lift_error_tmp_0_history; 
                Lift_error_var_old_floor := l_fby_integer(Lift_error_is_initialisation(Lift_error_clock___basic__) |-> {ref |-> 0} |-> Lift_error_var_tmp_1); 
                Lift_error_var_exec_up := l_and(Lift_error_var_up |-> l_less(Lift_error_var_old_floor |-> {ref |-> 102})); 
                Lift_error_var_exec_down := l_and(Lift_error_var_down |-> l_greater(Lift_error_var_old_floor |-> {ref |-> 0})); 
                Lift_error_var_floor := l_if_then_else_integer(Lift_error_var_exec_up |-> l_plus(Lift_error_var_old_floor |-> {ref |-> 1}) |-> l_if_then_else_integer(Lift_error_var_exec_down |-> l_minus(Lift_error_var_old_floor |-> {ref |-> 1}) |-> Lift_error_var_old_floor)); 
                Lift_error_var_tmp_0 := Lift_error_var_floor; 
                Lift_error_is_initialisation(Lift_error_clock___basic__) := FALSE

            END

        END



END