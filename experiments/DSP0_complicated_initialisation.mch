MACHINE DSP0_complicated_initialisation 
SETS
	CELL = {cell1,cell2};
	CHANNEL = {ch1,ch2}

VARIABLES
	cellChannels
INVARIANT
	cellChannels : CELL --> POW(CHANNEL)
	
INITIALISATION
	cellChannels : (cellChannels:CELL --> POW(CHANNEL) &
	    !(a1,a2).( (a1:dom(cellChannels) & a2:dom(cellChannels) & a1/=a2) =>  cellChannels(a1)/\cellChannels(a2)={} ) 
	  & union(ran(cellChannels)) = CHANNEL)
	  
	  
OPERATIONS
 unran = PRE union(ran(cellChannels)) = CHANNEL THEN skip END
 
 END