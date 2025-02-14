Consideriamo la seguente sottorete.

![[D-Routing.png]]

Il nostro obiettivo è quello di far comunicare tutti i nodi e per far ciò potremmo utilizzare una configurazione bridge per far comunicare facilmente tutti i nodi ma non potremmo avere a disposizione 2 sottoreti. Rispettando la configurazione dovremmo ricorrere al protocollo IP e al routing per far comunicare le due sottoreti. 
Allo scopo di fare comunicare le sottoreti, si individuano degli host che svolgono il ruolo di router, che inoltrano pacchetti da una sottorete ad un'altra (nel nostro esempio H2 svolgerà la funzione di router).
- L'inoltro dei pacchetti viene determinato in base all'indirizzo IP destinazione  
- Il router riceve un pacchetto con un indirizzo IP destinazione non suo ed, invece di scartarlo, lo inoltra secondo regole di routing  
- Ogni host deve conoscere quali sono i router a cui può inviare i pacchetti nel caso in cui i destinatari non facciano parte della sua sottorete, e li identifica con il termine di gateway

Dovremmo procedere con la configurazione (statica) degli host e dei gateway, la quale comprende, la definizione di tabelle di routing su tutti gli host e l'abilitazione dell'ip forwarding sugli host identificati come gateway.
Dopo aver configurato gli host modificando il file /etc/network/interfaces, testiamo la comunicazione tra gli host.

1. H1 ping H2
```powershell
$ ping 192.168.1.254
> PING 192.168.1.254 (192.168.1.254) 56(84) bytes of data.
> 64 bytes from 192.168.1.254: icmp_seq=1 ttl=64 time=1.71 ms
> 64 bytes from 192.168.1.254: icmp_seq=2 ttl=64 time=0.940 ms
> .....
> ...
```

2. H1 ping H3
```powershell
$ ping 192.168.1.254
> connect: Network is unreachable 
```

Se eseguiamo il ping tra H1 ed H3, i quali si trovano su 2 sottoreti diverse, la comunicazione fallisce (con arping possiamo comunque raggiungerlo). Per permette la comunicazione tra H1 e H3 dobbiamo configurare la tabella di routing. Prima di aggiungere regole manualmente alla tabella di routing dobbiamo visualizzarla per capire quali regole eventualmente aggiungere.

```powershell
$ ip route show (old version)
> 192.168.1.0/24 dev eth0 proto kernel scope link src 192.168.1.1
$ route -n
> Kernel IP routing table
> Destination     Gateway         Genmask         Flags Metric Ref  Use Iface
> 192.168.1.0     0.0.0.0         255.255.255.0   U     0    0      0   eth0
```

Notiamo che le tabelle non sono vuote, questo succede perchè le regole vengono aggiornate non appena portiamo nello stato up-running le interfacce di rete eth0,eth1,... .
Per comunicare a H1 che per arrivare ad H3 deve passare per H2 dobbiamo aggiornare la tabella di routing di H1 e H3. Per far ciò dobbiamo modificare il file /etc/network/interfaces.

```powershell
$ nano /etc/network/interfaces
```

Aggiungiamo il default router con la parola chiave gateway. In questo modo stiamo impostando un default gateway, cioè la destinazione di default per tutte le destinazioni target che non soddisfano nessuna delle regole presenti nella tabella di routing.

```powershell
auto eth0
iface eth0 inet static
	address 192.168.1.1/24
	gateway 192.168.1.254
```

Riprovando ad eseguire il ping, notiamo che l'errore "network is unreacheble" non compare ma il traffico generato si blocca. Questo succede perchè su H2 non è abilitato l'ip forwarding e quindi i pacchetti arrivano sulla porta eth0 di H2 ma non vengono inoltrati alla porta eth1. Per abilitare questa funzionalità dobbiamo attivare un flag (di default è disabilitato); prima di modificarlo visualizziamone lo stato con il seguente comando:

```powershell
$ sysctl net.ipv4.ip_forward
> net.ipv4.ip_forward = 0
```

Per abilitare la funzionalità temporaneamente, usiamo il seguente comando:

```powershell
$ sysctl -w net.ipv4.ip_forward=1
> net.ipv4.ip_forward = 1
```

Invece per abilitarla permanentemente, modifichiamo il file /etc/syctl.conf, decommentiamo la linea net.ipv4.ip_forward  = 1 (attenzione a non decommentare anche l'ultima riga) e riavviamo il networking per apportare le modifiche.

```powershell
$ nano etc/sysctl.conf
$ sysctl -p etc/sysctl.conf
> net.ipv4.ip_forward = 1
```

Possiamo aggiungere le regole di routing anche senza utilizzare il defaul gateway, ma specificando determinate regole attraverso i seguenti comandi:

```powershell
Verso un host:
$ route add -host <ip> gw <gwaddr>
$ ip route add <ip/32> via <gwaddr>

Verso una subnet:
$ route add -net <net> netmask <nm> gw <gw>  
$ ip route add <net/cidr> via <gwaddr>

Impostando default gateway:
$ route add default gw <gwaddr>  
$ ip route add default via <gwaddr>
```

Queste comandi permettono solo una configurazione temporanea, per impostare tabelle di routing dobbiamo modificare il file /etc/network/interfaces.

```powershell
$ nano /etc/network/interfaces
auto eth0
iface eth0 inet static
	address 192.168.1.1/24
	post-up ip route add 192.168.2.0/24 via 192.168.1.254
```

Attraverso la direttiva post-up possiamo applicare regole e comandi che verrano eseguiti in seguito all' attivazione delle interfacce di rete (up eth0).