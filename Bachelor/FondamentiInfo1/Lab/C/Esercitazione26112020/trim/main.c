/*Creare il file trim.c che consenta di utilizzare la seguente funzione:
extern char *trim(const char *s);
La funzione accetta una stringa zero terminata e ritorna un’altra stringa zero terminata, allocata dinamicamente nell’heap, contenente i caratteri della stringa in ingresso, senza tutti gli spazi iniziali e finali. La funzione deve ritornare NULL (e quindi non allocare memoria) se s è NULL.
Ad esempio:
“senza spazi” ->“senza spazi”
“ prima” ->“prima”
“dopo " ->“dopo”
“ a b ” ->“a b”
“ ” ->“”*/
#define _CRT_SECURE_NO_WARNINGS
extern char* trim(const char* s);

int main(void) {
	char* ris = trim(" prima ");
	return 0;
}