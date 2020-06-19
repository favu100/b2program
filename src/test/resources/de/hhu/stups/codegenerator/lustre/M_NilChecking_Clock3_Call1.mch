MACHINE M_NilChecking_Clock3_Call1

INCLUDES Node_2.M_NilChecking_Clock3_Call2

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_clock, is_initialisation, var_res, var_clock, var_x

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_clock : BOOL) & ((is_initialisation : BOOL) & ((var_x : LUSTRE_INT) & ((var_clock : LUSTRE_BOOL) & (var_res : LUSTRE_INT))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_clock := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_clock := {}; 
    var_x := {}


OPERATIONS 

    clock_step(param_clock, param_x) = 
        PRE
            ((param_clock : LUSTRE_BOOL) & (param_x : LUSTRE_INT))
        THEN
            var_clock := param_clock; 
            PRE (var_clock /= {}) THEN skip END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_x := param_x
            END; 
            Node_2.clock_step(var_clock, var_x); 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_res := Node_2.var_res
            END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                is_initialisation_clock := FALSE
            END; 
            is_initialisation := FALSE

        END



END

/*
Node_2: NilChecking_Clock3_Call2(clock, x)
*/
