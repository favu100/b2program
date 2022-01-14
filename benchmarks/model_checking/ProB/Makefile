.SUFFIXES:

.PHONY: all clean

all: CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 QueensWithEvents sort_m2_data1000_MC Train1_Lukas_POR_v3 Train_1_beebook_deterministic_MC_POR_v2
PROBCLI=./probcli.sh
OUTPUT ?= runtimes.txt

% :
	timeout 20m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory

clean:
	rm *.prob