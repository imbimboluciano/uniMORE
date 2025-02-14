Le socket sono l'astrazione attraverso cui l'applicazione può accedere ai protocolli [[TCP]], [[UDP]]. Sono delle Application Programming Interface (API) che consentono ai programmatori di gestire le comunicazioni tra processi ma differenza degli altri costrutti di comunicazione (pipe, code di messaggi e memoria condivisa), i socket  consentono la comunicazione tra processi che possono risiedere su host diversi, e dunque costituiscono lo strumento di base per realizzare servizi di rete. In pratica, consentono ad un programmatore di effettuare trasmissioni TCP e UDP senza curarsi dei dettagli “di più basso livello” che sono uguali per ogni comunicazione. Vediamo i principali tool e comandi che mettono a disposizione queste API:

1. **Socket statistics** (ss) è una delle applicazioni che permette di visualizzare e analizzare le socket utilizzate dal sistema 
```powershell
$ ss -t → mostra connessioni TCP  
	 -u → mostra connessioni UDP  
	 -e → mostra informazioni aggiuntive  
	 -l → mostra le socket in stato “listen”  
	 -a → mostra le socket in qualsiasi stato esse siano  
	 -n → non effettua la risoluzione DNS degli indirizzi  
	 -p → mostra il programma associato alla connessione
```

2. **Netcat** (nc) è un comando che permette di scambiare messaggi arbitrari impiegando i protocolli TCP e UDP.
```powershell
$ nc [-options] <hostname> <port> #client
$ nc [-options] -l -p <port> #server
``` 
   Netcat é molto utilizzato per inviare file tramite la rete
```powershell
$ nc -l -p <port> > <new_filename>  #server in ascolto
$ nc <ip-B> <port> < <filename> #client invia il file
``` 

Le fasi della comunicazione tra due host con l'utilizzo delle socket:
1. Dichiarazione al sistema operativo che si intende instaurare una connessione con specifica delle caratteristiche
2. Apertura della connessione (differente dal lato server rispetto al lato client)
	- Il server apre la connessione prime del client e rimane in attesa su una porta specificata
	- Il client assume che il server sia già attivo e prova a connettersi specificando indirizzo e porta del server
3. Scambio di dati bidirezionale (trasmissione e ricezione)
4. Chiusura della connessione