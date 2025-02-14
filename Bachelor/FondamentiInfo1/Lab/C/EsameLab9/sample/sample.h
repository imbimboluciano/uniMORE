#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


struct sample {
	int idSample;
	char nomeCategoria[20];
	double accuracy;
};

extern int sample_scrivi(FILE* f, const struct sample* s);
extern int sample_leggi(FILE* f, struct sample* s);

