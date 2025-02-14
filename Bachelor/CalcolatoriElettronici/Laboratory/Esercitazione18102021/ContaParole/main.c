#include <stdio.h>

int main(void) {

	char str[255] = " ";
	char* p;
	p = &str[0];
	int count = 0;
	__asm {
		mov ebx, p
		mov esi, 0
		mov ecx,count
		mov edi,0	//flag  0 = sono fuori dalla parola e 1 = sono dentro la parola

		ciclo:
		mov al,byte ptr[ebx + esi *1]
		cmp al,0
		je fine
		cmp edi,0
		je continua
		cmp al,' '
		je spazio
		jmp incremento
		



		continua:
		cmp al,' '
		je incremento


		parola:
		mov edx, 1
		inc esi
		inc ecx
		mov edi,1
		jmp ciclo

		spazio:
		mov edi,0
		jmp incremento


		
		incremento:
		inc esi
		jmp ciclo

		fine:
		mov count, ecx

	}

	return 0;
}