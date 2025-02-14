Un nodo deve essere configurato per poter connettersi alla rete. La configurazione puó essere statica o dinamica. Gestire in modo statico le configurazioni su ogni nodo è problematico  per diversi problemi:
- Manca un registro centrale degli indirizzi attribuiti  
- Si rischia di creare conflitti  
- Ogni modifica richiede di essere implementata su ogni nodo coinvolto  
- La presenza di nodi mobili aggrava il problema

Attraverso invece la configurazione dinamica possiamo gestire in modo centralizzato l'assegnazione dell'indirizzo IP, netmask, gateway e DNS. Questo consente anche di controllare gli accessi alla rete. Il protocollo per gestire la configurazione dei nodi alla loro connessione é il DHCP (Dynamic Host Configuration Protocol):
1.  Il nodo (client) appena connesso non sa come deve configurarsi  e quindi manda una richiesta generica “alla rete” (in broadcast)  
2. La rete invia i parametri di configurazione

Vediamo in dettaglio come funziona la procedura di configurazione di un host da parte del server DHCP:
1. Il client assume un indirizzo “provvisorio” per mandare  le sue richieste (0.0.0.0:68-255.255.255.255:67) incapsulati in un frame UDP
2. Il Client manda al server un DHCP_DISCOVER per richiedere se ci sono indirizzi di rete disponibili
3. Il Server risponde offrendo una possibile configurazione con DHCP_OFFER
4. Il Client richiede ed accetta uno degli indirizzi offerti con DHCP_REQUEST
5. Il Server con un messaggio di DHCP_ACK concede l'indirizzo richiesto

Il DHCP server si appoggia al protocollo [[UDP]] porta 67 e il DHCP client si appoggia al protocollo UDP porta 68.

Il server tiene traccia degli indirizzi che ha inviato, evitando conflitti. Inoltre ogni indirizzo è dato in prestito solo temporaneamente, cioé ogni indirizzo ha un lease time che deve essere rinnovato periodicamente.

### Installazione DHCP
Vediamo ora come installare un server DHCP e come permettere la configurazione automatica degli host (utilizzeremo DNSMasq). Sulla rete deve esserci un solo server DHCP raggiungibile a livello H2N da ogni nodo della rete. Per la configurazione abbiamo bisogno di alcuni elementi:
- Server DNS (perché DNSMasq fa anche da server DNS), Gateway, Lease Time
- Pool di indirizzi da assegnare liberamente
- Indirizzi riservati da assegnare ad un nodo ben preciso (Server DHCP)

![[DHCPNetwork.png]]

Client3 sará l'unico client con indirizzo IP fisso. Per far ció dobbiamo modificare il file /etc/network/interfaces impostando un determinato MAC.
```powershell
auto eth0 
iface eth0 inet dhcp
	hwaddress 02:04:06:11:22:33 (i primi 3 byte sempre 02:04:06)
```

Per il resto dei client il file /etc/network/interfaces sará configurato nel seguente modo:
```powershell
auto eth0  
iface eth0 inet dhcp
```

Invece sul server DHCP avremo bisogno di un indirizzo statico:
```powershell
auto eth0  
iface eth0 inet static
	address 192.168.1.254
```

Per configurare il server DNS e DHCP dovremmo modificare il file /etc/dnsmasq.conf, decommentando o aggiugendo le seguenti linee:
```powershell
# don't look for other nameservers
no-resolv
# leggi il file /etc/ethers
read-ethers
# interfaccia DHCP
interface=eth0
# Nome del dominio per DNS
domain=reti.org

# Opzioni DHCP
dhcp-option=option:router,192.168.1.254 #dhcp-option=3,192.168.1.254 (3 = default GW)
dhcp-option=option:dns-server,192.168.1.254 #dhcp-option=6,192.168.1.254 (6 = DNS)
#DHCP range IP con anche lease time
dhcp-range=192.168.1.10,192.168.1.15,1h
#Configurazione statica di un host(client3)
dhcp-host=02:04:06:11:22:33,client3,192.168.1.3,1h
#oppure 02:04:06:11:22:33 192.168.1.3 in \etc\ethers

#address (é possibile metterlo anche in /etc/hosts)
address=/www.hackerz.com/192.168.1.1
```

**N.B.** La regola range deve esserci sempre anche in caso di soli host con MAC fisso
(il range non deve includere eventuali host con MAC fisso)

Infine per permettere al server DNS la risoluzione dei nomi di dominio dobbiamo modificare il file /etc/hosts.
```powershell
192.168.1.254 server server.reti.org  
192.168.1.3 client3 client3.reti.org
192.168.1.1 hackerz www.hackerz.com
```

Infine per avviare e lanciare il server dobbiamo utilizzare i seguenti comandi:
```powershell
$ systemctl enable dnsmasq
$ service dnsmasq start
```


### Verifica configurazione
Per la configurazione DHCP dobbiamo verificare l'assegnazione di IP, netmask, gateway e lease time. 
```powershell
$ ip addr show dev eth0
$ ip route show dev eth0
```

Invece per la verifica del DNS dobbiamo verificare la risoluzione IP-dominio.
```powershell
$ cat /etc/resolv.conf  
$ nslookup client3  
$ nslookup client3.reti.org  
$ nslookup www.hackerz.com
```
