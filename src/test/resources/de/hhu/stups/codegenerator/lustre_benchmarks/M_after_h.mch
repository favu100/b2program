//generated from Lustre
//taken from Production cell in Lustre, Leszek Holenderski

MACHINE M_after_h

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_a, var_e1, var_e2_since_last_e1

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_e1 : LUSTRE_BOOL) & ((var_a : LUSTRE_BOOL) & (var_e2_since_last_e1 : LUSTRE_BOOL)))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_a := {}; 
    var_e1 := {}; 
    var_e2_since_last_e1 := {}


OPERATIONS 

    clock_step(param_e1, param_e2) = 
        PRE
            ((param_e1 : LUSTRE_BOOL) & (param_e2 : LUSTRE_BOOL))
        THEN
            VAR hvar_e1, var_e2 IN
                hvar_e1 := var_e1; 
                var_e1 := param_e1; 
                var_e2 := param_e2; 
                var_e2_since_last_e1 := l_fby_boolean(is_initialisation |-> var_e2 |-> l_ite_boolean(var_e2 |-> {ref |-> TRUE} |-> l_ite_boolean(hvar_e1 |-> {ref |-> FALSE} |-> var_e2_since_last_e1))); 
                var_a := l_and(var_e1 |-> var_e2_since_last_e1); 
                is_initialisation := FALSE

            END

        END



END

