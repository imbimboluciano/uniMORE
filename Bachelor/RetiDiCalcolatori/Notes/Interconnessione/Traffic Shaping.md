Il traffic shaping riguarda la gestione dei flussi di traffico, cioè si vuole ottimizzare la scelta dei pacchetti inviati su un link con capacità trasmissiva limitata.
- prioritizzazione del traffico  
- minimizzazione della latenza  
- gestione della banda
- garanzia "fairness"


Ogni interfaccia di rete dispone di almeno una coda dei datagrammi da inviare in rete ed ogni coda è gestita ogni coda è gestita da una queuing discipline (qdisc). Le qdisc possono essere di 2 tipi:
- **classless**: possono riordinare, ritardare o eliminare dei pacchetti in coda 
	- pfifo_fast  
		![[pfifo.png]]
	- tbf (Token Bucket Filter), la quale modella il traffico come un secchio di token.
		- il secchio si riempie a ritmo costante  
		- spedire dati consuma dei token  
		- non si inviano dati se non ci sono abbastanza token disponibil
		![[tbf.png]]
- **classful**: sono dei “contenitori” per ulteriori qdisc (classless o classful). Consentono di organizzare gerarchicamente le qdisc ed applicare filtri.
	- prio (Priority)
	- htb (Class Based Queueing)
	- cbq (Hierarchical Token Bucket)


Le qdisc e le classi sono identificate da handle tramite una notazione di due byte, nella forma **major:minor**.![[gerarchiaqdisc.png]]

Per visualizzare le regole e le statistiche qdisc di una determinata interfaccia dobbiamo utilizzare il seguente comando:
```powershell
$ tc [-s] qdisc show dev <iface>
>>> qdisc pfifo_fast 0: root refcnt 2 bands 3  
>>> priomap 1 2 2 2 1 2 0 0 1 1 1 1 1 1 1 1
```
- pfifo_fast nome della queue discipline attualmente impostata
- 0: identificatore qdisc (essendo la root class il minor viene omesso)
- bands 3 numero di bande (3=default)
- priomap mappa che indica a quale banda assegnare ogni pacchetto a seconda del valore del campo TOS dell'header IP

I comandi principali del traffic shaping sono i seguenti:
1. Impostare la root qdisc
```powershell
$ tc qdisc add dev <iface> root [handle <handle>] <qdisc-type> <qdisc-options>
```
2. Aggiungere classe ad un handle
```powershell
$ tc class add dev <iface> parent <class-handle> <qdisc-type> <qdisc-options>
```
3. Aggiungere filtro
```powershell
$ tc filter add dev <iface> protocol <proto> parent <qdisc-handle> u32 match  
<proto-rule> flowid <class-handle>
```
4. Eliminare la qdisc root
```powershell
$ tc qdisc del dev <iface> root
```
5. Eliminare la qdisc corrispondente ad un handle
```powershell
$ tc qdisc del dev <iface> handle <handle>
```



