/* Nel file cornicetta.c implementare la definizione della funzione:
extern void stampa_cornicetta (const char *s);
La funzione deve inviare a stdout la stringa passata come parametro circondandola con una cornicetta composta dei caratteri ‘\’ e ‘/’ agli spigoli e di ‘-’ e ‘|’ sui lati. Prima e dopo la stringa bisogna inserire uno spazio. Ad esempio chiamando la funzione con s=“ciao”, la funzione deve inviare su stdout:
/------\
| ciao |
\------/
Si ricorda che in C il carattere ‘\’ deve essere inserito come ‘\\’. Gli <a capo> a fine riga sono obbligatori per una soluzione corretta.*/

extern void stampa_cornicetta(const char* s);

int main(void) {

	char* s = "ciao";
	stampa_cornicetta(s);
	return 0;
}