#include <stdio.h>

int main(void) {
	
	char str[255] = "ciao come va? come";
	char parola[255] = "ciao";
	char* p1, * p2;
	p1 = &str[0];
	p2 = &parola[0];
	int count;

	__asm {
	
		mov eax,p1
		mov ebx,p2
		mov ecx,0
		mov esi,0
		mov edi,0

		ciclo:
		cmp byte ptr[eax + esi*1], 0
		je fine
		mov dl,byte ptr[ebx + edi*1]
		cmp byte ptr[eax + esi * 1],dl
		jne incrementoesi
		jmp incrementoedi

		ciclo2:
		mov dl, byte ptr[ebx + edi * 1]
		cmp dl,0
		je occorrenzatrovata

		cmp byte ptr[eax + esi * 1], dl
		je incrementoedi
		jmp azzeracontatori

		

		incrementoesi:
		inc esi
		jmp ciclo

		incrementoedi:
		inc esi
		inc edi
		jmp ciclo2

		occorrenzatrovata:
		inc ecx
		jmp azzeracontatori

		azzeracontatori:
		mov edi,0
		jmp ciclo

		fine:
		mov count,ecx
	}
	
	printf("%d", count);
}