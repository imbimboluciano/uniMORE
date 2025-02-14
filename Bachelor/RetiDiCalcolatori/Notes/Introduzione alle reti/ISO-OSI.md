L’organizzazione ISO (International Standard Organization) all'inizio degli anni ‘80 introdusse il modello OSI (Open System Interconnection) per definire le specifiche di quello che sarebbe dovuto diventare lo standard di protocolli per l’interconnessione di nodi eterogenei. 
Il modello ISO/OSI é formato da 7 livelli:
-   **Livello fisico**: gestisce i particolari meccanici ed elettrici della trasmissione fisica di un flusso di bit (frequenza modulante, cavo di fibra, wireless,…).
-   **Livello data link:** gestisce i frame o i pacchetti trasformando la semplice trasmissione in una linea di comunicazione priva di errori non rilevati ( definisce l’unità di trasmissione, gestisce gli errori, il flusso di arrivi e l’accesso al canale).
-   **Livello di rete**: fornisce i collegamenti e l’instradamento (indirizzo univoco) dei pacchetti nella rete (anche non fisicamente collegati).
-   **Livello di trasporto**: garantisce l’affidabilità del trasporto (concetto di connessione) e definisce un canale di comunicazione (open,close,gestione) senza gestire i dettagli fisici.
-   **Livello di sessione**: implementa funzioni di coordinamento, sincronizzazione e mantenimento dello stato tra utenti diversi su hardware eterogenei.
-   **Livello di presentazione**: risolve le differenze di formato tra i diversi nodi della rete (compressione dati, sicurezza ed autenticità)
-   **Livello applicazione**: Fornisce un’interfaccia standard per i programmi applicativi che utilizzano la rete, mascherando le peculiarità e la complessità del sistema sottostante
![[ISOOSI.png]]

I protocoli utilizzati all'interno dei livelli dello stack ISO/OSI si dividono in due tipologie:
-   Protocolli di comunicazione (network level): riguardano la comunicazione di messaggi tra nodi della rete, in modo da nascondere le caratteristiche dei mezzi fisici di trasmissione alle funzionalità di elaborazione (livello 1,2,3)
-   Protocolli di elaborazione (application level): insieme di meccanismi per il controllo delle applicazioni (livello 4,5,6,7)

Fin dall'inizio ISO/OSI nasce come modello concettuale e quindi non orientato alla realtá delle infrastrutture di rete. Questa caratteristica la si puó evincere dalla poca differenziazione, a livello di funzionalitá, tra il livello di sessione, presentazione e applicazione. Le principali criticitá del modello ISO/OSI che hanno portato al suo fallimento pratico sono le seguenti:
- pessima tempistica
- pessima tecnologia (influenzato dall’IBM)
- pessima implementazione (elevata complessità e eccessivo numero di livelli)
- pessima politica (modello a pagamento)

Inoltre, il modello ISO/OSI non riuscí ad affermarsi perché nel frattempo stava esplodendo il modello [[TCP-IP]]. Nonostante il suo inutilizzo pratico, il modello ISO/OSI rimane lo standard teorico e concettuale dell'architettura di rete. 