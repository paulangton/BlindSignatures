# BlindSignatures

Computes the oblivious multiplication of two Big Integers using Obliv-C, the secure multi-party computation C extension available at https://oblivc.org/.

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

This simple program is practice for what is to come!
