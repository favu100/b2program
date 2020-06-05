MACHINE M_If_Then_Else

INCLUDES Node_2.M_ite_2, Node_1.M_ite_1

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
                var_z := l_ite_integer(l_equal_integer(l_modulo(var_x |-> {ref |-> 2}) |-> {ref |-> 0}) |-> Node_1.var_z |-> Node_2.var_z); 
                SELECT ((assert_ok = TRUE) & ((Node_2.assert_ok = TRUE) & (Node_1.assert_ok = TRUE))) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

     out <-- getZ = BEGIN out := var_z END



END

/*
Node_1: ite_1(x)
Node_2: ite_2(x)
*/
