MACHINE DroneSafetyController

SETS 
  MODE = {LANDING, LANDED, FLYING, TAKE_OFF};
  SENSOR_DIRECTION = {UP_SENSOR, DOWN_SENSOR, LEFT_SENSOR, RIGHT_SENSOR, FORWARD_SENSOR, BACKWARD_SENSOR}

CONSTANTS
 DEPTH, 
 WIDTH,
 HEIGHT, 
 DRONE_DEPTH,
 DRONE_WIDTH,
 DRONE_HEIGHT,
 SENSOR_DISTANCE

PROPERTIES
  DEPTH : NATURAL1 &
  WIDTH : NATURAL1 &
  HEIGHT : NATURAL1 &
  DRONE_DEPTH : NATURAL1 &
  DRONE_WIDTH : NATURAL1 &
  DRONE_HEIGHT : NATURAL1 &
  DRONE_DEPTH < DEPTH &
  DRONE_WIDTH < WIDTH &
  DRONE_HEIGHT < HEIGHT &
  SENSOR_DISTANCE : NATURAL &
  SENSOR_DISTANCE = 100000 &
  DEPTH = 6000 &
  WIDTH = 3000 &
  HEIGHT = 2000 &
  DRONE_DEPTH = 116 &
  DRONE_WIDTH = 116 &
  DRONE_HEIGHT = 30


VARIABLES
  x,
  y,
  z,
  mode,
  sensor_data,
  updated

INVARIANT
  x : DRONE_WIDTH/2..WIDTH − DRONE_WIDTH/2 − 1 &
  y : DRONE_DEPTH/2..DEPTH − DRONE_DEPTH/2 − 1 &
  z : DRONE_HEIGHT/2..HEIGHT − DRONE_HEIGHT/2 − 1 &
  mode : MODE &
  sensor_data : SENSOR_DIRECTION --> 0..SENSOR_DISTANCE &
  updated : BOOL 

INITIALISATION
  mode := LANDED ||
  x :: DRONE_WIDTH/2..WIDTH − DRONE_WIDTH/2 − 1 ||
  y :: DRONE_DEPTH/2..DEPTH − DRONE_DEPTH/2 − 1 ||
  z :: DRONE_HEIGHT/2..HEIGHT − DRONE_HEIGHT/2 − 1 ||
  sensor_data := SENSOR_DIRECTION * {SENSOR_DISTANCE} ||
  updated := FALSE


OPERATIONS
  take_off =
    SELECT
      mode : {LANDED, LANDING}
    THEN
      mode := TAKE_OFF
    END;

  landing = 
    SELECT
      mode = FLYING
    THEN
      mode := LANDING
    END;

  flying =
    SELECT
      mode = TAKE_OFF
    THEN
      mode := FLYING
    END;

  landed = 
    SELECT
      mode = LANDING
    THEN
      mode := LANDED
    END;


  DOWN(dist) =
    SELECT
      mode : {LANDING, FLYING} &
      z − dist >= DRONE_HEIGHT/2 &
      dist > 0 &
      dist < sensor_data(DOWN_SENSOR) &
      updated = TRUE
    THEN
      z := z − dist ||
      updated := FALSE
    END;

  UP(dist) =
    SELECT
      mode : {TAKE_OFF, FLYING} &
      z + dist <= HEIGHT − DRONE_HEIGHT/2 − 1 &
      dist > 0 &
      dist < sensor_data(UP_SENSOR) &
      updated = TRUE
    THEN
      z := z + dist ||
      updated := FALSE
    END;

  LEFT(dist) =
    SELECT
      mode = FLYING &
      x − dist >= DRONE_WIDTH/2 &
      dist > 0 &
      dist < sensor_data(LEFT_SENSOR) &
      updated = TRUE
    THEN
      x := x − dist ||
      updated := FALSE
    END;

  RIGHT(dist) =
    SELECT
      mode = FLYING &
      x + dist <= WIDTH − DRONE_WIDTH/2−1 &
      dist > 0 &
      dist < sensor_data(RIGHT_SENSOR) &
      updated = TRUE
    THEN
      x := x + dist ||
      updated := FALSE
  END;

  BACKWARD(dist) = 
    SELECT
      mode = FLYING &
      y − dist >= DRONE_DEPTH/2 &
      dist > 0 &
      dist < sensor_data(BACKWARD_SENSOR) &
      updated = TRUE
    THEN
      y := y − dist ||
      updated := FALSE
  END;

  FORWARD(dist) =
    SELECT
      mode = FLYING &
      y + dist <= DEPTH − DRONE_DEPTH/2−1 &
      dist > 0 &
      dist < sensor_data(FORWARD_SENSOR) &
      updated = TRUE
    THEN
      y := y + dist ||
      updated := FALSE
  END;

  observe(data) =
    SELECT
      data : SENSOR_DIRECTION → 0..SENSOR_DISTANCE
    THEN
      sensor_data := data ||
      updated := TRUE
    END;

  setCoordinates(newX, newY, newZ) =
  SELECT
    newX : INTEGER &
    newY : INTEGER &
    newZ : INTEGER
  THEN
    x := newX ||
    y := newY ||
    z := newZ
  END
END
