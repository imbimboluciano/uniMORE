-t filAlcuni comandi utili ad implementare correttamente policy di filtraggio e di [[NAT]].
- Visualizza le regole attualmente incluse nelle catene appartenenti alla tabella filter e le loro policy di default
```powershell
$ iptables -t filter -L -v -n
# L'opzione -n evita reverse lookup di indirizzi IP
``` 
- Imposta la policy di negazione implicita (DROP) sulla catena FORWARD della tabella filter
```powershell
$ iptables -t filter -P FORWARD DROP
``` 
- Esempio di comando utilizzato per aggiungere una regola di packet filtering statico
```powershell
$ iptables -t filter -A FORWARD -p tcp --dport 22 -i eth0 -j DROP
# La regola inseritablocca (-j DROP) tutti i pacchetti TCP aventi 22 come numero di porta di destinazione e che hanno eth0 come interfaccia di t ingresso
``` 
- Esempio di eliminazione selettiva di una singola regola
```powershell
$ iptables -t filter -D FORWARD 2
``` 
- Eliminazione di tutte le regole appartenenti alla catena FORWARD
```powershell
$ iptables -t filter -F FORWARD 
``` 
- Eliminazione di tutte le regole appartenenti a tutte le catene della tabella filter
```powershell
$ iptables -t filter -F 
``` 
- Consetire il traffico solo a pacchetti derivanti da processi di un determinato utente
```powershell
$ iptables -t filter -A OUTPUT -o eth0 -m owner --uid-owner utente -j ACCEPT 
``` 