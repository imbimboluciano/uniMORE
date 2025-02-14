Tecnologia inventata a metà degli anni ’70 da Metcalfe che propone Ethernet nella sua tesi di PhD. 
![[Ethernet.png]]
L'Ethernet é formato principalmente da dei transceiver, cioé dei dispositivi attaccati al mezzo trasmissivo che raccolgono i dati(segnale) e li portano ad un'interfaccia.

La tecnologia Ethernet ha avuto un notevole successo fino a diventare standard de facto per una serie di motivazioni:
- Architettura molto facile -> poco costosa -> elevato interesse e notevole sviluppo
- Si adatta a diverse tipologie e tecnologie (tipicamente funziona a velocità relativamente basse)
Le principali caratteristiche dell'Ethernet sono le seguenti:
- Canale broadcast, tutti gli host collegati al canale ricevono i messaggi e quindi all'interno del frame dobbiamo inserire dei campi per identificare gli interlocutori
- Modalità di trasmissione broadcast 

Per identificare gli interlocutori e rendere univoca la trasmissione abbiamo bisogno di uno schema di indirizzamento. Introduciamo quindi l'Indirizzo Hardware o indirizzo **MAC** (Media Access Control) contenuto nel NIC dell'host (non è posseduto direttamente dall'host) e con le seguenti caratteristiche:
1. Indirizzo univoco e permanente a 48 bit (é incorporato nella ROM al momento della fabbricazione)
2. Indirizzi assegnati ai produttori della NIC da una autorità centrale (IEEE)
3. Indirizzo diviso in due parti:
	1. 24 bit identificatore del produttore 
	2. 24 bit identificatore della scheda di rete

Quando un host vuole trasmettere un pacchetto, vi inserisce l’indirizzo MAC del  
destinatario e lo immette nella LAN (broadcast). Se l’indirizzo di destinazione del pacchetto corrisponde all’indirizzo MAC dell’host ricevente, l’host accetta il pacchetto e lo passa verso l’alto nella pila protocollare; invece se l’indirizzo di destinazione non corrisponde all’indirizzo MAC dell’host ricevente, l’host scarta il pacchetto. (FF-FF-FF-FF-FF-FF indirizzo di broadcast).


### Frame Ethernet 
Indipendentemente dalla topologia, dai mezzi trasmissivi e dalla velocità di  
trasmissione, tutte le tecnologie Ethernet fanno uso dello stesso formato per il  
frame che trasmettono: 
- Preambolo (8 byte), serve per “attivare” gli adattatori dei riceventi e sincronizzare i loro orologi con quello del mittente
- Indirizzo MAC destinatario (6 byte)
- Indirizzo MAC mittente (6 byte)
- Tipo (2 byte), permette a Ethernet di multiplexare i protocolli dello strato di rete (scegliere tra i vari protocolli Internet IPv4, IPv6, AppleTalk)
- Payload o Dati (min 46 - max 1500 byte altrimenti frammentazione)
- CRC (Controllo a Ridondanza Ciclica), permette all’adattatore che riceve i dati di rilevare la presenza di un errore nei bit del frame ricevuto (escluso preambolo)


