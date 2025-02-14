#include<stdio.h>
#include<stdlib.h>

void stampa_scomposizione(unsigned int n) {
    if (n >= 2) {
        unsigned int i;
        unsigned int* vet = NULL;
        unsigned int* tmp = NULL;
        int h = 0;
        int j = 0;
        int conta = 0;
        for (i = 2; i <= n; i++) // La ricerca procede per ogni numero
            while (n % i == 0) {    // Verifica se i è divisore
                n /= i;        // Effettua la divisione per i
                if (conta == 0) {
                    j++;
                    vet = realloc(vet, j * sizeof(unsigned int));
                    vet[j - 1] = i;
                    conta++;
                }
                else {
                    if (vet[j - 1] != i) {
                        h++;
                        tmp = realloc(tmp, h * sizeof(unsigned int));
                        tmp[h - 1] = conta;
                        j++;
                        vet = realloc(vet, j * sizeof(unsigned int));
                        vet[j - 1] = i;
                        conta = 1;
                    }
                    else {
                        conta++;
                    }
                }
            }
            h++;
            tmp = realloc(tmp, h * sizeof(unsigned int));
            tmp[h - 1] = conta;

            for (int k = 0; k < h; k++) {
                if (k == h - 1) {
                    if (tmp[k] == 1) {
                        fprintf(stdout, "%d", vet[k]);
                    }
                    else {
                        fprintf(stdout, "%d^%d", vet[k], tmp[k]);
                    }
                   
                }
                else {
                    if (tmp[k] == 1) {
                        fprintf(stdout, "%d * ", vet[k]);
                    }
                    else {
                        fprintf(stdout, "%d^%d * ", vet[k], tmp[k]);
                    }
                    
                }
                
            }
            free(vet);
            free(tmp);
    }
    else if (n == 0) {
        fprintf(stdout, "%d", 0);
    }
    else if (n == 1) {
        fprintf(stdout, "%d", 1);
    }
    
}