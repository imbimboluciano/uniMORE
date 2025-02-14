Algoritmo adattativo rispetto a cambi di stato, in cui l'unità di scambio dell’informazione é il vettore di distanze rispetto alle varie destinazioni.
Ogni nodo aggiorna il proprio vettore di distanze in risposta a variazioni di costi sui link adiacenti ed invia un aggiornamento ai nodi adiacenti se il proprio vettore di distanze cambia. In particolare ogni nodo mantiene i seguenti dati:
- c(x,v) costo del link tra nodo x e nodo v  
- Dx= (Dx(y): y in N)  vettore di distanze del nodo x verso tutti i nodi y nella rete N  
- Dv= (Dv(y): y in N) vettori di distanze dei vicini v di x

Per il calcolo del costo minimo si usa la formula di Bellman-Ford: 
Dx(y) = min v { c(x,v) + Dv(y) } 
La formula è molto chiara:  tra tutti i nodi v adiacenti al nodo x, il  percorso da scegliere è quello che mi porta con il minor costo da v a y, a meno che il costo tra x e v sia talmente alto che mi conviene percorrere altre strade. 
![[dv1.png]]
![[dv2.png]]
![[dv3.png]]
![[dv4.png]]
![[dv5.png]]
![[dv6.png]]
![[dv7.png]]
![[dv8.png]]

In linea teorica questo tipo di algoritmo é molto efficiente ma sulla rete globale ci sono circa 1 miliardo di host e milioni di router, é credibile una tabella che riporti tutti i  router di Internet come destinazione? Gli algoritmi di Distance vector hanno problemi con la scalabilitá e sulla stabilitá, in particolare cosa succede in caso di rottura di un link? 
- I nodi che vertono su quel link, ricalcolano il vettore distanza 
- Aggiornano la propria routing table e trasmettono il nuovo vettore ai vicini  
- Ciascun nodo ricalcolerà il proprio vettore distanza e, iterativamente, lo invierà ai nodi vicini
Ci sono casi in cui questo aggiornamento é estremamente lento, questo fenomeno viene chiamato **effetto rimbalzo**. Consideriamo la situazione raffigurata nell'immagine sottostante e ipotizziamo che il link tra A e B abbia un problema. 
![[effectbouncing.png | center | 500]]
A questo punto B aggiorna le distanze per A tenendo conto dei dati di C (che però includevano il passaggio per B), B manda il vettore di distanze a C e C manda il vettore di distanze a B. 
![[bouncing1.png | center | 500]]
![[bouncing2.png | center | 500]]
![[bouncing3.png | center | 500]]
La distanza diretta da B verso A cresce molto e quindi, B sceglie C come prossimo hop per A, ma il percorso implicito da C verso A include B. Le tabelle di B e C si aggiornano gradualmente, ma si crea un loop che proseguirà fino a quando C considererà il proprio percorso verso A attraverso B minore di 25. 
Inoltre c'é il rischio che che in caso di rottura di un link ed host irraggiungibile il loop creatosi duri all'infinito (**count-to-infinity**). Esistono alcune possibili soluzioni a questi problemi:
1. Scegliere una soglia (abbastanza bassa) per  “rappresentare” l’infinito ed evitare cosí il “count-to-infinity”
2. Split Horizon: differenziare i vettori di distanze inviati ai nodi adiacenti e quindi il vettore di B inviato a C non conterrà le destinazioni raggiungibili tramite C.
3. Split Horizon with poisoned reverse: se B raggiunge A attraverso C, B avvertirà C  che la sua distanza verso A è infinita
4. Si devono selezionare percorsi senza cicli per evitare l’effetto rimbalzo e per far ció ogni aggiornamento del cammino minimo verso un nodo riporta l’intero percorso