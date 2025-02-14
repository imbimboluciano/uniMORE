/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
/* librerie per le socket API*/ 
#include <sys/socket.h>
#include <netinet/in.h>


/* funzione per gestire le situazioni anomale*/
void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){

    /* sockfd è la welcome socket, newsockfd è la connection socket*/
     int sockfd, newsockfd, portno, clilen;
     char buffer[256];

     /* strutture dati per gli indirizzi */
     struct sockaddr_in serv_addr, cli_addr;
     int n;

     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }

     sockfd = socket(AF_INET, SOCK_STREAM, 0);

     /* verifichiamo che ci siano socket disponibili*/
     if (sockfd < 0) 
        error("ERROR opening socket");

    /* essendo le strutture dati allocata sullo stack sono state riempiti di valori casuali. Dobbiamo ripulire quella zona di memoria*/
     bzero((char *) &serv_addr, sizeof(serv_addr)); // bzero simile a memset
     portno = atoi(argv[1]); // prendiamo la porta come parametro 


     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY; // accetto connessioni da qualunque nodo (INADDR_LOCAL per localhost)

     /* vista l'eterogeneità della rete dobbiamo usare queste macro htons (host to network) o nstoh (network to host) per convertire il dato dal formato nativo del processore
        al formato nativo della rete (big indian to little indian)*/
     serv_addr.sin_port = htons(portno);

     /* faccio binding*/
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");

     /* preparo il socket per una nuova connessione*/         
     listen(sockfd,5);
     clilen = sizeof(cli_addr); // per capire chi è il client connesso

    /* rimango in ascolto */
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");


     bzero(buffer,256);
    /* leggo dal buffer*/
     n = read(newsockfd,buffer,255);
     if (n < 0) error("ERROR reading from socket");
     
     printf("Here is the message: %s\n",buffer);
     /* rispondo al client*/
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     
     return 0; 
}
