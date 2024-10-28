.SUFFIXES:

.PHONY: all clean

all: Lift_MC_Large Cruise_finite1_deterministic_MC CAN_BUS_tlc LandingGear_R6 nota_v2 rether obsw_M001_1 obsw_M001_2 prob_oneway8seq Train_1_beebook_deterministic_MC_POR_v3 sort_m2_data1000_MC QueensWithEvents_Original_4
FLAGS=-l java -mc true -f
OUTPUT ?= runtimes.txt

% :
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch


clean:
	rm *.java & rm *.cpp & rm *.json
