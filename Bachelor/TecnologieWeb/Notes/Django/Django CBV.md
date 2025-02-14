Fino ad ora abbiamo programmato solo secondo il pattern di Function Based Views:
- Bassa riutilizzabilità, rottura della policy DRY
- Molto codice esplicito per l'accesso ai DB

Le classi di solito costituiscono un buon approccio alle metodologie di sviluppo basate sul riutilizzo di codice già scritto. E se quindi rispondessimo ad una richiesta tramite una classe anziché una funzione? [[Django Framework]] ci mette a disposizione le Class Based Views:
- poco o nessun codice ripetuto tra Viev imparentate tra di loro
- Possibilità di ereditare da classi presenti nei moduli\pkg di django per accesso al DB
- Alcune particolari operazioni diventano difficilmente implementabili

Non pensate a CBV e FBV come scelte “radicali”, in quanto sono meccanismi complementari e non esclusivi.
Django ci mette a disposizione delle classi ("View") pre-confezionate per i metodi CRUD che appartengono ai moduli django.views.generic. Creiamo quindi una classe che estende la view, specificando Model e template e abbiamo già finito.

C'è modo di operare dei filtri anche tramite le CBV, utilizzando dei metodi ereditati da View, il capostipite di tutte le View preconfezionate di django:
- get_queryset, permette di fare operazioni sul queryset sulla tabella indicata dall’attributo model
- get_context_data, permette di aggiungere variabili di contesto
```python
class ListaInsegnamentiAttivi(ListView):
	model = Insegnamento
	template_name = "iscrizioni/insegnamenti_attivi.html"
	
	def get_queryset(self):
		return self.model.objects.exclude(studenti__isnull=True)

	def get_context_data(self, **kwargs):
		context = super().get_context_data(**kwargs)
		context['titolo'] = "Insegnamenti Attivi"
		return context
```

Però occorre fare attenzione: le possibilità non sono propriamente infinite. Per esempio non è possibile chiamare dei view methods con parametri da template.



### ListView
Per elencare le entry della nostra tabella.
```python
from django.views.generic.list import ListView
from .models import *
# Create your views here.
class ListaStudentiView(ListView):
	model = Studente
	template_name = "iscrizioni/lista_studenti.html"
```

Quando si elencano gli url-patterns, c’è questa piccola differenza tra function views e class based views. La funzione path si aspetta di lavorare con delle funzioni e quindi usiamo il metodo della classe View, il quale restituisce un oggetto funzione che incorpora i meccanismi della view.
```python 
urlpatterns = [
	path("listastudenti/", views.ListaStudentiView.as_view(), name = "listastudenti")
]
```



### Create View
Permette di creare una entry di una tabella. Si specificail model ed il template e si aggiunge l’attributo **fields**, per indicare quali attributi si voglia permettere al client di impostare, e l’attributo **success_url** per indicare l’url di redirezionamento in caso di scrittura sul DB avvenuta a buon fine.
```python
class CreateStudenteView(CreateView):
	model = Studente
	template_name = "iscrizioni/crea_studente.html"
	fields = "__all__"
	success_url = reverse_lazy("iscrizioni:listastudenti")
```

reverse & reverse_lazy eseguono un “reverse look up”, cioè anzichè specificare un url “hardcodato”, abbiamo qui la possibilità di usare l’alias del nostro url pattern. Tale alias è tipicamente composto da “app_name:url_name. E’ necessario fare questo reverse lookup in quanto più string patterns possono fare match con lo stesso url:
- reverse si usa nei metodi e nelle funzioni e restituisce una stringa
- reverse_lazy si usa invece al momento di assegnare valori ad una variabile o attributo e restituisce un oggetto complesso

Confondere reverse e reverse_lazy può causare degli errori

Possiamo anche utilizzare una variabile di contesto chiamata form:
- {{ form.as_p }} Rendera sottoforma di paragrafi
- {{ form.as_table }} Rendera sottoforma di tabella
- {{ form.as_ul }} Rendera tramite una item list



### DetailView
Ci permette di fare una query ad una tabella partendo dalla sua primary key. Ciò ci permette di avere un contesto in cui esiste la variabile “object”, attraverso la quale possiamo poi scegliere quali campi visualizzare e come all’interno del template.
```python
class DetailInsegnamentoView(DetailView):
	model = Insegnamento
	template_name = "iscrizioni/insegnamento.html"
```



### UpdateView
Ci permette di modificare una specifica entry di una tabella.
- Accessibilità simile a [[#DetailView]], stesso metodo di passaggio della chiave per ottenere una entry di una tabella(tramite url)
- Modifica simile a [[#Create View]], stesso metodo per restituire un form lato template e sottomissione valori modificati tramite richiesta POST, protetta con csrf token.
```python
class UpdateInsegnamentoView(UpdateView):
	model = Insegnamento
	template_name = "iscrizioni/edit_insegnamento.html"
	fields = "__all__"

	def get_success_url(self):
		pk = self.get_context_data()["object"].pk
		return reverse("iscrizioni:insegnamento",kwargs={'pk': pk})
```



### DeleteView
Come Create ed Update view per ottenere la primary key (pk) dell’elemento da
cancellare ma occorre avere comunque un form di conferma della cancellazione all’interno del template associato alla View.
```python
class DeleteEntitaView(DeleteView):
	template_name = "iscrizioni/elimina_elemento.html"  
	def get_context_data(self, **kwargs: Any) -> Dict[str, Any]:
		ctx = super().get_context_data(**kwargs)
		entita = "Studente"
		if self.model == Insegnamento:
			entita = Insegnamento
		ctx["entita"] = entita
	return ctx
	
	def get_success_url(self) -> str:
		if self.model == Studente:
			return reverse("iscrizioni:listastudenti")
		else:
			return reverse("iscrizioni:listainsegnamenti")

class DeleteStudenteView(DeleteEntitaView):
	model = Studente

class DeleteInsegnamentoView(DeleteEntitaView):
	model = Insegnamento
```
