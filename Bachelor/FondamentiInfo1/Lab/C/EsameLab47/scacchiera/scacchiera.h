#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

struct scacchiera {
    char caselle[64];
};


extern void stampa_scacchiera(const struct scacchiera* sc);