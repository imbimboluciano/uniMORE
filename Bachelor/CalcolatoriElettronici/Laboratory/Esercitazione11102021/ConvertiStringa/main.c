#include <stdio.h>

int main(void) {

	char str[255] = "sono molto stupido";
	char* p;
	p = &str[0];
	__asm {
		mov ebx,p
		mov esi,0
		
		ciclo:
		mov al, byte ptr[ebx+ esi*1]
		cmp al,0
		je fine
		cmp al,32
		je incremento
		sub byte ptr[ebx + esi*1],32
		jmp incremento

		incremento:
		inc esi
		jmp ciclo
		fine:
	}

	printf("%s", str);
	return 0;

}