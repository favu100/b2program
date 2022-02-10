.SUFFIXES:

.PHONY: all clean

all: Lift_MC_Large CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 Train1_Lukas_POR Train_1_beebook_deterministic_MC_POR nota_v2 sort_m2_data1000_MC QueensWithEvents_Original_4 QueensWithEvents_Original_8
PROBCLI=./probcli.sh
FLAGS=--model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
OUTPUT ?= runtimes.txt

% :
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch $(FLAGS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch $(FLAGS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch $(FLAGS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch $(FLAGS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch $(FLAGS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch $(FLAGS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch $(FLAGS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch $(FLAGS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch $(FLAGS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch $(FLAGS)

clean:
	rm *.prob
