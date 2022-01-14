.SUFFIXES:

.PHONY: all clean

all: CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 QueensWithEvents sort_m2_data1000_MC Train1_Lukas_POR_v3 Train_1_beebook_deterministic_MC_POR_v2
PROBCLI=./probcli.sh
OUTPUT ?= runtimes.txt
LTSMIN=ltsmin_v3.0.2/bin
LTSMIN_FLAG=-noinv

% :
	timeout 20m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.mch -mc_with_lts_seq $(LTSMIN_FLAG) -p LTSMIN $(LTSMIN)

clean:
	rm *.prob