L'Internet Control Message Protocol  è un protocollo di supporto [[IP]] che si occupa di trasmettere informazioni riguardanti malfunzionamenti, informazioni di controllo o messaggi tra i vari componenti di una rete (è incapsulato all'interno di [[IP]]). ICMP interviene quando c’è una anomalia nel processo di instradamento e una condizione di  errore deve essere notificata al mittente del  
pacchetto; in particolare risulta molto utile all’amministratore della rete per testare la raggiungibilità al livello IP di un host remoto con un dato indirizzo.
![[ICMP.png]]

I principali messaggi di errore sono i seguenti:
- **TIME_ EXCEEDED**(tempo scaduto) -> il pacchetto ha TTL=0
- **DESTINATION_UNREACHABLE**
- **PARAMETER_PROBLEM** -> Il gateway non riesce ad interpretare il  pacchetto ricevuto a causa di un valore errato, possibile errore software

Invece i principali messaggi di informazioni sono i seguenti:
- **ECHO_REQUEST e REPLY** -> controllo di raggiungibilità di un host
- **TIMESTAMP e TIMESTAMP_REPLY** -> come echo ma con informazioni aggiuntive
- **REDIRECT** -> un router intermedio si accorge che il prossimo router cui  dovrebbe inoltrare il pacchetto sta sulla stessa LAN del mittente

I comandi che usano messaggi ICMP sono ping e traceroute.
```powershell
$ ping 192.168.1.1
# Invia una successione di pacchetti ICMP ECHO_REQUEST e attende la relativa risposta ECHO_REPLY

$ traceroute 192.168.1.1
# Il comando traceroute permette di capire per quali router passano i pacchetti IP quando sono diretti ad una data destinazione.
```