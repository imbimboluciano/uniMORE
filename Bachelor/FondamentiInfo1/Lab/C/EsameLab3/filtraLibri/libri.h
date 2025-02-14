#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>


struct libro {
	unsigned int codice;
	char titolo[255];
	unsigned int pagine;
};


extern struct libro* filtra_libri(struct libro* plibri, unsigned int* pn, const char* cerca);