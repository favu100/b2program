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
    PresentVehicles,
    VehiclesX,
    VehiclesY,
    VehiclesVx,
    VehiclesVy,
    VehiclesAx,
    VehiclesAy,
    Reward

INVARIANT
    Crash : BOOL &
    PresentVehicles : POW(Vehicles) &
    VehiclesX : Vehicles --> REAL &
    VehiclesY : Vehicles --> REAL &
    VehiclesVx : Vehicles --> REAL &
    VehiclesVy : Vehicles --> REAL &
    VehiclesAx : Vehicles --> REAL &
    VehiclesAy : Vehicles --> REAL &
    Reward : REAL

INITIALISATION
    Crash :: BOOL ||
    PresentVehicles :: POW(Vehicles) ||
    VehiclesX :: Vehicles --> REAL ||
    VehiclesY :: Vehicles --> REAL ||
    VehiclesVx :: Vehicles --> REAL ||
    VehiclesVy :: Vehicles --> REAL ||
    VehiclesAx :: Vehicles --> REAL ||
    VehiclesAy :: Vehicles --> REAL ||
    Reward :: REAL

OPERATIONS
  IDLE =
  SELECT
    not(#v. (v : PresentVehicles \ {EgoVehicle} & VehiclesX(v) > 0.0 & VehiclesX(v) < 35.0  & VehiclesY(v) < 3.5 & VehiclesY(v) > -3.5 & VehiclesVx(v) < 0.0))
  THEN
    Crash :: BOOL ||
    PresentVehicles :: POW(Vehicles) ||
    VehiclesX :: Vehicles --> REAL ||
    VehiclesY :: Vehicles --> REAL ||
    VehiclesVx :: Vehicles --> REAL ||
    VehiclesVy :: Vehicles --> REAL ||
    VehiclesAx :: Vehicles --> REAL ||
    VehiclesAy :: Vehicles --> REAL ||
    Reward :: REAL
  END;

  LANE_LEFT =
  SELECT
    VehiclesY(EgoVehicle) > 1.0 &
    not(#v. (v : PresentVehicles \ {EgoVehicle} & VehiclesX(v) > -25.0 & VehiclesX(v) <= -15.0  & VehiclesY(v) > -6.0 & VehiclesY(v) < -2.0 & VehiclesVx(v) > 0.0)) &
    not(#v. (v : PresentVehicles \ {EgoVehicle} & VehiclesX(v) > -15.0 & VehiclesX(v) <= 15.0  & VehiclesY(v) > -6.0 & VehiclesY(v) < -2.0)) &
    not(#v. (v : PresentVehicles \ {EgoVehicle} & VehiclesX(v) > 15.0 & VehiclesX(v) <= 35.0  & VehiclesY(v) > -6.0 & VehiclesY(v) < -2.0 & VehiclesVx(v) < 0.0))
  THEN
    Crash :: BOOL ||
    PresentVehicles :: POW(Vehicles) ||
    VehiclesX :: Vehicles --> REAL ||
    VehiclesY :: Vehicles --> REAL ||
    VehiclesVx :: Vehicles --> REAL ||
    VehiclesVy :: Vehicles --> REAL ||
    VehiclesAx :: Vehicles --> REAL ||
    VehiclesAy :: Vehicles --> REAL ||
    Reward :: REAL
  END;

  LANE_RIGHT =
  SELECT
    VehiclesY(EgoVehicle) < 7.0 &
    not(#v. (v : PresentVehicles \ {EgoVehicle} & VehiclesX(v) > -25.0 & VehiclesX(v) <= -15.0  & VehiclesY(v) < 6.0 & VehiclesY(v) > 2.0 & VehiclesVx(v) > 0.0)) &
    not(#v. (v : PresentVehicles \ {EgoVehicle} & VehiclesX(v) > -15.0 & VehiclesX(v) < 15.0  & VehiclesY(v) < 6.0 & VehiclesY(v) > 2.0)) &
    not(#v. (v : PresentVehicles \ {EgoVehicle} & VehiclesX(v) > 15.0 & VehiclesX(v) <= 35.0  & VehiclesY(v) < 6.0 & VehiclesY(v) > 2.0 & VehiclesVx(v) < 0.0))
  THEN
    Crash :: BOOL ||
    PresentVehicles :: POW(Vehicles) ||
    VehiclesX :: Vehicles --> REAL ||
    VehiclesY :: Vehicles --> REAL ||
    VehiclesVx :: Vehicles --> REAL ||
    VehiclesVy :: Vehicles --> REAL ||
    VehiclesAx :: Vehicles --> REAL ||
    VehiclesAy :: Vehicles --> REAL ||
    Reward :: REAL
  END;

  FASTER =
  SELECT
    not(#v. (v : PresentVehicles \ {EgoVehicle} & VehiclesX(v) > 0.0 & VehiclesX(v) < 45.0  & VehiclesY(v) < 3.5 & VehiclesY(v) > -3.5))
  THEN
    Crash :: BOOL ||
    PresentVehicles :: POW(Vehicles) ||
    VehiclesX :: Vehicles --> REAL ||
    VehiclesY :: Vehicles --> REAL ||
    VehiclesVx :: Vehicles --> REAL ||
    VehiclesVy :: Vehicles --> REAL ||
    VehiclesAx :: Vehicles --> REAL ||
    VehiclesAy :: Vehicles --> REAL ||
    Reward :: REAL
  END;

  SLOWER =
  BEGIN
    Crash :: BOOL ||
    PresentVehicles :: POW(Vehicles) ||
    VehiclesX :: Vehicles --> REAL ||
    VehiclesY :: Vehicles --> REAL ||
    VehiclesVx :: Vehicles --> REAL ||
    VehiclesVy :: Vehicles --> REAL ||
    VehiclesAx :: Vehicles --> REAL ||
    VehiclesAy :: Vehicles --> REAL ||
    Reward :: REAL
  END

END