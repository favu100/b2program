/*
From ProB Examples
*/
MACHINE IncrementalStatePackingTestLargeSlow
SETS
 ID={aa,bb,cc}
VARIABLES xx,yy,zz,ii
INVARIANT
 xx:ID & yy:ID & zz <: NATURAL & ii : 1..1000
INITIALISATION xx:=aa || yy := bb || zz := (1..1000 \/ 2000..3000) \ {2001} || ii := 1
OPERATIONS
  SetX(vv) = PRE vv:ID & vv /= xx
                & !x.(x:1..300 => 1..x <: zz) // always true
             THEN xx:= vv END;
  SetY(vv) = PRE vv:ID & vv /= yy
                & !x.(x:1..300 => 1..x <: zz)
             THEN yy:= vv END;
  IncrI = PRE ii<1000 THEN ii:=ii+1 END
END

/*
time probcli IncrementalStatePackingTestLarge.mch -model-check -p COMPRESSION FALSE -memory -p OPERATION_REUSE FALSE -lint -cs -get_min_max_coverage user_output
*/
