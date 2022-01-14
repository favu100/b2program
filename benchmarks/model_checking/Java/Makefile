.SUFFIXES:

.PHONY: build all clean

all: CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 QueensWithEvents sort_m2_data1000_MC Train1_Lukas_POR_v3 Train_1_beebook_deterministic_MC_POR_v2

build:
	cd ../../../btypes_primitives ; ./gradlew -q fatJar ; cp build/libs/btypes_primitives-all.jar ../benchmarks/model_checking/Java/btypes.jar ; cd ../benchmarks/model_checking/Java

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes.jar
STRATEGY=mixed
THREADS=2
CACHING=false

%.class : %.java
	javac -cp .$(DEPENDENCIES) $<

% : %.class
	gtime -f "%C %E %M" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@ $(STRATEGY) $(THREADS) $(CACHING)

clean:
	rm *.class & rm *.jar