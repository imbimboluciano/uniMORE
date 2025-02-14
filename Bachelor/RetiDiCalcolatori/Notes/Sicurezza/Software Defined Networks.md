I [[Cloud Data Center]] adottano tecniche di virtualizzazione delle risorse di calcolo (host, container, VM); tale approccio si sta estendendo anche alle reti:
- NFV: Network Function Virtualization, uso di sistemi COTS(standardizzati) per le funzioni di reti più sofisticate al posto di hardware dedicato; utilizzato nei grandi ISP 
- SDN: Software Defined Networking, soluzione nata in reti limitate e maturata nell’ambito di data center per migliorare orchestrazione in sistemi Cloud (sistemi software configurabili)

Le motivazioni principali che hanno portato all'adozione dei Software Defined Network sono le seguenti:
- Difficoltà, con HW dedicato, nella gestione della rete a fronte di carichi di lavoro variabili
- Infrastrutture di rete dimensionate su esigenze di picco (risorse sotto utilizzate)
- Serve un meccanismo flessibile per implementare policy complesse
- Dobbiamo garantire performance isolation, cioé i flussi di traffico non devono interferire tra loro (uso di VLAN e traffic shaper)
- Supporto alla ridondanza per gestire eventuali errori e carichi di lavoro elevati(spanning tree)
- Supporto per funzioni aggiuntive ([[Firewall]], [[NAT]], [[traffic shaping]])
- Necessitá di adattarsi a scenari fortemente dinamici ed agire in modo rapido

L'idea di base delle SDN é quella di separare le funzioni di rete in 2 grosse categorie:
1. [[#Data plane]], svolge operazioni semplici in tempi piccoli (Veloce e Distribuito) per esempio il forwarding dei pacchetti (molte volte sono soluzioni HW replicate)
2. [[#Control plane]], coordina le informazioni utilizzate dai data plane (tabelle di routing, policy, NAT, Firewall). Di norma é un elemento centralizzato non replicato
![[stackSDN.png | center ]]

Nonostante i notevoli vantaggi di flessibilitá, le SDN hanno alcune lacune legate soprattutto alle performance:
- Problemi prestazionali nelle interazioni con il controller
- Problemi prestazionali nel data plane (emulazione software)
- Complessità del controller



### Data plane
Lo standard de facto per i data plane é **OpenFlow**, il quale estende e generalizza la tabella di routing. Infatti in Openflow ogni riga della tabella é composta dai seguenti elementi:
- Predicato di match, il quale opera su numerosi campi (protocollo, porta, MAC address, interfaccia di ingresso). L'uso di predicati permette la deep packet inspection (campi di livelli differenti dello stack) e grande flessibilitá (il software a seconda del match puó operare come uno switch, un router o un firewall) a fronte, peró, di possibili problemi di prestazioni (dimensione tabelle)
- Azione
	- Inoltro, azione di default di router
	- Drop, azione di default di un firewall
	- Modifica di pacchetto (VLAN, NAT, load balancing)
	- Invio al controller (invia al control plane per sollevare situazioni non previste)
	- Metering & shaping, aggiornamento contatori e garanzia QoS
	- Gestione gerarchica di piú tabelle (primaria, secondaria) 
- Contatori, per gestire il traffico 
- Priorità  
- Time-out

Tra data plane e control plane, come giá visto abbiamo la Southbound interface che permette l'invio di messaggi tra i due livelli. Questi messaggi possono essere di tipologie diverse:
- Messaggi controller (censimento degli switch, cambio di configurazioni)
	- Features, lo switch mostra le sue possibilitá 
	- Configuration
	- Modify-State
- Messaggi asincroni, per informare il control plane di eventi sul data plane
	- Packet-in, manda il pacchetto al controller se non c'é match sulle tabelle 
	- Error
- Messaggi simmetrici, per verificare il funzionamento
	- Hello (ping) 
	- Echo



### Control plane
Sono disponibili diversi controller SDN (es. Onos e **Daylight**), non basati su standard comuni; hanno peró alcune caratteristiche architetturali comuni:
- Livello comunicazione (southbound), per interfacciarsi con i vari protocolli data plane (Openflow, [[SNMP]])
- Interfaccia applicazioni (northbound), tipicamente si usano API REST del protocolli [[HTTP]]. Inoltre consente di integrare la gestione della rete in altre logiche (VM, container) e di interfacciarsi con altri controller
- Visione globale della rete, non limitata ai singoli dispositivi (repository dello stato della rete SDN)

