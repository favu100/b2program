
MACHINE Ref5_Switch
SETS /* enumerated */
  DOOR_STATE={open,closed,door_moving};
  GEAR_STATE={retracted,extended,gear_moving};
  HANDLE_STATE={up,down};
  PLANE_STATE={ground,flight};
  SWITCH_STATE={switch_open,switch_closed};
  VALVE_STATE={valve_open,valve_closed};
  STIMULI={open_door_stimulus,close_door_stimulus,retract_gear_stimulus,extend_gear_stimulus,stop_open_door_stimulus,stop_close_door_stimulus,stop_retract_gear_stimulus,stop_extend_gear_stimulus}
ABSTRACT_VARIABLES
  analogical_switch,
  general_EV,
  general_valve,
  handle_move,
  handle,
  last_handle_state,
  lock_door_opening,
  shock_absorber,
  door_closed,
  door_open,
  gear_extended,
  gear_retracted,
  last_door_action,
  last_gear_action,
  close_EV,
  extend_EV,
  open_EV,
  retract_EV,
  close_door_valve,
  extend_gear_valve,
  open_door_valve,
  retract_gear_valve,
  door,
  gear
/* PROMOTED OPERATIONS
  env_start_extending,
  env_extend_gear,
  env_retract_gear,
  env_start_retracting,
  env_start_open_door,
  env_open_door,
  env_close_door,
  env_start_close_door,
  env_open_valve_open_door,
  env_close_valve_open_door,
  env_open_valve_close_door,
  env_close_valve_close_door,
  env_open_valve_retract_gear,
  env_close_valve_retract_gear,
  env_open_valve_extend_gear,
  env_close_valve_extend_gear,
  con_stimulate_open_door_valve,
  con_stop_stimulate_open_door_valve,
  con_stimulate_close_door_valve,
  con_stop_stimulate_close_door_valve,
  con_stimulate_retract_gear_valve,
  con_stop_stimulate_retract_gear_valve,
  con_stimulate_extend_gear_valve,
  con_stop_stimulate_extend_gear_valve,
  env_toggle_handle,
  env_changeShockAbsorber,
  con_stimulate_general_valve,
  con_stop_stimulate_general_valve,
  evn_open_general_valve,
  evn_close_general_valve,
  env_close_switch,
  env_open_switch */
INVARIANT
    (/* @Ref5_Switch:r51  */ open_EV = TRUE or (close_EV = TRUE or (retract_EV = TRUE or extend_EV = TRUE)) => general_EV = TRUE)
  & card(last_handle_state) < 2
  & (/* @Ref4_ControllerHandle:r31simple  */ extend_EV = TRUE or retract_EV = TRUE => open_EV = TRUE)
  & /* @Ref3_ControllerSensors:last_door_action  */ last_door_action : POW({open_door_stimulus,close_door_stimulus})
  & card(last_door_action) < 2
  & /* @Ref3_ControllerSensors:last_gear_action  */ last_gear_action : POW({extend_gear_stimulus,retract_gear_stimulus})
  & card(last_gear_action) < 2
  & /* @Ref2_ControllerOutputs:R41  */ not(open_EV = TRUE & close_EV = TRUE)
INITIALISATION
    EVENT INITIALISATION = /* of machine Ref5_Switch */
    THEN
         gear := extended
      ||
         door := closed
      ||
         close_door_valve := valve_closed
      ||
         open_door_valve := valve_closed
      ||
         retract_gear_valve := valve_closed
      ||
         extend_gear_valve := valve_closed
      ||
         open_EV := FALSE
      ||
         close_EV := FALSE
      ||
         retract_EV := FALSE
      ||
         extend_EV := FALSE
      ||
         door_closed := TRUE
      ||
         door_open := FALSE
      ||
         gear_extended := TRUE
      ||
         gear_retracted := FALSE
      ||
         last_door_action := {}
      ||
         last_gear_action := {}
      ||
         handle := down
      ||
         last_handle_state := {}
      ||
         shock_absorber := flight
      ||
         lock_door_opening := FALSE
      ||
         general_EV := FALSE
      ||
         handle_move := FALSE
      ||
         general_valve := valve_closed
      ||
         analogical_switch := switch_open
    REFINES
      EVENT INITIALISATION = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT INITIALISATION = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT INITIALISATION = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT INITIALISATION = /* of machine Ref1_Valve */
            THEN
              skip
            REFINES
              EVENT INITIALISATION = /* of machine Mch0_GearDoor */
              THEN
                skip
              END
            END
          END
        END
      END
    END
OPERATIONS
  env_start_extending =
    EVENT env_start_extending = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd2  */ gear = retracted
      & /* @Ref5_Switch:grd3  */ extend_gear_valve = valve_open
      & /* @Ref5_Switch:grd4  */ retract_gear_valve = valve_closed
      & /* @Ref5_Switch:general_valve  */ general_valve = valve_open
    THEN
         gear := gear_moving
      ||
         gear_retracted := FALSE
    REFINES
      EVENT env_start_extending = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_start_extending = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_start_extending = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_start_extending = /* of machine Ref1_Valve */
            THEN
              skip
            REFINES
              EVENT env_start_extending = /* of machine Mch0_GearDoor */
              THEN
                skip
              END
            END
          END
        END
      END
    END;

  env_extend_gear =
    EVENT env_extend_gear = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd2  */ gear = gear_moving
      & /* @Ref5_Switch:grd3  */ extend_gear_valve = valve_open
      & /* @Ref5_Switch:grd4  */ retract_gear_valve = valve_closed
      & /* @Ref5_Switch:general_valve  */ general_valve = valve_open
    THEN
         gear := extended
      ||
         gear_extended := TRUE
    REFINES
      EVENT env_extend_gear = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_extend_gear = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_extend_gear = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_extend_gear = /* of machine Ref1_Valve */
            THEN
              skip
            REFINES
              EVENT env_extend_gear = /* of machine Mch0_GearDoor */
              THEN
                skip
              END
            END
          END
        END
      END
    END;

  env_retract_gear =
    EVENT env_retract_gear = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd2  */ gear = gear_moving
      & /* @Ref5_Switch:grd3  */ retract_gear_valve = valve_open
      & /* @Ref5_Switch:grd4  */ extend_gear_valve = valve_closed
      & /* @Ref5_Switch:general_valve  */ general_valve = valve_open
    THEN
         gear := retracted
      ||
         gear_retracted := TRUE
      ||
         shock_absorber := flight
    REFINES
      EVENT env_retract_gear = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_retract_gear = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_retract_gear = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_retract_gear = /* of machine Ref1_Valve */
            THEN
              skip
            REFINES
              EVENT env_retract_gear = /* of machine Mch0_GearDoor */
              THEN
                skip
              END
            END
          END
        END
      END
    END;

  env_start_retracting =
    EVENT env_start_retracting = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd2  */ gear = extended
      & /* @Ref5_Switch:grd3  */ retract_gear_valve = valve_open
      & /* @Ref5_Switch:grd4  */ extend_gear_valve = valve_closed
      & /* @Ref5_Switch:general_valve  */ general_valve = valve_open
    THEN
         gear := gear_moving
      ||
         gear_extended := FALSE
    REFINES
      EVENT env_start_retracting = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_start_retracting = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_start_retracting = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_start_retracting = /* of machine Ref1_Valve */
            THEN
              skip
            REFINES
              EVENT env_start_retracting = /* of machine Mch0_GearDoor */
              THEN
                skip
              END
            END
          END
        END
      END
    END;

  env_start_open_door =
    EVENT env_start_open_door = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd2  */ door = closed
      & /* @Ref5_Switch:grd3  */ open_door_valve = valve_open
      & /* @Ref5_Switch:grd4  */ close_door_valve = valve_closed
      & /* @Ref5_Switch:general_valve  */ general_valve = valve_open
    THEN
         door := door_moving
      ||
         door_closed := FALSE
    REFINES
      EVENT env_start_open_door = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_start_open_door = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_start_open_door = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_start_open_door = /* of machine Ref1_Valve */
            THEN
              skip
            REFINES
              EVENT env_start_open_door = /* of machine Mch0_GearDoor */
              THEN
                skip
              END
            END
          END
        END
      END
    END;

  env_open_door =
    EVENT env_open_door = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd2  */ door = door_moving
      & /* @Ref5_Switch:grd3  */ open_door_valve = valve_open
      & /* @Ref5_Switch:grd4  */ close_door_valve = valve_closed
      & /* @Ref5_Switch:general_valve  */ general_valve = valve_open
    THEN
         door := open
      ||
         door_open := TRUE
    REFINES
      EVENT env_open_door = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_open_door = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_open_door = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_open_door = /* of machine Ref1_Valve */
            THEN
              skip
            REFINES
              EVENT env_open_door = /* of machine Mch0_GearDoor */
              THEN
                skip
              END
            END
          END
        END
      END
    END;

  env_close_door =
    EVENT env_close_door = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd2  */ door = door_moving
      & /* @Ref5_Switch:grd3  */ close_door_valve = valve_open
      & /* @Ref5_Switch:grd4  */ open_door_valve = valve_closed
      & /* @Ref5_Switch:general_valve  */ general_valve = valve_open
    THEN
         door := closed
      ||
         door_closed := TRUE
    REFINES
      EVENT env_close_door = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_close_door = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_close_door = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_close_door = /* of machine Ref1_Valve */
            THEN
              skip
            REFINES
              EVENT env_close_door = /* of machine Mch0_GearDoor */
              THEN
                skip
              END
            END
          END
        END
      END
    END;

  env_start_close_door =
    EVENT env_start_close_door = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ door = open
      & /* @Ref5_Switch:grd3  */ close_door_valve = valve_open
      & /* @Ref5_Switch:grd4  */ open_door_valve = valve_closed
      & /* @Ref5_Switch:general_valve  */ general_valve = valve_open
    THEN
         door := door_moving
      ||
         door_open := FALSE
    REFINES
      EVENT env_start_close_door = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_start_close_door = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_start_close_door = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_start_close_door = /* of machine Ref1_Valve */
            THEN
              skip
            REFINES
              EVENT env_start_close_door = /* of machine Mch0_GearDoor */
              THEN
                skip
              END
            END
          END
        END
      END
    END;

  env_open_valve_open_door =
    EVENT env_open_valve_open_door = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ open_door_valve = valve_closed
      & /* @Ref5_Switch:grd3  */ open_EV = TRUE
    THEN
         open_door_valve := valve_open
    REFINES
      EVENT env_open_valve_open_door = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_open_valve_open_door = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_open_valve_open_door = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_open_valve_open_door = /* of machine Ref1_Valve */
            THEN
              skip
            END
          END
        END
      END
    END;

  env_close_valve_open_door =
    EVENT env_close_valve_open_door = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ open_door_valve = valve_open
      & /* @Ref5_Switch:grd3  */ open_EV = FALSE
    THEN
         open_door_valve := valve_closed
    REFINES
      EVENT env_close_valve_open_door = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_close_valve_open_door = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_close_valve_open_door = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_close_valve_open_door = /* of machine Ref1_Valve */
            THEN
              skip
            END
          END
        END
      END
    END;

  env_open_valve_close_door =
    EVENT env_open_valve_close_door = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ close_door_valve = valve_closed
      & /* @Ref5_Switch:grd3  */ close_EV = TRUE
    THEN
         close_door_valve := valve_open
    REFINES
      EVENT env_open_valve_close_door = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_open_valve_close_door = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_open_valve_close_door = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_open_valve_close_door = /* of machine Ref1_Valve */
            THEN
              skip
            END
          END
        END
      END
    END;

  env_close_valve_close_door =
    EVENT env_close_valve_close_door = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ close_door_valve = valve_open
      & /* @Ref5_Switch:grd2  */ close_EV = FALSE
    THEN
         close_door_valve := valve_closed
    REFINES
      EVENT env_close_valve_close_door = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_close_valve_close_door = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_close_valve_close_door = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_close_valve_close_door = /* of machine Ref1_Valve */
            THEN
              skip
            END
          END
        END
      END
    END;

  env_open_valve_retract_gear =
    EVENT env_open_valve_retract_gear = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ retract_gear_valve = valve_closed
      & /* @Ref5_Switch:grd3  */ retract_EV = TRUE
    THEN
         retract_gear_valve := valve_open
    REFINES
      EVENT env_open_valve_retract_gear = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_open_valve_retract_gear = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_open_valve_retract_gear = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_open_valve_retract_gear = /* of machine Ref1_Valve */
            THEN
              skip
            END
          END
        END
      END
    END;

  env_close_valve_retract_gear =
    EVENT env_close_valve_retract_gear = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ retract_gear_valve = valve_open
      & /* @Ref5_Switch:grd3  */ retract_EV = FALSE
    THEN
         retract_gear_valve := valve_closed
    REFINES
      EVENT env_close_valve_retract_gear = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_close_valve_retract_gear = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_close_valve_retract_gear = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_close_valve_retract_gear = /* of machine Ref1_Valve */
            THEN
              skip
            END
          END
        END
      END
    END;

  env_open_valve_extend_gear =
    EVENT env_open_valve_extend_gear = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ extend_gear_valve = valve_closed
      & /* @Ref5_Switch:grd3  */ extend_EV = TRUE
    THEN
         extend_gear_valve := valve_open
    REFINES
      EVENT env_open_valve_extend_gear = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_open_valve_extend_gear = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_open_valve_extend_gear = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_open_valve_extend_gear = /* of machine Ref1_Valve */
            THEN
              skip
            END
          END
        END
      END
    END;

  env_close_valve_extend_gear =
    EVENT env_close_valve_extend_gear = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ extend_gear_valve = valve_open
      & /* @Ref5_Switch:grd3  */ extend_EV = FALSE
    THEN
         extend_gear_valve := valve_closed
    REFINES
      EVENT env_close_valve_extend_gear = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT env_close_valve_extend_gear = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT env_close_valve_extend_gear = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          REFINES
            EVENT env_close_valve_extend_gear = /* of machine Ref1_Valve */
            THEN
              skip
            END
          END
        END
      END
    END;

  con_stimulate_open_door_valve =
    EVENT con_stimulate_open_door_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ open_EV = FALSE
      & /* @Ref5_Switch:grd2  */ close_EV = FALSE
      & (/* @Ref5_Switch:gear_not_moving  */ gear_extended = TRUE or gear_retracted = TRUE)
      & (/* @Ref5_Switch:handle  */ (gear = extended & handle = up) or (gear = retracted & handle = down))
      & /* @Ref5_Switch:dooropeningnotlocked  */ lock_door_opening = FALSE
      & /* @Ref5_Switch:general_ev  */ general_EV = TRUE
    THEN
         open_EV := TRUE
      ||
         last_door_action := {open_door_stimulus}
      ||
         last_handle_state := {handle}
    REFINES
      EVENT con_stimulate_open_door_valve = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT con_stimulate_open_door_valve = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT con_stimulate_open_door_valve = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          END
        END
      END
    END;

  con_stop_stimulate_open_door_valve =
    EVENT con_stop_stimulate_open_door_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ open_EV = TRUE
      & (/* @Ref5_Switch:handle  */ (gear = extended & handle = down) or (handle = up & (gear = retracted or (gear_extended = TRUE & door_open = TRUE & shock_absorber = ground))))
      & retract_EV = FALSE
      & extend_EV = FALSE
      & /* @Ref5_Switch:general_ev  */ general_EV = TRUE
    THEN
         open_EV := FALSE
      ||
         last_handle_state := {}
      ||
         lock_door_opening := TRUE
    REFINES
      EVENT con_stop_stimulate_open_door_valve = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT con_stop_stimulate_open_door_valve = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT con_stop_stimulate_open_door_valve = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          END
        END
      END
    END;

  con_stimulate_close_door_valve =
    EVENT con_stimulate_close_door_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd2  */ close_EV = FALSE
      & /* @Ref5_Switch:grd1  */ open_EV = FALSE
      & (/* @Ref5_Switch:grd  */ door_closed = FALSE or last_door_action = {open_door_stimulus})
      & (/* @Ref5_Switch:gear_not_moving  */ gear_extended = TRUE or gear_retracted = TRUE)
      & (/* @Ref5_Switch:gear_not_waitingformoving  */ (gear_extended = TRUE & handle = down) or (handle = up & (gear_retracted = TRUE or (gear_extended = TRUE & shock_absorber = ground))))
      & /* @Ref5_Switch:general_ev  */ general_EV = TRUE
    THEN
         close_EV := TRUE
      ||
         last_door_action := {close_door_stimulus}
      ||
         last_handle_state := {handle}
      ||
         lock_door_opening := TRUE
    REFINES
      EVENT con_stimulate_close_door_valve = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT con_stimulate_close_door_valve = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT con_stimulate_close_door_valve = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          END
        END
      END
    END;

  con_stop_stimulate_close_door_valve =
    EVENT con_stop_stimulate_close_door_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ close_EV = TRUE
      & (/* @Ref5_Switch:grd5  */ door_closed = TRUE or (door_closed = FALSE & last_handle_state /= {handle}))
      & /* @Ref5_Switch:general_ev  */ general_EV = TRUE
    THEN
         close_EV := FALSE
      ||
         last_handle_state := {}
    REFINES
      EVENT con_stop_stimulate_close_door_valve = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT con_stop_stimulate_close_door_valve = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT con_stop_stimulate_close_door_valve = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          END
        END
      END
    END;

  con_stimulate_retract_gear_valve =
    EVENT con_stimulate_retract_gear_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ retract_EV = FALSE
      & /* @Ref5_Switch:grd2  */ extend_EV = FALSE
      & /* @Ref5_Switch:grd3  */ open_EV = TRUE
      & /* @Ref5_Switch:door  */ door_open = TRUE
      & (/* @Ref5_Switch:grd4  */ gear_retracted = FALSE or (gear_retracted = TRUE & last_gear_action = {extend_gear_stimulus}))
      & /* @Ref5_Switch:grd7  */ handle = up
      & (/* @Ref5_Switch:grd8  */ gear_extended = TRUE or (gear_extended = FALSE & last_handle_state /= {handle}))
      & /* @Ref5_Switch:groundguard  */ shock_absorber = flight
      & /* @Ref5_Switch:general_ev  */ general_EV = TRUE
    THEN
         retract_EV := TRUE
      ||
         last_gear_action := {retract_gear_stimulus}
    REFINES
      EVENT con_stimulate_retract_gear_valve = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT con_stimulate_retract_gear_valve = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT con_stimulate_retract_gear_valve = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          END
        END
      END
    END;

  con_stop_stimulate_retract_gear_valve =
    EVENT con_stop_stimulate_retract_gear_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ retract_EV = TRUE
      & (/* @Ref5_Switch:grd  */ gear_retracted = TRUE or (gear_retracted = FALSE & handle = down))
      & /* @Ref5_Switch:general_ev  */ general_EV = TRUE
    THEN
         retract_EV := FALSE
    REFINES
      EVENT con_stop_stimulate_retract_gear_valve = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT con_stop_stimulate_retract_gear_valve = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT con_stop_stimulate_retract_gear_valve = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          END
        END
      END
    END;

  con_stimulate_extend_gear_valve =
    EVENT con_stimulate_extend_gear_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ extend_EV = FALSE
      & /* @Ref5_Switch:grd2  */ retract_EV = FALSE
      & /* @Ref5_Switch:grd3  */ open_EV = TRUE
      & /* @Ref5_Switch:door  */ door_open = TRUE
      & (/* @Ref5_Switch:grd  */ gear_extended = FALSE or (gear_extended = TRUE & last_gear_action = {retract_gear_stimulus}))
      & /* @Ref5_Switch:grd7  */ handle = down
      & (/* @Ref5_Switch:grd8  */ gear_retracted = TRUE or (gear_retracted = FALSE & last_handle_state /= {handle}))
      & /* @Ref5_Switch:general_ev  */ general_EV = TRUE
    THEN
         extend_EV := TRUE
      ||
         last_gear_action := {extend_gear_stimulus}
    REFINES
      EVENT con_stimulate_extend_gear_valve = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT con_stimulate_extend_gear_valve = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT con_stimulate_extend_gear_valve = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          END
        END
      END
    END;

  con_stop_stimulate_extend_gear_valve =
    EVENT con_stop_stimulate_extend_gear_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd2  */ extend_EV = TRUE
      & (/* @Ref5_Switch:grd  */ gear_extended = TRUE or (gear_extended = FALSE & handle = up))
      & /* @Ref5_Switch:general_ev  */ general_EV = TRUE
    THEN
         extend_EV := FALSE
    REFINES
      EVENT con_stop_stimulate_extend_gear_valve = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      REFINES
        EVENT con_stop_stimulate_extend_gear_valve = /* of machine Ref3_ControllerSensors */
        THEN
          skip
        REFINES
          EVENT con_stop_stimulate_extend_gear_valve = /* of machine Ref2_ControllerOutputs */
          THEN
            skip
          END
        END
      END
    END;

  env_toggle_handle =
    EVENT env_toggle_handle = /* of machine Ref5_Switch */
    THEN
         handle :: HANDLE_STATE \ {handle}
      ||
         lock_door_opening := FALSE
      ||
         handle_move := TRUE
    REFINES
      EVENT env_toggle_handle = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      END
    END;

  env_changeShockAbsorber =
    EVENT env_changeShockAbsorber = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd  */ gear_retracted = FALSE
    THEN
         shock_absorber :: PLANE_STATE \ {shock_absorber}
    REFINES
      EVENT env_changeShockAbsorber = /* of machine Ref4_ControllerHandle */
      THEN
        skip
      END
    END;

  con_stimulate_general_valve =
    EVENT con_stimulate_general_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ general_EV = FALSE
      & /* @Ref5_Switch:grd2  */ handle_move = TRUE
    THEN
         general_EV := TRUE
    END;

  con_stop_stimulate_general_valve =
    EVENT con_stop_stimulate_general_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ general_EV = TRUE
      & (/* @Ref5_Switch:grd2  */ (handle = up & (gear_retracted = TRUE & (door_closed = TRUE & (close_EV = FALSE & open_EV = FALSE)))) or (gear_extended = TRUE & ((handle = down & door_closed = TRUE & close_EV = FALSE & open_EV = FALSE & last_handle_state = {} & lock_door_opening = FALSE & last_door_action = {close_door_stimulus}) or (handle = up & door_closed = TRUE & close_EV = FALSE & open_EV = FALSE & lock_door_opening = TRUE))))
    THEN
         general_EV := FALSE
      ||
         handle_move := FALSE
    END;

  evn_open_general_valve =
    EVENT evn_open_general_valve = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ general_EV = TRUE
      & /* @Ref5_Switch:grd2  */ general_valve = valve_closed
      & /* @Ref5_Switch:grd3  */ analogical_switch = switch_closed
    THEN
         general_valve := valve_open
    END;

  evn_close_general_valve =
    EVENT evn_close_general_valve = /* of machine Ref5_Switch */
    WHEN
        (/* @Ref5_Switch:grd1  */ general_EV = FALSE or analogical_switch = switch_open)
      & /* @Ref5_Switch:grd2  */ general_valve = valve_open
    THEN
         general_valve := valve_closed
    END;

  env_close_switch =
    EVENT env_close_switch = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ analogical_switch = switch_open
      & /* @Ref5_Switch:grd2  */ handle_move = TRUE
    THEN
         analogical_switch := switch_closed
    END;

  env_open_switch =
    EVENT env_open_switch = /* of machine Ref5_Switch */
    WHEN
        /* @Ref5_Switch:grd1  */ analogical_switch = switch_closed
    THEN
         analogical_switch := switch_open
    END
END
