#include <stdio.h>
#include <stdlib.h>
#include <obliv.h>
#include "addition.h"

int main (int argc, char *argv[]) {
	printf("Addition\n");
	if (argc == 5) {
		const char *remote_host = strtok(argv[1], ":");
		const char *port = strtok(NULL, ":");
		ProtocolDesc pd;
		addition add;
		log_info("Connecting to %s on port %s .. \n", remote_host, port);

		if(argv[2][0] == '1') { 
      		if(protocolAcceptTcp2P(&pd,port)!=0) { 
				log_err("TCP accept from %s failed\n", remote_host);
				exit(1);
      		}
    	}
   		else {
      		if(protocolConnectTcp2P(&pd,remote_host,port)!=0) {
				log_err("TCP connect to %s failed\n", remote_host);
				exit(1);
			}
		}
		currentParty = (argv[2][0] == '1'?:'2');
		setCurrentParty(&pd, currentParty);
		add->a = agrv[3];
		add->b = argv[4];

		execYaoProtocol(&pd, oblivAdd, &add);
		cleanupProtocol(&pd);

		log_info("Oblivious Addition produced: %d", add->c);
	}
	else {
		log_info("Usage: %s <hostname:port> <1|2> <filename>\n" 
	    "\tHostname usage:\n" 
		"\tlocal -> 'localhost' remote -> IP address or DNS name\n", argv[0]);
	}
	return 0;

}
