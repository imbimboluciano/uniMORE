Il livello H2N affronta le problematiche di interconnessione tra due o più host e di trasmissione dati tra host direttamente connessi.
Uno dei motivi principali per cui nello stack [[TCP-IP]] é stato definito un unico livello che accorpa le funzionalitá del livello Fisico e del livello Data Link del modello [[ISO-OSI]] é che modalità di interconnessione e protocolli per la trasmissione dati tra host interconnessi sono strettamente dipendenti tra loro (banalmente entrambe le funzioni sono svolte dalla scheda di rete). 

I possibili servizi offerti dal livello H2N (non presenti per forza tutti in tutte le tecnologie) sono i seguenti:
1. Livello Fisico
	- Connessione di host secondo diversi mezzi trasmissivi (doppino, cavo coassiale, fibra ottica)
2. Livello Data Link
	- Framing (incapsulamento in frame = PDU del livello H2N)  
	- Accesso al mezzo trasmissivo
	- Recapito affidabile (ack e ritrasmissione)  
	- Controllo di flusso 
	- Ricerca di errori  
	- Correzione degli errori  
	- Half-duplex o Full-duplex(ADSL e Fibra Ottica)

Alcuni servizi, possono sembrare simili a quelli del livello di Trasporto e del livello Internet, ma ci sono delle sottili ma importanti differenze:
- A differenza del livello di trasporto che lavora end-to-end, il livello h2n opera a livello di singolo link
- A differenza del livello Internet che consegna pacchetti dovunque, il livello h2n lavora solo all' interno di una stessa LAN.
![[LAN.png]]


### Modalitá di interconnessione
Il collegamento puó avvenire tra diversi dispositivi:
1. host to host
2. host to router
3. router to router (il router lavora fino al livello 3)
Il collegamento tra questi dispositivi puó essere:
- **broadcast**, cioé molti host connessi ad uno stesso canale
- **punto-punto**, cioé c'é un unico trasmettente ed unico ricevente (tipico del router to router)

### Modalitá di trasmissione
Le modalitá con cui si trasmettono i dati sulla rete possono essere di diversa tipologia:
- **Unicast**: singolo mittente e singoli ricevente (1-1)
- **Multicast**: singolo mittente e gruppo di destinatari (1-N)
- **Anycast**: singoli mittente e almeno un destinatario in un gruppo
- **Broadcast**: singoli mittente a tutti gli altri nodi (1-M)


Come giá detto, il protocollo H2N è implementato nella scheda di rete (NIC o Interface Card), dspositivo generalmente costituito da una RAM, un DSP (Digital Signal Processor), un’interfaccia bus/host e un’interfaccia di collegamento alla rete (RJ45). ![[NIC.png]]

Come giá detto, il livello H2N lavora a livello di rete locale (LAN). Le principali tecnologie a livello H2N per interconnettere due o piú host sono le seguenti:
- [[Ethernet]] (standard de facto)
- Token Ring
- WLAN (Wireless LAN)

Una domanda che sorge spontanea é "Perché non creare un’unica grande LAN  
quando vi sono da interconnettere molti host?". Le motivazioni per cui non é possibile realizzare un'unica rete LAN sono molteplici:
- Sarebbe possibile supportare una quantità limitata di traffico
- Unico grande “dominio di collisione” (ciascun host può collidere con molti host)
- Limiti fisici (lunghezza cavo)
Per questi motivi le reti locali LAN devono rimanere di piccole dimensioni.

Per interconnettere i vari dispositivi all'interno di una rete locale LAN possiamo utilizzare diversi apparati di rete:
- [[Hub]]
- [[Bridge]]
- [[Switch]]
- Managed Switch per [[Virtual LAN]] (lavorano fino al livello 3)







