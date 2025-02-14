Vediamo una panoramica sui principali strumenti di amministrazione. Le principali funzionalitá richieste sono le seguenti:
1. Data collection = [[SNMP]]
2. Data storage e visualization = rrdtool lavora in modalità round-robin, cioè alloca file a dimensione fissa e l'inserimento di nuovi dati porta a data consolidation nei dati vecchi (banalmente una media)
4. Configuration 
5. Additional functionality
	- Availability = Nagios, test periodico di servizi per valutarne la disponibilità; in caso di problemi genera allarmi
	- Utilisation = Cacti, per monitorare usage e prestazioni

![[rrdtool.png | center]]
