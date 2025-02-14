Nella realtà, i router di Internet non rappresentano un insieme omogeneo di risorse e quindi vengo aggregati in “regioni” o sistemi autonomi (AS), cioé insieme di nodi e router gestiti da un’unica entità di controllo centrale (ISP). Per gestire la scalabilitá e ridurre la complessitá del calcolo del cammino ogni organizzazione (ISP) sceglie autonomamente le proprie politiche di routing, cioè le regole per instradare e filtrare il traffico. In base alle politiche di routing implementate gli AS si dividono in 3 principali categorie:
- Stub -> AS con una sola connessione ad un altro AS
- Multi-homed -> AS connesso con diversi AS, ma non permette traffico che non è generato o diretto verso l’AS (non inoltra il traffico)
- Transit -> AS connesso a diversi AS che consente di fare da tramite per gli AS a cui è collegato

Per il routing all’interno di un AS (Intra-AS) i router utilizzano gli Interior Gateway Protocol, tra i quali i più diffusi sono il RIP(Routing Information Protocol) e l'[[OSPF]] (Open Shortest Path First); invece per il routing verso altri AS (Inter-AS) viene utilizzato l'Exterior Gateway Protocol, tra cui il più diffuso è il [[BGP]] (Border Gateway Protocol)
![[policyrouting.png]]
