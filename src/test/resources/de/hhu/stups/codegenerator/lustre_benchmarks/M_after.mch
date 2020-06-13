//generated from Lustre
//taken from Programming and verifying real-time systems by means of the synchronous data-flow language LUSTRE, N.Halbwachs et. al

MACHINE M_after

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_afterA, var_tmp_0

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_afterA : LUSTRE_BOOL) & (var_tmp_0 : LUSTRE_BOOL))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_afterA := {}; 
    var_tmp_0 := {}


OPERATIONS 

    clock_step(param_A) = 
        PRE
            (param_A : LUSTRE_BOOL)
        THEN
            VAR var_A IN
                var_A := param_A; 
                var_afterA := l_fby_boolean(is_initialisation |-> {ref |-> FALSE} |-> var_tmp_0); 
                var_tmp_0 := l_or(var_A |-> var_afterA); 
                is_initialisation := FALSE

            END

        END



END

/*
tmp_0: (A or afterA)
*/
