MACHINE M_Fby3_aux

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock, var_z, var_clock

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock : BOOL) & ((var_clock : LUSTRE_BOOL) & (var_z : LUSTRE_INT)))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock := TRUE; 
    var_z := {}; 
    var_clock := {}


OPERATIONS 

    clock_step(param_clock) = 
        PRE
            (param_clock : LUSTRE_BOOL)
        THEN
            VAR var_tmp_0 IN
                var_clock := param_clock; 
                PRE (var_clock /= {}) THEN skip END; 
                var_tmp_0 := {ref |-> 0}; 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    var_z := var_tmp_0
                END; 
                is_initialisation := FALSE; 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    is_initialisation_clock := FALSE
                END

            END

        END



END

/*
tmp_0: 0
*/
