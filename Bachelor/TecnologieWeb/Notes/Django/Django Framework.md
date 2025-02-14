Django è un web application framework free, open source, nato nel 2005 ed interamente scritto in [[Python]]. L'obiettivo dichiarato di Django è quello di rendere facile e veloce la creazione di applicazioni Web complesse e basate su database (database-driven Web sites). 

## Mvc in Django
Il pattern Model-View-Controller può implementato in 2 differenti modalità:
1. MVC classico: models.py (model), urls.py (controller), views.py (view)
2. MTV (Model Template View):  il Controller, e quindi la logica di business, è ripartito nel Template e nella View. Il Controller è gestito direttamente dal framework. ![[mvt.png]]



#### Model
Il Model in Django segue l'approccio Object-Relational Database (ORD), in cui viene definito un oggetto che rappresenta il database e con cui interagire per aggiornare il Model. Infatti il codice SQL per creare lo schema del DBMS è generato ed eseguito automaticamente da Django quando si esegue il deployment del modello. 

#### View
Il View in Django è il componente che include la logica di business (da non confondere la View con la visualizzazione grafica). Usa template Django per generare diversi tipi di output (HTML, XML, CSV, JSON).  I Template sono strumenti molto potenti che permettono di separare la logica (view) dalla presentazione (template).

#### Controller
Il Controller in Django è realizzato attraverso file urls.py, il quale mappa gli URL richiesti sulle opportune risorse richieste dall’utente.


## Struttura progetto Django

![[djangostruttura.png]]

Il file manage.py è un file si script per automatizzare le operazioni di Django; il file settings.py serve per impostare per il funzionamento dell'applicazione (definizione dei path dell'applicazione e configurazione accesso al DBMS). Infine il file urls.py serve per la configurazione degli URL del progetto. 
Un singolo progetto/sito Django può essere spezzato in diverse sotto-applicazioni. Ogni sotto-applicazione sarà un package Python separato con i propri componenti MVC.