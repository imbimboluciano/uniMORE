#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(char *msg){
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]){

    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256], hostname[256];

    if (argc < 2) {
       error("ERROR number of parameters");
    }

    
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    /* copio nella struttura dati del server l'hostname fornito*/
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(2525);

    /* connessione al server*/
    if (connect(sockfd,(const struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    gethostname(hostname, sizeof(hostname));

    bzero(buffer, 256);
    strcat(buffer,"Connection from ");
    strcat(buffer, hostname);

    if((n = write(sockfd, buffer, sizeof(buffer))) < 0){
        error("ERROR on writing to socket");
    }
    
   
    return 0;
}
