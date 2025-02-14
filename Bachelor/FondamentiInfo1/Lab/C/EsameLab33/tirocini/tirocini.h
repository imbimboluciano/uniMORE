#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


struct tirocinio {
	char* nome;
	char* azienda1;
	char* azienda2;
	char* azienda3;
};

extern bool tirocinio_load(FILE* f, struct tirocinio* t);
