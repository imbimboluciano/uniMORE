Il Transmission Control Protocol è un protocollo che fornisce un livello di  
trasporto affidabile ed orientato alla connessione:
- [[#Orientato alla connessione]], cioè viene creata una connessione tra i due host prima del trasferimento di qualunque dato tra le applicazioni. La connessione introduce del ritardo, caratteristica incompatibile con applicazioni real-time. Le fasi di un connessione sono le seguenti:
	1. Instaurazione
	2. Utilizzo
	3. Chiusura
- Orientato al flusso di dati, cioè considera il flusso di dati dall’host mittente fino al destinatario con byte come unità di trasmissione
- Connessione full duplex (piggybacking)
- [[#Trasferimento affidabile]], cioè TCP gestisce un trasferimento ordinato di uno stream di dati con l'utilizzo di acknowledgment, time-out e ritrasmissione.
- [[#Trasferimento con buffer]], cioé i dati sono memorizzati in un buffer e poi inseriti in un pacchetto quando il buffer è pieno. Un buffer consente, infatti, di ovviare ad asincronia dell’invio dati da parte del processo applicativo, tempi di trasmissione differenti, capacità di invio e di ricezione differenti , segmenti persi o fuori ordine.
	- [[Controllo di flusso]]: l’host mittente non deve sovraccaricare l’host ricevente
	- [[Controllo di congestione]]: l’host mittente deve diminuire il tasso di trasmissione dei pacchetti quando la rete è congestionata
	- [[Buffer bloating]]

Il segmento TCP contiene:  
- Payload: dati del byte stream  
- Header
	- source port (16 bit): numero di porta del mittente 
	- destination port (16 bit): numero di porta del destinatario  
	- sequence number (32 bit): numero di sequenza relativo al flusso di byte che si sta trasmettendo  
	- acknowledgement number (32 bit): ACK relativo ad un numero di sequenza del flusso di byte che si sta ricevendo 
	- hlen (4 bit): lunghezza dell’header TCP (in multipli di 32 bit) se non vi sono opzioni, di norma hlen = 20 byte  
	- reserved (6 bit): per usi futuri 
	- code bit (6 bit): flag che specificano scopo e contenuto del segmento  
		-  URG (urgent): dati segnati come urgenti dal livello applicativo  
		- ACK (acknowledgement): valore del campo acknowledgement è valido  
		- PSH (push): il destinatario deve passare i dati all’applicazione immediatamente senza passare per il buffer
		- SYN (synchronize), FIN, RST (reset): usati per instaurazione, chiusura ed  interruzione della connessione
	- window size (16 bit): dimensione della finestra in ricezione (indica il numero di byte che si è disposti ad accettare in ricezione). Grazie a questo campo possiamo regolare il flusso di dati del mittente. 
	- checksum (16 bit): controllo integrità dei dati trasportati nel segmento TCP (utilizza lo pseudo-header come il protocollo [[UDP]])  
	- urgent pointer (16 bit): puntatore al termine dei dati urgenti (utilizzato  raramente, nel caso di trasmissione di caratteri speciali)  
	- TCP options: campo opzionale di lunghezza variabile che serve a negoziare la  dimensione del segmento massimo scambiato (MSS), utile nello sfruttare al meglio la banda ed evitare la frammentazione. (Default MSS = 536 byte)
		- MSS troppo piccolo → overhead eccessivo dovuto agli header  
		- MSS troppo grande → elevati rischi di frammentazione 
	- zero padding: per header con lunghezza multipla di 32 bit.
![[segmentoTCP.png | center | 550]]

## Orientato alla connessione
L'instaurazione della connessione nel TCP é basato sul modello client/server.
- Il client richiede una connessione inviando un segmento TCP speciale, detto “SYN” segment (synchronize) al server, specificando la porta del server. Il segmento SYN del client include:
	- Initial Sequence Number (ISN) del client: numero di 32 bit scelto in modo pseudo-casuale (con un numero fisso potremmo avere una probabilitá molto alta di malfunzionamenti a causa di possibili collisioni). Se il numero iniziale è 2032 e ci sono da spedire 5000 byte, tutti i byte saranno numerati da 2032 a 7031.
	- Maximum Receive Window (MRW) del client: il massimo numero di byte che il  client è in grado di ricevere nel suo buffer, necessario per la regolazione del flusso dello stream di byte
	- Maximum Segment Size (MSS): la massima dimensione del segmento
	- NO payload
- Per accettare la connessione, il server deve essere già in attesa di ricevere connessioni (processo "daemon"). Il segmento SYN del server include:  
	- Initial Sequence Number (ISN) del server
	-  ACK del server: client_ISN+1  
	- Maximum Receive Window (MRW) del server 
	- Maximum Segment Size (MSS): la massima dimensione del segmento 
	- NO payload 

Il trasferimento dati tra host end-to-end  avviene in 3 fasi:
1. Handshaking: fase di setup (con trasferimento di 3 segmenti) in cui ci si prepara al trasferimento dei dati. L'instaurazione della connessione avviene con la procedura di **three-way handshaking** (3 volte handshaking):
	1. Il client invia al server un segmento di controllo con SYN=1, e specifica nello  stesso segmento il proprio numero iniziale di sequenza
	2. Se accetta la connessione, il server invia un segmento di controllo con SYN=1, ACK=client_isn+1 ed il proprio numero iniziale di sequenza
	3. Il client segnala la definitiva apertura della connessione inviando un segmento di controllo con SYN=0, ACK=server_isn+1, e numero di sequenza client_isn +1![[3wayhandshaking.png]]
2. Trasmissione: fase di trasmissione (bidirezionale) di uno o più segmenti  
3. Chiusura connessione, la quale puó avvenire sostanzialmente in 2 modi:
	- Chiusura polite
		1. Il client invia un segmento di controllo con bit FIN=1 al server
		2. Il server riceve FIN ed invia ACK
		3. ll server chiude la connessione lato client-server ed invia FIN=1 al client
		4. Il client riceve il segmento con FIN=1 ed invia ACK al server che peró ha giá chiuso la connessione; quindi il client attende il timeout dell’ACK  inviato (per evitare situazioni anomale) ed allo scadere anche la connessione lato server-client viene chiusa ![[politeclosed.png]]
	- Chiusura reset, per interrompere la connessione in modo “brusco”, o dal lato server (tipicamente, per errori o sovraccarico) o dal lato client (tipicamente, in seguito a azione dell’utente):
		1. L’host che decide il reset pone il campo del segmento RST=1
		2. L’altro nodo chiude immediatamente la connessione e vengono rilasciate tutte le risorse utilizzate dalla connessione ![[resetclosed.png]]

![[FSMTCP.png]]



## Trasferimento affidabile
Per garantire una trasmissione affidabile il TCP utilizza le tecniche di acknowledgement, ritrasmissione e time-out (stop-and-wait)
1. Il destinatario, quando riceve i dati, invia un acknowledgement (ACK) al mittente, che attende di ricevere un ACK prima di inviare il segmento successivo.
2. Se il mittente non ha ricevuto ACK di un segmento dopo un certo periodo (timeout), ritrasmette il segmento
![[stopandwait.png]]

Adesso la domanda che ci poniamo é come possiamo stimare il time-out? Se il timeout é troppo breve, si effettuano ritrasmissioni non necessarie; mentre invece se il timeout é troppo lungo avremo una reazione lenta alla perdita di segmenti. L'unica certezza che abbiamo é che il timeout deve essere maggiore del Round Trip Time (RTT), cioé il tempo che intercorre tra l'invio di un segnale e la ricezione della conferma di arrivo dello stesso. Il RTT, peró, é soggetto a variazioni continue che dipendo dalle condizioni di traffico della rete e quindi per effettuare la stima dobbiamo utilizzare metodi analitici:
- Timeout = beta * RTTmedio (old, ormai poco utilizzato)
- **SampleRTT**, misura del tempo trascorso dalla trasmissione del segmento alla ricezione del suo ACK, ignorando ritrasmissioni e segmenti con ack cumulativi.
- **EstimatedRTT**, media pesata del SampleRTT (Exponential Weighted Moving Average). 
```math
            EstRTT(t) = (1-x)*EstRTT(t-1) + x*SampRTT(t)
```

![[RTT.png]]

Tra il RTT stimato e quello campionato c'é una sostanziosa differenza dettata dal rumore durante la trasmissione. Quindi infine per la scelta del valore di timeout viene utilizzato il RTT stimato con l'aggiunta di una stima dell'errore (deviazione standard).          
```math
		           Timeout(t) = EstRTT(t) + 4*Dev(t)
```



## Trasferimento con buffer
Il livello TCP deve tener conto di tutti gli eventi che si verificano in modo asincrono perché non sa quando il processo applicativo deciderà di spedire ed accettare i dati.
Quindi l’unica possibilità è inserire temporaneamente i dati ricevuti in un buffer, in modo da poterli ricevere/trasmettere dal/al livello applicativo quando vengono inviati/richiesti.
Il meccanismo di trasporto stop-and-wait è estremamente affidabile e semplice da  
implementare ma utilizza le risorse di rete e degli host in modo non efficiente.
![[performances&w.png]]
Dall'esempio notiamo che si riesce a trasmettere ~1 KB ogni 30 msec , cioé ~264 Kbit ogni secondo, su un link da 1 Gbps. Questo esempio é un'evidenza dell’uso limitato delle risorse fisiche di rete nel protocolo stop-and-wait.
Per combinare affidabilitá ed efficienza con l'utilizzo di un buffer utilizziamo la tecnica di pipelining, cioé il mittente invia un numero multiplo di segmenti prima di ricevere un ACK.
![[performancepipeline.png]]

Per implementare il pipelining abbiamo bisogno dei seguenti elementi:
- L’intervallo dei numeri di sequenza dei pacchetti e degli ack deve essere sufficientemente lungo  
- Necessità di un buffer lato mittente, per mantenere i pacchetti inviati e di cui non ha ancora ricevuto l’ack  
- Necessità di un buffer lato destinatario, per mantenere le sequenze di pacchetti
- Necessità di una “finestra a scorrimento”([[Sliding window]]) che denota il numero massimo di pacchetti che il mittente può inviare senza aver ricevuto un ACK dal destinatario