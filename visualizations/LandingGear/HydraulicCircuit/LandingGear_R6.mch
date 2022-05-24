MACHINE LandingGear_R6
SETS /* enumerated */
  DOOR_STATE={open,closed,door_moving};
  GEAR_STATE={retracted,extended,gear_moving};
  HANDLE_STATE={up,down};
  POSITION={fr,lt,rt};
  SWITCH_STATE={switch_open,switch_closed};
  PLANE_STATE={ground,flight};
  VALVE_STATE={valve_open,valve_closed}

VARIABLES
  analogical_switch,
  general_EV,
  general_valve,
  handle_move,
  close_EV,
  extend_EV,
  open_EV,
  retract_EV,
  shock_absorber,
  valve_close_door,
  valve_extend_gear,
  valve_open_door,
  valve_retract_gear,
  doors,
  gears,
  handle,
  door,
  gear

/* PROMOTED OPERATIONS
  begin_flying,
  land_plane,
  open_valve_door_open,
  close_valve_door_open,
  open_valve_door_close,
  close_valve_door_close,
  open_valve_retract_gear,
  close_valve_retract_gear,
  open_valve_extend_gear,
  close_valve_extend_gear,
  con_stimulate_open_door_valve,
  con_stop_stimulate_open_door_valve,
  con_stimulate_close_door_valve,
  con_stop_stimulate_close_door_valve,
  con_stimulate_retract_gear_valve,
  con_stop_stimulate_retract_gear_valve,
  con_stimulate_extend_gear_valve,
  con_stop_stimulate_extend_gear_valve,
  env_start_retracting_first,
  env_retract_gear_skip,
  env_retract_gear_last,
  env_start_extending,
  env_extend_gear_last,
  env_extend_gear_skip,
  env_start_open_door,
  env_open_door_last,
  env_open_door_skip,
  env_start_close_door,
  env_close_door,
  env_close_door_skip,
  toggle_handle_up,
  toggle_handle_down,
  con_stimulate_general_valve,
  con_stop_stimulate_general_valve,
  evn_open_general_valve,
  evn_close_general_valve,
  env_close_analogical_switch,
  env_open_analogical_switch */
INVARIANT
analogical_switch : SWITCH_STATE
& general_EV : BOOL
& general_valve : VALVE_STATE
& handle_move : BOOL
& close_EV : BOOL
& extend_EV : BOOL
& open_EV : BOOL
& retract_EV : BOOL
& shock_absorber : PLANE_STATE
& valve_close_door : VALVE_STATE
& valve_extend_gear : VALVE_STATE
& valve_open_door : VALVE_STATE
& valve_retract_gear : VALVE_STATE
& handle : HANDLE_STATE
& door : DOOR_STATE
& gear : GEAR_STATE
& /* @R6GearsDoorsHandleValvesControllerSwitch:r51 */ ((open_EV = TRUE or close_EV = TRUE or retract_EV = TRUE or extend_EV = TRUE) => general_EV = TRUE)
& /* @R5GearsDoorsHandleValvesController:R41 */ not(open_EV = TRUE & close_EV = TRUE)
& /* @R3GearsDoorsHandle:inv1 */ gears : POSITION --> GEAR_STATE
& /* @R3GearsDoorsHandle:inv2 */ doors : POSITION --> DOOR_STATE
& /* @R3GearsDoorsHandle:glued1 */ (door = closed <=> ran(doors) = {closed})
& /* @R3GearsDoorsHandle:glued2 */ (door = open <=> ran(doors) = {open})
& /* @R3GearsDoorsHandle:glueg1 */ (gear = extended <=> ran(gears) = {extended})
& /* @R3GearsDoorsHandle:glueg2 */ (gear = retracted <=> ran(gears) = {retracted})
& /* @R1GearDoor:safety_inv1 */ (gear = gear_moving => door = open)


INITIALISATION
    gears := POSITION * {extended} ||
    doors := POSITION * {closed} ||
    handle := down ||
    valve_extend_gear := valve_closed ||
    valve_retract_gear := valve_closed ||
    valve_open_door := valve_closed ||
    valve_close_door := valve_closed ||
    open_EV := FALSE ||
    close_EV := FALSE ||
    retract_EV := FALSE ||
    extend_EV := FALSE ||
    shock_absorber := ground ||
    general_EV := FALSE ||
    general_valve := valve_closed ||
    analogical_switch := switch_open ||
    handle_move := FALSE ||
    gear := extended ||
    door := closed

OPERATIONS

    begin_flying =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:onground */ shock_absorber = ground
    THEN
        shock_absorber := flight
    END;

    land_plane =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:onground */ shock_absorber = flight
    THEN
        shock_absorber := ground
    END;

    open_valve_door_open =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:valve_not_open */ valve_open_door = valve_closed
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd3 */ open_EV = TRUE
    THEN
        valve_open_door := valve_open
    END;

    close_valve_door_open =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:valve_not_closed */ valve_open_door = valve_open
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd3 */ open_EV = FALSE
    THEN
        valve_open_door := valve_closed
    END;

    open_valve_door_close =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:valve_not_open */ valve_close_door = valve_closed
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd3 */ close_EV = TRUE
    THEN
        valve_close_door := valve_open
    END;

    close_valve_door_close =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:valve_not_closed */ valve_close_door = valve_open
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd2 */ close_EV = FALSE
    THEN
        valve_close_door := valve_closed
    END;

    open_valve_retract_gear =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:valve_not_open */ valve_retract_gear = valve_closed
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd3 */ retract_EV = TRUE
    THEN
        valve_retract_gear := valve_open
    END;

    close_valve_retract_gear =
    SELECT
    /* @R6GearsDoorsHandleValvesControllerSwitch:valve_not_closed */ valve_retract_gear = valve_open
    & /* @R6GearsDoorsHandleValvesControllerSwitch:grd3 */ retract_EV = FALSE
    THEN
        valve_retract_gear := valve_closed
    END;

    open_valve_extend_gear =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:valve_not_open */ valve_extend_gear = valve_closed
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd3 */ extend_EV = TRUE
    THEN
        valve_extend_gear := valve_open
    END;

    close_valve_extend_gear =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:valve_not_closed */ valve_extend_gear = valve_open
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd3 */ extend_EV = FALSE
    THEN
        valve_extend_gear := valve_closed
    END;

    con_stimulate_open_door_valve =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ open_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd2 */ close_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grdh1 */ ((handle = down & not(ran(gears) = {extended})) or (handle = up & not(ran(gears) = {retracted}) & not(ran(doors) = {open} & shock_absorber = ground)))
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_ev */ general_EV = TRUE
    THEN
        open_EV := TRUE
    END;

    con_stop_stimulate_open_door_valve =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ open_EV = TRUE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd11 */ extend_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd12 */ retract_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grdh1 */ ((handle = down & ran(gears) = {extended}) or (handle = up & (ran(gears) = {retracted} or shock_absorber = ground) & ran(doors) = {open}))
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_ev */ general_EV = TRUE
    THEN
        open_EV := FALSE
    END;

    con_stimulate_close_door_valve =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:grd2 */ close_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ open_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd11 */ extend_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd12 */ retract_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grdh1 */ ((handle = down & ran(gears) = {extended}) or (handle = up & (ran(gears) = {retracted} or shock_absorber = ground)))
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grddoors */ not(ran(doors) = {closed})
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_ev */ general_EV = TRUE
    THEN
        close_EV := TRUE
    END;

    con_stop_stimulate_close_door_valve =
    SELECT
    /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ close_EV = TRUE
    & /* @R6GearsDoorsHandleValvesControllerSwitch:grdh1 */ ((handle = down & ran(gears) = {extended} & ran(doors) = {closed}) or (handle = up & (ran(gears) = {retracted} or shock_absorber = ground) & ran(doors) = {closed}))
    & /* @R6GearsDoorsHandleValvesControllerSwitch:general_ev */ general_EV = TRUE
    THEN
        close_EV := FALSE
    END;

    con_stimulate_retract_gear_valve =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ retract_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd2 */ extend_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd3 */ open_EV = TRUE
        & handle = up
        & not(ran(gears) = {retracted})
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grdflight */ shock_absorber = flight
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grddoors */ ran(doors) = {open}
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_ev */ general_EV = TRUE
    THEN
        retract_EV := TRUE
    END;

    con_stop_stimulate_retract_gear_valve =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ retract_EV = TRUE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grdh1 */ (handle = down or ran(gears) = {retracted})
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_ev */ general_EV = TRUE
    THEN
        retract_EV := FALSE
    END;

    con_stimulate_extend_gear_valve =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ extend_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd2 */ retract_EV = FALSE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grd3 */ open_EV = TRUE
        & handle = down
        & not(ran(gears) = {extended})
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grddoors */ ran(doors) = {open}
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_ev */ general_EV = TRUE
    THEN
        extend_EV := TRUE
    END;

    con_stop_stimulate_extend_gear_valve =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:grd2 */ extend_EV = TRUE
        & /* @R6GearsDoorsHandleValvesControllerSwitch:grdh1 */ (handle = up or ran(gears) = {extended})
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_ev */ general_EV = TRUE
    THEN
        extend_EV := FALSE
    END;

    env_start_retracting_first(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
        & /* @R6GearsDoorsHandleValvesControllerSwitch:all_doors_open */ ran(doors) = {open}
        & /* @R6GearsDoorsHandleValvesControllerSwitch:handle_up */ handle = up
        & /* @R6GearsDoorsHandleValvesControllerSwitch:g1 */ gears(gr) = extended
        & /* @R6GearsDoorsHandleValvesControllerSwitch:gv */ valve_retract_gear = valve_open
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
        & /* @R2GearDoorHandle:g1 */ gear : {extended,gear_moving}
        & /* @R2GearDoorHandle:door_open */ door = open
    THEN
        gears := gears <+ {gr |-> gear_moving} ||
        gear := gear_moving
    END;

    env_retract_gear_skip(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
        & /* @R6GearsDoorsHandleValvesControllerSwitch:all_doors_open */ ran(doors) = {open}
        & /* @R6GearsDoorsHandleValvesControllerSwitch:all_others */ gears[POSITION \ {gr}] /= {retracted}
        & /* @R6GearsDoorsHandleValvesControllerSwitch:handle_up */ handle = up
        & /* @R6GearsDoorsHandleValvesControllerSwitch:g1 */ gears(gr) = gear_moving
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
    THEN
        gears := gears <+ {gr |-> retracted}
    END;

    env_retract_gear_last(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
    SELECT
        /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
        & /* @R6GearsDoorsHandleValvesControllerSwitch:all_doors_open */ ran(doors) = {open}
        & /* @R6GearsDoorsHandleValvesControllerSwitch:all_others */ gears[POSITION \ {gr}] = {retracted}
        & /* @R6GearsDoorsHandleValvesControllerSwitch:handle_up */ handle = up
        & /* @R6GearsDoorsHandleValvesControllerSwitch:g1 */ gears(gr) = gear_moving
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
        & /* @R2GearDoorHandle:g1 */ gear = gear_moving
        & /* @R2GearDoorHandle:door_open */ door = open
    THEN
        gears := gears <+ {gr |-> retracted} ||
        gear := retracted
    END;

        env_start_extending(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
            & /* @R6GearsDoorsHandleValvesControllerSwitch:all_doors_open */ ran(doors) = {open}
            & /* @R6GearsDoorsHandleValvesControllerSwitch:handle_down */ handle = down
            & /* @R6GearsDoorsHandleValvesControllerSwitch:g1 */ gears(gr) = retracted
            & /* @R6GearsDoorsHandleValvesControllerSwitch:gv */ valve_extend_gear = valve_open
            & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
            & /* @R2GearDoorHandle:g1 */ gear : {gear_moving,retracted}
            & /* @R2GearDoorHandle:door_open */ door = open
        THEN
            gears := gears <+ {gr |-> gear_moving} ||
            gear := gear_moving
        END;

        env_extend_gear_last(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
            & /* @R6GearsDoorsHandleValvesControllerSwitch:all_doors_open */ ran(doors) = {open}
            & /* @R6GearsDoorsHandleValvesControllerSwitch:handle_down */ handle = down
            & /* @R6GearsDoorsHandleValvesControllerSwitch:all_others */ gears[POSITION \ {gr}] = {extended}
            & /* @R6GearsDoorsHandleValvesControllerSwitch:g1 */ gears(gr) = gear_moving
            & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
            & /* @R2GearDoorHandle:g1 */ gear = gear_moving
            & /* @R2GearDoorHandle:door_open */ door = open
        THEN
            gears := gears <+ {gr |-> extended} ||
            gear := extended
        END;

        env_extend_gear_skip(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
            & /* @R6GearsDoorsHandleValvesControllerSwitch:all_doors_open */ ran(doors) = {open}
            & /* @R6GearsDoorsHandleValvesControllerSwitch:handle_down */ handle = down
            & /* @R6GearsDoorsHandleValvesControllerSwitch:all_others */ gears[POSITION \ {gr}] /= {extended}
            & /* @R6GearsDoorsHandleValvesControllerSwitch:g1 */ gears(gr) = gear_moving
            & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
        THEN
            gears := gears <+ {gr |-> extended}
        END;

        env_start_open_door(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
            & doors(gr) = closed
            & gears(gr) /= gear_moving
            & /* @R6GearsDoorsHandleValvesControllerSwitch:nomov */ gear_moving /: ran(gears)
            & /* @R6GearsDoorsHandleValvesControllerSwitch:h */ ((handle = down & ran(gears) = {retracted}) or (handle = up & ran(gears) = {extended}))
            & /* @R6GearsDoorsHandleValvesControllerSwitch:gv */ valve_open_door = valve_open
            & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
            & door : {closed,door_moving}
            & gear /= gear_moving
            & /* @R2GearDoorHandle:h */ ((handle = down & gear = retracted) or (handle = up & gear = extended))
        THEN
            doors := doors <+ {gr |-> door_moving} ||
            door := door_moving
        END;

        env_open_door_last(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
            & doors(gr) = door_moving
            & gears(gr) /= gear_moving
            & /* @R6GearsDoorsHandleValvesControllerSwitch:nomov */ gear_moving /: ran(gears)
            & /* @R6GearsDoorsHandleValvesControllerSwitch:all_others */ doors[POSITION \ {gr}] = {open}
            & /* @R6GearsDoorsHandleValvesControllerSwitch:h */ ((handle = down & ran(gears) = {retracted}) or (handle = up & ran(gears) = {extended}))
            & /* @R6GearsDoorsHandleValvesControllerSwitch:gv */ valve_open_door = valve_open
            & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
            & door = door_moving
            & gear /= gear_moving
            & /* @R2GearDoorHandle:h */ ((handle = down & gear = retracted) or (handle = up & gear = extended))
        THEN
            doors := doors <+ {gr |-> open} ||
            door := open
        END;

        env_open_door_skip(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
            & doors(gr) = door_moving
            & gears(gr) /= gear_moving
            & /* @R6GearsDoorsHandleValvesControllerSwitch:nomov */ gear_moving /: ran(gears)
            & /* @R6GearsDoorsHandleValvesControllerSwitch:all_others */ doors[POSITION \ {gr}] /= {open}
            & /* @R6GearsDoorsHandleValvesControllerSwitch:h */ ((handle = down & ran(gears) = {retracted}) or (handle = up & ran(gears) = {extended}))
            & /* @R6GearsDoorsHandleValvesControllerSwitch:gv */ valve_open_door = valve_open
            & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
        THEN
            doors := doors <+ {gr |-> open}
        END;

        env_start_close_door(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
            & doors(gr) = open
            & gears(gr) /= gear_moving
            & /* @R6GearsDoorsHandleValvesControllerSwitch:h */ ((handle = up & (ran(gears) = {retracted} or ran(gears) = {extended})) or (handle = down & ran(gears) = {extended}))
            & /* @R6GearsDoorsHandleValvesControllerSwitch:gv */ valve_close_door = valve_open
            & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
            & door : {door_moving,open} & gear /= gear_moving & /* @R2GearDoorHandle:h */ ((handle = down & gear = extended) or (handle = up & gear : {extended,retracted}))
        THEN
            doors := doors <+ {gr |-> door_moving} ||
            door := door_moving
        END;

        env_close_door(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
            & doors(gr) = door_moving & gears(gr) /= gear_moving & /* @R6GearsDoorsHandleValvesControllerSwitch:nomov */ gear_moving /: ran(gears)
            & /* @R6GearsDoorsHandleValvesControllerSwitch:all_others */ doors[POSITION \ {gr}] = {closed}
            & /* @R6GearsDoorsHandleValvesControllerSwitch:h */ ((handle = up & (ran(gears) = {retracted} or ran(gears) = {extended})) or (handle = down & ran(gears) = {extended}))
            & /* @R6GearsDoorsHandleValvesControllerSwitch:gv */ valve_close_door = valve_open
            & /* @R6GearsDoorsHandleValvesControllerSwitch:hground */ ((handle = up & ran(gears) = {extended}) => shock_absorber = ground)
            & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open & door = door_moving & gear /= gear_moving
            & /* @R2GearDoorHandle:h */ ((handle = down & gear = extended) or (handle = up & gear : {extended,retracted}))
        THEN
            doors := doors <+ {gr |-> closed} ||
            door := closed
        END;

        env_close_door_skip(/* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr) =
        SELECT /* @R6GearsDoorsHandleValvesControllerSwitch:gr */ gr : dom(gears)
        & doors(gr) = door_moving
        & gears(gr) /= gear_moving
        & /* @R6GearsDoorsHandleValvesControllerSwitch:nomov */ gear_moving /: ran(gears)
        & /* @R6GearsDoorsHandleValvesControllerSwitch:all_others */ doors[POSITION \ {gr}] /= {closed}
        & /* @R6GearsDoorsHandleValvesControllerSwitch:h */ ((handle = up & (ran(gears) = {retracted} or ran(gears) = {extended})) or (handle = down & ran(gears) = {extended}))
        & /* @R6GearsDoorsHandleValvesControllerSwitch:gv */ valve_close_door = valve_open
        & /* @R6GearsDoorsHandleValvesControllerSwitch:hground */ ((handle = up & ran(gears) = {extended}) => shock_absorber = ground)
        & /* @R6GearsDoorsHandleValvesControllerSwitch:general_valve */ general_valve = valve_open
        THEN
            doors := doors <+ {gr |-> closed}
        END;

        toggle_handle_up =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:h */ handle = down
        THEN
            handle := up ||
            handle_move := TRUE
        END;

        toggle_handle_down =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:h */ handle = up
        THEN
            handle := down ||
            handle_move := TRUE
        END;

        con_stimulate_general_valve =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ general_EV = FALSE
            & /* @R6GearsDoorsHandleValvesControllerSwitch:grd2 */ handle_move = TRUE
        THEN
            general_EV := TRUE
        END;

        con_stop_stimulate_general_valve =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ general_EV = TRUE
            & open_EV = FALSE
            & close_EV = FALSE
            & retract_EV = FALSE
            & extend_EV = FALSE
            & close_EV = FALSE
            & ((handle = up & ran(gears) = {retracted} & ran(doors) = {closed} & open_EV = FALSE) or (handle = down & ran(gears) = {extended} & ran(doors) = {closed} & open_EV = FALSE) or (handle = up & ran(gears) = {extended} & ran(doors) = {closed} & open_EV = FALSE))
        THEN
            general_EV := FALSE ||
            handle_move := FALSE
        END;

        evn_open_general_valve =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ general_EV = TRUE
            & /* @R6GearsDoorsHandleValvesControllerSwitch:grd2 */ general_valve = valve_closed
            & /* @R6GearsDoorsHandleValvesControllerSwitch:grd3 */ analogical_switch = switch_closed
        THEN
            general_valve := valve_open
        END;

        evn_close_general_valve =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ (general_EV = FALSE or analogical_switch = switch_open )
            & /* @R6GearsDoorsHandleValvesControllerSwitch:grd2 */ general_valve = valve_open
        THEN
            general_valve := valve_closed
        END;

        env_close_analogical_switch =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ analogical_switch = switch_open
            & /* @R6GearsDoorsHandleValvesControllerSwitch:grd2 */ handle_move = TRUE
        THEN
            analogical_switch := switch_closed
        END;

        env_open_analogical_switch =
        SELECT
            /* @R6GearsDoorsHandleValvesControllerSwitch:grd1 */ analogical_switch = switch_closed
        THEN
            analogical_switch := switch_open
        END

END
