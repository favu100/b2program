MACHINE M_When8

INCLUDES Node_1.M_invoked_node, Node_2.M_invoked_node, Node_3.M_invoked_node

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock1, is_initialisation_clock2, var_res, var_res1, var_res2, var_tmp_0, var_clock1, var_tmp_1, var_clock2

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock1 : BOOL) & ((is_initialisation_clock2 : BOOL) & ((var_clock2 : LUSTRE_BOOL) & ((var_clock1 : LUSTRE_BOOL) & ((var_res2 : LUSTRE_INT) & ((var_res1 : LUSTRE_INT) & ((var_res : LUSTRE_INT) & ((var_tmp_1 : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & (((is_initialisation_clock2 = FALSE) => (var_res2 /= {})) & (((is_initialisation_clock1 = FALSE) => (var_res1 /= {})) & ((is_initialisation = FALSE) => (var_res /= {})))))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock1 := TRUE; 
    is_initialisation_clock2 := TRUE; 
    var_res := {}; 
    var_res1 := {}; 
    var_res2 := {}; 
    var_tmp_0 := {}; 
    var_clock1 := {}; 
    var_tmp_1 := {}; 
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
            Node_3.clock_step({ref |-> TRUE}); 
            var_tmp_1 := Node_3.var_res; 
            Node_2.clock_step({ref |-> TRUE}); 
            var_tmp_0 := Node_2.var_res; 
            Node_1.clock_step({ref |-> TRUE}); 
            var_res := Node_1.var_res; 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                var_res1 := var_tmp_0
            END; 
            IF (var_clock2 = {ref |-> TRUE}) THEN 
                var_res2 := var_tmp_1
            END; 
            SELECT ((assert_ok = TRUE) & ((Node_1.assert_ok = TRUE) & ((Node_2.assert_ok = TRUE) & (Node_3.assert_ok = TRUE)))) THEN skip END; 
            is_initialisation := FALSE; 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                is_initialisation_clock1 := FALSE
            END; 
            IF (var_clock2 = {ref |-> TRUE}) THEN 
                is_initialisation_clock2 := FALSE
            END

        END;


    out <-- getRes = BEGIN out := var_res END;
    out <-- getRes1 = BEGIN out := var_res1 END;
    out <-- getRes2 = BEGIN out := var_res2 END



END

/*
Node_1: invoked_node(true)
Node_2: invoked_node(true)
Node_3: invoked_node(true)
tmp_0: invoked_node(true)
tmp_1: invoked_node(true)
*/
