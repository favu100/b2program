


VERS=0.1.0
JAR=B2Program-all-$(VERS)-SNAPSHOT.jar
../build/libs/$(JAR):
	../gradlew fatJar

FILE = Generated100
BFILE=$(FILE).java
JAVAFILE=$(FILE).java

test:
	time probcli Generated100.mch --model-check -disable-timeout
opreuse:
	time probcli Generated100.mch --model-check -disable-timeout -df -p COMPRESSION TRUE -p OPERATION_REUSE full -p SAFETY_MODEL_CHECK TRUE -nodead -nogoal

btypes.jar:
	cd ../btypes_big_integer && ./gradlew fatJar && cp build/libs/btypes_big_integer-all.jar ../experiments/btypes.jar && cd ../experiments

$(JAVAFILE): ../build/libs/$(JAR) $(BFILE)
	cp ../build/libs/$(JAR) .
	java -jar $(JAR) java false -2147483648 2147483647 10 true true $(BFILE)
mc: $(JAVAFILE) $(btypes.jar)
	time javac -cp .:btypes.jar $(JAVAFILE)
	time java -cp .:btypes.jar $(JAVAFILE) df 1 true
