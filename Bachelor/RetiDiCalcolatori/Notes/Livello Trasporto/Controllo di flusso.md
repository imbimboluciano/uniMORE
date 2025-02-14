L'obiettivo del controllo di flusso é che il mittente non deve riempire il buffer del destinatario inviando una quantità eccessiva di dati ad un tasso di trasmissione troppo elevato. Per questo scopo ogni segmento ACK informa il mittente di quanti byte sono stati ricevuti dal destinatario e quanti byte il destinatario può ancora  ricevere in quel momento (spazio nel buffer). Il mittente regola la sua finestra in base  alla disponibilità che gli è stata indicata dal destinatario. In caso la disponibilità sia pari a 0, la trasmissione si sospende e riprende solo quando il destinatario segnala di essere nuovamente in grado di ricevere byte.

Per gestire il controllo di flusso vengono intrdotte altre 2 metriche:
1. AdvertisedWindow: dimensione della finestra massima di ricezione comunicata  dal destinatario, cioé la quantità di spazio libero nel buffer di ricezione.
```math
	AdvertisedWindow = MaxRcvBuffer – ((NextByteExpected-1)-LastByteRead)
```
2. EffectiveWindow: il mittente calcola la finestra effettiva che limita la massima  quantità di dati che possono essere inviati
 ```math
	EffectiveWindow = AdvertisedWindow – (LastByteSent - LastByteAcked)
```

Il mittente può spedire dati solo se EffectiveWindow>0. In caso venga comunicata  
una AdvertisedWindow troppo piccola il mittente non potrá spedire altri dati; se la situazione persiste, può capitare che il buffer mittente si riempia ed il [[TCP]] deve  bloccare la generazione di nuovi dati da  parte del processo applicativo.
Invece in caso il mittente riceva una AdvertisedWindow=0, continua ad inviare  
periodicamente un segmento con 1 byte di dati questo perché il mittente non può conoscere se la finestra di ricezione è aumentata perché il destinatario non invia messaggi spontaneamente.

Che cosa succede se il ricevitore dà l’ACK appena ha un po’ di spazio libero (ad esempio un byte)? Il byte successivo verrà inviato subito riempendo nuovamente il buffer (**sindrome della finestra cattiva**). Per risolvere questa problematica possiamo attuare alcune contromisure:
- Il destinatario aspetta di avere svuotato almeno il 50% del “buffer” prima di inviare un ACK di restart  
- Il destinatario ritarda l’invio dell’ACK sistematicamente quando il buffer disponibile si riduce troppo (raccomandato dagli standard ma altera la stima di RTT)
- Il mittente aspetta di avere abbastanza dati per riempire un segmento di dimensione MSS; se però, mentre attende, arriva un ACK, invia comunque un segmento (più corto)

Un altro problema relativo al controllo di flusso é la gestione del timeout, infatti nel caso in cui il time-out sia troppo lungo, é possibile che si ritardi molto la necessaria ritrasmissione di un segmento, con conseguenti limitazioni a livello di buffer mittente e destinatario. Per questo motivo in alcune versioni di TCP si implementa un  meccanismo aggiuntivo per rilevare la perdita dei pacchetti prima che si verifichi un time-out: 
- **ACK duplicato**, quando il destinatario riceve segmenti fuori ordine, continua a spedire ACK relativi all’ultimo byte del segmento dati che ha ricevuto correttamente ed in sequenza ordinata. Quando il mittente riceverá molti ACK duplicati (triplo ACK)) ritrasmetterá subito il pacchetto perso.