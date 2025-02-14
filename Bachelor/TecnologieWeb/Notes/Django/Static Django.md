Una risorsa statica di una webapp è tutto ciò che non è dinamicamente generato o  
modificabile dall’utente (immagini, video, fogli di stile, JS scripts). Malgrado la semplicità del concetto di risorsa statica, in [[Django Framework]] gestire le risorse statiche può non essere banale. E’ uno di quegli aspetti in cui l’impostazione DEBUG=True|False causa una differenza significativa nel modo in cui vengono gestiti

### Debug = False
Mentre i template risiedono comunemente nella stessa macchina in cui è presente  
la logica in Python della nostra web app, Django non fa alcuna assunzione su  
dove nel mondo siano presenti le vostre risorse statiche, le quali possono risiedere su servizi cloud o CDN (content delivery networks)

![[staticDjango.png]]

Una possibile soluzione può essere la seguente:
1. Un client, tramite richiesta da browser contatta il nostro django web server.
2. La pagina di risposta contiene elementi dinamici, ma anche elementi statici. Quest’ultima deve essere servita, in quanto è collocata in un server apposito. 
3. Quindi, il web server può eventualmente avere una cache per questa specifica risorsa e/o immagine. 
4. Ad ogni modo, l’immagine viene combinata con gli altri elementi dinamici e poi finalmente rispedita al mittente della richiesta iniziale.

Per approfondimento: https://docs.djangoproject.com/en/4.0/howto/static-files/deployment/


### Debug = True
Nel nostro caso il flag di debug sarà sempre settato a true. Il modo più semplice per trattare le risorse statiche è il seguente:
1. Creiamo una cartella “static” allo stesso livello di dove abbiamo creato la cartella "templates”. Lì possiamo inserire le nostre risorse statiche.
```python
#in settings.py
STATICFILES_DIRS = [os.path.join(BASE_DIR, "static")]
```
2. Inseriamo il riferimento alle risorse nel file DTL
```html
{% load static %}
<img src="{% static '/foto.jpg' %}" alt="Mia immagine">  
<link rel="stylesheet" type="text/css" href='{% static "/css/style.css" %}'>
```
