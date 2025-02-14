#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

typedef unsigned char byte;
extern byte* read_file(const char* szFileName, size_t* cb);