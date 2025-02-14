Nella commutazione a pacchetto i dati sono suddivisi in “parti” ed inviati attraverso la rete (non c'é prenotazione delle risorse e assegnamento esclusivo del mezzo fisico).
- Ogni comunicazione è divisa in pacchetti, i quali condividono le risorse della rete (pacchetti provenienti da diverse sorgenti sono “mescolati” sullo stesso link)
- Ogni pacchetto utilizza tutta la capacità trasmissiva di un collegamento e le risorse sono utilizzate sulla base della necessità (flusso incostante di dati).
- La domanda aggregata di risorse può eccedere la quantità disponibile ed non essendoci prenotazione si possono generare dei conflitti tra i pacchetti e congestione di pacchetti (riempimento del buffer) che sono le principali cause di ritardo.
- Le principali metriche prestazionali sono la **Bandwidth** (banda di trasmissione), cioè la quantità di dati trasmessi per unità di tempo e la **latenza**, cioè il ritardo end-to-end (importante nelle interazioni).
![[pswitching.png]]