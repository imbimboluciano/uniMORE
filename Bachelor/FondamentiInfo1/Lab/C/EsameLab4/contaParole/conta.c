#include<stdlib.h>
#include<string.h>

size_t conta_parole(const char* s) {
	size_t i;
	size_t  c = 0;
	char parola = 0;//variabile vero falso
	for (i = 0; i <= strlen(s); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')//sono su una parola
			parola = 1;
		else if (s[i] < 'a' || s[i]>'z')//sono fuori dalla parola
		{
			if (parola == 1)//sono sul primo carattere dopo la parola
			{
				c++;
				parola = 0;

			}

		}

	}
	return c;
}