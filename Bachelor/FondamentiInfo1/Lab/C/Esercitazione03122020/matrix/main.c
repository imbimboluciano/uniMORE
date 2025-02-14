/*Creare i file matrix.h e matrix.c che consentano di utilizzare la seguente struttura:
struct matrix {
size_t rows, cols;
double *data;
};
e la funzione:
extern struct matrix *mat_transpose(const struct matrix *mat);
La struct consente di rappresentare matrici di dimensioni arbitraria, dove rows è il numero di righe,
cols è il numero di colonne e data è un puntatore a rows×cols valori di tipo double memorizzati per
righe. Consideriamo ad esempio la matrice
𝐴 = (1 2 3)
	(4 5 6)
questo corrisponderebbe ad una variabile struct matrix A, con A.rows = 2, A.cols = 3 e A.data
che punta ad un area di memoria contenente i valori {1.0, 2.0, 3.0, 4.0, 5.0, 6.0 }.

La funzione accetta come parametro un puntatore ad una matrice e deve ritornarne la trasposta,
allocata dinamicamente sull’heap. Se il puntatore passato alla funzione è NULL, la funzione ritorna
NULL.*/
#include "matrix.h"

int main(void) {
	double d[] = { 1.0,2.0,3.0,4.0,5.0,6.0 };
	struct matrix a = { 2,  3, NULL };
	a.data = d;
	struct matrix *aT = mat_transpose(&a);

	free(aT->data);
	free(aT);

	return 0;
}