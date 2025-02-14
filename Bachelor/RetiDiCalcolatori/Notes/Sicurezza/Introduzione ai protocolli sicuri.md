We have a standard comunication between two host (Alice and Bob).
![[comunicazionestandard.png | 450]]
In normal situation the channel is unprotected and possibly anyone (Eve) can view the messages between Alice and Bob and modify it. 
To prevent this we can do two thing:
- Make the channel secure (expensive and impassable)
- Transform the data in such a way that the adversary cannot make sense of it.

Cryptographic protocols allow to protect data as a secure enclosure:
- Confidentiality → Eve cannot access any information about the message  [[#Encryption]]
- Integrity → Bob can detect if the message has been modified by Eve  ([[#Hash functions]])
- Authenticity → Bob can verify if the message has not been sent by Alice ([[#Message Authentication Codes]])

To carry out encryption, the sender of the message must have a function available to encrypt the message (plaintext) while the recipient must have a decrypt function available to obtain the message in cleartext
![[crittografia.png]]

Cryptographic is based on primitives, that are mathematical tools like block ciphers, stream chipers, hash functions, ecc..  that combined with each other define the cryptographic protocols.



## Encryption
Modern encryption, that is encryption of computer, is based on **Kerckhoffs principle**:
1. Algorithms must be public (standard, evaluate from expert)
2. Security relies only on the secrecy of the key (not on secrecy of algorithm)
3. A cipher must be practically, if not mathematically, indecipherable (computational security, unfeasible to break given bounded amounts of time or resources.)
4. The key space is large enough to prevent brute force search (we need use long key because otherwise the attacker can be easily and quickly explore all the key space).
5. The scheme is designed to prevent cryptanalysis of the ciphertext, in fact no information can be obtained from the ciphertext regardless the type of plaintext data

There are two type of encryption scheme:
1. [[#Symmetric encryption]]
2. [[#Asymmetric encryption]]


### Symmetric encryption
Type of cryptography where the keys to encrypt and decrypt the message are the same (Alice and Bob share the same key). All symmetric schemes are based on one base operation **XOR**, because it is impossible to infer information about the plaintext or the key from the output (random value). ![[xor.png | center]]
Symmetric encryption primitives are of 3 types:
- **OTP (One time pad)**, where the random key has the same size of message and we do XOR between key and message (unique random key). Why we not used OTP everywhere? Because OTP have some pratical problem:
	- The key must be random but at the same time must be secret, shared between Bob and Alice and then communicated over a secure channel (impractical) 
	- Any reuse of the key allows the attacker to recover the plaintext message
For this reason OTP is used only in the case when we have available secure channels for a specified time. ![[OTP.png]]
- **Stream ciphers** (cifrari a flusso), very similar to OTP because a bit-wise XOR operation is computed between the plaintext and an intermediate key. The encryption key and the nonce, a number usually random or pseudo-random that has a unique use, are used to generate the PRG seed that is combined in XOR with messagge.
```math
			encrypt(key, nonce, m): m ⴲ PRG(key, nonce)
``` 
The nonce must be public because Bob need to generate the same seed. In fact given the same seed, the PRG produces the same intermediate key, for this reason re-using the same nonce (and key) completely breaks the cipher
- **Block ciphers**, the bits are aggregated into blocks, which will be encrypted (AES-128, AES-256) with a certain key.

More in detail computational security is based on two principles:
1. Encryption time is polynomial with respect to the size of the key
2. Brute-forcing a ciphertext takes exponential time with respect to the size of the key

In modern symmetric ciphers, the key size defines the security level.


### Asymmetric encryption
In asymmetric settings Alice and Bob use different keys (the encryption key is public and the decryption key is secret). Public key and private key are related by a certain mathematics. Asymmetric encryption algorithm are very heavy on performance and for this reason are typically used for following operation:
- **Key exchange**, allows Alice and Bob to obtain a shared key. Key exchange are based on trapdoor functions, mathematical functions where computing the function in one-way is always easy and the inverse is also easy only if we know the secret (otherwise is computational impossible).
	- Discrete logarithm problem, if you know g^a it is hard to compute a
	- Computational Diffie-Hellman, given g^a and g^b it is hard to compute g^ab
	- Decisional Diffie-Hellman, given g^a and g^b it is hard to distinguish g^ab from g^r where is random.
		![[diffiehellman.png | 500 ]]
- **Digital signature**, with the aim of demonstrating the integrity of the document and that the document has been approved by a certain public authority.
```math
					sign(sk, message) → signature  #like MAC
			verify(pk, message, signature) → {true, false}
```
A secure digital signature is unforgeable without knowledge of the secret key but everybody can verify the signature. ![[digitalsignatures.png]]

So asymmetric encrypto introduces the term “key pair", a couple of keys (secret-key, public-key) usually associated with a User. The public key of a user is unique, and identifies him. ![[keypair.png]]

In asymmetric schemes the security level is more difficult as it depends on the underlying math. 

The public key can be send to everyone but how can we be sure that that key is the public key of a certain user? The answer is that exist a [[#Public key Infrastructure]].



### Public key Infrastructure
The PKI define how to securely distribute the public keys by using intermediate trusted parties. All pairs of key need metadata to indicate the owner, the protocol used, time-to-live; for this reason PKI is based on **Certificate**, that is a digitally signed document that binds some information to cryptographic material.

PKI, usually, is used to protect from [[MitM]] attack.
![[pkimitm.png | center | 500]]

PKI is all based on trusted third party approach. This trusted third party are usually called **Certification Authority (CA)**. ![[ca.png | center | 500]]Alice need to know the public key of CA to validate the certificate received from Bob.

Requiring a few authorities to sign all certificates is not scalable (point of failures  
and political and economic conflicts). A hierarchical approach is a viable trade-off: the root CA certificates a CA that certificates a CA that.... . This approach is based **Certificate chain**:
- The server has a certificate, issued by an intermediate CA
- The intermediate CA has a certificate, issued by another intermediate CA or a root CA

To verify the end-user certificate, a client needs to verify all certificates in the chain, until it finds a known trusted certificate.
![[certifcatechain.png | center | 500]]




## Hash functions 
To ensure integrity in communication we can use hash functions to generate a digest, a small string of bit (fixed size), from the data to send. The principles of digest is this:
```math
				data1 != data2 <-> digest1 != digest2
``` 
But with fixed number of byte (128, 256) this is impossible. We need to define an hash function with the following characteristics:
- Collision resistance, computationally infeasible to find any m1, m2 such that H(m1) = H(m2)
- Preimage collision resistance, given m1 computationally infeasible find m2 such that H(m1) = H(m2)

Let's take a look to famous hash functions:
- md5 → really deprecated and insecure
- sha1 → deprecated, collisions found
- sha2 → OK, stronger version of sha1
- sha3 → OK, built on different primitives than sha1 and sha2



## Message Authentication Codes
A message authentication code is generated from the message and a shared key between Alice and Bob. 
```math
					MAC(key, message) → tag
```
If the tag generated by Bob is equals to the tag generated by Alice we obtain authenticity in communication. Cyber attacker can view the message but he can't generate the same tag because does not have the key; for this reason a MAC guarantee authenticity and also integrity. Beware that Hash != MAC, in fact hash functions do not make use of any secret information.
Common standard implementation of MAC are based on hash functions and block chipers. 

There is a common situation where the use of simple tag is not secure: **Replay attacks**. A replay attack is a form of network attack in which valid data transmission is maliciously or fraudulently repeated or delayed. For example "Suppose that Alice wants to prove her identity to Bob; Bob requests her password as proof of identity, which Alice dutifully provides (possibly after some transformation like hashing) the password; meanwhile, Eve sniff the conversation and keeps the password (or the hash). After the interchange is over, Eve (acting as Alice) connects to Bob; when asked for proof of identity, Eve sends Alice's password (or hash) read from the last session which Bob accepts, thus granting Eve access."
Replay attacks can be prevented by tagging each encrypted component with a session ID and a component number (transport protocol). ![[replyattacks.png]]
