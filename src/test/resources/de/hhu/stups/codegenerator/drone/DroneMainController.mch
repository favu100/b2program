MACHINE DroneMainController
INCLUDES DroneSafetyController, DroneCommunicator_Mockup

OPERATIONS

Controller_Init = BEGIN EXTERNAL_Init END;

Controller_open_link = BEGIN EXTERNAL_open_link END;

Controller_register_sensors = BEGIN EXTERNAL_register_sensors END;

Controller_Takeoff =
  BEGIN
    take_off;
    EXTERNAL_Drone_Takeoff;
    flying
  END;

  Controller_Landing =
  BEGIN
    landing;
    EXTERNAL_Drone_Land;
    landed
  END;

  Controller_DOWN(dist) =
  SELECT
	dist: INTEGER
  THEN
    DOWN(dist);
    EXTERNAL_Drone_Down(dist)
  END;

Controller_UP(dist) =
  SELECT
	dist: INTEGER
  THEN
    UP(dist);
    EXTERNAL_Drone_Up(dist)
  END;

Controller_LEFT(dist) =
  SELECT
	dist: INTEGER
  THEN
    LEFT(dist);
    EXTERNAL_Drone_Left(dist)
  END;

Controller_RIGHT(dist) =
  SELECT
	dist: INTEGER
  THEN
    RIGHT(dist);
    EXTERNAL_Drone_Right(dist)
  END;

Controller_BACKWARD(dist) =
  SELECT
	dist: INTEGER
  THEN
    BACKWARD(dist);
    EXTERNAL_Drone_Backward(dist)
  END;

Controller_FORWARD(dist) =
  SELECT
	dist: INTEGER
  THEN
    FORWARD(dist);
    EXTERNAL_Drone_Forward(dist)
  END;

Controller_OBSERVE =
  VAR dist_forward, dist_backward, dist_up, dist_down, dist_left, dist_right
  IN
	dist_forward <-- EXTERNAL_Drone_GetFrontDistance;
	dist_backward <-- EXTERNAL_Drone_GetBackDistance;
	dist_up <-- EXTERNAL_Drone_GetUpDistance;
	dist_down <-- EXTERNAL_Drone_GetDownDistance;
	dist_left <-- EXTERNAL_Drone_GetLeftDistance;
	dist_right <-- EXTERNAL_Drone_GetRightDistance;
	observe({UP_SENSOR |-> dist_up, DOWN_SENSOR |-> dist_down, LEFT_SENSOR |-> dist_left, RIGHT_SENSOR |-> dist_right, FORWARD_SENSOR |-> dist_forward, BACKWARD_SENSOR |-> dist_backward})
  END;

Controller_SYNC_POS =
  VAR x, y, z
  IN
	x <-- EXTERNAL_Drone_GetX;
	y <-- EXTERNAL_Drone_GetY;
	z <-- EXTERNAL_Drone_GetZ;
	setCoordinates(x, y, z)
  END;

Controller_CLOSE_LINK =
  BEGIN
    EXTERNAL_close_link
  END

END