#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>


struct stringa {
	unsigned char length;
	char* s;
};

extern struct stringa* read_stringhe_bin(const char* filename, unsigned int* pn);