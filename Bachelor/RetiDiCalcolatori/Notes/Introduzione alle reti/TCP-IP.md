Modello alla base di [[Internet]] che riprende alcune caratteristiche del modello [[ISO-OSI]] ma rispetto a quest'ultimo é piú orientato alla realtá:
- nasce come implementazione pratica
- meno generale dell'ISO/OSI
- protocolli sviluppati ad hoc
- disponibilità di una buona implementazione dello stack in versione open source a metà degli anni ’80 su BSD Unix
- disponibilità di un buon insieme di API per sviluppare applicazioni di rete

Il modello TCP/IP, a differenza di quello OSI, é formato da "solo" 4 livelli:
- [[Livello Host-to-Network]] che accorpa le funzionalitá del livello fisico e data link dell'ISO/OSI (questo perché entrambe le funzioni sono gestite dalla schede di rete)
- [[Livello Internet]]
- [[Livello Trasporto]]
- [[Livello Applicazione]] che ingloba al suo interno anche le funzionalitá del livello di sessione e presentazione dell'ISO/OSI
![[TCPIP.png]]

Nonostante il successo, questo modello non é esente da criticità:
-  livelli host-to-host e network confusi ed interdipendenti
-  protocolli sviluppati ad hoc invece che protocolli generali (IPv4 vs IPv6)


### Stack TCP/IP
I principali protocolli dello stack sono i seguenti:
- Livello Applicativo: [[SMTP]], [[HTTP]], **FTP**, [[BGP]], [[SNMP]].
- Livello Trasporto: estende il servizio di consegna con impegno proprio del protocollo IP tra due host terminali ad un servizio di consegna a due processi applicativi in esecuzione sugli host (fornisce un meccanismo di multiplazione e demultiplazione tra processi e il rilevamento degli errori). I principali protocolli sono i seguenti:
	 - [[TCP]], protocollo che fornisce un livello di trasporto affidabile e orientato alla connessione (buffer e connessione full-duplex).
	 - [[UDP]], protocollo che fornisce un livello di trasporto dell’informazione connectionless.
- Livello Internet: [[IP]] (IPv4 e IPv6) protocollo che fornisce un identificativo univoco e una comunicazione logica tra host (non esiste il concetto di connessione, l’IP è assolutamente orientato al pacchetto e non affidabile).
- Livello Host-to-network: [[Ethernet]] (LAN), PPP (modem), **802.11** (wireless).
- Altri protocolli: [[ICMP]], [[OSPF]] (servizi di supporto che si appoggiano all’IP).

![[strutturaclessidra.png|550]]

![[stackTCP.png|550]]
