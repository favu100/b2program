MACHINE speed_main

INCLUDES Node_1.counter

SEES LibraryLustre

VARIABLES speed_is_initialisation, speed_var_late, speed_var_early

SETS speed_clocks = {speed_clock___basic__}

INVARIANT ((speed_is_initialisation : speed_clocks --> BOOL) & ((speed_var_early : REF +-> BOOL) & (speed_var_late : REF +-> BOOL)))

INITIALISATION
    speed_is_initialisation := (speed_clocks * {TRUE});
    speed_var_late := {};
    speed_var_early := {}


OPERATIONS

    speed_clock_step(speed_param_beacon, speed_param_second) =
        PRE
            ((speed_param_beacon : REF --> BOOL) & (speed_param_second : REF --> BOOL))
        THEN
            VAR speed_var_diff, speed_var_beacon, speed_var_incr, speed_var_second IN
                speed_var_beacon := speed_param_beacon;
                speed_var_second := speed_param_second;
                speed_var_incr := l_ite_integer(l_and(speed_var_beacon |-> l_not(speed_var_second)) |-> {ref |-> 1} |-> l_ite_integer(l_and(speed_var_second |-> l_not(speed_var_beacon)) |-> l_unary_minus({ref |-> 1}) |-> {ref |-> 0}));
                Node_1.counter_clock_step({ref |-> 0}, speed_var_incr, l_or(speed_var_beacon |-> speed_var_second), {ref |-> FALSE});
                speed_var_diff := Node_1.counter_var_c;
                speed_var_early := l_fby_boolean(speed_is_initialisation(speed_clock___basic__) |-> {ref |-> FALSE} |-> l_ite_boolean(speed_var_early |-> l_greater(speed_var_diff |-> {ref |-> 0}) |-> l_greater_equal(speed_var_diff |-> {ref |-> 10})));
                speed_var_late := l_fby_boolean(speed_is_initialisation(speed_clock___basic__) |-> {ref |-> FALSE} |-> l_ite_boolean(speed_var_late |-> l_less(speed_var_diff |-> {ref |-> 0}) |-> l_less_equal(speed_var_diff |-> l_unary_minus({ref |-> 10}))));
                speed_is_initialisation(speed_clock___basic__) := FALSE

            END

        END



END
