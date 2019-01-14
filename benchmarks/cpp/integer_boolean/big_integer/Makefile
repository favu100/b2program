.SUFFIXES:

.PHONY: all clean

all: And Divide Equal Equivalent Greater GreaterEqual Implies Less LessEqual Minus Modulo Multiply Negative Or Plus SmallNumbers Unequal LiftExec BigNumbers

OUTPUT ?= runtimes.txt

CPPC ?= clang++
IMMERFLAGS=-DIMMER_NO_THREAD_SAFETY
CPPFLAGS ?= -std=c++14 -O2 -march=native -g $(IMMERFLAGS)

%.exec : %.cpp
	$(CPPC) $(CPPFLAGS) -o $@ $<

% : %.exec
	gtime -f "%C %E" -ao $(OUTPUT) ./$<

clean:
	rm -f *.exec
