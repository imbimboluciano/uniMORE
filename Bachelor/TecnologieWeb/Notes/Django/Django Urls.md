Vediamo come implementare una funzione (business logic) per dare un messaggio di benvenuto ai nostri visitatori. Dobbiamo modificare il file urls.py e creamo il file views.py.
```python
#urls.py
from django.contrib import admin
from django.urls import path,re_path
from .views import home_page

urlpatterns = [
	path('admin/', admin.site.urls), #pannello di amministrazione
	#regex espression
	re_path(r'^$|^/$|^home/$',home_page,name = "homepage"), 
	#con questa riga sostituiamo le seguenti righe
	#path("home/",home_page, name = "homepage")
	#path("/",home_page, name = "homepage")
	#path("",home_page, name = "homepage")  
]
```

Per specificare gli url risulta comodo utilizzare le [[Regex Expressions]].

```python
#views.py
from django.http import HttpResponse

def home_page(request):
	response = "Benvenuto nella Homepage\n"
	response += "di Luciano Imbimbo\n"

	return HttpResponse(response)
```

In caso di non matching con un determinato url potrebbe presentarsi un determinato errore con la corrispondente pagina di errore. Esistono diversi tipi di errore HTTP:
- 1XX -> Messaggio Informativo
- 2XX -> Successo
- 3XX -> Redirection  
- 4XX -> Fail (Client) (Es. non match con urls)
- 5XX -> Fail (Server) (Es. errore di sintassi nel codice)

### Richiesta GET
Il primo tipo di richiesta Http che vedremo è la richiesta GET, la quale richiede al server una specifica risorsa. Le richieste GET ammettono parametri specificati tramite URL.
```txt
url_path?param1=value1&param2=value2...
```

Possiamo recuperare questi parametri accedendo al dizionario chiave-valore della request.
```python
request.GET["param_name"]
```

Un altro metodo per specificare i parametri della richieste GET è quello di specificare il tipo ed il nome del parametro richiesto. 
```python
path('url_path/<int:eta>/', view_func, name=’alias’),
path(‘url_path/<str:nome>/<int:eta>/’, view_func, name=’alias’)
```

Riesco ad accedere a tali parametri come argomenti in ingresso alla mia funzione (nella view).
```python
def welcome_path(request,nome,eta):
	[...]
```

Bisogna fare molta attenzione perchè non tutti i tipi di dato sono supportati e perchè il matching con il tipo è molto rigido (se viene passato un double al posto di un int viene restituito un errore).