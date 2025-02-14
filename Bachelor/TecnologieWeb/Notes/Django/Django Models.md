Django usa la filosofia ORM (Object Relational Mapping) per la gestione di dati strutturati e quindi possiede ibrerie interne in grado di “tradurre” oggetti (istanze di classi) in entità  
fruibili come dati in un database. Le classi stesse rappresentano le tabelle dei DB ed i loro oggetti istanziati rappresentano le entry di queste tabelle. Il processo di traduzione da tabella ad oggetto è chiamato migrazione. Questo approccio offre notevoli vantaggi:
- ossibilità di creare ed usare database complessi senza dover scrivere query  
- Le classi ORM sono ben integrate con il resto del nostro codice python\DTL  
- Ci rendiamo “slegati” dalle effettive scelte implementative del nostro DB  
- Possiamo sfruttare concetti legati all’ereditarietà di classi per massimizzare il riutilizzo dei nostri modelli
- Funzioni comunemente usate nei DB, import\export\CRUD+L etc... sono praticamente “gratis” tramite il django View system

Partiamo quindi con una cosa semplice: una sola tabella. Un libro è caratterizzato da Titolo, Autore, Pagine, e da una data dell’ultimo prestito.
```python
class Libro(models.Model):  
	titolo = models.CharField(max_length=200)  
	autore = models.CharField(max_length=50)  
	pagine = models.IntegerField(default=100)  
	data_prestito = models.DateField(default=None)
```

Per rendere effettive le modifiche dobbiamo fare la migrazione.
```powershell
$ python .\manage.py makemigrations gestione
$ python .\manage.py migrate
```
Esistono migrazioni potenzialmente distruttive come aggiungere un campo senza valori di default o non-nullable e cambiare la primary key con il rischio di perdere i dati salvati. Ogni migrazione è salvata in  app/migrations così che possiamo “tornare indietro nel tempo”. Occorrerebbe fare esportare il proprio DB prima di eventuali migrazioni potenzialmente distruttive. 

Possiamo popolare il database attraverso differenti tipologie:
- Programmaticamente,ossia usando codice python; tipicamente si usa nel setup iniziale, quando si importano\esportano dati, routine di manutenzione e controllo
```python
from gestione.models import Libro
from django.utils import timezone
from datetime import datetime

  
def erase_DB():
	Libro.objects.all().delete()

  
def init_DB():
	if len(Libro.objects.all().count() != 0):
		return
	
	def func_time(off_year=None, off_month=None, off_day=None):
		tz = timezone.now()
		out = datetime(tz.year-off_year, tz.month-off_month, tz.day-           off_day,tz.hour, tz.minute,tz.second)

		return out

	libridict = {
		"autori" : ["Alessandro Manzoni", "George Orwell", "Omero"],
		"titoli" : ["Promessi Sposi", "1984", "Odissea"],
		"pagine" : [832,159,760],
		"date" : [func_time(y,m,d) for y in range(2) for m in range(2) for d in range(2)]
	}

  
	for i in range(3):
		l = Libro()
	
		for k in libridict:
			if k == "autori":
				l.autore = libridict[k][i]
			if k == "titoli":
				l.titolo = libridict[k][i]
			if k == "pagine":
				l.Pagine = libridict[k][i]
			if k == "date":
				l.data_prestito = libridict[k][i]
		l.save()
```
Queste one-shoot operation possono essere inserite nel file urls.py della root per essere eseguite automaticamente all'avvio.
- Tramite console dell’admin, permette di fare tutto quello elencato nel punto precedente tramite una comoda interfaccia grafica web-based. Ovviamente però deve esistere un superutente admin
- Tramite Views and function views, modifiche ai dati del DB scatenate da richieste client-side


### Filters
Possiamo applicare dei filtri ai QuerySet direttamente tramite codice [[Python]].
```python
<nome_attributo>__[gt,lt,gte,lte, ....] = value,
lista_filtrata = Libro.objects.filter(pagine__gte=300)  
#lista_filtrata = Libro.objects.exclude(pagine__lt=300)
Libro.objects.all().order_by('data_prestito') #Ordina in senso crescente
Libro.objects.all().order_by('-data_prestito') #Ordina in senso crescente
Libro.objects.all().order_by("-pagine")[:2] #due libre con più pagine
Libro.objects.filter(autore__iexact="Omero") #Case insensitive  
Libro.objects.filter(autore__iexact="George Orwell") #Case sensitive
q01 = qs0 | qs1 #unione querySet
```

l metodo filter e la sua versatilità nel definire criteri di selezione dovrebbe bastare  
per qualsiasi cosa ci venga in mente. Qualora non fosse così, si possono comunque utilizzare raw queries in caso siamo sicuri che il DB sottostante sia di fatto un database e ne conosciamo l’implementazione

```python
for l in Libro.objects.raw("SELECT * FROM gestione_libro WHERE pagine >= %s", [MATTONE_THRESHOLD]):  
	print(l)
#restituisce un oggetto RawQuerySet =! QuerySet
```


### Foreign Key
Django offre anche una serie di tipi di campi che rappresentano relazioni tra tabelle:  
- ForeignKey  (many to one) -> Richiede due argument posizionali:  
	- la classe (model) al quale il model si relaziona;  
	- il parametro on_delete che accetta, tra i valori più usati:  
		-  models.CASCADE → eliminazione a cascata. django emula il comportamento del vincolo SQL    
		- models.PROTECT → previene l’eliminazione dell’oggetto con il quale si crea la relazione.
	- Un altro parametro molto importante è related_name, il nome utilizzato dall’oggetto messo in relazione a quello con la foreign key per accedervi.
- ManyToManyField  -> Richiede un argument posizionale: la classe con la quale il model si relaziona.  Django genera automaticamente una tabella intermedia per rappresentare la relazione (reificazione).
- OneToOneField 
```python
from django.db import models

class Libro(models.Model):
	titolo = models.CharField(max_length=200)
	autore = models.CharField(max_length=200)
	pagine = models.IntegerField(default=200)  

	class Meta:
		verbose_name_plural = "Libri"

  
class Copie(models.Model):
	data_prestito = models.DateField(default=None)
	scaduto = models.BooleanField(default=False)
	libro = models.ForeignKey(Libro, on_delete = models.CASCADE, related_name= "copie")
```

Django parte dall’assunto che i nomi dei model siano in lingua inglese perciò aggiunge una ‘s’ in fondo al nome del model. Per evitare questo tipo di comportamento è sufficiente aggiungere  l’attributo verbose_name_plural ai  metadati del model