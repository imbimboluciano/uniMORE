Iptables è un software applicativo (user space) per implementare funzionalità di Packet Filtering (sia statico che dinamico), di Inspection, di [[NAT]] e di marking dei pacchetti. Presente in tuttte le maggiori distribuzioni Linux a partire dal Kernel 2.4, puó essere utilizzato sia per un firewall personale che aziendale. Per interfacciarsi con il Kernel Linux, IPtables sfrutta il modulo [[#Netfilter]], il quale opera fornendo agganci (hooks) al sistema operativo utilizzabili per intercettare i pacchetti in transito. 
Le regole definite poi con IPtables permettono di implementare delle funzioni di gestione, associate ad un determinato hook.  Ogni volta che un pacchetto attraversa un hook, Netfilter controlla se a quel determinato punto è stata assegnata una funzione di gestione; se sì il pacchetto viene passato alla funzione altrimenti il pacchetto passa all'hook successivo.

IPtables mette a disposizione tre tabelle alle quali si possono associare un  
numero arbitrario di catene di regole:
1. **Filter**: per operazioni di [[#Packet Filtering]]. Agganci agli hook NF_IP_LOCAL_IN, NF_IP_LOCAL_OUT e NF_IP_FORWARD
2. [[#NAT]]: per le funzioni di Masquerading (SNAT), Port Forwarding e Transparent Proxy (DNAT). Si aggancia agli hook NF_IP_PREROUTING, NF_IP_POSTROUTING,  NF_IP_LOCAL_OUT
3. **Mangle**: per le funzionalità di [[#Packet Marking]] e per effettuare modifiche ai campi TOS e TTL

Prima di vedere le funzionalitá, diamo un'occhiata alle opzioni del comando iptables:
- **opzione -N** é possibile definire delle nuove catene , in aggiunta a quelle presenti di default.
```powershell
$ iptables -t filter -N catena_tcp 
```
- **opzione -L** stampa a schermo una schermata contenente le catene contenute in una tabella e le regole appartenenti a ciascuna catena
```powershell
$ iptables -t filter -L 
```
- **opzione -D** consente di eliminare selettivamente una regola da una catena
```powershell
$ iptables -t filter -D FORWARD 2
```
- **opzione -F** (flush) elimina tutte le regole contenute in una determinata catena. Se nessuna catena viene specificata, sono eliminate tutte le regole appartenenti a tutte le catene della tabella
```powershell
$ iptables -t filter -F FORWARD iptables -t nat -F
```
- **opzione -X **consente di eliminare una catena create da utente
```powershell
$ iptables -t filter –X catena_tcp
```



### Netfilter
Gli hook messi a disposizione da Netfilter sono i seguenti:
1. **NF_IP_PREROUTING**: è raggiunto dai pacchetti in ingresso attraverso una interfaccia di rete, e prima di essere sottoposti a routing (hook per DNAT)  
2. **NF_IP_LOCAL_IN**: è raggiunto solo dai pacchetti diretti alla macchina locale  
3. **NF_IP_FORWARD**: è raggiunto solo dai pacchetti provenienti da una interfaccia di rete e diretti verso un’altra interfaccia (pacchetti in transito)  
4. **NF_IP_POSTROUTING**: è raggiunto dai pacchetti già sottoposti a routing e che stanno per uscire dalla macchina locale (hook per SNAT)
5. **NF_IP_LOCAL_OUT**: è attraversato dai pacchetti generati localmente prima di essere sottoposti alla logica di routing
![[iptables.png]]

Inoltre Netfilter mette a disposizione cinque principali valori di ritorno:
- **NF_ACCEPT**: accetta il pacchetto  
- **NF_DROP**: nega l'accesso al pacchetto  
- **NF_STOLEN**: preleva il pacchetto dal Kernel per  manipolazioni in kernel space 
- **NF_QUEUE**: accoda il pacchetto che viene reso disponibile  per una gestione in ambito user space  
- **NF_REPEAT**: provoca un nuovo transito del pacchetto nel medesimo hook



### Packet Filtering
Per le operazioni di packet filtering si usa la tabella Filter, che contiene tre catene:
- INPUT: contiene le regole per i pacchetti destinati ad un processo locale
- OUTPUT: contiene le regole per i pacchetti diretti verso l'esterno
- FORWARD: contiene le regole per i pacchetti in transito

Per ciascuna catena occorre impostare la politica (accesso o negazione implicita) utilizzando l'opzione -P
```powershell
$ iptables [-t tabella] -P catena { ACCEPT | DROP }
$ iptables –t filter –P INPUT DROP iptables –t filter –P FORWARD ACCEPT
``` 

A ciascuna catena possono essere aggiunte regole con l’opzione –A. Ogni regola ha un obiettivo, introdotto con l'opzione -j.
I possibili obiettivi sono:
- DROP: scarta il pacchetto
- REJECT: scarta il pacchetto inviando un messaggio ICMP
- ACCEPT: autorizza il pacchetto ad attraversare l'hook
- QUEUE: rende il pacchetto disponibile per elaborazioni in  user space
- LOG: effettua registrazione delle informazioni relative a pacchetti conformi alle regole specificate
- Il nome di un'altra catena di regole creata dall'utente 
```powershell
$ iptables [-t tabella] -A catena espressione -j obiettivo [opzioni]
$ iptables –t filter –A INPUT –s 192.168.1.0/24 –j DROP
$ iptables –t filter –A FORWARD –p tcp –i eth0 –d 192.168.1.0/24 --dport 80 –j ACCEPT
$ iptables –t filter –A INPUT –p icmp –s !192.168.1.0/16 --icmp-type echo-request –j DROP
```

Inoltre IPtables può essere usato per impostare delle regole dinamiche (stateful o state aware) utilizzando il modulo state, il quale utilizza dei qualificatori all'interno delle espressioni di confronto:
- NEW: pacchetti necessari per l'apertura di una nuova connessione  
- ESTABLISHED: pacchetti appartenenti a connessioni già stabilite in precedenza  
- RELATED: pacchetti correlati a connessioni già stabilite
```powershell
$ iptables –t filter –A FORWARD –p tcp - -dport ftp –m state --state NEW, ESTABLISHED –j ACCEPT  
$ iptables –t filter –A FORWARD –p tcp - -sport ftp –m state --state ESTABLISHED -j ACCEPT
```

Un'ulteriore esempio di regole dinamiche consiste nell'utilizzo del modulo limit, il quale consente di porre dei limiti alla frequenza con cui determinati tipi di pacchetti attraversano il firewall.
```powershell
$ iptables -t filter -A FORWARD -i eth+ -p icmp -m limit --limit 4/minute --limit-burst 3 -j ACCEPT
# Accetta una media di 4 pacchetti ICMP al minuto. Se la policy di default è DROP, i pacchetti ICMP in eccesso sono eliminati
```



### NAT
IPtables può essere utilizzato per funzioni di Network Address Translation (NAT) utilizzando la tabella nat, la quale prevede tre catene di default:
- **PREROUTING**: consente manipolazioni sull’indirizzo di destinazione (DNAT) dei pacchetti provenienti dall’esterno
- **OUTPUT**: consente manipolazioni sull'indirizzo di destinazione (DNAT) dei  pacchetti generati localipmente  
- **POSTROUTING**: consente manipolazioni sugli indirizzi sorgente (SNAT) di tutti i pacchetti in uscita

Gli obiettivi utilizzabili nelle regole delle catene della tabella NAT sono i seguenti: 
- SNAT: modifica l’indirizzo IP e la porta sorgente di un pacchetto
- MASQUERADE: sostituisce l’indirizzo IP sorgente di un pacchetto con quello dell’interfaccia di rete a cui è destinato (caso particolare SNAT)
- DNAT: modifica l’indirizzo IP e la porta di destinazione di un pacchetto
- REDIRECT: sostituisce l’indirizzo IP destinazione di un pacchetto con quello dell’host che si occupa del NAT (caso particolare DNAT)

Per condividere l'unico indirizzo IP pubblico con tutte le macchine della rete locale è possibile utilizzare la seguente regola di IPtables.
```powershell
$ iptables –t nat –A POSTROUTING –o eth0 –j SNAT --to-source 155.185.54.185
# 155.185.54.185 rappresenta l'indirizzo IP pubblico della interfaccia di rete esterna del firewall
```
In caso l'indirizzo IP pubblico del firewall sia impostato dinamicamente dobbiamo utilizzare MASQUERADE.
```powershell
$ iptables –t nat –A POSTROUTING –o ppp0 –j MASQUERADE
```

Per far fruire un servizio all’esterno di una rete locale con indirizzi privati occorre utilizzare il seguente comando.
```powershell
$ iptables –t nat –A PREROUTING –p tcp –d 155.185.54.185 --dport 80 -j DNAT --to-destination 192.168.1.1
# 192.168.1.1 è l'indirizzo privato del web server
```

Infine mediante le regole della tabella nat è possibile implementare un Transparent Proxy, cioè un proxy contattato dai client in modo trasparente, senza la necessità di impostazioni particolari.
```powershell
$ iptables –t nat –A PREROUTING –p tcp –i eth1 --dport 80 –j DNAT --to-destination 192.168.1.1:8080
# Questo comando redirige tutti i pacchetti tcp diretti alla porta 80 verso la porta 8080 dell'host 192.168.1.1, che ospita un web proxy
```
Se il transparent proxy risiede sullo stesso host che implementa i meccanismi di NAT è possibile usare l'obiettivo REDIRECT
```powershell
$ iptables –t nat –A PREROUTING –p tcp –i eth1 --dport 80 –j REDIRECT --to-port 8080
```



### Packet Marking
Con packet marking si intende la tecnica di manipolazione degli header dei  
pacchetti per utilizzare avanzate metodologie di routing e modificare i valori dei 
campi TOS, TTL. La tabella mangle mette a disposizione 5 catene:
- PREROUTING: per manipolare pacchetti prima della logica di routing  
- OUTPUT: per manipolare pacchetti generati da processi locali prima della logica di routing
- INPUT: per manipolare pacchetti diretti ad un processo locale 
- FORWARD: per manipolare pacchetti instradati da una interfaccia all’altra
- POSTROUTING: per manipolare pacchetti già sottoposti alla logica di routing
Invece gli obiettivi delle regole associate alle catene sono:  
- MARK: utilizzato per impostare il valore dei marcatori di Netfilter  
- TOS: usato per impostare il valore del campo TOS  
- DSCP: sfruttato per alterare il valore del campo DSCP (sei  bit all’interno del campo TOS)  
- ECN: permette di settare a 0 tutti i bit del campo ECN dei  pacchetti TCP  
- TCPMSS: consente di modificare il valore del MSS dei  pacchetti TCP SYN

```powershell
# Per impostare un valore ai marcatori di Netfilter
$ iptables –t mangle –A PREROUTING –p tcp –i eth0 –j MARK --set-mark mark

# Per alterare il valore del TOS di un pacchetto
$ iptables –t mangle –A OUTPUT – p tcp –dport 3045 –j TOS --tos tos

# Per modificare il valore della Maximum Segment Size
$ iptables –t mangle –A POSTROUTING –p tcp –j TCPMSS --clamp-mss-to-pmtu
```