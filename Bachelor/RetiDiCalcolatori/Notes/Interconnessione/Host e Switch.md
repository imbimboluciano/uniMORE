Collegare in rete due nodi tramite uno switch, in modo che possano comunicare tramite hostname ed indirizzi IP.

![[firstnetwork.png]]

Per connettere host e switch, cioè dispositivi di livello diverso, si usano i cavi dritti, invece per connettere dispositivi di rete dello stesso livello (switch-switch) si usano cavi cross. In questo abbiamo utilizzato solo cavi dritti non essendoci altri apparati di rete.
Abbiamo collegato la porta eth0 di ogni host alla porta 0 e 1 dello switch.

Per assegnare temporaneamente l'hostname possiamo usare il comando:  
```powershell
$ hostname <nome>  
```

Invece, per assegnare in modo permanente l'hostname della macchina che stiamo configurando, dobbiamo editare il file /etc/hostname in modo che contenga il nome  
del nodo ([[Marionnet]] di default assegna un nome univoco).

Allo start della simulazione le rispettive porte eth0 di norma non sono attive, per verificarlo possiamo usare il seguente comando sui terminali degli host.

```powershell
$ ip link show dev eth0
> 8: eth0: <BROADCAST,MULTICAST> mtu 1500 qdisc noop state DOWN mode DEFAULT group default qlen 1000
    link/ether 02:04:06:80:5b:46 brd ff:ff:ff:ff:ff:ff
```

Notiamo che lo stato é "DOWN", per attivare la porta eth0 dobbiamo portarla "up" attraverso il seguente comando:

```powershell
$ ip link set dev eth0 up 
$ ifconfig eth0 up (old version)
$ ip link show dev eth0
> 8: eth0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UNKNOWN mode DEFAULT group default qlen 1000
    link/ether 02:04:06:80:5b:46 brd ff:ff:ff:ff:ff:ff
```

Per testare la connessione tra due nodi non utilizzando protocolli che si appoggiano al livello Internet,non avendo a disposizione indirizzi IP, ed utilizzando solo protocolli di livello H2N dobbiamo seguire i seguenti passi:

1. Generare traffico da un nodo (h1) attraverso il protocollo arp  con il comando arping
```powershell
$ arping -B -0 -i eth0 (arping -B0i -eth0 forma compatta):
	-B broadcast (255.255.255.255)
	-0 (ip 0.0.0.0 host in this network)
	-i (interfaccia di rete)
> ARPING 255.255.255.255  
> Timeout  
> Timeout  
> Timeout  
> Timeout  
> Timeout
```
2. Ascoltare il traffico dall'altro nodo (h2), intercettando il traffico arp
```powershell
$ tcpdump -ni eth0 arp
> tcpdump: verbose output suppressed, use -v or -vv for full protocol decode  
> listening on eth0, link-type EN10MB (Ethernet), capture size 262144 bytes  
> 15:45:20.071611 ARP, Request who-has 255.255.255.255 tell 0.0.0.0, length 28  
> 15:45:21.080772 ARP, Request who-has 255.255.255.255 tell 0.0.0.0, length 28
```

Soffermiamoci un attimo sul comando tcpdump, analizzando alcune opzioni del comando abbastanza importanti:
```powershell
$ tcpdump [ -adeflnNOpqRStuvxX ] [ -c count ]  
			[ -C file_size ] [ -F file ]  
			[ -i interface ] [ -m module ] [ -r file ]  
			[ -s snaplen ] [ -T type ] [ -w file ]  
			[ -E algo:secret ] [ expression ]
```
- -c Termina dopo aver ricevuto count pacchetti  
- -e Visualizza gli header a livello DATA LINK  
- -E Utilizza algo:secret per decifrare i pacchetti IPsec  
- -i Rimane in ascolto sull’interfaccia di rete indicata  
- -n Non converte gli indirizzi (IP, di porta...) in nomi  
- -r Legge i pacchetti dal file file  
- -X Visualizza i pacchetti in formato hex e ascii

Quando Tcpdump termina la sua esecuzione fornisce un report riguardante il numero di  
pacchetti ricevuti ed il numero di pacchetti scartati dal kernel.  
```powershell
> 244 packets received by filter  
> 76 packets dropped by kernel
```

Inoltre, attravero le expression possiamo definire i criteri qualitativi coi quali scegliere i pacchetti da visualizzare (proto, type, dir). 

Adesso configuriamo gli indirizzi ip per inviare richieste arp specifiche. Per configurare un indirizzo IP in modo temporaneo possiamo utilizzare il seguente comando.
```powershell
$ ifconfig eth0 192.168.1.2
$ ip addr add dev eth0 192.168.1.2
```

Possiamo visualizzare gli indirizzi IP assegnati alle nostre interfacce di rete con il comando:
```powershell
$ ip addr show
$ ifconfig
```

Riprovando a fare arping da H1, questa volta verso un indirizzo IP specifico (H2), noteremo che H2 riceverà le richieste ARP e sarà in grado di rispondere ad H1.
```powershell
$ arping -0i eth0 192.168.1.2  
> ARPING 192.168.1.2  
> 42 bytes from 02:04:06:0f:47:dc (192.168.1.2): index=0 time=1.011 sec  
> 42 bytes from 02:04:06:0f:47:dc (192.168.1.2): index=1 time=1.008 sec  
> 42 bytes from 02:04:06:0f:47:dc (192.168.1.2): index=2 time=1.010 sec
```
```powershell
$ tcpdump -ni eth0 arp  
> tcpdump: verbose output suppressed, use -v or -vv for full protocol decode  
> listening on eth0, link-type EN10MB (Ethernet), capture size 262144 bytes  
> 08:04:55.933331 ARP, Request who-has 192.168.1.2 tell 0.0.0.0, length 28  
> 08:04:55.933365 ARP, Reply 192.168.1.2 is-at 02:04:06:0f:47:dc, length 28  
> 08:04:56.943018 ARP, Request who-has 192.168.1.2 tell 0.0.0.0, length 28  
> 08:04:56.943055 ARP, Reply 192.168.1.2 is-at 02:04:06:0f:47:dc, length 28
```


Per configurare in modo permanente le interfaccie di rete dobbiamo modificare il file /etc/network/interfaces.
```powershell
$ nano /etc/network/interfaces
  auto eth0
  iface eth0 inet static
	  address 192.168.1.2
```

Attraverso la direttiva iface possiamo configurare l'interfacci di rete specificata. Per far ciò possiamo utilizzare diverse modalità: 
- dhcp = inizializzazione dell'interfaccia in modo automatico col protocollo dhcp  
-  loopback = interfaccia locale (127.0.0.1)  
-  static = configutazione statica in cui possiamo impostare i diversi parametri dell'interfaccia (address, netmask, network, broadcast, gateway)

Modificando il file non avremo ancora apportato le modifiche (abbiamo solo modifcato un file su disco), per attivare l'interfaccia configurandola utilizzando i file di configurazione, possiamo utilizzare i comandi ifup e ifdown.
```powershell
$ ifup eth0 (-a per tutte le interfacce)
$ ifdown eth0
```

Infine per visualizzare le tabelle di arp/cache arp possiamo utilizzare i seguenti comandi.
```powershell
$ arp
> Address HWtype HWaddress Flags Mask Iface  
> 192.168.1.2 ether 02:04:06:64:66:db C eth0

$ ip neigh
> 192.168.1.2 dev eth0 lladdr 02:04:06:64:66:db REACHABLE
```
