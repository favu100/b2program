MACHINE M_NodeCall

INCLUDES Node_1.M_NodeCall_2, Node_2.M_NodeCall_1

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_res : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_res /= {})))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR var_x IN
                var_x := param_x; 
                Node_2.clock_step({ref |-> 1}); 
                Node_1.clock_step(Node_2.var_a, Node_2.var_b, {ref |-> 2}); 
                var_res := Node_1.var_res; 
                SELECT ((assert_ok = TRUE) & ((Node_1.assert_ok = TRUE) & (Node_2.assert_ok = TRUE))) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

     out <-- getRes = BEGIN out := var_res END



END

/*
Node_1: NodeCall_2(NodeCall_1(1), 2)
Node_2: NodeCall_1(1)
*/
