all: install btypes

.PHONY: install btypes
install:
	cp btypes_primitives/src/main/cpp/*.hpp /usr/local/include/btypes_primitives/ & cp btypes_big_integer/src/main/cpp/*.hpp /usr/local/include/btypes_big_integer/

btypes:
	cd btypes_primitives && ./gradlew fatJar && cp build/libs/btypes_primitives-all.jar ../btypes_persistent.jar && cd ..