/*
From ProB Examples
*/
MACHINE Lift
/* A simple model of a lift without a controller; The controller
   will be added in a refinement (by refining the lift moving operations) or
   by a CSP controller */
CONSTANTS groundf,topf, FLOORS
PROPERTIES
 groundf=-1 & topf=2 & groundf < topf & FLOORS = (groundf .. topf)
VARIABLES cur_floor, inside_buttons, door_open, call_buttons,direction_up
INVARIANT
 cur_floor : FLOORS &
 inside_buttons <: FLOORS &
 door_open : BOOL &
 call_buttons <: FLOORS &
 direction_up : BOOL
INITIALISATION
  cur_floor := groundf || inside_buttons := {} || door_open := FALSE || call_buttons := {} || direction_up := TRUE
OPERATIONS
  /* The lift operations : */
  move_up = PRE door_open = FALSE & cur_floor <topf & direction_up=TRUE THEN
    cur_floor := cur_floor +1
  END;
  move_down = PRE door_open = FALSE & cur_floor>groundf & direction_up=FALSE THEN
    cur_floor := cur_floor - 1
  END;
  reverse_lift_down = PRE direction_up=TRUE THEN direction_up := FALSE END;
  reverse_lift_up = PRE direction_up=FALSE THEN direction_up := TRUE END;
  open_door = PRE door_open = FALSE & cur_floor : (inside_buttons \/ call_buttons) THEN
    door_open := TRUE
  END;
  close_door = PRE door_open = TRUE THEN
    door_open := FALSE ||
     /* clear requests as floor now visited: */
    inside_buttons := inside_buttons - {cur_floor} || call_buttons := call_buttons - {cur_floor}
  END;
  
  /* The user interface : */
  push_inside_button(b) = PRE b:FLOORS & b/: inside_buttons & b/=cur_floor THEN
    inside_buttons := inside_buttons \/ {b}
  END;
  push_call_button(b) = PRE b:FLOORS & b/: call_buttons THEN
    call_buttons := call_buttons \/ {b}
  END
END