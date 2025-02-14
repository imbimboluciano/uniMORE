// SIMPLE SERVER SIDE FOR TCP CONNECTION 
// A single parameter is requested from the command line, and it is the port number 
// to bind the welcoming socket to

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv){

	// Check on parameters
	if(argc != 2) {
		printf("ERROR-- wrong number of parameters, only one requested\n\n");
		exit(-1);
	}
	int port_number = atoi(argv[1]);

	// Generate a new socket (welcoming socket)
	int welc_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(welc_sockfd < 0){
		perror("ERROR-- on the server side: ");
		exit(-2);
	}

	// Generate the struct sockaddr_in and fill that in
	struct sockaddr_in bind_socket;
	bind_socket.sin_family = AF_INET;
	bind_socket.sin_port = htons(port_number);
	bind_socket.sin_addr.s_addr = INADDR_ANY;	// 0.0.0.0 byte-order-neutral

	// Bind the welcoming socket to a local port and IP
	int check_bind = bind(welc_sockfd, (struct sockaddr*) &bind_socket, sizeof(bind_socket));
	if(check_bind < 0 ){
		perror("ERROR-- on the server side: ");
		exit(-3);
	}

	// Start listening
	int check_listen = listen(welc_sockfd, 10);
	if(check_listen < 0){
		perror("ERROR-- on the server side: ");
		exit(-4);
	}

	// Generate a new struct sockaddr_in for the clients
	struct sockaddr_in client_socket;
	int size_client_socket = sizeof(client_socket);
	
	// Initiate infinite loop to accept all client connections
	while(1){	
		int client_sockfd = accept(welc_sockfd, (struct sockaddr*) &client_socket, &size_client_socket);
		if (client_sockfd < 0){
			perror("ERROR-- on the server side: ");
			exit(-5);
		}

		// Print the relevant information about the new client
		char* client_address = inet_ntoa(client_socket.sin_addr);
		int client_port = ntohs(client_socket.sin_port);
		printf("== DEBUG == New client connected with IP: %s and port number: %d\n", client_address, client_port);
		
		// Create a child process to handle the connection
		int cpid = fork();
		if (cpid < 0){
			perror("ERROR-- on the server side: ");
			exit(-6);
		}
		if (cpid == 0) {      // CHILD CODE -----------------------------------------
			// The server sends the first message
			char buffer[255];
			memset(buffer, 0, 255);
			strcpy(buffer, "Congrats! You have successfully reached the server");
			int sent = send(client_sockfd, buffer, sizeof("Congrats! You have successfully reached the server"), 0);
			if(sent < 0){
				perror("ERROR-- on the server side: ");
				exit(-7);
			}

			// The server receives the response
			memset(buffer, 0, 255);
			int received = recv(client_sockfd, buffer, 30, 0);
			if(received < 0){
				perror("ERROR-- on the server side: ");
				exit(-8);
			}
			printf("DEBUG-- The server received from the client: %s\n\n", buffer);
			close(client_sockfd);
			exit(1);
		}
		// The server immediately closes the socket
		close(client_sockfd);
	}
	close(welc_sockfd);

	return 0;
}