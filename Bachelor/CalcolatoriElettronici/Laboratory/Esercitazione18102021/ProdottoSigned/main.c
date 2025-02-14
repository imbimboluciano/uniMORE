#include <stdio.h>

int main(void) {

	int a = -5, b = 7, prod = 0;

	__asm {
		mov eax,a
		mov ebx,b
		mov ecx,prod
		mov edi,1 

		cmp eax,0
		jg controllo_ebx
		cmp ebx,0
		jl negoentrambi
		neg eax
		mov edi,-1
		jmp finito1


		controllo_ebx:
		cmp ebx, 0
		jg finito1
		neg ebx
		mov edi,-1
		jmp finito1

		negoentrambi:
		neg eax
		neg ebx

		finito1:
		cmp eax,0
		je controllofinale

		add ecx,ebx
		dec eax
		jmp finito1

		controllofinale:
		cmp edi,1
		je fine
		neg ecx
		jmp fine

		fine:
		mov prod,ecx
	}

	return 0;
}

