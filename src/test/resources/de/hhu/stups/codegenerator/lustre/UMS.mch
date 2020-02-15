MACHINE UMS

VARIABLES UMS_is_initialisation, UMS_var_grant_access, UMS_var_do_AB, UMS_var_ack_BC, UMS_var_ack_AB, UMS_var_do_BC, UMS_var_empty_section, UMS_var_on_A, UMS_var_grant_exit, UMS_var_on_C, UMS_var_on_B, UMS_var_only_on_B

SETS UMS_clocks = {UMS_clock___basic__}; UMS_refs = {UMS_ref}

INVARIANT ((UMS_is_initialisation : UMS_clocks --> BOOL) & ((UMS_var_grant_access : UMS_refs +-> BOOL) & ((UMS_var_do_AB : UMS_refs +-> BOOL) & ((UMS_var_ack_BC : UMS_refs +-> BOOL) & ((UMS_var_ack_AB : UMS_refs +-> BOOL) & ((UMS_var_do_BC : UMS_refs +-> BOOL) & ((UMS_var_empty_section : UMS_refs +-> BOOL) & ((UMS_var_on_A : UMS_refs +-> BOOL) & ((UMS_var_grant_exit : UMS_refs +-> BOOL) & ((UMS_var_on_C : UMS_refs +-> BOOL) & ((UMS_var_on_B : UMS_refs +-> BOOL) & (UMS_var_only_on_B : UMS_refs +-> BOOL))))))))))))

INITIALISATION 
    UMS_is_initialisation := (UMS_clocks * {TRUE}); 
    UMS_var_grant_access := {}; 
    UMS_var_do_AB := {}; 
    UMS_var_ack_BC := {}; 
    UMS_var_ack_AB := {}; 
    UMS_var_do_BC := {}; 
    UMS_var_empty_section := {}; 
    UMS_var_on_A := {}; 
    UMS_var_grant_exit := {}; 
    UMS_var_on_C := {}; 
    UMS_var_on_B := {}; 
    UMS_var_only_on_B := {}


OPERATIONS 

    UMS_clock_step(UMS_param_on_A, UMS_param_on_B, UMS_param_on_C, UMS_param_ack_AB, UMS_param_ack_BC) = 
        PRE
            ((UMS_param_on_A : BOOL) & ((UMS_param_on_B : BOOL) & ((UMS_param_on_C : BOOL) & ((UMS_param_ack_AB : BOOL) & (UMS_param_ack_BC : BOOL)))))
        THEN
            VAR UMS_grant_access_history, UMS_do_AB_history, UMS_ack_BC_history, UMS_ack_AB_history, UMS_do_BC_history, UMS_empty_section_history, UMS_on_A_history, UMS_grant_exit_history, UMS_on_C_history, UMS_on_B_history, UMS_only_on_B_history IN
                UMS_grant_access_history := UMS_var_grant_access; 
                UMS_do_AB_history := UMS_var_do_AB; 
                UMS_ack_BC_history := UMS_var_ack_BC; 
                UMS_ack_AB_history := UMS_var_ack_AB; 
                UMS_do_BC_history := UMS_var_do_BC; 
                UMS_empty_section_history := UMS_var_empty_section; 
                UMS_on_A_history := UMS_var_on_A; 
                UMS_grant_exit_history := UMS_var_grant_exit; 
                UMS_on_C_history := UMS_var_on_C; 
                UMS_on_B_history := UMS_var_on_B; 
                UMS_only_on_B_history := UMS_var_only_on_B; 
                UMS_var_on_A(UMS_ref) := bool((UMS_param_on_A = TRUE)); 
                UMS_var_on_B(UMS_ref) := bool((UMS_param_on_B = TRUE)); 
                UMS_var_on_C(UMS_ref) := bool((UMS_param_on_C = TRUE)); 
                UMS_var_ack_AB(UMS_ref) := bool((UMS_param_ack_AB = TRUE)); 
                UMS_var_ack_BC(UMS_ref) := bool((UMS_param_ack_BC = TRUE)); 
                IF ((UMS_var_on_A /= {}) & ((UMS_var_on_B /= {}) & (UMS_var_on_C /= {}))) THEN 
                    UMS_var_empty_section(UMS_ref) := bool(not(((UMS_var_on_A(UMS_ref) = TRUE) or ((UMS_var_on_B(UMS_ref) = TRUE) or (UMS_var_on_C(UMS_ref) = TRUE)))))
                ELSE 
                    UMS_var_empty_section := {}
                END; 
                IF ((UMS_var_on_B /= {}) & ((UMS_var_on_A /= {}) & (UMS_var_on_C /= {}))) THEN 
                    UMS_var_only_on_B(UMS_ref) := bool(((UMS_var_on_B(UMS_ref) = TRUE) & not(((UMS_var_on_A(UMS_ref) = TRUE) or (UMS_var_on_C(UMS_ref) = TRUE)))))
                ELSE 
                    UMS_var_only_on_B := {}
                END; 
                IF ((UMS_var_empty_section /= {}) & (UMS_var_ack_AB /= {})) THEN 
                    UMS_var_grant_access(UMS_ref) := bool(((UMS_var_empty_section(UMS_ref) = TRUE) & (UMS_var_ack_AB(UMS_ref) = TRUE)))
                ELSE 
                    UMS_var_grant_access := {}
                END; 
                IF ((UMS_var_only_on_B /= {}) & (UMS_var_ack_BC /= {})) THEN 
                    UMS_var_grant_exit(UMS_ref) := bool(((UMS_var_only_on_B(UMS_ref) = TRUE) & (UMS_var_ack_BC(UMS_ref) = TRUE)))
                ELSE 
                    UMS_var_grant_exit := {}
                END; 
                IF ((UMS_var_ack_AB /= {}) & (UMS_var_empty_section /= {})) THEN 
                    UMS_var_do_AB(UMS_ref) := bool((not((UMS_var_ack_AB(UMS_ref) = TRUE)) & (UMS_var_empty_section(UMS_ref) = TRUE)))
                ELSE 
                    UMS_var_do_AB := {}
                END; 
                IF ((UMS_var_ack_BC /= {}) & (UMS_var_only_on_B /= {})) THEN 
                    UMS_var_do_BC(UMS_ref) := bool((not((UMS_var_ack_BC(UMS_ref) = TRUE)) & (UMS_var_only_on_B(UMS_ref) = TRUE)))
                ELSE 
                    UMS_var_do_BC := {}
                END; 
                UMS_is_initialisation(UMS_clock___basic__) := FALSE

            END

        END;

        out <-- getGrant_Access = BEGIN out := UMS_var_grant_access END;
        out <-- getGrant_Exit = BEGIN out := UMS_var_grant_exit END;
        out <-- getDo_AB = BEGIN out := UMS_var_do_AB END;
        out <-- getDo_BC = BEGIN out := UMS_var_do_BC END



END