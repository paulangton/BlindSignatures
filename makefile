BlindSignaturesMake: src/multiplication.c src/multiplication.oc
	../obliv-c/bin/oblivcc -o BlindSignaturesMake src/multiplication.c src/multiplication.oc -Llib/absentminded-crypto-kit/build/lib -lack
