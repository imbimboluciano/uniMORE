Grazie ai groups di [[Django Framework]] possiamo gestire diverse tipologie di utenti.
Un gruppo in Django è un contenitore di permessi.
- Gli Users possono essere associati a nessuno, uno o a più gruppi, “ereditandone” i permessi
- I permessi appaiono come regole (o vincoli)
	- Possono essere assegnati agli Users
	- Possono essere assegnati ai Gruppi
	- Si applicano alle risorse della webapp (tabelle, DB, FBV/CBV)

I groups possono essere definiti sia a livello di codice che tramite interfaccia grafica dal pannello di admin.
```python
from django.contrib.auth.models import Group

gruppo_a = Group.objects.get_or_create(name='nome_gruppo')

#definizione dei permessi…
gruppo_a.permissions.set([permission_list])
gruppo_a.permissions.add(permission, permission, ...)
gruppo_a.permissions.remove(permission, permission, ...)
gruppo_a.permissions.clear()


#inserimento utente in gruppo…
group_a.user_set.add(user)
user.groups.add(group_a)
```

Ora che abbiamo diverse categorie (o meglio gruppi) di utenti, possiamo usare
dei decoratori appositi per controllare che l’utente che richiede una certa
funzionalità abbia l’autorizzazione necessaria
```python
def has_group(user):
	return user.groups.filter(name='nome_gruppo').exists()

from django.contrib.auth.decorators import user_passes_test

@user_passes_test(has_group)
def my_view(request):
	…
```

Ed i mixins per i Gruppi? Django qui offre molto meno rispetto a quello che abbiamo visto per l’autenticazione. Esistono però moduli esterni ed aggiuntivi che ci permettono di avere queste funzionalità. In particolare, si consiglia l’uso di django_braces:
```powershell
$ pipenv install django-braces
```