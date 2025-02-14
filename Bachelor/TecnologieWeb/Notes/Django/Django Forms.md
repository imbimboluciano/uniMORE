Cosa fare quando le tabelle diventano due, o quando voglio operare una List view su un
form di ricerca con criteri particolari? Cosa fare quando voglio esplicitare condizioni e vincoli aggiuntivi per le entry della mia tabella, troppo astrusi per essere codificati nei models? Esiste la classe Form in “from django import forms” che permette di definire 2 cose importanti:
1. Campi editabili personalizzati
2. Aggiungere condizioni di validazione aggiuntivi a tali campi.

Tipicamente si usa creare un file apposito che raccoglie i Form personalizzati della mia applicazione. Lo chiameremo forms.py, e come view, model, url etc… può afferire all’intero progetto o alla specifica app. Similmente ai model, negli attributi del form andremo a definire i campi editabili che l’utente userà tramite browser.

Per campi editabili e widget https://docs.djangoproject.com/en/4.0/ref/forms/fields/ 

```python
from django import forms

class SearchForm(forms.Form):
	CHOICE_LIST = [("Questions","Search in Questions"),("Choices","Search in Choices")]
	search_string = forms.CharField(label="Search String",max_length=100, min_length=3, required=True)
	search_where = forms.ChoiceField(label="Search Where?", required=True,
choices=CHOICE_LIST)
```

Ogni elemento creato nel Form personalizzato:
- Ha una label associata (generata automaticamente in [[HTML]])
- Appare in forms.py come una variabile. Il nome della variabile riempie il campo “name” del rispettivo elemento HTML. Ottenibile poi tramite request.POST
- Ha ulteriori parametri (e.g. mix/max length), tradotti appositamente in attributi di elementi HTML

Dando come parametro in ingresso il dizionario request.POST al form personalizzato, il sistema, anzichè istanziare un form vuoto, leggerà i dati passati e li validerà. Grazie alle istruzioni form.cleaned_data.get(“...”) potremmo avere dei dati "puliti".

Con la shortcut “redirect” siamo in grado di dirottare i campi letti verso l’url resolver.


Così come abbiamo visto per le CBV, possiamo associare un Form ad una particolare tabella, se essa è stata definita come oggetto python tra i nostri model. Questa integrazione porta notevoli vantaggi:
1. Creare campi di scelta in funzione di querysets.
2. Creare dei ModelForm, ossia Form legati a dei modelli in cui non dobbiamo necessariamente specificare i campi editabili dall’utente e a cui possiamo dare direttive arbitrarie sul rendering (widget) e sulle regole di validazione
```python
class VoteForm(forms.Form):
	answer = forms.ModelChoiceField(queryset=None,required=True,label="Select your answer!")
	def __init__(self, pk, *args, **kwargs):
		super().__init__(*args, **kwargs)
		q = get_object_or_404(Question,pk=pk)
		self.fields['answer'].queryset = q.choices.all()
```


In [[Django Framework]] esistono quindi i ModelForm nello stesso modulo dei form tradizionali”.
Seguono le regole dei form che abbiamo già visto, ma danno la possibilità di creare meta informazioni (classe nested Meta) in cui possiamo specificare a quale tabella sono collegati.
Una volta specificato il model di riferimento e l’attributo fields (nella stessa maniera che
abbiamo visto con le CreateView, per esempio), non occorre poi specificare i campi del
form.
```python
class CreateQuestionForm(forms.ModelForm):
	description = "Create a new Question!"
	#metodo clean: questo ci consente di implementare validazione aggiuntiva sugli input dell’utente
	def clean(self):
		if (len(self.cleaned_data["question_text"]) < 5):
			self.add_error("question_text", "Error: question text must be at least 5 characters long")
			
		return self.cleaned_data

	class Meta:
		model = Question
		fields = "__all__"
		#parametro per meta informazioni
		widgets = {
'pub_date': forms.DateInput(format=('%d/%m/%Y'), attrs={'class':'form-control', 'placeholder':'Select a date', 'type':'date'})
}
```

Gli errori che aggiungiamo in clean, se scatenati, compariranno nel render del browser e impediranno la sottomissione dei dati POST.
- self.add_error(“campo interessato”,”stringa associata all’errore”)


### Crispy Form
Per quanto django offra strumenti veloci ed efficienti per realizzare form con pochissimo sforzo, non permette però di curarne l’aspetto e i form generati risultano funzionali ma graficamente poveri.
Per sopperire a questo è stato creato django-crispy-form, un’applicazione che permette di interagire con proprietà dei form direttamente dal backend controllando così il comportamento di rendering dei django form in modo elegante e DRY.
```powershell
$ pip install --upgrade django-crispy-forms
```
Poi aggiungere crispy_form ad INSTALLED_APPS in setting.py

django-crispy-forms offre un supporto integrato per diversi framework CSS, chiamati template packs all’interno di django-crispy-forms:
- bootstrap → Bootstrap versione 2 è il template pack utilizzato di default da crispy-forms;
- bootstrap3 → Twitter Bootstrap versione 3;
- bootstrap4 → Twitter Bootstrap versione 4;
- uni-form → Uni-form è un framework che standardizza il markup e lo stile dei form e lo modella con CSS;
- foundation
Per indicare a django il corretto template pack da utilizzare è sufficiente inserire nel file settings.py:
```python
CRISPY_TEMPLATE_PACK = ‘<nome template pack>’
```


Il metodo più semplice per usare crispy-forms è quello di utilizzare il filtro |crispy
1. Aggiungi la tag {% load crispy_form_tags %} al template;
2. Aggiungi il filtro |crispy alla variabile form del context.

```html
{% load crispy_form_tags %}
<form action = "home/" method = "POST">
	{{ form|crispy }}
</form>
```

Per quanto il filtro |crispy sia molto utile, lo si può concepire come i metodi integrati as_p, as_table e as_ul, quindi non permette di customizzare l’output in modo consistente.
Il miglior metodo per avere un controllo totale dell’output dei template è quello di utilizzare il tag {% crispy %}.
```python
from django import forms
from crispy_forms.helper import FormHelper
from crispy_forms.layout import Submit

class PersonaCrispyForm(forms.ModelForm):

	helper = FormHelper()
	helper.from_id = "persona-crispy-form"
	helper.form_method = "POST"
	helper.add_input(Submit("submit", "Submit"))

	class Meta:
		model = Persona
		fields = ("nome", "cognome", "ruolo")
```

Django-crispy-forms offre lo strumento Layout che permette di modificare radicalmente il modo in cui i campi vengono renderizzati. Permette di stabilire l’ordine dei campi, inserirli in elementi o altre strutture, aggiungere HTML, aggiungere id, classi o attributi a qualsiasi cosa.
```python
	helper.layout = Layout(
		Div (
			HTML("<p>Inserisci i dati del socio:</p>")
			Field("nome", style="color: red", css_class = "bg-dark", title = "Nome")
		
			),
			Submit("submit", "Submit")
	)
```

Per approfondire le potenzialità di Layout, visita https://django-crispy-forms.readthedocs.io/en/latest/layouts.html