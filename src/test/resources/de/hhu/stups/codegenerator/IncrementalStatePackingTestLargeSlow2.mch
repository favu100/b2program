MACHINE IncrementalStatePackingTestLargeSlow2
SETS
 ID={aa,bb,cc}
VARIABLES xx,yy,ii
INVARIANT
 xx:ID & yy:ID & ii >= 1 & ii <= 1000
INITIALISATION xx:=aa || yy := bb || ii := 1
OPERATIONS
  SetX(vv) = PRE vv:ID & vv /= xx
                & !x.(x:1..300 => !y.(y:1..x => (y /= 2001) & ((y >= 1 & y <= 1000) or (y >= 2000 & y <= 3000)))) // always true
             THEN xx:= vv END;
  SetY(vv) = PRE vv:ID & vv /= yy
                & !x.(x:1..300 => !y.(y:1..x => (y /= 2001) & ((y >= 1 & y <= 1000) or (y >= 2000 & y <= 3000)))) // always true
             THEN yy:= vv END;
  IncrI = PRE ii<1000 THEN ii:=ii+1 END
END

/*
time probcli IncrementalStatePackingTestLarge.mch -model-check -p COMPRESSION FALSE -memory -p OPERATION_REUSE FALSE -lint -cs -get_min_max_coverage user_output
*/
