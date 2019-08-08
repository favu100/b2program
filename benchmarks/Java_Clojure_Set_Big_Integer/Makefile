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
	cd ../../btypes_big_integer ; ./gradlew fatJar ; cp build/libs/btypes_big_integer-all.jar ../benchmarks/Java_Clojure_Set_Big_Integer/btypes.jar ; cd ../benchmarks/Java_Clojure_Big_Integer