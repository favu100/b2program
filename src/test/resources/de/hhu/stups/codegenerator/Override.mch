MACHINE Override

VARIABLES  f, s, r

INVARIANT  f : INT --> INT & s : INT --> INT & r : INT --> INT

INITIALISATION f := {0|->0, 1|->1, 2|->2}; s := {1|->3}; r:= {}

OPERATIONS

	calculate = BEGIN r := r <+ s END;
	out <-- getRes = out := r(1)

END