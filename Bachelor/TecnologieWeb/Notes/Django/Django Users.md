Possiamo gestire i vari utenti di una web app attravero gli strumenti auth di [[Django Framework]]. La creazione della tabella “User” all’interno del file db si crea e/o popola dopo il
primo comando di migrazione, contiene in caso di creazione di superutente solo le informazioni riguardanti l'admin.
In django, di default, non solo possiamo sfruttare la tabella User, ma anche un sistema di registrazione/login/logout quasi già completamente implementato. Questo sistema pre-esistente presume che l’utente si possa registrare sulla tabella User, la quale è accessibile a tutte le app del progetto.
```python
from django.contrib.auth import views as auth_views
urlpatterns = [
	path("register/", UserCreateView.as_view(), name="register"),
	path("login/", auth_views.LoginView.as_view(), name="login"),
	path("logout/", auth_views.LogoutView.as_view(), name="logout")
]

```

```python
from django.contrib.auth.forms import UserCreationForm
from django.views.generic.edit import CreateView

class UserCreateView(CreateView):
	form_class = UserCreationForm
	template_name = "user_create.html"
	success_url = reverse_lazy("login")
```

Supponendo i campi riempiti lato client passino i test di validazione, il sistema aggiunge l’username e la password come una entry nella tabella User. Di default, però, non porta a termine la procedura di login: infatti, quello che succede è che in seguito alla registrazione l’utente viene redirezionato ad un URL che deve essere specificato nella variabile success_url.

Essendo la logica già implementata nel modulo di login, non dobbiamo aggiungere
nulla al nostro views.py, dobbiamo solo fornire noi il template. Ma io non ho scritto la view e quindi non ho modo di impostare quale template, ed il success_url.

Non ne ho bisogno, perchè seguo le regole imposte dall’app auth:
- l template deve chiamarsi login.html e deve trovarsi in biblio3/templates/registration.
- Il success_url deve essere hardcodato in una variabile che chiameremo LOGIN_REDIRECT_URL in settings.py

Anche per il logout la logica è già implementata in tale modulo, non dobbiamo aggiungere nulla al nostro views.py. Il template lo daremo noi anche in questo caso, si deve chiamare
logged_out.html sempre in templates/registration.

Per mettere a disposizione le funzionalità della web app solo agli utenti autenticati dobbiamo utilizzare i django auth decorators (nel nostro caso preprocessing).
```python
from django.contrib.auth.decorators import login_required

@login_required
def my_situation(request):
	user = get_object_or_404(User, pk=request.user.pk)
	copie = user.copie_in_prestito.all()
	ctx = { "listacopie" : copie }
	return render(request,"gestione/situation.html",ctx)
title```

Django mette a disposizione un altro meccanismo di protezione specifico per le CBV chiamato **access mixin**. Si basa sul concetto di ereditarietà multipla, la quale è supportata da [[Python]].