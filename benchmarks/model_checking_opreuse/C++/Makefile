.SUFFIXES:

.PHONY: build all clean

all: Lift_MC_Large Cruise_finite1_deterministic_MC  CAN_BUS_tlc LandingGear_R6 nota_v2 rether obsw_M001_1 obsw_M001_2 prob_oneway8seq Train_1_beebook_deterministic_MC_POR_v3 sort_m2_data1000_MC QueensWithEvents_4

build:
	cd ../../../btypes_primitives ; ./gradlew -q fatJar ; cp build/libs/btypes_primitives-all.jar ../benchmarks/model_checking/Java/btypes.jar ; cd ../benchmarks/model_checking/Java

CPPC ?= clang++
IMMERFLAGS=-DIMMER_NO_THREAD_SAFETY
CPPFLAGS ?= -std=c++14 -O1 -flto -mtune=native -fbracket-depth=1000
STRATEGY=mixed
THREADS=6
CACHING=true
OUTPUT=runtimes.txt

%.exec : %.cpp
	$(CPPC) $(CPPFLAGS) -o $@ $<

% : %.exec
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) ./$< $(STRATEGY) $(THREADS) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) ./$< $(STRATEGY) $(THREADS) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) ./$< $(STRATEGY) $(THREADS) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) ./$< $(STRATEGY) $(THREADS) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) ./$< $(STRATEGY) $(THREADS) $(CACHING)

clean:
	rm -f *.exec
