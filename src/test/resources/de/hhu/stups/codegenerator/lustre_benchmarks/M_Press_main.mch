//generated from Lustre
//taken from Production cell in Lustre, Leszek Holenderski

MACHINE M_Press_main

INCLUDES Node_14.M_sustain, Node_13.M_sustain, Node_12.M_sustain, Node_6.M_MovingItem, Node_9.M_sustain, Node_10.M_after_h, Node_7.M_sustain, Node_8.M_after_h, Node_11.M_sustain

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_Pup, var_Pdn, var_ArmsMayPassPress, var_Pstop

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_ArmsMayPassPress : LUSTRE_BOOL) & ((var_Pstop : LUSTRE_BOOL) & ((var_Pdn : LUSTRE_BOOL) & ((var_Pup : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_ArmsMayPassPress /= {})) & (((is_initialisation = FALSE) => (var_Pstop /= {})) & (((is_initialisation = FALSE) => (var_Pdn /= {})) & ((is_initialisation = FALSE) => (var_Pup /= {})))))))))))

INITIALISATION
    assert_ok := TRUE;
    is_initialisation := TRUE;
    var_Pup := {};
    var_Pdn := {};
    var_ArmsMayPassPress := {};
    var_Pstop := {}


OPERATIONS

    clock_step(param_Rput1, param_NearPress1, param_OutPress1, param_Rget2, param_NearPress2, param_OutPress2, param_Pbot, param_Pmid, param_Ptop) =
        PRE
            ((param_Rput1 : LUSTRE_BOOL_NOT_NIL) & ((param_NearPress1 : LUSTRE_BOOL_NOT_NIL) & ((param_OutPress1 : LUSTRE_BOOL_NOT_NIL) & ((param_Rget2 : LUSTRE_BOOL_NOT_NIL) & ((param_NearPress2 : LUSTRE_BOOL_NOT_NIL) & ((param_OutPress2 : LUSTRE_BOOL_NOT_NIL) & ((param_Pbot : LUSTRE_BOOL_NOT_NIL) & ((param_Pmid : LUSTRE_BOOL_NOT_NIL) & (param_Ptop : LUSTRE_BOOL_NOT_NIL)))))))))
        THEN
            VAR var_Rput1, var_NearPress1, var_OutPress1, var_Rget2, var_NearPress2, var_OutPress2, var_Pbot, var_Pmid, var_Ptop, var_Arm1MayPassPress, var_Arm2MayPassPress, var_Arm1OutOfPress, var_Arm2OutOfPress, var_ArmsOutOfPress, var_Arm1CannotCollideWithPress, var_Arm2CannotCollideWithPress, var_up, var_down, var_stopped IN
                var_Rput1 := param_Rput1;
                var_NearPress1 := param_NearPress1;
                var_OutPress1 := param_OutPress1;
                var_Rget2 := param_Rget2;
                var_NearPress2 := param_NearPress2;
                var_OutPress2 := param_OutPress2;
                var_Pbot := param_Pbot;
                var_Pmid := param_Pmid;
                var_Ptop := param_Ptop;
                Node_11.clock_step(l_fby_boolean(is_initialisation |-> {ref |-> FALSE} |-> l_and(var_Ptop |-> var_Pstop)), var_Pbot);
                var_down := Node_11.var_s;
                var_Arm1OutOfPress := l_or(l_not(var_NearPress1) |-> var_OutPress1);
                var_Arm2OutOfPress := l_or(l_not(var_NearPress2) |-> var_OutPress2);
                var_ArmsOutOfPress := l_and(var_Arm1OutOfPress |-> var_Arm2OutOfPress);
                Node_8.clock_step(var_ArmsOutOfPress, var_Rput1);
                Node_7.clock_step(Node_8.var_a, var_Ptop);
                Node_10.clock_step(var_ArmsOutOfPress, var_Rget2);
                Node_9.clock_step(Node_10.var_a, var_Pmid);
                var_up := l_or(Node_7.var_s |-> Node_9.var_s);
                Node_6.clock_step({ref |-> TRUE}, var_up, var_down);
                var_Pup := Node_6.var_start1;
                var_Pdn := Node_6.var_start2;
                var_Pstop := Node_6.var_stop;
                Node_12.clock_step(l_or(var_Pup |-> var_Pdn), var_Pstop);
                var_stopped := l_not(Node_12.var_s);
                Node_13.clock_step(var_Pbot, var_Pmid);
                Node_14.clock_step(var_Pmid, var_Pbot);
                var_Arm1CannotCollideWithPress := l_or(l_or(l_and(var_stopped |-> l_or(var_Pmid |-> var_Ptop)) |-> Node_13.var_s) |-> Node_14.var_s);
                var_Arm2CannotCollideWithPress := l_and(var_stopped |-> l_or(var_Pbot |-> var_Ptop));
                var_Arm1MayPassPress := l_or(var_Arm1OutOfPress |-> var_Arm1CannotCollideWithPress);
                var_Arm2MayPassPress := l_or(var_Arm2OutOfPress |-> var_Arm2CannotCollideWithPress);
                var_ArmsMayPassPress := l_and(var_Arm1MayPassPress |-> var_Arm2MayPassPress);
                SELECT ((assert_ok = TRUE) & ((Node_14.assert_ok = TRUE) & ((Node_13.assert_ok = TRUE) & ((Node_12.assert_ok = TRUE) & ((Node_6.assert_ok = TRUE) & ((Node_9.assert_ok = TRUE) & ((Node_10.assert_ok = TRUE) & ((Node_7.assert_ok = TRUE) & ((Node_8.assert_ok = TRUE) & (Node_11.assert_ok = TRUE)))))))))) THEN skip END;
                is_initialisation := FALSE

            END

        END



END

/*
Node_6: MovingItem(true, up, down)
Node_7: sustain(after_h(ArmsOutOfPress, Rput1), Ptop)
Node_8: after_h(ArmsOutOfPress, Rput1)
Node_9: sustain(after_h(ArmsOutOfPress, Rget2), Pmid)
Node_10: after_h(ArmsOutOfPress, Rget2)
Node_11: sustain((false -> (Ptop and pre(Pstop))), Pbot)
Node_12: sustain((Pup or Pdn), Pstop)
Node_13: sustain(Pbot, Pmid)
Node_14: sustain(Pmid, Pbot)
*/
