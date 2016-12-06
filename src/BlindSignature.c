/*
I need to implement an Elliptic Curve Digital Signature Algorithm that will allow the signing of a message by someone other than the sender. The sender cannot see the signer's private key, and the signer cannot see the sender's message

Previously agreed will be the curve parameters which include:
- the elliptic curve function C
- the elliptic curve base point G (a generator of the elliptic curve with large prime order n)
- the multiplicative order of the point G, which is n

The inputs will be a SHA-256 hashed message from one party, and a private key package {p,q,g,x} from the signer.

To start, the sender will hash their message m (SHA-256), creating e, a hashed message
the signer will then compute their private key d by randomly selecting an integer [1, n-1]
and their public key q by computing d x G, where x represents the elliptic curve point multiplication by a scalar operation

at this point, both inputs will be passed into Obliv-land, where the following should occur

L is the bit length of the group order n
z is the L leftmost bits of e
select random k from [1, n-1]
calculate curve point (x,y) = k x G
calculate r = x mod n, if r = 0, select new random
calculate s = (k^-1)(z+rd) mod n, if s = 0, select new random and compute new r
signature pair is {r,s}

return {r,s} to both parties

exit obliv-land
print some representation of {r,s} for both parties to see


*/
