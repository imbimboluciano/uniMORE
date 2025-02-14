HyperText Trasmission Protocol (HTTP) è il protocollo applicatvo che permette il reperimento delle risorse [[Web]] attraverso un meccanismo di request/reply. HTTP è un protocollo stateless (ufficialmente non si basa su [[TCP]] ma a livello pratico si) quindi il server non conserva nessuna informazione riguardante le richieste dei client passati ed ogni richiesta é indipendente. Questa caratteristica permette di non avere problemi al riavvio del Web server (crash o failure).

Il protocollo definisce 2 tipi di messaggi:  
1. **Request HTTP**
	- Metodo, specifica il tipo di operazione che il client richiede al server.
		- GET, richiesta di un oggetto  
		- POST, il client richiede una pagina Web il cui contenuto è specificato dall'utente nel campo entity body 
		- HEAD, il client richiede che il server invii soltanto l'header
		- PUT, DELETE 
		- LINK e UNLINK, per rappresentare legami tra risorse (rimossi in HTTP 1.1)
		- TRACE, CONNECT e  OPTIONS, per aprire una connessione Http e incapsulare un altro protocollo
	- [[URL]], identificatore dell’oggetto richiesto
	- version, versione del protocollo HTTP
	- Insieme di extension header
		- Connection: tipo di connessione richiesta dal client
		- User-agent: browser utilizzato dall'utente
		- Accept: tipo di oggetti che il client accetta
		- Accept-language: preferenza della lingua
		- Accept-encoding, Accept-charset
		- Host: specifica host che ha la risorsa(HTTP 1.1)
		- Altri header per garantire la consistenza
	- Linea vuota per indicare la fine del messaggio delle informazioni
![[requestHTTP.png | center | 450]]
2. **Reply HTTP**
	- Version: versione del protocollo HTTP
	- Status code, phrase: esito della richiesta
		- 1xx: Informazioni  
		- 2xx: Successo  
		- 3xx: Redirezione  
		- 4xx: Errore del client  
		- 5xx: Errore del server![[statuscode.png | 550]]
	- Header
		- Connection: tipo di connessione usata dal server
		- Date: data e ora della richiesta
		- Server: tipo di Web server e di sistema operativo (molte volte rimossa per motivi di sicurezza)
		- Last-Modified: data e ora creazione o modifica dell'oggetto
		- Content-Length: dimensione in byte dell'oggetto
		- Content-Type: tipo di oggetto
	- Entity body: oggetto 
![[replyHTTP.png | center | 450]]


Possiamo utilizzare HTTP per accedere a risorse (tipicamente rappresentate con XML o JSON) , mappate su URL. Il supporto per manipolazione di dati generici viene chiamato API RESTful (Es. /api/v1/movies/star-wars-a-new-hope).

Essendo HTTP un protocollo stateless ogni oggetto viene trasferito usando una nuova connessione TCP creando problemi di congestione e controllo di flusso (3-way handshaking per ogni oggetto). Dalla versione 1.1 del protocollo sono state introdotte le connessione persistente, dove un numero multiplo di oggetti (ad es. tutti gli oggetti che compongono una pagina) vengono trasferiti entro una stessa connessione TCP; in questo modo il three-way handshake del TCP viene eseguito  solo per instaurare la connessione iniziale.



## Gestione richieste
La modalitá di gestione delle richieste HTTP da parte di un Web Server puó essere di 3 tipi:
- **Metodo fork** (processo padre e processi figli), poco efficiente a livello prestazionale (per ogni processo figlio bisogna fare la copia delle strutture dati e del processor descriptor)
- Metodo helper
- Metodo multithread
	- Puramente multithread (un processo molti thread), rischioso perché il crash del processo puó compromettere il funzionamento dell'intero web server
	- Molti processi con più thread per processo
	- Molti processi un thread per processo (poco prestazionale)
![[gestionerichieste.png | center | 600]]

Negli ultimi anni si é puntato sulla gestione delle richieste con un approccio event driven, in cui ogni azione necessaria al servizio della richiesta è definita come una funzione, che garantisce massime prestazioni senza compromessi.

Come molti protocolli anche HTTP fa uso di caching locale, con le risorse che vengono memorizzate sul disco del client dopo un download. Per permettere questo meccanismo dobbiamo validare la cache attraverso una richiesta HTTP condizionale, per capire se la risorsa é stata modificate o eliminata:
- Se la risorsa in cache è aggiornata  -> Response 304 – Not modified
- Se la risorsa in cache non è più valida -> Response 200 – OK  + Corpo della risorsa

Inoltre il protocollo HTTP introduce i cookie, una tupla di 5 valori (nome,valore, TTL, dominio, path), per permettere al server di identificare il client, ricostruire la “sessione” per seguire le preferenze e la navigazione degli utenti e bilanciare il carico. ![[cookie.png | center | 400]]
