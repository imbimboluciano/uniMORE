Funzione opposta al protocollo [[ARP]], cioé dato un indirizzo MAC ricava l’indirizzo [[IP]]  
corrispondente. Il meccanismo e la struttura del messaggio sono analoghi ad ARP :
1. Broadcast di una richiesta  
2. Solo l’host interessato risponde (in questo caso, il server RARP)

Veniva utilizzato al posto del [[DHCP]] per il boot della rete (invio MAC address in broadcast per configurare il proprio IP) ma oggi é poco utilizzato.