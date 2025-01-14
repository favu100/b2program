MACHINE DroneCommunicator// USES LibraryZMQ_RPC
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
    socket := ZMQ_RPC_INIT("tcp://localhost:22272");
    init := TRUE
  END;
  
  EXTERNAL_open_link =
  SELECT init = TRUE THEN
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "open_link", {("url" |-> RpcString(DRONE_URL)), ("reinit" |-> RpcBoolean(TRUE))}))
    END
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
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "open_link", {("url" |-> RpcString(DRONE_URL)), ("reinit" |-> RpcBoolean(TRUE)), ("commander" |-> RpcString(commander))}))
    END
  END;

  EXTERNAL_close_link =
  SELECT init = TRUE THEN
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "close_link", {("url" |-> RpcString(DRONE_URL))}))
    END
  END;

  EXTERNAL_register_sensors =
  SELECT init = TRUE THEN
    VAR res1, res2, res3 IN
      res1 := RpcSuccess~(ZMQ_RPC_SEND(socket, "register_log", {
        ("url" |-> RpcString(DRONE_URL)),
        ("name" |-> RpcString("Telemetry")),
        ("variables" |-> RpcArray([
          RpcString("stateEstimate.x"),
          RpcString("stateEstimate.y"),
          RpcString("stateEstimate.z"),
          RpcString("stateEstimate.roll"),
          RpcString("stateEstimate.pitch"),
          RpcString("stateEstimate.yaw")
        ]))}));
        res2 := RpcSuccess~(ZMQ_RPC_SEND(socket, "register_log", {
        ("url" |-> RpcString(DRONE_URL)),
        ("name" |-> RpcString("Power")),
        ("variables" |-> RpcArray([
          RpcString("pm.batteryLevel")
        ]))}));
        res3 := RpcSuccess~(ZMQ_RPC_SEND(socket, "register_log", {
        ("url" |-> RpcString(DRONE_URL)),
        ("name" |-> RpcString("Ranging")),
        ("variables" |-> RpcArray([
          RpcString("range.front"),
          RpcString("range.back"),
          RpcString("range.up"),
          RpcString("range.left"),
          RpcString("range.right"),
          RpcString("range.zrange")
        ]))}))
    END
  END;

  EXTERNAL_Drone_Takeoff =
  SELECT init = TRUE THEN
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "takeoff", {("url" |-> RpcString(DRONE_URL))}))
    END
  END;

  EXTERNAL_Drone_Land =
  SELECT init = TRUE THEN
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "land", {("url" |-> RpcString(DRONE_URL))}))
    END
  END;

  EXTERNAL_Drone_Left(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "left", {("url" |-> RpcString(DRONE_URL)), ("distance" |-> RpcFloat(RDIV(real(dist), real(1000))))}))
    END
  END;

  EXTERNAL_Drone_Right(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "right", {("url" |-> RpcString(DRONE_URL)), ("distance" |-> RpcFloat(RDIV(real(dist), real(1000))))}))
    END
  END;

  EXTERNAL_Drone_Up(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "up", {("url" |-> RpcString(DRONE_URL)), ("distance" |-> RpcFloat(RDIV(real(dist), real(1000))))}))
    END
  END;

  EXTERNAL_Drone_Down(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "down", {("url" |-> RpcString(DRONE_URL)), ("distance" |-> RpcFloat(RDIV(real(dist), real(1000))))}))
    END
  END;

  EXTERNAL_Drone_Forward(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "forward", {("url" |-> RpcString(DRONE_URL)), ("distance" |-> RpcFloat(RDIV(real(dist), real(1000))))}))
    END
  END;

  EXTERNAL_Drone_Backward(dist) =
  SELECT
    init = TRUE &
    dist : 0..2000
  THEN
    VAR res IN
      res := RpcSuccess~(ZMQ_RPC_SEND(socket, "backward", {("url" |-> RpcString(DRONE_URL)), ("distance" |-> RpcFloat(RDIV(real(dist), real(1000))))}))
    END
  END;

  out <-- EXTERNAL_Drone_GetX =
  SELECT init = TRUE THEN
    out := floor(RMUL(1000.0, RpcFloat~(RpcSuccess~(ZMQ_RPC_SEND(socket, "get_log_var", {("url" |-> RpcString(DRONE_URL)), ("name" |-> RpcString("stateEstimate.x"))})))));
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetY =
  SELECT init = TRUE THEN
    out := floor(RMUL(1000.0, RpcFloat~(RpcSuccess~(ZMQ_RPC_SEND(socket, "get_log_var", {("url" |-> RpcString(DRONE_URL)), ("name" |-> RpcString("stateEstimate.y"))})))));
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetZ =
  SELECT init = TRUE THEN
    out := floor(RMUL(1000.0, RpcFloat~(RpcSuccess~(ZMQ_RPC_SEND(socket, "get_log_var", {("url" |-> RpcString(DRONE_URL)), ("name" |-> RpcString("stateEstimate.z"))})))));
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetBattery =
  SELECT init = TRUE THEN
    out := RpcInteger~(RpcSuccess~(ZMQ_RPC_SEND(socket, "get_log_var", {("url" |-> RpcString(DRONE_URL)), ("name" |-> RpcString("pm.batteryLevel"))})));
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetFrontDistance =
  SELECT init = TRUE THEN
    out := RpcInteger~(RpcSuccess~(ZMQ_RPC_SEND(socket, "get_log_var", {("url" |-> RpcString(DRONE_URL)), ("name" |-> RpcString("range.front"))})));
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetBackDistance =
  SELECT init = TRUE THEN
    out := RpcInteger~(RpcSuccess~(ZMQ_RPC_SEND(socket, "get_log_var", {("url" |-> RpcString(DRONE_URL)), ("name" |-> RpcString("range.back"))})));
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetUpDistance =
  SELECT init = TRUE THEN
    out := RpcInteger~(RpcSuccess~(ZMQ_RPC_SEND(socket, "get_log_var", {("url" |-> RpcString(DRONE_URL)), ("name" |-> RpcString("range.up"))})));
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetDownDistance =
  SELECT init = TRUE THEN
    out := RpcInteger~(RpcSuccess~(ZMQ_RPC_SEND(socket, "get_log_var", {("url" |-> RpcString(DRONE_URL)), ("name" |-> RpcString("range.zrange"))})));
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetLeftDistance =
  SELECT init = TRUE THEN
    out := RpcInteger~(RpcSuccess~(ZMQ_RPC_SEND(socket, "get_log_var", {("url" |-> RpcString(DRONE_URL)), ("name" |-> RpcString("range.left"))})));
    cycle := cycle + 1
  END;

  out <-- EXTERNAL_Drone_GetRightDistance =
  SELECT init = TRUE THEN
    out := RpcInteger~(RpcSuccess~(ZMQ_RPC_SEND(socket, "get_log_var", {("url" |-> RpcString(DRONE_URL)), ("name" |-> RpcString("range.right"))})));
    cycle := cycle + 1
  END;

  EXTERNAL_Destroy =
  SELECT init = TRUE THEN
    ZMQ_RPC_DESTROY(socket);
    init := FALSE
  END
END
