extern unsigned int conta_occorrenze(const char* testo, const char* stringa);

int main(void) {
	unsigned int co = conta_occorrenze("Qui bisogna cercare la parola cercare", "cercare");
	return 0;
}