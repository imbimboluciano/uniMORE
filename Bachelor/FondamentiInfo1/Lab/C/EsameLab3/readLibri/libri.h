#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


struct libro {
	unsigned int codice;
	char titolo[255];
	unsigned int pagine;
};

extern struct libro* read_libri(const char* filename, unsigned int* pn);