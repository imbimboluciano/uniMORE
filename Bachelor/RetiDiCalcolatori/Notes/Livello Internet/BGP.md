BGP viene introdotto per sostituire EGP (primo protocollo di routing inter-AS) ed usa un algoritmo distribuito di tipo [[Distance vector protocol]] (decentralizzato). Protocollo principalmente utilizzato dagli ISP per il routing inter-AS ed in AS molto grandi come routing intra-AS. Le funzioni principali del BGP sono le seguenti:
- Scambiare informazioni di raggiungibilità tra AS confinanti, detti peer
- Propagare le informazioni di raggiungibilità a tutti i router all’interno di un AS ([[#Path Vector]])
- Determinare i percorsi migliori in base a informazioni di raggiungibilità e policy di routing

BGP fa uso di connessioni TCP semi-permanenti per far comunicare i router confinanti (peers) che si scambiano messaggi formando una sessione BGP che può essere di 2 tipi:
- interna (I-BGP) -> tra router dello stesso AS
- esterna (E-BGP) -> tra router di AS diversi

In base alla sessione gestita ed alla loro posizione i router si dividono in **transit router**, i quali gestiscono traffico I-BGP all’interno dell’AS (devono essere tutti peer), e **border router**, i quali gestiscono il traffico E-BGP tra diversi AS.
![[bgp.png]]

Come funziona il BGP? 
1. 3a annuncia a 1c i prefissi di rete raggiungibili da AS3  attraverso una sessione E-BGP  
2. 1c usa I-BGP per distribuire le informazioni di raggiungibilità a tutti i router in AS1 (1a – 1d – 1b) 
3. 1b annuncia a 2a i prefissi raggiungibili da AS3 e AS1 attraverso una sessione E-BGP 

L’annuncio di un prefisso comprende attributi BGP, tra cui i più importanti sono:  
- AS-PATH: elenco degli AS attraverso cui è passato l’annuncio del prefisso (strada  attraversata e misura della lunghezza del cammino)
- NEXT-HOP: lo specifico router nel next-hop AS da cui giunge l’annuncio

Quando un border router riceve un annuncio utilizza le policy locali per decidere se accettare/scartare l’annuncio. Le policy locali si basano su diverse regole:
- valore di preferenza
- AS-PATH più breve
- Router di NEXT-HOP più vicino


## Path Vector
BGP usa Path Vector, una variante dell’algoritmo distribuito [[Distance Vector Protocol]], nel quale ogni routing update contiene non solo informazioni adiacenti, ma sull’intero cammino verso la destinazione attraverso gli AS. Questa caratteristica permette di individuare eventuali loop e risolvere l'effetto rimbalzo.
![[pathvector.png]]
