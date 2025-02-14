La congestione é definita come un numero elevato di sorgenti che inviano contemporaneamente troppi dati generando un traffico che la rete (Internet) non è in grado di gestire. Gli effetti indesiderati della congestione sono la perdita di pachetti ed elevati ritardi. Per il controllo di congestione possiamo avere due approcci:
1. **Controllo di congestione assistito dalla rete**, i router forniscono un feedback esplicito ai nodi terminali riguardante lo stato di congestione nella rete (crea ulteriore traffico)
2. **Controllo di congestione end-to-end**, la situazione di congestione è determinata analizzando le perdite di pacchetti ed i ritardi nei nodi terminali (utilizzata nel TCP)
	- **AIMD**(Additive Increase - Multiplicative decrease), aumenta la window size linearmente per ACK arrivato entro timeout e diminuisce la window di un fattore moltiplicativo in caso di perdita.
	- **SLOW START**, all’inizio dell’utilizzo di una nuova connessione o in seguito a congestione di una connessione la dimensione della finestra è pari a 1; si prosegue poi con un incremento progressivo (esponenziale) della  dimensione della finestra. 

Per il controllo di congestione in [[TCP]] dobbiamo capire sempre qual é la banda disponibile e per far ció utilizziamo sempre il meccanismo di [[Sliding window]] definendo 2 finestre: 
- CongestionWindow (CW): dimensione della finestra di congestione  
- AdvertisedWindow (AW): dimensione della finestra di ricezione
La finestra effettiva utilizzata dal mittente sará data dal minimo tra le due finestre.
- stato stazionario (non di congestione): la dimensione della finestra è pari a quella  indicata dal ricevente per il controllo di flusso 
- stato di congestione: riduzione della dimensione della finestra (uguale a CW)
 ```math
					Advertised window* = min(AW, CW)
```
Inoltre dobbiamo definire il throughput per determinare il tasso di trasmissione 
 ```math
					throughput = (w * MSS) / RTT
```


Ora diamo un'occhiata agli algoritmi per il controllo di congestione utilizzati negli anni nel TCP.

### TCP Tahoe
Si incrementa esponenzialmente fino a threshold (valore della dimensione della finestra), raggiunto il quale la fase di incremento esponenziale termina e si raggiunge lo stato stazionario di incremento lineare) e poi si incrementa di 1. Tahoe si accorge che siamo entrati in congestione perché c'é stata una packet loss e quindi di conseguenza diminuisce la finestra ad 1 e rimodula la threshold. Tahoe non é piú utilizzato ![[tahoe.png | center | 350]]

### TCP Reno
Evoluzione del Tahoe che utilizza oltre al timeout anche la tecnica di ACK duplicati per capire che c'é congestione. Se si verifica un timeout riduce la window ad 1 ma in caso di ack duplicati non “esagera” come il Tahoe riducendo la window a 1, ma diminuisce la finestra riprendendo da threshold (**fast recovery**). Reno ormai risulta obsoleto![[reno.png | center | 400]]

### TCP Vegas
Rispetto a Reno utilizza un approccio proattivo invece che reattivo con un meccanismo di osservazione del RTT (legato alla banda disponibile). In questo modo si accorge molto presto della congestione (aumento continuo del RTT) e di conseguenza effettua una diminuzione lineare della frequenza di invio dei segmenti. La correllazione tra banda, RTT e throughput é evidenziata nella seguente figura ![[bandaRTT.png | center | 500]]
Vegas utilizza la seguente formula per individuare la congestione.
 ```math
		X = [WndSize(now) − WndSize(old)] / [RTT(now) − RTT(old)]
```
- Se X>0 all'aumento della congestion wnd corrisponde un aumento RTT e quindi c'é congestione e diminuiamo la congestion wnd di 1/8
- Se X≤0 non c'é congestione e quindi la finestra aumenta di 1 

Prima di evidenziare i problemi di TCP Vegas dobbiamo definire i concetti di fairness e friendlyness.
- **Fairness**, capacitá dati n flussi TCP sullo stesso link che utilizzano lo stesso algoritmo TCP di ripartirsi in modo uniforme la banda disponibile.
- **Friendlyness**,  capacitá dati n flussi TCP sullo stesso link che utilizzano diversi algoritmi TCP di ripartirsi in modo uniforme la banda disponibile.

Vegas soffre del problema della Friendlyness, infatti se flussi TCP Vegas e Reno competono per la banda avremo Vegas che sente la congestione prima e riduce il transmission rate ma Reno continuerá ad aumentare la congestion window. Dopo poco avremo Reno che utilizza la maggior parte delle risorse e Vegas "strangolato" dalla potenziale congestione. Per questo motivo Vegas non é piú utilizzato



### TCP BIC 
Algoritmo di congestione utilizzato per Long Fat Network, cioé per reti con alta banda passante ed alta latenza. Queste caratteristiche possono interferire con la stima della finestra e con lo slow start. BIC si basa sulla ricerca binaria e mantiene quattro valori di finestra di congestione: 
- Corrente  
- Minimo  
- Massimo  
- Atteso (valore medio tra massimo e minimo)

Usa tecniche di aggiustamento della finestra differenti in funzione della differenza tra finestra di congestione minima e massima:
1. Quando la differenza tra finestra minima e massima è grande si usa crescita aggressiva della finestra (additivo)
2. Quando la finestra corrente raggiunge quella attesa senza errori la finestra minima diventa quella attesa
3. In caso di errore la finestra massima assume il valore della finestra corrente. La finestra corrente si riduce al nuovo valore minimo
4. Mano a mano che le finestre minime e massime si restringono la ricerca si fa meno aggressiva
![[bic.png]]

BIC offre prestazione nettamente maggiori rispetto a Reno (arriva al punto di equilibrio piú lentamente) e gode di fairness (non "sgomita" con altri algoritmi per avere banda).

Il principale problema di BIC é che poco fairness con flussi con RTT diversi (flussi con RTT molto piccoli tendono a richiedere molta banda); questo problema é legato al fatto che BIC aggiorna la finestra ogni volta che riceve un ACK. 


### TCP CUBIC 
Anche Cubic é un algoritmo di congestione utilizzato per Long Fat Network. La funzione di crescita della finestra non dipende dal RTT ma da un fattore cubico dato dalla differenza tra l'istante attuale e l'istante dell'ultima congestione. Questo permette a CUBIC di avere i seguenti benefici:
- Stabilità
- Scalabilità
- Fairness tra flussi, infatti due flussi CUBIC che competono, convergono verso una dimensione della finestra “giusta
- Fairness rispetto a RTT, la crescita della finestra dipende dal tempo e non dal RTT
![[cubic2.png]]


### TCP é fair?
TCP utilizza l'algoritmo AIMD (Additive Increase Multiplicative Decrease), che garantisce fairness. In che modo? Gli host aumentano la loro larghezza di banda in modo additivo, ma quando si verifica una congestione la riducono in modo moltiplicativo. Quindi, l'host con una quota maggiore perde di più. Successivamente ogni host aumenta la propria quota dello stesso importo (additivamente). Poiché questi passaggi si ripetono ripetutamente, le larghezze di banda convergono a importi equi.