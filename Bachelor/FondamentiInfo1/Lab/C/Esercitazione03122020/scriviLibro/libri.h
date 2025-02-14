#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct libro {
	char* titolo;
	uint16_t* anni_ristampe;
};

extern bool libro_scrivi(const struct libro* p, FILE* f);
