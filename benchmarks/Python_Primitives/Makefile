.SUFFIXES:

.PHONY: all

all: CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec sort_m2_data1000_exec

BTYPESPYTHON=../../btypes_primitives/src/main/python_magicstack_immutable
OUTPUT ?= runtimes.txt

% : export PYTHONPATH = $(BTYPESPYTHON)
% :
	timeout 20m /usr/bin/time -f "%C %E %M" -ao $(OUTPUT) pypy3 $@.py
