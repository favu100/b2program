//generated from Lustre
//taken from Programming and verifying real-time systems by means of the synchronous data-flow language LUSTRE, N.Halbwachs et. al


MACHINE M_UMS_main

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_grant_access, var_grant_exit, var_do_AB, var_do_BC

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_do_BC : LUSTRE_BOOL) & ((var_do_AB : LUSTRE_BOOL) & ((var_grant_exit : LUSTRE_BOOL) & ((var_grant_access : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_do_BC /= {})) & (((is_initialisation = FALSE) => (var_do_AB /= {})) & (((is_initialisation = FALSE) => (var_grant_exit /= {})) & ((is_initialisation = FALSE) => (var_grant_access /= {})))))))))))

INITIALISATION
    assert_ok := TRUE;
    is_initialisation := TRUE;
    var_grant_access := {};
    var_grant_exit := {};
    var_do_AB := {};
    var_do_BC := {}


OPERATIONS

    clock_step(param_on_A, param_on_B, param_on_C, param_ack_AB, param_ack_BC) =
        PRE
            ((param_on_A : LUSTRE_BOOL_NOT_NIL) & ((param_on_B : LUSTRE_BOOL_NOT_NIL) & ((param_on_C : LUSTRE_BOOL_NOT_NIL) & ((param_ack_AB : LUSTRE_BOOL_NOT_NIL) & (param_ack_BC : LUSTRE_BOOL_NOT_NIL)))))
        THEN
            VAR var_on_A, var_on_B, var_on_C, var_ack_AB, var_ack_BC, var_empty_section, var_only_on_B IN
                var_on_A := param_on_A;
                var_on_B := param_on_B;
                var_on_C := param_on_C;
                var_ack_AB := param_ack_AB;
                var_ack_BC := param_ack_BC;
                var_empty_section := l_not(l_or(l_or(var_on_A |-> var_on_B) |-> var_on_C));
                var_only_on_B := l_and(var_on_B |-> l_not(l_or(var_on_A |-> var_on_C)));
                var_grant_access := l_and(var_empty_section |-> var_ack_AB);
                var_grant_exit := l_and(var_only_on_B |-> var_ack_BC);
                var_do_AB := l_and(l_not(var_ack_AB) |-> var_empty_section);
                var_do_BC := l_and(l_not(var_ack_BC) |-> var_only_on_B);
                SELECT (assert_ok = TRUE) THEN skip END;
                is_initialisation := FALSE

            END

        END;

        out <-- getGrant_Access = BEGIN out := var_grant_access END;
        out <-- getGrant_Exit = BEGIN out := var_grant_exit END;
        out <-- getDo_AB = BEGIN out := var_do_AB END;
        out <-- getDo_BC = BEGIN out := var_do_BC END



END
