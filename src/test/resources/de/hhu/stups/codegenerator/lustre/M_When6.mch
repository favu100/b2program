MACHINE M_When6

INCLUDES Node_2.M_other_when_node, Node_1.M_other_when_node

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_clock1, is_initialisation, is_initialisation_clock2, var_res1, var_clock1, var_res2, var_clock2

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_clock1 : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock2 : BOOL) & ((var_clock2 : LUSTRE_BOOL) & ((var_clock1 : LUSTRE_BOOL) & ((var_res2 : LUSTRE_INT) & ((var_res1 : LUSTRE_INT) & (((is_initialisation_clock2 = FALSE) => (var_res2 /= {})) & ((is_initialisation_clock1 = FALSE) => (var_res1 /= {})))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_clock1 := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock2 := TRUE; 
    var_res1 := {}; 
    var_clock1 := {}; 
    var_res2 := {}; 
    var_clock2 := {}


OPERATIONS 

    clock_step(param_clock1, param_clock2) = 
        PRE
            ((param_clock1 : LUSTRE_BOOL_NOT_NIL) & (param_clock2 : LUSTRE_BOOL_NOT_NIL))
        THEN
            var_clock1 := param_clock1; 
            PRE (var_clock1 /= {}) THEN skip END; 
            var_clock2 := param_clock2; 
            PRE (var_clock2 /= {}) THEN skip END; 
            Node_1.clock_step(var_clock1); 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                var_res1 := Node_1.var_res
            END; 
            Node_2.clock_step(var_clock2); 
            IF (var_clock2 = {ref |-> TRUE}) THEN 
                var_res2 := Node_2.var_res
            END; 
            SELECT ((assert_ok = TRUE) & ((Node_2.assert_ok = TRUE) & (Node_1.assert_ok = TRUE))) THEN skip END; 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                is_initialisation_clock1 := FALSE
            END; 
            is_initialisation := FALSE; 
            IF (var_clock2 = {ref |-> TRUE}) THEN 
                is_initialisation_clock2 := FALSE
            END

        END;

     out <-- getRes1 = BEGIN out := var_res1 END;
     out <-- getRes2 = BEGIN out := var_res2 END



END

/*
Node_1: other_when_node(clock1)
Node_2: other_when_node(clock2)
*/
