#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct person {
	char name[256];
	unsigned int age;
};

extern unsigned int count_teenagers(FILE* f);
