.SUFFIXES:

.PHONY: all clean

all: Lift_MC_Large CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 Train1_Lukas_POR Train_1_beebook_deterministic_MC_POR sort_m2_data1000_MC QueensWithEvents_Original_4 QueensWithEvents_Original_8
PROBCLI=./probcli.sh
OUTPUT ?= runtimes.txt

% :
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch --model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory

clean:
	rm *.prob
