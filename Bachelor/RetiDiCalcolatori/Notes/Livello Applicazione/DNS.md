Protocollo applicativo di servizio che ci consente dato un hostname di convertirlo nel corrispondente indirizzo [[IP]], per far ció realizza uno spazio dei nomi gerarchico ed introduce un ulteriore livello di naming.
Anche il DNS si basa su una architettura client-server:
1. Il client fa richiesta di risoluzione nome ad un server DNS
2. Il server elabora la richiesta e risponde al client
Il processo di risoluzione, di norma, coinvolge più server per avere maggiore scalabilità (un server non può contenere tutte le possibili associazioni nome-ip).
![[clientserverDNS.png]]

Il protocollo DNS (**Domain Name System**) aggiunge come identificatori gli **hostname**:
- Sequenza di label separate da punti (una label massimo 63 caratteri alfanumerici)
- L'intero hostname massimo 255 caratteri
- l'indirizzo IP non è mappato 1:1 con l'hostname (non dipende dai punti dell'hostname)
- **Esempio**
	- w3c.org
	- samba.ing.unimo.it

L'ordine in cui sono posizionate le label nella sequenza ha una certa importanza perché denota un ordine gerarchico. Prendiamo per esempio l'hostname sun3.ing.unimore.it:
- sun3, indica il nome computer
- ing, indica la facolta ingegneria
- unimore, identifica l'universita
- it. identifica la nazione

Una domanda che puó sorgere spontanea é "perché introdurre un ulteriore livello di indirizzamento?". Gli hostname favoriscono l’usabilità delle applicazioni Internet consentendo agli utenti di far riferimento a nomi mnemonici e gerarchici invece che a indirizzi IP numerici.  Inoltre gli hostname consentono una certa dinamicità a costo di una perditá di efficienza, infatti in caso di cambio di indirizzo IP del server non c'è bisogno di ricompilare il software del client. Infine grazie agli hostname possiamo bilanciare il carico tra vari siti.

Esistono 2 meccanismi di traduzione:
1. Da hostname a ip (diretta ed implicita)
```powershell
$ ping www.google.com
> PING www.google.com (142.250.184.100) 56(84) bytes of data.

$ dig www.google.com
> ;; ANSWER SECTION:
> www.google.com.		180	IN	A	142.250.184.100
```
2. Da ip ad hostname(reverse). Ad un ip possono essere associate diverse label
```powershell
$ dig -r "IP"
```

Come avviene questa traduzione?
1. Inizialmente, con pochi host, esisteva un database centralizzato (non praticabile oggi per problemi di scalabilitá)
2. Multipli name server (distribuzione della responsabilità) distribuiti su scala geografica che utilizzano cache (per molteplici accessi allo stesso hostname) e UDP per migliorare l'efficienza. Le coppie hostname-IP non rimangono  in cache per sempre (c'è un limite di secondi, di norma 5 minuti). 
```powershell
$ dig www.google.com
> ;; ANSWER SECTION:
> www.google.com.		180 IN	A	142.250.184.100
# 180 è un contatore che decrementa al passare del tempo e ci dice per quanto tempo rimarrà in cache l'associazione IP-hostname
```

Quale protocollo di trasporto usa il DNS?
- ll protocollo TCP per il trasferimento di interi database da server primari a server secondari (replica) o per lookup corposi
- Il protocollo UDP per il lookup di singoli o pochi nomi



## Organizzazione logica dello spazio dei nomi
Il protocollo DNS realizza uno spazio dei nomi gerarchico con struttura ad albero (la radice è un ., di norma omesso) formato dai seguenti elementi
1. **Top Level Domain (TLD)** (più a destra nell'hostname), dal 2012 liberalizzati, si dividono nelle seguenti categorie:
	- Generic TLD (gTLD) -> .com,.edu,.org
	- Country code TLD (ccTLD) -> .it, .uk, .fr
	- Infrastructure TLD -> .arpa
	- Unsponsored TLD (uTLD) -> .info,.biz, .name
	- Sponsored TLD (sTLD) -> .museum, .coop, .aero
2. **Second Level Domain (SLD)**, i quali corrispondono ai nomi delle aziende/brand. Essendo associati con i beni/servizi prodotti e con la reputazione della organizzazione hanno un valore economico e sono soggetti alla compravendita. Per questa caratteristica, da sembre si hanno fenomeni di **Cybersquatting**, cioé fenomeni in cui si registrava un dominio contenente il brand di un’azienda per provare a rivenderlo (adozione regole Anticybersquatting). Con l'utilizzo della codifica UNICODE è possibile registrare hostname in qualsiasi lingua.
3. **Eventuali sottodomini**
![[strutturahostname.png | center | 550]]



## Componenti DNS
Gli obiettivi progettuali del DNS sono di avere a disposizione uno spazio dei nomi consistente, una elevata tolleranza ai guasti ed un sistema scalabile e funzionante in reti eterogenee. L'infrastruttura che permette una notevole scalabilitá é la seguente.

#### Zone e Name Servers
Rappresentano i possessori e gestori dell’informazione, con le funzionalità di server abilitati a rispondere alle query dei client e di altri server. Per avere una certa flessbilitá e scalabilitá i Name servers si dividono in diverse classi:
- **Root DNS Servers** (replicati logicamente), sono i computer che forniscono accesso al file della “root zone” per le necessarie operazioni di DNS resolution (il file contiene le informazioni relative ai server TLD di quella zona). Questo "file root" é gestito dal’ente Network Solutions Incorporated of Herndon, Virginia (USA), il quale aggiorna gli altri root name server mediante "DNS zone transfers", appoggiandosi sul [[TCP]]. A causa delle limitazioni [[UDP]], protocollo tipicamente utilizzato dal DNS (porta 53), esistono 13 root name server (inizialmente erano 13 fisicamente) ma la maggior parte sono distribuiti con indirizzo IP pubblico anycast, cioé un indirizzo IP associato a indirizzi IP di più host (più server distribuiti con stesso indirizzo IP).
- **TLD Name Servers**, gestiscono i dati e le richieste relativamente ai gTLD e ai ccTLD. Per essere attivi devono registrarsi presso i root name server. 
- **SLD Name Servers**
- **Local Name Servers** (Fastweb, Vodafone) che rappresentano le foglie dell'albero e che puó essere configurato dal client.

Nel protocollo DNS vige il principio di delega, cioé ciascuna organizzazione che possiede e gestisce un nome a dominio é  responsabile dell’operatività di almeno un authoritative name server che deve essere registrato presso il dominio  gerarchicamente superiore (SLD -> TLD -> Root). Questo name server peró non deve necessariamente conosce tutti gli hostname di quel dominio, questo perché all'interno di uno stesso dominio possiamo avere diverse zone (zona non sempre uguale a dominio).
![[zonenameserver.png]]

Quindi i name server non hanno i dati di tutti i nomi ma devono conoscere quali altri server sono responsabili di altre zone. In generale, ciascun name server deve conoscere 
- Il name server della zona immediatamente superiore
- I name Server delle sottozone

Ne consegue che la gerarchia di name server risulta differente e molto più  irregolare rispetto alla gerarchia dei nomi di dominio. 
I dati relativi ad una Zona vengoni inseriti in un master file, unica sorgente di dati autoritativi per quella Zona, dagli amministratori sistema. Con l'utilizzo del master file abbiamo un'altra distinzione tra name server:
- Server primari, che leggono i dati di una zona direttamente dal master file
- Server secondari (molteplici) , che scaricano i dati dal server primario periodicamente per mantenersi aggiornati.
![[nameserverprimarisecondari.png | center ]]

```powershell
$ dig www.unimore.it
>  flags: qr aa rd ra; QUERY: 1, ANSWER: 2, AUTHORITY: 3, ADDITIONAL: 5
# Flags aa -> server autoritativo
```

Per ridurre i tempi di risposta, ogni name server del DNS è libero di effettuare il  
caching dei dati relativi ad altri server ed altre zone in modo da evitare di contattarli 
quando una risoluzione viene richiesta più volte. Quando un name server non-autoritativo ottiene un dato da un server autoritativo prende nota anche del TTL associato:
- Se TTL non è scaduto il name server fornirà un dato nella cache al client
- Se invece il TTL è scaduto, il name server contatta il name server autoritativo per  controllare se il dato è valido o meno

Il caching è uno strumento potente per ridurre il traffico di Internet relativo alla  
risoluzione indirizzi (la scelta del valore del TTL deve seguire tale scopo).


#### Domain Name Space e Resource Records
Rappresentano i dati su zone, descrittori, informazioni:
- Dati relativi a tutti i nomi di un Dominio, meno alcuni sotto-domini amministrati da autorità di livello inferiore.
- Hostname ed indirizzi IP del o dei name server che forniscono dati autoritativi per la Zona
- Hostname ed indirizzi IP dei name server  che possiedono dati autoritativi per sotto-zone delegate

Tutti questi dati vengono memorizzati come Descrittori di risorsa (RR) formati dai seguenti campi:
- Nome del dominio (simbolico)  
- Time-To-Live (TTL) del RR espresso in secondi (diverso per ogni dominio), per caching
-  Classe del RR, tipicamente IN = Internet 
-  Tipo del RR  
	- **SOA** = Start of Authority (parametri per gestire la zona)
		- TTL
		- Serial, identificatore seriale di aggiornamento; server per verificare che un server secondario abbia l’ultimo record con i dati più aggiornati
		- Refresh, indica ad un server secondario quanto frequentemente deve richiedere un aggiornamento
		- Expire, tempo limite che indica per quanto tempo un file di Zona può essere servito
		- Retry, se il server secondario richiede un refresh ed il primario è irraggiungibile, il valore Retry indica quanto tempo attendere prima di provare nuovamente
	- **A** = host address, usato per il riferimento da un nome all’indirizzo IP di un host
	- **NS** = Name server, specifica i server (primari e secondari) che contengono dati autoritativi relativi ad una Zona
	- **TXT** = text
	- **AAAA**, uguale a A per IPv6
	- **MX** = Mail Exchanger, specifica a quale server inviare una e-mail in arrivo
	- **CNAME** = alias per un host
	- **PTR** = Pointer to another node (per risoluzione inversa)
	- **HINFO** = Host information (descrizione CPU e OS)
- Valore del RR (indirizzo IP numerico) che dipende dal tipo


#### Resolvers (client)
Rappresentano i client del sistema DNS che sottomettono query, con protocollo [[UDP]], per informazioni su hostname e indirizzi IP per conto delle applicazioni Internet. Per chiedere delle risoluzioni ogni resolver deve conoscere il riferimento ad almeno un name server locale.
Esistono due modalità di comunicazione:
1. **Ricorsiva**, il top level domain server fa attendere il client perchè deve comunicare con il corrispondente name server
2. **Iterativa**, il top level domain server risponde al client con il nome del name server da conttatare per la risoluzione
![[resolver.png]]




