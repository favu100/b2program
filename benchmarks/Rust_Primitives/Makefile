.SUFFIXES:

.PHONY: all clean

all: CAN_BUS_tlc_exec Cruise_finite1_deterministic_exec LiftExec scheduler_deterministic_exec Sieve Train_1_beebook_deterministic_exec TrafficLightExec sort_m2_data1000_exec

CARGO_PROJ_PATH=../../btypes_primitives/src/main/rust/bmachine

%.main : %.rs
	cp $*.rs $(CARGO_PROJ_PATH)/src/main.rs

%Exec : %_exec.rs %.main
	cp $@ $(CARGO_PROJ_PATH)/src/%Exec.rs
	cargo build --release --manifest-path $(CARGO_PROJ_PATH)

%_exec : %_exec.rs %.main
	cp $@ $(CARGO_PROJ_PATH)/src/%_exec.rs
	cargo build --release --manifest-path $(CARGO_PROJ_PATH)

clean:
	rm -f $(CARGO_PROJ_PATH)/src/*.rs