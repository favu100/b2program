.SUFFIXES:

.PHONY: all clean

all: CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes.jar

%.class : %.java
	javac -cp .$(DEPENDENCIES) $<

% : %.class
	gtime -f "%C %E %M" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@

clean:
	rm *.class
