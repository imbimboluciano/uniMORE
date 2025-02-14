#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

static char* morse[] = { "._", "_...", "_._.", "_.." ,"." ,".._." ,"__." ,"...." ,".." ,".___" ,"_._" ,"._.." ,"__" ,"_." ,"___" ,".__." , "__._" ,"._." ,"..." ,"_" ,".._" ,"..._" ,".__" ,"_.._" ,"_.__" ,"__.." };


char* decodifica_morse(const char* codice) {
	if (codice == "")	 return NULL;
	char c[5];
	int pos = 0, cletti;
	char* ris = calloc(strlen(codice) + 1, 1);
	
	while (1) {
		int nletti = sscanf(codice + pos, "%s%n", c, &cletti);
		if (nletti == EOF)	break;

		pos += cletti;


		if (strcmp(c, "._") == 0)	strcat(ris, "A");
		else if (strcmp(c, "_...") == 0)	strcat(ris, "B");
		else if (strcmp(c, "_._.") == 0)	strcat(ris, "C");
		else if (strcmp(c, "_..") == 0)	strcat(ris, "D");
		else if (strcmp(c, ".") == 0)	strcat(ris, "E");
		else if (strcmp(c, ".._.") == 0)	strcat(ris, "F");
		else if (strcmp(c, "__.") == 0)	strcat(ris, "G");
		else if (strcmp(c, "....") == 0)	strcat(ris, "H");
		else if (strcmp(c, "..") == 0)	strcat(ris, "I");
		else if (strcmp(c, ".___") == 0)	strcat(ris, "J");
		else if (strcmp(c, "_._") == 0)	strcat(ris, "K");
		else if (strcmp(c, "._..") == 0)	strcat(ris, "L");
		else if (strcmp(c, "__") == 0)	strcat(ris, "M");
		else if (strcmp(c, "_.") == 0)	strcat(ris, "N");
		else if (strcmp(c, "___") == 0)	strcat(ris, "O");
		else if (strcmp(c, ".__.") == 0)	strcat(ris, "P");
		else if (strcmp(c, "__._") == 0)	strcat(ris, "Q");
		else if (strcmp(c, "._.") == 0)	strcat(ris, "R");
		else if (strcmp(c, "...") == 0)	strcat(ris, "S");
		else if (strcmp(c, "_") == 0)	strcat(ris, "T");
		else if (strcmp(c, ".._") == 0)	strcat(ris, "U");
		else if (strcmp(c, "..._") == 0)	strcat(ris, "V");
		else if (strcmp(c, ".__") == 0)	strcat(ris, "W");
		else if (strcmp(c, "_.._") == 0)	strcat(ris, "X");
		else if (strcmp(c, "_.__") == 0)	strcat(ris, "Y");
		else if (strcmp(c, "__..") == 0)	strcat(ris, "Z");
		else if (strcmp(c, "/") == 0)	strcat(ris, " ");
	}

	return ris;
}

