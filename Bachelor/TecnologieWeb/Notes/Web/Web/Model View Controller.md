**Model-view-controller** è un pattern architetturale molto diffuso nello sviluppo di sistemi software in grado di separare la logica di presentazione dei dati dalla logica di business. Il MVC fornisce una struttura logica e modulare per sistemi fortemente interattivi (interazioni con l'utente) e complessi. Nato nell'ambito delle GUI (interfacce desktop) e legato alla programmazione ad oggetti;la sua popolarità ne ha determinato l'adozione anche in ambito [[Web]]. Questo modello aderisce alle best practice dell'ingegnerizzazione del software:
- Information hiding (livello di sicurezza dei dati)
- Disaccoppiamento (rendere le classi indipendenti tra loro)
- Don't Repeat Yourself (DRY)

Questo particolare pattern è formato da 3 principali componenti:
1. **Model** -> Astrazione della rappresentazione dei dati. Si occupa della gestione dei dati e per questo deve essere completamente indipendente e disaccopiato da View e Controller.
2. **View** -> Visualizzazione dei dati contenuti nel Model(gli stessi dati possono essere visualizzati in modo diverso in base al dispositivo di accesso).
3. **Controller** -> Gestisce gli eventi (interazioni utenti) modificando il Model e aggiornando la View

![[mvc.png]]


L'approccio MVC nel contesto Web richiede una maggiore attenzione a causa dell'architettura client-server. La visualizzazione (View) avviene sul client ma i dati risiedono sul server e ciò può portare ad avere possibili view con dati non aggiornati rispetto al server. In quest'ottica, si distinguono diverse interpretazioni del modello MVC  applicato al Web:
- **server-side**: tutti i componenti MVC risiedono sul server; il client manda richieste, che saranno gestite dal controller, e riceve in risposta una pagina Web completa dal componente view (polling con refresh periodico) -> potenzialmente inefficiente 
- **client-side**: parti dei componenti MVC vengono eseguite sul client