#define CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>

static char* morse[] = { "._", "_...", "_._.", "_.." ,"." ,".._." ,"__." ,"...." ,".." ,".___" ,"_._" ,"._.." ,"__" ,"_." ,"___" ,".__." , "__._" ,"._." ,"..." ,"_" ,".._" ,"..._" ,".__" ,"_.._" ,"_.__" ,"__.." };


char* char_morse(const char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return morse[(int)(ch - 'A')];
	}
	return "/";
}


char* codifica_morse(const char* testo) {
	if (testo == NULL) 	return NULL;
	if (strcmp(testo, "") == 0) return calloc(1, 1);
	char* ris = calloc(250, 1);
	char tmp;

	for (size_t i = 0; testo[i] != 0; i++) {
		tmp = testo[i];
		strcat(ris, char_morse(tmp));
		if (testo[i + 1] != 0) strcat(ris, " ");
	}

	return ris;
}

