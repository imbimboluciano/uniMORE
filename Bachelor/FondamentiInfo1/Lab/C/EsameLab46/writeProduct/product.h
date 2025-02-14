#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

struct product {
    char* productId;
    char* fullName;
    int price;
};

extern void write_products(FILE* f, const struct product* list, size_t n);