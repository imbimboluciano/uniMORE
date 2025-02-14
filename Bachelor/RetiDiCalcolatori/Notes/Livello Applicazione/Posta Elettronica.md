E’ una delle “killer” application di Internet sebbene l’idea di comunicare via computer addirittura anticipa Internet (anni '60'). 
Per identificare gli utenti del servizio vennero introdotti gli indirizzi email formato dall'username (max 64 caratteri) e dal dominio(max 255 caratteri) divisi da @ (Es. Local_username@Domain).
Per via della sua natura protocolli e agenti software utilizzati per la gestione della posta elettronica non prevedono meccanismi di autenticazione per gli indirizzi di posta elettronica del mittente; infatti il campo “mittente” di un messaggio di posta elettronica non deve essere considerato come una informazione affidabile ([[#Limiti del sistema di posta elettronica]]).

Il sistema di gestione di posta elettronica è alquanto complesso e composto da diversi componenti:
- **Mail Transfer Agent**: il [[#Mail server]] per la gestione e il trasferimento della posta mediante SMTP
- [[SMTP]]: il protocollo per il trasferimento della posta
- [[DNS]]: resource record MX
- [[#Mail User Agent]]: applicativo client per la gestione della posta lato utente
- **Mail Delivery Agent (MDA)**, prende i dati dal MTA e li conserva in una mailbox (filtro antispam ed antivirus)
- **Mail Submission Agent (MSA)**, per inoltrare il messaggio al sistema di posta (autenticazione, controlli aggiuntivi)

![[postaelettronica.png | center | 550]]

In veritá nell'architettura moderna della posta elettronica tra il MDA e l'MUA di Bob c'e' uno nuovo strato software; infatti la mailbox viene resa fruibile in remoto  mediante appositi server e protocolli (POP e IMAP)  e Bob usa i server per copiare i contenuti della mailbox remota in locale.
![[mailboxlocale.png | center | 550]]


## Mail server
Le funzioni principali del MTA sono le seguenti:
- Memorizzazione messaggi in arrivo nelle user mailbox  
- Memorizzazione messaggi in uscita
- Invio/ricezione messaggi mediante il protocollo SMTP
- Inoltro di messaggi (mail forwarding)

Da un punto di vista architetturale MTA è sia client sia server di altri mail server.
Il nome della mailbox, normalmente corrisponde ad uno username, ma può  
corrispondere ad un “alias” e quindi abbiamo bisogno di un database che ne tenga traccia. Inoltre una mail può anche arrivare da un utente interno.
![[mailserver.png]]

Quindi MTA é il processo principale di un mail server che trasferisce messaggi da un computer all’altro. Esistono 2 modalitá di trasferimento:
- **Trasferimento diretto**: dall’MTA sending server all’MTA receiving server
- **Trasferimento relay**: trasferimento dall’MTA sending server ad un server  intermedio (mail gateway, mail bridge, mail relay) ![[relay.png]]

Per il trasferimento la prima informazione da conoscere è il mail server che gestisce il dominio di posta del destinatario. Per far ció ci viene in aiuto il [[DNS]], il quale gestisce un tipo di resource record MX ovvero Mail eXchanger record che specifica come deve essere inoltrato un messaggio:
- elenco di mail server (hostname, indirizzo IP) che possono ricevere l’email per quel dominio  
- priorità relativa
L’MTA mittente cerca di stabilire una  connessione SMTP/TCP con il server con priorità più alta e continua fin quando non c’è un server dell’elenco che risponde al quale verrá inoltrato il messaggio.
![[trasferimentoEmail.png | center | 550]]
In scenari ad alto traffico vengono replicati processi MTA ed utilizzati SMTP e MX server. 


In alcuni casi, il Mail server è costituito da diversi mail agent oltre al Mail Transfer Agent (MTA) sempre presente:
- Mail Delivery Agent (MDA), processo che consegna il messaggio alla mailbox utente ed esegue le seguenti operazioni:
	- Filtering (spam e virus) 
	- Ordinamento  
	- Inserimento in cartelle sulla base di keyword, soggetto, mittente, testo  
- Mail Submission Agent (MSA), processo che riceve un messaggio da un MUA e contatta un MTA per inviarlo. 

Molti MTA agiscono anche da MSA, anche perché queste funzionalità sono sempre  
state storicamente integrate. La separazione tra i due processi porta indubbi benefici:
- Alcuni MSA possono richiedere l’autenticazione dell’utente al posto del MTA
- Si evita la connessione diretta sulla porta 25 da parte di client “arbitrari”
- Interagendo direttamente con un MUA, MSA può correggere o segnalare  all’utente mittente alcuni errori evidenti



## Mail User Agent
E’ l’applicazione utente “della posta” che comprende varie funzionalità:
- interfaccia utente
- strumenti per lettura messaggi di posta
- strumenti per organizzazione della posta inviata e ricevuta
- integra anche funzionalitá MSA

Come giá detto nell'architettura moderna lo user agent accede alla mailbox remota, per la copia dei messaggi sulla mailbox locale, utilizzando determinati protocolli:
- [[POP]] (Post Office Protocol), autorizzazione (tra user agent e mail server) e download dei messaggi
- [[IMAP]] (Internet Mail Access Protocol), possibilità di manipolazione dei messaggi memorizzati sul server
![[MUA.png]]



## Limiti del sistema di posta elettronica
Per via della sua natura architetturale nel sistema di posta elettronica non c'é nessuna garanzia di confidenzialità, integrità, consegna del messaggio, autenticazione, non ripudio. 
- Scarsa confidenzialità e rivelazione di informazioni sensibili
- Insicurezza sull'origine e problemi di  integrità
- Possibilità di spam, cioé di diffondere a un elevatissimo numero di utenti messaggi pubblicitari via e-mail
	- Scam ovvero usare lo spam per condurre truffe o peggio.
	- Vendita di prodotti
	- Hoax, voci infondate e allarmanti con preghiera di diffusione

Lo spam viene spesso combattuto con software di analisi detti filtri antispam, i quali analizzano il contenuto della mail per vedere se “sembra spam”. Per limitare l'efficacia delle contromisure lo spam si è evoluto: mesaggi di spam offuscati.
- Sostituzione di caratteri in una parola:  V1agra, Vìagra
- Uso di finti tag [[HTML]]
- Uso di immagini per il messaggio invece che testo

Per migliorare la sicurezza é stato definito un estensione del protocollo [[SMTP]], chiamato [[SMTPS]], che include autenticazione degli utenti, cifratura dei dati (firma digitale o cifratura) e conferma di ricezione