Come abbiamo già detto, un’app è un’applicazione web che ha funzionalità specifiche e definite. Per creare una nuova app e integrarla in un progetto è necessario seguire una ben precisa procedura:
```powershell
$ python manage.py startapp "nomeapp"
```

[[Django Framework]] automaticamente genera una serie di file utili alla gestione delle varie app:
- admin.py -> vengono registrati i modelli (tabelle del database)
- apps.py -> configurazione dell'applicazione
- models.py -> model dell'applicazione
- tests.py -> file per configurare i test dell'applicazione
- views.py -> view specifiche dell'applicazione

Non essendo strettamente necessari, il comando startapp non genera una cartella templates e un file urls.py, questo perché non tutte le app devono necessariamente servire dei template o utilizzare degli url. Quando però sono necessari, è opportuno creare la cartella templates e il file urls.py all’interno dell’app per rendere il codice meglio organizzato e più facilmente fruibile. Una buona pratica per evitare conflitti con altri template è quella di creare, all’interno della cartella templates interna ad un’app, una sotto cartella riportante il nome dell’app: nomeapp/template/nomeapp/template.html.

Per fare in modo che django tenga traccia della nostra applicazione, è necessario registrarla”: in settings.py > INSTALLED_APPS aggiungi il nome dell'applicazione
```python
INSTALLED_APPS = [
	'django.contrib.admin',
	'django.contrib.auth',
	'django.contrib.contenttypes',
	'django.contrib.sessions',
	'django.contrib.messages',
	'django.contrib.staticfiles',
	'nomeapp'
]
```

Una volta aggiunta una nuova app al progetto, è necessario adoperare i comandi makemigrations/migrate per fare sì che vengano create le tabelle sul database (approfondimento in [[Django Models]]).

Il file urls.py creato in un’app viene trattato alla stessa maniera di uno presente nel progetto, ma è buona pratica assegnare alla variabile app_name il nome dell’app. Questa operazione crea un namespace specifico per il file ed evita conflitti con altri url utilizzati nei template che potrebbero avere lo stesso nome:
```python
app_name = "nomeapp"
path('nomeapp/', include('nomeapp.urls'))
```


Il model in Django è banalmente un oggetto che estende models.Model e che rappresenta una tabella del nostro database. Django ci fornisce delle API per l'accesso al database.




