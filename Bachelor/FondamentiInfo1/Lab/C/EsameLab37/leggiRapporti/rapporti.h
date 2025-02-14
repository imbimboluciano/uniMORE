#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdint.h> // Necessario per il tipo uint16_t
#include<stdio.h>
#include<stdlib.h>

struct rapporto {
	uint16_t id;
	char tipo;
	float valore;
};

extern struct rapporto* leggi_rapporti(const char* filename, uint16_t* n);