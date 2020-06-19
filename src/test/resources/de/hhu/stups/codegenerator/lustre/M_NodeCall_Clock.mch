MACHINE M_NodeCall_Clock

INCLUDES Node_1.M_NodeCall_Clock_Call2, Node_2.M_NodeCall_Clock_Call1

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_c, var_res, var_tmp_0, var_c

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_c : BOOL) & ((var_c : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & ((is_initialisation_c = FALSE) => (var_res /= {}))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_c := TRUE; 
    var_res := {}; 
    var_tmp_0 := {}; 
    var_c := {}


OPERATIONS 

    clock_step(param_x, param_c) = 
        PRE
            ((param_x : LUSTRE_INT_NOT_NIL) & (param_c : LUSTRE_BOOL_NOT_NIL))
        THEN
            VAR var_x, var_tmp_1, var_tmp_2 IN
                var_x := param_x; 
                var_c := param_c; 
                PRE (var_c /= {}) THEN skip END; 
                var_tmp_2 := {ref |-> 2}; 
                var_tmp_1 := var_tmp_0; 
                Node_2.clock_step(var_x); 
                var_tmp_0 := Node_2.var_a; 
                IF (var_c = {ref |-> TRUE}) THEN 
                    Node_1.clock_step(var_tmp_1, var_tmp_2)
                END; 
                IF (var_c = {ref |-> TRUE}) THEN 
                    var_res := Node_1.var_res
                END; 
                SELECT ((assert_ok = TRUE) & ((Node_1.assert_ok = TRUE) & (Node_2.assert_ok = TRUE))) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var_c = {ref |-> TRUE}) THEN 
                    is_initialisation_c := FALSE
                END

            END

        END;

     out <-- getRes = BEGIN out := var_res END



END

/*
Node_1: NodeCall_Clock_Call2((pre(NodeCall_Clock_Call1(x)), 2 when c))
Node_2: NodeCall_Clock_Call1(x)
tmp_0: NodeCall_Clock_Call1(x)
tmp_1: pre(NodeCall_Clock_Call1(x))
tmp_2: 2
*/
