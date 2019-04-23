.SUFFIXES:

.PHONY: all clean

all: CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec

OUTPUT ?= runtimes.txt

CPPC ?= clang++
IMMERFLAGS=-DIMMER_NO_THREAD_SAFETY
CPPFLAGS ?= -std=c++14 -O1 -march=native $(IMMERFLAGS)

%.exec : %.cpp
	$(CPPC) $(CPPFLAGS) -o $@ $<

% : %.exec
	gtime -f "%C %E" -ao $(OUTPUT) ./$<

clean:
	rm -f *.exec
