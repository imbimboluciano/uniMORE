#pragma once
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

typedef struct {
	size_t size;
	char* data;
} String;

typedef String ElemType;

extern String StringCopy(const String* e);

extern int StringCompare(const String* a, const String* b);// comparazione tra stringhe simili al confronto standard

extern void Swap(String* a, String* b);
extern void StringDelete(String* e);