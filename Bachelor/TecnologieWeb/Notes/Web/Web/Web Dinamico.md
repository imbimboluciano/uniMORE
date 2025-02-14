Applicazioni Web che restituiscono pagine dinamiche, ossia che contengono informazioni modificate (personalizzate) in base a dati ricevuti dal client/utente. I primi siti web erano basati sull'utilizzo di [[Common Interface Gateway (CGI)]], cioè standard per l'interfacciamento dei server Web con applicazioni esterne per la generazione di contenuti dinamici.

Ogni URL corrispondeva ad un programma CGI eseguito dal server in tempo reale:  
1. Il programma CGI interagiva con il DB per generare il contenuto dinamico
2. Restituiva al server pagina HTML contenenti informazioni personalizzate 
3. Il server restituiva la pagina al client

![[cgi.png]]

