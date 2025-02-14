Programma scritto con qualsiasi linguaggio di programmazione (generalmente C) che definisce lo standard di comunicazione col server circa la modalità per scambiare  
parametri di input (variabili di ambiente, riga di comando o std input) e output. 

Hanno avuto vita breve per le seguenti motivazioni:
1. Scalabilità -> Un nuovo processo invocato per ogni richiesta al server; questo creava un carico pesante sul server al crescere della quantità di richieste ed al crescere degli utenti connessi (crescita esponenziale con la diffusione del web)
2. Ripetizione del codice
3. Poco riutilizzabile


Per aumentare le prestazioni ed evitare la creazione di un nuovo processo ad ogni richiesta del client furono introdotte e definite le tecnologie di scripting:
- **FastCGI**: permette di condividere un’istanza di un programma CGI
- **Server API (Netscape NSAPI, MS ISAPI)**: Librerie condivise caricate nello spazio del server HTTP, in grado di servire richieste multiple senza creare nuovi processi. Ma poca portabilità (legate al server HTTP) e vulnerabili  
-  **mod_perl, mod_python, mod_php**: moduli di Apache, in grado di interpretare script all’interno del processo HTTP


Come ulteriore evoluzione, nascono i [[Linguaggi di Scripting]] e i  [[Web Framework]].
