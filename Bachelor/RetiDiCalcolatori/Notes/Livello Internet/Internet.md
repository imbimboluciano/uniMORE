Rete, inizialmente, finanziata dal Ministero della Difesa USA per consentire l’accesso alle poche risorse di calcolo potenti (e costose) da vari centri di ricerca e Università sparsi sul territorio statunitense. La rete Internet puó essere definita in diversi modi a seconda del punto di vista:
- A livello strutturale Internet é una rete fortemente distribuita (non è centralizzata) composta da milioni di host (computer, smartphone,TV), da dispositivi che instradano i messaggi (router) e da link di comunicazione (cavi, fibra ottica, satellitari).	![[internet1.png | center | 500]]
- Dal punto di vista dell'utente é una entitá trasparente, infatti logicamente la comunicazione sembra formata solo da i due host terminali (mittente e destinatario), ma in realtà il messaggio deve attraversare vari nodi intermedi (router) con un meccanismo di store and forward (aspetto tutti i pacchetti della comunicazione e inoltro).	![[internet2.png | center | 500]]
La rete Internet per la trasmissione dei messaggi utilizza la commutazione di pacchetto ([[Packet Switching]]) che é molto più vantaggiosa rispetto alla commutazione a circuito ([[Circuit Switching]]) utilizzata nelle reti telefoniche.



## Storia
```timeline
[line-3, body-2]
+ 1961
+ "Information flow in large communication nets"
+ Leonard Kleinrock del MIT pubblica la propria teoria sul packet switching

+ 1962-1964
+ "Galactic network"
+ J.C.R. Licklide scrive diversi articoli sul concetto di “galactic network”, cioé sul concetto di avere tante reti LAN che comunicano tra loro per creare una rete globale.

+ 1965
+ Prima volta che due computer si scambiano informazioni
+ Larry Roberts e Thomas Marrill effettuano il primo collegamento dati fra Massachussets e Santa Monica in California:

+ 1967
+ Interface Message Processors
+ Wesley Clark suggerisce di utilizzare una sottorete di minicomputer, tutti uguali, dedicata esclusivamente alla ricezione e trasmissione dei  
dati. Suggerisce di chiamare questi computer IMP.

+ aprile 1969
+ First H2H protocol
+ Steve Crocker scrive il Request For Comment (RFC) #1 che tratta l’host-to-host protocol

+ settembre 1969
+ Arpanet
+ Installato il primo nodo della rete Arpanet, presso UCLA. Gli slogan per il progetto erano i seguenti: "Perfection is achieved not when there is no  
longer anything to add, but when there is no longer anything to take away”  
[Antoine de Saint-Exupery], “The simplest explanation is the best” [Occam’s razor], “Be liberal in what you accept, and conservative in what you send” [Jon Postel], “In allocating resources, strive to avoid a disaster rather than to achieve an optimum” [Butler Lampson].

+ ottobre 1969
+ Arpanet
+ Nasce il secondo nodo della rete Arpanet, presso lo Standford Research Instituite.

+ 1973
+ Ethernet
+ Nella tesi di PhD, Metcalfe propone il protocollo e architettura per reti locali Ethernet.

+ 1983 
+ stack TCP/IP
+ 

+ 1983
+ DNS 
+ sistema distribuito per la traduzione da hostname a indirizzo IP  

+ 1985 
+ protocollo FTP
+ 

+ 1988
+ controllo di congestione del TCP
+ 

+ Inizi ’90 
+ nascita del WWW
+ 

+ Oggi
+ The network/computer is everywhere
+ Più di 1 miliardo di host connessi ad Internet

```


## Archittetura
L'archittetura di Internet é stata sviluppata con l'obiettivo di connettere un qualsiasi numero di reti indipendenti ed eterogenee, perseguendo 4 fondamentali principi:
1. **Survivability**: se tra due host esiste un qualsiasi  percorso, la comunicazione deve poter continuare.
2. **Forma a clessidra**: deve funzionare per tutti i tipi di applicazioni di rete
3. **Mancanza di “stato”**:  l'“intelligenza” è mantenuta ai bordi della rete (host) ed ogni pacchetto ha il proprio destino
4. **Autonomous systems**: ogni rete è posseduta e gestita da un ente diverso per osservare il principio di net neutrality (ogni LAN ha una specifica policy)

Dal punto di vista strutturale l'organizzazione di Internet é lascamente gerarchica, formata da 4 principali attori:
- **Host terminali**  connessi ad Internet Service Provider (ISP) locali
- **ISP locali** connessi a ISP regionali
- **ISP regionali** (nazionali) connessi a **ISP internazionali** (National Backbone Provide o National Service Provider)
![[interAS.png | center]]

Ciascun Internet Service Provider (ISP) ha:
- Dei Points Of Presence (POP) tramite cui si collegano gli utenti privati o aziendali  
- Dei NAP (Network Access Points) tramite cui si connetto a ISP di livello "superiore"
![[internet-backbone-map.webp]]

Nel definire l'archittettura di Internet non bisogna pensare ad Internet come un insieme di router “sparsi” casualmente nel mondo che vengono interconnessi tra di loro. Infatti i router sono aggregati in regioni, chiamate Autonomous Systems (AS). Tutti i router all’interno dello stesso AS usano lo stesso algoritmo di instradamento dei messaggi (routing) e si scambiano continue informazioni con gli altri router. Il traffico Internet si distribuisce tra più di 20000 Autonomous Systems, ciascun  caratterizzato da:
- un numero identificativo su 2 byte (2^16=65536)
- uno o più network ID o network prefix
![[skitter.png | center | 500]]
Come si puó vedere dal grafico, nessun AS gestisce più del 5% del traffico anzi la stragrande maggioranza degli AS gestisce molto meno dell’1% del traffico (la maggior parte degli AS si trovano sul bordo del grafico e quindi interagiscono poco).

Come sono interconnessi tra loro gli AS? Gli AS sono collegati tra di loro mediante due tipi  di “centri di interscambio” traffico:
- **Peering point (privati)**, interconnessione stabilita tra peer con lo scopo di scambiarsi il traffico dei relativi utenti. Inizialmente era definizione implicita che nessuno dei due contraenti pagava l’altro; attualmente, è più opportuno definire “settlement- free peering” quando ci si vuole riferire ad una situazione di peering senza pagamenti.
	1. Transit (o pay): tu AS paghi un altro AS per avere accesso o transito su Internet
	2. Peering (o swap): due AS si scambiano il traffico dei rispettivi utenti senza costi, per reciproco interesse (aumentare affidabilitá creando strade alternative)
	3. Customer (o sell): un altro AS paga te AS per avere accesso a Internet
	![[peeringpoint.png | center | 250]]
- **Internet Exchange Point (IXP)**, tipicamente consorzi indipendenti senza scopo di lucro creati fra AS ma talvolta supportati da finanziamenti pubblici (piú efficienti dei peering point). Poiché trasferiscono enormi quantita di traffico Internet, i centri di interscambio sono costituiti  da elementi di switching molto potenti e replicati, in particolare sono formati da uno o più centri stella ai quali vengono collegati i router dei vari  partecipanti (**shared switch fabric**); si stabiliscono cosí dei peering tra i router che consentono agli AS di scambiarsi traffico mediante protocollo BGP![[IXP.png | center | 250]]
Infine Internet puó essere anche visto come una organizzazione gerarchica di nomi e di domini utili al funzionamento del [[DNS]]. 
Arrivati a questo punto la domanda che sorge spontanea é "How do IP packets find their way through this mess?". La risposta a questa domanda si trova nei servizi offerti dall'[[IP]] e in particolare nelle funzioni di [[Routing]]