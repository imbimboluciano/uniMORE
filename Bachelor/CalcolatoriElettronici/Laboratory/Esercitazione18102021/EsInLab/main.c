#include <stdio.h>

int main(void) {

	unsigned int a = 3, b = 7, somma = 0;
	__asm {
		mov eax,a
		mov ebx,b
		mov ecx,somma
		ciclo:
		cmp eax,0
		je fine

		add ecx,ebx
		dec eax
		jmp ciclo

		fine:
		mov somma,ecx
	}
	return 0;
}