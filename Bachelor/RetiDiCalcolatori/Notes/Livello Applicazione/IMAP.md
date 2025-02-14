Più funzionalità e maggiore complessità rispetto al protocollo [[POP]]. Infatti il server IMAP deve essere in grado di gestire una gerarchia di mailbox per ogni utente e tenere traccia dello stato dei messaggi. Rispetto al protocollo POP permette le seguenti operazioni:
- Permette all’utente di modificare la propria mailbox come se fosse locale (operazioni tipiche del file system)
- Permette all’utente di ottenere alcune parti del messaggio (bilancio del carico)

Anche il protocollo IMAP si appoggia al livello trasporto al protocollo [[TCP]] ed é statefull quindi la comunicazione é composta da diverse fasi:
- Fase di instaurazione della connessione TCP
- Fase di autorizzazione
- Fase di transazione



Anche per il protocollo IMAP esiste una versione sicura, la quale integra funzionalitá di sicurezza, chiamata IMAPs.