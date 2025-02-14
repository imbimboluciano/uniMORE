Per inizializzare il nostro progetto [[Django Framework]] ed il corrispondente ambiente virtuale dobbiamo seguira una determinata procedura.
1. Creiamo una cartella
```powershell
$ mkdir 'nomecartella'
$ cd 'nomecartella'
```
2. Accertiamoci di aver installato pipenv
```powershell
$ pipenv --version
```
3. Installiamo Django nel nostro virtualenv (dovremmo installare Django per ogni virtualenv, no installazione globale)
```powershell
$ pipenv install django
```
4. Attiviamo il virtualenv
```powershell
$ pipenv shell
```

Per creare all'interno del virtualenv e della cartella di progetto, un nuovo progetto Django dobbiamo utilizzare i comandi amministrativi di Django:

```powershell
$ django-admin startproject 'nomeprogetto'
```

Eseguito questo comando, la cartella sarà così strutturata:
![[djangofilestruttura.png|250]]


### Settings.py
Settings.py è un file che contiene tutte le configurazioni del progetto django. Per utilizzare le funzionalità più basilari di django è però sufficiente saper gestire alcune opzioni  
specifiche di settings.py, tra queste troviamo:
- DEBUG = in caso di errori, con valore True mostra su schermo l’errore nel dettaglio. Con valore False si limita a dichiarare lo “status code” della risposta. True si utilizza in fase di sviluppo, False in produzione;  
- ALLOWED_HOST = il suo scopo è convalidare l'header host HTTP di una richiesta. È un’opzione  strettamente legata a DEBUG 
- INSTALLED_APPS = qui si inseriscono tutte le app presenti nel progetto (librerie di base di django e app sviluppate da noi)

### Urls.py
Nel file urls.py è presente una lista nella quale ciascun elemento rappresenta un url collegato ad una view specifica (funzione o classe che sia) e a un nome che può essere utilizzato nei template. 

### Wsgi.py
Wsgi.py aiuta django a servire eventuali pagine web

### Manage.py
Manage.py è usato per eseguire diversi comandi di django come eseguire un web server locale o creare una nuova applicazione.
```powershell
$ python manage.py runserver
```

### Views.py
Views.py è un file, non automaticamente generato da Django ma creato manualmente dallo sviluppatore, che raggruppa le view (viste) del progetto. Ogni view è responsabile della business logic e di cosa il server risponde a seguito di una particolare richiesta ritornando all’utente un oggetto HTTPResponse o sollevando un’eccezione come HTTP404.
