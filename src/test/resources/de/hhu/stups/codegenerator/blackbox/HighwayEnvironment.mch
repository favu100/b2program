MACHINE HighwayEnvironment

SETS
    Vehicles

CONSTANTS
    EgoVehicle
PROPERTIES
    card(Vehicles) > 1 &
    card(Vehicles) = 5 &
    EgoVehicle : Vehicles

VARIABLES
    Crash,
    VehiclesX,
    VehiclesY,
    VehiclesVx,
    VehiclesVy,
    VehiclesAx,
    VehiclesAy,
    Reward

INVARIANT
    Crash : BOOL &
    VehiclesX : Vehicles --> REAL &
    VehiclesY : Vehicles --> REAL &
    VehiclesVx : Vehicles --> REAL &
    VehiclesVy : Vehicles --> REAL &
    VehiclesAx : Vehicles --> REAL &
    VehiclesAy : Vehicles --> REAL &
    Reward : REAL

INITIALISATION
  Crash := FALSE ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
  Reward : (Reward : REAL)


OPERATIONS
  IDLE = BEGIN
  Crash :: BOOL ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
  Reward : (Reward : REAL)
  END;

  LANE_LEFT = BEGIN
  Crash :: BOOL ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
  Reward : (Reward : REAL)
  END;

  LANE_RIGHT = BEGIN
  Crash :: BOOL ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
  Reward : (Reward : REAL)
  END;

  FASTER = BEGIN
  Crash :: BOOL ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
  Reward : (Reward : REAL)
  END;

  SLOWER = BEGIN
  Crash :: BOOL ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
  Reward : (Reward : REAL)
  END

END