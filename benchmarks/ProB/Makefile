.SUFFIXES:

.PHONY: all clean

all: Counter10000 CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec

PROBCLI=./probcli.sh
OUTPUT ?= runtimes.txt

% :
	gtime -f "%C %E" -ao $(OUTPUT) $(PROBCLI) $@.mch -init -execute 1

clean:
	rm *.prob
