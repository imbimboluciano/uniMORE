Il World Wide Web, o più comunemente chiamato [[Web]],  nasce nel 1991 con la definizione del protocollo [[HTTP]], da parte del ricercatore Tim Berners-Lee. Gli ingredienti principali del Web sono i seguenti:
- Meccanismi di comunicazione e naming di Internet ([[TCP]], [[IP]], [[DNS]])
- Architettura client-server
- Basato su tre standard:
	1. [[URL]]: Sistema di indirizzamento delle risorse
	2. [[HTML]]: Linguaggio di markup ipertestuale
	3. [[HTTP]]: Protocollo per le richieste risorse


## Web Dinamico
Il Web dinamico permette l'interazione personalizzata (sulla base di parametri) tra utente e server, che consente all’utente di effettuare accessi riservati, ricerche, acquisti e transazioni. Alcune risorse Web non sono file multimediali, ma richiedono l’esecuzione di (uno o più) programmi. Per gestire questa dinamicitá in un servizio Web si possono approssimativamente distinguere, a livello logico, le seguenti componenti:
- Interfaccia utente
- Logica di presentazione, che rappresenta quello che accade quando l’utente  interagisce con l’interfaccia
- Logica dell’applicazione (business logic)
- Logica dei dati, cioè la gestione fisica dei dati

Di norma questi livelli risiedono su macchine diverse cha talvolta vengono anche replicate. 
![[webtier.png | center | 250]]

Un approccio molto usato nelle tecnologie con forte dinamicità é quello di spostare parte della presentation logic sul client per migliora l'interattività e ridurre le latenze di risposta. 
Adesso soffermiamoci sulle tecnlogie per sviluppare il middle tier, ovvero la business logic.
1. [[Common Interface Gateway (CGI)]], problemi di scalabilitá
2. [[Linguaggi di Scripting]], evitino la creazione di un nuovo processo (aumento delle prestazioni)
3. [[Web Framework]], come [[Django Framework]] basati su [[Model View Controller]]

Lo sviluppo di queste tecnologie, negli ultimi anni, é stato guidato dalla necessitá di ridurre sempre di piú il tempo per rendere disponibili nuovi servizi. 



## Logging
I logfile permettono di monitorare gli accessi ad un server Web e per questo motivo sono la prima sorgente di dato nella profilazione delle preferenze degli utenti. I logfile sono formati nel seguente modo:
- Una riga per ogni richiesta  
- Le righe sono composte da record (URL, IP, cookie)

I log file sono utili per monitorare lo stato del server, fare Capacity planning, per capire l'utilizzo di un servizio a pagamento da parte degli utenti (Billing) e per sventare attacchi.

Vista l'importanza dei logfile esistono diversi strumenti che permettono di analizzare file di log, chiamati **Log analyzer**.