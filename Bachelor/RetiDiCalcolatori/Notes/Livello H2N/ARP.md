L’Address Resolution Protocol (ARP) si occupa di individuare l'indirizzo MAC di host della stessa LAN dato l’indirizzo [[IP]]. Per risolvere un indirizzo IP nel corrispondente MAC il protocollo ARP utilizza due tipi di messaggi:
1. Richiesta ARP in broadcast, contenente l’indirizzo IP del destinatario
2. Risposta ARP in unicast, contenente il corrispondente indirizzo MAC
![[ARP.png]]

Per ridurre il traffico sulla rete causato dallo scambio di messaggi ARP, ciascun host effettua un caching temporaneo delle risoluzioni IP/MAC nella propria tabella di instradamento. Per visualizzare la cache ARP possiamo utilizzare il seguente comando
```powershell
$ sudo arp 
```

Il frame ARP é formato dai seguenti campi:
1. Payload (28 byte)
2. Hardware type, per specificare il tipo di protocollo livello fisico
3. Network protocol type, per specificare il tipo di protocollo livello rete
4. Sender Hardware address 
5. Sender Network protocol address 
6. Target Hardware address 
7. Target Network protocol address 
8. Operation (1 = ARP richiesta , 2 = ARP risposta , 3 = [[RARP]] richiesta, 4 = RARP risposta)