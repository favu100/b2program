MACHINE M_Fby3

INCLUDES Node_1.M_Fby3_aux

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock, var_z, var_clock

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock : BOOL) & ((var_clock : LUSTRE_BOOL) & ((var_z : LUSTRE_INT) & ((is_initialisation_clock = FALSE) => (var_z /= {})))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock := TRUE; 
    var_z := {}; 
    var_clock := {}


OPERATIONS 

    clock_step(param_clock) = 
        PRE
            (param_clock : LUSTRE_BOOL_NOT_NIL)
        THEN
            VAR var_tmp_0 IN
                var_clock := param_clock; 
                PRE (var_clock /= {}) THEN skip END; 
                var_tmp_0 := {ref |-> 1}; 
                Node_1.clock_step(var_clock); 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    var_z := l_fby_integer(is_initialisation_clock |-> Node_1.var_z |-> l_plus(var_z |-> var_tmp_0))
                END; 
                SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    is_initialisation_clock := FALSE
                END

            END

        END;

    out <-- getZ = BEGIN out := var_z END



END

/*
Node_1: Fby3_aux(clock)
tmp_0: 1
*/
