MACHINE M_node_call_pre

INCLUDES Node_2.M_node_call_pre2

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_z, var_tmp_0

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_z : LUSTRE_INT) & (var_tmp_0 : LUSTRE_INT))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_z := {}; 
    var_tmp_0 := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT)
        THEN
            VAR hvar_tmp_0, var_x IN
                hvar_tmp_0 := var_tmp_0; 
                var_x := param_x; 
                Node_2.clock_step(var_x); 
                var_tmp_0 := l_fby_integer(is_initialisation |-> {ref |-> 1} |-> Node_2.var_z); 
                var_z := hvar_tmp_0; 
                is_initialisation := FALSE

            END

        END



END

/*
Node_2: node_call_pre2(x)
tmp_0: (1 -> node_call_pre2(x))
*/
