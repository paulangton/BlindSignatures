# BlindSignatures (WIP)

Computes oblivious multi-party ECDSA in Obliv-C, the secure multi-party computation C extension available at https://oblivc.org/. Allows one party to sign the message of another party, revealing neither the message nor the signing key to the opposite party.

Also computes oblivious big integer multiplication, written as practice for implementing ECDSA.

Requires gmplib for big integer computation, found at:  
https://gmplib.org/  

To pull in the absentminded-crypto-kit(ACK) submodule:  
git submodule init  
git submodule update  

Requires building the ACK, instructions for which can be found at:  
https://bitbucket.org/jackdoerner/absentminded-crypto-kit

To compile (after building ACK):  
Change working directory to BlindSignatures  
Run make  

To run:  
./a.out IPAddress PartyNumber(1|2) BigInt

Blind Signature computation instructions coming soon!
