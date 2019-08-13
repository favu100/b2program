.SUFFIXES:

.PHONY: build compile link all clean

all: build compile link CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec sort_m2_data1000_exec

build:
	cp ../../btypes_primitives/src/main/cpp/*.cpp ./ & cp ../../btypes_primitives/src/main/cpp/*.hpp ./

compile:
	clang++ -std=c++14 -O2 -flto -march=native -DIMMER_NO_THREAD_SAFETY -c BInteger.cpp & clang++ -std=c++14 -O2 -flto -march=native -DIMMER_NO_THREAD_SAFETY -c BBoolean.cpp & clang++ -std=c++14 -O2 -flto -march=native -DIMMER_NO_THREAD_SAFETY -c BString.cpp & clang++ -std=c++14 -O2 -flto -march=native -DIMMER_NO_THREAD_SAFETY -c BStruct.cpp & clang++ -std=c++14 -O2 -flto -march=native -DIMMER_NO_THREAD_SAFETY -c BTuple.hpp & clang++ -std=c++14 -O2 -flto -march=native -DIMMER_NO_THREAD_SAFETY -c BSet.hpp & clang++ -std=c++14 -O2 -flto -march=native -DIMMER_NO_THREAD_SAFETY -c BRelation.hpp

link:
	ar rcs btypes.o BBoolean.o BInteger.o BSet.hpp.gch BString.o BStruct.o BTuple.hpp.gch BRelation.hpp.gch

OUTPUT ?= runtimes.txt

CPPC ?= clang++
IMMERFLAGS=-DIMMER_NO_THREAD_SAFETY
CPPFLAGS ?= -std=c++14 -O2 -flto -march=native $(IMMERFLAGS)

%.exec : %.cpp
	$(CPPC) btypes.o $(CPPFLAGS) -o $@ $<

% : %.exec
	gtime -f "%C %E %M" -ao $(OUTPUT) ./$<

clean:
	rm -f *.exec & rm BBoolean.cpp & rm BInteger.cpp & rm BString.cpp & rm BStruct.cpp & rm BBoolean.hpp & rm BInteger.hpp & rm BObject.hpp & rm BRelation.hpp & rm BSet.hpp & rm BString.hpp & rm BStruct.hpp & rm BTuple.hpp & rm BUtils.hpp & rm *.gch & rm *.o
