.SUFFIXES:

.PHONY: all clean

all: CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec sort_m2_data1000_exec

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes.jar

%.class : %.java
	javac -cp .$(DEPENDENCIES) $<

% : %.class
	gtime -f "%C %E %M" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@

clean:
	rm *.class

build:
	cd ../../btypes_primitives ; ./gradlew fatJar ; cp build/libs/btypes_primitives-all.jar ../benchmarks/Java_Clojure_Set_Primitives/btypes.jar ; cd ../benchmarks/Java_Clojure_Set_Primitives