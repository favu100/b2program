.SUFFIXES:

.PHONY: all clean

all: Lift_MC_Large CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 Train1_Lukas_POR_v3 Train_1_beebook_deterministic_MC_POR_v2 nota_v2 sort_m2_data1000_MC QueensWithEvents_Original_4 QueensWithEvents_Original_8
FLAGS=-l cpp -mc true
OUTPUT ?= runtimes.txt

% :
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(FLAGS) $@.mch


clean:
	rm *.java & rm *.cpp & rm *.json
