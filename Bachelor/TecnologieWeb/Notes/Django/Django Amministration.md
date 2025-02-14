Una delle caratteristiche più interessanti di [[Django Framework]] è l'interfaccia di amministrazione automatica. Legge i metadati dei model per fornire un'interfaccia rapida ed efficiente in cui utenti selezionati possono gestire i contenuti dell’applicazione web. Prima di accedervi dobbiamo creare un super utente attraverso il seguente comando:
```powershell
$ python manage.py createsuperuser
Username (leave blank to use ‘admin’): admin  
Email address: admin@admin.com  
Password: ****  
Password (again): ****  
Superuser created successfully.
```

Ora, utilizzando il comando runserver, aprendo il browser all’indirizzo 127.0.0.1:8000/admin, potremo accedere all’interfaccia di login per admin. Effettuando il login nella pagina di admin con le credenziali inserite dopo l’utilizzo del comando createsuperuser, si accede alla pagina di amministrazione vera e propria. Questa conterrà di default due tabelle sotto la voce AUTHENTICATION AND AUTHORIZATION: Groups e User, due model che fanno parte dell’autenticazione di default di django:
- Groups  definisce dei gruppi con specifici privilegi. 
- User contiene gli utenti registrati (almeno uno, il profilo appena creato)

Per aggiungere i propri model alla pagina di amministrazione è necessario modificare il file admin.py generato automaticamente alla creazione dell’app ‘soci’:
```python
admin.site.register('Model')
```