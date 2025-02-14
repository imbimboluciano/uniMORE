Il Simple Network Management Protocol è un protocollo applicativo per lo scambio di informazioni utili alla gestione della rete:
- Tenere traccia dei dispositivi in una rete e delle loro funzioni (temperatura)
- Identificare problemi attraverso una determinata policy e predisporre soluzioni temporanee o definitive
- Gestione delle prestazioni (capacity planning e degrado prestazioni)
- Gestione dei costi

Vista l'eterogeneità dei dispostivi da gestire è necessaria un'interfaccia di gestione standardizzata, estendibile, portabile e poco costosa. Per questo motivo SNMP cerca di rimanere il più leggero possibile per essere implementato in tutti dispositivi da gestire, senza gravare sulle prestazioni. Per essere leggero e veloce SMNP si appoggia al protocollo [[UDP]] ed utilizza le porte 161 e 162.

Il SNMP è stato definito in 3 principali versioni:
1. SNMPv1 standard,
2. SNMPv2 e SNMPV3 estensioni di SNMP per consentire monitoraggio distribuito e supportare meccanismi di sicurezza aggiuntivi

L'architettura di comunicazione SNMP è formata da 2 ruoli:
1. **Agent** (server) che gira sui dispositivi da gestire. In base all'implementazione nella rete gli agent si dividono in 3 diverse categorie: 
	- Estensibili, consentono di definire nuovi tipi di dati e di operazioni
	- Monolitici, ottimizzati per una specifico HW
	- Proxy e Gateway, per gestione di dispositivi che non supportano  nativamente SNMP
2. **Manager** (client) che interpella gli agenti per raccogliere informazioni e dare comandi. 

Il protocollo SNMP ribalta, in parte, la classica architettura client-server perché il  server SNMP (agent), rispetto ai Web server classici centrali nell'architettura client-server, è periferico nella locazione (risiede nei dispositivi da gestire). Per questo motivo abbiamo 2 modalitá per gestire la rete:
- **Client pull**, nella quale il client (manager) interroga i server (agent) per la raccolta di informazioni (approccio tipico)
- **Server push**, nella quale i server (agent) possono segnalare anomalie contattando i manager (client) mediante messaggi di tipo trap (in modo asincrono)


Il protocollo SNMP, al fine di gestire correttamente la rete, definisce le seguenti strutture dati:
- **Management Information Base (MIB)**, mappa gerarchica degli oggetti gestiti e a cui è possibile accedere. I MIB possono essere estesi aggiungendo sottoalberi. 
- Messaggi scambiati tra agent e manager
	- Get, recupera un valore da una MIB in un agente remoto
	- GetNext, recupera valore successivo navigando dentro ad una MIB
	- GetBulk, get di elementi multipli
	- Set, imposta un valore in una variabile di una MIB
	- Trap, notifica asincrona da un agent a un manager (failure), formata dai seguenti campi:
		- Priorità associata (Critica, Major, Minor, Warning)
		- Informazione
In caso di Trap le tipiche reazioni sono le seguenti:
- Interrogazione per avere informazioni maggiori
- Invio di mail di notifica a gli amministratori  
- Logging

Le varie funzioni monitorate vengo identificate da un ObjectID(OID) ed la navigazione dell’albero é dall’alto verso il basso. La gerarchia viene definita attraverso una serie di OIDs separati da '.' (Es. 1.3.6.1).
![[MIB.png | center | 525]]

I vari elementi di rete gestiti dal protocollo SNMP sono chiamati nodi. I nodi possono essere di diverso tipo in base al ruolo che assumono nella rete:
- Nodi gestiti, i quali ospitano un agent SNMP 
- Nodi gestori, i quali ospitano un manager SNMP  
- Nodi non gestiti, i quali non supportano SNMP, ma possono essere gestiti mediante proxy che gira su un altro nodo
Inolte i nodi possono anche essere aggregati all'interno di una community per partizionare il dominio.

Insieme ad SNMP vengono introdotti anche dei linguaggi per gestire la rete:
- **Structure of Management Information (SMI)**, regole per definire la struttura dei messaggi
- **Abstract Syntax Notation 1 (ASN.1)**, definisce i messaggi e le MIB in formato  privo di ambiguità (sintassi simile al C). ASN rappresenta il codice sorgente.
- **Basic Encoding Rules (BER)**, codifica i messaggi SNMP in formato network-friendly (ottengo un formato binario, piccolo ed efficiente). BER rappresenta l'eseguibile.

Il formato dei messaggi SNMP è il seguente.
![[SNMP.png | 450]]
