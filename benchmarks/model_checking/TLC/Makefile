.SUFFIXES:

.PHONY: all clean

all: CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 QueensWithEvents sort_m2_data1000_MC Train1_Lukas_POR_v3 Train_1_beebook_deterministic_MC_POR_v2
PROBCLI=./probcli.sh
OUTPUT ?= runtimes.txt

benchmarks_1 :
	timeout 20m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -p TLC_WORKERS 1

benchmarks_1 :
	timeout 20m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_tlc -p TLC_WORKERS 6


clean:
	rm *.prob