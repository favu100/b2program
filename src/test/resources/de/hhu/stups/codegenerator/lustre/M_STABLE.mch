//generated from Lustre
//taken from Lustre V6 Language Manual

MACHINE M_STABLE

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_level, var_count

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_level : LUSTRE_BOOL) & (var_count : LUSTRE_INT))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_level := {}; 
    var_count := {}


OPERATIONS 

    clock_step(param_set, param_delay) = 
        PRE
            ((param_set : LUSTRE_BOOL) & (param_delay : LUSTRE_INT))
        THEN
            VAR var_set, var_delay IN
                var_set := param_set; 
                var_delay := param_delay; 
                var_count := l_ite_integer(var_set |-> var_delay |-> l_ite_integer(l_fby_boolean(is_initialisation |-> {ref |-> FALSE} |-> var_level) |-> l_minus(var_count |-> {ref |-> 1}) |-> {ref |-> 0})); 
                var_level := l_greater(var_count |-> {ref |-> 0}); 
                is_initialisation := FALSE

            END

        END



END

