all: btypes

.PHONY: btypes
btypes:
	./gradlew btypes:assemble
	cp btypes/build/libs/B2Program-btypes.jar .
