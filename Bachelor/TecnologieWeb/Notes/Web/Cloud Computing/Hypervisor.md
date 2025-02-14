Conosciuto anche come virtual machine monitor (VMM)  é  il componente centrale e più importante di un sistema basato su macchine virtuali. Una macchina sulla quale venga eseguito un hypervisor che a sua volta controlla una o più macchine virtuali è detta macchina host, e ogni macchina virtuale è detta macchina guest.  Grazie ad un hypervisor, su una macchina host possono essere in esecuzione contemporaneamente diverse macchine guest, su ognuna delle quali puo' girare un sistema operativo diverso che ha il controllo sulle risorse hardware virtualizzate rese disponibili dall'hypervisor. 

### Hypervisor Type-1
Detti anche native o bare-metal hypervisors, sono hypervisor eseguiti direttamente sull'hardware dell'host, del quale hanno quindi controllo diretto (Es. Microsoft Hyper-V e Xbox One system software, Oracle VM Server).

### Hypervisor Type-2
Detti anche hosted hypervisor, vengono eseguiti all'interno di un tradizionale sistema operativo, proprio come un qualsiasi altro programma (Es. VirtualBox, VMware Player e VMware Workstation).

![[hv.png]]

