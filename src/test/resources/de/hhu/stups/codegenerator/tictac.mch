MACHINE tictac

ABSTRACT_VARIABLES  square, turn

INVARIANT  

	turn:(0..1)
&
	square:( (1..3) * (1..3) ) +-> (0..1) 

/* &
	not(	(1|->1)|->0 : square &
		(2|->2)|->0 : square &
		(3|->3)|->0 : square   )
This is equivalent
to the invariant below
*/
&
	(	(1|->1)|->0 /: square  or
		(2|->2)|->0 /: square  or
		(3|->3)|->0 /: square   )


INITIALISATION turn,square := 0,{}

OPERATIONS

  place0(xx,yy) =
	PRE 
		xx:(1..3) & yy:(1..3) &
		turn = 0 &
		xx|->yy /: dom(square)
	THEN 
		square(xx|->yy) := 0 ||
		turn := 1
	END ;

place1(xx,yy) =
	PRE
		xx:(1..3) & yy:(1..3) &
		turn = 1 &
		xx|->yy /: dom(square)
	THEN 
		square(xx|->yy) := 1  ||
		turn:=0
	END

/*
	
 place1 =
	ANY xx, yy WHERE
		turn = 1 &
		xx:(1..3) & yy:(1..3) &
		xx|->yy /: dom(square)
	THEN 
		square(xx|->yy) := 1  ||
		turn:=0
	END
*/

END


