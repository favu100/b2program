.SUFFIXES:

.PHONY: build all clean

all: build CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve TrafficLightExec Train_1_beebook_deterministic_exec sort_m2_data1000_exec

build:
	cd ../../../btypes_big_integer ; ./gradlew -q fatJar ; cp build/libs/btypes_big_integer-all.jar ../benchmarks/execution/Java_Clojure_Set_Big_Integer/btypes.jar ; cd ../benchmarks/execution/Java_Clojure_Set_Big_Integer

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes.jar

%.class : %.java
	javac -cp .$(DEPENDENCIES) $<

% : %.class
	gtime -f "%C %E %M" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@

clean:
	rm *.class & rm *.jar
