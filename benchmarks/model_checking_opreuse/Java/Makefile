#.SUFFIXES:

.PHONY: build all clean

all: Lift_MC_Large Cruise_finite1_deterministic_MC CAN_BUS_tlc LandingGear_R6 nota_v2 rether obsw_M001_1 obsw_M001_2 prob_oneway8seq Train_1_beebook_deterministic_MC_POR_v2 sort_m2_data1000_MC QueensWithEvents_4

build:
	cd ../../../btypes_primitives ; ./gradlew -q fatJar ; cp build/libs/btypes_primitives-all.jar ../benchmarks/model_checking/Java/btypes.jar ; cd ../benchmarks/model_checking/Java

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes.jar
STRATEGY=mixed
THREADS=8
CACHING=false

%.class : %.java
	javac -cp .$(DEPENDENCIES) $<

% : %.class
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@ $(STRATEGY) $(THREADS) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@ $(STRATEGY) $(THREADS) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@ $(STRATEGY) $(THREADS) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@ $(STRATEGY) $(THREADS) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@ $(STRATEGY) $(THREADS) $(CACHING)

clean:
	rm *.class & rm *.jar
