MACHINE M_Fby2

INCLUDES Node_2.M_fby_node_call2, Node_1.M_fby_node_call

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_z

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_z : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_z /= {})))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_z := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR var_x IN
                var_x := param_x; 
                Node_1.clock_step(var_x); 
                Node_2.clock_step(var_x); 
                var_z := l_fby_integer(is_initialisation |-> Node_1.var_z |-> Node_2.var_z); 
                SELECT ((assert_ok = TRUE) & ((Node_2.assert_ok = TRUE) & (Node_1.assert_ok = TRUE))) THEN skip END; 
                is_initialisation := FALSE

            END

        END;


     out <-- getZ = BEGIN out := var_z END



END

/*
Node_1: fby_node_call(x)
Node_2: fby_node_call2(x)
*/
