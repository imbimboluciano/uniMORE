#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct dato {
	double valore;
	unsigned  classe;
};
extern struct dato* read_dati(const char* filename, unsigned int* pn);