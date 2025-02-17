.SUFFIXES:

.PHONY: install build all b2program btypes_primitives btypes_big_integer

JAVA_CODE_GEN_FLAGS=-l java -mc true
JAVA_DEPENDENCIES= :btypes.jar
CPP_CODE_GEN_FLAGS=-l cpp -mc true
CPPC ?= clang++
CPPFLAGS ?= -std=c++14 -O1 -flto
RS_CODE_GEN_FLAGS=-l rs -mc true
STRATEGY=mixed
THREADS=1
CACHING=false
DIRECTORY=.

b2program:
	./gradlew fatJar && mv build/libs/B2Program-all-0.1.0-SNAPSHOT.jar .

btypes_primitives:
	cd btypes_primitives && ./gradlew check && ./gradlew fatJar && cp build/libs/btypes_primitives-all.jar ../btypes.jar && cd ..

btypes_big_integer:
	cd btypes_big_integer && ./gradlew check && ./gradlew fatJar && cp build/libs/btypes_big_integer-all.jar ../btypes.jar && cd ..

ifndef LANGUAGE
	echo "LANGUAGE is not set"
else
ifeq ($(LANGUAGE), java)
%:
	java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(JAVA_CODE_GEN_FLAGS) -f $(DIRECTORY)/$@.mch
	cp $(DIRECTORY)/*.java .
	javac -cp .$(JAVA_DEPENDENCIES) $@.java
	java -cp .$(JAVA_DEPENDENCIES) $@ $(STRATEGY) $(THREADS) $(CACHING)
endif
ifeq ($(LANGUAGE), cpp)
%:
	java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(CPP_CODE_GEN_FLAGS) -f $(DIRECTORY)/$@.mch
	cp $(DIRECTORY)/*.cpp .
	$(CPPC) $(CPPFLAGS) -o $@.exec $@.cpp
	./$@.exec $(STRATEGY) $(THREADS) $(CACHING)
endif
ifneq (,$(findstring $(LANGUAGE), rs|RS|rust|Rust))
%:
	java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(RS_CODE_GEN_FLAGS) -f $(DIRECTORY)/$@.mch
	mkdir -p ./btypes_primitives/src/main/rust/bmachine/src/
	mv $(DIRECTORY)/$@.rs ./btypes_primitives/src/main/rust/bmachine/src/main.rs
	find $(DIRECTORY) -maxdepth 1 -type f -name "*.rs" -exec mv -v '{}' ./btypes_primitives/src/main/rust/bmachine/src/ \;
	cargo run --release --manifest-path ./btypes_primitives/src/main/rust/bmachine/Cargo.toml -- $(STRATEGY) $(THREADS) $(CACHING)
endif
endif

# Usage:
# make b2program
# make btypes_primitives or make btypes_big_integer
# make CAN_BUS_tlc LANGUAGE=java