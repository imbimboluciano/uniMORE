#include <stdio.h>

int main(void)
{
	char str[255] = "davide chiossi";
	char* p;
	p = &str[0];
	int c = 0;
	__asm {
		mov ebx, p
		mov esi, 0
		mov eax, 0

		ciclo:
		mov cl, byte ptr[ebx + esi * 1]
			cmp cl, 0
			je fine
			cmp cl, 'a'
			je vocale
			cmp cl, 'e'
			je vocale
			cmp cl, 'i'
			je vocale
			cmp cl, 'o'
			je vocale
			cmp cl, 'u'
			je vocale
			jmp incremento

			vocale :
			inc eax
			jmp incremento

			incremento :
			inc esi
			jmp ciclo

			fine :
			mov c, eax
	}
	printf("%d", c);
	return 0;
}