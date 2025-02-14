HTTPS is «just» [[HTTP]] over TLS. On trasport layer is based on TCP and use the port 443. The secure connection is composed by the following steps:
1. Establish [[TCP]] connection with server  
2. Carry out the TLS handshake  
	- Allows client to authenticate server  
	- Server and client use Diffie-Hellman to establishe a symmetric  session key  
3. Send normal HTTP requests/responses inside the secure TLS channel