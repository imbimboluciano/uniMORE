In questa pagina sono mostrati dei comandi utili nella gestione di OS UNIX/Linux.

- **dd** è un’applicazione che “converte e copia un file”
```powershell
# creazione file di 1MB pieno di byte con valore 0
$ dd if=/dev/zero of=file.bin bs=1024 count =1024
``` 

- **tar** permette di creare o scomporre archivi di file
```powershell
$ tar cf [nomefile tar] # crerare una archivio
$ tar tf [nomefile tar] #visualizzare il contenuto di un archivio
$ tar xf [nomefile tar] #estrarre il contenuto
``` 

- **tmux** per abilitare il multitasking sulle finestre del terminale 
```powershell
$ tmux
# Ctrl-B + C per creare una nuova finestra
# Ctrl-B + number per switch tra le finestre
``` 

- **ristretto**, avvia un semplice programma di visualizzazione di immagini incluso di default nell'installazione di xfce. 
```powershell
$ ristretto network_diagram.png
``` 

- **w3m**, visualizza la home page del sito web (w3m é un browser con interfaccia testuale)
```powershell
$ w3m nome_sito
# per uscire premere q e poi y
``` 

- **ftp**, comando per aprire una sessione FTP con interfaccia testuale
```powershell
$ ftp nome_server
# comando dir per ottenere la lista dei file dell'utente
# get nome_file per scaricare dal server FTP il file nome_file
# Ctrl-d per chiudere la sessione
``` 

- **ssh**, per aprire una connessione remota SSH
```powershell
$ ssh nome_host
# Ctrl-d per chiudere la sessione
# porta 22
``` 