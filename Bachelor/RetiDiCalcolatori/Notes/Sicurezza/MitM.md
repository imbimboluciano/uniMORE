Attacco Man in the Middle è una terminologia impiegata nella crittografia e nella sicurezza informatica per indicare un attacco informatico in cui qualcuno segretamente ritrasmette o altera la comunicazione tra due parti che credono di comunicare direttamente tra di loro. Questi attacchi sfruttano la dinamicità delle configurazioni, le transazioni non autenticate e non cifrate e il dominio di broadcast. Possono peró scatenare degli effetti collaterali: 
-  Possibili malfunzionamenti della rete  
- Produzione di elevati volumi di traffico «anomalo» → facilmente identificati da sistemi di analisi del traffico di rete (NIDS)

![[MitM.png]]
Eve può sniffare, manipolare e bloccare il traffico con Alice e Bob che non si accorgano di nulla (a parte un po’ di ritardo aggiuntivo ed alcune «stranezze» di basso livello). I principali attacchi MitM sono l'[[#ARP spoofing]], il [[#Port stealing]] ed il [[#DHCP poisoning]]. 



### ARP spoofing
Consiste nell'inviare intenzionalmente e in modo forzato risposte ARP contenenti dati inesatti o, meglio, non corrispondenti a quelli reali. In questo modo la tabella ARP di un host conterrà dati alterati (da qui i termini poisoning/spoofing). Come posso convincere Alice a mandare pacchetti a Eve invece che a Bob forgiando pacchetti ARP?

Dal terminale eseguire il seguente comando:
```powershell
$ ettercap –T –M arp /192.168.1.1//
#option -M per specificare che vogliamo fare un attacco MitM
#arp per arp spoofing
#option -T per text mode
# /indirizzo IP mittente/indirizzo IP destinatario/ per indicare l'host da attaccare
```

In questo modo indirizziamo il traffico tra alice e bob verso eve. Per evitare questo tipo di attacco possiamo creare associazioni statiche MAC/IP su alice e bob (impraticabile a livello aziendale, quindi la maggior parte delle LAN rimangono vulnerabili a questo tipo di attacco). 
```powershell
$ arp -s address hwaddress
# possiamo settare una entry della tabella ARP
```

Alla fine dell'attacco l'attaccante ripristina la situazione iniziale, inviando delle ARP reply con MAC address corretti.



### Port stealing
Anche in caso di associazioni statiche, è possibile sniffare traffico ingannando lo switch attraverso l'attacco di port stealing (funziona meno dell'ARP spoofing). Eve cerca di convincere lo switch ("rubando la porta") che bob é attaccato alla stessa porta a cui é attaccato eve. Come può eve «convincere» lo switch a inoltrare a lei i pacchetti diretti verso alice? Mandando un messaggio Ethernet da eve allo switch con il MAC address di bob cosí da ingannare l'autoapprendimento dello switch.

```powershell
$ ettercap –T –M port /192.168.1.1//
# port per port stealing
```

Questo tipo di attacco funziona solo parzialmente perché eve ha bisogno che lo switch funzioni correttamente per inoltrare il messaggio a bob. Per evitare questo tipo di attacco possiamo creare associazioni statiche MAC/porta sullo switch (non supportato da vde_switch).



### DHCP poisoning
In questo tipo di attacco l'attaccante cerca di impersonare il ruolo di DHCP server della rete (bisogna vincere la resistenza del vero DHCP server). Con questo tipo di attacco possiamo fare diverse cose, in base a cosa viene configurato automaticamente:
- L'attaccante puó anche impersonare la "vittima" prendendo il suo IP e dandole un IP diverso
- L'attaccante puó impostarsi come gateway di default della "vittima"
- L'attaccante puó cambiare il name server della "vittima", impostandosi come DNS server

```powershell
$ ettercap –T –M dhcp:192.168.1.5-10/255.255.255.0/192.168.1.3
# dhcp per dhcp poisoning
```

Per evitare questo tipo di attacco possiamo configurare staticamente le interfacce di rete degli host della rete.