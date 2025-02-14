Per molte organizzazioni è importante avere reti semi - private con tre categorie di host:
1. nessun accesso da/a host fuori “dall’organizzazione” 
2. accesso parziale(workstation, host che possono raggiungere l’esterno)
3. accesso completo (server Web)

Poiché per molte organizzazioni non è necessario che tutti i loro indirizzi siano visibili globalmente, per evitare di sprecare indirizzi, la IANA ha definito delle reti private non uniche a livello mondiale e con indirizzi IANA privati (Non-Internet Routable [[IP]] Addresses) utilizzabili solo nella rete interna. 
![[IPnonroutable.png]]
In questo modo, un’organizzazione tipicamente ha la possibilità di progettare una rete che:  
-  include host visibili da Internet (host **pubblici**)  
- altri host che non sono visibili (host **privati**) , che possono scambiare pacchetti solo con altri host privati all’interno della stessa rete senza intermediari o con host pubblici mediante Application gateway (proxy) e Network Address Translation (NAT)

Il NAT router (router che si trova "al bordo" della rete interna) si interpone tra la rete locale di una organizzazione e Internet con i seguenti compiti: 
- Mappa gli indirizzi IP tra due domini (indirizzi locali <-> indirizzi IP globali)
- Aumenta la sicurezza evitando di rendere visibili all’esterno alcuni computer di una organizzazione
- Garantisce la trasparenza del routing tra gli end system
- Nascondere la struttura della rete, facendo in modo che tutti i pacchetti sembrino generati dal router
![[NAT.png]]
Si può distinguere tra source NAT (SNAT) e destination NAT (DNAT), a seconda che venga modificato l'indirizzo sorgente o l'indirizzo destinazione del pacchetto che inizia una nuova connessione:
- Nel source NAT, le connessioni effettuate da uno o più computer vengono alterate in modo da presentare verso l'esterno uno o più indirizzi IP diversi da quelli originali
- Nel destination NAT, le connessioni effettuate da uno o più computer vengono alterate in modo da venire redirette verso indirizzi IP diversi da quelli originali

In alcune versioni del NATting, è prevista la possibilità di  “tradurre” non solo l’indirizzo IP sorgente, ma anche la porta sorgente, questa funzionalitá é chiamata PAT (Port Address Traslation).

Per gestire la corrispondenza tra indirizzi IP interni ed indirizzi IP globali viene utilizzata una tabella di stato con le corrispondenze tra gli indirizzi e le porte originarie e i valori modificati. La corrispondenza viene chiamata binding e puó essere implemeentata in due versioni:
- **binding statico** o port forwarding, la tabella viene configurata manualmente (tecnica utilizzata per i web server) ![[bindingstatico.png]]
- **binding dinamico**, la tabella viene calcolata dinamicamente e cambia nel tempo a seconda del traffico. I numeri di porta degli host interni vengono mappati in numeri di porta presi da un pool del PAT router. ![[bindingdinamico.png]]

 Vantaggi | Svantaggi
------------ | ------------
  Ottima soluzione per la sicurezza | Distrugge la semantica della comunicazione Internet stateless e end-to-end 
 Soluzione economica, relativamente facile e veloce |  La cosiddetta NAT box modifica i pacchetti al volo e qualche volta questo richiede modifiche a livello di informazioni application e non solo header del datagramma IP
 | Consente massima flessibilità nella gestione interna degli indirizzi  | 


