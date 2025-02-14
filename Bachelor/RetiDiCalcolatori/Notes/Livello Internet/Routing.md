Il router deve risolvere un problema molto ben definito: Instradare i pacchetti nella  
rete da un qualsiasi host ad un qualsiasi altro host; vista la moltitudine di dispositivi all'interno della rete [[Internet]] questo problema é complesso. Quando un problema è complesso si suddivide in sottoproblemi più semplici:
- [[#IP forwarding]], ad ogni hop inoltrare il pacchetto ad un altro nodo in modo che si  avvicini alla destinazione 
- [[#Gestione delle tabelle di routing]], mantenere informazioni aggiornate per poter risolvere l'IP forwarding



## IP forwarding
Meccanismo con cui un router trasferisce i pacchetti da un’interfaccia d’ingresso a quella in uscita. Infatti i router devono conoscere solo l'indirizzo del next-hop, il quale appartiene ad una rete alla quale il router è collegato direttamente. Per inoltrare i pacchetti l’indirizzo di destinazione viene estratto dall’header del pacchetto e viene usato come indice nella tabella di routing (determinando il netid), una tabella in cui ciascuna riga fornisce il  next-hop per ogni possibile destinazione. 
- Se il netid corrisponde ad una rete connessa  direttamente al router, consegna il pacchetto al destinatario D sulla rete
- Se la tabella contiene un router per la rete specificata nel netid, invia il pacchetto al next-hop router specificato nella tabella
- Se la tabella contiene un router di default, invia il pacchetto a quel router
- Altrimenti, si verifica un errore di routing (scarta il pacchetto ed invia un messaggio di errore)
Le dimensioni crescenti delle tabelle di routing potrebbero essere un limite allo sviluppo di Internet ma in realtà, una riga può fornire informazioni per molte destinazioni con l’utilizzo di tecniche di aggregazione:
- Utilizzo del solo netid per un insieme di indirizzi IP di destinazione che condividono lo stesso next-hop
- Longest prefix matching, ordinando la tabella mettendo prima le maschere più lunghe e poi le più corte
- Organizzazione gerarchica che riflette l’architettura di Internet
- Routing geografico, sapendo che le classi di indirizzi IP vengono assegnati in funzione della posizione geografica continentale
- Uso del router di default (netid = 0)
![[routing.png | center | 400]]



## Gestione delle tabelle di routing
Le tabelle di routing possono essere gestite ed aggiornate con 2 principali modalitá:
- **Routing statico**: la tabella di routing non è modificata dal router ma dall'amministratore di rete (impossibilità di reagire automaticamente ai cambiamenti topologici)
- **Routing dinamico**: la tabella di routing è modificata dal router al variare delle condizioni sulla rete e lo scambio di informazioni ed il calcolo dei valori  della tabella di routing avvengono mediante qualche protocollo di routing: RIP, OSPF, BGP.

Tipicamente esistono 2 modalitá per gestire l'IP forwarding:
- Routing universale: la tabella di routing deve contenere un next-hop router per ciascuna destinazione (impraticabile a livello globale)
- Routing ottimo: il next-hop router è scelto in modo da minimizzare il cammino verso la destinazione grazie all'utilizzo degli [[#Algoritmi di routing]]



## Algoritmi di routing
L'obiettivo principale di questi algoritmi é quello che dato un insieme di router interconnessi,  determinare il cammino ottimale (costo minimo) dall’host mittente all’host destinatario. Per formulare un algoritmo di routing, si modella la rete tramite un grafo pesato G(N,E) dove:
- i nodi N rappresentano i router (oppure gli AS)  
- gli archi rappresentano le connessioni tra i router
- le etichette E degli archi rappresentano il “costo” delle connessioni tra i router
![[grafopesato.png | center | 400]]
Le prestazioni del routing sono influenzate dalla topologia della rete, dal traffico della rete, da eventuali guasti, dalle [[Politiche di routing]] e dall'algoritmo di routing implementato che puó essere fondamentalmente di 2 tipi:
- **Algoritmi di routing distribuito**, in cui nessun nodo ha un’informazione completa  del costo di tutti i link della rete ([[Distance vector protocol]])
- **Algoritmi di routing centralizzato**, in cui ogni nodo possiede un’informazione globale sulla rete ([[Link state protocol]])

Protocollo | Link State | Distance Vector
------------ | ------------ | ------------
Dimensione dei messaggi | piccola | potenzialmente grande
Numero di messaggi | molto grande O(n) con nodi del grafo | piccolo in quanto comunicazioni solo ai vicini
Velocità di convergenza | veloce  | veloce se si effettuano aggiornamenti periodici frequenti
Requisito di memorizzazione| molto alto si mantiene l’intera topologia del grafo | basso si mantiene solo lo stato dei vicini
Robustezza | calcolo dei percorsi effettuato in maniera indipendente da ogni nodo e quindi protezione contro guasti ai router | calcolo dei percorsi basato sui calcoli degli altri router e quindi il calcolo sbagliato di un router può essere propagato a gran parte della rete

Non c’è un chiaro vincitore tra i due algoritmi e quindi tendenzialmente gli algoritmi di tipo Link state tendono ad essere utilizzati all’interno degli AS ed invece gli algoritmi di tipo Distance vector sono utilizzati per il routing tra AS.