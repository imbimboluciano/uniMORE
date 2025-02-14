Dispositivo di livello data link che opera a livello di frame Ethernet, esaminando l’header dei frame ed inoltrandoli selettivamente, sulla base dell’indirizzo MAC della loro destinazione (svolge funzioni di filtraggio).
![[bridge.png]]

A differenza dell'hub, il bridge isola i domini di collisione producendo un aumento del massimo throughput totale e può connettere tipi diversi di Ethernet dal momento che è un dispositivo store-and-forward. Inoltre i bridge imparano quali host possono essere raggiunti attraverso quali interfacce, e per fare ció mantengono delle tabelle di filtraggio costruite automaticamente senza bisogno dell’intervento di amministratori di rete: quando viene ricevuto un frame, il bridge “impara” la locazione del mittente e la registra nella tabella di filtraggio. 
Il record registrato nella tabella di filtraggio é formato dai seguenti campi:
- Indirizzo MAC dell’host
- Interfaccia del Bridge
- Time-To-Live (TTL) che è il periodo di validità delle informazioni memorizzate  nella tabella di filtraggio

Il principale svantaggio dell'autoapprendimento é che se un host viene spostato in una nuova LAN i frame sono inoltrati sul segmento di LAN sbagliato fino a quando l’host non invia il primo frame (modifica tabella di filtraggio) o fino allo scadere del TTL per la entry relativa all'host (cancellazione della entry dalla tabella).

Per aumentare l’affidabilità di una rete ed evitare blocchi in caso di guasti, è desiderabile avere ridondanza ovvero cammini alternativi dalla sorgente alla destinazione; cammini multipli, peró, possono creare dei cicli (moltiplicazione dei pacchetti). La soluzione a questo problema é lo **Spanning tree**, cioè un sottoinsieme della topologia originaria che non contiene cicli.
![[spanningtree.png]]

Infine i bridge implementano anche funzioni di privacy 