Gli algoritmi Link State (LS) sono centralizzati e quindi prevedono che la topologia di rete e i costi di ogni link siano noti. Ogni nodo calcola lo stato dei link ad esso  connessi, ciascun nodo periodicamente trasmette identità e costi dei link connessi (link state broadcast)  e ciascun nodo calcola i cammini di costo minimo verso tutti gli altri nodi della rete mediante l’Algoritmo di Dijkstra. Periodicamente vengono inviati in broadcast, su tutti i link del nodo, dei pacchetti LSP con le seguenti informazioni:
- Node ID
- Lista di vicini e costo dei rispettivi link
- Numero di sequenza per accorgesi di errori in caso di delivery out-of-order delle informazioni
- Time To Live (TTL)

L'inoltro dei pacchetti LSP viene fatto con tecnica flooding, consideriamo il caso in cui  il nodo i riceve un LSP dal nodo j:
- Se il pacchetto LSP proveniente da j é il piú recente viene salvato nel database e una copia viene inoltrata su tutti i link connessi al nodo i
- Altrimenti il pacchetto LSP viene scartato

Come giá detto per il calcolo del costo minimo viene utilizzato l’Algoritmo di Dijkstra nel quale si definiscono:
- c(i,j) costo del link tra nodo i e nodo j  
- D(v) costo minimo del cammino verso il nodo v (minimo per la iterazione corrente)
- p(v) immediato predecessore di v lungo il cammino a costo minimo verso v  
- N gruppo nodi il cui cammino di costo minore è noto definitivamente

![[ls1.png | center | 600]]
![[ls2.png | center | 600]]
![[ls3.png | center | 600]]
![[ls4.png | center | 600]]
![[ls5.png | center | 600]]
![[ls6.png | center | 600]]

