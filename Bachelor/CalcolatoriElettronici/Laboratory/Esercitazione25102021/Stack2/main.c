#include <stdio.h>

__declspec(naked) int somma(int* vet, int lung) {

	__asm {
		push ebp
		mov ebp,esp
		push ebx
		push esi
		push edi

		mov eax,0
		mov esi,dword ptr[ebp + 12]
		dec esi
		mov ebx,dword ptr[ebp + 8]
		ciclo:
		cmp esi,-1
		je fine
		add eax,dword ptr[ebx + esi*4]
		dec esi
		jmp ciclo

		fine:

	
		pop edi
		pop esi
		pop ebx
		mov esp,ebp
		pop ebp

		ret 
	}
}

int main(void) {

	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d", somma(a, 10));
}