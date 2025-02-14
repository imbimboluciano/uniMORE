Il firewall è un dispositivo di sicurezza che si interpone tra due reti diverse per controllare e limitare il traffico.
1. Deve essere l’unico punto di contatto tra la rete esterna e la rete interna
2. Solo il traffico autorizzato o non vietato deve riuscire ad attraversare il firewall
![[firewall.png]]

L'implementazione di un firewall richiede il progetto delle regole sulla base di policy aziendali e l'implementazione delle regole.
Le politiche si definiscono mediante Access Control List (ACL) e possono essere di 2 tipologie:
1. Negazione implicita (lista di eccezzioni), non passa niente tranne ciò che è stato espressamente autorizzato 
	- Metodo piú sicuro
	- Difficile da gestire
2. Accesso implicito(blacklist), passa tutto ciò che non è stato espressamente vietato
	- Garantisce la massima usabilità della rete  
	- É più facile da gestire  
	- Espone la rete a rischi di sicurezza

I firewall si dividono in categorie sulla base del livello di protezione, della tecnologia e sul livello di esecuzione:
- Livello di esecuzione
	- Kernel level: controlli a [[Livello Internet]] e [[Livello Trasporto]]
	- User space level: controlli a livello applicazione
- Ambito di azione
	- Personale(installato su PC)
	- Aziendale
- Realizzazione
	- Hardware
	- Software (netfilter/[[Reti di Calcolatori/Sicurezza/IPtables]])
- Funzionalitá
	- [[#Packet filter]]
	- Application gateway (Proxy firewall) che filtrano a livello di contenuto dei protocolli



## Packet filter
Il firewall packet filter agisce a livello Internet (packet filter vero e proprio) e a livello Trasporto (circuit gateway) dello stack e bloccano o lasciano passare il traffico che attraversa il firewall definendo i protocolli, gli indirizzi IP e le porte che si possono o non possono utilizzare:
- interfaccia di ingresso e di uscita dei pacchetti [[IP]]
- valori dell’header dei protocolli di livello Internet
- protocolli di livello Trasporto
- valori dell’header dei protocolli di livello Trasporto

Esistono due tecniche di filtraggio dei pacchetti:
1. **Static Packet Filtering**, considera i singoli pacchetti come entità individuali, non  correlate tra loro. È realizzato mediante una lista di regole, ognuna composta due elementi:
	1. Espressione di confronto, per identificare i pacchetti che rispondono a certe descrizioni (considerano solo le informazioni contenute negli header)
	2. Azione (Accetta – Rifiuta – Ignora – Log)

Vantaggi | Svantaggi
------------ | ------------ 
  Basso costo computazionale e economico | Non è in grado di riconoscere pacchetti appartenenti ad una connessione già aperta (ESTABLISHED)
 Non richiede il mantenimento di informazioni di stato | Non è in grado di riconoscere pacchetti correlati ad una  connessione già aperta (RELATED)
 Semplice da implementare e gestire | |
   Ottima scalabilità | 
   
2. **Stateful Packet Filtering**, conosciuto anche come Dynamic Packet Filtering distingue le connessioni già aperte da quelle nuove, mantiene tabelle di stato con le informazioni relative alle connessioni attive ed adatta dinamicamente le regole utilizzate per il filtraggio in base alle informazioni di stato

Vantaggi | Svantaggi
------------ | ------------ 
  Riconosce pacchetti appartenenti ad una connessione già aperta (ESTABLISHED) | Problemi con i protocolli che si discostano dal  paradigma client/server (FTP)
 Le risposte provenienti dall’esterno a connessioni legittime vengono autorizzate da regole temporanee, istanziate dinamicamente e automaticamente | Non è in grado di riconoscere pacchetti correlati ad una  connessione già aperta (RELATED)
 Le regole temporanee sono attive solo per il tempo strettamente necessario durata della connesione + timeout) | Richiede maggiore capacità computazionale 
 Non è necessario aprire “buchi” permanenti | Richiede maggiori quantità di memoria per mantenere informazioni relative alle connessioni

3. **Stateful Packet Filter + Ispezione del payload**, ulteriore evoluzione dell’analisi stateful. I pacchetti non vengono valutati solo sulla base dei suoi header, ma anche sulla base dei dati del payload del pacchetto

Vantaggi | Svantaggi
------------ | ------------ 
  Riconosce anche pacchetti correlati ad una connessione già aperta (RELATED) | Ulteriore appesantimento dell’onere computazionale e quindi riesce a gestire minor traffico
 Il traffico correlato a connessioni legittime viene autorizzate da regole temporanee |
 Gestione efficace e sicura di protocolli complessi | 