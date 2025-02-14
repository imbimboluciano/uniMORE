Il livello trasporto estende il servizio di consegna con impegno proprio del protocollo IP tra due host terminali ad un servizio di consegna a due processi applicativi in esecuzione sugli host. Aggiunge alcune servizi rispetto al protocollo IP:
- multiplazione (creazione dei segmenti provenienti dai messaggi di diversi processi applicativi) e demultiplazione (unica comunicazione che viene smistata su più processi) dei messaggi tra processi  
- rilevamento dell’errore sull'intera comunicazione (non correzione)

I principali protocolli di trasporto sono l'[[UDP]] e il [[TCP]], entrambi implementati nel kernel del sistema operativo. UDP e TCP attuano la multiplazione e la demultiplazione includendo due campi speciali nell’header del segmento:  
- il numero di porta del mittente  
- il numero di porta del destinatario
Il numero di porta è un numero di 16 bit (0-65535) che permette di identificare in modo univoco un processo applicativo residente su un nodo terminale di una comunicazione.
![[transportlayer.png]]

I numeri di porta sono divisi in categorie:
- **0-1023 → Well Known Ports**: sono riservati per protocolli applicativi noti ed non devono essere usate senza una precedente autorizzazione da IANA
	- HTTP: numero di porta 80 
	- SMTP: numero di porta 25  
	- DNS: numero di porta 53
- **1024-49151 → Registered Ports**: possono essere usate da qualsiasi processo
- **49152-65535 → Dynamic or Private Ports**

Due processi client, residenti su host diversi per comunicare con lo stesso servizio applicativo sono sempre distinti in base al loro indirizzo IP (sorgente) e possono essere distinti in base al numero di porta sorgente (scelta casualmente tra le porte libere). Inoltre due processi client, residenti sullo stesso host per comunicare con  lo stesso servizio applicativo, non essendo distinti in base al loro indirizzo IP, useranno diversi numeri di porta sorgente (SP) grazie al sistema operativo.
![[numberporte.png]]

L’insieme di dati che il livello trasporto chiede di trasferire al livello IP è detto segmento.

