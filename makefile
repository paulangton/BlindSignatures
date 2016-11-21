makefile: src/multiplication.c src/multiplication.oc	
	$(OBLIVC_PATH)/bin/oblivcc -o BlindSignaturesMake src/multiplication.c src/multiplication.oc -Llib/absentminded-crypto-kit/build/lib -lack
