#include <stdio.h>
#include <stdlib.h>
#include <obliv.h>
#include "addition.h"

int main (int argc, char *argv[]) {
	printf("Addition\n");
	int currentParty;
	if (argc == 5) {
		const char *remote_host = strtok(argv[1], ":");
		const char *port = strtok(NULL, ":");
		ProtocolDesc pd;
		add *add1;
		add1->a = 0;
		add1->b = 0;
		add1->c = 0;
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
		currentParty = (argv[2][0] =='1'?1:2);
		setCurrentParty(&pd, currentParty);
		add1->a = argv[3];
		add1->b = argv[4];

		execYaoProtocol(&pd, oblivAdd, &add1);
		cleanupProtocol(&pd);

		printf("Oblivious Addition produced: %d", add1->c);
	}
	else {
		printf("Usage: %s <hostname:port> <1|2> <filename>\n" 
	    "\tHostname usage:\n" 
		"\tlocal -> 'localhost' remote -> IP address or DNS name\n", argv[0]);
	}
	return 0;

}
