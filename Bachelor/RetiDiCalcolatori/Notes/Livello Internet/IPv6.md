IPv6 è la versione dell'Internet Protocol designata come successore dell'[[IP]]v4. Tale protocollo introduce alcuni nuovi servizi e semplifica molto la configurazione e la gestione delle reti IP: 
- Uso di numeri in notazione esadecimale e quindi 8 blocchi di 16 bit (4 cifre) ciascuno (Es. 2001:cdba:0000:0000:0000:0000:3257:9652)

Come per l'IPv4 anche il procollo IPv6 dispone di alcuni indirizzi speciali utili per specifiche situazioni:
- Compatibilità con IPv4 -> ::/96 
- Indirizzo non specificato -> ::/128   
- Loopback address -> ::1/128 come 127.0.0.1 per IPv4  
- Indirizzo di esempio ->  2001:db8::/32 
- Unique Local Address (ULA) -> fc00::/7 
- Multicast -> ff00::/8 
- Link-local prefix -> fe80::/10 indirizzo valido solo sul link locale

Nell'header dell'IPv6 troviamo le principali differenze con il protocollo IPv4:
- Versione (4 bit), mappato 1:1 con IPv4 
- Classe di traffico (8 bit), analogo a campo ToS IPv4 (priorità del datagramma)
- **Etichetta di flusso (20 bit)**, campo nuovo per supportare l'ottimizzazione del traffico. Impostato da una sorgente per identificare più datagrammi come appartenenti a un unico flusso di traffico (può anche creare l'equivalente di un circuito virtuale)
- Lunghezza del payload (16 bit)
- Next Header, indica il tipo di protocollo usato per il payload (campo type)
- Hop Limit, come TTL in Ipv4
![[Ipv6.png]]

Notiamo che, rispetto all'header IPv4, non ci sono campi legati alla frammentazione; questo perchè IPv6 parte dal presupposto che frammentare è il Male. Solo la sorgente può frammentare (ovvero creare datagrammi più piccoli) e solo il destinatario può eventualmente riassemblare. Inoltre IPv6 decide di omettere il campo checksum per motivi di natura pratica (la corruzione di header è estremamente rara). Infine, un'altra differenza con l'header IPv4 è quella che non esiste il campo option e quindi l'header ha dimensione fissa (40 byte).

Per gestire le eventuali problematiche legate all'IPv6 sono stati definiti 2 nuovi protocolli di supporto:
1. ICMPv6
2. [[Neighbor Discovery Protocol]]


## Transizione a IPv6
La transizione non può avvenire improvvisamente perchè oggi non sarebbe possibile fare un reboot di [[Internet]]. Quindi si prevede una progressiva diffusione di sistemi dual-stack,cioè che possono gestire sia IPv4 che IPv6, instradando traffico IPv6 su link IPv4. Per fare ciò si può usare la tecnica di tunneling: si incapsula il datagramma IPv6 come payload di un datagramma IPv4 ed il tunnel trasporta IPv6 usando il “link” IPv4 come se fosse un livello H2N tra due router IPv6. Tra i sistemi di tunneling automatici più diffusi ci sono:
- 6over4, utilizzo di IPv4 come se fosse livello 2
- Ds-lite, incapsula tutti i dati dalle applicazioni IPv4 in pacchetti IPv6 e li trasmette al provider Internet tramite la connessione IPv6 (tunnel IPv4-in-IPv6).
- 6to4, si inserisce l’indirizzo IPv4 in un prefisso IPv6.
- 6rd, stesso approccio di 6to4 ma si lavora con indirizzi IPv6 pubblici
- [[NAT]]
