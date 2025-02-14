Un Web Cluster è un'aggregazione logica di macchine virtuali che distribuiscono un servizio in un data center. Consideriamo la struttura classica di un applicativo Web: Presentation logic, Business logic e back-end data. Il Web Cluster sarà formato dalle seguenti componenti:
- Front-end Switch
- Server Interni
- Informazioni del sito web (hostname e IP)
La filosofia di struttura è quella presentata nella seguente immagine.
![[webcluster.png]]

Le macchine virtuali (server) vengono replicati sia orizzontalmente (stessa funzionalità) che verticalmente. Al top del Web Cluster troviamo un cluster switch, cioè un dispositivo (hw o sw) che gestisce il carico, mappa gli IP dei server e gestisce il firewall. 


Recuperare Switch 4 e 7 (dove sono utilizzati)