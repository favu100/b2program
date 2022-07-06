.SUFFIXES:

.PHONY: install build all b2program btypes_primitives btypes_big_integer

JAVA_CODE_GEN_FLAGS=-l java -mc true
JAVA_DEPENDENCIES= :btypes.jar
CPP_CODE_GEN_FLAGS=-l cpp -mc true
CPPC ?= clang++
CPPFLAGS ?= -std=c++14 -O1 -flto
STRATEGY=mixed
THREADS=1
CACHING=false
DIRECTORY=.

b2program:
	./gradlew fatJar && mv build/libs/B2Program-all-0.1.0-SNAPSHOT.jar .

btypes_primitives:
	cd btypes_primitives && ./gradlew fatJar && cp build/libs/btypes_primitives-all.jar ../btypes.jar && cd ..

btypes_big_integer:
	cd btypes_big_integer && ./gradlew fatJar && cp build/libs/btypes_big_integer-all.jar ../btypes.jar && cd ..

refresh:
	./gradlew eclipse --refresh-dependencies


ifndef LANGUAGE
	echo "LANGUAGE is not set"
else
ifeq ($(LANGUAGE), java)
%:
	java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(JAVA_CODE_GEN_FLAGS) -f $(DIRECTORY)/$@.mch
	javac -cp .$(JAVA_DEPENDENCIES) $(DIRECTORY)/$@.java
	java -cp .$(JAVA_DEPENDENCIES) $@ $(STRATEGY) $(THREADS) $(CACHING)
endif
ifeq ($(LANGUAGE), cpp)
%:
	java -jar B2Program-all-0.1.0-SNAPSHOT.jar $(CPP_CODE_GEN_FLAGS) -f $(DIRECTORY)/$@.mch
	$(CPPC) $(CPPFLAGS) -o $@.exec $@.cpp
	./$@.exec $(STRATEGY) $(THREADS) $(CACHING)
endif
endif

# Usage:
# make b2program
# make btypes_primitives or make btypes_big_integer
# make CAN_BUS_tlc LANGUAGE = java 