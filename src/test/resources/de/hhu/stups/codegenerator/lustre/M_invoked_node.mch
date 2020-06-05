MACHINE M_invoked_node

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_res : LUSTRE_INT)))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_BOOL)
        THEN
            VAR var_x IN
                var_x := param_x; 
                var_res := l_plus(l_fby_integer(is_initialisation |-> {ref |-> 0} |-> var_res) |-> {ref |-> 1}); 
                is_initialisation := FALSE

            END

        END



END

