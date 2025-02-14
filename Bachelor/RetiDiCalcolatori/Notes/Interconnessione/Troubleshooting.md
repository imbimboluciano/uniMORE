Se qualcosa non funziona non controllare subito il file di configurazione delle interfacce ma utilizza i comandi opportuni per verificare lo stato attuale del sistema. 
In caso di conflitti “critici”, possiamo riavviare i servizi di rete:
```shell
$ service networking restart
$ systemctl restart networking (in sistemi systemd)
```


Durante il riavvio, il sistema eseguirà tutte le operazioni svolte durante la fase di boot del sistema, inclusa la lettura dei file di configurazione e quindi se ci sono degli errori nei file di configurazione, potremmo ottenere un sistema inconsistente anche dopo il riavvio dei serivizi.

Per riportare le interfacce di rete allo stato "DOWN" possiamo utilizzare i seguenti comandi.
```shell
$ ifconfig <iface> {up,down}
$ ip link set dev <iface> {up,down}
```

Invece per deconfigurare un'interfaccia di rete, rimuovendo l'indirizzo IP assegnato possiamo usare i seguenti comandi.
```shell
$ ifconfig <iface> 0    
$ ip addr del <address> dev <iface>
```
