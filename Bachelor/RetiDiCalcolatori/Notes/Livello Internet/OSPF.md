Il protocollo Open Shortest Path First è uno dei protocolli di routing (instradamento) di tipo [[Link state protocol]] più diffusi ed utilizzati all'interno di AS di primo livello. Utilizza il flooding (inondazione) di informazioni per inviare aggiornamenti sullo stato dei collegamenti, e l'algoritmo di Dijkstra per la determinazione del percorso a costo minimo. Ha varie funzioni migliorative rispetto a RIP:
- Sicurezza: autenticazione dei messaggi  OSPF con algoritmi di crittografia
- Possibilità di usare più percorsi per instradare il traffico (mentre è solo uno in RIP)
- Supporto integrato per instradamento unicast e multicast 
- Possibilità di strutturare grandi domini di instradamento in gerarchie di AS

I messaggi dell'OSPF sono composti, come quasi tutti i messaggi [[Internet]], da 2 elementi:
1. Header comune
	- Numero versione  
	- Tipo
		1. Hello (Scoperta di router adiacenti  e scambio di parametri per  funzionamento OSPF)
		2. DB description (Contenuto del Link State DB)
		3. Link state req  (Richiesta di informazioni relative a una porzione del Link State DB)
		4. Link state update (Mandato in risposta a request per aggiornare dello stato dei link)
		5. Link state ACK (acknowledgement update)
	- Dimensione (in bytes, incluso header) 
	-  Router ID (tipicamente IP dell’interfaccia da cui il messaggio è spedito) 
	- Area cui il messaggio appartiene (usato per gerarchie)
	- Checksum 
	- Tipo di autenticazione  
		1. 0 = Nessuna autenticazione  
		2. 1 = Password  
		3. 2 = Autenticazione crittografica 
	- Informazioni per autenticazione
2. Corpo del messaggio che dipende dal campo type
![[OSPF.png]]


Come già detto, l'OSPF permette di suddividere grandi AS in aree cosi da creare una gerarchia interna a due livelli:
1. Area backbone, area che  instrada il traffico tra le aree del sistema autonomo e che contiene tutti i router di confine. In particolare all'interno dell'area di backbone distinguiamo 3 tipologie di router:
	1. **Router di confine**: gestiscono l’instradamento verso altri AS 
	2. **Router di backbone**: effettuano l’instradamento all’interno dell’area  backbone  
	3. **Router di confine area**: comunicano i percorsi verso altre aree locali dell’AS ai router di quell’area
2. Aree locali
![[gerarchiaOSPF.png]]
