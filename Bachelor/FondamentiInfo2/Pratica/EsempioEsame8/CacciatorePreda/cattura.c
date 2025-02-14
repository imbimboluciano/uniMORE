#include <string.h>
#include <stdio.h>
#include<stdlib.h>

int contacacc(const char* v, size_t v_size) {
    int count = 0;
    for (int i = 0; i < (int) v_size; i++) {
        if (v[i] == 'c' || v[i] == 'C')
            ++count;
    }
    return count;
}

void CacciaRec(const char* v, size_t v_size, int u, int cacciatori, int presi, int i, int* sol) {
    if (presi == cacciatori || i ==(int) v_size)
        return;

    if (v[i] == 'C' || v[i] == 'c')
    {
        for (int j = 0; j < (int)v_size; ++j)
        {
            if (v[j] == 'P' || v[j] == 'p')
            {
                if (j > i) {

                    if ((j - i <= u) && sol[j] != -2 && sol[i] == -1)
                    {
                        sol[i] = j;
                        sol[j] = -2;
                        CacciaRec(v, v_size, u, cacciatori, presi + 1, i + 1, sol);
                    }
                }
                else {
                    if ((j < i && i - j <= u) && sol[j] == -1 && sol[i] == -1)
                    {
                        sol[i] = j;
                        sol[j] = -2;
                        CacciaRec(v, v_size, u, cacciatori, presi + 1, i + 1, sol);
                    }
                }

            }
            else { 
                continue; 
            }

        }

    }
    CacciaRec(v, v_size, u, cacciatori, presi, i + 1, sol);
}




int* CacciatorePreda(const char* v, size_t v_size, int u)
{
    int* sol = calloc(v_size, sizeof(int));
    for (int i = 0; i <(int) v_size; ++i) {
        sol[i] = -1;
    }
    int cacciatori = contacacc(v, v_size);
    CacciaRec(v, v_size, u, cacciatori, 0, 0, sol);
    return sol;
}