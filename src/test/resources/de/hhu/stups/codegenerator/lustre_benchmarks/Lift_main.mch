MACHINE Lift_main

SEES LibraryLustre

VARIABLES Lift_is_initialisation, Lift_var_exec_up, Lift_var_exec_down, Lift_var_floor

SETS Lift_clocks = {Lift_clock___basic__}

INVARIANT ((Lift_is_initialisation : Lift_clocks --> BOOL) & ((Lift_var_floor : REF +-> INTEGER) & ((Lift_var_exec_down : REF +-> BOOL) & (Lift_var_exec_up : REF +-> BOOL))))

INITIALISATION
    Lift_is_initialisation := (Lift_clocks * {TRUE});
    Lift_var_exec_up := {};
    Lift_var_exec_down := {};
    Lift_var_floor := {}


OPERATIONS

    Lift_clock_step(Lift_param_up, Lift_param_down) =
        PRE
            ((Lift_param_up : REF --> BOOL) & (Lift_param_down : REF --> BOOL))
        THEN
            VAR Lift_var_old_floor, Lift_var_down, Lift_var_up IN
                Lift_var_up := Lift_param_up;
                Lift_var_down := Lift_param_down;
                Lift_var_old_floor := l_fby_integer(Lift_is_initialisation(Lift_clock___basic__) |-> {ref |-> 0} |-> Lift_var_floor);
                Lift_var_exec_up := l_and(Lift_var_up |-> l_less(Lift_var_old_floor |-> {ref |-> 100}));
                Lift_var_exec_down := l_and(Lift_var_down |-> l_greater(Lift_var_old_floor |-> {ref |-> 0}));
                Lift_var_floor := l_ite_integer(Lift_var_exec_up |-> l_plus(Lift_var_old_floor |-> {ref |-> 1}) |-> l_ite_integer(Lift_var_exec_down |-> l_minus(Lift_var_old_floor |-> {ref |-> 1}) |-> Lift_var_old_floor));
                Lift_is_initialisation(Lift_clock___basic__) := FALSE

            END

        END



END
