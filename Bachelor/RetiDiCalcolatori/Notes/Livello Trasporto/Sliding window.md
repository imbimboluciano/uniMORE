La finestra rappresenta i byte che il [[#Destinatario]] si dichiara disposto a ricevere dal [[#Mittente]] oltre il segnale di riconferma ACK. Viene definita scorrevole in quanto si sposta in blocco partendo sempre dall'ultimo byte e non è di dimensione costante, ma può variare durante la trasmissione per controllare il flusso dei dati inviati dal mittente. 


#### Mittente
Il mittente mantiene una finestra scorrevole sugli indici dei segmenti, e solo quelli all’interno della finestra possono essere trasmessi. Per gestire la sliding window (finestra scorrevole), il mittente utilizza tre variabili:
1. Dimensione della finestra di invio SWS (Sender Window Size): indica il limite  superiore per il numero di segmenti che il mittente può inviare senza aver ricevuto un ACK  
2. Numero di sequenza dell’ultima conferma ricevuta LAR (Last Acknowledgement  Received)  
3. Numero di sequenza dell’ultimo segmento inviato LSS (Last Segment Sent)
Le tre variabili soddisfano la seguente relazione
```math
				          LSS - LAR <= SWS
```
![[sws.png]]
Quando arriva un ACK, il mittente sposta LAR verso destra, consentendo così l’invio di un altro segmento. Inoltre, il mittente associa un time-out a ciascun segmento che trasmette, con conseguente ritrasmissione del segmento,  se il time-out scade prima di aver ricevuto il relativo ACK.


#### Destinatario
Ad ogni istante, il destinatario mantiene una finestra scorrevole sugli indici dei segmenti ricevuti. Per gestire la sliding window anche il destinatario utilizza tre variabili: 
1. Dimensione della finestra di ricezione RWS (Receive Windows Size): indica il limite superiore per il numero di segmenti “fuori sequenza” che il destinatario può accettare  
2. Numero di sequenza del segmento accettabile più elevato LAS (Largest  Acceptable Segment)  
3. Numero di sequenza dell’ultimo segmento ricevuto “in sequenza” LSR (Last Segment Received)
Le tre variabili soddisfano la seguente relazione
```math
				          LAS - LSR <= RWS
```
![[rws.png]]
Quando arriva un segmento con numero di sequenza Num_segm, il destinatario agisce come segue:  
- Se Num_seg <= LSR oppure Num_segm > LAS, significa che il segmento si trova al di fuori della finestra del destinatario e viene scartato 
- Se LSR < Num_segm <= LAS , il segmento si trova all’interno della finestra del destinatario e viene inserito nel buffer



Cosa succede in caso di errori durante la trasmissione? Vi sono due “filosofie” alternative per affrontare il problema dell’affidabilità della comunicazione nel caso di un protocollo con pipelining:  
- [[#Go-Back-N ]]
- [[#Ritrasmissione selettiva]]


## Go-Back-N
Lato mittente abbiamo una finestra (window size) di max N segmenti consecutivi, inviabili senza ACK, ognuno con un proprio timeout. In caso di scadenza del timeout il mittente deve ritrasmettere il segmento corrispondente e tutti i segmenti che hanno un numero di sequenza superiore.
Lato destinatario vengono utilizzati dei “ACK cumulativi” da parte del destinatario, infatti ACK(n) conferma che sono arrivati correttamente i primi n segmenti ed i segmenti che arrivano fuori sequenza vengono scartati senza essere inseriti nel buffer. Per questo motivo il buffer serve solo per gestire l’asincronia tra l’arrivo dei dati a livello di TCP e il loro consumo da parte del processo applicativo del destinatario

![[gobackn.png]]



## Ritrasmissione selettiva
Mittente e destinatario gestiscono due finestre di sequenze di N segmenti  consecutivi:
- La finestra del destinatario avanza di 1 quando il  segmento “base_destinatario” è ricevuto correttamente
- La finestra del mittente avanza di 1 quando riceve un ACK entro il timeout sul segmento “base_mittente”

Il destinatario invia ACK di tutti i segmenti ricevuti correttamente (bufferizzazione dei pacchetti) mentre il mittente ritrasmette soltanto i segmenti per i quali non ha ricevuto ACK dal destinatario entro il time-out (timeout per ciascun pacchetto)

![[ritrasmissioneselettiva.png]]



Sebbene sia stata proposta una modifica al protocollo [[TCP]] per andare verso un meccanismo di ritrasmissione selettiva, attualmente il TCP non segue nessuna delle due versioni in modo puro, in quanto utilizza le seguenti componenti:
- “ACK cumulativi” da parte del destinatario
- Segmenti arrivati fuori ordine, vengono salvati nel buffer di ricezione

**Esempio**
Poniamo LSR=5, cioè l’ultimo ACK inviato dal destinatario è relativo al segmento 5, la RWS=4 (receiver window size) e quindi LAS=9. Se dovessero arrivare i segmenti 7 e 8,  verrebbero memorizzati nel buffer perché si trovano all’interno della finestra del destinatario, ma poiché non è arrivato ancora il segmento 6, a seconda dell’implementazione del TCP: 
- non verrebbe inviato alcun ACK oppure  
- verrebbe inviato nuovamente ACK(5)
Quando arriva il segmento 6, il  destinatario può inviare ACK(8), confermando la ricezione corretta di 6, 7 e 8 (cioè d=3), consentendo quindi di settare LFS=8 e LAS=12


L'utilizzo di questo algoritmo nel TCP porta alcuni benifici: 
1. Si evita la ritrasmissione di segmenti ricevuti correttamente che si verificava  nel caso di Go-Back-N  
2. Si sfruttano tutti gli ACK per comprendere che i segmenti sono stati ricevuti  correttamente e, quindi, in caso di  trasmissioni corrette, si velocizza  l’avanzamento della finestra di spedizione  
3. In caso di time-out, la quantità di dati trasmettibile diminuisce perché il mittente non è in grado di far avanzare la finestra ed il buffer risulta occupato da altri segmenti (necessità di comprendere problemi al più presto)
