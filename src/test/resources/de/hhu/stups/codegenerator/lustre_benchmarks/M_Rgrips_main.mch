//generated from Lustre
//taken from Production cell in Lustre, Leszek Holenderski

MACHINE M_Rgrips_main

INCLUDES Node_25.M_after_h, Node_24.M_after_h, Node_23.M_after_h, Node_22.M_after_h

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_Rget1, var_Rget2, var_Rput2, var_Rput1

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_Rput2 : LUSTRE_BOOL) & ((var_Rget2 : LUSTRE_BOOL) & ((var_Rput1 : LUSTRE_BOOL) & ((var_Rget1 : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_Rput2 /= {})) & (((is_initialisation = FALSE) => (var_Rget2 /= {})) & (((is_initialisation = FALSE) => (var_Rput1 /= {})) & ((is_initialisation = FALSE) => (var_Rget1 /= {})))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_Rget1 := {}; 
    var_Rget2 := {}; 
    var_Rput2 := {}; 
    var_Rput1 := {}


OPERATIONS 

    clock_step(param_InPress1, param_OverTable, param_ToTable, param_ToPress1, param_InPress2, param_OverDBelt, param_ToDBelt, param_ToPress2, param_Ttop, param_Pbot, param_Pmid) = 
        PRE
            ((param_InPress1 : LUSTRE_BOOL_NOT_NIL) & ((param_OverTable : LUSTRE_BOOL_NOT_NIL) & ((param_ToTable : LUSTRE_BOOL_NOT_NIL) & ((param_ToPress1 : LUSTRE_BOOL_NOT_NIL) & ((param_InPress2 : LUSTRE_BOOL_NOT_NIL) & ((param_OverDBelt : LUSTRE_BOOL_NOT_NIL) & ((param_ToDBelt : LUSTRE_BOOL_NOT_NIL) & ((param_ToPress2 : LUSTRE_BOOL_NOT_NIL) & ((param_Ttop : LUSTRE_BOOL_NOT_NIL) & ((param_Pbot : LUSTRE_BOOL_NOT_NIL) & (param_Pmid : LUSTRE_BOOL_NOT_NIL)))))))))))
        THEN
            VAR var_InPress1, var_OverTable, var_ToTable, var_ToPress1, var_InPress2, var_OverDBelt, var_ToDBelt, var_ToPress2, var_Ttop, var_Pbot, var_Pmid IN
                var_InPress1 := param_InPress1; 
                var_OverTable := param_OverTable; 
                var_ToTable := param_ToTable; 
                var_ToPress1 := param_ToPress1; 
                var_InPress2 := param_InPress2; 
                var_OverDBelt := param_OverDBelt; 
                var_ToDBelt := param_ToDBelt; 
                var_ToPress2 := param_ToPress2; 
                var_Ttop := param_Ttop; 
                var_Pbot := param_Pbot; 
                var_Pmid := param_Pmid; 
                Node_22.clock_step(l_and(l_and(var_OverTable |-> var_ToTable) |-> var_Ttop), l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> var_Rput1)); 
                var_Rget1 := Node_22.var_a; 
                Node_23.clock_step(l_and(l_and(var_InPress1 |-> var_ToPress1) |-> var_Pmid), var_Rget1); 
                var_Rput1 := Node_23.var_a; 
                Node_24.clock_step(l_and(l_and(var_InPress2 |-> var_ToPress2) |-> var_Pbot), var_Rput1); 
                var_Rget2 := Node_24.var_a; 
                Node_25.clock_step(l_and(var_OverDBelt |-> var_ToDBelt), var_Rget2); 
                var_Rput2 := Node_25.var_a; 
                SELECT ((assert_ok = TRUE) & ((Node_25.assert_ok = TRUE) & ((Node_24.assert_ok = TRUE) & ((Node_23.assert_ok = TRUE) & (Node_22.assert_ok = TRUE))))) THEN skip END; 
                is_initialisation := FALSE

            END

        END



END

/*
Node_22: after_h(((OverTable and ToTable) and Ttop), (true -> pre(Rput1)))
Node_23: after_h(((InPress1 and ToPress1) and Pmid), Rget1)
Node_24: after_h(((InPress2 and ToPress2) and Pbot), Rput1)
Node_25: after_h((OverDBelt and ToDBelt), Rget2)
*/
