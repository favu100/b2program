all: install btypes

.PHONY: install btypes

btypes:
	cd btypes_primitives && ./gradlew fatJar && cp build/libs/btypes_primitives-all.jar ../btypes_persistent.jar && cd ..