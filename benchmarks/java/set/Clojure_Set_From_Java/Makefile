.SUFFIXES:

.PHONY: all clean

all: RangeBig RangeCardBig2 RangeCardBig RangeCardSmall2 RangeCardSmall RangeDifferenceBig2 RangeDifferenceBig RangeDifferenceSmall2 RangeDifferenceSmall RangeElementOfBig2 RangeElementOfBig RangeElementOfSmall2 RangeElementOfSmall RangeIntersectionBig2 RangeIntersectionBig RangeIntersectionSmall2 RangeIntersectionSmall RangeSmall RangeUnionBig2 RangeUnionBig RangeUnionSmall2 RangeUnionSmall SetCardBig2 SetCardBig SetCardSmall2 SetCardSmall SetDifferenceBig2 SetDifferenceBig SetDifferenceSmall2 SetDifferenceSmall SetElementOfBig2 SetElementOfBig SetElementOfSmall2 SetElementOfSmall SetIntersectionBig2 SetIntersectionBig SetIntersectionSmall2 SetIntersectionSmall SetUnionBig2 SetUnionBig SetUnionSmall2 SetUnionSmall Sieve TrafficLightExec

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes.jar

%.class : %.java
	javac -cp .$(DEPENDENCIES) $<

% : %.class
	gtime -f "%C %E" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@

clean:
	rm *.class
