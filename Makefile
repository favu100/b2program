.PHONY: install btypes_primitives btypes_big_integer

btypes_primitives:
	cd btypes_primitives && ./gradlew fatJar && cp build/libs/btypes_primitives-all.jar ../btypes.jar && cd ..

btypes_big_integer:
	cd btypes_big_integer && ./gradlew fatJar && cp build/libs/btypes_big_integer-all.jar ../btypes.jar && cd ..