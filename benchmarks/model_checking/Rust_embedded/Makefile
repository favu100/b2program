.SUFFIXES:

.PHONY: all clean

all: Lift_MC_Large Cruise_finite1_deterministic_MC LandingGear_R6 CAN_BUS_tlc Train1_Lukas_POR_v3 Train_1_beebook_deterministic_MC_POR_v2 nota_v2

OUTPUT ?= runtimes.txt

CARGO_PROJ_PATH=../../../btypes_primitives/src/main/rust_embedded/bmachine_mc
#CARGO_PROJ_PATH=../../../btypes_primitives/src/main/rust_embedded/bmachine_bitvec_mc
CARGO_BUILD=cargo build --release --manifest-path $(CARGO_PROJ_PATH)/Cargo.toml
#CARGO_BUILD=cargo +nightly build --release --manifest-path $(CARGO_PROJ_PATH)/Cargo.toml
STRATEGY=mixed
THREADS=1
CACHING=true

% : clean %.rs
	cp $(*).rs $(CARGO_PROJ_PATH)/src/main.rs
	$(CARGO_BUILD)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine_mc $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine_mc $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine_mc $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine_mc $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine_mc $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine_mc $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine_mc $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine_mc $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine_mc $(STRATEGY) $(THREADS) $(CACHING)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine_mc $(STRATEGY) $(THREADS) $(CACHING)

clean:
	rm -f $(CARGO_PROJ_PATH)/src/*.rs