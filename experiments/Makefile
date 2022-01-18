


VERS=0.1.0
JAR=B2Program-all-$(VERS)-SNAPSHOT.jar

FILE = Generated100
FILE = ArithmeticLaws
BFILE=$(FILE).mch
JAVAFILE=$(FILE).java

probmc: $(BFILE)
	time probcli $(BFILE) --model-check -disable-timeout
opreuse: $(BFILE)
	time probcli $(BFILE) --model-check -disable-timeout -df -p COMPRESSION TRUE -p OPERATION_REUSE full -p SAFETY_MODEL_CHECK TRUE -nodead -nogoal

# for big integer:
btypes.jar:
	cd ../btypes_big_integer && ./gradlew fatJar && cp build/libs/btypes_big_integer-all.jar ../experiments/btypes.jar && cd ../experiments

# for primitive integer:
btypespi.jar:
	cd ../btypes_primitives && ./gradlew fatJar && cp build/libs/btypes_primitives-all.jar ../experiments/btypespi.jar && cd ../experiments

../build/libs/$(JAR):
	@echo "Creating B2Program JAR"
	cd .. && ./gradlew fatJar && cd experiments

$(JAR): ../build/libs/$(JAR)
	@echo "Copying B2Program JAR"
	cp ../build/libs/$(JAR) .

$(JAVAFILE): $(JAR) $(BFILE)
	@echo "Generating Java Model Checker file $(JAVAFILE) from B file $(BFILE)"
	java -jar $(JAR) java true -2147483648 2147483647 10 false true $(BFILE)

javamc: $(JAVAFILE) btypes.jar
	@echo "Compiling Java Model Checker file $(JAVAFILE)"
	time javac -cp .:btypes.jar $(JAVAFILE)
	@echo "Running Java Model Checker file $(JAVAFILE)"
	time java -cp .:btypes.jar $(JAVAFILE) df 1 true

clean:
	-rm $(JAVAFILE)
	-rm $(JAR)
	-rm ../build/libs/$(JAR)
	-rm btypes.jar