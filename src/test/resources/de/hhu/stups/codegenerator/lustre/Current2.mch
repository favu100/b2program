MACHINE Current2

VARIABLES Current2_is_initialisation, Current2_var_tmp_2, Current2_var_res1, Current2_var_clock2, Current2_var_clock1, Current2_var_res, Current2_var_tmp_0, Current2_var_res2, Current2_var_tmp_1, Current2_var_tmp_4, Current2_var_tmp_3, Current2_var_tmp_6, Current2_var_tmp_5, Current2_var_tmp_7

SETS Current2_clocks = {Current2_clock___basic__, Current2_clock_clock1, Current2_clock_clock2}; Current2_refs = {Current2_ref}

INVARIANT ((Current2_is_initialisation : Current2_clocks --> BOOL) & ((Current2_var_tmp_2 : Current2_refs +-> INTEGER) & ((Current2_var_res1 : Current2_refs +-> INTEGER) & ((Current2_var_clock2 : Current2_refs +-> BOOL) & ((Current2_var_clock1 : Current2_refs +-> BOOL) & ((Current2_var_res : Current2_refs +-> INTEGER) & ((Current2_var_tmp_0 : Current2_refs +-> INTEGER) & ((Current2_var_res2 : Current2_refs +-> INTEGER) & ((Current2_var_tmp_1 : Current2_refs +-> INTEGER) & ((Current2_var_tmp_4 : Current2_refs +-> INTEGER) & ((Current2_var_tmp_3 : Current2_refs +-> INTEGER) & ((Current2_var_tmp_6 : Current2_refs +-> INTEGER) & ((Current2_var_tmp_5 : Current2_refs +-> INTEGER) & ((Current2_var_tmp_7 : Current2_refs +-> INTEGER) & (((Current2_is_initialisation(Current2_clock___basic__) = FALSE) => (Current2_var_res /= {})) & (((Current2_is_initialisation(Current2_clock___basic__) = FALSE) => (Current2_var_res1 /= {})) & (((Current2_is_initialisation(Current2_clock___basic__) = FALSE) => (Current2_var_res2 /= {})) & (((Current2_is_initialisation(Current2_clock_clock1) = FALSE) => (Current2_var_clock1 /= {})) & ((Current2_is_initialisation(Current2_clock_clock2) = FALSE) => (Current2_var_clock2 /= {}))))))))))))))))))))

INITIALISATION 
    Current2_is_initialisation := (Current2_clocks * {TRUE}); 
    Current2_var_tmp_2 := {}; 
    Current2_var_res1 := {}; 
    Current2_var_clock2 := {}; 
    Current2_var_clock1 := {}; 
    Current2_var_res := {}; 
    Current2_var_tmp_0 := {}; 
    Current2_var_res2 := {}; 
    Current2_var_tmp_1 := {}; 
    Current2_var_tmp_4 := {}; 
    Current2_var_tmp_3 := {}; 
    Current2_var_tmp_6 := {}; 
    Current2_var_tmp_5 := {}; 
    Current2_var_tmp_7 := {}


OPERATIONS 

    Current2_clock_step(Current2_param_clock1, Current2_param_clock2) = 
        PRE
            ((Current2_param_clock1 : BOOL) & (Current2_param_clock2 : BOOL))
        THEN
            VAR Current2_tmp_2_history, Current2_res1_history, Current2_clock2_history, Current2_clock1_history, Current2_res_history, Current2_tmp_0_history, Current2_res2_history, Current2_tmp_1_history, Current2_tmp_4_history, Current2_tmp_3_history, Current2_tmp_6_history, Current2_tmp_5_history, Current2_tmp_7_history IN
                Current2_tmp_2_history := Current2_var_tmp_2; 
                Current2_res1_history := Current2_var_res1; 
                Current2_clock2_history := Current2_var_clock2; 
                Current2_clock1_history := Current2_var_clock1; 
                Current2_res_history := Current2_var_res; 
                Current2_tmp_0_history := Current2_var_tmp_0; 
                Current2_res2_history := Current2_var_res2; 
                Current2_tmp_1_history := Current2_var_tmp_1; 
                Current2_tmp_4_history := Current2_var_tmp_4; 
                Current2_tmp_3_history := Current2_var_tmp_3; 
                Current2_tmp_6_history := Current2_var_tmp_6; 
                Current2_tmp_5_history := Current2_var_tmp_5; 
                Current2_tmp_7_history := Current2_var_tmp_7; 
                Current2_var_clock1(Current2_ref) := bool((Current2_param_clock1 = TRUE)); 
                Current2_var_clock2(Current2_ref) := bool((Current2_param_clock2 = TRUE)); 
                IF (Current2_tmp_0_history /= {}) THEN 
                    Current2_var_tmp_1(Current2_ref) := Current2_tmp_0_history(Current2_ref)
                ELSE 
                    Current2_var_tmp_1 := {}
                END; 
                IF (not((Current2_is_initialisation(Current2_clock___basic__) = TRUE)) => (Current2_var_tmp_1 /= {})) THEN 
                    Current2_var_res(Current2_ref) := (IF (Current2_is_initialisation(Current2_clock___basic__) = TRUE) THEN 0 ELSE Current2_var_tmp_1(Current2_ref) END + 1)
                ELSE 
                    Current2_var_res := {}
                END; 
                IF (Current2_var_res /= {}) THEN 
                    Current2_var_tmp_2(Current2_ref) := Current2_var_res(Current2_ref)
                ELSE 
                    Current2_var_tmp_2 := {}
                END; 
                IF (Current2_var_clock1(Current2_ref) = TRUE) THEN 
                    IF (Current2_var_tmp_2 /= {}) THEN 
                        Current2_var_tmp_3(Current2_ref) := Current2_var_tmp_2(Current2_ref)
                    ELSE 
                        Current2_var_tmp_3 := {}
                    END
                END; 
                IF (Current2_var_clock1(Current2_ref) = TRUE) THEN 
                    IF (Current2_var_tmp_3 /= {}) THEN 
                        Current2_var_tmp_4(Current2_ref) := Current2_var_tmp_3(Current2_ref)
                    ELSE 
                        Current2_var_tmp_4 := {}
                    END
                END; 
                IF (Current2_var_tmp_4 /= {}) THEN 
                    Current2_var_res1(Current2_ref) := Current2_var_tmp_4(Current2_ref)
                ELSE 
                    Current2_var_res1 := {}
                END; 
                IF (Current2_var_res /= {}) THEN 
                    Current2_var_tmp_5(Current2_ref) := Current2_var_res(Current2_ref)
                ELSE 
                    Current2_var_tmp_5 := {}
                END; 
                IF (Current2_var_clock2(Current2_ref) = TRUE) THEN 
                    IF (Current2_var_tmp_5 /= {}) THEN 
                        Current2_var_tmp_6(Current2_ref) := Current2_var_tmp_5(Current2_ref)
                    ELSE 
                        Current2_var_tmp_6 := {}
                    END
                END; 
                IF (Current2_var_clock2(Current2_ref) = TRUE) THEN 
                    IF (Current2_var_tmp_6 /= {}) THEN 
                        Current2_var_tmp_7(Current2_ref) := Current2_var_tmp_6(Current2_ref)
                    ELSE 
                        Current2_var_tmp_7 := {}
                    END
                END; 
                IF (Current2_var_tmp_7 /= {}) THEN 
                    Current2_var_res2(Current2_ref) := Current2_var_tmp_7(Current2_ref)
                ELSE 
                    Current2_var_res2 := {}
                END; 
                IF (Current2_var_res /= {}) THEN 
                    Current2_var_tmp_0(Current2_ref) := Current2_var_res(Current2_ref)
                ELSE 
                    Current2_var_tmp_0 := {}
                END; 
                IF (Current2_var_clock1(Current2_ref) = TRUE) THEN 
                    Current2_is_initialisation(Current2_clock_clock1) := FALSE
                END; 
                Current2_is_initialisation(Current2_clock___basic__) := FALSE; 
                IF (Current2_var_clock2(Current2_ref) = TRUE) THEN 
                    Current2_is_initialisation(Current2_clock_clock2) := FALSE
                END

            END

        END;

        out <-- getRes = BEGIN out := Current2_var_res END;
        out <-- getRes1 = BEGIN out := Current2_var_res1 END;
        out <-- getRes2 = BEGIN out := Current2_var_res2 END



END