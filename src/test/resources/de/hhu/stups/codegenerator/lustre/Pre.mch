MACHINE Pre

VARIABLES Pre_is_initialisation, Pre_var_tmp_3, Pre_var_tmp_0, Pre_var_c, Pre_var_b, Pre_var_a, Pre_var_e, Pre_var_d, Pre_var_tmp_16, Pre_var_tmp_12, Pre_var_tmp_10, Pre_var_tmp_1, Pre_var_tmp_11, Pre_var_tmp_14, Pre_var_tmp_13, Pre_var_tmp_15, Pre_var_tmp_18, Pre_var_tmp_17, Pre_var_tmp_2, Pre_var_tmp_19, Pre_var_tmp_6, Pre_var_tmp_5, Pre_var_tmp_4, Pre_var_x, Pre_var_tmp_8, Pre_var_tmp_7, Pre_var_tmp_9, Pre_var_y

SETS Pre_clocks = {Pre_clock___basic__}; Pre_refs = {Pre_ref}

INVARIANT ((Pre_is_initialisation : Pre_clocks --> BOOL) & ((Pre_var_tmp_3 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_0 : Pre_refs +-> INTEGER) & ((Pre_var_c : Pre_refs +-> INTEGER) & ((Pre_var_b : Pre_refs +-> INTEGER) & ((Pre_var_a : Pre_refs +-> INTEGER) & ((Pre_var_e : Pre_refs +-> INTEGER) & ((Pre_var_d : Pre_refs +-> INTEGER) & ((Pre_var_tmp_16 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_12 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_10 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_1 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_11 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_14 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_13 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_15 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_18 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_17 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_2 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_19 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_6 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_5 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_4 : Pre_refs +-> INTEGER) & ((Pre_var_x : Pre_refs +-> INTEGER) & ((Pre_var_tmp_8 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_7 : Pre_refs +-> INTEGER) & ((Pre_var_tmp_9 : Pre_refs +-> INTEGER) & ((Pre_var_y : Pre_refs +-> INTEGER) & (((Pre_is_initialisation(Pre_clock___basic__) = FALSE) => (Pre_var_a /= {})) & (((Pre_is_initialisation(Pre_clock___basic__) = FALSE) => (Pre_var_b /= {})) & (((Pre_is_initialisation(Pre_clock___basic__) = FALSE) => (Pre_var_c /= {})) & (((Pre_is_initialisation(Pre_clock___basic__) = FALSE) => (Pre_var_d /= {})) & ((Pre_is_initialisation(Pre_clock___basic__) = FALSE) => (Pre_var_e /= {}))))))))))))))))))))))))))))))))))

INITIALISATION 
    Pre_is_initialisation := (Pre_clocks * {TRUE}); 
    Pre_var_tmp_3 := {}; 
    Pre_var_tmp_0 := {}; 
    Pre_var_c := {}; 
    Pre_var_b := {}; 
    Pre_var_a := {}; 
    Pre_var_e := {}; 
    Pre_var_d := {}; 
    Pre_var_tmp_16 := {}; 
    Pre_var_tmp_12 := {}; 
    Pre_var_tmp_10 := {}; 
    Pre_var_tmp_1 := {}; 
    Pre_var_tmp_11 := {}; 
    Pre_var_tmp_14 := {}; 
    Pre_var_tmp_13 := {}; 
    Pre_var_tmp_15 := {}; 
    Pre_var_tmp_18 := {}; 
    Pre_var_tmp_17 := {}; 
    Pre_var_tmp_2 := {}; 
    Pre_var_tmp_19 := {}; 
    Pre_var_tmp_6 := {}; 
    Pre_var_tmp_5 := {}; 
    Pre_var_tmp_4 := {}; 
    Pre_var_x := {}; 
    Pre_var_tmp_8 := {}; 
    Pre_var_tmp_7 := {}; 
    Pre_var_tmp_9 := {}; 
    Pre_var_y := {}


OPERATIONS 

    Pre_clock_step(Pre_param_x, Pre_param_y) = 
        PRE
            ((Pre_param_x : INTEGER) & (Pre_param_y : INTEGER))
        THEN
            VAR Pre_tmp_0_history, Pre_tmp_2_history, Pre_tmp_4_history, Pre_tmp_6_history, Pre_tmp_8_history, Pre_tmp_10_history, Pre_tmp_12_history, Pre_tmp_14_history, Pre_tmp_16_history, Pre_tmp_18_history IN
                Pre_tmp_0_history := Pre_var_tmp_0; 
                Pre_tmp_2_history := Pre_var_tmp_2; 
                Pre_tmp_4_history := Pre_var_tmp_4; 
                Pre_tmp_6_history := Pre_var_tmp_6; 
                Pre_tmp_8_history := Pre_var_tmp_8; 
                Pre_tmp_10_history := Pre_var_tmp_10; 
                Pre_tmp_12_history := Pre_var_tmp_12; 
                Pre_tmp_14_history := Pre_var_tmp_14; 
                Pre_tmp_16_history := Pre_var_tmp_16; 
                Pre_tmp_18_history := Pre_var_tmp_18; 
                Pre_var_x(Pre_ref) := Pre_param_x; 
                Pre_var_y(Pre_ref) := Pre_param_y; 
                IF (Pre_var_x /= {}) THEN 
                    Pre_var_tmp_0(Pre_ref) := Pre_var_x(Pre_ref)
                ELSE 
                    Pre_var_tmp_0 := {}
                END; 
                IF (Pre_tmp_0_history /= {}) THEN 
                    Pre_var_tmp_1(Pre_ref) := Pre_tmp_0_history(Pre_ref)
                ELSE 
                    Pre_var_tmp_1 := {}
                END; 
                IF (not((Pre_is_initialisation(Pre_clock___basic__) = TRUE)) => (Pre_var_tmp_1 /= {})) THEN 
                    Pre_var_a(Pre_ref) := IF (Pre_is_initialisation(Pre_clock___basic__) = TRUE) THEN 0 ELSE Pre_var_tmp_1(Pre_ref) END
                ELSE 
                    Pre_var_a := {}
                END; 
                IF (Pre_var_x /= {}) THEN 
                    Pre_var_tmp_2(Pre_ref) := Pre_var_x(Pre_ref)
                ELSE 
                    Pre_var_tmp_2 := {}
                END; 
                IF (Pre_tmp_2_history /= {}) THEN 
                    Pre_var_tmp_3(Pre_ref) := Pre_tmp_2_history(Pre_ref)
                ELSE 
                    Pre_var_tmp_3 := {}
                END; 
                IF (Pre_var_y /= {}) THEN 
                    Pre_var_tmp_4(Pre_ref) := Pre_var_y(Pre_ref)
                ELSE 
                    Pre_var_tmp_4 := {}
                END; 
                IF (Pre_tmp_4_history /= {}) THEN 
                    Pre_var_tmp_5(Pre_ref) := Pre_tmp_4_history(Pre_ref)
                ELSE 
                    Pre_var_tmp_5 := {}
                END; 
                IF (not((Pre_is_initialisation(Pre_clock___basic__) = TRUE)) => ((Pre_var_tmp_3 /= {}) & (Pre_var_tmp_5 /= {}))) THEN 
                    Pre_var_b(Pre_ref) := IF (Pre_is_initialisation(Pre_clock___basic__) = TRUE) THEN 0 ELSE (Pre_var_tmp_3(Pre_ref) + Pre_var_tmp_5(Pre_ref)) END
                ELSE 
                    Pre_var_b := {}
                END; 
                IF ((Pre_var_x /= {}) & (Pre_var_y /= {})) THEN 
                    Pre_var_tmp_6(Pre_ref) := (Pre_var_x(Pre_ref) + Pre_var_y(Pre_ref))
                ELSE 
                    Pre_var_tmp_6 := {}
                END; 
                IF (Pre_tmp_6_history /= {}) THEN 
                    Pre_var_tmp_7(Pre_ref) := Pre_tmp_6_history(Pre_ref)
                ELSE 
                    Pre_var_tmp_7 := {}
                END; 
                IF (not((Pre_is_initialisation(Pre_clock___basic__) = TRUE)) => (Pre_var_tmp_7 /= {})) THEN 
                    Pre_var_c(Pre_ref) := IF (Pre_is_initialisation(Pre_clock___basic__) = TRUE) THEN 0 ELSE Pre_var_tmp_7(Pre_ref) END
                ELSE 
                    Pre_var_c := {}
                END; 
                IF (Pre_var_x /= {}) THEN 
                    Pre_var_tmp_8(Pre_ref) := Pre_var_x(Pre_ref)
                ELSE 
                    Pre_var_tmp_8 := {}
                END; 
                IF (Pre_tmp_8_history /= {}) THEN 
                    Pre_var_tmp_9(Pre_ref) := Pre_tmp_8_history(Pre_ref)
                ELSE 
                    Pre_var_tmp_9 := {}
                END; 
                IF (not((Pre_is_initialisation(Pre_clock___basic__) = TRUE)) => (Pre_var_tmp_9 /= {})) THEN 
                    Pre_var_tmp_10(Pre_ref) := IF (Pre_is_initialisation(Pre_clock___basic__) = TRUE) THEN 2 ELSE Pre_var_tmp_9(Pre_ref) END
                ELSE 
                    Pre_var_tmp_10 := {}
                END; 
                IF (Pre_tmp_10_history /= {}) THEN 
                    Pre_var_tmp_11(Pre_ref) := Pre_tmp_10_history(Pre_ref)
                ELSE 
                    Pre_var_tmp_11 := {}
                END; 
                IF (not((Pre_is_initialisation(Pre_clock___basic__) = TRUE)) => (Pre_var_tmp_11 /= {})) THEN 
                    Pre_var_tmp_12(Pre_ref) := IF (Pre_is_initialisation(Pre_clock___basic__) = TRUE) THEN 1 ELSE Pre_var_tmp_11(Pre_ref) END
                ELSE 
                    Pre_var_tmp_12 := {}
                END; 
                IF (Pre_tmp_12_history /= {}) THEN 
                    Pre_var_tmp_13(Pre_ref) := Pre_tmp_12_history(Pre_ref)
                ELSE 
                    Pre_var_tmp_13 := {}
                END; 
                IF (not((Pre_is_initialisation(Pre_clock___basic__) = TRUE)) => (Pre_var_tmp_13 /= {})) THEN 
                    Pre_var_d(Pre_ref) := IF (Pre_is_initialisation(Pre_clock___basic__) = TRUE) THEN 0 ELSE Pre_var_tmp_13(Pre_ref) END
                ELSE 
                    Pre_var_d := {}
                END; 
                IF (Pre_var_x /= {}) THEN 
                    Pre_var_tmp_14(Pre_ref) := Pre_var_x(Pre_ref)
                ELSE 
                    Pre_var_tmp_14 := {}
                END; 
                IF (Pre_tmp_14_history /= {}) THEN 
                    Pre_var_tmp_15(Pre_ref) := Pre_tmp_14_history(Pre_ref)
                ELSE 
                    Pre_var_tmp_15 := {}
                END; 
                IF (not((Pre_is_initialisation(Pre_clock___basic__) = TRUE)) => (Pre_var_tmp_15 /= {})) THEN 
                    Pre_var_tmp_16(Pre_ref) := IF (Pre_is_initialisation(Pre_clock___basic__) = TRUE) THEN 1 ELSE Pre_var_tmp_15(Pre_ref) END
                ELSE 
                    Pre_var_tmp_16 := {}
                END; 
                IF (Pre_tmp_16_history /= {}) THEN 
                    Pre_var_tmp_17(Pre_ref) := Pre_tmp_16_history(Pre_ref)
                ELSE 
                    Pre_var_tmp_17 := {}
                END; 
                IF (Pre_var_y /= {}) THEN 
                    Pre_var_tmp_18(Pre_ref) := Pre_var_y(Pre_ref)
                ELSE 
                    Pre_var_tmp_18 := {}
                END; 
                IF (Pre_tmp_18_history /= {}) THEN 
                    Pre_var_tmp_19(Pre_ref) := Pre_tmp_18_history(Pre_ref)
                ELSE 
                    Pre_var_tmp_19 := {}
                END; 
                IF (not((Pre_is_initialisation(Pre_clock___basic__) = TRUE)) => (((Pre_is_initialisation(Pre_clock___basic__) = TRUE) => (Pre_var_tmp_17 /= {})) or (not((Pre_is_initialisation(Pre_clock___basic__) = TRUE)) => (Pre_var_tmp_19 /= {})))) THEN 
                    Pre_var_e(Pre_ref) := IF (Pre_is_initialisation(Pre_clock___basic__) = TRUE) THEN 0 ELSE IF (Pre_is_initialisation(Pre_clock___basic__) = TRUE) THEN (Pre_var_tmp_17(Pre_ref) + 0) ELSE Pre_var_tmp_19(Pre_ref) END END
                ELSE 
                    Pre_var_e := {}
                END; 
                Pre_is_initialisation(Pre_clock___basic__) := FALSE

            END

        END;

        out <-- getD = BEGIN out := Pre_var_d END



END