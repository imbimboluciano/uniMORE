Nella maggior parte delle reti dobbiamo introdurre delle tecniche di sicurezza per garantire:
- **Confidenzialitá**, cioé che le informazioni devono essere accessibili solo a determinate persone
- **Integritá**, cioé che i dati non devono essere modificati da chi non ne ha diritto
- **Disponibilitá**
- **Autenticitá**

In quali livelli devono essere introdotti i meccanismi di sicurezza di rete?
Più si sale nello stack TCP/IP e più le funzioni di sicurezza potranno essere specifiche ed indipendenti dalle reti sottostanti; invece più si resta in basso nello stack e più sarà possibile “espellere” in fretta gli intrusi, ma le informazioni su cui  basare le decisioni saranno più scarse. Per questo motivo si applica il paradigma di **defense in depth** o multilivello di difesa, cioé gli elementi di sicurezza devono essere introdotti a tutti i livelli.

La sicurezza nelle reti si basa principalmente su 2 aspetti:
- **Segmentazione**: partizionare le risorse aziendali logiche e fisiche 
- **Segregazione**: applicare controllo degli accessi

Per applicare i principi generali della sicurezza alle reti di calcolatori sono state definite le seguenti tecniche:
- [[VLAN]], tecnologia non nata per la sicurezza ma che risulta utile per ridurre il dominio di broadcast e dividere il traffico
- [[NAT]] (PAT)
- [[Firewall]]
- DMZ (Demilitary zone)