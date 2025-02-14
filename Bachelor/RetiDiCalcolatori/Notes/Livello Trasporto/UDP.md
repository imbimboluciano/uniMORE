User Data Protocol (UDP) è un protocollo di trasporto leggero, ovvero dotato delle funzionalità minime del trasporto:
- multiplazione e demultiplazione
- controllo dell'errore
- servizio di consegna best-effort (i segmenti UDP possono essere persi,  duplicati, consegnati senza ordine)
- servizio senza connessione (connectionless)

Il segmento UDP è formato dal payload e dall'header UDP, il quale contiene informazioni minime:
- numero di porta del mittente (16 bit)  
- numero di porta del destinatario (16 bit)  
- lunghezza (16 bit) del segmento (header + payload)
- checksum
![[UDP.png]]

Per il calcolo del checksum, l'UDP propone uno pseudo-header (usato anche nel [[TCP]]) all'UDP datagram formato dai seguenti parametri:
- IP mittente
- IP destinatario
- zero padding: dimensione dello pseudo-header (multiplo di 32 bit)  
- protocollo: campo protocollo del datagram IP
- lunghezza segmento UDP

Lo pseudo-header viene utilizzato solo per il calcolo del checksum, non viene inviato, né la sua presenza influenza il campo lunghezza nell'header UDP. Lo scopo dello pseudo-header è quello di verificare che l'UDP datagram abbia raggiunto la corretta destinazione, ovvero una specifica macchina e una specifica porta all'interno di quella macchina.  Alla destinazione, il destinatario deve ricostruire lo pseudo-header estraendo l'indirizzo IP destinazione e deve ricalcolare il checksum (con complemento a 1 della somma di tutti i campi dello pseudo-header).