/*
From ProB Examples, originally used to test ProB,
rewritten for B2Program
*/
MACHINE NatRangeLaws
VARIABLES xx,zz
INVARIANT
  xx:(0..4) & zz:(-3..4) &
  xx: xx..xx+1 &
  xx: xx..xx &
  xx: xx-1..xx &
  (xx<zz <=>  xx:0..zz-1) &
  (xx<=zz <=>  xx:0..zz) &
  card(xx..xx) = 1 & card(xx..xx-1) = 0 &
  card(xx..xx+1) = 2 &
  (xx>zz <=> card(xx..zz) = 0) &
  (xx<=zz => card(xx..zz) = zz-xx+1) &
  (xx<1 => {} : 1..xx --> INTEGER) &
  {} : 1..0 --> INTEGER &
  xx..zz = {nn | nn:(-3..4) & nn>=xx & nn<=zz}&
  (1..4) = (1..4) &
  (0..4) = (0..4) &
  (-3..4) = (-3..4) &
  (0..4) - (1..4) = {0} &
  (1..4) - (0..4) = {} &
  (0..4) \/ (1..4) = (0..4) &
  (1..4) <<: (0..4) & (0..4) <<: (-3..4) &
  (xx>=zz =>  (zz..4) = (zz..xx) \/ (xx+1)..4) &
  card(0..xx) = xx+1 &
  card((1..4)) = 4 &
  min(-1..xx) = -1 & max(-1..xx) = xx &
  (xx..zz = {}  <=>  zz < xx) &
  (xx..zz /= {}  <=>  zz >= xx) &
  (#v.(v:xx..zz)  <=>  zz >= xx) &
  !v.(v:xx..zz => v>=xx & v <= zz) &

  xx..(xx-1) <: xx..zz &
  xx..zz <: xx..zz &
  xx..zz <: xx..(zz+1) &
  (xx+1)..zz <: xx..zz &
  xx..(zz-1) <: xx..zz &
  (xx+1)..(zz-1) <: xx..zz &
  (xx<=zz => (  xx..zz <: xx..(zz+1) &
               (xx+1)..zz <<: xx..zz &
                xx..(zz-1) <<: xx..zz &
               (xx+1)..(zz-1) <<: xx..zz)) &

  ( xx..zz <: zz..xx <=> zz<=xx) &
  ( xx..zz <<: zz..xx <=> zz<xx)// &

  //perm((1..4)) = perm((1..4)) &
  //%i.(i:(1..4)|i) : perm((1..4))

INITIALISATION xx:=0 || zz:=0
OPERATIONS
 Setxx(yy) = PRE yy:(0..4) THEN xx:= yy END;
 Setzz(yy) = PRE yy:(1..4) THEN zz:= yy END;
 r <-- Cardxxzz = r := card(xx..zz)
END