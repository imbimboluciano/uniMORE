Mediante le VLAN gli host possono essere raggruppati "logicamente" e permettere una maggiore facilità di gestione, un maggiore grado di sicurezza e isolamento (la comunicazione diretta tra VLAN diverse è impedita) e maggiori performance perchè il traffico di broadcast è limitato agli host della VLAN. Tecnicamente creare una VLAN equivale a creare un dominio di broadcast separato.

Linux supporta la creazione di interfacce virtuali che gestiscono il tagging e l'untagging dei frame per una particolare VLAN. Per creare un'interfaccia VLAN solo temporaneamente dobbiamo utilizzare il seguente comando.

```powershell
$ ip link add link <physif> <virtif> type vlan id <N>
$ vconfig add <physif> <N> (old version)
```

In caso volessimo rimuovere un'interfaccia VLAN possiamo utilizzare il seguente comando.

```powershell
$ ip link del <virtif>
$ vconfig rem <physif>.<N>
```

Per rendere le modifiche permanenti è necessario inserire nel file /etc/network/interfaces un'interfaccia nel seguento modo:

```powershell
auto <physif>.<N>  
iface <physif>.<N> inet static  
	address <ip_address
```

Per recuperare il vlan id associato ad una interfaccia si può utilizzare il seguente comando

```powershell
$ grep VID /proc/net/vlan/<virtif>
> pippo VID: 10 REORDER_HDR: 1 dev->priv_flags: 1
```


### Configurazione VLAN
Per creare e configurare dovremmo modificare il file di configurazione dello switch introducendo opportuni comandi:

1. Creazione di VLAN sugli switch
```powershell
vlan/create vlan_number
```

2. Impostare la VLAN per ogni porta a cui è collegato un host  (VLAN untagged)
```powershell
port/setvlan port_number vlan_number
```

3. Aggiungere la porta collegata all'altro switch alla VLAN 
```powershell
vlan/addport vlan_number port_number
```

