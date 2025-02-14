Una rete, in generale, è definita come un insieme di nodi (host, switch) e di collegamenti/link (wireless, bluetooth, fibra, cavo coassiale).

![[rete.png]]

In base alle dimensione della rete e dal numero di nodi le reti si classificano nel seguente modo:
- LAN (Local Area Network), rete di host collegati tra loro all’interno di un’area fisica limitata che non superi la distanza di qualche chilometro
- MAN (Metropolitan Area Network)
- WAN (Wide Area Network)

La connessione tra i vari nodi della rete può essere di 2 tipi:
- connessione diretta: point-to-point o accesso multiplo
- connessione indiretta: commutazione (switched)

Come avviene la comunicazione tra due host o nodi della rete?
Nella comunicazione e nella trasmissione di un messaggio tra due o più host dobbiamo garantire sicurezza, qualità, affidabilità e prestazioni. Può sembrare un problema banale ma dobbiamo ricordare la quantità di dati e di utenti connessi alla rete che rendono il problema molto complesso e di elevate dimesioni (guasti, congestione, ritardo, problemi software). Per risolvere questo “problemone” dobbiamo scomporlo in piccoli sottoproblemi più facili e più piccoli; in questo caso scomponiamo in livelli e definiamo un’astrazione per ogni livello:
- Programmi applicativi e servizi di rete
- Canale di comunicazione (flusso di messaggi o richiesta/risposta)
- Connessione host-to-host
- Mezzo fisico di trasmissione

Più scendiamo di livello e più il problema passa da software (informatica) ad hardware (telecomunicazioni).
![[livellicomunicazione.png]]

La comunicazione tra entità richiede cooperazione,ossia collaborazione per il conseguimento di uno scopo comune. Tutte le comunicazioni devono essere regolate mediante una serie di regole comuni chiamate [[Protocollo]].