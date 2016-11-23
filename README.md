# BlindSignatures

Computes the oblivious multiplication of two Big Integers using Obliv-C, the secure multi-party computation C extension available at https://oblivc.org/. 

Requires building the absentminded-crypto-kit(ACK) which can be found at:
https://bitbucket.org/jackdoerner/absentminded-crypto-kit

To compile (after buliding ACK):
Change working directory to BlindSignatures
Type make

To run:
./a.out IPAddress PartyNumber(1|2) BigInt

This simple program is practice for what is to come!
