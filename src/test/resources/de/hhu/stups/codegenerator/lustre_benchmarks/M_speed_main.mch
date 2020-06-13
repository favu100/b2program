//generated from Lustre
//taken from N. Halbwachs, P Raymond A Tutorial of Lustre, 2002

MACHINE M_speed_main

INCLUDES Node_1.M_counter

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_early, var_late

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_early : LUSTRE_BOOL) & ((var_late : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_early /= {})) & ((is_initialisation = FALSE) => (var_late /= {})))))))

INITIALISATION
    assert_ok := TRUE;
    is_initialisation := TRUE;
    var_early := {};
    var_late := {}


OPERATIONS

    clock_step(param_beacon, param_second) =
        PRE
            ((param_beacon : LUSTRE_BOOL_NOT_NIL) & (param_second : LUSTRE_BOOL_NOT_NIL))
        THEN
            VAR var_beacon, var_second, var_diff, var_incr IN
                var_beacon := param_beacon;
                var_second := param_second;
                var_incr := l_ite_integer(l_and(var_beacon |-> l_not(var_second)) |-> {ref |-> 1} |-> l_ite_integer(l_and(var_second |-> l_not(var_beacon)) |-> l_unary_minus({ref |-> 1}) |-> {ref |-> 0}));
                Node_1.clock_step({ref |-> 0}, var_incr, l_or(var_beacon |-> var_second), {ref |-> FALSE});
                var_diff := Node_1.var_c;
                var_early := l_fby_boolean(is_initialisation |-> {ref |-> FALSE} |-> l_ite_boolean(var_early |-> l_greater(var_diff |-> {ref |-> 0}) |-> l_greater_equal(var_diff |-> {ref |-> 10})));
                var_late := l_fby_boolean(is_initialisation |-> {ref |-> FALSE} |-> l_ite_boolean(var_late |-> l_less(var_diff |-> {ref |-> 0}) |-> l_less_equal(var_diff |-> l_unary_minus({ref |-> 10}))));
                SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END;
                is_initialisation := FALSE

            END

        END



END

/*
Node_1: counter(0, incr, (beacon or second), false)
*/
