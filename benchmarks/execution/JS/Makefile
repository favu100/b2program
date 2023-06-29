.SUFFIXES:

.PHONY: all

all: CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec sort_m2_data1000_exec

OUTPUT ?= runtimes.txt
COMPILE_FLAGS=--target ES6 --moduleResolution node

%.js : %.ts
	tsc $(COMPILE_FLAGS) $<

% : %.js
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) node $@.js
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) node $@.js
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) node $@.js
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) node $@.js
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) node $@.js
