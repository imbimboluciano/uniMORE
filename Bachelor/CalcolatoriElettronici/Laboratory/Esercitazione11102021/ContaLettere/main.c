#include <stdio.h>

int main(void) {

	char str[255] = "6 uno 0";
	char* p;
	p = &str[0];
	int c = 0;
	__asm {
		mov ebx,p
		mov esi,0
		mov eax,0
		ciclo:
			mov cl,byte ptr[ebx + esi * 1]
			cmp cl,0
			je fine
			cmp cl,97
			jl incremento
			cmp cl,122
			jg incremento
			inc eax
			jmp incremento


		incremento:
			inc esi
			jmp ciclo
		
		fine:
			mov c,eax

	}
	return 0;
}