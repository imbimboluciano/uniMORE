Il procollo IP (Internet Protocol) é il protocollo di Livello Internet che si occupa di definire l'unitá di trasferimento dati ([[#Datagram IP]]), di definire un indirizzamento univoco degli host ([[#Indirizzi IP]]) e di determinare le funzioni di routing ([[Routing]]).

La caratteristica principale dei servizi basati sul protocollo IP é quella che la consegna dei pacchetti non é affidabile:
- Consegna priva di connessione: ogni pacchetto è trattato in modo indipendente da tutti gli altri (i pacchetti possono seguire percorsi diversi anche avendo lo stesso destinatario)
- Consegna con impegno (best effort)
- Consegna non garantita: i pacchetti possono essere persi, duplicati, ritardati, o consegnati senza ordine



### Datagram IP
Il **datagram**, unitá di trasferimento dati, é formato da 2 principali parti:
- Header 
	- VERS: versione del protocollo IP usata per creare il datagram (4 bit)
	- HLEN: lunghezza dell’header del datagram (in parole di 32 bit)
	- TOTAL LENGTH: lunghezza del datagram IP (max dimensione = 65536 byte = 64 Kbyte)
	- TYPE OF SERVICE (TOS): specifica come si richiede che sia trattato il datagram
		- **Pre RFC3168**
			- PRECEDENCE: specifica l’importanza del datagram
			- FLAG per il tipo di trasporto desiderato
				- D (delay): basso ritardo  
				- T (throughput): alto throughput 
				- R (reliability): alta affidabilità
		![[tos2.png | center]]
		- **Post RFC3168**
			- DS (DiffServ): usano un class selector per specificare la prioritá del traffico (best effort, priority, immediate) (6 bit)
			- ECN (Explicit Congestion Notification) (2 bit) per notificare una congestione
		![[tos1.png | center]]
	- IDENTIFICATION: intero che identifica il datagram
	- FLAGS: controllo della frammentazione
		- Reserved (=0)  
		- DF: don’t fragment  (in caso di frammentazione il pacchetto viene scartato e viene segnalato l'errore)
		- MF: more fragments (in caso di frammentazione questo flag é settato ad 1 in tutti i frammenti, tranne nell'ultimo per identificare la fine della trasmissione)
	- FRAGMENT OFFSET: la posizione del frammento nel datagram originale
	- TIME TO LIVE: Indica per quanto tempo il datagram può circolare in Internet.   Decrementato da ciascun router che  gestisce il datagram: quando diviene uguale a 0, è eliminato dal router corrispondente per evitare ciclo (contatore intero non temporale).
	- PROTOCOL: indica quale protocollo di livello superiore può utilizzare i dati contenuti nel datagram (simile al campo type dell'Ethernet)
	- HEADER CHECKSUM: serve per controllare l’integrità dei dati trasportati nell’header
	- SOURCE IP ADDRESS: indirizzo IP (32 bit) del mittente del datagram
	- DESTINATION IP ADDRESS: indirizzo IP (32 bit) del destinatario del datagram
	- IP OPTIONS: Campo opzionale di lunghezza variabile (per testing e debugging della rete)
	- PADDING: campio opzionale presente solo se IP options denota una lunghezza variabile
- Payload (dati)

![[datagramIP.png | center | 600]]

Per la gestione della frammentazione e la ricostruzione del datagram vengono utilizzati i campi IDENTIFICATION, FLAGS e FRAGMENT OFFSET. Bisogna, peró, fare molta attenzione con questa pratica perché una frammentazione troppo elevata puó aumentare la probabilitá di errore e di conseguenza aumentare congestione e ritardo; questo perché un numero elevato di datagram potrebbero riempire facilmente e velocemente il buffer del destinatario, cioé colui che ricostruisce il datagram. Perché é il destinatario che ricostruisce il datagram? Perché é l'unico che riceve tutti i frammenti, i quali possono seguire percorsi diversi. 



### Indirizzi IP
Per fornire un servizio di comunicazione universale occorre un metodo che permetta di identificare univocamente ogni nodo. Ad ogni nodo è assegnato un unico indirizzo Internet (indirizzo IP) formato da 32 bit (circa 4,3 miliardi di indirizzi diversi)  e suddiviso in 4 campi, ciascuno formato da un byte e separato da un punto dagli altri campi (**dotted notation**) (Es. 192.168.1.2). 

Ogni indirizzo IP è strutturato in una coppia:  <netid, hostid> dove netid (o prefisso di rete) identifica la rete e hostid identifica un host di quella rete. 

La lunghezza dell'indirizzo IP é fissa (per avere minori costi nella gestione dei pacchetti) e lo spazio di indirizzamento é gestito in modo gerarchico. Infatti la rete [[Internet]] é formata da una serie di reti connesse tra loro in modo gerarchico:
- Backbone (Internet Service Provider di livello globale)
- Regional (Internet Service Provider di livello nazionale)
- LAN
![[backbone.png]]

Per questo motivo gli indirizzi IP sono stati suddivisi in diverse classi da assegnare ai diversi soggetti della gerarchia (classe A assegnata alle big company). Inoltre le zone geograficamente vicine vengono poste per comoditá all'interno della stessa classe.
![[classeIP.png]]
Nonostante la divisione in classe, tutti questi indirizzi IP al giorno d'oggi sono esauriti. 

Ma chi assegna gli indirizzi IP? Inizialmente il governo USA creò la Internet Assigned Numbers Authority (IANA), in pratica il gruppo di Jon Postel, per gestire le  assegnazioni di gruppi di indirizzi. Con la morte di Jon Postel venne fondata l'ICANN: Internet Corporation for Assigned Names and numbers originariamente legata al Department of Commerce ma dal 2016 completamente indipendente dal governo USA. Quindi i network ID, corrispondenti ad un insieme di indirizzi IP, vengono assegnati poche organizzazioni e agli Internet Service Provider da IANA/ICANN. Questi ISP globali gestiranno l'assegnazione per altri ISP nazionali (Fastweb, Vodafone) e per altre organizzazioni. A loro volta gli ISP nazionali gestiranno l'assegnazione per piccole organizzazioni e per le reti domestiche.  Infine gli host ID sono assegnati localmente a ciascun host dall’amministratore di rete dell'oganizzazione attraverso due modalitá:
- Configurazione manuale
- [[DHCP]]

Un indirizzo IP (detto host address), essendo un indirizzo logico e non fisico,  viene in realtà assegnato ad una interfaccia di rete e quindi possiamo avere piú host address su un unico host. A questo punto una domanda che sorge spontanea é "perchè non utilizzare solo gli indirizzi IP e rimuovere gli indirizzi MAC?". Ci sono due validi motivi per cui utilizzare solo indirizzi IP sarebbe sbagliato:
- Non potremmo supportare altri protocolli di reti diversi da IP
- Servirebbero troppi indirizzi IP per identifcare univocamente tutti i dispositivi di una rete (IPv4 vs [[IPv6]])

Tra gli indirizzi IP possiamo identificare alcuni indirizzi "speciali":
- **Network address**: Hostid con tutti i bit uguali a 0 che denota il netid (prefisso) assegnato ad una rete
- **Directed broadcast address**: Hostid con tutti i bit uguali a 1 che permette il broadcast a tutta una certa rete (non è un vero broadcast in quanto si fonda sulla tecnologia hardware sottostante per il broadcast)
- **Limited broadcast address**: Tutti i bit uguali a 1 (ossia 255.255.255.255) che permette il broadcast sulla rete fisica locale
- **This host on this network**: Tutti i bit uguali a 0 (ossia 0.0.0.0) viene usato per il boot dell’host  
- **Loopback address**: netid pari a 127 (es.127.0.0.1) usato per connessioni locali con TCP/IP (localhost)

Per motivi gestionali e di routing, in molti casi, può convenire definire degli “insiemi logici” di indirizzi più flessibili rispetto alla rigida suddivisione in 1, 2, 3 byte per il netid:
- [[Subnetting]]
- [[Supernetting]]

Essendoci una maggiora flessibilitá dobbiamo definire il limite tra host id e net id e per far ció definiamo i bit dedicati al netid con una network mask di 4 byte, la quale permette di individuare mediante AND logico con l'indirizzo IP la parte di un indirizzo IP riservata per il netid (la parte di 1) e la parte disponibile per l’hostid (la  
parte di 0).  Es. 11111111.11111111.11111111.11000000
