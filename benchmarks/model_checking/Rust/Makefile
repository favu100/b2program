.SUFFIXES:

.PHONY: all clean

all: CAN_BUS_tlc Cruise_finite1_deterministic_MC LandingGear_R6 Lift_MC_Large sort_m2_data1000_MC QueensWithEvents_4 Train1_Lukas_POR_v3 Train_1_beebook_deterministic_MC_POR_v2 nota_v2 #QueensWithEvents_8

OUTPUT ?= runtimes.txt

CARGO_PROJ_PATH=../../../btypes_primitives/src/main/rust/bmachine
CARGO_BUILD=cargo build --release --manifest-path $(CARGO_PROJ_PATH)/Cargo.toml
#CARGO_BUILD=minicargo build --offline --release --manifest-path $(CARGO_PROJ_PATH)/Cargo.toml
STRATEGY=mixed
THREADS=1
CACHING=true

% : clean %.rs
	cp $(*).rs $(CARGO_PROJ_PATH)/src/main.rs
	$(CARGO_BUILD)
	/usr/bin/time -f "$(*) $(STRATEGY) $(THREADS) $(CACHING) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) $(STRATEGY) $(THREADS) $(CACHING) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) $(STRATEGY) $(THREADS) $(CACHING) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) $(STRATEGY) $(THREADS) $(CACHING) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) $(STRATEGY) $(THREADS) $(CACHING) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine $(STRATEGY) $(THREADS) $(CACHING)

clean:
	rm -f $(CARGO_PROJ_PATH)/src/*.rs