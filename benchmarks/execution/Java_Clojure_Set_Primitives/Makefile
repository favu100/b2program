.SUFFIXES:

.PHONY: build all clean

all: build CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec sort_m2_data1000_exec

build:
	cd ../../../btypes_primitives ; ./gradlew -q fatJar ; cp build/libs/btypes_primitives-all.jar ../benchmarks/execution/Java_Clojure_Set_Primitives/btypes.jar ; cd ../benchmarks/execution/Java_Clojure_Set_Primitives

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes.jar

%.class : %.java
	javac -cp .$(DEPENDENCIES) $<

% : %.class
	/usr/bin/time -f "%C %E %M" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@

clean:
	rm *.class & rm *.jar