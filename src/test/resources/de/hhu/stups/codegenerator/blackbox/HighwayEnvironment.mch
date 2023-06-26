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
    VehiclesVy

INVARIANT
    Crash : BOOL &
    VehiclesX : Vehicles --> REAL &
    VehiclesY : Vehicles --> REAL &
    VehiclesVx : Vehicles --> REAL &
    VehiclesVy : Vehicles --> REAL

INITIALISATION
  Crash := FALSE ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL)

OPERATIONS
  IDLE = BEGIN
  Crash :: BOOL ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL)
  END;

  LANE_LEFT = BEGIN
  Crash :: BOOL ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL)
  END;

  LANE_RIGHT = BEGIN
  Crash :: BOOL ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL)
  END;

  FASTER = BEGIN
  Crash :: BOOL ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL)
  END;

  SLOWER = BEGIN
  Crash :: BOOL ||
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL)
  END

END