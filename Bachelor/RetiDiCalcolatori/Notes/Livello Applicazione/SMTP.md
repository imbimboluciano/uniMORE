Il Simple Mail Transfer Protocol é protocollo applicativo per gestire lo scambio di messaggi di [[Posta Elettronica]] tra i mail server. Il paradigma di comunicazione é il solito client/server, in cui il client é MTA del mittente ed il server é MTA del destinatario. Al livello di trasporto si affisa al protocollo [[TCP]] per il trasferimento affidabile dei messaggi tra client e server. Il dialogo sender-receiver avviene sulla porta 25 ed è costituito da interazioni comando/risposta in forma testuale:
- Comando in formato ASCII-7 bit  ![[comandiSMTP.png | 450]]
- Risposta, status code e frase di commento ![[rispostaSMTP.png | 450]]

SMTP usa connessioni TCP persistenti per trasferire più messaggi in una sola volta dallo stesso MTA sender allo stesso MTA receiver. Il trasferimento é diviso in 3 fasi:
1. Handshaking (SMTP greetings diverso da TCP handshaking)
2. Trasferimento messaggi  
3. Chiusura
![[trasferimentoSMTP.png | center | 600]]

Vista l'architettura del SMTP é possibile inviare una mail senza usare uno user agent, utilizzando anche con nome “mittente” fittizio; questa caratteristica apre una falla di sicurezza importante (spoofing di email).

Il messaggio di mail consiste di due parti:
1. Un header che contiene dei campi codificati  
2. Il body del messaggio che deve essere un testo in ASCII a 7 bit (recenti evoluzioni consentono anche e-mail in formati più elaborati attarverso [[MIME]])
3. Una linea vuota divide header da body e una riga contenente solo un '.' indica la fine del messaggio![[messaggioSMTP.png | center | 400]]
