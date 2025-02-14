Un’organizzazione può suddividere il suo spazio di host address in gruppi detti  
subnet. Tipicamente questa pratica é utilizzata per raggruppare host basati sulla topologia fisica della rete. 
![[subnetting.png]]

Esempio:
- Indirizzo IP: 156.154.81.56  
- Network mask: 255.255.255.240
- Net ID: 10011100.10011010.0101001.00111000 AND 11111111.11111111.11111111.11110000 = 10011100.10011010.11110000.00110000 = 156.154.81.48
- Spazio di indirizzamento: 2^4 - 2 = 14 host
- Broadcast address: 156.154.81.63

![[subnetting2.png]]

Le subnet servono anche (e soprattutto) per facilitare il routing dei pacchetti all’interno della rete amministrata. Si assuma che arrivi un pacchetto con indirizzo destinazione: 150.100.12.176, per capire la rete di destinazione basta effettuare un AND tra l’indirizzo e la subnet mask.

Il subnet addressing modifica l’interpretazione degli indirizzi IP:
- indirizzamento gerarchico (schema originale)
![[indirizzamentogerarchico.png | center | 400]]
- routing gerarchico: i router esterni usano i primi due byte dell’indirizzo IP per il routing, mentre il router della rete locale usa il terzo byte dell’indirizzo IP.
![[routinggerarchico.png | center | 400]]
