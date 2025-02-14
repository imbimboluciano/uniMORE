Perché usare UDP anziché TCP?
- Non c’è instaurazione della connessione (non introduce un ritardo)
- Non c’è stato di connessione (maggior numero di "connessioni" attive)
- Overhead minore dovuto all’header del segmento più piccolo
- Flusso di invio non regolato, infatti il controllo di congestione del TCP può avere un forte impatto (negativo) sulle applicazioni di rete in real-time

Per questo motivo UDP viene utillizzato se si opera su rete locale, non è importante che tutti i pacchetti arrivino a destinazione (streaming) e l’applicazione gestisce meccanismi di ritrasmissione.

Vediamo ora quali protocolli applicativi supportano il TCP e quali l'UDP:
1. Posta elettronica ([[SMTP]]), accesso da terminale remoto (Telnet) , Web ([[HTTP]]) trasferimento di file (FTP)  → TCP
2. Aggiornamento tabelle di routing in RIP → UDP
3. [[DNS]] query → UDP
4. Telefonia Internet → UDP
5. Applicazioni multimediali → UDP
6. Gestione della rete [[SNMP]] → UDP