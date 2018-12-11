.SUFFIXES:

.PHONY: all clean

all: And Divide Equal Equivalent Greater GreaterEqual Implies IncreasingSet Less LessEqual Minus Modulo Multiply Negative Or Plus RangeBig RangeCardBig2 RangeCardBig RangeCardSmall2 RangeCardSmall RangeComplementBig2 RangeComplementBig RangeComplementSmall2 RangeComplementSmall RangeElementOfBig2 RangeElementOfBig RangeElementOfSmall2 RangeElementOfSmall RangeIntersectionBig2 RangeIntersectionBig RangeIntersectionSmall2 RangeIntersectionSmall RangeSmall RangeUnionBig2 RangeUnionBig RangeUnionSmall2 RangeUnionSmall SetCardBig2 SetCardBig SetCardSmall2 SetCardSmall SetComplementBig2 SetComplementBig SetComplementSmall2 SetComplementSmall SetElementOfBig2 SetElementOfBig SetElementOfSmall2 SetElementOfSmall SetIntersectionBig2 SetIntersectionBig SetIntersectionSmall2 SetIntersectionSmall SetOperation SetUnionBig2 SetUnionBig SetUnionSmall2 SetUnionSmall Sieve SmallNumbers Unequal #Cruise_finite_k Lift LiftExec BigNumbers TrafficLight TrafficLightExec 

OUTPUT ?= runtimes.txt
DEPENDENCIES ?= :btypes.jar

%.class : %.java
	javac -cp .$(DEPENDENCIES) $<

% : %.class
	/usr/bin/time -f "%C %E" -ao $(OUTPUT) java -cp .$(DEPENDENCIES) $@

clean:
	rm *.class
