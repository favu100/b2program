//generated from Lustre
//taken from Programming and verifying real-time systems by means of the synchronous data-flow language LUSTRE, N.Halbwachs et. al


MACHINE M_UMS_verif

INCLUDES Node_2.M_always_from_to, Node_1.M_always_from_to, Node_14.M_always_from_to, Node_13.M_always_from_to, Node_12.M_implies, Node_11.M_UMS, Node_9.M_implies, Node_10.M_edge, Node_7.M_implies, Node_8.M_edge, Node_5.M_implies, Node_6.M_edge, Node_3.M_implies, Node_4.M_edge

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_property, var_grant_access, var_grant_exit, var_no_collision, var_exclusive_req, var_no_derail_AB, var_no_derail_BC

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_property : LUSTRE_BOOL) & ((var_no_derail_BC : LUSTRE_BOOL) & ((var_no_derail_AB : LUSTRE_BOOL) & ((var_exclusive_req : LUSTRE_BOOL) & ((var_no_collision : LUSTRE_BOOL) & ((var_grant_exit : LUSTRE_BOOL) & ((var_grant_access : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_property /= {})) & ((is_initialisation = FALSE) => (var_property = {ref |-> TRUE}))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_property := {}; 
    var_grant_access := {}; 
    var_grant_exit := {}; 
    var_no_collision := {}; 
    var_exclusive_req := {}; 
    var_no_derail_AB := {}; 
    var_no_derail_BC := {}


OPERATIONS 

    clock_step(param_on_A, param_on_B, param_on_C, param_ack_AB, param_ack_BC) = 
        PRE
            ((param_on_A : LUSTRE_BOOL_NOT_NIL) & ((param_on_B : LUSTRE_BOOL_NOT_NIL) & ((param_on_C : LUSTRE_BOOL_NOT_NIL) & ((param_ack_AB : LUSTRE_BOOL_NOT_NIL) & (param_ack_BC : LUSTRE_BOOL_NOT_NIL)))))
        THEN
            VAR var_on_A, var_on_B, var_on_C, var_ack_AB, var_ack_BC, var_do_AB, var_do_BC, var_empty_section, var_only_on_B IN
                var_on_A := param_on_A; 
                var_on_B := param_on_B; 
                var_on_C := param_on_C; 
                var_ack_AB := param_ack_AB; 
                var_ack_BC := param_ack_BC; 
                var_empty_section := l_not(l_or(l_or(var_on_A |-> var_on_B) |-> var_on_C)); 
                var_only_on_B := l_and(var_on_B |-> l_not(l_or(var_on_A |-> var_on_C))); 
                PRE (l_not(l_and(var_ack_AB |-> var_ack_BC)) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_not(l_and(var_ack_AB |-> var_ack_BC)) = {ref |-> TRUE}))); 
                PRE (l_fby_boolean(is_initialisation |-> var_empty_section |-> {ref |-> TRUE}) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_fby_boolean(is_initialisation |-> var_empty_section |-> {ref |-> TRUE}) = {ref |-> TRUE}))); 
                Node_4.clock_step(l_not(var_empty_section)); 
                Node_3.clock_step(Node_4.var_EDGE, var_grant_access); 
                PRE (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_3.var_AimpliesB) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_3.var_AimpliesB) = {ref |-> TRUE}))); 
                Node_6.clock_step(var_on_C); 
                Node_5.clock_step(Node_6.var_EDGE, var_grant_exit); 
                PRE (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_5.var_AimpliesB) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_5.var_AimpliesB) = {ref |-> TRUE}))); 
                Node_8.clock_step(l_not(var_on_A)); 
                Node_7.clock_step(Node_8.var_EDGE, var_on_B); 
                PRE (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_7.var_AimpliesB) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_7.var_AimpliesB) = {ref |-> TRUE}))); 
                Node_10.clock_step(l_not(var_on_B)); 
                Node_9.clock_step(Node_10.var_EDGE, l_or(var_on_A |-> var_on_C)); 
                PRE (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_9.var_AimpliesB) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_9.var_AimpliesB) = {ref |-> TRUE}))); 
                Node_11.clock_step(var_on_A, var_on_B, var_on_C, var_ack_AB, var_ack_BC); 
                var_grant_access := Node_11.var_grant_access; 
                var_grant_exit := Node_11.var_grant_exit; 
                var_do_AB := Node_11.var_do_AB; 
                var_do_BC := Node_11.var_do_BC; 
                Node_12.clock_step(var_grant_access, var_empty_section); 
                var_no_collision := Node_12.var_AimpliesB; 
                var_exclusive_req := l_not(l_and(var_do_AB |-> var_do_BC)); 
                Node_13.clock_step(var_ack_AB, var_grant_access, var_only_on_B); 
                var_no_derail_AB := Node_13.var_X; 
                Node_14.clock_step(var_ack_BC, var_grant_exit, var_empty_section); 
                var_no_derail_BC := Node_14.var_X; 
                var_property := l_and(l_and(l_and(var_no_collision |-> var_exclusive_req) |-> var_no_derail_AB) |-> var_no_derail_BC); 
                Node_1.clock_step(var_ack_AB, var_ack_AB, var_do_BC); 
                PRE (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_1.var_X) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_1.var_X) = {ref |-> TRUE}))); 
                Node_2.clock_step(var_ack_BC, var_ack_BC, var_do_AB); 
                PRE (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_2.var_X) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> Node_2.var_X) = {ref |-> TRUE}))); 
                SELECT ((assert_ok = TRUE) & ((Node_2.assert_ok = TRUE) & ((Node_1.assert_ok = TRUE) & ((Node_14.assert_ok = TRUE) & ((Node_13.assert_ok = TRUE) & ((Node_12.assert_ok = TRUE) & ((Node_11.assert_ok = TRUE) & ((Node_9.assert_ok = TRUE) & ((Node_10.assert_ok = TRUE) & ((Node_7.assert_ok = TRUE) & ((Node_8.assert_ok = TRUE) & ((Node_5.assert_ok = TRUE) & ((Node_6.assert_ok = TRUE) & ((Node_3.assert_ok = TRUE) & (Node_4.assert_ok = TRUE))))))))))))))) THEN skip END; 
                is_initialisation := FALSE

            END

        END



END

/*
Node_1: always_from_to(ack_AB, ack_AB, do_BC)
Node_2: always_from_to(ack_BC, ack_BC, do_AB)
Node_3: implies(edge(not(empty_section)), pre(grant_access))
Node_4: edge(not(empty_section))
Node_5: implies(edge(on_C), pre(grant_exit))
Node_6: edge(on_C)
Node_7: implies(edge(not(on_A)), on_B)
Node_8: edge(not(on_A))
Node_9: implies(edge(not(on_B)), (on_A or on_C))
Node_10: edge(not(on_B))
Node_11: UMS(on_A, on_B, on_C, ack_AB, ack_BC)
Node_12: implies(grant_access, empty_section)
Node_13: always_from_to(ack_AB, grant_access, only_on_B)
Node_14: always_from_to(ack_BC, grant_exit, empty_section)
*/
