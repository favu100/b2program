MACHINE DroneCommunicator_Mockup
DEFINITIONS
  "LibraryZMQ_RPC.def";
  "LibraryReals.def";
  SET_PREF_MAX_OPERATIONS == 0;
CONSTANTS DRONE_URL
PROPERTIES DRONE_URL:STRING & DRONE_URL = "radio://0/80/2M/5700B500F4"
VARIABLES init, socket, cycle
INVARIANT
  init:BOOL &
  socket:INTEGER &
  cycle:INTEGER
INITIALISATION
  init := FALSE;
  socket := 0;
  cycle := 1

OPERATIONS
  EXTERNAL_Init =
  SELECT init = FALSE THEN
    init := TRUE
  END;
  
  EXTERNAL_open_link =
  SELECT init = TRUE THEN
    skip
  END;

  /*
  Available commanders:
  "motion" - cflib.positioning.motion_commander.MotionCommander
  "high_level" - cflib.crazyflie.high_level_commander.HighLevelCommander
  "position_high_level" (the default) - cflib.positioning.position_hl_commander.PositionHlCommander
  */
  EXTERNAL_open_link_with_commander_type(commander) =
  SELECT
    init = TRUE
    & commander : STRING
  THEN
    skip
  END;

  EXTERNAL_close_link =
  SELECT init = TRUE THEN
    skip
  END;

  EXTERNAL_register_sensors =
  SELECT init = TRUE THEN
    skip
  END;

  EXTERNAL_Drone_Takeoff =
  SELECT init = TRUE THEN
    skip
  END;

  EXTERNAL_Drone_Land =
  SELECT init = TRUE THEN
    skip
  END;

  EXTERNAL_Drone_Left(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    skip
  END;

  EXTERNAL_Drone_Right(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    skip
  END;

  EXTERNAL_Drone_Up(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    skip
  END;

  EXTERNAL_Drone_Down(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    skip
  END;

  EXTERNAL_Drone_Forward(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    skip
  END;

  EXTERNAL_Drone_Backward(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    skip
  END;

  EXTERNAL_Drone_Turn_Left(degrees) =
  SELECT
    init = TRUE &
    degrees : -360..360
  THEN
    skip
  END;

  EXTERNAL_Drone_Turn_Right(degrees) =
  SELECT
    init = TRUE &
    degrees : -360..360
  THEN
    skip
  END;

  out <-- EXTERNAL_Drone_GetX =
  SELECT init = TRUE THEN
    out := 2000;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetY =
  SELECT init = TRUE THEN
    out := 2000;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetZ =
  SELECT init = TRUE THEN
    out := 2000;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetBattery =
  SELECT init = TRUE THEN
    out := 100;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetFrontDistance =
  SELECT init = TRUE THEN
    out := 2000;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetBackDistance =
  SELECT init = TRUE THEN
    out := 2000;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetUpDistance =
  SELECT init = TRUE THEN
    out := 2000;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetDownDistance =
  SELECT init = TRUE THEN
    out := 2000;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetLeftDistance =
  SELECT init = TRUE THEN
    out := 2000;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetRightDistance =
  SELECT init = TRUE THEN
    out := 2000;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetRoll =
  SELECT init = TRUE THEN
    out := 0;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetPitch =
  SELECT init = TRUE THEN
    out := 0;
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetYaw =
  SELECT init = TRUE THEN
    out := 0;
    cycle := cycle + 1
  END;

  EXTERNAL_Destroy =
  SELECT init = TRUE THEN
    init := FALSE
  END
END
