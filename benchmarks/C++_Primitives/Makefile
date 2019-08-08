.SUFFIXES:

.PHONY: build all clean

all: build CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec sort_m2_data1000_exec

build:
	cp ../../btypes_primitives/src/main/cpp/*.cpp ./

OUTPUT ?= runtimes.txt

CPPC ?= clang++
IMMERFLAGS=-DIMMER_NO_THREAD_SAFETY
CPPFLAGS ?= -std=c++14 -O2 -march=native $(IMMERFLAGS)

%.exec : %.cpp
	$(CPPC) $(CPPFLAGS) -o $@ $<

% : %.exec
	gtime -f "%C %E %M" -ao $(OUTPUT) ./$<

clean:
	rm -f *.exec & rm BBoolean.cpp & rm BInteger.cpp & rm BObject.cpp & rm BRelation.cpp & rm BSet.cpp & rm BString.cpp & rm BStruct.cpp & rm BTuple.cpp & rm BUtils.cpp
