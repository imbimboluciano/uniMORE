#include <stdio.h>

int main(void) {

	int a[5] = { 3,8,11,2,1 }; // 25
	int b[5] = { 9,12,15,4,6 }; // 46
	int* p1, * p2;
	p1 = &a[0];
	p2 = &b[0];
	int c = 0; // 0 se sono uguali, 1 se a > b e -1 se a < b
	__asm {
		mov ebx,p1
		mov edx,p2
		mov esi,0
		mov eax,0
		mov ecx,0

		ciclo:
		cmp esi,5
		jnl controllo
		add eax,dword ptr[ebx + esi*4]
		add ecx,dword ptr[edx + esi*4]
		inc esi
		jmp ciclo

		controllo:
			cmp eax,ecx
			jg maggiore
			jl minore
			jmp fine
		maggiore:
			mov c,1
		minore:
			mov c,-1
		fine:
	}

	printf("%d", c);
	return 0;
}