.SUFFIXES:

.PHONY: all clean

all: Counter10000 CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve Train_1_beebook_deterministic_exec TrafficLightExec sort_m2_data1000_exec

PROBCLI=./probcli.sh
OUTPUT ?= runtimes.txt

% :
	timeout 60m /usr/bin/time -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -init -execute 1 -noass -noinv -nogoal -p COMPRESSION TRUE

clean:
	rm *.prob
