.SUFFIXES:

.PHONY: build all clean

all: build CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec sort_m2_data1000_exec

build:
	cp ../../btypes_primitives/src/main/cpp/*.cpp ./ & cp ../../btypes_primitives/src/main/cpp/*.h ./

OUTPUT ?= runtimes.txt

CPPC ?= clang++
IMMERFLAGS=-DIMMER_NO_THREAD_SAFETY
CPPFLAGS ?= -std=c++14 -O2 -flto -march=native $(IMMERFLAGS)

%.exec : %.cpp
	$(CPPC) $(CPPFLAGS) -o $@ $< BString.cpp BStruct.cpp BInteger.cpp BBoolean.cpp

% : %.exec
	gtime -f "%C %E %M" -ao $(OUTPUT) ./$<

clean:
	rm -f *.exec & rm BBoolean.cpp & rm BInteger.cpp & rm BString.cpp & rm BStruct.cpp & rm BBoolean.h & rm BInteger.h & rm BObject.h & rm BRelation.h & rm BSet.h & rm BString.h & rm BStruct.h & rm BTuple.h & rm BUtils.h
