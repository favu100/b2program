.SUFFIXES:

.PHONY: build all clean

all: CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 Train1_Lukas_POR_v3 Train_1_beebook_deterministic_MC_POR_v2 QueensWithEvents sort_m2_data1000_MC

build:
	cd ../../../btypes_primitives ; ./gradlew -q fatJar ; cp build/libs/btypes_primitives-all.jar ../benchmarks/model_checking/Java/btypes.jar ; cd ../benchmarks/model_checking/Java

CPPC ?= clang++
CPPFLAGS ?= -std=c++14 -O2 -flto
STRATEGY=mixed
THREADS=6
CACHING=false
OUTPUT=runtimes.txt

%.exec : %.cpp
	$(CPPC) $(CPPFLAGS) -o $@ $<

% : %.exec
	gtime -f "%C %E %M" -ao $(OUTPUT) ./$< $(STRATEGY) $(THREADS) $(CACHING)

clean:
	rm -f *.exec
