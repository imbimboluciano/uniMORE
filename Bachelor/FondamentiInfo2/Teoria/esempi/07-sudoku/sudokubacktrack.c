/**
***	sudokuSolve.c
***
***	Letta in input una matrice 9x9 di numeri interi da un file,
***	verifica con un procedimento esaustiva l'esistenza di una
***	soluzione della partita.
***
***
**/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 9

/*
 *	leggiFile(s, M)
 *
 *	Legge da file di testo ASCII una configurazione del Sudoku
 *	e la memorizza nella matrice di interi.
 *
 *	s: stringa contenente il nome del file da aprire; se la stringa
 *	   e' nulla viene richiesto il nome del file all'utente.
 *
 *	M: matrice di interi 9x9 in cui viene memorizzata la configurazione.
 *
 *	Restituisce 1 se la lettura del file e` andata a buon fine,
 *	0 altrimenti.
 *
 */

int leggiFile(char *s, int M[N][N]) {
	FILE *f;
	int i, j, rc;

	while (s[0] == '\0') {
		printf("Nome del file: ");
		scanf("%s", s);
	}
	if ((f = fopen(s, "rt"))) {
		for (i=0; i<N && !feof(f); i++) {
			for (j=0; j<N && !feof(f); j++) {
				fscanf(f, "%d", &M[i][j]);
			}
		}
		if (i==N && j==N) {
			rc = 1;
		} else {
			rc = 0;
		}
		fclose(f);
	} else {
		fprintf(stderr, "ERRORE: il file %s non puo' essere aperto in lettura\n\n", s);
		rc = 0;
	}
	return(rc);
}

/*
 *	stampaConfigurazione(M)
 *
 *	Stampa la matrice M 9x9 con una configurazione della
 *	tavola di gioco.
 *
 *	M: matrice 9x9 di interi
 *
 */

void stampaConfigurazione(int M[N][N]) {
	int i, j, h, k;

	printf("\n+---------+---------+---------+\n");
	for (i=0; i<3; i++) {
		for (j=3*i; j<3*(i+1); j++) {
			printf("|");
			for (k=0; k<3; k++) {
				for (h=3*k; h<3*(k+1); h++) {
					printf("%2d ", M[j][h]);
				}
				printf("|");
			}
			printf("\n");
		}
		printf("+---------+---------+---------+\n");
	}
	return;
}


/*
 *	verifica(M, i, j, debug)
 *
 *	Verifica che l'elemento M[i][j] contenga un valore compatibile
 *	con quelli presenti nella colonna j, nella riga i e nel riquadro
 *	3x3 in cui si trova l'elemento M[i][j].
 *
 *	M: matrice 9x9 di numeri interi con la configurazione di gioco.
 *
 *	i: indice di riga dell'elemento da verificare.
 *
 *	j: indice di colonna dell'elemento da verificare.
 *
 *	debug: se debug=1 visualizza messaggi di debug per seguire il
 *	   procedimento di calcolo.
 *
 *	La funzione restituisce 1 se la il valore di M[i][j] e'
 *	compatibile con il resto della matrice, 0 altrimenti.
 *
 */

int verifica(int m[N][N], int i, int j, int debug) {
	int h, k, rc;


//	printf("Verifica di m[%d][%d]=%d\n", i, j, m[i][j]);
	rc = 1;
	for (h=0; h<N && rc == 1; h++) {
		if (h != j && m[i][h] == m[i][j]) {
			rc = 0;
			if (debug)
				printf("m[%d][%d]=%d ... no: doppione in riga.\n", i, j, m[i][j]);
		} else {
			if (h != i && m[h][j] == m[i][j]) {
				rc = 0;
				if (debug)
					printf("m[%d][%d]=%d ... no: doppione in colonna.\n", i, j, m[i][j]);
			}
		}
	}
	for (h=3*(i/3); h<3*(i/3+1) && rc == 1; h++) {
		for (k=3*(j/3); k<3*(j/3+1) && rc == 1; k++) {
			if ((h != i || k != j) && m[h][k] == m[i][j]) {
				rc = 0;
				if (debug)
					printf("m[%d][%d]=%d ... no: doppione nel quadrato!\n", i, j, m[i][j]);
			}
		}
	}
	if (debug) {
		if (rc==1) {
			printf("Il valore m[%d][%d]=%d e' compatibile.\n", i, j, m[i][j]);
		} else {
			printf("Il valore m[%d][%d]=%d non e' compatibile.\n", i, j, m[i][j]);
		}
	}
	return(rc);
}

/*
 *	sudokuSolve(M, debug)
 *
 *	Funzione ricorsiva per la ricerca della configurazione risolutiva
 *	che prova a collocare nelle posizioni vuote tutti valori
 *	k=1, 2, ..., 9.
 *
 *	M: matrice 9x9 di interi con la configurazione corrente della
 *	   griglia di gioco.
 *
 *	debug: se debug=1  visualizza i messaggi di debug per seguire
 *	   l'evoluzione del processo di ricerca della soluzione.
 *
 *	La funzione restituisce 1 se la funzione riesce ad individuare
 *	una configurazione finale, 0 altrimenti (se la configurazione
 *	iniziale non ammette alcuna soluzione).
 *
 */

void sudokuSolve(int m[N][N], int debug, int i, int j, int *sol) {
	int k;

	if(i==N){
        (*sol)++;
		printf("SUDOKU risolto (%d)!\n", *sol);
		stampaConfigurazione(m);
		getchar();
	    return;

	}

	if (debug) {
		printf("\nProviamo a risolvere questa configurazione:");
		stampaConfigurazione(m);
	}

   int ii=i;
   int jj=j+1;
   if(jj==N) {
	   ii++;
	   jj=0;
   }
	if(m[i][j] == 0){
	   for (k=1; k<10; k++) {
		   m[i][j] = k;
     	if (debug) {
           printf("Provo m[%d][%d]=%d\n", i, j, m[i][j]);
    	}
		   if (verifica(m, i, j, debug) == 1) {
	    		if (debug) getchar();
		       sudokuSolve(m, debug, ii, jj, sol);
	       }
	       m[i][j] = 0;
	   }
	}
	else{
     	if (debug) {
         printf("Non cambio m[%d][%d]=%d\n", i, j, m[i][j]);
    	}
	   sudokuSolve(m, debug, ii, jj, sol);

	}
	return;
}

/*
 *	main
 *
 *	Funzione principale.
 *
 */

int main(int argc, char *argv[]) {
	char s[100];
	int m[N][N], i, debug = 0, sol=0;

	s[0] = '\0';

	if (leggiFile(s, m) == 1) {
		stampaConfigurazione(m);
		getchar();
		getchar();
		sudokuSolve(m, debug, 0, 0, &sol);

	}

	getchar();
	return(0);
}
