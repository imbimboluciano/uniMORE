Come trasferire un messaggio che contiene altri caratteri (ASCII 8 bit) o addirittura dati in binario? É possibile utilizzare il MIME (Multipurpose Internet Mail Extension), il quale si interpone tra l’interfaccia utente ed il mailer, automatizzando in pratica la procedura di conversione. Introduce un ulteriore livello di incapsulamento, estendendo l’header del messaggio con 5 campi specifici del MIME:
- **MIME-version**: deve avere il valore 1.0 per indicare la conformità alle specifiche delle RFC
- **Content-Type**: descrive i dati nel “body”
	- Text, testo semplice
	- Multipart, messaggio composto da piú parti
	- Image
	- Video
	- Audio
	- Application, dati in formato binario ![[mimecontenttype.png]]
- **Content-Transfer-Encoding**: tipo di trasformazione usata per il body in modo da  renderlo trasmissibile con caratteri ASCII a 7 bit
- **Contend-ID**: per identificare le entità in contesti multipli
- **Content-Description**: commento

Lo standard MIME è nato per essere espandibile e per questo motivo alcune sue definizioni includono metodi per definire nuovi tipi di contenuto e altri attributi MIME. Per questa sua flessibilità viene utilizzato anche da altri protocolli non di posta, come [[HTTP]].

![[messaggioMIME.png]]
