#include "scacchiera.h"

void stampa_scacchiera(const struct scacchiera* sc) {

	char* f1 = "+---+---+---+---+---+---+---+---+";

	for (int r = 2*7+1; r >= 0; r--) {
		if (r % 2 != 0) {
			fprintf(stdout, "%s\n", f1);
			continue;
		}
		
		fprintf(stdout, "|");
		for (int c = 0; c < 8; c++) {
			fprintf(stdout, " %c |",sc->caselle[c * 8 + (r/2)]);
		}
		fprintf(stdout, "\n");
	}
	fprintf(stdout, "%s\n", f1);

}