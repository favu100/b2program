all: btypes

.PHONY: btypes
btypes:
	cd btypes_primitives && ./gradlew fatJar && cp build/libs/btypes_primitives-all.jar ../btypes_persistent.jar && cd .. & cp btypes_primitives/src/main/cpp/*.cpp ./
