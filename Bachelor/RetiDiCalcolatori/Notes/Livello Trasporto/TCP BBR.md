Il nostro obiettivo attuale é quello di capire come é strutturato lo stack [[TCP-IP]] all'interno del kernel Linux attuale. Attualmente esiste un algoritmo migliore di TCP CUBIC? 
![[currenteTCPIPstack.png]]

Fino ad ora abbiamo visto i seguenti algoritmi di congestione [[TCP]]:
- Loss based
	- CUBIC, Reno, New Reno, BIC, Tahoe
- Time-based, i quali hanno problemi di fairness e friendliness
	- Vegas, New Vegas (2015)
Google nel 2017 ha introdotto un nuovo algoritmo TCP, model base, chiamato **BBR** e che sta prendendo strada all'interno del kernel di molte distro Linux.
É un algoritmo che si basa sul modello del bottleneck calcolato tramite il BDP (Bandwith Delay Product), cioé il prodotto banda-latenza: "If the link is at 10Mbps and the base RTT is at 100ms, how much data inflight a TCP socket must have to fulfill the bandwidth? 1Mbit".

Importantissima diventa la differenza tra latenza e datarate:
- Latenza, l'intervallo di tempo che intercorre fra il momento in cui viene inviato l'input/segnale al sistema e il momento in cui è disponibile il suo output.
- Datarate, la velocitá con cui vengono spediti i dati 

La direzione intrapresa dai nuovi algoritmi di congestione TCP é descritta in figura.
Sull'asse x abbiamo la quantitá di dati inviati ma di cui non ho ricevuto l'ack ed invece sull'asse y abbiamo sia il RTT (latenza) sia la banda disponibile (datarate).
![[ComportamentoTCP.png | center | 600]]
1. Poco Traffico e quindi poca banda utilizzata -> RTT minimo 
2. La banda cresce fino al bottloneck (BDP), perché non possiamo andare oltre -> Aumenta la congestione e quindi aumenta anche RTT
3. RTT aumenta troppo -> perdita di pacchetti


BBR (Bottleneck Bandwidh RTT) progettato da Google cerca di risolvere o migliorare le principali problematiche di CUBIC e lavora nel punto ottimale descritto dal grafico precedente (bottleneck):
- Cerca di conoscere la banda massima al quale ambire
- Allo stesso tempo cerca di mantenere RTT il piú piccolo possibile
In particolar modo sonda la capacità del percorso aumentando la velocità di invio per un breve intervallo:
- Se l'RTT attuale è uguale all'RTT dello stato precedente, allora è disponibile una larghezza di banda del percorso che potrebbe essere utilizzata
- Se l'RTT aumenta, è probabile che il percorso sia all'inizio di accodamento e non è disponibile ulteriore larghezza di banda del percorso

Sulla base di RTT e banda stima BBR definisce un modello che si aggiorna ad ogni ACK ricevuto.

Il modello a stati finiti di BBR é descritto dalla seguente immagine.
![[FSMBBR.png]]

Quindi l'algoritmo BBR é formato principalmente da 2 fasi:
1. Warm-up, simile allo slow start
	1. Start-up -> ricerca esponenziale della variazione di banda ![[startup.png | center|  400]]
	2. Drain -> Torna al punto ottimo ![[drain.png | center | 400]]
2. Steady-state
	1. ProbeBW -> cerco di capire se é disponibile della banda nuova (aumento leggermente le code)![[proberw.png | center | 400]]
	2. ProbeRTT -> dreno la coda per ripristinare RTT minimo ![[probertt.png | center | 400]]
Il vantaggio principale di un algoritmo basato su modelli matematici é che riesce a capire la differenza tra loss, perdita del pacchetto dovuta a problemi del mezzo trasmissivo, e drop, cioé la perdita del pacchetto a causa di code piene. E quindi, a differenza di CUBIC, BBR non reagisce in caso di loss.
Inoltre BBR é fairness ma solo con flussi con lo stesso RTT.

Per migliorare le prestazioni di BBR sono stati introdotti 2 meccanismi per controllare la distanza tra i pacchetti (pacing) e quanti vengono mandati giú nello stack (cerca di gestire la "congestione" al suo interno):
- **TCP Small Queues (TSQ)**, è un algoritmo che limita il traffico all'interno dello stack (comunicazione tra [[Livello Trasporto]] e [[Livello Host-to-Network]])
- **TCP Pacing**, è un algoritmo che aggiusta il rate di trasmissione dei pacchetti

BBR, a causa del pacing, a livello di prestazioni crolla con il wifi, il quale lavora in burst aggregando i flussi di dati (BBR non lavora in burst).


L'intero blocco TCP adesso dovrebbe essere chiaro. Ora ci spostiamo sul blocco centrale, il livello Disciplina delle code, Livello 3 dello stack TCP-IP. BBR abbandona la politica FIFO (fa schifo cit.Imperatore) per adottare la politica **FQ-CoDel** (Flow Queue Controlled Delay): Ogni flusso in una coda separata, ogni coda controlla il ritardo con CoDel e le code vengono servite con scheduler round-robin (intervalli di tempo sono assegnati a ciascun processo in porzioni uguali e in modo circolare, trattando tutti i processi senza priorità).
![[FQ-CoDel.png]]