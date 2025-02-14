La maggior parte dei siti che conosciamo seguono regole di formattazione [[HTML]]. Essendo, però, un linguaggio di markup non è molto comodo, non facilmente estendibile e riutilizzabile (viola la policy DRY). Django mette a disposizione un modo conveniente per generare HTML in modo dinamico. L'approccio più comune si basa sui template, cioè sui file HTML che contengono contenuti statici e dinamici (sintassi speciale che descrive come verranno inseriti i contenuti dinamici). 

I template sono "scheletri" riutilizzabili nella parte di presentazione della web app (per andare oltre html puro, che per definizione è statico). Per far ciò Django mette a disposizione [[#Django Template Language]] un vero proprio linguaggio basato su “blocchi” anziché “tag”.


### Template Engine
Quando ci si approccia a Django è facile credere che template e file html siano la stessa cosa. In realtà un Template è un oggetto Django che fa parte di una complessa struttura interna che si occupa di analizzare, elaborare, generare un context, gestire le Django tag, popolare il codice dinamico, fino alla generazione di una lunga stringa rappresentante il contenuto HTML da mostrare su browser. Tutto questo fa parte del template engine di Django.  

Un progetto django può essere configurato con uno o più template engine (o anche nessuno se il progetto non usa template). Per definire il Template Engine e la directory da cui l'engine caricherà i vari template dobbiamo modificare il file setting.py nel seguente modo:
```python
TEMPLATES = [  
	{  
		‘BACKEND’: ‘django.template.backends.django.DjangoTemplates’,  
		‘DIRS’: [os.path.join(BASE_DIR,"templates")],  
		‘APP_DIRS’: True,  
		#definisce se l’engine deve cercare template dentro alle app installate
		‘OPTIONS’: {  
			# opzioni  
		}  
	}  
]
```


### Django Template Language
Django template language basato su blocchi (no tag) è un mix tra linguaggio di programmazione e linguaggio di markup. La particolarità dei file DTL è che sono file statici risolti dinamicamente lato server e spediti al client come risultato statico.
In altre parole, ai blocchi che delimitano gli “spazi notevoli” della nostra pagina abbiamo anche dei programming construct che ci permettono l’accesso in lettura e scrittura alle variabili di contesto, ma anche di operare istruzioni condizionali e cicliche tipiche dei linguaggi di programmazione.

##### Variabile 
Quando il template engine incontra una variabile, questa viene tradotta e rimpiazzata con il suo valore. Il nome di una variabile NON può cominciare con un underscore. Il punto (.) viene usato per accedere agli attributi di una variabile
```html
{{ variable }}
{{ variable.attribute }}
```
 
##### Filtri 
```html
{{ name|lower }}
<!--> concatenazione filtri <!-->
{{ variable|filter|another_filter }}
<!---> filtri con argomenti<!-->
{{ text|truncatewords:30 }}
```

##### Tag
I tag svolgono varie funzioni. Alcuni generano un output testuale, altri controllano il flow con loop e operatori condizionali, altri ancora caricano informazioni esterne all’interno del template. Alcuni tag richiedono una tag di apertura e una di chiusura.
1. For
```html
{% for element in elements_list %}  
	{{ element.detail }} <br>  
{% endfor %}
```
2. If-else
```html
{% if elements_list %}  
	Numero di elementi: {{ elements_list|length }}  
{% elif elements_not_listed %}  
	Numero di elementi fuori dalla lista: {{ elements_not_listed|length }}  
{% else %}  
	Non è presente nessun elemento.  
{% endif %}
```
3. Block = permette di definire un contenuto che i template “figli” potranno personalizzare.
```html
{% block title %} {{ title }} {% endblock %}
```

##### Ereditarietà
Come se fosse dei propri e veri oggetti anche i template hanno la possibilità di estensione di template-padre ed inclusione di altri sub-template.

```html
{% extends 'base.html' %}
{% include 'base.html' %}
```

Non vi è uno stato condiviso tra template e sub-templates, in quanto vengono renderati in momenti diversi, indipendentemente l’uno dall’altro. Quindi estendere blocchi nei template, causa la loro totale riscrittura. e il padre base.html definisce dei blocchi (e.g. block head) con  tanto di contenuti, questi ultimi verranno di fatto riscritti nel momento in cui i figli  
ridefiniscono blocchi con lo stesso nome

##### Commenti
Django offre anche la possibilità di commentare una porzione di codice sia con la specifica sintassi {#... #} che con l’apposito tag {% comment %}





