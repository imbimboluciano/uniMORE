Il Post Office Protocol (detto anche POP) è un protocollo di livello applicativo di tipo client-server che ha il compito di permettere, mediante autenticazione, l'accesso da parte del client ad un account di posta elettronica presente su un host server e scaricare le e-mail dell'account stesso. É un protocollo statefull e quindi prevede delle fasi di comunicazione:
1. Fase di instaurazione della connessione (connessione TCP su porta 110)
2. Fase di autorizzazione
3. Fase di transazione, in cui l'user agent recupera i messaggi
	- Recupera tutti i messaggi
	- Recupera i messaggi selezionati dal filtro
	- Recupera i messaggi selezionati dall'utente
4. Fase di aggiornamento, vengono cancellati dalla mailbox i messaggi eventualmente indicati come tali dall’utente
![[comunicazionePOP.png | center | 550]]


Anche per il protocollo POP esiste una versione sicura, la quale integra funzionalitá di sicurezza, chiamata POPs.