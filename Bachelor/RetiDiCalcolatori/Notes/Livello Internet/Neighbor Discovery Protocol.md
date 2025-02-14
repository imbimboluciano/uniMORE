Il Neighbor Discovery Protocol (NDP) è un protocollo nella suite di protocolli Internet utilizzato da [[IPv6]]. Opera a livello di accesso alla rete ed è impiegato per le seguenti funzioni:
- Autoconfigurare gli indirizzi dei nodi (sostituisce DHCP)
- Individuare altri nodi sulla rete (apprendimento parametri come MTU e hop limit)
- Recuperare l'indirizzo di accesso alla rete degli altri nodi (sostituisce ARP)
- Identificare quando un vicino non è più raggiungibile.
- Identificare un nodo che usa il medesimo indirizzo IP di un’altro
- Informare un router di una destinazione migliore per raggiungere una  destinazione (redirect).
- Un nodo che sa di aver cambiato indirizzo MAC può mandare un messaggio di tipo Neighbor Advertisement agli altri nodi per aggiornare la loro cache (link-layer address change)
- I router possono non comunicare i loro MAC address per consentire una risposta selettiva quando più router possono gestire lo stesso percorso (load balancing)

Per adoperare queste funzionalità utilizza 5 tipi di pacchetto ICMPv6 ed indirizzi multicast:
1. **Router Solicitation**: Inviato quando un’interfaccia viene attivata. Serve per chiedere ai router presenti nella rete di mandare messaggi di tipo Router  Advertisement immediatamente
2. **Router Advertisement**: I router inviano periodicamente un messaggio che informa la rete della loro presenza. Il messaggio può essere mandato anche in risposta a una Router Solicitation
3. **Neighbor Solicitation**: Mandato da un nodo per ottenere l’indirizzo MAC di di un vicino. Può essere usato anche per determinare se il vicino è ancora raggiungibile (tipo arping).
4. **Neighbor Advertisement**: Risposta a messaggio di tipo Neighbor Solicitation
5. **Redirect**: Inviato da un router per informare un nodo di una possibile strada  migliore per una destinazione

![Address Resolution](NDP.png)
