MACHINE M_NilChecking2

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_clock1, is_initialisation, is_initialisation_clock2, var_loc, var_res, var_tmp_0, var_clock1, var_tmp_2, var_clock2

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_clock1 : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock2 : BOOL) & ((var_clock1 : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((var_tmp_2 : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_BOOL) & ((var_loc : LUSTRE_INT) & ((var_clock2 : LUSTRE_BOOL) & ((is_initialisation = FALSE) => (var_res /= {}))))))))))))

INITIALISATION
    assert_ok := TRUE;
    is_initialisation_clock1 := TRUE;
    is_initialisation := TRUE;
    is_initialisation_clock2 := TRUE;
    var_loc := {};
    var_res := {};
    var_tmp_0 := {};
    var_clock1 := {};
    var_tmp_2 := {};
    var_clock2 := {}


OPERATIONS

    clock_step(param_clock1, param_x) =
        PRE
            ((param_clock1 : LUSTRE_BOOL_NOT_NIL) & (param_x : LUSTRE_INT_NOT_NIL))
        THEN
            VAR var_x, var_tmp_1 IN
                var_clock1 := param_clock1;
                PRE (var_clock1 /= {}) THEN skip END;
                var_x := param_x;
                IF (var_clock1 = {ref |-> TRUE}) THEN
                    var_tmp_2 := var_x
                END;
                var_tmp_1 := var_tmp_0;
                var_tmp_0 := {ref |-> TRUE};
                IF (var_clock1 = {ref |-> TRUE}) THEN
                    var_clock2 := var_tmp_1;
                    PRE (var_clock2 /= {}) THEN skip END

                END;
                IF ((var_clock1 = {ref |-> TRUE}) & (var_clock2 = {ref |-> TRUE})) THEN
                    var_loc := var_tmp_2
                END;
                var_res := {ref |-> 1};
                SELECT (assert_ok = TRUE) THEN skip END;
                IF (var_clock1 = {ref |-> TRUE}) THEN
                    is_initialisation_clock1 := FALSE
                END;
                is_initialisation := FALSE;
                IF ((var_clock1 = {ref |-> TRUE}) & (var_clock2 = {ref |-> TRUE})) THEN
                    is_initialisation_clock2 := FALSE
                END

            END

        END;

    out <-- getRes = BEGIN out := var_res END



END

/*
tmp_0: true
tmp_1: pre(true)
tmp_2: (x when clock1)
*/
