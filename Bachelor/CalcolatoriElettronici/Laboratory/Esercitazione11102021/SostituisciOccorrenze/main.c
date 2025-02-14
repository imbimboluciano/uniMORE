#include <stdio.h>

int main(void) {

	char str[255] = "Sono in biblioteca a pranzo";
	char* p;
	p = &str[0];

	__asm {
		mov ebx, p
		mov esi, 0

		ciclo:
		mov cl, byte ptr[ebx + esi * 1]
		cmp cl,0
		je fine
		cmp cl,97
		jne incremento
		mov byte ptr[ebx + esi *1],117

		incremento:
		inc esi
		jmp ciclo
		fine:
	}

	printf("%s", str);
	return 0;
}