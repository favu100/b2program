MACHINE HighwayEnvironment2

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
    Critical_DistanceX,
    Critical_DistanceY,
    VehiclesX,
    VehiclesY,
    VehiclesVx,
    VehiclesVy,
    VehiclesAx,
    VehiclesAy,
    Reward

INVARIANT
    Crash : BOOL &
    Critical_DistanceX : BOOL &
    Critical_DistanceY : BOOL &
    VehiclesX : Vehicles --> REAL &
    VehiclesY : Vehicles --> REAL &
    VehiclesVx : Vehicles --> REAL &
    VehiclesVy : Vehicles --> REAL &
    VehiclesAx : Vehicles --> REAL &
    VehiclesAy : Vehicles --> REAL &
    Reward : REAL

INITIALISATION
  Crash := FALSE ||
  Critical_DistanceX := FALSE || 
  Critical_DistanceY := FALSE ||  
  VehiclesX : (VehiclesX : Vehicles --> REAL) ||
  VehiclesY : (VehiclesY : Vehicles --> REAL) ||
  VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
  VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
  VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
  Reward : (Reward : REAL)

OPERATIONS
  IDLE =
  SELECT
    not(#v. (v : Vehicles \ {EgoVehicle} & VehiclesX(v) > 0.0 & VehiclesX(v) < 30.0  & VehiclesY(v) < 7.5 & VehiclesY(v) > -7.5))
  THEN
      Crash :: BOOL ||
      Critical_DistanceX :: BOOL ||
      Critical_DistanceY :: BOOL ||
      VehiclesX : (VehiclesX : Vehicles --> REAL) ||
      VehiclesY : (VehiclesY : Vehicles --> REAL) ||
      VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
      VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
      VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
      VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
      Reward : (Reward : REAL)
  END;

  LANE_LEFT =
  SELECT
    VehiclesY(EgoVehicle) > 1.0 &
    not(#v. (v : Vehicles \ {EgoVehicle} & VehiclesX(v) > -6.0 & VehiclesX(v) < 30.0  & VehiclesY(v) > -9.0 & VehiclesY(v) < -2.0))
  THEN
      Crash :: BOOL ||
      Critical_DistanceX :: BOOL ||
      Critical_DistanceY :: BOOL ||
      VehiclesX : (VehiclesX : Vehicles --> REAL) ||
      VehiclesY : (VehiclesY : Vehicles --> REAL) ||
      VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
      VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
      VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
      VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
      Reward : (Reward : REAL)
  END;

  LANE_RIGHT =
  SELECT
    VehiclesY(EgoVehicle) < 15.0 &
    not(#v. (v : Vehicles \ {EgoVehicle} & VehiclesX(v) > -6.0 & VehiclesX(v) < 30.0  & VehiclesY(v) < 9.0 & VehiclesY(v) > 2.0))
  THEN
      Crash :: BOOL ||
      Critical_DistanceX :: BOOL ||
      Critical_DistanceY :: BOOL ||
      VehiclesX : (VehiclesX : Vehicles --> REAL) ||
      VehiclesY : (VehiclesY : Vehicles --> REAL) ||
      VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
      VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
      VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
      VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
      Reward : (Reward : REAL)
  END;

  FASTER =
  SELECT
    not(#v. (v : Vehicles \ {EgoVehicle} & VehiclesX(v) > 0.0 & VehiclesX(v) < 30.0  & VehiclesY(v) < 7.5 & VehiclesY(v) > -7.5))
  THEN
      Crash :: BOOL ||
      Critical_DistanceX :: BOOL ||
      Critical_DistanceY :: BOOL ||
      VehiclesX : (VehiclesX : Vehicles --> REAL) ||
      VehiclesY : (VehiclesY : Vehicles --> REAL) ||
      VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
      VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
      VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
      VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
      Reward : (Reward : REAL)
  END;

  SLOWER =
  BEGIN
      Crash :: BOOL ||
      Critical_DistanceX :: BOOL ||
      Critical_DistanceY :: BOOL ||
      VehiclesX : (VehiclesX : Vehicles --> REAL) ||
      VehiclesY : (VehiclesY : Vehicles --> REAL) ||
      VehiclesVx : (VehiclesVx : Vehicles --> REAL) ||
      VehiclesVy : (VehiclesVy : Vehicles --> REAL) ||
      VehiclesAx : (VehiclesVy : Vehicles --> REAL) ||
      VehiclesAy : (VehiclesVy : Vehicles --> REAL) ||
      Reward : (Reward : REAL)
  END

END