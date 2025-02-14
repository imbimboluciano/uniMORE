#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){

    int sockfd, newsockfd, cli_len;
    char buffer[256];


    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 1) {
         error("ERROR on number of parameters");
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0))  < 0){
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr,sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(2525);

    if(bind(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR on binding");
    }

    listen(sockfd, 5);
    
    cli_len = sizeof(cli_addr);
    if ((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_len)) < 0){
        error("ERROR on accept");
    }

    bzero(buffer, 256);
    if ((n = read(newsockfd,buffer,sizeof(buffer)))< 0)    error("ERROR reading from socket");
         
    printf("%s\n",buffer);

    return 0;





}