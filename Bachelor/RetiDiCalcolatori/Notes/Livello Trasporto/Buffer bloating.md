Problema legato a presenza di buffer molto grandi nella rete, tipicamente di dimensione variabile. La presenza di larghi buffer non determina perdita di pacchetti anche in presenza di congestione ma determina un aumento di RTT; quest'ultimo determina scarsa responsiveness rispetto alla congestione con crollo del throughput per l'effetto dei ritardi ed alto tasso di perdita dei pacchetti.

Le possibili contromisure sono le seguenti:
- Nuovi algoritmi di AQM (adaptive queue management) con gestione dinamica della dimensione dei buffer (algoritmo CoDel)
- Nuovi algoritmi che accorpano più flussi applicativi in un unico stream  TCP (google SPDY)