.SUFFIXES:

.PHONY: all clean

all: CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 nota_v2 Train1_Lukas_POR Train_1_beebook_deterministic_MC_POR sort_m2_data1000_MC QueensWithEvents_Original_4 QueensWithEvents_Original_8
PROBCLI=./probcli.sh
OUTPUT ?= runtimes.txt
THREADS=6

%:
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -noass -p TLC_WORKERS $(THREADS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -noass -p TLC_WORKERS $(THREADS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -noass -p TLC_WORKERS $(THREADS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -noass -p TLC_WORKERS $(THREADS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -noass -p TLC_WORKERS $(THREADS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -noass -p TLC_WORKERS $(THREADS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -noass -p TLC_WORKERS $(THREADS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -noass -p TLC_WORKERS $(THREADS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -noass -p TLC_WORKERS $(THREADS)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -noass -p TLC_WORKERS $(THREADS)


clean:
	rm *.prob
