#.SUFFIXES:

.PHONY: build all clean

all: Lift_MC_Large CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 Train1_Lukas_POR_v3 Train_1_beebook_deterministic_MC_POR_v2 sort_m2_data1000_MC QueensWithEvents_4 QueensWithEvents_8 nota_v2

build:
	cd ../../../btypes_primitives ; ./gradlew -q fatJar ; cp build/libs/btypes_primitives-all.jar ../benchmarks/model_checking/Java/btypes.jar ; cd ../benchmarks/model_checking/Java

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes.jar
STRATEGY=mixed
THREADS=6
CACHING=true

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
