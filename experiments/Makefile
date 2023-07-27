


VERS=0.1.0
JAR=B2Program-all-$(VERS)-SNAPSHOT.jar

FILE = Generated100
FILE = Generated1000
#FILE = ArithmeticLaws
#FILE = BoolLaws
FILE=ERnice_nodata_V53 # does not work
FILE=nota
#FILE=Library_3_3
BFILE=$(FILE).mch
JAVAFILE=$(FILE).java

probmc: $(BFILE)
	time probcli $(BFILE) --model-check -disable-timeout
opreuse: $(BFILE)
	time probcli $(BFILE) --model-check -disable-timeout -df -p COMPRESSION TRUE -p OPERATION_REUSE full -p SAFETY_MODEL_CHECK TRUE -nodead -nogoal
tlc: $(BFILE)
	time probcli $(BFILE) --mc-with-tlc -disable-timeout -nodead -nogoal

BIGINT=false
# for big integer:
ifeq ($(BIGINT),true)
btypes.jar:
	cd ../btypes_big_integer && ./gradlew fatJar && cp build/libs/btypes_big_integer-all.jar ../experiments/btypes.jar && cd ../experiments
else
# for primitive integer (BIGINT=false):
btypes.jar:
	cd ../btypes_primitives && ./gradlew fatJar && cp build/libs/btypes_primitives-all.jar ../experiments/btypes.jar && cd ../experiments
endif

../build/libs/$(JAR):
	@echo "Creating B2Program JAR"
	cd .. && ./gradlew fatJar && cd experiments

$(JAR): ../build/libs/$(JAR)
	@echo "Copying B2Program JAR"
	cp ../build/libs/$(JAR) .

$(JAVAFILE): $(JAR) $(BFILE)
	@echo "Generating Java Model Checker file $(JAVAFILE) from B file $(BFILE)"
	#java -jar $(JAR) java $(BIGINT) -2147483648 2147483647 10 false true $(BFILE)
	java -jar $(JAR) -l java -bi $(BIGINT) -min -2147483648 --max 2147483647 -dss 10 -cs false -a main -f $(BFILE)

CACHING=false
THREADS=1
javamc: $(JAVAFILE) btypes.jar
	@echo "Compiling Java Model Checker file $(JAVAFILE)"
	time javac -cp .:btypes.jar $(JAVAFILE)
	@echo "Running Java Model Checker file $(JAVAFILE), THREADS=$(THREADS), CACHING=$(CACHING)"
	time java -cp .:btypes.jar $(JAVAFILE) df $(THREADS) $(CACHING)

clean:
	-rm $(JAVAFILE)

clean-all:
	-rm $(JAVAFILE)
	-rm $(JAR)
	-rm ../build/libs/$(JAR)
	-rm btypes.jar