MACHINE M_microbenchmarks_node_call

INCLUDES Node_1.M_microbenchmarks_invoked_node

SEES LibraryLustre

VARIABLES is_initialisation, var_res

INVARIANT ((var_res : LUSTRE_BOOL) & ((is_initialisation : BOOL) & ((is_initialisation = FALSE) => (var_res /= {}))))

INITIALISATION 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x, param_y) = 
        PRE
            ((param_x : LUSTRE_BOOL_NOT_NIL) & (param_y : LUSTRE_BOOL_NOT_NIL))
        THEN
            VAR var_x, var_y IN
                var_x := param_x; 
                var_y := param_y; 
                Node_1.clock_step(var_x, var_y); 
                var_res := Node_1.var_res; 
                is_initialisation := FALSE

            END

        END



END

/*
Node_1: microbenchmarks_invoked_node(x, y)
*/
