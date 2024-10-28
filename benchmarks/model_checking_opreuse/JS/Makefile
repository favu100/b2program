.SUFFIXES:

.PHONY: build all clean

all: Lift_MC_Large Cruise_finite1_deterministic_MC CAN_BUS_tlc LandingGear_R6 nota_v2 rether obsw_M001_1 obsw_M001_2 prob_oneway8seq Train_1_beebook_deterministic_MC_POR_v2 sort_m2_data1000_MC QueensWithEvents_4

build:
	cd ../../../btypes_primitives/src/main/js ; cp -R btypes ../../../../benchmarks/model_checking/JS/btypes; cd ../../../../benchmarks/model_checking/JS

OUTPUT ?= runtimes.txt
STRATEGY=mixed
CACHING=true
COMPILE_FLAGS=--target ES6 --moduleResolution node

%.js : %.ts
	tsc $(COMPILE_FLAGS) $<

% : %.js
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) node $@ $(STRATEGY) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) node $@ $(STRATEGY) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) node $@ $(STRATEGY) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) node $@ $(STRATEGY) $(CACHING)
	timeout 60m gtime -f "%C %E %M" -ao $(OUTPUT) node $@ $(STRATEGY) $(CACHING)

clean:
	rm *.js
