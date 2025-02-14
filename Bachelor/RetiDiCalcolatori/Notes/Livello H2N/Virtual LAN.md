L’ utilizzo delle [[VLAN]] permette di realizzare:
- **risparmio**: non è necessario realizzare una nuova infrastruttura di rete locale con apparati e linee dedicate per creare una nuova LAN parallela
- **aumento di prestazioni**: il confinamento del traffico broadcast permette di evitare la propagazione di frame verso destinazioni che non hanno necessità di riceverlo
- **aumento della sicurezza**: una utenza connessa ad una VLAN non ha modo di vedere il traffico interno alle altre VLAN
- **flessibilità**: lo spostamento fisico di una utenza all’interno dei locali raggiunti dalla infrastruttura di rete può essere realizzato senza modifiche della topologia fisica

Per realizzare VLAN è necessario che gli switch ed i bridge della infrastruttura di  rete siano capaci di distinguere le diverse VLAN e devono quindi osservare lo standard **802.1Q**. Infatti questo standard definisce le specifiche che permettono di definire più reti locali virtuali (VLAN) distinte, utilizzando una stessa infrastruttura fisica; ciascuna VLAN si comporta come se fosse una rete locale separata dalle altre.
Esistono 2 principali modi per realizzare VLAN:
- [[#VLAN port based]] (o private VLAN)  
- [[#VLAN tagged]] (802.1Q)
- [[#VLAN protocol based]]

Indipendentemente dal tipo di VLAN, esistono tre funzioni che i bridge devono saper svolgere per poter gestire più reti virtuali:
- **ingress**: il bridge deve essere in grado di capire a quale VLAN appartenga un frame in ingresso da una porta
- **forwarding**: il bridge deve conoscere verso  quale porta deve essere inoltrato il frame verso destinazione, in funzione della VLAN di appartenenza  
- **egress**: il bridge deve poter trasmettere il frame in uscita in modo che la sua  appartenenza alla VLAN venga correttamente interpretata da altri bridge a valle

Attraverso l'utilizzo di VLAN é possibile anche creare una gerarchia di LAN virtuali. Per eseguire questa operazione dobbiamo utilizzare lo standard 802.1AD che introduce nel frame Ethernet un secondo campo TAG per distinguere tra la VLAN interna e la VLAN esterna.



### VLAN port based
Questa tecnica prevede l’assegnazione statica di ciascuna porta del bridge ad una VLAN. Le VLAN untagged (dette anche private) non richiedono l’osservanza dello standard 802.1Q, ma solo che lo switch ne supporti la configurabilità.
1. ingress: un frame in ingresso appartiene alla VLAN a cui è assegnata la porta
2. forwarding: il frame potrà essere inoltrato solo verso porte appartenenti alla stessa VLAN a cui appartiene la porta di ingresso (il bridge mantiene un forwarding database distinto per ogni VLAN)
3. egress: una volta determinata la porta (o le porte) attraverso cui deve essere trasmesso il frame, questo può essere trasmesso
![[untaggedVLAN.png | center]]



### VLAN tagged
Lo standard 802.1Q viene utilizzato per poter condividere lo stesso link fisico tra VLAN differenti. Lo standard definisce una modifica del formato del frame ethernet aggiungendo 4 byte che trasportano le informazioni sulla VLAN: 
- TPI (Tag Protocol Identifier) due bytes di valore 81 00 che identificano il frame come frame 802.1Q
- TCI (Tag Control Information) due bytes che trasportano le informazioni sulla tag
	- i primi tre bit (user priority) indicano l’eventuale livello di priorita
	- il quarto bit (CFI) vale 1 se il frame proviene da una LAN token ring
	- i restanti 12 bit (VID) trasportano la VLAN tag (da 0 = default a 4095 = broadcast)

Il frame così costituito rappresenta una violazione dello standard [[Ethernet]], in quanto  
può eccedere la dimensione massima di 1518 bytes . Quindi tutti i bridge che osservano lo standard devono poter accettare frame con 2 byte in più.

In un bridge 802.1Q tutte le porte devono essere associate ad una o più VLAN:
- se la porta è associata ad una VLAN “port based” (untagged) i frame ricevuti da quella porta non trasporteranno TAG, nè dovranno trasportarla i frame in uscita (access link)
- se la porta sarà associata ad una o più VLAN in modalità tagged  i frame  trasporteranno le informazioni di tag (trunk link)
- una porta puó essere associata ad una VLAN in modalità untagged, e ad altre VLAN in modalità tagged (hybrid link)

Le funzioni di ingress, forwarding e egress nello standard 802.1Q sono cosí descritte:
1. ingress: quando viene ricevuto un frame il bridge deve identificare la VLAN di appartenenza (tag o untag)
2. forwarding: una volta identificala la VLAN di appartenenza vengono applicate le regole di forwarding e viene identificata la porta di uscita
3. egress, ci sono diverse casistiche:
	1. se il frame in ingresso è di tipo 802.1Q e la porta in uscita è associata alla VLAN di appartenenza in modalità tagged, il frame viene inoltrato senza modifiche  
	2. se il frame in ingresso è untagged e la porta in uscita è  associata alla VLAN di appartenenza in modalità untagged, il frame viene inoltrato senza modifiche 
	3. se il frame in ingresso è di tipo 802.1Q e la porta di uscita è in modalità untagged, il TAG deve essere rimosso  
	4. se il frame in ingresso è di tipo 802.3 (Ethernet) e la porta di uscita è associata alla VLAN di appartenenza in modalità tagged, deve essere inserito il TAG.

![[taggedVLAN.png | center]]



### VLAN protocol based
L’ assegnazione di un frame ad una VLAN può anche essere effettuata dinamicamente, in funzione di diversi parametri:
- indirizzo IP del mittente
- protocol type del frame Ethernet (IP, NETBios...)  
- indirizzo Ethernet della stazione mittente

Queste regole di assegnazione possono anche convivere con una assegnazione statica, che peró avrà priorità maggiore.


