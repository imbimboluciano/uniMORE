L’insieme di tutti i meccanismi standard di naming delle risorse Web è l’Uniform Resource Identifiers (URI) che é composto da 3 parti:
1. **Uniform Resource Locator (URL)**: specifica la locazione fisica delle risorse
	- pagine (testo, immagini, suoni, video, ...)  
	- risultati di esecuzioni  
	- programmi eseguibili
1. **Uniform Resource Name (URN)**: proposta per la rappresentazione univoca dei nomi delle risorse (poco utilizzata)
2. **Uniform Resource Characteristics (URC)**: metadati della risorsa

In particolar modo concentriamoci sull'URL, il quale é formato da 3 campi:
- Schema: indica il modo con cui accedere alla risorsa, cioè quale protocollo bisogna usare per interagire con il server che controlla la risorsa (di norma [[HTTP]])
- host.domain: è l’hostname del nodo nel quale risiede la risorsa Web.
- pathname: identifica la risorsa presso il server Web
- Dopo il pathname é possibile specificare dei parametri attraverso query string
```url
					schema :// host.domain / pathname  
				http :// www.dsi.unimo.it / docenti/esami.html
```

Le richieste per una risorsa o una pagina [[Web]] possono essere singole (hit) o molteplici e allora si parla di session utente.
![[URL.png]]


