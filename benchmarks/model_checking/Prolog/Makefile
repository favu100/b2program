.SUFFIXES:

.PHONY: all clean

all: Lift
PROBCLI=./probcli.sh
FLAGS=--model-check -disable-time-out -p OPERATION_REUSE full -pref_group model_check unlimited -p COMPRESSION TRUE -noass -memory
OUTPUT ?= runtimes.txt

% :
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) $(PROBCLI) $@.P $(FLAGS)

clean:
	rm *.prob
