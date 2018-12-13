.SUFFIXES:

.PHONY: all clean

all: RangeBig RangeCardBig2 RangeCardBig RangeCardSmall2 RangeCardSmall RangeComplementBig2 RangeComplementBig RangeComplementSmall2 RangeComplementSmall RangeElementOfBig2 RangeElementOfBig RangeElementOfSmall2 RangeElementOfSmall RangeIntersectionBig2 RangeIntersectionBig RangeIntersectionSmall2 RangeIntersectionSmall RangeSmall RangeUnionBig2 RangeUnionBig RangeUnionSmall2 RangeUnionSmall SetCardBig2 SetCardBig SetCardSmall2 SetCardSmall SetComplementBig2 SetComplementBig SetComplementSmall2 SetComplementSmall SetElementOfBig2 SetElementOfBig SetElementOfSmall2 SetElementOfSmall SetIntersectionBig2 SetIntersectionBig SetIntersectionSmall2 SetIntersectionSmall SetOperation SetUnionBig2 SetUnionBig SetUnionSmall2 SetUnionSmall Sieve # TrafficLight TrafficLightExec

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes_persistent.jar

%.class : %.java
	javac -cp .$(DEPENDENCIES) $<

% : %.class
	gtime -f "%C %E" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@

clean:
	rm *.class
