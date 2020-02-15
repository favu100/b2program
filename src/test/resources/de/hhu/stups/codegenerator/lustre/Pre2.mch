MACHINE Pre2

VARIABLES Pre2_is_initialisation, Pre2_var_tmp_2, Pre2_var_tmp_0, Pre2_var_res1, Pre2_var_clock2, Pre2_var_clock1, Pre2_var_res, Pre2_var_res2, Pre2_var_tmp_11, Pre2_var_tmp_1, Pre2_var_tmp_10, Pre2_var_tmp_12, Pre2_var_tmp_13, Pre2_var_tmp_6, Pre2_var_tmp_4, Pre2_var_tmp_3, Pre2_var_tmp_5, Pre2_var_tmp_8, Pre2_var_tmp_7, Pre2_var_tmp_9

SETS Pre2_clocks = {Pre2_clock___basic__, Pre2_clock_clock1, Pre2_clock_clock2}; Pre2_refs = {Pre2_ref}

INVARIANT ((Pre2_is_initialisation : Pre2_clocks --> BOOL) & ((Pre2_var_tmp_2 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_0 : Pre2_refs +-> INTEGER) & ((Pre2_var_res1 : Pre2_refs +-> INTEGER) & ((Pre2_var_clock2 : Pre2_refs +-> BOOL) & ((Pre2_var_clock1 : Pre2_refs +-> BOOL) & ((Pre2_var_res : Pre2_refs +-> INTEGER) & ((Pre2_var_res2 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_11 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_1 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_10 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_12 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_13 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_6 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_4 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_3 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_5 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_8 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_7 : Pre2_refs +-> INTEGER) & ((Pre2_var_tmp_9 : Pre2_refs +-> INTEGER) & (((Pre2_is_initialisation(Pre2_clock___basic__) = FALSE) => (Pre2_var_res /= {})) & (((Pre2_is_initialisation(Pre2_clock___basic__) = FALSE) => (Pre2_var_res1 /= {})) & (((Pre2_is_initialisation(Pre2_clock___basic__) = FALSE) => (Pre2_var_res2 /= {})) & (((Pre2_is_initialisation(Pre2_clock_clock1) = FALSE) => (Pre2_var_clock1 /= {})) & ((Pre2_is_initialisation(Pre2_clock_clock2) = FALSE) => (Pre2_var_clock2 /= {}))))))))))))))))))))))))))

INITIALISATION 
    Pre2_is_initialisation := (Pre2_clocks * {TRUE}); 
    Pre2_var_tmp_2 := {}; 
    Pre2_var_tmp_0 := {}; 
    Pre2_var_res1 := {}; 
    Pre2_var_clock2 := {}; 
    Pre2_var_clock1 := {}; 
    Pre2_var_res := {}; 
    Pre2_var_res2 := {}; 
    Pre2_var_tmp_11 := {}; 
    Pre2_var_tmp_1 := {}; 
    Pre2_var_tmp_10 := {}; 
    Pre2_var_tmp_12 := {}; 
    Pre2_var_tmp_13 := {}; 
    Pre2_var_tmp_6 := {}; 
    Pre2_var_tmp_4 := {}; 
    Pre2_var_tmp_3 := {}; 
    Pre2_var_tmp_5 := {}; 
    Pre2_var_tmp_8 := {}; 
    Pre2_var_tmp_7 := {}; 
    Pre2_var_tmp_9 := {}


OPERATIONS 

    Pre2_clock_step(Pre2_param_clock1, Pre2_param_clock2) = 
        PRE
            ((Pre2_param_clock1 : BOOL) & (Pre2_param_clock2 : BOOL))
        THEN
            VAR Pre2_tmp_0_history, Pre2_tmp_6_history, Pre2_tmp_12_history IN
                Pre2_tmp_0_history := Pre2_var_tmp_0; 
                Pre2_tmp_6_history := Pre2_var_tmp_6; 
                Pre2_tmp_12_history := Pre2_var_tmp_12; 
                Pre2_var_clock1(Pre2_ref) := bool((Pre2_param_clock1 = TRUE)); 
                Pre2_var_clock2(Pre2_ref) := bool((Pre2_param_clock2 = TRUE)); 
                IF (Pre2_tmp_0_history /= {}) THEN 
                    Pre2_var_tmp_1(Pre2_ref) := Pre2_tmp_0_history(Pre2_ref)
                ELSE 
                    Pre2_var_tmp_1 := {}
                END; 
                IF (not((Pre2_is_initialisation(Pre2_clock___basic__) = TRUE)) => (Pre2_var_tmp_1 /= {})) THEN 
                    Pre2_var_res(Pre2_ref) := (IF (Pre2_is_initialisation(Pre2_clock___basic__) = TRUE) THEN 0 ELSE Pre2_var_tmp_1(Pre2_ref) END + 1)
                ELSE 
                    Pre2_var_res := {}
                END; 
                IF (Pre2_var_res /= {}) THEN 
                    Pre2_var_tmp_2(Pre2_ref) := Pre2_var_res(Pre2_ref)
                ELSE 
                    Pre2_var_tmp_2 := {}
                END; 
                IF (Pre2_var_clock1(Pre2_ref) = TRUE) THEN 
                    IF (Pre2_var_tmp_2 /= {}) THEN 
                        Pre2_var_tmp_3(Pre2_ref) := Pre2_var_tmp_2(Pre2_ref)
                    ELSE 
                        Pre2_var_tmp_3 := {}
                    END
                END; 
                IF (Pre2_var_clock1(Pre2_ref) = TRUE) THEN 
                    IF (Pre2_var_tmp_3 /= {}) THEN 
                        Pre2_var_tmp_4(Pre2_ref) := Pre2_var_tmp_3(Pre2_ref)
                    ELSE 
                        Pre2_var_tmp_4 := {}
                    END
                END; 
                IF (Pre2_var_tmp_4 /= {}) THEN 
                    Pre2_var_tmp_5(Pre2_ref) := Pre2_var_tmp_4(Pre2_ref)
                ELSE 
                    Pre2_var_tmp_5 := {}
                END; 
                IF (not((Pre2_is_initialisation(Pre2_clock___basic__) = TRUE)) => (Pre2_var_tmp_5 /= {})) THEN 
                    Pre2_var_tmp_6(Pre2_ref) := IF (Pre2_is_initialisation(Pre2_clock___basic__) = TRUE) THEN -(1) ELSE Pre2_var_tmp_5(Pre2_ref) END
                ELSE 
                    Pre2_var_tmp_6 := {}
                END; 
                IF (Pre2_tmp_6_history /= {}) THEN 
                    Pre2_var_tmp_7(Pre2_ref) := Pre2_tmp_6_history(Pre2_ref)
                ELSE 
                    Pre2_var_tmp_7 := {}
                END; 
                IF (not((Pre2_is_initialisation(Pre2_clock___basic__) = TRUE)) => (Pre2_var_tmp_7 /= {})) THEN 
                    Pre2_var_res1(Pre2_ref) := IF (Pre2_is_initialisation(Pre2_clock___basic__) = TRUE) THEN 0 ELSE Pre2_var_tmp_7(Pre2_ref) END
                ELSE 
                    Pre2_var_res1 := {}
                END; 
                IF (Pre2_var_res /= {}) THEN 
                    Pre2_var_tmp_8(Pre2_ref) := Pre2_var_res(Pre2_ref)
                ELSE 
                    Pre2_var_tmp_8 := {}
                END; 
                IF (Pre2_var_clock2(Pre2_ref) = TRUE) THEN 
                    IF (Pre2_var_tmp_8 /= {}) THEN 
                        Pre2_var_tmp_9(Pre2_ref) := Pre2_var_tmp_8(Pre2_ref)
                    ELSE 
                        Pre2_var_tmp_9 := {}
                    END
                END; 
                IF (Pre2_var_clock2(Pre2_ref) = TRUE) THEN 
                    IF (Pre2_var_tmp_9 /= {}) THEN 
                        Pre2_var_tmp_10(Pre2_ref) := Pre2_var_tmp_9(Pre2_ref)
                    ELSE 
                        Pre2_var_tmp_10 := {}
                    END
                END; 
                IF (Pre2_var_tmp_10 /= {}) THEN 
                    Pre2_var_tmp_11(Pre2_ref) := Pre2_var_tmp_10(Pre2_ref)
                ELSE 
                    Pre2_var_tmp_11 := {}
                END; 
                IF (not((Pre2_is_initialisation(Pre2_clock___basic__) = TRUE)) => (Pre2_var_tmp_11 /= {})) THEN 
                    Pre2_var_tmp_12(Pre2_ref) := IF (Pre2_is_initialisation(Pre2_clock___basic__) = TRUE) THEN -(1) ELSE Pre2_var_tmp_11(Pre2_ref) END
                ELSE 
                    Pre2_var_tmp_12 := {}
                END; 
                IF (Pre2_tmp_12_history /= {}) THEN 
                    Pre2_var_tmp_13(Pre2_ref) := Pre2_tmp_12_history(Pre2_ref)
                ELSE 
                    Pre2_var_tmp_13 := {}
                END; 
                IF (not((Pre2_is_initialisation(Pre2_clock___basic__) = TRUE)) => (Pre2_var_tmp_13 /= {})) THEN 
                    Pre2_var_res2(Pre2_ref) := IF (Pre2_is_initialisation(Pre2_clock___basic__) = TRUE) THEN 0 ELSE Pre2_var_tmp_13(Pre2_ref) END
                ELSE 
                    Pre2_var_res2 := {}
                END; 
                IF (Pre2_var_res /= {}) THEN 
                    Pre2_var_tmp_0(Pre2_ref) := Pre2_var_res(Pre2_ref)
                ELSE 
                    Pre2_var_tmp_0 := {}
                END; 
                IF (Pre2_var_clock1(Pre2_ref) = TRUE) THEN 
                    Pre2_is_initialisation(Pre2_clock_clock1) := FALSE
                END; 
                Pre2_is_initialisation(Pre2_clock___basic__) := FALSE; 
                IF (Pre2_var_clock2(Pre2_ref) = TRUE) THEN 
                    Pre2_is_initialisation(Pre2_clock_clock2) := FALSE
                END

            END

        END;

        out <-- getRes = BEGIN out := Pre2_var_res END;
        out <-- getRes1 = BEGIN out := Pre2_var_res1 END;
        out <-- getRes2 = BEGIN out := Pre2_var_res2 END



END