/*
Creare i file lettura.h e lettura.c che consentano di utilizzare la seguente funzione:
extern double *leggidouble(const char *filename, size_t *size);
È stato definito un formato testo (veramente banale) di dati per memorizzare numeri con la
virgola, che consiste nel memorizzare i numeri in formato testo in base 10 separandoli con
whitespace. Ad esempio un file contenente i valori 7.2, 8.19 e 9.0 verrebbe codificato come:
7.2 8.19 9.0
o anche
7.2↵
8.19↵
9.0↵
o anche
7.2↵
8.19 ↵
→ 9.0↵
(Con ↵ indichiamo l’<a capo> e con → indichiamo il tab)
La funzione leggidouble() riceve in input il nome di un file come stringa C e deve: aprire il file in
lettura in modalità tradotta (testo), leggere i numeri in variabili di tipo double allocando
dinamicamente la memoria, impostare size al numero di numeri trovati nel file, e ritornare un
puntatore alla memoria allocata. Se l’apertura fallisce o se non è possibile leggere nemmeno un
numero, ritornare NULL. Ricordarsi comunque di chiudere il file se l’apertura è andata a buon fine.*/
#include "lettura.h"


int main(void) {
	return 0;
}