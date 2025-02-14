Un data center è fondamentalmente una struttura fisica usata dalle aziende per conservare applicazioni e dati importanti. Un moderno data center é composto da tantissimi host, i quali ospitano decine se non centinaia di Virtual Machine e Container. Per gestire questa moltitudine di componenti abbiamo bisogno di un meccanismo di scalabilitá on-demand. 

Qualsiasi data center é costruito su una struttura gerarchica formata da router, switch, reti di connessione interna e rack, cioé le strutture meccaniche di sostegno su cui sono montate le parti hardware (chassis e blade system che compongono gli host). Per formare una struttura gerarchica ogni rack é dotato di switch, chiamato Top-of-Rack (ToR), che lo collegano alla rete interna; a loro volta gli switch Top-of-Rack sono collegati ad un altro elemento di switching chiamato End of Row (EoR) (Rack di switching per ogni fila). 
A livello organizzativo un data center é formato da 3 livelli principali:
1. Core Layer, backbone del data center che permette la connessione all'esterno
2. Aggregation Layer, connette le varie zone del data center
3. Edge Layer (Top-of-Rack switch)
![[datacenter.jpg | center | 600]]

Negli anni per migliorare le performance, oltre allo sviluppo hardware ed alla replicazione dei server, si é posto l'accento sulla [[virtualizzazione]]. Infatti i moderni data center sono decisamente diversi da quelli precedenti. L'infrastruttura si è spostata dai tradizionali server fisici on-premises alle reti virtuali in grado di supportare applicazioni e carichi di lavoro su più infrastrutture fisiche e in un ambiente multicloud.