/*
Developed by Fabian Vu for OpenAI Environment
*/
MACHINE LunarLander

VARIABLES  x, y, v_x, v_y, angle, v_angular, left_leg_on_ground, right_leg_on_ground

INVARIANT x : REAL & y : REAL & v_x : REAL & v_y : REAL &
          angle : REAL & v_angular : REAL &
          left_leg_on_ground : BOOL & right_leg_on_ground : BOOL

INITIALISATION
  x :: REAL ||
  y :: REAL ||
  v_x :: REAL ||
  v_y :: REAL ||
  angle :: REAL ||
  v_angular :: REAL ||
  left_leg_on_ground :: BOOL ||
  right_leg_on_ground :: BOOL

OPERATIONS
  Do_Nothing = BEGIN
    x :: REAL ||
    y :: REAL ||
    v_x :: REAL ||
    v_y :: REAL ||
    angle :: REAL ||
    v_angular :: REAL ||
    left_leg_on_ground :: BOOL ||
    right_leg_on_ground :: BOOL
  END;

  Fire_Left = BEGIN
    x :: REAL ||
    y :: REAL ||
    v_x :: REAL ||
    v_y :: REAL ||
    angle :: REAL ||
    v_angular :: REAL ||
    left_leg_on_ground :: BOOL ||
    right_leg_on_ground :: BOOL
  END;

  Fire_Right = BEGIN
    x :: REAL ||
    y :: REAL ||
    v_x :: REAL ||
    v_y :: REAL ||
    angle :: REAL ||
    v_angular :: REAL ||
    left_leg_on_ground :: BOOL ||
    right_leg_on_ground :: BOOL
  END;

  Fire_Down = BEGIN
    x :: REAL ||
    y :: REAL ||
    v_x :: REAL ||
    v_y :: REAL ||
    angle :: REAL ||
    v_angular :: REAL ||
    left_leg_on_ground :: BOOL ||
    right_leg_on_ground :: BOOL
  END

END