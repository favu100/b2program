MACHINE M_NodeCall_Clock2

INCLUDES Node_1.M_NodeCall_Clock2_Call

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_c, is_initialisation, var_res, var_x, var_c

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_c : BOOL) & ((is_initialisation : BOOL) & ((var_c : LUSTRE_BOOL) & ((var_x : LUSTRE_INT) & ((var_res : LUSTRE_INT) & ((is_initialisation_c = FALSE) => (var_res /= {}))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_c := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_x := {}; 
    var_c := {}


OPERATIONS 

    clock_step(param_x, param_c) = 
        PRE
            ((param_x : LUSTRE_INT_NOT_NIL) & (param_c : LUSTRE_BOOL_NOT_NIL))
        THEN
            var_x := param_x; 
            var_c := param_c; 
            PRE (var_c /= {}) THEN skip END; 
            IF (var_c = {ref |-> TRUE}) THEN 
                Node_1.clock_step(var_x)
            END; 
            IF (var_c = {ref |-> TRUE}) THEN 
                var_res := Node_1.var_a
            END; 
            SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END; 
            IF (var_c = {ref |-> TRUE}) THEN 
                is_initialisation_c := FALSE
            END; 
            is_initialisation := FALSE

        END;

     out <-- getRes = BEGIN out := var_res END



END

/*
Node_1: NodeCall_Clock2_Call((x when c))
*/
