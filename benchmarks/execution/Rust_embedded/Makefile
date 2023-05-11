.SUFFIXES:

.PHONY: all clean

all: LiftExec TrafficLightExec scheduler_deterministic_exec CAN_BUS_tlc_exec Train_1_beebook_deterministic_exec Cruise_finite1_deterministic_exec

OUTPUT ?= runtimes.txt

#CARGO_PROJ_PATH=../../../btypes_primitives/src/main/rust_embedded/bmachine
CARGO_PROJ_PATH=../../../btypes_primitives/src/main/rust_embedded/bmachine_bitvec
#CARGO_BUILD=cargo build --release --manifest-path $(CARGO_PROJ_PATH)/Cargo.toml
CARGO_BUILD=cargo +nightly build --release --manifest-path $(CARGO_PROJ_PATH)/Cargo.toml

%.main : %.rs
	cp $(*).rs $(CARGO_PROJ_PATH)/src/$(*).rs

%Exec.cp : %Exec.rs %.main
	cp $(*)Exec.rs $(CARGO_PROJ_PATH)/src/main.rs

%_exec.cp : %_exec.rs %.main
	cp $(*)_exec.rs $(CARGO_PROJ_PATH)/src/main.rs

% : clean %.cp
	$(CARGO_BUILD)
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine
	/usr/bin/time -f "$(*) %E %M" -ao $(OUTPUT) $(CARGO_PROJ_PATH)/target/release/bmachine

clean:
	rm -f $(CARGO_PROJ_PATH)/src/*.rs