#include "gioielli.h"

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {
	if (filename == NULL) {
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Gioiello* gioielli = malloc(sizeof(Gioiello));
	Gioiello temp;
	size_t sizeFile = 0;

	int ret = fscanf(f, "%d %f %f",&temp.codice,&temp.peso, &temp.prezzo);
	if (ret < 0) return NULL;
	sizeFile++;
	gioielli = realloc(gioielli, sizeFile * sizeof(Gioiello));
	gioielli[sizeFile - 1] = temp;

	while (1) {
		int ret = fscanf(f, "%d %f %f", &temp.codice,&temp.peso, &temp.prezzo);
		if (ret < 0) break;;
		sizeFile++;
		gioielli = realloc(gioielli, sizeFile * sizeof(Gioiello));
		gioielli[sizeFile - 1] = temp;
	}
	
	fclose(f);

	Gioiello* res = malloc(sizeof(Gioiello));
	float max = 0;
	size_t sizeRes = 0;
	size_t fine = 0;
	while (budget > 0) {
		fine++;
		for (size_t i = 0; i < sizeFile; i++) {
			if (gioielli[i].peso == -1) {
				continue;
			}
			if (((gioielli[i].peso / gioielli[i].prezzo) > max) && (gioielli[i].prezzo <= budget)) {
				max = (gioielli[i].peso / gioielli[i].prezzo);
			}
		}
		
		for (size_t i = 0; i < sizeFile; i++) {
			if ((gioielli[i].peso / gioielli[i].prezzo) == max) {
				budget = budget - gioielli[i].prezzo;
				sizeRes++;
				res = realloc(res, sizeRes * sizeof(Gioiello));
				res[sizeRes - 1] = gioielli[i];
				gioielli[i].peso = -1;
				break;
			}
		}
		if (fine == sizeFile) break;
		max = 0;
	}

	*ret_size = sizeRes;
	free(gioielli);
	return res;
	



}