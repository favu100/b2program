//generated from Lustre
//taken from Production cell in Lustre, Leszek Holenderski

MACHINE M_sustain

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_s

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_s : LUSTRE_BOOL)))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_s := {}


OPERATIONS 

    clock_step(param_on, param_off) = 
        PRE
            ((param_on : LUSTRE_BOOL) & (param_off : LUSTRE_BOOL))
        THEN
            VAR var_on, var_off IN
                var_on := param_on; 
                var_off := param_off; 
                var_s := l_fby_boolean(is_initialisation |-> var_on |-> l_ite_boolean(var_on |-> {ref |-> TRUE} |-> l_ite_boolean(var_off |-> {ref |-> FALSE} |-> var_s))); 
                is_initialisation := FALSE

            END

        END



END

