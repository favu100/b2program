MACHINE UMS_verif

INCLUDES Node_2.implies, Node_1.edge, Node_4.implies, Node_3.edge, Node_6.implies, Node_5.edge, Node_8.implies, Node_7.edge, Node_9.UMS, Node_10.implies, Node_11.always_from_to, Node_12.always_from_to, Node_13.always_from_to, Node_14.always_from_to

VARIABLES UMS_verif_is_initialisation, UMS_verif_var_grant_access, UMS_verif_var_do_BC, UMS_verif_var_ack_BC, UMS_verif_var_ack_AB, UMS_verif_var_do_AB, UMS_verif_var_exclusive_req, UMS_verif_var_empty_section, UMS_verif_var_on_B, UMS_verif_var_no_collision, UMS_verif_var_grant_exit, UMS_verif_var_no_derail_BC, UMS_verif_var_no_derail_AB, UMS_verif_var_on_A, UMS_verif_var_tmp_0, UMS_verif_var_only_on_B, UMS_verif_var_on_C, UMS_verif_var_property, UMS_verif_var_tmp_2, UMS_verif_var_tmp_1, UMS_verif_var_tmp_3

SETS UMS_verif_clocks = {UMS_verif_clock___basic__}; UMS_verif_refs = {UMS_verif_ref}

INVARIANT ((UMS_verif_is_initialisation : UMS_verif_clocks --> BOOL) & ((UMS_verif_var_grant_access : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_do_BC : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_ack_BC : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_ack_AB : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_do_AB : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_exclusive_req : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_empty_section : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_on_B : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_no_collision : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_grant_exit : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_no_derail_BC : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_no_derail_AB : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_on_A : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_tmp_0 : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_only_on_B : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_on_C : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_property : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_tmp_2 : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_tmp_1 : UMS_verif_refs +-> BOOL) & ((UMS_verif_var_tmp_3 : UMS_verif_refs +-> BOOL) & (((UMS_verif_is_initialisation(UMS_verif_clock___basic__) = FALSE) => (UMS_verif_var_property /= {})) & (((UMS_verif_is_initialisation(UMS_verif_clock___basic__) = FALSE) & (UMS_verif_var_property /= {})) => (UMS_verif_var_property(UMS_verif_ref) = TRUE))))))))))))))))))))))))

INITIALISATION 
    UMS_verif_is_initialisation := (UMS_verif_clocks * {TRUE}); 
    UMS_verif_var_grant_access := {}; 
    UMS_verif_var_do_BC := {}; 
    UMS_verif_var_ack_BC := {}; 
    UMS_verif_var_ack_AB := {}; 
    UMS_verif_var_do_AB := {}; 
    UMS_verif_var_exclusive_req := {}; 
    UMS_verif_var_empty_section := {}; 
    UMS_verif_var_on_B := {}; 
    UMS_verif_var_no_collision := {}; 
    UMS_verif_var_grant_exit := {}; 
    UMS_verif_var_no_derail_BC := {}; 
    UMS_verif_var_no_derail_AB := {}; 
    UMS_verif_var_on_A := {}; 
    UMS_verif_var_tmp_0 := {}; 
    UMS_verif_var_only_on_B := {}; 
    UMS_verif_var_on_C := {}; 
    UMS_verif_var_property := {}; 
    UMS_verif_var_tmp_2 := {}; 
    UMS_verif_var_tmp_1 := {}; 
    UMS_verif_var_tmp_3 := {}


OPERATIONS 

    UMS_verif_clock_step(UMS_verif_param_on_A, UMS_verif_param_on_B, UMS_verif_param_on_C, UMS_verif_param_ack_AB, UMS_verif_param_ack_BC) = 
        PRE
            ((UMS_verif_param_on_A : BOOL) & ((UMS_verif_param_on_B : BOOL) & ((UMS_verif_param_on_C : BOOL) & ((UMS_verif_param_ack_AB : BOOL) & (UMS_verif_param_ack_BC : BOOL)))))
        THEN
            VAR UMS_verif_grant_access_history, UMS_verif_do_BC_history, UMS_verif_ack_BC_history, UMS_verif_ack_AB_history, UMS_verif_do_AB_history, UMS_verif_exclusive_req_history, UMS_verif_empty_section_history, UMS_verif_on_B_history, UMS_verif_no_collision_history, UMS_verif_grant_exit_history, UMS_verif_no_derail_BC_history, UMS_verif_no_derail_AB_history, UMS_verif_on_A_history, UMS_verif_tmp_0_history, UMS_verif_only_on_B_history, UMS_verif_on_C_history, UMS_verif_property_history, UMS_verif_tmp_2_history, UMS_verif_tmp_1_history, UMS_verif_tmp_3_history IN
                UMS_verif_grant_access_history := UMS_verif_var_grant_access; 
                UMS_verif_do_BC_history := UMS_verif_var_do_BC; 
                UMS_verif_ack_BC_history := UMS_verif_var_ack_BC; 
                UMS_verif_ack_AB_history := UMS_verif_var_ack_AB; 
                UMS_verif_do_AB_history := UMS_verif_var_do_AB; 
                UMS_verif_exclusive_req_history := UMS_verif_var_exclusive_req; 
                UMS_verif_empty_section_history := UMS_verif_var_empty_section; 
                UMS_verif_on_B_history := UMS_verif_var_on_B; 
                UMS_verif_no_collision_history := UMS_verif_var_no_collision; 
                UMS_verif_grant_exit_history := UMS_verif_var_grant_exit; 
                UMS_verif_no_derail_BC_history := UMS_verif_var_no_derail_BC; 
                UMS_verif_no_derail_AB_history := UMS_verif_var_no_derail_AB; 
                UMS_verif_on_A_history := UMS_verif_var_on_A; 
                UMS_verif_tmp_0_history := UMS_verif_var_tmp_0; 
                UMS_verif_only_on_B_history := UMS_verif_var_only_on_B; 
                UMS_verif_on_C_history := UMS_verif_var_on_C; 
                UMS_verif_property_history := UMS_verif_var_property; 
                UMS_verif_tmp_2_history := UMS_verif_var_tmp_2; 
                UMS_verif_tmp_1_history := UMS_verif_var_tmp_1; 
                UMS_verif_tmp_3_history := UMS_verif_var_tmp_3; 
                UMS_verif_var_on_A(UMS_verif_ref) := bool((UMS_verif_param_on_A = TRUE)); 
                UMS_verif_var_on_B(UMS_verif_ref) := bool((UMS_verif_param_on_B = TRUE)); 
                UMS_verif_var_on_C(UMS_verif_ref) := bool((UMS_verif_param_on_C = TRUE)); 
                UMS_verif_var_ack_AB(UMS_verif_ref) := bool((UMS_verif_param_ack_AB = TRUE)); 
                UMS_verif_var_ack_BC(UMS_verif_ref) := bool((UMS_verif_param_ack_BC = TRUE)); 
                IF ((UMS_verif_var_on_A /= {}) & ((UMS_verif_var_on_B /= {}) & (UMS_verif_var_on_C /= {}))) THEN 
                    UMS_verif_var_empty_section(UMS_verif_ref) := bool(not(((UMS_verif_var_on_A(UMS_verif_ref) = TRUE) or ((UMS_verif_var_on_B(UMS_verif_ref) = TRUE) or (UMS_verif_var_on_C(UMS_verif_ref) = TRUE)))))
                ELSE 
                    UMS_verif_var_empty_section := {}
                END; 
                IF ((UMS_verif_var_on_B /= {}) & ((UMS_verif_var_on_A /= {}) & (UMS_verif_var_on_C /= {}))) THEN 
                    UMS_verif_var_only_on_B(UMS_verif_ref) := bool(((UMS_verif_var_on_B(UMS_verif_ref) = TRUE) & not(((UMS_verif_var_on_A(UMS_verif_ref) = TRUE) or (UMS_verif_var_on_C(UMS_verif_ref) = TRUE)))))
                ELSE 
                    UMS_verif_var_only_on_B := {}
                END; 
                IF (UMS_verif_tmp_0_history /= {}) THEN 
                    UMS_verif_var_tmp_1(UMS_verif_ref) := bool((UMS_verif_tmp_0_history(UMS_verif_ref) = TRUE))
                ELSE 
                    UMS_verif_var_tmp_1 := {}
                END; 
                IF (UMS_verif_var_empty_section /= {}) THEN 
                    Node_1.edge_clock_step(bool(not((UMS_verif_var_empty_section(UMS_verif_ref) = TRUE))))
                END; 
                IF ((Node_1.edge_var_EDGE /= {}) & (UMS_verif_var_tmp_1 /= {})) THEN 
                    Node_2.implies_clock_step(bool((Node_1.edge_var_EDGE(edge_ref) = TRUE)), UMS_verif_var_tmp_1(UMS_verif_ref))
                END; 
                IF (UMS_verif_tmp_2_history /= {}) THEN 
                    UMS_verif_var_tmp_3(UMS_verif_ref) := bool((UMS_verif_tmp_2_history(UMS_verif_ref) = TRUE))
                ELSE 
                    UMS_verif_var_tmp_3 := {}
                END; 
                IF (UMS_verif_var_on_C /= {}) THEN 
                    Node_3.edge_clock_step(UMS_verif_var_on_C(UMS_verif_ref))
                END; 
                IF ((Node_3.edge_var_EDGE /= {}) & (UMS_verif_var_tmp_3 /= {})) THEN 
                    Node_4.implies_clock_step(bool((Node_3.edge_var_EDGE(edge_ref) = TRUE)), UMS_verif_var_tmp_3(UMS_verif_ref))
                END; 
                IF (UMS_verif_var_on_A /= {}) THEN 
                    Node_5.edge_clock_step(bool(not((UMS_verif_var_on_A(UMS_verif_ref) = TRUE))))
                END; 
                IF ((Node_5.edge_var_EDGE /= {}) & (UMS_verif_var_on_B /= {})) THEN 
                    Node_6.implies_clock_step(bool((Node_5.edge_var_EDGE(edge_ref) = TRUE)), UMS_verif_var_on_B(UMS_verif_ref))
                END; 
                IF (UMS_verif_var_on_B /= {}) THEN 
                    Node_7.edge_clock_step(bool(not((UMS_verif_var_on_B(UMS_verif_ref) = TRUE))))
                END; 
                IF ((Node_7.edge_var_EDGE /= {}) & ((UMS_verif_var_on_A /= {}) & (UMS_verif_var_on_C /= {}))) THEN 
                    Node_8.implies_clock_step(bool((Node_7.edge_var_EDGE(edge_ref) = TRUE)), bool(((UMS_verif_var_on_A(UMS_verif_ref) = TRUE) or (UMS_verif_var_on_C(UMS_verif_ref) = TRUE))))
                END; 
                IF ((UMS_verif_var_on_A /= {}) & ((UMS_verif_var_on_B /= {}) & ((UMS_verif_var_on_C /= {}) & ((UMS_verif_var_ack_AB /= {}) & (UMS_verif_var_ack_BC /= {}))))) THEN 
                    Node_9.UMS_clock_step(UMS_verif_var_on_A(UMS_verif_ref), UMS_verif_var_on_B(UMS_verif_ref), UMS_verif_var_on_C(UMS_verif_ref), UMS_verif_var_ack_AB(UMS_verif_ref), UMS_verif_var_ack_BC(UMS_verif_ref))
                END; 
                IF ((Node_9.UMS_var_grant_access /= {}) & ((Node_9.UMS_var_grant_exit /= {}) & ((Node_9.UMS_var_do_AB /= {}) & (Node_9.UMS_var_do_BC /= {})))) THEN 
                    UMS_verif_var_grant_access(UMS_verif_ref) := bool((Node_9.UMS_var_grant_access(UMS_ref) = TRUE))
                ELSE 
                    UMS_verif_var_grant_access := {}
                END; 
                IF ((Node_9.UMS_var_grant_access /= {}) & ((Node_9.UMS_var_grant_exit /= {}) & ((Node_9.UMS_var_do_AB /= {}) & (Node_9.UMS_var_do_BC /= {})))) THEN 
                    UMS_verif_var_grant_exit(UMS_verif_ref) := bool((Node_9.UMS_var_grant_exit(UMS_ref) = TRUE))
                ELSE 
                    UMS_verif_var_grant_exit := {}
                END; 
                IF ((Node_9.UMS_var_grant_access /= {}) & ((Node_9.UMS_var_grant_exit /= {}) & ((Node_9.UMS_var_do_AB /= {}) & (Node_9.UMS_var_do_BC /= {})))) THEN 
                    UMS_verif_var_do_AB(UMS_verif_ref) := bool((Node_9.UMS_var_do_AB(UMS_ref) = TRUE))
                ELSE 
                    UMS_verif_var_do_AB := {}
                END; 
                IF ((Node_9.UMS_var_grant_access /= {}) & ((Node_9.UMS_var_grant_exit /= {}) & ((Node_9.UMS_var_do_AB /= {}) & (Node_9.UMS_var_do_BC /= {})))) THEN 
                    UMS_verif_var_do_BC(UMS_verif_ref) := bool((Node_9.UMS_var_do_BC(UMS_ref) = TRUE))
                ELSE 
                    UMS_verif_var_do_BC := {}
                END; 
                IF ((UMS_verif_var_grant_access /= {}) & (UMS_verif_var_empty_section /= {})) THEN 
                    Node_10.implies_clock_step(UMS_verif_var_grant_access(UMS_verif_ref), UMS_verif_var_empty_section(UMS_verif_ref))
                END; 
                IF (Node_10.implies_var_AimpliesB /= {}) THEN 
                    UMS_verif_var_no_collision(UMS_verif_ref) := bool((Node_10.implies_var_AimpliesB(implies_ref) = TRUE))
                ELSE 
                    UMS_verif_var_no_collision := {}
                END; 
                IF ((UMS_verif_var_do_AB /= {}) & (UMS_verif_var_do_BC /= {})) THEN 
                    UMS_verif_var_exclusive_req(UMS_verif_ref) := bool(not(((UMS_verif_var_do_AB(UMS_verif_ref) = TRUE) & (UMS_verif_var_do_BC(UMS_verif_ref) = TRUE))))
                ELSE 
                    UMS_verif_var_exclusive_req := {}
                END; 
                IF ((UMS_verif_var_ack_AB /= {}) & ((UMS_verif_var_grant_access /= {}) & (UMS_verif_var_only_on_B /= {}))) THEN 
                    Node_11.always_from_to_clock_step(UMS_verif_var_ack_AB(UMS_verif_ref), UMS_verif_var_grant_access(UMS_verif_ref), UMS_verif_var_only_on_B(UMS_verif_ref))
                END; 
                IF (Node_11.always_from_to_var_X /= {}) THEN 
                    UMS_verif_var_no_derail_AB(UMS_verif_ref) := bool((Node_11.always_from_to_var_X(always_from_to_ref) = TRUE))
                ELSE 
                    UMS_verif_var_no_derail_AB := {}
                END; 
                IF ((UMS_verif_var_ack_BC /= {}) & ((UMS_verif_var_grant_exit /= {}) & (UMS_verif_var_empty_section /= {}))) THEN 
                    Node_12.always_from_to_clock_step(UMS_verif_var_ack_BC(UMS_verif_ref), UMS_verif_var_grant_exit(UMS_verif_ref), UMS_verif_var_empty_section(UMS_verif_ref))
                END; 
                IF (Node_12.always_from_to_var_X /= {}) THEN 
                    UMS_verif_var_no_derail_BC(UMS_verif_ref) := bool((Node_12.always_from_to_var_X(always_from_to_ref) = TRUE))
                ELSE 
                    UMS_verif_var_no_derail_BC := {}
                END; 
                IF ((UMS_verif_var_no_collision /= {}) & ((UMS_verif_var_exclusive_req /= {}) & ((UMS_verif_var_no_derail_AB /= {}) & (UMS_verif_var_no_derail_BC /= {})))) THEN 
                    UMS_verif_var_property(UMS_verif_ref) := bool(((UMS_verif_var_no_collision(UMS_verif_ref) = TRUE) & ((UMS_verif_var_exclusive_req(UMS_verif_ref) = TRUE) & ((UMS_verif_var_no_derail_AB(UMS_verif_ref) = TRUE) & (UMS_verif_var_no_derail_BC(UMS_verif_ref) = TRUE)))))
                ELSE 
                    UMS_verif_var_property := {}
                END; 
                IF ((UMS_verif_var_ack_AB /= {}) & ((UMS_verif_var_ack_AB /= {}) & (UMS_verif_var_do_BC /= {}))) THEN 
                    Node_13.always_from_to_clock_step(UMS_verif_var_ack_AB(UMS_verif_ref), UMS_verif_var_ack_AB(UMS_verif_ref), UMS_verif_var_do_BC(UMS_verif_ref))
                END; 
                IF ((UMS_verif_var_ack_BC /= {}) & ((UMS_verif_var_ack_BC /= {}) & (UMS_verif_var_do_AB /= {}))) THEN 
                    Node_14.always_from_to_clock_step(UMS_verif_var_ack_BC(UMS_verif_ref), UMS_verif_var_ack_BC(UMS_verif_ref), UMS_verif_var_do_AB(UMS_verif_ref))
                END; 
                IF (UMS_verif_var_grant_access /= {}) THEN 
                    UMS_verif_var_tmp_0(UMS_verif_ref) := bool((UMS_verif_var_grant_access(UMS_verif_ref) = TRUE))
                ELSE 
                    UMS_verif_var_tmp_0 := {}
                END; 
                IF (UMS_verif_var_grant_exit /= {}) THEN 
                    UMS_verif_var_tmp_2(UMS_verif_ref) := bool((UMS_verif_var_grant_exit(UMS_verif_ref) = TRUE))
                ELSE 
                    UMS_verif_var_tmp_2 := {}
                END; 
                ASSERT ((((UMS_verif_var_ack_AB /= {}) & (UMS_verif_var_ack_BC /= {})) => not(((UMS_verif_var_ack_AB(UMS_verif_ref) = TRUE) & (UMS_verif_var_ack_BC(UMS_verif_ref) = TRUE)))) & ((((UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE) => (UMS_verif_var_empty_section /= {})) => (IF (UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE) THEN bool((UMS_verif_var_empty_section(UMS_verif_ref) = TRUE)) ELSE TRUE END = TRUE)) & (((not((UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE)) => (Node_2.implies_var_AimpliesB /= {})) => (IF (UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE) THEN TRUE ELSE bool((Node_2.implies_var_AimpliesB(implies_ref) = TRUE)) END = TRUE)) & (((not((UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE)) => (Node_4.implies_var_AimpliesB /= {})) => (IF (UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE) THEN TRUE ELSE bool((Node_4.implies_var_AimpliesB(implies_ref) = TRUE)) END = TRUE)) & (((not((UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE)) => (Node_6.implies_var_AimpliesB /= {})) => (IF (UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE) THEN TRUE ELSE bool((Node_6.implies_var_AimpliesB(implies_ref) = TRUE)) END = TRUE)) & (((not((UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE)) => (Node_8.implies_var_AimpliesB /= {})) => (IF (UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE) THEN TRUE ELSE bool((Node_8.implies_var_AimpliesB(implies_ref) = TRUE)) END = TRUE)) & (((not((UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE)) => (Node_13.always_from_to_var_X /= {})) => (IF (UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE) THEN TRUE ELSE bool((Node_13.always_from_to_var_X(always_from_to_ref) = TRUE)) END = TRUE)) & ((not((UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE)) => (Node_14.always_from_to_var_X /= {})) => (IF (UMS_verif_is_initialisation(UMS_verif_clock___basic__) = TRUE) THEN TRUE ELSE bool((Node_14.always_from_to_var_X(always_from_to_ref) = TRUE)) END = TRUE))))))))) THEN skip END
; 
                UMS_verif_is_initialisation(UMS_verif_clock___basic__) := FALSE

            END

        END;

        out <-- getGrant_Access = BEGIN out := UMS_verif_var_grant_access END;
        out <-- getGrant_Exit = BEGIN out := UMS_verif_var_grant_exit END;
        out <-- getDo_AB = BEGIN out := UMS_verif_var_do_AB END;
        out <-- getDo_BC = BEGIN out := UMS_verif_var_do_BC END



END