#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct person {
	char name[256];
	unsigned int age;
};
extern void person_read(FILE* f, struct person* pp);
