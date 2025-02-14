Tool per la creazione di ambienti python isolati, detti virtualenv, cioè di cartelle contenenti tutte le librerie, le dipendenze, i pacchetti e gli eseguibili del progetto [[Python]] ("simile" a Gradle). Ci permette di virtualizzare i pacchetti di python necessari per far girare l'applicativo. 
Per installare questo tool possiamo utilizzare pip, cioè il sistema di gestione dei pacchetti scritto in Python e che viene utilizzato per installare e gestire i pacchetti software.

```powershell
$ pip install pipenv
```

Per assicurarci che pip sia installato possiamo utilizzare il seguente comando.

```powershell
$ python3 -m pip --version
```

Pipenv gestisce i pacchetti attraverso l'uso dei file Pipfile e Pipfile.lock. Pipfile contiene la lista di dipendenze e di pacchetti del nostro progetto Python, mente Pipfile.lock è molto per effettuare la build del progetto. 