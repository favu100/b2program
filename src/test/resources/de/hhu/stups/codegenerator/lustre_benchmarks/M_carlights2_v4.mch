//generated from Lustre
//taken from https://github.com/jahierwan/lustre-examples, Lustre V6 Compiler applied to initial version carlights2.lus

MACHINE M_carlights2_v4

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation__AUTO_switch_pos_1, is_initialisation__OFF_switch_pos_1, is_initialisation__ON_switch_pos_1, var_is_on, var___tempo_2_1, var___tempo_1_1, var__split_1, var_tmp_0, var__OFF_switch_pos_1, var_tmp_1, var__ON_switch_pos_1, var__split_3, var_intensity, var__split_6, var_tmp_4, var_tmp_5, var_tmp_6, var_tmp_7, var_tmp_10, var_tmp_11, var_tmp_12, var_tmp_13, var_fm_auto, var_tmp_3, var_tmp_9, var_tmp_2, var_tmp_8, var__AUTO_switch_pos_1, var__split_27, var_res_auto, var__split_28

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation__AUTO_switch_pos_1 : BOOL) & ((is_initialisation__OFF_switch_pos_1 : BOOL) & ((is_initialisation__ON_switch_pos_1 : BOOL) & ((var_intensity : LUSTRE_INT) & ((var_is_on : LUSTRE_BOOL) & ((var_tmp_13 : LUSTRE_INT) & ((var_tmp_12 : LUSTRE_INT) & ((var_tmp_11 : LUSTRE_INT) & ((var_tmp_10 : LUSTRE_INT) & ((var_tmp_9 : LUSTRE_INT) & ((var_tmp_7 : LUSTRE_INT) & ((var_tmp_6 : LUSTRE_INT) & ((var_tmp_5 : LUSTRE_INT) & ((var_tmp_4 : LUSTRE_INT) & ((var_tmp_3 : LUSTRE_INT) & ((var_tmp_8 : LUSTRE_BOOL) & ((var_tmp_2 : LUSTRE_BOOL) & ((var_tmp_1 : LUSTRE_BOOL) & ((var_tmp_0 : LUSTRE_BOOL) & ((var_res_auto : LUSTRE_BOOL) & ((var_fm_auto : LUSTRE_BOOL) & ((var__split_1 : LUSTRE_BOOL) & ((var__split_3 : LUSTRE_BOOL) & ((var__split_6 : LUSTRE_BOOL) & ((var___tempo_2_1 : LUSTRE_INT) & ((var___tempo_1_1 : LUSTRE_INT) & ((var__AUTO_switch_pos_1 : LUSTRE_BOOL) & ((var__split_27 : LUSTRE_BOOL) & ((var__OFF_switch_pos_1 : LUSTRE_BOOL) & ((var__split_28 : LUSTRE_BOOL) & ((var__ON_switch_pos_1 : LUSTRE_BOOL) & ((is_initialisation = FALSE) => (var_is_on /= {})))))))))))))))))))))))))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation__AUTO_switch_pos_1 := TRUE; 
    is_initialisation__OFF_switch_pos_1 := TRUE; 
    is_initialisation__ON_switch_pos_1 := TRUE; 
    var_is_on := {}; 
    var___tempo_2_1 := {}; 
    var___tempo_1_1 := {}; 
    var__split_1 := {}; 
    var_tmp_0 := {}; 
    var__OFF_switch_pos_1 := {}; 
    var_tmp_1 := {}; 
    var__ON_switch_pos_1 := {}; 
    var__split_3 := {}; 
    var_intensity := {}; 
    var__split_6 := {}; 
    var_tmp_4 := {}; 
    var_tmp_5 := {}; 
    var_tmp_6 := {}; 
    var_tmp_7 := {}; 
    var_tmp_10 := {}; 
    var_tmp_11 := {}; 
    var_tmp_12 := {}; 
    var_tmp_13 := {}; 
    var_fm_auto := {}; 
    var_tmp_3 := {}; 
    var_tmp_9 := {}; 
    var_tmp_2 := {}; 
    var_tmp_8 := {}; 
    var__AUTO_switch_pos_1 := {}; 
    var__split_27 := {}; 
    var_res_auto := {}; 
    var__split_28 := {}


OPERATIONS 

    clock_step(param_switch_pos, param_intensity) = 
        PRE
            ((param_switch_pos : LUSTRE_INT_NOT_NIL) & (param_intensity : LUSTRE_INT_NOT_NIL))
        THEN
            VAR var_switch_pos, var___split_18_1, var___split_19_1, var___split_20_1, var___split_9_1, var___split_10_1, var___split_11_1, var___split_12_1, var___split_13_1, var___split_14_1, var___split_15_1, var___split_16_1, var___split_17_1, var___n_1_1, var_____split_21_1_1_1, var____x_1_1_1, var____split_26_1_1, var____split_25_1_1, var____split_24_1_1, var____split_23_1_1, var____split_22_1_1, var___n_2_1, var_____split_21_1_2_1, var____x_1_2_1, var____split_26_2_1, var____split_25_2_1, var____split_24_2_1, var____split_23_2_1, var____split_22_2_1, var__split_8, var__split_7, var__split_5, var__split_4, var__split_2 IN
                var_switch_pos := param_switch_pos; 
                var_intensity := param_intensity; 
                var_tmp_13 := {ref |-> 7}; 
                var_tmp_12 := {ref |-> 3}; 
                var_tmp_11 := {ref |-> 0}; 
                var_tmp_10 := {ref |-> 1}; 
                var_tmp_9 := {ref |-> 0}; 
                var_tmp_8 := {ref |-> FALSE}; 
                var_tmp_7 := {ref |-> 6}; 
                var_tmp_6 := {ref |-> 2}; 
                var_tmp_5 := {ref |-> 0}; 
                var_tmp_4 := {ref |-> 1}; 
                var_tmp_3 := {ref |-> 0}; 
                var_tmp_2 := {ref |-> TRUE}; 
                var_tmp_1 := {ref |-> TRUE}; 
                var_tmp_0 := {ref |-> FALSE}; 
                PRE (l_and(l_greater_equal(var_switch_pos |-> {ref |-> 0}) |-> l_less_equal(var_switch_pos |-> {ref |-> 2})) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_and(l_greater_equal(var_switch_pos |-> {ref |-> 0}) |-> l_less_equal(var_switch_pos |-> {ref |-> 2})) = {ref |-> TRUE}))); 
                PRE (l_and(l_greater_equal(var_intensity |-> {ref |-> 0}) |-> l_less_equal(var_intensity |-> {ref |-> 10})) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_and(l_greater_equal(var_intensity |-> {ref |-> 0}) |-> l_less_equal(var_intensity |-> {ref |-> 10})) = {ref |-> TRUE}))); 
                var__OFF_switch_pos_1 := l_equal_integer({ref |-> 0} |-> var_switch_pos); 
                PRE (var__OFF_switch_pos_1 /= {}) THEN skip END; 
                var__ON_switch_pos_1 := l_equal_integer({ref |-> 1} |-> var_switch_pos); 
                PRE (var__ON_switch_pos_1 /= {}) THEN skip END; 
                var__split_3 := l_less_equal(var_intensity |-> {ref |-> 7}); 
                var__split_6 := var_is_on; 
                var____split_23_2_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____split_23_2_1 := var___tempo_2_1
                END; 
                var____split_23_1_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____split_23_1_1 := var___tempo_1_1
                END; 
                var__AUTO_switch_pos_1 := l_equal_integer({ref |-> 2} |-> var_switch_pos); 
                PRE (var__AUTO_switch_pos_1 /= {}) THEN skip END; 
                var___split_18_1 := var__split_1; 
                var__split_1 := l_equal_integer(var_switch_pos |-> {ref |-> 2}); 
                IF (var__OFF_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var__split_27 := var_tmp_0
                END; 
                IF (var__ON_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var__split_28 := var_tmp_1
                END; 
                var__split_4 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var__split_4 := var__split_3
                END; 
                var__split_5 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var__split_5 := var_intensity
                END; 
                var__split_7 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var__split_7 := var__split_6
                END; 
                var____split_24_2_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____split_24_2_1 := l_minus(var____split_23_2_1 |-> var_tmp_4)
                END; 
                var____x_1_2_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____x_1_2_1 := var_tmp_5
                END; 
                var_____split_21_1_2_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var_____split_21_1_2_1 := l_greater(var____x_1_2_1 |-> var____split_24_2_1)
                END; 
                var____split_25_2_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____split_25_2_1 := l_ite_integer(var_____split_21_1_2_1 |-> var____x_1_2_1 |-> var____split_24_2_1)
                END; 
                var___n_2_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___n_2_1 := var_tmp_6
                END; 
                var___split_14_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___split_14_1 := l_less(var__split_5 |-> var_tmp_7)
                END; 
                var___split_13_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___split_13_1 := l_not(var__split_7)
                END; 
                var____split_24_1_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____split_24_1_1 := l_minus(var____split_23_1_1 |-> var_tmp_10)
                END; 
                var____x_1_1_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____x_1_1_1 := var_tmp_11
                END; 
                var_____split_21_1_1_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var_____split_21_1_1_1 := l_greater(var____x_1_1_1 |-> var____split_24_1_1)
                END; 
                var____split_25_1_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____split_25_1_1 := l_ite_integer(var_____split_21_1_1_1 |-> var____x_1_1_1 |-> var____split_24_1_1)
                END; 
                var___n_1_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___n_1_1 := var_tmp_12
                END; 
                var___split_9_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___split_9_1 := l_greater(var__split_5 |-> var_tmp_13)
                END; 
                var___split_19_1 := l_not(var___split_18_1); 
                var___split_15_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___split_15_1 := l_and(var___split_13_1 |-> var___split_14_1)
                END; 
                var___split_10_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___split_10_1 := l_and(var__split_7 |-> var___split_9_1)
                END; 
                var___split_20_1 := l_and(var__split_1 |-> var___split_19_1); 
                var_fm_auto := l_fby_boolean(is_initialisation |-> var__split_1 |-> var___split_20_1); 
                var__split_2 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var__split_2 := var_fm_auto
                END; 
                var____split_22_2_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____split_22_2_1 := l_not(var___split_15_1)
                END; 
                var____split_26_2_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____split_26_2_1 := l_ite_integer(var____split_22_2_1 |-> var___n_2_1 |-> var____split_25_2_1)
                END; 
                var____split_22_1_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____split_22_1_1 := l_not(var___split_10_1)
                END; 
                var____split_26_1_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var____split_26_1_1 := l_ite_integer(var____split_22_1_1 |-> var___n_1_1 |-> var____split_25_1_1)
                END; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___tempo_2_1 := l_fby_integer(is_initialisation__AUTO_switch_pos_1 |-> var___n_2_1 |-> var____split_26_2_1)
                END; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___tempo_1_1 := l_fby_integer(is_initialisation__AUTO_switch_pos_1 |-> var___n_1_1 |-> var____split_26_1_1)
                END; 
                var___split_16_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___split_16_1 := l_equal_integer(var___tempo_2_1 |-> var_tmp_3)
                END; 
                var___split_11_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___split_11_1 := l_equal_integer(var___tempo_1_1 |-> var_tmp_9)
                END; 
                var___split_17_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___split_17_1 := l_ite_boolean(var___split_16_1 |-> var_tmp_2 |-> var__split_7)
                END; 
                var___split_12_1 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var___split_12_1 := l_ite_boolean(var___split_11_1 |-> var_tmp_8 |-> var__split_7)
                END; 
                var__split_8 := {}; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var__split_8 := l_ite_boolean(var__split_7 |-> var___split_12_1 |-> var___split_17_1)
                END; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    var_res_auto := l_ite_boolean(var__split_2 |-> var__split_4 |-> var__split_8)
                END; 
                var_is_on := l_ite_boolean(var__OFF_switch_pos_1 |-> var__split_27 |-> l_ite_boolean(var__AUTO_switch_pos_1 |-> var_res_auto |-> var__split_28)); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var__AUTO_switch_pos_1 = {ref |-> TRUE}) THEN 
                    is_initialisation__AUTO_switch_pos_1 := FALSE
                END; 
                IF (var__OFF_switch_pos_1 = {ref |-> TRUE}) THEN 
                    is_initialisation__OFF_switch_pos_1 := FALSE
                END; 
                IF (var__ON_switch_pos_1 = {ref |-> TRUE}) THEN 
                    is_initialisation__ON_switch_pos_1 := FALSE
                END

            END

        END



END

/*
tmp_0: false
tmp_1: true
tmp_10: 1
tmp_11: 0
tmp_12: 3
tmp_13: 7
tmp_2: true
tmp_3: 0
tmp_4: 1
tmp_5: 0
tmp_6: 2
tmp_7: 6
tmp_8: false
tmp_9: 0
*/
