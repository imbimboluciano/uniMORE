#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>

struct seq {
	size_t len;
	uint16_t* values;
};

extern bool seq_load(const char* filename, struct seq* s);