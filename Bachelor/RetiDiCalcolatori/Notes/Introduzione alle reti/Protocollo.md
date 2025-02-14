Con protocollo intediamo un insieme di regole e convenzioni seguite da entità, dislocate su nodi distinti, che intendono comunicare per svolgere un compito comune e che definiscono semantica (significato dei comandi), sintassi (struttura dei comandi) e temporizzazione (specifica delle sequenze temporali di emissione dei comandi).

Tali regole hanno l’obiettivo di assicurare una cooperazione efficiente ed affidabile per la  
comunicazione tra nodi e per la realizzazione di servizi di rete, tenendo conto delle caratteristiche tipiche di un sistema distribuito.

Come abbiamo visto un sistema complesso è formato da diversi livelli e quindi necessita di un insieme di protocolli che cooperano tra loro. Questi i protocolli costituiscono i blocchi fondamentali del modello architetturale di rete basato su livelli (layering). L’insieme dei protocolli di questo modello viene chiamato [[#Stack di protocolli]]. 

### Stack di protocolli
Ciascun protocollo, ad un certo livello, ha due service interface (interfaccia interne) per comunicare con il livello superiore ed inferiore (riceve e offre servizi) e una peer-to-peer interface (interfaccia esterna) per comunicare con il livello equivalente di un altro nodo.
![[interfaceprotocollo.png]]

La comunicazione avviene logicamente tra peer, ma in realtà attraversa tutti i livelli sottostanti mediante l’incapsulamento del messaggio a ciascun livello.
1. Lato mittente ogni livello N aggiunge il proprio header dal pacchetto ricevuto dal livello precedente N+1 ed invia il nuovo pacchetto al livello successivo N-1![[comunicazionelatomittente.png|400]]
2. L'ultimo livello instrada il messaggio sul mezzo di comunicazione ![[comunicazionemezzofisico.png|400]]
3. Lato destinatario ogni livello N riceve il pacchetto dal livello N - 1, estrae l'header di livello N e passa il messaggio al livello N + 1.         ![[comunicazionelatodestinatario.png|400]]

Il messaggio viene chiamato Protocol Data Unit (PDU) si compone di due parti:
-   Protocol Control Information (PCI) = header
-   Service Data Unit (SDU) = informazione (payload)![[pdu.png|500]]

La comunicazione, peró, avviene tra nodi basati su piattaforme hardware e/o software eterogenee; per questa diversitá abbiamo bisogno di un standard di comunicazione. 
Nell’ infrastruttura di rete convivono 2 modelli architetturali (stack di protocolli):
-   [[ISO-OSI]] (standard de iure)
-   [[TCP-IP]] (standard de facto)
