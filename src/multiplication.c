#include <stdio.h>
#include <stdlib.h>
#include <obliv.h>
#include <string.h>
#include <gmp.h>
#include "multiplication.h"

int main (int argc, char *argv[]) {
	printf("Big-Int Oblivious Multiplication\n");
	printf("================================\n");

	if (argc == 4) {
		const char *remote_host = strtok(argv[1], ":");
		const char *port = strtok(NULL, ":");
		ProtocolDesc pd;
		ProtocolIO *mul = malloc(sizeof(ProtocolIO));
		int currentParty;

		printf("Connecting to %s on port %s .. \n", remote_host, port);

		if(argv[2][0] == '1') {
      		if(protocolAcceptTcp2P(&pd,port)!=0) {
				printf("TCP accept from %s failed\n", remote_host);
				exit(1);
      		}
    	}
   		else {
      		if(protocolConnectTcp2P(&pd,remote_host,port)!=0) {
				printf("TCP connect to %s failed\n", remote_host);
				exit(1);
			}
		}
		printf("Establishing parties...\n");
		currentParty = (argv[2][0] =='1'?1:2);
		setCurrentParty(&pd, currentParty);

		// Jack's function takes a pointer to the beginning of an array of 8 bit integers
		// We should first read our input into a gmplib mpz_t to preserve size, then
		// extract 8 bit pieces of the mpz_t into the vector
		uint8_t LEVector[32];
		toPointedLE(argv[3], &LEVector);
		mul->data = &LEVector;

		printf("Executing Yao's Protocol...\n");
		execYaoProtocol(&pd, oblivMul, mul);
		cleanupProtocol(&pd);

		printf("Oblivious Multiplication produced: %llu\n", mul->result);
		free(mul);
	}
	else {
		printf("Usage: %s <hostname:port> <1|2> <data>  \n"
	    "\tHostname usage:\n"
		"\tlocal -> 'localhost' remote -> IP address or DNS name\n", argv[0]);
	}

	return 0;

}

// should convert a
void toPointedLE(char[] x, void* p) obliv {
	mpz_t input;
	mpz_init(input);
	mpz_set_str(&input, &x, 10);
	temp = mpz_sizeinbase(input, 2);
	mpz_t quotient;
	mpz_init(quotient);
	mpz_set(quotient, input);
	for(size_t i = 0; i < temp; i += 8) {
		mpz_fdiv_qr_2exp(quotient, ((uint8_t) p)[i], quotient, );
	}
}
