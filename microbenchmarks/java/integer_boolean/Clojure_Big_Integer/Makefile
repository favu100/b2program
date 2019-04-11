.SUFFIXES:

.PHONY: all clean

all: And Divide Equal Equivalent Greater GreaterEqual Implies Less LessEqual Minus Modulo Multiply Negative Or Plus LiftExec

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes.jar

%.class : %.java
	javac -cp .$(DEPENDENCIES) $<

% : %.class
	gtime -f "%C %E" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@

clean:
	rm *.class
